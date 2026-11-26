#ifndef PRAINSPLATTER_H
#define PRAINSPLATTER_H

#include "types.h"

// Rain splatter effect. Offsets below 0x30 follow the Create, Animate and
// Splatter bodies; m_unk30 is the material index passed to SetMaterial.
class PRainSplatter {
public:
    void Render();
    void Animate(float fDelta);
    void Splatter(float *pPos);
    int Create(int nCount, float *pPos);
    ~PRainSplatter();

    PRainSplatter();
    void *m_unk00;              // 0x000 particle output array from AllocParticles
    int m_unk04;                // 0x004 element count
    void *m_unk08;              // 0x008 element array, 0x10 bytes per element
    char _pad0C[4];             // 0x00C
    float m_unk10[4];           // 0x010 vector copied by Create
    float m_unk20[3];           // 0x020 vector copied by Create (w lands on 0x02C)
    int m_unk2C;                // 0x02C
    int m_unk30;                // 0x030 material index
};

#endif
