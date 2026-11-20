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
extern u_long128 lit_00252670[2];
extern u_long128 lit_00252690;
extern u_long128 lit_004D19C0;

// DRAFT: 0x00216500 WobbleSTGrids__13PScreenBlurFxFP21tagGsScreenBlurPacketf
// note: 122 words differ; register roles and frame/spill layout differ, table-index loop form also differs. Tried: baseline, two-if angle wrap (123 to 122).
void PScreenBlurFx::WobbleSTGrids(tagGsScreenBlurPacket *pPacket, float fAngle) {
    int nAngle = (int)fAngle;
    int nTbl[8];
    int nIdx = 0;
    float vA[4];
    float vB[4];
    char *pRowCur;
    char *pRowPrev;
    *(u_long128 *)nTbl = lit_00252670[0];
    *(u_long128 *)(nTbl + 4) = lit_00252670[1];
    for (int i = 1; i < 16; i++) {
        pRowCur = (char *)pPacket + i * 0x840 + 0x40;
        pRowPrev = (char *)pPacket + (i - 1) * 0x840 + 0x40;
        for (int j = 1; j < 32; j++) {
            char *pCur = pRowCur + j * 0x40;
            char *pPrev = pRowPrev + j * 0x40;
            nAngle += nTbl[nIdx];
            nIdx++;
            if (nIdx >= 8) nIdx = 0;
            if (nAngle < 0) nAngle += 0x168;
            if (nAngle >= 0x168) nAngle -= 0x168;
            int nS3 = nAngle - 0xB4;
            *(u_long128 *)vA = lit_00252690;
            vA[0] = FastMath_IntCos180__Fi(nS3);
            vA[1] = FastMath_IntSin180__Fi(nS3);
            *(u_long128 *)vB = lit_004D19C0;
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
