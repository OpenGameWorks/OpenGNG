// FLAGS: -str readonly
#include "ClockworkPuncher.h"
#include "Debug.h"

// TODO(header): foreign declarations
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void PlaySound__15EntityBaseClassFUi(void *, unsigned int);
extern "C" int RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(void *, void *, unsigned int);
extern "C" void RemoveFromAttackSystem__15EntityBaseClassFv(void *);
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" float GetFrameTime__6PMNodeFv(PMNode *);
extern "C" float GetFrameRate__6PMNodeFv(PMNode *);
extern "C" int CreateDamageFx__15EntityBaseClassFfUi(void *, float, unsigned int);
extern "C" void ChangeDamageFxInterval__15EntityBaseClassFUif(void *, unsigned int, float);
extern "C" float FastMath_Fabs__Ff(float);

// Slot numbers are declaration order; Slot13 is the call at vtable offset 0x3C.
class EntityVirtualSlots {
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

class EntityBaseClass {
public:
    char _pad000[8];
    int m_unk8;
};

class MathAPI {
public:
    int FacingPoint(EntityBaseClass *arg0, float (*arg1)[4], float arg2);
    static float RandomFloatRange(float fMin, float fMax);
    static void VectorRotateY(float (*arg0)[4], float arg1);
};
class EntityManager {
public:
    char _pad000[0x505C];
    EntityBaseClass *m_unk505C;
};
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(EntityBaseClass *, float (*)[4]);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(EntityBaseClass *, float (*)[4]);
extern "C" float Round180__Ff(float);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*)[4], float (*)[4]);
extern "C" int RandomIntRange__7MathAPIFii(int, int);
extern MathAPI *mPlayerAPI__13EntityManager;
extern EntityManager *mpEntMgr__15EntityBaseClass;

class TimerAPI {
public:
    char _pad000[40];
    void KillTimer(unsigned int);
    unsigned int CreateTimer(unsigned int, unsigned int, bool);
};
extern TimerAPI mTimerAPI__13EntityManager;

class EffectAPI {
public:
    char _pad000[20];
    void DeleteEffect(unsigned int);
};
extern EffectAPI mEffectAPI__13EntityManager;
extern "C" void *EffectValid__9EffectAPIFUi(EffectAPI *, unsigned int);
extern "C" void SetFrameRate__6PMNodeFfb(PMNode *, float, bool);
extern "C" void SetVelocity__7PhysicsFff(void *, float, float);
extern "C" PMNode *Find__6PMNodeFUi(PMNode *, unsigned int);
extern int miRandom__7MathAPI;
extern "C" void __dl__FPv(void *);
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *, unsigned int *);
extern unsigned char __vt__16ClockworkPuncher[];
extern unsigned int ClockworkPuncher_SiegeMesh[];
extern unsigned int ClockworkPuncher_NormalMesh[];

struct tagParticleFxTrigger;
class PMNode {
public:
    int AddFxTrigger(struct tagParticleFxTrigger *pTrigger, bool bFlag);
    void DestroyFxTriggers(bool bA, bool bB, bool bC);
};
extern "C" void ScaleSet__6PMNodeFffff(PMNode *pThis, float a, float b, float c, float d);
extern "C" void CopyMNode__6PMNodeFR6PMNodeb(PMNode *pThis, PMNode *pSrc, bool bFlag);
extern "C" void InitMembers__6PMNodeFv(PMNode *pThis);
extern "C" void Add__6PArrayFPv(void *pArray, void *pItem);
extern "C" void __ct__6PArrayFv(void *pArray);
extern "C" void sceVu0UnitMatrix(float (*)[4]);
extern "C" void BuildDispList__9PSkeletonFv(void *pSkeleton);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" char __vt__9PResource[];
extern "C" char __vt__6PMNode[];
extern unsigned int DamageNames[4];
extern int mbHard__15EntityBaseClass;
extern "C" int printf(const char *, ...);
extern "C" float cosf(float);
extern "C" float sinf(float);
extern "C" void sceVu0AddVector(float *, float *, float *);
extern "C" void FacePlayer__15EntityBaseClassFf(void *, float);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern "C" int ProcessHitBack__15EntityBaseClassFv(void *);
extern "C" void ResetCollisions__15EntityBaseClassFv(void *);
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern "C" int PlaySoundOnFrame__15EntityBaseClassFUiUi(void *, unsigned int, unsigned int);
extern "C" void *Spawn__13EntityManagerFUibi(EntityManager *, unsigned int, bool, int);
extern "C" int GetResource__16PResourceManagerFUib(void *, unsigned int, bool);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, float (*)[4]);
extern "C" void InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(void *, int, float (*)[4], float (*)[4], float (*)[4]);
extern "C" int CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(void *, unsigned int, unsigned int, float (*)[4], float (*)[4], void *, float, bool, int, bool);
extern "C" int GetGroundPos__7MathAPIFPA4_f(float (*)[4]);
extern "C" void Remove__6PArrayFPv(void *, void *);
extern "C" void TriggerBGAnim__15EntityBaseClassFUiibUi(void *, unsigned int, int, bool, unsigned int);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *, int, char, unsigned int);
extern "C" void *GetPtrToApparition__13EntityManagerFUi(EntityManager *, unsigned int);
extern "C" void SetShellStartAndDest__8ZinShellFRA4_fRA4_f(void *, float (*)[4], float (*)[4]);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *, unsigned int, float (*)[4]);
extern "C" void SpawnBonus__15EntityBaseClassFPfii(void *, float *, int, int);
extern "C" void *__ct__7PhysicsFv(void *);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *, int, unsigned int);
extern void *mpResMgr__15EntityBaseClass;
extern float m_vBonusSpawnOffset[4];
extern float m_vDefaultSpawnVelocity[4];
extern float PuncherBox[8];
extern unsigned int ClockworkPuncher_AirStrikeSeq;
extern unsigned int ClockworkPuncher_AssembleSeq;
extern unsigned int ClockworkPuncher_BackHitSeq;
extern unsigned int ClockworkPuncher_BlockSeq;
extern unsigned int ClockworkPuncher_CrossHitSeq;
extern unsigned int ClockworkPuncher_DeathSeq;
extern unsigned int ClockworkPuncher_ExplosionSeq;
extern unsigned int ClockworkPuncher_HitSeq;
extern unsigned int ClockworkPuncher_IdleSeq;
extern unsigned int ClockworkPuncher_JumpFromShellSeq;
extern unsigned int ClockworkPuncher_KnockBackSeq;
extern unsigned int ClockworkPuncher_OneTwoHitSeq;
extern unsigned int ClockworkPuncher_RocketFistSeq;
extern unsigned int ClockworkPuncher_RunSeq;
extern unsigned int ClockworkPuncher_SiegeDeathSeq;
extern unsigned int ClockworkPuncher_SiegeExplosionSeq;
extern unsigned int ClockworkPuncher_Taunt2Seq;
extern unsigned int ClockworkPuncher_TauntSeq;

// FUNCTION: 0x001DE040 GetHealth__16ClockworkPuncherFv
int ClockworkPuncher::GetHealth() {
    return m_unk1FC;
}

// FUNCTION: 0x001DE050 GetClassName__16ClockworkPuncherFv
const char *ClockworkPuncher::GetClassName() {
    return "ClockworkPuncher";
}

// FUNCTION: 0x001DE060 GetTallyType__16ClockworkPuncherFv
int ClockworkPuncher::GetTallyType() {
    return 1;
}

// FUNCTION: 0x001DE070 GetArenaWaveID__16ClockworkPuncherFv
int ClockworkPuncher::GetArenaWaveID() {
    return m_unk1D8;
}

// FUNCTION: 0x001DE080 IsArenaApparition__16ClockworkPuncherFv
bool ClockworkPuncher::IsArenaApparition() {
    return m_unk1D8 ? true : false;
}

// FUNCTION: 0x001DE090 NeedsToBeWoken__16ClockworkPuncherFv
int ClockworkPuncher::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x1DC);
}

// FUNCTION: 0x001DE0A0 GetWokenVarPos__16ClockworkPuncherFv
int ClockworkPuncher::GetWokenVarPos() {
    return 5;
}

// FUNCTION: 0x001DE0B0 SetInnocentInstanceID__16ClockworkPuncherFUi
void ClockworkPuncher::SetInnocentInstanceID(unsigned int value) {
    m_unk280 = (int)value;
}

// DRAFT: 0x001DE0C0 LoadCorrectMesh__16ClockworkPuncherFv
// note: 32 words differ; branch layout (outer bnez target, siege block as beq target, normal lui in b delay slot). Tried if==1 siege-first, !=1 normal-first (32), early return (32), literal fixes.
void ClockworkPuncher::LoadCorrectMesh() {
    if (m_unk270 == 0) {
        m_unk270 = 1;
        if (m_unk1B4 != 1) {
            PlaySequence__15EntityBaseClassFPUi(this, ClockworkPuncher_NormalMesh);
            ScaleSet__6PMNodeFffff((PMNode *)m_unk3C, 1.15f, 1.15f, 1.15f, 1.0f);
        } else {
            PlaySequence__15EntityBaseClassFPUi(this, ClockworkPuncher_SiegeMesh);
            ScaleSet__6PMNodeFffff((PMNode *)m_unk3C, 1.4f, 1.4f, 1.4f, 1.0f);
        }
    }
}

