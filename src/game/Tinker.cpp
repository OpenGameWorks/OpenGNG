// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Tinker.h"

// TODO(header): foreign declarations
class EntityBaseClass;
class EntityManager;
class PArray;
class MathAPI;
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(float (*)[4], float (*)[4]);
// Apparition scratch list used by GetAllActiveApparitionsInRadius (same layout as Innocent.cpp).
struct TempApparitionArray { int m_count; int m_unk04; unsigned int *m_pData; char _pad0C[4]; };
extern TempApparitionArray mTempArray__15EntityBaseClass;
// The second argument is not set by the caller; the original leaves a1 untouched.
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);
// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("Tinker.cpp", line, #cond))
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" void *GetPtrToApparition__13EntityManagerFUi(EntityManager *pThis, unsigned int arg0);
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(EntityManager *pThis, int eLoadClass, PArray *pArray, float (*pBox)[4], float fRadius, int nFlags, bool bFlagA, bool bFlagB);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nState, char cParam, unsigned int uParam);
extern unsigned char gInterface[0xA60];
extern unsigned char gEng[0x19B90];
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bFlagA, bool bFlagB);
extern "C" void StartCutCamera__6CameraFUib(void *pThis, unsigned int arg0, bool bFlag);
extern "C" void Kill__6PlayerFv(void *pThis);
extern "C" void SetMaxValue__12HudBossMeterFsi(void *pThis, short nValue, int nFlag);
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char Tinker_AttackSeq[0x10];
extern unsigned char Tinker_Attack2Seq[0x10];
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, void *pSeq);
extern "C" void PlingInnocent__15EntityBaseClassFv(void *pThis);
extern "C" void DisplayString__11FontManagerFiiib(void *pThis, int nId, int nA, int nB, bool bFlag);
extern int InnocentDialogID[256];
extern "C" int IsPauseDisabled__6PlayerFv(void *pThis);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*arg0)[4], float (*arg1)[4]);
extern char *mPlayerAPI__13EntityManager;
extern "C" void SetupInnocentCamera__15EntityBaseClassFv(void *pThis);
extern "C" void *GetPickupData__6PickupFi(int nIndex);
extern "C" void GameVarAdd__6PlayerFUiii(void *pThis, unsigned int nVar, int nDelta, int nFlag);
extern "C" void SetAbility__6PlayerFii(void *pThis, int nIndex, int nFlag);
extern unsigned char Manda_AttackSeq[0x10];
extern unsigned char Baron_WalkSeq[0x10];
extern unsigned char Baron_RunSeq[0x10];
extern unsigned char Tinker_RunSeq[0x10];
extern unsigned char Tinker_WalkSeq[0x10];
extern unsigned char Manda_RunSeq[0x10];
extern unsigned char BGuard_RunSeq[0x10];
extern unsigned char Tinker_LoadMeshSeq[0x10];
extern unsigned char Tinker_IdleSeq[0x10];
extern unsigned char Tinker_AttackShortIdleSeq[0x10];
extern unsigned char Tinker_AttackIdleSeq[0x10];
extern unsigned char Tinker_Idle2Seq[0x10];
extern unsigned char Tinker_AwardSeq[0x10];
extern unsigned char Tinker_HitSeq[0x10];
extern unsigned char Tinker_DieSeq[0x10];
extern unsigned char Tinker_DeadSeq[0x10];
extern unsigned char Tinker_TransitionToIdleSeq[0x10];
extern unsigned char Tinker_TransitionFromAttackToIdleSeq[0x10];
extern unsigned char TinkerTransitionFromIdleToAttackSeq[0x10];
extern unsigned char Baron_LoadMeshSeq[0x10];
extern unsigned char Baron_IdleSeq[0x10];
extern unsigned char Baron_Attack2Seq[0x10];
extern unsigned char Baron_AttackSeq[0x10];
extern unsigned char Baron_AttackShortIdleSeq[0x10];
extern unsigned char Baron_AwardSeq[0x10];
extern unsigned char Baron_TalkSeq[0x10];
extern unsigned char Baron_HitSeq[0x10];
extern unsigned char Baron_DieSeq[0x10];
extern unsigned char Baron_DeadSeq[0x10];
extern unsigned char Baron_TransitionToIdleSeq[0x10];
extern unsigned char Manda_LoadMeshSeq[0x10];
extern unsigned char Manda_IdleSeq[0x10];
extern unsigned char Manda_TrappedSeq[0x10];
extern unsigned char Manda_ShortIdleSeq[0x10];
extern unsigned char Manda_TalkSeq[0x10];
extern unsigned char Manda_HitSeq[0x10];
extern unsigned char Manda_DieSeq[0x10];
extern unsigned char Manda_DeadSeq[0x10];
extern unsigned char Manda_TransitionToIdleSeq[0x10];
extern unsigned char BGuard_LoadMeshSeq[0x10];
extern unsigned char BGuard_IdleSeq[0x10];
extern unsigned char BGuard_AttackSeq[0x10];
extern unsigned char BGuard_TrappedSeq[0x10];
extern unsigned char BGuard_ShortIdleSeq[0x10];
extern unsigned char BGuard_TalkSeq[0x10];
extern unsigned char BGuard_HitSeq[0x10];
extern unsigned char BGuard_DieSeq[0x10];
extern unsigned char BGuard_DeadSeq[0x10];
extern unsigned char BGuard_TransitionToIdleSeq[0x10];
extern "C" int RandomIntRange__7MathAPIFii(int nMin, int nMax);
extern "C" float RandomFloatRange__7MathAPIFff(float fMin, float fMax);
extern "C" float Round180__Ff(float);
extern "C" void PlaySoundOnFrame__15EntityBaseClassFUiUi(void *pThis, unsigned int nSound, unsigned int nFrame);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
struct tagWaypointGroup { char _pad000[4]; unsigned int m_unk4; };
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);
extern "C" int ReadApparitionData__15EntityBaseClassFiUi(void *pThis, int nMode, unsigned int nId);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(EntityBaseClass *pEntity, float (*pPos)[4]);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *pThis, float *pOut);
extern "C" float GetAngleBetweenVectors__7MathAPIFPfPf(float *pA, float *pB);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *pThis, float (*pPos)[4]);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void CheckVariable__15EntityBaseClassFii(EntityBaseClass *pThis, int nValue, int nIndex);
extern int mbHard__15EntityBaseClass;
extern "C" void FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(void *pThis, EntityBaseClass *pOther);
extern "C" void CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(void *pThis, float (*pBox)[4], int nObjType, int nWeaponType, bool bFlag);
extern "C" void SetValue__12HudBossMeterFs(void *pThis, short nValue);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" int CreateTimer__8TimerAPIFUiUib(void *pThis, unsigned int nId, int nTime, bool bFlag);
extern "C" void *GetWaypointGroupInfo__15WaypointManagerFUi(void *pThis, unsigned int nIndex);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *pThis, int nType, unsigned int nFlags);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int nType, float (*pBox)[4]);
extern "C" int sprintf(char *pBuf, const char *pFmt, ...);
extern "C" int printf(const char *pFmt, ...);
extern unsigned char mTimerAPI__13EntityManager[0x40];
extern "C" float GetFrameTime__6PMNodeFv(void *pThis);

// Stab frame thresholds for the Baron attack sequence; 0xFFFF marks the end of the list.
static int StabFrames[9] = {0x12, 0x16, 0x1A, 0x1E, 0x22, 0xFFFF, 0x1, 0x10002F5, 0xFF};

// Apparition objects are reached through a virtual table; slot 12 sits at offset 0x30.
class ApparitionVirtual {
public:
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
    virtual void Slot12(int arg);
    virtual int Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual int Slot17();
};

extern "C" void OnInnocentAttack__15EntityBaseClassFP15EntityBaseClassi(void *pThis, EntityBaseClass *pAttacker, int nDamage);

// FUNCTION: 0x00208D60 __dt__6TinkerFv
Tinker::~Tinker() {}

