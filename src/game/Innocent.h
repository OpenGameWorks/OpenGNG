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
    void SetEditableVars(char *pText);
    void OnTimerEvent(unsigned int nTimer);
    int OnHitEvent(EntityBaseClass *pEnt, int nDamage, unsigned int nHitId, unsigned int nUnused);
    int IsEnemyReady(unsigned int *pOut);
    void ActivateAttackingEnemies();
    int GetNextPosition(float (&pos)[4]);
    int AwardCheck();
    int IsAlive();
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
    char _padD8[0xE8 - 0xD8];
    unsigned char m_unkE8;          // 0x0E8 set to 3 by OnHitEvent
    char _padE9[0x103 - 0xE9];
    unsigned char m_unk103;         // 0x103 set to 0xFE by constructor
    int m_unk104;                   // 0x104 set to 2.0f bits by constructor
    int m_unk108;                   // 0x108 set to 4.0f bits by constructor
    char _pad10C[0x140 - 0x10C];
    int m_unk140;                   // 0x140 compared with a sequence entry by OnHitEvent
    char _pad144[0x17A - 0x144];
    unsigned char m_unk17A;         // 0x17A cleared by OnTimerEvent
    char _pad17B[0x190 - 0x17B];
    float m_unk190;                 // 0x190 default box, read by SetEditableVars when no box is set
    float m_unk194;                 // 0x194 default box, y
    float m_unk198;                 // 0x198 default box, z
    char _pad19C[0x1B0 - 0x19C];
    int m_unk1B0;                   // 0x1B0 state; 3 selects the wake scale-up
    int m_unk1B4;                   // 0x1B4 must equal 2 for OnHitEvent to continue
    int m_unk1B8;                   // 0x1B8 scaled by SetEditableVars, positive while alive
    char _pad1BC[0x1C0 - 0x1BC];
    float m_unk1C0;                 // 0x1C0 editable box, x
    float m_unk1C4;                 // 0x1C4 editable box, y
    float m_unk1C8;                 // 0x1C8 editable box, z
    char _pad1CC[0x1D0 - 0x1CC];
    float m_unk1D0;                 // 0x1D0 search box, x
    float m_unk1D4;                 // 0x1D4 search box, y
    float m_unk1D8;                 // 0x1D8 search box, z
    float m_unk1DC;                 // 0x1DC search radius
    int m_unk1E0;                   // 0x1E0 copied to m_unk294 by SetEditableVars
    int m_unk1E4;                   // 0x1E4 copied to m_unk298 by SetEditableVars
    int m_unk1E8;                   // 0x1E8 copied to m_unk29C by SetEditableVars
    EntityBaseClass *m_unk1EC[3];   // 0x1EC..0x1F7 tracked entity handles
    char _pad1F8[0x208 - 0x1F8];
    int m_unk208;                   // 0x208 clamped to >= 0 by SetEditableVars
    unsigned int m_unk20C;          // 0x20C cut camera argument
    char _pad210[0x214 - 0x210];
    EntityBaseClass *m_unk214;      // 0x214 tracked apparition for AwardCheck
    char _pad218[0x230 - 0x218];
    float m_unk230;                 // 0x230 output box, x, set by SetEditableVars
    float m_unk234;                 // 0x234 output box, y
    float m_unk238;                 // 0x238 output box, z
    char _pad23C[0x250 - 0x23C];
    int m_unk250;                   // 0x250 timer id that sets m_unk266
    unsigned int m_unk254;          // 0x254 waypoint index
    int m_unk258;                   // 0x258 compared with m_unk254 by OnHitEvent
    int m_unk25C;                   // 0x25C read by ActivatedEnemiesDead
    int m_unk260;                   // 0x260 state at the last hit, written by OnHitEvent
    unsigned char m_unk264;         // 0x264 set by OnHitEvent
    char _pad265[0x266 - 0x265];
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
