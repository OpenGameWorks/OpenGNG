// FLAGS: -str readonly
#include "types.h"
#include "Timing.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *pMem);

class PProgressBar {
public:
    void SetReading(float fReading);
    void Render();
};

struct PGfxEngineRef {
    char *pDisplayList;
    char _pad04[0x10];
};
extern PGfxEngineRef gGfxEng;
extern "C" char *strcat(char *pDst, char *pSrc);
extern "C" char *strcpy(char *pDst, const char *pSrc);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" long long fptodp(float fValue);
extern "C" void *__dt__12PProgressBarFv(void *pThis, short nFlag);
extern "C" void __destroy_arr(void *pArr, void *(*pDtor)(ESubTimer *, short), unsigned int nSize, int nCount);
extern "C" void *__dt__9ESubTimerFv(ESubTimer *pThis, short nFlag);
class Debug {
public:
    void DebugDisp(char *pText);
    // Debug size is unknown; the placeholder keeps gDebug out of small data (threshold 8 bytes).
    char _pad000[0x10];
};
extern Debug gDebug;
// Engine size is unknown; the placeholder keeps gEng out of small data (threshold 8 bytes).
class Engine { public: char _pad000[0x1E8]; float m_unk1E8; char _pad1EC[0x10]; };
extern Engine gEng;

// FUNCTION: 0x001695A0 GenerateStringWSuffix__9ESubTimerFPcUi
int ESubTimer::GenerateStringWSuffix(char *pOut, unsigned int nArg) {
    char aBuf[0x70];
    char aSuffix[0x10];
    *pOut = 0;
    if (m_unk045 != 0) {
        return 0;
    }
    aBuf[0] = 0;
    GenerateString(aBuf, nArg, m_unk03C);
    const char *pUs = "us";
    strcpy(aSuffix, pUs);
    if (m_unk03C & 1) {
        const char *pMs = "ms";
        strcpy(aSuffix, pMs);
    }
    sprintf(pOut, "%s: %s %s\n", (char *)m_unk040, aBuf, aSuffix);
    return 1;
}

// DRAFT: 0x00169930 ZeroTimer__9ESubTimerFv
// note: 8 differing words; the original has one extra nop before the block-loop bnez and one after it before sb 0x44 (needs -O4,p?). Tried unguarded for (12 words), top-tested while (14), guarded do-while (8, kept).
void ESubTimer::ZeroTimer() {
    m_unk000 = 0;
    m_unk004 = 0;
    m_unk008 = 0;
    m_unk00C = 0;
    m_unk010 = 0;
    m_unk014 = 0;
    int nIdx = 0;
    int nOff = 0;
    do {
        int *pBlk = (int *)((char *)this + nOff);
        pBlk[6] = 0;
        pBlk[7] = 0;
        pBlk[8] = 0;
        pBlk[9] = 0;
        pBlk[10] = 0;
        pBlk[11] = 0;
        pBlk[12] = 0;
        pBlk[13] = 0;
        nIdx += 8;
        nOff += 0x20;
    } while (nIdx <= 0);
    if (nIdx < 9) {
        int nOff2 = nIdx << 2;
        do {
            int *pW = (int *)((char *)this + nOff2);
            nIdx++;
            pW[6] = 0;
            nOff2 += 4;
        } while (nIdx < 9);
    }
    m_unk044 = 0;
    m_unk046 = 0;
}

// DRAFT: 0x00169890 StopTimer__9ESubTimerFv
// note: 8 differing lines. The mnemonic mfc0 drops the sel bit (0x4006C800, original 0x4006C801); the .word form gives v0 instead of a2. Tried .word reads, mnemonic read, and reversed max compares (9 to 8 lines); the compare load order still differs.
void ESubTimer::StopTimer() {
    if (m_unk044 != 0) {
        unsigned int nCounter;
        asm {
            .word 0x4003C801
            mfc0 nCounter, $25
        }
        m_unk004 += nCounter - m_unk000;
        m_unk044 = 0;
        if (m_unk008 < m_unk004) {
            m_unk008 = m_unk004;
            if (m_unk014 < m_unk004) {
                m_unk014 = m_unk004;
            }
        }
    }
}

// FUNCTION: 0x001699C0 __ct__9ESubTimerFv
ESubTimer::ESubTimer() {
    ZeroTimer();
    m_unk040 = 0;
    m_unk03C = 0;
    m_unk045 = 1;
}

// DRAFT: 0x00169B70 PrintDisplayListStatusMeter__7ETimingFUiP5PMat4
// note: 3 differing lines; compiler keeps this+0xAE0 in s0 (original keeps this in s0 and recomputes a0 per call). Tried pBar local (3), reordered nCount first (9), pSelf local (9), inline cast at both calls (9).
void ETiming::PrintDisplayListStatusMeter(unsigned int nUnused, PMat4 *pMat) {
    PProgressBar *pBar = (PProgressBar *)((char *)this + 0xAE0);
    int nCount = *(int *)(gGfxEng.pDisplayList + 0xA3340);
    pBar->SetReading(100.0f * ((float)nCount / 32768.0f));
    pBar->Render();
}