// FUNCTION: 0x00208DD0 GetHealth__6TinkerFv
int Tinker::GetHealth() {
    return m_unk1B8;
}

// FUNCTION: 0x00208DE0 GetClassName__6TinkerFv
const char *Tinker::GetClassName() {
    return "Tinker";
}

// FUNCTION: 0x00208DF0 NeedsToBeWoken__6TinkerFv
int Tinker::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x208);
}

// FUNCTION: 0x00208E00 GetWokenVarPos__6TinkerFv
int Tinker::GetWokenVarPos() {
    return 16;
}

// FUNCTION: 0x00208E10 AttackSound__6TinkerFv
void Tinker::AttackSound() {
    if (m_unk140 == (int)Tinker_AttackSeq) {
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x2A4, 0xB);
    } else if (m_unk140 == (int)Tinker_Attack2Seq) {
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x2A4, 0xB);
    } else if ((void *)Manda_AttackSeq != 0) {
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xD9, 0xE);
    }
}

// FUNCTION: 0x00208E90 FootstepSound__6TinkerFv
void Tinker::FootstepSound() {
    int nType = m_unk1B0;
    int nSeq = m_unk140;
    switch (nType) {
    case 1:
        if (nSeq == (int)Baron_WalkSeq || nSeq == (int)Baron_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E23, 0x12);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E23, 0x21);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E23, 0x30);
        }
        break;
    case 0:
        if (nSeq == (int)Tinker_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E22, 5);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E22, 0xE);
            return;
        }
        if (nSeq == (int)Tinker_WalkSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E22, 0xA);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E22, 0x19);
        }
        break;
    case 2:
        if (nSeq == (int)Manda_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E24, 0xA);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E24, 0x14);
        }
        break;
    case 3:
        if (nSeq == (int)BGuard_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E24, 0xA);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E24, 0x14);
        }
        break;
    }
}

// DRAFT: 0x00208FF0 GetAnimSequence__6TinkerFUi
// note: 249 words; case 8 duplicates lui s0 and emits a separate b per arm (original shares a tail), so jump-table offsets shift; tried if/else, (bool) cast, local bool, ternary.
void *Tinker::GetAnimSequence(unsigned int arg0) {
    void *var_s0 = 0;
    if (m_unk1B0 == 0) {
        switch (arg0) {
        case 0:
            var_s0 = &Tinker_LoadMeshSeq;
            break;
        case 1:
        case 6:
            var_s0 = &Tinker_IdleSeq;
            break;
        case 7:
        case 15:
        case 18:
            var_s0 = &Tinker_RunSeq;
            break;
        case 8:
            bool bRand = (RandomIntRange__7MathAPIFii(0, 100) & 1) != 0;
            if (bRand) {
                var_s0 = &Tinker_Attack2Seq;
            } else {
                var_s0 = &Tinker_AttackSeq;
            }
            break;
        case 9:
            var_s0 = &Tinker_AttackShortIdleSeq;
            break;
        case 12:
            var_s0 = &Tinker_WalkSeq;
            break;
        case 11:
            var_s0 = &Tinker_AttackIdleSeq;
            break;
        case 10:
            if (m_unk140 == (int)&Tinker_Idle2Seq) {
                var_s0 = &TinkerTransitionFromIdleToAttackSeq;
            } else {
                var_s0 = &Tinker_AttackIdleSeq;
            }
            break;
        case 14:
        case 16:
            var_s0 = &Tinker_Idle2Seq;
            break;
        case 13:
            var_s0 = &Tinker_AwardSeq;
            break;
        case 3:
            var_s0 = &Tinker_HitSeq;
            break;
        case 4:
            var_s0 = &Tinker_DieSeq;
            break;
        case 19:
            var_s0 = &Tinker_DeadSeq;
            break;
        case 20:
            if (m_unk140 == (int)&Tinker_AttackIdleSeq || m_unk140 == (int)&TinkerTransitionFromIdleToAttackSeq) {
                var_s0 = &Tinker_TransitionFromAttackToIdleSeq;
            } else {
                var_s0 = &Tinker_TransitionToIdleSeq;
            }
            break;
        default:
            CdsAssert("Tinker.cpp", 0xB3F, "false");
            break;
        }
    } else if (m_unk1B0 == 1) {
        switch (arg0) {
        case 0:
            var_s0 = &Baron_LoadMeshSeq;
            break;
        case 1:
        case 6:
        case 10:
        case 11:
        case 16:
            var_s0 = &Baron_IdleSeq;
            break;
        case 7:
        case 15:
        case 18:
            var_s0 = &Baron_RunSeq;
            break;
        case 8:
            if ((bool)(RandomIntRange__7MathAPIFii(0, 100) & 1)) {
                var_s0 = &Baron_Attack2Seq;
            } else {
                var_s0 = &Baron_AttackSeq;
            }
            break;
        case 9:
            var_s0 = &Baron_AttackShortIdleSeq;
            break;
        case 12:
            var_s0 = &Baron_WalkSeq;
            break;
        case 13:
            var_s0 = &Baron_AwardSeq;
            break;
        case 14:
            var_s0 = &Baron_TalkSeq;
            break;
        case 3:
            var_s0 = &Baron_HitSeq;
            break;
        case 4:
            var_s0 = &Baron_DieSeq;
            break;
        case 19:
            var_s0 = &Baron_DeadSeq;
            break;
        case 20:
            var_s0 = &Baron_TransitionToIdleSeq;
            break;
        default:
            CdsAssert("Tinker.cpp", 0xB96, "false");
            break;
        }
    } else if (m_unk1B0 == 2) {
        switch (arg0) {
        case 0:
            var_s0 = &Manda_LoadMeshSeq;
            break;
        case 1:
        case 6:
        case 16:
            var_s0 = &Manda_IdleSeq;
            break;
        case 7:
        case 12:
        case 15:
        case 18:
            var_s0 = &Manda_RunSeq;
            break;
        case 8:
            var_s0 = &Manda_AttackSeq;
            break;
        case 17:
            var_s0 = &Manda_TrappedSeq;
            break;
        case 9:
        case 10:
        case 11:
            var_s0 = &Manda_ShortIdleSeq;
            break;
        case 13:
        case 14:
            var_s0 = &Manda_TalkSeq;
            break;
        case 3:
            var_s0 = &Manda_HitSeq;
            break;
        case 4:
            var_s0 = &Manda_DieSeq;
            break;
        case 19:
            var_s0 = &Manda_DeadSeq;
            break;
        case 20:
            var_s0 = &Manda_TransitionToIdleSeq;
            break;
        default:
            CdsAssert("Tinker.cpp", 0xBD4, "false");
            break;
        }
    } else if (m_unk1B0 == 3) {
        switch (arg0) {
        case 0:
            var_s0 = &BGuard_LoadMeshSeq;
            break;
        case 1:
        case 6:
        case 16:
            var_s0 = &BGuard_IdleSeq;
            break;
        case 7:
        case 12:
        case 15:
        case 18:
            var_s0 = &BGuard_RunSeq;
            break;
        case 8:
            var_s0 = &BGuard_AttackSeq;
            break;
        case 17:
            var_s0 = &BGuard_TrappedSeq;
            break;
        case 9:
        case 10:
        case 11:
            var_s0 = &BGuard_ShortIdleSeq;
            break;
        case 13:
        case 14:
            var_s0 = &BGuard_TalkSeq;
            break;
        case 3:
            var_s0 = &BGuard_HitSeq;
            break;
        case 4:
            var_s0 = &BGuard_DieSeq;
            break;
        case 19:
            var_s0 = &BGuard_DeadSeq;
            break;
        case 20:
            var_s0 = &BGuard_TransitionToIdleSeq;
            break;
        default:
            CdsAssert("Tinker.cpp", 0xC12, "false");
            break;
        }
    }
    if (var_s0 == 0) {
        CdsAssert("Tinker.cpp", 0xC17, "aiRet");
    }
    return var_s0;
}

