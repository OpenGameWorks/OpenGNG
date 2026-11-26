#ifndef SAVEPOINT_H
#define SAVEPOINT_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; SavePoint adds its fields from 0x190 on.
class SavePoint : public EntityBaseClass {
public:
    void OnTimerEvent(unsigned int nTimer);
    SavePoint();
    virtual ~SavePoint();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();
    int NeedsToBeWoken();
    int GetWokenVarPos();

    float m_unk190[4];          // 0x190 position passed to SetHolyGround
    char _pad1A0[0x4];
    float m_unk1A4;             // 0x1A4 radius passed to SetHolyGround
    char _pad1A8[0x8];
    unsigned int m_unk1B0;      // 0x1B0 timer id
    unsigned char m_unk1B4;     // 0x1B4 set when the timer fires
    char _pad1B5[0x3];
    int m_unk1B8;               // 0x1B8 editable-vars block; SetEditableVars memcpys 0x8 bytes here
    int m_unk1BC;               // 0x1BC second word of the editable-vars block
};

#endif
