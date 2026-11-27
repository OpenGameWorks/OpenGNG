// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "ClockworkStalker.h"

// TODO(header): foreign declarations
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern char ClockworkStalker_DashShortSeq[60];
extern char ClockworkStalker_DashShortLoopSeq[60];
extern char ClockworkStalker_DashBackSeq[60];
extern char ClockworkStalker_HitRightSeq[52];
extern char ClockworkStalker_VerticalDeathSeq[60];
extern char ClockworkStalker_StabDownDeathSeq[60];
extern char ClockworkStalker_DeadSeq[60];
extern char m_vBonusSpawnOffset[16];
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *, int, char, unsigned int);
extern "C" void SpawnBonus__15EntityBaseClassFPfii(void *, float *, int, int);
extern char ClockworkStalker_HitLeftSeq[52];
extern char ClockworkStalker_KnockBackSeq[60];
extern char ClockworkStalker_HitSeq[52];
extern char ClockworkStalker_LaunchSeq[52];
extern char ClockworkStalker_JuggleSeq[52];
extern char ClockworkStalker_JuggleInAirSeq[52];
extern char ClockworkStalker_KnockDownSeq[52];
extern char ClockworkStalker_GetUpSeq[52];
extern "C" int GetGroundPos__7MathAPIFPA4_f(void *);
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
extern char ClockworkStalker_Taunt2Seq[52];
extern char ClockworkStalker_DodgeSeq[52];
extern char ClockworkStalker_WalkSeq[52];
extern char ClockworkStalker_JumpOutSeq[60];
extern char ClockworkStalker_JumpFromShellSeq[52];
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *, unsigned int *);
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *, float *);
extern "C" float Round180__Ff(float f);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(void *, float (*)[4]);
extern "C" int RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(void *, void *, unsigned int);
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);
extern "C" void PlaySound__15EntityBaseClassFUi(void *, unsigned int);
extern "C" float GetAngleBetweenVectors__7MathAPIFPfPf(float *, float *);
extern "C" void RemoveFromAttackSystem__15EntityBaseClassFv(void *);
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern char ClockworkStalker_IdleSeq[52];
extern char ClockworkStalker_ComboAttackSeq[80];
extern char ClockworkStalker_LowSweepSeq[72];
extern "C" int CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(void *, unsigned int, unsigned int, float (*)[4], float (*)[4], void *, float, bool, int, bool);
extern "C" void ResetCollisions__15EntityBaseClassFv(void *);
extern int miRandom__7MathAPI;
// Shadow object layout used by the attack-start and case 25 states: byte at 0x0, pointer at 0xC, byte at 0x18.
class ClockworkShadowShell {
public:
    unsigned char unk0;
    char _pad001[0xC - 0x1];
    void *unkC;
    char _pad010[0x18 - 0x10];
    unsigned char unk18;
};
extern "C" void VectorRotateY__7MathAPIFPA4_ff(float *, float);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float s);
extern "C" float GetFrameTime__6PMNodeFv(void *);
extern "C" void *Find__6PMNodeFUi(void *, unsigned int);
extern "C" unsigned int CreateDamageFx__15EntityBaseClassFfUi(void *, float, unsigned int);
extern "C" void ChangeDamageFxInterval__15EntityBaseClassFUif(void *, unsigned int, float);
extern "C" int printf(const char *, ...);
extern "C" void *__nw__FUi(unsigned int);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *, int, unsigned int);
extern "C" void *__ct__7PhysicsFv(void *);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *, unsigned int, float (*)[4]);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, float (*)[4]);
extern "C" float cosf(float x);
extern "C" float sinf(float x);
extern float m_vDefaultSpawnVelocity[4];
extern char lit_0026C030[];
extern char lit_0026C0B0[];
extern char lit_0026C108[];
extern char lit_0026C118[];
extern char lit_0026C130[];
extern char lit_0026C150[];
extern char lit_0026C160[];

class ZinShell {
public:
    char _pad000[4];
    unsigned int m_unk4;
    char _pad008[0x224 - 0x008];
    int m_unk224;
    int m_unk228;
    unsigned char m_unk22C;
    unsigned char m_unk22D;
};

struct PosBlock {
    float x;
    float y;
    float z;
};
extern "C" ZinShell *Spawn__13EntityManagerFUibi(void *, unsigned int, int, bool);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern "C" void SetShellStartAndDest__8ZinShellFRA4_fRA4_f(void *, float (*)[4], float (*)[4]);
extern "C" void TriggerBGAnim__15EntityBaseClassFUiibUi(void *, unsigned int, int, bool, unsigned int);
extern "C" ZinShell *GetPtrToApparition__13EntityManagerFUi(void *, unsigned int);
extern "C" float RandomFloatRange__7MathAPIFff(float, float);
extern "C" void SetAllFade__6PMNodeFf(void *, float);
extern "C" void FacePlayer__15EntityBaseClassFf(void *, float);
extern char ClockworkStalker_NormalMesh[0x10];
extern char ClockworkStalker_TransitionMesh[0x10];
extern char ClockworkStalker_CamouflageMesh[0x10];

// Local view of PMNode with the virtual slots used here (dtor 0x08, Render 0x0C, SetFrameTime 0x10,
// CreateObjectDisplayList 0x14, Animate 0x18).
class PMNodeView {
public:
    virtual ~PMNodeView();
    virtual void Render(void *pLights, int a, int b);
    virtual void SetFrameTime(float fTime);
    virtual void CreateObjectDisplayList();
    virtual void Animate(float, float, void *, int, bool);
    char _pad004[0x38 - 0x04];
    float m_unk38;
    char _pad03C[0x3E - 0x3C];
    unsigned char m_unk3E;
    char _pad03F[0x94 - 0x3F];
    float m_unk94;
};

// FUNCTION: 0x001E2800 GetHealth__16ClockworkStalkerFv
int ClockworkStalker::GetHealth() {
    return m_unk1FC;
}

// FUNCTION: 0x001E2810 GetClassName__16ClockworkStalkerFv
const char *ClockworkStalker::GetClassName() {
    return "ClockworkStalker";
}

// FUNCTION: 0x001E2820 GetTallyType__16ClockworkStalkerFv
int ClockworkStalker::GetTallyType() {
    return 1;
}

// FUNCTION: 0x001E2830 GetArenaWaveID__16ClockworkStalkerFv
int ClockworkStalker::GetArenaWaveID() {
    return m_unk1D8;
}

// FUNCTION: 0x001E2840 IsArenaApparition__16ClockworkStalkerFv
bool ClockworkStalker::IsArenaApparition() {
    return m_unk1D8 ? true : false;
}

// FUNCTION: 0x001E2850 NeedsToBeWoken__16ClockworkStalkerFv
int ClockworkStalker::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x1DC);
}

// FUNCTION: 0x001E2860 GetWokenVarPos__16ClockworkStalkerFv
int ClockworkStalker::GetWokenVarPos() {
    return 5;
}

// FUNCTION: 0x001E2870 SetInnocentInstanceID__16ClockworkStalkerFUi
void ClockworkStalker::SetInnocentInstanceID(unsigned int value) {
    m_unk2DC = (int)value;
}

