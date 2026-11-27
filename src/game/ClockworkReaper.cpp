// FLAGS: -str readonly
#include "ClockworkReaper.h"
#include "types.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    void SequenceViewer(unsigned int **arg0, int arg1);
    char _pad000[8];
    int m_unk8;
    char _pad00C[0x1C - 0xC];
    int m_unk1C;
    char _pad020[0x3C - 0x20];
    void *m_unk3C;
    char _pad040[0x10C - 0x40];
    unsigned int m_unk10C;
    char _pad110[0x163 - 0x110];
    unsigned char m_unk163;
    char _pad164[0x190 - 0x164];
    u_long128 m_unk190;
    u_long128 m_unk1A0;
};

extern unsigned int ClockworkReaper_ViewerIdleGruntSeq[];
extern unsigned int ClockworkReaper_Idle1Seq[];
extern unsigned int ClockworkReaper_Idle2Seq[];
extern unsigned int ClockworkReaper_RunSeq[];
extern unsigned int ClockworkReaper_HitBySingleSlashSeq[];
extern unsigned int ClockworkReaper_HitByDoubleSlashSeq[];
extern unsigned int ClockworkReaper_AssembleSeq[];
extern unsigned int ClockworkReaper_UpwardStrikeSeq[];
extern unsigned int ClockworkReaper_GetBackUpSeq[];
extern unsigned int ClockworkReaper_KnockBackSeq[];
extern unsigned int ClockworkReaper_KnockDownSeq[];
extern unsigned int ClockworkReaper_OverheadHitSeq[];
extern unsigned int ClockworkReaper_LaunchSeq[];
extern unsigned int ClockworkReaper_JuggleSeq[];
extern unsigned int ClockworkReaper_Taunt1Seq[];
extern unsigned int ClockworkReaper_Taunt2Seq[];
extern unsigned int ClockworkReaper_WalkBackwardsSeq[];
extern unsigned int ClockworkReaper_SideStepLeftSeq[];
extern unsigned int ClockworkReaper_SideStepRightSeq[];
extern unsigned int ClockworkReaper_WalkForwardsSeq[];
extern unsigned int ClockworkReaper_HitSeq[];
extern unsigned int ClockworkReaper_Hit2Seq[];
extern unsigned int ClockworkReaper_BlockSeq[];
extern unsigned int ClockworkReaper_BlockReactSeq[];
extern unsigned int ClockworkReaper_JuggleInAirSeq[];
extern unsigned int ClockworkReaper_JuggleInAir3rdHitSeq[];
extern unsigned int ClockworkReaper_AttackSeq[];
extern unsigned int ClockworkReaper_OverheadAttackSeq[];
extern unsigned int ClockworkReaper_ViewerIdleVeteranSeq[];
extern unsigned int ClockworkReaper_VeteranDoubleComboSeq[];
extern unsigned int ClockworkReaper_VeteranDashSeq[];
extern unsigned int ClockworkReaper_VeteranDodgeSeq[];

static unsigned int *SequenceTable[32] = {
    ClockworkReaper_ViewerIdleGruntSeq,
    ClockworkReaper_Idle1Seq,
    ClockworkReaper_Idle2Seq,
    ClockworkReaper_RunSeq,
    ClockworkReaper_HitBySingleSlashSeq,
    ClockworkReaper_HitByDoubleSlashSeq,
    ClockworkReaper_AssembleSeq,
    ClockworkReaper_UpwardStrikeSeq,
    ClockworkReaper_GetBackUpSeq,
    ClockworkReaper_KnockBackSeq,
    ClockworkReaper_KnockDownSeq,
    ClockworkReaper_OverheadHitSeq,
    ClockworkReaper_LaunchSeq,
    ClockworkReaper_JuggleSeq,
    ClockworkReaper_Taunt1Seq,
    ClockworkReaper_Taunt2Seq,
    ClockworkReaper_WalkBackwardsSeq,
    ClockworkReaper_SideStepLeftSeq,
    ClockworkReaper_SideStepRightSeq,
    ClockworkReaper_WalkForwardsSeq,
    ClockworkReaper_HitSeq,
    ClockworkReaper_Hit2Seq,
    ClockworkReaper_BlockSeq,
    ClockworkReaper_BlockReactSeq,
    ClockworkReaper_JuggleInAirSeq,
    ClockworkReaper_JuggleInAir3rdHitSeq,
    ClockworkReaper_AttackSeq,
    ClockworkReaper_OverheadAttackSeq,
    ClockworkReaper_ViewerIdleVeteranSeq,
    ClockworkReaper_VeteranDoubleComboSeq,
    ClockworkReaper_VeteranDashSeq,
    ClockworkReaper_VeteranDodgeSeq,
};

class MathAPI {
public:
    char _pad000[0x3C];
    char *m_unk3C;
    char _pad040[0x154 - 0x40];
    int m_unk154;
    char _pad158[0x15E - 0x158];
    unsigned short m_unk15E;
    char _pad160[0x1CC - 0x160];
    int m_unk1CC;
    char _pad1D0[0x23D2 - 0x1D0];
    unsigned char m_unk23D2;
};

extern "C" float Distance__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
extern MathAPI *mPlayerAPI__13EntityManager;

class EffectAPI {
public:
    char _pad000[20];
    void DeleteEffect(unsigned int);
    int CreateOneshot(unsigned int, unsigned int, float (*)[4], float (*)[4], EntityBaseClass *, float, bool, int, bool);
};

extern EffectAPI mEffectAPI__13EntityManager;
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void RemoveFromAttackSystem__15EntityBaseClassFv(void *);
extern "C" int CreateDamageFx__15EntityBaseClassFfUi(void *, float, unsigned int);
extern "C" void ChangeDamageFxInterval__15EntityBaseClassFUif(void *, unsigned int, float);
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern unsigned int ClockworkReaper_JoltOnGround[];
extern void *mpEntMgr__15EntityBaseClass;
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *, float *);
extern "C" float Round180__Ff(float);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" int RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(void *, void *, unsigned int);
class TimerAPI {
public:
    char _pad000[40];
    void KillTimer(unsigned int);
    unsigned int CreateTimer(unsigned int, unsigned int, bool);
};
extern TimerAPI mTimerAPI__13EntityManager;
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__15ClockworkReaper[];

extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" long long fptodp(float arg0);
extern "C" void *memcpy(void *, const void *, unsigned int);
void CdsAssert(char *, int, char *);
// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("ClockworkReaper.cpp", line, #cond))

class Debug {
public:
    void DebugDisp(char *pText);

    // Debug size is unknown; the placeholder keeps gDebug out of small data (threshold 8 bytes).
    char _pad000[0x10];
};
extern Debug gDebug;

struct tagParticleFxTrigger {
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1C;
    unsigned int m_unk20;
    unsigned int m_unk24;
};

class PMNode {
public:
    char _pad000[4];
    int m_unk04;
    char _pad008[4];
    int m_unk0C;
    void *m_unk10;
    char _pad014[0x3E - 0x14];
    unsigned char m_unk3E;
    signed char m_unk3F;
};
extern "C" float GetFrameTime__6PMNodeFv(PMNode *);
extern "C" void AddFxTrigger__6PMNodeFP20tagParticleFxTriggerb(PMNode *, tagParticleFxTrigger *, bool);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern "C" PMNode *Find__6PMNodeFUi(PMNode *, unsigned int);
extern "C" PMNode *GetResource__16PResourceManagerFUib(void *, unsigned int, bool);
extern "C" void BuildDispList__9PSkeletonFv(void *);
extern void *mpResMgr__15EntityBaseClass;
extern "C" int RandomIntRange__7MathAPIFii(int, int);
class Shadow {
public:
    signed char m_unk0;
    char _pad001[0x0C - 0x01];
    void *m_unkC;
};
extern "C" void *__nw__FUi(unsigned int);
extern "C" Shadow *__ct__6ShadowFQ26Shadow10ShadowTypeUi(Shadow *, int, unsigned int);
extern "C" void PlaySequence__15EntityBaseClassFPUi(EntityBaseClass *, unsigned int *);
extern unsigned int ClockworkReaper_InitGruntSeq[4];
extern unsigned int ClockworkReaper_InitVeteranSeq[4];
extern unsigned int ClockworkReaper_InitEliteSeq[4];

// TODO(header): foreign declarations for Execute
class Physics {
public:
    u_long128 m_unk0;
    char _pad010[0xCC - 0x10];
    char *m_unkCC;
    char _pad0D0[0xEC - 0xD0];
    int m_unkEC;
    char _pad0F0[0x108 - 0xF0];
    int m_unk108;
    float m_unk10C;
    float m_unk110;
    char _pad114[0x118 - 0x114];
    int m_unk118;
    char _pad11C[0x120 - 0x11C];
    Physics();
};
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(Physics *, unsigned int, float (*)[4]);
extern "C" void GetGroundPos__7PhysicsFv(float *);
extern "C" int GetGroundPos__7MathAPIFPA4_f(float *);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, float *);
extern "C" float RandomFloatRange__7MathAPIFff(float, float);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void sceVu0AddVector(float *, float *, float *);
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" void sceVu0Normalize(float *, float *);
extern "C" float cosf(float);
extern "C" float sinf(float);
extern "C" int printf(const char *, ...);
extern "C" void StopSoundBySoundRef__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void PlaySoundOnFrame__15EntityBaseClassFUiUi(void *, unsigned int, unsigned int);
extern "C" void FacePlayer__15EntityBaseClassFf(void *, float);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern "C" void TriggerBGAnim__15EntityBaseClassFUiibUi(void *, unsigned int, int, bool, unsigned int);
extern "C" void PlaySound__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern "C" void SpawnBonus__15EntityBaseClassFPfii(void *, float *, int, int);
extern "C" void SetRenderPass__15EntityBaseClassFi(void *, int);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *, int, char, unsigned int);
extern "C" void ResetCollisions__15EntityBaseClassFv(void *);
extern "C" EntityBaseClass *InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *, unsigned int);
class ZinShell {
public:
    char _pad000[4];
    unsigned int m_unk4;
    char _pad008[0x3C - 0x8];
    PMNode *m_unk3C;
    char _pad040[0x190 - 0x40];
    u_long128 m_unk190;
    u_long128 m_unk1A0;
    int m_unk1B0;
    int m_unk1B4;
    char _pad1B8[0x1C4 - 0x1B8];
    unsigned int m_unk1C4;
    char _pad1C8[0x1CC - 0x1C8];
    signed char m_unk1CC;
    char _pad1CD[0x224 - 0x1CD];
    unsigned int m_unk224;
    unsigned int m_unk228;
    signed char m_unk22C;
    unsigned char m_unk22D;
};
extern "C" ZinShell *Spawn__13EntityManagerFUibi(void *, unsigned int, bool, int);
extern "C" void SetShellStartAndDest__8ZinShellFRA4_fRA4_f(ZinShell *, float *, float *);
extern int fst_TestAmbientSounds;
extern float gUnitMatrix[16];
extern float m_vBonusSpawnOffset[4];
extern float m_vDefaultSpawnVelocity[4];
extern unsigned int ClockworkReaper_DeadSeq[];
extern unsigned int ClockworkReaper_DeathSplitSeq[];
extern unsigned int ClockworkReaper_EliteThrowSpearSeq[];
extern unsigned int ClockworkReaper_JumpAirSeq[];
extern unsigned int ClockworkReaper_JumpFromShellSeq[];
extern unsigned int ClockworkReaper_JumpLandSeq[];
extern unsigned int ClockworkReaper_JumpLaunchSeq[];
extern unsigned int ClockworkReaper_KnockDownSeq2[];
extern unsigned int ClockworkReaper_Taunt3Seq[];
extern unsigned int ClockworkReaper_StabDownDeathSeq[];
extern unsigned int ClockworkReaper_UpwardStrikeDeathSeq[];
extern unsigned int ClockworkReaper_VerticalDeath2Seq[];

