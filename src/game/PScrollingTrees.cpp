// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
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
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];
extern "C" int rand(void);
extern "C" void *__nwa__FUi(unsigned int nSize);
float FastMath_Fabs(float fVal);
void FastMath_RotateMatrix(float (*pA)[4][4], float (*pB)[4][4], float (*pRot)[4], float (*pC)[4][4]);

// A level-of-detail list inside a scrolling-tree record: count at +8, entries at +0xC.
struct PScrollingTreeLod {
    int nSize;
    void *pData;
};
struct PScrollingTreeLodList {
    unsigned int n;
    PScrollingTreeLod *p;
    int Size(unsigned int i) { return (i < n) ? p[i].nSize : 0; }
    void *Data(unsigned int i) { return (i < n) ? p[i].pData : 0; }
};

// The original strength-reduces the outer entry offset (written out as nOff) but indexes
// the inner LOD entries with `sll j,3` on every access.
#pragma opt_strength_reduction off
// FUNCTION: 0x1FAC10 Render__15PScrollingTreesFv
int PScrollingTrees::Render() {
    int nTotal = 0;
    int i;
    char *pRec;
    int nOff;
    unsigned int j;
    char *pE;
    int k;
    char *pRec2;
    int nOff2;
    unsigned int j2;
    char *pE2;
    ((PGfxEngine *)gGfxEng)->SetWorldMatrix((PMat4 *)gUnitMatrix);
    for (i = 0, nOff = 0; i < 3; i++) {
        pE = (char *)this + nOff;
        pRec = *(char **)(pE + 0x34);
        if (pRec != 0) {
            ((PShader *)*(void **)pRec)->Render(0x80, false, 0);
            for (j = 0; j < *(unsigned int *)(pRec + 8); j++) {
                int nSize = ((PScrollingTreeLodList *)(pRec + 8))->Size(j);
                void *pData = ((PScrollingTreeLodList *)(pRec + 8))->Data(j);
                ((PGfxEngine *)gGfxEng)->BeginStaticInstances(pData, nSize);
                ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->DrawStaticInstances(
                    (tagVuStaticInstance *)*(void **)(pE + 0x38), *(int *)(pE + 0x3C), 0x28, 0, 1, true);
            }
            nTotal += *(int *)(pE + 0x3C) * *(int *)(pRec + 4);
        }
        nOff += 0x10;
    }
    for (k = 0, nOff2 = 0; k < 8; k++) {
        pE2 = (char *)this + nOff2;
        pRec2 = *(char **)(pE2 + 0x70);
        if (pRec2 != 0) {
            ((PShader *)*(void **)pRec2)->Render(0x80, false, 0);
            for (j2 = 0; j2 < *(unsigned int *)(pRec2 + 8); j2++) {
                int nSize = ((PScrollingTreeLodList *)(pRec2 + 8))->Size(j2);
                void *pData = ((PScrollingTreeLodList *)(pRec2 + 8))->Data(j2);
                ((PGfxEngine *)gGfxEng)->BeginStaticInstances(pData, nSize);
                ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->DrawStaticInstances(
                    (tagVuStaticInstance *)(pE2 + 0x80), *(int *)(pE2 + 0x120), 0x28, 0, 1, true);
            }
            nTotal += *(int *)(pE2 + 0x120) * *(int *)(pRec2 + 4);
        }
        nOff2 += 0xC0;
    }
    return nTotal;
}

#pragma opt_strength_reduction reset
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
// note: DIFF 199, size 0x3E0 vs 0x3E4; lit stand-ins replaced by brace-init locals and a union quad (216 to 199); this/nB register assignment, float save order, FastMath_RotateMatrix reloc differ. Tried: ids/rot hoisting, brace-init in loop, Z block first, field stores for rot, nOff/pNodes removal, ids load after assert.
int PScrollingTrees::Create(int nA, int nB, int nType) {
    PScrollingTreeTypeIds ids = {{0x0600000A, 0x06000009, 0x06000008, 0x00000000}};
    PScrollingTreeQuad pos;
    PScrollingTreeQuad rot = (PScrollingTreeQuad){{0.0f, 0.0f, 0.0f, 1.0f}};
    if (m_unk670 == 0) {
        CdsAssert("PScrollingTrees.cpp", 0x6D, "mpResMgr");
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
        CdsAssert("PScrollingTrees.cpp", 0x7D, "mInstanceData[iType].pMasterMesh");
    }
    pEnt->m_unk4 = __nwa__FUi(nCount * 0x50);
    if (pEnt->m_unk4 == 0) {
        CdsAssert("PScrollingTrees.cpp", 0x80, "mInstanceData[iType].pInstanceData");
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
// note: DIFF 56, frame 0xA0 vs 0xB0; the 1.0 quad is a union of two 64-bit halves (75 to 56); original keeps it in a register and splats with pcpyld, ours spills to stack and reloads with lq; reloc positions for GetResource, CdsAssert and sceVu0UnitMatrix sit 4 bytes early; literal names @177/@152 vs @569/@590. Tried: u_long128 shift build (compile error), unsigned long long local splat (56, equal), union hoisted out of loop (87). A 128-bit literal `(u_long128)0x3F8000003F8000003F8000003F800000` gives the original lui/dsll32/or/pcpyld v,v,v and frame 0xA0, and indexing by i (`m_unk70 + i * 0xC0`, `((unsigned int *)&ids)[i]`) puts this in s0; together 69 words because MWCC then folds rec+0x60 into store offsets where the original bumps s2 by 0x60 and keeps pMat in s3 (src/scratch/solo/cf5.py).
int PScrollingTrees::CreateFloor() {
    PScrollingTreeIds ids = {{0x0600001A, 0x06000014, 0x06000015, 0x06000016, 0x06000017, 0x06000018, 0x06000019, 0x06000013}};
    PScrollingTreeQuad quad = {{0.0f, -140.0f, 170.0f, 1.0f}};
    int nRec = 0;
    int nOff = 0;
    for (int i = 0; i < 8; i++) {
        char *rec = m_unk70 + nRec;
        *(PMNode **)rec = m_unk670->GetResource(*(unsigned int *)((char *)&ids + nOff), false);
        if (*(PMNode **)rec == 0) {
            CdsAssert("PScrollingTrees.cpp", 0x50, "apGroup->pMasterMesh");
        }
        char *pMat = rec + 0x10;
        *(int *)(rec + 0xB0) = 2;
        sceVu0UnitMatrix(pMat);
        *(PScrollingTreeQuad *)(pMat + 0x30) = quad;
        {
            union { u_long128 q; unsigned long long d[2]; } one;
            one.d[0] = 0x3F8000003F800000ULL;
            one.d[1] = 0x3F8000003F800000ULL;
            *(u_long128 *)(pMat + 0x40) = one.q;
        }
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
        CdsAssert("PScrollingTrees.cpp", 0x31, "pResMgr");
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
