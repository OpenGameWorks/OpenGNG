#include "types.h"
#include "PDynamicSplinePatch.h"
#include "PGfxEngine.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void __dl__FPv(void *pData);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void QwordMemset__FP1Ui1(u_long128 *pDst, unsigned int nQwords, u_long128 nValue);
extern "C" void Vu0_Compute_Spline_Tangents(void);
extern "C" void Vu0_Compute_Spline_Patch_Color_ST(void);
extern u_long128 lit_004C9330;
extern u_long128 lit_0024D860;
extern u_long128 lit_0024D870;
extern char gGfxEng[1504384];
class PMNode;

// FUNCTION: 0x001F3280 InitMatrixCache__19PDynamicSplinePatchFv
void PDynamicSplinePatch::InitMatrixCache() {
    char *pNode = (char *)m_unk1F6C;
    if (pNode != 0) {
        char *pSrc = pNode + 0x40;
        int i = 0;
        int off = 0;
        char *pDst;
        do {
            pDst = (char *)this + off;
            i += 8;
            off += 0x200;
            *(u_long128 *)(pDst + 0x1690) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x16A0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x16B0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x16C0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x16D0) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x16E0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x16F0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1700) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1710) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1720) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1730) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1740) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1750) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1760) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1770) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1780) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1790) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x17A0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x17B0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x17C0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x17D0) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x17E0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x17F0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1800) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1810) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1820) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1830) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1840) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1850) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1860) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1870) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1880) = *(u_long128 *)(pSrc + 0x20);
        } while (i < 0x20);
        i = 0;
        off = 0;
        do {
            pDst = (char *)this + off;
            i += 8;
            off += 0x200;
            *(u_long128 *)(pDst + 0x1210) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1220) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1230) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1240) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1250) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1260) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1270) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1280) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1290) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x12A0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x12B0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x12C0) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x12D0) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x12E0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x12F0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1300) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1310) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1320) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1330) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1340) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1350) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1360) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1370) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1380) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1390) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x13A0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x13B0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x13C0) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x13D0) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x13E0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x13F0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1400) = *(u_long128 *)(pSrc + 0x30);
        } while (i < 0x0A);
        while (i < 0x12) {
            char *pRow = (char *)this + (i << 6);
            i += 1;
            *(u_long128 *)(pRow + 0x1210) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pRow + 0x1220) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pRow + 0x1230) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pRow + 0x1240) = *(u_long128 *)(pSrc + 0x30);
        }
    }
}

