#ifndef PROPELLERPOWERSOURCE_H
#define PROPELLERPOWERSOURCE_H

#include "types.h"
#include "EntityBaseClass.h"

class PMNode;

// EntityBaseClass occupies 0x000..0x18F; PropellerPowerSource adds its fields from 0x190 on.
// Base fields at 0x103..0x10F (0x104, 0x108, 0x10C) are not named in EntityBaseClass.h and are
// reached through raw offsets in the .cpp.
class PropellerPowerSource : public EntityBaseClass {
public:
    PropellerPowerSource();
    virtual ~PropellerPowerSource();
    void SetEditableVars(char *pSrc);
    int OnHitEvent(EntityBaseClass *pOther, int nA, unsigned int nB, unsigned int nC);
    virtual void Execute();
    const char *GetClassName();
    int GetHealth();
    int GetTallyType();
    int NeedsToBeWoken();
    int GetWokenVarPos();

    float m_unk190;             // 0x190
    char _pad194[0x1C];         // 0x194..0x1AF
    unsigned int m_unk1B0;      // 0x1B0 editable-vars block start; SetEditableVars memcpys 0x20 bytes here
    unsigned int m_unk1B4;      // 0x1B4 anim id passed to RecurseResetAnimByID
    int m_unk1B8;               // 0x1B8
    int m_unk1BC;               // 0x1BC
    int m_unk1C0;               // 0x1C0
    int m_unk1C4;               // 0x1C4
    int m_unk1C8;               // 0x1C8
    char _pad1CC[4];            // 0x1CC..0x1CF
    int m_unk1D0;               // 0x1D0 set to 1000 by SetEditableVars
    int m_unk1D4;               // 0x1D4
    int m_unk1D8;               // 0x1D8
    int m_unk1DC;               // 0x1DC
};

#endif
