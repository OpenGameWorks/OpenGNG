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
extern char gGfxEng[1504384];
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
struct tagFogSpritePacket;
struct tagTexturedFogSpritePacket;
struct tagMoveRgToBaPacket;
void GsInitMoveRG2BAPacket(tagMoveRgToBaPacket *pPacket, short nA, short nB, short nC, short nD);
void GsInitFogSprite(tagFogSpritePacket *pPacket, char nA, char nB, char nC, unsigned int nD);
void GsInitTexturedFogSprite(tagTexturedFogSpritePacket *pPacket, char nA, char nB, char nC, unsigned int nD);
void GsInitClut256(tagGsClut256 *pClut);
enum eGsContext { eGsContext_Placeholder = 0 };
class PDisplayList {
public:
    void SetGsRegisters(u_long128 *pRegData, int nNumRegs);
    void SetVifCodes(unsigned int nA, unsigned int nB);
    void SendGsPacket(void *pData, int nSize, bool bFlag);
};
class PGfxEngine {
public:
    void SetZBufferUpdate(bool bEnable, eGsContext eCtx);
    void SetCurFrameBufferAs8BitTexture(tagGsClut256 *pClut);
};

#define CLUT_U8(v) ((v) >= 2147483648.0f ? ((int)((v) - 2147483648.0f) | 0x80000000) : (int)(v))
#define CLUT_LERP(a, b, t) ((a) + (t) * ((b) - (a)))

// DRAFT: 0x001CD8C0 SetClutFogTable__11PZBufferFogFP14tagClutFogData
// note: 561 words differ; x loaded into f0 not f1 and 2^31 into f1 (c.lt.s f0,f1 vs original c.le.s f0,f1); big-path andi 0xFF extra; tried direct aClut entries (615), pDst entries (621), no casts (615)
void PZBufferFog::SetClutFogTable(tagClutFogData *pData) {
    unsigned char aClut[0x400];
    unsigned char *pDst;
    int t0;
    int t1;
    float fT;

    pDst = aClut;
    pDst[0] = (unsigned char)CLUT_U8(255.0f * pData->unk40);
    pDst[1] = (unsigned char)CLUT_U8(255.0f * pData->unk44);
    pDst[2] = (unsigned char)CLUT_U8(255.0f * pData->unk48);
    pDst[3] = (unsigned char)CLUT_U8(128.0f * pData->unk4C);

    t0 = 1;
    t1 = 4;
    do {
        fT = (float)t0 / 32.0f;
        pDst = aClut + t1;
        pDst[0] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk40, pData->unk30, fT));
        pDst[1] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk44, pData->unk34, fT));
        pDst[2] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk48, pData->unk38, fT));
        pDst[3] = (unsigned char)CLUT_U8(128.0f * CLUT_LERP(pData->unk4C, pData->unk3C, fT));
        t0 += 1;
        t1 += 4;
    } while (t0 < 0x20);

    t0 = 0x20;
    t1 = 0x80;
    do {
        fT = (float)(t0 - 0x20) / 32.0f;
        pDst = aClut + t1;
        pDst[0] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk30, pData->unk20, fT));
        pDst[1] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk34, pData->unk24, fT));
        pDst[2] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk38, pData->unk28, fT));
        pDst[3] = (unsigned char)CLUT_U8(128.0f * CLUT_LERP(pData->unk3C, pData->unk2C, fT));
        t0 += 1;
        t1 += 4;
    } while (t0 < 0x40);

    t0 = 0x40;
    t1 = 0x100;
    do {
        fT = (float)(t0 - 0x40) / 32.0f;
        pDst = aClut + t1;
        pDst[0] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk20, pData->unk10, fT));
        pDst[1] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk24, pData->unk14, fT));
        pDst[2] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk28, pData->unk18, fT));
        pDst[3] = (unsigned char)CLUT_U8(128.0f * CLUT_LERP(pData->unk2C, pData->unk1C, fT));
        t0 += 1;
        t1 += 4;
    } while (t0 < 0x60);

    t0 = 0x60;
    t1 = 0x180;
    do {
        fT = (float)(t0 - 0x60) / 32.0f;
        pDst = aClut + t1;
        pDst[0] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk10, pData->unk0, fT));
        pDst[1] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk14, pData->unk4, fT));
        pDst[2] = (unsigned char)CLUT_U8(255.0f * CLUT_LERP(pData->unk18, pData->unk8, fT));
        pDst[3] = (unsigned char)CLUT_U8(128.0f * CLUT_LERP(pData->unk1C, pData->unkC, fT));
        t0 += 1;
        t1 += 4;
    } while (t0 < 0x7F);

    pDst = aClut + 0x1FC;
    pDst[0] = (unsigned char)CLUT_U8(255.0f * pData->unk0);
    pDst[1] = (unsigned char)CLUT_U8(255.0f * pData->unk4);
    pDst[2] = (unsigned char)CLUT_U8(255.0f * pData->unk8);
    pDst[3] = (unsigned char)CLUT_U8(128.0f * pData->unkC);

    SetClutFogTable((GsRGBA *)aClut);
}

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

