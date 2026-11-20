#include "ClockworkFlyer.h"
#include "MathAPI.h"
#include "types.h"

// TODO(header): foreign declarations
extern "C" float FastMath_Fabs__Ff(float f);
extern char gEng[105360];
extern "C" void GetForwardVector__6CameraFRA4_f(void *pCam, float (*pOut)[4]);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
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
extern "C" void *__ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nArg);
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
extern "C" int RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(void *pThis, void *pOther, unsigned int nArg);
extern "C" float sinf(float fX);
extern "C" float sqrtf(float fX);
extern "C" unsigned int CreateDamageFx__15EntityBaseClassFfUi(void *pThis, float fInterval, unsigned int nFlag);
extern "C" void ChangeDamageFxInterval__15EntityBaseClassFUif(void *pThis, unsigned int nFx, float fInterval);
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, struct tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern void *mpEntMgr__15EntityBaseClass;
extern void *mPlayerAPI__13EntityManager;
extern "C" void GetGroundPos__7PhysicsFv(float *pOut, void *pPhysics);
extern "C" int SulfurCheck__7PhysicsFv(void *pThis);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int nType, float (*pPos)[4]);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *pThis, int nType, unsigned int nArg);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nA, char cB, unsigned int nC);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" struct tagWaypointGroup *GetWaypointGroupInfo__15WaypointManagerFUi(void *pThis, unsigned int nGroupId);
extern "C" int sprintf(char *pBuf, const char *pFmt, ...);
extern char ClockworkFlyer_LoadMeshSeq[20];
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

