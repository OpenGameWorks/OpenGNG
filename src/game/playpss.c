// FLAGS: -lang c++ -str readonly
#include "playpss.h"
#include "Font.h"

#include "movie.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" int sceCdStatus();
extern "C" int sceCdGetDiskType();
extern "C" int sceGsSyncV(int);
extern "C" int sceMpegDemuxPss(sceMpeg *, void *, int);
extern "C" void RemoteChangePCMVolume(int);
void CdsAssert(char *, int, char *);
void audioUpdate();
void getTrayStatus();

extern signed char gbMoviesOnDisc;
extern int fst_trayOpen;
extern int fst_disk_status;
extern int fst_readCount;
extern int muxBuffFullness;
extern int bgDuration;
extern int demuxBuffFuture;
extern int demuxBuffPast;
extern int demuxBuffPresent;
extern int demuxBuffSize;
extern int demuxBuff;
extern int (*fileRead)(void *, int);
extern char muxBuff[0x8000];
extern char audioDec[0x60];
extern "C" void audioDecBeginPut(void *, char **, int *, char **, int *);
extern "C" void audioDecEndPut(void *, int);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern unsigned char gInterface[];
extern "C" void sceMpegInit();
extern "C" int sceMpegCreate(sceMpeg *, void *, int);
extern "C" int sceMpegAddStrCallback(sceMpeg *, int, int, void *);
extern "C" int sceMpegAddCallback(sceMpeg *, int, void *, void *);
extern "C" int sceMpegIsEnd(sceMpeg *);
extern "C" int sceMpegGetPicture(sceMpeg *, void *, int);
extern "C" void sceMpegReset(sceMpeg *);
extern "C" void sceMpegDelete(sceMpeg *);
extern "C" void sceGsResetGraph(int, int, int, int);
extern "C" void sceGsSetDefDispEnv(void *, int, int, int);
extern "C" void sceGsPutDispEnv(void *);
extern "C" int sceGsSyncPath(int, int);
extern "C" void loadImage(void *, void *);
extern "C" void setLoadImageTags(int, void *, int, int, int, int, int);
extern "C" void audioDecCreate(void *, int, int, int);
extern "C" void audioDecSendToIOP(void *);
extern "C" int audioDecIsPreset(void *);
extern "C" void audioDecStart(void *);
extern "C" void audioDecReset(void *);
extern "C" void RemoteChangeMasterVolume(int);
extern "C" void UpdatePad(void *);
extern "C" float GetMainMusicRelVolume__6PSoundFv(void *);
extern unsigned char gSound[0x18080];
extern unsigned char gPad[0x1C0];
extern "C" void *memset(void *, int, unsigned int);

// TODO(header): PMovieOverlayEngine shell, the real class lives in PMovieOverlayEngine.h
class PMovieOverlayEngine {
public:
    void Init(short, short, short);
    void BeginRender();
    void EndRender();
    char _pad[0xA0];
};
extern PMovieOverlayEngine gOverlayEng;
extern char TSprites[0x200];
extern unsigned char exitEarly[0x90];
extern unsigned char gUnitMatrix[0x40];
extern short DISP_WIDTH;
extern short DISP_HEIGHT;
extern short TV_MODE;
extern int MAX_WIDTH;
extern int MAX_HEIGHT;
extern int SCAN_LINES;
extern unsigned char MODE_PAL;
extern unsigned char gbNoMovieSound;
extern int isStarted;
extern int path3tag;
extern int fst_uHsyncBase;
extern int fst_uHsyncCnt;
extern int fst_movieFrameOverflows;

