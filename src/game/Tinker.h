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
    void Execute();

    float m_unk190[4];                  // 0x190
    float m_unk1A0[4];                  // 0x1A0
    int m_unk1B0;                       // 0x1B0
    int m_unk1B4;                       // 0x1B4
    int m_unk1B8;                       // 0x1B8
    int m_unk1BC;                       // 0x1BC
    float m_unk1C0;                     // 0x1C0
    float m_unk1C4;                     // 0x1C4
    float m_unk1C8;                     // 0x1C8
    float m_unk1CC;                     // 0x1CC
    float m_unk1D0[4];                  // 0x1D0
    EntityBaseClass *m_unk1E0[4];       // 0x1E0, attacking enemies
    EntityBaseClass *m_unk1F0[4];       // 0x1F0
    int m_unk200;                       // 0x200
    int m_unk204;                       // 0x204
    char _pad208[0x4];
    unsigned int m_unk20C;              // 0x20C
    int m_unk210;                       // 0x210
    unsigned int m_unk214;              // 0x214
    unsigned int m_unk218;              // 0x218
    float m_unk21C;                     // 0x21C
    EntityBaseClass *m_unk220;          // 0x220
    int m_unk224;                       // 0x224
    EntityBaseClass *m_unk228;          // 0x228
    int m_unk22C;                       // 0x22C
    int m_unk230;                       // 0x230
    char _pad234[0x240 - 0x234];
    float m_unk240;                     // 0x240
    float m_unk244;                     // 0x244
    float m_unk248;                     // 0x248
    char _pad24C[0x250 - 0x24C];
    float m_unk250[4];                  // 0x250
    float m_unk260[4];                  // 0x260
    int m_unk270;                       // 0x270
    int m_unk274;                       // 0x274
    int m_unk278;                       // 0x278
    int m_unk27C;                       // 0x27C
    unsigned char m_unk280;             // 0x280
    char _pad281[0x284 - 0x281];
    int m_unk284;                       // 0x284
    int m_unk288;                       // 0x288
    int m_unk28C;                       // 0x28C
    int m_unk290;                       // 0x290
    int m_unk294;                       // 0x294
    int m_unk298;                       // 0x298
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
    EntityBaseClass *m_unk2F0;          // 0x2F0
    unsigned char m_unk2F4;             // 0x2F4
};

#endif
