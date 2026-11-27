// FLAGS: -str readonly
#include "ClockworkReaperSpear.h"
#include "Debug.h"
#include "types.h"

// TODO(header): foreign declarations
extern unsigned char __vt__20ClockworkReaperSpear[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" float atan2f(float fY, float fX);
extern "C" float sqrtf(float fX);
extern "C" float Round180__Ff(float fAngle);
extern u_long128 mHitPos__15EntityBaseClass;
extern void *mPlayerAPI__13EntityManager;
extern "C" void *__ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoad, unsigned int nArg);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" int CreateTimer__8TimerAPIFUiUib(void *pTimer, unsigned int nA, unsigned int nB, bool bFlag);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(void *pA, void *pB);
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(void *pThis, float *pOut);
extern "C" int IsValid__16PParticleManagerFP15PParticleSystem(void *pMgr, void *pSys);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pPhys, unsigned int nType, void *pArg);
extern char gGfxEng[1504384];
extern char gEng[105360];
extern char mTimerAPI__13EntityManager[40];
extern unsigned int ClockworkReaperSpear_InAirSeq[13];
extern unsigned int ClockworkReaperSpear_FadeSeq[5];
extern "C" void SetAnimLoopCount__6PMNodeFib(void *pNode, int nCount, bool bFlag);

// Leading virtuals of PParticleSystem's vtable; SetPosition sits at slot 0x28 (virtual 8).
class ParticleSystemVirtuals {
public:
    virtual ~ParticleSystemVirtuals();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void SetPosition(float *pA, float *pB);
};

// Leading virtuals of EntityBaseClass's vtable; OnHitEvent sits at slot 0x58 (virtual 20).
// A call through this view loads the slot into $t9 as the original's virtual calls do.
class EntityBaseVirtuals {
public:
    virtual ~EntityBaseVirtuals();
    virtual void Slot1();
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
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void OnHitEvent(EntityBaseClass *pOther, int nDmg, unsigned int a, unsigned int b);
};