// TODO(header): PlayPss state, bodies in this file only
struct SubTitleState {
    unsigned char m_unk0;       // 0x00 active flag, 0x4C94F0
    unsigned char m_unk1;       // 0x01 draw flag tested before DrawSprites
    char _pad2[6];
    FontSubtitle *m_unk8;       // 0x08 current table entry, 0x4C94F8
    char _pad10[4];
    float m_unk14;              // 0x14 timer, 0x4C9504
    int m_unk18;                // 0x18 end time of the shown entry, 0x4C9508
    char _pad1C[4];
    PMat4 *m_unk20;             // 0x20 screen matrix, 0x4C9510
    char _pad24[0x198 - 0x24];  // note: the 352-byte symbol ends at 0x160; the draft writes past it
};

extern SubTitleState subTitle;

// DRAFT: 0x001FFA40 ProcessNextSubtitle__Fv
// note: 39 words differ; original keeps pEntry in s0 and computes the next entry in-register (ours reloads subTitle.m_unk8), length 0x164 vs our 0x15C. Tried extern vs static subTitle (relocs now match), local end-time sum; none reduced the diff.
void ProcessNextSubtitle() {
    FontManager *gi;
    FontSubtitle *pEntry;
    FontNode *pNode;

    gi = (FontManager *)(gInterface + 0x80);
    gi->InitFrame();
    if (subTitle.m_unk0 != 0) {
        if (subTitle.m_unk14 < (float)subTitle.m_unk18) {
            return;
        }
        gi->RemoveText(50);
        subTitle.m_unk0 = 0;
        return;
    }
    pEntry = subTitle.m_unk8;
    if (pEntry == 0) {
        return;
    }
    if (subTitle.m_unk14 < (float)pEntry->m_unk4) {
        return;
    }
    gi->RemoveText(50);
    pNode = gi->DisplayString(pEntry->m_unk0, 0.0f, -220.0f, pEntry->m_unkA, (FontColor)pEntry->m_unk8, (FontAlign)1);
    pNode->m_unk6 = 50;
    if (pEntry->m_unk6 != 0) {
        subTitle.m_unk0 = 1;
        subTitle.m_unk18 = pEntry->m_unk4 + pEntry->m_unk6;
    }
    if (pEntry->m_unk9 != 0) {
        subTitle.m_unk8 = 0;
        return;
    }
    subTitle.m_unk8 = subTitle.m_unk8 + 1;
    if (subTitle.m_unk8->m_unk4 < subTitle.m_unk18) {
        subTitle.m_unk0 = 0;
    }
}

// DRAFT: 0x001FFBB0 checkAndWaitForDisk__Fv
// note: 20 words differ; loop layout (do-while back-branch one word early, unfilled delay-slot nops after sceCdGetDiskType, tail call at 0x80 vs 0x88). Tried while(1), loop-scoped diskType, for(;;)+break; none reduced the diff.
void checkAndWaitForDisk() {
    if (gbMoviesOnDisc != 0) {
        getTrayStatus();
        if (fst_trayOpen != 0) {
            RemoteChangePCMVolume(0);
            do {
                sceGsSyncV(0);
                getTrayStatus();
            } while (fst_trayOpen != 0);
            while (1) {
                int diskType = sceCdGetDiskType();
                if (diskType == 0x14 || diskType == 0x12) {
                    break;
                }
                sceGsSyncV(0);
            }
            Movie::MovieOutputCurVol();
        }
    }
}

// FUNCTION: 0x001FFC50 getTrayStatus__Fv
void getTrayStatus() {
    int status;

    status = sceCdStatus();
    fst_disk_status = status;
    if (status == 1 || status == 0x20) {
        fst_trayOpen = 1;
        return;
    }
    fst_trayOpen = 0;
}

// FUNCTION: 0x001FFCB0 fillBuff__FP7sceMpegi
static int fillBuff(sceMpeg *arg0, int arg1) {
    char *var_a1;
    int temp_v0;

    if (muxBuffFullness != 0) {
        var_a1 = muxBuff + 0x8000 - muxBuffFullness;
        goto block_8;
    }
loop_2:
    muxBuffFullness = fileRead(muxBuff, 0x8000);
    if (muxBuffFullness == 0 && arg1 == 0) {
        return 0;
    }
    if (muxBuffFullness != 0) {
        var_a1 = muxBuff;
        if (fst_readCount == 0) {
            fst_readCount += 1;
        }
block_8:
        temp_v0 = sceMpegDemuxPss(arg0, var_a1, muxBuffFullness);
        muxBuffFullness -= temp_v0;
        return temp_v0;
    }
    goto loop_2;
}

