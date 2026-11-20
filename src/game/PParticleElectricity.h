#ifndef PPARTICLEELECTRICITY_H
#define PPARTICLEELECTRICITY_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

// Electricity arc emitter. The PParticleSystem base occupies the first 0xE0
// bytes; the members below start at 0xE0.
class PParticleElectricity : public PParticleSystem {
public:
    struct tagElectricityBranch {
        void *m_unk00;          // 0x00 source vectors, 0x20-byte stride
        void *m_unk04;          // 0x04 particle buffer returned by AllocParticles
        char _pad08[0x2C];      // 0x08
        unsigned int m_unk34;   // 0x34 element count
    };

    PParticleElectricity();
    void SetPosition(float *pFrom, float *pTo);
    void Render();
    void SetupGlowParticles(tagElectricityBranch *pBranch);

    void *m_unkE0;              // 0x0E0 particle buffer (0x40-byte elements), freed by the destructor
    char _pad0E4[0xC];          // 0x0E4
    float m_unkF0[4];           // 0x0F0 source vector copied by SetPosition
    float m_unk100[4];          // 0x100 direction vector, normalised by SetPosition
    char _pad110[0x14];         // 0x110
    float m_unk124;             // 0x124 squared length from InnerProduct
    char _pad128[0x8];          // 0x128
    int m_unk130;               // 0x130 element count walked by Render
    float m_unk134;             // 0x134 width passed to SetupGlowParticles
};

#endif
