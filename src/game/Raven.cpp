// FLAGS: -str readonly
#include "Raven.h"
#include "types.h"

// TODO(header): foreign declarations
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
extern unsigned int BlueRaven_Init[4];
extern unsigned int SeaGull_Init[4];
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int printf(const char *pFmt, ...);
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nA, int nB);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *pThis, float *pPos);
extern "C" void RotateTo__15EntityBaseClassFff(void *pThis, float fAngle, float fRate);
extern "C" void sceVu0SubVector(float *pOut, float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pOut, float *pIn);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern float mHitPos__15EntityBaseClass[4];

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
        sprintf(buf, "Anim Frame = %f\n", fptodp(GetFrameTime__6PMNodeFv(node)));
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
// note: DIFF 53 words; original asserts via CdsAssert before the sprintf/printf block and is 0x12c vs our 0x120.
void Raven::SetEditableVars(char *pArg) {
    char buf[0x80];
    memcpy(&m_unk1B0, pArg, 0x14);
    m_unk179 = 0;
    if (m_unk1B0 == 0.0f && m_unk1B4 == 0.0f && m_unk1B8 == 0.0f) {
        if ("eif 0, 0, 0 error.  see keith or ted" != 0) {
            CdsAssert__FPciPc("Raven.cpp", 0x35D, "!\"eif 0, 0, 0 error.  see keith or ted\"");
        }
        float *pSrc = m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190;
        m_unk1B0 = pSrc[0];
        m_unk1B4 = pSrc[1];
        m_unk1B8 = pSrc[2];
    }
    if (m_unk1BC <= 10.0f) {
        sprintf(buf, "Warning: Raven (%d), activation radius (%3.2f) <= minimum (%3.2f). Please fix!\n", m_unk4, fptodp(m_unk1BC), 10.0);
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

// DRAFT: 0x001B2D30 OnTouchEvent__5RavenFP15EntityBaseClass
// note: 34 words (was 36); size 0x158 vs 0x148. Original shares one epilogue at 0x130 via bc1t; ours is 4 words longer before it. Tried: nesting tail in the >10 block, guard instead of return, flipped pPos ternary, single store base pointer (all 34, reverted).
void Raven::OnTouchEvent(EntityBaseClass *pArg) {
    if (pArg != 0 && pArg->m_unk8 == 3 && m_unk20 == 0xD) {
        float *pSrc = mPlayerAPI__13EntityManager->m_unk3C ? (float *)((char *)mPlayerAPI__13EntityManager->m_unk3C + 0x80) : mPlayerAPI__13EntityManager->m_unk190;
        if (DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])pSrc, (float (*)[4])m_unk1E0) > 10.0f) {
            SetState__15EntityBaseClassFi(this, 7);
            m_unk10C &= 0xFBFFFFFF;
        }
        Player *pPlayer = mpEntMgr__15EntityBaseClass->m_unk505C;
        if (pPlayer == 0) {
            CdsAssert__FPciPc("Raven.cpp", 0x314, "apPlayer");
        }
        if (pPlayer->m_unk163 == 2 && pPlayer->m_unk1CC == m_unk4) {
            return;
        }
        float *pPos = m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190;
        float f3 = pPos[0];
        float f2 = pPos[1];
        float f1 = pPos[2];
        float f0 = pPos[3];
        mHitPos__15EntityBaseClass[0] = f3;
        mHitPos__15EntityBaseClass[1] = f2;
        mHitPos__15EntityBaseClass[2] = f1;
        mHitPos__15EntityBaseClass[3] = f0;
        ((EntityBaseView *)pArg)->OnHitEvent((EntityBaseClass *)this, 0, 0x1001, 0);
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
