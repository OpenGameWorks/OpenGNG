#ifndef FARPLANETRIGGER_H
#define FARPLANETRIGGER_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; FarPlaneTrigger adds its fields from 0x190 on.
class FarPlaneTrigger : public EntityBaseClass {
public:
    virtual ~FarPlaneTrigger();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x14];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x14 bytes here
};

#endif
