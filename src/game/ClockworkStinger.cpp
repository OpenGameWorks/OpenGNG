#include "types.h"
#include "Debug.h"
#include "ClockworkStinger.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern char ClockworkStinger_HitSpinSeq[];
extern char ClockworkStinger_HitFlippedSeq[];
extern char ClockworkStinger_StruggleUpSeq[];
extern char ClockworkStinger_HitLaunchSeq[];
extern char ClockworkStinger_HitJuggleSeq[];
extern char ClockworkStinger_HitJuggleFinalSeq[];
class TimerAPI {
public:
    char _pad000[40];
    void KillTimer(unsigned int);
    int CreateTimer(unsigned int, unsigned int, bool);
};
extern TimerAPI mTimerAPI__13EntityManager;
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *, int, char, unsigned int);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern unsigned char __vt__16ClockworkStinger[];
extern int miRandom__7MathAPI;
extern "C" void *memcpy(void *, const void *, unsigned int);
class MathAPI;
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern char *mPlayerAPI__13EntityManager;
extern "C" float Distance__7MathAPIFPA4_fPA4_f(void *, void *);
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern "C" int RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(void *, void *, unsigned int);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *, float *);
extern "C" float GetAngleBetweenVectors__7MathAPIFPfPf(float *, float *);
extern "C" void PlaySound__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float t);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void StopSoundBySoundRef__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void RemoveFromAttackSystem__15EntityBaseClassFv(void *);
extern "C" unsigned int CreateDamageFx__15EntityBaseClassFfUi(void *, float, unsigned int);
extern "C" void ChangeDamageFxInterval__15EntityBaseClassFUif(void *, unsigned int, float);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *, int, unsigned int);
extern "C" void *__ct__7PhysicsFv(void *);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *, unsigned int, float (*)[4]);

// Target point of a stinger or of the player: the PMNode animation vector at +0x80 when the node exists, else the base's own vector at +0x190.
#define CS_TARGET(pb) (*(char **)((char *)(pb) + 0x3C) ? *(char **)((char *)(pb) + 0x3C) + 0x80 : (char *)(pb) + 0x190)
#define CS_ASSERT(line, cond, msg) ((cond) ? (void)0 : CdsAssert("ClockworkStinger.cpp", line, msg))
// FUNCTION: 0x001E6480 GetHealth__16ClockworkStingerFv
int ClockworkStinger::GetHealth() {
    return m_unk1FC;
}

// FUNCTION: 0x001E6490 GetTallyType__16ClockworkStingerFv
int ClockworkStinger::GetTallyType() {
    return 1;
}

// FUNCTION: 0x001E64A0 GetClassName__16ClockworkStingerFv
const char *ClockworkStinger::GetClassName() {
    return "ClockworkStinger";
}

// FUNCTION: 0x001E64B0 GetArenaWaveID__16ClockworkStingerFv
int ClockworkStinger::GetArenaWaveID() {
    return m_unk1D8;
}

// FUNCTION: 0x001E64C0 IsArenaApparition__16ClockworkStingerFv
bool ClockworkStinger::IsArenaApparition() {
    return m_unk1D8 ? true : false;
}

// FUNCTION: 0x001E64D0 NeedsToBeWoken__16ClockworkStingerFv
int ClockworkStinger::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x1DC);
}

// FUNCTION: 0x001E64E0 GetWokenVarPos__16ClockworkStingerFv
int ClockworkStinger::GetWokenVarPos() {
    return 5;
}

// FUNCTION: 0x001E64F0 SetInnocentInstanceID__16ClockworkStingerFUi
void ClockworkStinger::SetInnocentInstanceID(unsigned int value) {
    m_unk24C = (int)value;
}

