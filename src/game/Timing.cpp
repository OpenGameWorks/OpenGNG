// COMPILER: mwcps2-3.0-011126
// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Timing.h"
#include "PGfxEngine.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *pMem);

class PProgressBar {
public:
    void SetReading(float fReading);
    void Render();
    void Init(float fX, float fY, float fW, float fH, int nFrames);
    void SetColor1(float fR, float fG, float fB, float fA);
    void SetColor2(float fR, float fG, float fB, float fA);
    void SetBgColor(float fR, float fG, float fB, float fA);
    void SetRange(float fRange);
    void ResetReading();
};

struct PGfxEngineRef {
    char *pDisplayList;
    char _pad04[0x10];
};
extern PGfxEngine gGfxEng;
extern float GAME_FPS;
extern "C" char *strcat(char *pDst, char *pSrc);
extern "C" char *strcpy(char *pDst, const char *pSrc);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" long long fptodp(float fValue);
extern "C" void *__dt__12PProgressBarFv(void *pThis, short nFlag);
extern "C" void __destroy_arr(void *pArr, void *(*pDtor)(ESubTimer *, short), unsigned int nSize, int nCount);
extern "C" void *__dt__9ESubTimerFv(ESubTimer *pThis, short nFlag);
extern "C" void *__ct__9ESubTimerFv(void *pThis);
extern "C" void *__ct__12PProgressBarFv(void *pThis);
extern "C" void *__construct_array(void *pBlock, void *(*pCtor)(void *), void *(*pDtor)(void *, short), int nSize, int nCount);
extern int SCREEN_HEIGHT;
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

// DRAFT: 0x00169640 GenerateString__9ESubTimerFPcUiUi
// note: DIFF 113 under 011126 (110 under 3.0.3); beqz skip length, assert delay slot, float compare shape (c.le.s vs c.lt.s), nArg2==1 float scheduling, tail scheduling. Tried: nMask per-branch, fScaled condition reversed, aAcc[0x70] frame 0x100.
void ESubTimer::GenerateString(char *pOut, unsigned int nArg, unsigned int nArg2) {
    char aTmp[0x20];
    char aAcc[0x70];
    int nTime = 0;
    unsigned int nMask = nArg;
    int nCount = 0;
    aAcc[0] = 0;
    if (nArg != 0) {
        do {
            unsigned int nPrev = nMask;
            if (nMask & 1) {
                nTime = m_unk004;
                nMask &= -2;
            } else if (nMask & 2) {
                nTime = m_unk00C;
                nMask &= -3;
            } else if (nMask & 4) {
                nTime = m_unk010;
                nMask &= -5;
            } else if (nMask & 8) {
                nTime = m_unk014;
                nMask &= -9;
            }
            ((nPrev != nMask) ? (void)0 : CdsAssert("Timing.cpp", 0x356, "uDurationStylePre != uDurationStyle"));
            if (nCount > 0) {
                strcat(aAcc, ", ");
            }
            if (nArg2 == 1) {
                float fVal;
                if (nTime >= 0) {
                    fVal = (float)nTime;
                } else {
                    fVal = 2.0f * (float)(((unsigned int)nTime >> 1) | (nTime & 1));
                }
                sprintf(aTmp, "%.0f", (double)((fVal * gEng.m_unk1E8) / 1000.0f));
            } else {
                float fVal2;
                if (nTime >= 0) {
                    fVal2 = (float)nTime;
                } else {
                    fVal2 = 2.0f * (float)(((unsigned int)nTime >> 1) | (nTime & 1));
                }
                float fScaled = fVal2 * gEng.m_unk1E8;
                int nInt;
                if (!(fScaled >= 2.1474836e9f)) {
                    nInt = (int)fScaled;
                } else {
                    nInt = (int)(fScaled - 2.1474836e9f) | 0x80000000;
                }
                sprintf(aTmp, "% 5d", nInt);
            }
            strcat(aAcc, aTmp);
            nCount += 1;
        } while (nMask != 0);
    }
    strcat(pOut, aAcc);
}

