#ifndef PPROJECTILERIPPLES_H
#define PPROJECTILERIPPLES_H

#include "types.h"

// One ring slot, 0x60 bytes. The flag at +0x50 is zero while the slot is free.
struct PProjectileRing {
    float m_unk00[4];
    float m_unk10[4];
    float m_unk20[4];
    float m_unk30[4];
    float m_unk40;
    float m_unk44;
    float m_unk48;
    float m_unk4C;
    unsigned char m_unk50;
    char _pad51[0x0F];
};

struct tagProjectileRippesParams;

class PProjectileRipples {
public:
    PProjectileRipples();
    int FindFreeRing();
    void ComputeAxes(float *pSrc, float *pAxis0, float *pAxis1, float *pVec);
    int CreateRingTriStrip(int, float, float, int, int, float (*)[4], float (*)[4], float (*)[4]);
    void *InitRingMeshPacket(int &, int, bool);
    void CreateRing(float *arg0, float *arg1);
    void Create(tagProjectileRippesParams *pParams);
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
    float m_unk40[4][4];
    char _pad80[0x50];
    int m_unkD0;
    char _padD4[0x34];
    float m_unk108;
    int m_unk10C;
    unsigned char m_unk110;
    char _pad111[0x0F];
    PProjectileRing *m_unk120;
    int m_unk124;
    int m_unk128;
    void *m_unk12C;
    int m_unk130;
    void *m_unk134;
    int m_unk138;
};

#endif
