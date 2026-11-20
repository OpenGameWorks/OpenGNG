#ifndef PPARTICLEGAS_H
#define PPARTICLEGAS_H

#include "types.h"
#include "PParticleSystem.h"

struct tagParticleGasParams;

// Gas emitter. The PParticleSystem base occupies the first 0xE0 bytes.
// The vtable (__vt__12PParticleGas) is stored by the constructor and destructor,
// so the class declares no virtuals.
class PParticleGas : public PParticleSystem {
public:
    PParticleGas();
    ~PParticleGas();
    void Start();
    void Stop();
    void FadeOut(float fFade);
    void FadeAndDie(unsigned int nUnused);
    int Create(tagParticleGasParams *pParams, float fA, float fB, float fC);

    float m_unkE0;              // 0x0E0 parameter block copied from pParams by Create (0x70 bytes)
    float m_unkE4;              // 0x0E4
    float m_unkE8;              // 0x0E8
    char _padEC[0x04];          // 0x0EC
    float m_unkF0[4];           // 0x0F0 vector; m_unkF0[1] is 0x0F4, m_unkF0[2] is 0x0F8
    char _pad100[0x10];         // 0x100
    float m_unk110;             // 0x110
    float m_unk114;             // 0x114
    char _pad118[0x04];         // 0x118
    float m_unk11C;             // 0x11C
    float m_unk120;             // 0x120
    char _pad124[0x08];         // 0x124
    float m_unk12C;             // 0x12C copied to m_unk160 by Start
    float m_unk130;             // 0x130 clamped to at least 4.0f by Create
    float m_unk134;             // 0x134 clamped to at least 1.0f by Create
    float m_unk138;             // 0x138 fade value; FadeOut sets it, FadeAndDie and Stop test it
    char _pad13C[0x14];         // 0x13C
    void *m_unk150;             // 0x150 buffer released by the destructor
    int m_unk154;               // 0x154 cleared by the constructor; Create stores a float here
    int m_unk158;               // 0x158 set by Create
    char _pad15C[0x04];         // 0x15C
    int m_unk160;               // 0x160 cleared by the constructor
    float m_unk164;             // 0x164 fade value; FadeOut sets it, the constructor clears it
    unsigned char m_unk168;     // 0x168 set to 1 by FadeOut, cleared by the constructor
};

#endif
