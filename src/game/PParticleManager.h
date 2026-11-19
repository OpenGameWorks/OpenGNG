#ifndef PPARTICLEMANAGER_H
#define PPARTICLEMANAGER_H

#include "types.h"

class PParticleSystem;
class PParticleRain;
struct tagVuParticle;

class PParticleManager {
public:
    void FreeAuraParticle(tagVuParticle *pParticle);
    void SetLightningDensity(float fDensity);
    void DestroyRain();
    int IsValid(PParticleSystem *pSystem);
    void RemoveAll();

    void Remove(PParticleSystem *pSystem);
    void RemoveAllParticleSystems();
    void RemoveAllFogObjects();

    char _pad000[0x6A8];
    PParticleRain *m_pRain;     // 0x6A8
    char _pad6AC[0xEC0 - 0x6AC];
    int m_unkEC0;               // 0xEC0
};

#endif
