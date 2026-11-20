#ifndef PPARTICLEFIRE_H
#define PPARTICLEFIRE_H

#include "types.h"
#include "PParticleSystem.h"

// Fire emitter. The PParticleSystem base occupies the first 0xE0 bytes;
// the members below start at 0xE0. The vtable (__vt__13PParticleFire) is
// stored by the constructor and destructor, so the class declares no virtuals.
class PParticleFire : public PParticleSystem {
public:
    PParticleFire();
    ~PParticleFire();
    void Enable(bool bEnable);
    void ModifyPosition(PMat4 *pMat);
    void SetPosition(float *pPos, float *pUnused);

    void *m_unkE0;              // 0x0E0 buffer released by the destructor
    void *m_unkE4;              // 0x0E4 buffer of 0x10-byte entries filled by ModifyPosition and SetPosition
    char _padE8[0x08];          // 0x0E8
    float m_unkF0[4];           // 0x0F0 offset vector written by PMat4::MulVector in ModifyPosition
    char _pad100[0x50];         // 0x100
    float m_unk150;             // 0x150 scales the y offset in ModifyPosition and SetPosition
    char _pad154[0x2C];         // 0x154
    float m_unk180[4];          // 0x180 position copied by SetPosition and ModifyPosition
    char _pad190[0x08];         // 0x190
    unsigned char m_unk198;     // 0x198 pending-fill flag, cleared by Enable and by the fill loops
};

#endif