// FUNCTION: 0x001FFD60 errorCallback__FP7sceMpegP13sceMpegCbDataPv
int errorCallback(sceMpeg *arg0, sceMpegCbData *arg1, void *arg2) {
    CdsAssert("playpss.c", 0x3DB, "0");
    return 1;
}

// DRAFT: 0x001FFD90 backgroundCallback__FP7sceMpegP13sceMpegCbDataPv
// note: 2 words differ; load order of the counter and bgDuration. Tried single-expression, split, counter-local, cast, and swapped-operand forms; the counter-local form is the best at 2.
int backgroundCallback(sceMpeg *arg0, sceMpegCbData *arg1, void *arg2) {
    unsigned int temp_s0;
    unsigned int counter;

    counter = *(unsigned int *)0x10000000;
    temp_s0 = bgDuration + counter;
    while ((unsigned int)*(unsigned int *)0x10000000 < temp_s0) {
        fillBuff(arg0, 0);
        audioUpdate();
    }
    return 1;
}

// FUNCTION: 0x001FFE00 nodataCallback__FP7sceMpegP13sceMpegCbDataPv
int nodataCallback(sceMpeg *arg0, sceMpegCbData *arg1, void *arg2) {
    int temp_s1;
    int temp_a1;

    temp_s1 = demuxBuffPast - demuxBuffFuture;
    demuxBuffPresent = demuxBuffFuture;
    if (temp_s1 < 0) {
        temp_s1 += demuxBuffSize;
    }
    if (temp_s1 < 0x1000) {
        for (;;) {
            if (fillBuff(arg0, 1) == 0) {
                temp_s1 += 15;
                break;
            }
            temp_s1 = demuxBuffPast - demuxBuffFuture;
            if (temp_s1 < 0) {
                temp_s1 += demuxBuffSize;
            }
            if (temp_s1 >= 0x1000) {
                break;
            }
        }
    }
    temp_a1 = temp_s1 & -16;
    if (temp_a1 > 0x1000) {
        temp_a1 = 0x1000;
    }
    if ((unsigned int)(demuxBuffPresent + temp_a1) > (unsigned int)(demuxBuff + demuxBuffSize)) {
        temp_a1 = demuxBuff + demuxBuffSize - demuxBuffPresent;
    }
    *(unsigned int *)0x1000B420 = temp_a1 / 16;
    *(int *)0x1000B410 = demuxBuffPresent;
    *(unsigned int *)0x1000B400 = 0x101;
    demuxBuffFuture = demuxBuffPresent + temp_a1;
    if ((unsigned int)demuxBuffFuture >= (unsigned int)(demuxBuff + demuxBuffSize)) {
        demuxBuffFuture -= demuxBuffSize;
    }
    audioUpdate();
    return 1;
}

// DRAFT: 0x001FFF50 audioCallback__FP7sceMpegP16sceMpegCbDataStrPv
// note: 19 words differ; arg1 and size are swapped between s0/s1. Tried local reorder, pointer copy first/last, dropping temp_a2; declaration order does not change register assignment.
int audioCallback(sceMpeg *arg0, sceMpegCbDataStr *arg1, void *arg2) {
    int temp_s1;
    char *ptr1;
    char *ptr2;
    int size1;
    int size2;

    audioDecBeginPut(&audioDec, &ptr1, &size1, &ptr2, &size2);
    arg1->m_unkC -= 4;
    arg1->m_unk8 += 4;
    temp_s1 = arg1->m_unkC - size1;
    if ((unsigned int)(size1 + size2) < arg1->m_unkC) {
        return 0;
    }
    if (temp_s1 > 0) {
        memcpy(ptr1, (char *)arg1->m_unk8, arg1->m_unkC - temp_s1);
        memcpy(ptr2, (char *)arg1->m_unk8 + (arg1->m_unkC - temp_s1), temp_s1);
    } else {
        memcpy(ptr1, (char *)arg1->m_unk8, arg1->m_unkC);
    }
    audioDecEndPut(&audioDec, arg1->m_unkC);
    audioUpdate();
    return 1;
}