// DRAFT: 0x001E8F50 DoDartTasks__14ClockworkFlyerFv
// note: DIFF 117 (frame 0x60 vs 0x50). Original keeps this in s0 with no s2 save and copies @835 to 0x30(sp); ours saves s2 for this when a pointer alias takes s0. Tried: top-level local (155), store-point read (157), direct local read at store (155), alias pointer (117).
int ClockworkFlyer::DoDartTasks() {
    u_long128 vDefault = *(u_long128 *)0x004C92A0;
    u_long128 *pDefault = &vDefault;
    if (m_unk2A0 == 0) {
        ClockworkFlyer *pTarget = GetTarget();
        char *pTgtPoint;
        if (pTarget->m_unk3C != 0) {
            pTgtPoint = pTarget->m_unk3C + 0x80;
        } else {
            pTgtPoint = (char *)pTarget + 0x190;
        }
        float fToTarget = Distance__7MathAPIFPA4_fPA4_f((char *)this + 0x220, (float (*)[4])pTgtPoint);
        if (!(fToTarget <= *(float *)&m_unk1D8)) {
            SetState__15EntityBaseClassFi(this, 5);
            return 1;
        }
        pTarget = GetTarget();
        if (pTarget->m_unk3C != 0) {
            pTgtPoint = pTarget->m_unk3C + 0x80;
        } else {
            pTgtPoint = (char *)pTarget + 0x190;
        }
        char *pSelfPos;
        if (m_unk3C != 0) {
            pSelfPos = m_unk3C + 0x80;
        } else {
            pSelfPos = (char *)this + 0x190;
        }
        float fSelf = Distance__7MathAPIFPA4_fPA4_f(pSelfPos, (float (*)[4])pTgtPoint);
        if (!(fSelf <= 15.0f)) {
            SetState__15EntityBaseClassFi(this, 7);
            return 1;
        }
        if (MathAPI::RandomIntRange(0, 4) == 0) {
            SetupDartDest();
            SetState__15EntityBaseClassFi(this, 9);
            return 1;
        }
        if (!InCameraView()) {
            SetState__15EntityBaseClassFi(this, 6);
            return 1;
        }
        if (!RequestAttack__15EntityBaseClassFP15EntityBaseClassUi(this, m_unk2C8, 0x3C)) {
            SetState__15EntityBaseClassFi(this, 6);
            return 1;
        }
        SetState__15EntityBaseClassFi(this, 0xB);
        return 1;
    }
    PitchLevelOut();
    FaceTarget(0.05f);
    char *pOwnPoint;
    if (m_unk3C != 0) {
        pOwnPoint = m_unk3C + 0x80;
    } else {
        pOwnPoint = (char *)this + 0x190;
    }
    float aVec[4];
    sceVu0SubVector(aVec, (float *)((char *)this + 0x290), (float *)pOwnPoint);
    if (m_unk38 != 0) {
        *(u_long128 *)m_unk38 = *pDefault;
    }
    float fLen = sqrtf(sceVu0InnerProduct(aVec, aVec));
    if (m_unk2C4 != 0) {
        float fSin = sinf(m_unk2C0);
        *(float *)(pOwnPoint + 4) = m_unk290[1] + 0.7f * fSin;
        m_unk2C0 = m_unk2C0 + 0.1f;
        return 0;
    }
    if (fLen <= 1.0f) {
        m_unk2C4 = 1;
        m_unk2C0 = 0.0f;
        return 0;
    }
    sceVu0Normalize(aVec, aVec);
    sceVu0ScaleVector(aVec, aVec, 1.4f);
    if (m_unk38 != 0) {
        *(u_long128 *)m_unk38 = *(u_long128 *)aVec;
    }
    return 0;
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

// FUNCTION: 0x001E9270 InCameraView__14ClockworkFlyerFv
int ClockworkFlyer::InCameraView() {
    float afFwd[4];
    float afVec[4];
    char *pPos;
    char *pCam = gEng + 0x19760;
    GetForwardVector__6CameraFRA4_f(pCam, &afFwd);
    if (m_unk3C != 0) {
        pPos = m_unk3C + 0x80;
    } else {
        pPos = (char *)this + 0x190;
    }
    sceVu0SubVector(afVec, (float *)pPos, (float *)pCam);
    MathAPI::VectorRotateY(&afVec, 50.0f);
    if (sceVu0InnerProduct(afFwd, afVec) < 0.0f) {
        return 0;
    }
    MathAPI::VectorRotateY(&afVec, -100.0f);
    if (sceVu0InnerProduct(afFwd, afVec) < 0.0f) {
        return 0;
    }
    return 1;
}

// DRAFT: 0x001E9340 SetupDartDest__14ClockworkFlyerFv
// note: 38 words, size 0x184 vs 0x180. Both RandomFloatRange calls load arg2 into f13 first (original), ours loads arg1 into f12 first; tried -1.0f*f vs f*-1.0f, 4.0f*(float)r, fMin/fMax locals, hoisted owner id, float period local: no change.
void ClockworkFlyer::SetupDartDest() {
    ClockworkFlyer *pTarget = GetTarget();
    char *pTgtPoint;
    if (pTarget->m_unk3C != 0) {
        pTgtPoint = pTarget->m_unk3C + 0x80;
    } else {
        pTgtPoint = (char *)pTarget + 0x190;
    }
    char *pOwnPoint;
    if (m_unk3C != 0) {
        pOwnPoint = m_unk3C + 0x80;
    } else {
        pOwnPoint = (char *)_pad190;
    }
    sceVu0SubVector(m_unk290, (float *)pOwnPoint, (float *)pTgtPoint);
    m_unk290[1] = 0.0f;
    float fAngle = MathAPI::RandomFloatRange(35.0f, 60.0f);
    if (MathAPI::RandomIntRange(0, 1) == 0) {
        fAngle = -1.0f * fAngle;
    }
    MathAPI::VectorRotateY((float (*)[4])m_unk290, fAngle);
    sceVu0Normalize(m_unk290, m_unk290);
    sceVu0ScaleVector(m_unk290, m_unk290, 5.0f + (float)MathAPI::RandomIntRange(0, 2) * 4.0f);
    m_unk290[1] = MathAPI::RandomFloatRange(2.5f, 7.5f);
    pTarget = GetTarget();
    if (pTarget->m_unk3C != 0) {
        pTgtPoint = pTarget->m_unk3C + 0x80;
    } else {
        pTgtPoint = (char *)pTarget + 0x190;
    }
    sceVu0AddVector(m_unk290, m_unk290, (float *)pTgtPoint);
    int nPeriod = (int)(60.0f * (0.5f + 0.5f * (float)MathAPI::RandomIntRange(0, 3)));
    m_unk2A0 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, nPeriod, true);
    m_unk2C4 = 0;
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

// FUNCTION: 0x001E95E0 DetermineStateByDistance__14ClockworkFlyerFv
int ClockworkFlyer::DetermineStateByDistance() {
    char *pTargetPos;
    ClockworkFlyer *pTarget = GetTarget();
    if (pTarget->m_unk3C != 0) {
        pTargetPos = pTarget->m_unk3C + 0x80;
    } else {
        pTargetPos = (char *)pTarget + 0x190;
    }
    float fToTarget = Distance__7MathAPIFPA4_fPA4_f((char *)this + 0x220, (float (*)[4])pTargetPos);
    pTarget = GetTarget();
    if (pTarget->m_unk3C != 0) {
        pTargetPos = pTarget->m_unk3C + 0x80;
    } else {
        pTargetPos = (char *)pTarget + 0x190;
    }
    char *pSelfPos;
    if (m_unk3C != 0) {
        pSelfPos = m_unk3C + 0x80;
    } else {
        pSelfPos = (char *)this + 0x190;
    }
    float fSelf = Distance__7MathAPIFPA4_fPA4_f(pSelfPos, (float (*)[4])pTargetPos);
    if (fToTarget < *(float *)&m_unk1D8) {
        if (fSelf < 15.0f) {
            return 9;
        }
        return 7;
    }
    if (MathAPI::RandomIntRange(0, 2) == 0) {
        return 6;
    }
    return 5;
}

// FUNCTION: 0x001E96B0 EscapeIfApproachStalled__14ClockworkFlyerFv
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
    if (fDist <= 0.9f) {
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

// FUNCTION: 0x001E9760 EscapeIfStalled__14ClockworkFlyerFv
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
    if (fDist <= 0.9f) {
        SetState__15EntityBaseClassFi(this, DetermineStateByDistance());
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

// FUNCTION: 0x001E9890 FlyerPitchChange__14ClockworkFlyerFv
int ClockworkFlyer::FlyerPitchChange() {
    static float aTolerance;
    static char init;
    static float aDistPercent;
    float *pVal;
    float fDist;
    float fStep;

    if (init == 0) {
        aTolerance = 1.0f;
        init = 1;
    }
    {
        static char init;
        if (init == 0) {
            aDistPercent = 0.1f;
            init = 1;
        }
    }
    pVal = m_unk3C != 0 ? (float *)(m_unk3C + 0x90) : &m_unk1A0;
    fDist = FastMath_Fabs__Ff(*pVal - m_unk280);
    fStep = fDist * aDistPercent;
    if (fDist < aTolerance) {
        pVal = m_unk3C != 0 ? (float *)(m_unk3C + 0x90) : &m_unk1A0;
        *pVal = m_unk280;
        return 1;
    }
    pVal = m_unk3C != 0 ? (float *)(m_unk3C + 0x90) : &m_unk1A0;
    if (*pVal < m_unk280) {
        pVal = m_unk3C != 0 ? (float *)(m_unk3C + 0x90) : &m_unk1A0;
        *pVal += fStep;
    } else {
        pVal = m_unk3C != 0 ? (float *)(m_unk3C + 0x90) : &m_unk1A0;
        *pVal -= fStep;
    }
    return 0;
}

// FUNCTION: 0x001E99B0 FlyerFlyTo__14ClockworkFlyerFPA4_fff
int ClockworkFlyer::FlyerFlyTo(float (*pDest)[4], float fDist, float fSpeed) {
    float vDir[4];
    float (*pTgt)[4];

    pTgt = m_unk3C != 0 ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])(char *)_pad190;
    if (Distance__7MathAPIFPA4_fPA4_f(pDest, pTgt) > fDist) {
        pTgt = m_unk3C != 0 ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])(char *)_pad190;
        sceVu0SubVector(vDir, (float *)pDest, (float *)pTgt);
        sceVu0Normalize(vDir, vDir);
        sceVu0ScaleVector(vDir, vDir, fSpeed);
        pTgt = m_unk3C != 0 ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])(char *)_pad190;
        sceVu0AddVector((float *)(m_unk3C != 0 ? (float (*)[4])(m_unk3C + 0x80) : (float (*)[4])(char *)_pad190), vDir, (float *)pTgt);
        return 0;
    }
    return 1;
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

