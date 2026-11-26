// FLAGS: -str readonly
#include "Raven.h"
#include "types.h"

// TODO(header): foreign declarations
extern unsigned char jtbl_00269CE0[64];
class Player;
class EntityBaseClass {
public:
    char _pad000[0x8];
    int m_unk8;                     // 0x008 type tag (3 is checked by OnTouchEvent)
    char _pad00C[0x505C - 0x0C];
    Player *m_unk505C;              // 0x505C player pointer
};

class Player {
public:
    char _pad000[0x163];
    unsigned char m_unk163;         // 0x163
    char _pad164[0x1CC - 0x164];
    int m_unk1CC;                   // 0x1CC
    char _pad1D0[0x229 - 0x1D0];
    signed char m_unk229;           // 0x229
};

// Virtual dispatch view: slot 0x58 is virtual index 20 (dtor is index 0).
class EntityBaseView {
public:
    virtual ~EntityBaseView();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual int OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB);
};

class PMNode;
class EntityManager {
public:
    char _pad000[0x3C];
    PMNode *m_unk3C;                // 0x03C
    char _pad040[0x190 - 0x40];
    float m_unk190[3];              // 0x190
    char _pad19C[0x1E0 - 0x19C];
    int m_unk1E0;                   // 0x1E0
};
extern EntityManager *mPlayerAPI__13EntityManager;
extern EntityBaseClass *mpEntMgr__15EntityBaseClass;
extern "C" int IsPauseDisabled__6PlayerFv(Player *pPlayer);

class Debug {
public:
    void DebugDisp(char *pText);

    // Debug size is unknown; the placeholder keeps gDebug out of small data (threshold 8 bytes).
    char _pad000[0x10];
};
extern Debug gDebug;

class PMNode;
extern "C" float GetFrameTime__6PMNodeFv(PMNode *);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__5Raven[0x80];

extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" long long fptodp(float arg0);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *pThis, float *pOut);
extern "C" void sceVu0ScaleVector(float *pOut, float *pIn, float fScale);
extern unsigned int BlueRaven_Init[5];
extern unsigned int SeaGull_Init[5];
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int printf(const char *pFmt, ...);
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nA, int nB);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *pThis, float *pPos);
extern "C" void RotateTo__15EntityBaseClassFff(void *pThis, float fAngle, float fRate);
extern "C" void sceVu0SubVector(float *pOut, float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pOut, float *pIn);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern float mHitPos__15EntityBaseClass[4];
extern unsigned char mTimerAPI__13EntityManager[40];
extern unsigned char mEffectAPI__13EntityManager[20];
extern unsigned int Raven_Idle1[13];
extern unsigned int Raven_Idle2[13];
extern unsigned int Raven_Rise[13];
extern unsigned int Raven_Fly[13];
extern unsigned int Raven_Glide[13];
extern unsigned int Raven_Grab[13];
extern unsigned int Raven_Land[13];
extern unsigned int Raven_Damage[13];
extern unsigned int BlueRaven_Dead[15];
extern unsigned int SeaGull_Dead[15];
extern float BonusSpawnOffset[4];
extern "C" int CreateTimer__8TimerAPIFUiUib(void *pThis, unsigned int, unsigned int, bool);
extern "C" int CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(void *pThis, unsigned int, unsigned int, float (*)[4], float (*)[4], void *, float, bool, int, bool);
extern "C" void *Spawn__13EntityManagerFUibi(void *pThis, unsigned int, bool, int);
extern "C" void Destroy__13EntityManagerFUiUi(void *pThis, unsigned int, unsigned int);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *pEnt, float (*pPos)[4]);
extern "C" float FastMath_Fabs__Ff(float fVal);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nId);
extern "C" int PlaySoundOnFrame__15EntityBaseClassFUiUi(void *pThis, unsigned int nId, unsigned int nFrame);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int nType, float (*pPos)[4]);
extern "C" int RandomIntRange__7MathAPIFii(int nMin, int nMax);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nA, char cB, unsigned int nC);
extern "C" void SpawnBonus__15EntityBaseClassFPfii(void *pThis, float *pOffset, int nA, int nB);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__7PhysicsFv(void *pThis);

// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("Raven.cpp", line, #cond))

// FUNCTION: 0x001B25E0 __dt__5RavenFv
extern "C" void *__dt__5RavenFv(Raven *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__5Raven;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001B2640 GetClassName__5RavenFv
const char *Raven::GetClassName() {
    return "Raven";
}

// FUNCTION: 0x001B2650 GetHealth__5RavenFv
int Raven::GetHealth() {
    return m_unk244;
}

// FUNCTION: 0x001B2660 GetTallyType__5RavenFv
int Raven::GetTallyType() {
    return 1;
}

// DRAFT: 0x001B2670 GetSoundID__5RavenFUi
// note: 44 words differ; case-group label order (3,4,6,5,2) fixed the chain, the 0x10 branch still targets a different body. Tried: label orders 2-6 / 2,5,6,4,3 / 3,4,6,5,2, case 12 before 10, default:, reordered top case (DIFF 50-56).
int Raven::GetSoundID(unsigned int nId) {
    int snd = 0;
    switch (nId) {
    case 1:
        snd = 0x62;
        if (m_unk1C0 == 2) {
            snd = 0x29C;
        }
        break;
    case 3:
    case 4:
    case 6:
    case 5:
    case 2:
        snd = 0x4E27;
        if (m_unk1C0 == 2) {
            snd = 0x4E61;
        }
        break;
    case 10:
        snd = 0xE9;
        if (m_unk1C0 == 2) {
            snd = 0x294;
        }
        break;
    case 12:
        snd = 0x63;
        if (m_unk1C0 == 2) {
            snd = 0x2BE;
        }
        break;
    }
    if (snd == 0) {
        CdsAssert__FPciPc("Raven.cpp", 0x41C, "aSndId");
    }
    return snd;
}

// FUNCTION: 0x001B2770 OutputDebug__5RavenFv
void Raven::OutputDebug() {
    char buf[0x100];
    PMNode *node = m_unk3C;
    if (node != 0) {
        sprintf(buf, "Anim Frame = %f\n", (double)(GetFrameTime__6PMNodeFv(node)));
        gDebug.DebugDisp(buf);
    }
}

// FUNCTION: 0x001B27D0 CanAttack__5RavenFv
int Raven::CanAttack() {
    int bCan = mPlayerAPI__13EntityManager->m_unk1E0 > 0;
    if (bCan != 0) {
        Player *pPlayer = mpEntMgr__15EntityBaseClass->m_unk505C;
        if (pPlayer == 0) {
            CdsAssert__FPciPc("Raven.cpp", 0x3DA, "apPlayer");
        }
        if (pPlayer->m_unk163 == 3 || pPlayer->m_unk229 == 4 || IsPauseDisabled__6PlayerFv(pPlayer) != 0) {
            bCan = 0;
        }
    }
    return bCan;
}

// FUNCTION: 0x001B2870 FlyAway__5RavenFv
void Raven::FlyAway() {
    float vec[4];
    if (m_unk20 != 3) {
        if (m_unk3C == 0) {
            switch (m_unk1C0) {
            case 0:
                PlaySequence__15EntityBaseClassFPUi(this, BlueRaven_Init);
                break;
            case 1:
                PlaySequence__15EntityBaseClassFPUi(this, BlueRaven_Init);
                break;
            case 2:
                PlaySequence__15EntityBaseClassFPUi(this, SeaGull_Init);
                break;
            default:
                CdsAssert__FPciPc("Raven.cpp", 0x3B9, "false");
                break;
            }
        }
        SetState__15EntityBaseClassFi(this, 3);
    }
    m_unk10C &= 0xF8FFFFFF;
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, vec);
    sceVu0ScaleVector(vec, vec, 0.25f);
    vec[1] = 0.05f;
    if (m_unk38 != 0) {
        *(u_long128 *)m_unk38 = *(u_long128 *)vec;
    }
}