// FUNCTION: 0x00209440 SetAsActivatedEnemyTarget__6TinkerFv
void Tinker::SetAsActivatedEnemyTarget() {
    int i;
    int off;
    if (m_unk280 != 0) {
        CdsAssert("Tinker.cpp", 0xACD, "m_bTrapped == false");
    }
    for (i = 0, off = 0; i < 4; off += 4, i++) {
        EntityBaseClass *pEnt = *(EntityBaseClass **)((char *)this + off + 0x2AC);
        if (pEnt != 0) {
            ApparitionVirtual *pObj = (ApparitionVirtual *)InstanceIsValid__15EntityBaseClassFUi(pEnt);
            if (pObj != 0) {
                pObj->Slot12(*(int *)((char *)this + 0x0C));
            }
        }
    }
}

// FUNCTION: 0x002094E0 SetAsEnemyTarget__6TinkerFUib
void Tinker::SetAsEnemyTarget(unsigned int arg0, bool arg1) {
    void *pObj = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, arg0);
    if (pObj != 0) {
        int v = arg1 ? *(int *)((char *)this + 0x0C) : 0;
        ((ApparitionVirtual *)pObj)->Slot12(v);
    }
}

// FUNCTION: 0x00209E40 TrappedEntityRemoved__6TinkerFv
bool Tinker::TrappedEntityRemoved() {
    EntityBaseClass **pEnt = m_unk1F0;
    int i = 0;
    do {
        if (*pEnt != 0 && InstanceIsValid__15EntityBaseClassFUi(*pEnt)) {
            return false;
        }
        i++;
        pEnt++;
    } while (i < 4);
    return true;
}

// FUNCTION: 0x00209540 IsBadWaypoint__6TinkerFUi
unsigned int Tinker::IsBadWaypoint(unsigned int arg0) {
    int off;
    unsigned int n = m_unk2D0.m_unk0;
    unsigned int i;
    i = 0;
    off = 0;
    int v;
    goto test;
body:
    v = (i < n) ? *(int *)((char *)m_unk2D0.m_unk8 + off) : 0;
    if (v == (int)arg0) {
        return 1;
    }
    off += 4;
    i++;
test:
    if (i < n) goto body;
    return 0;
}

// FUNCTION: 0x002095A0 GetClosestWaypoint__6TinkerFRA4_fb
int Tinker::GetClosestWaypoint(float (&pos)[4], bool bFlag) {
    int nBest;
    unsigned char bLast;
    float fBest;
    float *wp;
    unsigned int i;
    unsigned char bWpFlag;
    float p[4];
    float d;

    if (m_unk2A8 != 0) {
        nBest = -1;
        bLast = 0;
        fBest = 99999.0f;
        for (i = 0; i < m_unk2C8; i++) {
            wp = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, (tagWaypointGroup *)m_unk2A8, i, bWpFlag);
            if (i == m_unk2C4 || IsBadWaypoint(i)) {
                continue;
            }
            p[0] = wp[0];
            p[1] = wp[1];
            p[2] = wp[2];
            if (bFlag) {
                unsigned char bNear;
                bNear = FastMath_Fabs__Ff(GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f((EntityBaseClass *)this, &p)) <= 90.0f;
                if (!bNear) {
                    continue;
                }
            }
            float (*pTarget)[4];
            if (m_unk3C != 0) {
                pTarget = (float (*)[4])(m_unk3C + 0x80);
            } else {
                pTarget = (float (*)[4])m_unk190;
            }
            d = DistanceXZ__7MathAPIFPA4_fPA4_f(pTarget, &p);
            if (d < fBest) {
                *(u_long128 *)pos = *(u_long128 *)p;
                fBest = d;
                nBest = i;
                bLast = bWpFlag != 0;
                if (bLast) {
                    bLast = (i + 1 < m_unk2C8);
                }
            }
        }
        if (nBest >= 0) {
            Add__6PArrayFPv((char *)this + 0x2D0, (void *)m_unk2C4);
            m_unk2C4 = nBest;
            m_unk2E0 = bLast;
        }
        return nBest >= 0;
    }
    return 0;
}

// FUNCTION: 0x00209760 GetNextPosition__6TinkerFRA4_f
int Tinker::GetNextPosition(float (&pos)[4]) {
    tagWaypointGroup *pGroup = (tagWaypointGroup *)m_unk2A8;
    if (pGroup != 0) {
        if (m_unk2CC < m_unk2C8) {
            unsigned char bPrimary;
            float *pWp = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, pGroup, m_unk2CC, bPrimary);
            pos[0] = pWp[0];
            pos[1] = pWp[1];
            pos[2] = pWp[2];
            m_unk2CC++;
            return 1;
        }
        unsigned char bFlag;
        float *pWp = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, pGroup, m_unk2C8 - 1, bFlag);
        if (bFlag) {
            pos[0] = pWp[0];
            pos[1] = pWp[1];
            pos[2] = pWp[2];
            float (*pTarget)[4];
            if (m_unk3C != 0) {
                pTarget = (float (*)[4])(m_unk3C + 0x80);
            } else {
                pTarget = (float (*)[4])m_unk190;
            }
            if (DistanceXZ__7MathAPIFPA4_fPA4_f(pTarget, &pos) > 1.0f) {
                return 1;
            }
        }
    }
    return 0;
}

// FUNCTION: 0x00209860 AwardCheck__6TinkerFv
int Tinker::AwardCheck() {
    bool bZero;
    bZero = (m_unk1B0 == 0);
    if (!bZero) {
        bZero = (m_unk1B0 == 1);
    }
    if (bZero) {
        if (ReadApparitionData__15EntityBaseClassFiUi(this, 2, 0) == 0) {
            return 1;
        }
    } else {
        switch (m_unk200) {
        case 7:
        case 8:
            if (ReadApparitionData__15EntityBaseClassFiUi(this, 1, 0) == 0) {
                return 1;
            }
            break;
        default:
            if (ReadApparitionData__15EntityBaseClassFiUi(this, 3, 0) == 0) {
                return 1;
            }
            break;
        }
    }
    return (m_unk2C1 != 0) ^ 1;
}

// FUNCTION: 0x00209930 IsStalled__6TinkerFfPA4_f
int Tinker::IsStalled(float fDist, float (*arg1)[4]) {
    float (*pTarget)[4];
    float d1;
    float d2;
    if (m_unk3C != 0) {
        pTarget = (float (*)[4])(m_unk3C + 0x80);
    } else {
        pTarget = (float (*)[4])m_unk190;
    }
    d1 = DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk250, arg1);
    d2 = DistanceXZ__7MathAPIFPA4_fPA4_f(pTarget, arg1);
    return ((d1 - d2) <= fDist) ? 1 : 0;
}

