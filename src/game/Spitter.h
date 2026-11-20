#ifndef SPITTER_H
#define SPITTER_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; Spitter adds its fields from 0x190 on.
class Spitter : public EntityBaseClass {
public:
    Spitter();
    virtual ~Spitter();
    virtual void Execute();
    virtual char *GetClassName();
    virtual void SetEditableVars(char *pSrc);
    virtual void OnTimerEvent(unsigned int nTimer);
    virtual int NeedsToBeWoken();
    virtual int GetWokenVarPos();
    void SpawnItem();

    float m_unk190[4];          // 0x190 position, copied to the spawned item at 0x80 or 0x190
    float m_unk1A0[4];          // 0x1A0 velocity, copied to the spawned item at 0x90 or 0x1A0
    float m_unk1B0;             // 0x1B0
    float m_unk1B4;             // 0x1B4
    float m_unk1B8;             // 0x1B8
    float m_unk1BC;             // 0x1BC
    int m_unk1C0;               // 0x1C0 item type, compared against 3 and 2 in SpawnItem
    float m_unk1C4;             // 0x1C4
    unsigned int m_unk1C8;      // 0x1C8
    float m_unk1CC;             // 0x1CC
    float m_unk1D0;             // 0x1D0
    float m_unk1D4;             // 0x1D4
    float m_unk1D8;             // 0x1D8
    float m_unk1DC;             // 0x1DC
    float m_unk1E0;             // 0x1E0
    int m_unk1E4;               // 0x1E4 read by NeedsToBeWoken
    float m_unk1E8;             // 0x1E8
    float m_unk1EC;             // 0x1EC
    unsigned int m_unk1F0;      // 0x1F0
    char _pad1F4[0xC];          // 0x1F4
    float m_unk200;             // 0x200 written to a spawned Spitter when item type is 2
};

#endif