// DRAFT: 0x00169890 StopTimer__9ESubTimerFv
// note: 8 differing words; the compare loads m_unk008 into a1 first and m_unk004 into v1, while ours loads m_unk004 first, so the two compares differ in operand registers. Tried <, > (8), explicit sum temp (8), hoisted declarations (8), nElapsed local, nMax local loaded before the compare, swapped local order, `!(m_unk004 <= m_unk008)`, unsigned casts, expanded sum, `this->` prefix, sum through nCounter (10); all keep the swapped a1/v1 operands. Also tried: inline max-update helpers (8, 17), separate asm statements, int counters, swapped asm locals, > compares (all 8). Also tried: two sequential ifs (9), inner compare against m_unk008 (8), `m_unk004 > m_unk0xx` (8).
void ESubTimer::StopTimer() {
    if (m_unk044 != 0) {
        unsigned int nDummy;
        unsigned int nCounter;
        asm {
            mfpc nDummy, 0
            mfpc nCounter, 0
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

// FUNCTION: 0x00169900 GetTime__9ESubTimerFv
int ESubTimer::GetTime() {
    return *(int *)((char *)this + 0x4);
}

// FUNCTION: 0x00169910 StartTimer__9ESubTimerFv
void ESubTimer::StartTimer() {
    unsigned int nCounter;
    m_unk044 = 1;
    asm { mfpc nCounter, 0 }
    m_unk000 = nCounter;
}

// FUNCTION: 0x00169930 ZeroTimer__9ESubTimerFv
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

// FUNCTION: 0x001699C0 __ct__9ESubTimerFv
ESubTimer::ESubTimer() {
    ZeroTimer();
    m_unk040 = 0;
    m_unk03C = 0;
    m_unk045 = 1;
}

// FUNCTION: 0x00169A00 PrintPerformanceMeter__7ETimingFUiP5PMat4
void ETiming::PrintPerformanceMeter(unsigned int nUnused, PMat4 *pMat) {
    unsigned int nDelta = gGfxEng.m_unk158E18 - gGfxEng.m_unk158E14;
    float fFrame = (1000.0f / GAME_FPS) - 0.5f;
    unsigned int nCount = gGfxEng.m_unk158E0C;
    ((PProgressBar *)m_unk640)->SetReading(100.0f * ((((3.3333333f * (float)nCount) / 1000.0f) / 1000.0f) / fFrame));
    ((PProgressBar *)m_unk890)->SetReading(100.0f * ((((3.3333333f * (float)nDelta) / 1000.0f) / 1000.0f) / fFrame));
    ((PProgressBar *)m_unk640)->Render();
    ((PProgressBar *)m_unk890)->Render();
}

// FUNCTION: 0x00169B70 PrintDisplayListStatusMeter__7ETimingFUiP5PMat4
void ETiming::PrintDisplayListStatusMeter(unsigned int nUnused, PMat4 *pMat) {
    int nCount = gGfxEng.m_unk154C80->m_unkA3340;
    ((PProgressBar *)m_unkAE0)->SetReading(100.0f * ((float)nCount / 32768.0f));
    ((PProgressBar *)m_unkAE0)->Render();
}

// FUNCTION: 0x00169BE0 PrintCalcTimings__7ETimingFv
void ETiming::PrintCalcTimings() {
    char aOut[0x800];
    aOut[0] = 0;
    float fRate = 60.0f / gEng.m_unk1E8;
    sprintf(aOut, "Frame Rate: %.0f FPS, over %d\n", (double)fRate, m_unkD38);
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
    sprintf(aOut, "Frame Rate: %.0f FPS, over %d\n", (double)fRate, m_unkD38);
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
// note: 18 differing lines. Original copies this to v1 before the s0 save and computes the element address in v0 from v1; ours saves s0 first and keeps this in a0. Tried: aBuf[0] store after the checks (28 to 27), element pointer local (27 to 18, kept), this-copy pSelf local (18, reverted), aBuf[0] store before the checks (19; the sb moves to the bnez delay slot as in the original, but pTimer takes a0 and this stays in a0), pSelf for this/m_unk0 with store first (19), pTimer declared then assigned late (19), pSelf for every access (19).
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

// FUNCTION: 0x00169E30 ZeroAllOneFrameVals__7ETimingFv
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

// DRAFT: 0x00169E70 MaxesUpdate__7ETimingFv
// note: frame-count and ring-index logic matches the asm; the per-timer max loop still differs (see fncmp).
void ETiming::MaxesUpdate() {
    ESubTimer *pFrame = FindTimer(1);
    if (pFrame != 0) {
        int nTime = pFrame->GetTime();
        float fTime;
        if (nTime < 0) {
            float fHalf = (float)(int)(((unsigned int)nTime >> 1) | (nTime & 1));
            fTime = fHalf + fHalf;
        } else {
            fTime = (float)nTime;
        }
        float fScaled = fTime * gEng.m_unk1E8;
        int nScaled;
        if (!(fScaled >= 2.1474836e9f)) {
            nScaled = (int)fScaled;
        } else {
            nScaled = (int)(fScaled - 2.1474836e9f) | 0x80000000;
        }
        if ((unsigned int)nScaled >= 0x3CF1U) {
            m_unkD38 += 1;
        }
    }
    m_unkD34 -= 1;
    if (m_unkD34 <= 0) {
        m_unkD34 = 0x14;
        m_unkD30 += 1;
        if (m_unkD30 >= 9U) {
            m_unkD30 = 0;
        }
        ESubTimer *pEntry = m_aTimers;
        ESubTimer *pEnd = (ESubTimer *)((char *)this + 0x634);
        if (pEntry < pEnd) {
            do {
                pEntry->m_unk00C = pEntry->m_unk008;
                *(int *)((char *)pEntry + 0x18 + m_unkD30 * 4) = (int)pEntry->m_unk008;
                pEntry->m_unk008 = 0;
                pEntry->m_unk010 = 0;
                unsigned int *pWord = (unsigned int *)((char *)pEntry + 0x18);
                unsigned int *pWordEnd = (unsigned int *)((char *)pEntry + 0x3C);
                if (pWord < pWordEnd) {
                    do {
                        unsigned int nWord = *pWord;
                        if (pEntry->m_unk010 < nWord) {
                            pEntry->m_unk010 = nWord;
                        }
                        pWord++;
                    } while (pWord < pWordEnd);
                }
                pEntry++;
            } while (pEntry < pEnd);
        }
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

// FUNCTION: 0x0016A170 InitTimers__7ETimingFv
void ETiming::InitTimers() {
    InitSubTimer(0U, "Render", 1U);
    InitSubTimer(1U, "Game Loop", 0U);
    InitSubTimer(2U, "Physics", 0U);
    InitSubTimer(3U, "Collision", 0U);
    InitSubTimer(4U, "Camera", 0U);
    InitSubTimer(5U, "Level Animation", 0U);
    InitSubTimer(6U, "Obj Animation", 0U);
    InitSubTimer(7U, "Effects Update", 0U);
    InitSubTimer(8U, "Main World", 0U);
    InitSubTimer(9U, "Object", 0U);
    InitSubTimer(0xAU, "Effect", 0U);
    InitSubTimer(0xBU, "Interface", 0U);
    InitSubTimer(0xCU, "Skybox", 0U);
    InitSubTimer(0xDU, "Shadow", 0U);
    InitSubTimer(0xEU, "Entity", 0U);
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
ESubTimer::~ESubTimer() {}

// DRAFT: 0x0016A3E0 __ct__7ETimingFv
// note: DIFF 51; bar Init/SetRange temps differ (this reload a2/v1 vs a0/v0, float constant order). Tried: explicit construct_array removed (184 to 132), member-array bar form (132 to 51).
ETiming::ETiming() {
    __ct__12PProgressBarFv((char *)this + 0x640);
    __ct__12PProgressBarFv((char *)this + 0x890);
    __ct__12PProgressBarFv((char *)this + 0xAE0);
    ((PProgressBar *)m_unk640)->Init(610.0f, (float)SCREEN_HEIGHT - 4.0f, 15.0f, 65.0f, 120);
    ((PProgressBar *)m_unk640)->SetColor1(0.0f, 180.0f, 0.0f, 80.0f);
    ((PProgressBar *)m_unk640)->SetColor2(180.0f, 0.0f, 0.0f, 80.0f);
    ((PProgressBar *)m_unk640)->SetBgColor(40.0f, 40.0f, 40.0f, 80.0f);
    ((PProgressBar *)m_unk640)->SetRange(100.0f);
    ((PProgressBar *)m_unk640)->ResetReading();
    ((PProgressBar *)m_unk890)->Init(590.0f, (float)SCREEN_HEIGHT - 4.0f, 15.0f, 65.0f, 120);
    ((PProgressBar *)m_unk890)->SetColor1(0.0f, 0.0f, 180.0f, 80.0f);
    ((PProgressBar *)m_unk890)->SetColor2(180.0f, 0.0f, 0.0f, 80.0f);
    ((PProgressBar *)m_unk890)->SetBgColor(65.0f, 65.0f, 65.0f, 80.0f);
    ((PProgressBar *)m_unk890)->SetRange(100.0f);
    ((PProgressBar *)m_unk890)->ResetReading();
    ((PProgressBar *)m_unkAE0)->Init(610.0f, (float)SCREEN_HEIGHT - 4.0f, 15.0f, 65.0f, 120);
    ((PProgressBar *)m_unkAE0)->SetColor1(180.0f, 180.0f, 180.0f, 80.0f);
    ((PProgressBar *)m_unkAE0)->SetColor2(180.0f, 0.0f, 0.0f, 80.0f);
    ((PProgressBar *)m_unkAE0)->SetBgColor(40.0f, 40.0f, 40.0f, 80.0f);
    ((PProgressBar *)m_unkAE0)->SetRange(100.0f);
    ((PProgressBar *)m_unkAE0)->ResetReading();
    m_unkD30 = 0;
    m_unkD34 = 0x14;
    m_unk0 = 1;
    m_unkD38 = 0;
    m_unk634 = 0;
    m_unk638 = 0;
    m_unk63C = 0;
}