// DRAFT: 0x002099C0 MoveTo__6TinkerFPA4_ff
// note: 5 differing words; the flag select is a branch (`bnez`/`b`), not the original `movz`. m_unk250 store moved inside `if (c & 4)`. Tried ternary local (6), nCond local (5), bool bSet (6), default-8-then-override (5, kept).
int Tinker::MoveTo(float (*arg0)[4], float arg1) {
    int nFlags;
    char *pPath;
    float pos[4];
    float fwd[4];
    float dir[4];
    float path[4];
    float f20;
    float f21;
    float *pDst;

    nFlags = 0;
    pPath = *(char **)((char *)m_unk38 + 0xE4);
    *(u_long128 *)pos = *(u_long128 *)arg0;
    f20 = DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])pos, (m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190));
    if (pPath != 0) {
        *(u_long128 *)path = *(u_long128 *)(pPath + 0x10);
        GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, fwd);
        sceVu0SubVector(dir, pos, (float *)((m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190)));
        sceVu0Normalize(fwd, fwd);
        sceVu0Normalize(path, path);
        sceVu0Normalize(dir, dir);
        f21 = GetAngleBetweenVectors__7MathAPIFPfPf(path, fwd);
        if (!(GetAngleBetweenVectors__7MathAPIFPfPf(path, dir) <= 90.0f)) {
            if (!(f21 <= 120.0f)) {
                {
                    int nBit = 8;
                    if (((*(int *)(pPath + 0xC)) & 0x80) == 0) {
                        nBit = 4;
                    }
                    nFlags |= nBit;
                }
            }
        }
    }
    *(int *)((char *)m_unk38 + 0x118) = 0;
    if (f20 > arg1 + 6.0f) {
        f21 = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])pos);
        if (FastMath_Fabs__Ff(f21) > 45.0f) {
            RotateTo(f21, 0.16f);
        } else {
            pDst = (m_unk3C != 0) ? (float *)(m_unk3C + 0x90) : (float *)((char *)this + 0x1A0);
            pDst[1] = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])pos);
        }
    } else {
        pDst = (m_unk3C != 0) ? (float *)(m_unk3C + 0x90) : (float *)((char *)this + 0x1A0);
        pDst[1] = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])pos);
    }
    {
        signed char c = m_unk3C[0x3F] & 7;
        if (c & 4) {
            if (IsStalled(0.5f, (float (*)[4])pos)) {
                nFlags |= 1;
            }
            *(u_long128 *)m_unk250 = *(u_long128 *)((m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190));
        }
    }
    if (f20 <= arg1) {
        nFlags |= 2;
    }
    return nFlags;
}

// FUNCTION: 0x00209C30 FindClosestEnemy__6TinkerFPA4_fQ215EntityBaseClass9LoadClassUi
void *Tinker::FindClosestEnemy(float (*pBox)[4], EntityBaseClass::LoadClass eLoadClass, unsigned int nFlags) {
    EntityBaseClass *pNearestApparition;
    EntityBaseClass *pSecond;
    float fNearest;
    float fSecond;
    unsigned int nHandle;
    EntityBaseClass *pApp;
    float fDist;
    float (*pPos)[4];
    int nIdx;

    if (mTempArray__15EntityBaseClass.m_pData != 0) {
        mTempArray__15EntityBaseClass.m_count = 0;
        mTempArray__15EntityBaseClass.m_unk04 = 0;
    }
    GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, eLoadClass, (PArray *)&mTempArray__15EntityBaseClass, pBox, m_unk1D0[3], nFlags, true, false);
    mTempArray__15EntityBaseClass.m_unk04 = 0;
    fNearest = 99999.0f;
    fSecond = 99999.0f;
    pNearestApparition = 0;
    pSecond = 0;
    nHandle = (mTempArray__15EntityBaseClass.m_count != 0) ? mTempArray__15EntityBaseClass.m_pData[0] : 0;
    while (nHandle != 0) {
        pApp = (EntityBaseClass *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, nHandle);
        if (pApp != 0 && pApp->m_unk163 != 6 && pApp->m_unk3C != 0) {
            pPos = (pApp->m_unk3C != 0) ? (float (*)[4])(pApp->m_unk3C + 0x80) : (float (*)[4])((char *)pApp + 0x190);
            fDist = DistanceXZ__7MathAPIFPA4_fPA4_f(pBox, pPos);
            if (fDist < fNearest) {
                fSecond = fNearest;
                pSecond = pNearestApparition;
                fNearest = fDist;
                pNearestApparition = pApp;
            } else if (fDist < fSecond) {
                fSecond = fDist;
                pSecond = pApp;
            }
        }
        nIdx = mTempArray__15EntityBaseClass.m_unk04 + 1;
        mTempArray__15EntityBaseClass.m_unk04 = nIdx;
        nHandle = ((unsigned int)nIdx < (unsigned int)mTempArray__15EntityBaseClass.m_count) ? mTempArray__15EntityBaseClass.m_pData[mTempArray__15EntityBaseClass.m_unk04] : 0;
    }
    if (pSecond != 0) {
        CDS_ASSERT(0x91B, pNearestApparition);
        if (pNearestApparition->m_unk04 == *(int *)((char *)*(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x1CC) || pNearestApparition->m_unk04 == m_unk2E8) {
            pNearestApparition = pSecond;
        }
    }
    return pNearestApparition;
}

// FUNCTION: 0x00209EB0 EnemiesInCheckRadius__6TinkerFv
int Tinker::EnemiesInCheckRadius() {
    float box[4];
    float *pLast = &box[3];
    box[0] = m_unk1D0[0];
    box[1] = m_unk1D0[1];
    box[2] = m_unk1D0[2];
    *pLast = m_unk1D0[3];
    return GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, 0, &box, *pLast, 0, true, false);
}

// FUNCTION: 0x00209F10 ActivateAttackingEnemies__6TinkerFv
void Tinker::ActivateAttackingEnemies() {
    EntityBaseClass **pSlot = m_unk1E0;
    int i = 0;
    EntityBaseClass *pEnt;
    ApparitionVirtual *pValid;
    int off = 0;
    do {
        pEnt = *pSlot;
        if (pEnt != 0) {
            pValid = (ApparitionVirtual *)InstanceIsValid__15EntityBaseClassFUi(pEnt);
            if (pValid != 0) {
                if (pValid->Slot17() == 0) {
                    ((unsigned char *)pValid)[0x1A] = 1;
                }
                if (m_unk280 == 0) {
                    pValid->Slot12(*(int *)((char *)this + 0x0C));
                }
                *(EntityBaseClass **)((char *)this + off + 0x2AC) = pEnt;
            }
        }
        i++;
        off += 4;
        pSlot++;
    } while (i < 4);
    m_unk2C0 = 1;
}

// DRAFT: 0x00209FF0 ActivatedEnemiesDead__6TinkerFv
// note: 16 differing lines; the m_unk2C0==0 path returns 0 (the 0x1C delay slot sets v0=0). Remaining diffs: the 0x1C/0x28 branch targets, the 0x2C daddu vs addiu return hoist, and the 0x94 beqz vs bnez. Tried folded && guards (22), split early returns (49), nested guard (42), and the tail `if (m_unk228 != 0 && InstanceIsValid(...) != 0) return 0; return 1;` (16, kept).
int Tinker::ActivatedEnemiesDead() {
    if (m_unk2BC != 0 && m_unk2C0 != 0) {
        int i = 0;
        int off = 0;
        do {
            EntityBaseClass **pSlot = (EntityBaseClass **)((char *)this + off + 0x2AC);
            EntityBaseClass *pEnt = *pSlot;
            if (pEnt != 0) {
                ApparitionVirtual *pValid = (ApparitionVirtual *)InstanceIsValid__15EntityBaseClassFUi(pEnt);
                if (pValid != 0 && pValid->Slot13() > 0) {
                    return 0;
                }
                *pSlot = 0;
            }
            i++;
            off += 4;
        } while (i < 4);
        if (m_unk228 != 0 && InstanceIsValid__15EntityBaseClassFUi(m_unk228) != 0) {
            return 0;
        }
        return 1;
    }
    return 1;
}

// Layout-compatible view of the Tinker vtable. Two header entries precede the
// first virtual, so the 14th declared slot (index 13) sits at offset 0x3C.
class TinkerVirtual {
public:
    virtual void Slot0();
    virtual int Slot1();
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
    virtual unsigned char Slot13();
};

// FUNCTION: 0x0020A0E0 IsAlive__6TinkerFv
bool Tinker::IsAlive() {
    return m_unk1B8 > 0;
}

