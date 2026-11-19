#ifndef PPARTICLEMANAGER_H
#define PPARTICLEMANAGER_H

#include "types.h"

class PParticleSystem;
class PParticleRain;
class PMovingFog;
class PParticleFog;
class PStaticInstanceGroup;
class PParticleOneShot;
class PMNode;
class PParticleSystem;
class PFrustrum;
struct tagVuParticle;
struct tagParticleRainParams;

class PParticleManager {
public:
    void *AllocAuraParticle();
    void FreeAuraParticle(tagVuParticle *pParticle);
    void DestroyMovingFog();
    void SetLightningDensity(float fDensity);
    void SetRainDensity(float fDensity, bool bFlag);
    void SetRainDensity(unsigned int hRain, float fDensity, bool bFlag);
    void DestroyRain();
    PParticleRain *CreateRain(tagParticleRainParams *pParams);
    int CreateEweedReaction(float *pPos);
    int CreateSulphurReaction(float *pPos, float fUnused);
    int CreateGroundDust(float *pPos, float fScale);
    void RenderEweedReactionFx();
    void InitEweedReactionFx();
    void DestroyEweedReactionFx();
    void InitSulphurReactionFx();
    void RenderSulphurReactionFx();
    void DestroySulphurReactionFx();
    void RenderGroundDustFx();
    void DestroyGroundDustFx();
    PParticleOneShot *Create(unsigned int hFx, float fA, float fB, float fC, PMNode *pNode, bool bFlag);
    PParticleOneShot *CreateOneShot(unsigned int hFx, float fA, float fB, float fC);
    int IsValid(PParticleSystem *pSystem);
    void RenderParticleInstanceGroups(bool bFlag);
    void AddParticleInstanceGroup(PStaticInstanceGroup *pGroup);
    void AddMasterParticleInstance(PParticleSystem *pFx);
    void RemoveAll();
    void Stop(unsigned int hSystem);
    void StopFx(unsigned int hSystem);
    void Destroy(unsigned int hSystem);

    void Add(PParticleSystem *pSystem);
    void Remove(PParticleSystem *pSystem);
    void RemoveAllParticleSystems();
    void RemoveAllFogObjects();
    void UpdateMasterParticleInstances(float fDt, PFrustrum *pFrustrum);

    char _pad000[0x20];
    unsigned int m_unk20;       // 0x20
    unsigned int m_unk24;       // 0x24
    PParticleFog **m_unk28;     // 0x28
    char _pad02C[0x6A8 - 0x2C];
    PParticleRain *m_pRain;     // 0x6A8
    char _pad6AC[0x9B4 - 0x6AC];
    PMovingFog *m_unk9B4;       // 0x9B4
    char _pad9B8[0xEC0 - 0x9B8];
    int m_unkEC0;               // 0xEC0
    char _padEC4[0x2068 - 0xEC4];
    unsigned int m_unk2068;     // 0x2068
    unsigned int m_unk206C;     // 0x206C
    PStaticInstanceGroup **m_unk2070; // 0x2070
    char _pad2074[0x2078 - 0x2074];
    unsigned int m_unk2078;     // 0x2078
    unsigned int m_unk207C;     // 0x207C
    PParticleSystem **m_unk2080; // 0x2080
};

#endif
