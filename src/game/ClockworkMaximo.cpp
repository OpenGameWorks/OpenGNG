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
    virtual int GetHealth();
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
extern "C" int RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(void *, void *, unsigned int);
extern "C" int FacingPoint__7MathAPIFP15EntityBaseClassPA4_ff(void *, void *, float);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern "C" float Round180__Ff(float);
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
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *, float *);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(float (*)[4], float (*)[4]);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*)[4], float (*)[4]);
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern "C" int GetGroundPos__7MathAPIFPA4_f(void *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void sceVu0AddVector(float *, float *, float *);
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" float sceVu0InnerProduct(float *, float *);
extern "C" float sqrtf(float);
extern "C" void InitShield__6ShieldFP15EntityBaseClassfPA4_fPA4_fUiPbi(void *, void *, float, float (*)[4], float (*)[4], unsigned int, bool *, int);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *, void *);
extern "C" unsigned int CreateDamageFx__15EntityBaseClassFfUi(void *, float, unsigned int);
extern "C" void ChangeDamageFxInterval__15EntityBaseClassFUif(void *, unsigned int, float);
extern "C" float GetFrameTime__6PMNodeFv(void *);
extern char CMaximo_HitOnGroundSeq[0x34];
extern char CMaximo_IdleSeq[0x34];
extern char CMaximo_HammerIdleSeq[0x34];
extern char CMaximo_TauntSeq[0x34];
extern char CMaximo_JumpLaunchSeq[0x3C];
extern char CMaximo_HammerJumpLaunchSeq[0x3C];
extern char CMaximo_JumpAirSeq[0x3C];
extern char CMaximo_HammerJumpAirSeq[0x3C];
extern char CMaximo_JumpLandSeq[0x34];
extern char CMaximo_HammerJumpLandSeq[0x34];
extern char CMaximo_StopWalkSeq[0x34];
extern char CMaximo_StopRunSeq[0x34];
extern char CMaximo_HammerStopWalkSeq[0x34];
extern char CMaximo_IdleLoopSeq[0x34];
extern char CMaximo_HammerIdleLoopSeq[0x34];
extern unsigned int LandSound[8];
extern "C" void SetVelocity__7PhysicsFff(void *, float, float);
extern "C" void RemoveFromAttackSystem__15EntityBaseClassFv(void *);
extern char CMaximo_LoadMeshSeq[20];
extern char CMaximo_ShieldAttackSeq[0x40];
extern char CMaximo_HammerShieldAttackSeq[0x40];
extern char CMaximo_ShieldCatchSeq[0x34];
extern char CMaximo_HammerShieldCatchSeq[0x34];
extern char CMaximo_HitKnockbackSeq[0x34];
extern char CMaximo_HitSeq[0x34];
extern char CMaximo_HammerHitSeq[0x34];
extern char CMaximo_HammerHitKnockbackSeq[0x34];
extern char CMaximo_HitKnockdownSeq[0x3C];
extern char CMaximo_HammerHitKnockdownSeq[0x3C];
extern char CMaximo_SwordBlockSeq[0x34];
extern char CMaximo_HammerBlockSeq[0x34];
extern char CMaximo_BlockHitSeq[0x44];
extern char CMaximo_HammerBlockHitSeq[0x44];
extern char CMaximo_GetUpSeq[0x34];
extern char CMaximo_HammerGetUpSeq[0x34];
extern char CMaximo_AirHitSeq[0x3C];
extern char CMaximo_DiePrecursorSeq[0x3C];
extern char CMaximo_DieSeq[0x4C];
extern char CMaximo_DieOnGroundSeq[0x44];
extern float m_vBonusSpawnOffset[4];
extern "C" void SpawnBonus__15EntityBaseClassFPfii(void *, float *, int, int);
extern char CMaximo_LaunchSeq[0x34];
extern char CMaximo_HammerLaunchSeq[0x34];
extern char CMaximo_JuggleSeq[0x34];
extern char CMaximo_JuggleInAirSeq[0x34];
extern char mTimerAPI__13EntityManager[0x28];
extern "C" int CreateTimer__8TimerAPIFUiUib(void *, unsigned int, unsigned int, bool);
extern "C" unsigned int GetAttackTimeOut__15ClockworkMaximoFv(void *);
extern "C" int printf(const char *, ...);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *, int, char, unsigned int);
extern "C" void PlaySound__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void ScaleSet__6PMNodeFffff(void *, float, float, float, float);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *, unsigned int, float (*)[4]);
extern char CMaximo_SingleSlashAttackSeq[0x48];
extern char CMaximo_360AttackSeq[0x48];
extern char CMaximo_OverheadAttackSeq[0x48];
extern char CMaximo_RingOfPainAttackSeq[0x48];
extern char CMaximo_DoubleSlashAttackSeq[0x48];
extern char CMaximo_HammerSingleSlashAttackSeq[0x40];
extern char CMaximo_HammerDoubleSlashAttackSeq[0x40];
extern char CMaximo_HammerDrillAttackSeq[0x40];
static unsigned char astbComboCheck;

// Physics and Shadow are shells: the size and the constructor are all Execute needs.
class Physics {
public:
    Physics();
    char _pad000[0x120];
};

struct ShadowInner {
    char _pad000[0x18];
    int m_unk18;
};

class Shadow {
public:
    enum ShadowType { SHADOW_TYPE_1 = 1 };
    Shadow(ShadowType arg0, unsigned int arg1);
    int m_unk0;
    char _pad004[8];
    ShadowInner *m_unkC;
};

// Reads an int-typed slot as a float, as the original's lwc1 does.
#define CMF(x) (*(float *)&(x))

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

// FUNCTION: 0x00210650 CanJump__15ClockworkMaximoFPA4_f
int ClockworkMaximo::CanJump(float (*arg0)[4]) {
    float sp60[4];
    float sp70[4];
    float sp80[4];
    float *var_s0;
    float var_f20;
    int temp_v0;
    int var_v1;

    temp_v0 = m_unk3C;
    if (temp_v0 != 0) {
        var_s0 = (float *)(temp_v0 + 0x80);
    } else {
        var_s0 = (float *)&m_unk190;
    }
    for (var_f20 = 3.0f; var_f20 < 10.0f; var_f20 += 1.0f) {
        GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, sp80);
        sceVu0ScaleVector(sp60, sp80, var_f20);
        sceVu0AddVector(sp70, sp60, var_s0);
        sp70[1] += 6.0f;
        if (GetGroundPos__7MathAPIFPA4_f(sp70)) {
            float temp_f1 = var_s0[1];
            float temp_f2 = sp70[1];
            if (!(temp_f2 <= 0.5f + temp_f1)) {
                var_v1 = 1;
                if ((temp_f2 - temp_f1) <= 1.5f) {
                    var_v1 = 0;
                }
                m_unk28C = var_v1;
                *(u_long128 *)arg0 = *(u_long128 *)sp70;
                return 1;
            }
        }
    }
    return 0;
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