static inline float *PosOf(void *pNode, void *pFallback) {
    return pNode ? (float *)((char *)pNode + 0x80) : (float *)pFallback;
}
static inline float *QuatOf(void *pNode, void *pFallback) {
    return pNode ? (float *)((char *)pNode + 0x90) : (float *)pFallback;
}
static inline void Copy128(void *pDst, void *pSrc) {
    *(u_long128 *)pDst = *(u_long128 *)pSrc;
}
static inline float *PlayerPos() {
    EntityBaseClass *p = (EntityBaseClass *)mPlayerAPI__13EntityManager;
    return PosOf(p->m_unk3C, &p->m_unk190);
}
static inline int EntVirt3C(EntityBaseClass *p) {
    return ((int (*)(EntityBaseClass *))(*(void ***)p)[0x3C / 4])(p);
}
static inline void Play(ClockworkReaper *p, unsigned int *pSeq) {
    PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)p, pSeq);
}
static inline void ClearShadow(Shadow *pShadow) {
    if (pShadow != 0) {
        pShadow->m_unk0 = 0;
        if (pShadow->m_unkC != 0) {
            *(int *)((char *)pShadow->m_unkC + 0x18) = 0;
        }
    }
}

// FUNCTION: 0x001BF7A0 GetHealth__15ClockworkReaperFv
int ClockworkReaper::GetHealth() {
    return m_unk208;
}

// FUNCTION: 0x001BF7B0 GetClassName__15ClockworkReaperFv
const char *ClockworkReaper::GetClassName() {
    return "ClockworkReaper";
}

// FUNCTION: 0x001BF7C0 GetTallyType__15ClockworkReaperFv
int ClockworkReaper::GetTallyType() {
    return 1;
}

// FUNCTION: 0x001BF7D0 GetArenaWaveID__15ClockworkReaperFv
int ClockworkReaper::GetArenaWaveID() {
    return m_unk1D8;
}

// FUNCTION: 0x001BF7E0 IsArenaApparition__15ClockworkReaperFv
bool ClockworkReaper::IsArenaApparition() {
    return m_unk1D8 ? true : false;
}

// FUNCTION: 0x001BF7F0 NeedsToBeWoken__15ClockworkReaperFv
int ClockworkReaper::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x1DC);
}

// FUNCTION: 0x001BF800 GetWokenVarPos__15ClockworkReaperFv
int ClockworkReaper::GetWokenVarPos() {
    return 5;
}

// FUNCTION: 0x001BF810 SetInnocentInstanceID__15ClockworkReaperFUi
void ClockworkReaper::SetInnocentInstanceID(unsigned int value) {
    *(unsigned int *)((char *)this + 0x304) = value;
}

// FUNCTION: 0x001BF820 SetRiseAndAttack__15ClockworkReaperFPA4_fff
void ClockworkReaper::SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2) {
    m_unk1B8[0] = arg0[0][0];
    m_unk1B8[1] = arg0[0][1];
    m_unk1B8[2] = arg0[0][2];
    m_unk1C8[0] = arg0[0][0];
    m_unk1C8[1] = arg0[0][1];
    m_unk1C8[2] = arg0[0][2];
    m_unk1C4 = arg1;
    m_unk1D4 = arg2;
}

// FUNCTION: 0x001BF860 AttachSoulStoneEffect__15ClockworkReaperFP6PMNode
void ClockworkReaper::AttachSoulStoneEffect(PMNode *arg0) {
    if (arg0 == 0) {
        return;
    }
    tagParticleFxTrigger trig;
    trig.m_unk00 = 0x8300014B;
    trig.m_unk04 = 0;
    trig.m_unk08 = 0x3E800000;
    trig.m_unk0C = 0;
    trig.m_unk10 = 0;
    trig.m_unk14 = 0;
    trig.m_unk18 = 0xBF800000;
    trig.m_unk1C = 0xBF800000;
    trig.m_unk20 = 0;
    trig.m_unk24 = 0;
    AddFxTrigger__6PMNodeFP20tagParticleFxTriggerb(arg0, &trig, 0);
    m_unk2E0 = 1;
}

// FUNCTION: 0x001BF8E0 AnimationViewer__15ClockworkReaperFi
int ClockworkReaper::AnimationViewer(int arg0) {
    ((EntityBaseClass *)this)->SequenceViewer(SequenceTable, arg0);
    return 0x20;
}

// FUNCTION: 0x001BF910 GetRenderPassIndex__15ClockworkReaperFv
int ClockworkReaper::GetRenderPassIndex() {
    switch (m_unk1B0) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return 0;
}

// FUNCTION: 0x001BF960 PlayerInAttackRadius__15ClockworkReaperFv
int ClockworkReaper::PlayerInAttackRadius() {
    MathAPI *player = mPlayerAPI__13EntityManager;
    char *target;
    float dist;
    if (player->m_unk3C != 0) {
        target = player->m_unk3C + 0x80;
    } else {
        target = (char *)player + 0x190;
    }
    dist = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)target, (float (*)[4])m_unk290);
    if (dist <= m_unk1D4) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001BF9C0 InBlockableState__15ClockworkReaperFv
int ClockworkReaper::InBlockableState() {
    if ((unsigned int)(m_unk20 - 0x15) <= 4U || m_unk20 == 4) {
        return 1;
    }
    return 0;
}

// DRAFT: 0x001BF9F0 CheckBlockAttack__15ClockworkReaperFv
// note: 23 words differ; switch reg a0 vs original a1, and case 0/1 store takes `daddu a0,zero` before sb in original. Tried: per-exit early returns (83), grouped 0xF4 guard (87), split guard (51), per-case roll test (47), explicit if/else store (24), ternary return 0x1F:0x22 (23, current), local mode var (23).
int ClockworkReaper::CheckBlockAttack() {
    MathAPI *player = mPlayerAPI__13EntityManager;
    if (player == 0) {
        CdsAssert("ClockworkReaper.cpp", 0xD25, "pPlayer");
    }
    if (m_unkF4 != 0) {
        return 0;
    }
    if (m_unk208 > 0 && player->m_unk23D2 != 0 && player->m_unk15E != 0xD && player->m_unk1CC == m_unk4 &&
        InBlockableState() != 0) {
        char *selfTarget = m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190;
        char *playerTarget = player->m_unk3C ? player->m_unk3C + 0x80 : (char *)player + 0x190;
        float dist = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)playerTarget, (float (*)[4])selfTarget);
        if (dist <= 20.0f) {
            int roll = RandomIntRange__7MathAPIFii(1, 100);
            switch (m_unk1B0) {
            case 0:
                if (roll < 6) {
                    if (m_unk20 == 4) {
                        m_unk2C5 = 1;
                    } else {
                        m_unk2C5 = 0;
                    }
                    return 0x1F;
                }
                break;
            case 1:
                if (roll < 6) {
                    m_unk2C8 = 0;
                    return 0x21;
                }
                break;
            case 2:
                if (roll < 6) {
                    if (m_unk20 == 4) {
                        m_unk2C5 = 1;
                    } else {
                        m_unk2C5 = 0;
                    }
                    return m_unk2C5 ? 0x1F : 0x22;
                }
                break;
            }
        }
    }
    return 0;
}

// DRAFT: 0x001BFB90 FaceHit__15ClockworkReaperFv
// note: 39 words; mode-chain blocks inline, original places 4316/C316 out of line with beq (tried switch with default first, outer if + switch, pExt local, case order 0x07/0x0E/default (40), earlier if-chain, else-if, 0x10 wrap, 0xE/0x7 inversions).
void ClockworkReaper::FaceHit() {
    float dir[4];
    MathAPI *api = *(MathAPI **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(api, dir);
    char *src;
    if (api->m_unk3C != 0) {
        src = api->m_unk3C + 0x90;
    } else {
        src = (char *)api + 0x1A0;
    }
    float f0;
    float f1 = *(float *)(src + 4);
    int mode = (*(MathAPI **)((char *)mpEntMgr__15EntityBaseClass + 0x505C))->m_unk154;
    if (mode != 0x82000010) {
        switch (mode) {
        default:
            f0 = 180.0f;
            break;
        case 0x82000007:
            f0 = 150.0f;
            break;
        case 0x8200000E:
            f0 = -150.0f;
            break;
        }
        char *dst;
        if (m_unk3C != 0) {
            dst = (char *)m_unk3C + 0x90;
        } else {
            dst = (char *)this + 0x1A0;
        }
        f1 = f1 - f0;
        *(float *)(dst + 4) = f1;
        char *pExt = (char *)m_unk38;
        if (pExt != 0) {
            char *s2;
            if (m_unk3C != 0) {
                s2 = (char *)m_unk3C + 0x90;
            } else {
                s2 = (char *)this + 0x1A0;
            }
            *(float *)(pExt + 0x11C) = Round180__Ff(*(float *)(s2 + 4));
        }
    }
}

// FUNCTION: 0x001BFCA0 Stalled__15ClockworkReaperFf
int ClockworkReaper::Stalled(float arg0) {
    char *src;
    float dist;
    if (m_unk3C != 0) {
        src = (char *)m_unk3C + 0x80;
    } else {
        src = (char *)this + 0x190;
    }
    dist = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)((char *)this + 0x2A0), (float (*)[4])src);
    if (dist <= arg0) {
        return 1;
    }
    if (m_unk3C != 0) {
        src = (char *)m_unk3C + 0x80;
    } else {
        src = (char *)this + 0x190;
    }
    m_unk2A0 = *(u_long128 *)src;
    char *ent = *(char **)((char *)m_unk38 + 0xE4);
    if (ent != 0 && (*(int *)(ent + 0xC) & 0x10)) {
        MathAPI *player = mPlayerAPI__13EntityManager;
        char *dst;
        if (player->m_unk3C != 0) {
            dst = (char *)player->m_unk3C + 0x80;
        } else {
            dst = (char *)player + 0x190;
        }
        float angle = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f((void *)this, dst);
        if (angle < 15.0f) {
            return 1;
        }
    }
    return 0;
}

// DRAFT: 0x001BFD90 CheckAttackPlayer__15ClockworkReaperFv
// note: 208 words, size 0x56C vs 0x55C; original fail block at 0x520 vs ours 0x540, mode2 roll compare hoisted into beq delay slot, 0x33 compare shared by modes 0/1; tried plain returns (325), dispatch reorder (317), flipped Distance null test (212), m_unk1B0 switch (307)
int ClockworkReaper::CheckAttackPlayer() {
    int pick;
    int roll;
    float dist;

    if (m_unkF4 != 0) {
        return 0;
    }
    if (!PlayerInAttackRadius()) {
        goto fail;
    }
    if (m_unk218 == 0) {
        goto fail;
    }
    if (!CanAttackInState()) {
        goto fail;
    }
    roll = RandomIntRange__7MathAPIFii(1, 100);
    if (m_unk1B0 == 2) {
        if (roll >= 0x4C) {
            goto fail;
        }
        goto mode2;
    }
    if (m_unk1B0 == 1) {
        if (roll >= 0x33) {
            goto fail;
        }
        goto mode1;
    }
    if (m_unk1B0 == 0) {
        if (roll >= 0x33) {
            goto fail;
        }
        goto mode0;
    }
    goto fail;

mode0:
    dist = Distance__7MathAPIFPA4_fPA4_f(
        (MathAPI *)(m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190),
        (float (*)[4])(mPlayerAPI__13EntityManager->m_unk3C ? (char *)mPlayerAPI__13EntityManager->m_unk3C + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190));
    pick = RandomIntRange__7MathAPIFii(0, 2);
    if (dist <= 7.0f) {
        goto mode0_a7;
    }
    if (dist <= 9.0f) {
        goto fail;
    }
    if (dist >= 12.0f) {
        goto fail;
    }
    if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, mPlayerAPI__13EntityManager, 0) == 0) {
        goto fail;
    }
    m_unk218 = 0;
    if (RandomIntRange__7MathAPIFii(1, 100) < 0x28) {
        m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 4, false);
        return 0x1B;
    }
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 2, false);
    return 0x19;

