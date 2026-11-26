// FLAGS: -str readonly
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
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(Physics *pThis, unsigned int nType, float (*pMatrix)[4]);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" int PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nId);
extern "C" int PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pId);
extern "C" signed char ReadApparitionData__15EntityBaseClassFiUi(void *pThis, int nIndex, unsigned int nFlags);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nIndex, char nValue, unsigned int nFlags);
extern "C" int CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(void *pThis, unsigned int nA, unsigned int nB, float (*pA)[4], float (*pB)[4], void *pEntity, float fScale, bool bA, int nC, bool bB);
extern "C" void ScaleSet__6PMNodeFffff(void *pThis, float fA, float fB, float fC, float fD);
extern "C" int CheckDuplicate__6PlayerFi(void *pThis, int nId);
extern "C" int NeedSuperMeter__6PlayerFv(void *pThis);
extern "C" int GameVarSub__6PlayerFUii(void *pThis, unsigned int nId, int nValue);
extern "C" unsigned char mEffectAPI__13EntityManager[0x10];

// FUNCTION: 0x0019CF40 __dt__6PickupFv
Pickup::~Pickup() {
    this->m_unk0 = __vt__6Pickup;
    __dt__15EntityBaseClassFv(this, 0);
}

// FUNCTION: 0x0019CFA0 GetClassName__6PickupFv
const char *Pickup::GetClassName() {
    return "Pickup";
}

// FUNCTION: 0x0019CFB0 GetTallyType__6PickupFv
int Pickup::GetTallyType() {
    return 2;
}

// FUNCTION: 0x0019CFC0 NeedsToBeWoken__6PickupFv
int Pickup::NeedsToBeWoken() {
    return m_unk1BC;
}

