#ifndef PPARTICLELITEFIRE_H
#define PPARTICLELITEFIRE_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

// Lite fire emitter. The PParticleSystem base occupies the first 0xE0 bytes;
// the members below start at 0xE0. The vtable (__vt__17PParticleLiteFire) is
// stored by the constructor and destructor, so the class declares no virtuals.
class PParticleLiteFire : public PParticleSystem {
public:
    PParticleLiteFire();
    ~PParticleLiteFire();
    void Enable(bool bEnable);
    void FadeAndDie(unsigned int nArg);
    void SetPosition(float *pPos, float *pUnused);
    void ModifyPosition(PMat4 *pMat);

    char _pad0E0[0x60];         // 0x0E0 MulVector output written by ModifyPosition
    float m_unk140;             // 0x140 scales the y offset in SetPosition
    char _pad144[0x1C];         // 0x144
    void *m_unk160;             // 0x160 buffer filled by SetPosition, released by the destructor
    char _pad164[0x0C];         // 0x164
    float m_unk170[4];          // 0x170 position copied by SetPosition
    void *m_unk180;             // 0x180 buffer released by the destructor
    char _pad184[0x08];         // 0x184
    float m_unk18C;             // 0x18C set by FadeAndDie
    unsigned char m_unk190;     // 0x190 set by FadeAndDie, cleared by the constructor
    unsigned char m_unk191;     // 0x191 pending-fill flag, cleared by the constructor
};

#endif
