#ifndef CLOCKWORKMAXIMO_H
#define CLOCKWORKMAXIMO_H

#include "types.h"

// ClockworkMaximo derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class EntityBaseClass;

class ClockworkMaximoState {
public:
    char _pad000[0xE8];
    unsigned int m_unkE8;   // 0x0E8
    unsigned int m_unkEC;   // 0x0EC
    char _pad0F0[0x108 - 0xF0];
    int m_unk108;           // 0x108
};

class ClockworkMaximo {
public:
    enum WEAPON_TYPE {
        WEAPON_TYPE_0 = 0,
        WEAPON_TYPE_1 = 1,
        WEAPON_TYPE_2 = 2
    };

    void FootStepSound(unsigned int arg0);
    int DetermineIdleState();
    void OnWakeEvent();
    void OnTimerEvent(unsigned int arg0);
    void OnAttackEvent(EntityBaseClass *arg0, int arg1);
    void AttachWeapon(WEAPON_TYPE arg0);

    char _pad000[0x20];
    int m_unk20;                    // 0x020
    char _pad024[0x38 - 0x24];
    ClockworkMaximoState *m_unk38;  // 0x038
    int m_unk3C;                    // 0x03C
    char _pad040[0x1E4 - 0x40];
    int m_unk1E4;                   // 0x1E4
    int m_unk1E8;                   // 0x1E8
    char _pad1EC[0x274 - 0x1EC];
    int m_unk274;                   // 0x274
    int m_unk278;                   // 0x278
    char m_unk27C;                  // 0x27C
};

#endif
