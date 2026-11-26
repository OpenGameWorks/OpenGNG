#ifndef SOUNDTRIGGERPLAINSPHERE_H
#define SOUNDTRIGGERPLAINSPHERE_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; SoundTriggerPlainSphere adds its fields from 0x190 on.
class SoundTriggerPlainSphere : public EntityBaseClass {
public:
    SoundTriggerPlainSphere();
    virtual ~SoundTriggerPlainSphere();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x38];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x38 bytes here
};

#endif
