#ifndef PMIDASSHIELDRINGS_H
#define PMIDASSHIELDRINGS_H

#include "types.h"

// Ring slots are 0x14 bytes each, starting at +0x15C. The flag byte at slot offset 0 is zero while the slot is free.
// The array is kept as raw bytes up to +0x1EC, where the gate and handle members begin.
class PMidasShieldRings {
public:
    PMidasShieldRings();
    void Create(bool bFlag);
    void Create(float fA, float fB, float fC, float *pA, float *pB, float *pC, float fD, float fE, float fF, int nA, int nB, bool bA, bool bB);
    void *InitRingMeshPacket(int &nCount, int nSegs, bool bFlag);
    int CreateRingTriStrip(int nSegs, float fA, float fB, int iC, int iD, float (*pA)[4], float (*pB)[4], float (*pC)[4]);
    int FindFreeRing();
    int Emit();
    void FadeAndDie(unsigned int uArg);
    void Render();

    void *m_unk000;
    char _pad004[0x08];
    int m_unkC;
    int m_unk10;
    unsigned char m_unk14;
    unsigned char m_unk15;
    char _pad16[0x02];
    unsigned char m_unk18;
    unsigned char m_unk19;
    char _pad1A[0x16];
    unsigned long long m_unk30;
    char _pad38[0x08];
    float m_unk40[16];
    char _pad80[0x50];
    int m_unkD0;
    char _pad0D4[0x0C];
    float m_unkE0[4];
    float m_unkF0[4];
    float m_unk100[4];
    float m_unk110;
    float m_unk114;
    int m_unk118;
    int m_unk11C;
    float m_unk120;
    float m_unk124;
    int m_unk128;
    int m_unk12C;
    float m_unk130;
    float m_unk134;
    int m_unk138;
    int m_unk13C;
    float m_unk140;
    int m_unk144;
    int m_unk148;
    char _pad14C[0x10];
    unsigned char m_unk15C[0x90];
    int m_unk1EC;
    int m_unk1F0;
    void *m_unk1F4;
    int m_unk1F8;
    void *m_unk1FC;
    int m_unk200;
    unsigned char m_unk204;
};

#endif
