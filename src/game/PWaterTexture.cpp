// FLAGS: -str readonly
#include "types.h"
#include "PWaterTexture.h"
#include "PDisplayList.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
float FastMath_IntCos180(int nAngle);
float FastMath_IntSin180(int nAngle);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern char gGfxEng[1504384];

// DRAFT: 0x001EE330 InitWobbleStrip__13PWaterTextureFP14tagWobbleStripcssssfbff
// note: DIFF 69; prologue, CdsAssert and string addressing match; loop setup register assignment differs (dsll32/dsra32 sign extension and sll 4 ordering); -str readonly needed.
void PWaterTexture::InitWobbleStrip(tagWobbleStrip *pStrip, char cA, short sB, short sC, short sD, short sE, float fA, bool bFlag, float fB, float fC) {
    if (pStrip == 0) {
        CdsAssert("PWaterTexture.cpp", 0x1E2, "pStrip");
    }
    int nStep = (int)sD << 4;
    int nX = (int)sB << 4;
    float fStep = fB / 33.0f;
    float fY = fA + fC / 16.0f;
    int nTop = (int)sC << 4;
    int nBot = ((int)sC + (int)sE) << 4;
    float fRun = 0.0f;
    int nOff = 0;
    for (int i = 0; i < 33; i++) {
        char *pElem = (char *)pStrip + nOff;
        *(float *)(pElem + 0x00) = fRun;
        *(float *)(pElem + 0x04) = fA;
        *(float *)(pElem + 0x08) = 1.0f;
        *(int *)(pElem + 0x10) = nX;
        *(int *)(pElem + 0x14) = nTop;
        *(float *)(pElem + 0x20) = fRun;
        *(float *)(pElem + 0x24) = fY;
        *(float *)(pElem + 0x28) = 1.0f;
        *(int *)(pElem + 0x30) = *(int *)(pElem + 0x10);
        *(int *)(pElem + 0x34) = nBot;
        if (bFlag) {
            if (i == 0) {
                *(unsigned char *)(pElem + 0x1D) = (*(unsigned char *)(pElem + 0x1D) & ~0x80) | 0x80;
                *(unsigned char *)(pElem + 0x3D) = (*(unsigned char *)(pElem + 0x3D) & ~0x80) | 0x80;
            }
        }
        fRun += fStep;
        nX += nStep;
        nOff += 0x40;
    }
}

// DRAFT: 0x001EEB60 WobbleSTGrids__13PWaterTextureFP21tagGsWobbleCopyStripsf
// note: loop, wrap and FastMath calls follow the asm; the VU0 lqc2/vmul/vadd/sqc2 chain is plain C with z=w=0, not byte-matched.
void PWaterTexture::WobbleSTGrids(tagGsWobbleCopyStrips *pStrips, float fScale) {
    int nPhase = (int)fScale;
    char *pBase = (char *)pStrips;
    for (int nRow = 1; nRow < 16; nRow++) {
        char *pCur = pBase + nRow * 2112 + 0x10;
        char *pPrev = pBase + (nRow - 1) * 2112 + 0x10;
        for (int nCol = 1; nCol < 32; nCol++) {
            nPhase -= 0xF;
            if (nPhase < 0) {
                nPhase += 0x168;
            } else if (nPhase >= 0x168) {
                nPhase -= 0x168;
            }
            float fCos = FastMath_IntCos180(nPhase - 0xB4);
            float fSin = FastMath_IntSin180(nPhase - 0xB4);
            float *pSrc = (float *)(pCur + nCol * 64);
            float *pDst = (float *)(pPrev + nCol * 64 + 0x20);
            float fZ = 0.0f;
            float fW = 0.0f;
            float fX = pSrc[0] + fCos * fZ + (fCos * fSin) * fZ;
            float fY = pSrc[1] + fSin * fZ + (fSin * fZ) * (fW * (fSin * fCos));
            pDst[0] = fX;
            pDst[1] = fY;
            pDst[2] = pSrc[2];
            pDst[3] = pSrc[3];
        }
    }
}