// FUNCTION: 0x001E6500 GetSequenceState__16ClockworkStingerFv
int ClockworkStinger::GetSequenceState() {
    int result = 0;
    if (m_unk140 == (unsigned int *)ClockworkStinger_HitSpinSeq ||
        m_unk140 == (unsigned int *)ClockworkStinger_HitFlippedSeq ||
        (m_unk140 == (unsigned int *)ClockworkStinger_StruggleUpSeq && m_unk3C->GetFrameTime() <= 12.0f) ||
        (m_unk140 == (unsigned int *)ClockworkStinger_HitLaunchSeq && !(m_unk3C->GetFrameTime() < 28.0f)) ||
        (m_unk140 == (unsigned int *)ClockworkStinger_HitJuggleSeq && !(m_unk3C->GetFrameTime() < 18.0f)) ||
        (m_unk140 == (unsigned int *)ClockworkStinger_HitJuggleFinalSeq && !(m_unk3C->GetFrameTime() < 28.0f))) {
        result |= 1;
    }
    if ((m_unk140 == (unsigned int *)ClockworkStinger_HitLaunchSeq && m_unk3C->GetFrameTime() <= 27.0f &&
         !(m_unk3C->GetFrameTime() < 2.0f)) ||
        (m_unk140 == (unsigned int *)ClockworkStinger_HitJuggleSeq && m_unk3C->GetFrameTime() <= 17.0f)) {
        result |= 2;
    }
    return result;
}

// FUNCTION: 0x001E66D0 IsStalled__16ClockworkStingerFfPA4_f
int ClockworkStinger::IsStalled(float arg0, float (*arg1)[4]) {
    MathAPI *pRef;
    float d1;
    float d2;
    if (m_unk3C != 0) {
        pRef = (MathAPI *)((char *)m_unk3C + 0x80);
    } else {
        pRef = (MathAPI *)((char *)this + 0x190);
    }
    d1 = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)((char *)this + 0x220), arg1);
    d2 = DistanceXZ__7MathAPIFPA4_fPA4_f(pRef, arg1);
    return (FastMath_Fabs__Ff(d1 - d2) <= arg0) ? 1 : 0;
}

// DRAFT: 0x001E6760 MoveTo__16ClockworkStingerFPA4_f
// note: first compile, branch layout and store order not yet compared
int ClockworkStinger::MoveTo(float (*arg0)[4]) {
    float sp50[4];
    float sp60[4];
    float sp70[4];
    float sp80[4];
    int s0;
    char *s1;
    char *pr;
    float f20;
    float f21;

    s0 = 0;
    *(u_long128 *)sp50 = *(u_long128 *)arg0;
    s1 = *(char **)(*(char **)((char *)this + 0x38) + 0xE4);
    pr = m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190;
    f20 = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)sp50, (float (*)[4])pr);
    if ((m_unk1B0 == 0 || m_unk244 != 1) && !(Distance__7MathAPIFPA4_fPA4_f((char *)this + 0x200, sp50) <= m_unk1D4)) {
        sceVu0SubVector(sp50, sp50, (float *)((char *)this + 0x200));
        sceVu0Normalize(sp50, sp50);
        sceVu0ScaleVector(sp50, sp50, m_unk1D4);
        sceVu0AddVector(sp50, (float *)((char *)this + 0x200), sp50);
    }
    if (s1 != 0) {
        *(u_long128 *)sp80 = *(u_long128 *)(s1 + 0x10);
        GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, sp60);
        pr = m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190;
        sceVu0SubVector(sp70, sp50, (float *)pr);
        sceVu0Normalize(sp60, sp60);
        sceVu0Normalize(sp80, sp80);
        f21 = GetAngleBetweenVectors__7MathAPIFPfPf(sp80, sp60);
        if (!(GetAngleBetweenVectors__7MathAPIFPfPf(sp80, sp70) <= 90.0f) && !(f21 <= 120.0f)) {
            s0 = (s1[0xC] & 0x80) ? 8 : 4;
        }
    }
    RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, sp50), 0.06f);
    if ((*(unsigned char *)((char *)m_unk3C + 0x3F)) & 4) {
        PlaySound__15EntityBaseClassFUi(this, 0x4E32);
        if (IsStalled(1.0f, (float (*)[4])sp50) != 0) {
            s0 |= 1;
        }
        pr = m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190;
        *(u_long128 *)((char *)this + 0x220) = *(u_long128 *)pr;
    }
    return s0 | ((f20 <= 1.0f) ? 2 : 0);
}

