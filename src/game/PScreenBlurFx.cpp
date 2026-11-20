// FLAGS: -str readonly
#include "types.h"
#include "PScreenBlurFx.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void __dl__FPv(void *);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern "C" void CdsAssert__FPciPc(char *, int, char *);

// DRAFT: 0x00216720 InitBlurStrip__13PScreenBlurFxFP12tagBlurStripcssssfbff
// note: 69 words differ; the sC/sA temporaries get a0/v1 (original v1/a0), nX lands in a3 (original a1), and the prologue frame and save layout differ. Tried: float-first, int-first, shift instead of multiply, readonly flag.
void PScreenBlurFx::InitBlurStrip(tagBlurStrip *pStrip, char cA, short sA, short sB, short sC, short sD, float fA, bool bFlag, float fB, float fC) {
    if (pStrip == 0) {
        CdsAssert__FPciPc("PScreenBlurFx.cpp", 0xF7, "pStrip");
    }
    int nStepX = sC << 4;
    int nX = sA << 4;
    float fStep = fB / 33.0f;
    float fEdge = fA + fC / 16.0f;
    int nW = sB << 4;
    int nWW = (sB + sD) * 0x10;
    float fAcc = 0.0f;
    char *pBase = (char *)pStrip;
    int nOff = 0;
    int i = 0;
    do {
        char *p = pBase + nOff;
        *(float *)(p + 0x00) = fAcc;
        *(float *)(p + 0x04) = fA;
        *(float *)(p + 0x08) = 1.0f;
        *(int *)(p + 0x10) = nX;
        *(int *)(p + 0x14) = nW;
        *(float *)(p + 0x20) = fAcc;
        *(float *)(p + 0x24) = fEdge;
        *(float *)(p + 0x28) = 1.0f;
        *(int *)(p + 0x30) = *(int *)(p + 0x10);
        *(int *)(p + 0x34) = nWW;
        if (bFlag) {
            if (i == 0) {
                p[0x1D] = (p[0x1D] & ~0x80) | 0x80;
                p[0x3D] = (p[0x3D] & ~0x80) | 0x80;
            }
        }
        i++;
        fAcc += fStep;
        nX += nStepX;
        nOff += 0x40;
    } while (i < 0x21);
}

// FUNCTION: 0x00217120 SkipToFadeOut__13PScreenBlurFxFv
void PScreenBlurFx::SkipToFadeOut() {
    if (m_unk84A0 != 4 || m_unk84A0 != 3) {
        m_unk846C = m_unk8464;
        m_unk84A0 = 3;
        *(u_long128 *)m_unk8480 = *(u_long128 *)m_unk8470;
    }
}

// FUNCTION: 0x00217190 Init__13PScreenBlurFxFfffffffb
int PScreenBlurFx::Init(float fA1, float fA2, float fA3, float fA4, float fA5, float fA6, float fA7, bool bFlag) {
    m_unk8450 = 0;
    m_unk8454 = 1.0f;
    m_unk8470[0] = fA4;
    m_unk8470[1] = fA5;
    m_unk8470[2] = fA6;
    m_unk8470[3] = fA7;
    m_unk8460 = fA1;
    m_unk8464 = fA3;
    m_unk8468 = fA2;
    m_unk846C = m_unk8460;
    m_unk84A0 = 1;
    float fRatio = m_unk8470[3] / m_unk8460;
    m_unk8490 = 0;
    m_unk8494 = 0;
    m_unk8498 = 0;
    m_unk849C = fRatio;
    *(u_long128 *)m_unk8480 = *(u_long128 *)m_unk8470;
    m_unk8480[3] = 0;
    m_unk84A4 = bFlag;
    if (bFlag) {
        m_unk8458 = (float)SCREEN_WIDTH / 1024.0f;
        m_unk845C = (float)SCREEN_HEIGHT / 256.0f;
        InitBlurPacket((tagGsScreenBlurPacket *)m_unk10, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 0);
    } else {
        m_unk8458 = 1.0f;
        m_unk845C = 1.0f;
        InitBlurPacket((tagGsScreenBlurPacket *)m_unk10, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 0);
    }
    return 1;
}

// FUNCTION: 0x00217370 __dt__13PScreenBlurFxFv
extern "C" void *__dt__13PScreenBlurFxFv(PScreenBlurFx *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x002173C0 __ct__13PScreenBlurFxFv
PScreenBlurFx::PScreenBlurFx() {
    memset(m_unk10, 0, 0x8440);
    m_unk84A0 = 4;
}
