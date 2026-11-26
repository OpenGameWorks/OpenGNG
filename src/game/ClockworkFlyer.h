#ifndef CLOCKWORKFLYER_H
#define CLOCKWORKFLYER_H

#include "types.h"

class EntityBaseClass;

struct ClockworkFlyerPad190 {
    char b[0x10];
    ~ClockworkFlyerPad190() {}
    operator char *() { return b; }
};

class ClockworkFlyer {
public:
    void OnAttackEvent(EntityBaseClass *, int);
    void OnSleepEvent();
    void SetEditableVars(char *);
    int GetWokenVarPos();
    int NeedsToBeWoken();
    int GetArenaWaveID();
    int GetTallyType();
    const char * GetClassName();
    void OutputDebug();
    void OnStopAttack();
    int GetHealth();
    ClockworkFlyer();
    void SetSpawnedFromEntity(float *pPos, float *pAlt, int nType);
    int GetNextPosition(float (&rOut)[4]);
    int InCameraView();
    void FaceTarget(float fAngle);
    ClockworkFlyer *GetTarget();
    int DetermineStateByDistance();
    int FlyerPitchChange();
    int FlyerFlyTo(float (*pDest)[4], float fDist, float fSpeed);
    void EscapeIfApproachStalled();
    void EscapeIfStalled();
    void InitStallData();
    void SetDefaultVars();
    void OnTimerEvent(unsigned int nId);
    int OnHitEvent(EntityBaseClass *pOther, int nDmg, unsigned int a, unsigned int b);
    void SetupDartDest();
    int DoDartTasks();
    void PitchLevelOut();
    void Execute();
    bool IsArenaApparition();
    void SetInnocentInstanceID(unsigned int);

    char _pad000[0x4];                  // 0x000 vtable
    unsigned int m_unk4;                // 0x004 owner id passed to CreateTimer
    char _pad008[0x20 - 0x8];
    int m_unk20;                        // 0x020 state selector switched on by Execute
    char _pad024[0x38 - 0x24];
    float *m_unk38;                     // 0x038 16-byte output pointer
    char *m_unk3C;                     // 0x03C target entity pointer; +0x80 used when non-null
    char _pad040[0xD4 - 0x40];
    void *m_unkD4;                      // 0x0D4 shadow object, created by Execute
    char _padD8[0xE9 - 0xD8];
    unsigned char m_unkE9;              // 0x0E9 nonzero: first-entry sequence and sound pass
    char _padEA[0xF4 - 0xEA];
    int m_unkF4;                        // 0x0F4 nonzero selects the damage-absorb path in OnHitEvent
    char _pad0F8[0x103 - 0xF8];
    unsigned char m_unk103;             // 0x103
    int m_unk104;                       // 0x104 float bits 3.0f (Execute case -1/9)
    int m_unk108;                       // 0x108 float bits 3.5f (Execute case -1/9)
    int m_unk10C;                       // 0x10C flag word, bits set by Execute case -1/9
    char _pad110[0x140 - 0x110];
    void *m_unk140;                     // 0x140 sequence pointer, cases 13/23, 14/24, 17/27
    char _pad144[0x15C - 0x144];
    short m_unk15C;                     // 0x15C
    short m_unk15E;                     // 0x15E
    int m_unk160;                       // 0x160 countdown; zero lets the state change
    char _pad164[0x18C - 0x164];
    int m_unk18C;                       // 0x18C
    ClockworkFlyerPad190 _pad190;       // 0x190 16-byte block, address taken
    float m_unk1A0;                     // 0x1A0 position read by FlyerPitchChange
    char _pad1A4[0x1B0 - 0x1A4];
    int m_unk1B0;                       // 0x1B0 type argument of SetSpawnedFromEntity
    char _pad1B4[0x1B8 - 0x1B4];
    int m_unk1B8;                       // 0x1B8 nonzero skips the Physics collision-flag clear

    float m_unk1BC;                     // 0x1BC
    float m_unk1C0;                     // 0x1C0
    float m_unk1C4;                     // 0x1C4
    int m_unk1C8;                       // 0x1C8 float bits 25.0f (SetDefaultVars), 75.0f (SetSpawnedFromEntity)
    float m_unk1CC[3];                  // 0x1CC position copied by SetSpawnedFromEntity
    int m_unk1D8;                       // 0x1D8 float bits 35.0f (SetDefaultVars), 150.0f (SetSpawnedFromEntity)
    int m_unk1DC;                       // 0x1DC
    char _pad1E0[0x1E4 - 0x1E0];
    int m_unk1E4;                       // 0x1E4
    float m_unk1E8;                     // 0x1E8
    float m_unk1EC;                     // 0x1EC
    float m_unk1F0;                     // 0x1F0
    char _pad1F4[0x1F8 - 0x1F4];
    int m_unk1F8;                       // 0x1F8
    int m_unk1FC;                       // 0x1FC float bits 0.1f
    int m_unk200;                       // 0x200
    char _pad204[0x210 - 0x204];
    float m_unk210[4];                  // 0x210 position vector used by the Distance checks in Execute
    float m_unk220[4];                  // 0x220 copy of the position and the Distance target row
    int m_unk230;                       // 0x230 timer id slot
    unsigned int m_unk234;              // 0x234 state-change argument set by OnHitEvent on death
    unsigned int m_unk238;              // 0x238 argument set by OnHitEvent on hit
    int m_unk23C;                       // 0x23C written by Execute case 0/10 sub-switch 1/3
    float m_unk240;                     // 0x240 ground height copied from the GetGroundPos result
    char _pad244[0x248 - 0x244];
    char *m_unk248;                     // 0x248 target entity read by GetTarget
    char _pad24C[0x250 - 0x24C];
    u_long128 m_unk250;                 // 0x250 16-byte copy of target block
    int m_unk260;                       // 0x260 timer id slot
    char _pad264[0x270 - 0x264];
    float m_unk270[4];                  // 0x270 vector, [1] is 0x274 (case 12/22 float)
    float m_unk280;                     // 0x280 target position read by FlyerPitchChange
    int m_unk284;                       // 0x284 hit points, reduced by OnHitEvent
    char _pad288[0x28C - 0x288];
    char *m_unk28C;                     // 0x28C effect handle, destroyed in dtor
    float m_unk290[4];                  // 0x290 dart vector; [1] is 0x294 (speed, zeroed in SetupDartDest)
    int m_unk2A0;                       // 0x2A0 timer id slot
    char *m_unk2A4;                     // 0x2A4 waypoint group, count at +4
    int m_unk2A8;                       // 0x2A8 next waypoint index
    int m_unk2AC;                       // 0x2AC waypoint index result of Execute case -1/9
    float m_unk2B0[4];                  // 0x2B0 dart target vector passed to FlyerFlyTo
    float m_unk2C0;                     // 0x2C0 bobbing phase

    unsigned char m_unk2C4;             // 0x2C4 flag cleared by SetupDartDest
    char _pad2C5[0x2C8 - 0x2C5];
    void *m_unk2C8;                     // 0x2C8 GetTarget cache
};

#endif
