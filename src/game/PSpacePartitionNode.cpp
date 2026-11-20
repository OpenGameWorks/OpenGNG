// FLAGS: -str readonly
#include "types.h"
#include "PSpacePartitionNode.h"
#include "PMesh.h"
#include "PFrustrum.h"
#include "PPakFile.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *memcpy(void *pDst, void *pSrc, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dt__5PMeshFv(void *pThis, short nFlag);
extern "C" void __destroy_new_array(void *pArray, void *pDtor);
extern "C" void *__dt__20PStaticInstanceGroupFv(void *pThis, short nFlag);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" float sqrtf(float fValue);

#define SPTREE_MAX_VISIBLE_NODES 0x100
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PSpacePartitionNode.cpp", line, #cond))
#define CDS_ASSERT_MSG(line, cond, msg) ((cond) ? (void)0 : CdsAssert__FPciPc("PSpacePartitionNode.cpp", line, msg))

class PStaticInstanceGroup {
public:
    PStaticInstanceGroup();
    int Render();
    int Load(PPakFile *poFile, PArray *poInstances, ePsx2FileVersion eVersion);
    ~PStaticInstanceGroup();
    char _pad[0xC];
};

// FUNCTION: 0x001986B0 CountNodes__19PSpacePartitionNodeFv
int PSpacePartitionNode::CountNodes() {
    int nCount = 0;
    if (m_pMesh) {
        nCount++;
    }
    for (unsigned int i = 0; i < m_nChildCount; i++) {
        nCount += m_pChild[i]->CountNodes();
    }
    return nCount;
}

// FUNCTION: 0x00198730 TestNodeWithFrustrum__19PSpacePartitionNodeFP9PFrustrumPP19PSpacePartitionNodeRUi
int PSpacePartitionNode::TestNodeWithFrustrum(PFrustrum *poFrustrum, PSpacePartitionNode **ppNodes, unsigned int &nNode) {
    CDS_ASSERT(0x15E, poFrustrum);
    int nCount = 0;
    int nHit = poFrustrum->IntersectBox((float (*)[2][4])m_unk20, 0);
    m_unk4 = nHit;
    if (nHit != 0) {
        if (m_pMesh) {
            CDS_ASSERT(0x16B, nNode < SPTREE_MAX_VISIBLE_NODES);
            ppNodes[nNode] = this;
            nNode++;
            nCount += m_pMesh->m_unkA;
        }
        for (unsigned int i = 0; i < m_nChildCount; i++) {
            nCount += m_pChild[i]->TestNodeWithFrustrum(poFrustrum, ppNodes, nNode);
        }
    }
    return nCount;
}

// FUNCTION: 0x00198860 RecurseSetSTAnimOptions__19PSpacePartitionNodeFb
void PSpacePartitionNode::RecurseSetSTAnimOptions(bool bFlag) {
    if (m_pMesh) {
        m_pMesh->SetSTAnimOptions(bFlag);
    }
    for (unsigned int i = 0; i < m_nChildCount; i++) {
        m_pChild[i]->RecurseSetSTAnimOptions(bFlag);
    }
}

// FUNCTION: 0x001988F0 Animate__19PSpacePartitionNodeFf
void PSpacePartitionNode::Animate(float fDelta) {
    if (m_pMesh) {
        m_pMesh->AnimateShaders(fDelta, false);
    }
    for (unsigned int i = 0; i < m_nChildCount; i++) {
        m_pChild[i]->Animate(fDelta);
    }
}

// FUNCTION: 0x00198980 RenderStaticInstances__19PSpacePartitionNodeFv
int PSpacePartitionNode::RenderStaticInstances() {
    int nTotal = 0;
    if (m_unk4) {
        if (m_nGroupCount && m_pGroup) {
            for (int i = 0; i < m_nGroupCount; i++) {
                nTotal += m_pGroup[i].Render();
            }
        }
        for (unsigned int i = 0; i < m_nChildCount; i++) {
            nTotal += m_pChild[i]->RenderStaticInstances();
        }
    }
    return nTotal;
}