// FUNCTION: 0x0020A0F0 SetEditableVars__6TinkerFPc
void Tinker::SetEditableVars(char *arg0) {
    memcpy(&m_unk1B0, arg0, 0x84);
    m_unk1B8 *= 0x32;
    if (mbHard__15EntityBaseClass == 0) {
        int t = m_unk1B8;
        if (t != 0) {
            m_unk1B8 = t + 0x32;
        }
    }
    m_unk288 = m_unk1B8;
    CheckVariable__15EntityBaseClassFii((EntityBaseClass *)this, m_unk1B0, 4);
    CheckVariable__15EntityBaseClassFii((EntityBaseClass *)this, m_unk1B4, 3);
    m_unk2AC[0] = m_unk1E0[0];
    m_unk2AC[1] = m_unk1E0[1];
    m_unk2AC[2] = m_unk1E0[2];
    m_unk2AC[3] = m_unk1E0[3];
    if (m_unk210 < 0) {
        m_unk210 = 0;
    }
    if (m_unk1C0 == 0.0f && m_unk1C4 == 0.0f && m_unk1C8 == 0.0f) {
        CDS_ASSERT(0x82E, !"eif 0, 0, 0 error.  see keith or ted");
        float *p = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
        m_unk240 = p[0];
        p = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
        m_unk244 = p[1];
        p = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
        m_unk248 = p[2];
    }
    m_unk240 = m_unk1C0;
    m_unk244 = m_unk1C4;
    m_unk248 = m_unk1C8;
}

class HudBossVirtual {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
};

// FUNCTION: 0x0020A2A0 OnTimerEvent__6TinkerFUi
void Tinker::OnTimerEvent(unsigned int arg0) {
    if (arg0 == m_unk2EC) {
        EnableSleep__15EntityBaseClassFbb(this, false, false);
        StartCutCamera__6CameraFUib(gEng + 0x19760, m_unk218, false);
        *(unsigned char *)((char *)this + 0x17A) = 0;
    } else if (arg0 == m_unk278) {
        m_unk2F4 = 1;
        m_unk278 = 0;
    } else if (arg0 == m_unk2A4) {
        m_unk2A0 = 1;
    } else if (arg0 == m_unk284) {
        m_unk284 = 0;
    } else if (arg0 == m_unk28C) {
        m_unk28C = 0;
        int nBoss = m_unk1B8;
        if (nBoss != 0) {
            int nState = (m_unk1B0 == 0) ? 2 : 1;
            ((HudBossVirtual *)(gInterface + 0x270))->Slot4();
            SetMaxValue__12HudBossMeterFsi(gInterface + 0x270, (short)nBoss, nState);
        }
    } else if (arg0 == m_unk290) {
        m_unk290 = 0;
        Kill__6PlayerFv(*(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C));
    } else if (arg0 == m_unk294) {
        m_unk294 = 0;
    }
}

// FUNCTION: 0x0020A3D0 OnAttackEvent__6TinkerFP15EntityBaseClassi
void Tinker::OnAttackEvent(EntityBaseClass *pAttacker, int nDamage) {
    OnInnocentAttack__15EntityBaseClassFP15EntityBaseClassi(this, pAttacker, nDamage);
}

