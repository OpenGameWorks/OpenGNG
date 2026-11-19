#ifndef CLOCKWORKSOULSUCKER_H
#define CLOCKWORKSOULSUCKER_H

#include "types.h"

class ClockworkSoulsucker {
public:
    void SetRiseAndAttack(float (*pVec)[4], float fA, float fB);
    void ResetAttackTimer();
    void ReleaseSemaphoreIfOwned();
    void DeleteEffects();
    void SetDefaultVars();

    char _pad000[0x4];
    unsigned int m_unk4;    // 0x004 owner id, compared with m_SuckerRef
    char _pad008[0x1B4 - 0x8];
    int m_unk1B4;           // 0x1B4
    float m_unk1B8;         // 0x1B8
    float m_unk1BC;         // 0x1BC
    float m_unk1C0;         // 0x1C0
    float m_unk1C4;         // 0x1C4
    float m_unk1C8;         // 0x1C8
    float m_unk1CC;         // 0x1CC
    float m_unk1D0;         // 0x1D0
    float m_unk1D4;         // 0x1D4
    int m_unk1D8;           // 0x1D8
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;           // 0x1E0
    int m_unk1E4;           // 0x1E4
    int m_unk1E8;           // 0x1E8
    int m_unk1EC;           // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    int m_unk1F4;           // 0x1F4
    char _pad1F8[0x25C - 0x1F8];
    int m_unk25C;           // 0x25C timer handle from TimerAPI::CreateTimer
    char _pad260[0x2A4 - 0x260];
    unsigned int m_unk2A4;  // 0x2A4 effect handle, 0 when none
};

#endif