// DRAFT: 0x001F3510 GenerateAndRenderVuSplinePatch__19PDynamicSplinePatchFv
// note: 98 words differ; frame 0xE0 against 0xD0. Original sets 1.0f (lui/mtc1) before the quad stores to 0xB0/0xC0 and computes the 0x1FB0/0x1FC0 pointers after them; ours does not. Tried: extern-symbol and absolute pool loads (146, 138, 99), pointer-local extern loads (98, best), key base moved earlier (98).
void PDynamicSplinePatch::GenerateAndRenderVuSplinePatch() {
    u_long128 qCtl;
    float mtx[16];
    u_long128 qA;
    u_long128 qB;
    u_long128 qC;
    float fStepS;
    float fStepT;
    int i;
    int j;
    char *pKeyBase;
    char *pRow;

    sceVu0UnitMatrix(mtx);
    {
        u_long128 *pLitA = &lit_004C9330;
        u_long128 *pLitB = &lit_0024D860;
        u_long128 *pLitC = &lit_0024D870;
        qA = *pLitA;
        qB = *pLitB;
        qC = *pLitC;
    }
    pKeyBase = (char *)0x70001000;
    fStepT = 1.0f / (float)(m_unk00 - 1);
    fStepS = 1.0f / (float)(m_unk08 - 1);
    {
        char *p1 = (char *)this + 0x1FB0;
        char *p2 = (char *)this + 0x1FC0;
        char *pQC = (char *)&qC;
        asm {
            lqc2 vf5, 0x0(p1)
            lqc2 vf6, 0x0(p2)
            lqc2 vf9, 0x0(pQC)
        }
    }
    gGfxEng[0x158E22] = 0;
    ((PGfxEngine *)gGfxEng)->SetMaterial(m_unk1FE0, m_unk2000, m_unk2010, m_unk1FF0, m_unk1FE8);
    ((PGfxEngine *)gGfxEng)->SetWorldMatrix((PMat4 *)mtx);
    ((PGfxEngine *)gGfxEng)->BeginSplinePatch();
    for (i = 0; i < m_unk00; i++) {
        char *pA = (char *)&qA;
        char *pB = (char *)&qB;
        asm {
            lqc2 vf7, 0x0(pA)
            lqc2 vf8, 0x0(pB)
        }
        qCtl = 0;
        pRow = (char *)this + ((((i << 3) + i)) << 5);
        for (j = 0; j < m_unk04 - 2; j++) {
            if (j <= m_unk08 - 1) {
                char *pSrc = pRow + (j << 4) + 0x10;
                char *pCtl = (char *)&qCtl;
                asm {
                    lqc2 vf1, 0x0(pSrc)
                    lqc2 vf2, 0x10(pSrc)
                    lqc2 vf3, 0x20(pSrc)
                    lqc2 vf4, 0x30(pSrc)
                    lqc2 vf10, 0x0(pCtl)
                    vcallms Vu0_Compute_Spline_Tangents
                }
            }
            {
                char *pKey = pKeyBase + ((((j << 2) + j)) << 4);
                *(u_long128 *)pKey = *(u_long128 *)(pRow + (((j + 1) << 4)) + 0x10);
                *(float *)&qCtl += fStepS;
                asm {
                    qmtc2.i v0, vf0
                    vcallms Vu0_Compute_Spline_Patch_Color_ST
                    sqc2 vf28, 0x30(pKey)
                    sqc2 vf29, 0x40(pKey)
                    qmtc2.i v0, vf0
                    sqc2 vf30, 0x10(pKey)
                    sqc2 vf31, 0x20(pKey)
                }
            }
        }
        ((PGfxEngine *)gGfxEng)->DrawSplinePatch((struct tagVuSplinePatchKey *)pKeyBase, m_unk08, m_unk0C + 1, 1.0f / (float)m_unk0C, true);
        *(float *)&qA += fStepT;
        *(float *)&qB = *(float *)&qA;
    }
    gGfxEng[0x158E22] = 1;
}

// FUNCTION: 0x001F3D80 Render__19PDynamicSplinePatchFv
void PDynamicSplinePatch::Render() {
    if (m_unk2011 != 0) {
        GenerateAndRenderVuSplinePatch();
    }
}

// FUNCTION: 0x001F3DB0 Animate__19PDynamicSplinePatchFf
void PDynamicSplinePatch::Animate(float fTime) {
    if (m_unk2011 != 0) {
        InitSplineKeys(m_unk1F90, m_unk1FA0);
        char *pNode = (char *)m_unk1F6C;
        if (pNode != 0) {
            if (m_unk2012 != 0) {
                InitMatrixCache();
                m_unk2012 = 0;
            } else {
                char *pDst = m_unk1690 + (m_unk1F68 << 6);
                *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pNode + 0x40);
                *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pNode + 0x50);
                *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pNode + 0x60);
                *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pNode + 0x70);
            }
            m_unk1F68 = m_unk1F68 + 1;
            if (m_unk1F68 >= 32) {
                m_unk1F68 = 0;
            }
            ApplyControlMatrices();
        }
    }
}

// FUNCTION: 0x001F3E60 SetControlNode__19PDynamicSplinePatchFP6PMNode
void PDynamicSplinePatch::SetControlNode(PMNode *pNode) {
    m_unk1F6C = pNode;
    m_unk1F68 = 0;
    if (m_unk1F6C != 0) {
        char *pSrc = (char *)m_unk1F6C;
        char *pDst = m_unk1690 + (m_unk1F68 << 6);
        *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x40);
        *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x50);
        *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x60);
        *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x70);
        *(u_long128 *)m_unk1FD0 = *(u_long128 *)(pSrc + 0x70);
        m_unk1F68 = m_unk1F68 + 1;
    }
}

