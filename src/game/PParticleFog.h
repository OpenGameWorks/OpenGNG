#ifndef PPARTICLEFOG_H
#define PPARTICLEFOG_H

#include "types.h"

class PFrustrum;
class PMat4;

// Fog volume creation data read by PParticleFog::Create. Offsets 0x00 to 0x0C
// give the centre, 0x10 to 0x18 the half extents, 0x20 a vector copied to
// m_unk10, 0x30 to 0x38 the scale values, 0x3C an index into a table of 64-bit
// values, 0x40 the particle count limit and 0x44 a random-placement flag.
struct tagParticleFogData {
    float unk0;
    float unk4;
    float unk8;
    char _pad0C[4];
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    u_long128 unk20;
    float unk30;
    float unk34;
    float unk38;
    int unk3C;
    unsigned int unk40;
    unsigned char unk44;
};

// Fog particle volume. Offsets 0x00 to 0x0C hold the particle output array,
// count and size values; 0x10 holds a vector passed to DrawFogParticles;
// 0x20 is the fog alpha written by FrustrumTest; 0x30 holds two 4x4 boxes
// read by FrustrumTest; 0x50 and 0x54 are the visibility flag and material.
class PParticleFog {
public:
    PParticleFog();
    ~PParticleFog();
    int Create(tagParticleFogData *pData, int nMode);
    void Render(PMat4 *pMat);
    void FrustrumTest(PFrustrum *pFrustum, float *pPos, float fNear, float fFar, PMat4 *pMat);

    float (*m_unk00)[4];        // 0x000 particle output array
    int m_unk04;                // 0x004 particle count
    float m_unk08;              // 0x008
    float m_unk0C;              // 0x00C
    float m_unk10[4];           // 0x010 vector passed to DrawFogParticles
    float m_unk20;              // 0x020 fog alpha
    char _pad24[0xC];           // 0x024
    float m_unk30[2][4];        // 0x030 bounding boxes used by FrustrumTest
    int m_unk50;                // 0x050 visibility or box intersect flag
    int m_unk54;                // 0x054 material index
    long long m_unk58;          // 0x058 material argument
};

#endif
