#ifndef PWORLD_H
#define PWORLD_H

#include "PFrustrum.h"

class PMeshNode;
class PSpacePartitionTree;
class PPakFile;
class PMNode;
class PStaticInstanceMesh;
class PArray;
struct tagParticleFxTriggerData;

// Enumerator values are not recovered yet; the name is what the mangled signatures need.
enum ePsx2FileVersion {
    ePsx2FileVersion_Placeholder = 0
};

class PWorld {
public:
    void InitFrustrum(PMat4 *pMat, float (*pVec)[4]);
    void CullMainWorld();
    int LoadEditedInstanceData(PPakFile *pFile);
    void AttachFxTriggersToNodes(PMeshNode *pNode, tagParticleFxTriggerData *pData, unsigned int nCount);
    int LoadFxTriggerData(PPakFile *pFile, tagParticleFxTriggerData **ppData, unsigned int &nCount);
    void UpdateAnimate(PMNode *pNode);
    void InitRenderFrame();
    void RenderWorld();
    void Init();
    void UpdateTimer();
    void InitMatrices();
    void Destroy();
    void CleanupStaticInstanceMeshes();
    int LoadStaticInstanceMeshes(PPakFile *pFile, PArray *pArray, ePsx2FileVersion nVersion);
    ~PWorld();

    PMeshNode *m_pMeshNode;                     // 0x000
    char _pad004[0x4];
    PSpacePartitionTree *m_pSpacePartitionTree; // 0x008
    char _pad00C[0x4];
    float m_Screen[4][4];   // 0x010
    int m_50;               // 0x050
    int m_54;               // 0x054
    int m_58;               // 0x058
    char _pad05C[0x4];
    float m_60;             // 0x060
    float m_64;             // 0x064
    int m_68;               // 0x068
    char _pad06C[0x90 - 0x6C];
    float m_Mat[4][4];      // 0x090
    float m_Vec[4];         // 0x0D0
    float m_Persp[4];       // 0x0E0
    PFrustrum m_Frustrum;   // 0x0F0
    char _pad100[0x1E0 - 0x100];
    float m_1E0;            // 0x001E0
    float m_1E4;            // 0x001E4
    float m_1E8;            // 0x001E8
    char _pad1EC[0x1ED - 0x1EC];
    bool m_1ED;             // 0x001ED
    char _pad1EE[0x8720 - 0x1EE];
    signed char m_8720;     // 0x08720
    char _pad8721[0x3];
    int m_8724;             // 0x08724
    signed char m_8728;     // 0x08728
    char _pad8729[0x8748 - 0x8729];
    int m_8748;             // 0x08748
    char _pad874C[0x9EA0 - 0x874C];
    float m_9EA0;           // 0x09EA0
    char _pad9EA4[0x9FB0 - 0x9EA4];
    unsigned int m_9FB0;                        // 0x09FB0
    unsigned int m_9FB4;                        // 0x09FB4
    PStaticInstanceMesh **m_9FB8;               // 0x09FB8
    char _pad9FBC[0x13790 - 0x9FBC];
    char m_bCulled;         // 0x13790
    char _pad13791[0x13794 - 0x13791];
    float m_13794;          // 0x13794
};

#endif
