#ifndef CLOCKWORKSOULSUCKER_H
#define CLOCKWORKSOULSUCKER_H

#include "types.h"

class ClockworkSoulsucker {
public:
    void AttachDamageEffect(class PMNode *pNode, unsigned int nId, float fA, float fB, float fC);
    int PlayerFacingUs();
    int DetermineIdleState();
    void DeleteTimers();
    int GetSuckingSucker();
    void SetRiseAndAttack(float (*pVec)[4], float fA, float fB);
    void ResetAttackTimer();
    void ReleaseSemaphoreIfOwned();
    void DeleteEffects();
    void SetDefaultVars();
    void SetSpawnedFromEntity(float *pPos, float *pAlt, int nType);
    void FaceTarget(float fArg);
    void AddSoulValue(int nValue);
    void OnWakeEvent();
    void *GetTarget();
    void SetupType();
    void UpdateDamageFx();
    void AttachSmokeEffect();
    void AdjustPhysicsForEweedCheck();

    char _pad000[0x4];
    unsigned int m_unk4;    // 0x004 owner id, compared with m_SuckerRef
    char _pad008[0x3C - 0x8];
    int m_unk3C;            // 0x03C target entity pointer; +0x80 used when non-null
    char _pad040[0x190 - 0x40];
    char _pad190[0x1B0 - 0x190]; // 0x190 embedded EntityBaseClass, address taken by PlayerFacingUs
    int m_unk1B0;           // 0x1B0 read by DetermineIdleState
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
    char _pad1F8[0x22C - 0x1F8];
    int m_unk22C;           // 0x22C soul value, capped at 800 by AddSoulValue
    char _pad230[0x238 - 0x230];
    unsigned int m_unk238;  // 0x238 handle passed to DestroyDamageFx in the destructor
    char _pad23C[0x240 - 0x23C];
    unsigned int m_unk240;  // 0x240 timer handle, killed by DeleteTimers
    unsigned int m_unk244;  // 0x244 timer handle, killed by DeleteTimers
    char _pad248[0x258 - 0x248];
    int m_unk258;           // 0x258 counter, capped at 15 by AddSoulValue
    int m_unk25C;           // 0x25C timer handle from TimerAPI::CreateTimer
    char _pad260[0x2A4 - 0x260];
    unsigned int m_unk2A4;  // 0x2A4 effect handle, 0 when none
    char _pad2A8[0x2B0 - 0x2A8];
    unsigned char m_unk2B0; // 0x2B0 flag, read by OnWakeEvent
    char _pad2B1[0x2B8 - 0x2B1];
    unsigned char m_unk2B8; // 0x2B8 set to 1 by AddSoulValue once m_unk258 reaches 6
};

#endif
