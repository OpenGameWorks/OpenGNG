#ifndef PPARTICLEGAS_H
#define PPARTICLEGAS_H

#include "types.h"
#include "PParticleSystem.h"

// Gas emitter. The PParticleSystem base occupies the first 0xE0 bytes.
// The vtable (__vt__12PParticleGas) is stored by the constructor and destructor,
// so the class declares no virtuals.
class PParticleGas : public PParticleSystem {
public:
    PParticleGas();
    ~PParticleGas();
    void Stop();
    void FadeOut(float fFade);
    void FadeAndDie(unsigned int nUnused);

    char _padE0[0x58];          // 0x0E0 zeroed by the constructor together with 0x138..0x14F
    float m_unk138;             // 0x138 fade value; FadeOut sets it, FadeAndDie and Stop test it
    char _pad13C[0x14];         // 0x13C
    void *m_unk150;             // 0x150 buffer released by the destructor
    int m_unk154;               // 0x154 cleared by the constructor
    char _pad158[0x08];         // 0x158
    int m_unk160;               // 0x160 cleared by the constructor
    float m_unk164;             // 0x164 fade value; FadeOut sets it, the constructor clears it
    unsigned char m_unk168;     // 0x168 set to 1 by FadeOut, cleared by the constructor
};

#endif