// DRAFT: 0x001E2880 PlaySoundOnFrame__16ClockworkStalkerFUiUi
// note: 48 words after plain (float)/(unsigned int) conversion casts; earlier: 0x34 float lands in f0 (original f1), so sub.s/cvt/c.lt operands swap and branch offsets shift; 59 words differ.
void ClockworkStalker::PlaySoundOnFrame(unsigned int arg0, unsigned int arg1) {
    int t0 = 0;
    float f1;
    if (m_unk3C != 0) {
        unsigned int t1;
        f1 = *(float *)(m_unk3C + 0x34);
        t1 = (unsigned int)f1;
        if (t1 != m_unk2F4) {
            m_unk2F4 = 0xF423F;
            if (t1 == arg1) {
                t0 = 1;
            } else {
                f1 = *(float *)(m_unk3C + 0x38);
                if (*(signed char *)(m_unk3C + 0x3F) & 4) {
                    f1 = -1000000.0f;
                }
                int at = arg1 < t1;
                if (*(float *)&m_unk2A8 != -1.0f) {
                    f1 = 1000000.0f;
                    at = arg1 < t1;
                }
                if (at != 0) {
                    float f0;
                    f0 = (float)arg1;
                    if (f1 < f0) {
                        t0 = 1;
                        *(float *)&m_unk2A8 = -1.0f;
                    }
                }
            }
            if (t0 != 0) {
                m_unk2F4 = t1;
                PlaySound__15EntityBaseClassFUi(this, arg0);
            }
        }
    }
}


// DRAFT: 0x001E29C0 CircleAround__16ClockworkStalkerFPff
// note: 108 words differ: this/arg0 register swap in prologue and xori/sltiu assert-compare form at 0x20-0x2C; no-op, inverted guard and local copy probes changed nothing
void ClockworkStalker::CircleAround(float *arg0, float arg1) {
    float v40[4];
    float v50[4];
    float v60[4];
    float f20;
    if (m_unk268 != 1 && m_unk268 != 2) {
        CdsAssert("ClockworkStalker.cpp", 0x9D5, "m_iSideStepDir == SIDESTEP_RIGHT || m_iSideStepDir == SIDESTEP_LEFT");
    }
    sceVu0SubVector(v40, arg0, (float *)(m_unk3C ? m_unk3C + 0x80 : &m_unk190));
    sceVu0Normalize(v40, v40);
    *(u_long128 *)v50 = *(u_long128 *)v40;
    if (m_unk268 == 1) {
        VectorRotateY__7MathAPIFPA4_ff(v50, arg1);
    } else {
        VectorRotateY__7MathAPIFPA4_ff(v50, -arg1);
    }
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, v60);
    sceVu0Normalize(v60, v60);
    f20 = GetAngleBetweenVectors__7MathAPIFPfPf(v50, v60);
    if (m_unk268 == 2) {
        f20 *= -1.0f;
    }
    if (f20 < -180.0f) {
        f20 += 360.0f;
    } else if (!(f20 <= 180.0f)) {
        f20 -= 360.0f;
    }
    if (!(GetAngleBetweenVectors__7MathAPIFPfPf(v40, v60) <= arg1)) {
        f20 *= -1.0f;
    }
    float *t = (float *)(m_unk3C ? m_unk3C + 0x90 : m_unk1A0);
    *(float *)(m_unk38 + 0x11C) = Round180__Ff(f20 + t[1]);
}

// FUNCTION: 0x001E2B80 KillTimers__16ClockworkStalkerFv
void ClockworkStalker::KillTimers() {
    mTimerAPI__13EntityManager.KillTimer(*(unsigned int *)((char *)this + 0x214));
    mTimerAPI__13EntityManager.KillTimer(m_unk2D8);
    mTimerAPI__13EntityManager.KillTimer(m_unk2D0);
    mTimerAPI__13EntityManager.KillTimer(m_unk2AC);
}

// DRAFT: 0x001E2BE0 LoadCorrectMesh__16ClockworkStalkerFb
// note: 8 words differ: f20/f21 swapped for fFrameTime/fAlpha; tried decl order swap, split init, -1.0f/0.0f on the left of the test, store/Find order swap (92), hoisted fAlpha (107), temp for m_unk38 (8, no change), separate decls fAlpha-first with either init order (8), permute.py 90s (8)
void ClockworkStalker::LoadCorrectMesh(bool arg0) {
    if ((m_unk2B0 == 0 || arg0) && (m_unk20 != 9 || m_unk20 != 0x18)) {
        float fFrameTime = -1.0f;
        float fAlpha = 0.0f;
        if (m_unk3C != 0) {
            fFrameTime = GetFrameTime__6PMNodeFv(m_unk3C);
            *(float *)&m_unk2A8 = ((PMNodeView *)m_unk3C)->m_unk38;
            fAlpha = ((PMNodeView *)Find__6PMNodeFUi(m_unk3C, 0xE1612999))->m_unk94;
        }
        switch (m_unk2A0) {
        case 0:
            m_unk2A4 = 0x3F800000;
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_NormalMesh);
            break;
        case 1:
        case 3:
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_TransitionMesh);
            break;
        case 2:
            m_unk2A4 = 0x3F800000;
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_CamouflageMesh);
            break;
        default:
            CdsAssert("ClockworkStalker.cpp", 0x994, "false");
            break;
        }
        if (m_unk2E4 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, m_unk2E4);
        }
        if (fFrameTime != -1.0f) {
            ((PMNodeView *)m_unk3C)->SetFrameTime(fFrameTime);
        }
        if (fAlpha != 0.0f) {
            PMNodeView *pNode = (PMNodeView *)Find__6PMNodeFUi(m_unk3C, 0xE1612999);
            pNode->m_unk94 = fAlpha;
            pNode->m_unk3E |= 8;
        }
        m_unk2B0 = 1;
    }
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

// FUNCTION: 0x001E2E40 CheckBlockAttack__16ClockworkStalkerFv
void ClockworkStalker::CheckBlockAttack() {
    MathAPI *player = mPlayerAPI__13EntityManager;
    if (player == 0) {
        CdsAssert("ClockworkStalker.cpp", 0x920, "pPlayer");
    }
    if (m_unk1FC > 0 && m_unkF4 == 0 && *(unsigned char *)((char *)player + 0x23D2) != 0) {
        unsigned short state = *(unsigned short *)((char *)player + 0x15E);
        if (state != 0xD && state != 0xF && ((state != 0x40) | 8) &&
            *(int *)((char *)player + 0x1CC) == (int)m_unk4 && InBlockableState()) {
            char *thisSide = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            char *playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
            if (Distance__7MathAPIFPA4_fPA4_f(playerSide, (float (*)[4])thisSide) <= 10.0f &&
                PlayerFacingUs() != 0 && MathAPI::RandomIntRange(1, 100) < 0x1F) {
                SetState__15EntityBaseClassFi(this, 0x1B);
            }
        }
    }
}

