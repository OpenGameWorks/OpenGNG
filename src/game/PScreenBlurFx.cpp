// FLAGS: -str readonly
#include "types.h"
#include "PScreenBlurFx.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void __dl__FPv(void *);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" float FastMath_IntCos180__Fi(int);
extern "C" float FastMath_IntSin180__Fi(int);
extern char gGfxEng[1504384];
extern "C" void SetPrevFrameBufferAsTexture__10PGfxEngineFv(void *);
extern "C" void UpdateHeatHazeBuffer__16PParticleManagerFv(void *);
extern "C" void SetTexture__10PGfxEngineFi(void *, int);
extern "C" void SetGsRegisters__12PDisplayListFP1i(void *, u_long128 *, int);
extern "C" void SendGsPacket__12PDisplayListFPvib(void *, void *, int, bool);

// DRAFT: 0x00216500 WobbleSTGrids__13PScreenBlurFxFP21tagGsScreenBlurPacketf
// note: 80 words differ; lit_ stand-ins replaced by local initializers (vA, vB, nTbl). Register roles differ (this in s5, pPacket in fp, i/j/nIdx/nS3 assigned differently), frame 0x120 vs 0x100, literal base v0 vs v1. Tried: baseline 122, vA/vB placement and pRow hoisting (83), else-if angle wrap (80, kept), nIdx == 8 wrap (80, no change).
void PScreenBlurFx::WobbleSTGrids(tagGsScreenBlurPacket *pPacket, float fAngle) {
    int nAngle = (int)fAngle;
    int nTbl[8] = {10, -15, 16, 27, 51, -32, 13, -46};
    int nIdx = 0;
    char *pRowCur;
    char *pRowPrev;
    for (int i = 1; i < 16; i++) {
        pRowCur = (char *)pPacket + i * 0x840 + 0x40;
        pRowPrev = (char *)pPacket + (i - 1) * 0x840 + 0x40;
        for (int j = 1; j < 32; j++) {
            char *pCur = pRowCur + j * 0x40;
            char *pPrev = pRowPrev + j * 0x40;
            nAngle += nTbl[nIdx];
            nIdx++;
            if (nIdx >= 8) nIdx = 0;
            if (nAngle < 0) {
                nAngle += 0x168;
            } else if (nAngle >= 0x168) {
                nAngle -= 0x168;
            }
            int nS3 = nAngle - 0xB4;
            float vA[4] = {0.0f, 0.0f, 0.0002f, 2.0f};
            vA[0] = FastMath_IntCos180__Fi(nS3);
            vA[1] = FastMath_IntSin180__Fi(nS3);
            float vB[4] = {0.0f, 0.0f, 0.0f, 0.0f};
            vB[0] = m_unk8458;
            vB[1] = m_unk845C;
            char *pPrevHi = pPrev + 0x20;
            char *pA = (char *)vA;
            char *pB = (char *)vB;
            asm {
                lqc2 vf1, 0x0(pA)
                lqc2 vf2, 0x0(pCur)
                lqc2 vf10, 0x0(pB)
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
                vadd.xy vf2, vf2, vf6
                vnop
                vnop
                vnop
                vmini.xy vf2, vf2, vf10
                vnop
                vnop
                vnop
                sqc2 vf2, 0x0(pCur)
                sqc2 vf2, 0x0(pPrevHi)
            }
        }
    }
}

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

// DRAFT: 0x002168A0 InitBlurPacket__13PScreenBlurFxFP21tagGsScreenBlurPacketiicccc
// note: 209 words (attempt 3); the original keeps cA..cD sign extension and saves before header zeroing, and emits andi $zero zero terms; zero local and store-order swap gave no change
struct GifTagBits {
    unsigned long long nloop : 15;
    unsigned long long eop : 1;
    unsigned long long unused0 : 30;
    unsigned long long pre : 1;
    unsigned long long prim : 11;
    unsigned long long flg : 2;
    unsigned long long nreg : 4;
    unsigned long long regs;
};

void PScreenBlurFx::InitBlurPacket(tagGsScreenBlurPacket *pPacket, int nWidth, int nHeight, char cA, char cB, char cC, char cD) {
    unsigned char *p = (unsigned char *)pPacket;
    *(int *)(p + 0x20) = cA;
    *(int *)(p + 0x24) = cB;
    *(int *)(p + 0x28) = cC;
    *(int *)(p + 0x2C) = cD;
    short sC = nWidth / 32;
    short sD = nHeight / 16;
    short sA = 0x800 - nWidth / 2;
    short sB = 0x800 - nHeight / 2;
    GifTagBits *t = (GifTagBits *)p;
    *(u_long128 *)p = 0;
    t->prim = 0;
    t->pre = 0;
    t->nloop = 1;
    t->eop = 0;
    t->flg = 0;
    t->nreg = 2;
    p[8] = (p[8] & ~0x0F) | 2;
    p[8] = (p[8] & ~0xF0) | (1 << 4);
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    *(float *)(p + 0x18) = 1.0f;
    GifTagBits *t2 = (GifTagBits *)(p + 0x30);
    *(u_long128 *)(p + 0x30) = 0;
    t2->prim = 4;
    t2->pre = 1;
    t2->nloop = 0x210;
    t2->eop = 1;
    t2->flg = 0;
    t2->nreg = 4;
    p[0x38] = (p[0x38] & ~0x0F) | 2;
    p[0x38] = (p[0x38] & ~0xF0) | 0x50;
    p[0x39] = (p[0x39] & ~0x0F) | 2;
    p[0x39] = (p[0x39] & ~0xF0) | 0x50;

    float fStep = m_unk845C / 16.0f;
    float fAcc = 0.0f;
    int nOff = 0;
    int i = 0;
    do {
        InitBlurStrip((tagBlurStrip *)((char *)pPacket + nOff + 0x40), cD, sA, sB, sC, sD, fAcc, i > 0, m_unk8458, m_unk845C);
        sB = (short)(sB + sD);
        i++;
        nOff += 0x840;
        fAcc += fStep;
    } while (i < 16);
}

