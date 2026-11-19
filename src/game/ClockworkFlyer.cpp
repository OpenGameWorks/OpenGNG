#include "ClockworkFlyer.h"
#include "types.h"

// TODO(header): foreign declarations
class TimerAPI {
public:
    char _pad000[40];
    int CreateTimer(unsigned int, unsigned int, bool);
};

extern TimerAPI mTimerAPI__13EntityManager;
extern unsigned char __vt__14ClockworkFlyer[];
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *, void *);
extern "C" void RotateTo__15EntityBaseClassFff(void *, float, float);
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
class EntityBaseVtSlots {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual int IsValidTarget();
};
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int nInstance);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(void *pThis, float (*pPos)[4]);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" int DetermineStateByDistance__14ClockworkFlyerFv(void *pThis);
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, struct tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern void *mpEntMgr__15EntityBaseClass;
extern void *mPlayerAPI__13EntityManager;
struct tagWaypointGroup {
    char _pad000[4];
    unsigned int nCount;
};

// FUNCTION: 0x001E8ED0 SetSpawnedFromEntity__14ClockworkFlyerFPfPfi
void ClockworkFlyer::SetSpawnedFromEntity(float *pPos, float *pAlt, int nType) {
    m_unk1CC[0] = pPos[0];
    m_unk1CC[1] = pPos[1];
    m_unk1CC[2] = pPos[2];
    m_unk1D8 = 0x43160000;
    m_unk1B0 = nType;
    m_unk1C8 = 0x42960000;
    m_unk1E4 = 0;
    u_long128 *pDst;
    if (m_unk3C != 0) {
        pDst = (u_long128 *)(m_unk3C + 0x80);
    } else {
        pDst = (u_long128 *)((char *)this + 0x190);
    }
    *pDst = *(u_long128 *)pPos;
    if (pAlt != 0) {
        if (m_unk3C != 0) {
            pDst = (u_long128 *)(m_unk3C + 0x90);
        } else {
            pDst = (u_long128 *)((char *)this + 0x1A0);
        }
        *pDst = *(u_long128 *)pAlt;
    }
}

// FUNCTION: 0x001E91E0 GetNextPosition__14ClockworkFlyerFRA4_f
int ClockworkFlyer::GetNextPosition(float (&rOut)[4]) {
    tagWaypointGroup *pGroup = (tagWaypointGroup *)m_unk2A4;
    if (pGroup != 0) {
        unsigned int nIdx = m_unk2A8;
        if (nIdx < pGroup->nCount) {
            unsigned char bFlag;
            float *pPoint = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, pGroup, nIdx, bFlag);
            rOut[0] = pPoint[0];
            rOut[1] = pPoint[1];
            rOut[2] = pPoint[2];
            m_unk2A8 += 1;
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x001E94C0 FaceTarget__14ClockworkFlyerFf
void ClockworkFlyer::FaceTarget(float fAngle) {
    ClockworkFlyer *pTarget = GetTarget();
    char *pMark = pTarget->m_unk3C;
    char *pPoint;
    if (pMark != 0) {
        pPoint = pMark + 0x80;
    } else {
        pPoint = (char *)pTarget + 0x190;
    }
    float fYaw = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, pPoint);
    RotateTo__15EntityBaseClassFff(this, fYaw, fAngle);
}

// FUNCTION: 0x001E9520 GetTarget__14ClockworkFlyerFv
ClockworkFlyer *ClockworkFlyer::GetTarget() {
    if (m_unk248 != 0) {
        m_unk2C8 = InstanceIsValid__15EntityBaseClassFUi((unsigned int)m_unk248);
        if (m_unk2C8 == 0 || ((EntityBaseVtSlots *)m_unk2C8)->IsValidTarget() == 0) {
            m_unk2C8 = mPlayerAPI__13EntityManager;
            if (m_unk2C8 == 0) {
                CdsAssert__FPciPc("ClockworkFlyer.cpp", 0x55A, "m_pTarget");
            }
        }
    } else {
        m_unk2C8 = mPlayerAPI__13EntityManager;
        if (m_unk2C8 == 0) {
            CdsAssert__FPciPc("ClockworkFlyer.cpp", 0x561, "m_pTarget");
        }
    }
    return (ClockworkFlyer *)m_unk2C8;
}

// DRAFT: 0x001E96B0 EscapeIfApproachStalled__14ClockworkFlyerFv
// note: 4 differing lines; frame 0x30 vs 0x20 and sw/lwc1 spill of the address-taken 0.9f bit pattern (orig lui/ori/mtc1 into f1 with no stack slot). Tried pooled 0.9f (gp lwc1, many lines), integer-bit punned local (4 lines).
void ClockworkFlyer::EscapeIfApproachStalled() {
    if (m_unk260 != 0) {
        return;
    }
    char *pPos;
    if (m_unk3C != 0) {
        pPos = m_unk3C + 0x80;
    } else {
        pPos = (char *)this + 0x190;
    }
    float fDist = Distance__7MathAPIFPA4_fPA4_f(&m_unk250, (float (*)[4])pPos);
    unsigned int nLimit = 0x3F666666;
    if (fDist <= *(float *)&nLimit) {
        SetState__15EntityBaseClassFi(this, 9);
        return;
    }
    m_unk260 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 8, true);
    if (m_unk3C != 0) {
        pPos = m_unk3C + 0x80;
    } else {
        pPos = (char *)this + 0x190;
    }
    m_unk250 = *(u_long128 *)pPos;
}