// DRAFT: 0x001F3EC0 Init__19PDynamicSplinePatchFiiiPfPf
// note: 59 words differ; original is 0x120 bytes, ours 0xF8. Clamp branch polarity and delay-slot scheduling differ. Tried: ternary-in-if (at vs v0 compare), nested ternary, sequential ifs, v-less compare; none reduced below 59.
int PDynamicSplinePatch::Init(int nA, int nB, int nC, float *pVecA, float *pVecB) {
    int v = (nA < 16) ? nA : 16;
    if (v < 3) {
        nA = 2;
    }
    if (nA > 16) {
        nA = 16;
    }
    m_unk00 = nA;

    v = (nB < 16) ? nB : 16;
    if (v < 3) {
        nB = 2;
    }
    if (nB > 16) {
        nB = 16;
    }
    m_unk08 = nB;
    m_unk04 = m_unk08 + 2;

    v = (nC < 10) ? nC : 10;
    if (v < 3) {
        nC = 2;
    }
    if (nC > 10) {
        nC = 10;
    }
    m_unk0C = nC;

    sceVu0CopyVector(m_unk1F90, pVecA);
    sceVu0CopyVector(m_unk1FA0, pVecB);
    return 1;
}

// FUNCTION: 0x001F3FE0 __dt__19PDynamicSplinePatchFv
extern "C" void *__dt__19PDynamicSplinePatchFv(PDynamicSplinePatch *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->m_unk1F68 = 0;
        pThis->m_unk1F6C = 0;
        pThis->m_unk1FE0 = 0;
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001F4030 __ct__19PDynamicSplinePatchFv
// note: 5 words differ in loop B: original has addiu a0,a0,4 between the two sw, and its exit beqz is +0xA vs our +0x9. Tried: while form, swapped store order (6 words), walking pointers (19 words); for form with original order is best at 5.
PDynamicSplinePatch::PDynamicSplinePatch() {
    m_unk00 = 0;
    m_unk04 = 0;
    m_unk08 = 0;
    m_unk0C = 0;
    QwordMemset__FP1Ui1((u_long128 *)_pad10, 0x120, 0);
    QwordMemset__FP1Ui1((u_long128 *)m_unk1690, 0x80, 0);
    memset(m_unk1F20, 0, 0x48);
    m_unk1F68 = 0;
    m_unk1F6C = 0;
    m_unk1FE0 = 0;
    m_unk1FE8 = 0x50000;
    m_unk1FF0 = 0x44;
    m_unk2000[0] = 1.0f;
    m_unk2000[1] = 1.0f;
    m_unk2000[2] = 1.0f;
    m_unk2000[3] = 1.0f;
    m_unk2010 = 0;
    m_unk1F70 = 0;
    m_unk1F74 = 5.0f;
    m_unk1F80 = 0.4f;
    m_unk1F84 = 1.0f;
    m_unk1F88 = 0.4f;
    m_unk1F8C = 0;
    m_unk1FB0[0] = 128.0f;
    m_unk1FB0[1] = 128.0f;
    m_unk1FB0[2] = 128.0f;
    m_unk1FB0[3] = 128.0f;
    m_unk1FB0[4] = 128.0f;
    m_unk1FB0[5] = 128.0f;
    m_unk1FB0[6] = 128.0f;
    m_unk1FB0[7] = 128.0f;
    m_unk2011 = 1;
    m_unk2012 = 0;
    m_unk1F78 = 0;
    int i = 0;
    for (; i < 10; i += 8) {
        m_unk1E90[i + 0] = 1.0f;
        m_unk1ED8[i + 0] = 1.0f;
        m_unk1E90[i + 1] = 1.0f;
        m_unk1ED8[i + 1] = 1.0f;
        m_unk1E90[i + 2] = 1.0f;
        m_unk1ED8[i + 2] = 1.0f;
        m_unk1E90[i + 3] = 1.0f;
        m_unk1ED8[i + 3] = 1.0f;
        m_unk1E90[i + 4] = 1.0f;
        m_unk1ED8[i + 4] = 1.0f;
        m_unk1E90[i + 5] = 1.0f;
        m_unk1ED8[i + 5] = 1.0f;
        m_unk1E90[i + 6] = 1.0f;
        m_unk1ED8[i + 6] = 1.0f;
        m_unk1E90[i + 7] = 1.0f;
        m_unk1ED8[i + 7] = 1.0f;
    }
    for (; i < 18; i++) {
        m_unk1E90[i] = 1.0f;
        m_unk1ED8[i] = 1.0f;
    }
}
