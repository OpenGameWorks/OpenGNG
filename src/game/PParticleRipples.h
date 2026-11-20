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
    void Render();
    void AutoEmit(float fArg0, float *pArr, float fArg2, float fArg3, float fArg4, float fArg5);
    void Create(float *pArr, float fArg1, float fArg2, float fArg3);
    int Create(float *pArr0, float *pArr1, float fArg2, float fArg3, float fArg4,
                float fArg5, float fArg6, float fArg7);
    void Init(int nArg0, bool bArg1, bool bArg2);
    void *InitRingMeshPacket(int &nOut, int nArg1, bool bArg2);
    int CreateRingTriStrip(int nArg0, float fArg1, float fArg2, int nArg3, int nArg4,
                           float (*pTop)[4], float (*pMid)[4], float (*pBot)[4]);

    void *m_unk000;
    char _pad004[8];
    int m_unk00C;
    int m_unk010;
    unsigned char m_unk014;
    unsigned char m_unk015;
    char _pad016[2];
    unsigned char m_unk018;
    char _pad019[0x27];
    char m_unk040[0xA0];
    char m_unk0E0[0x780];
    int m_unk860;
    int m_unk864;
    float m_unk868;
    int m_unk86C;
    unsigned char m_unk870[0x10];
    float m_unk880;
    float m_unk884;
    float m_unk888;
    float m_unk88C;
    void *m_unk890;
    int m_unk894;
    float m_unk898;
    float m_unk89C;
    float m_unk8A0;
    float m_unk8A4;
    int m_unk8A8;
    int m_unk8AC;
    unsigned char m_unk8B0;
    unsigned char m_unk8B1;
};

#endif