struct GsAD {
    unsigned long long lo;
    unsigned long long hi;
};

// DRAFT: 0x00216C00 Render__13PScreenBlurFxFv
// note: 116 words; packet stores via aPkt[] (attempt 4 pointer form 126, worse); byte/branch order still differs
void PScreenBlurFx::Render() {
    GsAD aPkt[5];
    float f;
    int nByte;

    if (m_unk84A0 == 4) {
        return;
    }
    if (m_unk84A4) {
        SetPrevFrameBufferAsTexture__10PGfxEngineFv(gGfxEng);
        aPkt[0].lo = 0;
    } else {
        UpdateHeatHazeBuffer__16PParticleManagerFv(gGfxEng + 0x154F00);
        SetTexture__10PGfxEngineFi(gGfxEng, *(int *)(gGfxEng + 0x155570));
        aPkt[0].lo = 0;
    }
    aPkt[0].hi = 0x1A;
    aPkt[1].lo = 0x58;
    aPkt[1].hi = 0x1B;
    aPkt[2].lo = 0x44;
    aPkt[2].hi = 0x42;
    aPkt[3].lo = 0x30000;
    aPkt[3].hi = 0x47;
    aPkt[4].lo = 5;
    aPkt[4].hi = 8;
    SetGsRegisters__12PDisplayListFP1i((void *)*(int *)(gGfxEng + 0x154C80), (u_long128 *)aPkt, 5);

    f = *(float *)&m_unk8480[0];
    if (f >= 2147483648.0f) {
        nByte = ((int)(f - 2147483648.0f) | 0x80000000) & 0xFF;
    } else {
        nByte = (int)f & 0xFF;
    }
    *(int *)((char *)this + 0x30) = nByte;

    f = *(float *)&m_unk8480[1];
    if (f >= 2147483648.0f) {
        nByte = ((int)(f - 2147483648.0f) | 0x80000000) & 0xFF;
    } else {
        nByte = (int)f & 0xFF;
    }
    *(int *)((char *)this + 0x34) = nByte;

    f = *(float *)&m_unk8480[2];
    if (f >= 2147483648.0f) {
        nByte = ((int)(f - 2147483648.0f) | 0x80000000) & 0xFF;
    } else {
        nByte = (int)f & 0xFF;
    }
    *(int *)((char *)this + 0x38) = nByte;

    f = *(float *)&m_unk8480[3];
    if (f >= 2147483648.0f) {
        nByte = ((int)(f - 2147483648.0f) | 0x80000000) & 0xFF;
    } else {
        nByte = (int)f & 0xFF;
    }
    *(int *)((char *)this + 0x3C) = nByte;

    SendGsPacket__12PDisplayListFPvib((void *)*(int *)(gGfxEng + 0x154C80), (char *)this + 0x10, 0x8440, true);
    aPkt[0].lo = 0;
    aPkt[0].hi = 8;
    SetGsRegisters__12PDisplayListFP1i((void *)*(int *)(gGfxEng + 0x154C80), (u_long128 *)aPkt, 1);
}

// FUNCTION: 0x00216EA0 Animate__13PScreenBlurFxFf
void PScreenBlurFx::Animate(float fDelta) {
    if (m_unk84A0 == 1) {
        float fStep = fDelta * m_unk849C;
        *(float *)&m_unk8480[3] += fStep;
        if (*(float *)&m_unk8480[3] >= m_unk8470[3]) {
            m_unk84A0 = 2;
            m_unk846C = m_unk8468;
            *(float *)&m_unk8480[3] = m_unk8470[3];
        }
        m_unk846C -= fDelta;
    } else if (m_unk84A0 == 3) {
        float fStep = fDelta * m_unk849C;
        *(float *)&m_unk8480[3] -= fStep;
        if (*(float *)&m_unk8480[3] <= 0.0f) {
            m_unk84A0 = 4;
            m_unk846C = 0.0f;
            *(float *)&m_unk8480[3] = 0.0f;
        }
        m_unk846C -= fDelta;
    } else if (m_unk84A0 == 2) {
        m_unk846C -= fDelta;
        if (m_unk846C <= 0.0f) {
            m_unk846C = m_unk8464;
            m_unk84A0 = 3;
            *(u_long128 *)m_unk8480 = *(u_long128 *)m_unk8470;
        }
    } else {
        return;
    }
    *(float *)&m_unk8450 += m_unk8454;
    if (*(float *)&m_unk8450 <= 0.0f || *(float *)&m_unk8450 >= 360.0f) {
        m_unk8454 = -m_unk8454;
    }
    WobbleSTGrids((tagGsScreenBlurPacket *)m_unk10, *(float *)&m_unk8450);
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
