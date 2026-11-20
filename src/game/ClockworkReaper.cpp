// FLAGS: -str readonly
#include "ClockworkReaper.h"
#include "types.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    void SequenceViewer(unsigned int **arg0, int arg1);
};

static unsigned int *SequenceTable[32];

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
};

extern EffectAPI mEffectAPI__13EntityManager;
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern void *mpEntMgr__15EntityBaseClass;
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *, float *);
extern "C" float Round180__Ff(float);
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
    char _pad008[0x10 - 0x08];
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
                    CdsAssert("ClockworkReaper.cpp", 0xBE4, "pNode");
                }
                PMNode *found = Find__6PMNodeFUi(node, 0x8EA3DD30U);
                if (found == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0xBE7, "pEffect");
                }
                PMNode *res = GetResource__16PResourceManagerFUib(mpResMgr__15EntityBaseClass, 0x81000197U, true);
                if (res == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0xBEA, "pResource");
                }
                PMNode *found2 = Find__6PMNodeFUi(res, 0x8EA3DD30U);
                if (found2 == 0) {
                    CdsAssert("ClockworkReaper.cpp", 0xBED, "pSource");
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
