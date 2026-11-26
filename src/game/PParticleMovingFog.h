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
    char m_unk10[0x30];         // 0x010 copied from the creation params (0x50 bytes)
    float m_unk40[4];           // 0x040 scale vector, m_unk40[3] is a multiplier
    char m_unk50[0x10];         // 0x050
    PParticleFog m_unk60[6];    // 0x060
    char _pad2A0[0x80];         // 0x2A0
    PMat4 m_unk320[6];          // 0x320
    int m_unk4A0;               // 0x4A0 active fog count
};

#endif
