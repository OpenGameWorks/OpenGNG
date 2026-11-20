#ifndef ANIMSEGMENTTRIGGER_H
#define ANIMSEGMENTTRIGGER_H

#include "types.h"

// AnimSegmentTrigger derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class EntityBaseClass;

class AnimSegmentTrigger {
public:
    int PlayerInsideTriggerVolume();
    int OnHitEvent(EntityBaseClass *pOther, int nArg1, unsigned int nFlags, unsigned int nArg3);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x3C - 0x04];
    char *m_unk3C;              // 0x03C object whose +0x80 matrix is the trigger origin
    char _pad040[0x10C - 0x40];
    int m_unk10C;               // 0x10C flags (bit 25 cleared on apparition)
    char _pad110[0x190 - 0x110];
    float m_unk190[4];          // 0x190 trigger origin matrix row
    char _pad1A0[0x1B0 - 0x1A0];
    float m_unk1B0;             // 0x1B0 trigger range
    float m_unk1B4[4];          // 0x1B4 trigger box
    char _pad1C4[0x1E4 - 0x1C4];
    int m_unk1E4;               // 0x1E4 volume mode selector
    int m_unk1E8;               // 0x1E8 hit state (must be 1)
    char _pad1EC[0x210 - 0x1EC];
    int m_unk210;               // 0x210 apparition flag
    char _pad214[0x22A - 0x214];
    unsigned char m_unk22A;     // 0x22A hit-triggered flag
};

#endif
