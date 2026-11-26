#ifndef MOVINGFOG_H
#define MOVINGFOG_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; MovingFog adds its fields from 0x190 on.
class MovingFog : public EntityBaseClass {
public:
    MovingFog();
    virtual ~MovingFog();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x44];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x44 bytes here
};

#endif
