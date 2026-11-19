#ifndef PPROJECTILERIPPLES_H
#define PPROJECTILERIPPLES_H

#include "types.h"

// One ring slot, 0x60 bytes. The flag at +0x50 is zero while the slot is free.
struct PProjectileRing {
    char _pad00[0x50];
    unsigned char m_unk50;
    char _pad51[0x0F];
};

class PProjectileRipples {
public:
    PProjectileRipples();
    int FindFreeRing();
    void FadeAndDie(unsigned int uArg);
    void Render();

    void *m_unk000;
    char _pad004[0x0C];
    int m_unk10;
    char _pad14[0x01];
    unsigned char m_unk15;
    char _pad16[0x02];
    unsigned char m_unk18;
    unsigned char m_unk19;
    char _pad1A[0x16];
    unsigned long long m_unk30;
    char _pad38[0xD4];
    int m_unk10C;
    char _pad110[0x10];
    PProjectileRing *m_unk120;
    int m_unk124;
    char _pad128[0x04];
    void *m_unk12C;
    int m_unk130;
    void *m_unk134;
    int m_unk138;
};

#endif
