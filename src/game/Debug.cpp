// FLAGS: -str readonly
#include "types.h"

// TODO(header): foreign declarations
extern "C" int sceDevConsPrintf(const char *pFmt, ...);
extern "C" void sceDevConsAttribute(char *pCons, unsigned char nAttr);
extern "C" void sceDevConsClear(char *pCons);
extern "C" void sceDevConsLocate(char *pCons, unsigned int nX, unsigned int nY);
extern "C" unsigned int strlen(const char *pStr);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern char gEng[105360];
extern short mPerformanceBars;
extern short mDisplayListStatusBar;
extern short mDebugTime;
extern short mSound;
extern short gPlayerPos;
extern "C" int sprintf(char *pBuf, const char *pFmt, ...);
extern "C" void sceDevConsClose(char *pCons);
extern "C" void __dl__FPv(void *pMem);

class PMat4;

class MaxEngine {
public:
    void InitRenderFrame(bool bFlag, unsigned int nId);
};

class PSound {
public:
    void SoundEditEnter();
    void SoundEditLeave();
    void DebugInterface(int nPad);
    char _pad000[0x10];
};

extern PSound gSound;

struct PadState {
    char _pad000[0x110];
    unsigned short m_unk110;
    char _pad112[0x10];
};

extern PadState gPad;

class PGfxEngine {
public:
    void UpdateLights(PMat4 *pA, PMat4 *pB, float (*pC)[4]);
    char _pad000[0x158E22];
    unsigned char m_unk158E22;
};

extern PGfxEngine gGfxEng;
extern char mLightCache[0x100];
extern void *gpAnimation;

class AnimObject {
public:
    virtual ~AnimObject();
    virtual void Slot1(int nA, int nB, int nC);
};

class ETiming {
public:
    void StopSubTimer(unsigned int nId);
    void StartSubTimer(unsigned int nId);
    void PrintPerformanceMeter(unsigned int nId, PMat4 *pMat);
    void PrintDisplayListStatusMeter(unsigned int nId, PMat4 *pMat);
};

class Camera {
public:
    void TextDebug();
};

extern "C" void __dt__7ETimingFv(ETiming *pThis, short nDestroy);

#include "Debug.h"

extern Debug gDebug;

// FUNCTION: 0x16A700 RenderPerformanceMeters__5DebugFv
void Debug::RenderPerformanceMeters() {
    ETiming *t = this->m_unk0C;
    if (t != 0 && mPerformanceBars != 0) {
        t->PrintPerformanceMeter(0, 0);
        return;
    }
    if (t != 0 && mDisplayListStatusBar != 0) {
        t->PrintDisplayListStatusMeter(0, 0);
    }
}

// DRAFT: 0x16A940 StopDebugTimer__5DebugFPv
// note: 1 differing line: compiler keeps the mfc0 counter in v0, original uses a3 for the subu; tried decl order, initialized counter (folds to negu), register keyword.
void Debug::StopDebugTimer(void *pArg) {
    unsigned int nNow;
    unsigned int nDelta;

    asm { .word 0x4007C801 }
    nDelta = nNow - this->m_unk10;
    if (nDelta < this->m_unk14) {
        this->m_unk14 = nDelta;
    }
    if (this->m_unk18 < nDelta) {
        this->m_unk18 = nDelta;
        this->m_unk24 = pArg;
    }
    this->m_unk1C += nDelta;
}

// FUNCTION: 0x16A9B0 ResetDebugTimer__5DebugFv
void Debug::ResetDebugTimer() {
    this->m_unk14 = 0x7FFFFFFF;
    this->m_unk18 = 0;
    this->m_unk1C = 0;
    this->m_unk20 = 0;
    this->m_unk24 = 0;
}

// FUNCTION: 0x16AB00 DebugDisp__5DebugFPc
void Debug::DebugDisp(char *pStr) {
    sceDevConsPrintf(this->m_unk00, pStr);
    this->LineFeed(pStr);
    this->m_unk2D = 1;
}

// FUNCTION: 0x16AB50 DebugDispPos__5DebugFPcUiUii
void Debug::DebugDispPos(char *pStr, unsigned int nX, unsigned int nY, int nColor) {
    if (nColor != 7) {
        sceDevConsAttribute(this->m_unk00, (unsigned char)nColor);
    }
    sceDevConsLocate(this->m_unk00, nX, nY);
    sceDevConsPrintf(this->m_unk00, pStr);
    sceDevConsLocate(this->m_unk00, this->m_unk04, this->m_unk08);
    if (nColor != 7) {
        sceDevConsAttribute(this->m_unk00, 7);
    }
    this->m_unk2D = 1;
}