// FUNCTION: 0x001DE170 ChooseNextState__16ClockworkPuncherFv
void ClockworkPuncher::ChooseNextState() {
    float fDist;
    RemoveFromAttackSystem__15EntityBaseClassFv(this);
    char *pPlayerPt = *(char **)((char *)mPlayerAPI__13EntityManager + 0x3C);
    pPlayerPt = pPlayerPt ? pPlayerPt + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190;
    if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPlayerPt, (float (*)[4])m_unk200) < m_unk1D4) {
        fDist = Distance__7MathAPIFPA4_fPA4_f(
            (float (*)[4])(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190),
            (float (*)[4])(*(char **)((char *)mPlayerAPI__13EntityManager + 0x3C)
                               ? *(char **)((char *)mPlayerAPI__13EntityManager + 0x3C) + 0x80
                               : (char *)mPlayerAPI__13EntityManager + 0x190));
        if (m_unk280 != 0) {
            void *pValid = InstanceIsValid__15EntityBaseClassFUi((unsigned int)m_unk280);
            if (pValid != 0 && ((EntityVirtualSlots *)pValid)->Slot13() != 0) {
                char *pOtherPt = ((ClockworkPuncher *)pValid)->m_unk3C;
                pOtherPt = pOtherPt ? pOtherPt + 0x80 : (char *)pValid + 0x190;
                if (Distance__7MathAPIFPA4_fPA4_f(
                        (float (*)[4])(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190),
                        (float (*)[4])pOtherPt) < fDist) {
                    SetState__15EntityBaseClassFi(this, 4);
                    return;
                }
            }
        }
        if (m_unk276 == 0) {
            if (fDist > 10.0f) {
                SetState__15EntityBaseClassFi(this, 2);
                return;
            }
            SetState__15EntityBaseClassFi(this, 0xF);
            return;
        }
        SetState__15EntityBaseClassFi(this, 0x10);
        return;
    }
    SetState__15EntityBaseClassFi(this, 0);
}

// FUNCTION: 0x001DE2F0 ChooseAttack__16ClockworkPuncherFv
void ClockworkPuncher::ChooseAttack() {
    float fDist;
    char *pPlayerPt = *(char **)((char *)mPlayerAPI__13EntityManager + 0x3C);
    pPlayerPt = pPlayerPt ? pPlayerPt + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190;
    fDist = Distance__7MathAPIFPA4_fPA4_f(
        (float (*)[4])(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190), (float (*)[4])pPlayerPt);
    if (fDist > 4.0f) {
        if (fDist > 9.0f) {
            if (m_unk1B4 == 1) {
                if (RandomIntRange__7MathAPIFii(1, 100) < 0x4B) {
                    SetState__15EntityBaseClassFi(this, 0x19);
                    return;
                }
            } else {
                float fLimit = m_unk1D4;
                if (50.0f < fLimit) {
                    fLimit = 50.0f;
                }
                if (fDist < fLimit) {
                    if (RandomIntRange__7MathAPIFii(1, 100) & 1) {
                        SetState__15EntityBaseClassFi(this, 0x15);
                        return;
                    }
                }
            }
        }
        if (m_unk1B4 == 1) {
            if (RandomIntRange__7MathAPIFii(1, 100) < 0x4B) {
                m_unk276 = 1;
                SetState__15EntityBaseClassFi(this, 0x10);
                return;
            }
        }
        SetState__15EntityBaseClassFi(this, 0x14);
    } else {
        miRandom__7MathAPI = miRandom__7MathAPI * 0x343FD + 0x269EC3;
        if (miRandom__7MathAPI & 1) {
            SetState__15EntityBaseClassFi(this, 0x16);
        } else {
            SetState__15EntityBaseClassFi(this, 0x18);
        }
    }
}

// FUNCTION: 0x001DE4A0 AttachSparkEffect__16ClockworkPuncherFv
void ClockworkPuncher::AttachSparkEffect() {
    float vec[4];

    if (m_unk2B4 != 0) {
        if (m_unk2B4 == 0) {
            CdsAssert("ClockworkPuncher.cpp", 0xA46, "m_pBackjoint");
        }
        m_unk2B4->DestroyFxTriggers(false, true, false);
    }
    char *pSelf = m_unk3C != 0 ? m_unk3C + 0x80 : (char *)this + 0x190;
    char *pPlayerAlt = *(char **)((char *)mPlayerAPI__13EntityManager + 0x3C);
    char *pPlayer = (char *)mPlayerAPI__13EntityManager;
    sceVu0SubVector(vec, (float *)(pPlayerAlt != 0 ? pPlayerAlt + 0x80 : pPlayer + 0x190), (float *)pSelf);
    sceVu0Normalize(vec, vec);
    sceVu0ScaleVector(vec, vec, 1.56f);
    float fLo = -90.0f;
    float fHi = 90.0f;
    MathAPI::VectorRotateY((float (*)[4])vec, MathAPI::RandomFloatRange(fLo, fHi));
    if (m_unk2B4 != 0) {
        AttachDamageEffect(m_unk2B4, 0x8300015A, vec[0], vec[1], vec[2]);
        PlaySound__15EntityBaseClassFUi((void *)this, 0x100);
    }
}

// FUNCTION: 0x001DE5A0 AttachDamageMesh__16ClockworkPuncherFv
void ClockworkPuncher::AttachDamageMesh() {
    char *pNew;
    PMNode *pFound;
    char *pSkeleton;

    m_unk2B8 += RandomIntRange__7MathAPIFii(0, 2);
    if (m_unk2B8 >= 4) {
        m_unk2B8 -= 4;
    }
    pFound = Find__6PMNodeFUi((PMNode *)m_unk2C0, DamageNames[m_unk2B8]);
    if (pFound == 0) {
        CdsAssert("ClockworkPuncher.cpp", 0xA33, "aNextJoint");
    }
    if (m_unk2B4 != 0) {
        if ((pNew = (char *)__nw__FUi(0x100)) != 0) {
            char *volatile pThis = pNew;
            *(char **)pNew = __vt__9PResource;
            *(int *)(pThis + 4) = 0;
            *(char **)pThis = __vt__6PMNode;
            __ct__6PArrayFv(pThis + 0x14);
            sceVu0UnitMatrix((float (*)[4])(pThis + 0x40));
            __ct__6PArrayFv(pThis + 0xD8);
            InitMembers__6PMNodeFv((PMNode *)pThis);
            pNew = pThis;
        }
        if (pNew == 0) {
            CdsAssert("ClockworkPuncher.cpp", 0xA37, "pNew");
        }
        CopyMNode__6PMNodeFR6PMNodeb((PMNode *)pNew, pFound, true);
        Add__6PArrayFPv((char *)m_unk2B4 + 0x14, pNew);
    }
    pSkeleton = m_unk3C;
    if (pSkeleton == 0) {
        CdsAssert("ClockworkPuncher.cpp", 0xA3F, "pSkeleton");
    }
    BuildDispList__9PSkeletonFv(pSkeleton);
}

// FUNCTION: 0x001DE730 AttachDamageEffect__16ClockworkPuncherFP6PMNodeUifff
void ClockworkPuncher::AttachDamageEffect(PMNode *pNode, unsigned int nId, float fA, float fB, float fC) {
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

// FUNCTION: 0x001DE790 SetEffectsFrameRate__16ClockworkPuncherFf
void ClockworkPuncher::SetEffectsFrameRate(float fRate) {
    void *pFx;

    pFx = EffectValid__9EffectAPIFUi(&mEffectAPI__13EntityManager, *(unsigned int *)((char *)this + 0x298));
    if (pFx != 0) {
        SetFrameRate__6PMNodeFfb(*(PMNode **)((char *)pFx + 4), fRate, true);
    }
    pFx = EffectValid__9EffectAPIFUi(&mEffectAPI__13EntityManager, m_unk29C);
    if (pFx != 0) {
        SetFrameRate__6PMNodeFfb(*(PMNode **)((char *)pFx + 4), fRate, true);
    }
    pFx = EffectValid__9EffectAPIFUi(&mEffectAPI__13EntityManager, m_unk2A4);
    if (pFx != 0) {
        SetFrameRate__6PMNodeFfb(*(PMNode **)((char *)pFx + 4), fRate, true);
    }
    pFx = EffectValid__9EffectAPIFUi(&mEffectAPI__13EntityManager, m_unk2A8);
    if (pFx != 0) {
        SetFrameRate__6PMNodeFfb(*(PMNode **)((char *)pFx + 4), fRate, true);
    }
    pFx = EffectValid__9EffectAPIFUi(&mEffectAPI__13EntityManager, m_unk2A0);
    if (pFx != 0) {
        SetFrameRate__6PMNodeFfb(*(PMNode **)((char *)pFx + 4), fRate, true);
    }
    pFx = EffectValid__9EffectAPIFUi(&mEffectAPI__13EntityManager, m_unk2AC);
    if (pFx != 0) {
        SetFrameRate__6PMNodeFfb(*(PMNode **)((char *)pFx + 4), fRate, true);
    }
}

// FUNCTION: 0x001DE8B0 DeleteEffects__16ClockworkPuncherFv
void ClockworkPuncher::DeleteEffects() {
    if (m_unk298 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk298);
        m_unk298 = 0;
    }
    if (m_unk29C != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk29C);
        m_unk29C = 0;
    }
    if (m_unk2A4 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2A4);
        m_unk2A4 = 0;
    }
    if (m_unk2A8 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2A8);
        m_unk2A8 = 0;
    }
    if (m_unk2A0 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2A0);
        m_unk2A0 = 0;
    }
    if (m_unk2AC != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2AC);
        m_unk2AC = 0;
    }
}

