// FLAGS: -str readonly
#include "types.h"
#include "PZBufferFog.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void __dl__FPv(void *pMem);
struct tagGsClut256;
void GsSwizzleClut(tagGsClut256 *pClut);
extern float GAME_FPS;
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0ClampVector(float *pDst, float *pSrc, float fMin, float fMax);
extern "C" void sceVu0InterVector(float *pDst, float *pA, float *pB, float fT);

// FUNCTION: 0x1CE1B0 TweenClutFog__11PZBufferFogFP14tagClutFogDataP14tagClutFogDataf
void PZBufferFog::TweenClutFog(tagClutFogData *pStart, tagClutFogData *pEnd, float fTime) {
    if (pStart == 0) {
        CdsAssert__FPciPc("PZBufferFog.cpp", 0x139, "pStart");
    }
    if (pEnd == 0) {
        CdsAssert__FPciPc("PZBufferFog.cpp", 0x13A, "pEnd");
    }
    memcpy(m_unk17B0, pStart, 0x50);
    memcpy(m_unk1800, pEnd, 0x50);
    m_unk1850 = 0;
    m_unk1854 = 1.0f / (fTime * GAME_FPS);
    m_unk17AC = 1;
}

// FUNCTION: 0x1CE280 SetClutFogTable__11PZBufferFogFP6GsRGBA
void PZBufferFog::SetClutFogTable(GsRGBA *pClut) {
    if (pClut == 0) {
        CdsAssert__FPciPc("PZBufferFog.cpp", 0x130, "pClut");
    }
    memcpy(m_unk1350, pClut, 0x400);
    GsSwizzleClut((tagGsClut256 *)m_unk12F0);
}

// DRAFT: 0x1CE2E0 SetClutFogAlpha__11PZBufferFogFf
// note: 30 words differ; bc1t target and polarity at 0x30/0x48, mul.s lands in f0 not f1; ternary clamp 33, operand swap 30, flipped outer test 32.
void PZBufferFog::SetClutFogAlpha(float fAlpha) {
    float fMin = 1.0f;
    if (fAlpha < 1.0f) {
        fMin = fAlpha;
    }
    if (!(fMin <= 0.0f)) {
        if (fAlpha >= 1.0f) {
            fAlpha = 1.0f;
        }
    } else {
        fAlpha = 0.0f;
    }
    float fScaled = 128.0f * fAlpha;
    int nAlpha;
    if (!(fScaled >= 2147483648.0f)) {
        nAlpha = (int)fScaled;
    } else {
        nAlpha = (int)(fScaled - 2147483648.0f) | 0x80000000;
    }
    m_unk17AB = (unsigned char)nAlpha;
}

// DRAFT: 0x1CE3B0 SetDensity__11PZBufferFogFfbf
// note: 80 words differ; mul.s/div.s land in f1 not f12, outer fMin branch polarity and bc1t target differ; bFlag arms compile; tried outer restructure (82) and fMin > 0 form (80)
void PZBufferFog::SetDensity(float fDensity, bool bFlag, float fTime) {
    float fTarget = (fDensity * 0.9f) / 100.0f;
    float fMin = 1.0f;
    if (fTarget < 1.0f) {
        fMin = fTarget;
    }
    if (!(fMin <= 0.0f)) {
        if (fTarget < 1.0f) {
        } else {
            fTarget = 1.0f;
        }
    } else {
        fTarget = 0.0f;
    }
    if (bFlag) {
        m_unk1758 = fTarget;
        float fRate = (fTarget - m_unk1754) * (1.0f / (fTime * GAME_FPS));
        m_unk175C = fRate;
        if (FastMath_Fabs__Ff(fRate) < 0.000001f) {
            m_unk175C = 0.0f;
        }
        if (m_unk1758 == 0.0f || m_unk1754 == 0.0f) {
            m_unk1760 = 0x4A800000;
            m_unk1764 = 0x4B800000;
        } else {
            m_unk1760 = 0x4A800000;
            m_unk1764 = 0x4B800000;
        }
        if (m_unk175C != 0.0f) {
            m_unk17A4 = (int)(fTime * GAME_FPS);
        }
    } else {
        m_unk1758 = fTarget;
        m_unk1754 = fTarget;
        m_unk175C = 0.0f;
        m_unk1760 = 0x4A800000;
        m_unk1764 = 0x4B800000;
        m_unk17A4 = 0;
    }
    m_unk17A9 = 1;
}

