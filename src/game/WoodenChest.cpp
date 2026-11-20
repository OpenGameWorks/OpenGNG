// FLAGS: -str readonly
#include "types.h"
#include "WoodenChest.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void GetGroundPos__7MathAPIFPA4_f(void *pVec);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int printf(const char *pFmt, ...);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void RotateTo__15EntityBaseClassFff(void *pThis, float fA, float fB);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *pThis, void *pEnt, float (*pVec)[4]);
extern "C" int RandomIntRange__7MathAPIFii(void *pThis, int nMin, int nMax);
extern "C" signed char ReadApparitionData__15EntityBaseClassFiUi(void *pThis, int nIndex, unsigned int nFlag);
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *pThis, unsigned int nId);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int nType, float (*pVec)[4]);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void *__nw__FUi(unsigned int nSize);
extern void *mpEntMgr__15EntityBaseClass;
extern unsigned char __vt__11WoodenChest[];
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nVar, int nValue);
extern "C" void *Spawn__13EntityManagerFUibi(void *pThis, unsigned int nId, bool bA, int nB);
extern "C" void *SpawnPickups__15EntityBaseClassFiiPA4_fb(void *pThis, int nA, int nB, float (*pVec)[4], bool bC);
extern "C" int GetVarType__6PickupFi(void *pThis, int nVar);
extern "C" int PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" int PlaySoundOnFrame__15EntityBaseClassFUiUi(void *pThis, unsigned int nA, unsigned int nB);
extern "C" void FacePlayer__15EntityBaseClassFf(void *pThis, float fA);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" float Round180__Ff(float fA);
extern "C" float FastMath_Fabs__Ff(float fA);
extern "C" float GetFrameTime__6PMNodeFv(void *pThis);
extern "C" int GetGround__11BGCollisionFPA4_fUi(void *pThis, float (*pVec)[4], unsigned int nFlag);
extern "C" void *Create__16PParticleManagerFUifffP6PMNodeb(void *pThis, unsigned int nId, float fX, float fY, float fZ, void *pNode, bool bA);
extern "C" int IsValid__16PParticleManagerFP15PParticleSystem(void *pThis, void *pSys);
extern "C" float atan2f(float fY, float fX);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void SetPling__6PlayerFQ26Player9PlingTypeP15EntityBaseClassUi(void *pThis, int nType, void *pEnt, unsigned int nA);
extern "C" void RemoveFromBGAnimList__15EntityBaseClassFv(void *pThis);
extern "C" void ModifyLoadClass__15EntityBaseClassFQ215EntityBaseClass9LoadClass(void *pThis, int eLoad);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nIndex, char cVal, unsigned int nFlag);
extern "C" void NotifyTreasure__6PlayerFPA4_ff(void *pThis, float (*pVec)[4], float fA);
extern "C" void __dl__FPv(void *pThis);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *pThis, int nType, unsigned int nId);
extern char gEng[0x40000];
extern char gGfxEng[0x200000];
extern char mBGCollision__15EntityBaseClass[0x100];
extern char mPlayerAPI__13EntityManager[0x10];
extern unsigned int LockedChest_IdleSeq[4];
extern unsigned int LockedChest_OpenSeq[4];
extern unsigned int LockedChest_RiseSeq[4];
extern unsigned int Mimic_Attack_Seq[4];
extern unsigned int Mimic_Damaged_Seq[4];
extern unsigned int Mimic_Death_Seq[4];
extern unsigned int Mimic_Idle_Seq[4];
extern unsigned int Mimic_Wakeup_Seq[4];
extern unsigned int WoodenChest_FadeSeq[4];
extern unsigned int WoodenChest_IdleSeq[4];
extern unsigned int WoodenChest_OpenSeq[4];
extern unsigned int WoodenChest_RiseSeq[4];

// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("WoodenChest.cpp", line, #cond))

// FUNCTION: 0x001A1590 __dt__11WoodenChestFv
WoodenChest::~WoodenChest() {
}

// FUNCTION: 0x001A1600 GetTallyType__11WoodenChestFv
int WoodenChest::GetTallyType()
{
    if (m_unk1CC != 0) {
        return 4;
    }
    return (m_unk1C8 == 2) ? 1 : 2;
}

// FUNCTION: 0x001A1640 SetDefaultVars__11WoodenChestFv
void WoodenChest::SetDefaultVars()
{
    m_unk1B0 = -1;
    m_unk1B4 = 0;
    m_unk1B8 = -1;
    m_unk1BC = 0;
    m_unk1C0 = -1;
    m_unk1C4 = 0;
    m_unk1C8 = 0;
    m_unk1CC = 0;
    m_unk1D0 = 10.0f;
    m_unk1D4 = 40.0f;
    m_unk1E0 = 150;
}