// DRAFT: 0x001E69C0 DetermineStateChange__16ClockworkStingerFv
// note: DIFF 36; gp displacement for mPlayerAPI+0x3C, join offsets in ladders, angle block and epilogue order; tried if/else angle block, ternary angle block, reordered tests
void ClockworkStinger::DetermineStateChange() {
    float f20;
    float f21;
    float angle;
    PMNode *pn;
    PMNode *tn;
    char *pr;
    char *tr;
    int s0;

    s0 = 3;
    pn = *(PMNode **)(mPlayerAPI__13EntityManager + 0x3C);
    pr = pn ? (char *)pn + 0x80 : mPlayerAPI__13EntityManager + 0x190;
    f20 = Distance__7MathAPIFPA4_fPA4_f((char *)this + 0x200, pr);
    pn = *(PMNode **)(mPlayerAPI__13EntityManager + 0x3C);
    pr = pn ? (char *)pn + 0x80 : mPlayerAPI__13EntityManager + 0x190;
    tn = m_unk3C;
    tr = tn ? (char *)tn + 0x80 : (char *)this + 0x190;
    f21 = Distance__7MathAPIFPA4_fPA4_f(tr, pr);
    if (m_unk1B0 == 0) {
        if (m_unk240 == 0) {
            if (f21 <= 5.0f && m_unk258 == 0 && RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, mPlayerAPI__13EntityManager, 0) != 0) {
                s0 = 9;
            } else if (f20 <= m_unk1D4) {
                s0 = 7;
            } else if (f21 <= 30.0f) {
                s0 = 4;
            }
        } else {
            if (f20 <= m_unk1D4) {
                s0 = 6;
            } else if (f21 <= 30.0f) {
                s0 = 4;
            }
        }
    } else {
        pn = *(PMNode **)(mPlayerAPI__13EntityManager + 0x3C);
        pr = pn ? (char *)pn + 0x80 : mPlayerAPI__13EntityManager + 0x190;
        angle = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pr);
        if (f21 <= 15.0f) {
            s0 = 4;
            if (FastMath_Fabs__Ff(angle) <= 55.0f) {
                s0 = 8;
            }
        }
    }
    if (s0 != m_unk20) {
        SetState__15EntityBaseClassFi(this, s0);
    }
}

// FUNCTION: 0x001E6BA0 SetRiseAndAttack__16ClockworkStingerFPA4_fff
void ClockworkStinger::SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2) {
    m_unk1B8 = arg0[0][0];
    m_unk1BC = arg0[0][1];
    m_unk1C0 = arg0[0][2];
    m_unk1C8 = arg0[0][0];
    m_unk1CC = arg0[0][1];
    m_unk1D0 = arg0[0][2];
    m_unk1C4 = arg1;
    m_unk1D4 = arg2;
}

// FUNCTION: 0x001E6BE0 SetSpawnedFromEntity__16ClockworkStingerFPfPfi
void ClockworkStinger::SetSpawnedFromEntity(float *arg0, float *arg1, int arg2) {
    char *pDst;
    m_unk1C8 = arg0[0];
    m_unk1CC = arg0[1];
    m_unk1D0 = arg0[2];
    *(int *)&m_unk1D4 = 0x43160000;
    miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
    m_unk1FC = !(miRandom__7MathAPI & 1) ? 0xB4 : 0x6E;
    *(int *)&m_unk1C4 = 0x42960000;
    m_unk1B0 = 0;
    m_unk1E0 = 0;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1D8 = 0;
    *(int *)&m_unk1F8 = 0x3DCCCCCD;
    m_unk1F4 = 0;
    if (m_unk3C != 0) {
        pDst = (char *)m_unk3C + 0x80;
    } else {
        pDst = (char *)this + 0x190;
    }
    *(u_long128 *)pDst = *(u_long128 *)arg0;
    if (arg1 != 0) {
        if (m_unk3C != 0) {
            pDst = (char *)m_unk3C + 0x90;
        } else {
            pDst = (char *)this + 0x1A0;
        }
        *(u_long128 *)pDst = *(u_long128 *)arg1;
    }
}

