// FLAGS: -str readonly
#include "ClockworkSoulsucker.h"

// TODO(header): foreign declarations
class PMNode {
public:
    int AddFxTrigger(struct tagParticleFxTrigger *, bool);
    void ScaleSet(float, float, float, float);
    PMNode *Find(unsigned int);
    float GetFrameTime();
    float GetFrameRate();
    void SetFrameRate(float, bool);
};

class Physics {
public:
    void SetPhysicsType(unsigned int, float (*)[4]);
    void SetVelocity(float, float);
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

class EffectObj {
public:
    char _pad000[4];
    PMNode *m_unk4;
};

class EffectAPI {
public:
    char _pad000[20];
    EffectObj *EffectValid(unsigned int);
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
extern int miRandom__7MathAPI;
void CdsAssert(char *, int, char *);
extern "C" int printf(const char *fmt, ...);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *);
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" unsigned int CreateDamageFx__15EntityBaseClassFfUi(void *pThis, float fInterval, unsigned int nFlag);
extern "C" int ChangeDamageFxInterval__15EntityBaseClassFUif(void *pThis, unsigned int nFx, float fInterval);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(void *pThis, float (*pPos)[4]);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void **InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(void *pThis, int eLoadClass, void *pArray, float (*pBox)[4], float fRadius, int nFlags, bool bFlagA, bool bFlagB);
struct ApparitionState {
    char _pad000[0x1B0];
    int m_unk1B0;
};
struct TempApparitionArray {
    int m_count;            // 0x00
    int m_unk04;            // 0x04 cleared with m_count
    unsigned int *m_pData;  // 0x08
    char _pad0C[4];
};
extern "C" ApparitionState *ApparitionIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" void StopAllSoundsByObject__15EntityBaseClassFv(void *);
extern "C" void PlaySound__15EntityBaseClassFUi(void *, unsigned int);
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern unsigned char ClockworkSoulsucker_DeathBottomWiggleSeq[60];
extern void *mpEntMgr__15EntityBaseClass;
extern TempApparitionArray mTempArray__15EntityBaseClass;
extern unsigned char __vt__19ClockworkSoulsucker[0x10];
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *, void *);
extern "C" float Round180__Ff(float);
extern unsigned char ClockworkSoulsucker_GrabAttemptSeq[0x10];
extern unsigned char ClockworkSoulsucker_Small_AirJuggleSeq[0x10];
extern unsigned char ClockworkSoulsucker_Small_JuggleSeq[0x10];
extern unsigned char ClockworkSoulsucker_Small_LaunchSeq[0x10];
extern unsigned char ClockworkSoulsucker_Small_KnockUpSeq[0x10];

// FUNCTION: 0x002042B0 AdjustPhysicsForEweedCheck__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::AdjustPhysicsForEweedCheck() {
    char *pPhys = (char *)m_unk38;
    if (pPhys != 0) {
        *(int *)(pPhys + 0x84) = 0x40200000;
        *(int *)(pPhys + 0x94) = 0x40200000;
    }
}

// DRAFT: 0x002042D0 ScaleSpikes__19ClockworkSoulsuckerFf
// note: 20 words differ; loop recomputes &aNodes (addiu v1,sp,0x60) each iteration, ours folds sp+0x60 into lw offset (size 0x19C vs 0x1A0). Tried do/while, for, pointer-walk, byte-offset forms.
void ClockworkSoulsucker::ScaleSpikes(float fArg) {
    int aNodes[4];
    int i;

    if (m_unk3C == 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0xA3A, "GetMeshNode()");
    }
    aNodes[0] = (int)((PMNode *)m_unk3C)->Find(0x37FF8FE2U);
    aNodes[1] = (int)((PMNode *)m_unk3C)->Find(0x35117538U);
    aNodes[2] = (int)((PMNode *)m_unk3C)->Find(0x34B4DC8EU);
    aNodes[3] = (int)((PMNode *)m_unk3C)->Find(0x30CC808CU);
    if (aNodes[0] == 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0xA41, "pSpikeJoints[0] != NULL");
    }
    if (aNodes[1] == 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0xA42, "pSpikeJoints[1] != NULL");
    }
    if (aNodes[2] == 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0xA43, "pSpikeJoints[2] != NULL");
    }
    if (aNodes[3] == 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0xA44, "pSpikeJoints[3] != NULL");
    }
    if (m_unk1B0 != 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0xA46, "mEVars.m_iType == CWSS_TYPE_SMALL");
    }
    i = 0;
    do {
        ((PMNode *)aNodes[i])->ScaleSet(fArg, fArg, fArg, 1.0f);
        i++;
    } while (i < 4);
}

