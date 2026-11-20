#ifndef PPARTICLEENERGYSTREAM_H
#define PPARTICLEENERGYSTREAM_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
struct tagVuParticle;
struct tagVuSplineKey;
struct tagParticleEnergyStreamParams;

// Energy stream emitter. The PParticleSystem base occupies the first 0xE0
// bytes; the members below start at 0xE0. The constructor zeroes 0xE0..0x170.
class PParticleEnergyStream : public PParticleSystem {
public:
    PParticleEnergyStream();
    void ComputeVuSplineKeys(struct tagVuParticle *pParticles, int nUnused, struct tagVuSplineKey *pKeys, int nCount);
    void SetPosition(float *pFrom, float *pTo);
    void Start();
    void Stop();
    void FadeAndDie(unsigned int nUnused);
    void ModifyPosition(PMat4 *pMat);
    void Render();
    void Animate(float fDelta);
    int Create(tagParticleEnergyStreamParams *pParams, float fA, float fB, float fC);

    float m_unkE0[4];           // 0x0E0 source vector copied by SetPosition
    float m_unkF0[4];           // 0x0F0
    float m_unk100[4];          // 0x100
    float m_unk110[4];          // 0x110 direction vector, normalised by SetPosition
    int m_unk120;               // 0x120 read by Render
    int m_unk124;               // 0x124 read by Render
    float m_unk128;             // 0x128 squared length from InnerProduct
    char _pad12C[4];            // 0x12C
    float m_unk130;             // 0x130 blend factor; ComputeVuSplineKeys uses (1 - m_unk130) / 2
    float m_unk134;             // 0x134
    float m_unk138;             // 0x138
    float m_unk13C;             // 0x13C
    float m_unk140;             // 0x140
    char _pad144[0x2C];         // 0x144
    int m_unk170;               // 0x170
    char _pad174[0xC];          // 0x174
    float m_unk180[4];          // 0x180 target vector copied by SetPosition
    float m_unk190;             // 0x190 set to 1.0f by Start
    float m_unk194;             // 0x194 set to 1.0f by Start
    float m_unk198;             // 0x198 step added to m_unk194 each Animate
    float m_unk19C;             // 0x19C cleared by Start; advanced by Animate
    unsigned char m_unk1A0;     // 0x1A0 set to 1 when the random direction was all -1.0f
};

#endif
