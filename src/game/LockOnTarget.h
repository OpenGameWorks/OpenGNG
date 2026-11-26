#ifndef LOCKONTARGET_H
#define LOCKONTARGET_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; LockOnTarget adds its fields from 0x190 on.
class LockOnTarget : public EntityBaseClass {
public:
    LockOnTarget();
    virtual ~LockOnTarget();
    const char *GetClassName();
    void Execute();
    void SetEditableVars(char *);
    int OnHitEvent(EntityBaseClass *, int, unsigned int, unsigned int);

    u_long128 m_unk190;         // 0x190 copy of the 0x70 quadword of m_unk1B0
    char _pad1A0[0x10];
    void *m_unk1B0;             // 0x1B0 cleared by the ctor, points at a 0x80-byte block
};

#endif
