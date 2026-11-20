// FLAGS: -str readonly
#include "ClockworkReaper.h"
#include "types.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    void SequenceViewer(unsigned int **arg0, int arg1);
    char _pad000[8];
    int m_unk8;
    char _pad00C[0x3C - 0xC];
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

// DRAFT: 0x001BF910 GetRenderPassIndex__15ClockworkReaperFv
// note: 14 differing lines; switch with case 0 and nested if/else tried, branch shape and lw order still differ.
int ClockworkReaper::GetRenderPassIndex() {
    if (m_unk1B0 == 2) {
        return 2;
    }
    if (m_unk1B0 == 1) {
        return 1;
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

// DRAFT: 0x001BF9C0 InBlockableState__15ClockworkReaperFv
// note: 2 differing lines: range test is sltiu into v0, original uses at (sltiu at,v0,N; bnez at); early-return, ternary and operand-swap forms tried.
int ClockworkReaper::InBlockableState() {
    if ((unsigned int)(m_unk20 - 0x15) < 5U || m_unk20 == 4) {
        return 1;
    }
    return 0;
}

// DRAFT: 0x001BF9F0 CheckBlockAttack__15ClockworkReaperFv
// note: 80 words differ: original frame is 0x30 (saves s0,s1 only) with player in s0 and this in s1, no result register; ours keeps result in s0 and this in s2 (0x40 frame). Tried: early-return per exit (82), &&-chain with early return (84), shared exit with result var (80, current).
int ClockworkReaper::CheckBlockAttack() {
    int result = 0;
    MathAPI *player = mPlayerAPI__13EntityManager;
    if (player == 0) {
        CdsAssert("ClockworkReaper.cpp", 0xD25, "pPlayer");
    }
    if (m_unkF4 == 0 && m_unk208 > 0 && player->m_unk23D2 != 0 && player->m_unk15E != 0xD &&
        player->m_unk1CC == m_unk4 && InBlockableState() != 0) {
        char *selfTarget = m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190;
        char *playerTarget = player->m_unk3C ? player->m_unk3C + 0x80 : (char *)player + 0x190;
        float dist = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)playerTarget, (float (*)[4])selfTarget);
        if (dist <= 20.0f) {
            int roll = RandomIntRange__7MathAPIFii(1, 100);
            if (roll < 6) {
                switch (m_unk1B0) {
                case 0:
                    m_unk2C5 = (m_unk20 == 4);
                    result = 0x1F;
                    break;
                case 1:
                    m_unk2C8 = 0;
                    result = 0x21;
                    break;
                case 2:
                    m_unk2C5 = (m_unk20 == 4);
                    result = (m_unk2C5 == 0) ? 0x22 : 0x1F;
                    break;
                }
            }
        }
    }
    return result;
}

// DRAFT: 0x001BFB90 FaceHit__15ClockworkReaperFv
// note: 39 words; mode-chain blocks inline, original places 4316/C316 out of line with beq (tried switch, if-chain, else-if, 0x10 wrap, 0xE/0x7 inversions).
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
        if (mode != 0x8200000E) {
            if (mode != 0x82000007) {
                f0 = 180.0f;
            } else {
                f0 = 150.0f;
            }
        } else {
            f0 = -150.0f;
        }
        char *dst;
        if (m_unk3C != 0) {
            dst = (char *)m_unk3C + 0x90;
        } else {
            dst = (char *)this + 0x1A0;
        }
        f1 = f1 - f0;
        *(float *)(dst + 4) = f1;
        if (m_unk38 != 0) {
            char *s2;
            if (m_unk3C != 0) {
                s2 = (char *)m_unk3C + 0x90;
            } else {
                s2 = (char *)this + 0x1A0;
            }
            *(float *)((char *)m_unk38 + 0x11C) = Round180__Ff(*(float *)(s2 + 4));
        }
    }
}

// DRAFT: 0x001BFCA0 Stalled__15ClockworkReaperFf
// note: 13 differing words, all in the return tail (extra b and dead daddu before epilogue); tried result-var, inverted >=, ternary, explicit else: 26, 15, 13, 13.
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
        return 0;
    }
    return 0;
}

// DRAFT: 0x001BFD90 CheckAttackPlayer__15ClockworkReaperFv
// note: 208 words, size 0x56C vs 0x55C; mode dispatch branch shape, 0x30/0x3C targets, Distance arg branch sense, extra RandomIntRange reloc at 0x41C; tried plain returns (325), dispatch reorder (317), flipped Distance null test (212)
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

// DRAFT: 0x001C02F0 CanAttackInState__15ClockworkReaperFv
// note: 2 differing lines: range test is sltiu into v0, original uses at (same as InBlockableState); split-range form gave 13, early returns 17.
int ClockworkReaper::CanAttackInState() {
    if (m_unk20 == 0 || m_unk20 == 3 || (unsigned int)(m_unk20 - 0x15) < 7U || m_unk20 == 0x1C) {
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
        sprintf(buf, "Anim Frame = %f\n", fptodp(GetFrameTime__6PMNodeFv(node)));
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

// DRAFT: 0x001C0A70 SetEditableVars__15ClockworkReaperFPc
// note: 23 differing lines; the original keeps a lui/addiu address-vs-0 test on the message literal (sltu/xori/bnez), ours folds it away; local msg pointer variant gave 25 lines.
void ClockworkReaper::SetEditableVars(char *arg0) {
    memcpy(&m_unk1B0, arg0, 0x58);
    SetupHealth();
    int key = m_unk1FC;
    if (key != 8 && key != 7 && key != 0 && "Invalid m_iSpawnsKey in Reaper\n") {
        CdsAssert("ClockworkReaper.cpp", 0xAFA, "!\"Invalid m_iSpawnsKey in Reaper\\n\"");
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
// note: DIFF 455 words, size 0x73c vs 0x750; frame 0x90 vs 0xA0 with f20 (20.0f, hoisted in original) not spilled; per-path returns and store order differ; tried /2.0f to *0.5f (457 to 455).
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