// FUNCTION: 0x00169BE0 PrintCalcTimings__7ETimingFv
void ETiming::PrintCalcTimings() {
    char aOut[0x800];
    aOut[0] = 0;
    float fRate = 60.0f / gEng.m_unk1E8;
    sprintf(aOut, "Frame Rate: %.0f FPS, over %d\n", fptodp(fRate), m_unkD38);
    GenerateStringWSuffixAndCat(aOut, 1);
    GenerateStringWSuffixAndCat(aOut, 2);
    GenerateStringWSuffixAndCat(aOut, 3);
    GenerateStringWSuffixAndCat(aOut, 4);
    GenerateStringWSuffixAndCat(aOut, 5);
    GenerateStringWSuffixAndCat(aOut, 6);
    GenerateStringWSuffixAndCat(aOut, 7);
    GenerateStringWSuffixAndCat(aOut, 0xE);
    gDebug.DebugDisp(aOut);
}

// FUNCTION: 0x00169CD0 PrintRenderTimings__7ETimingFv
void ETiming::PrintRenderTimings() {
    char aOut[0x800];
    aOut[0] = 0;
    float fRate = 60.0f / gEng.m_unk1E8;
    sprintf(aOut, "Frame Rate: %.0f FPS, over %d\n", fptodp(fRate), m_unkD38);
    GenerateStringWSuffixAndCat(aOut, 1);
    GenerateStringWSuffixAndCat(aOut, 8);
    GenerateStringWSuffixAndCat(aOut, 9);
    GenerateStringWSuffixAndCat(aOut, 0xA);
    GenerateStringWSuffixAndCat(aOut, 0xB);
    GenerateStringWSuffixAndCat(aOut, 0xC);
    GenerateStringWSuffixAndCat(aOut, 0xD);
    gDebug.DebugDisp(aOut);
}

// DRAFT: 0x00169DB0 GenerateStringWSuffixAndCat__7ETimingFPcUi
// note: 18 differing lines. Original copies this to v1 before the s0 save and computes the element address in v0 from v1; ours saves s0 first and keeps this in a0. Tried: aBuf[0] store after the checks (28 to 27), element pointer local (27 to 18, kept), this-copy pSelf local (18, reverted).
int ETiming::GenerateStringWSuffixAndCat(char *pDest, unsigned int nId) {
    char aBuf[0x70];
    if (nId >= 0x16) {
        return 0;
    }
    ESubTimer *pTimer = &m_aTimers[nId];
    if (pTimer->m_unk045 != 0) {
        return 0;
    }
    aBuf[0] = 0;
    pTimer->GenerateStringWSuffix(aBuf, m_unk0);
    strcat(pDest, aBuf);
    return 1;
}

// DRAFT: 0x00169E30 ZeroAllOneFrameVals__7ETimingFv
// note: guarded do-while matches the loop; 4 differing lines remain, one extra nop before the loop bnez; top-tested, counted and byte-step forms were worse.
void ETiming::ZeroAllOneFrameVals() {
    ESubTimer *pTimer = m_aTimers;
    ESubTimer *pEnd = (ESubTimer *)((char *)this + 0x634);
    if (pTimer < pEnd) {
        do {
            pTimer->m_unk004 = 0;
            pTimer++;
        } while (pTimer < pEnd);
    }
}

// FUNCTION: 0x00169FF0 StopSubTimer__7ETimingFUi
int ETiming::StopSubTimer(unsigned int nId) {
    if (nId >= 0x16) {
        return 0;
    }
    ESubTimer *pTimer = &m_aTimers[nId];
    if (pTimer->m_unk045 != 0) {
        return 0;
    }
    pTimer->StopTimer();
    return 1;
}

// FUNCTION: 0x0016A050 StartSubTimer__7ETimingFUi
int ETiming::StartSubTimer(unsigned int nId) {
    if (nId >= 0x16) {
        return 0;
    }
    ESubTimer *pTimer = &m_aTimers[nId];
    if (pTimer->m_unk045 != 0) {
        return 0;
    }
    pTimer->StartTimer();
    return 1;
}

// FUNCTION: 0x0016A0B0 InitSubTimer__7ETimingFUiPCcUi
int ETiming::InitSubTimer(unsigned int nId, const char *pName, unsigned int nArg) {
    if (nId >= 0x16) {
        return 0;
    }
    if (pName == 0) {
        return 0;
    }
    ESubTimer *pTimer = &m_aTimers[nId];
    pTimer->ZeroTimer();
    pTimer->m_unk040 = (int)pName;
    pTimer->m_unk03C = (int)nArg;
    pTimer->m_unk045 = 0;
    return 1;
}

// FUNCTION: 0x0016A130 FindTimer__7ETimingFUi
ESubTimer *ETiming::FindTimer(unsigned int nId) {
    if (nId >= 0x16) {
        return 0;
    }
    ESubTimer *pTimer = &m_aTimers[nId];
    if (pTimer->m_unk045 != 0) {
        return 0;
    }
    return pTimer;
}

// FUNCTION: 0x0016A300 __dt__7ETimingFv
extern "C" void *__dt__7ETimingFv(ETiming *pThis, short nFlag) {
    if (pThis != 0) {
        __dt__12PProgressBarFv((char *)pThis + 0xAE0, -1);
        __dt__12PProgressBarFv((char *)pThis + 0x890, -1);
        __dt__12PProgressBarFv((char *)pThis + 0x640, -1);
        __destroy_arr(pThis->m_aTimers, __dt__9ESubTimerFv, 0x48, 0x16);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0016A390 __dt__9ESubTimerFv
extern "C" void *__dt__9ESubTimerFv(ESubTimer *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
