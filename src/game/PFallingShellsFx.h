#ifndef PFALLINGSHELLSFX_H
#define PFALLINGSHELLSFX_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

// Falling-shell effect. The PParticleSystem base occupies the first 0xE0
// bytes; the members below start at 0xE0. The shell array at 0x150 holds 0x40
// shells of 0x70 bytes each; the flag byte of shell N is at 0x1B2 + N * 0x70.
class PFallingShellsFx : public PParticleSystem {
public:
    PFallingShellsFx();
    int FindFreeShell();
    void ModifyPosition(PMat4 *pMat);
    void SetDirection(float *pDir);

    float m_unkE0[4];           // 0x0E0 source vector read by ModifyPosition
    float m_unkF0[4];           // 0x0F0 vector transformed by ModifyPosition
    float m_unk100[4];          // 0x100 direction result of ModifyPosition
    float m_unk110[4];          // 0x110 first direction vector set by SetDirection
    float m_unk120[4];          // 0x120 second direction vector set by SetDirection
    char _pad130[0x8];          // 0x130
    float m_unk138;             // 0x138 angle scale used by SetDirection
    char _pad13C[0x4];          // 0x13C
    float m_unk140;             // 0x140 value copied to m_unk144 by ModifyPosition
    float m_unk144;             // 0x144
    int m_unk148;               // 0x148
    char m_unk150[0x1C00];      // 0x150 shell array, 0x40 entries of 0x70 bytes
    int m_unk1D50;              // 0x1D50
};

#endif