mode0_a7:
    if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, mPlayerAPI__13EntityManager, 0) == 0) {
        goto fail;
    }
    m_unk218 = 0;
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 2, false);
    return 0x1C;

mode1:
    dist = Distance__7MathAPIFPA4_fPA4_f(
        (MathAPI *)(m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190),
        (float (*)[4])(mPlayerAPI__13EntityManager->m_unk3C ? (char *)mPlayerAPI__13EntityManager->m_unk3C + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190));
    pick = RandomIntRange__7MathAPIFii(0, 2);
    if (dist <= 7.0f) {
        goto mode1_a7;
    }
    if (dist <= 10.0f) {
        goto fail;
    }
    if (dist >= 14.0f) {
        goto fail;
    }
    if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, mPlayerAPI__13EntityManager, 0) == 0) {
        goto fail;
    }
    m_unk218 = 0;
    if (*(int *)((char *)m_unk3C + 0xC) != 1) {
        goto mode1_tail19;
    }
    if (RandomIntRange__7MathAPIFii(1, 100) >= 0x28) {
        goto mode1_tail19;
    }
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 4, false);
    return 0x1E;

mode1_tail19:
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 2, false);
    return 0x19;

mode1_a7:
    if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, mPlayerAPI__13EntityManager, 0) == 0) {
        goto fail;
    }
    m_unk218 = 0;
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 4, false);
    return 0x1D;

mode2:
    dist = Distance__7MathAPIFPA4_fPA4_f(
        (MathAPI *)(m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190),
        (float (*)[4])(mPlayerAPI__13EntityManager->m_unk3C ? (char *)mPlayerAPI__13EntityManager->m_unk3C + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190));
    pick = RandomIntRange__7MathAPIFii(0, 2);
    if (dist <= 15.0f) {
        goto mode2_small;
    }
    if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, mPlayerAPI__13EntityManager, 0) == 0) {
        goto fail;
    }
    m_unk218 = 0;
    if (FastMath_Fabs__Ff(((float *)((mPlayerAPI__13EntityManager->m_unk3C ? (char *)mPlayerAPI__13EntityManager->m_unk3C + 0x80 : (char *)mPlayerAPI__13EntityManager + 0x190)))[1] - ((float *)((m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190)))[1]) >= 6.0f) {
        goto mode2_tail17;
    }
    if (RandomIntRange__7MathAPIFii(1, 100) >= 0x28) {
        goto mode2_tail17;
    }
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 4, false);
    return 0x23;

mode2_tail17:
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 2, false);
    return 0x17;

mode2_small:
    if (dist > 6.0f) {
        goto mode2_tail19;
    }
    if (RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, mPlayerAPI__13EntityManager, 0) == 0) {
        goto fail;
    }
    m_unk218 = 0;
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 2, false);
    if (RandomIntRange__7MathAPIFii(1, 100) < 0x32) {
        return 0x26;
    }
    return 0x25;

mode2_tail19:
    m_unk218 = 0;
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, pick + 2, false);
    return 0x19;

fail:
    m_unk218 = 0;
    m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 0x1E, true);
    return 0;
}

// FUNCTION: 0x001C02F0 CanAttackInState__15ClockworkReaperFv
int ClockworkReaper::CanAttackInState() {
    if (m_unk20 == 0 || m_unk20 == 3 || (unsigned int)(m_unk20 - 0x15) <= 6U || m_unk20 == 0x1C) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001C0330 LoadCorrectMesh__15ClockworkReaperFb
void ClockworkReaper::LoadCorrectMesh(bool arg0) {
    if (m_unk255 == 0 || arg0) {
        if (m_unkD4 == 0) {
            Shadow *shadow = (Shadow *)__nw__FUi(0x10);
            if (shadow != 0) {
                shadow = __ct__6ShadowFQ26Shadow10ShadowTypeUi(shadow, 1, 0x87000007U);
            }
            m_unkD4 = shadow;
            if (m_unkD4 == 0) {
                CdsAssert("ClockworkReaper.cpp", 0xBD8, "mpShadow");
            }
            Shadow *s = m_unkD4;
            if (s != 0) {
                s->m_unk0 = 1;
                void *c = s->m_unkC;
                if (c != 0) {
                    *(unsigned char *)((char *)c + 0x18) = 1;
                }
            }
        }
        switch (m_unk1B0) {
        case 0:
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, ClockworkReaper_InitGruntSeq);
            if (m_unk2B6 == 0) {
                PMNode *node = m_unk3C;
                if (node == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0xBE4, "pSkeleton");
                }
                PMNode *found = Find__6PMNodeFUi(node, 0x8EA3DD30U);
                if (found == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0xBE7, "pHeadJoint");
                }
                PMNode *res = GetResource__16PResourceManagerFUib(mpResMgr__15EntityBaseClass, 0x81000197U, true);
                if (res == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0xBEA, "pHeadNode");
                }
                PMNode *found2 = Find__6PMNodeFUi(res, 0x8EA3DD30U);
                if (found2 == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0xBED, "pNewHeadJoint");
                }
                PMNode *v1 = (PMNode *)found2->m_unk10;
                found->m_unk10 = v1;
                found->m_unk3E &= 0xEF;
                if (v1 != 0) {
                    if (*(unsigned char *)((char *)v1 + 0xC) != 0) {
                        found->m_unk3E |= 0x10;
                    }
                }
                AttachSoulStoneEffect(found);
                BuildDispList__9PSkeletonFv((void *)node);
            }
            break;
        case 1: {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, ClockworkReaper_InitVeteranSeq);
            char *obj = (char *)m_unk38;
            *(float *)(obj + 0x84) = *(float *)(obj + 0x84) - 0.2f;
            *(float *)(obj + 0x94) = *(float *)(obj + 0x94) - 0.2f;
            break;
        }
        case 2:
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, ClockworkReaper_InitEliteSeq);
            break;
        }
        m_unk255 = 1;
    }
}

// FUNCTION: 0x001C0590 OutputDebug__15ClockworkReaperFv
void ClockworkReaper::OutputDebug() {
    char buf[0x100];
    sprintf(buf, "State = %d\n", m_unk20);
    gDebug.DebugDisp(buf);
    PMNode *node = m_unk3C;
    if (node != 0) {
        sprintf(buf, "Anim Frame = %f\n", (double)(GetFrameTime__6PMNodeFv(node)));
        gDebug.DebugDisp(buf);
        sprintf(buf, "Anim Loop = %d\n", (signed char)(m_unk3C->m_unk3F & 7) & 4);
        gDebug.DebugDisp(buf);
    }
}

// DRAFT: 0x001C0650 CheckOnWakeTasks__15ClockworkReaperFv
// note: DIFF 94; node in s0 and Find result in s1 (original s1/s0), prologue daddu after sq. Tried: v0 reuse, s0 declared first, self local copy, !flag test.
void ClockworkReaper::CheckOnWakeTasks() {
    ClockworkReaper *self = this;
    self->m_unk2C4 = 0;
    if (!self->m_unk2B6 || self->m_unk2B8 != 0) {
        PMNode *s1 = self->m_unk3C;
        if (s1->m_unk04 == 1) {
            return;
        }
        if (s1 == 0) {
            CdsAssert("ClockworkReaper.cpp", 0xBA4, "pSkeleton");
        }
        PMNode *s0 = Find__6PMNodeFUi(s1, 0x8EA3DD30);
        if (s0 == 0) {
            CdsAssert("ClockworkReaper.cpp", 0xBA7, "pHeadJoint");
        }
        PMNode *v0 = GetResource__16PResourceManagerFUib(mpResMgr__15EntityBaseClass, 0x81000197, true);
        if (v0 == 0) {
            CdsAssert("ClockworkReaper.cpp", 0xBAA, "pHeadNode");
        }
        v0 = Find__6PMNodeFUi(v0, 0x8EA3DD30);
        if (v0 == 0) {
            CdsAssert("ClockworkReaper.cpp", 0xBAD, "pNewHeadJoint");
        }
        void *v1 = v0->m_unk10;
        s0->m_unk10 = v1;
        s0->m_unk3E &= 0xEF;
        if (v1 != 0 && *((unsigned char *)v1 + 0xC) != 0) {
            s0->m_unk3E |= 0x10;
        }
        if (self->m_unk2E0 == 0) {
            self->AttachSoulStoneEffect(s0);
        }
        BuildDispList__9PSkeletonFv(s1);
    }
    void *a0 = self->m_unk38;
    *(int *)((char *)a0 + 0x84) = 0x4039999A;
    *(int *)((char *)a0 + 0x94) = 0x4039999A;
}

// FUNCTION: 0x001C07E0 OnWakeEvent__15ClockworkReaperFv
void ClockworkReaper::OnWakeEvent() {
    m_unk2C4 = 1;
}

// FUNCTION: 0x001C07F0 OnSleepEvent__15ClockworkReaperFv
void ClockworkReaper::OnSleepEvent() {
    m_unk2E0 = 0;
}

// FUNCTION: 0x001C0800 DeleteEffects__15ClockworkReaperFv
void ClockworkReaper::DeleteEffects() {
    if (m_unk2EC != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2EC);
        m_unk2EC = 0;
    }
    if (m_unk2F0 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2F0);
        m_unk2F0 = 0;
    }
}

// FUNCTION: 0x001C0850 SetSpawnedFromEntity__15ClockworkReaperFPfPfi
void ClockworkReaper::SetSpawnedFromEntity(float *arg0, float *arg1, int arg2) {
    m_unk1C8[0] = arg0[0];
    m_unk1C8[1] = arg0[1];
    m_unk1C8[2] = arg0[2];
    m_unk1D4 = 150.0f;
    m_unk1C4 = 75.0f;
    m_unk1E0 = 0;
    m_unk1B0 = arg2;
    SetupHealth();
    char *dst;
    if (m_unk3C != 0) {
        dst = (char *)m_unk3C + 0x80;
    } else {
        dst = (char *)this + 0x190;
    }
    *(u_long128 *)dst = *(u_long128 *)arg0;
    if (arg1 != 0) {
        if (m_unk3C != 0) {
            dst = (char *)m_unk3C + 0x90;
        } else {
            dst = (char *)this + 0x1A0;
        }
        *(u_long128 *)dst = *(u_long128 *)arg1;
    }
}

// FUNCTION: 0x001C08F0 SetSpawnedFromLift__15ClockworkReaperFv
void ClockworkReaper::SetSpawnedFromLift() {
    *(unsigned char *)((char *)this + 0x2FC) = 1;
    *(unsigned char *)((char *)this + 0x2FD) = 0;
}

