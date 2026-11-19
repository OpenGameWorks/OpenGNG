#ifndef CLOCKWORKFLYER_H
#define CLOCKWORKFLYER_H

#include "types.h"

class ClockworkFlyer {
public:
    void SetSpawnedFromEntity(float *pPos, float *pAlt, int nType);
    int GetNextPosition(float (&rOut)[4]);
    void FaceTarget(float fAngle);
    ClockworkFlyer *GetTarget();
    void EscapeIfApproachStalled();
    void EscapeIfStalled();
    void InitStallData();
    void SetDefaultVars();
    void OnTimerEvent(unsigned int nId);

    char _pad000[0x4];                  // 0x000 vtable
    unsigned int m_unk4;                // 0x004 owner id passed to CreateTimer
    char _pad008[0x3C - 0x8];
    char *m_unk3C;                      // 0x03C target entity pointer; +0x80 used when non-null
    char _pad040[0x190 - 0x40];
    char _pad190[0x1B0 - 0x190];        // 0x190 embedded EntityBaseClass, address taken
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
    char _pad234[0x248 - 0x234];
    char *m_unk248;                     // 0x248 target entity read by GetTarget
    char _pad24C[0x250 - 0x24C];
    u_long128 m_unk250;                 // 0x250 16-byte copy of target block
    int m_unk260;                       // 0x260 timer id slot
    char _pad264[0x28C - 0x264];
    char *m_unk28C;                     // 0x28C effect handle, destroyed in dtor
    char _pad290[0x2A0 - 0x290];
    int m_unk2A0;                       // 0x2A0 timer id slot
    char *m_unk2A4;                     // 0x2A4 waypoint group, count at +4
    int m_unk2A8;                       // 0x2A8 next waypoint index
    char _pad2AC[0x2C8 - 0x2AC];
    void *m_unk2C8;                     // 0x2C8 GetTarget cache
};

#endif
