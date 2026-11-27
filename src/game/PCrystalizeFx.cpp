// FLAGS: -str readonly
#pragma opt_strength_reduction off
#include "types.h"
#include "PCrystalizeFx.h"
#include "PGfxEngine.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void __dla__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern unsigned char __vt__13PCrystalizeFx[];
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *GetResource__16PParticleManagerFUi(void *pThis, unsigned int nId);
extern "C" float sqrtf(float);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *pThis, void *pData, int nCount, bool bFlag);
extern char gUnk45B300[16];
extern float gUnitMatrix[16];
// TODO(header): PGfxEngine.h does not declare the global gGfxEng; declared here by name.
extern PGfxEngine gGfxEng;
extern "C" void Vu0_Set_Identity_Matrix(void);
extern "C" int rand(void);
extern "C" void sceVu0ScaleVectorXYZ(void *pDst, void *pSrc, float fScale);
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
    unsigned int nCount;
    int nIndex;
    PMNode **pNodes;
};

struct PCrystalizeFxNodeView {
    char _pad0[4];
    int m_unk4;
    char _pad8[8];
    void *m_unk10;
    PCrystalizeFxChild m_child;
    char _pad20[8];
    void *m_unk28;
};

// Virtual view of the PParticleSystem vtable. ModifyPosition is virtual #3 (slot 0x14);
// Create passes the node matrix at +0x40 as its argument.
class PCrystalizeFxVirtView {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void ModifyPosition(void *pMat);
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

// FUNCTION: 0x001FE700 GetValidNodes__13PCrystalizeFxFP6PMNodePP6PMNode
void PCrystalizeFx::GetValidNodes(PMNode *pNode, PMNode **pOut) {
    PCrystalizeFxNodeView *pView = (PCrystalizeFxNodeView *)pNode;
    if (pView->m_unk10 != 0) {
        if (m_unk1E4 >= 0x41) {
            return;
        }
        pOut[m_unk1E4] = pNode;
        m_unk1E4++;
    }
    PCrystalizeFxChild *pList = &pView->m_child;
    if (pList != 0) {
        pList->nIndex = 0;
        PMNode *pChild = (pList->nCount != 0) ? pList->pNodes[0] : 0;
        while (pChild != 0) {
            GetValidNodes(pChild, pOut);
            int nIdx = pList->nIndex + 1;
            pList->nIndex = nIdx;
            pChild = (nIdx < pList->nCount) ? pList->pNodes[pList->nIndex] : 0;
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

// DRAFT: 0x001FE980 Create__13PCrystalizeFxFP6PMNodeP21tagCrystalizeFxParams
// note: 65 words differ. Seed/LCG block schedules differently (original loads the constants 0x343FD and 0x269EC3 before m_unkD0 and uses mult with a2 = m_unkD0; ours loads m_unkD0 first) and the scale expression's neg.s/add.s order differs; loop-end b is 2 instructions longer than the original. Relocation addends at 0x138/0x178/0x188 are placeholders. Tried: -str readonly (65, kept), scale operand swap (65), pBlock declared after the assert (78, reverted).
int PCrystalizeFx::Create(PMNode *pNode, tagCrystalizeFxParams *pParams) {
    PMNode *poModel = pNode;
    CDS_ASSERT(0x28, poModel);
    m_unkD0 = (int)(0.5f + (23154.0f + 20367.0f * ((float)rand() / 2147483648.0f)));
    m_unk0C = 22;
    m_unk1F4 = m_unkD0;
    if (((PCrystalizeFxNodeView *)pNode)->m_unk4 == 2) {
        PCrystalizeFxChild *apChildList = (PCrystalizeFxChild *)((char *)pNode + 0x14);
        CDS_ASSERT(0x32, apChildList);
        apChildList->nIndex = 0;
        pNode = (apChildList->nCount != 0) ? apChildList->pNodes[0] : 0;
    }
    GetValidNodes(pNode, (PMNode **)m_unkE0);
    PParticleSystem::Create(m_unk1E4, false);
    m_unk1E8 = GetResource__16PParticleManagerFUi(&gGfxEng, pParams->m_unk1C);
    if (m_unk1E8 == 0) {
        return 0;
    }
    m_unk1E0 = __nwa__FUi(m_unk1E4 * 0x60);
    CDS_ASSERT(0x42, m_unk1E0);
    m_unk1EC = pParams->m_unk14;
    m_unk1F0 = pParams->m_unk18;
    m_unk1F8 = pParams->m_unk20;
    m_unk1F9 = pParams->m_unk21;
    m_unk1FA = pParams->m_unk22;
    for (int i = 0; i < m_unk1E4; i++) {
        void *apNode = *(void **)(m_unkE0 + i * 4);
        char *pBlock = (char *)m_unk1E0 + i * 0x60;
        CDS_ASSERT(0x50, apNode);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        float fScale = (1.0f + (-pParams->m_unk10 + (pParams->m_unk10 + pParams->m_unk10) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)))) * 0.003921569f;
        sceVu0ScaleVectorXYZ(pBlock + 0x40, pParams, fScale);
        *(float *)(pBlock + 0x4C) = pParams->m_unk0C / 128.0f;
        *(u_long128 *)(pBlock + 0x50) = (u_long128)((unsigned long long)0x3F800000 << 32);
    }
    if (pNode == 0) {
        return 1;
    }
    {
        int nType = ((PCrystalizeFxNodeView *)pNode)->m_unk4;
        if (nType == 2 || nType == 1) {
            memcpy(&m_unk80, (char *)pNode + 0x110, 0x20);
        } else if (((PCrystalizeFxNodeView *)pNode)->m_unk28 != 0) {
            memcpy(&m_unk80, ((PCrystalizeFxNodeView *)pNode)->m_unk28, 0x20);
        }
    }
    m_unk90 = (m_unk1F0 <= m_unk90) ? m_unk90 : m_unk1F0;
    m_unk94 = (m_unk1F0 <= m_unk94) ? m_unk94 : m_unk1F0;
    m_unk98 = (m_unk1F0 <= m_unk98) ? m_unk98 : m_unk1F0;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    ((PCrystalizeFxVirtView *)this)->ModifyPosition((char *)pNode + 0x40);
    return 1;
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

// FUNCTION: 0x001FEDE0 __ct__13PCrystalizeFxFv
PCrystalizeFx::PCrystalizeFx() {
    *(void **)this = __vt__13PCrystalizeFx;
    m_unk1E0 = 0;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    memset(m_unkE0, 0, 0x100);
    m_unk1F8 = 1;
    m_unk1F9 = 1;
    m_unk1FA = 1;
}
