// FLAGS: -lang c++ -str readonly
#include "playpss.h"
#include "Font.h"

// TODO(header): foreign declarations
class Movie {
public:
    static void MovieOutputCurVol();
};

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

struct SubTitleState {
    unsigned char m_unk0;       // 0x00 active flag, 0x4C94F0
    char _pad1[7];
    FontSubtitle *m_unk8;       // 0x08 current table entry, 0x4C94F8
    char _pad10[4];
    float m_unk14;              // 0x14 timer, 0x4C9504
    int m_unk18;                // 0x18 end time of the shown entry, 0x4C9508
    char _pad1C[0x160 - 0x1C];
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
int fillBuff(sceMpeg *arg0, int arg1) {
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
