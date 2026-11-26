#include "types.h"
#include "SpitterItem.h"
#include "EntityBaseClass.h"
#include "Physics.h"
#include "MathAPI.h"

// TODO(header): foreign declarations
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" Physics *__ct__7PhysicsFv(Physics *pThis);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pExpr);
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, struct tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern void *mpEntMgr__15EntityBaseClass;
extern unsigned char __vt__11SpitterItem[];
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" float FastMath_Fabs__Ff(float fValue);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(void *pThis, float (*pA)[4], float (*pB)[4]);
extern "C" int GetGroundPos__7MathAPIFPA4_f(void *pThis, float (*pPos)[4]);
extern "C" void SetFrameRate__6PMNodeFfb(void *pThis, float fRate, bool bFlag);
extern "C" tagWaypointGroup *GetWaypointGroupInfo__15WaypointManagerFUi(void *pThis, unsigned int nGroupId);
extern "C" int sprintf(char *pBuf, const char *pFmt, ...);
extern unsigned int SpitterItemTable[9];
extern unsigned char Beetle_IdleSeq[80];
extern unsigned char Beetle_StabDownDeathSeq[68];
extern unsigned char gEng[105360];
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void RotateTo__15EntityBaseClassFff(void *pThis, float fAngle, float fRate);
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nA, int nB);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int nType, float (*pMat)[4]);
extern "C" void SetVelocity__7PhysicsFff(void *pThis, float fX, float fY);
extern "C" float GetAngleBetweenVectors__7MathAPIFPfPf(float *pA, float *pB);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *pArg, float (*pPos)[4]);
extern unsigned char jtbl_0026B8E0[];

