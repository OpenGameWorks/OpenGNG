// FLAGS: -str readonly
#include "ClockworkPuncher.h"

// TODO(header): foreign declarations
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void PlaySound__15EntityBaseClassFUi(void *, unsigned int);

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
};
extern TimerAPI mTimerAPI__13EntityManager;

class EffectAPI {
public:
    char _pad000[20];
    void DeleteEffect(unsigned int);
};
extern EffectAPI mEffectAPI__13EntityManager;
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

// DRAFT: 0x001DE4A0 AttachSparkEffect__16ClockworkPuncherFv
// note: 1.56f is pooled (lwc1 from gp) but the original builds 0x3FC7AE14 with lui/ori/mtc1; the bit-cast variant spills to the stack; RandomFloatRange argument registers are swapped (v0/v1 order); 31 differing lines.
void ClockworkPuncher::AttachSparkEffect() {
    float vec[4];

    if (m_unk2B4 != 0) {
        if (m_unk2B4 == 0) {
            CdsAssert__FPciPc("ClockworkPuncher.cpp", 0xA46, "m_pBackjoint");
        }
        m_unk2B4->DestroyFxTriggers(false, true, false);
    }
    char *pSelf = m_unk3C != 0 ? m_unk3C + 0x80 : (char *)this + 0x190;
    char *pPlayerAlt = *(char **)((char *)mPlayerAPI__13EntityManager + 0x3C);
    char *pPlayer = (char *)mPlayerAPI__13EntityManager;
    sceVu0SubVector(vec, (float *)(pPlayerAlt != 0 ? pPlayerAlt + 0x80 : pPlayer + 0x190), (float *)pSelf);
    sceVu0Normalize(vec, vec);
    sceVu0ScaleVector(vec, vec, 1.56f);
    MathAPI::VectorRotateY((float (*)[4])vec, MathAPI::RandomFloatRange(-90.0f, 90.0f));
    if (m_unk2B4 != 0) {
        AttachDamageEffect(m_unk2B4, 0x8300015A, vec[0], vec[1], vec[2]);
        PlaySound__15EntityBaseClassFUi((void *)this, 0x100);
    }
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
        CdsAssert__FPciPc("ClockworkPuncher.cpp", 0x93E, "pPlayer");
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