// DRAFT: 0x00200040 videoCallback__FP7sceMpegP16sceMpegCbDataStrPv
// note: 5 words differ; wrap path loads m_unkC/m_unk8 into swapped registers (original m_unkC in v1). Tried the original wrap expression (10), local first-chunk length (60), and reordered memcpy source; else-path operand swap gave 5.
int videoCallback(sceMpeg *arg0, sceMpegCbDataStr *arg1, void *arg2) {
    int avail;
    int wrap;

    avail = demuxBuffPresent - demuxBuffPast;
    if (avail < 0) {
        avail += demuxBuffSize;
    }
    if (avail == 0 && demuxBuffPresent == demuxBuffFuture) {
        avail = demuxBuffSize;
    }
    if ((unsigned int)avail < arg1->m_unkC) {
        return 0;
    }
    wrap = (demuxBuffPast - demuxBuff) + arg1->m_unkC - demuxBuffSize;
    if (wrap > 0) {
        memcpy((void *)(((unsigned int)demuxBuffPast & 0x0FFFFFFF) | 0x20000000), (void *)arg1->m_unk8, arg1->m_unkC - wrap);
        memcpy((void *)(((unsigned int)demuxBuff & 0x0FFFFFFF) | 0x20000000), (void *)(arg1->m_unk8 + (arg1->m_unkC - wrap)), wrap);
        demuxBuffPast = demuxBuff + wrap;
    } else {
        memcpy((void *)(((unsigned int)demuxBuffPast & 0x0FFFFFFF) | 0x20000000), (void *)arg1->m_unk8, arg1->m_unkC);
        demuxBuffPast = arg1->m_unkC + demuxBuffPast;
    }
    return 1;
}