// FUNCTION: 0x0019CFD0 GetWokenVarPos__6PickupFv
int Pickup::GetWokenVarPos() {
    return 3;
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
// note: 21-word diff; original enters the loop with a `b` to the bottom test (s0 = 0 in the delay slot) and bumps the offset s1 before the count s0; ours puts the s1 add in the bottom branch's delay slot. Tried: signed/unsigned i (unsigned matches beqz), byte-offset induction in header or body end, for-header increment order; all 21.
void Pickup::AdjustPickupBox() {
    static unsigned int MeshTable[1] = { 0x810000A2 };
    PMNode *pNode;
    unsigned int i;
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

// DRAFT: 0x0019D340 Execute__6PickupFv
// note: cases 0,1,2,7,8,9,10,13 left as break; frame 0x120 vs 0x80 and this kept in s0 vs s2 (locals and register allocation); extra $f20 save; CreateOneshot args 4-7 are placeholders; 1842 words differ.
void Pickup::Execute() {
    int rec;
    void *pPlayer;
    void *pNode;
    if (this->m_unk1B0 == 0xE) {
        pNode = this->m_unk3C;
        if (pNode != 0 && *(float *)((char *)pNode + 0xA0) != 1.5f) {
            ScaleSet__6PMNodeFffff(pNode, 1.5f, 1.5f, 1.5f, 1.0f);
        }
    }
    switch (this->m_unk20) {
    case -1:
        rec = this->m_unk1B0 * 24;
        if (PickUpData[rec] == 0) {
            printf("\nInvalid pickup type found\n");
            ((EntityBaseClass *)this)->SetState(-2);
            return;
        }
        if (PickUpData[rec + 5] != 0 && CheckDuplicate__6PlayerFi(*(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C), PickUpData[rec + 4]) != 0) {
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 2, 0U);
            ((EntityBaseClass *)this)->SetState(-2);
            return;
        }
        if (this->m_unk1B8 != 0 || this->m_unk18 == 0) {
            if (this->m_unk38 == 0) {
                void *pPhys = __nw__FUi(0x120U);
                if (pPhys != 0) {
                    pPhys = __ct__7PhysicsFv(pPhys);
                }
                this->m_unk38 = (Physics *)pPhys;
                if (this->m_unk38 == 0) {
                    CdsAssert__FPciPc("Pickup.cpp", 0x1D0, "mpPhysics");
                }
            }
            SetPhysicsType__7PhysicsFUiPA4_f(this->m_unk38, 0x12U, 0);
            this->m_unk20A = 0x12;
        }
        if (this->m_unk1ED != 0) {
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            this->m_unk10C &= 0xF8FFFFFF;
            this->m_unk103 = 0x10;
            this->m_unk1B4 = 1;
            this->m_unk1EF = 0;
            ((EntityBaseClass *)this)->SetState(4);
            return;
        }
        this->m_unk103 = (this->m_unk18 == 0) ? 0x10 : 0x11;
        if ((unsigned int)this->m_unk1B0 >= 0x27U) {
            CdsAssert__FPciPc("Pickup.cpp", 0x1E5, "mEVars.m_iPickupType < PICKUP_MAX");
        }
        this->m_unk10C |= 0x05000000;
        this->m_unk104 = 0;
        this->m_unk108 = 0;
        if (this->m_unk18 == 0) {
            ((EntityBaseClass *)this)->SetState(0);
            if (PickUpData[this->m_unk1B0 * 24] == -3) {
                this->m_unk1B4 = 0;
            }
            EnableSleep__15EntityBaseClassFbb(this, false, false);
        } else {
            if ((signed char)ReadApparitionData__15EntityBaseClassFiUi(this, 3, 0U) == 1) {
                ((EntityBaseClass *)this)->SetState(5);
                return;
            }
            ((EntityBaseClass *)this)->SetState(1);
        }
        if (this->m_unk1CF == 0) {
            ((EntityBaseClass *)this)->SetState(1);
            this->m_unk1B4 = 0;
        }
        return;
    case 3:
    case 14:
        rec = this->m_unk1B0 * 24;
        PlaySound__15EntityBaseClassFUi(this, *(unsigned int *)(PickUpData + rec + 0x14));
        {
            u_long128 sp80;
            void *pSrc;
            pNode = this->m_unk3C;
            if (pNode != 0) {
                pSrc = (char *)pNode + 0x80;
            } else {
                pSrc = &this->m_unk190;
            }
            sp80 = *(u_long128 *)pSrc;
            ((float *)&sp80)[1] += 2.0f;
            CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib((void *)mEffectAPI__13EntityManager, 0x81000026U, 0x82000061U, (float (*)[4])&sp80, 0, 0, 0.5f, false, 0, false);
        }
        ((EntityBaseClass *)this)->SetState(-2);
        return;
    case 4:
        if (this->m_unkE9 != 0) {
            if (this->m_unk1F0 == 0) {
                ((EntityBaseClass *)this)->SetState(-2);
                return;
            }
            this->m_unk10C &= 0xF8FFFFFF;
            if (this->m_unk1F8 >= 0x27) {
                CdsAssert__FPciPc("Pickup.cpp", 0x554, "m_iPickupTypeFromParent < PICKUP_MAX");
            }
            rec = this->m_unk1F8 * 24;
            *(unsigned int *)((char *)this->m_unk38 + 0x10C) = *(unsigned int *)(PickUpData + rec + 0x10);
            if (this->m_unk1EE != 0) {
                pPlayer = *(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
                if (pPlayer == 0) {
                    CdsAssert__FPciPc("Pickup.cpp", 0x55D, "pPlayer");
                }
                GameVarSub__6PlayerFUii(pPlayer, (unsigned int)PickUpData[rec + 1], (int)PickUpData[rec + 2]);
            }
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)(PickUpData + rec + 0xC));
        }
        pNode = ApparitionIsValid__15EntityBaseClassFUi(this->m_unk1F0);
        this->m_unk1F4 = pNode;
        if (pNode != 0) {
            u_long128 sp110;
            void *pSrc;
            Pickup *pOther = (Pickup *)pNode;
            if (pOther->m_unk3C != 0) {
                pSrc = (char *)pOther->m_unk3C + 0x80;
            } else {
                pSrc = &pOther->m_unk190;
            }
            sp110 = *(u_long128 *)pSrc;
            ((float *)&sp110)[1] -= 1.0f;
            if (this->m_unk3C != 0) {
                *(u_long128 *)((char *)this->m_unk3C + 0x80) = sp110;
                *(unsigned char *)((char *)this->m_unk3C + 0x3E) |= 8;
            } else {
                this->m_unk190 = sp110;
            }
        } else {
            this->m_unk1EF = 1;
        }
        if (this->m_unk1EF != 0) {
            SetPhysicsType__7PhysicsFUiPA4_f(this->m_unk38, 0x12U, 0);
            this->m_unk20A = 0x12;
            *(unsigned int *)((char *)this + 0x1D0) = 0;
            *(unsigned int *)((char *)this + 0x1D4) = 0;
            *(unsigned int *)((char *)this + 0x1D8) = 0;
            *(unsigned int *)this->m_unk38 = *(unsigned int *)((char *)this + 0x1D0);
            this->m_unk10C |= 0x05000000;
            this->m_unk104 = 0x3F333333;
            this->m_unk108 = 0x3F333333;
            this->m_unk1B0 = this->m_unk1F8;
            ((EntityBaseClass *)this)->SetState(1);
        }
        break;
    case 5:
        if (this->m_unk1B0 == 5 && NeedSuperMeter__6PlayerFv(*(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C)) != 0) {
            this->m_unkD2 = 0x80;
            ((EntityBaseClass *)this)->SetState(1);
            return;
        }
        break;
    default:
        break;
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
    this->m_unk1D0 = *(u_long128 *)&gUnitMatrix[12];
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