// FUNCTION: 0x001DE960 DeleteTimers__16ClockworkPuncherFv
void ClockworkPuncher::DeleteTimers() {
    mTimerAPI__13EntityManager.KillTimer(m_unk214);
    mTimerAPI__13EntityManager.KillTimer(m_unk27C);
    mTimerAPI__13EntityManager.KillTimer(m_unk288);
    mTimerAPI__13EntityManager.KillTimer(m_unk28C);
    m_unk214 = 0;
    m_unk27C = 0;
    m_unk288 = 0;
    m_unk28C = 0;
}

// FUNCTION: 0x001DE9D0 FaceHit__16ClockworkPuncherFv
void ClockworkPuncher::FaceHit() {
    float vFwd[4];
    EntityBaseClass *pPlayer = mpEntMgr__15EntityBaseClass->m_unk505C;
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(pPlayer, &vFwd);
    char *pSrc = *(char **)((char *)pPlayer + 0x3C);
    pSrc = pSrc ? pSrc + 0x90 : (char *)pPlayer + 0x1A0;
    float fDelta = *(float *)(pSrc + 4);
    int nState = *(int *)((char *)mpEntMgr__15EntityBaseClass->m_unk505C + 0x154);
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
    char *pDst = m_unk3C ? m_unk3C + 0x90 : (char *)this + 0x1A0;
    *(float *)(pDst + 4) = fDelta;
    char *pDst2 = m_unk3C ? m_unk3C + 0x90 : (char *)this + 0x1A0;
    char *pObj = m_unk38;
    *(float *)(pObj + 0x11C) = Round180__Ff(*(float *)(pDst2 + 4));
}

// FUNCTION: 0x001DEAE0 Stalled__16ClockworkPuncherFf
int ClockworkPuncher::Stalled(float fDist) {
    char *target;
    float dist;
    if (m_unk3C != 0) {
        target = m_unk3C + 0x80;
    } else {
        target = &m_unk190;
    }
    dist = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk250, (float (*)[4])target);
    if (dist <= fDist) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001DEB30 PlayerFacingUs__16ClockworkPuncherFv
int ClockworkPuncher::PlayerFacingUs() {
    MathAPI *player = mPlayerAPI__13EntityManager;
    if (player != 0) {
        char *target = &m_unk190;
        float (*unused)[4];
        if (m_unk3C != 0) {
            target = m_unk3C + 0x80;
        }
        if (player->FacingPoint((EntityBaseClass *)target, unused, 45.0f) != 0) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x001DEB90 InBlockableState__16ClockworkPuncherFv
int ClockworkPuncher::InBlockableState() {
    if (m_unk20 == 2 || m_unk20 == 0x17 || (unsigned int)(m_unk20 - 0xE) <= 1U || m_unk20 == 0x10) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001DEBD0 CheckBlockAttack__16ClockworkPuncherFv
void ClockworkPuncher::CheckBlockAttack() {
    char *pPlayer = (char *)mPlayerAPI__13EntityManager;
    if (pPlayer == 0) {
        CdsAssert("ClockworkPuncher.cpp", 0x93E, "pPlayer");
    }
    if (m_unk1FC > 0 && *(unsigned char *)(pPlayer + 0x23D2) != 0 &&
        *(unsigned short *)(pPlayer + 0x15E) != 0xD && *(int *)(pPlayer + 0x1CC) == m_unk4) {
        if (InBlockableState()) {
            char *pThisPt = m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190;
            char *pPlayerPt = *(char **)(pPlayer + 0x3C);
            pPlayerPt = pPlayerPt ? pPlayerPt + 0x80 : pPlayer + 0x190;
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPlayerPt, (float (*)[4])pThisPt) <= 20.0f) {
                if (PlayerFacingUs()) {
                    if (RandomIntRange__7MathAPIFii(1, 100) < 0x10) {
                        SetState__15EntityBaseClassFi(this, 0xC);
                    }
                }
            }
        }
    }
}

// FUNCTION: 0x001DECD0 CanAttackPlayer__16ClockworkPuncherFv
int ClockworkPuncher::CanAttackPlayer() {
    if (m_unk272 != 0) {
        char *pThisPt = m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190;
        char *pPlayerPt = *(char **)((char *)mPlayerAPI__13EntityManager + 0x3C);
        pPlayerPt = pPlayerPt ? pPlayerPt + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190;
        if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPlayerPt, (float (*)[4])pThisPt) <= 30.0f) {
            int nRoll = RandomIntRange__7MathAPIFii(1, 100);
            if (nRoll < 0x33) {
                if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, mPlayerAPI__13EntityManager, 0)) {
                    m_unk272 = 0;
                    m_unk214 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, RandomIntRange__7MathAPIFii(1, 2), false);
                    return 1;
                }
            }
            if (nRoll > 0x32) {
                m_unk272 = 0;
                m_unk214 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, RandomIntRange__7MathAPIFii(1, 2), false);
            }
        }
    }
    return 0;
}

// FUNCTION: 0x001DEDF0 SetBoundBoxW__16ClockworkPuncherFf
void ClockworkPuncher::SetBoundBoxW(float value) {
    *(float *)((char *)m_unk3C + 0x12C) = value;
}

// FUNCTION: 0x001DEE00 SetRiseAndAttack__16ClockworkPuncherFPA4_fff
void ClockworkPuncher::SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2) {
    m_unk1B8[0] = arg0[0][0];
    m_unk1B8[1] = arg0[0][1];
    m_unk1B8[2] = arg0[0][2];
    m_unk1C8[0] = arg0[0][0];
    m_unk1C8[1] = arg0[0][1];
    m_unk1C8[2] = arg0[0][2];
    m_unk1C4 = arg1;
    m_unk1D4 = arg2;
}

// FUNCTION: 0x001DEE40 SetDefaultVars__16ClockworkPuncherFv
void ClockworkPuncher::SetDefaultVars() {
    m_unk1FC = 0x3E8;
    m_unk210 = m_unk1FC;
    m_unk1B8[0] = 0.0f;
    m_unk1B8[1] = 0.0f;
    m_unk1B8[2] = 0.0f;
    *(int *)&m_unk1C4 = 0x41C80000;
    *(int *)&m_unk1D4 = 0x420C0000;
    m_unk1B4 = 0;
    m_unk1E0 = 1;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F4 = 0;
    m_unk1D8 = 0;
    *(int *)&m_unk1F8 = 0x3DCCCCCD;
    m_unk2BD = 1;
}

// FUNCTION: 0x001DEEA0 SetSpawnedFromEntity__16ClockworkPuncherFPfPfi
void ClockworkPuncher::SetSpawnedFromEntity(float *pPos, float *pAlt, int nType) {
    char *pDst;

    m_unk1C4 = 150.0f;
    m_unk1C8[0] = pPos[0];
    m_unk1C8[1] = pPos[1];
    m_unk1C8[2] = pPos[2];
    m_unk1D4 = 150.0f;
    m_unk1B4 = nType;
    m_unk1E0 = 0;
    pDst = m_unk3C != 0 ? m_unk3C + 0x80 : (char *)this + 0x190;
    *(u_long128 *)pDst = *(u_long128 *)pPos;
    if (pAlt != 0) {
        char *pDst2 = m_unk3C != 0 ? m_unk3C + 0x90 : (char *)this + 0x1A0;
        *(u_long128 *)pDst2 = *(u_long128 *)pAlt;
    }
}

// FUNCTION: 0x001DEF20 SetEditableVars__16ClockworkPuncherFPc
void ClockworkPuncher::SetEditableVars(char *arg0) {
    memcpy((char *)this + 0x1B0, arg0, 0x4C);
    m_unk1FC = 1000;
    m_unk210 = m_unk1FC;
}

// DRAFT: 0x001DEF60 OnTimerEvent__16ClockworkPuncherFUi
// note: 5 lines differ; original hoists mtc1 $zero,$f12 and mov.s f13 above the m_unk38 null test (mov.s in the beqz delay slot), ours keeps them in the body. Tried local pointer, local float zero (also as call args, declared before/after the m_unkDC store), literal zeros, if (m_unk38) truthiness, static inline StopVel(p,a,b) helper: all 5 lines.
void ClockworkPuncher::OnTimerEvent(unsigned int nHandle) {
    if (nHandle == m_unk214) {
        m_unk272 = 1;
        return;
    }
    if (nHandle == m_unk27C) {
        m_unk278 = 1;
        return;
    }
    if (nHandle == m_unk288) {
        m_unkDC = 0;
        if (m_unk38 != 0) {
            SetVelocity__7PhysicsFff(m_unk38, 0.0f, 0.0f);
        }
        if (m_unk2B4 != 0) {
            if (m_unk2B4 == 0) {
                CdsAssert("ClockworkPuncher.cpp", 0x882, "m_pBackjoint");
            }
            *(float *)((char *)m_unk2B4 + 0x90) = m_unk290;
        }
        if (m_unk3C != 0) {
            SetFrameRate__6PMNodeFfb((PMNode *)m_unk3C, m_unk284, true);
        }
        SetEffectsFrameRate(m_unk284);
        static signed char init;
        static int aAFTERpausesec;
        if (init == 0) {
            aAFTERpausesec = 5;
            init = 1;
        }
        m_unk28C = mTimerAPI__13EntityManager.CreateTimer(m_unk4, aAFTERpausesec, true);
        m_unk288 = 0;
        return;
    }
    if (nHandle == m_unk28C) {
        m_unk28C = 0;
    }
}

