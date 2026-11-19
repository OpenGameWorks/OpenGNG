#ifndef CLOCKWORKSTINGER_H
#define CLOCKWORKSTINGER_H

#include "types.h"

class ClockworkStinger {
public:
    void SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2);
    void SetDefaultVars();
    void OnStopAttack();
    void OnTimerEvent(unsigned int arg0);

    char _pad000[4];
    unsigned int m_unk4;            // 0x004 timer argument for CreateTimer
    char _pad008[0x20 - 0x08];
    int m_unk20;                    // 0x020 state
    char _pad024[0x1B0 - 0x24];
    int m_unk1B0;                   // 0x1B0 nonzero blocks OnStopAttack
    char _pad1B4[0x1B8 - 0x1B4];
    float m_unk1B8;                 // 0x1B8 copied from arg0[0]
    float m_unk1BC;                 // 0x1BC copied from arg0[1]
    float m_unk1C0;                 // 0x1C0 copied from arg0[2]
    float m_unk1C4;                 // 0x1C4 arg1 in SetRiseAndAttack, 25.0f default
    float m_unk1C8;                 // 0x1C8 copied from arg0[0]
    float m_unk1CC;                 // 0x1CC copied from arg0[1]
    float m_unk1D0;                 // 0x1D0 copied from arg0[2]
    float m_unk1D4;                 // 0x1D4 arg2 in SetRiseAndAttack, 35.0f default
    int m_unk1D8;                   // 0x1D8
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;                   // 0x1E0
    int m_unk1E4;                   // 0x1E4
    int m_unk1E8;                   // 0x1E8
    int m_unk1EC;                   // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    int m_unk1F4;                   // 0x1F4
    int m_unk1F8;                   // 0x1F8 float bits 0.1f
    int m_unk1FC;                   // 0x1FC random 0xB4 or 0x6E
    char _pad200[0x240 - 0x200];
    int m_unk240;                   // 0x240 timer id slot
    char _pad244[0x250 - 0x244];
    unsigned int m_unk250;          // 0x250 damage fx handle, destroyed in dtor
    int m_unk254;                   // 0x254 timer id slot
    int m_unk258;                   // 0x258 timer id slot
};

#endif
