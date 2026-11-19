#ifndef TINKER_H
#define TINKER_H

class EntityBaseClass;

class Tinker {
public:
    Tinker();
    void AttackSound();
    void SetAsActivatedEnemyTarget();
    bool TrappedEntityRemoved();
    unsigned int IsBadWaypoint(unsigned int arg0);
    int GetNextPosition(float (&pos)[4]);
    int AwardCheck();
    void SetAsEnemyTarget(unsigned int arg0, bool arg1);
    int IsStalled(float fDist, float (*arg1)[4]);
    int EnemiesInCheckRadius();
    void ActivateAttackingEnemies();
    int ActivatedEnemiesDead();
    void OnTouchEvent(EntityBaseClass *pOther);
    void OnDestroyEvent();

    char _pad000[0x0C];
    int m_unk00C;                       // 0x00C
    char _pad010[0x20 - 0x10];
    int m_unk20;                        // 0x020
    char _pad024[0x3C - 0x24];
    char *m_unk3C;                      // 0x03C
    char _pad040[0xD4 - 0x40];
    int m_unk0D4;                       // 0x0D4
    char _pad0D8[0x104 - 0xD8];
    float m_unk104;                     // 0x104
    float m_unk108;                     // 0x108
    char _pad10C[0x140 - 0x10C];
    void *m_unk140;                     // 0x140, current attack sequence
    char _pad144[0x190 - 0x144];
    float m_unk190[4];                  // 0x190
    char _pad1A0[0x1B0 - 0x1A0];
    int m_unk1B0;                       // 0x1B0
    int m_unk1B4;                       // 0x1B4
    char _pad1B8[0x1D0 - 0x1B8];
    float m_unk1D0[4];                  // 0x1D0
    EntityBaseClass *m_unk1E0[4];       // 0x1E0, attacking enemies
    EntityBaseClass *m_unk1F0[4];       // 0x1F0
    int m_unk200;                       // 0x200
    char _pad204[0x228 - 0x204];
    EntityBaseClass *m_unk228;          // 0x228
    char _pad22C[0x250 - 0x22C];
    float m_unk250[4];                  // 0x250
    char _pad260[0x278 - 0x260];
    int m_unk278;                       // 0x278
    char _pad27C[0x280 - 0x27C];
    unsigned char m_unk280;             // 0x280
    char _pad281[0x284 - 0x281];
    int m_unk284;                       // 0x284
    char _pad288[0x28C - 0x288];
    int m_unk28C;                       // 0x28C
    int m_unk290;                       // 0x290
    int m_unk294;                       // 0x294
    char _pad298[0x2A4 - 0x298];
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
    unsigned int m_unk2D0;              // 0x2D0
    char _pad2D4[0x2D8 - 0x2D4];
    int *m_unk2D8;                      // 0x2D8, pointer to waypoint array
    char _pad2DC[0x2E4 - 0x2DC];
    unsigned int m_unk2E4;              // 0x2E4
    char _pad2E8[0x2EC - 0x2E8];
    int m_unk2EC;                       // 0x2EC
    int m_unk2F0;                       // 0x2F0
};

#endif
