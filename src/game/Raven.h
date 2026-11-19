#ifndef RAVEN_H
#define RAVEN_H

#include "types.h"

// Raven derives from EntityBaseClass at offset 0; the base is not declared here,
// so every member is named by its offset from the object start.
class EntityBaseClass;
class PMNode;

class Raven {
public:
    Raven();
    void OutputDebug();
    void OnTimerEvent(unsigned int nId);
    int OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB);

    void *m_unk0;                   // 0x000 vtable pointer (__vt__5Raven)
    char _pad004[0x3C - 0x04];
    PMNode *m_unk3C;                // 0x03C
    char _pad040[0xEB - 0x40];
    signed char m_unkEB;            // 0x0EB
    char _pad0EC[0x10C - 0xEC];
    int m_unk10C;                   // 0x10C
    char _pad110[0x1C0 - 0x110];
    int m_unk1C0;                   // 0x1C0
    char _pad1C4[0x1C5 - 0x1C4];
    signed char m_unk1C5;           // 0x1C5
    signed char m_unk1C6;           // 0x1C6
    signed char m_unk1C7;           // 0x1C7
    int m_unk1C8;                   // 0x1C8
    char _pad1CC[0x244 - 0x1CC];
    int m_unk244;                   // 0x244
    char _pad248[0x250 - 0x248];
    int m_unk250;                   // 0x250
    char _pad254[0x258 - 0x254];
    int m_unk258;                   // 0x258
    int m_unk25C;                   // 0x25C
};

#endif
