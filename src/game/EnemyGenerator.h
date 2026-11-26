#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H

#include "types.h"

// Empty member subobject at the end of the layout; its declared destructor makes
// the constructor keep `this` in memory, as the original does.
class EnemyGeneratorSlotGuard {
public:
    EnemyGeneratorSlotGuard() {}
    ~EnemyGeneratorSlotGuard() {}
    char _pad000[4];
};

// EnemyGenerator derives from EntityBaseClass; the base is not declared here,
// so every member is named by its offset from the object start.
class EnemyGenerator {
public:
    EnemyGenerator();
    void OnTimerEvent(unsigned int arg0);
    void CheckGeneratedEnemies();
    void Execute();
    void GenerateEnemy();
    int GetHealth();
    int GetWokenVarPos();
    const char *GetClassName();
    void SetEditableVars(char *);

    char _pad000[4];
    unsigned int m_unk4;            // 0x004 timer argument
    char _pad008[0x20 - 0x08];
    int m_unk20;                    // 0x020 state
    char _pad024[0x3C - 0x24];
    void *m_unk3C;                  // 0x03C apparition whose offsets place the spawn point, or null
    char _pad040[0x190 - 0x40];
    float m_unk190[4];              // 0x190 position measured against the player by Execute
    char _pad1A0[0x1B0 - 0x1A0];
    unsigned char m_unk1B0;         // 0x1B0 set to 1 by OnTimerEvent
    char _pad1B1[0x1B4 - 0x1B1];
    int m_unk1B4;                   // 0x1B4 timer argument that OnTimerEvent matches
    unsigned char m_unk1B8;         // 0x1B8 cleared by the constructor
    char _pad1B9[0x1BC - 0x1B9];
    int m_unk1BC;                   // 0x1BC set to 0x1E0 by the constructor
    int m_unk1C0;                   // 0x1C0 set to 0x1E0 by the constructor
    int m_unk1C4;                   // 0x1C4 cleared by the constructor
    int m_unk1C8[3];                // 0x1C8 type indices of the enabled enemy types, built by Execute
    int m_unk1D4;                   // 0x1D4 count of enabled enemy types
    int m_unk1D8;                   // 0x1D8 number of live generated enemies
    int m_unk1DC[3];                // 0x1DC generated enemy handles, one per slot
    int m_unk1E8;                   // 0x1E8 free slot index, -1 when none
    float m_unk1EC;                 // 0x1EC threshold read by Execute
    int m_unk1F0[3];                // 0x1F0 per-type values, summed in Execute
    EnemyGeneratorSlotGuard m_unk1FC;
    unsigned int m_unk200;          // 0x200 instance id of the innocent entity, checked by InstanceIsValid
};

extern "C" EnemyGenerator *__dt__14EnemyGeneratorFv(EnemyGenerator *pThis, short nFlag);

#endif