// DRAFT: 0x001EED30 Update__13PWaterTextureFv
// note: DIFF 92; early-exit epilogue at 0x5C words not 0x62, and lui $at,1 address folding for m_unk86A0/86A4 differs; 8 attempts (flat/nested if, early return, local fStep, || guard, inverted range).
void PWaterTexture::Update() {
    if (m_unk0 != 0 && m_unk8 != 0 && m_unk4 != 0) {
        float fStep = *(float *)&m_unk86A4;
        *(float *)&m_unk86A0 = *(float *)&m_unk86A0 + fStep;
        if (*(float *)&m_unk86A0 <= 0.0f || *(float *)&m_unk86A0 >= 360.0f) {
            *(float *)&m_unk86A4 = -*(float *)&m_unk86A4;
        }
        WobbleSTGrids((tagGsWobbleCopyStrips *)m_unk150, *(float *)&m_unk86A0);
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SetVifCodes(0x11000000, 0);
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SendGsPacket(m_unk10, 0x140, true);
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SendGsPacket(m_unk150, 0x8410, true);
        (*(PDisplayList **)(gGfxEng + 0x154C80))->SetVifCodes(0x11000000, 0);
        if (m_unk4 != 0) {
            (*(PDisplayList **)(gGfxEng + 0x154C80))->SetVifCodes(0x11000000, 0);
            (*(PDisplayList **)(gGfxEng + 0x154C80))->SendGsPacket(m_unk8560, 0x140, true);
            (*(PDisplayList **)(gGfxEng + 0x154C80))->SendGsPacket(m_unk150, 0x8410, true);
            (*(PDisplayList **)(gGfxEng + 0x154C80))->SetVifCodes(0x11000000, 0);
        }
    }
}

// FUNCTION: 0x001EECE0 Reset__13PWaterTextureFv
void PWaterTexture::Reset() {
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk4 = 0;
    m_unk86A0 = 0;
    m_unk86A4 = 0x40A00000;
    m_unk86A8 = 0;
    m_unk86AC = 0x40000000;
}

// FUNCTION: 0x001EEEE0 Init__13PWaterTextureFiii
int PWaterTexture::Init(int nA, int nB, int nC) {
    m_unk0 = nA;
    m_unk4 = nB;
    m_unk8 = nC;
    InitWobblePacket((tagGsWobbleCopy *)m_unk10, (tagGsWobbleCopyStrips *)m_unk150, m_unk0, m_unk8, false, 0, 0x44, 0, m_unk86B0, m_unk86B4);
    if (m_unk4 != 0) {
        InitWobblePacket((tagGsWobbleCopy *)m_unk8560, 0, m_unk4, m_unk8, true, (char)(int)m_unk86C0, 0x49, 0, m_unk86B8, m_unk86BC);
    }
    m_unk86A0 = 0;
    m_unk86A4 = 0x40A00000;
    m_unk86A8 = 0;
    m_unk86AC = 0x40000000;
    return 1;
}

// DRAFT: 0x001EEFF0 Init__13PWaterTextureFP24tagProceduralTextureDataP6PArray
// note: DIFF 70; original keeps pBaseTex in s1 and pShineTex in s0, ours the reverse (lw $s1/$s0 at 0x8C/0x94); declaring pShineTex first gave 70 too; `||` early return kept.
int PWaterTexture::Init(tagProceduralTextureData *pData, PArray *pArr) {
    void *pBaseTex;
    void *pWaterTex;
    void *pShineTex;
    pShineTex = 0;
    if (pData == 0) {
        CdsAssert("PWaterTexture.cpp", 0x20, "pData");
    }
    if (*(int *)pData < 0 || *(int *)((char *)pData + 0x8) < 0) {
        return 1;
    }
    pBaseTex = ((unsigned int)*(int *)pData < pArr->m_unk0) ? pArr->m_unk8[*(int *)pData] : 0;
    if (pBaseTex == 0) {
        CdsAssert("PWaterTexture.cpp", 0x2B, "ahBaseTexture");
    }
    pWaterTex = ((unsigned int)*(int *)((char *)pData + 0x8) < pArr->m_unk0) ? pArr->m_unk8[*(int *)((char *)pData + 0x8)] : 0;
    if (pWaterTex == 0) {
        CdsAssert("PWaterTexture.cpp", 0x2E, "ahWaterTexture");
    }
    memcpy(&m_unk86B0, (char *)pData + 0xC, 8);
    memcpy(&m_unk86B8, (char *)pData + 0x14, 8);
    m_unk86C0 = 255.0f * *(float *)((char *)pData + 0x1C);
    if (*(int *)((char *)pData + 0x4) >= 0) {
        pShineTex = ((unsigned int)*(int *)((char *)pData + 0x4) < pArr->m_unk0) ? pArr->m_unk8[*(int *)((char *)pData + 0x4)] : 0;
        if (pShineTex == 0) {
            CdsAssert("PWaterTexture.cpp", 0x37, "ahShineTexture");
        }
    }
    return Init((int)pBaseTex, (int)pShineTex, (int)pWaterTex);
}

// FUNCTION: 0x001EF1B0 __dt__13PWaterTextureFv
extern "C" PWaterTexture *__dt__13PWaterTextureFv(PWaterTexture *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001EF200 __ct__13PWaterTextureFv
PWaterTexture::PWaterTexture() {
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk4 = 0;
    memset(m_unk10, 0, 0x140);
    memset(m_unk8560, 0, 0x140);
    memset(m_unk150, 0, 0x8410);
}