// FUNCTION: 0x001E9B40 OnHitEvent__14ClockworkFlyerFP15EntityBaseClassiUiUi
int ClockworkFlyer::OnHitEvent(EntityBaseClass *pOther, int nDmg, unsigned int a, unsigned int b) {
    if (m_unkF4 != 0) {
        int nLeft = m_unk284 - nDmg;
        if (nLeft > 0) {
            m_unk284 = nLeft;
            return 1;
        }
    }
    m_unk284 -= nDmg;
    if (m_unk284 <= 0) {
        m_unk234 = a;
        SetState__15EntityBaseClassFi(this, 0x10);
        return 2;
    }
    if ((float)m_unk284 < 213.75f && m_unk28C == 0) {
        m_unk28C = (char *)CreateDamageFx__15EntityBaseClassFfUi(this, 90.0f, 0);
    }
    if ((float)m_unk284 < 85.5f) {
        if (m_unk28C != 0) {
            ChangeDamageFxInterval__15EntityBaseClassFUif(this, (unsigned int)m_unk28C, 20.0f);
        }
    }
    m_unk238 = a;
    SetState__15EntityBaseClassFi(this, 0xE);
    return 1;
}

// DRAFT: 0x001E9C60 Execute__14ClockworkFlyerFv
// note: prologue, block A/9, case -1/9 and default transcribed; cases 0/10 onward untranscribed
void ClockworkFlyer::Execute() {
    float sp1E0[4];
    char sp50[0x20];
    char *pTarget;
    char *var_a0;
    void *p;
    int nState;

    if (m_unk38 != 0) {
        pTarget = m_unk3C;
        var_a0 = (char *)&_pad190;
        if (pTarget != 0) {
            var_a0 = pTarget + 0x80;
        }
        if (!(Distance__7MathAPIFPA4_fPA4_f(var_a0, (float (*)[4])m_unk220) <= (15.0f + *(float *)&m_unk1D8))) {
            nState = m_unk20;
            if (nState != 8 && nState != 0x11 && nState != 0x10 && nState != 0xE) {
                SetState__15EntityBaseClassFi(this, 8);
                SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x10U, 0);
                return;
            }
        }
    }

    GetGroundPos__7PhysicsFv(sp1E0, *(void **)(*(char **)(gEng + 0x1883C) + 0x38));
    m_unk240 = sp1E0[1];
    if (m_unk38 != 0 && SulfurCheck__7PhysicsFv(m_unk38) != 0) {
        WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0U);
        if (m_unk38 != 0) {
            __dl__FPv(m_unk38);
        }
        m_unk38 = 0;
        SetState__15EntityBaseClassFi(this, 0x11);
        return;
    }

    switch (m_unk20) {
    case -1:
    case 9:
        if (m_unkE9 != 0) {
            m_unk10C &= 0xF8FFFFFF;
            m_unk10C |= 0x071B1902;
            m_unk103 = 0x40;
            m_unk220[0] = m_unk1CC[0];
            m_unk220[1] = m_unk1CC[1];
            m_unk220[2] = m_unk1CC[2];
            m_unk230 = 0;
            if (m_unk1BC == 0.0f) {
                if (m_unk1C0 == 0.0f && m_unk1C4 == 0.0f) {
                    pTarget = m_unk3C;
                    var_a0 = (char *)&_pad190;
                    if (pTarget != 0) {
                        var_a0 = pTarget + 0x80;
                    }
                    m_unk1BC = *(float *)var_a0;
                    m_unk1C0 = *(float *)(var_a0 + 4);
                    m_unk1C4 = *(float *)(var_a0 + 8);
                }
            }
            m_unk15C = 0xC;
            m_unk15E = 0;
            m_unk104 = 0x40400000;
            m_unk108 = 0x40600000;
            if (m_unk1DC != 0) {
                m_unk1C8 = m_unk18C;
                m_unk1D8 = m_unk18C;
            }
            m_unk2A4 = 0;
            if (m_unk200 >= 0) {
                m_unk2A4 = (char *)GetWaypointGroupInfo__15WaypointManagerFUi((char *)mpEntMgr__15EntityBaseClass + 0x30, (unsigned int)m_unk200);
                if (m_unk2A4 == 0) {
                    sprintf(sp50, "Flyer refers to bad waypoint group ( group id = %d )", m_unk200);
                    CdsAssert__FPciPc("ClockworkFlyer.cpp", 0x17B, sp50);
                }
            }
            m_unk2A8 = 0;
            m_unk2AC = (m_unk2A4 != 0) ? (int)((struct tagWaypointGroup *)m_unk2A4)->nCount : 0;
        }
        if (m_unk1E4 != 2) {
            ClockworkFlyer *pTgt = GetTarget();
            char *var_a1 = (char *)pTgt + 0x190;
            if (pTgt->m_unk3C != 0) {
                var_a1 = pTgt->m_unk3C + 0x80;
            }
            float *var_s0 = &m_unk1A0;
            if (m_unk3C != 0) {
                var_s0 = (float *)(m_unk3C + 0x90);
            }
            var_s0[1] = GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, var_a1);
        }
        m_unk210[0] = m_unk1BC;
        m_unk210[1] = m_unk1C0;
        m_unk210[2] = m_unk1C4;
        {
            char *pPl = (char *)mPlayerAPI__13EntityManager;
            char *var_a1_2 = pPl + 0x190;
            if (*(char **)(pPl + 0x3C) != 0) {
                var_a1_2 = *(char **)(pPl + 0x3C) + 0x80;
            }
            if (Distance__7MathAPIFPA4_fPA4_f(m_unk210, (float (*)[4])var_a1_2) <= *(float *)&m_unk1C8) {
                if (m_unk38 == 0) {
                    p = __nw__FUi(0x120U);
                    if (p != 0) {
                        p = __ct__7PhysicsFv(p);
                    }
                    m_unk38 = (float *)p;
                    if (m_unk38 == 0) {
                        CdsAssert__FPciPc("ClockworkFlyer.cpp", 0x193, "mpPhysics");
                    }
                    if (m_unk1B8 == 0) {
                        if (((char *)m_unk38 + 0xA0) == 0) {
                            CdsAssert__FPciPc("ClockworkFlyer.cpp", 0x196, "pInfo");
                        }
                        *((unsigned char *)m_unk38 + 0xEC) &= ~0x80;
                    }
                    SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x10U, 0);
                }
                if (m_unkD4 == 0) {
                    p = __nw__FUi(0x10U);
                    if (p != 0) {
                        p = __ct__6ShadowFQ26Shadow10ShadowTypeUi(p, 1, 0x87000007U);
                    }
                    m_unkD4 = p;
                    if (m_unkD4 == 0) {
                        CdsAssert__FPciPc("ClockworkFlyer.cpp", 0x19E, "mpShadow");
                    }
                    if (m_unkD4 != 0) {
                        *(unsigned char *)m_unkD4 = 1;
                        if (*(char **)((char *)m_unkD4 + 0xC) != 0) {
                            *(unsigned char *)(*(char **)((char *)m_unkD4 + 0xC) + 0x18) = 1;
                        }
                    }
                }
                if (m_unk1E4 != 0) {
                    SetState__15EntityBaseClassFi(this, 0);
                    return;
                }
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)ClockworkFlyer_LoadMeshSeq);
                *(int *)((char *)m_unk38 + 0x84) = 0x40000000;
                PlaySound__15EntityBaseClassFUi(this, 0x4DU);
                nState = DetermineStateByDistance();
                SetState__15EntityBaseClassFi(this, nState);
                return;
            }
        }
        break;
    default:
        return;
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

