// FLAGS: -str readonly
#include "ClockworkMaximo.h"
#include "types.h"

// TODO(header): foreign declarations
// Leading virtuals of ClockworkMaximo's vtable (__vt__15ClockworkMaximo); a call
// through this view loads the slot into $t9 as the original's virtual calls do.
class PLightManager;
class ClockworkMaximoVirtuals {
public:
    virtual ~ClockworkMaximoVirtuals();
    virtual int GetTallyType();
    virtual void Execute();
    virtual void OutputDebug();
    virtual char *GetClassName();
    virtual void SetEditableVars(char *);
    virtual void SetDefaultVars();
    virtual void OnTimerEvent(unsigned int);
    virtual void Render(PLightManager *);
    virtual void Animate(int, float);
    virtual void SetInnocentInstanceID(unsigned int);
};
class EntityBaseClass {
public:
    void PlaySoundOnFrame(unsigned int arg0, unsigned int arg1);

    char _pad000[8];
    int m_unk8;             // 0x008
};

class MathAPI {
public:
    static int RandomIntRange(int arg0, int arg1);
};

extern unsigned int FootSound[8];
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern "C" int FacingPoint__7MathAPIFP15EntityBaseClassPA4_ff(void *, void *, float);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern char CMaximo_RunSeq[0x40];
extern char CMaximo_WalkSeq[0x40];
extern char CMaximo_HammerRunSeq[0x40];
extern char CMaximo_HammerWalkSeq[0x40];
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void __dt__15EntityBaseClassFv(void *, short);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__15ClockworkMaximo[0x40];
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern MathAPI *mPlayerAPI__13EntityManager;
extern "C" void *Spawn__13EntityManagerFUibi(void *, unsigned int, bool, int);
extern "C" void InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(void *, int, float (*)[4], float (*)[4], float (*)[4]);
extern void *mpEntMgr__15EntityBaseClass;
extern "C" void *Find__6PMNodeFUi(void *, unsigned int);
extern "C" void BuildDispList__9PSkeletonFv(void *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);

// Slot numbers are declaration order; Slot13 is the call at vtable offset 0x3C.
class VirtualSlots {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual int Slot13();
};

// FUNCTION: 0x00210520 StopMoving__15ClockworkMaximoFv
bool ClockworkMaximo::StopMoving() {
    bool moving = IsMoving();
    if (moving) {
        m_unk254 = m_unk20;
        m_unk260 = m_unk1B;
        EnableSleep__15EntityBaseClassFbb(this, false, false);
        SetState__15EntityBaseClassFi(this, 0x21);
    }
    return moving;
}

// FUNCTION: 0x00210590 IsMoving__15ClockworkMaximoFv
bool ClockworkMaximo::IsMoving() {
    return (m_unk140 == (int)CMaximo_RunSeq) || (m_unk140 == (int)CMaximo_WalkSeq) ||
           (m_unk140 == (int)CMaximo_HammerRunSeq) || (m_unk140 == (int)CMaximo_HammerWalkSeq);
}

// FUNCTION: 0x00210600 FootStepSound__15ClockworkMaximoFUi
void ClockworkMaximo::FootStepSound(unsigned int arg0) {
    ClockworkMaximoState *temp = m_unk38;
    unsigned int snd;

    if (temp->m_unk108 & 0x200) {
        snd = 0x4E25;
    } else {
        snd = FootSound[(temp->m_unkE8 >> 11) & 7];
    }
    ((EntityBaseClass *)this)->PlaySoundOnFrame(snd, arg0);
}

// FUNCTION: 0x002107A0 UpdateShieldStatus__15ClockworkMaximoFP6Shield
void ClockworkMaximo::UpdateShieldStatus(Shield *arg0) {
    if (((VirtualSlots *)this)->Slot13() != 0) {
        if (arg0 != 0) {
            DetachWeapon(WEAPON_TYPE_1);
        } else {
            AttachWeapon(WEAPON_TYPE_1);
        }
        if (arg0 == 0 && m_unk280 != 0) {
            SetState__15EntityBaseClassFi(this, 0x11);
        }
    }
    m_unk280 = arg0;
}

// FUNCTION: 0x00210A40 SetShockwave__15ClockworkMaximoFv
void ClockworkMaximo::SetShockwave() {
    int pNode = m_unk3C;
    if (pNode == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA59, "pNode");
    }
    void *pPrj;
    float (*pVel)[4] = (float (*)[4])(pNode + 0x80);
    float (*pPos)[4] = (float (*)[4])(pNode + 0x90);
    pPrj = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x2D, false, 0);
    if (pPrj == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA5F, "pPrj");
    }
    InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(pPrj, 0x1E, pVel, pPos, 0);
}

