#include "ClockworkSoulsucker.h"

// TODO(header): foreign declarations
class PMNode {
public:
    int AddFxTrigger(struct tagParticleFxTrigger *, bool);
    void ScaleSet(float, float, float, float);
};

class Physics {
public:
    void SetPhysicsType(unsigned int, float (*)[4]);
};

class EntityBaseClass;

class EntitySlotView {
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
    virtual void Slot14();
    virtual void Slot15();
};

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
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *);
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern "C" void **InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);
extern unsigned char __vt__19ClockworkSoulsucker[0x10];
extern unsigned char ClockworkSoulsucker_GrabAttemptSeq[0x10];
extern unsigned char ClockworkSoulsucker_Small_AirJuggleSeq[0x10];

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

// FUNCTION: 0x002048B0 SetSpawnedFromEntity__19ClockworkSoulsuckerFPfPfi
void ClockworkSoulsucker::SetSpawnedFromEntity(float *pPos, float *pAlt, int nType) {
    m_unk1C8 = pPos[0];
    m_unk1CC = pPos[1];
    m_unk1D0 = pPos[2];
    m_unk1D4 = 150.0f;
    m_unk1C4 = 75.0f;
    m_unk1E0 = 0;
    m_unk1B0 = nType;
    u_long128 *pDst;

    if (m_unk3C != 0) {
        pDst = (u_long128 *)(m_unk3C + 0x80);
    } else {
        pDst = (u_long128 *)((char *)this + 0x190);
    }
    *pDst = *(u_long128 *)pPos;
    if (pAlt != 0) {
        if (m_unk3C != 0) {
            pDst = (u_long128 *)(m_unk3C + 0x90);
        } else {
            pDst = (u_long128 *)((char *)this + 0x1A0);
        }
        *pDst = *(u_long128 *)pAlt;
    }
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

// FUNCTION: 0x00204AF0 SetupType__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::SetupType() {
    if (m_unk3C == 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0x966, "GetMeshNode()");
    }
    if (m_unk1B0 == 0) {
        ((PMNode *)m_unk3C)->ScaleSet(0.5f, 0.5f, 0.5f, 1.0f);
        m_unk104 = 0x40000000;
        m_unk108 = 0x40000000;
        m_unk103 = 0x40;
        ScaleSpikes(0.0f);
        return;
    }
    ((PMNode *)m_unk3C)->ScaleSet(1.0f, 1.0f, 1.0f, 1.0f);
    m_unk104 = 0x40600000;
    m_unk108 = 0x40800000;
    m_unk103 = 0x40;
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

// FUNCTION: 0x00204C20 InBlockableState__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::InBlockableState() {
    int nState;

    nState = m_unk20;
    if (m_unk1B0 == 1) {
        if (nState == 4 || nState == 7 || nState == 5) {
            return 1;
        }
    } else {
        if (nState == 0x10 || (unsigned int)(nState - 0x1B) <= 1U || (nState == 0x17 && m_unk2A0 == 0) || nState == 0x19 || nState == 0x1E) {
            if (!InJuggleAirspace()) {
                return 1;
            }
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

// FUNCTION: 0x00205330 GetTarget__19ClockworkSoulsuckerFv
void *ClockworkSoulsucker::GetTarget() {
    if (m_unk234 != 0) {
        m_unk260 = InstanceIsValid__15EntityBaseClassFUi(m_unk234);
        if (m_unk260 == 0 || ((EntitySlotView *)m_unk260)->Slot13() == 0) {
            m_unk260 = mPlayerAPI__13EntityManager;
            if (m_unk260 == 0) {
                CdsAssert("ClockworkSoulsucker.cpp", 0x841, "m_pTarget");
            }
        }
    } else {
        m_unk260 = mPlayerAPI__13EntityManager;
        if (m_unk260 == 0) {
            CdsAssert("ClockworkSoulsucker.cpp", 0x848, "m_pTarget");
        }
    }
    return m_unk260;
}

// FUNCTION: 0x002053F0 FaceTarget__19ClockworkSoulsuckerFf
void ClockworkSoulsucker::FaceTarget(float fArg) {
    void *pTarget;
    int nOwner;
    char *pPos;

    pTarget = GetTarget();
    nOwner = *(int *)((char *)pTarget + 0x3C);
    pPos = (char *)pTarget + 0x190;
    if (nOwner != 0) {
        pPos = (char *)nOwner + 0x80;
    }
    RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pPos), fArg);
}

// FUNCTION: 0x00205450 SetDrainHit__19ClockworkSoulsuckerFUi
void ClockworkSoulsucker::SetDrainHit(unsigned int nArg) {
    if (m_unk140 != &ClockworkSoulsucker_GrabAttemptSeq) {
        CdsAssert("ClockworkSoulsucker.cpp", 0x820, "GetCurrentSequence() == ClockworkSoulsucker_GrabAttemptSeq");
    }
    m_unk10C &= 0xF8FFFFFF;
    m_unk38->SetPhysicsType(0x812, 0);
    m_unk2A0 = 1;
    m_unk2C4 = nArg;
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

// FUNCTION: 0x00205530 AddSoulValue__19ClockworkSoulsuckerFi
void ClockworkSoulsucker::AddSoulValue(int nValue) {
    m_unk258 += nValue;
    m_unk22C += nValue * 150;
    if (m_unk22C > 800) {
        m_unk22C = 800;
    }
    if (m_unk258 > 15) {
        m_unk258 = 15;
    }
    if (m_unk258 >= 6) {
        m_unk2B8 = 1;
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

// FUNCTION: 0x00205BC0 OnWakeEvent__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::OnWakeEvent() {
    if (m_unk3C != 0) {
        SetupType();
        UpdateDamageFx();
        if (m_unk2B0 != 0) {
            AttachSmokeEffect();
        }
    }
    AdjustPhysicsForEweedCheck();
}

// FUNCTION: 0x00208980 __dt__19ClockworkSoulsuckerFv
extern "C" void *__dt__19ClockworkSoulsuckerFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        ClockworkSoulsucker *pSelf = (ClockworkSoulsucker *)pThis;
        *(void **)pThis = __vt__19ClockworkSoulsucker;
        pSelf->ReleaseSemaphoreIfOwned();
        DestroyDamageFx__15EntityBaseClassFUi(pThis, pSelf->m_unk238);
        pSelf->m_unk238 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00208A00 __ct__19ClockworkSoulsuckerFv
ClockworkSoulsucker::ClockworkSoulsucker() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 0U);
    m_unk0 = __vt__19ClockworkSoulsucker;
    m_unk22C = 0x320;
    m_unk238 = 0;
    m_unk166 = 1;
    m_unk24C = 0x3F800000;
    m_unk248 = 0;
    m_unk244 = 0;
    m_unk240 = 0;
    m_unk250 = 0;
    m_unk254 = 0;
    m_unk25C = 0;
    m_unk264 = 0;
    m_unk268 = 0;
    m_unk258 = 5;
    m_unk2A0 = 0;
    m_unk2A1 = 0;
    m_unk2A4 = 0;
    m_unk2A8 = 0;
    m_unk2AC = 0;
    m_unk2C8 = 0;
    m_unk2C9 = 0;
    m_unk2B0 = 0;
    m_unk2B4 = 0;
    m_unk2BC = 0;
    m_unk2C0 = 0;
    m_unk2C4 = 0;
    m_unk2B8 = 0;
}
