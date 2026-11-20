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
    struct tagLeaf;

    PParticleBlowingLeaves();

    int Create(float *pA, float *pB, float *pC, int nNum, float fRate, bool bFlag);
    void GenerateLeafMeshData();
    void ComputeWindAxes(float *pWind);
    void InitLeafRotations();
    void Render();
    void SetCameraPosRot(float (*arg0)[4], float (*arg1)[4]);
    void SpawnLeaf(tagLeaf *pLeaf);

    void *m_unkE0;
    int m_unkE4;
    PBlowingLeavesPad _padE8;
    // 20 leaves of 0x70 bytes each, from 0xF0 to 0x9B0.
    char m_unkF0[0x8C0];
    float m_unk9B0;
    char _pad9B4[0xC];
    float m_unk9C0[4];
    float m_unk9D0[4];
    float m_unk9E0[4];
    float m_unk9F0;
    float m_unk9F4;
    char _pad9F8[8];
    float m_unkA00[4];
    float m_unkA10[4];
    float m_unkA20[4];
    float m_unkA30[4];
    int m_unkA40;
    int m_unkA44;
    int m_unkA48;
    int m_unkA4C;
    void *m_unkA50;
    int m_unkA54;
    int m_unkA58;
    bool m_unkA5C;
};

#endif
