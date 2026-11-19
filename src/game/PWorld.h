#ifndef PWORLD_H
#define PWORLD_H

#include "PFrustrum.h"

class PMeshNode;
class PSpacePartitionTree;
class PPakFile;
class PMNode;
struct tagParticleFxTriggerData;

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
    char _pad100[0x1ED - 0x100];
    bool m_1ED;             // 0x001ED
    char _pad1EE[0x8720 - 0x1EE];
    signed char m_8720;     // 0x08720
    char _pad8721[0x3];
    int m_8724;             // 0x08724
    char _pad8728[0x8748 - 0x8728];
    int m_8748;             // 0x08748
    char _pad874C[0x9EA0 - 0x874C];
    float m_9EA0;           // 0x09EA0
    char _pad9EA4[0x13790 - 0x9EA4];
    char m_bCulled;         // 0x13790
    char _pad13791[0x13794 - 0x13791];
    float m_13794;          // 0x13794
};

#endif