// FUNCTION: 0x001A1680 SetEditableVars__11WoodenChestFPc
void WoodenChest::SetEditableVars(char *pSrc)
{
    float vec[4];

    memcpy(&m_unk1B0, pSrc, 0x30);
    m_unk1E0 = 0x96;
    *(u_long128 *)vec = *(u_long128 *)_pad190;
    GetGroundPos__7MathAPIFPA4_f(vec);
    m_unk214 = vec[1];
    if (m_unk1CC != 0 && m_unk1D8 != 0) {
        printf("m_bHidden & m_bOnMovingGround cannot be set together\n");
    }
    if (m_unk1C8 == 1 && HaveKeys()) {
        CDS_ASSERT(0x3E0, !"Locked chest shouldn't have key");
    }
}

// FUNCTION: 0x001A1740 OnSleepEvent__11WoodenChestFv
void WoodenChest::OnSleepEvent()
{
    if (ApparitionIsValid__15EntityBaseClassFUi(m_unk210)) {
        EnableSleep__15EntityBaseClassFbb(ApparitionIsValid__15EntityBaseClassFUi(m_unk210), true, false);
    }
}

// DRAFT: 0x001A1790 HaveKeys__11WoodenChestFv
// note: original tests ==8 then ==7 with two branches to a shared body and an i++ in the non-matching b delay slot; ours emits three branches. 17 words differ (for, continue, do-while 8-first, goto, if/else variants tried; 7-first is 19).
int WoodenChest::HaveKeys()
{
    int *p;
    int i;

    i = 0;
    p = &m_unk1B0;
    do {
        if (p[0] == 8 || p[0] == 7) {
            if (p[1] > 0) {
                return 1;
            }
        }
        i++;
        p += 2;
    } while (i < 3);
    return 0;
}

// Setup run when m_unk1DC is set: clears the flag, zeroes the slot at m_unk3C+0x90 (or this+0x1A0), and makes the Physics object.
#define WC_HIT_SETUP(LINE) \
    m_unk1DC = 0; \
    pBase = (m_unk3C != 0) ? m_unk3C + 0x90 : (char *)this + 0x1A0; \
    *(int *)pBase = 0; \
    *(int *)(pBase + 8) = 0; \
    if (*(char **)((char *)this + 0x38) == 0) { \
        pPhys = (char *)__nw__FUi(0x120); \
        if (pPhys != 0) { \
            pPhys = (char *)__ct__7PhysicsFv(pPhys); \
        } \
        *(char **)((char *)this + 0x38) = pPhys; \
        if (*(char **)((char *)this + 0x38) == 0) { \
            CdsAssert__FPciPc((char *)"WoodenChest.cpp", LINE, (char *)"mpPhysics"); \
        } \
    } \
    SetPhysicsType__7PhysicsFUiPA4_f(*(void **)((char *)this + 0x38), 0x1A, 0); \
    *(unsigned int *)(*(char **)((char *)this + 0x38) + 0x10C) = 0x3E4CCCCD; \
    *(unsigned char *)((char *)this + 0x103) = 0x20; \
    pApp = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk210); \
    if (pApp != 0) { \
        SetState__15EntityBaseClassFi(pApp, 1); \
    }

// DRAFT: 0x001A17F0 OnHitEvent__11WoodenChestFP15EntityBaseClassiUiUi
// note: DIFF 233 words. Frame 0x60 vs original 0x50, this in s4 not s3; goto-based switch fall-through and the duplicated setup macro differ. Tried nState removal and nB in the tail; no change in count.
int WoodenChest::OnHitEvent(EntityBaseClass *pEntity, int nEvent, unsigned int nA, unsigned int nB)
{
    char *pBase;
    char *pPhys;
    char *pTarget;
    void *pApp;

    if ((*(int *)((char *)pEntity + 0x10C) & 1) == 1) {
        if (*(int *)((char *)pEntity + 8) == 3) {
            if (*(signed char *)((char *)pEntity + 0x229) == 4 && m_unk1C8 != 1 && m_unk20 == 0) {
                nA = 0x1FD;
                if (m_unk1DC != 0) {
                    WC_HIT_SETUP(0x336)
                }
            }
        }
        switch (nA) {
        case 0x1FD:
            PlaySound__15EntityBaseClassFUi(this, 0x27D);
            if (m_unk1C8 == 2) {
                SetState__15EntityBaseClassFi(this, 6);
            } else if (HaveKeys() == 0 && (signed char)ReadApparitionData__15EntityBaseClassFiUi(this, 3, 0) == 2) {
                if (RandomIntRange__7MathAPIFii(0, 1, 20) < 15) {
                    SetState__15EntityBaseClassFi(this, 3);
                } else {
                    SetState__15EntityBaseClassFi(this, 6);
                }
            } else {
                SetState__15EntityBaseClassFi(this, 3);
            }
            return 1;
        case 0x1FF:
            if (m_unk1C8 == 1) {
                SetState__15EntityBaseClassFi(this, 0xD);
                return 0;
            }
            goto block_49;
        default:
            if (m_unk1DC != 0) {
                WC_HIT_SETUP(0x375)
            }
            goto block_49;
        }
block_49:
        if (m_unk20 == 6 || (unsigned int)(m_unk20 - 7) < 3U || m_unk20 == 0xC || m_unk20 == 0xA) {
            pTarget = (m_unk3C != 0) ? m_unk3C + 0x80 : (char *)pEntity + 0x190;
            RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pTarget, 0), 1.0f);
            m_unk1E0 -= nB;
            if (m_unk1E0 > 0) {
                SetState__15EntityBaseClassFi(this, 9);
                return 1;
            }
            SetState__15EntityBaseClassFi(this, 0xB);
            return 2;
        }
    }
    return 5;
}

