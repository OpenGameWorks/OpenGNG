#ifndef MUSICSWITCH_H
#define MUSICSWITCH_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; MusicSwitch adds its fields from 0x190 on.
class MusicSwitch : public EntityBaseClass {
public:
    MusicSwitch();
    virtual ~MusicSwitch();
    void Execute();
    const char *GetClassName();
    void OnHitEvent(EntityBaseClass *, int, unsigned int, unsigned int);
    void SetEditableVars(char *);

    char _pad190[0x20];
    float m_unk1B0;             // 0x1B0
    float m_unk1B4;             // 0x1B4
    unsigned int m_unk1B8;      // 0x1B8
    unsigned int m_unk1BC;      // 0x1BC
    unsigned int m_unk1C0;      // 0x1C0 range-checked against 3..0x20 in Execute
    int m_unk1C4;               // 0x1C4
    int m_unk1C8;               // 0x1C8
    int m_unk1CC;               // 0x1CC
    float m_unk1D0;             // 0x1D0
    char _pad1D4[0xC];          // 0x1D4..0x1DF
    float m_unk1E0;             // 0x1E0
    char _pad1E4[0xC];          // 0x1E4..0x1EF
    float m_unk1F0;             // 0x1F0
    char _pad1F4[0xC];          // 0x1F4..0x1FF
    float m_unk200;             // 0x200
    unsigned int m_unk204;      // 0x204
};

#endif