// FUNCTION: 0x001E6CB0 SetDefaultVars__16ClockworkStingerFv
void ClockworkStinger::SetDefaultVars() {
    miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
    m_unk1FC = !(miRandom__7MathAPI & 1) ? 0xB4 : 0x6E;
    *(int *)&m_unk1C4 = 0x41C80000;
    *(int *)&m_unk1D4 = 0x420C0000;
    m_unk1B0 = 0;
    m_unk1E0 = 0;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1D8 = 0;
    m_unk1F8 = 0x3DCCCCCD;
    m_unk1F4 = 0;
}

// FUNCTION: 0x001E6D30 SetEditableVars__16ClockworkStingerFPc
void ClockworkStinger::SetEditableVars(char *arg0) {
    memcpy(&m_unk1B0, arg0, 0x4C);
    if (m_unk1B0 == 0) {
        miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
        m_unk1FC = !(miRandom__7MathAPI & 1) ? 0xB4 : 0x6E;
    } else {
        miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
        m_unk1FC = !(miRandom__7MathAPI & 1) ? 0x78 : 0x64;
    }
}

// FUNCTION: 0x001E6DE0 OnStopAttack__16ClockworkStingerFv
void ClockworkStinger::OnStopAttack() {
    if ((m_unk1B0 == 0) && (m_unk20 != 4)) {
        m_unk258 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 2, false);
        SetState__15EntityBaseClassFi(this, 4);
    }
}

// FUNCTION: 0x001E6E40 OnTimerEvent__16ClockworkStingerFUi
void ClockworkStinger::OnTimerEvent(unsigned int arg0) {
    if (arg0 == (unsigned int)m_unk240) {
        m_unk240 = 0;
        return;
    }
    if (arg0 == (unsigned int)m_unk254) {
        m_unk254 = 0;
        return;
    }
    if (arg0 == (unsigned int)m_unk258) {
        m_unk258 = 0;
    }
}

// FUNCTION: 0x001E6E80 OnEffectDelete__16ClockworkStingerFUi
void ClockworkStinger::OnEffectDelete(unsigned int arg0) {
    if (arg0 == (unsigned int)m_unk264) {
        m_unk25C = 1;
        m_unk264 = 0;
    }
}

// DRAFT: 0x001E6EA0 OnHitEvent__16ClockworkStingerFP15EntityBaseClassiUiUi
// note: this/arg0 land in s3/s2 (original s2/s3), 150 words; tried declaration order and local alias (both worse); body is 0x2A8 vs 0x280
int ClockworkStinger::OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int s0;
    int a1;
    PMNode *pn;
    char *pr;
    float *p3;

    s0 = arg2;
    if (m_unk20 == 0xF) {
        return 0;
    }
    if (m_unk260 != 0) {
        StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk260);
    }
    m_unk260 = 0;
    if (*(int *)((char *)arg0 + 8) == 0x37) {
        if (m_unk1B0 == 1) {
            if (m_unkF4 != 0) {
                SetState__15EntityBaseClassFi(this, 0xF);
            }
            return 2;
        }
        if (m_unk244 == 2) {
            SetState__15EntityBaseClassFi(this, 0xA);
            return 2;
        }
    }
    RemoveFromAttackSystem__15EntityBaseClassFv(this);
    if (m_unkF4 != 0) {
        int t = m_unk1FC - arg1;
        if (t > 0) {
            m_unk1FC = t;
        }
        return 1;
    }
    m_unk23C = arg2;
    pn = *(PMNode **)(mPlayerAPI__13EntityManager + 0x3C);
    pr = pn ? (char *)pn + 0x80 : mPlayerAPI__13EntityManager + 0x190;
    p3 = (float *)(m_unk3C ? (char *)m_unk3C + 0x90 : (char *)this + 0x1A0);
    p3[1] = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pr);
    *(unsigned int *)((char *)m_unk38 + 0x118) = 0;
    if (((ClockworkStinger *)m_unk38)->GetSequenceState() == 0) {
        arg1 -= 0x1E;
        if (arg1 < 0) {
            arg1 = 0;
        }
    }
    m_unk1FC -= arg1;
    if (m_unk1FC < 0x46) {
        if (m_unk250 == 0) {
            m_unk250 = CreateDamageFx__15EntityBaseClassFfUi(this, 60.0f, 0);
        }
    }
    if (m_unk1FC < 0x19) {
        if (m_unk250 != 0) {
            ChangeDamageFxInterval__15EntityBaseClassFUif(this, m_unk250, 15.0f);
        }
    }
    PlaySound__15EntityBaseClassFUi(this, 0x12A);
    if (m_unk1FC > 0) {
        s0 = 1;
        a1 = 0xC;
    } else {
        a1 = 0xC;
        if ((s0 & -0x5C1) == 0xF) {
            a1 = 0xE;
            s0 = 2;
        } else if ((s0 & 0x48) == 0x48) {
            a1 = 0xE;
            s0 = 2;
        } else if (m_unk254 != 0) {
            a1 = 0xF;
            s0 = 2;
        } else if (m_unk1B0 == 1) {
            a1 = (m_unk244 == 1 || m_unk244 == 2) ? 0xF : 0xE;
            s0 = 2;
        } else {
            a1 = 0xE;
            s0 = 2;
        }
    }
    if (m_unk1B0 == 1 && m_unk244 == 2) {
        s0 = 2;
        a1 = 0xF;
    }
    SetState__15EntityBaseClassFi(this, a1);
    return s0;
}