// FUNCTION: 0x00210AF0 DetachWeapon__15ClockworkMaximoFQ215ClockworkMaximo11WEAPON_TYPE
void ClockworkMaximo::DetachWeapon(WEAPON_TYPE arg0) {
    int pNode = m_unk3C;
    unsigned int var;
    if (pNode == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA36, "apSkeleton");
    }
    switch (arg0) {
    case WEAPON_TYPE_0:
        var = 0xB5714B5A;
        break;
    case WEAPON_TYPE_2:
        var = 0xB5714B5A;
        break;
    case WEAPON_TYPE_1:
        var = 0x6499DC24;
        break;
    default:
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA47, "FALSE");
        break;
    }
    void *pBone = Find__6PMNodeFUi((void *)pNode, var);
    if (pBone == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA4F, "apBone");
    }
    *(int *)((char *)pBone + 0x10) = 0;
    *(unsigned char *)((char *)pBone + 0x3E) &= 0xEF;
    BuildDispList__9PSkeletonFv((void *)pNode);
}

// FUNCTION: 0x00210D70 TargetFacingUs__15ClockworkMaximoFv
bool ClockworkMaximo::TargetFacingUs() {
    ClockworkMaximo *target = GetTarget();
    if (target == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x9F3, "apTarget");
    }
    int m3C = m_unk3C;
    void *a1 = (char *)this + 0x190;
    if (m3C != 0) {
        a1 = (void *)(m3C + 0x80);
    }
    if (FacingPoint__7MathAPIFP15EntityBaseClassPA4_ff(target, a1, 60.0f) != 0) {
        return true;
    }
    return false;
}

// FUNCTION: 0x00210DF0 FacingTarget__15ClockworkMaximoFP15EntityBaseClass
bool ClockworkMaximo::FacingTarget(EntityBaseClass *arg0) {
    if (arg0 == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x9E3, "thepTarget");
    }
    int m3C = *(int *)((char *)arg0 + 0x3C);
    void *a1 = (char *)arg0 + 0x190;
    if (m3C != 0) {
        a1 = (void *)(m3C + 0x80);
    }
    if (FacingPoint__7MathAPIFP15EntityBaseClassPA4_ff(this, a1, 60.0f) != 0) {
        return true;
    }
    return false;
}

// FUNCTION: 0x002110F0 FaceTarget__15ClockworkMaximoFf
bool ClockworkMaximo::FaceTarget(float arg0) {
    ClockworkMaximo *target = GetTarget();
    int m3C = target->m_unk3C;
    void *a1 = (char *)target + 0x190;
    if (m3C != 0) {
        a1 = (void *)(m3C + 0x80);
    }
    float angle = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, a1);
    RotateTo__15EntityBaseClassFff(this, angle, arg0);
    return true;
}


// DRAFT: 0x00211150 InBlockableState__15ClockworkMaximoFv
// note: original is a beq chain on constants in v0 with unsorted case order and a shared v0=1 exit; switch sorts cases, 11 words differ. Tried value ||, if-chain, condition ||, int return with 1/0: 18-25 words.
bool ClockworkMaximo::InBlockableState() {
    switch (m_unk20) {
    case 3:
    case 0xD:
    case 2:
    case 1:
    case 0:
    case 4:
        return true;
    default:
        return false;
    }
}

// FUNCTION: 0x002112C0 GetTarget__15ClockworkMaximoFv
ClockworkMaximo *ClockworkMaximo::GetTarget() {
    VirtualSlots *target = 0;
    if (m_unk24C != 0) {
        target = (VirtualSlots *)InstanceIsValid__15EntityBaseClassFUi(m_unk24C);
        if (target == 0 || target->Slot13() == 0) {
            target = 0;
        }
    }
    if (target == 0) {
        target = (VirtualSlots *)mPlayerAPI__13EntityManager;
        if (target == 0) {
            CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x91A, "apTarget");
        }
    }
    return (ClockworkMaximo *)target;
}

// FUNCTION: 0x00211510 DetermineIdleState__15ClockworkMaximoFv
int ClockworkMaximo::DetermineIdleState() {
    m_unk38->m_unkEC = 0x80113FD5;
    return (MathAPI::RandomIntRange(0, 0x64) & 1) != 0;
}

// FUNCTION: 0x00211550 SetSpawnedFromEntity__15ClockworkMaximoFPfPfi
void ClockworkMaximo::SetSpawnedFromEntity(float *arg0, float *arg1, int arg2) {
    m_unk240 = (MathAPI::RandomIntRange(1, 0x64) & 1) ? 0x3DE : 0x429;
    m_unk1C4 = 0x43160000;
    m_unk1C8 = arg0[0];
    m_unk1CC = arg0[1];
    m_unk1D0 = arg0[2];
    m_unk1D4 = 0x43160000;
    m_unk1B4 = 0;
    m_unk1D8 = 0;
    m_unk1E0 = 0;
    m_unk1E4 = MathAPI::RandomIntRange(0, 0x64) & 1;
    m_unk1E8 = MathAPI::RandomIntRange(0, 0x64) & 1;
    u_long128 *pDst = &m_unk190;
    if (m_unk3C != 0) {
        pDst = (u_long128 *)(m_unk3C + 0x80);
    }
    *pDst = *(u_long128 *)arg0;
    if (arg1 != 0) {
        u_long128 *pDst2 = &m_unk1A0;
        if (m_unk3C != 0) {
            pDst2 = (u_long128 *)(m_unk3C + 0x90);
        }
        *pDst2 = *(u_long128 *)arg1;
    }
    ((ClockworkMaximoVirtuals *)this)->SetInnocentInstanceID(0);
}

