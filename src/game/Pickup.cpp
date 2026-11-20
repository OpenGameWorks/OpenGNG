#include "types.h"
#include "Pickup.h"
#include "EntityBaseClass.h"

// TODO(header): foreign declarations
// PickUpData is a local data table of 24-byte records (936 bytes) read by SetAbilityType and GetVarType.
extern signed char PickUpData[936];

// FUNCTION: 0x0019CFE0 FlyToApparition__6PickupFUif
void Pickup::FlyToApparition(unsigned int arg0, float arg1) {
    if (this->m_unk20 == 8) {
        this->m_unk22C = arg0;
        this->m_unk230 = arg1;
        ((EntityBaseClass *)this)->SetState(0xD);
    }
}

// FUNCTION: 0x0019D1D0 OnSleepEvent__6PickupFv
void Pickup::OnSleepEvent() {
    u_long128 *src;
    this->m_unk1CE = 1;
    if (this->m_unk3C != 0) {
        src = (u_long128 *)((char *)this->m_unk3C + 0x80);
    } else {
        src = &this->m_unk190;
    }
    this->m_unk190 = *src;
}

// FUNCTION: 0x0019D310 OnEffectDelete__6PickupFUi
void Pickup::OnEffectDelete(unsigned int arg0) {
    if (arg0 == (unsigned int)this->m_unk234) {
        ((EntityBaseClass *)this)->SetState(-2);
    }
}

// FUNCTION: 0x0019F0D0 SetAbilityType__6PickupFi
int Pickup::SetAbilityType(int arg0) {
    unsigned int i;
    for (i = 0; i < 0x27; i++) {
        if (arg0 == PickUpData[i * 24 + 4]) {
            this->m_unk1B0 = i;
            return 1;
        }
    }
    this->m_unk1B0 = 0;
    return 0;
}

// FUNCTION: 0x0019F1A0 GetVarType__6PickupFi
signed char Pickup::GetVarType(int arg0) {  // static: no this in a0
    return PickUpData[arg0 * 24 + 1];
}
