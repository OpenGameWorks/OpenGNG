#ifndef CUTABLEITEM_H
#define CUTABLEITEM_H

#include "types.h"

class EntityBaseClass;

// CutableItem entity. It is not derived from EntityBaseClass in the header; the
// base object is reached through a cast. Only the fields read by the recovered
// functions are named, the rest of the object is kept as padding.
class CutableItem {
public:
    CutableItem();
    void Execute();
    void SetEditableVars(char *pArg);
    void OnTouchEvent(EntityBaseClass *pArg);
    int OnHitEvent(EntityBaseClass *pArg, int nHit, unsigned int nFlagsA, unsigned int nFlagsB);
    const char *GetClassName();

    void *m_unk0;                   // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                    // 0x020 state, compared against 3 by OnTouchEvent
    char _pad024[0x38 - 0x24];
    void *m_unk38;                  // 0x038 Physics pointer (inherited from EntityBaseClass)
    void *m_unk3C;                  // 0x03C object whose byte at +0x3F holds the 3-bit state
    char _pad040[0x0E9 - 0x40];
    unsigned char m_unkE9;          // 0x0E9 flag byte
    char _pad0EA[0x10C - 0x0EA];
    int m_unk10C;                   // 0x10C flag word
    char _pad110[0x160 - 0x110];
    unsigned char m_unk160;         // 0x160 flag byte
    char _pad161[0x190 - 0x161];
    char m_unk190[0x10];            // 0x190 16-byte vector
    char _pad1A0[0x1B0 - 0x1A0];
    int m_unk1B0;                   // 0x1B0 item index into ItemTable (36-byte records); the 0x10-byte editable block starts here
    int m_unk1B4;                   // 0x1B4
    int m_unk1B8;                   // 0x1B8
    int m_unk1BC;                   // 0x1BC
};

#endif