// FUNCTION: 0x001DF080 OnWakeEvent__16ClockworkPuncherFv
void ClockworkPuncher::OnWakeEvent() {
    if (m_unk3C != 0) {
        m_unk2B4 = Find__6PMNodeFUi((PMNode *)m_unk3C, 0xAB4BE7B1);
        if (m_unk2B4 == 0) {
            CdsAssert("ClockworkPuncher.cpp", 0x862, "m_pBackjoint");
        }
    }
    if (m_unk2BC != 0) {
        miRandom__7MathAPI = miRandom__7MathAPI * 0x343FD + 0x269EC3;
        if (miRandom__7MathAPI & 1) {
            AttachDamageEffect(Find__6PMNodeFUi((PMNode *)m_unk3C, 0xF9D9DD15), 0x83000154, 0.0f, 0.0f, 0.0f);
        } else {
            AttachDamageEffect(Find__6PMNodeFUi((PMNode *)m_unk3C, 0x3EAD836C), 0x83000154, 0.0f, 0.0f, 0.0f);
        }
        AttachDamageEffect(Find__6PMNodeFUi((PMNode *)m_unk3C, 0xFEE57AF8), 0x83000154, 0.0f, 0.0f, 0.0f);
    }
}

// FUNCTION: 0x001DF1B0 OnSleepEvent__16ClockworkPuncherFv
void ClockworkPuncher::OnSleepEvent() {
    DeleteEffects();
    DeleteTimers();
    m_unk272 = 1;
    m_unk2B4 = 0;
}

// FUNCTION: 0x001DF1F0 OnEffectDelete__16ClockworkPuncherFUi
void ClockworkPuncher::OnEffectDelete(unsigned int nHandle) {
    if ((int)nHandle == m_unk298) {
        m_unk298 = 0;
    }
    if ((int)nHandle == m_unk29C) {
        m_unk29C = 0;
    }
    if ((int)nHandle == m_unk2A4) {
        m_unk2A4 = 0;
    }
    if ((int)nHandle == m_unk2A8) {
        m_unk2A8 = 0;
    }
    if ((int)nHandle == m_unk2A0) {
        m_unk2A0 = 0;
    }
    if ((int)nHandle == m_unk2AC) {
        m_unk2AC = 0;
    }
}

// DRAFT: 0x001DF260 OnHitEvent__16ClockworkPuncherFP15EntityBaseClassiUiUi
// note: DIFF 419 words, size 0x560 vs 0x6E8: this/pEntity saved in s2/s3 (original s4/s3), extra f21 spill, body ~95 insns short (m_unk2C4 and timer sections)
int ClockworkPuncher::OnHitEvent(EntityBaseClass *pEntity, int nArg, unsigned int nFlags, unsigned int nFlags2) {
    static int testhitback;
    static int init;
    static int aPauseFrames;
    static int init2;
    char *pPlayer;
    char *pTgt;
    float fDist;
    float fRot;
    float fRate;
    int nRnd;
    PMNode *pFound;
    void *pValid;
    int nState;

    PlaySound__15EntityBaseClassFUi((void *)this, 0x5E);
    if (m_unkF4 != 0) {
        m_unk1FC -= nArg;
        if (m_unk1FC > 0) {
            return 1;
        }
        DeleteEffects();
        DeleteTimers();
        m_unk2BC = 0;
        if (m_unk2B4 != 0) {
            m_unk2B4->DestroyFxTriggers(false, true, false);
        }
        SetState__15EntityBaseClassFi(this, 9);
        m_unk218 = nFlags;
        return 2;
    }

    nState = m_unk20;
    if ((int)pEntity->m_unk8 == 0x1D) {
        DeleteEffects();
        m_unk1FC = 0;
        DeleteTimers();
        m_unk2BC = 0;
        pTgt = m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190;
        SetState__15EntityBaseClassFi(this, 9);
        m_unk218 = nFlags;
        return 2;
    }

    if (nState == 2) {
        fRate = GetFrameTime__6PMNodeFv((PMNode *)m_unk3C);
        if (fRate < 85.0f) {
            nState = 4;
        }
    }

    fRot = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f((EntityBaseClass *)this, (float (*)[4])(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190));
    fRot = fRot + 180.0f;
    if (fRot < -180.0f) {
        fRot += 360.0f;
    } else if (fRot > 180.0f) {
        fRot -= 360.0f;
    }
    m_unkD8 = fRot;
    m_unkDCf = 0.3f;

    if (mbHard__15EntityBaseClass == 0) {
        if ((nFlags & -0x5C1) == 0x2D) {
            FaceHit();
            DeleteEffects();
            SetState__15EntityBaseClassFi(this, 3);
        }
    }

    pPlayer = *(char **)((char *)mPlayerAPI__13EntityManager + 0x3C);
    fDist = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f((EntityBaseClass *)this, (float (*)[4])(pPlayer ? pPlayer + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190));
    if (FastMath_Fabs__Ff(fDist) < 90.0f) {
        m_unk274 = 1;
    } else {
        m_unk274 = 0;
    }
    if (m_unk2B4 == 0) {
        if (m_unk3C == 0) {
            m_unk2B4 = Find__6PMNodeFUi((PMNode *)m_unk2C0, 0);
        }
    }
    m_unk1FC -= nArg;
    if (m_unk2C4 == 0) {
        fRate = (float)m_unk210 / 2.0f;
        if ((float)m_unk1FC <= fRate) {
            ChangeDamageFxInterval__15EntityBaseClassFUif(this, 20, 20.0f);
        }
    }

    if (nFlags & 0x20) {
        pPlayer = m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190;
        fDist = Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPlayer, (float (*)[4])m_unk200);
        if (fDist < m_unk1D4) {
            fRot = fDist;
        }
    }

    if (m_unk2BC == 0) {
        m_unk2BC = 1;
        m_unk2C4 = CreateDamageFx__15EntityBaseClassFfUi(this, 90.0f, 0);
    }
    miRandom__7MathAPI = miRandom__7MathAPI * 0x343FD + 0x269EC3;
    if (miRandom__7MathAPI & 1) {
        pFound = Find__6PMNodeFUi((PMNode *)m_unk3C, 0xF9DDDD15);
        AttachDamageEffect(pFound, 0x83000154, 0.0f, 0.0f, 0.0f);
    } else {
        pFound = Find__6PMNodeFUi((PMNode *)m_unk3C, 0x3EAD836C);
        AttachDamageEffect(pFound, 0x83000154, 0.0f, 0.0f, 0.0f);
    }
    pFound = Find__6PMNodeFUi((PMNode *)m_unk3C, 0xFEE57AF8);
    AttachDamageEffect(pFound, 0x83000154, 0.0f, 0.0f, 0.0f);

    if (m_unk2C4 != 0) {
        fRate = (float)m_unk210 / 4.0f;
        if ((float)m_unk1FC <= 4.0f) {
            ChangeDamageFxInterval__15EntityBaseClassFUif(this, 20, 20.0f);
        }
    }

    if (m_unk1FC <= 0) {
        DeleteEffects();
        DeleteTimers();
        m_unk2BC = 0;
        if (m_unk2B4 != 0) {
            m_unk2B4->DestroyFxTriggers(false, true, false);
        }
        SetState__15EntityBaseClassFi(this, 9);
        m_unk218 = nFlags;
        return 2;
    }

    m_unk21C = nFlags;
    if (nFlags & 0x100) {
        m_unk284 = GetFrameRate__6PMNodeFv((PMNode *)m_unk3C);
        SetFrameRate__6PMNodeFfb((PMNode *)m_unk3C, 0.0f, true);
        SetEffectsFrameRate(0.0f);
    }

    if (init2 == 0) {
        init2 = 1;
        aPauseFrames = 7;
    }
    m_unk288 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, aPauseFrames, true);

    ((m_unk2B4 != 0) ? (void)0 : CdsAssert("ClockworkPuncher.cpp", 0x7FD, "m_pBackjoint"));
    m_unk290 = *(float *)((char *)m_unk2B4 + 0x90);

    if (nFlags & 0x20) {
        pTgt = m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190;
        fDist = Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pTgt, (float (*)[4])m_unk200);
        if (fDist < m_unk1D4) {
            fRot = fDist;
        }
    }

    pValid = InstanceIsValid__15EntityBaseClassFUi((unsigned int)m_unk280);
    if (pValid != 0) {
        if (fRot <= fDist) {
            SetState__15EntityBaseClassFi(this, 0x10);
        }
    }
    return 1;
}

// FUNCTION: 0x001DF950 OnAttackEvent__16ClockworkPuncherFP15EntityBaseClassi
void ClockworkPuncher::OnAttackEvent(EntityBaseClass *arg0, int arg1) {
    if (arg0->m_unk8 == 3 && arg1 != 5 && m_unk20 == 0x18) {
        PlaySound__15EntityBaseClassFUi((void *)this, 0x10D);
    }
}

// FUNCTION: 0x001DF9A0 OnStopAttack__16ClockworkPuncherFv
void ClockworkPuncher::OnStopAttack() {
    if (m_unk163 != 2) {
        if (m_unk20 != 0xE) {
            SetState__15EntityBaseClassFi(this, 0);
        }
    }
}

#define CP_I(o) (*(int *)((char *)this + (o)))
#define CP_F(o) (*(float *)((char *)this + (o)))
#define CP_B(o) (*(unsigned char *)((char *)this + (o)))
#define CP_S(o) (*(short *)((char *)this + (o)))
#define CP_P(o) ((float (*)[4])((char *)this + (o)))
#define CP_PTR(o) (*(char **)((char *)this + (o)))
#define CP_PICK_SIDE() \
    if (!(Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf((char *)mPlayerAPI__13EntityManager)) <= Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), CP_P(0x240)))) { \
        CP_B(0x276) = 1; \
    } else { \
        CP_B(0x276) = 0; \
    }

static inline float (*PosOf(char *pObj))[4] {
    char *p = *(char **)(pObj + 0x3C);
    return (float (*)[4])(p != 0 ? p + 0x80 : pObj + 0x190);
}

