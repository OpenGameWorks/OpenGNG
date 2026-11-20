#ifndef PSPACEPARTITIONTREE_H
#define PSPACEPARTITIONTREE_H

#include "types.h"
#include "PMesh.h"

class PFrustrum;
class PSpacePartitionNode;
class PLightManager;
class PMat4;

// Root of the static-world space partition. The object is 0x1289C bytes, so
// members past 0x8000 are reached with lui/addiu.
class PSpacePartitionTree {
public:
    PSpacePartitionTree();
    ~PSpacePartitionTree();

    int Load(PPakFile *pFile, PArray *pArr1, PArray *pArr2, ePsx2FileVersion nVersion);
    void CullToFrustrum(PFrustrum *pFrustrum, float *pOut);
    void ResetShaderGroups();
    void RenderMesh(PMesh *pMesh, bool bFlag);
    void RenderShaderGroups(bool bFlag);
    int Render(PLightManager *pLightManager, PMat4 *pMat, bool bFlag);

    PSpacePartitionNode *m_unk0;            // 0x000 root node, owned
    PSpacePartitionNode *m_unk4;            // 0x004 child node set by Load
    char _pad008[0x404 - 0x08];
    unsigned int m_unk404;                  // 0x404
    int m_unk408;                           // 0x408 element count set by Load
    int m_unk40C;                           // 0x40C initialised to 0x3A98
    int m_unk410;                           // 0x410
    float m_unk414;                         // 0x414 frame time from CullToFrustrum
    char _pad418[0x12480];                  // 0x418 block cleared by the constructor
    int m_unk12898;                         // 0x12898
};

#endif
