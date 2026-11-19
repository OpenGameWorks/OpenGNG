#include "types.h"
#include "ClockworkStalker.h"

// TODO(header): foreign declarations
class EntityBaseClass;

class TimerAPI {
public:
    char _pad000[40];
    void KillTimer(unsigned int);
};

class EffectAPI {
public:
    char _pad000[20];
    void DeleteEffect(unsigned int);
};

class MathAPI {
public:
    static int RandomIntRange(int, int);
    int FacingPoint(EntityBaseClass *, float (*)[4], float);
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