// FUNCTION: 0x001EB390 __ct__14ClockworkFlyerFv
ClockworkFlyer::ClockworkFlyer() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 0xA);
    *(unsigned char **)this = __vt__14ClockworkFlyer;
    *(int *)((char *)this + 0x210) = 0;
    *(int *)((char *)this + 0x214) = 0;
    *(int *)((char *)this + 0x218) = 0;
    *(int *)((char *)this + 0x21C) = 0;
    *(int *)((char *)this + 0x220) = 0;
    *(int *)((char *)this + 0x224) = 0;
    *(int *)((char *)this + 0x228) = 0;
    *(int *)((char *)this + 0x22C) = 0;
    this->m_unk230 = 0;
    *(unsigned int *)((char *)this + 0x234) = 0;
    *(unsigned int *)((char *)this + 0x238) = 0;
    *(int *)((char *)this + 0x23C) = 0;
    *(int *)((char *)this + 0x240) = 0;
    *(int *)((char *)this + 0x244) = 0;
    this->m_unk248 = 0;
    *(int *)((char *)this + 0x250) = 0;
    *(int *)((char *)this + 0x254) = 0;
    *(int *)((char *)this + 0x258) = 0;
    *(int *)((char *)this + 0x25C) = 0;
    this->m_unk260 = 0;
    *(int *)((char *)this + 0x270) = 0;
    *(int *)((char *)this + 0x274) = 0;
    *(int *)((char *)this + 0x278) = 0;
    *(int *)((char *)this + 0x27C) = 0;
    *(int *)((char *)this + 0x280) = 0;
    if (!MathAPI::RandomIntRange(0, 1)) {
        this->m_unk284 = 0x11D;
    } else {
        this->m_unk284 = 0x168;
    }
    *(int *)((char *)this + 0x288) = 0x50;
    this->m_unk28C = 0;
    *(int *)((char *)this + 0x290) = 0;
    *(int *)((char *)this + 0x294) = 0;
    *(int *)((char *)this + 0x298) = 0;
    *(int *)((char *)this + 0x29C) = 0;
    this->m_unk2A0 = 0;
    this->m_unk2C8 = 0;
    *((unsigned char *)this + 0x166) = 1;
}
