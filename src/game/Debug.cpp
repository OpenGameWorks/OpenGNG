// FLAGS: -str readonly
#include "types.h"

// TODO(header): foreign declarations
extern "C" int sceDevConsPrintf(const char *pFmt, ...);
extern "C" void sceDevConsAttribute(char *pCons, unsigned char nAttr);
extern "C" void sceDevConsClear(char *pCons);
extern "C" unsigned int strlen(const char *pStr);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern char gEng[105360];
extern short mPerformanceBars;
extern short mDisplayListStatusBar;
extern short mDebugTime;

class PMat4;

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

#include "Debug.h"

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
