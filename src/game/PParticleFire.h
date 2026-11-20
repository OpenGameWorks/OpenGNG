#ifndef PPARTICLEFIRE_H
#define PPARTICLEFIRE_H

#include "types.h"
#include "PParticleSystem.h"

// Fire emitter. The PParticleSystem base occupies the first 0xE0 bytes;
// the members below start at 0xE0. The vtable (__vt__13PParticleFire) is
// stored by the constructor and destructor, so the class declares no virtuals.
struct tagParticleFireParams;

class PParticleFire : public PParticleSystem {
public:
    PParticleFire();
    ~PParticleFire();
    void Enable(bool bEnable);
    void ModifyPosition(PMat4 *pMat);
    void SetPosition(float *pPos, float *pUnused);
    int Create(tagParticleFireParams *pParams, float fX, float fY, float fZ);

    void *m_unkE0;              // 0x0E0 buffer released by the destructor
    void *m_unkE4;              // 0x0E4 buffer of 0x10-byte entries filled by ModifyPosition and SetPosition
    char _padE8[0x08];          // 0x0E8
    float m_unkF0[4];           // 0x0F0 offset vector written by PMat4::MulVector in ModifyPosition
    char _pad100[0x30];         // 0x100
    float m_unk130;             // 0x130 added to the x offset of SetPosition output in Create
    char _pad134[0x04];         // 0x134
    float m_unk138;             // 0x138 added to the z offset of SetPosition output in Create
    char _pad13C[0x08];         // 0x13C
    float m_unk144;             // 0x144 Create range input, reduced to m_unkA0 in its tail
    float m_unk148;             // 0x148 Create range input, reduced to m_unkA0 in its tail
    float m_unk14C;             // 0x14C Create range input, reduced to m_unkA0 in its tail
    float m_unk150;             // 0x150 scales the y offset in ModifyPosition and SetPosition
    float m_unk154;             // 0x154 subtracted from 1.0f when Create derives m_unk190
    char _pad158[0x08];         // 0x158
    float m_unk160;             // 0x160 gates the particle fill in Create
    char _pad164[0x10];         // 0x164
    float m_unk174;             // 0x174 decremented by Create
    char _pad178[0x08];         // 0x178
    float m_unk180[4];          // 0x180 position copied by SetPosition and ModifyPosition
    float m_unk190;             // 0x190 random-derived value written by Create
    int m_unk194;               // 0x194 integer value written by Create
    unsigned char m_unk198;     // 0x198 pending-fill flag, cleared by Enable and by the fill loops
};

#endif
