#ifndef PMIDASSHIELDRINGS_H
#define PMIDASSHIELDRINGS_H

#include "types.h"

// Ring slots are 0x14 bytes each, starting at +0x15C. The flag byte at slot offset 0 is zero while the slot is free.
// The array is kept as raw bytes up to +0x1EC, where the gate and handle members begin.
class PMidasShieldRings {
public:
    PMidasShieldRings();
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
    char _pad38[0x124];
    unsigned char m_unk15C[0x90];
    int m_unk1EC;
    char _pad1F0[0x04];
    void *m_unk1F4;
    int m_unk1F8;
    void *m_unk1FC;
    int m_unk200;
};

#endif
