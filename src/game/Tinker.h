#ifndef TINKER_H
#define TINKER_H

class EntityBaseClass;

class Tinker {
public:
    void AttackSound();
    void SetAsActivatedEnemyTarget();
    bool TrappedEntityRemoved();
    unsigned int IsBadWaypoint(unsigned int arg0);
    void SetAsEnemyTarget(unsigned int arg0, bool arg1);
    int IsStalled(float fDist, float (*arg1)[4]);
    int EnemiesInCheckRadius();
    void OnTouchEvent(EntityBaseClass *pOther);
    void OnDestroyEvent();

    char _pad000[0x0C];
    int m_unk00C;                       // 0x00C
    char _pad010[0x20 - 0x10];
    int m_unk20;                        // 0x020
    char _pad024[0x3C - 0x24];
    char *m_unk3C;                      // 0x03C
    char _pad040[0x140 - 0x40];
    void *m_unk140;                     // 0x140, current attack sequence
    char _pad144[0x190 - 0x144];
    float m_unk190[4];                  // 0x190
    char _pad1A0[0x1B0 - 0x1A0];
    int m_unk1B0;                       // 0x1B0
    int m_unk1B4;                       // 0x1B4
    char _pad1B8[0x1D0 - 0x1B8];
    float m_unk1D0[4];                  // 0x1D0
    char _pad1E0[0x1F0 - 0x1E0];
    EntityBaseClass *m_unk1F0[4];       // 0x1F0
    char _pad200[0x250 - 0x200];
    float m_unk250[4];                  // 0x250
    char _pad260[0x280 - 0x260];
    unsigned char m_unk280;             // 0x280
    char _pad281[0x2AC - 0x281];
    EntityBaseClass *m_unk2AC[4];       // 0x2AC
    char _pad2BC[0x2D0 - 0x2BC];
    unsigned int m_unk2D0;              // 0x2D0
    char _pad2D4[0x2D8 - 0x2D4];
    int *m_unk2D8;                      // 0x2D8, pointer to waypoint array
    char _pad2DC[0x2E4 - 0x2DC];
    unsigned int m_unk2E4;              // 0x2E4
};

#endif
