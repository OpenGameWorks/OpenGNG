#include "types.h"
#include "ClockworkStalker.h"

// TODO(header): foreign declarations
class EntityBaseClass;

class TimerAPI {
public:
    char _pad000[40];
    void KillTimer(unsigned int);
    int CreateTimer(unsigned int, unsigned int, bool);
};

class EffectAPI {
public:
    char _pad000[20];
    void DeleteEffect(unsigned int);
};

class MathAPI {
public:
    char _pad000[0x3C];
    char *m_unk3C;
    char _pad040[0x154 - 0x40];
    int m_unk154;
    static int RandomIntRange(int, int);
    int FacingPoint(EntityBaseClass *, float (*)[4], float);
};

class EntityManager {
public:
    char _pad000[0x505C];
    MathAPI *m_unk505C;
};

extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__16ClockworkStalker[];
extern TimerAPI mTimerAPI__13EntityManager;
extern EffectAPI mEffectAPI__13EntityManager;
extern MathAPI *mPlayerAPI__13EntityManager;
extern char ClockworkStalker_KnockUp1Seq[];
extern char ClockworkStalker_KnockUp2Seq[];
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *, unsigned int *);
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *, float *);
extern "C" float Round180__Ff(float f);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(void *, float (*)[4]);
extern "C" int RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(void *, void *, unsigned int);
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);

// DRAFT: 0x001E2B80 KillTimers__16ClockworkStalkerFv
// note: 2 differing lines; original copies this to s0 before the first timer load, ours loads a0 first (tried local self pointer and unsigned cast, no change)
void ClockworkStalker::KillTimers() {
    mTimerAPI__13EntityManager.KillTimer(m_unk214);
    mTimerAPI__13EntityManager.KillTimer(m_unk2D8);
    mTimerAPI__13EntityManager.KillTimer(m_unk2D0);
    mTimerAPI__13EntityManager.KillTimer(m_unk2AC);
}

// FUNCTION: 0x001E2DA0 DeleteEffects__16ClockworkStalkerFv
void ClockworkStalker::DeleteEffects() {
    if (m_unk2E0 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2E0);
        m_unk2E0 = 0;
    }
}

// FUNCTION: 0x001E2DE0 InBlockableState__16ClockworkStalkerFv
int ClockworkStalker::InBlockableState() {
    if ((unsigned int)(m_unk20 - 0x14) <= 1U || m_unk20 == 0x1B ||
        m_unk140 == (unsigned int *)ClockworkStalker_KnockUp1Seq ||
        m_unk140 == (unsigned int *)ClockworkStalker_KnockUp2Seq) {
        return 0;
    }
    return 1;
}

// DRAFT: 0x001E2F70 FaceHit__16ClockworkStalkerFv
// note: 22 differing lines; original loads f0 with lui+mtc1 per case and subtracts once in a shared delay slot, ours loads the switch scrutinee and constant in different registers (tried f0 constant variable: 44 lines, per-case f1 subtract: 22)
void ClockworkStalker::FaceHit() {
    float sp30[4];
    MathAPI *mgr = mpEntMgr__15EntityBaseClass->m_unk505C;
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(mgr, sp30);
    char *ptr = mgr->m_unk3C != 0 ? mgr->m_unk3C + 0x90 : (char *)mgr + 0x1A0;
    float f1 = *(float *)(ptr + 4);
    switch (mpEntMgr__15EntityBaseClass->m_unk505C->m_unk154) {
    case 0x82000010:
        return;
    case 0x8200000E:
        f1 = f1 - 150.0f;
        break;
    case 0x82000007:
        f1 = f1 - -150.0f;
        break;
    default:
        f1 = f1 - 180.0f;
        break;
    }
    char *dst = m_unk3C != 0 ? m_unk3C + 0x90 : (char *)this + 0x1A0;
    *(float *)(dst + 4) = f1;
    char *s0 = m_unk38;
    char *src = m_unk3C != 0 ? m_unk3C + 0x90 : (char *)this + 0x1A0;
    *(float *)(s0 + 0x11C) = Round180__Ff(*(float *)(src + 4));
}

// FUNCTION: 0x001E3080 IsStalled__16ClockworkStalkerFfPA4_f
int ClockworkStalker::IsStalled(float fDist, float (*arg1)[4]) {
    char *target;
    float d1;
    float d2;
    if (m_unk3C != 0) {
        target = m_unk3C + 0x80;
    } else {
        target = &m_unk190;
    }
    d1 = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk240, arg1);
    d2 = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)target, arg1);
    if (FastMath_Fabs__Ff(d1 - d2) <= fDist) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001E3110 PlayerFacingUs__16ClockworkStalkerFv
int ClockworkStalker::PlayerFacingUs() {
    MathAPI *player = mPlayerAPI__13EntityManager;
    if (player != 0) {
        char *target = &m_unk190;
        float (*unused)[4];
        if (m_unk3C != 0) {
            target = m_unk3C + 0x80;
        }
        if (player->FacingPoint((EntityBaseClass *)target, unused, 60.0f) != 0) {
            return 1;
        }
    }
    return 0;
}

// DRAFT: 0x001E3170 CanAttackPlayer__16ClockworkStalkerFv
// note: 42 differing lines; original reloads mPlayerAPI as a gp global (v1) and keeps roll in s0 across RequestAttack, ours uses a local player in s0 and roll in v0 (tried global RequestAttack arg: 50, roll-retest restructure: 52); TimerAPI lui/addiu carries a zero relocation
int ClockworkStalker::CanAttackPlayer() {
    if (m_unk221 != 0) {
        MathAPI *player = mPlayerAPI__13EntityManager;
        char *target = (char *)player + 0x190;
        if (player->m_unk3C != 0) {
            target = player->m_unk3C + 0x80;
        }
        if (Distance__7MathAPIFPA4_fPA4_f(target, &m_unk200) <= *(float *)&m_unk1D4) {
            int roll = MathAPI::RandomIntRange(1, 100);
            if (roll < 0x33) {
                if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, player, 0) != 0) {
                    m_unk221 = 0;
                    m_unk214 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 0xC, true);
                    return 1;
                }
            } else {
                m_unk221 = 0;
                m_unk214 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 0xC, true);
            }
        }
    }
    return 0;
}

