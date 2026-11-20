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
extern "C" void *GetTexEnv__15PTextureManagerFi(void *pThis, int nHandle);
extern "C" unsigned int GsGetTexByteAddr__FP23tagGsTextureEnvironment(void *pEnv);

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

#define WB_U8(p, o)  (*(unsigned char *)((char *)(p) + (o)))
#define WB_U16(p, o) (*(unsigned short *)((char *)(p) + (o)))
#define WB_S32(p, o) (*(int *)((char *)(p) + (o)))
#define WB_U64(p, o) (*(unsigned long long *)((char *)(p) + (o)))

// DRAFT: 0x001EE4B0 InitWobblePacket__13PWaterTextureFP15tagGsWobbleCopyP21tagGsWobbleCopyStripsiibcUliff
// note: DIFF 399: strip-call args now match the asm (V=nH0, a0=nW0); prologue saves differ (original this in $fp, nC in $s6, frame 0xB0; ours frame 0xC0, nC in $fp), branch forms at 0x5C/0x7C/0xB4. Tried: nC store after loop (401->399), bFlag store after loop (back to 401).
void PWaterTexture::InitWobblePacket(tagGsWobbleCopy *pPacket, tagGsWobbleCopyStrips *pStrips, int nA, int nB, bool bFlag, char cFlag, unsigned long nC, int nD, float fA, float fB) {
    char *pEnvA;
    char *pEnvB;
    int nIdx;
    int nAddr;
    int nBlk;
    int nW0;
    int nH0;
    int nT1;
    int nCount;
    int nOff;
    float fRun;
    unsigned long long nMask;

    if (nA == 0) {
        CdsAssert("PWaterTexture.cpp", 0x154, "hSourceTexture");
    }
    if (nB == 0) {
        CdsAssert("PWaterTexture.cpp", 0x155, "hTargetTexture");
    }
    nIdx = *(int *)(gGfxEng + 0x16D408);
    if (nIdx == 0) {
        nIdx = nA;
    }
    pEnvA = (char *)GetTexEnv__15PTextureManagerFi(gGfxEng + 0x154C90, nIdx);
    nIdx = *(int *)(gGfxEng + 0x16D408);
    if (nIdx == 0) {
        nIdx = nB;
    }
    pEnvB = (char *)GetTexEnv__15PTextureManagerFi(gGfxEng + 0x154C90, nIdx);
    if (pEnvA == 0) {
        CdsAssert("PWaterTexture.cpp", 0x15A, "apSourceTexEnv");
    }
    if (pEnvB == 0) {
        CdsAssert("PWaterTexture.cpp", 0x15B, "apTargetTexEnv");
    }
    GsGetTexByteAddr__FP23tagGsTextureEnvironment(pEnvA);
    nAddr = (int)GsGetTexByteAddr__FP23tagGsTextureEnvironment(pEnvB);
    nBlk = nAddr / 0x2000;
    nW0 = 1 << (int)((WB_U64(pEnvB, 0x30) << 0x1E) >> 0x3C);
    nH0 = 1 << (int)(((unsigned long long)((long long)(signed char)pEnvB[0x33] << 0x3A)) >> 0x3C);

    WB_U64(pPacket, 0x00) = 0;
    WB_U64(pPacket, 0x08) = 0;
    WB_U16(pPacket, 0x00) = (unsigned short)((WB_U16(pPacket, 0x00) & ~0x7FFF) | 0x10);
    WB_U8(pPacket, 0x01) = (unsigned char)((WB_U8(pPacket, 0x01) & ~0x80) | ((0 & 1) << 7));
    WB_U8(pPacket, 0x07) = (unsigned char)((WB_U8(pPacket, 0x07) & ~0xF0) | 0x10);
    WB_U8(pPacket, 0x08) = (unsigned char)((WB_U8(pPacket, 0x08) & ~0xF) | 0xE);
    WB_U64(pPacket, 0xC0) = (((unsigned long long)((long long)(signed char)pEnvB[0x32] << 0x36) >> 0x3A) << 0x18)
        | ((unsigned long long)(long long)nBlk | (((WB_U64(pEnvB, 0x30) << 0x2C) >> 0x3A) << 0x10));
    WB_U64(pPacket, 0xC8) = 0x4D;
    WB_U64(pPacket, 0xD0) = ((unsigned long long)(long long)((0x800 - (nH0 >> 1)) * 0x10))
        | (((unsigned long long)(long long)((0x800 - (nW0 >> 1)) * 0x10)) << 0x20);
    WB_U64(pPacket, 0xD8) = 0x19;
    WB_U64(pPacket, 0xE0) = (((unsigned long long)(long long)(nH0 - 1)) << 0x10)
        | (((unsigned long long)(long long)(nW0 - 1)) << 0x30);
    WB_U64(pPacket, 0xE8) = 0x41;
    WB_U64(pPacket, 0xF0) = (((unsigned long long)(long long)*(signed char *)(gGfxEng + 0x158E02)) << 0x18) | 0x100000000ULL;
    WB_U64(pPacket, 0xF8) = 0x4F;
    WB_U64(pPacket, 0x100) = 0;
    WB_U64(pPacket, 0x108) = 0x4B;
    WB_U64(pPacket, 0x88) = 0x43;
    WB_U64(pPacket, 0x90) = 0x30000;
    WB_U64(pPacket, 0x98) = 0x48;
    WB_U64(pPacket, 0xA0) = 0;
    WB_U64(pPacket, 0xA8) = 0x1A;
    WB_U64(pPacket, 0xB0) = (((unsigned long long)(unsigned char)bFlag) << 6) | 0x210;
    WB_U64(pPacket, 0xB8) = 0x1B;
    nMask = 0xFC007FFFFFFFFFFFULL;
    WB_U64(pPacket, 0x10) = 1;
    WB_U64(pPacket, 0x18) = 0x3F;
    WB_U64(pPacket, 0x50) = 0;
    WB_U64(pPacket, 0x58) = 9;
    WB_U64(pPacket, 0x20) = 0x60;
    WB_U64(pPacket, 0x28) = 0x15;
    nT1 = (0 & 3) * 4;
    WB_U64(pPacket, 0x30) = WB_U64(pEnvA, 0x30);
    WB_U64(pPacket, 0x38) = 7;
    WB_U8(pPacket, 0x34) = (unsigned char)((WB_U8(pPacket, 0x34) & ~0x18) | ((nD & 3) * 8));
    WB_U64(pPacket, 0x70) = ((((unsigned long long)((long long)(signed char)pEnvA[0x36] << 0x39)) >> 0x3C) << 0x33)
        | (((((unsigned long long)((long long)(signed char)pEnvA[0x32] << 0x36)) >> 0x3A) << 0x14)
        | (((WB_U64(pEnvA, 0x30) << 0xD) >> 0x32) << 0x25))
        | 0x2000000000000000ULL;
    WB_U64(pPacket, 0x78) = 0x17;
    WB_U64(pPacket, 0x40) = 0;
    WB_U64(pPacket, 0x48) = 0x35;
    WB_U64(pPacket, 0x60) = 0;
    WB_U64(pPacket, 0x68) = 0x37;
    WB_U64(pPacket, 0x110) = 0;
    WB_U64(pPacket, 0x118) = 0;
    WB_U64(pPacket, 0x110) = (WB_U64(pPacket, 0x110) & nMask) | ((0 & 0x7FF) << 0x2F);
    WB_U8(pPacket, 0x115) = (unsigned char)((WB_U8(pPacket, 0x115) & ~0x40) | ((0 & 1) << 6));
    WB_U16(pPacket, 0x110) = (unsigned short)((WB_U16(pPacket, 0x110) & ~0x7FFF) | 1);
    WB_U8(pPacket, 0x111) = (unsigned char)((WB_U8(pPacket, 0x111) & ~0x80) | 0x80);
    WB_U8(pPacket, 0x117) = (unsigned char)((WB_U8(pPacket, 0x117) & ~0xF0) | 0x20);
    WB_U8(pPacket, 0x117) = (unsigned char)((WB_U8(pPacket, 0x117) & ~0xC) | nT1);
    WB_U8(pPacket, 0x118) = (unsigned char)((WB_U8(pPacket, 0x118) & ~0xF) | 2);
    WB_U8(pPacket, 0x118) = (unsigned char)((WB_U8(pPacket, 0x118) & ~0xF0) | 0x10);
    WB_S32(pPacket, 0x120) = 0;
    WB_S32(pPacket, 0x124) = 0;
    WB_S32(pPacket, 0x128) = 0x3F800000;
    WB_S32(pPacket, 0x130) = 0xFF;
    WB_S32(pPacket, 0x134) = 0xFF;
    WB_S32(pPacket, 0x138) = 0xFF;
    WB_S32(pPacket, 0x13C) = (int)(signed char)cFlag;

    if (pStrips != 0) {
        WB_U64(pStrips, 0x00) = 0;
        WB_U64(pStrips, 0x08) = 0;
        WB_U64(pStrips, 0x00) = (WB_U64(pStrips, 0x00) & nMask) | (4ULL << 0x2F);
        WB_U8(pStrips, 0x05) = (unsigned char)((WB_U8(pStrips, 0x05) & ~0x40) | (1 << 6));
        WB_U16(pStrips, 0x00) = (unsigned short)((WB_U16(pStrips, 0x00) & ~0x7FFF) | 0x210);
        WB_U8(pStrips, 0x01) = (unsigned char)((WB_U8(pStrips, 0x01) & ~0x80) | 0x80);
        WB_U8(pStrips, 0x07) = (unsigned char)((WB_U8(pStrips, 0x07) & ~0xF0) | 0x40);
        WB_U8(pStrips, 0x07) = (unsigned char)((WB_U8(pStrips, 0x07) & ~0xC) | nT1);
        WB_U8(pStrips, 0x08) = (unsigned char)((WB_U8(pStrips, 0x08) & ~0xF) | 2);
        WB_U8(pStrips, 0x08) = (unsigned char)((WB_U8(pStrips, 0x08) & ~0xF0) | 0x50);
        WB_U8(pStrips, 0x09) = (unsigned char)((WB_U8(pStrips, 0x09) & ~0xF) | 2);
        WB_U8(pStrips, 0x09) = (unsigned char)((WB_U8(pStrips, 0x09) & ~0xF0) | 0x50);
        nCount = 0;
        nOff = 0;
        fRun = 0.0f;
        do {
            InitWobbleStrip((tagWobbleStrip *)((char *)pStrips + nOff + 0x10), cFlag, (short)(0x800 - ((nH0 + 1) >> 1)), (short)(0x800 - ((nW0 + 1) >> 1)), (short)((nH0 + 0x1F) >> 5), (short)((nW0 + 0xF) >> 4), fRun, nCount > 0, fA, fB);
            nCount += 1;
            fRun += 0.0625f;
            nOff += 0x840;
        } while (nCount < 16);
    }
    WB_U64(pPacket, 0x80) = nC;
}