// DRAFT: 0x001B2980 FlyToFlyToPos__5RavenFi
// note: 4 attempts; best 87 words (nMode==1 branch first, GetAngleYToPoint stored to vec[1] before RotateTo), size 0x1C4 vs 0x1BC. Tried nMode==0 first (93 words, size 0x1B0), switch on nMode (112), if/else with pAng write-through (112).
void Raven::FlyToFlyToPos(int nMode) {
    float fwd[4];
    float vec[4];
    float tgt0[4];
    float tgt1[4];
    float *pBase;
    GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, fwd);
    vec[0] = fwd[0];
    vec[2] = fwd[2];
    pBase = m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190;
    if (nMode == 1) {
        *(u_long128 *)tgt1 = *(u_long128 *)m_unk1E0;
        tgt1[1] += 3.0f;
        sceVu0SubVector(m_unk210, tgt1, pBase);
        sceVu0Normalize(m_unk210, m_unk210);
        vec[1] = m_unk210[1] * 0.1f;
        vec[1] = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, m_unk1E0);
        RotateTo__15EntityBaseClassFff(this, vec[1], m_unk248);
    } else if (nMode == 0) {
        float *pSrc = mPlayerAPI__13EntityManager->m_unk3C ? (float *)((char *)mPlayerAPI__13EntityManager->m_unk3C + 0x80) : mPlayerAPI__13EntityManager->m_unk190;
        *(u_long128 *)tgt0 = *(u_long128 *)pSrc;
        tgt0[1] += (m_unk20 == 0xD) ? 2.0f : 6.0f;
        sceVu0SubVector(m_unk210, tgt0, pBase);
        sceVu0Normalize(m_unk210, m_unk210);
        vec[1] = m_unk210[1] * 0.2f;
        vec[1] = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, tgt0);
        RotateTo__15EntityBaseClassFff(this, vec[1], m_unk248);
    }
    float keep = vec[1];
    sceVu0ScaleVector(vec, vec, m_unk240);
    vec[1] = keep;
    if (m_unk38 != 0) {
        *(u_long128 *)m_unk38 = *(u_long128 *)vec;
    }
}

// DRAFT: 0x001B2B40 SetEditableVars__5RavenFPc
// note: DIFF 51 words; the original keeps a nop in the bnez delay slot before the 0x35D assert (ours fills it with lui $a0), shifting later offsets; size 0x128 vs 0x12c; CheckVariable call reloc missing at 0x114. Tried: plain CdsAssert call (54), hoisting pSrc (51), inverted ternary (54), (void)0 vs 0 arm.
void Raven::SetEditableVars(char *pArg) {
    char buf[0x80];
    memcpy(&m_unk1B0, pArg, 0x14);
    m_unk179 = 0;
    if (m_unk1B0 == 0.0f && m_unk1B4 == 0.0f && m_unk1B8 == 0.0f) {
        CDS_ASSERT(0x35D, !"eif 0, 0, 0 error.  see keith or ted");
        float *pSrc = m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190;
        m_unk1B0 = pSrc[0];
        m_unk1B4 = pSrc[1];
        m_unk1B8 = pSrc[2];
    }
    if (m_unk1BC <= 10.0f) {
        sprintf(buf, "Warning: Raven (%d), activation radius (%3.2f) <= minimum (%3.2f). Please fix!\n", m_unk4, (double)m_unk1BC, 10.0);
        printf(buf);
    }
    CheckVariable__15EntityBaseClassFii(this, m_unk1C0, 3);
}

// FUNCTION: 0x001B2C70 OnTimerEvent__5RavenFUi
void Raven::OnTimerEvent(unsigned int nId) {
    if (nId == (unsigned int)m_unk1C8) {
        m_unk1C5 = 1;
        return;
    }
    if (nId == (unsigned int)m_unk258) {
        m_unk1C6 = 1;
        return;
    }
    if (nId == (unsigned int)m_unk25C) {
        m_unk1C7 = 1;
    }
}

// FUNCTION: 0x001B2CB0 OnHitEvent__5RavenFP15EntityBaseClassiUiUi
int Raven::OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB) {
    m_unk244 -= nDamage;
    if (m_unk244 <= 0) {
        m_unk10C &= 0xF8FFFFFF;
        EnableSleep__15EntityBaseClassFbb(this, 0, 0);
        SetState__15EntityBaseClassFi(this, 0xC);
        return 2;
    }
    SetState__15EntityBaseClassFi(this, 0xA);
    return 1;
}

