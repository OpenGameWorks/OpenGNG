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

    char _pad190[0x20];
    char m_unk1B0[4];           // 0x1B0 editable-vars block; SetEditableVars memcpys 0x34 bytes here
    int m_unk1B4;               // 0x1B4 AnimID, must not be -1
    char _pad1B8[0x14];
    EntityBaseClass *m_unk1CC[4];   // 0x1CC wave instances
    char _pad1DC[8];
    PArray m_unk1E4;            // 0x1E4
    PArray m_unk1F4;            // 0x1F4
    char m_unk204[0x1B8];       // 0x204 WAVE_TABLE_ELEMENT[10], 0x2C bytes each (__construct_array in ctor)
    char _pad3BC[4];            // 0x3BC..0x3BF
    int m_unk3C0;               // 0x3C0 current wave
    char _pad3C4[4];
    unsigned char m_unk3C8;     // 0x3C8 all-enemies-dead flag
    char _pad3C9[7];            // 0x3C9..0x3CF not yet identified
    char m_unk3D0[0x18];        // 0x3D0 PList, size not recovered; must end by 0x3E8
    float m_unk3E8;             // 0x3E8 completed delay
    int m_unk3EC;               // 0x3EC zeroed by ctor
    char _pad3F0[4];            // 0x3F0..0x3F3
    signed char m_unk3F4;       // 0x3F4
    signed char m_unk3F5;       // 0x3F5
    char _pad3F6[2];
};

#endif
