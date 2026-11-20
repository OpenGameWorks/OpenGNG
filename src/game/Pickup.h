#ifndef PICKUP_H
#define PICKUP_H

#include "types.h"

// Pickup entity. Only the fields read or written by the recovered functions are named;
// the rest of the object is kept as padding.
class Pickup {
public:
    void FlyToApparition(unsigned int arg0, float arg1);
    void OnSleepEvent();
    void OnEffectDelete(unsigned int arg0);
    int SetAbilityType(int arg0);
    static signed char GetVarType(int arg0);

    char _pad000[0x20];
    int m_unk20;                    // 0x020 state; 8 selects FlyToApparition
    char _pad024[0x3C - 0x24];
    void *m_unk3C;                  // 0x03C; when non-null, OnSleepEvent copies from +0x80
    char _pad040[0x190 - 0x40];
    u_long128 m_unk190;             // 0x190 16-byte record copied by OnSleepEvent
    char _pad1A0[0x1B0 - 0x1A0];
    int m_unk1B0;                   // 0x1B0 ability index written by SetAbilityType
    char _pad1B4[0x1CE - 0x1B4];
    unsigned char m_unk1CE;         // 0x1CE set to 1 by OnSleepEvent
    char _pad1CF[0x22C - 0x1CF];
    unsigned int m_unk22C;          // 0x22C target id stored by FlyToApparition
    float m_unk230;                 // 0x230 float stored by FlyToApparition
    int m_unk234;                   // 0x234 handle compared by OnEffectDelete
};

#endif
