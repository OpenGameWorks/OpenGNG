#ifndef ZINSHELLCRATER_H
#define ZINSHELLCRATER_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; ZinShellCrater adds its fields from 0x190 on.
class ZinShellCrater : public EntityBaseClass {
public:
    ZinShellCrater();
    virtual ~ZinShellCrater();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char m_unk190[0x20];       // 0x190 MathAPI view (GetGroundPos target); MathAPI itself is too large to embed
    char m_unk1B0[0x1];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x1 bytes here
};

#endif