// FUNCTION: 0x001A1BB0 OnAttackEvent__11WoodenChestFP15EntityBaseClassi
void WoodenChest::OnAttackEvent(class EntityBaseClass *pEntity, int nEvent)
{
    if (*(int *)((char *)pEntity + 8) == 3 && m_unk20 == 7) {
        SetState__15EntityBaseClassFi(this, 12);
    }
}

#define WCX_PTR(b, o) (*(void **)((char *)(b) + (o)))
#define WCX_S32(b, o) (*(int *)((char *)(b) + (o)))
#define WCX_U32(b, o) (*(unsigned int *)((char *)(b) + (o)))
#define WCX_U8(b, o) (*(unsigned char *)((char *)(b) + (o)))
#define WCX_S8(b, o) (*(signed char *)((char *)(b) + (o)))
#define WCX_F32(b, o) (*(float *)((char *)(b) + (o)))
#define WCX_VCALL(b, o) (((int (*)(void *))(((void **)*(void **)(b))[(o) / 4]))(b))

// DRAFT: 0x001A1BF0 Execute__11WoodenChestFv
// note: DIFF 1286 words, size 0x1424 vs 0x14C0. Frame 0xD0 saves s0-s5 vs original 0xE0 saves s0-s4 with this in s0; switch range -1..13 vs original -2..13 (case -2 tried, count unchanged); case 4 loop, case 6 and 7 pointer ternaries and sequence picks differ.
void WoodenChest::Execute()
{
    switch (this->m_unk20) {
    case -1: {
        int *pVar = &this->m_unk1B0;
        int i;
        for (i = 0; i < 3; i++) {
            if (pVar[0] > 0) {
                CheckVariable__15EntityBaseClassFii((EntityBaseClass *)this, pVar[0], 0x27);
            }
            pVar += 2;
        }
        WCX_U32(this, 0x10C) &= 0xF8FFFFFF;
        WCX_U32(this, 0x10C) |= 0x02000000;
        if (this->m_unk1D8 != 0) {
            if (this->m_unk38 == 0) {
                void *pPhys = __nw__FUi(0x120);
                if (pPhys != 0) {
                    pPhys = __ct__7PhysicsFv(pPhys);
                }
                this->m_unk38 = (Physics *)pPhys;
                if (this->m_unk38 == 0) {
                    CdsAssert__FPciPc("WoodenChest.cpp", 0x95, "mpPhysics");
                }
            }
            SetPhysicsType__7PhysicsFUiPA4_f(this->m_unk38, 0x40U, (float (*)[4])((char *)this + 0x190));
        }
        if (this->m_unk1DC != 0) {
            WCX_U8(this, 0x1F) = 1;
            WCX_U8(this, 0xEA) = 1;
        }
        WCX_U8(this, 0x103) = 0xFF;
        if (this->m_unk1CC != 0) {
            if (ReadApparitionData__15EntityBaseClassFiUi((EntityBaseClass *)this, 3, 0U) == 0) {
                float f0 = this->m_unk1D0;
                WCX_F32(this, 0x1E4) = f0;
                WCX_F32(this, 0x1E4) = f0 * f0;
                SetState__15EntityBaseClassFi((EntityBaseClass *)this, 1);
                return;
            }
        }
        SetState__15EntityBaseClassFi((EntityBaseClass *)this, 0);
        return;
    }
    case 1: {
        char *pSrc = (char *)this->m_unk3C;
        char *pPlayer = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
        float *pPos = (pSrc != 0) ? (float *)(pSrc + 0x80) : (float *)((char *)this + 0x190);
        float sp70[4];
        NotifyTreasure__6PlayerFPA4_ff(pPlayer, (float (*)[4])pPos, this->m_unk1D0);
        if (WCX_U32(WCX_PTR(pPlayer, 0x38), 0x108) & 2) {
            char *pA = (char *)WCX_PTR(pPlayer, 0x3C);
            float *pA1 = (pA != 0) ? (float *)(pA + 0x80) : (float *)(pPlayer + 0x190);
            sceVu0SubVector(sp70, pA1, (float *)pPos);
            if (sceVu0InnerProduct(sp70, sp70) < WCX_F32(this, 0x1E4)) {
                SetState__15EntityBaseClassFi((EntityBaseClass *)this, 2);
                return;
            }
        } else {
            return;
        }
        break;
    }
    case 2: {
        char *pSrc = (char *)this->m_unk3C;
        float *pPos = (pSrc != 0) ? (float *)(pSrc + 0x80) : (float *)((char *)this + 0x190);
        float sp80[4];
        if (WCX_U8(this, 0xE9) != 0) {
            WriteApparitionData__15EntityBaseClassFicUi((EntityBaseClass *)this, 3, 1, 0U);
            WriteApparitionData__15EntityBaseClassFicUi((EntityBaseClass *)this, 2, 1, 0U);
            PlaySound__15EntityBaseClassFUi((EntityBaseClass *)this, 0x93U);
            if (this->m_unk1C8 == 1) {
                PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, LockedChest_RiseSeq);
            } else {
                PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, WoodenChest_RiseSeq);
            }
            pSrc = (char *)this->m_unk3C;
            pPos = (pSrc != 0) ? (float *)(pSrc + 0x80) : (float *)((char *)this + 0x190);
            *(u_long128 *)sp80 = *(u_long128 *)pPos;
            sp80[1] += 10.0f;
            if (GetGround__11BGCollisionFPA4_fUi((void *)mBGCollision__15EntityBaseClass, (float (*)[4])sp80, 1U) == 0) {
                WCX_PTR(this, 0x1EC) = Create__16PParticleManagerFUifffP6PMNodeb((void *)(gGfxEng + 0x154F00), 0x83000047U, pPos[0], pPos[1], pPos[2], 0, 1);
                void *pPs = WCX_PTR(this, 0x1EC);
                if (pPs != 0 && IsValid__16PParticleManagerFP15PParticleSystem((void *)(gGfxEng + 0x154F00), (void *)pPs) != 0) {
                    void (*pfn)(void *) = (void (*)(void *))((void **)*(void **)pPs)[0x20 / 4];
                    pfn(pPs);
                }
            }
            WCX_F32(this, 0x1E8) = pPos[1];
            pSrc = (char *)this->m_unk3C;
            pPos = (pSrc != 0) ? (float *)(pSrc + 0x80) : (float *)((char *)this + 0x190);
            pPos[1] = pPos[1] - 2.6f;
        }
        if (pPos[1] <= WCX_F32(this, 0x1E8)) {
            pPos[1] = pPos[1] + (0.04f * WCX_F32(gEng, 0x1E8));
        }
        {
            float f1 = WCX_F32(this, 0x1E8);
            if (!(pPos[1] <= f1)) {
                pPos[1] = f1;
                void *pPs = WCX_PTR(this, 0x1EC);
                if (pPs != 0) {
                    if (IsValid__16PParticleManagerFP15PParticleSystem((void *)(gGfxEng + 0x154F00), (void *)pPs) != 0) {
                        void (*pfn)(void *, int) = (void (*)(void *, int))((void **)*(void **)pPs)[0x1C / 4];
                        pfn(pPs, 0);
                    }
                    WCX_PTR(this, 0x1EC) = 0;
                }
            }
        }
        if (this->m_unk160 == 0) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 0);
            return;
        }
        break;
    }
    case 0: {
        if (WCX_U8(this, 0xE9) != 0) {
            if (this->m_unk1C8 == 1) {
                PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, LockedChest_IdleSeq);
            } else {
                PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, WoodenChest_IdleSeq);
            }
            if ((this->m_unk1DC != 0) && (ApparitionIsValid__15EntityBaseClassFUi(this->m_unk210) == 0)) {
                void *pSpawn = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x23U, 0, 0);
                if (pSpawn == 0) {
                    CdsAssert__FPciPc("WoodenChest.cpp", 0x12B, "pNet");
                }
                this->m_unk210 = WCX_U32(pSpawn, 4);
                WCX_S32(pSpawn, 0x1B4) = (int)WCX_U32(this, 4);
                char *pSrc = (char *)this->m_unk3C;
                char *pVec = (pSrc != 0) ? (pSrc + 0x80) : ((char *)this + 0x190);
                char *pDst = (char *)WCX_PTR(pSpawn, 0x3C);
                if (pDst != 0) {
                    *(u_long128 *)(pDst + 0x80) = *(u_long128 *)pVec;
                    pDst[0x3E] = (unsigned char)(pDst[0x3E] | 8);
                } else {
                    *(u_long128 *)((char *)pSpawn + 0x190) = *(u_long128 *)pVec;
                }
                pSrc = (char *)this->m_unk3C;
                char *pVec2 = (pSrc != 0) ? (pSrc + 0x90) : ((char *)this + 0x1A0);
                pDst = (char *)WCX_PTR(pSpawn, 0x3C);
                if (pDst != 0) {
                    *(u_long128 *)(pDst + 0x90) = *(u_long128 *)pVec2;
                    pDst[0x3E] = (unsigned char)(pDst[0x3E] | 8);
                } else {
                    *(u_long128 *)((char *)pSpawn + 0x1A0) = *(u_long128 *)pVec2;
                }
            }
        }
        {
            Physics *pPhys = this->m_unk38;
            int bClear = 0;
            if (pPhys != 0 && (*(unsigned short *)((char *)pPhys + 0x106) & 0x800)) {
                char *pSrc = (char *)this->m_unk3C;
                float *pPos = (pSrc != 0) ? (float *)(pSrc + 0x80) : (float *)((char *)this + 0x190);
                float sp90[4];
                float fRaise = 1.5f;
                *(u_long128 *)sp90 = *(u_long128 *)pPos;
                sp90[1] += fRaise;
                GetGroundPos__7MathAPIFPA4_f(sp90);
                pSrc = (char *)this->m_unk3C;
                pPos = (pSrc != 0) ? (float *)(pSrc + 0x80) : (float *)((char *)this + 0x190);
                if (FastMath_Fabs__Ff(pPos[1] - sp90[1]) < 0.5f) {
                    if (FastMath_Fabs__Ff(pPos[1] - this->m_unk214) < 0.5f) {
                        WCX_F32(pPhys, 0) = 0.0f;
                        __dl__FPv(pPhys);
                        bClear = 1;
                    }
                } else {
                    SetPhysicsType__7PhysicsFUiPA4_f(pPhys, *(unsigned short *)((char *)pPhys + 0x106) & ~0x800, 0);
                }
            } else if (pPhys != 0 && (WCX_U32(pPhys, 0x108) & 2)) {
                if (this->m_unk1C8 == 1) {
                    PlaySound__15EntityBaseClassFUi((EntityBaseClass *)this, 0x26FU);
                } else {
                    PlaySound__15EntityBaseClassFUi((EntityBaseClass *)this, 0x2B0U);
                }
                WCX_U8(this, 0x103) = 0xFF;
                char *pCC = (char *)WCX_PTR(pPhys, 0xCC);
                if (pCC != 0 && WCX_U32(pCC, 0x100) != 0) {
                    SetPhysicsType__7PhysicsFUiPA4_f(pPhys, *(unsigned short *)((char *)pPhys + 0x106) | 0x800, 0);
                } else {
                    WCX_F32(pPhys, 0) = 0.0f;
                    __dl__FPv(pPhys);
                    bClear = 1;
                }
            }
            if (bClear) {
                this->m_unk38 = 0;
            }
        }
        if (this->m_unk1C8 == 1) {
            char *pPl = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
            char *pPlCC = (char *)WCX_PTR(WCX_PTR(pPl, 0x38), 0xCC);
            if (pPlCC == 0 || WCX_U32(this, 4) != WCX_U32(pPlCC, 0x100)) {
                char *pSrc = (char *)this->m_unk3C;
                float *pA2 = (pSrc != 0) ? (float *)(pSrc + 0x80) : (float *)((char *)this + 0x190);
                char *pPlPos = (char *)WCX_PTR(pPl, 0x3C);
                float *pA1 = (pPlPos != 0) ? (float *)(pPlPos + 0x80) : (float *)(pPl + 0x190);
                float spC0[4];
                sceVu0SubVector(spC0, pA1, pA2);
                float *pDir = (float *)((char *)WCX_PTR(this, 0x3C) + 0x40);
                if (FastMath_Fabs__Ff(spC0[1]) < 1.5f && sceVu0InnerProduct(spC0, spC0) < 16.0f && FastMath_Fabs__Ff(sceVu0InnerProduct(pDir, spC0)) < 2.0f) {
                    char *pPlA = (char *)WCX_PTR(pPl, 0x3C);
                    float *pPlQ = (pPlA != 0) ? (float *)(pPlA + 0x90) : (float *)(pPl + 0x1A0);
                    char *pMy = (char *)WCX_PTR(this, 0x3C);
                    float *pMyQ = (pMy != 0) ? (float *)(pMy + 0x90) : (float *)((char *)this + 0x1A0);
                    float f20 = FastMath_Fabs__Ff(Round180__Ff(pMyQ[1] - pPlQ[1]));
                    if (sceVu0InnerProduct((float *)((char *)pDir + 0x20), spC0) < 0.0f && !(f20 <= 90.0f) && (f20 < 270.0f)) {
                        SetPling__6PlayerFQ26Player9PlingTypeP15EntityBaseClassUi(pPl, 3, this, 0U);
                        return;
                    }
                }
            }
        } else {
            char *pPl2 = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
            char *pPl2CC = (char *)WCX_PTR(WCX_PTR(pPl2, 0x38), 0xCC);
            if (pPl2CC == 0 || WCX_U32(this, 4) != WCX_U32(pPl2CC, 0x100)) {
                char *pSrc = (char *)this->m_unk3C;
                float *pA2 = (pSrc != 0) ? (float *)(pSrc + 0x80) : (float *)((char *)this + 0x190);
                char *pPlPos = (char *)WCX_PTR(pPl2, 0x3C);
                float *pA1 = (pPlPos != 0) ? (float *)(pPlPos + 0x80) : (float *)(pPl2 + 0x190);
                float spD0[4];
                sceVu0SubVector(spD0, pA1, pA2);
                if (FastMath_Fabs__Ff(spD0[1]) < 1.5f && sceVu0InnerProduct(spD0, spD0) < 16.0f) {
                    float fAng = 57.295776f * atan2f(spD0[0], spD0[2]);
                    char *pPlA = (char *)WCX_PTR(pPl2, 0x3C);
                    float *pPlQ = (pPlA != 0) ? (float *)(pPlA + 0x90) : (float *)(pPl2 + 0x1A0);
                    if (FastMath_Fabs__Ff(Round180__Ff(fAng - pPlQ[1])) < 45.0f) {
                        SetPling__6PlayerFQ26Player9PlingTypeP15EntityBaseClassUi(pPl2, 1, this, 0U);
                        return;
                    }
                }
            }
        }
        break;
    }
    case 3: {
        if (WCX_U8(this, 0xE9) != 0) {
            WCX_U32(this, 0x10C) &= 0xFDFFFFFF;
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, WoodenChest_OpenSeq);
            PlaySound__15EntityBaseClassFUi((EntityBaseClass *)this, 0x94U);
            WriteApparitionData__15EntityBaseClassFicUi((EntityBaseClass *)this, 0, (char)WCX_VCALL(this, 0xC), 0U);
        }
        if (WCX_S32(this, 0x160) == 0) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 4);
            return;
        }
        break;
    }
    case 4: {
        int *pEnt = &this->m_unk1B0;
        int *pCnt;
        int i;
        int nAny = 0;
        if (WCX_U8(this, 0xE9) != 0) {
            WCX_S32(this, 0x1F0) = this->m_unk1B4;
            WCX_S32(this, 0x1F4) = this->m_unk1BC;
            WCX_S32(this, 0x1F8) = this->m_unk1C4;
            nAny = 0;
            if (ReadApparitionData__15EntityBaseClassFiUi((EntityBaseClass *)this, 3, 0U) < 2) {
                WriteApparitionData__15EntityBaseClassFicUi((EntityBaseClass *)this, 3, 2, 0U);
                if (this->m_unk1CC != 0) {
                    WriteApparitionData__15EntityBaseClassFicUi((EntityBaseClass *)this, 1, -3, 0U);
                }
            } else {
                pCnt = &this->m_unk1B0;
                for (i = 0; i < 3; i++) {
                    if (pCnt[1] > 0) {
                        int nType = GetVarType__6PickupFi((void *)pCnt[0], 0);
                        if (nType != 8 && nType != 7) {
                            if (nAny == 0) {
                                nAny = 1;
                            }
                            WCX_S32(this, 0x1F0 + i * 4) = 0;
                        }
                    }
                    pCnt += 2;
                }
                if (nAny != 0) {
                    SpawnPickups__15EntityBaseClassFiiPA4_fb((EntityBaseClass *)this, 0, 1, 0, 0);
                }
            }
        }
        for (i = 0; i < 3; i++) {
            int nCount = WCX_S32(this, 0x1F0 + i * 4);
            if (nCount > 0) {
                int nId = pEnt[0];
                if (nId == 0 && pEnt[1] >= 9) {
                    SpawnPickups__15EntityBaseClassFiiPA4_fb((EntityBaseClass *)this, 0, 1, 0, 0);
                    WCX_S32(this, 0x1F0 + i * 4) -= 1;
                } else {
                    void *pPickup = SpawnPickups__15EntityBaseClassFiiPA4_fb((EntityBaseClass *)this, nId, nCount, 0, 0);
                    WCX_S32(this, 0x1F0 + i * 4) = 0;
                    if (pEnt[0] == 8 || pEnt[0] == 7) {
                        if (pPickup == 0) {
                            CdsAssert__FPciPc("WoodenChest.cpp", 0x1F8, "pPickup");
                        }
                        WCX_S32(pPickup, 0x1C4) = (int)WCX_F32(this, 0x4);
                    }
                }
                return;
            }
            pEnt += 2;
        }
        if (this->m_unk1C8 != 2) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 5);
            return;
        }
        if (WCX_S32(this, 0x160) == 0) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, -2);
            return;
        }
        break;
    }
    case 5: {
        if (WCX_U8(this, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, WoodenChest_FadeSeq);
            RemoveFromBGAnimList__15EntityBaseClassFv((EntityBaseClass *)this);
        }
        if (WCX_S32(this, 0x160) == 0) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, -2);
            return;
        }
        break;
    }
    case 13: {
        if (WCX_U8(this, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, LockedChest_OpenSeq);
            PlaySound__15EntityBaseClassFUi((EntityBaseClass *)this, 0x92U);
            WriteApparitionData__15EntityBaseClassFicUi((EntityBaseClass *)this, 1, -3, 0U);
            WriteApparitionData__15EntityBaseClassFicUi((EntityBaseClass *)this, 0, (char)WCX_VCALL(this, 0xC), 0U);
        }
        if (WCX_S32(this, 0x160) == 0) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 4);
            return;
        }
        break;
    }
    case 6: {
        if (WCX_U8(this, 0xE9) != 0) {
            char *pSub = (this->m_unk3C != 0) ? (this->m_unk3C + 0x90) : ((char *)this + 0x1A0);
            WCX_S32(pSub, 0) = 0;
            pSub = (this->m_unk3C != 0) ? (this->m_unk3C + 0x90) : ((char *)this + 0x1A0);
            WCX_S32(pSub, 8) = 0;
            if (this->m_unkD4 == 0) {
                void *pShadow = __nw__FUi(0x10U);
                if (pShadow != 0) {
                    pShadow = __ct__6ShadowFQ26Shadow10ShadowTypeUi(pShadow, 1, 0x87000007U);
                }
                this->m_unkD4 = (char *)pShadow;
                if (this->m_unkD4 == 0) {
                    CdsAssert__FPciPc("WoodenChest.cpp", 0x243, "mpShadow");
                }
            }
            WCX_U32(this, 0x10C) |= 0x031B1902;
            if (this->m_unk38 == 0) {
                void *pPhys = __nw__FUi(0x120U);
                if (pPhys != 0) {
                    pPhys = __ct__7PhysicsFv(pPhys);
                }
                this->m_unk38 = (Physics *)pPhys;
                if (this->m_unk38 == 0) {
                    CdsAssert__FPciPc("WoodenChest.cpp", 0x249, "mpPhysics");
                }
            }
            SetPhysicsType__7PhysicsFUiPA4_f(this->m_unk38, 0x12U, 0);
            WCX_U8(this, 0xEB) = 1;
            {
                char *pSh = this->m_unkD4;
                if (pSh != 0) {
                    WCX_S32(pSh, 0) = 1;
                    char *pSh2 = (char *)WCX_PTR(pSh, 0xC);
                    if (pSh2 != 0) {
                        WCX_S32(pSh2, 0x18) = 1;
                    }
                }
            }
            WCX_U8(this, 0x103) = 0x10;
            WCX_U32(this, 0x104) = 0x40000000;
            WCX_U32(this, 0x108) = 0x40000000;
            *(short *)((char *)this + 0x15C) = 0x32;
            *(short *)((char *)this + 0x15E) = 0;
            ModifyLoadClass__15EntityBaseClassFQ215EntityBaseClass9LoadClass((EntityBaseClass *)this, 3);
            WCX_U8(this, 0xEA) = 1;
            WCX_U8(this, 0x1F) = 1;
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Wakeup_Seq);
            {
                char *pB = this->m_unk3C;
                char *pV = (pB != 0) ? (pB + 0x80) : ((char *)this + 0x190);
                *(u_long128 *)((char *)this + 0x200) = *(u_long128 *)pV;
            }
            WCX_U8(this, 0xE8) |= 8;
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi((EntityBaseClass *)this, 0x56U, 0x1AU);
        if (WCX_S32(this, 0x160) == 0) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 7);
            return;
        }
        break;
    }
    case 7: {
        if (WCX_U8(this, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Attack_Seq);
        }
        FacePlayer__15EntityBaseClassFf((EntityBaseClass *)this, 0.04f);
        PlaySoundOnFrame__15EntityBaseClassFUiUi((EntityBaseClass *)this, 0x54U, 0x18U);
        Physics *pPh = this->m_unk38;
        if (pPh != 0 && (WCX_U32(pPh, 0x108) & 0x400)) {
            if (pPh != 0) {
                __dl__FPv(pPh);
            }
            this->m_unk38 = 0;
            WCX_U32(this, 0x10C) &= 0xFDFFFFFF;
            EnableSleep__15EntityBaseClassFbb((EntityBaseClass *)this, 0, 0);
            this->m_unk1E0 = 0;
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 0xB);
            return;
        }
        char *pPl = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
        char *pPlA = *(char **)(pPl + 0x3C);
        float *pPlPos = (pPlA != 0) ? (float *)(pPlA + 0x80) : (float *)(pPl + 0x190);
        if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])((char *)this + 0x200), (float (*)[4])pPlPos) <= this->m_unk1D4)) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 0xA);
        }
        if (WCX_S32(this, 0x160) == 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Attack_Seq);
            return;
        }
        break;
    }
    case 10: {
        if (WCX_U8(this, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Attack_Seq);
        }
        if ((unsigned int *)this->m_unk140 == Mimic_Attack_Seq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi((EntityBaseClass *)this, 0x54U, 0x18U);
        } else if ((unsigned int *)this->m_unk140 == Mimic_Idle_Seq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi((EntityBaseClass *)this, 0x339U, 0x23U);
        }
        RotateTo__15EntityBaseClassFff((EntityBaseClass *)this,
            GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f((void *)this, (void *)((char *)this + 0x200), 0),
            0.04f);
        char *pA = this->m_unk3C;
        float *pTgt = (pA != 0) ? (float *)(pA + 0x80) : (float *)((char *)this + 0x190);
        if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])((char *)this + 0x200), (float (*)[4])pTgt) < 2.0f) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 8);
        }
        char *pPl = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
        char *pPlA = *(char **)(pPl + 0x3C);
        float *pPlPos = (pPlA != 0) ? (float *)(pPlA + 0x80) : (float *)(pPl + 0x190);
        if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])((char *)this + 0x200), (float (*)[4])pPlPos) < this->m_unk1D4) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 7);
        }
        if (WCX_S32(this, 0x160) == 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Idle_Seq);
            return;
        }
        break;
    }
    case 8: {
        if (WCX_U8(this, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Idle_Seq);
        }
        FacePlayer__15EntityBaseClassFf((EntityBaseClass *)this, 0.04f);
        char *pPl = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
        char *pPlA = *(char **)(pPl + 0x3C);
        float *pPlPos = (pPlA != 0) ? (float *)(pPlA + 0x80) : (float *)(pPl + 0x190);
        if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])((char *)this + 0x200), (float (*)[4])pPlPos) < this->m_unk1D4) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 7);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi((EntityBaseClass *)this, 0x339U, 0x23U);
        if (WCX_S32(this, 0x160) == 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Idle_Seq);
            return;
        }
        break;
    }
    case 12: {
        if (WCX_U8(this, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Idle_Seq);
        }
        PlaySoundOnFrame__15EntityBaseClassFUiUi((EntityBaseClass *)this, 0x339U, 0x23U);
        if (WCX_S32(this, 0x160) == 0) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 8);
            return;
        }
        break;
    }
    case 9: {
        if (WCX_U8(this, 0xE9) != 0) {
            char *pPl = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
            char *pPlA = *(char **)(pPl + 0x3C);
            float *pPlPos = (pPlA != 0) ? (float *)(pPlA + 0x80) : (float *)(pPl + 0x190);
            Physics *pPh = this->m_unk38;
            WCX_F32(pPh, 0x11C) = Round180__Ff(GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f((void *)this, (void *)pPlPos, 0));
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Damaged_Seq);
            PlaySound__15EntityBaseClassFUi((EntityBaseClass *)this, 0x55U);
        }
        if (WCX_S32(this, 0x160) == 0) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 7);
            return;
        }
        break;
    }
    case 11: {
        if (WCX_U8(this, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi((EntityBaseClass *)this, Mimic_Death_Seq);
            PlaySound__15EntityBaseClassFUi((EntityBaseClass *)this, 0x53U);
            WCX_U32(this, 0x10C) &= 0xF8FFFFFF;
            char *pSh = this->m_unkD4;
            if (pSh != 0) {
                WCX_S32(pSh, 0) = 0;
                char *pSh2 = (char *)WCX_PTR(pSh, 0xC);
                if (pSh2 != 0) {
                    WCX_S32(pSh2, 0x18) = 0;
                }
            }
            WriteApparitionData__15EntityBaseClassFicUi((EntityBaseClass *)this, 0, (char)WCX_VCALL(this, 0xC), 0U);
        }
        if (!(GetFrameTime__6PMNodeFv(this->m_unk3C) <= 30.0f)) {
            SetState__15EntityBaseClassFi((EntityBaseClass *)this, 4);
        }
        break;
    }
    default:
        return;
    }
}

// FUNCTION: 0x001A30B0 __ct__11WoodenChestFv
WoodenChest::WoodenChest() : EntityBaseClass((EntityBaseClass::LoadClass)1, 0U)
{
    m_unk1EC = 0;
    m_unk210 = 0;
}
