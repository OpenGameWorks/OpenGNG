// FLAGS: -str readonly
#include "ClockworkSoulsucker.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

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
    unsigned int CreateOneshot(unsigned int, unsigned int, float (*)[4], float (*)[4], class EntityBaseClass *, float, bool, int, bool);
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
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nArg, char cArg, unsigned int nFlags);
extern "C" int ProcessHitBack__15EntityBaseClassFv(void *pThis);
extern "C" float FastMath_Fabs__Ff(float fArg);
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
extern unsigned char ClockworkSoulsucker_GrabHitSeq[108];
extern unsigned char ClockworkSoulsucker_GrabMissSeq[52];
extern unsigned char ClockworkSoulsucker_BlockSeq[60];
extern unsigned char ClockworkSoulsucker_HitSeq[52];
extern unsigned char ClockworkSoulsucker_Small_AirJuggleSeq[52];
extern unsigned char ClockworkSoulsucker_Small_JuggleSeq[52];
extern unsigned char ClockworkSoulsucker_Small_LaunchSeq[52];
extern unsigned char ClockworkSoulsucker_Small_KnockUpSeq[52];
extern unsigned char ClockworkSoulsucker_Small_HitSeq[52];
extern unsigned char ClockworkSoulsucker_Small_HitRightSeq[52];
extern unsigned char ClockworkSoulsucker_Small_HitLeftSeq[52];
extern unsigned char ClockworkSoulsucker_Small_KnockBackSeq[52];
extern unsigned char ClockworkSoulsucker_Small_SmackDownSeq[52];
extern unsigned char ClockworkSoulsucker_Small_CrushSeq[52];
// TODO(header): cases 13-15 foreign declarations
void SpawnBonus__15EntityBaseClassFPfii(void *, float *, int, int);
extern float m_vBonusSpawnOffset[4];
extern unsigned char ClockworkSoulsucker_Small_DeathSeq[68];
extern unsigned char ClockworkSoulsucker_DeathBottomExplodeSeq[68];
// TODO(header): PMNode.h declares SetFrameTime non-virtual; vtable slot 0x10 is its third virtual.
class PMNodeVirtualView {
public:
    virtual ~PMNodeVirtualView();
    virtual int Render(void *pLM, int nArg1, int nArg2);
    virtual void SetFrameTime(float fTime);
};
extern unsigned char ClockworkSoulsucker_LoadMeshSeq[20];
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *, unsigned int *);
extern unsigned char ClockworkSoulsucker_JumpFromShellSeq[20];
extern unsigned char ClockworkSoulsucker_AssembleSeq[20];
extern unsigned char ClockworkSoulsucker_IdleSeq[20];
extern unsigned char ClockworkSoulsucker_SmallIdleSeq[20];
extern unsigned char ClockworkSoulsucker_Small_TauntSeq[20];
extern unsigned char ClockworkSoulsucker_TauntSeq[20];
extern unsigned char ClockworkSoulsucker_WalkForwSeq[20];
extern unsigned char ClockworkSoulsucker_PreyInPlaceSeq[20];
extern unsigned char ClockworkSoulsucker_Small_WalkForwSeq[20];
extern unsigned char ClockworkSoulsucker_Small_PreyInPlaceSeq[20];
extern unsigned char ClockworkSoulsucker_Small_WalkForwOnceSeq[52];
extern unsigned char ClockworkSoulsucker_Small_DashForwSeq[52];
extern unsigned char ClockworkSoulsucker_Small_DashBackSeq[52];
extern unsigned char ClockworkSoulsucker_Small_DodgeSeq[60];
extern unsigned char ClockworkSoulsucker_DoubleChopSeq[64];
extern unsigned char ClockworkSoulsucker_GrowSeq[60];
extern unsigned char ClockworkSoulsucker_DrillSeq[64];
extern unsigned char ClockworkSoulsucker_SonicBoomSeq[60];
extern unsigned char ClockworkSoulsucker_SuckSoulSeq[52];
extern unsigned char ClockworkSoulsucker_Small_SuckSoulSeq[52];
extern "C" void PlaySoundOnFrame__15EntityBaseClassFUiUi(void *, unsigned int, unsigned int);
extern "C" void RemoveFromAttackSystem__15EntityBaseClassFv(void *);
extern "C" void ResetCollisions__15EntityBaseClassFv(void *);
extern "C" void LoadMesh__15EntityBaseClassFUibb(void *, unsigned int, bool, bool);
extern "C" int RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(void *pThis, void *pTarget, unsigned int nFlag);
extern "C" void sceVu0Normalize(void *, void *);
extern "C" void sceVu0ScaleVector(void *, void *, float);
extern "C" void sceVu0SubVector(void *, void *, void *);
extern "C" void sceVu0AddVector(void *, void *, void *);
extern "C" void VectorRotateY__7MathAPIFPA4_ff(void *, float);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__7PhysicsFv(void *);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *, int, unsigned int);
extern "C" float cosf(float x);
extern "C" float sinf(float x);
extern float m_vDefaultSpawnVelocity[4];
extern "C" void *Spawn__13EntityManagerFUibi(void *pThis, unsigned int nClass, bool bFlag, int nArg);
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *pThis, unsigned int nHandle);
extern "C" float RandomFloatRange__7MathAPIFff(float fMin, float fMax);
extern "C" void *TriggerBGAnim__15EntityBaseClassFUiibUi(void *pThis, unsigned int nAnim, int nLoops, bool bFlag, unsigned int nArg);
extern "C" void SetShellStartAndDest__8ZinShellFRA4_fRA4_f(void *pThis, float (*pStart)[4], float (*pDest)[4]);
extern "C" void InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(void *pThis, int nType, void *pA, void *pB, void *pC);

// FUNCTION: 0x00204230 GetHealth__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::GetHealth() {
    return m_unk22C;
}

// FUNCTION: 0x00204240 GetClassName__19ClockworkSoulsuckerFv
const char *ClockworkSoulsucker::GetClassName() {
    return "ClockworkSoulsucker";
}

// FUNCTION: 0x00204250 GetTallyType__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::GetTallyType() {
    return 1;
}

// FUNCTION: 0x00204260 GetArenaWaveID__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::GetArenaWaveID() {
    return m_unk1D8;
}

// FUNCTION: 0x00204270 IsArenaApparition__19ClockworkSoulsuckerFv
bool ClockworkSoulsucker::IsArenaApparition() {
    return m_unk1D8 ? true : false;
}

// FUNCTION: 0x00204280 NeedsToBeWoken__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x1DC);
}

// FUNCTION: 0x00204290 GetWokenVarPos__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::GetWokenVarPos() {
    return 5;
}

// FUNCTION: 0x002042A0 SetInnocentInstanceID__19ClockworkSoulsuckerFUi
void ClockworkSoulsucker::SetInnocentInstanceID(unsigned int value) {
    m_unk234 = value;
}

