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
    char _pad1B1[0x3];         // 0x1B1..0x1B3
    float m_unk1B4;            // 0x1B4 shadow scale, grows by 0.02 per frame in Execute
};

#endif
