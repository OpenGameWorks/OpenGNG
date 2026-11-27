#ifndef PPARTICLELITEFIRE_H
#define PPARTICLELITEFIRE_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
struct tagParticleLiteFireParams;

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
    void AnimateRotatableParticles(float fDt);
    void Animate(float fDt);

    int Create(tagParticleLiteFireParams *pParams, float fX, float fY, float fZ);
    void Stop();
    char _pad0E0[0x40];         // 0x0E0 MulVector output written by ModifyPosition; vector slots to 0x120
    float m_unk120;             // 0x120
    float m_unk124;             // 0x124
    float m_unk128;             // 0x128
    char _pad12C[0x04];         // 0x12C
    unsigned int m_unk130;      // 0x130 particle count limit
    float m_unk134;             // 0x134
    float m_unk138;             // 0x138
    float m_unk13C;             // 0x13C
    float m_unk140;             // 0x140 scales the y offset in SetPosition
    float m_unk144;             // 0x144
    float m_unk148;             // 0x148
    float m_unk14C;             // 0x14C
    float m_unk150;             // 0x150
    unsigned char m_unk154;     // 0x154
    char _pad155[0x0B];         // 0x155
    void *m_unk160;             // 0x160 buffer filled by SetPosition, released by the destructor
    char _pad164[0x0C];         // 0x164
    float m_unk170[4];          // 0x170 position copied by SetPosition
    float *m_unk180;            // 0x180 per-particle float buffer, released by the destructor
    float m_unk184;             // 0x184
    int m_unk188;               // 0x188
    float m_unk18C;             // 0x18C set by FadeAndDie
    unsigned char m_unk190;     // 0x190 set by FadeAndDie, cleared by the constructor
    unsigned char m_unk191;     // 0x191 pending-fill flag, cleared by the constructor
};

#endif