// DRAFT: 0x00204470 AttachSmokeEffect__19ClockworkSoulsuckerFv
// note: 18 lines differ; original reloads miRandom in beqz delay slot at 0x40, ours has nop. Tried truthiness, bit-compare, early-return, zero-first (40), else-if (40).
void ClockworkSoulsucker::AttachSmokeEffect() {
    int nRand;

    m_unk2B0 = 1;
    nRand = miRandom__7MathAPI;
    miRandom__7MathAPI = nRand * 0x343FD + 0x269EC3;
    if (m_unk3C != 0) {
        if (miRandom__7MathAPI & 1) {
            AttachDamageEffect(((PMNode *)m_unk3C)->Find(0x8EA3DD30U), 0x83000154U, 0.0f, 0.0f, 0.0f);
        } else {
            AttachDamageEffect(((PMNode *)m_unk3C)->Find(0x72C7C29BU), 0x83000154U, 0.0f, 0.0f, 0.0f);
        }
    } else {
        printf("SOULSUCKER BUG (ALERT JOEY IMMEDIATELY): GetMeshNode() returned NULL when calling AttachSmokeEffects!!!\n", nRand);
        CdsAssert("ClockworkSoulsucker.cpp", 0xA32, "0");
    }
}

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

// FUNCTION: 0x002045D0 UpdateDamageFx__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::UpdateDamageFx() {
    float fTime = (float)m_unk22C;
    if (fTime < 600.0f) {
        if (m_unk238 == 0) {
            if (fTime < 240.00002f) {
                m_unk238 = CreateDamageFx__15EntityBaseClassFfUi(this, 20.0f, (m_unk1B0 == 1) ? 0x830002AAull : 0ull);
                if (m_unk238 == 0) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x9DB, "m_hDamageFx");
                }
                if (m_unk1B0 == 1) {
                    AttachSmokeEffect();
                }
                m_unk2B4 = 2;
            } else {
                m_unk238 = CreateDamageFx__15EntityBaseClassFfUi(this, 90.0f, (m_unk1B0 == 1) ? 0x830002AAull : 0ull);
                if (m_unk238 == 0) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x9E6, "m_hDamageFx");
                }
                m_unk2B4 = 1;
            }
        } else if (fTime < 240.00002f && m_unk2B4 != 2) {
            if (!(ChangeDamageFxInterval__15EntityBaseClassFUif(this, m_unk238, 20.0f) & 0xFF)) {
                m_unk238 = CreateDamageFx__15EntityBaseClassFfUi(this, 20.0f, (m_unk1B0 == 1) ? 0x830002AAull : 0ull);
                if (m_unk238 == 0) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x9F1, "m_hDamageFx");
                }
            }
            if (m_unk1B0 == 1) {
                AttachSmokeEffect();
            }
            m_unk2B4 = 2;
        } else if (m_unk2B4 != 1) {
            if (!(ChangeDamageFxInterval__15EntityBaseClassFUif(this, m_unk238, 90.0f) & 0xFF)) {
                m_unk238 = CreateDamageFx__15EntityBaseClassFfUi(this, 90.0f, (m_unk1B0 == 1) ? 0x830002AAull : 0ull);
                if (m_unk238 == 0) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x9FE, "m_hDamageFx");
                }
            }
            m_unk2B4 = 1;
        }
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

