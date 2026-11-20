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
extern "C" int rand(void);
extern "C" void *__nwa__FUi(unsigned int nSize);
float FastMath_Fabs(float fVal);
void FastMath_RotateMatrix(float (*pA)[4][4], float (*pB)[4][4], float (*pRot)[4], float (*pC)[4][4]);
extern PScrollingTreeQuad lit_0024DDF0;

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

// FUNCTION: 0x1FAE50 Animate__15PScrollingTreesFf
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
        PScrollingTreeNode *pN2 = (PScrollingTreeNode *)((char *)this + 0x80 + k * 0xC0);
        float fVal = pN2->m_unk38 + fStep;
        pN2->m_unk38 = fVal;
        if (!(fVal < 170.0f)) {
            pN2->m_unk38 = -350.0f + (fVal - 170.0f);
        }
    }
}

// DRAFT: 0x1FAF30 Create__15PScrollingTreesFiii
// note: DIFF 216, size 0x3F8 vs 0x3E4 (frame 0x110 vs 0x100); this/nB register assignment, float save order, FastMath_RotateMatrix reloc differ. Tried: ids/rot hoisting, brace-init in loop, Z block first, field stores for rot, nOff/pNodes removal (240-247), ids load after assert (222).
int PScrollingTrees::Create(int nA, int nB, int nType) {
    PScrollingTreeQuad ids = lit_0024DDF0;
    PScrollingTreeQuad pos;
    PScrollingTreeQuad rot = (PScrollingTreeQuad){{0.0f, 0.0f, 0.0f, 1.0f}};
    if (m_unk670 == 0) {
        CdsAssert__FPciPc("PScrollingTrees.cpp", 0x6D, "mpResMgr");
    }
    float fSpanX = m_unk20[0] - m_unk10[0];
    float fStepX = fSpanX / (float)nB;
    float fHalfX = 0.5f * fSpanX;
    float fCenterX = 0.5f * (m_unk20[0] + m_unk10[0]);
    float fSpanZ = m_unk20[2] - m_unk10[2];
    float fStepZ = fSpanZ / (float)nA;
    float fHalfStepX = 0.5f * fStepX;
    float fHalfStepZ = 0.5f * fStepZ;
    float fX = m_unk10[0] + fHalfStepX;
    float fZ = m_unk10[2] + fHalfStepZ;
    int nCount = nA * nB;
    PScrollingTreeEntry *pEnt = &m_unk34[nType];
    pEnt->m_unk8 = nCount;
    pEnt->m_unk0 = (int)m_unk670->GetResource(*(unsigned int *)((char *)&ids + nType * 4), false);
    if (pEnt->m_unk0 == 0) {
        CdsAssert__FPciPc("PScrollingTrees.cpp", 0x7D, "mInstanceData[iType].pMasterMesh");
    }
    pEnt->m_unk4 = __nwa__FUi(nCount * 0x50);
    if (pEnt->m_unk4 == 0) {
        CdsAssert__FPciPc("PScrollingTrees.cpp", 0x80, "mInstanceData[iType].pInstanceData");
    }
    char *pNodes = (char *)pEnt->m_unk4;
    int nRow = 0;
    for (int i = 0; i < nA; i++) {
        int nOff = nRow;
        for (int j = 0; j < nB; j++) {
            char *pCell = pNodes + nOff;
            float fA = 0.3f * fStepX;
            float u1 = (float)rand() / 2147483648.0f;
            pos.f[0] = fX + (fA + ((0.3f * -fStepX - fA) * u1));
            pos.f[1] = m_unk10[1];
            float fB = 0.3f * fStepZ;
            float u2 = (float)rand() / 2147483648.0f;
            pos.f[2] = fZ + (fB + ((0.3f * -fStepZ - fB) * u2));
            pos.f[3] = 1.0f;
            float u3 = (float)rand() / 2147483648.0f;
            rot.f[1] = -180.0f + 360.0f * u3;
            float fT = FastMath_Fabs(pos.f[0] - fCenterX) / fHalfX;
            float u4 = (float)rand() / 2147483648.0f;
            float fS = 1.0f + 0.5f * u4;
            sceVu0UnitMatrix(pCell);
            *(float *)(pCell + 0x0) = fS;
            *(float *)(pCell + 0x14) = 1.0f + 0.5f * fT;
            *(float *)(pCell + 0x28) = fS;
            FastMath_RotateMatrix((float (*)[4][4])pCell, (float (*)[4][4])pCell, (float (*)[4])rot.f, 0);
            *(PScrollingTreeQuad *)(pCell + 0x30) = pos;
            *(float *)(pCell + 0x40) = 1.0f;
            *(float *)(pCell + 0x44) = 1.0f;
            *(float *)(pCell + 0x48) = 1.0f;
            *(float *)(pCell + 0x4C) = 1.0f;
            nOff += 0x50;
            nRow += 0x50;
            fX += fStepX;
        }
        fZ += fStepZ;
        fX = m_unk10[0] + fHalfStepX;
    }
    return 1;
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