// FUNCTION: 0x001E2F70 FaceHit__16ClockworkStalkerFv
void ClockworkStalker::FaceHit() {
    float vFwd[4];
    EntityBaseClass *pPlayer = *(EntityBaseClass **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(pPlayer, vFwd);
    char *pSrc = *(char **)((char *)pPlayer + 0x3C);
    pSrc = pSrc ? pSrc + 0x90 : (char *)pPlayer + 0x1A0;
    float fDelta = *(float *)(pSrc + 4);
    int nState = *(int *)((char *)*(EntityBaseClass **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x154);
    switch (nState) {
    case 0x82000007:
        fDelta = fDelta - (-150.0f);
        break;
    case 0x8200000E:
        fDelta = fDelta - 150.0f;
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

// FUNCTION: 0x001E3510 OnHitEvent__16ClockworkStalkerFP15EntityBaseClassiUiUi
int ClockworkStalker::OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    int state;
    unsigned int temp;
    unsigned char t;
    PMNodeView *node;
    char *src;

    DeleteEffects();
    if (m_unkF4 != 0) {
        m_unk1FC -= arg1;
        if (m_unk1FC > 0) {
            return 1;
        }
        m_unk218 = arg2;
        SetState__15EntityBaseClassFi(this, 9);
        return 2;
    }
    t =*((unsigned char *)arg0 + 0x10C);
    if (t != 1 && t != 0x10) {
        return 5;
    }
    if (m_unk2A0 == 2 && !(arg2 & 0x100)) {
        m_unk2A0 = 3;
        m_unk2AC = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 0x2D, true);
        LoadCorrectMesh(true);
    }
    state = m_unk20;
    m_unk270 = (int)Find__6PMNodeFUi(m_unk3C, 0xE1612999U);
    node = (PMNodeView *)m_unk270;
    node->m_unk94 = *(float *)&m_unk274;
    node->m_unk3E |= 8;
    if ((unsigned int)(state - 5) <= 1U || state == 7) {
        if (m_unk3C != 0) {
            src = m_unk3C + 0x80;
        } else {
            src = &m_unk190;
        }
        *(u_long128 *)m_unk200 = *(u_long128 *)src;
    }
    if (state == 0x14) {
        if (GetFrameTime__6PMNodeFv(m_unk3C) < 30.0f) {
            m_unk2D4 = !(arg2 & 0x200) ? 0 : 1;
            m_unk21C = arg2;
            m_unk1FC -= arg1;
            if (m_unk1FC <= 0) {
                m_unk218 = arg2;
                SetState__15EntityBaseClassFi(this, 9);
                return 2;
            }
            SetState__15EntityBaseClassFi(this, 0x15);
            return 1;
        }
        goto block_22;
    }
block_22:
    if (state == 0x15 && GetFrameTime__6PMNodeFv(m_unk3C) < 20.0f) {
        m_unk2D4 = !(arg2 & 0x200) ? 0 : 1;
        m_unk21C = arg2;
        m_unk1FC -= arg1;
        if (m_unk1FC <= 0) {
            m_unk218 = arg2;
            SetState__15EntityBaseClassFi(this, 9);
            return 2;
        }
        SetState__15EntityBaseClassFi(this, 0x15);
        return 1;
    }
    m_unk1FC -= arg1;
    if (m_unk2E8 == 0 && (float)m_unk1FC <= (float)m_unk210 / 2.0f) {
        m_unk2E8 = CreateDamageFx__15EntityBaseClassFfUi(this, 90.0f, 0U);
    }
    temp = m_unk2E8;
    if (temp != 0 && (float)m_unk1FC <= (float)m_unk210 / 4.0f) {
        ChangeDamageFxInterval__15EntityBaseClassFUif(this, temp, 20.0f);
    }
    if (m_unk1FC <= 0) {
        ((PMNodeView *)m_unk3C)->Animate(0.0f, 0.0f, 0, 0, false);
        m_unk218 = arg2;
        SetState__15EntityBaseClassFi(this, 9);
        return 2;
    }
    m_unk21C = arg2;
    FaceHit();
    SetState__15EntityBaseClassFi(this, 4);
    return 1;
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

// FUNCTION: 0x001E38D0 OnAttackEvent__16ClockworkStalkerFP15EntityBaseClassi
void ClockworkStalker::OnAttackEvent(EntityBaseClass *, int) {
}

// DRAFT: 0x001E38E0 Execute__16ClockworkStalkerFv
// note: every switch-1 case is transcribed (none empty), switch 6 targets match the asm; DIFF 2740 words, still differs.
void ClockworkStalker::Execute() {
    char *temp_a0;
    void *temp_v0_8;
    float temp_f12;
    ZinShell *temp_v0_9;
    char *temp_v0_10;
    PosBlock *var_v1;
    float temp_f3;
    float temp_f2;
    float var_f0;
    float startPos[4];
    float destPos[4];
    int temp_v1_3;
    unsigned int temp_a1;
    ZinShell *temp_v0_11;
    PMNodeView *temp_v1_11;
    static int astallcountcount;
    static int aStopDashDst;
    static int init;
    switch (m_unk20) {
    case -1:
        if (m_unkE9 != 0) {
            m_unk200[0] = m_unk1C8;
            m_unk200[1] = m_unk1CC;
            m_unk200[2] = m_unk1D0;
            if (!(Distance__7MathAPIFPA4_fPA4_f((m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190, &m_unk200) <= *(float *)&m_unk1D4)) {
                printf(lit_0026C0B0);
                SetState__15EntityBaseClassFi(this, -2);
                return;
            }
            m_unk10C &= 0xF8FFFFFF;
            m_unk10C |= 0x071B1902;
            if (m_unkD4 == 0) {
                void *p = __nw__FUi(0x10);
                if (p != 0) {
                    p = __ct__6ShadowFQ26Shadow10ShadowTypeUi(p, 1, 0x87000008);
                }
                m_unkD4 = p;
                if (m_unkD4 == 0) {
                    CdsAssert(lit_0026C030, 0x14B, lit_0026C108);
                }
            }
            if (m_unk38 == 0) {
                void *p2 = __nw__FUi(0x120);
                if (p2 != 0) {
                    p2 = __ct__7PhysicsFv(p2);
                }
                m_unk38 = (char *)p2;
                if (m_unk38 == 0) {
                    CdsAssert(lit_0026C030, 0x150, lit_0026C118);
                }
            }
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12, 0);
            m_unk221 = 1;
            m_unk222 = 1;
            m_unk278 = 1;
            m_unk234 = 0x19;
            m_unk210 = m_unk1FC;
            if (*(float *)&m_unk1B8 == 0.0f) {
                if ((*(float *)&m_unk1BC == 0.0f) && (*(float *)&m_unk1C0 == 0.0f)) {
                    char *src = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                    m_unk1B8 = *(int *)(src + 0);
                    m_unk1BC = *(int *)(src + 4);
                    m_unk1C0 = *(int *)(src + 8);
                }
            }
            m_unk104 = 0x40400000;
            m_unk108 = 0x40000000;
            if (m_unk1B4 >= 2) {
                CdsAssert(lit_0026C030, 0x166, lit_0026C130);
            }
            if (m_unk1D8 != 0) {
                m_unk1C4 = m_unk18C;
                m_unk1D4 = m_unk18C;
            }
            if (m_unk1E0 != 2) {
                MathAPI *pl = mPlayerAPI__13EntityManager;
                char *a1 = (pl->m_unk3C != 0) ? pl->m_unk3C + 0x80 : (char *)pl + 0x190;
                char *s0 = (m_unk3C != 0) ? m_unk3C + 0x90 : (char *)&m_unk1A0;
                *(float *)(s0 + 4) = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])a1);
            }
            *(int *)(m_unk240 + 0x10) = m_unk1B8;
            *(int *)(m_unk240 + 0x14) = m_unk1BC;
            *(int *)(m_unk240 + 0x18) = m_unk1C0;
        }
        {
            MathAPI *pl2 = mPlayerAPI__13EntityManager;
            char *a1b = (pl2->m_unk3C != 0) ? pl2->m_unk3C + 0x80 : (char *)pl2 + 0x190;
            if (Distance__7MathAPIFPA4_fPA4_f(m_unk240 + 0x10, (float (*)[4])a1b) <= *(float *)&m_unk1C4) {
                if (m_unk1E0 != 0) {
                    SetState__15EntityBaseClassFi(this, 0xA);
                } else {
                    LoadCorrectMesh(true);
                    SetState__15EntityBaseClassFi(this, 0x19);
                }
            }
        }
        break;
    case 10:
        if (m_unkE9 != 0) {
            switch (m_unk1E0) {
            case 1:
            case 3:
                temp_v0_9 = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0xF, 0, 0);
                if (temp_v0_9 == 0) {
                    CdsAssert(lit_0026C030, 0x1A0, lit_0026C150);
                }
                m_unk228 = temp_v0_9->m_unk4;
                EnableSleep__15EntityBaseClassFbb(this, 0, 0);
                if (m_unk1E0 == 3) {
                    temp_v0_9->m_unk22C = 1;
                }
                temp_v0_10 = m_unk3C;
                var_v1 = (PosBlock *)&m_unk190;
                if (temp_v0_10 != 0) {
                    var_v1 = (PosBlock *)(temp_v0_10 + 0x80);
                }
                temp_f3 = *(float *)&m_unk1E4;
                temp_f2 = var_v1->x;
                if (temp_f3 == temp_f2 && *(float *)&m_unk1E8 == var_v1->y && *(float *)&m_unk1EC == var_v1->z) {
                    startPos[0] = temp_f2;
                    startPos[1] = 50.0f + var_v1->y;
                    var_f0 = var_v1->z;
                } else if (temp_f3 == 0.0f && *(float *)&m_unk1E8 == 0.0f && *(float *)&m_unk1EC == 0.0f) {
                    startPos[0] = temp_f2;
                    startPos[1] = 50.0f + var_v1->y;
                    var_f0 = var_v1->z;
                } else {
                    startPos[0] = temp_f3;
                    startPos[1] = *(float *)&m_unk1E8;
                    var_f0 = *(float *)&m_unk1EC;
                }
                startPos[2] = var_f0;
                destPos[0] = var_v1->x;
                destPos[1] = var_v1->y;
                destPos[2] = var_v1->z;
                SetShellStartAndDest__8ZinShellFRA4_fRA4_f(temp_v0_9, &startPos, &destPos);
                temp_v1_3 = m_unk1F4;
                if (temp_v1_3 != 0) {
                    temp_v0_9->m_unk224 = temp_v1_3;
                    temp_v0_9->m_unk228 = m_unk4;
                }
                goto block_99;
            case 2:
                temp_a1 = m_unk1F4;
                if (temp_a1 != 0) {
                    TriggerBGAnim__15EntityBaseClassFUiibUi(this, temp_a1, -1, 0, 0);
                }
                SetState__15EntityBaseClassFi(this, 0x12);
                return;
            case 4:
                LoadCorrectMesh(true);
                SetState__15EntityBaseClassFi(this, 0x19);
                return;
            default:
                CdsAssert(lit_0026C030, 0x1E6, lit_0026C160);
                goto block_99;
            }
        } else {
block_99:
            if (m_unk1E0 != 1) {
                CdsAssert(lit_0026C030, 0x1FD, lit_0026C160);
            } else {
                temp_v0_11 = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk228);
                if (temp_v0_11 == 0 || temp_v0_11->m_unk22D != 0) {
                    *(float *)&m_unk224 = RandomFloatRange__7MathAPIFff(0.0f, 360.0f);
                    SetState__15EntityBaseClassFi(this, 8);
                    EnableSleep__15EntityBaseClassFbb(this, 1, 0);
                }
            }
            goto block_541;
        }
        break;
    case 18: {
        float sp70[4];
        if (m_unkE9 != 0) {
            GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, sp70);
            sceVu0Normalize(sp70, sp70);
            sceVu0ScaleVector(sp70, sp70, *(float *)&m_unk1F8);
            *(u_long128 *)m_unk38 = *(u_long128 *)sp70;
            LoadCorrectMesh(true);
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_JumpOutSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_JumpOutSeq;
        }
        var_v1 = (PosBlock *)m_unk38;
        if (var_v1->x == 0.0f && var_v1->y == 0.0f && var_v1->z == 0.0f) {
            SetState__15EntityBaseClassFi(this, 0x19);
            PlaySound__15EntityBaseClassFUi(this, 0x2D7U);
        }
        goto block_541;
    }
    case 8: {
        float sp80[4];
        float fCos;
        float fSin;
        fCos = cosf(0.017453292f * *(float *)&m_unk224);
        fSin = sinf(0.017453292f * *(float *)&m_unk224);
        *(int *)(m_unk38 + 0x10C) = 0x3E4CCCCD;
        sp80[0] = m_vDefaultSpawnVelocity[2] * fSin + m_vDefaultSpawnVelocity[0] * fCos;
        sp80[2] = m_vDefaultSpawnVelocity[2] * fCos - m_vDefaultSpawnVelocity[0] * fSin;
        sp80[1] = m_vDefaultSpawnVelocity[1];
        *(u_long128 *)m_unk38 = *(u_long128 *)sp80;
        LoadCorrectMesh(true);
        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_JumpFromShellSeq);
        m_unk2E4 = (unsigned int *)ClockworkStalker_JumpFromShellSeq;
        if (*(float *)m_unk38 == 0.0f && *(float *)(m_unk38 + 4) == 0.0f && *(float *)(m_unk38 + 8) == 0.0f) {
            SetState__15EntityBaseClassFi(this, 0x19);
        }
        break;
    }
    case 13: {
        MathAPI *player;
        char *playerSide;
        char *ownSide;
        char *tgt;
        char *tgtSide;
        float dist;
        int roll;

        RemoveFromAttackSystem__15EntityBaseClassFv(this);
        *(int *)(m_unk38 + 0xEC) = 0x80113FD5;
        player = mPlayerAPI__13EntityManager;
        playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
        if (Distance__7MathAPIFPA4_fPA4_f(playerSide, &m_unk200) < *(float *)&m_unk1D4) {
            player = mPlayerAPI__13EntityManager;
            playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
            ownSide = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            dist = Distance__7MathAPIFPA4_fPA4_f(ownSide, (float (*)[4])playerSide);
            if (m_unk2DC != 0) {
                tgt = (char *)InstanceIsValid__15EntityBaseClassFUi((unsigned int)m_unk2DC);
                if (tgt != 0) {
                    if (((int (*)(void *))(*(void ***)tgt)[15])(tgt) != 0) {
                        tgtSide = (*(char **)(tgt + 0x3C) != 0) ? *(char **)(tgt + 0x3C) + 0x80 : tgt + 0x190;
                        ownSide = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                        if (Distance__7MathAPIFPA4_fPA4_f(ownSide, (float (*)[4])tgtSide) < dist) {
                            SetState__15EntityBaseClassFi(this, 5);
                            return;
                        }
                        goto block_139;
                    }
                    goto block_139;
                }
                goto block_140;
            }
block_139:
block_140:
            roll = MathAPI::RandomIntRange(1, 100);
            if (CanAttackPlayer() != 0) {
                SetState__15EntityBaseClassFi(this, 0);
            } else if (roll < 5) {
                SetState__15EntityBaseClassFi(this, 0x21);
            } else if (dist < 15.0f) {
                if (m_unk2EC <= 0) {
                    if (PlayerFacingUs() != 0) {
                        SetState__15EntityBaseClassFi(this, 0x1F);
                    } else {
                        m_unk2EC = 1;
                        SetState__15EntityBaseClassFi(this, 0x1A);
                    }
                } else {
                    goto block_150;
                }
            } else {
block_150:
                if (!(dist <= 20.0f)) {
                    player = mPlayerAPI__13EntityManager;
                    playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
                    m_unk2C0 = *(float *)playerSide;
                    ownSide = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                    m_unk2C4 = *(float *)(ownSide + 4);
                    m_unk264 = MathAPI::RandomIntRange(1, 2);
                    SetState__15EntityBaseClassFi(this, 0x22);
                } else {
                    m_unk2EC = 0;
                    SetState__15EntityBaseClassFi(this, 0x1A);
                }
            }
            goto block_541;
        }
        SetState__15EntityBaseClassFi(this, 0x19);
        goto block_541;
    }
    case 33:
        if (m_unkE9 != 0) {
            PlaySound__15EntityBaseClassFUi(this, 0x4E3DU);
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_Taunt2Seq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_Taunt2Seq;
        }
        FacePlayer__15EntityBaseClassFf(this, 0.15f);
        if (*(int *)((char *)this + 0x160) == 0) {
            SetState__15EntityBaseClassFi(this, 0xD);
        }
        goto block_541;
    case 26: {
        int blk[4];
        int t;
        if (m_unkE9 != 0) {
            char *var8 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            *(u_long128 *)m_unk240 = *(u_long128 *)var8;
            m_unk280 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, MathAPI::RandomIntRange(0x168, 0x258), true);
            {
                char *ownSide = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                MathAPI *player = mPlayerAPI__13EntityManager;
                char *playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
                Distance__7MathAPIFPA4_fPA4_f(playerSide, (float (*)[4])ownSide);
            }
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_WalkSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_WalkSeq;
            t = m_unk26C;
            if (t == 3) {
                m_unk26C = 0;
                m_unk268 = 1;
                blk[1] = 0xC2B60000;
            } else if (t == 4) {
                m_unk26C = 0;
                m_unk268 = 2;
                blk[1] = 0x42B60000;
            } else if (MathAPI::RandomIntRange(1, 0x14) & 1) {
                blk[1] = 0xC2B60000;
                m_unk268 = 1;
            } else {
                blk[1] = 0x42B60000;
                m_unk268 = 2;
            }
            m_unk270 = (int)Find__6PMNodeFUi(m_unk3C, 0xE1612999U);
            blk[0] = 0;
            blk[2] = 0;
            *(u_long128 *)((char *)m_unk270 + 0x90) = *(u_long128 *)blk;
            ((PMNodeView *)m_unk270)->m_unk3E |= 8;
            m_unk2F0 = (float)MathAPI::RandomIntRange(0x5A, 0x6E);
        }
        PlaySoundOnFrame(0x173U, 8U);
        PlaySoundOnFrame(0x174U, 0xEU);
        PlaySoundOnFrame(0x173U, 0x16U);
        PlaySoundOnFrame(0x174U, 0x1DU);
        PlaySoundOnFrame(0x173U, 0x25U);
        PlaySoundOnFrame(0x174U, 0x2CU);
        {
            MathAPI *player = mPlayerAPI__13EntityManager;
            char *s0 = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
            m_unk290 = *(float *)s0;
        }
        {
            MathAPI *player = mPlayerAPI__13EntityManager;
            char *s1 = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
            m_unk294 = *(float *)(s1 + 4);
        }
        {
            MathAPI *player = mPlayerAPI__13EntityManager;
            char *s2 = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
            m_unk298 = *(float *)(s2 + 8);
        }
        {
            char *s3 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            m_unk294 = *(float *)(s3 + 4);
        }
        CircleAround(&m_unk290, m_unk2F0);
        if (m_unk280 == 0) {
            m_unk270 = (int)Find__6PMNodeFUi(m_unk3C, 0xE1612999U);
            ((PMNodeView *)m_unk270)->m_unk94 = m_unk274;
            ((PMNodeView *)m_unk270)->m_unk3E |= 8;
            FacePlayer__15EntityBaseClassFf(this, 0.15f);
            SetState__15EntityBaseClassFi(this, 0xD);
        }
        if (init == 0) {
            astallcountcount = 0xF;
            init = 1;
        }
        if (astallcountcount < m_unk230) {
            m_unk230 = 0;
            if (*(int *)(m_unk38 + 0xE4) != 0) {
                m_unk270 = (int)Find__6PMNodeFUi(m_unk3C, 0xE1612999U);
                ((PMNodeView *)m_unk270)->m_unk94 = m_unk274;
                ((PMNodeView *)m_unk270)->m_unk3E |= 8;
                if (m_unk268 == 2) {
                    m_unk26C = 3;
                } else {
                    m_unk26C = 4;
                }
                FacePlayer__15EntityBaseClassFf(this, 0.15f);
                SetState__15EntityBaseClassFi(this, 0xD);
            }
        }
        m_unk230 += 1;
        if (((signed char)(m_unk3C[0x3F] & 7) & 4) != 0) {
            if (CanAttackPlayer() != 0) {
                m_unk270 = (int)Find__6PMNodeFUi(m_unk3C, 0xE1612999U);
                ((PMNodeView *)m_unk270)->m_unk94 = m_unk274;
                ((PMNodeView *)m_unk270)->m_unk3E |= 8;
                SetState__15EntityBaseClassFi(this, 0);
            }
            {
                char *a1 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                MathAPI *player = mPlayerAPI__13EntityManager;
                char *a0 = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
                if (!(Distance__7MathAPIFPA4_fPA4_f(a0, (float (*)[4])a1) <= 20.0f)) {
                    char *b0 = (mPlayerAPI__13EntityManager->m_unk3C != 0) ? mPlayerAPI__13EntityManager->m_unk3C + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190;
                    if (Distance__7MathAPIFPA4_fPA4_f(b0, (float (*)[4])&m_unk200) <= *(float *)&m_unk1D4) {
                        m_unk270 = (int)Find__6PMNodeFUi(m_unk3C, 0xE1612999U);
                        ((PMNodeView *)m_unk270)->m_unk94 = m_unk274;
                        ((PMNodeView *)m_unk270)->m_unk3E |= 8;
                        {
                            MathAPI *player2 = mPlayerAPI__13EntityManager;
                            char *c0 = (player2->m_unk3C != 0) ? player2->m_unk3C + 0x80 : (char *)player2 + 0x190;
                            m_unk2C0 = *(float *)c0;
                        }
                        {
                            char *c1 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                            m_unk2C4 = (float)*(int *)(c1 + 4);
                        }
                        m_unk264 = MathAPI::RandomIntRange(1, 2);
                        SetState__15EntityBaseClassFi(this, 0x22);
                    }
                }
            }
            if (m_unk2A0 == 0) {
                m_unk2A0 = 1;
                m_unk2AC = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 0x2D, true);
                LoadCorrectMesh(true);
            }
        }
        goto block_541;
    }
    case 25: {
        if (m_unkE9 != 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            ClockworkShadowShell *shadow = (ClockworkShadowShell *)m_unkD4;
            if (shadow != 0) {
                shadow->unk0 = 1;
                if (shadow->unkC != 0) {
                    ((ClockworkShadowShell *)shadow->unkC)->unk18 = 1;
                }
            }
            EnableSleep__15EntityBaseClassFbb(this, 1, 0);
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_IdleSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_IdleSeq;
            if (m_unk2DC != 0 && InstanceIsValid__15EntityBaseClassFUi(m_unk2DC) != 0) {
                SetState__15EntityBaseClassFi(this, 5);
                return;
            }
            goto block_231;
        }
block_231:
        FacePlayer__15EntityBaseClassFf(this, 0.15f);
        {
            MathAPI *player = mPlayerAPI__13EntityManager;
            char *side = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
            if (Distance__7MathAPIFPA4_fPA4_f(side, (float (*)[4])&m_unk200) < *(float *)&m_unk1D4) {
                SetState__15EntityBaseClassFi(this, 0xD);
            }
        }
        goto block_541;
    }
    case 27:
        if (m_unkE9 != 0) {
            m_unk270 = (int)Find__6PMNodeFUi(m_unk3C, 0xE1612999U);
            temp_v1_11 = (PMNodeView *)m_unk270;
            *(int *)((char *)temp_v1_11 + 0x94) = m_unk274;
            temp_v1_11->m_unk3E |= 8;
            PlaySound__15EntityBaseClassFUi(this, 0x16AU);
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_DodgeSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_DodgeSeq;
            *(int *)(m_unk38 + 0xEC) = 0x80113FD5;
            m_unk10C &= 0xFDFFFFFF;
            DeleteEffects();
            m_unk2EC += 1;
        }
        FacePlayer__15EntityBaseClassFf(this, 0.15f);
        if (!(GetFrameTime__6PMNodeFv(m_unk3C) < 9.0f)) {
            m_unk10C |= 0x02000000;
        }
        if (*(int *)((char *)this + 0x160) == 0) {
            SetState__15EntityBaseClassFi(this, 0);
        }
        goto block_541;
    case 0: {
        if (m_unkE9 != 0) {
            int temp_v1_12 = m_unk2A0;
            if (temp_v1_12 != 2) {
                if (temp_v1_12 == 1) {
                    goto block_245;
                }
            } else {
block_245:
                m_unk2A0 = 3;
                m_unk2AC = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 0x2D, true);
                LoadCorrectMesh(true);
            }
            MathAPI *player = mPlayerAPI__13EntityManager;
            char *playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
            char *ownSide = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            float dist = Distance__7MathAPIFPA4_fPA4_f(ownSide, (float (*)[4])playerSide);
            if (!(dist <= 15.0f)) {
                char *farSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
                m_unk2C0 = *(float *)farSide;
                char *ownFar = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                m_unk2C4 = (float)*(int *)(ownFar + 4);
                SetState__15EntityBaseClassFi(this, 0x20);
                return;
            }
            if ((dist < 7.0f) || (m_unk140 == (unsigned int *)ClockworkStalker_DodgeSeq)) {
                if (MathAPI::RandomIntRange(1, 100) < 0x19) {
                    PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_ComboAttackSeq);
                    m_unk2E4 = (unsigned int *)ClockworkStalker_ComboAttackSeq;
                    m_unk2E0 = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x010001BA, 0x0200035E, 0, 0, 0, 0.5f, false, 0, false);
                    m_unk27C = 0;
                    goto block_264;
                }
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_LowSweepSeq);
                m_unk2E4 = (unsigned int *)ClockworkStalker_LowSweepSeq;
                m_unk2E0 = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x010000FD, 0x0200021F, 0, 0, 0, 0.5f, false, 0, false);
            } else {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_ComboAttackSeq);
                m_unk2E4 = (unsigned int *)ClockworkStalker_ComboAttackSeq;
                m_unk2E0 = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(&mEffectAPI__13EntityManager, 0x010001BA, 0x0200035E, 0, 0, 0, 0.5f, false, 0, false);
                m_unk27C = 0;
