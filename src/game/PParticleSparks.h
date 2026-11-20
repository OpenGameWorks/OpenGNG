#ifndef PPARTICLESPARKS_H
#define PPARTICLESPARKS_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
struct tagVuFxLine;

// Spark emitter. The PParticleSystem base occupies the first 0xE0 bytes.
// Methods are not declared virtual here: the base has no vptr declared, so a
// virtual keyword would add one and shift the layout.
class PParticleSparks : public PParticleSystem {
public:
    PParticleSparks();
    ~PParticleSparks();
    void Animate(float fDelta);
    void Render();
    void ModifyPosition(PMat4 *pMat);
    void Start();
    void InitSparkDirections();

    u_long128 m_unkE0;          // 0x0E0 spark vector
    char _padF0[0x50];
    void *m_unk140;             // 0x140 spark buffer, released by the destructor
    int m_unk144;               // 0x144
    int m_unk148;               // 0x148
    char _pad14C[4];
    u_long128 m_unk150;         // 0x150
    u_long128 m_unk160;         // 0x160
    int m_unk170;               // 0x170 spark count set by Start
};

#endif