// DRAFT: 0x001E9760 EscapeIfStalled__14ClockworkFlyerFv
// note: 4 differing lines; frame 0x30 vs 0x20 and sw/lwc1 spill of the address-taken 0x3F666666 bit pattern (orig lui/ori/mtc1 into f1). Same as EscapeIfApproachStalled.
void ClockworkFlyer::EscapeIfStalled() {
    if (m_unk260 != 0) {
        return;
    }
    char *pPos;
    if (m_unk3C != 0) {
        pPos = m_unk3C + 0x80;
    } else {
        pPos = (char *)this + 0x190;
    }
    float fDist = Distance__7MathAPIFPA4_fPA4_f(&m_unk250, (float (*)[4])pPos);
    unsigned int nLimit = 0x3F666666;
    if (fDist <= *(float *)&nLimit) {
        SetState__15EntityBaseClassFi(this, DetermineStateByDistance__14ClockworkFlyerFv(this));
        return;
    }
    m_unk260 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 8, true);
    if (m_unk3C != 0) {
        pPos = m_unk3C + 0x80;
    } else {
        pPos = (char *)this + 0x190;
    }
    m_unk250 = *(u_long128 *)pPos;
}

// FUNCTION: 0x001E9820 InitStallData__14ClockworkFlyerFv
void ClockworkFlyer::InitStallData() {
    u_long128 *pSrc;
    if (this->m_unk3C != 0) {
        pSrc = (u_long128 *)(this->m_unk3C + 0x80);
    } else {
        pSrc = (u_long128 *)((char *)this + 0x190);
    }
    m_unk250 = *pSrc;
    m_unk260 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 8, true);
}

// FUNCTION: 0x001E9A80 SetDefaultVars__14ClockworkFlyerFv
void ClockworkFlyer::SetDefaultVars() {
    m_unk1BC = 0;
    m_unk1C0 = 0;
    m_unk1C4 = 0;
    m_unk1C8 = 0x41C80000;
    m_unk1D8 = 0x420C0000;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F0 = 0;
    m_unk1F8 = 0;
    m_unk1DC = 0;
    m_unk1FC = 0x3DCCCCCD;
    m_unk200 = -1;
}

// FUNCTION: 0x001E9AF0 OnTimerEvent__14ClockworkFlyerFUi
void ClockworkFlyer::OnTimerEvent(unsigned int nId) {
    if (nId == m_unk230) {
        m_unk230 = 0;
    } else if (nId == m_unk260) {
        m_unk260 = 0;
    } else if (nId == m_unk2A0) {
        m_unk2A0 = 0;
    }
}

// FUNCTION: 0x001EB320 __dt__14ClockworkFlyerFv
extern "C" ClockworkFlyer *__dt__14ClockworkFlyerFv(ClockworkFlyer *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__14ClockworkFlyer;
        DestroyDamageFx__15EntityBaseClassFUi(pThis, (unsigned int)pThis->m_unk28C);
        pThis->m_unk28C = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
