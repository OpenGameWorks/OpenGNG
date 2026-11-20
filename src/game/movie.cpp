// FLAGS: -str readonly
#include "types.h"
#include "movie.h"
#include "MemoryManager.h"
#include "PSound.h"

// TODO(header): foreign declarations
extern "C" void RemoteChangePCMVolume(int);
extern "C" int printf(const char *pFmt, ...);
extern "C" unsigned int sceSifAllocIopHeap(int);
extern "C" void sceSifFreeIopHeap(unsigned int);
extern "C" void sceGsSyncPath(int, int);
extern "C" void sceGsSyncV(int);
class PResourceManager {
public:
    void Unload();
};
extern PSound gSound;
#define MOVIE_LAST 6
#define PAL_MOVIE 6
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert((char *)"movie.cpp", line, (char *)#cond))
void CdsAssert(char *, int, char *);
void GsClearVRAM(unsigned char, unsigned char, unsigned char, unsigned char, short, short, short);
int strFileOpen(const char *);
int strFileRead(void *, int);
void strFileClose();
struct PlayPssRsrcs;
int playPss(int (*)(void *, int), PlayPssRsrcs *, int, unsigned int);
void playNTSCtoPAL(PlayPssRsrcs *, int, unsigned int);
extern MemoryManager MemMgr;
extern char gEng[105360];
extern char *gPssFilenames[64];
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int DISP_WIDTH;
extern int DISP_HEIGHT;
extern int MAX_WIDTH;
extern int MAX_HEIGHT;
extern int SCAN_LINES;
extern unsigned char MODE_PAL;
extern signed char gbNoMovieSound;

// DRAFT: 0x001FF2C0 UpdateFadeMusicVolume__5MovieFv
// note: branch structure matches; float loads land in f0/f2 (original f1/f0, zero in f2), and the 0x4F000000 constant is not hoisted into the bnez delay slot. Tried split temp += delta, swapped sum operands, cached locals: all 65+ words.
void Movie::UpdateFadeMusicVolume() {
    if (mst_bMusicFading != 0) {
        float temp = mst_fMusicRelVolFadeCur + mst_fMusicRelVolFadeDelta;
        if (temp <= 0.0f) {
            mst_bMusicFading = 0;
        } else if (mst_fMusicRelVolFadeDelta > 0.0f) {
            if (!(temp < (float)mst_uMusicRelVolFadeTarget)) {
                mst_bMusicFading = 0;
            }
        } else if (mst_uMusicRelVolFadeTarget >= mst_uMusicRelVolCur) {
            mst_bMusicFading = 0;
        }
        if (mst_bMusicFading == 0) {
            mst_uMusicRelVolCur = mst_uMusicRelVolFadeTarget;
        } else {
            mst_fMusicRelVolFadeCur = temp;
            mst_uMusicRelVolCur = (unsigned int)temp;
        }
        MovieOutputCurVol();
    }
}

// FUNCTION: 0x001FF3E0 BeginFadeMusicVolume__5MovieFUiUi
void Movie::BeginFadeMusicVolume(unsigned int msecs, unsigned int target) {
    if (target > 1000) {
        target = 1000;
    }
    mst_bMusicFading = 1;
    mst_uMusicRelVolFadeTarget = target;
    mst_uMusicFadeMsecs = msecs;
    int n = ((int)msecs * 30) / 1000;
    if (n == 0) {
        n = 1;
    }
    mst_fMusicRelVolFadeDelta = (float)((int)target - (int)mst_uMusicRelVolCur) / (float)n;
    mst_fMusicRelVolFadeCur = (float)mst_uMusicRelVolCur;
}

// FUNCTION: 0x001FF4A0 MovieOutputCurVol__5MovieFv
void Movie::MovieOutputCurVol() {
    mst_uMusicVolRawCur = (mst_uMusicRelVolCur * 0x7FFF) / 1000;
    RemoteChangePCMVolume(mst_uMusicVolRawCur);
}

// FUNCTION: 0x001FF4E0 MovieVolInit__5MovieFv
void Movie::MovieVolInit() {
    mst_uMusicVolRawCur = 0;
    mst_uMusicRelVolBase = 0;
    mst_uMusicRelVolCur = 0;
    mst_bMusicFading = 0;
    mst_uMusicFadeMsecs = 0;
    mst_uMusicRelVolFadeTarget = 0;
    mst_fMusicRelVolFadeDelta = 0.0f;
    mst_fMusicRelVolFadeCur = 0.0f;
}

struct MoviePlayBuf {
    void *m_unk00;
    int m_unk04;
    void *m_unk08;
    void *m_unk0C;
    void *m_unk10;
    int m_unk14;
    void *m_unk18;
    int m_unk1C;
    unsigned int m_unk20;
    int m_unk24;
    void *m_unk28;
    unsigned int m_unk2C;
    int m_unk30;
};

// FUNCTION: 0x001FF510 PlayMovie__5MovieFiiUib
int Movie::PlayMovie(int movieID, int arg1, unsigned int arg2, bool arg3) {
    MoviePlayBuf buf;
    int var_s1;

    DISP_WIDTH = SCREEN_WIDTH;
    DISP_HEIGHT = SCREEN_HEIGHT * 2;
    MAX_WIDTH = DISP_WIDTH;
    MAX_HEIGHT = DISP_HEIGHT;
    if (MODE_PAL) {
        SCAN_LINES = 0x271;
        movieID += 6;
    } else {
        SCAN_LINES = 0x20D;
    }
    gbNoMovieSound = movieID >= 9;
    GsClearVRAM(0, 0, 0, 0, (short)SCREEN_WIDTH, (short)(SCREEN_HEIGHT * 4), 0);
    sceGsSyncPath(0, 0);
    ((PResourceManager *)(gEng + 0x188A4))->Unload();
    MemMgr.m_unk18 = 2;

    buf.m_unk00 = (void *)MovieMemAlign64((MAX_WIDTH * MAX_HEIGHT * 9) / 2 + 0x1768, "mpeg work area");
    buf.m_unk04 = (MAX_WIDTH * MAX_HEIGHT * 9) / 2 + 0x1768;
    buf.m_unk08 = (void *)MovieMemAlign64(((MAX_WIDTH / 16) * (MAX_HEIGHT / 16)) << 10, "rgb32 buffer");
    buf.m_unk0C = (void *)MovieMemAlign64((((((MAX_WIDTH / 16) * (MAX_HEIGHT / 16) * 6) + 0xA) * 4 + 0x3F) / 64) << 9, "path 3 tags");
    buf.m_unk10 = (void *)MovieMemAlign64(0x30000, "demux buffer");
    buf.m_unk14 = 0x30000;
    buf.m_unk18 = (void *)MovieMemAlign64(0xC000, "audio buffer");
    buf.m_unk1C = 0xC000;
    buf.m_unk20 = MovieIOPAlloc(0x6000, "audio buffer");
    buf.m_unk24 = 0x6000;
    buf.m_unk28 = (void *)MovieMemAlign64(0x800, "zero buffer");
    buf.m_unk2C = MovieIOPAlloc(0x800, "zero buffer");
    buf.m_unk30 = movieID;
    CDS_ASSERT(0x103, movieID < ((MODE_PAL) ? ((MOVIE_LAST) + (PAL_MOVIE)) : (MOVIE_LAST)));

    var_s1 = 0;
    if (((int)arg3 & 0xFF) == 0) {
        while (strFileOpen(gPssFilenames[movieID]) == 0) {
            printf("Movie: Can't open file %s\n", gPssFilenames[movieID]);
            sceGsSyncV(0);
        }
        MovieVolInit();
        var_s1 = playPss(strFileRead, (PlayPssRsrcs *)&buf, arg1, arg2);
        strFileClose();
    } else {
        playNTSCtoPAL((PlayPssRsrcs *)&buf, arg1, arg2);
    }
    sceSifFreeIopHeap(buf.m_unk20);
    sceSifFreeIopHeap(buf.m_unk2C);
    MemMgr.DeAllocateAligned(buf.m_unk00);
    MemMgr.DeAllocateAligned(buf.m_unk08);
    MemMgr.DeAllocateAligned(buf.m_unk0C);
    MemMgr.DeAllocateAligned(buf.m_unk10);
    MemMgr.DeAllocateAligned(buf.m_unk18);
    MemMgr.DeAllocateAligned(buf.m_unk28);
    gSound.ReturnControlOfIOPToMjln();
    MemMgr.m_unk18 = 0;
    return var_s1;
}

// FUNCTION: 0x001FF910 MovieIOPAlloc__5MovieFUiPCc
unsigned int Movie::MovieIOPAlloc(unsigned int size, const char *name) {
    unsigned int size2 = (size + 0x7FF) & ~0x7FFu;
    unsigned int temp;
    if ((temp = sceSifAllocIopHeap(size2)) == 0) {
        printf("Cannot allocate % bytes of IOP memory for %s\n", size, name);
        CdsAssert((char *)"movie.cpp", 0x8D, (char *)"0");
    } else {
        printf("Allocated %7d bytes of IOP memory at %d(%x) for %s\n", size, temp, temp, name);
    }
    return temp;
}

// FUNCTION: 0x001FF9B0 MovieMemAlign64__5MovieFUiPCc
int Movie::MovieMemAlign64(unsigned int size, const char *name) {
    void *temp = MemMgr.AllocateAligned((int)size, 0x40);
    if (temp == 0) {
        CdsAssert((char *)"movie.cpp", 0x76, (char *)"0");
    } else {
        printf("Allocated %7d bytes of EE memory at x%7x for %s\n", size, temp, name);
    }
    return (int)temp;
}