// DRAFT: 0x001EEB60 WobbleSTGrids__13PWaterTextureFP21tagGsWobbleCopyStripsf
// note: DIFF 85; VU0 chain in asm over C locals; frame 0xA0 not 0xB0 with no fp save, loop head differs; tried pCur shift form (86), else-if wrap (86), pDst offset in sqc2 (86), vec[2..3] stores (85), vec decl first (86).
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
            }
            if (nPhase >= 0x168) {
                nPhase -= 0x168;
            }
            float vec[4] = {0.0f, 0.0f, 0.001f, 2.0f};
            vec[0] = FastMath_IntCos180(nPhase - 0xB4);
            vec[1] = FastMath_IntSin180(nPhase - 0xB4);
            float *pVec = vec;
            float *pSrc = (float *)(pCur + nCol * 64);
            float *pDst = (float *)(pPrev + nCol * 64 + 0x20);
            asm {
                lqc2 vf1, 0x0(pVec)
                lqc2 vf2, 0x0(pSrc)
                vmulx.y vf3, vf1, vf1x
                vmuly.x vf3, vf1, vf1y
                vmulz.x vf4, vf1, vf1z
                vmulz.y vf4, vf1, vf1z
                vmuly.w vf5, vf1, vf3y
                vnop
                vmulz.x vf6, vf3, vf1z
                vmulw.y vf6, vf4, vf5w
                vadd.xy vf2, vf2, vf4
                vnop
                vnop
                vnop
                vadd.xy vf2, vf2, vf6
                vnop
                vnop
                vnop
                sqc2 vf2, 0x0(pSrc)
                sqc2 vf2, 0x0(pDst)
            }
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
