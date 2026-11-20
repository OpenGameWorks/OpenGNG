#ifndef MINEABLEITEM_H
#define MINEABLEITEM_H

#include "types.h"

// MineableItem derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class EntityBaseClass;

class MineableItem {
public:
    int OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3);
    void SetEditableVars(char *arg0);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x103 - 0x04];
    unsigned char m_unk103;     // 0x103 set to 0xFF by SetEditableVars
    char _pad104[0x10C - 0x104];
    unsigned int m_unk10C;      // 0x10C flags; bit 0x02000000 set by SetEditableVars, 0x02000000 cleared on hit
    char _pad110[0x1B0 - 0x110];
    int m_unk1B0;               // 0x1B0 editable variable block (16 bytes copied by SetEditableVars)
    int m_unk1B4;               // 0x1B4
    int m_unk1B8;               // 0x1B8 editable time, zero disables the timer reset
    int m_unk1BC;               // 0x1BC timer sequence id
    unsigned int m_unk1C0;      // 0x1C0 hit counter, compared with 3 in OnHitEvent
    unsigned char m_unk1C4;     // 0x1C4 flag
    char _pad1C5[0x1C8 - 0x1C5];
    unsigned int m_unk1C8;      // 0x1C8 last hit type stored by OnHitEvent
};

#endif
