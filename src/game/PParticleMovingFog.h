#ifndef PPARTICLEMOVINGFOG_H
#define PPARTICLEMOVINGFOG_H

#include "types.h"
#include "PParticleFog.h"
#include "PMat4.h"

class PFrustrum;
struct tagParticleMovingFogParams;

// Moving fog volume: a parameter block at 0x10, a vector at 0x40, six
// PParticleFog objects at 0x60 and six PMat4 transforms at 0x320.
class PParticleMovingFog {
public:
    PParticleMovingFog();
    virtual ~PParticleMovingFog();
    int Create(tagParticleMovingFogParams *pParams);
    void Render();
    void FrustrumTest(PFrustrum *pFrustum, float *pPos, float fNear, float fFar);
    void CreateFogObjects();
    void Animate(float fDelta);

    char _pad04[0xC];           // 0x004
    float m_unk10;              // 0x010 copied from the creation params (0x50 bytes)
    float m_unk14;              // 0x014
    float m_unk18;              // 0x018
    char _pad1C[0x4];           // 0x01C
    float m_unk20;              // 0x020
    float m_unk24;              // 0x024
    float m_unk28;              // 0x028
    char _pad2C[0x4];           // 0x02C
    float m_unk30[4];           // 0x030 velocity vector
    float m_unk40[4];           // 0x040 scale vector, m_unk40[3] is a multiplier
    float m_unk50;              // 0x050 velocity scale
    char _pad54[0xC];           // 0x054
    PParticleFog m_unk60[6];    // 0x060
    float m_unk2A0[6][4];       // 0x2A0 positions, w = 1.0f
    float m_unk300[6];          // 0x300 angles
    char _pad318[0x8];          // 0x318
    PMat4 m_unk320[6];          // 0x320
    int m_unk4A0;               // 0x4A0 active fog count
};

#endif
