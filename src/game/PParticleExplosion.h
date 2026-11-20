#ifndef PPARTICLEEXPLOSION_H
#define PPARTICLEEXPLOSION_H

#include "types.h"
#include "PParticleSystem.h"

// Parameter block copied into the emitter by Create (0xC0 bytes).
struct tagParticleExplosionParams {
    char _pad000[0x80];         // 0x000
    unsigned int m_unk80;       // 0x080 passed to PParticleSystem::Create
    char _pad084[0x3C];         // 0x084
};

// Explosion emitter. The PParticleSystem base occupies the first 0xE0 bytes;
// the members below start at 0xE0. The vtable (__vt__18PParticleExplosion) is
// stored by the constructor and destructor, so the class declares no virtuals.
class PParticleExplosion : public PParticleSystem {
public:
    int Create(tagParticleExplosionParams *pParams, float fA, float fB, float fC);
    void ModifyPosition(PMat4 *pMat);
    void Start();

    float m_unkE0[4];           // 0x0E0 position, copied from the parameter block
    float m_unkF0[4];           // 0x0F0 offset vector written by PMat4::MulVector in ModifyPosition
    float m_unk100[4];          // 0x100 vector used by Create
    char _pad110[0x5C];         // 0x110
    float m_unk16C;             // 0x16C
    float m_unk170;             // 0x170 scale, replaced by 1 - itself in Create
    char _pad174[0x20];         // 0x174
    float m_unk194;             // 0x194
    char _pad198[0x08];         // 0x198
    float m_unk1A0;             // 0x1A0
    int m_unk1A4;               // 0x1A4
    char _pad1A8[0x08];         // 0x1A8
    float m_unk1B0[4];          // 0x1B0 position copied into m_unk80..m_unk88
    float m_unk1C0[4];          // 0x1C0 copy of m_unkE0 made by Create and Start
    int m_unk1D0;               // 0x1D0
};

#endif