struct V4 { float v[4]; };

// FUNCTION: 0x001B2D30 OnTouchEvent__5RavenFP15EntityBaseClass
void Raven::OnTouchEvent(EntityBaseClass *pArg) {
    if (pArg != 0 && pArg->m_unk8 == 3 && m_unk20 == 0xD) {
        float *pSrc = mPlayerAPI__13EntityManager->m_unk3C ? (float *)((char *)mPlayerAPI__13EntityManager->m_unk3C + 0x80) : mPlayerAPI__13EntityManager->m_unk190;
        if (DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])pSrc, (float (*)[4])m_unk1E0) > 10.0f) {
            SetState__15EntityBaseClassFi(this, 7);
            m_unk10C &= 0xFBFFFFFF;
            Player *pPlayer = mpEntMgr__15EntityBaseClass->m_unk505C;
            if (pPlayer == 0) {
                CdsAssert__FPciPc("Raven.cpp", 0x314, "apPlayer");
            }
            if (pPlayer->m_unk163 == 2 && pPlayer->m_unk1CC == m_unk4) {
                return;
            }
            float *pPos = m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190;
            *(V4 *)mHitPos__15EntityBaseClass = *(V4 *)pPos;
            ((EntityBaseView *)pArg)->OnHitEvent((EntityBaseClass *)this, 0, 0x1001, 0);
        }
    }
}

#define RAVEN_SELF_POS (m_unk3C ? (float (*)[4])((char *)m_unk3C + 0x80) : (float (*)[4])m_unk190)
#define RAVEN_PLAYER_POS (mPlayerAPI__13EntityManager->m_unk3C ? (float (*)[4])((char *)mPlayerAPI__13EntityManager->m_unk3C + 0x80) : (float (*)[4])mPlayerAPI__13EntityManager->m_unk190)
#define RAVEN_PM_BITS4 ((*((signed char *)m_unk3C + 0x3F) & 7) & 4)