// DRAFT: 0x0020A6C0 Execute__6TinkerFv
// note: all cases transcribed and compiling, DIFF 1637 (size 0x18A4 vs 0x1A90, frame 0x80 vs 0x140); the 14/3/4/19 additions raised it from 1480; case 20 sits before 13 here, not in draft order.
void Tinker::Execute() {
    if ((m_unk20 >= 0) && (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) == 0)) {
        FootstepSound();
        if ((m_unk1B0 == 1) && (m_unk22C == 0) && (m_unk284 == 0)) {
            unsigned int nSound = 0;
            float fPct = (100.0f * (float)m_unk1B8) / (float)m_unk288;
            if (!(fPct < 75.0f)) {
                nSound = 0x15B;
            } else if (!(fPct < 40.0f)) {
                nSound = 0x15D;
            } else if (((TinkerVirtual *)this)->Slot13() != 0) {
                nSound = !(RandomIntRange__7MathAPIFii(0, 100) & 1) ? 0x167U : 0x15EU;
            }
            if (nSound != 0) {
                PlaySound__15EntityBaseClassFUi(this, nSound);
            }
            m_unk284 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04,RandomIntRange__7MathAPIFii(4, 8), 0);
        }
    }
    switch (m_unk20) {
    case -1:
        m_unk10C &= 0xF8FFFFFF;
        m_unk10C |= 0x07000000;
        if (m_unk38 == 0) {
            void *pPhys = __nw__FUi(0x120);
            if (pPhys != 0) {
                pPhys = __ct__7PhysicsFv(pPhys);
            }
            m_unk38 = (Physics *)pPhys;
            if (m_unk38 == 0) {
                CdsAssert("Tinker.cpp", 0x2F5, "mpPhysics");
            }
        }
        SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12, 0);
        if (m_unkD4 == 0) {
            void *pShadow = __nw__FUi(0x10);
            if (pShadow != 0) {
                pShadow = __ct__6ShadowFQ26Shadow10ShadowTypeUi(pShadow, 1, 0x87000006);
            }
            m_unkD4 = (char *)pShadow;
            if (m_unkD4 == 0) {
                CdsAssert("Tinker.cpp", 0x2FD, "mpShadow");
            }
        }
        if (m_unkD4 != 0) {
            *(unsigned char *)m_unkD4 = 1;
            char *pShadowSub = *(char **)(m_unkD4 + 0xC);
            if (pShadowSub != 0) {
                *(unsigned char *)(pShadowSub + 0x18) = 1;
            }
        }
        m_unk2A8 = 0;
        m_unk2E8 = 0;
        m_unk280 = (TrappedEntityRemoved() & 0xFF) == 0;
        m_unk2BC = 0;
        {
            int nIdx = 0;
            do {
                if (m_unk2AC[nIdx] != 0 && InstanceIsValid__15EntityBaseClassFUi(m_unk2AC[nIdx]) != 0) {
                    m_unk2BC++;
                }
                nIdx++;
            } while (nIdx < 4);
        }
        m_unk2C0 = (m_unk2BC != 0) ? 0 : 1;
        SetState__15EntityBaseClassFi(this, 0);
        if (m_unk1B0 == 0 || m_unk1B0 == 1) {
            m_unk28C = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 2, 1);
        }
        if (m_unk1BC >= 0) {
            m_unk2A8 = GetWaypointGroupInfo__15WaypointManagerFUi((char *)mpEntMgr__15EntityBaseClass + 0x30, (unsigned int)m_unk1BC);
            if (m_unk2A8 == 0) {
                char sMsg[0x40];
                sprintf(sMsg, "Tinker refers to bad waypoint group ( group id = %d )", m_unk1BC);
                CdsAssert("Tinker.cpp", 0x32E, sMsg);
            }
        }
        if (m_unk2D0.m_unk8 != 0) {
            m_unk2D0.m_unk0 = 0;
            m_unk2D0.m_unk4 = 0;
        }
        m_unk2E0 = 0;
        if (m_unk2A8 != 0) {
            m_unk2C8 = *(unsigned int *)((char *)m_unk2A8 + 4);
        } else {
            m_unk2C8 = 0;
        }
        switch (m_unk200) {
        case 7:
        case 8:
            m_unk2C1 = (ReadApparitionData__15EntityBaseClassFiUi(this, 1, 0) == 0) ? 0 : 1;
            return;
        default:
            m_unk2C1 = (ReadApparitionData__15EntityBaseClassFiUi(this, 3, 0) == 0) ? 0 : 1;
            return;
        }
        break;
    case 0:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            int nMode = m_unk1B4;
            if (nMode != 2 && nMode != 0) {
                if (nMode != 1) {
                    CdsAssert("Tinker.cpp", 0x37B, "Invalid Tinker AI mode");
                } else {
                    if ((int)m_unk2CC < 0) {
                        m_unk2C0 = 0;
                        m_unk2CC = 0;
                    }
                    if (m_unk2BC != 0 && ActivatedEnemiesDead() != 0 && TrappedEntityRemoved() != 0) {
                        CdsAssert("Tinker.cpp", 0x358, "false");
                    }
                }
            }
        }
        PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
        SetState__15EntityBaseClassFi(this, 1);
        return;
    case 1:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            m_unkE8 = 3;
            if (m_unk1B4 != 2 && m_unk1B4 != 0 && m_unk1B4 != 1) {
                CdsAssert("Tinker.cpp", 0x3A5, "Invalid Tinker AI mode");
            } else {
                PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            }
        }
        FacePlayer(0.04f);
        if (m_unk2C0 == 0) {
            char *pPlayer = mPlayerAPI__13EntityManager;
            char *pBox = pPlayer + 0x190;
            char *pTrack = *(char **)(pPlayer + 0x3C);
            if (pTrack != 0) {
                pBox = pTrack + 0x80;
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pBox, (float (*)[4])&m_unk240) < m_unk1CC) {
                EnableSleep__15EntityBaseClassFbb(this, false, false);
                ActivateAttackingEnemies();
                return;
            }
        } else {
            if (IsPauseDisabled__6PlayerFv(mPlayerAPI__13EntityManager) != 0 && m_unk230 != 0) {
                EnableSleep__15EntityBaseClassFbb(this, false, false);
                m_unkE8 |= 8;
                switch (m_unk1B4) {
                case 2:
                    SetState__15EntityBaseClassFi(this, 6);
                    return;
                case 0:
                    SetState__15EntityBaseClassFi(this, 0x15);
                    return;
                case 1:
                    SetState__15EntityBaseClassFi(this, 0x11);
                    return;
                }
            }
        }
        break;
    case 21:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            m_unk2A0 = 0;
            m_unk2A4 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 3, 0);
        }
        if (m_unk2A0 != 0) {
            SetState__15EntityBaseClassFi(this, 5);
            return;
        }
        break;
    case 5:
        if (EnemiesInCheckRadius() != 0) {
            SetState__15EntityBaseClassFi(this, 7);
            return;
        }
        SetState__15EntityBaseClassFi(this, 0xB);
        return;
    case 17:
        if (TrappedEntityRemoved() != 0) {
            if (m_unk280 != 0) {
                if (m_unk228 != 0) {
                    EntityBaseClass *pValid = (EntityBaseClass *)InstanceIsValid__15EntityBaseClassFUi(m_unk228);
                    if (pValid != 0) {
                        if (((ApparitionVirtual *)pValid)->Slot17() == 0) {
                            pValid->m_unk1A = 1;
                        }
                    } else {
                        printf("Instance ID %d could not be woken (called from trapped Tinker)\n", m_unk228);
                    }
                }
                m_unk280 = 0;
                SetAsActivatedEnemyTarget();
            }
            int nLoadClass = 3;
            unsigned int nFlags = 0;
            if (m_unk1B4 == 1 && m_unk1B0 == 0) {
                nLoadClass = 5;
                nFlags = 0x1E;
            }
            float (*pBox)[4] = (m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190);
            if (FindClosestEnemy(pBox, (EntityBaseClass::LoadClass)nLoadClass, nFlags) != 0) {
                SetState__15EntityBaseClassFi(this, 7);
            } else if (GetNextPosition(m_unk260) != 0) {
                SetState__15EntityBaseClassFi(this, 0x12);
            } else if (ActivatedEnemiesDead() != 0) {
                SetState__15EntityBaseClassFi(this, (m_unk224 == 0) ? 0x14 : 0xD);
            } else {
                SetState__15EntityBaseClassFi(this, 0xB);
            }
        } else {
            if (*(unsigned char *)((char *)this + 0xE9) != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            }
            if ((m_unk3C[0x3F] & 4) && m_unk294 == 0) {
                if (m_unk1B0 != 2 && m_unk1B0 != 3) {
                    CdsAssert("Tinker.cpp", 0x445, "(mEVars.m_iType == TYPE_MANDA) || (mEVars.m_iType == TYPE_RANDY)");
                }
                unsigned int nSound = 0x4E67;
                if (m_unk1B0 == 2) {
                    nSound = 0x4E63;
                }
                PlaySound__15EntityBaseClassFUi(this, nSound);
                m_unk294 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, RandomIntRange__7MathAPIFii(5, 0xF), 0);
            }
        }
        FacePlayer(0.04f);
        return;
    case 18:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            void *pSeq = GetAnimSequence(m_unk20);
            if ((int)pSeq != m_unk140) {
                PlaySequence__15EntityBaseClassFPUi(this, pSeq);
            }
        }
        m_unk298 = MoveTo((float (*)[4])m_unk260, 1.0f);
        if (m_unk298 & 2) {
            m_unk270 = 0;
            SetState__15EntityBaseClassFi(this, 7);
            return;
        }
        if (m_unk298 & 0xC) {
            m_unk274 -= 1;
            if (m_unk274 == 0) {
                m_unk274 = 5;
                float fOffset = 180.0f + RandomFloatRange__7MathAPIFff(-20.0f, 20.0f);
                if (m_unk3C != 0) {
                    ((float *)(m_unk3C + 0x90))[1] = ((float *)(m_unk3C + 0x90))[1] - fOffset;
                } else {
                    m_unk1A0[1] = m_unk1A0[1] - fOffset;
                }
                if (m_unk3C != 0) {
                    *(float *)((char *)m_unk38 + 0x11C) = Round180__Ff(((float *)(m_unk3C + 0x90))[1]);
                } else {
                    *(float *)((char *)m_unk38 + 0x11C) = Round180__Ff(m_unk1A0[1]);
                }
                return;
            }
        }
        break;
    case 7:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            int nLoadClass = 3;
            unsigned int nFlags = 0;
            if (m_unk1B4 == 1 && m_unk1B0 == 0) {
                nLoadClass = 5;
                nFlags = 0x1E;
            }
            float (*pBox)[4] = (m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190);
            EntityBaseClass *pFound = (EntityBaseClass *)FindClosestEnemy(pBox, (EntityBaseClass::LoadClass)nLoadClass, nFlags);
            if (pFound != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
                int nId = pFound->m_unk04;
                SetAsEnemyTarget(m_unk2E4, false);
                m_unk2E4 = nId;
                SetAsEnemyTarget(m_unk2E4, true);
            } else {
                m_unk2E4 = 0;
                m_unk2E8 = 0;
                int nState = 0xB;
                if (m_unk1B4 == 1) {
                    nState = 0x11;
                }
                SetState__15EntityBaseClassFi(this, nState);
                return;
            }
        }
        {
            EntityBaseClass *pApp = (EntityBaseClass *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk2E4);
            if (pApp != 0) {
                float (*pTarget)[4] = (pApp->m_unk3C != 0) ? (float (*)[4])(pApp->m_unk3C + 0x80) : (float (*)[4])((char *)pApp + 0x190);
                m_unk298 = MoveTo(pTarget, 4.0f);
                if (m_unk298 & 2) {
                    m_unk270 = 0;
                    SetState__15EntityBaseClassFi(this, 8);
                    return;
                }
                if (m_unk298 & 0xD) {
                    m_unk270 += 1;
                    if ((unsigned int)m_unk270 >= 4U) {
                        SetState__15EntityBaseClassFi(this, 0xF);
                        return;
                    }
                }
            } else {
                int nState = 5;
                if (m_unk1B4 == 1) {
                    nState = 0x11;
                }
                SetState__15EntityBaseClassFi(this, nState);
                return;
            }
        }
        break;
    case 8: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            m_unk2E8 = 0;
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            m_unk27C = 0;
            if (m_unk1B4 == 0) {
                m_unk2C4 = -1;
                if (m_unk2D0.m_unk8 != 0) {
                    m_unk2D0.m_unk0 = 0;
                    m_unk2D0.m_unk4 = 0;
                }
                m_unk2E0 = 0;
            }
            if (m_unk294 == 0) {
                unsigned int nSnd = 0;
                switch (m_unk1B0) {
                case 2:
                    nSnd = 0x4E63;
                    break;
                case 3:
                    nSnd = 0x4E67;
                    break;
                }
                if (nSnd != 0) {
                    PlaySound(nSnd);
                    m_unk294 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, RandomIntRange__7MathAPIFii(2, 7), 0);
                }
            }
        }
        EntityBaseClass *pApp = (EntityBaseClass *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk2E4);
        if (pApp != 0) {
            float (*pAppBox)[4] = (pApp->m_unk3C != 0) ? (float (*)[4])(pApp->m_unk3C + 0x80) : (float (*)[4])((char *)pApp + 0x190);
            RotateTo(GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pAppBox), 0.04f);
        }
        AttackSound();
        if (m_unk140 == (int)Baron_AttackSeq) {
            int nStab = m_unk27C;
            if ((int)GetFrameTime__6PMNodeFv(m_unk3C) >= StabFrames[nStab]) {
                m_unk27C = nStab + 1;
                ResetCollisions();
                if (StabFrames[m_unk27C] == 0xFFFF) {
                    PlaySound(0x13CU);
                }
            }
        }
        if (m_unk160 == 0) {
            int nOk = 1;
            if (pApp != 0 && pApp->m_unk163 != 6 && *(int *)((char *)pApp + 0x1C) == 0) {
                float (*pAppBox2)[4] = (pApp->m_unk3C != 0) ? (float (*)[4])(pApp->m_unk3C + 0x80) : (float (*)[4])((char *)pApp + 0x190);
                RotateTo(GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pAppBox2), 0.04f);
                float (*pSelfBox)[4] = (m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190);
                if (Distance__7MathAPIFPA4_fPA4_f(pSelfBox, pAppBox2) <= 6.0f) {
                    nOk = 0;
                }
            }
            if (nOk != 0) {
                SetState((m_unk1B4 != 0) ? 0x11 : 5);
                return;
            }
            SetState(9);
            return;
        }
        break;
    }
    case 9:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            m_unk2A0 = 0;
            m_unk2A4 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 0xF, 1);
        }
        if (m_unk2A0 != 0) {
            SetState(8);
            return;
        }
        break;
    case 12: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            EntityBaseClass *pPlayer = (EntityBaseClass *)mPlayerAPI__13EntityManager;
            float (*pBox)[4] = (pPlayer->m_unk3C != 0) ? (float (*)[4])(pPlayer->m_unk3C + 0x80) : (float (*)[4])((char *)pPlayer + 0x190);
            *(u_long128 *)m_unk260 = *(u_long128 *)pBox;
        }
        m_unk298 = MoveTo((float (*)[4])m_unk260, 4.0f);
        if (m_unk298 & 0xF) {
            SetState((m_unk224 == 0) ? 0x14 : 0xD);
            return;
        }
        break;
    }
    case 15: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            if (!(GetClosestWaypoint(m_unk260, 1) & 0xFF)) {
                EntityBaseClass *pPlayer = (EntityBaseClass *)mPlayerAPI__13EntityManager;
                float (*pBox)[4] = (pPlayer->m_unk3C != 0) ? (float (*)[4])(pPlayer->m_unk3C + 0x80) : (float (*)[4])((char *)pPlayer + 0x190);
                *(u_long128 *)m_unk260 = *(u_long128 *)pBox;
            }
            m_unk274 = 5;
        }
        m_unk298 = MoveTo((float (*)[4])m_unk260, 1.0f);
        int nMove = m_unk298;
        if (nMove & 2) {
            if (m_unk2E0 != 0) {
                GetClosestWaypoint(m_unk260, 1);
                return;
            }
            int nState = 5;
            if (m_unk1B4 == 1) {
                nState = 0x11;
            }
            SetState(nState);
            return;
        }
        if (nMove & 1) {
            m_unk270 = 0;
            m_unk2C4 = -1;
            if (m_unk2D0.m_unk8 != 0) {
                m_unk2D0.m_unk0 = 0;
                m_unk2D0.m_unk4 = 0;
            }
            SetState(0xA);
            return;
        }
        if (nMove & 0xC) {
            m_unk274 -= 1;
            if (m_unk274 == 0) {
                m_unk274 = 5;
                float fOffset = 180.0f + RandomFloatRange__7MathAPIFff(-20.0f, 20.0f);
                float *pTgt = (m_unk3C != 0) ? (float *)(m_unk3C + 0x90) : m_unk1A0;
                pTgt[1] = pTgt[1] - fOffset;
                float *pSelf = (m_unk3C != 0) ? (float *)(m_unk3C + 0x90) : m_unk1A0;
                *(float *)((char *)m_unk38 + 0x11C) = Round180__Ff(pSelf[1]);
                GetClosestWaypoint(m_unk260, 1);
                return;
            }
        }
        break;
    }
    case 10:
    case 11: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            void *pSeq = GetAnimSequence(m_unk20);
            if (m_unk140 != (int)pSeq) {
                PlaySequence__15EntityBaseClassFPUi(this, pSeq);
            }
            float (*pBox)[4] = (m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190);
            m_unk2F4 = (FindClosestEnemy(pBox, (EntityBaseClass::LoadClass)3, 0) != 0);
            m_unk278 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 2, 0);
        }
        FacePlayer(0.04f);
        if (m_unk2F4 != 0 && *(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) == 0) {
            float (*pBox2)[4] = (m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190);
            if (FindClosestEnemy(pBox2, (EntityBaseClass::LoadClass)3, 0) != 0) {
                SetState((m_unk1B4 != 0) ? 0x11 : 5);
                return;
            }
            if (ActivatedEnemiesDead() != 0) {
                SetState(0xC);
                return;
            }
            m_unk2F4 = 0;
            m_unk278 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 2, 0);
            if (m_unk20 != 0xA) {
                SetState(0xA);
            }
        }
        if (m_unk20 == 0xA) {
            PlingInnocent__15EntityBaseClassFv(this);
            return;
        }
        break;
    }
    case 6:
    case 16: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            m_unk2F4 = 0;
            m_unk278 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 2, 0);
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            EnableSleep__15EntityBaseClassFbb(this, 1, 0);
        }
        PlingInnocent__15EntityBaseClassFv(this);
        if (m_unk2F4 != 0 && *(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) == 0) {
            float (*pBox)[4] = (m_unk3C != 0) ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])((char *)this + 0x190);
            if (FindClosestEnemy(pBox, (EntityBaseClass::LoadClass)3, 0) != 0) {
                SetState((m_unk1B4 != 0) ? 0x11 : 5);
            }
            m_unk2F4 = 0;
            m_unk278 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 2, 0);
            return;
        }
        break;
    }
    case 20: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            if (!(ActivatedEnemiesDead() & 0xFF)) {
                unsigned int nDialog = m_unk214;
                if (nDialog < 0x100U) {
                    DisplayString__11FontManagerFiiib(gInterface + 0x80, InnocentDialogID[nDialog], -1, 0, false);
                }
                *(unsigned char *)(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x335) &= ~4;
            }
        }
        if (m_unk160 == 0) {
            SetState((ActivatedEnemiesDead() == 0) ? 0xE : 6);
            return;
        }
        break;
    }
    case 13: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
            unsigned int nDialog = m_unk20C;
            int nAward = AwardCheck() & 0xFF;
            if ((nDialog < 0x100U) && (m_unk224 == 0)) {
                if (nAward == 0) {
                    nDialog = m_unk210;
                }
                DisplayString__11FontManagerFiiib(gInterface + 0x80, InnocentDialogID[nDialog], -1, 0, false);
            }
            if ((nAward != 0) && (m_unk218 != 0)) {
                float fTime = m_unk21C;
                if (fTime == 0.0f) {
                    EnableSleep__15EntityBaseClassFbb(this, false, false);
                    StartCutCamera__6CameraFUib(gEng + 0x19760, m_unk218, false);
                } else {
                    float fFrames = 60.0f * fTime;
                    int nTime;
                    if (!(fFrames >= 2.1474836e9f)) {
                        nTime = (int)fFrames;
                    } else {
                        nTime = (int)(fFrames - 2.1474836e9f) | 0x80000000;
                    }
                    m_unk2EC = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, nTime, true);
                    *(unsigned char *)((char *)this + 0x17A) = 1;
                }
            } else if (m_unk224 == 0) {
                SetupInnocentCamera__15EntityBaseClassFv(this);
            }
            if (nAward != 0) {
                EntityBaseClass *pTarget = m_unk220;
                if (pTarget != 0) {
                    m_unk2F0 = (EntityBaseClass *)InstanceIsValid__15EntityBaseClassFUi(pTarget);
                    if (m_unk2F0 != 0) {
                        m_unk2F0->m_unk1A = 1;
                        EnableSleep__15EntityBaseClassFbb(m_unk2F0, false, false);
                    }
                }
            }
            if (m_unk2C1 != 0) {
                *(unsigned char *)(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x335) &= ~4;
            }
        }
        FacePlayer(0.04f);
        if ((m_unk2C1 == 0) && !(GetFrameTime__6PMNodeFv(m_unk3C) < 0.0f)) {
            int nPickup = m_unk200;
            if (nPickup != -1) {
                char *pPickup = (char *)GetPickupData__6PickupFi(nPickup);
                int nIndex = 0;
                while (nIndex < m_unk204) {
                    signed char nVar = *(signed char *)(pPickup + 1);
                    if (nVar != -1) {
                        GameVarAdd__6PlayerFUiii(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C), (unsigned int)nVar, *(short *)(pPickup + 2), 1);
                    } else {
                        SetAbility__6PlayerFii(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C), *(signed char *)(pPickup + 4), 1);
                    }
                    nIndex++;
                }
            }
            if (m_unk1B0 == 0 || m_unk1B0 == 1) {
                WriteApparitionData__15EntityBaseClassFicUi(this, 2, 1, 0U);
            } else {
                switch (m_unk200) {
                case 7:
                case 8:
                    WriteApparitionData__15EntityBaseClassFicUi(this, 1, 1, 0U);
                    break;
                default:
                    WriteApparitionData__15EntityBaseClassFicUi(this, 3, 1, 0U);
                    break;
                }
            }
            int nFlag = ((TinkerVirtual *)this)->Slot1();
            if (nFlag != 0) {
                WriteApparitionData__15EntityBaseClassFicUi(this, 0, (char)nFlag, 0U);
            }
            if (m_unk1B0 == 0) {
                WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
            }
            *(unsigned char *)(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x335) &= ~4;
            m_unk2C1 = 1;
        }
        if (m_unk160 == 0) {
            SetState(0x10);
            return;
        }
        break;
    }
    case 14: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
        }
        if (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) == 0) {
            SetState(0xA);
            return;
        }
        break;
    }
    case 3: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
        }
        if (m_unk160 == 0) {
            if (m_unk29C == 0xB || m_unk29C == 0xA) {
                int nNew = 5;
                if (m_unk1B4 == 1) {
                    nNew = 0x11;
                }
                m_unk29C = nNew;
            }
            SetState(m_unk29C);
            return;
        }
        break;
    }
    case 4: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            m_unk10C &= 0xF8FFFFFF;
            *(int *)((char *)m_unk38 + 0x118) = 0;
            if (m_unk38 != 0 && *(int *)((char *)m_unk38 + 0xCC) == 0) {
                if (m_unk38 != 0) {
                    __dl__FPv(m_unk38);
                }
                m_unk38 = 0;
            }
            m_unk290 = 0;
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
        }
        if (m_unk160 == 0) {
            if ((m_unk1B0 == 0) || (m_unk1B0 == 1)) {
                m_unk290 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 1, false);
            }
            SetState(0x13);
            return;
        }
        break;
    }
    case 19: {
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            EnableSleep__15EntityBaseClassFbb(this, true, false);
            PlaySequence__15EntityBaseClassFPUi(this, GetAnimSequence(m_unk20));
        }
        break;
    }
    }
}