block_264:
                m_unk278 = 1;
            }
            FacePlayer__15EntityBaseClassFf(this, 0.15f);
            goto block_266;
        }
block_266:
        if (m_unk140 == (unsigned int *)ClockworkStalker_ComboAttackSeq) {
            PlaySoundOnFrame(0x168U, 0x1CU);
            PlaySoundOnFrame(0x168U, 0x23U);
            PlaySoundOnFrame(0x168U, 0x2CU);
            PlaySoundOnFrame(0x168U, 0x33U);
            PlaySoundOnFrame(0x168U, 0x41U);
            switch (m_unk27C) {
            case 0:
                if ((m_unk278 != 0) && !(GetFrameTime__6PMNodeFv(m_unk3C) < 35.0f)) {
                    m_unk278 = 0;
                    ResetCollisions__15EntityBaseClassFv(this);
                }
                if (!(GetFrameTime__6PMNodeFv(m_unk3C) < 38.0f)) {
                    m_unk27C += 1;
                    m_unk278 = 1;
                }
                break;
            case 1:
                if ((m_unk278 != 0) && !(GetFrameTime__6PMNodeFv(m_unk3C) < 44.0f)) {
                    m_unk278 = 0;
                    ResetCollisions__15EntityBaseClassFv(this);
                    FacePlayer__15EntityBaseClassFf(this, 0.15f);
                }
                if (!(GetFrameTime__6PMNodeFv(m_unk3C) < 47.0f)) {
                    m_unk27C += 1;
                    m_unk278 = 1;
                }
                break;
            case 2:
                if ((m_unk278 != 0) && !(GetFrameTime__6PMNodeFv(m_unk3C) < 51.0f)) {
                    m_unk278 = 0;
                    ResetCollisions__15EntityBaseClassFv(this);
                }
                if (!(GetFrameTime__6PMNodeFv(m_unk3C) < 54.0f)) {
                    m_unk27C += 1;
                    m_unk278 = 1;
                }
                break;
            case 3:
                if ((m_unk278 != 0) && !(GetFrameTime__6PMNodeFv(m_unk3C) < 65.0f)) {
                    m_unk27C += 1;
                    m_unk278 = 0;
                    ResetCollisions__15EntityBaseClassFv(this);
                }
                if (!(GetFrameTime__6PMNodeFv(m_unk3C) < 69.0f)) {
                    m_unk27C += 1;
                    m_unk278 = 1;
                }
                break;
            }
        } else {
            PlaySoundOnFrame(0x168U, 0x11U);
        }
        if (*(int *)((char *)this + 0x160) == 0) {
            MathAPI *player2 = mPlayerAPI__13EntityManager;
            char *playerSide2 = (player2->m_unk3C != 0) ? player2->m_unk3C + 0x80 : (char *)player2 + 0x190;
            char *ownSide2 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            if (!(Distance__7MathAPIFPA4_fPA4_f(ownSide2, (float (*)[4])playerSide2) <= 13.0f)) {
                SetState__15EntityBaseClassFi(this, 0xD);
            } else {
                miRandom__7MathAPI = miRandom__7MathAPI * 0x343FD + 0x269EC3;
                if (miRandom__7MathAPI & 1) {
                    if (PlayerFacingUs() != 0) {
                        if (m_unk2EC <= 0) {
                            SetState__15EntityBaseClassFi(this, 0x1F);
                        } else {
                            goto block_305;
                        }
                    } else {
block_305:
                        m_unk2EC = 1;
                        SetState__15EntityBaseClassFi(this, 0x1A);
                    }
                } else {
                    SetState__15EntityBaseClassFi(this, 0xD);
                }
            }
        }
        goto block_541;
    }
    case 32: {
        float spA0[4];
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_DashShortSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_DashShortSeq;
            char *ownSide = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            *(u_long128 *)m_unk240 = *(u_long128 *)ownSide;
            MathAPI *inst = (MathAPI *)InstanceIsValid__15EntityBaseClassFUi(m_unk2DC);
            if (inst != 0) {
                char *instSide = (inst->m_unk3C != 0) ? inst->m_unk3C + 0x80 : (char *)inst + 0x190;
                m_unk2C0 = *(float *)instSide;
            }
            *(u_long128 *)spA0 = *(u_long128 *)&m_unk2C0;
            spA0[1] += 10.0f;
            if (GetGroundPos__7MathAPIFPA4_f(spA0) == 0) {
                SetState__15EntityBaseClassFi(this, 0xD);
                return;
            }
            RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])&m_unk2C0), 0.15f);
            goto block_319;
        }
