#ifndef PICKUP_H
#define PICKUP_H

#include "types.h"

// Pickup entity. Only the fields read or written by the recovered functions are named;
// the rest of the object is kept as padding.
class Pickup {
public:
    Pickup();
    ~Pickup();
    void AdjustPickupBox();
    void SetEditableVars(char *arg0);
    void FlyToApparition(unsigned int arg0, float arg1);
    void OnSleepEvent();
    void OnEffectDelete(unsigned int arg0);
    void SetDefaultVars();
    void SetBonusVelocity(float (*arg0)[4], float *arg1, float arg2);
    int SetAbilityType(int arg0);
    int SoulSuckerInRange();
    void OnTouchEvent(class EntityBaseClass *arg0);
    static signed char GetVarType(int arg0);
    static void *GetPickupData(int arg0);

    void *m_unk0;                   // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x18 - 0x04];
    unsigned char m_unk18;          // 0x018 read by the ctor
    char _pad019[0x20 - 0x19];
    int m_unk20;                    // 0x020 state; 8 selects FlyToApparition
    char _pad024[0x3C - 0x24];
    void *m_unk3C;                  // 0x03C; when non-null, OnSleepEvent copies from +0x80
    char _pad040[0x190 - 0x40];
    u_long128 m_unk190;             // 0x190 16-byte record copied by OnSleepEvent
    char _pad1A0[0x1B0 - 0x1A0];
    int m_unk1B0;                   // 0x1B0 ability index written by SetAbilityType
    int m_unk1B4;                   // 0x1B4 set to 1 by the ctor when m_unk18 is 0
    int m_unk1B8;                   // 0x1B8 cleared by SetDefaultVars
    int m_unk1BC;                   // 0x1BC cleared by SetDefaultVars
    int m_unk1C0;                   // 0x1C0 cleared by SetDefaultVars
    int m_unk1C4;                   // 0x1C4 cleared by the ctor
    int m_unk1C8;                   // 0x1C8 cleared by the ctor
    unsigned char m_unk1CC;         // 0x1CC set to 0x14 by the ctor
    unsigned char m_unk1CD;         // 0x1CD cleared by the ctor
    unsigned char m_unk1CE;         // 0x1CE set to 1 by OnSleepEvent, cleared by the ctor
    unsigned char m_unk1CF;         // 0x1CF set to 1 by the ctor
    u_long128 m_unk1D0;             // 0x1D0 copied from gUnitMatrix by the ctor
    int m_unk1E0;                   // 0x1E0 set to 1 by the ctor
    int m_unk1E4;                   // 0x1E4 cleared by the ctor
    char _pad1E8[0x4];
    unsigned char m_unk1EC;         // 0x1EC cleared by the ctor
    unsigned char m_unk1ED;         // 0x1ED cleared by the ctor
    unsigned char m_unk1EE;         // 0x1EE cleared by the ctor
    char _pad1EF[0x1];
    int m_unk1F0;                   // 0x1F0 cleared by the ctor
    char _pad1F4[0x200 - 0x1F4];
    int m_unk200;                   // 0x200 cleared by the ctor
    char _pad204[0x20A - 0x204];
    short m_unk20A;                 // 0x20A set to 0x800 by the ctor
    char _pad20C[0x22C - 0x20C];
    unsigned int m_unk22C;          // 0x22C target id stored by FlyToApparition
    float m_unk230;                 // 0x230 float stored by FlyToApparition
    int m_unk234;                   // 0x234 handle compared by OnEffectDelete
};

#endif