// FUNCTION: 0x001C0900 SetDefaultVars__15ClockworkReaperFv
void ClockworkReaper::SetDefaultVars() {
    m_unk1B0 = 0;
    SetupHealth();
    m_unk1B8[0] = 0.0f;
    m_unk1B8[1] = 0.0f;
    m_unk1B8[2] = 0.0f;
    m_unk1C4 = 25.0f;
    m_unk1D4 = 35.0f;
    m_unk1E0 = 1;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F4 = 0;
    m_unk1D8 = 0;
    m_unk1F8 = 0x3DCCCCCD;
    m_unk1FC = 0;
    m_unk204 = 0;
}

// FUNCTION: 0x001C0980 SetupHealth__15ClockworkReaperFv
void ClockworkReaper::SetupHealth() {
    int roll = RandomIntRange__7MathAPIFii(1, 100);
    switch (m_unk1B0) {
    case 0:
        if (roll & 1) {
            m_unk208 = 0xDC;
            m_unk2B6 = 0;
        } else {
            m_unk208 = 0x104;
            m_unk2B6 = 1;
        }
        if (m_unk200 != 0) {
            m_unk2B6 = 1;
        }
        break;
    case 1:
        m_unk2B6 = 1;
        if (roll & 1) {
            m_unk208 = 0x190;
        } else {
            m_unk208 = 0x1E0;
        }
        break;
    case 2:
        m_unk2B6 = 1;
        if (roll & 1) {
            m_unk208 = 0x2D0;
        } else {
            m_unk208 = 0x370;
        }
        break;
    default:
        CdsAssert("ClockworkReaper.cpp", 0xB37, "Illegal Reaper Difficulty");
        break;
    }
    m_unk210 = m_unk208;
}

// FUNCTION: 0x001C0A70 SetEditableVars__15ClockworkReaperFPc
void ClockworkReaper::SetEditableVars(char *arg0) {
    memcpy(&m_unk1B0, arg0, 0x58);
    SetupHealth();
    switch (m_unk1FC) {
    case 0:
    case 7:
    case 8:
        break;
    default:
        CDS_ASSERT(0xAFA, !"Invalid m_iSpawnsKey in Reaper\n");
        break;
    }
}

// FUNCTION: 0x001C0B00 OnTimerEvent__15ClockworkReaperFUi
void ClockworkReaper::OnTimerEvent(unsigned int arg0) {
    if (arg0 == m_unk220) {
        m_unk218 = 1;
        return;
    }
    if (arg0 == m_unk300) {
        m_unk2FE = 1;
        return;
    }
    if (arg0 == m_unk2E8) {
        m_unk240 = 1;
        return;
    }
    if (arg0 == m_unk250) {
        m_unk24D = 1;
    }
}

// DRAFT: 0x001C0B60 OnHitEvent__15ClockworkReaperFP15EntityBaseClassiUiUi
// note: DIFF 455 words, size 0x73c vs 0x750; frame 0x90 vs 0xA0 with f20 (20.0f, hoisted in original) not spilled; per-path returns and store order differ; tried /2.0f to *0.5f (457 to 455). Not revisited in job d2.
int ClockworkReaper::OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    int ret;
    int state;
    unsigned int masked;
    char *pick0;
    char *pick1;

    if (m_unkF4 != 0) {
        m_unk208 -= arg1;
        if (m_unk208 > 0) {
            return 1;
        }
        m_unk224 = arg2;
        masked = arg2 & -0x5C1;
        m_unk228 = masked;
        SetState__15EntityBaseClassFi(this, 9);
        return 2;
    }

    state = m_unk20;
    if (state == 0x21) {
        if (GetFrameTime__6PMNodeFv(m_unk3C) < 10.0f) {
            return 0;
        }
    }
    if (state == 7 || state == 0x14 || state == 0x2A) {
        if (*(int *)((char *)m_unk38 + 0xC0) == 0) {
            return 0;
        }
    }
    RemoveFromAttackSystem__15EntityBaseClassFv(this);
    DeleteEffects();

    if (arg0->m_unk8 == 0x1D) {
        m_unk224 = 0;
        m_unk228 = 0;
        m_unk208 = 0;
        pick0 = arg0->m_unk3C ? (char *)arg0->m_unk3C + 0x80 : (char *)&arg0->m_unk190;
        pick1 = m_unk3C ? (char *)m_unk3C + 0x80 : (char *)&m_unk190;
        *(float *)(pick1 + 4) = 2.0f + *(float *)(pick0 + 4);
        SetState__15EntityBaseClassFi(this, 9);
        return 2;
    }

    if (state == 2 || state == 6) {
        pick1 = m_unk3C ? (char *)m_unk3C + 0x80 : (char *)&m_unk190;
        *(u_long128 *)m_unk290 = *(u_long128 *)pick1;
    }
    masked = arg2 & -0x5C1;
    if (state == 0x1F || state == 0x22) {
        if (masked != 2 && (arg2 & 0x40) == 0) {
            SetState__15EntityBaseClassFi(this, 0x20);
            return 4;
        }
    }
    if (state == 9 && m_unk24C != 0) {
        m_unk10C &= 0xF8FFFFFF;
        SetState__15EntityBaseClassFi(this, 0x12);
        return 5;
    }
    if (state == 0xF) {
        ret = 1;
        if (GetFrameTime__6PMNodeFv(m_unk3C) < 30.0f) {
            m_unk278 = (arg2 & 0x200) ? ret : 0;
            m_unk22C = arg2;
            m_unk208 -= arg1;
            if (m_unk208 > 0) {
                SetState__15EntityBaseClassFi(this, 0x10);
                return ret;
            }
            m_unk224 = arg2;
            m_unk228 = masked;
            SetState__15EntityBaseClassFi(this, 9);
            return 2;
        }
    }
    if (state == 0x10) {
        if (GetFrameTime__6PMNodeFv(m_unk3C) < 20.0f) {
            m_unk278 = (arg2 & 0x200) ? 1 : 0;
            m_unk22C = arg2;
            m_unk208 -= arg1;
            if (m_unk208 > 0) {
                SetState__15EntityBaseClassFi(this, 0x10);
                return 1;
            }
            m_unk224 = arg2;
            m_unk228 = masked;
            SetState__15EntityBaseClassFi(this, 9);
            return 2;
        }
    }

    if (m_unk240 == 0 && !(GetFrameTime__6PMNodeFv(m_unk3C) < (float)m_unk248)) {
        if (masked == 2) {
            m_unk208 = 0;
            m_unk10C &= 0xFDFFFFFF;
            SetState__15EntityBaseClassFi(this, 0xE);
            return 2;
        }
        if (masked == 1 || masked == 0x220 || masked == 0x201 ||
            (arg2 & -0x101) == 0x44 || (arg2 & -0x101) == 0x4F) {
            m_unk208 -= arg1;
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, ClockworkReaper_JoltOnGround);
            if (m_unk208 <= 0) {
                m_unk208 = 0;
                m_unk10C &= 0xFDFFFFFF;
                SetState__15EntityBaseClassFi(this, 0xE);
            }
            return 2;
        }
        return 3;
    }

    if ((arg0->m_unk10C & 1) == 0 && arg0->m_unk163 == 4) {
        m_unk22C = 8;
        m_unk2E6 = 0;
        SetState__15EntityBaseClassFi(this, 4);
        return 1;
    }

    FaceHit();
    m_unk208 -= arg1;
    if (m_unk2F8 == 0) {
        if ((float)m_unk208 <= (float)m_unk210 * 0.5f) {
            m_unk2F8 = CreateDamageFx__15EntityBaseClassFfUi(this, 90.0f, 0);
        }
    }
    if (m_unk2F8 != 0 && (float)m_unk208 <= (float)m_unk210 / 4.0f) {
        ChangeDamageFxInterval__15EntityBaseClassFUif(this, m_unk2F8, 20.0f);
    }

    if (m_unk208 > 0) {
        if (m_unk2B6 != 0 && m_unk2B8 == 0 && !(m_unk210 / 2 < m_unk208)) {
            PMNode *head;
            PMNode *headJoint;
            PMNode *headNode;
            void *headMesh;
            int pass;

            m_unk2B8 = 1;
            pick0 = m_unk3C ? (char *)m_unk3C + 0x90 : (char *)&m_unk1A0;
            pick1 = m_unk3C ? (char *)m_unk3C + 0x80 : (char *)&m_unk190;
            pass = GetRenderPassIndex();
            mEffectAPI__13EntityManager.CreateOneshot(0x81000082, 0x8200011A, (float (*)[4])pick1,
                                                      (float (*)[4])pick0, 0, 0.5f, true, pass, false);

            head = m_unk3C;
            if (head == 0) {
                CdsAssert("ClockworkReaper.cpp", 0xAB5, "pSkeleton");
            }
            headJoint = Find__6PMNodeFUi(head, 0x8EA3DD30);
            if (headJoint == 0) {
                CdsAssert("ClockworkReaper.cpp", 0xAB8, "pHeadJoint");
            }
            headNode = GetResource__16PResourceManagerFUib(mpResMgr__15EntityBaseClass, 0x81000197, true);
            if (headNode == 0) {
                CdsAssert("ClockworkReaper.cpp", 0xABB, "pHeadNode");
            }
            headNode = Find__6PMNodeFUi(headNode, 0x8EA3DD30);
            if (headNode == 0) {
                CdsAssert("ClockworkReaper.cpp", 0xABE, "pNewHeadJoint");
            }

            headMesh = headNode->m_unk10;
            headJoint->m_unk10 = headMesh;
            *((unsigned char *)headJoint + 0x3E) &= 0xEF;
            if (headMesh != 0) {
                if (*((unsigned char *)headMesh + 0xC) != 0) {
                    *((unsigned char *)headJoint + 0x3E) |= 0x10;
                }
            }
            AttachSoulStoneEffect(headJoint);
            BuildDispList__9PSkeletonFv(head);
        }
        m_unk22C = arg2;
    } else {
        m_unk224 = arg2;
        m_unk228 = masked;
        SetState__15EntityBaseClassFi(this, 9);
        ret = 2;
        return ret;
    }

    m_unk2E6 = (arg0->m_unk8 == 0x6C);
    SetState__15EntityBaseClassFi(this, 4);
    return ret;
}

// FUNCTION: 0x001C12B0 OnStopAttack__15ClockworkReaperFv
void ClockworkReaper::OnStopAttack() {
    if (m_unk208 > 0 && m_unk163 != 2 && m_unk20 != 0x15) {
        SetState__15EntityBaseClassFi(this, 0x15);
    }
}

