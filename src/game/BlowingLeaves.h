#ifndef BLOWINGLEAVES_H
#define BLOWINGLEAVES_H

#include "types.h"

class BlowingLeavesSubobject {
public:
    ~BlowingLeavesSubobject() {}
    char _pad[0x1B0 - 0x24];
};

// BlowingLeaves derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class BlowingLeaves {
public:
    BlowingLeaves();
    ~BlowingLeaves();
    void Execute();

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                // 0x020 state
    BlowingLeavesSubobject m_unk24;   // 0x024
    int m_unk1B0;               // 0x1B0
    float m_unk1B4;             // 0x1B4
    int m_unk1B8;               // 0x1B8
    char _pad1BC[0x1CC - 0x1BC];
    float m_unk1CC[3];          // 0x1CC
    char _pad1D8[4];
    float m_unk1DC[3];          // 0x1DC
    char _pad1E8[8];
    unsigned int m_unk1F0;      // 0x1F0 handle of the particle system created by CreateBlowingLeaves
};

#endif
