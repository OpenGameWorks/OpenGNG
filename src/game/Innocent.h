#ifndef INNOCENT_H
#define INNOCENT_H

#include "types.h"

class EntityBaseClass;
class PMNode;

class Innocent {
public:
    Innocent();
    int AnimationViewer(int arg0);
    void OnWakeEvent();
    void *FindClosestEnemy(float (*pBox)[4]);
    int EnemiesInCheckRadius();
    int ActivatedEnemiesDead();
    int TrappedEntityRemoved();
    void OutputDebug();
    void OnTimerEvent(unsigned int nTimer);
    int IsEnemyReady(unsigned int *pOut);
    void ActivateAttackingEnemies();
    int GetNextPosition(float (&pos)[4]);
    int AwardCheck();
    int BuildDialogTable();

    void *m_unk0;                   // 0x000 vtable pointer
    unsigned int m_unk4;
    char _pad008[0x0C - 0x08];
    int m_unkC;
    char _pad010[0x20 - 0x10];
    int m_unk20;                    // 0x020 state, printed by OutputDebug
    char _pad024[0x3C - 0x24];
    PMNode *m_unk3C;                // 0x03C
    char _pad040[0xD4 - 0x40];
    int m_unkD4;                    // 0x0D4 cleared by constructor
    char _padD8[0x103 - 0xD8];
    unsigned char m_unk103;         // 0x103 set to 0xFE by constructor
    int m_unk104;                   // 0x104 set to 2.0f bits by constructor
    int m_unk108;                   // 0x108 set to 4.0f bits by constructor
    char _pad10C[0x17A - 0x10C];
    unsigned char m_unk17A;         // 0x17A cleared by OnTimerEvent
    char _pad17B[0x1B0 - 0x17B];
    int m_unk1B0;                   // 0x1B0 state; 3 selects the wake scale-up
    char _pad1B4[0x1D0 - 0x1B4];
    float m_unk1D0;                 // 0x1D0 search box, x
    float m_unk1D4;                 // 0x1D4 search box, y
    float m_unk1D8;                 // 0x1D8 search box, z
    float m_unk1DC;                 // 0x1DC search radius
    char _pad1E0[0x1EC - 0x1E0];
    EntityBaseClass *m_unk1EC[3];   // 0x1EC..0x1F7 tracked entity handles
    char _pad1F8[0x20C - 0x1F8];
    unsigned int m_unk20C;          // 0x20C cut camera argument
    char _pad210[0x214 - 0x210];
    EntityBaseClass *m_unk214;      // 0x214 tracked apparition for AwardCheck
    char _pad218[0x250 - 0x218];
    int m_unk250;                   // 0x250 timer id that sets m_unk266
    unsigned int m_unk254;          // 0x254 waypoint index
    char _pad258[0x25C - 0x258];
    int m_unk25C;                   // 0x25C read by ActivatedEnemiesDead
    char _pad260[0x266 - 0x260];
    unsigned char m_unk266;         // 0x266 set by OnTimerEvent
    char _pad267[0x26C - 0x267];
    unsigned char m_unk26C;         // 0x26C awarded flag
    char _pad26D[0x270 - 0x26D];
    unsigned char m_unk270;         // 0x270 read by ActivatedEnemiesDead
    unsigned char m_unk271;         // 0x271 set by OnTimerEvent
    unsigned char m_unk272;         // 0x272 cleared by constructor
    char _pad273[0x274 - 0x273];
    int m_unk274;                   // 0x274 cleared by constructor
    unsigned char m_unk278;         // 0x278 set by OnTimerEvent
    char _pad279[0x27C - 0x279];
    int m_unk27C;                   // 0x27C timer id that sets m_unk278
    char _pad280[0x284 - 0x280];
    int m_unk284;                   // 0x284 timer id that sets m_unk271
    int m_unk288;                   // 0x288 cleared by constructor
    char _pad28C[0x290 - 0x28C];
    void *m_unk290;                 // 0x290 waypoint group
    EntityBaseClass *m_unk294[3];   // 0x294..0x29C tracked entity handles
    int m_unk2A0;                   // 0x2A0 timer id that starts the cut camera
};

#endif
