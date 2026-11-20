#include "types.h"
#include "PSpacePartitionNode.h"
#include "PMesh.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);

class PStaticInstanceGroup {
public:
    int Render();
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

// FUNCTION: 0x00198FA0 __ct__19PSpacePartitionNodeFv
PSpacePartitionNode::PSpacePartitionNode() {
    m_pMesh = 0;
    m_unk4 = 4;
    m_nChildCount = 0;
    memset(m_unk20, 0, 0x20);
    m_pGroup = 0;
    m_nGroupCount = 0;
}
