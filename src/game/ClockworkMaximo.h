#ifndef CLOCKWORKMAXIMO_H
#define CLOCKWORKMAXIMO_H

#include "types.h"

// ClockworkMaximo derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class EntityBaseClass;
class Shield;

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
    void DetachWeapon(WEAPON_TYPE arg0);
    void UpdateShieldStatus(Shield *arg0);
    bool TargetFacingUs();
    bool FacingTarget(EntityBaseClass *arg0);
    bool IsMoving();
    bool StopMoving();
    ClockworkMaximo *GetTarget();
    bool FaceTarget(float arg0);
    bool InBlockableState();
    void SetDefaultVars();

    char _pad000[0x1B];
    unsigned char m_unk1B;          // 0x01B
    char _pad01C[0x20 - 0x1C];
    int m_unk20;                    // 0x020
    char _pad024[0x38 - 0x24];
    ClockworkMaximoState *m_unk38;  // 0x038
    int m_unk3C;                    // 0x03C
    char _pad040[0x140 - 0x40];
    int m_unk140;                   // 0x140
    char _pad144[0x1B4 - 0x144];
    int m_unk1B4;                   // 0x1B4
    int m_unk1B8;                   // 0x1B8
    int m_unk1BC;                   // 0x1BC
    int m_unk1C0;                   // 0x1C0
    int m_unk1C4;                   // 0x1C4
    char _pad1C8[0x1D4 - 0x1C8];
    int m_unk1D4;                   // 0x1D4
    int m_unk1D8;                   // 0x1D8
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;                   // 0x1E0
    int m_unk1E4;                   // 0x1E4
    int m_unk1E8;                   // 0x1E8
    char _pad1EC[0x240 - 0x1EC];
    int m_unk240;                   // 0x240
    char _pad244[0x24C - 0x244];
    int m_unk24C;                   // 0x24C
    unsigned int m_unk250;          // 0x250
    int m_unk254;                   // 0x254
    char _pad258[0x260 - 0x258];
    unsigned char m_unk260;         // 0x260
    char _pad261[0x274 - 0x261];
    int m_unk274;                   // 0x274
    int m_unk278;                   // 0x278
    char m_unk27C;                  // 0x27C
    Shield *m_unk280;               // 0x280
};

#endif
