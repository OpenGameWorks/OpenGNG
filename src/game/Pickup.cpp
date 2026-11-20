#include "types.h"
#include "Pickup.h"
#include "EntityBaseClass.h"
#include "PResourceManager.h"
#include "PMeshNode.h"
#include "PArray.h"

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
extern void *mpEntMgr__15EntityBaseClass;
extern PArray mTempArray__15EntityBaseClass;
extern "C" void GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(void *pThis, int nLoadClass, PArray *pList, float (*pBox)[4], float fRadius, int nFilter, bool bA, bool bB);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" float sinf(float x);
extern "C" float cosf(float x);

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

// DRAFT: 0x0019D020 SoulSuckerInRange__6PickupFv
// note: 10-word diff; count reload at bottom test uses v0 (orig v1), sltu source reg, return-0 daddu not in bnez delay slot; tried while/ternary forms, (0<x)!=0 wrap, local bool.
int Pickup::SoulSuckerInRange() {
    float (*pBox)[4];
    if (mTempArray__15EntityBaseClass.m_unk8 != 0) {
        mTempArray__15EntityBaseClass.m_unk0 = 0;
        mTempArray__15EntityBaseClass.m_unk4 = 0;
    }
    if (this->m_unk3C != 0) {
        pBox = (float (*)[4])((char *)this->m_unk3C + 0x80);
    } else {
        pBox = (float (*)[4])&this->m_unk190;
    }
    GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, &mTempArray__15EntityBaseClass, pBox, 17.0f, 0x6B, true, false);
    while ((0 < mTempArray__15EntityBaseClass.m_unk0) != 0) {
        int bHas = (0 < mTempArray__15EntityBaseClass.m_unk0) != 0;
        ApparitionIsValid__15EntityBaseClassFUi(bHas ? (unsigned int)mTempArray__15EntityBaseClass.m_unk8[0] : 0U);
        return 1;
    }
    return 0;
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

// FUNCTION: 0x0019D140 SetDefaultVars__6PickupFv
void Pickup::SetDefaultVars() {
    this->m_unk1B0 = 0;
    this->m_unk1B4 = 1;
    this->m_unk1B8 = 0;
    this->m_unk1BC = 0;
    this->m_unk1C0 = 0;
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

// DRAFT: 0x0019D200 OnTouchEvent__6PickupFP15EntityBaseClass
// note: 36-word diff; original tests type 5 before 3 and branches forward into the record block (ours bnez/bne sense differs); switch dispatch 3/5 with shared tail beats else-if (41); testing 5 first gives 45.
void Pickup::OnTouchEvent(EntityBaseClass *arg0) {
    if (this->m_unk1CC == 0) {
        if (this->m_unk1B0 == 0x26) {
            if (*(int *)((char *)arg0 + 8) == 5 && *(int *)(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x210) == 1) {
                ((EntityBaseClass *)this)->SetState(2);
            }
        } else if (this->m_unk1B0 != 0x25) {
            switch (*(int *)((char *)arg0 + 8)) {
            case 3:
                goto tail;
            case 5: {
                signed char *pRec = PickUpData + this->m_unk1B0 * 24 + 1;
                if (*pRec == 4) {
                    goto tail;
                }
                if (*pRec == 3) {
                    if (*(int *)(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x210) == 1) {
                        goto tail;
                    }
                }
                break;
            }
            }
            return;
tail:
            if (this->m_unk20 != 5) {
                ((EntityBaseClass *)this)->SetState(2);
            }
        }
    }
}

// FUNCTION: 0x0019D310 OnEffectDelete__6PickupFUi
void Pickup::OnEffectDelete(unsigned int arg0) {
    if (arg0 == (unsigned int)this->m_unk234) {
        ((EntityBaseClass *)this)->SetState(-2);
    }
}

// FUNCTION: 0x0019F020 SetBonusVelocity__6PickupFPA4_fPff
void Pickup::SetBonusVelocity(float (*arg0)[4], float *arg1, float arg2) {
    u_long128 tmp;
    float fCos;
    void *pTemp;
    sceVu0AddVector((float *)&tmp, (float *)arg0, arg1);
    pTemp = this->m_unk3C;
    if (pTemp != 0) {
        *(u_long128 *)((char *)pTemp + 0x80) = tmp;
        *(unsigned char *)((char *)pTemp + 0x3E) |= 8;
    } else {
        this->m_unk190 = tmp;
    }
    fCos = cosf(arg2);
    *(float *)((char *)this + 0x1D0) = 0.1f * sinf(arg2);
    *(float *)((char *)this + 0x1D8) = 0.1f * fCos;
    *(int *)((char *)this + 0x1D4) = 0x3ECCCCCD;
    *(int *)((char *)this + 0x1DC) = 0x3F800000;
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
