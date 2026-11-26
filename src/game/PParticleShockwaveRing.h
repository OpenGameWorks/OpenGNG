#ifndef PPARTICLESHOCKWAVERING_H
#define PPARTICLESHOCKWAVERING_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
class PFrustrum;
struct tagParticleShockwaveRingParams;

// Expanding shockwave ring emitter. The PParticleSystem base occupies the
// first 0xE0 bytes; the members below start at 0xE0. The class declares no
// virtuals: a vptr in the derived class shifts every member by 0x10, so the
// constructor and destructor store the vtable pointer by hand.
class PParticleShockwaveRing : public PParticleSystem {
public:
    PParticleShockwaveRing();

    void Animate(float fDelta);
    void Render();
    void FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar);
    void Start();

    int Create(tagParticleShockwaveRingParams *pParams, float fA, float fB, float fC);

    float m_unkE0[4][4];        // 0x0E0 rotation matrix (sceVu0UnitMatrix target)
    u_long128 m_unk120;         // 0x120 quadword written by Animate
    float m_unk130;             // 0x130 scaled cos of the ring angle
    float m_unk134;             // 0x134 scaled sin of the ring angle
    char _pad138[8];
    u_long128 m_unk140;         // 0x140 copied from the parameter block; w = 1.0f
    u_long128 m_unk150;         // 0x150 interpolation vector
    u_long128 m_unk160;         // 0x160 interpolation vector
    u_long128 m_unk170;         // 0x170 interpolation vector
    u_long128 m_unk180;         // 0x180 interpolation vector
    u_long128 m_unk190;         // 0x190 interpolation vector
    u_long128 m_unk1A0;         // 0x1A0 interpolation vector
    float m_unk1B0[4];          // 0x1B0 random angles, rotation input to FastMath_RotateMatrix
    float m_unk1C0;             // 0x1C0 copy of parameter block entry 0x80 (memcpy of 0xA0 bytes into m_unk140)
    float m_unk1C4;             // 0x1C4 parameter block entry, cos amplitude
    float m_unk1C8;             // 0x1C8 parameter block entry, sin amplitude
    char _pad1CC[0x14];         // 0x1CC parameter block tail
    float m_unk1E0;             // 0x1E0 progress along the ring, 0.0f..1.0f
    float m_unk1E4;             // 0x1E4 progress step, 1.0f / m_unk1C0
    float m_unk1E8;             // 0x1E8 angle accumulator, wrapped at 360.0f
};

#endif