// DRAFT: 0x00210830 ThrowShield__15ClockworkMaximoFv
// 30 words: frame 0x214 vs 0x210, m_unk38 load order around Round180, final sp40 stores and 16-byte copy.
void ClockworkMaximo::ThrowShield() {
    if (m_unk280 != 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA69, "mpShield == NULL");
    }
    m_unk280 = (Shield *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 5, false, 0);
    if (m_unk280 == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA6C, "mpShield");
    }
    void *pSkel = (void *)m_unk3C;
    if (pSkel == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA76, "apSkeleton");
    }
    void *pBone = Find__6PMNodeFUi(pSkel, 0x6499DC24);
    if (pBone == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA79, "apBone");
    }
    float sp30[4];
    float sp40[4];
    *(u_long128 *)sp40 = *(u_long128 *)((char *)pBone + 0x70);
    ClockworkMaximo *pTarget = GetTarget();
    if (pTarget == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0xA7E, "pTarget");
    }
    float *pSrc;
    if (pTarget->m_unk3C != 0) {
        pSrc = (float *)(pTarget->m_unk3C + 0x80);
    } else {
        pSrc = (float *)((char *)pTarget + 0x190);
    }
    *(u_long128 *)sp30 = *(u_long128 *)pSrc;
    sp30[1] += 2.0f;
    sceVu0SubVector(sp30, sp30, sp40);
    float dot = sceVu0InnerProduct(sp30, sp30);
    sceVu0ScaleVector(sp30, sp30, 0.7f / sqrtf(dot));
    float *pSrc2;
    if (m_unk3C != 0) {
        pSrc2 = (float *)(m_unk3C + 0x90);
    } else {
        pSrc2 = (float *)((char *)this + 0x1A0);
    }
    float yaw = Round180__Ff(pSrc2[1]);
    m_unk38->m_unk11C = yaw;
    sp30[3] = 1.0f;
    InitShield__6ShieldFP15EntityBaseClassfPA4_fPA4_fUiPbi(m_unk280, this, 22.142857f, (float (*)[4])sp40, (float (*)[4])sp30, 0, (bool *)0, 0);
    sp40[0] = *(float *)(m_unk3C + 0x80);
    sp40[2] = *(float *)(m_unk3C + 0x88);
    *(u_long128 *)((char *)*(void **)((char *)m_unk280 + 0x38) + 0xA0) = *(u_long128 *)sp40;
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

// DRAFT: 0x00210E80 FaceHit__15ClockworkMaximoFP15EntityBaseClass
// note: DIFF 17 words; compare-chain branch sense and duplicated 150.0f lui in delay slots differ; merged || arm gave 38, nested form 17.
void ClockworkMaximo::FaceHit(EntityBaseClass *arg0) {
    float sp30[4];
    float *sel;
    float f1;
    unsigned int type;
    int m3C;
    if (arg0 == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x9B3, "aPlayer");
    }
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(arg0, sp30);
    m3C = *(int *)((char *)arg0 + 0x3C);
    if (m3C != 0) {
        sel = (float *)(m3C + 0x90);
    } else {
        sel = (float *)((char *)arg0 + 0x1A0);
    }
    f1 = sel[1];
    type = *(unsigned int *)((char *)arg0 + 0x154);
    if (type == 0x0200051D) {
        return;
    }
    if (type == 0x82000010) {
        return;
    }
    if (type != 0x8200000E) {
        if (type == 0x020004E8) {
            f1 = f1 - 150.0f;
        } else if (type == 0x82000007) {
            f1 = f1 - 150.0f;
        } else {
            f1 = f1 - 180.0f;
        }
    } else {
        f1 = f1 - -150.0f;
    }
    if (m_unk3C != 0) {
        sel = (float *)(m_unk3C + 0x90);
    } else {
        sel = (float *)&m_unk1A0;
    }
    sel[1] = f1;
    if (m_unk3C != 0) {
        sel = (float *)(m_unk3C + 0x90);
    } else {
        sel = (float *)&m_unk1A0;
    }
    ClockworkMaximoState *st = m_unk38;
    st->m_unk11C = Round180__Ff(sel[1]);
}