// DRAFT: 0x001E7120 Execute__16ClockworkStingerFv
// note: prologue, case -1 and both gates verified; case 0 and cases 1-15, -2, default still empty; m_unk200 float store unverified
void ClockworkStinger::Execute()
{
    if ((m_unk38 != 0) && (*(unsigned int *)((char *)m_unk38 + 0x108) & 0x400)) {
        WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
        if (m_unk38 != 0) {
            __dl__FPv(m_unk38);
            m_unk38 = 0;
        }
        m_unk10C &= 0xFDFFFFFF;
        EnableSleep__15EntityBaseClassFbb(this, false, false);
        m_unk1FC = 0;
        SetState__15EntityBaseClassFi(this, 0xE);
        return;
    }
    switch (m_unk20) {
    case -1:
        if (m_unkE9 != 0) {
            m_unk10C &= 0xF8FFFFFF;
            m_unk10C |= 0x071B1902;
            m_unk15C = 0x32;
            m_unk15E = 0;
            if (m_unk1B8 == 0.0f && m_unk1BC == 0.0f && m_unk1C0 == 0.0f) {
                m_unk1B8 = *(float *)CS_TARGET(this);
                m_unk1BC = *((float *)CS_TARGET(this) + 1);
                m_unk1C0 = *((float *)CS_TARGET(this) + 2);
            }
            if (m_unk1D8 != 0) {
                m_unk1C4 = m_unk18C;
                m_unk1D4 = m_unk18C;
            }
            m_unk24C = 0;
            m_unk240 = 0;
            m_unk220 = *(u_long128 *)CS_TARGET(this);
            *(u_long128 *)&m_unk210 = *(u_long128 *)CS_TARGET(this);
            *(float *)&m_unk200 = m_unk1C8;
            *(float *)&m_unk204 = m_unk1CC;
            *(float *)&m_unk208 = m_unk1D0;
            CS_ASSERT(0x17F, m_unk1B0 == 0 || m_unk1B0 == 1, "mEVars.m_iType == STINGER_TYPE_NORMAL || mEVars.m_iType == STINGER_TYPE_DEMOLITION");
        } else {
            float vec[3];
            vec[0] = m_unk1B8;
            vec[1] = m_unk1BC;
            vec[2] = m_unk1C0;
            if (m_unk1B0 == 1) {
                if (Distance__7MathAPIFPA4_fPA4_f(vec, CS_TARGET(mPlayerAPI__13EntityManager)) <= m_unk1C4) {
                    if (m_unkD4 == 0) {
                        void *p = __nw__FUi(0x10);
                        if (p) p = __ct__6ShadowFQ26Shadow10ShadowTypeUi(p, 1, 0x87000007);
                        m_unkD4 = p;
                    }
                    CS_ASSERT(0x18F, m_unkD4 != 0, "mpShadow");
                    if (m_unkD4 != 0) {
                        *(unsigned char *)m_unkD4 = 1;
                        char *sp0 = *(char **)((char *)m_unkD4 + 0xC);
                        if (sp0 != 0) *(unsigned char *)(sp0 + 0x18) = 1;
                    }
                    if (m_unk38 == 0) {
                        void *p = __nw__FUi(0x120);
                        if (p) p = __ct__7PhysicsFv(p);
                        m_unk38 = p;
                    }
                    CS_ASSERT(0x194, m_unk38 != 0, "mpPhysics");
                    SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12, 0);
                    SetState__15EntityBaseClassFi(this, 2);
                    return;
                }
            }
            if (Distance__7MathAPIFPA4_fPA4_f(vec, CS_TARGET(mPlayerAPI__13EntityManager)) > m_unk1C4) return;
            if (m_unkD4 == 0) {
                void *p = __nw__FUi(0x10);
                if (p) p = __ct__6ShadowFQ26Shadow10ShadowTypeUi(p, 1, 0x87000007);
                m_unkD4 = p;
            }
            CS_ASSERT(0x1A0, m_unkD4 != 0, "mpShadow");
            if (m_unkD4 != 0) {
                *(unsigned char *)m_unkD4 = 1;
                char *sp1 = *(char **)((char *)m_unkD4 + 0xC);
                if (sp1 != 0) *(unsigned char *)(sp1 + 0x18) = 1;
            }
            if (m_unk38 == 0) {
                void *p = __nw__FUi(0x120);
                if (p) p = __ct__7PhysicsFv(p);
                m_unk38 = p;
            }
            CS_ASSERT(0x1A5, m_unk38 != 0, "mpPhysics");
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12, 0);
            if (m_unk1E0 == 1) {
                SetState__15EntityBaseClassFi(this, 0);
            } else if (m_unk1E0 == 2) {
                SetState__15EntityBaseClassFi(this, 1);
            } else {
                SetState__15EntityBaseClassFi(this, 2);
            }
            return;
        }
        break;
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    case 15:
        break;
    case -2:
        break;
    default:
        break;
    }
}