// FUNCTION: 0x002049F0 InJuggleAirspace__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::InJuggleAirspace() {
    float fTime;

    fTime = ((PMNode *)m_unk3C)->GetFrameTime();
    if (m_unk140 == ClockworkSoulsucker_Small_AirJuggleSeq && fTime < 21.0f) {
        return 1;
    }
    if (m_unk140 == ClockworkSoulsucker_Small_JuggleSeq && fTime < 17.0f) {
        return 1;
    }
    if (m_unk140 == ClockworkSoulsucker_Small_LaunchSeq && fTime < 30.0f) {
        return 1;
    }
    if (m_unk140 == ClockworkSoulsucker_Small_KnockUpSeq && fTime < 23.0f) {
        return 1;
    }
    return 0;
}

// DRAFT: 0x00204EA0 SoulsInRange__19ClockworkSoulsuckerFv
// note: 24 lines; register swap (ours i=s0, off=s1), loop-tail order and range-test branch shape differ. Tried: off before i, for-header steps (26), pointer local (37), range test forms (same count).
int ClockworkSoulsucker::SoulsInRange() {
    unsigned int i;
    unsigned int off;
    float (*pBox)[4];
    if (mTempArray__15EntityBaseClass.m_pData != 0) {
        mTempArray__15EntityBaseClass.m_count = 0;
        mTempArray__15EntityBaseClass.m_unk04 = 0;
    }
    pBox = (float (*)[4])((char *)this + 0x190);
    if (m_unk3C != 0) {
        pBox = (float (*)[4])(m_unk3C + 0x80);
    }
    GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 1, &mTempArray__15EntityBaseClass, pBox, 30.0f, 8, true, false);
    off = 0;
    for (i = 0; i < (unsigned int)mTempArray__15EntityBaseClass.m_count; i++) {
        ApparitionState *p = ApparitionIsValid__15EntityBaseClassFUi(i < (unsigned int)mTempArray__15EntityBaseClass.m_count ? *(unsigned int *)((char *)mTempArray__15EntityBaseClass.m_pData + off) : 0);
        int st = p->m_unk1B0;
        if (st == 4 || (unsigned int)(st - 0x14) < 2U || st == 0x16) {
            return 1;
        }
        off += 4;
    }
    return 0;
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

// FUNCTION: 0x00204CD0 CheckBlockAttack__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::CheckBlockAttack() {
    MathAPI *pPlayer;

    pPlayer = mPlayerAPI__13EntityManager;
    if (pPlayer == 0) {
        CdsAssert("ClockworkSoulsucker.cpp", 0x8F9, "pPlayer");
    }
    if (m_unk22C > 0 && *((unsigned char *)pPlayer + 0x23D2) != 0 &&
        *((unsigned short *)((char *)pPlayer + 0x15E)) != 0xD &&
        *((int *)((char *)pPlayer + 0x1CC)) == (int)m_unk4) {
        if (m_unk1B0 == 1) {
            if (InBlockableState()) {
                if (Distance__7MathAPIFPA4_fPA4_f(
                        (*((int *)((char *)pPlayer + 0x3C)) != 0) ? (void *)(*((int *)((char *)pPlayer + 0x3C)) + 0x80) : (void *)((char *)pPlayer + 0x190),
                        (float (*)[4])((m_unk3C != 0) ? (char *)(m_unk3C + 0x80) : (char *)this + 0x190)) <= 20.0f &&
                    PlayerFacingUs() != 0 && MathAPI::RandomIntRange(0, 0x63) < 0x28) {
                    m_unk25C = 0;
                    SetState__15EntityBaseClassFi(this, 0xB);
                }
            }
        } else {
            if (Distance__7MathAPIFPA4_fPA4_f(
                    (m_unk3C != 0) ? (void *)(m_unk3C + 0x80) : (void *)((char *)this + 0x190),
                    (float (*)[4])((char *)this + 0x200)) < m_unk1D4) {
                if (InBlockableState()) {
                    if (Distance__7MathAPIFPA4_fPA4_f(
                            (*((int *)((char *)pPlayer + 0x3C)) != 0) ? (void *)(*((int *)((char *)pPlayer + 0x3C)) + 0x80) : (void *)((char *)pPlayer + 0x190),
                            (float (*)[4])((m_unk3C != 0) ? (char *)(m_unk3C + 0x80) : (char *)this + 0x190)) <= 20.0f &&
                        PlayerFacingUs() != 0 && MathAPI::RandomIntRange(0, 0x63) < 0x28) {
                        m_unk25C = 0;
                        SetState__15EntityBaseClassFi(this, 0x16);
                    }
                }
            }
        }
    }
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