block_319:
        PlaySoundOnFrame(0x2ACU, 0x10U);
        PlaySoundOnFrame(0x2A5U, 0x1EU);
        MathAPI *player = mPlayerAPI__13EntityManager;
        char *playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
        char *ownSide2 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
        float dist = Distance__7MathAPIFPA4_fPA4_f(ownSide2, (float (*)[4])playerSide);
        char *ownSide3 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
        if (Distance__7MathAPIFPA4_fPA4_f((char *)&m_unk2C0, (float (*)[4])ownSide3) < 7.0f) {
            if (init == 0) {
                aStopDashDst = 0x41500000;
                init = 1;
            }
            MathAPI *inst2 = (MathAPI *)InstanceIsValid__15EntityBaseClassFUi(m_unk2DC);
            if (inst2 != 0) {
                char *ownSide4 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                char *instSide2 = (inst2->m_unk3C != 0) ? inst2->m_unk3C + 0x80 : (char *)inst2 + 0x190;
                dist = Distance__7MathAPIFPA4_fPA4_f(ownSide4, (float (*)[4])instSide2);
                if (!(dist <= 7.0f)) {
                    *(u_long128 *)&m_unk2C0 = *(u_long128 *)instSide2;
                    SetState__15EntityBaseClassFi(this, 0x20);
                } else {
                    SetState__15EntityBaseClassFi(this, 6);
                }
            } else if (!(dist <= 7.0f)) {
                SetState__15EntityBaseClassFi(this, 0xD);
            } else {
                SetState__15EntityBaseClassFi(this, 0);
            }
        }
        if (((signed char)(m_unk3C[0x3F] & 7) & 4) != 0) {
            if (dist < 10.0f) {
                if (!(dist <= 7.0f)) {
                    SetState__15EntityBaseClassFi(this, 0xD);
                } else {
                    SetState__15EntityBaseClassFi(this, 0);
                }
            }
            if (*(int *)(m_unk38 + 0xE4) != 0) {
                FacePlayer__15EntityBaseClassFf(this, 0.15f);
                SetState__15EntityBaseClassFi(this, 0xD);
                return;
            }
            if (IsStalled(1.0f, (float (*)[4])m_unk240) != 0) {
                FacePlayer__15EntityBaseClassFf(this, 0.15f);
                SetState__15EntityBaseClassFi(this, 0xD);
                return;
            }
            char *side = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            *(u_long128 *)m_unk240 = *(u_long128 *)side;
            goto block_541;
        }
        goto block_541;
    }
    case 34: {
        float spB0[4];
        if (m_unkE9 != 0) {
            *(u_long128 *)spB0 = *(u_long128 *)&m_unk2C0;
            spB0[1] += 10.0f;
            if (GetGroundPos__7MathAPIFPA4_f(spB0) == 0) {
                SetState__15EntityBaseClassFi(this, 0xD);
                return;
            }
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_DashShortLoopSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_DashShortLoopSeq;
            *(int *)(m_unk240 + 0x20) = 0;
            goto block_360;
        }
block_360:
        PlaySoundOnFrame(0x2ACU, 0x10U);
        PlaySoundOnFrame(0x2A5U, 0x1EU);
        RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])&m_unk2C0), 0.15f);
        if (*(int *)(m_unk240 + 0x20) < m_unk264) {
            char *ownSide = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            if (Distance__7MathAPIFPA4_fPA4_f(ownSide, (float (*)[4])&m_unk2C0) < 5.0f) {
                goto block_365;
            }
            if (*(unsigned char *)((char *)this + 0x160) == 0) {
                MathAPI *player = mPlayerAPI__13EntityManager;
                char *playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
                char *ownSide2 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                if (Distance__7MathAPIFPA4_fPA4_f(ownSide2, (float (*)[4])playerSide) < 10.0f) {
                    SetState__15EntityBaseClassFi(this, 0xD);
                    return;
                }
                *(int *)(m_unk240 + 0x20) += 1;
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_DashShortLoopSeq);
                m_unk2E4 = (unsigned int *)ClockworkStalker_DashShortLoopSeq;
                goto block_541;
            }
            goto block_541;
        }
