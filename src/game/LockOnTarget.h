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

    char _pad190[0x20];
    int m_unk1B0;               // 0x1B0 cleared by the ctor
};

#endif
