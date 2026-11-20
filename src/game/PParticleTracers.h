#ifndef PPARTICLETRACERS_H
#define PPARTICLETRACERS_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

// Particle tracer emitter. The PParticleSystem base occupies the first 0xE0
// bytes (u_long128 alignment rounds sizeof up from 0xD8); the members below
// start at 0xE0.
class PParticleTracers : public PParticleSystem {
public:
    PParticleTracers();
    void ModifyPosition(PMat4 *pMat);
    void SetPosition(float *pFrom, float *pTo);
    void Start();
    void ComputeTracerAxes();
    void InitTracers();

    float m_unkE0[4];           // 0x0E0 source vector read by ModifyPosition
    float m_unkF0[4];           // 0x0F0 vector, direction written by SetPosition
    char _pad100[0x24];         // 0x100
    float m_unk124;             // 0x124 squared length from InnerProduct
    char _pad128[0x28];         // 0x128
    int m_unk150;               // 0x150 random value set by Start
    char _pad154[0xC];          // 0x154
    float m_unk160[4];          // 0x160 position vector copied by SetPosition
    float m_unk170;             // 0x170
    void *m_unk174;             // 0x174 tracer array, freed by the destructor
    int m_unk178;               // 0x178 tracer count, tested by SetPosition
};

#endif
