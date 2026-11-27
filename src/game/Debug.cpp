// FLAGS: -str readonly
#include "types.h"

// TODO(header): foreign declarations
extern "C" int sceDevConsPrintf(const char *pFmt, ...);
extern "C" void sceDevConsAttribute(char *pCons, unsigned char nAttr);
extern "C" void sceDevConsClear(char *pCons);
extern "C" void sceDevConsLocate(char *pCons, unsigned int nX, unsigned int nY);
extern "C" unsigned int strlen(const char *pStr);
extern "C" char *strcpy(char *pDst, const char *pSrc);
extern "C" char *strcat(char *pDst, const char *pSrc);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern char gEng[105360];
extern short mPerformanceBars;
extern short mDisplayListStatusBar;
extern short mDebugTime;
extern short mSound;
extern short gPlayerPos;
extern "C" int sprintf(char *pBuf, const char *pFmt, ...);
extern "C" void sceDevConsClose(char *pCons);
extern "C" void __dl__FPv(void *pMem);
extern short giRep;
extern short gApparition;
class Apparition {
public:
    virtual ~Apparition();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    char _pad004[0x38];
    char *m_unk3C;
    char _pad040[0x190 - 0x40];
};
extern Apparition *gpApparition;
class PArray {
public:
    int Find(void *pItem);
};

class PMat4;

class MaxEngine {
public:
    void InitRenderFrame(bool bFlag, unsigned int nId);
};

class PSound {
public:
    void SoundEditEnter();
    void SoundEditLeave();
    char _pad000[0x10];
};

extern PSound gSound;
// PSound::DebugInterface(unsigned int) takes the pad word without the andi a C++ unsigned parameter adds.
extern "C" void DebugInterface__6PSoundFUi(PSound *pThis, int nPad);

struct PadState {
    char _pad000[0x10C];
    unsigned short m_unk10C;
    char _pad10E[2];
    unsigned short m_unk110;
    char _pad112[0x10];
};

extern PadState gPad;

class FileUtils {
public:
    static int GetHung();
};