// DRAFT: 0x001C1300 Execute__15ClockworkReaperFv
// note: DIFF 3545 words (alignment shifted after the dispatch: original s0=state before s1=this and a rodata jump table); full transcription of the m2c draft as one switch, frame 0x120 matches; no scheduling variants tried yet
void ClockworkReaper::Execute() {
    float vGround[4];
    float vSpawn[4];
    float vRot[4];
    float vFwd2[4];
    float vShellDest[4];
    float vShellStart[4];
    float vGround2[4];
    float vVel[4];
    float vTarget[4];
    float vScaled[4];
    float vFwd[4];
    int state = m_unk20;

    if (fst_TestAmbientSounds != 0 && state != 5) {
        if (m_unk308 != 0) {
            StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk308);
            m_unk308 = 0;
        }
    }

    switch (m_unk20) {
    case -1:
        if (m_unkE9 != 0) {
            Copy128(m_unk290, m_unk1C8);
            if (!(Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])m_unk290) <= m_unk1D4)) {
                printf("ERROR - Clockwork Reaper shutdown as initial position wasn't inside attack radius\n");
                SetState__15EntityBaseClassFi(this, -2);
                return;
            }
            m_unk10C &= 0xF8FFFFFF;
            m_unk10C |= 0x071B1902;
            m_unk2E5 = 0;
            m_unk218 = 1;
            m_unk240 = 1;
            m_unk2E4 = 0;
            m_unk210 = m_unk208;
            if (m_unk1B8[0] == 0.0f) {
                if (m_unk1B8[1] == 0.0f && m_unk1B8[2] == 0.0f) {
                    m_unk1B8[0] = PosOf(m_unk3C, &m_unk190)[0];
                    m_unk1B8[1] = PosOf(m_unk3C, &m_unk190)[1];
                    m_unk1B8[2] = PosOf(m_unk3C, &m_unk190)[2];
                }
            }
            m_unk104 = 2.0f;
            m_unk108 = 4.0f;
            if ((unsigned int)m_unk1B0 >= 3U) {
                CdsAssert("ClockworkReaper.cpp", 0x20D, "mEVars.m_iType < 3");
            }
            if (m_unk1D8 != 0) {
                m_unk1C4 = m_unk18C;
                m_unk1D4 = m_unk18C;
            }
            if (m_unk1E0 != 2 && m_unk1E0 != 5 && m_unk1E0 != 7) {
                m_unk21C = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, PlayerPos());
                m_unk230 = QuatOf(m_unk3C, &m_unk1A0);
                m_unk230[1] = m_unk21C;
            }
            m_unk280[0] = m_unk1B8[0];
            m_unk280[1] = m_unk1B8[1];
            m_unk280[2] = m_unk1B8[2];
            sceVu0SubVector(m_unk2D0, m_unk2D0, m_unk2D0);
        }
        if (m_unk2FC == 0 && !(Distance__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk280, (float (*)[4])PlayerPos()) <= m_unk1C4)) {
        } else {
            if (m_unk38 == 0) {
                m_unk38 = new Physics;
                if (m_unk38 == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0x22A, "mpPhysics");
                }
            }
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12U, 0);
            m_unk103 = 0x40;
            if (m_unk1E0 != 0) {
                SetState__15EntityBaseClassFi(this, 0xA);
            } else {
                SetState__15EntityBaseClassFi(this, 0);
            }
        }
        break;
    case 0:
        if (m_unkE9 != 0) {
            m_unk2E5 = 1;
            if (m_unk2FC == 0) {
                EnableSleep__15EntityBaseClassFbb(this, true, false);
            }
            m_unk38->m_unkEC = 0x80113FD5;
            LoadCorrectMesh(false);
            if (RandomIntRange__7MathAPIFii(1, 0x14) & 1) {
                Play(this, ClockworkReaper_Idle1Seq);
            } else {
                Play(this, ClockworkReaper_Idle2Seq);
            }
            if (m_unk304 != 0) {
                if (InstanceIsValid__15EntityBaseClassFUi(m_unk304) != 0) {
                    SetState__15EntityBaseClassFi(this, 5);
                    return;
                }
            }
        } else if (m_unk2FC != 0 && m_unk2FD == 0) {
            char *pCC = m_unk38->m_unkCC;
            if (pCC != 0 && ((((PMNode *)pCC)->m_unk3F & 7)) == 0) {
                m_unk2FD = 1;
            }
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x68U, 0x29U);
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk2FD != 0 && PlayerInAttackRadius() != 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
            return;
        }
        if (m_unk160 == 0) {
            if (RandomIntRange__7MathAPIFii(1, 0x14) & 1) {
                Play(this, ClockworkReaper_Idle1Seq);
            } else {
                Play(this, ClockworkReaper_Idle2Seq);
            }
        }
        break;
    case 0x15:
        if (PlayerInAttackRadius() != 0) {
            float fDist = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PlayerPos());
            if (m_unk304 != 0) {
                EntityBaseClass *pTarget = InstanceIsValid__15EntityBaseClassFUi(m_unk304);
                if (pTarget != 0 && EntVirt3C(pTarget) != 0) {
                    if (Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PosOf(pTarget->m_unk3C, &pTarget->m_unk190)) < 2.0f * fDist) {
                        SetState__15EntityBaseClassFi(this, 5);
                        return;
                    }
                }
            }
            switch (m_unk1B0) {
            case 1:
            case 0:
                if (!(fDist <= 25.0f)) {
                    SetState__15EntityBaseClassFi(this, 3);
                } else if (!(fDist <= 12.0f)) {
                    SetState__15EntityBaseClassFi(this, 0x19);
                } else if (fDist < 7.0f) {
                    if (RandomIntRange__7MathAPIFii(1, 0x64) < 0x33) {
                        SetState__15EntityBaseClassFi(this, 0x17);
                    } else {
                        SetState__15EntityBaseClassFi(this, 0x16);
                    }
                } else {
                    SetState__15EntityBaseClassFi(this, 0x17);
                }
                break;
            case 2:
                if (!(fDist <= 40.0f)) {
                    SetState__15EntityBaseClassFi(this, 3);
                } else if (!(fDist <= 25.0f)) {
                    SetState__15EntityBaseClassFi(this, 0x19);
                } else if (fDist < 15.0f) {
                    if (RandomIntRange__7MathAPIFii(1, 0x64) < 0x33) {
                        SetState__15EntityBaseClassFi(this, 0x17);
                    } else {
                        SetState__15EntityBaseClassFi(this, 0x16);
                    }
                } else {
                    SetState__15EntityBaseClassFi(this, 0x17);
                }
                break;
            }
        } else {
            SetState__15EntityBaseClassFi(this, 0);
        }
        break;
    case 0x18:
        if (m_unkE9 != 0) {
            Copy128(&m_unk2A0, PosOf(m_unk3C, &m_unk190));
            m_unk258 = 0;
            m_unk260 = RandomIntRange__7MathAPIFii(1, 2);
            Play(this, ClockworkReaper_WalkBackwardsSeq);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x10U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x20U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x30U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x40U);
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if ((m_unk3C->m_unk3F & 7) & 4) {
            if (Stalled(2.0f) != 0) {
                SetState__15EntityBaseClassFi(this, 0x1A);
                return;
            }
            m_unk258 += 1;
            if (m_unk258 == m_unk260) {
                SetState__15EntityBaseClassFi(this, 0x15);
            }
        }
        break;
    case 0x19:
        if (m_unkE9 != 0) {
            Copy128(&m_unk2A0, PosOf(m_unk3C, &m_unk190));
            m_unk268 = 0;
            m_unk26C = 1;
            Play(this, ClockworkReaper_WalkForwardsSeq);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0xEU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x20U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x32U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x42U);
        if ((m_unk3C->m_unk3F & 7) & 4) {
            if (Stalled(2.0f) != 0) {
                SetState__15EntityBaseClassFi(this, 0x1A);
                return;
            }
            m_unk268 += 1;
            if (m_unk268 == m_unk26C) {
                SetState__15EntityBaseClassFi(this, 0x15);
            }
        }
        break;
    case 0x17:
        if (m_unkE9 != 0) {
            Copy128(&m_unk2A0, PosOf(m_unk3C, &m_unk190));
            m_unk25C = 0;
            m_unk264 = RandomIntRange__7MathAPIFii(2, 3);
            m_unk270 = !(RandomIntRange__7MathAPIFii(1, 0x14) & 1) ? 1 : 0;
            if (m_unk270 == 0) {
                Play(this, ClockworkReaper_SideStepLeftSeq);
            } else {
                Play(this, ClockworkReaper_SideStepRightSeq);
            }
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0xEU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x27U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x40U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x55U);
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if ((m_unk3C->m_unk3F & 7) & 4) {
            if (Stalled(2.0f) != 0) {
                SetState__15EntityBaseClassFi(this, 0x19);
                return;
            }
            m_unk25C += 1;
            if (m_unk25C == m_unk264) {
                if (!(Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PlayerPos()) <= 15.0f)) {
                    SetState__15EntityBaseClassFi(this, 0x19);
                } else if (RandomIntRange__7MathAPIFii(1, 0x64) < 0x1F) {
                    SetState__15EntityBaseClassFi(this, 0x16);
                } else {
                    SetState__15EntityBaseClassFi(this, 0x18);
                }
            }
        }
        break;
    case 0x1A:
        if (m_unkE9 != 0) {
            float *pPos = PosOf(m_unk3C, &m_unk190);
            GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, vFwd);
            sceVu0ScaleVector(vScaled, vFwd, 10.0f);
            sceVu0AddVector(vTarget, vScaled, pPos);
            if (m_unk2E7 != 0) {
                if (m_unk2FC == 0 && Distance__7MathAPIFPA4_fPA4_f((MathAPI *)vTarget, (float (*)[4])m_unk290) <= m_unk1D4) {
                    vTarget[1] += 10.0f;
                    if (GetGroundPos__7MathAPIFPA4_f(vTarget) != 0) {
                        if (!(vTarget[1] <= 1.0f + pPos[1])) {
                            m_unk2C0 = vTarget[1] - pPos[1];
                            if (!(Distance__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk2D0, (float (*)[4])PosOf(m_unk3C, &m_unk190)) <= 3.0f)) {
                                SetState__15EntityBaseClassFi(this, 0x27);
                                return;
                            }
                        }
                    }
                }
            }
            if (RandomIntRange__7MathAPIFii(1, 0xA) & 1) {
                Play(this, ClockworkReaper_Idle1Seq);
            } else {
                Play(this, ClockworkReaper_Idle2Seq);
            }
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x27:
        if (m_unkE9 != 0) {
            Copy128(m_unk2D0, PosOf(m_unk3C, &m_unk190));
            Play(this, ClockworkReaper_JumpLaunchSeq);
        }
        if (m_unk160 == 0) {
            GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, vFwd);
            vVel[0] = 0.35f * vFwd[0];
            vVel[1] = 1.5f * (m_unk2C0 / 10.0f);
            vVel[2] = 0.35f * vFwd[2];
            if (!(vVel[1] <= 1.0f)) {
                vVel[1] = 1.0f;
            }
            if (m_unk38 != 0) {
                Copy128(&m_unk38->m_unk0, vVel);
            }
            m_unk38->m_unk110 = 0.04f;
            SetState__15EntityBaseClassFi(this, 0x28);
        }
        break;
    case 0x28:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_JumpAirSeq);
        }
        GetGroundPos__7PhysicsFv(vGround);
        Copy128(vGround2, vGround);
        if (PosOf(m_unk3C, &m_unk190)[1] <= 1.0f + vGround2[1]) {
            SetState__15EntityBaseClassFi(this, 0x29);
        }
        break;
    case 0x29:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_JumpLandSeq);
        }
        if (m_unk160 == 0) {
            if (m_unk38 != 0) {
                Copy128(&m_unk38->m_unk0, &gUnitMatrix[12]);
            }
            EntityBaseClass *pTarget = InstanceIsValid__15EntityBaseClassFUi(m_unk304);
            if (pTarget != 0 && EntVirt3C(pTarget) != 0) {
                SetState__15EntityBaseClassFi(this, 5);
                return;
            }
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x16:
        if (m_unkE9 != 0) {
            switch (m_unk1B0) {
            case 0:
                Play(this, ClockworkReaper_Taunt1Seq);
                break;
            case 1:
                Play(this, ClockworkReaper_Taunt2Seq);
                break;
            case 2:
                Play(this, ClockworkReaper_Taunt3Seq);
                break;
            }
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk140 == ClockworkReaper_Taunt1Seq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x67U, 5U);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0xA:
        if (m_unkE9 != 0) {
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            if ((unsigned int)m_unk1E0 < 8U) {
                switch (m_unk1E0) {
                case 1:
                case 3: {
                    ZinShell *pShell = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0xFU, false, 0);
                    if (pShell == 0) {
                        CdsAssert("ClockworkReaper.cpp", 0x420, "pContainerEnt");
                    }
                    m_unk23C = pShell->m_unk4;
                    if (m_unk1E0 == 3) {
                        pShell->m_unk22C = 1;
                    }
                    float *pPos = PosOf(m_unk3C, &m_unk190);
                    float fX = m_unk1E4f;
                    float fPX = pPos[0];
                    float fZ;
                    if (fX == fPX && m_unk1E8f == pPos[1] && m_unk1ECf == pPos[2]) {
                        vShellStart[0] = fPX;
                        vShellStart[1] = 50.0f + pPos[1];
                        fZ = pPos[2];
                    } else if (fX == 0.0f && m_unk1E8f == 0.0f && m_unk1ECf == 0.0f) {
                        vShellStart[0] = fPX;
                        vShellStart[1] = 50.0f + pPos[1];
                        fZ = pPos[2];
                    } else {
                        vShellStart[0] = fX;
                        vShellStart[1] = m_unk1E8f;
                        fZ = m_unk1ECf;
                    }
                    vShellStart[2] = fZ;
                    vShellDest[0] = pPos[0];
                    vShellDest[1] = pPos[1];
                    vShellDest[2] = pPos[2];
                    SetShellStartAndDest__8ZinShellFRA4_fRA4_f(pShell, vShellStart, vShellDest);
                    if (m_unk1F4 != 0) {
                        pShell->m_unk224 = m_unk1F4;
                        pShell->m_unk228 = m_unk4;
                    }
                    break;
                }
                case 2:
                    if (m_unk1F4 != 0) {
                        TriggerBGAnim__15EntityBaseClassFUiibUi(this, m_unk1F4, -1, false, 0);
                    }
                    SetState__15EntityBaseClassFi(this, 0x14);
                    return;
                case 6:
                    if (m_unk1F4 != 0) {
                        TriggerBGAnim__15EntityBaseClassFUiibUi(this, m_unk1F4, -1, false, 0);
                    }
                case 4:
                    SetState__15EntityBaseClassFi(this, 0);
                    return;
                case 5:
                    SetState__15EntityBaseClassFi(this, 0x2A);
                    return;
                case 7:
                    if (m_unk1F4 != 0) {
                        TriggerBGAnim__15EntityBaseClassFUiibUi(this, m_unk1F4, -1, false, 0);
                    }
                    SetState__15EntityBaseClassFi(this, 0x14);
                    PlaySound__15EntityBaseClassFUi(this, 0x1F9U);
                    return;
                }
            } else {
                CdsAssert("ClockworkReaper.cpp", 0x476, "\0");
            }
        }
        if (m_unk1E0 != 1) {
            CdsAssert("ClockworkReaper.cpp", 0x48C, "\0");
        } else {
            void *pApp = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk23C);
            if (pApp == 0 || ((ZinShell *)pApp)->m_unk22D != 0) {
                m_unk238 = RandomFloatRange__7MathAPIFff(0.0f, 360.0f);
                SetState__15EntityBaseClassFi(this, 7);
            }
        }
        break;
    case 0x2A:
        if (m_unkE9 != 0) {
            LoadCorrectMesh(false);
            Play(this, ClockworkReaper_OverheadAttackSeq);
            m_unk10C = m_unk10C & 0xF9FFFFFF;
        } else if ((int)GetFrameTime__6PMNodeFv(m_unk3C) >= 0x14) {
            m_unk10C = m_unk10C | 0x06000000;
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xF1U, 0x16U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x66U, 0x37U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xF1U, 0x50U);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0);
        }
        break;
    case 0x14:
        if (m_unkE9 != 0) {
            m_unk38->m_unk10C = 0.2f;
            GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, vFwd2);
            sceVu0Normalize(vFwd2, vFwd2);
            sceVu0ScaleVector(vFwd2, vFwd2, m_unk1F8f);
            Copy128(&m_unk38->m_unk0, vFwd2);
            LoadCorrectMesh(false);
            Play(this, ClockworkReaper_JumpFromShellSeq);
        }
        if (m_unk2B4 == 0 && (m_unk38->m_unk108 & 1)) {
            m_unk2B4 = 1;
            PlaySound__15EntityBaseClassFUi(this, 0xF1U);
        }
        {
            float *pV = (float *)&m_unk38->m_unk0;
            if (pV[0] == 0.0f && pV[1] == 0.0f && pV[2] == 0.0f) {
                SetState__15EntityBaseClassFi(this, 8);
            }
        }
        break;
    case 7:
        if (m_unkE9 != 0) {
            float fCos = cosf(0.017453292f * m_unk238);
            float fSin = sinf(0.017453292f * m_unk238);
            m_unk38->m_unk10C = 0.2f;
            vRot[0] = m_vDefaultSpawnVelocity[0] * fSin + m_vDefaultSpawnVelocity[2] * fCos;
            vRot[2] = m_vDefaultSpawnVelocity[0] * fCos - m_vDefaultSpawnVelocity[2] * fSin;
            vRot[1] = m_vDefaultSpawnVelocity[1];
            Copy128(&m_unk38->m_unk0, vRot);
            LoadCorrectMesh(false);
            Play(this, ClockworkReaper_JumpFromShellSeq);
        }
        {
            float *pV = (float *)&m_unk38->m_unk0;
            if (pV[0] == 0.0f && pV[1] == 0.0f && pV[2] == 0.0f) {
                SetState__15EntityBaseClassFi(this, 8);
            }
        }
        break;
    case 8:
        if (m_unkE9 != 0) {
            if (m_unk2FC == 0) {
                EnableSleep__15EntityBaseClassFbb(this, true, false);
            }
            Play(this, ClockworkReaper_AssembleSeq);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk1E0 == 7 && m_unk2B4 == 0 && (m_unk38->m_unk108 & 1)) {
            m_unk2B4 = 1;
            PlaySound__15EntityBaseClassFUi(this, 0xF1U);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0);
        }
        break;
    case 3:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_RunSeq);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0xDU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x1AU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x27U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x34U);
        if (Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PlayerPos()) <= 15.0f) {
            SetState__15EntityBaseClassFi(this, 0x15);
            return;
        }
        if (((m_unk3C->m_unk3F & 7) & 4) && Stalled(2.0f) != 0) {
            SetState__15EntityBaseClassFi(this, 0x1A);
            return;
        }
        break;
    case 4:
        if (m_unkE9 != 0) {
            m_unk10C |= 0x01000000;
            if (m_unk1FC == 0) {
                m_unk38->m_unkEC = 0x80113F55;
            }
            m_unk21C = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, PlayerPos());
            m_unk230 = QuatOf(m_unk3C, &m_unk1A0);
            m_unk230[1] = m_unk21C;
            int nHit = m_unk22C;
            switch (nHit & ~0x580) {
            case 0xF:
                Play(this, ClockworkReaper_LaunchSeq);
                SetState__15EntityBaseClassFi(this, 0xF);
                return;
            case 0x804:
                Play(this, ClockworkReaper_HitSeq);
                break;
            case 0x4:
                if (RandomIntRange__7MathAPIFii(1, 0x64) & 1) {
                    Play(this, ClockworkReaper_HitByDoubleSlashSeq);
                } else {
                    Play(this, ClockworkReaper_HitSeq);
                }
                break;
            case 0xC:
                Play(this, ClockworkReaper_KnockBackSeq);
                break;
            case 0xD:
                Play(this, ClockworkReaper_HitSeq);
                break;
            case 0x2D:
                if (RandomIntRange__7MathAPIFii(1, 0x64) < 0x15) {
                    m_unk244 = m_unk22C;
                    SetState__15EntityBaseClassFi(this, 0xD);
                    return;
                }
                Play(this, ClockworkReaper_Hit2Seq);
                break;
            case 0x20:
                Play(this, ClockworkReaper_HitSeq);
                break;
            case 0x8:
                if ((m_unk210 >> 2) >= m_unk208) {
                    m_unk244 = nHit;
                    SetState__15EntityBaseClassFi(this, 0xD);
                } else {
                    Play(this, ClockworkReaper_Hit2Seq);
                }
                return;
            case 0x1:
                Play(this, ClockworkReaper_OverheadHitSeq);
                break;
            case 0x201:
                Play(this, ClockworkReaper_Hit2Seq);
                break;
            case 0x5:
                Play(this, ClockworkReaper_HitByDoubleSlashSeq);
                break;
            case 0x800:
            case 0x808:
                Play(this, ClockworkReaper_HitSeq);
                break;
            case 0x40:
                if (RandomIntRange__7MathAPIFii(1, 0x64) & 1) {
                    Play(this, ClockworkReaper_HitBySingleSlashSeq);
                } else {
                    Play(this, ClockworkReaper_HitSeq);
                }
                break;
            case 0x44:
                m_unk244 = nHit;
                SetState__15EntityBaseClassFi(this, 0xD);
                return;
            case 0x4F:
                Play(this, ClockworkReaper_HitSeq);
                break;
            case 0x4D:
                Play(this, ClockworkReaper_Hit2Seq);
                break;
            case 0x48:
                Play(this, ClockworkReaper_LaunchSeq);
                SetState__15EntityBaseClassFi(this, 0xF);
                return;
            default:
                if (m_unk2E6 == 0 && (RandomIntRange__7MathAPIFii(1, 0x64) & 1)) {
                    Play(this, ClockworkReaper_HitBySingleSlashSeq);
                } else {
                    Play(this, ClockworkReaper_HitSeq);
                }
                break;
            }
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0xF:
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x10:
        if (m_unkE9 != 0) {
            if (m_unk278 != 0) {
                if (m_unk22C == 0x220) {
                    Play(this, ClockworkReaper_JuggleInAir3rdHitSeq);
                } else {
                    Play(this, ClockworkReaper_JuggleInAirSeq);
                }
            } else {
                Play(this, ClockworkReaper_JuggleSeq);
            }
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk160 == 0) {
            m_unk10C &= 0xFEFFFFFF;
            m_unk240 = 0;
            m_unk2E8 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 4U, false);
            SetState__15EntityBaseClassFi(this, 0x11);
        }
        break;
    case 0x11:
        if (m_unk240 != 0) {
            m_unk10C |= 0x01000000;
            SetState__15EntityBaseClassFi(this, 0xC);
        }
        break;
    case 0xD:
        if (m_unkE9 != 0) {
            unsigned int nTime = 4;
            m_unk38->m_unk118 = 0;
            m_unk240 = 0;
            if (m_unkF4 == 0) {
                m_unk10C &= 0xFDFFFFFF;
            }
            m_unk244 &= ~0x580;
            switch (m_unk244) {
            case 0x8:
                Play(this, ClockworkReaper_UpwardStrikeSeq);
                m_unk248 = 0x12;
                break;
            case 0x20:
            case 0x2D:
                Play(this, ClockworkReaper_KnockDownSeq);
                m_unk248 = 0xB;
                break;
            case 0x44:
                Play(this, ClockworkReaper_KnockDownSeq2);
                nTime = 2;
                m_unk248 = 0x28;
                break;
            default:
                CdsAssert("ClockworkReaper.cpp", 0x650, "\0");
                break;
            }
            m_unk2E8 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, nTime, false);
        }
        if (!(GetFrameTime__6PMNodeFv(m_unk3C) < (float)m_unk248)) {
            m_unk10C |= 0x02000000;
        }
        if (m_unk160 == 0) {
            m_unk10C &= 0xFEFFFFFF;
            if (m_unk240 != 0) {
                m_unk10C |= 0x01000000;
                SetState__15EntityBaseClassFi(this, 0xC);
                return;
            }
        }
        break;
    case 0xC:
        if (m_unkE9 != 0) {
            m_unk38->m_unkEC = 0x80113FD5;
            Play(this, ClockworkReaper_GetBackUpSeq);
            m_unk2F0 = mEffectAPI__13EntityManager.CreateOneshot(0x81000080U, 0x820000FCU, 0, 0, 0, 0.5f, 0, 0, 0);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 5: {
        if (m_unkE9 != 0) {
            m_unk2BC = RandomIntRange__7MathAPIFii(0x78, 0xB4);
            EntityBaseClass *pTgt = InstanceIsValid__15EntityBaseClassFUi(m_unk304);
            if (pTgt != 0) {
                if (!(Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PosOf(pTgt->m_unk3C, &pTgt->m_unk190)) <= 15.0f)) {
                    Play(this, ClockworkReaper_RunSeq);
                } else {
                    Play(this, ClockworkReaper_WalkForwardsSeq);
                }
            }
        }
        if (m_unk140 == ClockworkReaper_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0xDU);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x1AU);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x27U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x34U);
        } else {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0xEU);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x20U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x32U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E2AU, 0x42U);
        }
        if (((m_unk3C->m_unk3F & 7) & 4) && Stalled(2.0f) != 0) {
            SetState__15EntityBaseClassFi(this, 0x1A);
            return;
        }
        if (m_unk2BC != 0) {
            m_unk2BC = m_unk2BC - 1;
        }
        EntityBaseClass *pTarget = InstanceIsValid__15EntityBaseClassFUi(m_unk304);
        if (pTarget != 0) {
            if (EntVirt3C(pTarget) == 0) {
                Copy128(m_unk290, PosOf(m_unk3C, &m_unk190));
                m_unk304 = 0;
                SetState__15EntityBaseClassFi(this, 0);
                return;
            }
            if (!(Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PosOf(pTarget->m_unk3C, &pTarget->m_unk190)) <= 15.0f)) {
                if (m_unk140 != ClockworkReaper_RunSeq) {
                    Play(this, ClockworkReaper_RunSeq);
                }
            } else {
                if (Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PosOf(pTarget->m_unk3C, &pTarget->m_unk190)) < 10.0f && m_unk140 != ClockworkReaper_WalkForwardsSeq) {
                    Play(this, ClockworkReaper_WalkForwardsSeq);
                }
            }
            RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, PosOf(pTarget->m_unk3C, &pTarget->m_unk190)), 0.04f);
            float fD = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PosOf(pTarget->m_unk3C, &pTarget->m_unk190));
            m_unk214 = fD;
            if (fD <= 5.0f) {
                if (m_unk2BC != 0) {
                    m_unk2BC = m_unk2BC - 1;
                }
                if ((m_unk2BC == 0 || (int)pTarget->m_unk163 < 2) && pTarget->m_unk1C == 0) {
                    SetState__15EntityBaseClassFi(this, 6);
                }
            }
            break;
        }
        Copy128(m_unk290, PosOf(m_unk3C, &m_unk190));
        m_unk304 = 0;
        SetState__15EntityBaseClassFi(this, 0);
        return;
    }
    case 6: {
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_AttackSeq);
        }
        EntityBaseClass *pTarget = InstanceIsValid__15EntityBaseClassFUi(m_unk304);
        if (pTarget == 0) {
            Copy128(m_unk290, PosOf(m_unk3C, &m_unk190));
            m_unk304 = 0;
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
        RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, PosOf(pTarget->m_unk3C, &pTarget->m_unk190)), 0.04f);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x71U, 0x16U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x2B9U, 0x19U);
        if (m_unk160 == 0) {
            Play(this, ClockworkReaper_Idle1Seq);
            float fD = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)PosOf(m_unk3C, &m_unk190), (float (*)[4])PosOf(pTarget->m_unk3C, &pTarget->m_unk190));
            m_unk214 = fD;
            if (fD <= 5.0f) {
                if ((int)pTarget->m_unk163 < 2) {
                    if (pTarget->m_unk1C == 0) {
                        SetState__15EntityBaseClassFi(this, 6);
                    } else {
                        SetState__15EntityBaseClassFi(this, 5);
                    }
                } else {
                    SetState__15EntityBaseClassFi(this, 5);
                }
            } else {
                SetState__15EntityBaseClassFi(this, 5);
            }
        }
        break;
    }
    case 9:
        if (m_unkE9 != 0) {
            m_unk2B7 = 0;
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            m_unk10C &= 0xF8FFFFFF;
            ClearShadow(m_unkD4);
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            if (m_unk1FC == 0) {
                WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
            }
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
            if (m_unk224 & 0x40) {
                PlaySound__15EntityBaseClassFUi(this, 0x4E29U);
                Play(this, ClockworkReaper_DeadSeq);
                SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
            } else {
                switch (m_unk228) {
                default:
                    if (m_unk3C != 0) {
                        PMNode *pJoint = Find__6PMNodeFUi(m_unk3C, 0x72C7C29BU);
                        if (pJoint != 0) {
                            PosOf(m_unk3C, &m_unk190)[1] = ((float *)((char *)pJoint + 0x70))[1] - 2.7f;
                        }
                    }
                    Play(this, ClockworkReaper_DeadSeq);
                    SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
                    break;
                case 0x1:
                    m_unk24C = 1;
                    m_unk10C |= 0x02000000;
                    m_unk24D = 0;
                    m_unk250 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 3U, false);
                    Play(this, ClockworkReaper_DeathSplitSeq);
                    SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
                    m_unk2B7 = 1;
                    m_unk2F4 = mEffectAPI__13EntityManager.CreateOneshot(0x8100007FU, 0x820000FBU, (float (*)[4])PosOf(m_unk3C, &m_unk190), 0, 0, 0.5f, 0, 0, 0);
                    break;
                case 0x220:
                case 0x201:
                    Play(this, ClockworkReaper_VerticalDeath2Seq);
                    SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
                    break;
                case 0x20:
                case 0x25:
                case 0x3:
                    GetRenderPassIndex();
                    mEffectAPI__13EntityManager.CreateOneshot(0x8100007CU, 0x82000103U, (float (*)[4])PosOf(m_unk3C, &m_unk190), 0, 0, 0.5f, 0, 0, 0);
                    GetRenderPassIndex();
                    mEffectAPI__13EntityManager.CreateOneshot(0x8100007BU, 0x82000102U, (float (*)[4])PosOf(m_unk3C, &m_unk190), 0, 0, 0.5f, 0, 0, 0);
                    switch (m_unk1B0) {
                    case 0:
                        SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 1, 1);
                        break;
                    case 1:
                        SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 2, 2);
                        break;
                    case 2:
                        SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 4, 4);
                        break;
                    }
                    PlaySound__15EntityBaseClassFUi(this, 0x65U);
                    SetState__15EntityBaseClassFi(this, -2);
                    return;
                case 0xF:
                case 0x8:
                    Play(this, ClockworkReaper_UpwardStrikeDeathSeq);
                    SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
                    break;
                case 0x2:
                    Play(this, ClockworkReaper_StabDownDeathSeq);
                    SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
                    break;
                }
            }
            switch (m_unk1B0) {
            case 0:
                SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 1, 1);
                break;
            case 1:
                SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 2, 2);
                break;
            case 2:
                SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 4, 4);
                break;
            }
        }
        if (m_unk24D != 0) {
            m_unk10C &= 0xFEFFFFFF;
            m_unk24D = 0;
        }
        if (m_unk140 == ClockworkReaper_DeathSplitSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xF9U, 1U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x142U, 0x14U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x65U, 0x32U);
        }
        if (m_unk160 == 0) {
            if (m_unk2B7 != 0) {
                SetState__15EntityBaseClassFi(this, 0x24);
            } else {
                SetState__15EntityBaseClassFi(this, -2);
            }
        }
        break;
    case 0x24:
        if (m_unkE9 != 0) {
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            m_unk10C &= 0xF8FFFFFF;
            ClearShadow(m_unkD4);
            Play(this, ClockworkReaper_DeadSeq);
            SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    case 0xE:
        if (m_unkE9 != 0) {
            if (m_unk1FC == 0) {
                WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
            }
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
            Play(this, ClockworkReaper_StabDownDeathSeq);
            SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
            m_unk10C &= 0xF8FFFFFF;
            ClearShadow(m_unkD4);
            switch (m_unk1B0) {
            case 0:
                SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 1, 1);
                break;
            case 1:
                SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 2, 2);
                break;
            case 2:
                SpawnBonus__15EntityBaseClassFPfii(this, m_vBonusSpawnOffset, 4, 4);
                break;
            }
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    case 0x12:
        if (m_unkE9 != 0) {
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            Play(this, ClockworkReaper_DeadSeq);
            SetRenderPass__15EntityBaseClassFi(this, GetRenderPassIndex());
            mEffectAPI__13EntityManager.DeleteEffect(m_unk2F4);
            m_unk10C &= 0xF8FFFFFF;
            ClearShadow(m_unkD4);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    case 0x1C:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_AttackSeq);
            m_unk2EC = mEffectAPI__13EntityManager.CreateOneshot(0x81000081U, 0x820000FDU, 0, 0, 0, 0.5f, 0, 0, 0);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x71U, 0x16U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x2B9U, 0x19U);
        if (m_unk160 == 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x1B:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_OverheadAttackSeq);
            m_unk2EC = mEffectAPI__13EntityManager.CreateOneshot(0x81000084U, 0x82000124U, 0, 0, 0, 0.5f, 0, 0, 0);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xF1U, 0x16U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x66U, 0x37U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xF1U, 0x50U);
        if (m_unk160 == 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x1F:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_BlockSeq);
        }
        m_unk2C8 = (m_unk2C5 == 0) ? 0 : 0xA;
        if (m_unk2C5 != 0) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x10EU, 2U);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x20:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_BlockReactSeq);
        }
        if (m_unk2C8 == 0) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x10EU, 2U);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk160 == 0) {
            if (RandomIntRange__7MathAPIFii(1, 0x64) >= 0x29) {
                m_unk218 = 0;
                mTimerAPI__13EntityManager.KillTimer(m_unk220);
                m_unk220 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, RandomIntRange__7MathAPIFii(0, 2) + 4, false);
                switch (m_unk1B0) {
                case 0:
                    SetState__15EntityBaseClassFi(this, 0x1C);
                    break;
                case 1:
                    SetState__15EntityBaseClassFi(this, 0x1D);
                    break;
                case 2:
                    SetState__15EntityBaseClassFi(this, 0x25);
                    break;
                default:
                    CdsAssert("ClockworkReaper.cpp", 0x8A1, "\0");
                    break;
                }
                return;
            }
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x1D:
        if (m_unkE9 != 0) {
            m_unk2B5 = 0;
            Play(this, ClockworkReaper_VeteranDoubleComboSeq);
            m_unk2EC = mEffectAPI__13EntityManager.CreateOneshot(0x81000193U, 0x82000327U, 0, 0, 0, 0.5f, 0, 0, 0);
        }
        if (m_unk2B5 == 0) {
            if (!(GetFrameTime__6PMNodeFv(m_unk3C) < 30.0f)) {
                m_unk2B5 = 1;
                ResetCollisions__15EntityBaseClassFv(this);
                m_unk15C = 0x32;
                m_unk15E = 0;
            }
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x70U, 7U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x70U, 0x23U);
        if (m_unk160 == 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x1E:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_VeteranDashSeq);
        }
        if (GetFrameTime__6PMNodeFv(m_unk3C) < 30.0f) {
            FacePlayer__15EntityBaseClassFf(this, 0.04f);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x299U, 0x23U);
        if (m_unk160 == 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x21:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_VeteranDodgeSeq);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x66U, 6U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xF1U, 0x15U);
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x23:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_EliteThrowSpearSeq);
            m_unk2B9 = 0;
        }
        if (m_unk2B9 == 0) {
            if (!(GetFrameTime__6PMNodeFv(m_unk3C) < 24.0f)) {
                PlaySound__15EntityBaseClassFUi(this, 0xDEU);
                ZinShell *pSpear = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x69U, false, 0);
                if (pSpear == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0x90B, "pSpearEnt");
                }
                m_unk2B9 = 1;
                PMNode *pHand = Find__6PMNodeFUi(m_unk3C, 0xC7701CB0U);
                if (pHand == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0x911, "pHandJoint");
                }
                if (pSpear->m_unk3C != 0) {
                    Copy128((char *)pSpear->m_unk3C + 0x80, (char *)pHand + 0x70);
                    pSpear->m_unk3C->m_unk3E = pSpear->m_unk3C->m_unk3E | 8;
                } else {
                    Copy128(&pSpear->m_unk190, (char *)pHand + 0x70);
                }
                if (pSpear->m_unk3C != 0) {
                    Copy128((char *)pSpear->m_unk3C + 0x90, QuatOf(m_unk3C, &m_unk1A0));
                    pSpear->m_unk3C->m_unk3E = pSpear->m_unk3C->m_unk3E | 8;
                } else {
                    Copy128(&pSpear->m_unk1A0, QuatOf(m_unk3C, &m_unk1A0));
                }
            }
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk160 == 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x22:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_BlockSeq);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.04f);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x25:
        if (m_unkE9 != 0) {
            Play(this, ClockworkReaper_AttackSeq);
            m_unk2EC = mEffectAPI__13EntityManager.CreateOneshot(0x81000081U, 0x820000FDU, 0, 0, 0, 0.5f, 0, 0, 0);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x71U, 0x16U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x2B9U, 0x19U);
        if (m_unk160 == 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case 0x26:
        if (m_unkE9 != 0) {
            m_unk2B5 = 0;
            Play(this, ClockworkReaper_VeteranDoubleComboSeq);
            m_unk2EC = mEffectAPI__13EntityManager.CreateOneshot(0x81000193U, 0x82000327U, 0, 0, 0, 0.5f, 0, 0, 0);
        }
        if (m_unk2B5 == 0) {
            if (!(GetFrameTime__6PMNodeFv(m_unk3C) < 30.0f)) {
                m_unk2B5 = 1;
                ResetCollisions__15EntityBaseClassFv(this);
                m_unk15C = 0x32;
                m_unk15E = 0;
            }
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x70U, 7U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x70U, 0x23U);
        if (m_unk160 == 0) {
            RemoveFromAttackSystem__15EntityBaseClassFv(this);
            SetState__15EntityBaseClassFi(this, 0x15);
        }
        break;
    case -2:
        if (m_unkE9 != 0 && m_unk1FC != 0) {
            ZinShell *pKey = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 8U, false, 0);
            if (pKey == 0) {
                CdsAssert("ClockworkReaper.cpp", 0x96F, "pKey");
            }
            Copy128(vSpawn, PosOf(m_unk3C, &m_unk190));
            vSpawn[1] += 2.0f;
            if (pKey->m_unk3C != 0) {
                Copy128((char *)pKey->m_unk3C + 0x80, vSpawn);
                pKey->m_unk3C->m_unk3E = pKey->m_unk3C->m_unk3E | 8;
            } else {
                Copy128(&pKey->m_unk190, vSpawn);
            }
            pKey->m_unk1B0 = m_unk1FC;
            pKey->m_unk1B4 = 0;
            pKey->m_unk1CC = 0x5A;
            pKey->m_unk1C4 = m_unk4;
        }
        break;
    }

    if (state >= 0 && m_unk255 != 0 && m_unk208 > 0) {
        int nBlock = CheckBlockAttack();
        if (nBlock != 0) {
            m_unk38->m_unkEC = 0x80113FD5;
            SetState__15EntityBaseClassFi(this, nBlock);
        } else {
            int nAttack = CheckAttackPlayer();
            if (nAttack != 0) {
                m_unk38->m_unkEC = 0x80113FD5;
                SetState__15EntityBaseClassFi(this, nAttack);
            }
        }
        if (m_unk2C4 != 0) {
            CheckOnWakeTasks();
        }
        if (m_unk2C8 != 0) {
            m_unk2C8 = m_unk2C8 - 1;
        }
        Physics *pPhys = m_unk38;
        if (pPhys != 0 && (pPhys->m_unk108 & 0x400)) {
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
            if (m_unk38 != 0) {
                delete m_unk38;
            }
            m_unk38 = 0;
            m_unk10C &= 0xFDFFFFFF;
            EnableSleep__15EntityBaseClassFbb(this, false, false);
            m_unk208 = 0;
            SetState__15EntityBaseClassFi(this, 0x24);
            return;
        }
        if (m_unk2E5 != 0 && m_unk20 != 0x24 && pPhys != 0 && m_unk1FC == 0 && m_unk204 != 0) {
            unsigned char nFlag = m_unk2E4;
            if (nFlag != 0 && (pPhys->m_unk108 & 1)) {
                WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
                if (m_unk38 != 0) {
                    delete m_unk38;
                }
                m_unk38 = 0;
                m_unk10C &= 0xFDFFFFFF;
                EnableSleep__15EntityBaseClassFbb(this, false, false);
                m_unk208 = 0;
                SetState__15EntityBaseClassFi(this, 0x24);
                return;
            }
            if (nFlag == 0 && !(pPhys->m_unk108 & 1)) {
                if (pPhys != 0 && ((float *)&pPhys->m_unk0)[1] < -1.0f) {
                    m_unk2E4 = 1;
                }
            }
        }
    }
}

