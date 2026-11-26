#ifndef RAINTRIGGER_H
#define RAINTRIGGER_H

#include "types.h"

// RainTrigger derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class RainTrigger {
public:
    void Execute();
    const char *GetClassName();
    void SetEditableVars(char *);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                // 0x020 state selector: -2 idle, -1 reset, 0 watch, 1 apply rain
    char _pad024[0x3C - 0x24];
    char *m_unk3C;              // 0x03C pointer whose +0x80 is the self-side Distance operand
    char _pad040[0x190 - 0x40];
    float m_unk190[4];          // 0x190 position (self-side Distance operand)
    char _pad1A0[0x1B0 - 0x1A0];
    float m_unk1B0;             // 0x1B0 rain density
    int m_unk1B4;               // 0x1B4 rain density flag
    float m_unk1B8;             // 0x1B8 lightning density
    char _pad1BC[0x1C8 - 0x1BC];
    float m_unk1C8;             // 0x1C8 trigger range
    unsigned char m_unk1CC;     // 0x1CC armed flag (set by case 1, cleared when out of range)
};

#endif
