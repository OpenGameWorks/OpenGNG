// FLAGS: -str readonly
#include "types.h"
#include "PSpacePartitionNode.h"
#include "PMesh.h"
#include "PFrustrum.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dt__5PMeshFv(void *pThis, short nFlag);
extern "C" void __destroy_new_array(void *pArray, void *pDtor);
extern "C" void *__dt__20PStaticInstanceGroupFv(void *pThis, short nFlag);

#define SPTREE_MAX_VISIBLE_NODES 0x100
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PSpacePartitionNode.cpp", line, #cond))

class PStaticInstanceGroup {
public:
    int Render();
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