// FUNCTION: 0x001D9450 __dt__11SpitterItemFv
extern "C" SpitterItem *__dt__11SpitterItemFv(SpitterItem *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->m_unk0 = __vt__11SpitterItem;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001D94B0 GetClassName__11SpitterItemFv
const char *SpitterItem::GetClassName() {
    return "SpitterItem";
}

// FUNCTION: 0x001D94C0 SpitterItemBounceOff__11SpitterItemFv
void SpitterItem::SpitterItemBounceOff() {
    u_long128 sp20 = *(u_long128 *)m_unk38;
    if (MathAPI::RandomIntRange(1, 100) & 1) {
        MathAPI::VectorRotateY((float (*)[4])&sp20, MathAPI::RandomFloatRange(30.0f, 40.0f));
    } else {
        MathAPI::VectorRotateY((float (*)[4])&sp20, MathAPI::RandomFloatRange(-30.0f, -40.0f));
    }
    sceVu0Normalize((float *)&sp20, (float *)&sp20);
    sceVu0ScaleVector((float *)&sp20, (float *)&sp20, m_unk200);
    *(u_long128 *)m_unk38 = sp20;
    m_unk1B4 = 0xB4;
    m_unk1BC = 1;
    m_unk38->m_unk10C = 0;
    SetState__15EntityBaseClassFi(this, 3);
}

// FUNCTION: 0x001D95A0 GetNextPosition__11SpitterItemFRA4_f
int SpitterItem::GetNextPosition(float (&rOut)[4]) {
    if (m_unk204 != 0) {
        if (m_unk1E4 < *(unsigned int *)((char *)m_unk204 + 4)) {
            unsigned char bFlag;
            float *pPoint = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, m_unk204, m_unk1E4, bFlag);
            rOut[0] = pPoint[0];
            rOut[1] = pPoint[1];
            rOut[2] = pPoint[2];
            m_unk1E4 = m_unk1E4 + 1;
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x001D9630 OnTimerEvent__11SpitterItemFUi
void SpitterItem::OnTimerEvent(unsigned int) {
}

// FUNCTION: 0x001D9640 OnHitEvent__11SpitterItemFP15EntityBaseClassiUiUi
void SpitterItem::OnHitEvent(EntityBaseClass *pArg, int nType, unsigned int nA, unsigned int nB) {
    if (((unsigned char *)pArg)[0x10C] == 1) {
        if (m_unk1B8 == 2) {
            if (m_unk20 != 3) {
                SpitterItemBounceOff();
                m_unk10C &= 0xF8FFFFFF;
            }
        }
    }
}

// FUNCTION: 0x001D96B0 OnAttackEvent__11SpitterItemFP15EntityBaseClassi
void SpitterItem::OnAttackEvent(EntityBaseClass *pArg, int nType) {
    if (((unsigned char *)pArg)[0x10C] == 1) {
        if (m_unk1B8 == 2) {
            if (m_unk20 != 3) {
                SpitterItemBounceOff();
                m_unk10C &= 0xF8FFFFFF;
            } else {
                m_unk10C &= 0xF8FFFFFF;
            }
        } else {
            struct {
                int a;
                int b;
                int c;
            } local;
            local.a = 0;
            local.b = 0;
            local.c = 0;
            *(u_long128 *)m_unk38 = *(u_long128 *)&local;
            SetState__15EntityBaseClassFi(this, 1);
        }
    }
}

// Accessors for SpitterItem fields not yet named in SpitterItem.h (they sit in the
// SpitterItemGap or in padding), and for the entity manager's flag word.
#define SI_FIELD(T, off) (*(T *)((char *)this + (off)))
#define SI_MGR_FLAGS (*(unsigned int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058))

// DRAFT: 0x001D9750 Execute__11SpitterItemFv
// note: switch dispatch matches; frame 0xD0 vs 0x190, extra s2 save, this in s0 not s1, jump-table lui/addiu reloc differs (DIFF 520).
void SpitterItem::Execute() {
    static unsigned char init523;
    static float aReachDst;
    static unsigned char init536;
    static float aPhysicsOnDelta;
    u_long128 sp140;
    u_long128 sp160;
    u_long128 sp170;
    u_long128 sp180;
    struct {
        int a;
        int b;
        int c;
    } local;

    switch (m_unk20 + 2) {
    case 0:
        break;
    case 1:
        m_unk10C = (m_unk10C & 0xF8FFFFFF) | 0x02000000;
        SI_FIELD(unsigned char, 0x103) = 0x10;
        SI_FIELD(int, 0x15C) = 0x19;
        SI_FIELD(short, 0x15E) = 0;
        SI_FIELD(unsigned char, 0xEA) = 0;
        SI_FIELD(unsigned char, 0x179) = 0;
        SI_FIELD(int, 0x1C0) = 0;
        m_unk1E4 = 0;
        CheckVariable__15EntityBaseClassFii(this, m_unk1B8, 4);
        if (m_unk1E0 != -1) {
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 9U, 0);
            local.a = 0;
            local.b = 0;
            local.c = 0;
            *(u_long128 *)m_unk38 = *(u_long128 *)&local;
            if (m_unk1E0 >= 0) {
                m_unk204 = GetWaypointGroupInfo__15WaypointManagerFUi((char *)mpEntMgr__15EntityBaseClass + 0x30, m_unk1E0);
                if (m_unk204 == 0) {
                    char buf[0x40];
                    sprintf(buf, "Innocent refers to bad waypoint group ( group id = %d )", m_unk1E0);
                    CdsAssert__FPciPc("SpitterItem.cpp", 0x7B, buf);
                }
            }
            GetNextPosition(*(float (*)[4])((char *)this + 0x1F0));
            SetState__15EntityBaseClassFi(this, 2);
            return;
        }
        SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x9AU, 0);
        SetState__15EntityBaseClassFi(this, 0);
        return;
    case 2:
        if (SI_FIELD(unsigned char, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)SpitterItemTable[m_unk1B8 * 3]);
            m_unk1B4 = 0xB4;
            *(u_long128 *)((char *)this + 0x1D0) = *(u_long128 *)m_unk38;
        }
        if (!(SI_FIELD(unsigned char, 0xE8) & SI_MGR_FLAGS)) {
            int t = m_unk1B4;
            float f;
            if (t >= 0) {
                f = (float)t;
            } else {
                f = 2.0f * (float)(((unsigned int)t >> 1) | (t & 1));
            }
            float tf = f - *(float *)(gEng + 0x1E8);
            int v;
            if (!(tf >= 2.1474836e9f)) {
                v = (int)tf;
            } else {
                v = (int)(tf - 2.1474836e9f) | 0x80000000;
            }
            m_unk1B4 = v;
            if (m_unk1B4 == 0) {
                SetState__15EntityBaseClassFi(this, 1);
            }
            {
                unsigned int nPhys = *(unsigned int *)((char *)m_unk38 + 0x108);
                if ((m_unk1BC != -1) && (((nPhys & 0x20) != 0) || (nPhys & 2))) {
                    if (m_unk1B8 == 0) {
                        PlaySound__15EntityBaseClassFUi(this, 0x1BCU);
                    } else if (m_unk1B8 == 1) {
                        PlaySound__15EntityBaseClassFUi(this, 0x1F6U);
                    }
                    SI_FIELD(int, 0x1C0) += 1;
                    if (SI_FIELD(int, 0x1C0) >= m_unk1BC) {
                        SetState__15EntityBaseClassFi(this, 1);
                    }
                    sp140 = *(u_long128 *)m_unk38;
                    float fAng = GetAngleBetweenVectors__7MathAPIFPfPf((float *)&sp140, (float *)((char *)this + 0x1D0));
                    RotateTo__15EntityBaseClassFff(this, *(float *)((char *)m_unk38 + 0x11C) + fAng, 1.0f);
                    *(u_long128 *)((char *)this + 0x1D0) = sp140;
                }
            }
            if (sceVu0InnerProduct((float *)m_unk38, (float *)m_unk38) == 0.0f) {
                SetState__15EntityBaseClassFi(this, 1);
                return;
            }
        }
        break;
    case 3:
        if (SI_FIELD(unsigned char, 0xE9) != 0) {
            unsigned int *pSeq = (unsigned int *)SpitterItemTable[1 + m_unk1B8 * 3];
            if (pSeq != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, pSeq);
                if (m_unk1B8 == 0) {
                    PlaySound__15EntityBaseClassFUi(this, 0x1BBU);
                } else if (m_unk1B8 == 1) {
                    PlaySound__15EntityBaseClassFUi(this, 0x1F7U);
                }
            } else {
                SetState__15EntityBaseClassFi(this, -2);
            }
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 1U, 0);
            local.a = 0;
            local.b = 0;
            local.c = 0;
            *(u_long128 *)m_unk38 = *(u_long128 *)&local;
        }
        if (SI_FIELD(int, 0x160) == 0) {
            SetState__15EntityBaseClassFi(this, -2);
            return;
        }
        break;
    case 4:
        if (SI_FIELD(unsigned char, 0xE9) != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)Beetle_IdleSeq);
            float fRate = m_unk200;
            if (!(fRate >= 0.5f)) {
                fRate = 0.5f;
            }
            SetFrameRate__6PMNodeFfb(*(void **)((char *)this + 0x3C), fRate, true);
            RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])((char *)this + 0x1F0)), 0.04f);
            void *pNode = *(void **)((char *)this + 0x3C);
            float *pDst = (pNode != 0) ? *(float **)((char *)pNode + 0x80) : *(float **)((char *)this + 0x190);
            sceVu0SubVector((float *)&sp160, (float *)((char *)this + 0x1F0), pDst);
            sceVu0Normalize((float *)&sp160, (float *)&sp160);
            sceVu0ScaleVector((float *)&sp160, (float *)&sp160, m_unk200);
            *(u_long128 *)m_unk38 = sp160;
        }
        if (!(SI_FIELD(unsigned char, 0xE8) & SI_MGR_FLAGS)) {
            if (init523 == 0) {
                aReachDst = 1.0f;
                init523 = 1;
            }
            void *pNode2 = *(void **)((char *)this + 0x3C);
            float *pDst2 = (pNode2 != 0) ? *(float **)((char *)pNode2 + 0x80) : *(float **)((char *)this + 0x190);
            if (Distance__7MathAPIFPA4_fPA4_f((void *)((char *)this + 0x1F0), (float (*)[4])pDst2, (float (*)[4])((char *)this + 0x1F0)) <= aReachDst) {
                if (GetNextPosition(*(float (*)[4])((char *)this + 0x1F0)) == 0) {
                    SetState__15EntityBaseClassFi(this, -2);
                    return;
                }
                RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])((char *)this + 0x1F0)), 0.04f);
                void *pNode3 = *(void **)((char *)this + 0x3C);
                float *pDst3 = (pNode3 != 0) ? *(float **)((char *)pNode3 + 0x80) : *(float **)((char *)this + 0x190);
                sceVu0SubVector((float *)&sp170, (float *)((char *)this + 0x1F0), pDst3);
                sceVu0Normalize((float *)&sp170, (float *)&sp170);
                sceVu0ScaleVector((float *)&sp170, (float *)&sp170, m_unk200);
                *(u_long128 *)m_unk38 = sp170;
                return;
            }
        }
        break;
    case 5:
        if (SI_FIELD(unsigned char, 0xE9) != 0) {
            void *pNode = *(void **)((char *)this + 0x3C);
            float *pPos = (pNode != 0) ? *(float **)((char *)pNode + 0x80) : *(float **)((char *)this + 0x190);
            sp180 = *(u_long128 *)pPos;
            ((float *)&sp180)[1] += 10.0f;
            GetGroundPos__7MathAPIFPA4_f(&sp180, (float (*)[4])jtbl_0026B8E0);
            SI_FIELD(float, 0x208) = ((float *)&sp180)[1];
            return;
        }
        {
            void *pNode = *(void **)((char *)this + 0x3C);
            float *pPos = (pNode != 0) ? *(float **)((char *)pNode + 0x80) : *(float **)((char *)this + 0x190);
            sp180 = *(u_long128 *)pPos;
            ((float *)&sp180)[1] += 10.0f;
            if (GetGroundPos__7MathAPIFPA4_f(&sp180, (float (*)[4])jtbl_0026B8E0) != 0) {
                if (init536 == 0) {
                    aPhysicsOnDelta = 10.0f;
                    init536 = 1;
                }
                if (!(FastMath_Fabs__Ff(SI_FIELD(float, 0x208) - ((float *)&sp180)[1]) <= aPhysicsOnDelta)) {
                    SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12U, 0);
                }
            } else {
                SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12U, 0);
            }
        }
        if (!(SI_FIELD(unsigned char, 0xE8) & SI_MGR_FLAGS)) {
            int t = m_unk1B4;
            float f;
            if (t >= 0) {
                f = (float)t;
            } else {
                f = 2.0f * (float)(((unsigned int)t >> 1) | (t & 1));
            }
            float tf = f - *(float *)(gEng + 0x1E8);
            int v;
            if (!(tf >= 2.1474836e9f)) {
                v = (int)tf;
            } else {
                v = (int)(tf - 2.1474836e9f) | 0x80000000;
            }
            m_unk1B4 = v;
            if (m_unk1B4 == 0) {
                SetState__15EntityBaseClassFi(this, 1);
            }
            if (*(unsigned int *)((char *)m_unk38 + 0x108) & 2) {
                SetVelocity__7PhysicsFff(m_unk38, 0.0f, 0.0f);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)Beetle_StabDownDeathSeq);
            }
        }
        break;
    }
}
#undef SI_MGR_FLAGS
#undef SI_FIELD

// FUNCTION: 0x001D9F00 __ct__11SpitterItemFv
SpitterItem::SpitterItem() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 1);
    m_unk0 = __vt__11SpitterItem;
    Physics *pPhysics = (Physics *)__nw__FUi(0x120);
    if (pPhysics != 0) {
        pPhysics = __ct__7PhysicsFv(pPhysics);
    }
    m_unk38 = pPhysics;
    if (m_unk38 == 0) {
        CdsAssert__FPciPc("SpitterItem.cpp", 0x4C, "mpPhysics");
    }
    m_unk1E0 = -1;
}