// DRAFT: 0x001DF9E0 Execute__16ClockworkPuncherFv
// note: 2804 words; frame 0x130 vs 0x110, this in s4 with extra s5/s6 (orig s0..s4); offsets via CP_* macros; tried dropping nState/pScale locals, PosOf as macro (worse)
void ClockworkPuncher::Execute() {
    if (CP_PTR(0x3C) != 0) {
        if (CP_I(0x1B4) == 1 && *(float *)(CP_PTR(0x3C) + 0xA0) != 1.4f) {
            ScaleSet__6PMNodeFffff((PMNode *)CP_PTR(0x3C), 1.4f, 1.4f, 1.4f, 1.0f);
        }
        if (CP_I(0x1B4) == 0) {
            if (*(float *)(CP_PTR(0x3C) + 0xA0) != 1.15f) {
                ScaleSet__6PMNodeFffff((PMNode *)CP_PTR(0x3C), 1.15f, 1.15f, 1.15f, 1.0f);
            }
        }
    }
    if (CP_I(0x288) != 0) {
        if (m_unk2B4 != 0) {
            if (m_unk2B4 == 0) {
                CdsAssert("ClockworkPuncher.cpp", 0x13F, "m_pBackjoint");
            }
            *(float *)((char *)m_unk2B4 + 0x90) += CP_F(0x294);
            float fNew = CP_F(0x294) - 7.0f;
            CP_F(0x294) = fNew;
            if (fNew <= -14.0f) {
                CP_F(0x294) = 7.0f;
            }
        }
    }
    if (ProcessHitBack__15EntityBaseClassFv(this) != 0) {
        char *pPhys = CP_PTR(0x38);
        if (FastMath_Fabs__Ff(*(float *)pPhys) < 0.05f && FastMath_Fabs__Ff(*(float *)(pPhys + 4)) < 0.05f && FastMath_Fabs__Ff(*(float *)(pPhys + 8)) < 0.05f) {
            float vZero[4];
            vZero[0] = 0.0f;
            vZero[1] = 0.0f;
            vZero[2] = 0.0f;
            *(u_long128 *)CP_PTR(0x38) = *(u_long128 *)vZero;
            CP_I(0xDC) = 0;
            if (CP_PTR(0x38) != 0) {
                SetVelocity__7PhysicsFff(CP_PTR(0x38), 0.0f, 0.0f);
            }
        }
    }
    if (CP_B(0x2BC) != 0 && CP_I(0xF4) == 0) {
        int nV = CP_I(0x2C8);
        if (nV == 0) {
            AttachSparkEffect();
            CP_I(0x2C8) = RandomIntRange__7MathAPIFii(5, 0xF);
        } else {
            CP_I(0x2C8) = nV - 1;
        }
        nV = CP_I(0x2D0);
        if (nV == 0) {
            if (m_unk2B4 != 0) {
                void **pFound = (void **)Find__6PMNodeFUi(m_unk2B4, DamageNames[CP_I(0x2B8)]);
                if (pFound != 0) {
                    Remove__6PArrayFPv((char *)m_unk2B4 + 0x14, pFound);
                    if (pFound != 0) {
                        ((void (*)(void *, int))(*(void ***)pFound)[2])(pFound, 1);
                    }
                }
            }
            if (CP_PTR(0x3C) == 0) {
                CdsAssert("ClockworkPuncher.cpp", 0x175, "pSkeleton");
            }
            BuildDispList__9PSkeletonFv(CP_PTR(0x3C));
            CP_I(0x2CC) = RandomIntRange__7MathAPIFii(0xF, 0x1E);
            CP_I(0x2D0) = -1;
        } else if (nV > 0) {
            CP_I(0x2D0) = nV - 1;
        }
        nV = CP_I(0x2CC);
        if (nV == 0) {
            AttachDamageMesh();
            CP_I(0x2D0) = RandomIntRange__7MathAPIFii(3, 5);
            CP_I(0x2CC) = -1;
        } else if (nV > 0) {
            CP_I(0x2CC) = nV - 1;
        }
    }
    switch (m_unk20) {
    case -1:
        if (CP_B(0xE9) != 0) {
            CP_F(0x200) = CP_F(0x1C8);
            CP_F(0x204) = CP_F(0x1CC);
            CP_F(0x208) = CP_F(0x1D0);
            if (!(Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), CP_P(0x200)) <= CP_F(0x1D4))) {
                printf("ERROR - Clockwork Puncher shutdown as initial position wasn't inside attack radius\n");
                SetState__15EntityBaseClassFi(this, -2);
                return;
            }
            CP_I(0x10C) &= 0xF8FFFFFF;
            CP_I(0x10C) |= 0x071B1902;
            CP_B(0x103) = 0x40;
            CP_B(0x272) = 1;
            CP_I(0x28C) = 0;
            CP_I(0x288) = 0;
            CP_B(0x275) = 0;
            CP_B(0x276) = 1;
            CP_B(0x277) = 1;
            CP_B(0x270) = 0;
            CP_I(0x298) = 0;
            CP_I(0x29C) = 0;
            CP_I(0x2A0) = 0;
            CP_I(0x2A4) = 0;
            CP_I(0x2A8) = 0;
            CP_I(0x2B0) = 0;
            CP_I(0x2AC) = 0;
            CP_B(0x2BC) = 0;
            CP_I(0x2CC) = 0;
            CP_I(0x2D0) = 0;
            CP_I(0x210) = CP_I(0x1FC);
            CP_I(0x2C0) = GetResource__16PResourceManagerFUib(mpResMgr__15EntityBaseClass, 0x010001B9U, true);
            if (CP_I(0x2C0) == 0) {
                CdsAssert("ClockworkPuncher.cpp", 0x1BF, "m_pDamageMesh");
            }
            if (CP_F(0x1B8) == 0.0f) {
                if (CP_F(0x1BC) == 0.0f && CP_F(0x1C0) == 0.0f) {
                    CP_F(0x1B8) = (*PosOf((char *)this))[0];
                    CP_F(0x1BC) = (*PosOf((char *)this))[1];
                    CP_F(0x1C0) = (*PosOf((char *)this))[2];
                }
            }
            CP_S(0x15C) = 0x32;
            CP_S(0x15E) = 0;
            CP_I(0x104) = 0x40000000;
            CP_I(0x108) = 0x40800000;
            if ((unsigned int)CP_I(0x1B4) >= 2U) {
                CdsAssert("ClockworkPuncher.cpp", 0x1CD, "mEVars.m_iDifficulty < 2");
            }
            if (CP_I(0x1D8) != 0) {
                CP_F(0x1C4) = CP_F(0x18C);
                CP_F(0x1D4) = CP_F(0x18C);
            }
            if (CP_I(0x1E0) != 2 && CP_I(0x1E0) != 7) {
                char *pRot = CP_PTR(0x3C) != 0 ? CP_PTR(0x3C) + 0x90 : (char *)this + 0x1A0;
                *(float *)(pRot + 4) = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, PosOf((char *)mPlayerAPI__13EntityManager));
            }
            CP_F(0x230) = CP_F(0x1B8);
            CP_F(0x234) = CP_F(0x1BC);
            CP_F(0x238) = CP_F(0x1C0);
        }
        if (Distance__7MathAPIFPA4_fPA4_f(CP_P(0x230), PosOf((char *)mPlayerAPI__13EntityManager)) <= CP_F(0x1C4)) {
            if (CP_PTR(0x38) == 0) {
                void *pPhys = __nw__FUi(0x120U);
                if (pPhys != 0) {
                    pPhys = __ct__7PhysicsFv(pPhys);
                }
                CP_PTR(0x38) = (char *)pPhys;
                if (CP_PTR(0x38) == 0) {
                    CdsAssert("ClockworkPuncher.cpp", 0x1EF, "mpPhysics");
                }
            }
            SetPhysicsType__7PhysicsFUiPA4_f(CP_PTR(0x38), 0x12U, 0);
            if (CP_PTR(0xD4) == 0) {
                void *pShadow = __nw__FUi(0x10U);
                if (pShadow != 0) {
                    pShadow = __ct__6ShadowFQ26Shadow10ShadowTypeUi(pShadow, 1, 0x87000008U);
                }
                CP_PTR(0xD4) = (char *)pShadow;
                if (CP_PTR(0xD4) == 0) {
                    CdsAssert("ClockworkPuncher.cpp", 0x1F7, "mpShadow");
                }
            }
            if (CP_I(0x1E0) != 0) {
                SetState__15EntityBaseClassFi(this, 0xA);
            } else {
                SetState__15EntityBaseClassFi(this, 0);
            }
        }
        break;
    case 10:
        if (CP_B(0xE9) != 0) {
            switch (CP_I(0x1E0)) {
            case 1:
            case 3: {
                char *pShell = (char *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0xFU, 0, 0);
                if (pShell == 0) {
                    CdsAssert("ClockworkPuncher.cpp", 0x210, "pContainerEnt");
                }
                CP_I(0x224) = *(int *)(pShell + 4);
                EnableSleep__15EntityBaseClassFbb(this, false, false);
                if (CP_I(0x1E0) == 3) {
                    *(int *)(pShell + 0x22C) = 1;
                }
                float (*pPos)[4] = PosOf((char *)this);
                float vA[4];
                float vB[4];
                float fX = CP_F(0x1E4);
                if (fX == (*pPos)[0] && CP_F(0x1E8) == (*pPos)[1] && CP_F(0x1EC) == (*pPos)[2]) {
                    vA[0] = (*pPos)[0];
                    vA[1] = 50.0f + (*pPos)[1];
                    vA[2] = (*pPos)[2];
                } else if (fX == 0.0f && CP_F(0x1E8) == 0.0f && CP_F(0x1EC) == 0.0f) {
                    vA[0] = (*pPos)[0];
                    vA[1] = 50.0f + (*pPos)[1];
                    vA[2] = (*pPos)[2];
                } else {
                    vA[0] = fX;
                    vA[1] = CP_F(0x1E8);
                    vA[2] = CP_F(0x1EC);
                }
                vB[0] = (*pPos)[0];
                vB[1] = (*pPos)[1];
                vB[2] = (*pPos)[2];
                SetShellStartAndDest__8ZinShellFRA4_fRA4_f(pShell, (float (*)[4])vA, (float (*)[4])vB);
                if (CP_I(0x1F4) != 0) {
                    *(int *)(pShell + 0x224) = CP_I(0x1F4);
                    *(int *)(pShell + 0x228) = m_unk4;
                }
                goto block132;
            }
            case 2:
                if (CP_I(0x1F4) != 0) {
                    TriggerBGAnim__15EntityBaseClassFUiibUi(this, CP_I(0x1F4), -1, false, 0);
                }
                SetState__15EntityBaseClassFi(this, 0xD);
                return;
            case 4:
                SetState__15EntityBaseClassFi(this, 0);
                return;
            case 7:
                if (CP_I(0x1F4) != 0) {
                    TriggerBGAnim__15EntityBaseClassFUiibUi(this, CP_I(0x1F4), -1, false, 0);
                }
                SetState__15EntityBaseClassFi(this, 0xD);
                PlaySound__15EntityBaseClassFUi(this, 0x1F9U);
                return;
            default:
                CdsAssert("ClockworkPuncher.cpp", 0x25C, "0");
                goto block132;
            }
        } else {
        block132:
            if (CP_I(0x1E0) != 1) {
                CdsAssert("ClockworkPuncher.cpp", 0x273, "0");
            } else {
                char *pApp = (char *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, CP_I(0x224));
                if (pApp == 0 || pApp[0x22D] != 0) {
                    SetState__15EntityBaseClassFi(this, 7);
                    if (CP_B(0x2BD) == 0) {
                        EnableSleep__15EntityBaseClassFbb(this, true, false);
                    }
                }
            }
        }
        break;
    case 13:
        if (CP_B(0xE9) != 0) {
            float vFwd[4];
            *(int *)(CP_PTR(0x38) + 0x10C) = 0x3E4CCCCD;
            GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f((EntityBaseClass *)this, (float (*)[4])vFwd);
            sceVu0Normalize(vFwd, vFwd);
            sceVu0ScaleVector(vFwd, vFwd, CP_F(0x1F8));
            *(u_long128 *)CP_PTR(0x38) = *(u_long128 *)vFwd;
            LoadCorrectMesh();
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_JumpFromShellSeq);
        }
        {
            float *pV = (float *)CP_PTR(0x38);
            if (pV[0] == 0.0f && pV[1] == 0.0f && pV[2] == 0.0f) {
                SetState__15EntityBaseClassFi(this, 8);
            }
        }
        break;
    case 7:
        if (CP_B(0xE9) != 0) {
            float vVel[4];
            float fAng = 0.017453292f * MathAPI::RandomFloatRange(0.0f, 360.0f);
            float fCos = cosf(fAng);
            float fSin = sinf(fAng);
            *(int *)(CP_PTR(0x38) + 0x10C) = 0x3E4CCCCD;
            vVel[0] = m_vDefaultSpawnVelocity[0] * fCos + m_vDefaultSpawnVelocity[2] * fSin;
            vVel[2] = m_vDefaultSpawnVelocity[2] * fCos - m_vDefaultSpawnVelocity[0] * fSin;
            vVel[1] = m_vDefaultSpawnVelocity[1];
            *(u_long128 *)CP_PTR(0x38) = *(u_long128 *)vVel;
            LoadCorrectMesh();
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_JumpFromShellSeq);
        }
        {
            float *pV = (float *)CP_PTR(0x38);
            if (pV[0] == 0.0f && pV[1] == 0.0f && pV[2] == 0.0f) {
                SetState__15EntityBaseClassFi(this, 8);
            }
        }
        break;
    case 8:
        if (CP_B(0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_AssembleSeq);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (CP_I(0x1E0) == 7 && CP_B(0x2D4) == 0 && (*(int *)(CP_PTR(0x38) + 0x108) & 1)) {
            CP_B(0x2D4) = 1;
            PlaySound__15EntityBaseClassFUi(this, 0xF1U);
        }
        if (CP_B(0x160) == 0) {
            SetState__15EntityBaseClassFi(this, 0);
        }
        break;
    case 0:
        if (CP_B(0xE9) != 0) {
            char *pSh = CP_PTR(0xD4);
            if (pSh != 0) {
                *(int *)pSh = 1;
                char *pSh2 = *(char **)(pSh + 0xC);
                if (pSh2 != 0) {
                    *(int *)(pSh2 + 0x18) = 1;
                }
            }
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            if (CP_B(0x2BD) == 0) {
                EnableSleep__15EntityBaseClassFbb(this, true, false);
            }
            LoadCorrectMesh();
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_IdleSeq);
            char *pBox = CP_PTR(0x38);
            *(u_long128 *)(pBox + 0x80) = *(u_long128 *)&PuncherBox[0];
            *(u_long128 *)(pBox + 0x90) = *(u_long128 *)&PuncherBox[4];
            if (CP_I(0x280) != 0 && InstanceIsValid__15EntityBaseClassFUi(CP_I(0x280)) != 0) {
                SetState__15EntityBaseClassFi(this, 4);
                return;
            }
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0xFU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0x2DU);
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        SetBoundBoxW(13.0f);
        if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)mPlayerAPI__13EntityManager), CP_P(0x200)) < CP_F(0x1D4)) {
            ChooseNextState();
            return;
        }
        if (CP_B(0x160) == 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_IdleSeq);
        }
        break;
    case 15:
        if (CP_B(0xE9) != 0) {
            *(u_long128 *)CP_P(0x250) = *(u_long128 *)PosOf((char *)this);
            CP_I(0x264) = 0;
            CP_I(0x268) = 1;
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_RunSeq);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0xAU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0x24U);
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (CanAttackPlayer() != 0) {
            ChooseAttack();
            return;
        }
        if (!(Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)mPlayerAPI__13EntityManager), CP_P(0x200)) <= CP_F(0x1D4))) {
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
        if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf((char *)mPlayerAPI__13EntityManager)) < 4.0f) {
            CP_B(0x276) = 1;
            SetState__15EntityBaseClassFi(this, 0x10);
            return;
        }
        if (CP_PTR(0x3C)[0x3F] & 4) {
            if (Stalled(2.0f) != 0) {
                if (RandomIntRange__7MathAPIFii(1, 0x64) & 1) {
                    SetState__15EntityBaseClassFi(this, 0x13);
                } else {
                    SetState__15EntityBaseClassFi(this, 0x10);
                }
                return;
            }
            *(u_long128 *)CP_P(0x250) = *(u_long128 *)PosOf((char *)this);
            CP_I(0x264) += 1;
            if (CP_I(0x264) == CP_I(0x268)) {
                ChooseNextState();
            }
        }
        break;
    case 19:
        if (CP_B(0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_IdleSeq);
        }
        if (CP_B(0x160) == 0) {
            ChooseNextState();
        }
        break;
    case 16:
        if (CP_B(0xE9) != 0) {
            miRandom__7MathAPI = miRandom__7MathAPI * 0x343FD + 0x269EC3;
            if (miRandom__7MathAPI & 1) {
                PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_Taunt2Seq);
                CP_I(0x2A4) = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x01000152U, 0x020002A8U, 0, 0, 0, 0.5f, false, 0, false);
            } else {
                PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_TauntSeq);
            }
            *(u_long128 *)CP_P(0x240) = *(u_long128 *)PosOf((char *)mPlayerAPI__13EntityManager);
        }
        if (CP_I(0x140) == (int)&ClockworkPuncher_TauntSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x26DU, 0x19U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x26DU, 0x20U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x26DU, 0x26U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x26DU, 0x2CU);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x26DU, 0x32U);
        } else if (CP_I(0x140) == (int)&ClockworkPuncher_Taunt2Seq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x59U, 0x17U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x59U, 0x2BU);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (CanAttackPlayer() != 0) {
            DeleteEffects();
            ChooseAttack();
            return;
        }
        if (CP_B(0x160) == 0) {
            float fD1 = Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf((char *)mPlayerAPI__13EntityManager));
            if (!(fD1 <= Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), CP_P(0x240)))) {
                CP_B(0x276) = 1;
            } else {
                CP_B(0x276) = 0;
            }
            ChooseNextState();
        }
        break;
    case 2:
        if (CP_B(0xE9) != 0) {
            *(u_long128 *)CP_P(0x250) = *(u_long128 *)PosOf((char *)this);
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_RunSeq);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0xAU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0x24U);
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (!(Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)mPlayerAPI__13EntityManager), CP_P(0x200)) <= CP_F(0x1D4))) {
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
        if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf((char *)mPlayerAPI__13EntityManager)) < 4.0f) {
            CP_B(0x276) = 1;
            SetState__15EntityBaseClassFi(this, 0x10);
            return;
        }
        if (CanAttackPlayer() != 0) {
            ChooseAttack();
        }
        if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf((char *)mPlayerAPI__13EntityManager)) <= 9.0f) {
            ChooseNextState();
        }
        if (CP_PTR(0x3C)[0x3F] & 4) {
            if (Stalled(2.0f) != 0) {
                if (RandomIntRange__7MathAPIFii(1, 0x64) & 1) {
                    SetState__15EntityBaseClassFi(this, 0x13);
                } else {
                    SetState__15EntityBaseClassFi(this, 0x10);
                }
                return;
            }
            *(u_long128 *)CP_P(0x250) = *(u_long128 *)PosOf((char *)this);
        }
        break;
    case 22:
        if (CP_B(0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_OneTwoHitSeq);
            static signed char init;
            static float aOneTwoWindUpFrameRate;
            if (init == 0) {
                init = 1;
                aOneTwoWindUpFrameRate = 0.3f;
            }
            CP_I(0x29C) = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x0100014FU, 0x020002A9U, 0, 0, 0, 0.5f, false, 0, false);
            CP_S(0x15C) = 0x32;
            CP_S(0x15E) = 0;
            *(u_long128 *)CP_P(0x240) = *(u_long128 *)PosOf((char *)mPlayerAPI__13EntityManager);
            CP_B(0x275) = 0;
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xABU, 0x15U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xABU, 0x1EU);
        if (!(GetFrameTime__6PMNodeFv((PMNode *)CP_PTR(0x3C)) < 20.0f) && CP_I(0x288) == 0) {
            GetFrameRate__6PMNodeFv((PMNode *)CP_PTR(0x3C));
        }
        if (!(GetFrameTime__6PMNodeFv((PMNode *)CP_PTR(0x3C)) < 35.0f) && CP_B(0x275) == 0) {
            ResetCollisions__15EntityBaseClassFv(this);
            FacePlayer__15EntityBaseClassFf(this, 0.04f);
            CP_S(0x15C) = 0x32;
            CP_S(0x15E) = 0x1007;
            CP_B(0x275) = 1;
        }
        if (CP_B(0x160) == 0) {
            CP_PICK_SIDE();
            ChooseNextState();
        }
        break;
    case 24:
        if (CP_B(0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_CrossHitSeq);
            CP_I(0x2A0) = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x010001B3U, 0x0200034DU, 0, 0, 0, 0.5f, false, 0, false);
            *(u_long128 *)CP_P(0x240) = *(u_long128 *)PosOf((char *)mPlayerAPI__13EntityManager);
            PlaySound__15EntityBaseClassFUi(this, 0x109U);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xABU, 0x1AU);
        if (GetFrameTime__6PMNodeFv((PMNode *)CP_PTR(0x3C)) <= 20.0f) {
            FacePlayer__15EntityBaseClassFf(this, 0.04f);
        }
        if (CP_B(0x160) == 0) {
            CP_PICK_SIDE();
            ChooseNextState();
        }
        break;
    case 21:
        if (CP_B(0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_RocketFistSeq);
            CP_I(0x298) = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x01000150U, 0x020002A6U, 0, 0, 0, 0.5f, false, 0, false);
            *(u_long128 *)CP_P(0x240) = *(u_long128 *)PosOf((char *)mPlayerAPI__13EntityManager);
            CP_B(0x277) = 1;
            PlaySound__15EntityBaseClassFUi(this, 0x57U);
        }
        if (GetFrameTime__6PMNodeFv((PMNode *)CP_PTR(0x3C)) < 32.0f) {
            FacePlayer__15EntityBaseClassFf(this, 0.04f);
        } else if (CP_B(0x277) != 0 && !(GetFrameTime__6PMNodeFv((PMNode *)CP_PTR(0x3C)) < 32.0f) && CP_I(0x288) == 0) {
            CP_B(0x277) = 0;
            int nI = 0;
            do {
                char *pPrj = (char *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x2DU, 0, 0);
                if (pPrj == 0) {
                    CdsAssert("ClockworkPuncher.cpp", 0x4B0, "pPrj");
                }
                float vD[4] = {0.0f, 4.5f, -3.8f, 0.0f};
                vD[0] = -2.0f + 4.0f * (float)nI;
                MathAPI::VectorRotateY((float (*)[4])vD, CP_PTR(0x3C) != 0 ? *(float *)(CP_PTR(0x3C) + 0x94) : *(float *)((char *)this + 0x1A4));
                vD[0] += (*PosOf((char *)this))[0];
                vD[1] += (*PosOf((char *)this))[1];
                vD[2] += (*PosOf((char *)this))[2];
                InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(pPrj, nI == 0 ? 2 : 3, (float (*)[4])vD, (float (*)[4])(CP_PTR(0x3C) != 0 ? CP_PTR(0x3C) + 0x90 : (char *)this + 0x1A0), 0);
                *(int *)(pPrj + 0x1EC) = m_unk4;
                char *pPN = *(char **)(pPrj + 0x3C);
                if (pPN != 0) {
                    ScaleSet__6PMNodeFffff((PMNode *)pPN, 1.15f, 1.15f, 1.15f, 1.0f);
                }
                nI += 1;
                vD[0] = (*PosOf((char *)this))[0];
                vD[1] = (*PosOf((char *)this))[1];
                vD[2] = (*PosOf((char *)this))[2];
                *(u_long128 *)(*(char **)(pPrj + 0x38) + 0xA0) = *(u_long128 *)vD;
            } while (nI < 2);
        }
        if (CP_B(0x160) == 0) {
            CP_PICK_SIDE();
            ChooseNextState();
        }
        break;
    case 25:
        if (CP_B(0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_AirStrikeSeq);
            CP_I(0x2AC) = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x010003BBU, 0x02000676U, 0, 0, 0, 0.5f, false, 0, false);
            CP_B(0x277) = 1;
            CP_B(0x272) = 0;
            mTimerAPI__13EntityManager.KillTimer(m_unk214);
            m_unk214 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 3U, false);
        }
        if (CP_B(0x277) != 0 && !(GetFrameTime__6PMNodeFv((PMNode *)CP_PTR(0x3C)) < 32.0f)) {
            CP_B(0x277) = 0;
            PlaySound__15EntityBaseClassFUi(this, 0x1AAU);
            int nHit = 0;
            int nK = 0;
            float vE[4];
            float vF[4];
            float vG[4];
            if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf((char *)mPlayerAPI__13EntityManager)) < 9.0f) {
                nHit = 1;
                sceVu0SubVector(vE, (float *)PosOf((char *)mPlayerAPI__13EntityManager), (float *)PosOf((char *)this));
                sceVu0Normalize(vE, vE);
                sceVu0ScaleVector(vE, vE, 15.0f);
                sceVu0AddVector(vE, vE, (float *)PosOf((char *)this));
                nK = 0;
            }
            do {
                char *pPrj = (char *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x2DU, 0, 0);
                if (pPrj == 0) {
                    CdsAssert("ClockworkPuncher.cpp", 0x513, "pPrj");
                }
                GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(mpEntMgr__15EntityBaseClass->m_unk505C, (float (*)[4])vF);
                sceVu0Normalize(vF, vF);
                MathAPI::VectorRotateY((float (*)[4])vF, 90.0f * (float)nK + MathAPI::RandomFloatRange(0.0f, 90.0f));
                static signed char init2;
                static float aTargetDst;
                if (init2 == 0) {
                    aTargetDst = 5.0f;
                    init2 = 1;
                }
                sceVu0ScaleVector(vF, vF, MathAPI::RandomFloatRange(1.0f, 5.0f));
                if (nHit != 0) {
                    sceVu0AddVector(vF, vF, vE);
                } else {
                    sceVu0AddVector(vF, vF, (float *)PosOf((char *)mPlayerAPI__13EntityManager));
                }
                *(u_long128 *)vG = *(u_long128 *)vF;
                vG[1] += 10.0f;
                if (GetGroundPos__7MathAPIFPA4_f((float (*)[4])vG) != 0) {
                    *(u_long128 *)vF = *(u_long128 *)vG;
                }
                *(u_long128 *)(pPrj + 0x1C0) = *(u_long128 *)vF;
                sceVu0SubVector(vF, vF, (float *)PosOf((char *)this));
                sceVu0Normalize(vF, vF);
                static signed char init3;
                static float aTargetSpeed;
                if (init3 == 0) {
                    aTargetSpeed = 0.25f;
                    init3 = 1;
                }
                sceVu0ScaleVector(vF, vF, aTargetSpeed);
                InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(pPrj, 8, PosOf((char *)this), (float (*)[4])(CP_PTR(0x3C) != 0 ? CP_PTR(0x3C) + 0x90 : (char *)this + 0x1A0), 0);
                nK += 1;
                *(int *)(pPrj + 0x1EC) = m_unk4;
            } while (nK < 4);
            CP_PICK_SIDE();
        }
        if (CP_B(0x160) == 0) {
            ChooseNextState();
        }
        break;
    case 20:
        if (CP_B(0xE9) != 0) {
            if (CP_I(0x140) != (int)&ClockworkPuncher_RunSeq) {
                PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_RunSeq);
            }
            *(u_long128 *)CP_P(0x250) = *(u_long128 *)PosOf((char *)this);
            CP_I(0x264) = 0;
            CP_I(0x268) = 1;
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0xAU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0x24U);
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (!(Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)mPlayerAPI__13EntityManager), CP_P(0x200)) <= CP_F(0x1D4))) {
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
        if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf((char *)mPlayerAPI__13EntityManager)) < 4.0f) {
            ChooseAttack();
            return;
        }
        if (CP_PTR(0x3C)[0x3F] & 4) {
            if (Stalled(2.0f) != 0) {
                if (RandomIntRange__7MathAPIFii(1, 0x64) & 1) {
                    SetState__15EntityBaseClassFi(this, 0x13);
                } else {
                    SetState__15EntityBaseClassFi(this, 0x10);
                }
                return;
            }
            *(u_long128 *)CP_P(0x250) = *(u_long128 *)PosOf((char *)this);
            CP_I(0x264) += 1;
            if (CP_I(0x264) == CP_I(0x268)) {
                ChooseNextState();
            }
        }
        if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf((char *)mPlayerAPI__13EntityManager)) <= 4.0f) {
            ChooseAttack();
        }
        break;
    case 3:
        if (CP_B(0xE9) != 0) {
            if (CP_B(0x274) != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_BackHitSeq);
            } else {
                int nFl = CP_I(0x21C) & ~0x5C0;
                if (nFl != 8 && nFl != 0x2D && nFl != 0xB && nFl != 0xA && nFl != 9 && nFl != 6) {
                    PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_HitSeq);
                } else if (CP_I(0x140) != (int)&ClockworkPuncher_KnockBackSeq) {
                    PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_KnockBackSeq);
                }
            }
        }
        if (CP_I(0x140) == (int)&ClockworkPuncher_KnockBackSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x5DU, 0x1EU);
        }
        if (CP_B(0x160) == 0) {
            ChooseNextState();
            CP_I(0xDC) = 0;
            if (CP_PTR(0x38) != 0) {
                SetVelocity__7PhysicsFff(CP_PTR(0x38), 0.0f, 0.0f);
            }
        }
        break;
    case 12:
        if (CP_B(0xE9) != 0) {
            DeleteEffects();
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_BlockSeq);
            CP_B(0x275) = 1;
        }
        if (CP_I(0x2A8) == 0 && !(GetFrameTime__6PMNodeFv((PMNode *)CP_PTR(0x3C)) < 81.0f) && CP_I(0x288) == 0 && CP_B(0x275) != 0) {
            CP_I(0x2A8) = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x01000153U, 0x020002A5U, 0, 0, 0, 0.5f, false, 0, false);
            CP_B(0x275) = 0;
        }
        if (CP_B(0x160) == 0) {
            SetState__15EntityBaseClassFi(this, 0);
        }
        break;
    case 4:
        if (CP_B(0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_RunSeq);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0xAU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2BU, 0x24U);
        {
            char *pInst = (char *)InstanceIsValid__15EntityBaseClassFUi(CP_I(0x280));
            if (pInst != 0) {
                if (((EntityVirtualSlots *)pInst)->Slot13() == 0) {
                    *(u_long128 *)CP_P(0x200) = *(u_long128 *)PosOf((char *)this);
                    CP_I(0x280) = 0;
                    SetState__15EntityBaseClassFi(this, 0);
                    return;
                }
                RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, PosOf(pInst)), 0.04f);
                if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf(pInst)) <= 5.0f && (int)(unsigned char)pInst[0x163] < 2) {
                    SetState__15EntityBaseClassFi(this, 5);
                }
                break;
            }
            *(u_long128 *)CP_P(0x200) = *(u_long128 *)PosOf((char *)this);
            CP_I(0x280) = 0;
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
        break;
    case 5:
        if (CP_B(0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_OneTwoHitSeq);
            CP_I(0x29C) = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x0100014FU, 0x020002A9U, 0, 0, 0, 0.5f, false, 0, false);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xABU, 0x15U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xABU, 0x1EU);
        {
            char *pInst = (char *)InstanceIsValid__15EntityBaseClassFUi(CP_I(0x280));
            if (pInst == 0) {
                *(u_long128 *)CP_P(0x200) = *(u_long128 *)PosOf((char *)this);
                CP_I(0x280) = 0;
                SetState__15EntityBaseClassFi(this, 0);
                return;
            }
            RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, PosOf(pInst)), 0.04f);
        }
        if (CP_B(0x160) == 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_IdleSeq);
            SetState__15EntityBaseClassFi(this, 6);
        }
        break;
    case 6:
        if (CP_B(0xE9) != 0) {
            mTimerAPI__13EntityManager.KillTimer(m_unk27C);
            CP_B(0x278) = 0;
            m_unk27C = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 1U, false);
        }
        {
            char *pInst = (char *)InstanceIsValid__15EntityBaseClassFUi(CP_I(0x280));
            if (pInst != 0) {
                if (((EntityVirtualSlots *)pInst)->Slot13() == 0) {
                    *(u_long128 *)CP_P(0x200) = *(u_long128 *)PosOf((char *)this);
                    CP_I(0x280) = 0;
                    SetState__15EntityBaseClassFi(this, 0);
                    return;
                }
                RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, PosOf(pInst)), 0.04f);
                if (CP_B(0x278) != 0) {
                    if (Distance__7MathAPIFPA4_fPA4_f(PosOf((char *)this), PosOf(pInst)) <= 4.0f) {
                        SetState__15EntityBaseClassFi(this, 5);
                    } else {
                        SetState__15EntityBaseClassFi(this, 4);
                    }
                }
                break;
            }
            *(u_long128 *)CP_P(0x200) = *(u_long128 *)PosOf((char *)this);
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
    case 9:
        if (CP_B(0xE9) != 0) {
            DestroyDamageFx__15EntityBaseClassFUi(this, CP_I(0x2C4));
            CP_I(0x2C4) = 0;
            CP_I(0xDC) = 0;
            if (CP_PTR(0x38) != 0) {
                SetVelocity__7PhysicsFff(CP_PTR(0x38), 0.0f, 0.0f);
            }
            CP_I(0x10C) &= 0xF8FFFFFF;
            char *pSh = CP_PTR(0xD4);
            if (pSh != 0) {
                *(int *)pSh = 0;
                char *pSh2 = *(char **)(pSh + 0xC);
                if (pSh2 != 0) {
                    *(int *)(pSh2 + 0x18) = 0;
                }
            }
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
            switch (CP_I(0x218)) {
            case 0xD:
            case 0x220:
            case 0x201:
            case 0x1:
            case 0x20:
                PlaySound__15EntityBaseClassFUi(this, 0x58U);
                if (CP_I(0x1B4) == 1) {
                    PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_SiegeExplosionSeq);
                } else {
                    PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_ExplosionSeq);
                }
                break;
            default:
                PlaySound__15EntityBaseClassFUi(this, 0x5CU);
                if (CP_I(0x1B4) == 1) {
                    PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_SiegeDeathSeq);
                } else {
                    PlaySequence__15EntityBaseClassFPUi(this, &ClockworkPuncher_DeathSeq);
                }
                break;
            }
            int nBonus;
            if (CP_I(0x1B4) == 1) {
                ScaleSet__6PMNodeFffff((PMNode *)CP_PTR(0x3C), 1.4f, 1.4f, 1.4f, 1.0f);
                nBonus = 8;
            } else {
                ScaleSet__6PMNodeFffff((PMNode *)CP_PTR(0x3C), 1.15f, 1.15f, 1.15f, 1.0f);
                nBonus = 5;
            }
            SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 5, nBonus);
        }
        if (CP_B(0x160) == 0) {
            CP_I(0x10C) &= 0xF8FFFFFF;
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    }
    if (m_unk20 >= 0) {
        CheckBlockAttack();
    }
    if (CP_PTR(0x38) != 0 && (*(int *)(CP_PTR(0x38) + 0x108) & 0x400)) {
        WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
        if (CP_PTR(0x38) != 0) {
            __dl__FPv(CP_PTR(0x38));
        }
        CP_PTR(0x38) = 0;
        CP_I(0x10C) &= 0xFDFFFFFF;
        EnableSleep__15EntityBaseClassFbb(this, false, false);
        CP_I(0x1FC) = 0;
        SetState__15EntityBaseClassFi(this, 9);
        CP_I(0x218) = 1;
        DeleteEffects();
        DeleteTimers();
        CP_B(0x2BC) = 0;
        if (m_unk2B4 != 0) {
            m_unk2B4->DestroyFxTriggers(false, true, false);
        }
    }
}
#undef CP_I
#undef CP_F
#undef CP_B
#undef CP_S
#undef CP_P
#undef CP_PTR
#undef CP_PICK_SIDE

