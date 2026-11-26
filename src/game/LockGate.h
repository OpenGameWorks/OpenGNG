#ifndef LOCKGATE_H
#define LOCKGATE_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; LockGate adds its fields from 0x190 on.
class LockGate : public EntityBaseClass {
public:
    LockGate();
    virtual ~LockGate();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();
    int OnHitEvent(EntityBaseClass *pArg, int nHit, unsigned int nFlagsA, unsigned int nFlagsB);

    char _pad190[0x20];
    int m_unk1B0;              // 0x1B0 editable-vars block (8 bytes); SetEditableVars memcpys here
    int m_unk1B4;
    unsigned char m_unk1B8;     // 0x1B8 cleared by the ctor
    char _pad1B9[0x3];
    int m_unk1BC;               // 0x1BC sound ref, set by PlaySound in Execute
};

#endif
