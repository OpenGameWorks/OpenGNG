#ifndef PPARTICLESPARKS_H
#define PPARTICLESPARKS_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
struct tagVuFxLine;

// Parameter block copied into the emitter (0x60 bytes). Create reads m_unk38.
struct tagParticleSparksParams {
    char _pad00[0x38];
    unsigned int m_unk38;
    char _pad3C[0x24];
};

// Spark emitter. The PParticleSystem base occupies the first 0xE0 bytes.
// Methods are not declared virtual here: the base has no vptr declared, so a
// virtual keyword would add one and shift the layout.
class PParticleSparks : public PParticleSystem {
public:
    PParticleSparks();
    ~PParticleSparks();
    void Animate(float fDelta);
    void Render();
    void ModifyPosition(PMat4 *pMat);
    void Start();
    int Create(tagParticleSparksParams *pParams, float fA, float fB, float fC);
    void InitSparkDirections();

    u_long128 m_unkE0;          // 0x0E0 spark vector
    float m_unkF0;              // 0x0F0 base direction x in InitSparkDirections
    float m_unkF4;              // 0x0F4 base direction y in InitSparkDirections
    float m_unkF8;              // 0x0F8 base direction z in InitSparkDirections
    char _padFC[0x14];
    float m_unk110;             // 0x110 lower bound of the random spark scale in Animate
    float m_unk114;             // 0x114 upper bound of the random spark scale in Animate
    int m_unk118;               // 0x118 loop count limit in Animate
    float m_unk11C;             // 0x11C spread factor in InitSparkDirections
    float m_unk120;             // 0x120 spark speed in Animate
    float m_unk124;             // 0x124 input to the loop length in Create
    float m_unk128;             // 0x128 extent value copied to 0x90..0x98 by Create
    float m_unk12C;             // 0x12C offset subtracted from y in InitSparkDirections
    float m_unk130;             // 0x130 mix factor in Animate
    char _pad134[0xC];
    void *m_unk140;             // 0x140 spark buffer, released by the destructor
    float m_unk144;             // 0x144
    float m_unk148;             // 0x148 elapsed time, reset when the loop counter wraps
    char _pad14C[4];
    u_long128 m_unk150;         // 0x150
    u_long128 m_unk160;         // 0x160
    int m_unk170;               // 0x170 spark count set by Start
};

#endif
