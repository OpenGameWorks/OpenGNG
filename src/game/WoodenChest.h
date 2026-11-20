#ifndef WOODENCHEST_H
#define WOODENCHEST_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F (including the vtable pointer and m_unk20);
// WoodenChest adds its fields from 0x190 on.
class WoodenChest : public EntityBaseClass {
public:
    WoodenChest();
    virtual ~WoodenChest();
    int GetTallyType();
    void SetDefaultVars();
    void SetEditableVars(char *pSrc);
    int HaveKeys();
    int OnHitEvent(class EntityBaseClass *pEntity, int nEvent, unsigned int nA, unsigned int nB);
    void OnSleepEvent();
    void OnAttackEvent(class EntityBaseClass *pEntity, int nEvent);

    char _pad190[0x20];
    int m_unk1B0;             // 0x1B0 set to -1 by SetDefaultVars
    int m_unk1B4;             // 0x1B4 set to 0 by SetDefaultVars
    int m_unk1B8;             // 0x1B8 set to -1 by SetDefaultVars
    int m_unk1BC;             // 0x1BC set to 0 by SetDefaultVars
    int m_unk1C0;             // 0x1C0 set to -1 by SetDefaultVars
    int m_unk1C4;             // 0x1C4 set to 0 by SetDefaultVars
    int m_unk1C8;             // 0x1C8 set to 0 by SetDefaultVars, tally type 1 when 2
    int m_unk1CC;             // 0x1CC set to 0 by SetDefaultVars, tally type 4 when nonzero
    float m_unk1D0;           // 0x1D0 set to 10.0f by SetDefaultVars
    float m_unk1D4;           // 0x1D4 set to 40.0f by SetDefaultVars
    int m_unk1D8;             // 0x1D8 printed as a warning when set together with 0x1CC
    int m_unk1DC;             // 0x1DC cleared by OnHitEvent when set
    int m_unk1E0;            // 0x1E0 set to 150 by SetDefaultVars
    char _pad1E4[0x1EC - 0x1E4];
    int m_unk1EC;             // 0x1EC cleared by the constructor
    char _pad1F0[0x210 - 0x1F0];
    unsigned int m_unk210;    // 0x210 apparition id, cleared by the constructor
    float m_unk214;           // 0x214 ground height from GetGroundPos, set by SetEditableVars
};

#endif
