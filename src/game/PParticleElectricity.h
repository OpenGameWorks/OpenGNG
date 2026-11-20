#ifndef PPARTICLEELECTRICITY_H
#define PPARTICLEELECTRICITY_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

struct tagParticleElectricityParams {
    char _pad00[0x70];          // 0x00 copied to m_unkF0 by Create (0x70 bytes)
};

// Electricity arc emitter. The PParticleSystem base occupies the first 0xE0
// bytes; the members below start at 0xE0.
class PParticleElectricity : public PParticleSystem {
public:
    struct tagElectricityBranch {
        void *m_unk00;          // 0x00 source vectors, 0x20-byte stride
        void *m_unk04;          // 0x04 particle buffer returned by AllocParticles
        char _pad08[0x8];       // 0x08
        float m_unk10;          // 0x10 start point x
        float m_unk14;          // 0x14 start point y
        float m_unk18;          // 0x18 start point z
        char _pad1C[0x4];       // 0x1C
        float m_unk20;          // 0x20 direction x
        float m_unk24;          // 0x24 direction y
        float m_unk28;          // 0x28 direction z
        char _pad2C[0x4];       // 0x2C
        float m_unk30;          // 0x30 branch length
        unsigned int m_unk34;   // 0x34 element count
    };

    PParticleElectricity();
    int Create(tagParticleElectricityParams *pParams, float fA, float fB, float fC);
    void SetPosition(float *pFrom, float *pTo);
    void Render();
    void CreateBranch(tagElectricityBranch *pBranch);
    void SetupGlowParticles(tagElectricityBranch *pBranch);

    void *m_unkE0;              // 0x0E0 particle buffer (0x40-byte elements), freed by the destructor
    char _pad0E4[0xC];          // 0x0E4
    float m_unkF0[4];           // 0x0F0 source vector copied by SetPosition
    float m_unk100[4];          // 0x100 direction vector, normalised by SetPosition
    float m_unk110;             // 0x110 colour channel, divided by 255 into m_unkC0 by Create
    float m_unk114;             // 0x114 colour channel, divided by 255 into m_unkC4 by Create
    float m_unk118;             // 0x118 colour channel, divided by 255 into m_unkC8 by Create
    float m_unk11C;             // 0x11C divided by 128 into m_unkCC by Create
    int m_unk120;               // 0x120 copied to the base m_unk04 by Create
    float m_unk124;             // 0x124 squared length from InnerProduct
    float m_unk128;             // 0x128 scaled by 0.3f into m_unk188 by Create
    char _pad12C[0x4];          // 0x12C
    int m_unk130;               // 0x130 element count walked by Render
    float m_unk134;             // 0x134 width passed to SetupGlowParticles
    char _pad138[0x4C];         // 0x138
    int m_unk184;               // 0x184 0x89A9 set by Create
    float m_unk188;             // 0x188 0.3f * m_unk128, set by Create
    int m_unk18C;               // 0x18C set to 2 by Create
};

#endif