// DRAFT: 0x00198A40 Load__19PSpacePartitionNodeFP8PPakFileP6PArrayP6PArray16ePsx2FileVersion
// note: DIFF 95; aHeader[9] test register (0x78-0x88), loop-tail b offsets, min/max loop index register (0x340-0x3A4); tried while-loop, unsigned nIdx, do-while min/max, byte-offset min/max (no gain)
int PSpacePartitionNode::Load(PPakFile *poFile, PArray *poTextures, PArray *poInstances, ePsx2FileVersion eVersion) {
    unsigned int aHeader[12];
    unsigned int aMeshHeader[4];
    int nTag;
    float vChildMin[4];
    float vChildMax[4];
    float vMin[4];
    float vMax[4];

    if (poFile == 0) {
        CdsAssert__FPciPc("PSpacePartitionNode.cpp", 0x44, "poFile");
    }
    if (poFile->Read(aHeader, 0x30) != 0x30) {
        return 0;
    }
    if (aHeader[9] != 0) {
        if (aHeader[9] >= 0x10000U) {
            CdsAssert__FPciPc("PSpacePartitionNode.cpp", 0x4F, "aHeader.uNumStaticInstanceGroups <= 0xffff");
        }
        m_nGroupCount = (unsigned short)aHeader[9];
        m_pGroup = new PStaticInstanceGroup[m_nGroupCount];
        if (m_pGroup == 0) {
            CdsAssert__FPciPc("PSpacePartitionNode.cpp", 0x52, "mpStaticInstanceGroupTable");
        }
        for (int i = 0; i < (int)m_nGroupCount; i++) {
            if (m_pGroup[i].Load(poFile, poInstances, eVersion) == 0) {
                return 0;
            }
        }
    }
    memcpy(m_unk20, aHeader, 0x20);
    if (poFile->Read(aMeshHeader, 0x10) != 0x10) {
        return 0;
    }
    if (aMeshHeader[0] != 0) {
        if (m_pMesh != 0) {
            CdsAssert__FPciPc("PSpacePartitionNode.cpp", 0x6B, "mpMesh == NULL");
        }
        m_pMesh = new PMesh;
        if (m_pMesh == 0) {
            return 0;
        }
        if (m_pMesh->Load(poFile, poTextures, aMeshHeader[0], aMeshHeader[1], eVersion, true) == 0) {
            __dt__5PMeshFv(m_pMesh, 1);
            m_pMesh = 0;
            return 0;
        }
    }
    nTag = 0;
    if (poFile->Read(&nTag, 4) != 4) {
        return 0;
    }
    if (nTag == 0xF) {
        return 1;
    }
    while (nTag == 0xE) {
        PSpacePartitionNode *pChild = new PSpacePartitionNode;
        if (pChild == 0) {
            return 0;
        }
        if (pChild->Load(poFile, poTextures, poInstances, eVersion) == 0) {
            return 0;
        }
        if ((unsigned short)m_nChildCount >= 4U) {
            CdsAssert__FPciPc("PSpacePartitionNode.cpp", 0x96, "mnChild < sizeof(mChildArray) / 4");
        }
        unsigned int nIdx = m_nChildCount;
        m_nChildCount = nIdx + 1;
        m_pChild[nIdx] = pChild;
        sceVu0SubVector(vChildMin, (float *)pChild->m_unk20, (float *)(pChild->m_unk20 + 0x10));
        sceVu0AddVector(vChildMax, (float *)pChild->m_unk20, (float *)(pChild->m_unk20 + 0x10));
        sceVu0SubVector(vMin, (float *)m_unk20, (float *)(m_unk20 + 0x10));
        sceVu0AddVector(vMax, (float *)m_unk20, (float *)(m_unk20 + 0x10));
        for (int i = 0; i < 3; i++) {
            if (vChildMin[i] < vMin[i]) {
                vMin[i] = vChildMin[i];
            }
            if (!(vChildMax[i] <= vMax[i])) {
                vMax[i] = vChildMax[i];
            }
        }
        sceVu0AddVector(vChildMin, vMin, vMax);
        sceVu0ScaleVector((float *)m_unk20, vChildMin, 0.5f);
        *(float *)(m_unk20 + 0x0C) = 1.0f;
        sceVu0SubVector((float *)(m_unk20 + 0x10), vMax, (float *)m_unk20);
        *(float *)(m_unk20 + 0x1C) = sqrtf(sceVu0InnerProduct((float *)(m_unk20 + 0x10), (float *)(m_unk20 + 0x10)));
        nTag = 0;
        if (poFile->Read(&nTag, 4) != 4) {
            return 0;
        }
        if (nTag == 0xF) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x00198ED0 __dt__19PSpacePartitionNodeFv
PSpacePartitionNode::~PSpacePartitionNode() {
    for (unsigned int i = 0; i < m_nChildCount; i++) {
        delete m_pChild[i];
    }
    m_nChildCount = 0;
    if (m_pMesh) {
        __dt__5PMeshFv(m_pMesh, 1);
        m_pMesh = 0;
    }
    if (m_pGroup) {
        __destroy_new_array(m_pGroup, (void *)__dt__20PStaticInstanceGroupFv);
        m_pGroup = 0;
    }
    m_nGroupCount = 0;
}

// FUNCTION: 0x00198FA0 __ct__19PSpacePartitionNodeFv
PSpacePartitionNode::PSpacePartitionNode() {
    m_pMesh = 0;
    m_unk4 = 4;
    m_nChildCount = 0;
    memset(m_unk20, 0, 0x20);
    m_pGroup = 0;
    m_nGroupCount = 0;
}
