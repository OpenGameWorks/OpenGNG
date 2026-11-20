#ifndef PPARTICLESPLINETRAIL_H
#define PPARTICLESPLINETRAIL_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

// Spline trail emitter. The PParticleSystem base occupies the first 0xE0 bytes;
// the members below start at 0xE0.
class PParticleSplineTrail : public PParticleSystem {
public:
    void Start();
    void SetPosition(float *pFrom, float *pTo);
    void ModifyPosition(PMat4 *pMat);

    float m_unkE0[4];           // 0x0E0 offset vector passed to PMat4::MulVector by ModifyPosition
    char _pad0F0[0x60];         // 0x0F0
    float m_unk150[4];          // 0x150 source vector copied by SetPosition and ModifyPosition
    float m_unk160;             // 0x160 set to 1.0f by Start
};

#endif