// FUNCTION: 0x16AC00 DebugColorDisp__5DebugFPcUc
void Debug::DebugColorDisp(char *pStr, unsigned char nColor) {
    sceDevConsAttribute(this->m_unk00, nColor);
    sceDevConsPrintf(this->m_unk00, pStr);
    sceDevConsAttribute(this->m_unk00, 7);
    this->LineFeed(pStr);
    this->m_unk2D = 1;
}

// DRAFT: 0x16AC70 LineFeed__5DebugFPc
// note: 10 differing lines, size 0x68 vs 0x6C; original has nops at inner-if join (0x44) and guard join (0x54) that the compiler does not emit; tried for/while/do-while, empty else, pre-decrement test.
void Debug::LineFeed(char *pStr) {
    int n = strlen(pStr);
    if (n != 0) {
        do {
            if (*pStr == 0xA) {
                this->m_unk08++;
            }
            pStr++;
        } while (--n != 0);
    }
}

// FUNCTION: 0x16ADD0 DebugClear__5DebugFv
void Debug::DebugClear() {
    sceDevConsClear(this->m_unk00);
    this->m_unk08 = 0;
    this->m_unk04 = 0;
    if (mDebugTime != 0) {
        this->m_unk0C->StartSubTimer(1);
    }
    this->ResetDebugTimer();
}

// DRAFT: 0x16AE40 SoundEdit__Fv
// note: 6 differing words: the original reuses the bnez delay-slot lui(gSound) for DebugInterface and has its own lui for SoundEditLeave; ours reloads gSound and shares one lui. Tried int DebugInterface param (15->6), do/while with break (6), local pad copy (6).
void SoundEdit() {
    if (mSound != 0) {
        gSound.SoundEditEnter();
    loop:
        ((MaxEngine *)gEng)->InitRenderFrame(false, 0);
        gDebug.DebugDispPos("Sound Edit", 0x1E, 0, 7);
        gDebug.DebugDisp("\n");
        if (!(gPad.m_unk110 & 1)) {
            gSound.DebugInterface(gPad.m_unk110);
            goto loop;
        }
        gSound.SoundEditLeave();
    }
}

// FUNCTION: 0x16AEE0 PlayerPosDisplay__Fv
void PlayerPosDisplay() {
    char buf[0x80];
    float *pPos;

    if (gPlayerPos != 0) {
        char *pObj = *(char **)(gEng + 0x1883C);
        if (pObj != 0) {
            char *pTrack = *(char **)(pObj + 0x3C);
            if (pTrack != 0) {
                pPos = (float *)(pTrack + 0x80);
            } else {
                pPos = (float *)(pObj + 0x190);
            }
            sprintf(buf, "Player (%d, %d, %d)\n", (int)(pPos[0] + 0.5f), (int)(pPos[1] + 0.5f), (int)(pPos[2] + 0.5f));
            gDebug.DebugDisp(buf);
        }
    }
}

// FUNCTION: 0x16AF80 RenderAnimation__Fv
void RenderAnimation() {
    AnimObject *t;

    if (gpAnimation != 0) {
        t = *(AnimObject **)((char *)gpAnimation + 0x3C);
        if (t != 0) {
            gGfxEng.m_unk158E22 = 1;
            gGfxEng.UpdateLights((PMat4 *)mLightCache, (PMat4 *)(mLightCache + 0x40), (float (*)[4])(mLightCache + 0x80));
            t->Slot1(0, 0x80, 0);
            gGfxEng.m_unk158E22 = 0;
        }
    }
}

// FUNCTION: 0x16B210 CameraDisplay__Fv
void CameraDisplay() {
    Camera *p = (Camera *)(gEng + 0x19760);
    if (p == 0) {
        CdsAssert__FPciPc("Debug.cpp", 0x89, "pGameCam");
    }
    p->TextDebug();
}

// FUNCTION: 0x16B260 StopTimer__5DebugFUi
void Debug::StopTimer(unsigned int nId) {
    if (this->m_unk0C != 0) {
        this->m_unk0C->StopSubTimer(nId);
    }
}

// FUNCTION: 0x16B290 StartTimer__5DebugFUi
void Debug::StartTimer(unsigned int nId) {
    if (this->m_unk0C != 0) {
        this->m_unk0C->StartSubTimer(nId);
    }
}

// FUNCTION: 0x16B580 __dt__5DebugFv
Debug::~Debug() {
    sceDevConsClose(this->m_unk00);
    if (this->m_unk0C != 0) {
        __dt__7ETimingFv(this->m_unk0C, 1);
        this->m_unk0C = 0;
    }
}