// FUNCTION: 0x001E26C0 __dt__16ClockworkPuncherFv
extern "C" ClockworkPuncher *__dt__16ClockworkPuncherFv(ClockworkPuncher *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__16ClockworkPuncher;
        DestroyDamageFx__15EntityBaseClassFUi(pThis, (unsigned int)pThis->m_unk2C4);
        pThis->m_unk2C4 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001E2730 __ct__16ClockworkPuncherFv
ClockworkPuncher::ClockworkPuncher() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 0U);
    m_unk0 = __vt__16ClockworkPuncher;
    m_unk271 = 0;
    m_unk224 = 0;
    m_unk280 = 0;
    m_unk274 = 0;
    m_unk294 = 7.0f;
    m_unk288 = 0;
    m_unk2B4 = 0;
    m_unk277 = 1;
    m_unk2BD = 0;
    m_unk214 = 0;
    m_unk27C = 0;
    m_unk288 = 0;
    m_unk28C = 0;
    m_unk298 = 0;
    m_unk29C = 0;
    m_unk2A4 = 0;
    m_unk2A8 = 0;
    m_unk2A0 = 0;
    m_unk2AC = 0;
    m_unk2B0 = 0;
    m_unk2B8 = 0;
    m_unk2BC = 0;
    m_unk2C0 = 0;
    m_unk2C8 = 0;
    m_unk2CC = 0;
    m_unk2D0 = 0;
    m_unk2D4 = 0;
    m_unk2C4 = 0;
    m_unkF8 = 1.5f;
    m_unkFC = 2.0f;
    m_unk166 = 1;
}