// FUNCTION: 0x001E3260 SetSpawnedFromEntity__16ClockworkStalkerFPfPfi
void ClockworkStalker::SetSpawnedFromEntity(float *arg0, float *arg1, int arg2) {
    if (MathAPI::RandomIntRange(1, 100) & 1) {
        m_unk1FC = 0x1F4;
    } else {
        m_unk1FC = 0x23A;
    }
    m_unk210 = m_unk1FC;
    m_unk1C4 = 0x43160000;
    m_unk1C8 = arg0[0];
    m_unk1CC = arg0[1];
    m_unk1D0 = arg0[2];
    m_unk1D4 = 0x43160000;
    m_unk1B4 = 0;
    m_unk1E0 = 0;
    char *dst = m_unk3C != 0 ? m_unk3C + 0x80 : &m_unk190;
    *(u_long128 *)dst = *(u_long128 *)arg0;
    if (arg1 != 0) {
        char *dst2 = m_unk3C != 0 ? m_unk3C + 0x90 : &m_unk1A0[0];
        *(u_long128 *)dst2 = *(u_long128 *)arg1;
    }
}

// FUNCTION: 0x001E3330 SetDefaultVars__16ClockworkStalkerFv
void ClockworkStalker::SetDefaultVars() {
    if (MathAPI::RandomIntRange(1, 100) & 1) {
        m_unk1FC = 0x1F4;
    } else {
        m_unk1FC = 0x23A;
    }
    m_unk210 = m_unk1FC;
    m_unk1B8 = 0;
    m_unk1BC = 0;
    m_unk1C0 = 0;
    m_unk1C4 = 0x41C80000;
    m_unk1D4 = 0x420C0000;
    m_unk1B4 = 0;
    m_unk1E0 = 1;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F4 = 0;
    m_unk1D8 = 0;
    m_unk1F8 = 0x3DCCCCCD;
}

// FUNCTION: 0x001E33D0 SetEditableVars__16ClockworkStalkerFPc
void ClockworkStalker::SetEditableVars(char *arg0) {
    memcpy((char *)this + 0x1B0, arg0, 0x4C);
    if (MathAPI::RandomIntRange(1, 100) & 1) {
        m_unk1FC = 0x1F4;
    } else {
        m_unk1FC = 0x23A;
    }
    m_unk210 = m_unk1FC;
}

// FUNCTION: 0x001E3430 OnTimerEvent__16ClockworkStalkerFUi
void ClockworkStalker::OnTimerEvent(unsigned int arg0) {
    if (arg0 == m_unk214) {
        m_unk221 = 1;
        return;
    }
    if (arg0 == m_unk2D8) {
        m_unk2D5 = 1;
        return;
    }
    if (arg0 == m_unk2D0) {
        m_unk222 = 1;
        return;
    }
    if (arg0 == m_unk2AC) {
        int temp_v1 = m_unk2A0;
        if (temp_v1 == 1) {
            m_unk2A0 = 2;
        } else if (temp_v1 == 3) {
            m_unk2A0 = 0;
        }
        LoadCorrectMesh(1);
        return;
    }
    if (arg0 == m_unk280) {
        m_unk280 = 0;
    }
}

// FUNCTION: 0x001E34E0 OnWakeEvent__16ClockworkStalkerFv
void ClockworkStalker::OnWakeEvent() {
    if (m_unk2E4 != 0) {
        PlaySequence__15EntityBaseClassFPUi(this, m_unk2E4);
    }
}

// FUNCTION: 0x001E3880 OnStopAttack__16ClockworkStalkerFv
void ClockworkStalker::OnStopAttack() {
    if (m_unk163 == 2) {
        return;
    }
    if (m_unk20 == 0xD) {
        return;
    }
    if (m_unk20 == 0x1B) {
        return;
    }
    SetState__15EntityBaseClassFi(this, 0xD);
}

// FUNCTION: 0x001E6370 __dt__16ClockworkStalkerFv
extern "C" ClockworkStalker *__dt__16ClockworkStalkerFv(ClockworkStalker *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__16ClockworkStalker;
        DestroyDamageFx__15EntityBaseClassFUi(pThis, pThis->m_unk2E8);
        pThis->m_unk2E8 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001E63E0 __ct__16ClockworkStalkerFv
ClockworkStalker::ClockworkStalker() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 0);
    *(unsigned char **)this = __vt__16ClockworkStalker;
    m_unk220 = 0;
    m_unk228 = 0;
    m_unk2DC = 0;
    m_unk270 = 0;
    m_unk274 = 0;
    m_unk268 = 0;
    m_unk26C = 0;
    m_unk2E4 = 0;
    m_unk278 = 1;
    m_unk280 = 0;
    m_unk2D0 = 0;
    m_unk230 = 0;
    m_unk2EC = 0;
    m_unk2E8 = 0;
    m_unk2E0 = 0;
    m_unk2A0 = 0;
    m_unk2A4 = 0;
    m_unk2AC = 0;
    m_unk2B0 = 0;
    m_unk2A8 = 0xBF800000;
    m_unk166 = 1;
    m_unk103 = 0x40;
}
