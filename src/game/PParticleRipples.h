#ifndef PPARTICLERIPPLES_H
#define PPARTICLERIPPLES_H

#include "types.h"

// Particle ripple emitter. The first 0x860 bytes hold the PParticleSystem base
// and a 30-slot array of 0x40-byte ripples; the flag at +0x11C of each slot is
// zero while the slot is free.
class PParticleRipples {
public:
    PParticleRipples();

    int FindFreeRipple();
    void FadeAndDie(unsigned int uArg);
    void AutoEmit(float fArg0, float *pArr, float fArg2, float fArg3, float fArg4, float fArg5);
    void Create(float *pArr, float fArg1, float fArg2, float fArg3);
    void Create(float *pArr0, float *pArr1, float fArg2, float fArg3, float fArg4,
                float fArg5, float fArg6, float fArg7);

    void *m_unk000;
    char _pad004[0x14];
    unsigned char m_unk018;
    char _pad019[0x847];
    int m_unk860;
    char _pad864[4];
    float m_unk868;
    int m_unk86C;
    unsigned char m_unk870[0x10];
    float m_unk880;
    float m_unk884;
    float m_unk888;
    float m_unk88C;
    int m_unk890;
    int m_unk894;
    int m_unk898;
    int m_unk89C;
    int m_unk8A0;
    int m_unk8A4;
    int m_unk8A8;
    char _pad8AC[4];
    unsigned char m_unk8B0;
    unsigned char m_unk8B1;
};

#endif
