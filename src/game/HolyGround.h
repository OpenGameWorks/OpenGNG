#ifndef HOLYGROUND_H
#define HOLYGROUND_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; HolyGround adds its fields from 0x190 on.
// Base-class padding at 0x10C is reached through a (char *)this cast in the .cpp.
class HolyGround : public EntityBaseClass {
public:
    HolyGround();
    virtual ~HolyGround();
    void OnTimerEvent(unsigned int nId);
    int OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB);
    void Execute();
    void CreateRipplesFx();

    float m_unk190[4];          // 0x190
    char _pad1A0[0x4];          // 0x1A0
    float m_unk1A4;             // 0x1A4
    char _pad1A8[0xC];          // 0x1A8..0x1B3
    int m_unk1B4;               // 0x1B4 timer id for the 120-frame timer
    int m_unk1B8;               // 0x1B8 second timer id
    int m_unk1BC;               // 0x1BC sound reference stopped on hit
    void *m_unk1C0;             // 0x1C0
    unsigned char m_unk1C4;     // 0x1C4 set by OnTimerEvent on the first timer
    unsigned char m_unk1C5;     // 0x1C5 set by OnTimerEvent on the second timer
};

#endif
