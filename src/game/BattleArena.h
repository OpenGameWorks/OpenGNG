#ifndef BATTLEARENA_H
#define BATTLEARENA_H

#include "types.h"
#include "EntityBaseClass.h"
#include "PArray.h"

// Layout from BattleArena.cpp: EntityBaseClass occupies 0x000..0x18F.
class BattleArena : public EntityBaseClass {
public:
    BattleArena();
    void OutputDebug();
    void ActivateInstances();
    void SpawnAllEnemiesInCurrentWave();
    void SpawnEnemyFromCurrentWave(unsigned int nApparitionId);
    void SetEditableVars(char *pSrc);
    void Execute();
    const char *GetClassName();
    int NeedsToBeWoken();
    int GetWokenVarPos();

    char _pad190[0x20];
    char m_unk1B0[4];           // 0x1B0 editable-vars block; SetEditableVars memcpys 0x34 bytes here
    int m_unk1B4;               // 0x1B4 AnimID, must not be -1
    float m_unk1B8;             // 0x1B8 delay scale; case -1 multiplies it by 60
    int m_unk1BC;               // 0x1BC wave start index (>= 0 starts a cutscene)
    float m_unk1C0;             // 0x1C0 player-height threshold (case 12)
    int m_unk1C4;               // 0x1C4 level-clear flag (case -2)
    int m_unk1C8;               // 0x1C8 camera id (case 5)
    EntityBaseClass *m_unk1CC[4];   // 0x1CC wave instances
    char _pad1DC[4];
    int m_unk1E0;               // 0x1E0 forces the distance check in case 0
    PArray m_unk1E4;            // 0x1E4
    PArray m_unk1F4;            // 0x1F4
    char m_unk204[0x1B8];       // 0x204 WAVE_TABLE_ELEMENT[10], 0x2C bytes each (__construct_array in ctor)
    int m_unk3BC;               // 0x3BC wave count
    int m_unk3C0;               // 0x3C0 current wave
    int m_unk3C4;               // 0x3C4 not yet identified
    unsigned char m_unk3C8;     // 0x3C8 all-enemies-dead flag
    char _pad3C9[3];            // 0x3C9..0x3CB not yet identified
    float m_unk3CC;             // 0x3CC decremented by the delay scale
    char m_unk3D0[0x18];        // 0x3D0 PList, size not recovered; must end by 0x3E8
    float m_unk3E8;             // 0x3E8 completed delay
    int m_unk3EC;               // 0x3EC zeroed by ctor
    char _pad3F0[4];            // 0x3F0..0x3F3
    signed char m_unk3F4;       // 0x3F4
    signed char m_unk3F5;       // 0x3F5
    char _pad3F6[2];
};

#endif