// FUNCTION: 0x001C4A60 __dt__15ClockworkReaperFv
extern "C" ClockworkReaper *__dt__15ClockworkReaperFv(ClockworkReaper *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__15ClockworkReaper;
        DestroyDamageFx__15EntityBaseClassFUi(pThis, pThis->m_unk2F8);
        pThis->m_unk2F8 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001C4AD0 __ct__15ClockworkReaperFv
ClockworkReaper::ClockworkReaper() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 0);
    *(unsigned char **)this = __vt__15ClockworkReaper;
    m_unk208 = 0;
    *(int *)((char *)this + 0x20C) = 0;
    m_unk210 = 0;
    *(int *)((char *)this + 0x214) = 0;
    m_unk218 = 0;
    *(int *)((char *)this + 0x21C) = 0;
    m_unk220 = 0;
    *(int *)((char *)this + 0x224) = 0;
    *(int *)((char *)this + 0x228) = 0;
    *(int *)((char *)this + 0x22C) = 0;
    *(int *)((char *)this + 0x230) = 0;
    *(unsigned char *)((char *)this + 0x234) = 0;
    *(unsigned char *)((char *)this + 0x235) = 0;
    *(int *)((char *)this + 0x238) = 0;
    *(int *)((char *)this + 0x23C) = 0;
    m_unk240 = 0;
    *(int *)((char *)this + 0x244) = 0;
    *(int *)((char *)this + 0x248) = 0;
    *(unsigned char *)((char *)this + 0x24C) = 0;
    m_unk24D = 0;
    m_unk250 = 0;
    *(unsigned char *)((char *)this + 0x254) = 0;
    *(unsigned char *)((char *)this + 0x255) = 0;
    *(int *)((char *)this + 0x258) = 0;
    *(int *)((char *)this + 0x25C) = 0;
    *(int *)((char *)this + 0x260) = 0;
    *(int *)((char *)this + 0x264) = 0;
    *(int *)((char *)this + 0x268) = 0;
    *(int *)((char *)this + 0x26C) = 0;
    *(int *)((char *)this + 0x270) = 0;
    *(int *)((char *)this + 0x274) = 0;
    *(unsigned char *)((char *)this + 0x278) = 0;
    *(int *)((char *)this + 0x280) = 0;
    *(int *)((char *)this + 0x284) = 0;
    *(int *)((char *)this + 0x288) = 0;
    *(int *)((char *)this + 0x28C) = 0;
    *(int *)((char *)this + 0x290) = 0;
    *(int *)((char *)this + 0x294) = 0;
    *(int *)((char *)this + 0x298) = 0;
    *(int *)((char *)this + 0x29C) = 0;
    *(int *)((char *)this + 0x2A0) = 0;
    *(int *)((char *)this + 0x2A4) = 0;
    *(int *)((char *)this + 0x2A8) = 0;
    *(int *)((char *)this + 0x2AC) = 0;
    *(int *)((char *)this + 0x2B0) = 0;
    *(unsigned char *)((char *)this + 0x2B4) = 0;
    *(unsigned char *)((char *)this + 0x2B5) = 0;
    m_unk2B6 = 0;
    *(unsigned char *)((char *)this + 0x2B7) = 0;
    m_unk2B8 = 0;
    *(unsigned char *)((char *)this + 0x2B9) = 0;
    *(unsigned char *)((char *)this + 0x2BA) = 0;
    *(int *)((char *)this + 0x2BC) = 0;
    *(int *)((char *)this + 0x2C0) = 0;
    m_unk2C4 = 0;
    *(unsigned char *)((char *)this + 0x2C5) = 0;
    *(int *)((char *)this + 0x2C8) = 0;
    *(int *)((char *)this + 0x2D0) = 0;
    *(int *)((char *)this + 0x2D4) = 0;
    *(int *)((char *)this + 0x2D8) = 0;
    *(int *)((char *)this + 0x2DC) = 0;
    m_unk2E0 = 0;
    *(unsigned short *)((char *)this + 0x2E2) = 0;
    *(unsigned char *)((char *)this + 0x2E4) = 0;
    *(unsigned char *)((char *)this + 0x2E5) = 0;
    *(unsigned char *)((char *)this + 0x2E6) = 0;
    *(unsigned char *)((char *)this + 0x2E7) = 1;
    m_unk2E8 = 0;
    m_unk2EC = 0;
    m_unk2F0 = 0;
    *(int *)((char *)this + 0x2F4) = 0;
    m_unk2F8 = 0;
    *(unsigned char *)((char *)this + 0x2FC) = 0;
    *(unsigned char *)((char *)this + 0x2FD) = 1;
    m_unk2FE = 0;
    m_unk300 = 0;
    *(int *)((char *)this + 0x304) = 0;
    *(int *)((char *)this + 0x308) = 0;
    *(int *)((char *)this + 0xE4) = 0x3F800000;
    *(unsigned char *)((char *)this + 0x166) = 1;
}
