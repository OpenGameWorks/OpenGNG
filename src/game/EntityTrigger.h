#ifndef ENTITYTRIGGER_H
#define ENTITYTRIGGER_H

#include "types.h"

// EntityTrigger derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class EntityBaseClass;

class EntityTrigger {
public:
    void Execute();

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                // 0x020 state selector: -2 idle, -1 watch, 0 fire
    char _pad024[0x3C - 0x24];
    char *m_unk3C;              // 0x03C linked entity, position at +0x80 when set
    char _pad040[0x190 - 0x40];
    float m_unk190[4];          // 0x190 own position (Distance operand)
    char _pad1A0[0x1B0 - 0x1A0];
    float m_unk1B0;             // 0x1B0 trigger range
    int m_unk1B4;               // 0x1B4 saved slot 0 handle, copied to m_unk1D8
    int m_unk1B8;               // 0x1B8 saved slot 1 handle, copied to m_unk1DC
    int m_unk1BC;               // 0x1BC saved slot 2 handle, copied to m_unk1E0
    int m_unk1C0;               // 0x1C0 saved slot 3 handle, copied to m_unk1E4
    int m_unk1C4;               // 0x1C4 saved slot 4 handle, copied to m_unk1E8
    int m_unk1C8;               // 0x1C8 saved slot 5 handle, copied to m_unk1EC
    int m_unk1CC;               // 0x1CC saved slot 6 handle, copied to m_unk1F0
    int m_unk1D0;               // 0x1D0 saved slot 7 handle, copied to m_unk1F4
    unsigned int m_unk1D4;      // 0x1D4 cut camera ID (0 = none)
    int m_unk1D8[4];            // 0x1D8 live handles (instance flagged by Execute)
    int m_unk1E8[4];            // 0x1E8 destroy handles
};

#endif