// DRAFT: 0x001B2E80 Execute__5RavenFv
// note: DIFF 1010 words; added case -2 to the switch and the 0xEC clear as an int lw/and/sw on m_unk38 (was 1030); outer range check matches now, the rest of the jump-table bodies and branch shapes differ, CreateOneshot trailing args guessed.
void Raven::Execute() {
    float (*pPos)[4];
    unsigned int nSound;

    switch (m_unk20) {
    case -1:
        m_unk254 = 0;
        m_unk15C = 0;
        m_unk15E = 0;
        SetState__15EntityBaseClassFi(this, 0);
        return;
    case 0:
        m_unk10C &= 0xF8FFFFFF;
        m_unk10C |= 0x02000000;
        m_unk104 = 0x3F800000;
        m_unk108 = 0x3F000000;
        m_unk1D0[0] = m_unk1B0;
        m_unk1D0[1] = m_unk1B4;
        m_unk1D0[2] = m_unk1B8;
        m_unk1D0[3] = 1.0f;
        m_unk1CC = m_unk1BC;
        m_unk1C4 = 1;
        if (m_unk38 == 0) {
            m_unk38 = (Physics *)__ct__7PhysicsFv(__nw__FUi(0x120));
            CDS_ASSERT(0xBC, m_unk38 != 0);
            *(int *)((char *)m_unk38 + 0xEC) &= 0xFFFFFF7F;
        }
        switch (m_unk1C0) {
        case 0:
        case 1:
            PlaySequence__15EntityBaseClassFPUi(this, BlueRaven_Init);
            break;
        case 2:
            PlaySequence__15EntityBaseClassFPUi(this, SeaGull_Init);
            break;
        default:
            CDS_ASSERT(0xD0, 0);
            break;
        }
        *(u_long128 *)m_unk1E0 = *(u_long128 *)RAVEN_PLAYER_POS;
        m_unk1C5 = 1;
        m_unk1C6 = 0;
        m_unk248 = 0.01f;
        m_unk244 = 100;
        SetState__15EntityBaseClassFi(this, 1);
        return;
    case 1:
        if (m_unkE9) {
            m_unk103 = 0xFE;
            m_unk10C |= 0x01000000;
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x10, 0);
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Idle1);
            m_unk1C4 = 0;
        }
        if (CanAttack() && m_unk1C5) {
            if (Distance__7MathAPIFPA4_fPA4_f(RAVEN_PLAYER_POS, &m_unk1D0) <= m_unk1CC &&
                !(DistanceXZ__7MathAPIFPA4_fPA4_f(RAVEN_PLAYER_POS, &m_unk1E0) <= 10.0f)) {
                m_unk103 = 0x10;
                SetState__15EntityBaseClassFi(this, 2);
                return;
            }
        }
        if (m_unk160 == 0) {
            PlaySound__15EntityBaseClassFUi(this, GetSoundID(m_unk20));
        }
        if (m_unk1C4) {
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Idle1);
            m_unk1C4 = 0;
        } else {
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Idle2);
            m_unk1C4 = 1;
        }
        return;
    case -2:
    default:
        return;
    case 2:
        if (m_unkE9) {
            m_unk10C &= 0xFEFFFFFF;
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Rise);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 9U);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 0xFU);
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 0x18U);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 4);
            return;
        }
        break;
    case 3:
        if (m_unkE9) {
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Rise);
        }
        if (m_unk160 == 0) {
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Fly);
        }
        if (m_unk140 == Raven_Fly) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 5U);
        } else {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 9U);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 0xFU);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 0x18U);
        }
        FlyAway();
        return;
    case 4:
        if (m_unkE9) {
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Fly);
            m_unk248 = 0.03f;
            m_unk240 = 0.18f;
            m_unk1C6 = 0;
            m_unk258 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, 5U, false);
            m_unk260 = 0xF0;
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 5U);
        FlyToFlyToPos(0);
        if (!(m_unk1C6 == 0 && Distance__7MathAPIFPA4_fPA4_f(RAVEN_SELF_POS, &m_unk1D0) <= m_unk1CC)) {
            if (!(Distance__7MathAPIFPA4_fPA4_f(RAVEN_PLAYER_POS, &m_unk1D0) <= m_unk1CC)) {
                SetState__15EntityBaseClassFi(this, 5);
                return;
            }
        }
        if (GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, RAVEN_PLAYER_POS) < 45.0f &&
            DistanceXZ__7MathAPIFPA4_fPA4_f(RAVEN_PLAYER_POS, &m_unk1E0) <= 10.0f) {
            SetState__15EntityBaseClassFi(this, 6);
            return;
        }
        if (RAVEN_PM_BITS4 && (RandomIntRange__7MathAPIFii(0, 100) & 1)) {
            PlaySound__15EntityBaseClassFUi(this, GetSoundID(1U));
        }
        if (m_unk260 != 0) {
            m_unk260--;
            return;
        }
        SetState__15EntityBaseClassFi(this, 5);
        return;
    case 6:
        if (m_unkE9) {
            if (m_unk140 != Raven_Fly) {
                PlaySequence__15EntityBaseClassFPUi(this, Raven_Fly);
            }
            m_unk248 = 0.05f;
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 5U);
        FlyToFlyToPos(0);
        if (!(m_unk1C6 == 0 && Distance__7MathAPIFPA4_fPA4_f(RAVEN_SELF_POS, &m_unk1D0) <= m_unk1CC)) {
            if (!(Distance__7MathAPIFPA4_fPA4_f(RAVEN_PLAYER_POS, &m_unk1D0) <= m_unk1CC)) {
                SetState__15EntityBaseClassFi(this, 5);
                return;
            }
            if (!(FastMath_Fabs__Ff(GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, RAVEN_PLAYER_POS)) <= 55.0f)) {
                SetState__15EntityBaseClassFi(this, 5);
                return;
            }
        }
        if (Distance__7MathAPIFPA4_fPA4_f(RAVEN_PLAYER_POS, RAVEN_SELF_POS) < 10.0f) {
            SetState__15EntityBaseClassFi(this, 0xD);
            return;
        }
        if (RAVEN_PM_BITS4 && (RandomIntRange__7MathAPIFii(0, 100) & 1)) {
            PlaySound__15EntityBaseClassFUi(this, GetSoundID(1U));
            return;
        }
        break;
    case 13:
        if (m_unkE9) {
            m_unk10C |= 0x04000000;
            m_unk240 = 0.18f;
            m_unk248 = 0.0f;
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Glide);
            m_unk1C7 = 0;
            m_unk25C = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, 2U, false);
        }
        FlyToFlyToPos(0);
        if (m_unk1C7 != 0) {
            m_unk10C &= 0xFBFFFFFF;
            SetState__15EntityBaseClassFi(this, 5);
            return;
        }
        break;
    case 7:
        if (m_unkE9) {
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Grab);
        }
        if (!(GetFrameTime__6PMNodeFv(m_unk3C) <= 5.0f)) {
            if (CanAttack()) {
                int nLevel = mPlayerAPI__13EntityManager->m_unk1E0;
                void *pNode;
                m_unk250 = (EntityBaseClass *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 8U, false, 0);
                CDS_ASSERT(0x1F8, m_unk250 != 0);
                pNode = *(void **)((char *)m_unk250 + 0x3C);
                if (pNode != 0) {
                    *(u_long128 *)((char *)pNode + 0x80) = *(u_long128 *)RAVEN_SELF_POS;
                    *((unsigned char *)pNode + 0x3E) |= 8;
                } else {
                    *(u_long128 *)((char *)m_unk250 + 0x190) = *(u_long128 *)RAVEN_SELF_POS;
                }
                m_unk254 = *(EntityBaseClass **)((char *)m_unk250 + 4);
                *(int *)((char *)m_unk250 + 0x1F0) = m_unk4;
                *((unsigned char *)m_unk250 + 0x1ED) = 1;
                if (nLevel >= 0xB) {
                    *(int *)((char *)m_unk250 + 0x1F8) = 0xA;
                } else if (nLevel >= 6) {
                    *(int *)((char *)m_unk250 + 0x1F8) = 1;
                } else {
                    *(int *)((char *)m_unk250 + 0x1F8) = 0;
                }
                *((unsigned char *)m_unk250 + 0x1EE) = 1;
                m_unk240 = 0.12f;
            }
            SetState__15EntityBaseClassFi(this, 5);
            return;
        }
        break;
    case 5:
        if (m_unkE9) {
            m_unk1C6 = 0;
            m_unk258 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, 3U, false);
            m_unk248 = 0.02f;
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Fly);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, GetSoundID(m_unk20), 5U);
        if (m_unk250 == 0 && m_unk1C6 != 0 && CanAttack()) {
            if (Distance__7MathAPIFPA4_fPA4_f(RAVEN_PLAYER_POS, &m_unk1D0) <= m_unk1CC) {
                SetState__15EntityBaseClassFi(this, 4);
                return;
            }
        }
        if (DistanceXZ__7MathAPIFPA4_fPA4_f(RAVEN_SELF_POS, &m_unk1E0) < 7.0f) {
            if (m_unk250 != 0 && ApparitionIsValid__15EntityBaseClassFUi((unsigned int)m_unk254) != 0) {
                Destroy__13EntityManagerFUiUi(mpEntMgr__15EntityBaseClass, (unsigned int)m_unk254, 0U);
                m_unk250 = 0;
                m_unk254 = 0;
            }
        }
        if (!(DistanceXZ__7MathAPIFPA4_fPA4_f(RAVEN_PLAYER_POS, &m_unk1E0) <= 5.0f)) {
            m_unk248 = 0.1f;
            SetState__15EntityBaseClassFi(this, 8);
            return;
        }
        FlyToFlyToPos(1);
        if (RAVEN_PM_BITS4 && (RandomIntRange__7MathAPIFii(0, 100) & 1)) {
            PlaySound__15EntityBaseClassFUi(this, GetSoundID(1U));
            return;
        }
        break;
    case 8:
        pPos = RAVEN_PLAYER_POS;
        if (m_unkE9) {
            PlaySequence__15EntityBaseClassFPUi(this, Raven_Land);
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 1, 0);
            m_unk210[2] = m_unk210[1] = m_unk210[0] = 0.0f;
            *(float **)m_unk38 = m_unk210;
            *(u_long128 *)m_unk220 = *(u_long128 *)pPos;
            sceVu0SubVector(m_unk230, m_unk1E0, (float *)pPos);
            m_unk24C = 0.01f;
        }
        Distance__7MathAPIFPA4_fPA4_f(pPos, &m_unk1E0);
        if (m_unk160 == 0 && !(m_unk24C <= 1.0f)) {
            if (m_unk3C != 0) {
                *(u_long128 *)((char *)m_unk3C + 0x80) = *(u_long128 *)m_unk1E0;
                *((unsigned char *)m_unk3C + 0x3E) |= 8;
            } else {
                *(u_long128 *)m_unk190 = *(u_long128 *)m_unk1E0;
            }
            m_unk1C5 = 0;
            m_unk1C8 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, 1U, false);
            RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float *)pPos), m_unk248);
            SetState__15EntityBaseClassFi(this, 1);
            return;
        }
        if (m_unk24C <= 1.0f) {
            m_unk210[0] = m_unk220[0] + m_unk230[0] * m_unk24C;
            m_unk210[1] = m_unk220[1] + m_unk230[1] * m_unk24C;
            m_unk210[2] = m_unk220[2] + m_unk230[2] * m_unk24C;
            m_unk24C += 0.02f;
            if (m_unk3C != 0) {
                *(u_long128 *)((char *)m_unk3C + 0x80) = *(u_long128 *)m_unk210;
                *((unsigned char *)m_unk3C + 0x3E) |= 8;
            } else {
                *(u_long128 *)m_unk190 = *(u_long128 *)m_unk210;
            }
            return;
        }
        break;
    case 10:
        if (m_unkE9) {
            if (m_unk254 != 0 && ApparitionIsValid__15EntityBaseClassFUi((unsigned int)m_unk254) != 0) {
                *((unsigned char *)m_unk254 + 0x1EF) = 1;
            }
            m_unk250 = 0;
            m_unk254 = 0;
            PlaySound__15EntityBaseClassFUi(this, GetSoundID(m_unk20));
            switch (m_unk1C0) {
            case 0:
            case 1:
                nSound = 0x01000370;
                break;
            case 2:
                nSound = 0x0100039C;
                break;
            default:
                CDS_ASSERT(0x2A5, 0);
                break;
            }
            CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(mEffectAPI__13EntityManager, nSound, 0x020005E7U,
                RAVEN_PLAYER_POS, &m_unk1E0, this, 0.5f, false, 0, false);
        }
        PlaySequence__15EntityBaseClassFPUi(this, Raven_Damage);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 5);
            return;
        }
        break;
    case 12:
        if (m_unkE9) {
            if (m_unk254 != 0 && ApparitionIsValid__15EntityBaseClassFUi((unsigned int)m_unk254) != 0) {
                *((unsigned char *)m_unk254 + 0x1EF) = 1;
            }
            if (m_unk38 != 0) {
                __dl__FPv(m_unk38);
                m_unk38 = 0;
            }
            PlaySound__15EntityBaseClassFUi(this, GetSoundID(m_unk20));
            switch (m_unk1C0) {
            case 0:
            case 1:
                PlaySequence__15EntityBaseClassFPUi(this, BlueRaven_Dead);
                break;
            case 2:
                PlaySequence__15EntityBaseClassFPUi(this, SeaGull_Dead);
                break;
            default:
                CDS_ASSERT(0x2DB, 0);
                break;
            }
        }
        WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0U);
        WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
        SpawnBonus__15EntityBaseClassFPfii(this, BonusSpawnOffset, 1, 1);
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    }
}

// FUNCTION: 0x001B3F20 __ct__5RavenFv
Raven::Raven() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 2U);
    m_unk0 = __vt__5Raven;
    m_unk250 = 0;
    m_unk1C0 = 0;
    m_unkEB = 0;
}
