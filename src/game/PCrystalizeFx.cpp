#include "types.h"
#include "PCrystalizeFx.h"
#include "PGfxEngine.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void __dla__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern unsigned char __vt__13PCrystalizeFx[];
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *pThis, void *pData, int nCount, bool bFlag);
extern char gUnk45B300[16];
extern float gUnitMatrix[16];
// TODO(header): PGfxEngine.h does not declare the global gGfxEng; declared here by name.
extern PGfxEngine gGfxEng;
extern "C" void Vu0_Set_Identity_Matrix(void);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
void FastMath_RotateMatrix(float (*)[4][4], float (*)[4][4], float (*)[4], float (*)[4][4]);

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PCrystalizeFx.cpp", line, #cond))

// TODO(header): PShader has no header in the repo; minimal view of its Render entry.
class PShader {
public:
    void Render(int nFlags, bool bFlag, bool *pOut);
};

// Effect block at m_unk1E8: shader pointer, entry count and entry array.
struct PCrystalizeFxEntry {
    int nSize;
    void *pData;
};

struct PCrystalizeFxBlock {
    PShader *pShader;
    int m_unk4;
    int nCount;
    PCrystalizeFxEntry *pEntries;
};

// Leading fields of PMNode as read by GetValidNodes. PMNode.h cannot be included
// here (its eBoxIntersect placeholder clashes with PGfxEngine.h).
// Child list embedded at +0x14 of a node: count, walk index, node array.
struct PCrystalizeFxChild {
    int nCount;
    int nIndex;
    PMNode **pNodes;
};

struct PCrystalizeFxNodeView {
    char _pad0[0x10];
    void *m_unk10;
    PCrystalizeFxChild m_child;
};

// DRAFT: 0x001FE410 UpdateInstances__13PCrystalizeFxFv
// note: 105 words. Loop head loads m_unk1E0 and apNode in a different order; assert string uses gp not lui/addiu (-str readonly gives 174 and a data mismatch); lane constants -20/40 swapped in $f0/$f1; lane 2/3 mul/add operands swapped; vector stored via temp not 0x50(sp). Tried: block-scoped pVec, nop after vcallms, local fr, RNG addend order.
void PCrystalizeFx::UpdateInstances() {
    float vec[4];
    int i;

    for (i = 0; i < m_unk1E4; i++) {
        void *apNode = *(void **)(m_unkE0 + i * 4);
        float (*pBlock)[4][4] = (float (*)[4][4])((char *)m_unk1E0 + i * 0x60);
        CDS_ASSERT(0xBF, apNode);
        {
            float *pVec = vec;
            asm {
                vcallms Vu0_Set_Identity_Matrix
                nop
                lui v1, 0x3F80
                dsll32 v1, v1, 0
                pcpyld v1, v1, zero
                sq v1, 0x0(pVec)
            }
        }
        if (m_unk1F8 != 0) {
            float fr;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            fr = 0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF);
            vec[0] = -20.0f + 40.0f * fr;
        }
        if (m_unk1F9 != 0) {
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            vec[1] = -20.0f + 40.0f * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF));
        }
        if (m_unk1FA != 0) {
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            vec[2] = -20.0f + 40.0f * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF));
        }
        asm {
            qmtc2.i v0, vf0
            sqc2 vf1, 0x0(pBlock)
            sqc2 vf2, 0x10(pBlock)
            sqc2 vf3, 0x20(pBlock)
            sqc2 vf4, 0x30(pBlock)
        }
        {
            float f3 = m_unk1EC;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            pBlock[0][0][0] = f3 + (m_unk1F0 - f3) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF));
        }
        {
            float f3 = m_unk1EC;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            pBlock[0][1][1] = f3 + (m_unk1F0 - f3) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF));
        }
        {
            float f3 = m_unk1EC;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            pBlock[0][2][2] = f3 + (m_unk1F0 - f3) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF));
        }
        FastMath_RotateMatrix(pBlock, pBlock, (float (*)[4])vec, (float (*)[4][4])((char *)apNode + 0x40));
    }
}

