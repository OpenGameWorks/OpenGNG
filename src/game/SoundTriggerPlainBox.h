#ifndef SOUNDTRIGGERPLAINBOX_H
#define SOUNDTRIGGERPLAINBOX_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; SoundTriggerPlainBox adds its fields from 0x190 on.
class SoundTriggerPlainBox : public EntityBaseClass {
public:
    SoundTriggerPlainBox();
    virtual ~SoundTriggerPlainBox();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x78];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x78 bytes here
};

#endif
