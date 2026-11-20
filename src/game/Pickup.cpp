#include "types.h"
#include "Pickup.h"
#include "EntityBaseClass.h"
#include "PResourceManager.h"
#include "PMeshNode.h"

// TODO(header): foreign declarations
extern PResourceManager *mpResMgr__15EntityBaseClass;
// PickUpData is a local data table of 24-byte records (936 bytes) read by SetAbilityType and GetVarType.
extern signed char PickUpData[936];
extern float gUnitMatrix[16];
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" int printf(const char *fmt, ...);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern unsigned char __vt__6Pickup[];

// FUNCTION: 0x0019CF40 __dt__6PickupFv
Pickup::~Pickup() {
    this->m_unk0 = __vt__6Pickup;
    __dt__15EntityBaseClassFv(this, 0);
}

// FUNCTION: 0x0019CFE0 FlyToApparition__6PickupFUif
void Pickup::FlyToApparition(unsigned int arg0, float arg1) {
    if (this->m_unk20 == 8) {
        this->m_unk22C = arg0;
        this->m_unk230 = arg1;
        ((EntityBaseClass *)this)->SetState(0xD);
    }
}

// DRAFT: 0x0019D0D0 AdjustPickupBox__6PickupFv
// note: 21-word diff; original enters the loop with a `b` to the bottom test that for-loop, do-while and while forms do not emit (constant 0<1 folded); outer pNode and byte-offset induction variants tried too.
void Pickup::AdjustPickupBox() {
    static unsigned int MeshTable[1] = { 0x810000A2 };
    PMNode *pNode;
    int i;
    for (i = 0; i < 1; i++) {
        pNode = mpResMgr__15EntityBaseClass->GetResource(MeshTable[i], true);
        if (pNode != 0) {
            ((PMeshNode *)pNode)->AdjustPickup();
        }
    }
}

// FUNCTION: 0x0019D160 SetEditableVars__6PickupFPc
void Pickup::SetEditableVars(char *arg0) {
    memcpy(&this->m_unk1B0, arg0, 0x14);
    if (PickUpData[this->m_unk1B0 * 24] == 0) {
        printf("\nInvalid pickup type found\n", this->m_unk1B0);
        ((EntityBaseClass *)this)->SetState(-2);
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

// FUNCTION: 0x0019F120 GetPickupData__6PickupFi
void *Pickup::GetPickupData(int arg0) {
    if (arg0 < 0) {
        CdsAssert__FPciPc("Pickup.cpp", 0x16E, "iType >= 0");
    }
    if (arg0 >= 0x27) {
        CdsAssert__FPciPc("Pickup.cpp", 0x16F, "iType < PICKUP_MAX");
    }
    return &PickUpData[arg0 * 24];
}

// FUNCTION: 0x0019F1A0 GetVarType__6PickupFi
signed char Pickup::GetVarType(int arg0) {  // static: no this in a0
    return PickUpData[arg0 * 24 + 1];
}

// FUNCTION: 0x0019F1C0 __ct__6PickupFv
Pickup::Pickup() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 1, 0);
    this->m_unk0 = __vt__6Pickup;
    this->m_unk1D0 = *(u_long128 *)gUnitMatrix;
    this->m_unk1ED = 0;
    this->m_unk1F0 = 0;
    this->m_unk1EE = 0;
    this->m_unk1EC = 0;
    this->m_unk1CD = 0;
    this->m_unk1C4 = 0;
    this->m_unk1CC = 0x14;
    this->m_unk1C8 = 0;
    this->m_unk20A = 0x800;
    if (this->m_unk18 == 0) {
        this->m_unk1B4 = 1;
    }
    this->m_unk1CF = 1;
    this->m_unk200 = 0;
    this->m_unk1CE = 0;
    this->m_unk1E0 = 1;
    this->m_unk1E4 = 0;
    this->m_unk234 = 0;
}