// DRAFT: 0x001FE700 GetValidNodes__13PCrystalizeFxFP6PMNodePP6PMNode
// note: 7 words differ. Original keeps the incremented index in a0 and uses sltu; ours reloads nIndex and uses slt, and the branch order around the loop tail differs. Tried: child struct, explicit pChild != 0, ternary first-child load, unsigned index (no change), local index variable (20 words).
void PCrystalizeFx::GetValidNodes(PMNode *pNode, PMNode **pOut) {
    PCrystalizeFxNodeView *pView = (PCrystalizeFxNodeView *)pNode;
    if (pView->m_unk10 != 0) {
        if (m_unk1E4 >= 0x41) {
            return;
        }
        pOut[m_unk1E4] = pNode;
        m_unk1E4++;
    }
    PCrystalizeFxChild *pChild = (PCrystalizeFxChild *)((char *)pNode + 0x14);
    if (pChild != 0) {
        pChild->nIndex = 0;
        PMNode *pChildNode = (pChild->nCount != 0) ? pChild->pNodes[0] : 0;
        if (pChildNode != 0) {
            do {
                GetValidNodes(pChildNode, pOut);
                pChild->nIndex++;
                pChildNode = (pChild->nIndex < pChild->nCount) ? pChild->pNodes[pChild->nIndex] : 0;
            } while (pChildNode != 0);
        }
    }
}

// DRAFT: 0x001FE7E0 Render__13PCrystalizeFxFv
// note: 74 words differ. Original keeps this in s1 with a 0x30 frame and walks entries by byte offset (addiu s1,s1,8); ours keeps this in s2 with a 0x40 frame. Tried: unsigned nCount (74), pointer walk over pEntries (76, reverted), reloading m_unk1E8 per use (74).
void PCrystalizeFx::Render() {
    unsigned int i;
    if (m_unk1E8 != 0 && m_unk15 != 0 && m_unkA4 != 0) {
        gGfxEng.SetZBufferUpdate(true, (eGsContext)0);
        gGfxEng.SetWorldMatrix((PMat4 *)gUnitMatrix);
        ((PCrystalizeFxBlock *)m_unk1E8)->pShader->Render(0x80, true, 0);
        for (i = 0; i < ((PCrystalizeFxBlock *)m_unk1E8)->nCount; i++) {
            gGfxEng.BeginFxInstances(
                (i < ((PCrystalizeFxBlock *)m_unk1E8)->nCount) ? ((PCrystalizeFxBlock *)m_unk1E8)->pEntries[i].pData : 0,
                (i < ((PCrystalizeFxBlock *)m_unk1E8)->nCount) ? ((PCrystalizeFxBlock *)m_unk1E8)->pEntries[i].nSize : 0,
                false);
            DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)gUnk45B300, m_unk1E0, m_unk1E4, false);
        }
        gGfxEng.SetZBufferUpdate(false, (eGsContext)0);
    }
}

// FUNCTION: 0x001FE920 Animate__13PCrystalizeFxFf
void PCrystalizeFx::Animate(float fDelta) {
    m_unk16 = m_unk17;
    m_unk15 = m_unk18;
    m_unkD0 = m_unk1F4;
    if (m_unk15 != 0 && m_unk16 == 0 && m_unkA4 != 0) {
        UpdateInstances();
    }
}

// FUNCTION: 0x001FED60 __dt__13PCrystalizeFxFv
extern "C" void *__dt__13PCrystalizeFxFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PCrystalizeFx *pSelf = (PCrystalizeFx *)pThis;
        *(void **)pThis = __vt__13PCrystalizeFx;
        if (pSelf->m_unk1E0 != 0) {
            __dla__FPv(pSelf->m_unk1E0);
            pSelf->m_unk1E0 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001FEDE0 __ct__13PCrystalizeFxFv
// note: 28 words differ. Original stores this to 0x1C(sp) and reloads it before each store; ours keeps this in s0. Tried: direct this stores (28), pSelf alias (28), volatile pSelf (31, reverted).
PCrystalizeFx::PCrystalizeFx() {
    PCrystalizeFx *pSelf = this;
    *(void **)pSelf = __vt__13PCrystalizeFx;
    pSelf->m_unk1E0 = 0;
    pSelf->m_unk1E4 = 0;
    pSelf->m_unk1E8 = 0;
    memset(pSelf->m_unkE0, 0, 0x100);
    pSelf->m_unk1F8 = 1;
    pSelf->m_unk1F9 = 1;
    pSelf->m_unk1FA = 1;
}