#define PZ_FLOAT_TO_S8(v) ((unsigned char)(((v) < 2147483648.0f) ? (int)(v) : ((int)((v) - 2147483648.0f) | 0x80000000)))

// DRAFT: 0x1CE630 Render__11PZBufferFogFv
void PZBufferFog::Render() {
    unsigned long long aRegs[4];
    if (m_unk17A9 != 0 && m_unk1754 != 0.0f) {
        aRegs[0] = 1;
        aRegs[1] = 0x1A;
        aRegs[2] = 0;
        aRegs[3] = 0x1B;
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SetGsRegisters((u_long128 *)aRegs, 2);
        int nX = *(int *)(gGfxEng + 0x158DF0);
        int nA = (nX < 0 ? nX + 0x1FFF : nX) >> 13;
        int nW = (SCREEN_WIDTH < 0 ? SCREEN_WIDTH + 0x3F : SCREEN_WIDTH) >> 6;
        *(long long *)((char *)this + 0x10) = (long long)(short)nA | ((long long)nW << 16) | 0x3FFF00000000LL | 0x02000000LL;
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SendGsPacket((void *)this, 0xAD0, true);
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SetVifCodes(0x13000000U, 0x13000000U);
        ((PGfxEngine *)gGfxEng)->SetZBufferUpdate(false, (eGsContext)0);
        aRegs[0] = 0x80ULL << 32;
        aRegs[1] = 0x3B;
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SetGsRegisters((u_long128 *)aRegs, 1);
        if (m_unk17AA != 0) {
            *((unsigned char *)this + 0xDE0) = PZ_FLOAT_TO_S8(((float *)m_unk1770)[0]);
            *((unsigned char *)this + 0xDE1) = PZ_FLOAT_TO_S8(((float *)m_unk1770)[1]);
            *((unsigned char *)this + 0xDE2) = PZ_FLOAT_TO_S8(((float *)m_unk1770)[2]);
            *((unsigned char *)this + 0xDE3) = m_unk17AB;
            ((PGfxEngine *)gGfxEng)->SetCurFrameBufferAs8BitTexture((tagGsClut256 *)m_unk12F0);
            (*(PDisplayList **)(gGfxEng + 0x154C80))->SendGsPacket((void *)((char *)this + 0xDA0), 0x550, true);
        } else {
            *((unsigned char *)this + 0xB10) = PZ_FLOAT_TO_S8(((float *)m_unk1770)[0]);
            *((unsigned char *)this + 0xB11) = PZ_FLOAT_TO_S8(((float *)m_unk1770)[1]);
            *((unsigned char *)this + 0xB12) = PZ_FLOAT_TO_S8(((float *)m_unk1770)[2]);
            *((unsigned char *)this + 0xB13) = 0x80;
            (*(PDisplayList **)(gGfxEng + 0x154C80))->SendGsPacket((void *)((char *)this + 0xAD0), 0x2D0, true);
        }
        ((PGfxEngine *)gGfxEng)->SetZBufferUpdate(true, (eGsContext)0);
        aRegs[0] = 0;
        aRegs[1] = 0x1A;
        aRegs[2] = 0x18;
        aRegs[3] = 0x1B;
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SetGsRegisters((u_long128 *)aRegs, 2);
    }
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

// DRAFT: 0x1CEC10 Init__11PZBufferFogFv
void PZBufferFog::Init() {
    int nX = *(int *)(gGfxEng + 0x158E04);
    int nA = (nX < 0 ? nX + 0x1FFF : nX) >> 13;
    int nY = *(int *)(gGfxEng + 0x158DF0);
    int nB = (nY < 0 ? nY + 0x1FFF : nY) >> 13;
    GsInitMoveRG2BAPacket((tagMoveRgToBaPacket *)this, (short)(nA << 5), (short)nB, (short)nA, (short)(SCREEN_HEIGHT << 1));
    GsInitFogSprite((tagFogSpritePacket *)((char *)this + 0xAD0), 0, 0, 0, 0x7FFF);
    m_unk17AA = 0;
    GsInitClut256((tagGsClut256 *)m_unk12F0);
    GsInitTexturedFogSprite((tagTexturedFogSpritePacket *)((char *)this + 0xDA0), 0, 0, 0, 0x7FFF);
    int nGroup = 0;
    int nOff = 0;
    do {
        char *pRow = (char *)this + nOff;
        pRow[0x1350] = (char)0x80;
        pRow[0x1351] = (char)0x80;
        pRow[0x1352] = (char)0x80;
        pRow[0x1353] = (char)(0x81 - nGroup);
        pRow[0x1354] = (char)0x80;
        pRow[0x1355] = (char)0x80;
        pRow[0x1356] = (char)0x80;
        pRow[0x1357] = (char)(0x81 - (nGroup + 1));
        pRow[0x1358] = (char)0x80;
        pRow[0x1359] = (char)0x80;
        pRow[0x135A] = (char)0x80;
        pRow[0x135B] = (char)(0x81 - (nGroup + 2));
        pRow[0x135C] = (char)0x80;
        pRow[0x135D] = (char)0x80;
        pRow[0x135E] = (char)0x80;
        pRow[0x135F] = (char)(0x81 - (nGroup + 3));
        pRow[0x1360] = (char)0x80;
        pRow[0x1361] = (char)0x80;
        pRow[0x1362] = (char)0x80;
        pRow[0x1363] = (char)(0x81 - (nGroup + 4));
        pRow[0x1364] = (char)0x80;
        pRow[0x1365] = (char)0x80;
        pRow[0x1366] = (char)0x80;
        pRow[0x1367] = (char)(0x81 - (nGroup + 5));
        pRow[0x1368] = (char)0x80;
        pRow[0x1369] = (char)0x80;
        pRow[0x136A] = (char)0x80;
        pRow[0x136B] = (char)(0x81 - (nGroup + 6));
        pRow[0x136C] = (char)0x80;
        pRow[0x136D] = (char)0x80;
        pRow[0x136E] = (char)0x80;
        pRow[0x136F] = (char)(0x81 - (nGroup + 7));
        nOff += 0x20;
        nGroup += 8;
    } while (nGroup < 0x80);
    m_unk1350[0] = (char)0x80;
    m_unk1350[1] = (char)0x80;
    m_unk1350[2] = (char)0x80;
    m_unk1350[3] = 0;
    GsSwizzleClut((tagGsClut256 *)m_unk12F0);
    *(long long *)((char *)this + 0xDC0) = 0x44;
    m_unk1750 = 0x4B800000;
    m_unk1754 = 0.0f;
    m_unk1758 = 0.0f;
    m_unk1770[2] = 0;
    m_unk1770[1] = 0;
    m_unk1770[0] = 0;
    m_unk1770[3] = 0x3F800000;
    m_unk1780[3] = 0x3F800000;
    m_unk1780[2] = 0;
    m_unk1780[1] = 0;
    m_unk1780[0] = 0;
    m_unk17A9 = 0;
    m_unk17A4 = 0;
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
