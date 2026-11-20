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

    unsigned char *m_unk0;  // 0x000 vtable pointer
    char _pad004[0x38 - 0x04];
    void *m_unk38;          // 0x038 Physics object, 0x120 bytes
    PMNode *m_unk3C;        // 0x03C owner node; OrientSpear reads its 0x90 and sets 0x3E bit 0x8
    char _pad040[0x10C - 0x40];
    unsigned int m_unk10C;  // 0x10C flags; OnTouchEvent clears the 0xF8FFFFFF mask
    char _pad110[0x190 - 0x110];
    u_long128 m_unk190;     // 0x190 hit position copied to mHitPos
    u_long128 m_unk1A0;     // 0x1A0 fallback orientation source for OrientSpear
    char _pad1B0[0x1C0 - 0x1B0];
    u_long128 m_unk1C0;     // 0x1C0 orientation copied by OrientSpear
    int m_unk1D0;           // 0x1D0
    int m_unk1D4;           // 0x1D4 zeroed by the ctor before the Physics allocation
};

#endif
