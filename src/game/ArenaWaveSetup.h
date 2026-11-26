#ifndef ARENAWAVESETUP_H
#define ARENAWAVESETUP_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; ArenaWaveSetup adds its fields from 0x190 on.
class ArenaWaveSetup : public EntityBaseClass {
public:
    ArenaWaveSetup();
    virtual ~ArenaWaveSetup();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x20];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x20 bytes here
};

#endif
