#ifndef ZINSHELLSHADOW_H
#define ZINSHELLSHADOW_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; ZinShellShadow adds its fields from 0x190 on.
class ZinShellShadow : public EntityBaseClass {
public:
    ZinShellShadow();
    virtual ~ZinShellShadow();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0x1];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x1 bytes here
};

#endif
