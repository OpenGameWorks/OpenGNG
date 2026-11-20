#ifndef PPARTICLETEXTURE_H
#define PPARTICLETEXTURE_H

#include "types.h"

class PParticleSystem;

// 4x4 float matrix whose empty inline destructor is folded away by the compiler.
class PParticleMatrix {
public:
    ~PParticleMatrix() {}
    float m_unk00[4][4];
};

// Embedded by value in PFogTexture, PGasTexture and PFireTexture at offset 0x10.
class PParticleTexture {
public:
    PParticleTexture();
    ~PParticleTexture();
    void Reset();
    void InitGsRegs(int nIndex, bool bFlag);
    int Init(int nIndex, PParticleSystem *pSystemA, PParticleSystem *pSystemB, bool bFlag);
    void Update(float fStep);

    int m_unk0;                 // 0x00
    char _pad4[0xC];            // 0x04
    char m_unk10[0x50];         // 0x10 cleared by Reset
    char _pad60[0x460];         // 0x60 GS clear packet and related state
    int m_unk4C0;               // 0x4C0
    void *m_unk4C4;             // 0x4C4
    char _pad4C8[0x8];          // 0x4C8
    PParticleMatrix m_unk4D0;   // 0x4D0 matrix
    PParticleMatrix m_unk510;   // 0x510 matrix
    PParticleSystem *m_unk550;  // 0x550
    PParticleSystem *m_unk554;  // 0x554
    bool m_unk558;              // 0x558
    char _pad559[0x7];          // 0x559
};

#endif
