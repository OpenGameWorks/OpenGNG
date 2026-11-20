#ifndef PPARTICLEBLOWINGLEAVES_H
#define PPARTICLEBLOWINGLEAVES_H

#include "types.h"
#include "PParticleSystem.h"

// Blowing-leaves emitter. The PParticleSystem base occupies the first 0xE0
// bytes; the members below start at 0xE0.
// Padding subobject whose type declares an (empty, inline) destructor.
struct PBlowingLeavesPad {
    char _pad[8];
    ~PBlowingLeavesPad() {}
};

class PParticleBlowingLeaves : public PParticleSystem {
public:
    PParticleBlowingLeaves();

    void GenerateLeafMeshData();
    void ComputeWindAxes(float *pWind);
    void InitLeafRotations();

    void *m_unkE0;
    int m_unkE4;
    PBlowingLeavesPad _padE8;
    // 20 leaves of 0x70 bytes each, from 0xF0 to 0x9B0.
    char m_unkF0[0x8C0];
    int m_unk9B0;
    char _pad9B4[0x5C];
    float m_unkA10[4];
    float m_unkA20[4];
    float m_unkA30[4];
    char _padA40[0x10];
    void *m_unkA50;
    int m_unkA54;
};

#endif
