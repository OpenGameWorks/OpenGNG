#ifndef TINKER_H
#define TINKER_H

#include "EntityBaseClass.h"
#include "PArray.h"

// EntityBaseClass occupies 0x000..0x18F; Tinker fields start at 0x190.
class Tinker : public EntityBaseClass {
public:
    Tinker();
    virtual ~Tinker();
    void AttackSound();
    void FootstepSound();
    void *GetAnimSequence(unsigned int arg0);
    void SetAsActivatedEnemyTarget();
    bool TrappedEntityRemoved();
    unsigned int IsBadWaypoint(unsigned int arg0);
    int GetClosestWaypoint(float (&pos)[4], bool bFlag);
    int GetNextPosition(float (&pos)[4]);
    int AwardCheck();
    void SetAsEnemyTarget(unsigned int arg0, bool arg1);
    int IsStalled(float fDist, float (*arg1)[4]);
    int MoveTo(float (*arg0)[4], float arg1);
    void *FindClosestEnemy(float (*pBox)[4], EntityBaseClass::LoadClass eLoadClass, unsigned int nFlags);
    int EnemiesInCheckRadius();
    void ActivateAttackingEnemies();
    int ActivatedEnemiesDead();
    void SetEditableVars(char *arg0);
    void OnTouchEvent(EntityBaseClass *pOther);
    void OnDestroyEvent();
    void OnTimerEvent(unsigned int arg0);
    int OnHitEvent(EntityBaseClass *pOther, int arg1, unsigned int arg2, unsigned int arg3);

    float m_unk190[4];                  // 0x190
    char _pad1A0[0x1B0 - 0x1A0];
    int m_unk1B0;                       // 0x1B0
    int m_unk1B4;                       // 0x1B4
    int m_unk1B8;                       // 0x1B8
    char _pad1BC[0x1C0 - 0x1BC];
    float m_unk1C0;                     // 0x1C0
    float m_unk1C4;                     // 0x1C4
    float m_unk1C8;                     // 0x1C8
    char _pad1CC[0x1D0 - 0x1CC];
    float m_unk1D0[4];                  // 0x1D0
    EntityBaseClass *m_unk1E0[4];       // 0x1E0, attacking enemies
    EntityBaseClass *m_unk1F0[4];       // 0x1F0
    int m_unk200;                       // 0x200
    char _pad204[0x210 - 0x204];
    int m_unk210;                       // 0x210
    char _pad214[0x218 - 0x214];
    unsigned int m_unk218;              // 0x218
    char _pad21C[0x228 - 0x21C];
    EntityBaseClass *m_unk228;          // 0x228
    char _pad22C[0x240 - 0x22C];
    float m_unk240;                     // 0x240
    float m_unk244;                     // 0x244
    float m_unk248;                     // 0x248
    char _pad24C[0x250 - 0x24C];
    float m_unk250[4];                  // 0x250
    char _pad260[0x278 - 0x260];
    int m_unk278;                       // 0x278
    char _pad27C[0x280 - 0x27C];
    unsigned char m_unk280;             // 0x280
    char _pad281[0x284 - 0x281];
    int m_unk284;                       // 0x284
    int m_unk288;                       // 0x288
    int m_unk28C;                       // 0x28C
    int m_unk290;                       // 0x290
    int m_unk294;                       // 0x294
    char _pad298[0x29C - 0x298];
    int m_unk29C;                       // 0x29C
    unsigned char m_unk2A0;             // 0x2A0
    char _pad2A1[0x2A4 - 0x2A1];
    int m_unk2A4;                       // 0x2A4
    void *m_unk2A8;                     // 0x2A8, waypoint group
    EntityBaseClass *m_unk2AC[4];       // 0x2AC, activated enemies
    int m_unk2BC;                       // 0x2BC
    unsigned char m_unk2C0;             // 0x2C0
    unsigned char m_unk2C1;             // 0x2C1
    char _pad2C2[0x2C4 - 0x2C2];
    int m_unk2C4;                       // 0x2C4
    unsigned int m_unk2C8;              // 0x2C8
    unsigned int m_unk2CC;              // 0x2CC
    PArray m_unk2D0;                    // 0x2D0, waypoint array; m_unk2D0.m_unk8 is its storage at 0x2D8
    unsigned char m_unk2E0;             // 0x2E0
    char _pad2E1[0x2E4 - 0x2E1];
    unsigned int m_unk2E4;              // 0x2E4
    int m_unk2E8;                       // 0x2E8
    int m_unk2EC;                       // 0x2EC
    int m_unk2F0;                       // 0x2F0
    unsigned char m_unk2F4;             // 0x2F4
};

#endif
