#ifndef SOUNDROOM_H
#define SOUNDROOM_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; SoundRoom adds its fields from 0x190 on.
class SoundRoom : public EntityBaseClass {
public:
    SoundRoom();
    virtual ~SoundRoom();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x40];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x40 bytes here
};

#endif