// DRAFT: 0x00205000 DetermineNewState__19ClockworkSoulsuckerFv
// note: first draft, not yet compared
int ClockworkSoulsucker::DetermineNewState() {
    char *pTarget = (char *)GetTarget();
    int nTargetMesh = *(int *)(pTarget + 0x3C);
    float fTargetDist;
    float fSelfDist;

    char *pTargetPos = pTarget + 0x190;
    if (nTargetMesh != 0) {
        pTargetPos = (char *)(nTargetMesh + 0x80);
    }
    fTargetDist = Distance__7MathAPIFPA4_fPA4_f((char *)this + 0x200, (float (*)[4])pTargetPos);
    if (m_unk3C != 0) {
        fSelfDist = Distance__7MathAPIFPA4_fPA4_f((char *)this + 0x200, (float (*)[4])(m_unk3C + 0x80));
    } else {
        fSelfDist = Distance__7MathAPIFPA4_fPA4_f((char *)this + 0x200, (float (*)[4])((char *)this + 0x190));
    }

    if (m_unk1B0 != 0) {
        if (m_bSuckingSemaphoreBusy__19ClockworkSoulsucker == 0 && SoulsInRange()) {
            EnableSleep__15EntityBaseClassFbb(this, 0, 0);
            if (m_bSuckingActive__19ClockworkSoulsucker != 0) {
                CdsAssert("ClockworkSoulsucker.cpp", 0x8AF, "m_bSuckingActive == false");
            }
            m_bSuckingSemaphoreBusy__19ClockworkSoulsucker = 1;
            m_SuckerRef__19ClockworkSoulsucker = (int)m_unk4;
            return 6;
        }
        if (fTargetDist <= m_unk1D4) {
            return 7;
        }
        return DetermineIdleState();
    }
    if (m_unk2B8 != 0) {
        return 0x1D;
    }
    if (m_bSuckingSemaphoreBusy__19ClockworkSoulsucker == 0 && SoulsInRange()) {
        EnableSleep__15EntityBaseClassFbb(this, 0, 0);
        if (m_bSuckingActive__19ClockworkSoulsucker != 0) {
            CdsAssert("ClockworkSoulsucker.cpp", 0x895, "m_bSuckingActive == false");
        }
        m_bSuckingSemaphoreBusy__19ClockworkSoulsucker = 1;
        m_SuckerRef__19ClockworkSoulsucker = (int)m_unk4;
        return 0x12;
    }
    if (fSelfDist > m_unk1D4) {
        return 0x11;
    }
    if (fTargetDist <= m_unk1D4 || fTargetDist <= fSelfDist) {
        return 0x10;
    }
    return DetermineIdleState();
}

// FUNCTION: 0x002051D0 DeleteTimers__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::DeleteTimers() {
    mTimerAPI__13EntityManager.KillTimer(m_unk240);
    mTimerAPI__13EntityManager.KillTimer(m_unk244);
    m_unk240 = 0;
    m_unk244 = 0;
}

