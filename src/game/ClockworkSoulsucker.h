#ifndef CLOCKWORKSOULSUCKER_H
#define CLOCKWORKSOULSUCKER_H

#include "types.h"

class ClockworkSoulsucker {
public:
    ClockworkSoulsucker();
    void AttachDamageEffect(class PMNode *pNode, unsigned int nId, float fA, float fB, float fC);
    int PlayerFacingUs();
    int DetermineIdleState();
    int DetermineNewState();
    void DeleteTimers();
    int GetSuckingSucker();
    int GetSuckingPos(float (&)[4]);
    void SetRiseAndAttack(float (*pVec)[4], float fA, float fB);
    void ResetAttackTimer();
    void ReleaseSemaphoreIfOwned();
    void DeleteEffects();
    void SetDefaultVars();
    void SetSpawnedFromEntity(float *pPos, float *pAlt, int nType);
    void FaceTarget(float fArg);
    void FaceHit();
    void AddSoulValue(int nValue);
    void OnWakeEvent();
    void OnTimerEvent(unsigned int nTimer);
    void *GetTarget();
    void SetupType();
    void ScaleSpikes(float fArg);
    void UpdateDamageFx();
    void AttachSmokeEffect();
    void AdjustPhysicsForEweedCheck();
    int InBlockableState();
    int InJuggleAirspace();
    int SoulsInRange();
    void SetDrainHit(unsigned int nArg);

    void *m_unk0;           // 0x000 vtable pointer
    unsigned int m_unk4;    // 0x004 owner id, compared with m_SuckerRef
    char _pad008[0x20 - 0x08];
    int m_unk20;            // 0x020
    char _pad024[0x38 - 0x24];
    class Physics *m_unk38; // 0x038 physics object, first argument of SetPhysicsType
    int m_unk3C;            // 0x03C target entity pointer; +0x80 used when non-null
    char _pad040[0xDC - 0x40];
    int m_unkDC;            // 0x0DC cleared by OnTimerEvent
    char _pad0E0[0x103 - 0xE0];
    unsigned char m_unk103; // 0x103 flag byte set by SetupType
    int m_unk104;           // 0x104 float bits set by SetupType
    int m_unk108;           // 0x108 float bits set by SetupType
    int m_unk10C;           // 0x10C bitfield, bits 24-26 cleared by SetDrainHit
    char _pad110[0x140 - 0x110];
    void *m_unk140;         // 0x140 current sequence, compared against sequence globals
    char _pad144[0x166 - 0x144];
    unsigned char m_unk166; // 0x166 set to 1 by the constructor
    char _pad167[0x190 - 0x167];
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
    char _pad230[0x234 - 0x230];
    unsigned int m_unk234;  // 0x234 target handle, resolved by GetTarget
    unsigned int m_unk238;  // 0x238 handle passed to DestroyDamageFx in the destructor
    float m_unk23C;         // 0x23C frame rate passed to PMNode::SetFrameRate
    unsigned int m_unk240;  // 0x240 timer handle, killed by DeleteTimers
    unsigned int m_unk244;  // 0x244 timer handle, killed by DeleteTimers
    float m_unk248;         // 0x248
    int m_unk24C;           // 0x24C initialised to 1.0f by the constructor
    int m_unk250;           // 0x250
    unsigned char m_unk254; // 0x254
    char _pad255[0x258 - 0x255];
    int m_unk258;           // 0x258 counter, capped at 15 by AddSoulValue
    int m_unk25C;           // 0x25C timer handle from TimerAPI::CreateTimer
    void *m_unk260;         // 0x260 resolved target pointer, set by GetTarget
    int m_unk264;           // 0x264
    int m_unk268;           // 0x268
    char _pad26C[0x2A0 - 0x26C];
    unsigned char m_unk2A0; // 0x2A0 set to 1 by SetDrainHit
    unsigned char m_unk2A1; // 0x2A1
    char _pad2A2[0x2A4 - 0x2A2];
    unsigned int m_unk2A4;  // 0x2A4 effect handle, 0 when none
    unsigned char m_unk2A8; // 0x2A8 byte, cleared by the constructor
    char _pad2A9[0x2AC - 0x2A9];
    int m_unk2AC;           // 0x2AC
    unsigned char m_unk2B0; // 0x2B0 flag, read by OnWakeEvent
    char _pad2B1[0x2B4 - 0x2B1];
    int m_unk2B4;           // 0x2B4
    unsigned char m_unk2B8; // 0x2B8 set to 1 by AddSoulValue once m_unk258 reaches 6
    char _pad2B9[0x2BC - 0x2B9];
    int m_unk2BC;           // 0x2BC
    int m_unk2C0;           // 0x2C0
    unsigned int m_unk2C4;  // 0x2C4 argument stored by SetDrainHit
    unsigned char m_unk2C8; // 0x2C8
    unsigned char m_unk2C9; // 0x2C9
};

#endif