// DRAFT: 0x0020A3E0 OnHitEvent__6TinkerFP15EntityBaseClassiUiUi
// note: 96 words differ; the 0x1FE block is 27 words in the original and 23 here, so the branch offsets and the shared jal/delay-slot placement shift. Tried: flat else-if (99), switch with fall-through (103), 6 tested before 16 (98).
int Tinker::OnHitEvent(EntityBaseClass *pOther, int arg1, unsigned int arg2, unsigned int arg3) {
    if (arg2 == 0x1FE) {
        if (m_unk20 != 10) {
            if (m_unk20 == 16 || m_unk20 == 6) {
                SetState__15EntityBaseClassFi(this, 0xD);
            } else {
                return 5;
            }
        } else {
            SetState__15EntityBaseClassFi(this, 0x14);
        }
        m_unkE8 = 3;
        return 1;
    }
    int nPrevState = m_unk20;
    if ((*(unsigned int *)((char *)pOther + 0x10C) & 1) != 0) {
        return (*(int *)((char *)pOther + 0x8) == 3) ? 5 : 4;
    }
    if (nPrevState == 3 || nPrevState == 4) {
        return 5;
    }
    if (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) != 0) {
        return 5;
    }
    FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(this, pOther);
    CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(this, 0, 3, 0, false);
    m_unk1B8 -= arg1;
    if (m_unk1B8 < 0) {
        m_unk1B8 = 0;
    }
    bool bFlag = (m_unk1B0 == 0 || m_unk1B0 == 1);
    if (bFlag) {
        SetValue__12HudBossMeterFs(gInterface + 0x270, (short)m_unk1B8);
    }
    if (m_unk1B8 > 0) {
        m_unk29C = nPrevState;
        SetState__15EntityBaseClassFi(this, 3);
    } else {
        SetState__15EntityBaseClassFi(this, 4);
        if (bFlag) {
            *(unsigned char *)(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x26D) = 1;
        }
    }
    return 1;
}

