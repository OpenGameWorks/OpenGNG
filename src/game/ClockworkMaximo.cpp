#include "ClockworkMaximo.h"
#include "types.h"

// TODO(header): foreign declarations
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
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern char CMaximo_RunSeq[0x40];
extern char CMaximo_WalkSeq[0x40];
extern char CMaximo_HammerRunSeq[0x40];
extern char CMaximo_HammerWalkSeq[0x40];
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void __dt__15EntityBaseClassFv(void *, short);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__15ClockworkMaximo[0x40];

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

// DRAFT: 0x00210600 FootStepSound__15ClockworkMaximoFUi
// note: original is a tail call (j) with no frame; ours sets up a frame and jal. Tried dropping temp local, ternary single call, bare constant call: no drop.
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

// FUNCTION: 0x00211510 DetermineIdleState__15ClockworkMaximoFv
int ClockworkMaximo::DetermineIdleState() {
    m_unk38->m_unkEC = 0x80113FD5;
    return (MathAPI::RandomIntRange(0, 0x64) & 1) != 0;
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
