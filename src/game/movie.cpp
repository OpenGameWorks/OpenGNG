// FLAGS: -str readonly
#include "types.h"
#include "movie.h"
#include "MemoryManager.h"

// TODO(header): foreign declarations
extern "C" void RemoteChangePCMVolume(int);
extern "C" int printf(const char *pFmt, ...);
extern "C" unsigned int sceSifAllocIopHeap(int);
void CdsAssert(char *, int, char *);
extern MemoryManager MemMgr;

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
