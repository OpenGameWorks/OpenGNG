#ifndef PPARTICLERAIN_H
#define PPARTICLERAIN_H

#include "types.h"
#include "PParticleSystem.h"
#include "PRainSplatter.h"

// Rain emitter. The PParticleSystem base ends at 0x0E0. Four quadrant entries
// 0x50 bytes apart start at 0x140 (start index at +0, particle count at +8);
// the particle buffer (0x20-byte elements) is at 0x248; the embedded splatter
// effect is at 0x270 and its sound reference at 0x2B0.
// One quadrant entry of the rain emitter; four entries start at +0x140 of the emitter.
struct PRainQuadrant {
    unsigned int m_unk00;       // start index, scaled by 0x20 bytes into the particle buffer
    char _pad04[4];
    unsigned int m_unk08;       // particle count
    char _pad0C[0x44];
};

class PParticleRain : public PParticleSystem {
public:
    PParticleRain();
    ~PParticleRain();

    void RenderQuadrant(unsigned int nIndex);
    void InitParticles();
    void SetNumRainParticles(unsigned int nNum);
    void Render();
    void SetLightningDensity(float fDensity);
    void SetDensity(float fDensity, bool bFlag);
    void SetCameraPosRot(float (*arg0)[4], float (*arg1)[4]);
    void FrustrumTest(PFrustrum *, float *, float, float);

    char m_unkE0[0x20];         // 0x0E0 zeroed by the constructor
    char m_unk100[0x140];       // 0x100..0x240 zeroed by the constructor; quadrant entries from 0x140
    unsigned int m_unk240;      // 0x240 quadrant index drawn first by Render
    unsigned int m_unk244;      // 0x244 quadrant index drawn second by Render
    void *m_unk248;             // 0x248 particle buffer, 0x20-byte elements
    char _pad24C[4];            // 0x24C
    float m_unk250;             // 0x250 density, current value; SetDensity
    float m_unk254;             // 0x254 density, target value; SetDensity
    float m_unk258;             // 0x258 density step per frame; SetDensity
    int m_unk25C;               // 0x25C
    int m_unk260;               // 0x260 lightning density; zero disables lightning
    int m_unk264;               // 0x264 lightning window low bound
    int m_unk268;               // 0x268 lightning window high bound
    int m_unk26C;               // 0x26C lightning level chosen in the window
    PRainSplatter m_unk270;     // 0x270 splatter effect, constructed and destroyed with the rain
    char _pad2A4[0xC];          // 0x2A4
    int m_unk2B0;               // 0x2B0 sound reference stopped by the destructor
    char _pad2B4[0xC];          // 0x2B4
};

#endif
