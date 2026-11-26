#ifndef BLOWINGLEAVESTRIGGER_H
#define BLOWINGLEAVESTRIGGER_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; BlowingLeavesTrigger adds its fields from 0x190 on.
class BlowingLeavesTrigger : public EntityBaseClass {
public:
    BlowingLeavesTrigger();
    virtual ~BlowingLeavesTrigger();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    int m_unk1B0;               // 0x1B0 editable-vars block (0x18 bytes); SetEditableVars memcpys it here
    float m_unk1B4;             // 0x1B4 divisor for the leaf wind strength
    float m_unk1B8[3];          // 0x1B8 trigger position
    float m_unk1C4;             // 0x1C4 trigger radius
    unsigned char m_unk1C8;     // 0x1C8 set once the wind state has been applied
};

#endif