// FUNCTION: 0x001E8CF0 __dt__16ClockworkStingerFv
extern "C" ClockworkStinger *__dt__16ClockworkStingerFv(ClockworkStinger *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__16ClockworkStinger;
        DestroyDamageFx__15EntityBaseClassFUi(pThis, pThis->m_unk250);
        pThis->m_unk250 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001E8D60 __ct__16ClockworkStingerFv
extern "C" ClockworkStinger *__ct__16ClockworkStingerFv(ClockworkStinger *pThis) {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 3, 0xA);
    *(unsigned char **)pThis = __vt__16ClockworkStinger;
    pThis->m_unk200 = 0;
    pThis->m_unk204 = 0;
    pThis->m_unk208 = 0;
    pThis->m_unk20C = 0;
    pThis->m_unk210 = 0;
    pThis->m_unk214 = 0;
    pThis->m_unk218 = 0;
    pThis->m_unk21C = 0;
    *(int *)((char *)pThis + 0x220) = 0;
    *(int *)((char *)pThis + 0x224) = 0;
    *(int *)((char *)pThis + 0x228) = 0;
    *(int *)((char *)pThis + 0x22C) = 0;
    pThis->m_unk230 = 0;
    pThis->m_unk234 = 0;
    pThis->m_unk238 = 0;
    pThis->m_unk23C = 0;
    pThis->m_unk240 = 0;
    pThis->m_unk244 = 0;
    pThis->m_unk248 = 0;
    pThis->m_unk24C = 0;
    pThis->m_unk250 = 0;
    pThis->m_unk254 = 0;
    pThis->m_unk258 = 0;
    pThis->m_unk25C = 0;
    pThis->m_unk260 = 0;
    pThis->m_unk264 = 0;
    pThis->m_unk268 = 0;
    pThis->m_unk103 = 0x10;
    pThis->m_unk104 = 0x40000000;
    pThis->m_unk108 = 0x3FC00000;
    pThis->m_unk166 = 1;
    return pThis;
}
