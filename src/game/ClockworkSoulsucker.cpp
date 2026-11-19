#include "ClockworkSoulsucker.h"

// TODO(header): foreign declarations
class TimerAPI {
public:
    char _pad000[40];
    int CreateTimer(unsigned int, unsigned int, bool);
};

class EffectAPI {
public:
    char _pad000[20];
    void DeleteEffect(unsigned int);
};

class MathAPI {
public:
    static int RandomIntRange(int, int);
};

extern TimerAPI mTimerAPI__13EntityManager;
extern EffectAPI mEffectAPI__13EntityManager;
extern unsigned char m_bSuckingActive__19ClockworkSoulsucker;
extern unsigned char m_bSuckingSemaphoreBusy__19ClockworkSoulsucker;
extern int m_SuckerRef__19ClockworkSoulsucker;

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