// DRAFT: 0x00210FC0 Stalled__15ClockworkMaximoFfRUi
// note: DIFF 32; counter reg v1 vs v0, GetTarget call delay slot nop, float-compare reg v1 vs v0 with bc1t, tail sltu; tried delay-slot defaults, inverted counter, explicit tail.
bool ClockworkMaximo::Stalled(float arg0, unsigned int &arg1) {
    char *sel;
    arg1 = 0;
    if (m_unk38->m_unkE4 != 0) {
        arg1 = *(unsigned int *)(m_unk38->m_unkE4 + 0xC);
    }
    sel = (char *)&m_unk190;
    if (m_unk3C != 0) {
        sel = (char *)(m_unk3C + 0x80);
    }
    if (DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])&m_unk230, (float (*)[4])sel) <= arg0) {
        if (m_unk288 < 3) {
            m_unk288 = m_unk288 + 1;
        } else {
            return true;
        }
    } else {
        m_unk288 = 0;
    }
    if (m_unk3C != 0) {
        sel = (char *)(m_unk3C + 0x80);
    } else {
        sel = (char *)&m_unk190;
    }
    *(u_long128 *)&m_unk230 = *(u_long128 *)sel;
    if (arg1 & 0x10) {
        ClockworkMaximo *target = GetTarget();
        char *sel2;
        if (target->m_unk3C != 0) {
            sel2 = (char *)(target->m_unk3C + 0x80);
        } else {
            sel2 = (char *)&target->m_unk190;
        }
        float rel = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, sel2);
        return rel < 15.0f;
    }
    if (arg1 & 0x80) {
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


// FUNCTION: 0x00211150 InBlockableState__15ClockworkMaximoFv
bool ClockworkMaximo::InBlockableState() {
    switch (m_unk20) {
    case 0:
    case 1:
    case 2:
    case 0xD:
    case 3:
    case 4:
        return true;
    }
    return false;
}

// FUNCTION: 0x002111B0 CheckBlockAttack__15ClockworkMaximoFv
void ClockworkMaximo::CheckBlockAttack() {
    EntityBaseClass *target = (EntityBaseClass *)mPlayerAPI__13EntityManager;
    if (target == 0) {
        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x924, "pPlayer");
    }
    if (m_unk240 > 0 && m_unk1E8 != 0 && *((unsigned char *)target + 0x23D2) != 0 &&
        *(unsigned short *)((char *)target + 0x15E) != 0xD &&
        *(int *)((char *)target + 0x1CC) == *(int *)((char *)this + 4) && InBlockableState()) {
        float (*a1)[4] = (float (*)[4])((char *)this + 0x190);
        int m3C = m_unk3C;
        if (m3C != 0) {
            a1 = (float (*)[4])(m3C + 0x80);
        }
        float (*a0)[4] = (float (*)[4])((char *)target + 0x190);
        int t3C = *(int *)((char *)target + 0x3C);
        if (t3C != 0) {
            a0 = (float (*)[4])(t3C + 0x80);
        }
        if (Distance__7MathAPIFPA4_fPA4_f(a0, a1) <= 20.0f && FacingTarget(target) &&
            MathAPI::RandomIntRange(0, 0x63) < 10) {
            SetState__15EntityBaseClassFi(this, 6);
        }
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
    memcpy(&m_unk1B0, arg0, 0x3C);
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

// DRAFT: 0x00211800 OnHitEvent__15ClockworkMaximoFP15EntityBaseClassiUiUi
// note: 145 words, size 0x440 vs 0x450: branch targets off by one insn at 0x60/0x70/0xB4/0xCC/0xE0; wrap block f0/f1/f2 register assignment inverted (decl swap and +180 operand order tried, no change).
int ClockworkMaximo::OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    EntityBaseClass *var_s4 = arg0;
    unsigned int temp_s0 = arg2 & ~0x5C0;
    int temp_s1 = m_unk20;
    float f0;
    float f2;
    char *base;
    unsigned int temp_a1;
    int temp_v1_2;

    m_unk264 = arg2;
    if (*(int *)((char *)this + 0xF4) != 0) {
        m_unk240 -= arg1;
        if (m_unk240 > 0) {
            return 1;
        }
        SetState__15EntityBaseClassFi(this,0x1E);
        return 2;
    }
    if (temp_s1 == 6) {
        ((m_unk1E8 != 0) ? (void)0 : CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x7A1, "mEVars.m_bHasShield"));
        SetState__15EntityBaseClassFi(this,7);
        return 4;
    }
    if (temp_s1 == 5) {
        SetState__15EntityBaseClassFi(this,0x1E);
        return 2;
    }
    if (temp_s1 == 7) {
        return 0;
    }
    {
        f0 = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (void *)(*(int *)((char *)arg0 + 0x3C) + 0x80)) + 180.0f;
        base = (m_unk3C != 0) ? (char *)m_unk3C + 0x90 : (char *)this + 0x1A0;
        f2 = *(float *)(base + 4) + f0;
        if (f2 < -180.0f) {
            f2 += 360.0f;
        } else if (!(f2 <= 180.0f)) {
            f2 -= 360.0f;
        }
        *(float *)((char *)this + 0xD8) = f2;
        *(int *)((char *)this + 0xDC) = 0x3E99999A;
        if ((temp_s1 == 0x19) || (temp_s1 == 0x1A)) {
            m_unk258 = 0;
            if (m_unk25C >= (int)GetFrameTime__6PMNodeFv((void *)m_unk3C)) {
                m_unk258 = !(arg2 & 0x200) ? 0 : 1;
                m_unk264 = arg2;
                m_unk240 -= arg1;
                if (m_unk240 <= 0) {
                    *(unsigned int *)((char *)this + 0x268) = arg2;
                    SetState__15EntityBaseClassFi(this,5);
                    return 2;
                }
                SetState__15EntityBaseClassFi(this,0x1A);
                return 1;
            }
            return 0;
        }
        if (m_unk278 != 0) {
            if (GetFrameTime__6PMNodeFv((void *)m_unk3C) < 30.0f) {
                if (m_unk140 != (int)CMaximo_HitOnGroundSeq) {
                    return 0;
                }
            }
            switch (temp_s0) {
            case 0x2:
                m_unk240 = 0;
                *(int *)((char *)this + 0x10C) &= 0xFDFFFFFF;
                SetState__15EntityBaseClassFi(this,0x1D);
                return 2;
            case 0x220:
            case 0x201:
            case 0x1:
                m_unk240 -= arg1;
                if (m_unk240 <= 0) {
                    m_unk240 = 0;
                    *(int *)((char *)this + 0x10C) &= 0xFDFFFFFF;
                    SetState__15EntityBaseClassFi(this,0x1D);
                    return 2;
                }
                PlaySequence__15EntityBaseClassFPUi(this, CMaximo_HitOnGroundSeq);
                return 1;
            default:
                return 3;
            }
        } else {
            if ((m_unk250 == 0) && ((float)m_unk240 <= (0.75f * (float)*(int *)((char *)this + 0x244)))) {
                m_unk250 = CreateDamageFx__15EntityBaseClassFfUi(this, 90.0f, 0U);
            }
            temp_a1 = m_unk250;
            if ((temp_a1 != 0) && ((float)m_unk240 <= (0.5f * (float)*(int *)((char *)this + 0x244)))) {
                ChangeDamageFxInterval__15EntityBaseClassFUif(this, temp_a1, 20.0f);
            }
            m_unk240 -= arg1;
            if (m_unk240 > 0) {
                temp_v1_2 = *(int *)((char *)arg0 + 0x8);
                if ((temp_v1_2 == 0x2D) || (temp_v1_2 == 5)) {
                    var_s4 = *(EntityBaseClass **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
                }
                FaceHit(var_s4);
                SetState__15EntityBaseClassFi(this,4);
                return 1;
            }
            SetState__15EntityBaseClassFi(this,5);
            return 2;
        }
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

// DRAFT: 0x00211CA0 Execute__15ClockworkMaximoFv
// note: all cases transcribed; 1946 differing words, size 0x1E3C vs 0x1F80. Case -2 added 36 words over the 1910 stub state (best_batch16.cpp); the first divergence is the branch at 0x38 (beqz to +0x7AB vs +0x114), and the prologue frame is 0xD0 vs 0xB0, so every later word shifts.
void ClockworkMaximo::Execute() {
    if (m_unk20 >= 0) {
        CheckBlockAttack();
    }
    switch (m_unk20) {
    case -2:
        {
            if (m_unkE9 != 0 && m_unk1E0 != 0) {
                char *pSpawn = (char *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 8, false, 0);
                if (pSpawn == 0) {
                    CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x740, "apKey");
                }
                char *pSrc = ((char *)m_unk3C != 0) ? (char *)m_unk3C + 0x80 : (char *)this + 0x190;
                u_long128 spB0;
                spB0 = *(u_long128 *)pSrc;
                ((float *)&spB0)[1] = ((float *)&spB0)[1] + 2.0f;
                char *pDst = *(char **)(pSpawn + 0x3C);
                if (pDst != 0) {
                    *(u_long128 *)(pDst + 0x80) = spB0;
                    pDst[0x3E] = (unsigned char)(pDst[0x3E] | 8);
                } else {
                    *(u_long128 *)(pSpawn + 0x190) = spB0;
                }
                *(int *)(pSpawn + 0x1B0) = m_unk1E0;
                *(int *)(pSpawn + 0x1B4) = 0;
                *(unsigned char *)(pSpawn + 0x1CC) = 0x5A;
                *(unsigned int *)(pSpawn + 0x1C4) = m_unk4;
            }
        }
        goto block_444;
    case -1:
        if (m_unkE9 != 0) {
            m_unk1F0 = m_unk1C8;
            m_unk1F4 = m_unk1CC;
            m_unk1F8 = m_unk1D0;
            int t3C = m_unk3C;
            float (*a0)[4] = (float (*)[4])((char *)this + 0x190);
            if (t3C != 0) {
                a0 = (float (*)[4])(t3C + 0x80);
            }
            if (!(Distance__7MathAPIFPA4_fPA4_f(a0, (float (*)[4])&m_unk1F0) <= CMF(m_unk1D4))) {
                printf("ERROR - ClockworkMaximo shutdown as initial position wasn't inside attack radius (Instance ID: %d)\n", m_unkC);
                SetState__15EntityBaseClassFi(this, -2);
                return;
            }
            m_unk10C &= 0xF8FFFFFF;
            m_unk10C |= 0x071B1902;
            m_unk103 = 0x40;
            if (CMF(m_unk1B8) == 0.0f) {
                if (CMF(m_unk1BC) == 0.0f && CMF(m_unk1C0) == 0.0f) {
                    int t3C_a = m_unk3C;
                    float (*v0)[4] = (float (*)[4])((char *)this + 0x190);
                    if (t3C_a != 0) {
                        v0 = (float (*)[4])(t3C_a + 0x80);
                    }
                    CMF(m_unk1B8) = (*v0)[0];
                    int t3C_b = m_unk3C;
                    float (*v1)[4] = (float (*)[4])((char *)this + 0x190);
                    if (t3C_b != 0) {
                        v1 = (float (*)[4])(t3C_b + 0x80);
                    }
                    CMF(m_unk1BC) = (*v1)[1];
                    int t3C_c = m_unk3C;
                    float (*v2)[4] = (float (*)[4])((char *)this + 0x190);
                    if (t3C_c != 0) {
                        v2 = (float (*)[4])(t3C_c + 0x80);
                    }
                    CMF(m_unk1C0) = (*v2)[2];
                }
            }
            m_unk104 = 0x40200000;
            m_unk108 = 0x40800000;
            if (m_unk1D8 != 0) {
                CMF(m_unk1C4) = m_unk18C;
                CMF(m_unk1D4) = m_unk18C;
            }
            m_unk200 = CMF(m_unk1B8);
            m_unk204 = CMF(m_unk1BC);
            m_unk208 = CMF(m_unk1C0);
            m_unk244 = m_unk240;
        }
        {
            EntityBaseClass *target = (EntityBaseClass *)mPlayerAPI__13EntityManager;
            float (*a1)[4] = (float (*)[4])((char *)target + 0x190);
            int t3C_t = *(int *)((char *)target + 0x3C);
            if (t3C_t != 0) {
                a1 = (float (*)[4])(t3C_t + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])&m_unk200, a1) <= CMF(m_unk1C4)) {
                if (m_unk38 == 0) {
                    m_unk38 = (ClockworkMaximoState *)new Physics;
                    if (m_unk38 == 0) {
                        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x2AD, "mpPhysics");
                    }
                    SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12, 0);
                }
                if (m_unkD4 == 0) {
                    m_unkD4 = new Shadow(Shadow::SHADOW_TYPE_1, 0x87000006);
                    if (m_unkD4 == 0) {
                        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x2B6, "mpShadow");
                    }
                    Shadow *s = m_unkD4;
                    if (s != 0) {
                        s->m_unk0 = 1;
                        if (s->m_unkC != 0) {
                            s->m_unkC->m_unk18 = 1;
                        }
                    }
                }
                PlaySequence__15EntityBaseClassFPUi(this, CMaximo_LoadMeshSeq);
                if (m_unk3C == 0) {
                    CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x2BF, "GetMeshNode()");
                }
                ScaleSet__6PMNodeFffff((void *)m_unk3C, 1.15f, 1.15f, 1.15f, 1.0f);
                sceVu0SubVector((float *)&m_unk210, (float *)&m_unk210, (float *)&m_unk210);
                AttachWeapon(m_unk1E4 == 0 ? WEAPON_TYPE_0 : WEAPON_TYPE_2);
                if (m_unk1E8 != 0) {
                    AttachWeapon(WEAPON_TYPE_1);
                }
                if (m_unk1B0 == 7) {
                    PlaySound__15EntityBaseClassFUi(this, 0x1F9);
                }
                SetState__15EntityBaseClassFi(this, DetermineIdleState());
            }
        }
    default:
    block_444:
        {
            ClockworkMaximoState *s = m_unk38;
            if (s != 0 && (s->m_unk108 & 0x400)) {
                WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
                if (m_unk38 != 0) {
                    __dl__FPv(m_unk38);
                }
                m_unk38 = 0;
                m_unk10C &= 0xFDFFFFFF;
                EnableSleep__15EntityBaseClassFbb(this, false, false);
                m_unk240 = 0;
                SetState__15EntityBaseClassFi(this, 0x1E);
            }
            return;
        }
    case 0:
    case 1:
        {
            ClockworkMaximo *target;
            float (*pos)[4];
            float (*dst)[4];
            void *seq;
            int idle;
            if (m_unkE9 != 0) {
                if (StopMoving() == 0) {
                    RemoveFromAttackSystem__15EntityBaseClassFv(this);
                    EnableSleep__15EntityBaseClassFbb(this, true, false);
                    if (m_unk20 == 0) {
                        if (m_unk1E4 != 0) {
                            seq = CMaximo_HammerIdleSeq;
                        } else {
                            seq = CMaximo_IdleSeq;
                        }
                        PlaySequence__15EntityBaseClassFPUi(this, seq);
                    } else {
                        PlaySequence__15EntityBaseClassFPUi(this, CMaximo_TauntSeq);
                    }
                    goto block_61;
                }
            } else {
block_61:
                target = GetTarget();
                pos = (float (*)[4])((char *)target + 0x190);
                if (target->m_unk3C != 0) {
                    pos = (float (*)[4])(target->m_unk3C + 0x80);
                }
                RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pos), 0.06f);
                target = GetTarget();
                if (((ClockworkMaximoVirtuals *)target)->GetHealth() > 0) {
                    dst = (float (*)[4])((char *)target + 0x190);
                    if (target->m_unk3C != 0) {
                        dst = (float (*)[4])(target->m_unk3C + 0x80);
                    }
                    if (Distance__7MathAPIFPA4_fPA4_f(dst, (float (*)[4])&m_unk1F0) < CMF(m_unk1D4)) {
                        SetState__15EntityBaseClassFi(this, DetermineNewState());
                        return;
                    }
                    goto block_70;
                }
