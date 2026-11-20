// FLAGS: -str readonly
#include "types.h"
#include "PScrollingTrees.h"
#include "PResourceManager.h"
#include "PShader.h"
#include "PGfxEngine.h"
#include "PDisplayList.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pExpr);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern PScrollingTreeIds lit_0024DDC0;
extern PScrollingTreeQuad lit_0024DDE0;
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];

// DRAFT: 0x1FAC10 Render__15PScrollingTreesFv
// note: 115 words; frame 0x90 vs 0x80; this in s7 vs s0; first-call args and gUnitMatrix load order; loop 1 offset reg s6 (addu s6,s7,s5). Tried: local class stubs, nCount removal, per-iter entry pointer (118), nTotal after first call (115, kept), this-derived loop 2 base (no change).
int PScrollingTrees::Render() {
    ((PGfxEngine *)gGfxEng)->SetWorldMatrix((PMat4 *)gUnitMatrix);
    int nTotal = 0;
    for (int i = 0; i < 3; i++) {
        char *pRec = (char *)m_unk34[i].m_unk0;
        if (pRec != 0) {
            ((PShader *)*(void **)pRec)->Render(0x80, false, 0);
            for (int j = 0; j < *(int *)(pRec + 8); j++) {
                int nCount = *(int *)(pRec + 8);
                int nSize = (j < nCount) ? *(int *)(*(char **)(pRec + 0xC) + j * 8) : 0;
                void *pData = (j < nCount) ? *(void **)(*(char **)(pRec + 0xC) + j * 8 + 4) : 0;
                ((PGfxEngine *)gGfxEng)->BeginStaticInstances(pData, nSize);
                ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->DrawStaticInstances(
                    (tagVuStaticInstance *)m_unk34[i].m_unk4, m_unk34[i].m_unk8, 0x28, 0, 1, true);
            }
            nTotal += *(int *)(pRec + 4) * m_unk34[i].m_unk8;
        }
    }
    for (int k = 0; k < 8; k++) {
        char *pBase = m_unk70 + k * 0xC0;
        char *pRec = *(char **)pBase;
        if (pRec != 0) {
            ((PShader *)*(void **)pRec)->Render(0x80, false, 0);
            for (int j = 0; j < *(int *)(pRec + 8); j++) {
                int nCount = *(int *)(pRec + 8);
                int nSize = (j < nCount) ? *(int *)(*(char **)(pRec + 0xC) + j * 8) : 0;
                void *pData = (j < nCount) ? *(void **)(*(char **)(pRec + 0xC) + j * 8 + 4) : 0;
                ((PGfxEngine *)gGfxEng)->BeginStaticInstances(pData, nSize);
                ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->DrawStaticInstances(
                    (tagVuStaticInstance *)(pBase + 0x10), *(int *)(pBase + 0xB0), 0x28, 0, 1, true);
            }
            nTotal += *(int *)(pRec + 4) * *(int *)(pBase + 0xB0);
        }
    }
    return nTotal;
}

// DRAFT: 0x1FAE50 Animate__15PScrollingTreesFf
// note: loop 2 base: original addiu v1+0x80 with 0x38 displacement, ours folds to v1+0xB8; 2 words.
void PScrollingTrees::Animate(float fTime) {
    float fStep = m_unk30 * fTime;
    for (int i = 0; i < 3; i++) {
        PScrollingTreeNode *pNode = (PScrollingTreeNode *)m_unk34[i].m_unk4;
        if (pNode != 0) {
            for (int j = 0; j < m_unk34[i].m_unk8; j++) {
                PScrollingTreeNode *pN = &pNode[j];
                float fNew = pN->m_unk38 + fStep;
                pN->m_unk38 = fNew;
                if (!(fNew <= m_unk20[2])) {
                    pN->m_unk38 = m_unk10[2];
                }
            }
        }
    }
    for (int k = 0; k < 8; k++) {
        float *pT = (float *)((char *)this + 0xB8 + k * 0xC0);
        float fVal = *pT + fStep;
        *pT = fVal;
        if (!(fVal < 170.0f)) {
            PScrollingTreeNode *pN2 = (PScrollingTreeNode *)((char *)pT - 0x38);
            pN2->m_unk38 = -350.0f + (fVal - 170.0f);
        }
    }
}

// DRAFT: 0x1FB320 CreateFloor__15PScrollingTreesFv
// note: prologue frame 0xB0 vs 0xA0 (compound literal temp); s0..s5 allocation differs; 1.0 quad not built inline; 91 words.
int PScrollingTrees::CreateFloor() {
    PScrollingTreeIds ids = lit_0024DDC0;
    PScrollingTreeQuad quad = lit_0024DDE0;
    int nRec = 0;
    int nOff = 0;
    for (int i = 0; i < 8; i++) {
        char *rec = m_unk70 + nRec;
        *(PMNode **)rec = m_unk670->GetResource(*(unsigned int *)((char *)&ids + nOff), false);
        if (*(PMNode **)rec == 0) {
            CdsAssert__FPciPc("PScrollingTrees.cpp", 0x50, "apGroup->pMasterMesh");
        }
        char *pMat = rec + 0x10;
        *(int *)(rec + 0xB0) = 2;
        sceVu0UnitMatrix(pMat);
        *(PScrollingTreeQuad *)(pMat + 0x30) = quad;
        *(PScrollingTreeQuad *)(pMat + 0x40) = (PScrollingTreeQuad){{1.0f, 1.0f, 1.0f, 1.0f}};
        rec += 0x60;
        sceVu0UnitMatrix(rec);
        *(float *)(rec + 0x0) = 0.0f;
        *(float *)(rec + 0x14) = 0.0f;
        *(float *)(rec + 0x28) = 0.0f;
        *(float *)(rec + 0x30) = -100000.0f;
        *(float *)(rec + 0x34) = -1000000.0f;
        *(float *)(rec + 0x38) = 0.0f;
        *(float *)(rec + 0x3C) = 1.0f;
        *(float *)(rec + 0x40) = 0.0f;
        *(float *)(rec + 0x44) = 0.0f;
        *(float *)(rec + 0x48) = 0.0f;
        *(float *)(rec + 0x4C) = 0.0f;
        nRec += 0xC0;
        nOff += 4;
        quad.f[2] -= 65.0f;
    }
    return 1;
}

// FUNCTION: 0x1FB4A0 Init__15PScrollingTreesFPfPffP16PResourceManager
void PScrollingTrees::Init(float *pVecA, float *pVecB, float fScale, PResourceManager *pResMgr) {
    if (pResMgr == 0) {
        CdsAssert__FPciPc("PScrollingTrees.cpp", 0x31, "pResMgr");
    }
    sceVu0CopyVector(m_unk10, pVecA);
    sceVu0CopyVector(m_unk20, pVecB);
    m_unk30 = fScale;
    m_unk670 = pResMgr;
}

// FUNCTION: 0x1FB530 __dt__15PScrollingTreesFv
PScrollingTrees::~PScrollingTrees() {
    for (int i = 0; i < 3; i++) {
        if (m_unk34[i].m_unk4 != 0) {
            __dla__FPv(m_unk34[i].m_unk4);
            m_unk34[i].m_unk4 = 0;
        }
        m_unk34[i].m_unk0 = 0;
    }
}

// FUNCTION: 0x1FB5E0 __ct__15PScrollingTreesFv
PScrollingTrees::PScrollingTrees() {
    memset(m_unk34, 0, 0x30);
    memset(m_unk70, 0, 0x600);
}