// DRAFT: 0x00205220 FaceHit__19ClockworkSoulsuckerFv
// note: 42 lines differ; original E-block is an out-of-line beq, ours inline bne; chain order and tail s0 load differ. Tried: early-return vs single exit, chain orders (E-first 42, 0x82000007-first 43), cached physics pointer (42).
void ClockworkSoulsucker::FaceHit() {
    float vec[4];
    void *pMath;
    float *pVec;
    float fY;
    int nMode;

    pMath = *(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(pMath, vec);
    if (*(int *)((char *)pMath + 0x3C) != 0) {
        pVec = (float *)(*(int *)((char *)pMath + 0x3C) + 0x90);
    } else {
        pVec = (float *)((char *)pMath + 0x1A0);
    }
    fY = pVec[1];
    nMode = *(int *)((char *)*(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x154);
    if (nMode != 0x82000010) {
        if (nMode == 0x8200000E) {
            fY = fY - (-150.0f);
        } else if (nMode == 0x82000007) {
            fY = fY - 150.0f;
        } else {
            fY = fY - 180.0f;
        }
        if (m_unk3C != 0) {
            pVec = (float *)(m_unk3C + 0x90);
        } else {
            pVec = (float *)((char *)this + 0x1A0);
        }
        pVec[1] = fY;
        if (m_unk3C != 0) {
            pVec = (float *)(m_unk3C + 0x90);
        } else {
            pVec = (float *)((char *)this + 0x1A0);
        }
        *(float *)((char *)m_unk38 + 0x11C) = Round180__Ff(pVec[1]);
    }
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

// FUNCTION: 0x002055A0 GetSuckingPos__19ClockworkSoulsuckerFRA4_f
int ClockworkSoulsucker::GetSuckingPos(float (&)[4]) {
    ClockworkSoulsucker *pSucker;
    PMNode *pNeck;

    if (m_bSuckingActive__19ClockworkSoulsucker != 0) {
        if (m_SuckerRef__19ClockworkSoulsucker == 0) {
            CdsAssert("ClockworkSoulsucker.cpp", 0x7E8, "m_SuckerRef");
        }
        pSucker = (ClockworkSoulsucker *)ApparitionIsValid__15EntityBaseClassFUi(m_SuckerRef__19ClockworkSoulsucker);
        if (pSucker == 0) {
            CdsAssert("ClockworkSoulsucker.cpp", 0x7EA, "pSucker");
        }
        if (pSucker->m_unk3C == 0) {
            CdsAssert("ClockworkSoulsucker.cpp", 0x7EC, "pSucker->GetMeshNode()");
        }
        pNeck = ((PMNode *)pSucker->m_unk3C)->Find(0xD0A0801EU);
        if (pNeck == 0) {
            CdsAssert("ClockworkSoulsucker.cpp", 0x7EF, "pNeckJoint");
        }
        *(float *)((char *)this + 0x0) = *(float *)((char *)pNeck + 0x70);
        *(float *)((char *)this + 0x4) = *(float *)((char *)pNeck + 0x74);
        *(float *)((char *)this + 0x8) = *(float *)((char *)pNeck + 0x78);
        *(float *)((char *)this + 0xC) = *(float *)((char *)pNeck + 0x7C);
        return 1;
    }
    return 0;
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

// DRAFT: 0x002056F0 OnTimerEvent__19ClockworkSoulsuckerFUi
// note: DIFF 89. Frame 0x20 vs 0x30: original keeps m_unk248 in f20 across the second Find (lwc1 before jal); ours sinks the load after the call. Tried float local hoisted above first Find (same DIFF).
void ClockworkSoulsucker::OnTimerEvent(unsigned int nTimer) {
    static char init;
    static int aAFTERpausesec;

    if (nTimer == m_unk240) {
        m_unkDC = 0;
        if (m_unk38) {
            m_unk38->SetVelocity(0.0f, 0.0f);
        }
        if (m_unk3C) {
            if (((PMNode *)m_unk3C)->Find(0x0700104E)) {
                *(float *)((char *)((PMNode *)m_unk3C)->Find(0x0700104E) + 0x90) = m_unk248;
            }
            ((PMNode *)m_unk3C)->SetFrameRate(m_unk23C, true);
        }
        EffectObj *pEffect = mEffectAPI__13EntityManager.EffectValid(m_unk2A4);
        if (pEffect) {
            pEffect->m_unk4->SetFrameRate(m_unk23C, true);
        }
        if (!init) {
            aAFTERpausesec = 5;
            init = 1;
        }
        m_unk244 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, aAFTERpausesec, true);
        m_unk240 = 0;
        return;
    }
    if (nTimer == m_unk244) {
        m_unk244 = 0;
        return;
    }
    if (nTimer == m_unk25C) {
        m_unk25C = 0;
        return;
    }
    if (nTimer == m_unk264) {
        m_unk264 = 0;
        return;
    }
    if (nTimer == m_unk268) {
        m_unk268 = 0;
        return;
    }
    if (nTimer == m_unk2AC) {
        m_unk2AC = 0;
        return;
    }
    if (nTimer == m_unk2BC) {
        m_unk2BC = 0;
    }
}

// DRAFT: 0x00205850 OnHitEvent__19ClockworkSoulsuckerFP15EntityBaseClassiUiUi
// note: DIFF 93. Float block at 0x138-0x1AC matches. Left: branch offsets at 0x4C/0x70/0xA0/0xD4/0xE8/0x1F0, dead addiu v0,0xB vs 0x2 at 0x90, m_unk1B0 far bne at 0x208, timer block and mask order at 0x210-0x264. Tried: operand swap (102), compound fAngle += 180.0f (93), merged return-0 tails (102), if/else for m_unk1B0 (93, reverted).
int ClockworkSoulsucker::OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB) {
    int nAnim = m_unk20;
    if (m_unkF4 != 0) {
        int nLeft = m_unk22C - nDamage;
        if (nLeft > 0) {
            m_unk22C = nLeft;
            return 1;
        }
    }
    if (m_unk2AC != 0 || nAnim == 0x18) {
        return 0;
    }
    StopAllSoundsByObject__15EntityBaseClassFv(this);
    if (m_unk140 == ClockworkSoulsucker_DeathBottomWiggleSeq) {
        SetState__15EntityBaseClassFi(this, 0xE);
        return 2;
    }
    if (nAnim == 2 && ((PMNode *)m_unk3C)->GetFrameTime() < 19.0f) {
        return 4;
    }
    if (nAnim == 0x1D) {
        return 4;
    }
    if (m_unk1B0 == 0) {
        PlaySound__15EntityBaseClassFUi(this, 0x1D6);
    } else {
        PlaySound__15EntityBaseClassFUi(this, 0x5E);
    }
    float fAngle = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (void *)(*(int *)((char *)pAttacker + 0x3C) + 0x80));
    fAngle += 180.0f;
    float *pSrc = (m_unk3C != 0) ? (float *)(m_unk3C + 0x90) : (float *)((char *)this + 0x1A0);
    float fPos = pSrc[1] + fAngle;
    if (fPos < -180.0f) {
        fPos += 360.0f;
    } else if (fPos > 180.0f) {
        fPos -= 360.0f;
    }
    m_unkD8 = fPos;
    m_unkDC = 0x3E99999A;
    m_unk22C -= nDamage;
    m_unk250 = nA;
    if (m_unk22C <= 0) {
        DeleteTimers();
        ReleaseSemaphoreIfOwned();
        SetState__15EntityBaseClassFi(this, 0xD);
        return 2;
    }
    UpdateDamageFx();
    if (m_unk1B0 != 1) {
        ReleaseSemaphoreIfOwned();
        SetState__15EntityBaseClassFi(this, 0x1E);
        return 1;
    }
    if (m_unk240 == 0 && m_unk244 == 0) {
        m_unk23C = ((PMNode *)m_unk3C)->GetFrameRate();
        ((PMNode *)m_unk3C)->SetFrameRate(0.0f, true);
        EffectObj *pEffect = mEffectAPI__13EntityManager.EffectValid(m_unk2A4);
        if (pEffect != 0) {
            pEffect->m_unk4->SetFrameRate(0.0f, true);
        }
        m_unk240 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 0xE, true);
        ((m_unk3C) ? (void)0 : CdsAssert("ClockworkSoulsucker.cpp", 0x768, "GetMeshNode()"));
        if (((PMNode *)m_unk3C)->Find(0x0700104EU) != 0) {
            m_unk248 = *(float *)((char *)((PMNode *)m_unk3C)->Find(0x0700104EU) + 0x90);
        }
    }
    {
        unsigned int nFlags = nA & ~0x5C0U;
        if (nFlags == 8 || nFlags == 0x2D) {
            FaceHit();
            DeleteEffects();
            ReleaseSemaphoreIfOwned();
            SetState__15EntityBaseClassFi(this, 0xC);
            DeleteTimers();
        }
    }
    return 1;
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
    m_unk248 = 0.0f;
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
