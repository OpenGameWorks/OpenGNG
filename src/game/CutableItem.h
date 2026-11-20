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
    void SetEditableVars(char *pArg);
    void OnTouchEvent(EntityBaseClass *pArg);
    const char *GetClassName();

    void *m_unk0;                   // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                    // 0x020 state, compared against 3 by OnTouchEvent
    char _pad024[0x3C - 0x24];
    void *m_unk3C;                  // 0x03C object whose byte at +0x3F holds the 3-bit state
    char _pad040[0x1B0 - 0x40];
    int m_unk1B0;                   // 0x1B0 item index into ItemTable (36-byte records); the 0x10-byte editable block starts here
    char _pad1B4[0x10 - 0x04];
};

#endif
