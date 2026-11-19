#ifndef PPARTICLEMANAGER_H
#define PPARTICLEMANAGER_H

#include "types.h"

class PParticleSystem;
class PParticleRain;
class PMovingFog;
class PStaticInstanceGroup;
class PParticleOneShot;
class PMNode;
struct tagVuParticle;

class PParticleManager {
public:
    void FreeAuraParticle(tagVuParticle *pParticle);
    void DestroyMovingFog();
    void SetLightningDensity(float fDensity);
    void SetRainDensity(float fDensity, bool bFlag);
    void SetRainDensity(unsigned int hRain, float fDensity, bool bFlag);
    void DestroyRain();
    void RenderEweedReactionFx();
    PParticleOneShot *Create(unsigned int hFx, float fA, float fB, float fC, PMNode *pNode, bool bFlag);
    PParticleOneShot *CreateOneShot(unsigned int hFx, float fA, float fB, float fC);
    int IsValid(PParticleSystem *pSystem);
    void AddParticleInstanceGroup(PStaticInstanceGroup *pGroup);
    void AddMasterParticleInstance(PParticleSystem *pFx);
    void RemoveAll();
    void Stop(unsigned int hSystem);
    void StopFx(unsigned int hSystem);
    void Destroy(unsigned int hSystem);

    void Remove(PParticleSystem *pSystem);
    void RemoveAllParticleSystems();
    void RemoveAllFogObjects();

    char _pad000[0x6A8];
    PParticleRain *m_pRain;     // 0x6A8
    char _pad6AC[0x9B4 - 0x6AC];
    PMovingFog *m_unk9B4;       // 0x9B4
    char _pad9B8[0xEC0 - 0x9B8];
    int m_unkEC0;               // 0xEC0
};

#endif