block_365:
        SetState__15EntityBaseClassFi(this, 0xD);
        return;
    }
    case 31: {
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_DashBackSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_DashBackSeq;
            FacePlayer__15EntityBaseClassFf(this, 0.15f);
            char *side = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            *(u_long128 *)m_unk240 = *(u_long128 *)side;
        }
        int t = m_unk2EC;
        if (t <= 0 && *(int *)(m_unk38 + 0xE4) != 0) {
            m_unk2EC = t + 1;
        }
        if (*(unsigned char *)((char *)this + 0x160) == 0) {
            if (IsStalled(1.0f, (float (*)[4])m_unk240) != 0) {
                m_unk2EC += 1;
            }
            m_unk2EC += 1;
            if (CanAttackPlayer() != 0) {
                SetState__15EntityBaseClassFi(this, 0);
            } else {
                SetState__15EntityBaseClassFi(this, 0xD);
            }
        }
        goto block_541;
    }
    case 4: {
        unsigned int *var_v1_6;
        if (m_unkE9 != 0) {
            *(int *)(m_unk38 + 0xEC) = 0x80113F55U;
            MathAPI *player = mPlayerAPI__13EntityManager;
            char *playerSide = (player->m_unk3C != 0) ? player->m_unk3C + 0x80 : (char *)player + 0x190;
            char *dst = (m_unk3C != 0) ? m_unk3C + 0x90 : m_unk1A0;
            *(float *)(dst + 4) = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])playerSide);
            switch (m_unk21C) {
            case 0x8F: case 0x108: case 0x48: case 0xF:
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_LaunchSeq);
                m_unk2E4 = (unsigned int *)ClockworkStalker_LaunchSeq;
                SetState__15EntityBaseClassFi(this, 0x14);
                return;
            case 0x25: case 0x0:
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_HitRightSeq);
                var_v1_6 = (unsigned int *)ClockworkStalker_HitRightSeq;
            block_419:
                m_unk2E4 = var_v1_6;
                goto block_420;
            case 0x5: case 0x4:
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_HitLeftSeq);
                var_v1_6 = (unsigned int *)ClockworkStalker_HitLeftSeq;
                goto block_419;
            case 0xC:
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_KnockBackSeq);
                var_v1_6 = (unsigned int *)ClockworkStalker_KnockBackSeq;
                goto block_419;
            case 0x2D:
                if (MathAPI::RandomIntRange(1, 0x64) < 0x15) {
                    m_unk22C = m_unk21C;
                    SetState__15EntityBaseClassFi(this, 0xC);
                    return;
                }
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_HitSeq);
                var_v1_6 = (unsigned int *)ClockworkStalker_HitSeq;
                goto block_419;
            case 0x8:
                if (MathAPI::RandomIntRange(1, 0x64) < 0x15) {
                    m_unk22C = m_unk21C;
                    SetState__15EntityBaseClassFi(this, 0xC);
                    return;
                }
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_KnockUp1Seq);
                var_v1_6 = (unsigned int *)ClockworkStalker_KnockUp1Seq;
                goto block_419;
            default:
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_HitSeq);
                var_v1_6 = (unsigned int *)ClockworkStalker_HitSeq;
                goto block_419;
            }
        } else {
        block_420:
            if (*(unsigned char *)((char *)this + 0x160) == 0) SetState__15EntityBaseClassFi(this, 0xD);
            goto block_541;
        }
        break;
    }
    case 20:
        FacePlayer__15EntityBaseClassFf(this, 0.15f);
        if (*(unsigned char *)((char *)this + 0x160) == 0) {
            SetState__15EntityBaseClassFi(this, 0xD);
        }
        goto block_541;
    case 21: {
        unsigned int *var_v0_22;
        if (m_unkE9 != 0) {
            if (m_unk2D4 != 0) {
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_JuggleInAirSeq);
                var_v0_22 = (unsigned int *)ClockworkStalker_JuggleInAirSeq;
            } else {
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_JuggleSeq);
                var_v0_22 = (unsigned int *)ClockworkStalker_JuggleSeq;
            }
            m_unk2E4 = var_v0_22;
        }
        FacePlayer__15EntityBaseClassFf(this, 0.15f);
        if (*(unsigned char *)((char *)this + 0x160) == 0) {
            SetState__15EntityBaseClassFi(this, 0x17);
        }
        goto block_541;
    }
    case 12:
        if (m_unkE9 != 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            switch (m_unk22C) {
            case 8:
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_KnockUp2Seq);
                m_unk2E4 = (unsigned int *)ClockworkStalker_KnockUp2Seq;
                break;
            case 32:
            case 45:
                PlaySound__15EntityBaseClassFUi(this, 0x4E3CU);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_KnockDownSeq);
                m_unk2E4 = (unsigned int *)ClockworkStalker_KnockDownSeq;
                break;
            default:
                CdsAssert(lit_0026C030, 0x609, lit_0026C160);
                break;
            }
        }
        if (*(unsigned char *)((char *)this + 0x160) == 0) {
            SetState__15EntityBaseClassFi(this, 0x17);
            return;
        }
        goto block_541;
    case 23:
        if (m_unkE9 != 0) {
            *(int *)(m_unk38 + 0xEC) = 0x80113FD5;
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_GetUpSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_GetUpSeq;
        }
        FacePlayer__15EntityBaseClassFf(this, 0.15f);
        if (*(unsigned char *)((char *)this + 0x160) == 0) {
            SetState__15EntityBaseClassFi(this, 0xD);
        }
        goto block_541;
    case 5: {
        if (m_unkE9 != 0) {
            MathAPI *inst = (MathAPI *)InstanceIsValid__15EntityBaseClassFUi(m_unk2DC);
            if (inst != 0) {
                char *instSide = (inst->m_unk3C != 0) ? inst->m_unk3C + 0x80 : (char *)inst + 0x190;
                m_unk2C0 = *(float *)instSide;
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_DashShortSeq);
            }
        }
        PlaySoundOnFrame(0x2ACU, 0x10U);
        PlaySoundOnFrame(0x2A5U, 0x1EU);
        MathAPI *inst3 = (MathAPI *)InstanceIsValid__15EntityBaseClassFUi(m_unk2DC);
        if ((inst3 != 0 && ((int (*)(MathAPI *))(*(void ***)inst3)[15])(inst3) == 0) || inst3 == 0) {
            char *src = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            *(u_long128 *)m_unk200 = *(u_long128 *)src;
            m_unk2DC = 0;
            SetState__15EntityBaseClassFi(this, 0xD);
            return;
        }
        char *tgtA = (inst3->m_unk3C != 0) ? inst3->m_unk3C + 0x80 : (char *)inst3 + 0x190;
        RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])tgtA), 0.15f);
        char *ownA = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
        if (Distance__7MathAPIFPA4_fPA4_f(ownA, (float (*)[4])tgtA) <= 7.0f) {
            SetState__15EntityBaseClassFi(this, 6);
            return;
        }
        char *ownB = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
        if (Distance__7MathAPIFPA4_fPA4_f(ownB, (float (*)[4])&m_unk2C0) < 3.0f) {
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_DashShortSeq);
            char *tgtB = (inst3->m_unk3C != 0) ? inst3->m_unk3C + 0x80 : (char *)inst3 + 0x190;
            m_unk2C0 = *(float *)tgtB;
        }
        if (m_unk3C[0x3F] & 4) {
            if (IsStalled(1.0f, (float (*)[4])m_unk240) != 0) {
                FacePlayer__15EntityBaseClassFf(this, 0.15f);
                SetState__15EntityBaseClassFi(this, 0xD);
                return;
            }
            char *tgtC = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            *(u_long128 *)m_unk240 = *(u_long128 *)tgtC;
            goto block_541;
        }
        goto block_541;
    }
    case 6: {
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_LowSweepSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_LowSweepSeq;
        }
        MathAPI *inst6 = (MathAPI *)InstanceIsValid__15EntityBaseClassFUi(m_unk2DC);
        if (inst6 == 0) {
            m_unk2DC = 0;
            SetState__15EntityBaseClassFi(this, 0x19);
            return;
        }
        char *tgt6 = (inst6->m_unk3C != 0) ? inst6->m_unk3C + 0x80 : (char *)inst6 + 0x190;
        RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])tgt6), 0.04f);
        if (*(unsigned char *)((char *)this + 0x160) == 0) {
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_IdleSeq);
            m_unk2E4 = (unsigned int *)ClockworkStalker_IdleSeq;
            SetState__15EntityBaseClassFi(this, 7);
        }
        goto block_541;
    }
    case 7: {
        if (m_unkE9 != 0) {
            mTimerAPI__13EntityManager.KillTimer(m_unk2D8);
            m_unk2D5 = 0;
            m_unk2D8 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 1U, false);
        }
        MathAPI *ent7 = (MathAPI *)InstanceIsValid__15EntityBaseClassFUi(m_unk2DC);
        if (ent7 != 0) {
            if (((int (*)(MathAPI *))(*(void ***)ent7)[15])(ent7) == 0) {
                char *src7 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
                *(u_long128 *)m_unk200 = *(u_long128 *)src7;
                m_unk2DC = 0;
                SetState__15EntityBaseClassFi(this, 0x19);
                return;
            }
            char *tgt7 = (ent7->m_unk3C != 0) ? ent7->m_unk3C + 0x80 : (char *)ent7 + 0x190;
            RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])tgt7), 0.04f);
            if (m_unk2D5 != 0) {
                SetState__15EntityBaseClassFi(this, 6);
            }
            char *tgt7b = (ent7->m_unk3C != 0) ? ent7->m_unk3C + 0x80 : (char *)ent7 + 0x190;
            char *own7 = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
            if (!(Distance__7MathAPIFPA4_fPA4_f(own7, (float (*)[4])tgt7b) <= 7.0f)) {
                SetState__15EntityBaseClassFi(this, 5);
            }
            goto block_541;
        }
        char *src7b = (m_unk3C != 0) ? m_unk3C + 0x80 : &m_unk190;
        *(u_long128 *)m_unk200 = *(u_long128 *)src7b;
        SetState__15EntityBaseClassFi(this, 0x19);
        return;
    }
    case 9:
    {
        if (m_unkE9 != 0) {
            float spC0[4];
            *(int *)(m_unk3C + 0x18) = 0;
            char *var_v0_27 = 0;
            if (*(int *)(m_unk3C + 0x14) != 0) {
                var_v0_27 = *(char **)(m_unk3C + 0x1C);
            }
            *(u_long128 *)spC0 = *(u_long128 *)(var_v0_27 + 0x70);
            spC0[1] -= 5.0f;
            m_unk10C &= 0xF8FFFFFF;
            ClockworkShadowShell *shadow = (ClockworkShadowShell *)m_unkD4;
            if (shadow != 0) {
                shadow->unk0 = 0;
                if (shadow->unkC != 0) ((ClockworkShadowShell *)shadow->unkC)->unk18 = 0;
            }
            KillTimers();
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            EnableSleep__15EntityBaseClassFbb(this, 0, 0);
            WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
            switch (m_unk218) {
            case 0x220: case 0x201: case 0x20: case 0x8:
                PlaySound__15EntityBaseClassFUi(this, 0x169U);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_VerticalDeathSeq);
                break;
            case 0x2:
                PlaySound__15EntityBaseClassFUi(this, 0x169U);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_StabDownDeathSeq);
                break;
            default:
                PlaySound__15EntityBaseClassFUi(this, 0x169U);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_DeadSeq);
                break;
            }
            *(u_long128 *)(m_unk3C + 0x80) = *(u_long128 *)spC0;
            *(unsigned char *)(m_unk3C + 0x3E) |= 8;
            SpawnBonus__15EntityBaseClassFPfii(this, (float *)m_vBonusSpawnOffset, 3, 3);
        }
        if (*(unsigned char *)((char *)this + 0x160) == 0) SetState__15EntityBaseClassFi(this, -2);
        goto block_541;
    }
    case 24:
    {
        if (m_unkE9 != 0) {
            m_unk10C &= 0xF8FFFFFF;
            KillTimers();
            WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
            PlaySound__15EntityBaseClassFUi(this, 0x169U);
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkStalker_StabDownDeathSeq);
            SpawnBonus__15EntityBaseClassFPfii(this, (float *)m_vBonusSpawnOffset, 3, 3);
        }
        if (*(unsigned char *)((char *)this + 0x160) == 0) SetState__15EntityBaseClassFi(this, -2);
        goto block_541;
    }
    default:
    block_541:
        temp_a0 = m_unk3C;
        if (temp_a0 != 0) {
            temp_v0_8 = Find__6PMNodeFUi(temp_a0, 0xE7F78F41U);
            if (temp_v0_8 != 0 && m_unk2A0 == 1) {
                temp_f12 = *(float *)&m_unk2A4 - 0.017777778f;
                *(float *)&m_unk2A4 = temp_f12;
                SetAllFade__6PMNodeFf(temp_v0_8, temp_f12);
            }
        }
        if (m_unk20 >= 0) {
            CheckBlockAttack();
        }
        return;
    }
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
