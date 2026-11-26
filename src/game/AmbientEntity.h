#ifndef AMBIENTENTITY_H
#define AMBIENTENTITY_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; AmbientEntity adds its fields from 0x190 on.
class AmbientEntity : public EntityBaseClass {
public:
    AmbientEntity();
    virtual ~AmbientEntity();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x4];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x4 bytes here
};

#endif
