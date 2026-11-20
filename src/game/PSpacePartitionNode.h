#ifndef PSPACEPARTITIONNODE_H
#define PSPACEPARTITIONNODE_H

#include "types.h"

class PMesh;
class PFrustrum;
class PStaticInstanceGroup;

// Space partition tree node. Mesh pointer at 0x00, flag at 0x04, four child
// pointers at 0x08..0x17, u16 child count at 0x18, u16 group count at 0x1A,
// static instance group base at 0x1C (12-byte stride), and a 0x20-byte block
// cleared by the constructor at 0x20. Size 0x40.
class PSpacePartitionNode {
public:
    PSpacePartitionNode();
    ~PSpacePartitionNode();
    int CountNodes();
    void RecurseSetSTAnimOptions(bool bFlag);
    void Animate(float fDelta);
    int RenderStaticInstances();
    int TestNodeWithFrustrum(PFrustrum *poFrustrum, PSpacePartitionNode **ppNodes, unsigned int &nNode);

    PMesh *m_pMesh;
    int m_unk4;
    PSpacePartitionNode *m_pChild[4];
    unsigned short m_nChildCount;
    unsigned short m_nGroupCount;
    PStaticInstanceGroup *m_pGroup;
    char m_unk20[0x20];
};

#endif
