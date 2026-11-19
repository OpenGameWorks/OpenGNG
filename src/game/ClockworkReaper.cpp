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
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
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
    char _pad000[0x3F];
    signed char m_unk3F;
};
extern "C" float GetFrameTime__6PMNodeFv(PMNode *);
extern "C" void AddFxTrigger__6PMNodeFP20tagParticleFxTriggerb(PMNode *, tagParticleFxTrigger *, bool);

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

// DRAFT: 0x001C02F0 CanAttackInState__15ClockworkReaperFv
// note: 2 differing lines: range test is sltiu into v0, original uses at (same as InBlockableState); split-range form gave 13, early returns 17.
int ClockworkReaper::CanAttackInState() {
    if (m_unk20 == 0 || m_unk20 == 3 || (unsigned int)(m_unk20 - 0x15) < 7U || m_unk20 == 0x1C) {
        return 1;
    }
    return 0;
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