block_70:
                if (m_unk160 == 0) {
                    idle = DetermineIdleState();
                    if (idle == m_unk20) {
                        if (m_unk1E4 != 0) {
                            seq = CMaximo_HammerIdleSeq;
                        } else {
                            seq = CMaximo_IdleSeq;
                        }
                        PlaySequence__15EntityBaseClassFPUi(this, seq);
                    } else {
                        SetState__15EntityBaseClassFi(this, idle);
                    }
                }
                goto block_444;
            }
        }
        break;
    case 2:
    case 13:
        {
            ClockworkMaximo *target;
            float (*pos)[4];
            int seq;
            if (m_unkE9 != 0) {
                if (StopMoving() == 0) {
                    if (m_unk1E4 != 0) {
                        seq = (int)&CMaximo_HammerIdleLoopSeq;
                    } else {
                        seq = (int)&CMaximo_IdleLoopSeq;
                    }
                    if (m_unk140 != seq) {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)seq);
                    }
                    goto block_444;
                }
            } else {
                if (m_unk274 == 0) {
                    if (m_unk20 == 2) {
                        SetState__15EntityBaseClassFi(this, 3);
                    } else if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, GetTarget(), 0U) != 0) {
                        SetState__15EntityBaseClassFi(this, m_unk268.m_unk270);
                    } else {
                        SetState__15EntityBaseClassFi(this, DetermineIdleState());
                    }
                } else {
                    target = GetTarget();
                    pos = (float (*)[4])((char *)target + 0x190);
                    if (target->m_unk3C != 0) {
                        pos = (float (*)[4])(target->m_unk3C + 0x80);
                    }
                    RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pos), 0.06f);
                }
                goto block_444;
            }
        }
        break;
    case 3:
        {
            ClockworkMaximo *target;
            float (*pos)[4];
            float (*pos2)[4];
            float dist;
            float angle;
            int rnd;
            int v;
            int seq;
            pos = (float (*)[4])&m_unk190;
            if (m_unk3C != 0) {
                pos = (float (*)[4])(m_unk3C + 0x80);
            }
            target = GetTarget();
            pos2 = (float (*)[4])((char *)target + 0x190);
            if (target->m_unk3C != 0) {
                pos2 = (float (*)[4])(target->m_unk3C + 0x80);
            }
            dist = Distance__7MathAPIFPA4_fPA4_f(pos2, pos);
            if (m_unkE9 != 0) {
                if (!(dist <= 10.0f)) {
                    SetState__15EntityBaseClassFi(this, DetermineNewState());
                    return;
                }
                if (StopMoving() == 0) {
                    rnd = MathAPI::RandomIntRange(0, 0x64);
                    m_unk28E = 0;
                    m_unk27C = 0;
                    if (m_unk1E4 != 0) {
                        if (rnd < 0x32) {
                            v = 0x16;
                            m_unk268.m_unk26C = 6.0f;
                            goto block_214;
                        }
                        if (rnd < 0x64) {
                            v = 0x18;
                            m_unk268.m_unk26C = 8.0f;
                            goto block_214;
                        }
                    } else {
                        if (rnd < 0x19) {
                            v = 9;
                            m_unk268.m_unk26C = 8.0f;
                        } else if (rnd < 0x32) {
                            m_unk268.m_unk26C = 6.0f;
                            v = 9;
                            m_unk28E = 1;
                        } else if (rnd < 0x4B) {
                            v = 0x1F;
                            m_unk268.m_unk26C = 8.0f;
                        } else {
                            v = 0xC;
                            m_unk268.m_unk26C = 6.0f;
                        }
block_214:
                        m_unk268.m_unk270 = v;
                    }
                    if (!(dist <= m_unk268.m_unk26C)) {
                        if (m_unk1E4 != 0) {
                            seq = (int)&CMaximo_HammerWalkSeq;
                        } else {
                            seq = (int)&CMaximo_WalkSeq;
                        }
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)seq);
                    }
                    goto block_221;
                }
            } else {
block_221:
                target = GetTarget();
                pos2 = (float (*)[4])((char *)target + 0x190);
                if (target->m_unk3C != 0) {
                    pos2 = (float (*)[4])(target->m_unk3C + 0x80);
                }
                angle = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pos2);
                RotateTo__15EntityBaseClassFff(this, angle, 0.06f);
                if (!(dist <= 10.0f)) {
                    SetState__15EntityBaseClassFi(this, 8);
                } else if (!(dist <= m_unk268.m_unk26C)) {
                    SetVelocity__7PhysicsFff(m_unk38, angle, 0.08f);
                } else if (m_unkE9 == 0) {
                    if (*(unsigned char *)(m_unk3C + 0x3F) & 4) {
                        goto block_231;
                    }
                } else {
block_231:
                    SetState__15EntityBaseClassFi(this, 0xD);
                }
                FootStepSound(0x19);
                FootStepSound(0x38);
                goto block_444;
            }
        }
        break;
    case 4:
        {
            int temp_v1_12;
            char *var_a1_16;
            char *var_a1_17;
            if (m_unkE9 != 0) {
                PlaySound__15EntityBaseClassFUi(this, 0x5EU);
                SetVelocity__7PhysicsFff(m_unk38, m_unk38->m_unk11C, 0.0f);
                if (m_unk1E0 == 0) {
                    m_unk38->m_unkEC = 0x80113F55;
                }
                if ((m_unk28D != 0) && !(m_unk38->m_unk108 & 1)) {
                    m_unk28D = 0;
                    SetState__15EntityBaseClassFi(this, 0x20);
                } else {
                    temp_v1_12 = m_unk264 & ~0x580;
                    switch (temp_v1_12) {
                    case 0x48:
                    case 0xF:
                    case 0x8:
                        SetState__15EntityBaseClassFi(this, 0x19);
                        break;
                    case 0x800:
                    case 0x808:
                    case 0xD:
                    case 0x2D:
                        if (m_unk1E4 != 0) {
                            var_a1_16 = CMaximo_HammerHitKnockbackSeq;
                        } else {
                            var_a1_16 = CMaximo_HitKnockbackSeq;
                        }
                        PlaySequence__15EntityBaseClassFPUi(this, var_a1_16);
                        break;
                    case 0x4D:
                    case 0xC:
                    case 0x804:
                        SetState__15EntityBaseClassFi(this, 0x23);
                        break;
                    default:
                        if (m_unk1E4 != 0) {
                            var_a1_17 = CMaximo_HammerHitSeq;
                        } else {
                            var_a1_17 = CMaximo_HitSeq;
                        }
                        PlaySequence__15EntityBaseClassFPUi(this, var_a1_17);
                        break;
                    }
                }
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
        }
        goto block_444;
    case 5:
        {
            if (m_unkE9 != 0) {
                PlaySound__15EntityBaseClassFUi(this, 0x5EU);
                if (m_unk258 == 0) {
                    *(int *)((char *)this + 0xDC) = 0;
                    if (m_unk38 != 0) {
                        SetVelocity__7PhysicsFff(m_unk38, 0.0f, 0.0f);
                    }
                    RemoveFromAttackSystem__15EntityBaseClassFv(this);
                    EnableSleep__15EntityBaseClassFbb(this, 0U, 0);
                    SetVelocity__7PhysicsFff(m_unk38, m_unk38->m_unk11C, 0.0f);
                    PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_DiePrecursorSeq);
                } else {
                    void *temp_v0_21;
                    char *var_v1_2;
                    temp_v0_21 = Find__6PMNodeFUi((void *)m_unk3C, 0x72C7C29BU);
                    if (temp_v0_21 == 0) {
                        CdsAssert__FPciPc("ClockworkMaximo.cpp", 0x6F7, "pNode");
                    }
                    if (m_unk3C != 0) {
                        var_v1_2 = (char *)(m_unk3C + 0x80);
                    } else {
                        var_v1_2 = (char *)&m_unk190;
                    }
                    *(int *)(var_v1_2 + 4) = *(int *)((char *)temp_v0_21 + 0x74);
                    SetState__15EntityBaseClassFi(this, 0x1E);
                }
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x1E);
            }
        }
        goto block_444;
    case 6:
        {
            char *var_a1_21;
            if (m_unkE9 != 0) {
                if (StopMoving() == 0) {
                    if (m_unk1E4 != 0) { var_a1_21 = CMaximo_HammerBlockSeq; } else { var_a1_21 = CMaximo_SwordBlockSeq; }
                    PlaySequence__15EntityBaseClassFPUi(this, var_a1_21);
                    goto block_389;
                }
            } else {
block_389:
                if (m_unk160 == 0) { SetState__15EntityBaseClassFi(this, DetermineNewState()); }
                goto block_444;
            }
        }
        break;
    case 7:
        {
            char *var_a1_22;
            if (m_unkE9 != 0) {
                if (m_unk1E4 != 0) { var_a1_22 = CMaximo_HammerBlockHitSeq; } else { var_a1_22 = CMaximo_BlockHitSeq; }
                PlaySequence__15EntityBaseClassFPUi(this, var_a1_22);
            }
            if (m_unk160 == 0) { SetState__15EntityBaseClassFi(this, DetermineNewState()); }
        }
        goto block_444;
    case 8:
        {
            ClockworkMaximo *target;
            float (*pos)[4];
            float angle;
            unsigned int spCC;
            float jumpPos[4];
            if (m_unkE9 != 0) {
                if (m_unk1E4 != 0) {
                    if (m_unk140 != (int)CMaximo_HammerRunSeq) {
                        PlaySequence__15EntityBaseClassFPUi(this, CMaximo_HammerRunSeq);
                    }
                } else if (m_unk140 != (int)CMaximo_RunSeq) {
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_RunSeq);
                }
            }
            FootStepSound(0xF);
            FootStepSound(0x22);
            target = GetTarget();
            pos = (float (*)[4])((char *)target + 0x190);
            if (target->m_unk3C != 0) {
                pos = (float (*)[4])(target->m_unk3C + 0x80);
            }
            angle = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pos);
            RotateTo__15EntityBaseClassFff(this, angle, 0.06f);
            SetVelocity__7PhysicsFff(m_unk38, angle, 0.2f);
            if ((m_unk1B0 == 7) && (m_unk290 == 0) && (m_unk38->m_unk108 & 1)) {
                m_unk290 = 1;
                PlaySound__15EntityBaseClassFUi(this, 0xF1);
            }
            if (*(unsigned char *)(m_unk3C + 0x3F) & 4) {
                if (Stalled(2.0f, spCC) != 0) {
                    if (CanJump((float (*)[4])jumpPos) != 0) {
                        SetState__15EntityBaseClassFi(this, 0x12);
                        return;
                    }
                    SetState__15EntityBaseClassFi(this, 1);
                    return;
                }
                {
                    int newState = DetermineNewState();
                    if (newState != m_unk20) {
                        SetState__15EntityBaseClassFi(this, newState);
                    } else if ((m_unk1E8 != 0) && (MathAPI::RandomIntRange(0, 0x64) < 0x28)) {
                        pos = (float (*)[4])&m_unk190;
                        if (m_unk3C != 0) {
                            pos = (float (*)[4])(m_unk3C + 0x80);
                        }
                        target = GetTarget();
                        {
                            float (*tpos)[4] = (float (*)[4])((char *)target + 0x190);
                            if (target->m_unk3C != 0) {
                                tpos = (float (*)[4])(target->m_unk3C + 0x80);
                            }
                            if ((Distance__7MathAPIFPA4_fPA4_f(tpos, pos) < 20.0f) && (m_unk38->m_unk108 & 1)) {
                                m_unk268.m_unk270 = 0xF;
                                m_unk27C = 0;
                                SetState__15EntityBaseClassFi(this, 0xD);
                            }
                        }
                    }
                }
                goto block_444;
            }
            goto block_444;
        }
        break;
    case 9:
        {
            float frame;
            if (m_unkE9 != 0) {
                astbComboCheck = 1;
                PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_SingleSlashAttackSeq);
            }
            frame = GetFrameTime__6PMNodeFv((void *)m_unk3C);
            if ((m_unk28E != 0) && !(frame < 14.0f)) {
                SetState__15EntityBaseClassFi(this, 0xB);
            } else if ((astbComboCheck != 0) && !(frame < 19.0f) && (frame <= 24.0f)) {
                astbComboCheck = 0;
                if (MathAPI::RandomIntRange(0, 0x64) >= 0x29) {
                    SetState__15EntityBaseClassFi(this, 0xA);
                }
            } else if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x10);
            }
        }
        goto block_444;
    case 10:
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_DoubleSlashAttackSeq);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x10);
        }
        goto block_444;
    case 11:
        if (m_unkE9 != 0) {
            m_unk28E = 0;
            PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_360AttackSeq);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x10);
        }
        goto block_444;
    case 12:
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_OverheadAttackSeq);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x10);
        }
        goto block_444;
    case 14:
        {
            float frame;
            if (m_unkE9 != 0) {
                astbComboCheck = 1;
                PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_RingOfPainAttackSeq);
            }
            frame = GetFrameTime__6PMNodeFv((void *)m_unk3C);
            if ((astbComboCheck != 0) && !(frame < 25.0f) && (frame <= 30.0f)) {
                astbComboCheck = 0;
                m_unk28D = 0;
                SetShockwave();
            } else if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x10);
            }
        }
        goto block_444;
    case 15:
        {
            void *var_a1_14;
            if (m_unkE9 != 0) {
                astbComboCheck = 1;
                EnableSleep__15EntityBaseClassFbb(this, 0U, 0);
                if (m_unk1E4 != 0) {
                    var_a1_14 = &CMaximo_HammerShieldAttackSeq;
                } else {
                    var_a1_14 = &CMaximo_ShieldAttackSeq;
                }
                PlaySequence__15EntityBaseClassFPUi(this, var_a1_14);
            }
            if ((astbComboCheck != 0) && (m_unk280 == 0) && !(GetFrameTime__6PMNodeFv((void *)m_unk3C) < 11.0f)) {
                astbComboCheck = 0;
                ThrowShield();
            }
        }
        goto block_444;
    case 16:
        {
            if (m_unkE9 != 0) {
                m_unk274 = CreateTimer__8TimerAPIFUiUib((void *)&mTimerAPI__13EntityManager, m_unk4, GetAttackTimeOut__15ClockworkMaximoFv(this), 0);
                if (m_unk27C != 0) {
                    SetState__15EntityBaseClassFi(this, 0x22);
                } else {
                    SetState__15EntityBaseClassFi(this, DetermineNewState());
                }
            }
        }
        goto block_444;
    case 17:
        {
            void *var_a1_15;
            if (m_unkE9 != 0) {
                EnableSleep__15EntityBaseClassFbb(this, 1U, 0);
                if (m_unk1E4 != 0) {
                    var_a1_15 = &CMaximo_HammerShieldCatchSeq;
                } else {
                    var_a1_15 = &CMaximo_ShieldCatchSeq;
                }
                PlaySequence__15EntityBaseClassFPUi(this, var_a1_15);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x10);
            }
        }
        goto block_444;
    case 18:
        {
            float sp40[4];
            if (CanJump((float (*)[4])sp40) != 0) {
                m_unk28D = 0;
                SetState__15EntityBaseClassFi(this, 0x13);
                return;
            }
            FaceTarget(0.06f);
            SetState__15EntityBaseClassFi(this, DetermineNewState());
            goto block_444;
        }
        break;
    case 19:
        {
            u_long128 *src;
            int tgt;
            float fwd[4];
            float vec[4];
            if (m_unkE9 != 0) {
                tgt = m_unk3C;
                if (tgt != 0) {
                    src = (u_long128 *)(tgt + 0x80);
                } else {
                    src = &m_unk190;
                }
                m_unk210 = *src;
                if (m_unk1E4 != 0) {
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_HammerJumpLaunchSeq);
                } else {
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_JumpLaunchSeq);
                }
                GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, fwd);
                vec[1] = 0.33f;
                vec[3] = 1.0f;
                vec[0] = 0.1f * fwd[0];
                vec[2] = 0.1f * fwd[2];
                if (m_unk38 != 0) {
                    *(u_long128 *)m_unk38 = *(u_long128 *)vec;
                }
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, (m_unk28C == 0) ? 0x15 : 0x14);
            }
            goto block_444;
        }
        break;
    case 20:
        {
            char *seq;
            float fwd[4];
            float vec[4];
            if (m_unkE9 != 0) {
                if (m_unk1E4 != 0) {
                    seq = CMaximo_HammerJumpAirSeq;
                } else {
                    seq = CMaximo_JumpAirSeq;
                }
                PlaySequence__15EntityBaseClassFPUi(this, seq);
                GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, fwd);
                vec[1] = 0.45f;
                vec[3] = 1.0f;
                vec[0] = 0.05f * fwd[0];
                vec[2] = 0.05f * fwd[2];
                if (m_unk38 != 0) {
                    *(u_long128 *)m_unk38 = *(u_long128 *)vec;
                }
            }
            if ((m_unk28D != 0) && !(GetFrameTime__6PMNodeFv((void *)m_unk3C) < 19.0f)) {
                SetState__15EntityBaseClassFi(this, 0xE);
            } else if (m_unk38->m_unk108 & 1) {
                SetState__15EntityBaseClassFi(this, 0x15);
            }
        }
        goto block_444;
    case 21:
        {
            char *seq;
            if (m_unkE9 != 0) {
                if (m_unk1E4 != 0) {
                    seq = CMaximo_HammerJumpLandSeq;
                } else {
                    seq = CMaximo_JumpLandSeq;
                }
                PlaySequence__15EntityBaseClassFPUi(this, seq);
                PlaySound__15EntityBaseClassFUi(this, LandSound[(m_unk38->m_unkE8 >> 11) & 7]);
            }
            if (m_unk160 == 0) {
                FaceTarget(0.06f);
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
        }
        goto block_444;
    case 22:
        {
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_HammerSingleSlashAttackSeq);
            }
            ((EntityBaseClass *)this)->PlaySoundOnFrame(0xD1, 6);
            if (m_unk160 == 0) {
                if (MathAPI::RandomIntRange(0, 0x64) >= 0x29) {
                    SetState__15EntityBaseClassFi(this, 0x17);
                } else {
                    SetState__15EntityBaseClassFi(this, 0x10);
                }
            }
        }
        goto block_444;
    case 23:
        {
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_HammerDoubleSlashAttackSeq);
            }
            ((EntityBaseClass *)this)->PlaySoundOnFrame(0xD2, 2);
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x10);
            }
        }
        goto block_444;
    case 24:
        {
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_HammerDrillAttackSeq);
            }
            ((EntityBaseClass *)this)->PlaySoundOnFrame(0xD2, 2);
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x10);
            }
        }
        goto block_444;
    case 25:
        {
            char *var_a1_19;
            if (m_unkE9 != 0) {
                if (m_unk1E4 != 0) {
                    var_a1_19 = CMaximo_HammerLaunchSeq;
                } else {
                    var_a1_19 = CMaximo_LaunchSeq;
                }
                PlaySequence__15EntityBaseClassFPUi(this, var_a1_19);
                m_unk25C = 0x1E;
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x1B);
            }
        }
        goto block_444;
    case 26:
        {
            int var_v1;
            if (m_unkE9 != 0) {
                PlaySound__15EntityBaseClassFUi(this, 0x5EU);
                if (m_unk258 != 0) {
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_JuggleInAirSeq);
                    var_v1 = 0x15;
                } else {
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_JuggleSeq);
                    var_v1 = 0xF;
                }
                m_unk25C = var_v1;
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x1B);
            }
        }
        goto block_444;
    case 27:
        {
            int var_a2;
            if (m_unkE9 != 0) {
                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                m_unk10C &= 0xFEFFFFFF;
                var_a2 = 2;
                if (m_unk240 >= 0x97) {
                    var_a2 = 0;
                }
                m_unk278 = CreateTimer__8TimerAPIFUiUib((void *)&mTimerAPI__13EntityManager, m_unk4, var_a2, 0);
            }
            if (m_unk278 == 0) {
                m_unk10C |= 0x01000000;
                SetState__15EntityBaseClassFi(this, 0x1C);
            }
        }
        goto block_444;
    case 28:
        {
            char *var_a1_20;
            if (m_unkE9 != 0) {
                if (m_unk1E4 != 0) {
                    var_a1_20 = CMaximo_HammerGetUpSeq;
                } else {
                    var_a1_20 = CMaximo_GetUpSeq;
                }
                PlaySequence__15EntityBaseClassFPUi(this, var_a1_20);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
        }
        goto block_444;
    case 29:
    case 30:
        {
            if (m_unkE9 != 0) {
                *(int *)((char *)this + 0xDC) = 0;
                if (m_unk38 != 0) {
                    SetVelocity__7PhysicsFff(m_unk38, 0.0f, 0.0f);
                }
                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                m_unk10C &= 0xF8FFFFFF;
                if (m_unkD4 != 0) {
                    m_unkD4->m_unk0 = 0;
                    if (m_unkD4->m_unkC != 0) {
                        m_unkD4->m_unkC->m_unk18 = 0;
                    }
                }
                EnableSleep__15EntityBaseClassFbb(this, 0U, 0);
                if (m_unk38 != 0) {
                    SetVelocity__7PhysicsFff(m_unk38, m_unk38->m_unk11C, 0.0f);
                }
                {
                    char *seqPtr;
                    if (m_unk20 == 0x1E) {
                        seqPtr = CMaximo_DieSeq;
                    } else {
                        seqPtr = CMaximo_DieOnGroundSeq;
                    }
                    PlaySequence__15EntityBaseClassFPUi(this, seqPtr);
                }
            }
            if ((m_unk38 != 0) && !(GetFrameTime__6PMNodeFv((void *)m_unk3C) <= 15.0f)) {
                if (m_unk28F == 0) {
                    if (m_unk1E0 == 0) {
                        WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
                    }
                    WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
                    SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 5, 0xA);
                }
                m_unk28F = 1;
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, -2);
            }
        }
        goto block_444;
    case 31:
        if (m_unkE9 != 0) {
            m_unk28C = 1;
            m_unk28D = 1;
            SetState__15EntityBaseClassFi(this, 0x13);
        }
        goto block_444;
    case 32:
        {
            if (m_unkE9 != 0) {
                PlaySound__15EntityBaseClassFUi(this, 0x5EU);
                {
                    u_long128 spA0;
                    spA0 = *(u_long128 *)m_unk38;
                    if (((float *)&spA0)[1] < 0.0f) {
                        ((float *)&spA0)[1] = 0.1f;
                    }
                    *(u_long128 *)m_unk38 = spA0;
                }
                PlaySequence__15EntityBaseClassFPUi(this, &CMaximo_AirHitSeq);
            }
            if (m_unk38->m_unk108 & 1) {
                SetState__15EntityBaseClassFi(this, 0x15);
            }
        }
        goto block_444;
    case 33:
        {
            int temp;
            if (m_unkE9 != 0) {
                temp = m_unk140;
                if (m_unk1E4 != 0) {
                    if (temp == (int)CMaximo_HammerRunSeq) {
                        SetVelocity__7PhysicsFff(m_unk38, m_unk38->m_unk11C, 0.06f);
                        PlaySequence__15EntityBaseClassFPUi(this, CMaximo_HammerStopWalkSeq);
                    } else if (temp == (int)CMaximo_HammerWalkSeq) {
                        PlaySequence__15EntityBaseClassFPUi(this, CMaximo_HammerStopWalkSeq);
                    } else {
                        PlaySequence__15EntityBaseClassFPUi(this, CMaximo_HammerStopWalkSeq);
                    }
                } else if (temp == (int)CMaximo_RunSeq) {
                    SetVelocity__7PhysicsFff(m_unk38, m_unk38->m_unk11C, 0.06f);
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_StopRunSeq);
                } else if (temp == (int)CMaximo_WalkSeq) {
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_StopWalkSeq);
                } else {
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_StopWalkSeq);
                }
            }
            if (m_unk160 == 0) {
                SetVelocity__7PhysicsFff(m_unk38, m_unk38->m_unk11C, 0.0f);
                SetState__15EntityBaseClassFi(this, m_unk254);
                EnableSleep__15EntityBaseClassFbb(this, m_unk260, false);
            }
        }
        goto block_444;
    case 34:
        {
            ClockworkMaximo *target;
            float (*pos)[4];
            if (m_unkE9 != 0) {
                if (StopMoving() == 0) {
                    RemoveFromAttackSystem__15EntityBaseClassFv(this);
                    EnableSleep__15EntityBaseClassFbb(this, true, false);
                    PlaySequence__15EntityBaseClassFPUi(this, CMaximo_TauntSeq);
                    goto block_81;
                }
            } else {
block_81:
                target = GetTarget();
                pos = (float (*)[4])((char *)target + 0x190);
                if (target->m_unk3C != 0) {
                    pos = (float (*)[4])(target->m_unk3C + 0x80);
                }
                RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pos), 0.06f);
                if (m_unk160 == 0) {
                    SetState__15EntityBaseClassFi(this, DetermineNewState());
                }
                goto block_444;
            }
        }
        break;
    case 35:
        {
            char *var_a1_18;
            if (m_unkE9 != 0) {
                if (m_unk1E4 != 0) {
                    var_a1_18 = CMaximo_HammerHitKnockdownSeq;
                } else {
                    var_a1_18 = CMaximo_HitKnockdownSeq;
                }
                PlaySequence__15EntityBaseClassFPUi(this, var_a1_18);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, 0x1C);
            }
        }
        goto block_444;
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