// FUNCTION: 0x00211650 SetDefaultVars__15ClockworkMaximoFv
void ClockworkMaximo::SetDefaultVars() {
    m_unk240 = (MathAPI::RandomIntRange(1, 0x64) & 1) ? 0x3DE : 0x429;
    m_unk1B8 = 0;
    m_unk1BC = 0;
    m_unk1C0 = 0;
    m_unk1C4 = 0x41C80000;
    m_unk1D4 = 0x41C80000;
    m_unk1B4 = 0;
    m_unk1D8 = 0;
    m_unk1E0 = 0;
    m_unk1E4 = MathAPI::RandomIntRange(0, 0x64) & 1;
    m_unk1E8 = MathAPI::RandomIntRange(0, 0x64) & 1;
}

// DRAFT: 0x002116E0 SetEditableVars__15ClockworkMaximoFPc
// note: ternary, chain and call match; literal test emits xor/sltiu/bnez not sltu/xori/bnez; 8 forms tried (nested pMsg best, 23 lines).
void ClockworkMaximo::SetEditableVars(char *arg0) {
    char *pMsg;
    int bNull;
    memcpy(_pad1B0, arg0, 0x3C);
    m_unk240 = (MathAPI::RandomIntRange(1, 0x64) & 1) ? 0x3DE : 0x429;
    if (m_unk1E0 != 8 && m_unk1E0 != 7 && m_unk1E0 != 0) {
        pMsg = "Invalid m_iSpawnsKey in ClockworkMaximo.\n";
        bNull = pMsg == 0;
        if (!bNull) {
            CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x882, "!\"Invalid m_iSpawnsKey in ClockworkMaximo.\\n\"");
        }
    }
}

// DRAFT: 0x00211780 OnWakeEvent__15ClockworkMaximoFv
// note: ternary compiles to branches, not movz; load order differs. Tried local-variable form: same 15 lines.
void ClockworkMaximo::OnWakeEvent() {
    if (m_unk3C != 0) {
        AttachWeapon((m_unk1E4 == 0) ? WEAPON_TYPE_0 : WEAPON_TYPE_2);
        if (m_unk1E8 != 0) {
            AttachWeapon(WEAPON_TYPE_1);
        }
    }
}

// FUNCTION: 0x002117D0 OnTimerEvent__15ClockworkMaximoFUi
void ClockworkMaximo::OnTimerEvent(unsigned int arg0) {
    if (arg0 == (unsigned int)m_unk274) {
        m_unk274 = 0;
        return;
    }
    if (arg0 == (unsigned int)m_unk278) {
        m_unk278 = 0;
    }
}

// DRAFT: 0x00211C50 OnAttackEvent__15ClockworkMaximoFP15EntityBaseClassi
// note: branch layout differs (original uses beq/b to shared exit, ours bne); positive form 15 lines, explicit else-return 17 lines.
void ClockworkMaximo::OnAttackEvent(EntityBaseClass *arg0, int arg1) {
    int t;

    if (arg0 != 0) {
        t = arg0->m_unk8;
        if (t == 0x48 || t == 3) {
            t = m_unk20;
            m_unk27C = (t == 0x18) || (t == 0xE);
        }
    }
}

// FUNCTION: 0x00213C20 __dt__15ClockworkMaximoFv
extern "C" void *__dt__15ClockworkMaximoFv(ClockworkMaximo *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__15ClockworkMaximo;
        DestroyDamageFx__15EntityBaseClassFUi(pThis, pThis->m_unk250);
        pThis->m_unk250 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00213C90 __ct__15ClockworkMaximoFv
ClockworkMaximo::ClockworkMaximo() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 0U);
    m_unk0 = __vt__15ClockworkMaximo;
    m_unk240 = 0;
    m_unk258 = 0;
    m_unk250 = 0;
    m_unk280 = 0;
    m_unk264 = 0;
    m_unk284 = 0;
    m_unk288 = 0;
    m_unk25C = -1;
    m_unk274 = 0;
    m_unk278 = 0;
    m_unk28F = 0;
    m_unk28C = 0;
    m_unk28D = 0;
    m_unk28E = 0;
    m_unk27C = 0;
    m_unk260 = m_unk1B;
    m_unk290 = 0;
    m_unk166 = 1;
    ((ClockworkMaximoVirtuals *)this)->SetInnocentInstanceID(0);
    m_unkF8 = 0x3F000000;
    m_unkFC = 0x3F400000;
}
