#ifndef TINKER_H
#define TINKER_H

class EntityBaseClass;

class Tinker {
public:
    bool TrappedEntityRemoved();
    unsigned int IsBadWaypoint(unsigned int arg0);
    void SetAsEnemyTarget(unsigned int arg0, bool arg1);
    int EnemiesInCheckRadius();
    void OnDestroyEvent();

    char _pad000[0x0C];
    int m_unk00C;                       // 0x00C
    char _pad010[0x1B0 - 0x10];
    int m_unk1B0;                       // 0x1B0
    char _pad1B4[0x1D0 - 0x1B4];
    float m_unk1D0[4];                  // 0x1D0
    char _pad1E0[0x1F0 - 0x1E0];
    EntityBaseClass *m_unk1F0[4];       // 0x1F0
    char _pad200[0x2D0 - 0x200];
    unsigned int m_unk2D0;              // 0x2D0
    char _pad2D4[0x2D8 - 0x2D4];
    int *m_unk2D8;                      // 0x2D8, pointer to waypoint array
};

#endif
