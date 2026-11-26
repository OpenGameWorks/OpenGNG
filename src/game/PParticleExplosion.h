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
    void Animate(float fDelta);

    void SetPosition(float *, float *);
    float m_unkE0[4];           // 0x0E0 position, copied from the parameter block
    float m_unkF0[4];           // 0x0F0 offset vector written by PMat4::MulVector in ModifyPosition
    float m_unk100[4];          // 0x100 vector used by Create
    float m_unk110[4];          // 0x110 random range minimum and maximum pairs, used by Animate
    float m_unk120[4];          // 0x120 random range maximum pairs, used by Animate
    float m_unk130[4];          // 0x130 lerp start for the particle offset
    float m_unk140[4];          // 0x140 lerp end for the particle offset
    float m_unk150[4];          // 0x150 lerp end for the second particle offset
    int m_unk160;               // 0x160 loop count before the emitter restarts
    float m_unk164;             // 0x164 colour ramp start
    float m_unk168;             // 0x168 colour ramp end
    float m_unk16C;             // 0x16C
    float m_unk170;             // 0x170 scale, replaced by 1 - itself in Create
    float m_unk174;             // 0x174
    float m_unk178;             // 0x178
    float m_unk17C;             // 0x17C
    float m_unk180;             // 0x180
    float m_unk184;             // 0x184
    float m_unk188;             // 0x188
    float m_unk18C;             // 0x18C
    float m_unk190;             // 0x190 minimum age fraction
    float m_unk194;             // 0x194
    float m_unk198;             // 0x198
    float m_unk19C;             // 0x19C
    float m_unk1A0;             // 0x1A0 lifetime
    float m_unk1A4;             // 0x1A4 age
    char _pad1A8[0x08];         // 0x1A8
    float m_unk1B0[4];          // 0x1B0 position copied into m_unk80..m_unk88
    float m_unk1C0[4];          // 0x1C0 copy of m_unkE0 made by Create and Start
    int m_unk1D0;               // 0x1D0
};

#endif
