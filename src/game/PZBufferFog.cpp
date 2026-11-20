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
