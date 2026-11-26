#ifndef PPARTICLEAURA_H
#define PPARTICLEAURA_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
struct tagParticleAuraParams;

// Aura emitter. The PParticleSystem base occupies the first 0xE0 bytes;
// the members below start at 0xE0. The parameter block copied in by Create
// spans 0xE0..0x11F.
class PParticleAura : public PParticleSystem {
public:
    PParticleAura();

    void SetPosition(float *pPos, float *pUnused);
    void ModifyPosition(PMat4 *pMat);
    void Animate(float fDelta);
    int Create(tagParticleAuraParams *pParams, float fX, float fY, float fZ);
    void Render();

    float m_unkE0[16];          // 0x0E0 params block (0x40 bytes), offsets 0x0E0..0x11F
    float m_unk120[4];          // 0x120 position vector
    void *m_unk130;             // 0x130 particle from PParticleManager::AllocAuraParticle
    float m_unk134;             // 0x134
    float m_unk138;             // 0x138
};

#endif
