#ifndef BREAKABLEITEM_H
#define BREAKABLEITEM_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; BreakableItem adds its fields from 0x190 on.
class BreakableItem : public EntityBaseClass {
public:
    BreakableItem();
    virtual ~BreakableItem();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    int OnHitEvent(EntityBaseClass *pArg, int nHit, unsigned int nFlagsA, unsigned int nFlagsB);
    void Execute();

    char _pad190[0x1B0 - 0x190];
    int m_unk1B0;               // 0x1B0 editable-vars block (0xC bytes); its first word is the type index
    float m_unk1B4;             // 0x1B4 distance threshold
    int m_unk1B8;               // 0x1B8
    int m_unk1BC;               // 0x1BC hit counter, set to 0x78 by the constructor
    unsigned int m_unk1C0;      // 0x1C0 state, 0..2 after a hit
    unsigned char m_unk1C4;     // 0x1C4 cleared by the constructor
    unsigned char m_unk1C5;     // 0x1C5 cleared by the constructor, set once a hit has been handled
};

#endif
