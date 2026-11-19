#ifndef PPARTICLESYSTEM_H
#define PPARTICLESYSTEM_H

#include "types.h"

class PMat4;

class PParticleSystem {
public:
    void UpdateLoopDelay(float fDelta);
    void Cleanup();
    void FadeAndDie(unsigned int nUnused);
    void ModifyPosition(PMat4 *pMat);

    // 0x000 vtable pointer (__vt__15PParticleSystem), stored by the destructor.
    char _pad000[8];
    void *m_unk08;              // 0x008 buffer released by Cleanup
    int m_unk0C;                // 0x00C
    int m_unk10;                // 0x010
    unsigned char m_unk14;      // 0x014
    unsigned char m_unk15;      // 0x015 active flag tested by FadeAndDie
    unsigned char m_unk16;      // 0x016
    unsigned char m_unk17;      // 0x017
    unsigned char m_unk18;      // 0x018
    char _pad019[1];
    unsigned char m_unk1A;      // 0x01A
    char _pad01B[0x25];
    u_long128 m_unk40;          // 0x040 copied from PMat4 rows by ModifyPosition
    u_long128 m_unk50;          // 0x050
    u_long128 m_unk60;          // 0x060
    u_long128 m_unk70;          // 0x070
    char _pad080[0x28];
    int m_unkA8;                // 0x0A8
    int m_unkAC;                // 0x0AC
    char _pad0B0[4];
    float m_unkB4;              // 0x0B4 loop delay countdown
};

#endif
