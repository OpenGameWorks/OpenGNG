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

// Empty member subobject with a declared destructor; it makes the constructor keep
// `this` in memory and reload it, as the original does.
class PCutSceneGuard {
public:
    PCutSceneGuard() {}
    ~PCutSceneGuard() {}
    char _pad000[4];
};

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
    bool LoadActors(PPakFile *pFile, unsigned int nFlag);
    void CullTest(PFrustrum *pFrustrum);
    bool Animate(float fTime);
    void GetViewMatrix(PMat4 *pMat);
    void Render(PLightManager *pLightMgr);

    char m_unk00[0x40];
    PMNode *m_unk40;
    int m_unk44;
    PCutSceneAnim *m_unk48;
    PCutSceneAnim *m_unk4C;
    PCutSceneAnim *m_unk50;
    PCutSceneAnim *m_unk54;
    PCutSceneGuard m_unk58;
    int m_unk5C;
    char m_unk60[0x10];
    char m_unk70[0x10];
    char m_unk80[0x10];
    char m_unk90[0x10];
    unsigned int m_unkA0;
    unsigned int m_unkA4;
    void **m_unkA8;
    char m_unkAC[4];
    unsigned int m_unkB0;
    unsigned int m_unkB4;
    void **m_unkB8;
    char m_unkBC[4];
    float m_unkC0[4];
    char m_unkD0[0x10];
    float m_unkE0[4];
    float m_unkF0;
    char m_unkF4[0xC];
    char m_unk100[0x20E0 - 0x100];
    int m_unk20E0;
    char m_unk20E4[0x2130 - 0x20E4];
    int m_unk2130;
    char m_unk2134[4];
    float m_unk2138;
    signed char m_unk213C;
    signed char m_unk213D;
};

#endif