// FUNCTION: 0x002042B0 AdjustPhysicsForEweedCheck__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::AdjustPhysicsForEweedCheck() {
    char *pPhys = (char *)m_unk38;
    if (pPhys != 0) {
        *(int *)(pPhys + 0x84) = 0x40200000;
        *(int *)(pPhys + 0x94) = 0x40200000;
    }
}

// DRAFT: 0x002042D0 ScaleSpikes__19ClockworkSoulsuckerFf
// note: 20 words differ; original recomputes &aNodes (addiu v1,sp,0x60) each iteration then adds the byte offset, ours folds sp+0x60 into the lw displacement (size 0x19C vs 0x1A0). Tried do/while, for, pointer-walk, byte-offset, PMNode *aNodes[4] (do/while and for).
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
// note: 18 words differ; original fills the m_unk3C beqz delay slot with the miRandom reload (lw at 0x40), ours leaves a nop and the else arm's lui in the next slot. Tried truthiness, bit-compare, early-return, zero-first (40), else-if (40), block-scoped nBit, else-first, (x) != 0 spelling, local PMNode pointer.
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

// FUNCTION: 0x00204560 EndGrab__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::EndGrab() {
    SetState__15EntityBaseClassFi(this, 0x19);
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

// FUNCTION: 0x00204EA0 SoulsInRange__19ClockworkSoulsuckerFv
int ClockworkSoulsucker::SoulsInRange() {
    unsigned int off;
    unsigned int i;
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
    for (i = 0, off = 0; i < (unsigned int)mTempArray__15EntityBaseClass.m_count; i++) {
        ApparitionState *p = ApparitionIsValid__15EntityBaseClassFUi(i < (unsigned int)mTempArray__15EntityBaseClass.m_count ? *(unsigned int *)((char *)mTempArray__15EntityBaseClass.m_pData + off) : 0);
        unsigned int st = p->m_unk1B0;
        if (st == 4 || (st - 0x14) <= 1U || st == 0x16) {
            return 1;
        }
        off += 4;
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

// FUNCTION: 0x00205220 FaceHit__19ClockworkSoulsuckerFv
void ClockworkSoulsucker::FaceHit() {
    float vFwd[4];
    EntityBaseClass *pPlayer = *(EntityBaseClass **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(pPlayer, &vFwd);
    char *pSrc = *(char **)((char *)pPlayer + 0x3C);
    pSrc = pSrc ? pSrc + 0x90 : (char *)pPlayer + 0x1A0;
    float fDelta = *(float *)(pSrc + 4);
    int nState = *(int *)((char *)*(EntityBaseClass **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x154);
    switch (nState) {
    case 0x82000007:
        fDelta = fDelta - 150.0f;
        break;
    case 0x8200000E:
        fDelta = fDelta - (-150.0f);
        break;
    case 0x82000010:
        return;
    default:
        fDelta = fDelta - 180.0f;
        break;
    }
    char *pDst = m_unk3C ? (char *)m_unk3C + 0x90 : (char *)this + 0x1A0;
    *(float *)(pDst + 4) = fDelta;
    char *pDst2 = m_unk3C ? (char *)m_unk3C + 0x90 : (char *)this + 0x1A0;
    char *pObj = (char *)m_unk38;
    *(float *)(pObj + 0x11C) = Round180__Ff(*(float *)(pDst2 + 4));
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

// FUNCTION: 0x002056E0 SetEditableVars__19ClockworkSoulsuckerFPc
void ClockworkSoulsucker::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x48);
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

// DRAFT: 0x00205C20 Execute__19ClockworkSoulsuckerFv
// note: DIFF 2782 words, size 0x2AFC vs 0x2D5C: all switch cases have bodies, but prologue frame is 0xD0 (original 0x30), first reloc diff at CheckBlockAttack 0x2D3C, and case 10 and case 30 arm order are unverified.
void ClockworkSoulsucker::Execute() {
    if (m_unk2C8 != 0) {
        int state = m_unk20;
        if (state != 0x1D) {
            printf("SOULSUCKER BUG! --> not in CWSS_GROW when debug var thinks it is! state = %d\n", state);
            m_unk2C8 = 0;
        }
    }
    if (m_unk2C9 != 0) {
        int state = m_unk20;
        if (state != 6 && state != 0x12) {
            if (m_SuckerRef__19ClockworkSoulsucker == (int)m_unk4) {
                printf("SOULSUCKER BUG! --> not in CWSS_GROW when debug var thinks it is! state = %d\n", state);
                ReleaseSemaphoreIfOwned();
            }
            m_unk2C9 = 0;
        }
    }
    if (m_unk38 != 0 && (*(int *)((char *)m_unk38 + 0x108) & 0x400)) {
        WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0);
        if (m_unk38 != 0) {
            __dl__FPv(m_unk38);
            m_unk38 = 0;
        }
        m_unk10C &= 0xFDFFFFFF;
        EnableSleep__15EntityBaseClassFbb(this, 0, 0);
        m_unk22C = 0;
        SetState__15EntityBaseClassFi(this, 0xF);
        ReleaseSemaphoreIfOwned();
        if (m_unk2C8 != 0) {
            m_unk2C8 = 0;
        }
        if (m_unk2C9 != 0) {
            m_unk2C9 = 0;
        }
    } else {
        if (m_unk240 != 0) {
            if (m_unk3C != 0) {
                PMNode *pNode = ((PMNode *)m_unk3C)->Find(0x0700104E);
                if (pNode != 0) {
                    float *pNodeF = (float *)((char *)pNode + 0x90);
                    float *pTimerF = (float *)&m_unk24C;
                    *pNodeF = *pNodeF + *pTimerF;
                    float fTimer = *pTimerF - 1.0f;
                    *pTimerF = fTimer;
                    if (fTimer <= -2.0f) {
                        *pTimerF = 1.0f;
                    }
                }
            } else {
                printf("SOULSUCKER BUG (ALERT JOEY IMMEDIATELY): GetMeshNode() returned NULL when m_iPauseTimerID NON-NULL!!!\n");
            }
        }
        if (ProcessHitBack__15EntityBaseClassFv(this) != 0) {
            Physics *pPhys = m_unk38;
            float *pVel = (float *)pPhys;
            if (FastMath_Fabs__Ff(pVel[0]) < 0.05f && FastMath_Fabs__Ff(pVel[1]) < 0.05f && FastMath_Fabs__Ff(pVel[2]) < 0.05f) {
                pVel[0] = 0.0f;
                pVel[1] = 0.0f;
                pVel[2] = 0.0f;
                m_unkDC = 0;
                if (m_unk38 != 0) {
                    m_unk38->SetVelocity(0.0f, 0.0f);
                }
            }
        }
        switch (m_unk20) {
        case -1:
            if (m_unkE9 != 0) {
                m_unk200 = m_unk1C8;
                m_unk204 = m_unk1CC;
                m_unk208 = m_unk1D0;
                char *pA0 = m_unk190;
                if (m_unk3C != 0) {
                    pA0 = (char *)m_unk3C + 0x80;
                }
                if (!(Distance__7MathAPIFPA4_fPA4_f(pA0, (float (*)[4])&m_unk200) <= m_unk1D4)) {
                    printf("ERROR - Clockwork Soulsucker shutdown as initial position wasn't inside attack radius\n");
                    SetState__15EntityBaseClassFi(this, -2);
                    return;
                }
                m_unk10C &= 0xF8FFFFFF;
                m_unk10C |= 0x071B1902;
                m_unk103 = 0x40;
                if (m_unk1B8 == 0.0f) {
                    if ((m_unk1BC == 0.0f) && (m_unk1C0 == 0.0f)) {
                        char *pV0 = m_unk190;
                        if (m_unk3C != 0) {
                            pV0 = (char *)m_unk3C + 0x80;
                        }
                        m_unk1B8 = ((float *)pV0)[0];
                        char *pV1 = m_unk190;
                        if (m_unk3C != 0) {
                            pV1 = (char *)m_unk3C + 0x80;
                        }
                        m_unk1BC = ((float *)pV1)[1];
                        char *pV2 = m_unk190;
                        if (m_unk3C != 0) {
                            pV2 = (char *)m_unk3C + 0x80;
                        }
                        m_unk1C0 = ((float *)pV2)[2];
                    }
                }
                m_unk15C = 0x32;
                m_unk15E = 0;
                if (m_unk1D8 != 0) {
                    m_unk1C4 = m_unk18C;
                    m_unk1D4 = m_unk18C;
                }
                if ((m_unk1E0 != 2) && (m_unk1E0 != 7)) {
                    char *pTarget = (char *)GetTarget();
                    int nTarget3C = *(int *)(pTarget + 0x3C);
                    char *pA1 = pTarget + 0x190;
                    if (nTarget3C != 0) {
                        pA1 = (char *)nTarget3C + 0x80;
                    }
                    m_unk224 = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pA1);
                    char *pV4;
                    if (m_unk3C != 0) {
                        pV4 = *(char **)((char *)m_unk3C + 0x90);
                    } else {
                        pV4 = (char *)m_unk1A0;
                    }
                    *(float *)(pV4 + 4) = m_unk224;
                }
                m_unk210 = m_unk1B8;
                m_unk214 = m_unk1BC;
                m_unk218 = m_unk1C0;
            }
            {
                char *pPlayer = (char *)mPlayerAPI__13EntityManager;
                int nPlayer3C = *(int *)(pPlayer + 0x3C);
                char *pPlayerPos = pPlayer + 0x190;
                if (nPlayer3C != 0) {
                    pPlayerPos = (char *)nPlayer3C + 0x80;
                }
                if (Distance__7MathAPIFPA4_fPA4_f(&m_unk210, (float (*)[4])pPlayerPos) <= m_unk1C4) {
                    if (m_unk38 == 0) {
                        void *p = __nw__FUi(0x120U);
                        if (p != 0) {
                            p = __ct__7PhysicsFv(p);
                        }
                        m_unk38 = (Physics *)p;
                        if (m_unk38 == 0) {
                            CdsAssert("ClockworkSoulsucker.cpp", 0x239, "mpPhysics");
                        }
                    }
                    m_unk38->SetPhysicsType(0x12, 0);
                    if (m_unkD4 == 0) {
                        void *p = __nw__FUi(0x10U);
                        if (p != 0) {
                            p = __ct__6ShadowFQ26Shadow10ShadowTypeUi(p, 1, 0x87000008U);
                        }
                        m_unkD4 = (Physics *)p;
                        if (m_unkD4 == 0) {
                            CdsAssert("ClockworkSoulsucker.cpp", 0x240, "mpShadow");
                        }
                    }
                    if (m_unk1E0 != 0) {
                        SetState__15EntityBaseClassFi(this, 0);
                    } else {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_LoadMeshSeq);
                        AdjustPhysicsForEweedCheck();
                        SetupType();
                        SetState__15EntityBaseClassFi(this, DetermineNewState());
                    }
                }
            }
            /* fall through */
        case -2:
        case 26:
        block_533:
            if ((m_unk20 >= 0) && (m_unkF4 == 0)) {
                CheckBlockAttack();
            }
            return;
        case 0:
            if (m_unkE9 != 0) {
                switch (m_unk1E0) {
                case 1:
                case 3: {
                    void *pShell = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0xF, false, 0);
                    float v60[4];
                    float v70[4];
                    float fz;
                    float *pVec;
                    float f2;
                    float f3;
                    float f8;
                    float fC;
                    if (pShell == 0) {
                        CdsAssert("ClockworkSoulsucker.cpp", 0x25B, "pContainerEnt");
                    }
                    m_unk220 = *(unsigned int *)((char *)pShell + 4);
                    EnableSleep__15EntityBaseClassFbb(this, false, false);
                    if (m_unk1E0 == 3) {
                        *(int *)((char *)pShell + 0x22C) = 1;
                    }
                    pVec = (float *)m_unk190;
                    if (m_unk3C != 0) {
                        pVec = (float *)(char *)(m_unk3C + 0x80);
                    }
                    f3 = *(float *)&m_unk1E4;
                    f2 = pVec[0];
                    f8 = *(float *)&m_unk1E8;
                    fC = *(float *)&m_unk1EC;
                    if ((f3 == f2) && (f8 == pVec[1]) && (fC == pVec[2])) {
                        v60[0] = f2;
                        v60[1] = 50.0f + pVec[1];
                        fz = pVec[2];
                    } else if ((f3 == 0.0f) && (f8 == 0.0f) && (fC == 0.0f)) {
                        v60[0] = f2;
                        v60[1] = 50.0f + pVec[1];
                        fz = pVec[2];
                    } else {
                        v60[0] = f3;
                        v60[1] = f8;
                        fz = fC;
                    }
                    v60[2] = fz;
                    v70[0] = pVec[0];
                    v70[1] = pVec[1];
                    v70[2] = pVec[2];
                    SetShellStartAndDest__8ZinShellFRA4_fRA4_f(pShell, (float (*)[4])v60, (float (*)[4])v70);
                    if (m_unk1F4 != 0) {
                        *(int *)((char *)pShell + 0x224) = m_unk1F4;
                        *(unsigned int *)((char *)pShell + 0x228) = m_unk4;
                    }
                    goto block_116;
                }
                case 2:
                    if (m_unk1F4 != 0) {
                        TriggerBGAnim__15EntityBaseClassFUiibUi(this, m_unk1F4, -1, false, 0);
                    }
                    SetState__15EntityBaseClassFi(this, 1);
                    return;
                case 4:
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)&ClockworkSoulsucker_LoadMeshSeq);
                    AdjustPhysicsForEweedCheck();
                    SetupType();
                    SetState__15EntityBaseClassFi(this, DetermineNewState());
                    return;
                case 7:
                    if (m_unk1F4 != 0) {
                        TriggerBGAnim__15EntityBaseClassFUiibUi(this, m_unk1F4, -1, false, 0);
                    }
                    SetState__15EntityBaseClassFi(this, 1);
                    PlaySound__15EntityBaseClassFUi(this, 0x1F9);
                    return;
                default:
                    CdsAssert("ClockworkSoulsucker.cpp", 0x2AA, "0");
                    goto block_116;
                }
            } else {
block_116:
                if (m_unk1E0 != 1) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x2BF, "0");
                } else {
                    void *pApp = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk220);
                    if ((pApp == 0) || (*(unsigned char *)((char *)pApp + 0x22D) != 0)) {
                        m_unk228 = RandomFloatRange__7MathAPIFff(0.0f, 360.0f);
                        SetState__15EntityBaseClassFi(this, 2);
                        EnableSleep__15EntityBaseClassFbb(this, true, false);
                    }
                }
                goto block_533;
            }
            break;
        case 1: {
            float sp80[4];
            char *pVel;
            if (m_unkE9 != 0) {
                *(int *)((char *)m_unk38 + 0x10C) = 0x3E4CCCCD;
                GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, sp80);
                sceVu0Normalize(sp80, sp80);
                sceVu0ScaleVector(sp80, sp80, 0.1f);
                *(u_long128 *)m_unk38 = *(u_long128 *)sp80;
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_LoadMeshSeq);
                AdjustPhysicsForEweedCheck();
                SetupType();
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_JumpFromShellSeq);
            }
            pVel = (char *)m_unk38;
            if (pVel == 0) {
                pVel = 0;
            }
            if ((*(float *)pVel == 0.0f) && (*(float *)(pVel + 4) == 0.0f) && (*(float *)(pVel + 8) == 0.0f)) {
                SetState__15EntityBaseClassFi(this, 3);
            }
            goto block_533;
        }
        case 2: {
            float sp90[4];
            float fCos;
            float fSin;
            char *pVel;
            if (m_unkE9 != 0) {
                fCos = cosf(0.017453292f * m_unk228);
                fSin = sinf(0.017453292f * m_unk228);
                *(int *)((char *)m_unk38 + 0x10C) = 0x3E4CCCCD;
                sp90[0] = m_vDefaultSpawnVelocity[2] * fSin + m_vDefaultSpawnVelocity[0] * fCos;
                sp90[1] = m_vDefaultSpawnVelocity[1];
                sp90[2] = m_vDefaultSpawnVelocity[2] * fCos - m_vDefaultSpawnVelocity[0] * fSin;
                *(u_long128 *)m_unk38 = *(u_long128 *)sp90;
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_JumpFromShellSeq);
                AdjustPhysicsForEweedCheck();
                SetupType();
            }
            pVel = (char *)m_unk38;
            if (pVel == 0) {
                pVel = 0;
            }
            if ((*(float *)pVel == 0.0f) && (*(float *)(pVel + 4) == 0.0f) && (*(float *)(pVel + 8) == 0.0f)) {
                SetState__15EntityBaseClassFi(this, 3);
            }
            goto block_533;
        }
        case 3:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_AssembleSeq);
            }
            FaceTarget(0.06f);
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 4: {
            char *pPhys;
            void *pTgt;
            int nSub;
            void *pDistThis;
            if (m_unkE9 != 0) {
                pPhys = (char *)m_unkD4;
                if (pPhys != 0) {
                    *(int *)pPhys = 1;
                    {
                        char *pSub = *(char **)(pPhys + 0xC);
                        if (pSub != 0) {
                            *(int *)(pSub + 0x18) = 1;
                        }
                    }
                }
                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                EnableSleep__15EntityBaseClassFbb(this, true, false);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_IdleSeq);
            }
            FaceTarget(0.06f);
            pTgt = GetTarget();
            nSub = *(int *)((char *)pTgt + 0x3C);
            pDistThis = (char *)pTgt + 0x190;
            if (nSub != 0) {
                pDistThis = (void *)(nSub + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f(pDistThis, (float (*)[4])&m_unk200) < m_unk1D4) {
                SetState__15EntityBaseClassFi(this, 7);
                return;
            }
            if (m_unk160 == 0) {
                if (MathAPI::RandomIntRange(0, 4) != 0) {
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_IdleSeq);
                } else {
                    SetState__15EntityBaseClassFi(this, 5);
                }
            }
            goto block_533;
        }
        case 27: {
            char *pPhys;
            void *pTgt;
            int nSub;
            void *pDistThis;
            if (m_unkE9 != 0) {
                pPhys = (char *)m_unkD4;
                if (pPhys != 0) {
                    *(int *)pPhys = 1;
                    {
                        char *pSub = *(char **)(pPhys + 0xC);
                        if (pSub != 0) {
                            *(int *)(pSub + 0x18) = 1;
                        }
                    }
                }
                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                EnableSleep__15EntityBaseClassFbb(this, true, false);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_SmallIdleSeq);
            }
            FaceTarget(0.06f);
            pTgt = GetTarget();
            nSub = *(int *)((char *)pTgt + 0x3C);
            pDistThis = (char *)pTgt + 0x190;
            if (nSub != 0) {
                pDistThis = (void *)(nSub + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f(pDistThis, (float (*)[4])&m_unk200) < m_unk1D4) {
                SetState__15EntityBaseClassFi(this, 0x10);
                return;
            }
            if (m_unk160 == 0) {
                if (MathAPI::RandomIntRange(0, 4) != 0) {
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_SmallIdleSeq);
                } else {
                    SetState__15EntityBaseClassFi(this, 0x1C);
                }
            }
            goto block_533;
        }
        case 28:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_TauntSeq);
            }
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1D7, 0xD);
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 5: {
            unsigned int *pSeq;
            if (m_unkE9 != 0) {
                if (MathAPI::RandomIntRange(0, 1) == 0) {
                    pSeq = (unsigned int *)ClockworkSoulsucker_TauntSeq;
                } else {
                    pSeq = (unsigned int *)ClockworkSoulsucker_Small_TauntSeq;
                }
                PlaySequence__15EntityBaseClassFPUi(this, pSeq);
            }
            if (m_unk140 == (void *)ClockworkSoulsucker_TauntSeq) {
                PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1D7, 0xB);
                PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1D7, 0x20);
            } else {
                PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1D7, 0xD);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        }
        case 7: {
            float (*pSelfPos)[4];
            void *pTgt;
            int nSub;
            void *pTgtPos;
            float fDist;
            float fDist2;
            int nRand;

            pSelfPos = (float (*)[4])m_unk190;
            if (m_unk3C != 0) {
                pSelfPos = (float (*)[4])(m_unk3C + 0x80);
            }
            pTgt = GetTarget();
            nSub = *(int *)((char *)pTgt + 0x3C);
            pTgtPos = (char *)pTgt + 0x190;
            if (nSub != 0) {
                pTgtPos = (void *)(nSub + 0x80);
            }
            fDist = Distance__7MathAPIFPA4_fPA4_f(pTgtPos, pSelfPos);
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_WalkForwSeq);
                PlaySound__15EntityBaseClassFUi(this, 0x1D8);
            }
            FaceTarget(0.06f);
            pTgt = GetTarget();
            nSub = *(int *)((char *)pTgt + 0x3C);
            pTgtPos = (char *)pTgt + 0x190;
            if (nSub != 0) {
                pTgtPos = (void *)(nSub + 0x80);
            }
            fDist2 = Distance__7MathAPIFPA4_fPA4_f(pTgtPos, (float (*)[4])&m_unk200);
            if (!(fDist2 <= m_unk1D4)) {
                StopAllSoundsByObject__15EntityBaseClassFv(this);
                SetState__15EntityBaseClassFi(this, DetermineIdleState());
            } else if (m_unk25C == 0) {
                StopAllSoundsByObject__15EntityBaseClassFv(this);
                if (!(fDist <= 11.0f)) {
                    if (m_unk2BC == 0 && RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, m_unk260, 0U) != 0) {
                        SetState__15EntityBaseClassFi(this, 0xA);
                    } else {
                        goto block_210;
                    }
                } else {
block_210:
                    if (fDist <= 11.0f) {
                        if (!(fDist <= 8.0f) && RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, m_unk260, 0U) != 0) {
                            nRand = MathAPI::RandomIntRange(0, 4);
                            if (nRand >= 2) {
                                SetState__15EntityBaseClassFi(this, 9);
                            } else if (nRand == 1) {
                                SetState__15EntityBaseClassFi(this, 8);
                            } else if (m_unk2BC == 0) {
                                SetState__15EntityBaseClassFi(this, 0xA);
                            } else {
                                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                            }
                        } else {
                            goto block_223;
                        }
                    } else {
block_223:
                        if (fDist <= 8.0f && RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, m_unk260, 0U) != 0) {
                            nRand = MathAPI::RandomIntRange(0, 4);
                            if (nRand >= 2) {
                                SetState__15EntityBaseClassFi(this, 8);
                            } else if (nRand == 1) {
                                SetState__15EntityBaseClassFi(this, 9);
                            } else if (m_unk2BC == 0) {
                                SetState__15EntityBaseClassFi(this, 0xA);
                            } else {
                                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                            }
                        }
                    }
                }
            } else if (fDist < 6.0f) {
                if (m_unk140 == (void *)ClockworkSoulsucker_WalkForwSeq) {
                    StopAllSoundsByObject__15EntityBaseClassFv(this);
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_PreyInPlaceSeq);
                } else {
                    goto block_239;
                }
            } else {
block_239:
                if (!(fDist <= 6.0f) && m_unk140 == (void *)ClockworkSoulsucker_PreyInPlaceSeq && (*(unsigned char *)(m_unk3C + 0x3F) & 4)) {
                    PlaySound__15EntityBaseClassFUi(this, 0x1D8);
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_WalkForwSeq);
                }
            }
            goto block_533;
        }
        case 16: {
            float (*pSelfPos)[4];
            void *pTgt;
            int nSub;
            void *pTgtPos;
            float fDist;
            float (*pSrc)[4];

            pSelfPos = (float (*)[4])m_unk190;
            if (m_unk3C != 0) {
                pSelfPos = (float (*)[4])(m_unk3C + 0x80);
            }
            pTgt = GetTarget();
            nSub = *(int *)((char *)pTgt + 0x3C);
            pTgtPos = (char *)pTgt + 0x190;
            if (nSub != 0) {
                pTgtPos = (void *)(nSub + 0x80);
            }
            fDist = Distance__7MathAPIFPA4_fPA4_f(pTgtPos, pSelfPos);
            if (m_unkE9 != 0) {
                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_WalkForwSeq);
                PlaySound__15EntityBaseClassFUi(this, 0x1D8);
            }
            FaceTarget(0.08f);
            pTgt = GetTarget();
            nSub = *(int *)((char *)pTgt + 0x3C);
            pTgtPos = (char *)pTgt + 0x190;
            if (nSub != 0) {
                pTgtPos = (void *)(nSub + 0x80);
            }
            if (!(Distance__7MathAPIFPA4_fPA4_f(pTgtPos, (float (*)[4])&m_unk200) <= m_unk1D4)) {
                StopAllSoundsByObject__15EntityBaseClassFv(this);
                SetState__15EntityBaseClassFi(this, DetermineIdleState());
            } else if (m_unk25C == 0) {
                if (fDist < 11.0f && RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, m_unk260, 0U) != 0) {
                    StopAllSoundsByObject__15EntityBaseClassFv(this);
                    SetState__15EntityBaseClassFi(this, 0x17);
                }
            } else if (fDist < 9.0f) {
                if (m_unk140 == (void *)ClockworkSoulsucker_Small_PreyInPlaceSeq) {
                    if (*(unsigned char *)(m_unk3C + 0x3F) & 4) {
                        goto block_265;
                    }
                    goto block_284;
                }
block_265:
                StopAllSoundsByObject__15EntityBaseClassFv(this);
                if (m_unk268 == 0) {
                    pTgt = GetTarget();
                    nSub = *(int *)((char *)pTgt + 0x3C);
                    if (nSub != 0) {
                        pSrc = (float (*)[4])(nSub + 0x80);
                    } else {
                        pSrc = (float (*)[4])((char *)pTgt + 0x190);
                    }
                    *(u_long128 *)m_unk270 = *(u_long128 *)pSrc;
                    pSelfPos = (float (*)[4])m_unk190;
                    if (m_unk3C != 0) {
                        pSelfPos = (float (*)[4])(m_unk3C + 0x80);
                    }
                    sceVu0SubVector(m_unk270, m_unk270, pSelfPos);
                    sceVu0ScaleVector(m_unk270, m_unk270, 2.0f);
                    if (MathAPI::RandomIntRange(0, 1) == 0) {
                        VectorRotateY__7MathAPIFPA4_ff(m_unk270, 45.0f);
                    } else {
                        VectorRotateY__7MathAPIFPA4_ff(m_unk270, -45.0f);
                    }
                    pSelfPos = (float (*)[4])m_unk190;
                    if (m_unk3C != 0) {
                        pSelfPos = (float (*)[4])(m_unk3C + 0x80);
                    }
                    sceVu0AddVector(m_unk270, m_unk270, pSelfPos);
                    RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, m_unk270), 1.0f);
                    SetState__15EntityBaseClassFi(this, 0x14);
                } else if (m_unk264 == 0 && MathAPI::RandomIntRange(0, 3) != 0) {
                    SetState__15EntityBaseClassFi(this, 0x15);
                } else {
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_PreyInPlaceSeq);
                }
            } else {
block_284:
                if (fDist < 14.0f) {
                    pTgt = GetTarget();
                    nSub = *(int *)((char *)pTgt + 0x3C);
                    if (nSub != 0) {
                        pSrc = (float (*)[4])(nSub + 0x80);
                    } else {
                        pSrc = (float (*)[4])((char *)pTgt + 0x190);
                    }
                    *(u_long128 *)m_unk270 = *(u_long128 *)pSrc;
                    pSelfPos = (float (*)[4])m_unk190;
                    if (m_unk3C != 0) {
                        pSelfPos = (float (*)[4])(m_unk3C + 0x80);
                    }
                    sceVu0SubVector(m_unk270, m_unk270, pSelfPos);
                    if (MathAPI::RandomIntRange(0, 1) == 0) {
                        VectorRotateY__7MathAPIFPA4_ff(m_unk270, 70.0f);
                    } else {
                        VectorRotateY__7MathAPIFPA4_ff(m_unk270, -70.0f);
                    }
                    pSelfPos = (float (*)[4])m_unk190;
                    if (m_unk3C != 0) {
                        pSelfPos = (float (*)[4])(m_unk3C + 0x80);
                    }
                    sceVu0AddVector(m_unk270, m_unk270, pSelfPos);
                    RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, m_unk270), 1.0f);
                    SetState__15EntityBaseClassFi(this, 0x13);
                }
            }
            goto block_533;
        }
        case 17: {
            float (*pSelfPos)[4];
            double dDist;

            if (m_unkE9 != 0) {
                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_WalkForwSeq);
                PlaySound__15EntityBaseClassFUi(this, 0x1D8);
            }
            RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, &m_unk200), 0.08f);
            pSelfPos = (float (*)[4])m_unk190;
            if (m_unk3C != 0) {
                pSelfPos = (float (*)[4])(m_unk3C + 0x80);
            }
            dDist = Distance__7MathAPIFPA4_fPA4_f(pSelfPos, (float (*)[4])&m_unk200);
            if (dDist < m_unk1D4 * 0.9) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        }
        case 19:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_WalkForwOnceSeq);
            }
            if (m_unk160 == 0) {
                StopAllSoundsByObject__15EntityBaseClassFv(this);
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 20: {
            float (*pSelfPos)[4];
            float fTime;

            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_DashForwSeq);
                m_unk268 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 1U, 0);
                pSelfPos = (float (*)[4])m_unk190;
                if (m_unk3C != 0) {
                    pSelfPos = (float (*)[4])(m_unk3C + 0x80);
                }
                sceVu0SubVector(m_unk280, m_unk270, pSelfPos);
                sceVu0Normalize(m_unk280, m_unk280);
                sceVu0ScaleVector(m_unk280, m_unk280, 0.3f);
                m_unk284 = 0;
            }
            fTime = ((PMNode *)m_unk3C)->GetFrameTime();
            if (fTime < 7.0f) {
                *(u_long128 *)m_unk38 = *(u_long128 *)m_unk280;
            } else if (!(fTime <= 7.0f)) {
                if (fTime < 25.0f) {
                    sceVu0ScaleVector(m_unk290, m_unk280, (25.0f - fTime) / 18.0f);
                    FaceTarget(0.13f);
                    *(u_long128 *)m_unk38 = *(u_long128 *)m_unk290;
                } else {
                    goto block_320;
                }
            } else {
block_320:
                FaceTarget(0.13f);
                m_unk38->SetVelocity(0.0f, 0.0f);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        }
        case 21:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_DashBackSeq);
                m_unk264 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 4U, 0);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 22:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_DodgeSeq);
                FaceTarget(1.0f);
                m_unk264 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 4U, 0);
                m_unk2AC = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 0xAU, 1);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 8:
            if (m_unkE9 != 0) {
                m_unk254 = 0;
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_DoubleChopSeq);
                m_unk2A4 = mEffectAPI__13EntityManager.CreateOneshot(0x010003A9U, 0x02000662U, 0, 0, (class EntityBaseClass *)this, 0.5f, 0, 0, 0);
            }
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1DDU, 0x16U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1DDU, 0x27U);
            if (((PMNode *)m_unk3C)->GetFrameTime() < 22.0f) {
                FaceTarget(0.03f);
            }
            if ((m_unk254 == 0) && !(((PMNode *)m_unk3C)->GetFrameTime() < 32.0f)) {
                ResetCollisions__15EntityBaseClassFv(this);
                m_unk254 = 1;
            }
            if (m_unk160 == 0) {
                ResetAttackTimer();
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 29: {
            float var_f20;
            float temp_f12;
            if (m_unkE9 != 0) {
                m_unk2B8 = 0;
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_GrowSeq);
                ((PMNode *)m_unk3C)->ScaleSet(0.5f, 0.5f, 0.5f, 1.0f);
                ScaleSpikes(0.0f);
                m_unk22C += 0x320;
                if (m_unk22C >= 0x321) {
                    m_unk22C = 0x320;
                }
                DestroyDamageFx__15EntityBaseClassFUi(this, m_unk238);
                m_unk238 = 0;
                EnableSleep__15EntityBaseClassFbb(this, 0, 0);
                m_unk2C8 = 1;
                PlaySound__15EntityBaseClassFUi(this, 0x1D4U);
            }
            var_f20 = ((PMNode *)m_unk3C)->GetFrameTime() / 45.0f;
            temp_f12 = 0.5f + (var_f20 / 2.0f);
            if (!(var_f20 <= 1.0f)) {
                var_f20 = 1.0f;
            }
            ((PMNode *)m_unk3C)->ScaleSet(temp_f12, temp_f12, temp_f12, 1.0f);
            ScaleSpikes(var_f20);
            if (m_unk160 == 0) {
                EnableSleep__15EntityBaseClassFbb(this, 1, 0);
                m_unk2C8 = 0;
                m_unk1B0 = 1;
                m_unk103 = 0x40;
                m_unk104 = 0x40600000;
                m_unk108 = 0x40800000;
                LoadMesh__15EntityBaseClassFUibb(this, 0x0100030FU, 0, 1);
                AdjustPhysicsForEweedCheck();
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_IdleSeq);
                SetState__15EntityBaseClassFi(this, DetermineNewState());
                UpdateDamageFx();
            }
            goto block_533;
        }
        case 9:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_DrillSeq);
                PlaySound__15EntityBaseClassFUi(this, 0x1DAU);
            }
            if (((PMNode *)m_unk3C)->GetFrameTime() < 36.0f) {
                FaceTarget(0.03f);
            }
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1D1U, 0x18U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1E1U, 0x1AU);
            if (m_unk160 == 0) {
                ResetAttackTimer();
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 6:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_SuckSoulSeq);
                m_unk2C9 = 1;
                PlaySound__15EntityBaseClassFUi(this, 0x1E0U);
            }
            if (!(((PMNode *)m_unk3C)->GetFrameTime() <= 11.0f) && (((PMNode *)m_unk3C)->GetFrameTime() < 36.0f) && (m_bSuckingActive__19ClockworkSoulsucker == 0)) {
                if (m_SuckerRef__19ClockworkSoulsucker != (int)m_unk4) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x55D, "m_SuckerRef == GetApparitionRef()");
                }
                m_bSuckingActive__19ClockworkSoulsucker = 1U;
            }
            if (!(((PMNode *)m_unk3C)->GetFrameTime() <= 36.0f) && (m_bSuckingActive__19ClockworkSoulsucker == 1)) {
                if (m_SuckerRef__19ClockworkSoulsucker != (int)m_unk4) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x563, "m_SuckerRef == GetApparitionRef()");
                }
                m_bSuckingActive__19ClockworkSoulsucker = 0U;
            }
            if (m_unk160 == 0) {
                m_unk2C9 = 0;
                m_bSuckingSemaphoreBusy__19ClockworkSoulsucker = 0;
                m_SuckerRef__19ClockworkSoulsucker = 0;
                EnableSleep__15EntityBaseClassFbb(this, 1, 0);
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 10: {
            float vA0[4];
            float vB0[4];
            float vC0[4];
            void *pPrj;
            char *pTgt;
            char *pVec;
            int nTgt3C;
            int rnd;
            if (m_unk2A8 == 0) {
                pPrj = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x2D, false, 0);
                if (pPrj == 0) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x519, "pPrj");
                }
                GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, vC0);
                sceVu0Normalize(vC0, vC0);
                sceVu0ScaleVector(vC0, vC0, 2.0f);
                pVec = m_unk3C ? (char *)m_unk3C + 0x80 : m_unk190;
                *(u_long128 *)vB0 = *(u_long128 *)pVec;
                sceVu0AddVector(vB0, vB0, vC0);
                vB0[1] = vB0[1] + 3.0f;
                pTgt = (char *)GetTarget();
                nTgt3C = *(int *)(pTgt + 0x3C);
                pVec = nTgt3C ? (char *)nTgt3C + 0x80 : pTgt + 0x190;
                *(u_long128 *)vA0 = *(u_long128 *)pVec;
                vA0[1] = vA0[1] + 1.0f;
                pVec = m_unk3C ? (char *)m_unk3C + 0x80 : m_unk190;
                sceVu0SubVector(vA0, vA0, pVec);
                sceVu0Normalize(vA0, vA0);
                sceVu0ScaleVector(vA0, vA0, 0.5f);
                pVec = m_unk3C ? (char *)m_unk3C + 0x90 : (char *)m_unk1A0;
                InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(pPrj, 6, vB0, pVec, vA0);
                *(unsigned int *)((char *)pPrj + 0x1EC) = m_unk4;
                *(int *)((char *)pPrj + 0x1E0) = 0x42480000;
                m_unk2A8 = 1;
            }
            if (m_unk160 != 0) {
                EnableSleep__15EntityBaseClassFbb(this, 1, 0);
                ResetAttackTimer();
                rnd = MathAPI::RandomIntRange(2, 5);
                m_unk2A8 = 0;
                m_unk2BC = mTimerAPI__13EntityManager.CreateTimer(m_unk4, rnd, false);
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        }
        case 11:
            if (m_unkE9 != 0) {
                DeleteEffects();
                ReleaseSemaphoreIfOwned();
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_BlockSeq);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 12:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_HitSeq);
            }
            if (m_unk160 == 0) {
                m_unkDC = 0;
                if (m_unk38 != 0) {
                    m_unk38->SetVelocity(0.0f, 0.0f);
                }
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 13: {
            if (m_unkE9 != 0) {
                m_unkDC = 0;
                if (m_unk38 != 0) {
                    m_unk38->SetVelocity(0.0f, 0.0f);
                }
                DeleteEffects();
                ReleaseSemaphoreIfOwned();
                RemoveFromAttackSystem__15EntityBaseClassFv(this);
                EnableSleep__15EntityBaseClassFbb(this, false, false);
                WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
                WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
                if (m_unk1B0 == 0) {
                    unsigned int *pFound;
                    float *pVec;
                    if (InJuggleAirspace() != 0) {
                        pFound = (unsigned int *)((PMNode *)m_unk3C)->Find(0x72C7C29BU);
                        if (pFound == 0) {
                            CdsAssert("ClockworkSoulsucker.cpp", 0x688, "pNode");
                        }
                        pVec = (m_unk3C != 0) ? (float *)((char *)m_unk3C + 0x80) : (float *)m_unk190;
                        pVec[1] = *(float *)((char *)pFound + 0x74);
                    }
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_DeathSeq);
                    ((PMNode *)m_unk3C)->ScaleSet(0.5f, 0.5f, 0.5f, 1.0f);
                    m_unk10C &= 0xF8FFFFFF;
                    {
                        Physics *pPhys = m_unkD4;
                        if (pPhys != 0) {
                            *(char *)pPhys = 0;
                            char *pSub = *(char **)((char *)pPhys + 0xC);
                            if (pSub != 0) {
                                *(char *)(pSub + 0x18) = 0;
                            }
                        }
                    }
                    SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, m_unk258, 4);
                } else {
                    mEffectAPI__13EntityManager.CreateOneshot(0x01000325U, 0x02000557U, 0, 0, (class EntityBaseClass *)this, 1.0f, false, 0, false);
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_DeathBottomWiggleSeq);
                    PlaySound__15EntityBaseClassFUi(this, 0x142U);
                    m_unk2AC = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 1U, 0);
                }
            }
            if (m_unk160 == 0) {
                if (m_unk140 == (void *)ClockworkSoulsucker_DeathBottomWiggleSeq) {
                    SetState__15EntityBaseClassFi(this, 0xE);
                } else {
                    SetState__15EntityBaseClassFi(this, -2);
                }
            }
            goto block_533;
        }
        case 14: {
            if (m_unkE9 != 0) {
                m_unk10C &= 0xF8FFFFFF;
                {
                    Physics *pPhys = m_unkD4;
                    if (pPhys != 0) {
                        *(char *)pPhys = 0;
                        char *pSub = *(char **)((char *)pPhys + 0xC);
                        if (pSub != 0) {
                            *(char *)(pSub + 0x18) = 0;
                        }
                    }
                }
                SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, m_unk258, 4);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_DeathBottomExplodeSeq);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, -2);
            }
            goto block_533;
        }
        case 15: {
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_DeathSeq);
                WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
                WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
            }
            if (m_unk160 == 0) {
                SetState__15EntityBaseClassFi(this, -2);
            }
            goto block_533;
        }
        case 18:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_SuckSoulSeq);
                m_unk2C9 = 1;
                PlaySound__15EntityBaseClassFUi(this, 0x1E0U);
            }
            if (!(((PMNode *)m_unk3C)->GetFrameTime() <= 11.0f) && (((PMNode *)m_unk3C)->GetFrameTime() < 36.0f) && (m_bSuckingActive__19ClockworkSoulsucker == 0)) {
                if (m_SuckerRef__19ClockworkSoulsucker != (int)m_unk4) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x580, "m_SuckerRef == GetApparitionRef()");
                }
                m_bSuckingActive__19ClockworkSoulsucker = 1U;
            }
            if (!(((PMNode *)m_unk3C)->GetFrameTime() <= 36.0f) && (m_bSuckingActive__19ClockworkSoulsucker == 1)) {
                if (m_SuckerRef__19ClockworkSoulsucker != (int)m_unk4) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x586, "m_SuckerRef == GetApparitionRef()");
                }
                m_bSuckingActive__19ClockworkSoulsucker = 0U;
            }
            if (m_unk160 == 0) {
                m_unk2C9 = 0;
                m_bSuckingSemaphoreBusy__19ClockworkSoulsucker = 0;
                m_SuckerRef__19ClockworkSoulsucker = 0;
                EnableSleep__15EntityBaseClassFbb(this, 1, 0);
                if (m_unk2B8 != 0) {
                    SetState__15EntityBaseClassFi(this, 0x1D);
                } else {
                    SetState__15EntityBaseClassFi(this, DetermineNewState());
                }
            }
            goto block_533;
        case 23: {
            float *pVec;
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_GrabAttemptSeq);
                pVec = m_unk3C ? (float *)((char *)m_unk3C + 0x80) : (float *)m_unk190;
                m_unk2C0 = pVec[1];
            }
            FaceTarget(0.08f);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1DF, 0x1E);
            if (m_unk2A0 != 0) {
                SetState__15EntityBaseClassFi(this, 0x18);
            } else if (m_unk160 == 0) {
                if (m_unk2A0 & 0xFF) {
                    CdsAssert("ClockworkSoulsucker.cpp", 0x5B2, "m_bDrainHit == false");
                }
                SetState__15EntityBaseClassFi(this, 0x19);
            }
            goto block_533;
        }
        case 24: {
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_GrabHitSeq);
                ((PMNode *)m_unk3C)->ScaleSet(0.5f, 0.5f, 0.5f, 1.0f);
                ScaleSpikes(0.0f);
                m_unk258 += m_unk2C4;
            }
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1DE, 0x6C);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1D3, 0x29);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1D9, 0x62);
            if (!(((PMNode *)m_unk3C)->GetFrameTime() <= 76.0f)) {
                PMNode *pNode = (PMNode *)m_unk3C;
                if (*(float *)((char *)pNode + 0xA0) != 0.5f) {
                    pNode->ScaleSet(0.5f, 0.5f, 0.5f, 1.0f);
                    ScaleSpikes(0.0f);
                }
            }
            if (!(((PMNode *)m_unk3C)->GetFrameTime() <= 100.0f)) {
                if (*(unsigned short *)((char *)m_unk38 + 0x106) & 0x800) {
                    m_unk38->SetPhysicsType(0x12, 0);
                    m_unk10C |= 0x071B1902;
                }
            }
            if (m_unk160 == 0) {
                ResetAttackTimer();
                AdjustPhysicsForEweedCheck();
                if (m_unk258 >= 6) {
                    SetState__15EntityBaseClassFi(this, 0x1D);
                } else {
                    SetState__15EntityBaseClassFi(this, DetermineNewState());
                }
                m_unk2A0 = 0;
            }
            goto block_533;
        }
        case 25:
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_GrabMissSeq);
            }
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x1DE, 9);
            if (m_unk160 == 0) {
                ResetAttackTimer();
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        case 30:
            if (m_unkE9 != 0) {
                int rnd = MathAPI::RandomIntRange(0, 1);
                unsigned int *pSeq;
                switch (m_unk250 & ~0x5C0) {
                case 0x0:
                    if (InJuggleAirspace() != 0) {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_JuggleSeq);
                    } else {
                        if (rnd == 0) {
                            pSeq = (unsigned int *)ClockworkSoulsucker_Small_HitRightSeq;
                        } else {
                            pSeq = (unsigned int *)ClockworkSoulsucker_Small_HitSeq;
                        }
                        PlaySequence__15EntityBaseClassFPUi(this, pSeq);
                    }
                    break;
                case 0x4:
                case 0x5:
                    if (InJuggleAirspace() != 0) {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_JuggleSeq);
                    } else {
                        if (rnd == 0) {
                            pSeq = (unsigned int *)ClockworkSoulsucker_Small_HitLeftSeq;
                        } else {
                            pSeq = (unsigned int *)ClockworkSoulsucker_Small_HitSeq;
                        }
                        PlaySequence__15EntityBaseClassFPUi(this, pSeq);
                    }
                    break;
                case 0x1:
                case 0xD:
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_HitSeq);
                    break;
                case 0x25:
                case 0x28:
                case 0xC:
                case 0x2D:
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_KnockBackSeq);
                    break;
                case 0x201:
                case 0x220:
                    if (InJuggleAirspace() != 0) {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_SmackDownSeq);
                    } else {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_KnockBackSeq);
                    }
                    break;
                case 0x8:
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_KnockUpSeq);
                    if (m_unk250 == 0x148) {
                        ((PMNodeVirtualView *)m_unk3C)->SetFrameTime(1.0f);
                    }
                    break;
                case 0xF:
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_LaunchSeq);
                    break;
                case 0x2:
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_CrushSeq);
                    break;
                case 0x200:
                case 0x204:
                    if (InJuggleAirspace() != 0) {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_AirJuggleSeq);
                    } else {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_HitSeq);
                    }
                    break;
                default:
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkSoulsucker_Small_HitSeq);
                    break;
                }
            }
            if (m_unk160 == 0) {
                m_unkDC = 0;
                if (m_unk38 != 0) {
                    m_unk38->SetVelocity(0.0f, 0.0f);
                }
                SetState__15EntityBaseClassFi(this, DetermineNewState());
            }
            goto block_533;
        }
    }
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
