#include "ClockworkSoulsucker.h"

// TODO(header): foreign declarations
class PMNode {
public:
    int AddFxTrigger(struct tagParticleFxTrigger *, bool);
};

class EntityBaseClass;

class TimerAPI {
public:
    char _pad000[40];
    int CreateTimer(unsigned int, unsigned int, bool);
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

extern TimerAPI mTimerAPI__13EntityManager;
extern EffectAPI mEffectAPI__13EntityManager;
extern MathAPI *mPlayerAPI__13EntityManager;
extern unsigned char m_bSuckingActive__19ClockworkSoulsucker;
extern unsigned char m_bSuckingSemaphoreBusy__19ClockworkSoulsucker;
extern int m_SuckerRef__19ClockworkSoulsucker;
void CdsAssert(char *, int, char *);

// FUNCTION: 0x00204570 AttachDamageEffect__19ClockworkSoulsuckerFP6PMNodeUifff
void ClockworkSoulsucker::AttachDamageEffect(PMNode *pNode, unsigned int nId, float fA, float fB, float fC) {
    struct FxTriggerBlock {
        unsigned int id;
        float a;
        float b;
        float c;
        int z0;
        int z1;
        int n0;
        int n1;
        int z2;
        int z3;
    } trig;

    if (pNode != 0) {
        trig.id = nId;
        trig.a = fA;
        trig.b = fB;
        trig.c = fC;
        trig.z0 = 0;
        trig.z1 = 0;
        trig.n0 = (int)0xBF800000;
        trig.n1 = (int)0xBF800000;
        trig.z2 = 0;
        trig.z3 = 0;
        pNode->AddFxTrigger((struct tagParticleFxTrigger *)&trig, 0);
    }
}

// FUNCTION: 0x00204870 SetRiseAndAttack__19ClockworkSoulsuckerFPA4_fff
void ClockworkSoulsucker::SetRiseAndAttack(float (*pVec)[4], float fA, float fB) {
    m_unk1B8 = pVec[0][0];
    m_unk1BC = pVec[0][1];
    m_unk1C0 = pVec[0][2];
    m_unk1C8 = pVec[0][0];
    m_unk1CC = pVec[0][1];
    m_unk1D0 = pVec[0][2];
    m_unk1C4 = fA;
    m_unk1D4 = fB;
}

// FUNCTION: 0x00204930 ResetAttackTimer__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::ResetAttackTimer() {
    m_unk25C = mTimerAPI__13EntityManager.CreateTimer(m_unk4, MathAPI::RandomIntRange(0, 3), 0);
}

// FUNCTION: 0x00204980 ReleaseSemaphoreIfOwned__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::ReleaseSemaphoreIfOwned() {
    if (m_bSuckingSemaphoreBusy__19ClockworkSoulsucker != 0 && m_SuckerRef__19ClockworkSoulsucker == (int)m_unk4) {
        m_bSuckingSemaphoreBusy__19ClockworkSoulsucker = 0;
        m_SuckerRef__19ClockworkSoulsucker = 0;
        m_bSuckingActive__19ClockworkSoulsucker = 0;
    }
}

// FUNCTION: 0x002049B0 DeleteEffects__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::DeleteEffects() {
    if (m_unk2A4 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2A4);
        m_unk2A4 = 0;
    }
}

// FUNCTION: 0x00204BC0 PlayerFacingUs__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::PlayerFacingUs() {
    EntityBaseClass *pTarget;
    float (*pVec)[4];
    MathAPI *pPlayer;

    pPlayer = mPlayerAPI__13EntityManager;
    if (pPlayer != 0) {
        pTarget = (EntityBaseClass *)((char *)this + 0x190);
        if (m_unk3C != 0) {
            pTarget = (EntityBaseClass *)(m_unk3C + 0x80);
        }
        if (pPlayer->FacingPoint(pTarget, pVec, 45.0f)) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x00204FA0 DetermineIdleState__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::DetermineIdleState() {
    int rnd;
    int state;

    rnd = MathAPI::RandomIntRange(0, 1);
    if (m_unk1B0 == 0) {
        state = rnd == 0 ? 0x1C : 0x1B;
        return state;
    }
    state = rnd == 0 ? 5 : 4;
    return state;
}

// FUNCTION: 0x002051D0 DeleteTimers__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::DeleteTimers() {
    mTimerAPI__13EntityManager.KillTimer(m_unk240);
    mTimerAPI__13EntityManager.KillTimer(m_unk244);
    m_unk240 = 0;
    m_unk244 = 0;
}

// FUNCTION: 0x002054E0 GetSuckingSucker__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::GetSuckingSucker() {
    if (m_bSuckingSemaphoreBusy__19ClockworkSoulsucker == 0) {
        return 0;
    }
    if (m_SuckerRef__19ClockworkSoulsucker == 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0x817, "m_SuckerRef");
    }
    return m_SuckerRef__19ClockworkSoulsucker;
}

// FUNCTION: 0x002056A0 SetDefaultVars__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::SetDefaultVars() {
    m_unk1B8 = 0.0f;
    m_unk1BC = 0.0f;
    m_unk1C0 = 0.0f;
    m_unk1C4 = 25.0f;
    m_unk1D4 = 25.0f;
    m_unk1B4 = 0;
    m_unk1E0 = 1;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F4 = 0;
    m_unk1D8 = 0;
}