// FUNCTION: 0x0020A5A0 OnTouchEvent__6TinkerFP15EntityBaseClass
void Tinker::OnTouchEvent(EntityBaseClass *pOther) {
    if (((TinkerVirtual *)this)->Slot13() == 0) {
        return;
    }
    switch (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058)) {
    case 0:
        switch (m_unk1B4) {
        case 0:
            if (pOther != 0 && (*(unsigned int *)((char *)pOther + 0x10C) & 1) == 0 && m_unk2E4 != *(unsigned int *)((char *)pOther + 0x4) && m_unk20 != 8) {
                SetState__15EntityBaseClassFi(this, 7);
                return;
            }
            break;
        }
        break;
    }
}

// FUNCTION: 0x0020A660 OnDestroyEvent__6TinkerFv
void Tinker::OnDestroyEvent() {
    bool r = (m_unk1B0 == 0) || (m_unk1B0 == 1);
    if (r) {
        char *pSub = *(char **)(gInterface + 0x274);
        if (pSub != 0) {
            *(int *)(pSub + 0xC) = 0;
        }
        if (m_unk1B0 == 0) {
            WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0);
        }
    }
}

// FUNCTION: 0x0020C150 GetTallyType__6TinkerFv
int Tinker::GetTallyType() {
    return m_unk22C ? 3 : 0;
}

// FUNCTION: 0x0020C160 __ct__6TinkerFv
Tinker::Tinker() : EntityBaseClass((LoadClass)6, 0) {
    m_unk2F0 = 0;
    m_unkD4 = 0;
    m_unk2C4 = -1;
    m_unk2CC = -1;
    m_unk280 = 0;
    m_unk284 = 0;
    m_unk294 = 0;
    m_unk2EC = 0;
    m_unk278 = 0;
    m_unk2A4 = 0;
    m_unk284 = 0;
    m_unk28C = 0;
    m_unk290 = 0;
    m_unk294 = 0;
    *(float *)((char *)this + 0x104) = 1.5f;
    *(float *)((char *)this + 0x108) = 3.0f;
}
