#ifndef FARPLANETRIGGER_H
#define FARPLANETRIGGER_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; FarPlaneTrigger adds its fields from 0x190 on.
class FarPlaneTrigger : public EntityBaseClass {
public:
    FarPlaneTrigger();
    virtual ~FarPlaneTrigger();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    float m_unk190[4];          // 0x190 position vec4 passed to Distance
    char _pad1A0[0x10];         // 0x1A0..0x1AF
    float m_unk1B0;             // 0x1B0 editable-vars block (0x14 bytes, 0x1B0..0x1C3); first float copied to gEng
    char _pad1B4[0xC];          // 0x1B4..0x1BF editable-vars block
    float m_unk1C0;             // 0x1C0 editable far-plane range
    unsigned char m_unk1C4;     // 0x1C4 flag: set by the state-1 path, cleared when the player is out of range
};

#endif
