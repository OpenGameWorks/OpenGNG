#ifndef CLOCKWORKPUNCHER_H
#define CLOCKWORKPUNCHER_H

#include "types.h"

class ClockworkPuncher {
public:
    int InBlockableState();
    void SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2);
    void SetEditableVars(char *arg0);
    void OnSleepEvent();
    void OnStopAttack();
    void DeleteEffects();
    void DeleteTimers();

    char _pad000[0x20];
    int m_unk20;             // 0x020 state
    char _pad024[0x163 - 0x24];
    unsigned char m_unk163;  // 0x163
    char _pad164[0x1B8 - 0x164];
    float m_unk1B8[3];       // 0x1B8, written by SetRiseAndAttack
    float m_unk1C4;          // 0x1C4
    float m_unk1C8[3];       // 0x1C8
    float m_unk1D4;          // 0x1D4
    // 0x1B0..0x1FB is also the 0x4C-byte block copied by SetEditableVars
    char _pad1D8[0x1FC - 0x1D8];
    int m_unk1FC;            // 0x1FC
    char _pad200[0x210 - 0x200];
    int m_unk210;            // 0x210
    char _pad214[0x272 - 0x214];
    unsigned char m_unk272;  // 0x272
    char _pad273[0x2B4 - 0x273];
    int m_unk2B4;            // 0x2B4
};

#endif
