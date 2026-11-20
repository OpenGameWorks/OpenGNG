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

    char _pad000[0x4];                  // 0x000 vtable
    unsigned int m_unk4;                // 0x004 owner id passed to CreateTimer
    char _pad008[0x38 - 0x8];
    float *m_unk38;                     // 0x038 16-byte output pointer
    char *m_unk3C;                     // 0x03C target entity pointer; +0x80 used when non-null
    char _pad040[0xF4 - 0x40];
    int m_unkF4;                        // 0x0F4 nonzero selects the damage-absorb path in OnHitEvent
    char _pad0F8[0x190 - 0xF8];
    ClockworkFlyerPad190 _pad190;       // 0x190 16-byte block, address taken
    float m_unk1A0;                     // 0x1A0 position read by FlyerPitchChange
    char _pad1A4[0x1B0 - 0x1A4];
    int m_unk1B0;                       // 0x1B0 type argument of SetSpawnedFromEntity
    char _pad1B4[0x1BC - 0x1B4];
    int m_unk1BC;                       // 0x1BC
    int m_unk1C0;                       // 0x1C0
    int m_unk1C4;                       // 0x1C4
    int m_unk1C8;                       // 0x1C8 float bits 25.0f (SetDefaultVars), 75.0f (SetSpawnedFromEntity)
    float m_unk1CC[3];                  // 0x1CC position copied by SetSpawnedFromEntity
    int m_unk1D8;                       // 0x1D8 float bits 35.0f (SetDefaultVars), 150.0f (SetSpawnedFromEntity)
    int m_unk1DC;                       // 0x1DC
    char _pad1E0[0x1E4 - 0x1E0];
    int m_unk1E4;                       // 0x1E4
    int m_unk1E8;                       // 0x1E8
    int m_unk1EC;                       // 0x1EC
    int m_unk1F0;                       // 0x1F0
    char _pad1F4[0x1F8 - 0x1F4];
    int m_unk1F8;                       // 0x1F8
    int m_unk1FC;                       // 0x1FC float bits 0.1f
    int m_unk200;                       // 0x200
    char _pad204[0x230 - 0x204];
    int m_unk230;                       // 0x230 timer id slot
    unsigned int m_unk234;              // 0x234 state-change argument set by OnHitEvent on death
    unsigned int m_unk238;              // 0x238 argument set by OnHitEvent on hit
    char _pad23C[0x248 - 0x23C];
    char *m_unk248;                     // 0x248 target entity read by GetTarget
    char _pad24C[0x250 - 0x24C];
    u_long128 m_unk250;                 // 0x250 16-byte copy of target block
    int m_unk260;                       // 0x260 timer id slot
    char _pad264[0x280 - 0x264];
    float m_unk280;                     // 0x280 target position read by FlyerPitchChange
    int m_unk284;                       // 0x284 hit points, reduced by OnHitEvent
    char _pad288[0x28C - 0x288];
    char *m_unk28C;                     // 0x28C effect handle, destroyed in dtor
    float m_unk290[4];                  // 0x290 dart vector; [1] is 0x294 (speed, zeroed in SetupDartDest)
    int m_unk2A0;                       // 0x2A0 timer id slot
    char *m_unk2A4;                     // 0x2A4 waypoint group, count at +4
    int m_unk2A8;                       // 0x2A8 next waypoint index
    char _pad2AC[0x2C0 - 0x2AC];
    float m_unk2C0;                     // 0x2C0 bobbing phase

    unsigned char m_unk2C4;             // 0x2C4 flag cleared by SetupDartDest
    char _pad2C5[0x2C8 - 0x2C5];
    void *m_unk2C8;                     // 0x2C8 GetTarget cache
};

#endif