// FUNCTION: 0x001F06B0 __dt__20ClockworkReaperSpearFv
extern "C" ClockworkReaperSpear *__dt__20ClockworkReaperSpearFv(ClockworkReaperSpear *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__20ClockworkReaperSpear;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F0710 GetClassName__20ClockworkReaperSpearFv
const char *ClockworkReaperSpear::GetClassName() {
    return "ClockworkReaperSpear";
}

// FUNCTION: 0x001F0720 OrientSpear__20ClockworkReaperSpearFv
void ClockworkReaperSpear::OrientSpear() {
    float ang[4];
    float n[4];

    u_long128 *pSrc = (m_unk3C != 0) ? (u_long128 *)((char *)m_unk3C + 0x90) : &m_unk1A0;
    m_unk1C0 = *pSrc;
    sceVu0Normalize(n, (m_unk38 != 0) ? (float *)m_unk38 : 0);
    if (!(n[0] == 0.0f && n[1] == 0.0f && n[2] == 0.0f)) {
        ang[0] = 57.295776f * atan2f(n[1], sqrtf(n[2] * n[2] + n[0] * n[0]));
        ang[1] = 57.295776f * (3.1415927f + atan2f(n[0], n[2]));
        ang[0] = Round180__Ff(ang[0]);
        ang[1] = Round180__Ff(ang[1]);
        ang[2] = 0.0f;
        PMNode *pNode = m_unk3C;
        if (pNode != 0) {
            *(u_long128 *)((char *)pNode + 0x90) = *(u_long128 *)ang;
            *((unsigned char *)pNode + 0x3E) |= 8;
        } else {
            m_unk1A0 = *(u_long128 *)ang;
        }
    }
}

// FUNCTION: 0x001F0890 OnTimerEvent__20ClockworkReaperSpearFUi
void ClockworkReaperSpear::OnTimerEvent(unsigned int) {
    SetState__15EntityBaseClassFi(this, -2);
}

// FUNCTION: 0x001F08A0 OnTouchEvent__20ClockworkReaperSpearFP15EntityBaseClass
void ClockworkReaperSpear::OnTouchEvent(EntityBaseClass *arg0) {
    m_unk10C &= 0xF8FFFFFF;
    if (arg0 != 0) {
        u_long128 *pSrc = (m_unk3C != 0) ? (u_long128 *)((char *)m_unk3C + 0x80) : (u_long128 *)((char *)this + 0x190);
        mHitPos__15EntityBaseClass = *pSrc;
        int nType = *(int *)((char *)arg0 + 8);
        switch (nType) {
        case 3: {
            void *pPlayer = mPlayerAPI__13EntityManager;
            if (pPlayer == 0) {
                CdsAssert("ClockworkReaperSpear.cpp", 0xE7, "pPlayer");
            }
            ((EntityBaseVirtuals *)pPlayer)->OnHitEvent((EntityBaseClass *)this, 0x32, 0x1001, 0);
            break;
        }
        case 0x48:
            ((EntityBaseVirtuals *)arg0)->OnHitEvent((EntityBaseClass *)this, 0x32, 0, 0);
            break;
        }
    }
}

// DRAFT: 0x001F0990 Execute__20ClockworkReaperSpearFv
// note: DIFF 61 words; case 0/2 branch targets off by 1-2 words (extra b/nop before case 0), case -1 scale load order and rodata via lui 0x0 + reloc differ. Tried: compound *=, local pPhys.
void ClockworkReaperSpear::Execute() {
    float vec[4];

    switch (m_unk20) {
    case -1: {
        m_unk10C &= 0xF8FFFFFF;
        m_unk10C |= 0x041B1902;
        SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12, 0);
        GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, vec);
        vec[0] *= 0.8f;
        vec[2] *= 0.8f;
        *(unsigned int *)((char *)m_unk38 + 0x110) = 0;
        if (m_unk38 != 0) {
            *(u_long128 *)m_unk38 = *(u_long128 *)vec;
        }
        PlaySequence__15EntityBaseClassFPUi(this, ClockworkReaperSpear_InAirSeq);
        CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, 6, false);
        float init[8] = {0.0f, 0.0f, 0.0f, 1.0f, 0.7f, 0.7f, 0.7f, 0.7f};
        char *pPhys = (char *)m_unk38;
        *(u_long128 *)(pPhys + 0x80) = *(u_long128 *)init;
        *(u_long128 *)(pPhys + 0x90) = *(u_long128 *)(init + 4);
        SetState__15EntityBaseClassFi(this, 0);
        break;
    }
    case 0: {
        void *pPlayer = mPlayerAPI__13EntityManager;
        void *pPlayerNode = *(void **)((char *)pPlayer + 0x3C);
        void *pPlayerPos = (pPlayerNode != 0) ? (void *)((char *)pPlayerNode + 0x80) : (void *)((char *)pPlayer + 0x190);
        void *pThisPos = (m_unk3C != 0) ? (void *)((char *)m_unk3C + 0x80) : (void *)((char *)this + 0x190);
        if (DistanceXZ__7MathAPIFPA4_fPA4_f(pThisPos, pPlayerPos) < 10.0f) {
            *(unsigned int *)((char *)m_unk38 + 0x110) = 0x3CF5C28F;
        }
        OrientSpear();
        void *pMgr = gGfxEng + 0x154F00;
        if (pMgr == 0) {
            CdsAssert("ClockworkReaperSpear.cpp", 0x70, "apParticleManager");
        }
        float *pB = (m_unk3C != 0) ? (float *)((char *)m_unk3C + 0x80) : (float *)((char *)this + 0x190);
        float *pA = (m_unk3C != 0) ? (float *)((char *)m_unk3C + 0x80) : (float *)((char *)this + 0x190);
        void *pSys = (void *)m_unk1D4;
        if (pSys != 0 && IsValid__16PParticleManagerFP15PParticleSystem(pMgr, pSys) != 0) {
            ((ParticleSystemVirtuals *)pSys)->SetPosition(pA, pB);
        }
        unsigned char *pPhys = (unsigned char *)m_unk38;
        void *pE4 = *(void **)(pPhys + 0xE4);
        if (pE4 != 0 && (*(unsigned int *)((char *)pE4 + 0xC) & 0x10) != 0) {
            vec[0] = 0.0f;
            vec[1] = 0.0f;
            vec[2] = 0.0f;
            vec[3] = 0.0f;
            if (m_unk38 != 0) {
                *(u_long128 *)m_unk38 = *(u_long128 *)vec;
            }
            *(unsigned int *)((char *)m_unk38 + 0x110) = 0;
            SetState__15EntityBaseClassFi(this, 2);
        } else if ((*(unsigned int *)(pPhys + 0x108) & 1) != 0) {
            SetState__15EntityBaseClassFi(this, 2);
        }
        break;
    }
    case 2: {
        if (m_unkE9 != 0) {
            PlaySound__15EntityBaseClassFUi(this, 0x128);
            SetAnimLoopCount__6PMNodeFib(m_unk3C, 1, true);
            if (m_unk3C != 0) {
                *(u_long128 *)((char *)m_unk3C + 0x90) = m_unk1C0;
                *((unsigned char *)m_unk3C + 0x3E) |= 8;
            } else {
                m_unk1A0 = m_unk1C0;
            }
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 1, 0);
            m_unk10C &= 0xF8FFFFFF;
            m_unk1B4 = 0.0f;
        }
        if (m_unk1B4 > 0.0f) {
            m_unk1B4 = m_unk1B4 - *(float *)(gEng + 0x1E8);
        } else {
            SetState__15EntityBaseClassFi(this, 3);
        }
        break;
    }
    case 3: {
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, ClockworkReaperSpear_FadeSeq);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    }
    case -2:
        break;
    }
}

// FUNCTION: 0x001F0D40 __ct__20ClockworkReaperSpearFv
extern "C" ClockworkReaperSpear *__ct__20ClockworkReaperSpearFv(ClockworkReaperSpear *volatile pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 5, 1);
    pThis->m_unk0 = __vt__20ClockworkReaperSpear;
    pThis->m_unk1D4 = 0;
    void *pPhys = __nw__FUi(0x120);
    if (pPhys != 0) {
        pPhys = __ct__7PhysicsFv(pPhys);
    }
    pThis->m_unk38 = pPhys;
    if (pThis->m_unk38 == 0) {
        CdsAssert("ClockworkReaperSpear.cpp", 0x22, "mpPhysics");
    }
    unsigned char *pInfo = (unsigned char *)pThis->m_unk38 + 0xA0;
    if (pInfo == 0) {
        CdsAssert("ClockworkReaperSpear.cpp", 0x25, "pInfo");
    }
    *(unsigned int *)(pInfo + 0x4C) &= ~0x80;
    EnableSleep__15EntityBaseClassFbb(pThis, 0, 0);
    return pThis;
}
