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

    float m_unk190;             // 0x190
    char _pad194[0x1C];         // 0x194..0x1AF
    char m_unk1B0[4];           // 0x1B0 editable-vars block start; SetEditableVars memcpys 0x20 bytes here
    unsigned int m_unk1B4;      // 0x1B4 anim id passed to RecurseResetAnimByID
    char _pad1B8[4];            // 0x1B8..0x1BB
    int m_unk1BC;               // 0x1BC
    char _pad1C0[0x10];         // 0x1C0..0x1CF
    int m_unk1D0;               // 0x1D0 set to 1000 by SetEditableVars
    char _pad1D4[4];            // 0x1D4..0x1D7
    int m_unk1D8;               // 0x1D8
};

#endif