// FUNCTION: 0x1CE570 SetColor__11PZBufferFogFPfbf
void PZBufferFog::SetColor(float *pColor, bool bFlag, float fTime) {
    if (bFlag) {
        *(u_long128 *)&m_unk1780 = *(u_long128 *)pColor;
        sceVu0SubVector((float *)&m_unk1790, (float *)&m_unk1780, (float *)&m_unk1770);
        sceVu0ScaleVector((float *)&m_unk1790, (float *)&m_unk1790, 1.0f / (fTime * GAME_FPS));
        m_unk17A0 = (int)(fTime * GAME_FPS);
        return;
    }
    *(u_long128 *)&m_unk1780 = *(u_long128 *)pColor;
    *(u_long128 *)&m_unk1770 = *(u_long128 *)pColor;
    m_unk1790[2] = 0;
    m_unk1790[1] = 0;
    m_unk1790[0] = 0;
    m_unk1790[3] = 0x3F800000;
    m_unk17A0 = 0;
}

// DRAFT: 0x1CEA10 Animate__11PZBufferFogFf
// note: 95 words differ; our body is 3 instructions short; beqz/blez targets and bc1t/bc1f polarity at 0x5C/0x74 differ; tried ladder store placement (98), ladder ternary (95), else-arm inline (95), direct m_unk1850 read (95)
void PZBufferFog::Animate(float fDelta) {
    char sp20[0x50];
    if (m_unk17A9 != 0) {
        if (m_unk17A4 > 0) {
            float fMin = 1.0f;
            float fNext = m_unk1754 + m_unk175C;
            m_unk1754 = fNext;
            if (fNext < 1.0f) {
                fMin = fNext;
            }
            if (!(fMin <= 0.0f)) {
                if (fNext < 1.0f) {
                } else {
                    fNext = 1.0f;
                }
            } else {
                fNext = 0.0f;
            }
            m_unk1754 = fNext;
            m_unk17A4 -= 1;
        }
        if (m_unk1754 == 0.0f) {
            m_unk17A9 = 0;
            m_unk1750 = 0x4B800000;
            m_unk17A4 = 0;
            m_unk17A0 = 0;
        } else {
            float fHi = *(float *)&m_unk1764;
            *(float *)&m_unk1750 = fHi + m_unk1754 * (*(float *)&m_unk1760 - fHi);
            if (m_unk17A0 > 0) {
                sceVu0AddVector((float *)m_unk1770, (float *)m_unk1770, (float *)m_unk1790);
                sceVu0ClampVector((float *)m_unk1770, (float *)m_unk1770, 0.0f, 255.0f);
                m_unk17A0 -= 1;
            }
        }
        if (m_unk17AC != 0 && m_unk17AA != 0) {
            float fT = m_unk1850;
            if (fT <= 1.0f) {
                sceVu0InterVector((float *)sp20, (float *)m_unk1800, (float *)m_unk17B0, fT);
                sceVu0InterVector((float *)(sp20 + 0x10), (float *)(m_unk1800 + 0x10), (float *)(m_unk17B0 + 0x10), m_unk1850);
                sceVu0InterVector((float *)(sp20 + 0x20), (float *)(m_unk1800 + 0x20), (float *)(m_unk17B0 + 0x20), m_unk1850);
                sceVu0InterVector((float *)(sp20 + 0x30), (float *)(m_unk1800 + 0x30), (float *)(m_unk17B0 + 0x30), m_unk1850);
                sceVu0InterVector((float *)(sp20 + 0x40), (float *)(m_unk1800 + 0x40), (float *)(m_unk17B0 + 0x40), m_unk1850);
                m_unk1850 += m_unk1854;
                SetClutFogTable((tagClutFogData *)sp20);
                return;
            }
            m_unk1850 = 1.0f;
            m_unk17AC = 0;
        }
    }
}

// FUNCTION: 0x1CEE20 __dt__11PZBufferFogFv
PZBufferFog::~PZBufferFog() {
}

// FUNCTION: 0x1CEE70 __ct__11PZBufferFogFv
PZBufferFog::PZBufferFog() {
    m_unk17A9 = 0;
    m_unk1750 = 0x4B800000;
    m_unk1754 = 0;
    m_unk1758 = 0;
    m_unk17AA = 0;
    m_unk17AB = 0x80;
    m_unk17A8 = 0;
    m_unk1770[2] = 0;
    m_unk1770[1] = 0;
    m_unk1770[0] = 0;
    m_unk1770[3] = 0x3F800000;
    m_unk1780[2] = 0;
    m_unk1780[1] = 0;
    m_unk1780[0] = 0;
    m_unk1780[3] = 0x3F800000;
    m_unk17AC = 0;
    memset(m_unk17B0, 0, 0x50);
    memset(m_unk1800, 0, 0x50);
    m_unk1850 = 0;
    m_unk1854 = 0;
}
