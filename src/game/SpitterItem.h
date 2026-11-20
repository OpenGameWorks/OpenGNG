#ifndef SPITTERITEM_H
#define SPITTERITEM_H

#include "types.h"

class EntityBaseClass;
class Physics;
struct tagWaypointGroup;

// Filler for an embedded gap. Its declared destructor makes the constructor keep
// `this` on the stack, as the original constructor does.
struct SpitterItemGap {
    ~SpitterItemGap() {}
    char _bytes[0xD0];
};

// SpitterItem entity. It is not derived from EntityBaseClass in the header; the
// base object is reached through a cast. Only the fields read by the recovered
// functions are named, the rest of the object is kept as padding.
class SpitterItem {
public:
    SpitterItem();
    int GetNextPosition(float (&rOut)[4]);
    void OnHitEvent(EntityBaseClass *pArg, int nType, unsigned int nA, unsigned int nB);
    void OnAttackEvent(EntityBaseClass *pArg, int nType);
    void SpitterItemBounceOff();

    void *m_unk0;                   // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                    // 0x020 state, compared against 3 by OnHitEvent
    char _pad024[0x38 - 0x24];
    Physics *m_unk38;               // 0x038 heap-allocated Physics object (0x120 bytes)
    SpitterItemGap _pad03C;
    int m_unk10C;                   // 0x10C word; OnHitEvent clears bits 24..26 of it
    char _pad110[0x1B4 - 0x110];
    int m_unk1B4;                   // 0x1B4 set to 0xB4 by SpitterItemBounceOff
    int m_unk1B8;                   // 0x1B8 compared against 2 by OnHitEvent
    int m_unk1BC;                   // 0x1BC set to 1 by SpitterItemBounceOff
    char _pad1C0[0x1E0 - 0x1C0];
    int m_unk1E0;                   // 0x1E0 set to -1 by the constructor
    unsigned int m_unk1E4;          // 0x1E4 waypoint index, advanced by GetNextPosition
    char _pad1E8[0x200 - 0x1E8];
    float m_unk200;                 // 0x200 bounce speed scale, read by SpitterItemBounceOff
    struct tagWaypointGroup *m_unk204; // 0x204 waypoint group
};

#endif
