#ifndef PPARTICLETRACERS_H
#define PPARTICLETRACERS_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

// Creation parameters block copied into the emitter at 0xE0 by Create.
struct tagParticleTracersParams {
    char _pad00[0x40];
    unsigned int m_unk40;       // 0x040 base particle count passed to PParticleSystem::Create
    char _pad44[0x2C];          // 0x044
};

// Particle tracer emitter. The PParticleSystem base occupies the first 0xE0
// bytes (u_long128 alignment rounds sizeof up from 0xD8); the members below
// start at 0xE0.
class PParticleTracers : public PParticleSystem {
public:
    PParticleTracers();
    int Create(tagParticleTracersParams *pParams, float fA, float fB, float fC);
    void ModifyPosition(PMat4 *pMat);
    void SetPosition(float *pFrom, float *pTo);
    void Start();
    void Render();
    void ComputeTracerAxes();
    void InitTracers();

    float m_unkE0[4];           // 0x0E0 source vector read by ModifyPosition
    float m_unkF0[4];           // 0x0F0 vector, direction written by SetPosition
    float m_unk100[4];          // 0x100 vector read by InitTracers
    float m_unk110[4];          // 0x110 vector scaled into m_unkC0 by Create
    int m_unk120;               // 0x120 tracer count, loop bound of InitTracers
    float m_unk124;             // 0x124 squared length from InnerProduct
    float m_unk128;             // 0x128 fraction read by Create
    char _pad12C[0x10];         // 0x12C
    unsigned int m_unk13C;      // 0x13C resource id read by Create
    char _pad140[0x10];         // 0x140
    int m_unk150;               // 0x150 random value set by Start
    char _pad154[0xC];          // 0x154
    float m_unk160[4];          // 0x160 position vector copied by SetPosition
    float m_unk170;             // 0x170
    void *m_unk174;             // 0x174 tracer array, freed by the destructor
    int m_unk178;               // 0x178 tracer count, tested by SetPosition
    char _pad17C[4];            // 0x17C
    float m_unk180[4];          // 0x180 tracer axis vector, written by ComputeTracerAxes
    float m_unk190[4];          // 0x190 outer product of m_unk180 and m_unk1A0
    float m_unk1A0[4];          // 0x1A0 vector copied from m_unkF0 and scaled by -1
};

#endif
