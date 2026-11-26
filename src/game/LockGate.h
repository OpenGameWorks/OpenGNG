#ifndef LOCKGATE_H
#define LOCKGATE_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; LockGate adds its fields from 0x190 on.
class LockGate : public EntityBaseClass {
public:
    virtual ~LockGate();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x8];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x8 bytes here
};

#endif