// DRAFT: 0x00200160 playPss__FPFPvi_iP12PlayPssRsrcsiUi
// note: 1121 words differ; control flow, setup, sync, decode and teardown calls only. The exitEarly, TSprites and subTitle constant stores, the matrix setup, the centring tags, the sprite draw, Render and printf are not transcribed.
int playPss(int (*arg0)(void *, int), PlayPssRsrcs *arg1, int arg2, unsigned int arg3) {
    char spC0[0x50];
    char sp110[0x20];
    int var_s1;
    int vol;
    unsigned int buttons;
    int tilesW;
    int tilesH;
    int i;
    sceMpeg *mpeg;

    mpeg = (sceMpeg *)spC0;
    var_s1 = 0;
    sceGsSyncV(0);
    sceGsResetGraph(0, 1, TV_MODE, 0);
    path3tag = (int)arg1->m_unkC;
    fst_readCount = 0;
    fst_uHsyncBase = 0;
    fst_uHsyncCnt = 0;
    fst_movieFrameOverflows = 0;
    fst_trayOpen = 0;
    fst_disk_status = 0;
    checkAndWaitForDisk();
    sceMpegInit();
    audioDecCreate(audioDec, arg1->m_unk18, arg1->m_unk1C, arg1->m_unk20);
    RemoteChangeMasterVolume(0);
    if (gbNoMovieSound != 0) {
        vol = 0;
    } else {
        vol = (int)GetMainMusicRelVolume__6PSoundFv(gSound);
    }
    Movie::BeginFadeMusicVolume(100, (unsigned int)vol);
    isStarted = 0;
    sceMpegCreate(mpeg, (void *)arg1->m_unk0, arg1->m_unk4);
    sceMpegAddStrCallback(mpeg, 0, 0, (void *)videoCallback);
    sceMpegAddStrCallback(mpeg, 2, 0, (void *)audioCallback);
    sceMpegAddCallback(mpeg, 1, (void *)nodataCallback, 0);
    sceMpegAddCallback(mpeg, 4, (void *)backgroundCallback, 0);
    sceMpegAddCallback(mpeg, 0, (void *)errorCallback, 0);
    muxBuffFullness = 0;
    demuxBuff = arg1->m_unk10;
    demuxBuffSize = arg1->m_unk14;
    tilesW = demuxBuff + 0x10;
    fileRead = arg0;
    demuxBuffPresent = demuxBuff;
    demuxBuffPast = tilesW;
    demuxBuffFuture = tilesW;
    do {
    } while (fillBuff(mpeg, 1) != 0);

    sceGsSetDefDispEnv(sp110, 0, DISP_WIDTH, DISP_HEIGHT);
    sceGsPutDispEnv(sp110);
    gOverlayEng.Init(0, DISP_WIDTH, DISP_HEIGHT);
    ((FontManager *)(gInterface + 0x80))->InitFMV();

    do {
    } while (sceGsSyncV(0) == 1);
    *(int *)0x10000010 = 0x83;
    *(unsigned int *)0x10000000 = 0;
    fst_uHsyncBase = 0;
    fst_uHsyncCnt = 0;
    if (sceMpegIsEnd(mpeg) == 0) {
        do {
            fst_uHsyncBase += *(unsigned int *)0x10000000;
            fst_uHsyncCnt = fst_uHsyncBase;
            audioUpdate();
            UpdatePad(gPad);
            buttons = *(unsigned int *)(gPad + 0x110);
            checkAndWaitForDisk();
            if (exitEarly[0] == 0) {
                if ((buttons & arg3) != 0 || (arg2 != 0 && !(subTitle.m_unk14 <= (float)arg2))) {
                    Movie::BeginFadeMusicVolume(0x3E8, 0);
                    var_s1 = (buttons == 0) ? 1 : 2;
                }
            }
            tilesW = (MAX_WIDTH + 0xF) >> 4;
            tilesH = (MAX_HEIGHT + 0xF) >> 4;
            if (sceMpegGetPicture(mpeg, arg1->m_unk8, tilesW * tilesH) < 0) {
                CdsAssert((char *)"playpss.c", 0x255, (char *)"0");
            }
            audioUpdate();
            loadImage((void *)path3tag, arg1->m_unk8);
            audioUpdate();
            sceGsSyncPath(0, 0);
            audioUpdate();
            gOverlayEng.BeginRender();
            ProcessNextSubtitle();
            ((FontManager *)(gInterface + 0x80))->InitFrame();
            gOverlayEng.EndRender();
            audioDecSendToIOP(audioDec);
            if (isStarted == 0 && audioDecIsPreset(audioDec) != 0) {
                audioDecStart(audioDec);
                isStarted = 1;
            }
            for (i = 0; i < SCAN_LINES; i++) {
                fillBuff(mpeg, 0);
            }
            sceGsSyncV(0);
            fst_movieFrameOverflows += 1;
            Movie::UpdateFadeMusicVolume();
            sceGsPutDispEnv(sp110);
        } while (sceMpegIsEnd(mpeg) == 0);
    }

    audioDecReset(audioDec);
    RemoteChangePCMVolume(0);
    sceMpegReset(mpeg);
    sceMpegDelete(mpeg);
    ((FontManager *)(gInterface + 0x80))->RemoveText((unsigned short)50);
    if (var_s1 == 3) {
        CdsAssert((char *)"playpss.c", 0x33F, (char *)"retval != PSS_RETVAL_INVALID");
    }
    return var_s1;
}
