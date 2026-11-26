#ifndef BLOWINGLEAVESTRIGGER_H
#define BLOWINGLEAVESTRIGGER_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; BlowingLeavesTrigger adds its fields from 0x190 on.
class BlowingLeavesTrigger : public EntityBaseClass {
public:
    virtual ~BlowingLeavesTrigger();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x18];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x18 bytes here
};

#endif
