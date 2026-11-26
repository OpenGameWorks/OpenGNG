#ifndef LOCKONTARGET_H
#define LOCKONTARGET_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; LockOnTarget adds its fields from 0x190 on.
class LockOnTarget : public EntityBaseClass {
public:
    virtual ~LockOnTarget();
    const char *GetClassName();
    void Execute();

};

#endif