class PGfxEngine {
public:
    void UpdateLights(PMat4 *pA, PMat4 *pB, float (*pC)[4]);
    void RefreshDisplay();
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
    ETiming();
    char _pad000[0xD40];
    void InitTimers();
    void MaxesUpdate();
    void ZeroAllOneFrameVals();
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
extern "C" void sceDevConsInit();
extern "C" int sceDevConsOpen(int nX, int nY, int nW, int nH);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern "C" void sceDevConsDraw(char *pCons);
extern unsigned char gbApparition;

struct DebugTblEntry {
    int _pad000[3];
    void (*pFn)();
};

extern DebugTblEntry DebugTbl[0x1A];

#include "Debug.h"
extern short gNoDamage;

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

// DRAFT: 0x16A760 DispDebugTimer__5DebugFv
// note: 31 differing words: frame and buf size match with buf[0x40]; the compiler evaluates the 1C, 14, 18 float conversions in the order 14, 18, 1C while the original does 1C, 14, 18. All six statement orders, uA/uB/uC declaration orders, a shared float constant local, and float product locals each stay at 31 (local-temporary and early-nSub orders gave 33 and 112).
void Debug::DispDebugTimer() {
    char buf[0x40];
    static int test;
    static char init;
    unsigned int nSub = 0;

    unsigned int uA;
    unsigned int uB;
    unsigned int uC;

    if (this->m_unk24 != 0) {
        nSub = ((unsigned int *)this->m_unk24)[2];
    }
    uC = (unsigned int)((float)this->m_unk1C * *(float *)(gEng + 0x1E0));
    uA = (unsigned int)((float)this->m_unk14 * *(float *)(gEng + 0x1E0));
    uB = (unsigned int)((float)this->m_unk18 * *(float *)(gEng + 0x1E0));
    sprintf(buf, "(%d uS  %d uS, %d) %d uS / %d\n",
            uA, uB, nSub, uC, this->m_unk20);
    this->DebugDisp(buf);
    if (!init) {
        test = 0x2BC;
        init = 1;
    }
}

// FUNCTION: 0x16A940 StopDebugTimer__5DebugFPv
void Debug::StopDebugTimer(void *pArg) {
    unsigned int nNow;
    unsigned int nDelta;

    asm { mfpc nNow, 0 }
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

// FUNCTION: 0x16A990 StartDebugTimer__5DebugFv
void Debug::StartDebugTimer() {
    unsigned int nNow;

    asm { mfpc nNow, 0 }
    this->m_unk10 = nNow;
    this->m_unk20++;
}

// FUNCTION: 0x16A9B0 ResetDebugTimer__5DebugFv
void Debug::ResetDebugTimer() {
    this->m_unk14 = 0x7FFFFFFF;
    this->m_unk18 = 0;
    this->m_unk1C = 0;
    this->m_unk20 = 0;
    this->m_unk24 = 0;
}

// FUNCTION: 0x16A9D0 CdsAssert__FPciPc
void CdsAssert(char *pFile, int nLine, char *pExpr) {
    char buf[0x100];
    char hangBuf[0x40];
    char lineBuf[0x10];
    static unsigned char bLoop;
    static char init;

    if (!init) {
        bLoop = 1;
        init = 1;
    }
    char *pHead = "\n\n\nFile  : ";
    strcpy(buf, pHead);
    strcat(buf, pFile);
    strcat(buf, "\nLine  : ");
    sprintf(lineBuf, "%d", nLine);
    strcat(buf, lineBuf);
    strcat(buf, "\nError : ");
    strcat(buf, pExpr);
    if (FileUtils::GetHung()) {
        sprintf(hangBuf, "\n     HangParams %d %d", *(int *)(gEng + 0x19A74), *(int *)(gEng + 0x19A70));
        strcat(buf, hangBuf);
    }
    while (bLoop) {
        gDebug.DebugClear();
        gDebug.DebugDisp(buf);
        gGfxEng.RefreshDisplay();
    }
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

// FUNCTION: 0x16AC70 LineFeed__5DebugFPc
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

// DRAFT: 0x16ACE0 FrameEnd__5DebugFv
// note: 13 words; goto-entered loop fixes the shape, but this sits in s0 and the table pointer in s2 where the original swaps them. Tried p/i declaration and init order (13-16), increment order (14), indexed DebugTbl[i] (43), static inline loop helper (44), Debug *self copy (13).
void Debug::FrameEnd() {
    char buf[0x20];

    if (mDebugTime != 0) {
        this->m_unk0C->StopSubTimer(1);
        this->m_unk0C->MaxesUpdate();
    }
    gbApparition = 1;
    if (this->m_unk2C == 0) {
        unsigned int i;
        DebugTblEntry *p;
        i = 0;
        p = DebugTbl;
        goto test;
    loop:
            if (p->pFn != 0) {
                p->pFn();
            }
        i++;
        p++;
    test:
        if (i < 0x1A) goto loop;
    }
    if (mDebugTime != 0) {
        unsigned int nCount;
        asm { mfpc nCount, 1 }
        sprintf(buf, "D cache miss : %d\n", nCount);
        this->DebugDisp(buf);
        this->m_unk0C->ZeroAllOneFrameVals();
    }
    if (this->m_unk2D != 0) {
        sceDevConsDraw(this->m_unk00);
    }
    this->m_unk2D = 0;
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

// FUNCTION: 0x0016AE30 IsNoDamage__5DebugFv
short Debug::IsNoDamage() {
    return gNoDamage;
}

// FUNCTION: 0x16AE40 SoundEdit__Fv
static void SoundEdit() {
    if (mSound != 0) {
        gSound.SoundEditEnter();
    loop:
        ((MaxEngine *)gEng)->InitRenderFrame(false, 0);
        gDebug.DebugDispPos("Sound Edit", 0x1E, 0, 7);
        gDebug.DebugDisp("\n");
        if (!(gPad.m_unk110 & 1)) {
            DebugInterface__6PSoundFUi(&gSound, gPad.m_unk110);
            goto loop;
        }
        gSound.SoundEditLeave();
    }
}

// FUNCTION: 0x16AEE0 PlayerPosDisplay__Fv
static void PlayerPosDisplay() {
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

// DRAFT: 0x0016B010 ApparitionDisplay__Fv
// note: 13 differing words: gbApparition read as lbu from gp (-0x7C28) in the original, ours uses 0x0($gp) with a reloc; gPad lhu uses -0x40F0 in the original, ours 0x110 from $at; nA in a2 (original) vs a0 and bDirty in a3 vs a1. bool bDirty matches the daddiu flag but does not change the count. Tried decl orders (bDirty first 66, bDirty before nA 69, nB before nA 63, nRep first 13); kept nA, nB, nRep, bDirty.
static void ApparitionDisplay() {
    float *pPos;
    unsigned int nA;
    unsigned int nB;
    int nRep;
    bool bDirty;
    char aBuf[0x40];

    if (gpApparition == 0) {
        return;
    }
    if (((PArray *)(gEng + 0x18858))->Find(gpApparition) < 0) {
        gpApparition = 0;
        gApparition = 0;
        return;
    }
    if (gbApparition) {
        gpApparition->Slot3();
    }
    gbApparition = 0;
    if (gpApparition->m_unk3C) {
        pPos = (float *)(gpApparition->m_unk3C + 0x80);
    } else {
        pPos = (float *)((char *)gpApparition + 0x190);
    }
    nA = gPad.m_unk110;
    nRep = (short)(giRep - 1);
    giRep = (short)nRep;
    nB = gPad.m_unk10C;
    if (nRep == 0) {
        nA |= nB;
    }
    bDirty = false;
    if (nA & 0x50) {
        giRep = 4;
        if (nB & 0x100) {
            pPos[1] += (nA & 0x10) ? 0.1f : -0.1f;
        } else {
            pPos[2] += (nA & 0x10) ? 0.1f : -0.1f;
        }
        bDirty = true;
    }
    if (nA & 0xA0) {
        giRep = 4;
        pPos[0] += (nA & 0x20) ? 0.1f : -0.1f;
        bDirty = true;
    }
    if (bDirty) {
        if (gpApparition->m_unk3C) {
            ((unsigned char *)gpApparition->m_unk3C)[0x3E] |= 8;
        }
    }
    sprintf(aBuf, "(%f, %f, %f)\n", pPos[0], pPos[1], pPos[2]);
    gDebug.DebugDisp(aBuf);
}

// FUNCTION: 0x16B210 CameraDisplay__Fv
static void CameraDisplay() {
    Camera *p = (Camera *)(gEng + 0x19760);
    if (p == 0) {
        CdsAssert("Debug.cpp", 0x89, "pGameCam");
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

// FUNCTION: 0x16B4D0 InitDebug__5DebugFv
void Debug::InitDebug() {
    int nX;
    int nY;

    sceDevConsInit();
    nX = (0x1000 - SCREEN_WIDTH) / 2;
    nY = (0x1000 - SCREEN_HEIGHT) / 2;
    this->m_unk00 = (char *)sceDevConsOpen(nX * 0x10 + 0x100, nY * 0x10 + 0x100, 0x4B, 0x1E);
    sceDevConsClear(this->m_unk00);
    this->m_unk0C = new ETiming();
    this->m_unk0C->InitTimers();
    this->m_unk34 = 0;
}

// FUNCTION: 0x16B580 __dt__5DebugFv
Debug::~Debug() {
    sceDevConsClose(this->m_unk00);
    if (this->m_unk0C != 0) {
        __dt__7ETimingFv(this->m_unk0C, 1);
        this->m_unk0C = 0;
    }
}

// FUNCTION: 0x16B5F0 __ct__5DebugFv
Debug::Debug() {
    this->m_unk28 = 0;
    this->m_unk2C = 0;
    this->m_unk0C = 0;
}
