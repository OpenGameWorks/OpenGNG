#include "types.h"
#include "PDynamicSplinePatch.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void __dl__FPv(void *pData);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void QwordMemset__FP1Ui1(u_long128 *pDst, unsigned int nQwords, u_long128 nValue);
class PMNode;

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
