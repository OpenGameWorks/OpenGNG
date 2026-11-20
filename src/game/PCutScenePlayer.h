#ifndef PCUTSCENEPLAYER_H
#define PCUTSCENEPLAYER_H

#include "types.h"

class PArray;
class PPakFile;
class PMNode;
class PFrustrum;
class PCutSceneAnim;
class PMat4;
class PLightManager;

class PCutScenePlayer {
public:
    PCutScenePlayer();
    ~PCutScenePlayer();
    void KillActorFx();
    void Abort();
    void ResetCutScene();
    void ResetAnimations();
    void AttachActors();
    void UpdatePlayer();
    void Unload(bool bFlag);
    void SetBgNodesOpacity(PArray *pArray, float fOpacity);
    bool LoadNodeNameTable(PPakFile *pFile, unsigned int nCount, PArray *pArray);
    bool LoadBgAnims(PPakFile *pFile, unsigned int nFlag);
    void CullTest(PFrustrum *pFrustrum);
    void GetViewMatrix(PMat4 *pMat);
    void Render(PLightManager *pLightMgr);

    char m_unk00[0x40];
    PMNode *m_unk40;
    int m_unk44;
    PCutSceneAnim *m_unk48;
    PCutSceneAnim *m_unk4C;
    PCutSceneAnim *m_unk50;
    PCutSceneAnim *m_unk54;
    char m_unk58[4];
    int m_unk5C;
    char m_unk60[0x10];
    char m_unk70[0x10];
    char m_unk80[0x10];
    char m_unk90[0x10];
    char m_unkA0[0x10];
    unsigned int m_unkB0;
    unsigned int m_unkB4;
    void **m_unkB8;
    char m_unkBC[0x44];
    char m_unk100[0x2130 - 0x100];
    int m_unk2130;
    char m_unk2134[0x8];
    signed char m_unk213C;
    signed char m_unk213D;
};

#endif
