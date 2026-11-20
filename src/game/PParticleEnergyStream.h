#ifndef PPARTICLEENERGYSTREAM_H
#define PPARTICLEENERGYSTREAM_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
struct tagVuParticle;
struct tagVuSplineKey;

// Energy stream emitter. The PParticleSystem base occupies the first 0xE0
// bytes; the members below start at 0xE0. The constructor zeroes 0xE0..0x170.
class PParticleEnergyStream : public PParticleSystem {
public:
    PParticleEnergyStream();
    void ComputeVuSplineKeys(struct tagVuParticle *pParticles, int nUnused, struct tagVuSplineKey *pKeys, int nCount);
    void SetPosition(float *pFrom, float *pTo);
    void Start();
    void Render();

    float m_unkE0[4];           // 0x0E0 source vector copied by SetPosition
    char _pad0F0[0x20];         // 0x0F0
    float m_unk110[4];          // 0x110 direction vector, normalised by SetPosition
    int m_unk120;               // 0x120 read by Render
    int m_unk124;               // 0x124 read by Render
    float m_unk128;             // 0x128 squared length from InnerProduct
    char _pad12C[4];            // 0x12C
    float m_unk130;             // 0x130 blend factor; ComputeVuSplineKeys uses (1 - m_unk130) / 2
    char _pad134[0x4C];         // 0x134
    float m_unk180[4];          // 0x180 target vector copied by SetPosition
    float m_unk190;             // 0x190 set to 1.0f by Start
    float m_unk194;             // 0x194 set to 1.0f by Start
    int m_unk198;               // 0x198
    int m_unk19C;               // 0x19C cleared by Start
};

#endif
