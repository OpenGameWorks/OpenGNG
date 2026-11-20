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

// FUNCTION: 0x001A30B0 __ct__11WoodenChestFv
WoodenChest::WoodenChest() : EntityBaseClass((EntityBaseClass::LoadClass)1, 0U)
{
    m_unk1EC = 0;
    m_unk210 = 0;
}
