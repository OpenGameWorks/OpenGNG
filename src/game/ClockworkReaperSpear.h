#ifndef CLOCKWORKREAPERSPEAR_H
#define CLOCKWORKREAPERSPEAR_H

#include "types.h"

// ClockworkReaperSpear derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class EntityBaseClass;
class PMNode;

class ClockworkReaperSpear {
public:
    ClockworkReaperSpear();
    void OrientSpear();
    void OnTouchEvent(EntityBaseClass *arg0);
    void Execute();
    const char *GetClassName();

    unsigned char *m_unk0;  // 0x000 vtable pointer
    unsigned int m_unk4;    // 0x004
    char _pad008[0x20 - 0x08];
    int m_unk20;            // 0x020 dispatch selector (a1 of the switch)
    char _pad024[0x38 - 0x24];
    void *m_unk38;          // 0x038 Physics object, 0x120 bytes
    PMNode *m_unk3C;        // 0x03C owner node; OrientSpear reads its 0x90 and sets 0x3E bit 0x8
    char _pad040[0xE9 - 0x40];
    unsigned char m_unkE9;  // 0x0E9 flag gating PlaySound / PlaySequence
    char _pad0EA[0x108 - 0xEA];
    unsigned int m_unk108;  // 0x108
    unsigned int m_unk10C;  // 0x10C flags; OnTouchEvent clears the 0xF8FFFFFF mask
    char _pad110[0x160 - 0x110];
    unsigned char m_unk160; // 0x160 flag tested by the fade case
    char _pad161[0x190 - 0x161];
    u_long128 m_unk190;     // 0x190 hit position copied to mHitPos
    u_long128 m_unk1A0;     // 0x1A0 fallback orientation source for OrientSpear
    char _pad1B0[0x1B4 - 0x1B0];
    float m_unk1B4;         // 0x1B4 compared against 0 in the landing case
    char _pad1B8[0x1C0 - 0x1B8];
    u_long128 m_unk1C0;     // 0x1C0 orientation copied by OrientSpear
    int m_unk1D0;           // 0x1D0
    int m_unk1D4;           // 0x1D4 zeroed by the ctor before the Physics allocation
};

#endif
