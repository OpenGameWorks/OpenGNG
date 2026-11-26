#ifndef ACTIONPLING_H
#define ACTIONPLING_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; ActionPling adds its fields from 0x190 on.
class ActionPling : public EntityBaseClass {
public:
    ActionPling();
    virtual ~ActionPling();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x1];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x1 bytes here
    unsigned char m_unk1B1;     // 0x1B1 cleared by the ctor
};

#endif
