#include "CameraFollow.h"
#include "Debug.h"
#include "PFrustrum.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" int abs(int);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" void sceVu0Normalize(float *dst, float *src);
extern "C" float GetLength__5PVec3Fv(float *this_vec);
extern float GAME_FPS;
extern unsigned char gPad[448];
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void __dl__FPv(void *pMem);
extern "C" void GetGroundPos__7PhysicsFv(float *pDst, void *pSrc);
extern PFrustrum *mpFrustum__15EntityBaseClass;
extern "C" void *__construct_array(void *pBlock, void *(*pCtor)(void *), void *(*pDtor)(void *, short), int nSize, int nCount);
extern "C" void __destroy_arr(void *pBlock, void *(*pDtor)(void *, short), int nSize, int nCount);
extern "C" void *__ct__5PVec3Fv(void *pThis);
extern "C" void *__dt__5PVec3Fv(void *pThis, short nFlag);
extern "C" void *__ct__12CameraSplineFv(void *pThis);
extern "C" void *__dt__13tag_CurveDataFv(void *pThis, short nFlag);
extern "C" void *__dt__15tag_ControlDataFv(void *pThis, short nFlag);
extern "C" float Round180__Ff(float);
extern "C" float FastMath_Sin180__Ff(float);
extern "C" void __mi__5PVec3FR5PVec3(float *ret, float *lhs, float *rhs);
extern "C" void __pl__5PVec3FR5PVec3(float *ret, float *lhs, float *rhs);
extern "C" float cosf(float x);
extern "C" float sinf(float x);
extern "C" float sqrtf(float x);
extern "C" float acosf(float x);
extern "C" void sceVu0ApplyMatrix(float *dst, float *mat, float *src);
extern "C" void sceVu0AddVector(float *dst, float *a, float *b);
extern "C" void sceVu0ScaleVector(float *dst, float *src, float scale);
extern char mBGCollision__15EntityBaseClass[0x20];
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void ReleaseHeadCamera__6PlayerFv(void *pThis);
extern "C" void UpdatePos__6CameraF5PVec35PVec3(void *pThis, float *pA, float *pB);
extern "C" void CreateViewMatrix__6CameraFR5PMat45PVec35PVec3(void *pThis, float *pMatrix, float *pA, float *pB);
extern "C" void SetViewMatrix__6CameraF5PMat4(void *pThis, float *pMatrix);
extern "C" void InitFrustrum__6PWorldFP5PMat4PA4_f(void *pThis, float *pMatrix, float (*pArr)[4]);
extern char gEng[105360];
extern "C" void RotateX__5PMat4Ff(float *pMat, float angle);
extern "C" void RotateY__5PMat4Ff(float *pMat, float angle);
extern "C" void RotateZ__5PMat4Ff(float *pMat, float angle);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" int printf(const char *fmt, ...);
extern "C" int fptodp(float f);
extern Debug gDebug;
extern "C" int CheckCameraShake__6CameraFR5PVec3R5PVec3b(void *pThis, float *pA, float *pB, int bFlag);
extern "C" void MakeViewMatrix__5PMat4FPfPfPf(float *pMat, float *pA, float *pB, float *pC);
extern "C" void Mul__5PMat4F5PMat4(float *pOut, float *pA, float *pB);
extern "C" void SetPosAndRot__6CameraFPA4_fPA4_f(void *pThis, float (*pPos)[4], float (*pRot)[4]);
extern "C" int _dpfge(long long a, long long b);
extern "C" int IsHanging__6PlayerFv(void *pPlayer);
extern "C" void QuatSlerp__7MathAPIFP9tag_EQuatP9tag_EQuatfP9tag_EQuat(void *pA, void *pB, float t, void *pOut);

class PVec3 {
public:
    PVec3() {}
    PVec3(const PVec3 &o) {
        m_v[0] = o.m_v[0];
        m_v[1] = o.m_v[1];
        m_v[2] = o.m_v[2];
        m_v[3] = o.m_v[3];
    }
    float m_v[4];
};

class BGCollision {
public:
    int FindIntersect(PVec3 &arg0, PVec3 &arg1, unsigned int arg2, float (*arg3)[4]);
    int CameraBGIntersect(PVec3 &arg0, PVec3 arg1, float arg2, unsigned int arg3, float &arg4, float (*arg5)[4]);
};

class MathAPI;
extern "C" float Distance__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);

class Camera {
public:
    void SetSourceTarget(PVec3 arg0, PVec3 arg1);
    void UpdatePos(PVec3 arg0, PVec3 arg1);

    float m_src[4];         // 0x000
    float m_tgt[4];         // 0x010
};

// The 16-byte ground position Physics::GetGroundPos returns through the hidden result pointer.
struct PGroundPos {
    PGroundPos() {}
    PGroundPos(const float *pSrc) { x = pSrc[0]; y = pSrc[1]; z = pSrc[2]; w = 1.0f; }
    float x, y, z, w;
};

class Physics {
public:
    PGroundPos GetGroundPos();

    float m_unk0;           // 0x000
    float m_unk4;           // 0x004
    float m_unk8;           // 0x008
    int m_unkC;             // 0x00C
    char _pad010[0xB0 - 0x10];
    float m_unkB0;          // 0x0B0 ground position x
    float m_unkB4;          // 0x0B4 ground position y
    float m_unkB8;          // 0x0B8 ground position z
};

// FUNCTION: 0x00173640 DrawTextDebug__12CameraFollowFv
void CameraFollow::DrawTextDebug() {
    sceVu0CopyVector(m_unk10, (float *)m_pCamera);
    sprintf(m_unk639C, "Cam Pos = %f, %f, %f\n", fptodp(m_unk10[0]), fptodp(m_unk10[1]), fptodp(m_unk10[2]));
    gDebug.DebugDisp(m_unk639C);
    sceVu0CopyVector(m_unk10, (float *)((char *)m_pCamera + 0x20));
    sprintf(m_unk639C, "Cam Rot = %f, %f, %f\n", fptodp(m_unk10[0]), fptodp(m_unk10[1]), fptodp(m_unk10[2]));
    gDebug.DebugDisp(m_unk639C);
    sprintf(m_unk639C, "Zoom = %f\n", fptodp(m_unk140));
    gDebug.DebugDisp(m_unk639C);
    sprintf(m_unk639C, "LOS Collide = %d\n", m_unk2C0);
    gDebug.DebugDisp(m_unk639C);
    if (m_unk210 != 0) {
        sprintf(m_unk639C, "Cam box ID = %d\n", m_unk210);
        gDebug.DebugDisp(m_unk639C);
    }
    sprintf(m_unk639C, "Against Wall = %d\n", m_unk62F0);
    gDebug.DebugDisp(m_unk639C);
    sprintf(m_unk639C, "Cam Version = %d\n", 14);
    gDebug.DebugDisp(m_unk639C);
    sprintf(m_unk639C, "Shake freeze = %d\n", m_unk62F8);
    gDebug.DebugDisp(m_unk639C);
    sprintf(m_unk639C, "Idle freeze = %d\n", m_unk6310);
    gDebug.DebugDisp(m_unk639C);
    sprintf(m_unk639C, "Player idle ctr = %d\n", m_unk6314);
    gDebug.DebugDisp(m_unk639C);
}

// DRAFT: 0x00173860 Create__12CameraSplineFv
// note: B-spline coefficients and arc length match in shape; accumulator fusion (mula/madd) not reproduced.
void CameraSpline::Create() {
    unsigned int numInner = m_unk4;
    int numCtrl = m_iNumCtrlPoints;
    int curveIdx = 0;
    for (int seg = 0; seg < (int)((unsigned int)(numCtrl - 3)); seg++) {
        for (int j = 0; j < (int)numInner; j++) {
            float u = (float)j / (float)numInner;
            float u2 = u * u;
            float u3 = u2 * u;
            float b0 = 1.0f + (((-1.0f) * u3 + 3.0f * u2) - 3.0f * u);
            float b1 = 4.0f + (3.0f * u3 - 6.0f * u2);
            float b2 = 1.0f + (3.0f * u + ((-3.0f) * u3 + 3.0f * u2));
            ((curveIdx < 0x2EE) ? (void)0 : CdsAssert__FPciPc("CameraFollow.cpp", 0x85B, "iIndex < MAX_CURVE_POINTS"));
            tag_CurveData *cur = &m_curves[curveIdx];
            for (int c = 0; c < 3; c++) {
                float t = m_ctrlPts[seg].m_v[c] * b0 + m_ctrlPts[seg + 1].m_v[c] * b1;
                float t2 = m_ctrlPts[seg + 2].m_v[c] * b2 + t;
                cur->m_v[c] = (t2 + u3 * m_ctrlPts[seg + 3].m_v[c]) / 6.0f;
            }
            if (j == 0 && seg == 0) {
                cur->m_unk10 = 0.0f;
                m_unkC = 65536.0f;
            } else {
                PVec3 spD0;
                PVec3 spC0;
                __mi__5PVec3FR5PVec3(spD0.m_v, cur->m_v, m_curves[curveIdx - 1].m_v);
                sceVu0CopyVector(spC0.m_v, spD0.m_v);
                float len = GetLength__5PVec3Fv(spC0.m_v);
                float acc = m_curves[curveIdx - 1].m_unk10 + len;
                cur->m_unk10 = acc;
                if (acc < m_unkC) {
                    m_unkC = acc;
                }
            }
            curveIdx++;
        }
    }
    m_unk8 = curveIdx;
}

// FUNCTION: 0x00173B30 AddControlPoint__12CameraSplineF5PVec3
void CameraSpline::AddControlPoint(PVec3 arg0) {
    if (m_iNumCtrlPoints >= 0xF) {
        CdsAssert__FPciPc("CameraFollow.cpp", 0x83F, "m_iNumCtrlPoints < MAX_CONTROL_POINTS");
    }
    int idx = m_iNumCtrlPoints;
    m_iNumCtrlPoints = idx + 1;
    sceVu0CopyVector(m_ctrlPts[idx].m_v, arg0.m_v);
}

// FUNCTION: 0x00173BA0 GetPosition__12CameraSplineFUiR5PVec3
void CameraSpline::GetPosition(unsigned int arg0, PVec3 &arg1) {
    sceVu0CopyVector(arg1.m_v, m_curves[arg0].m_v);
}

// FUNCTION: 0x00173BD0 __ct__12CameraSplineFv
CameraSpline::CameraSpline() {
    m_iNumCtrlPoints = 0;
    m_unk4 = 0x32;
    m_unk8 = 0;
}

// FUNCTION: 0x00173C50 __dt__15tag_ControlDataFv
tag_ControlData::~tag_ControlData() {
}

// FUNCTION: 0x00173CB0 __dt__13tag_CurveDataFv
tag_CurveData::~tag_CurveData() {
}

// DRAFT: 0x00173D20 ForceReset__12CameraFollowFb
// note: 28 lines; original copies by-value PVec3 temps to sp+0x20/0x30/0x40 with lwc1/swc1 pairs in a different order. Tried: empty copy ctor (43), no copy ctor (breaks 4 matches), copy ctor with body plus explicit locals (28), direct args (34).
void CameraFollow::ForceReset(bool arg0) {
    if (arg0) {
        *(int *)&m_unk10[0] = 0;
        m_unk10[1] = m_unk144;
        m_unk10[2] = m_unk140;
        sceVu0ApplyMatrix(m_unk20, m_unkA0, m_unk10);
        sceVu0AddVector(m_unk20, m_unk20, m_unk180);
        *(int *)&m_unk20[3] = 0x3F800000;
        m_unk224 = m_unk180[1];
        sceVu0CopyVector(m_unk40, m_unk180);
        m_unk40[1] += m_unk164;
    } else if (((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk40, *(PVec3 *)m_unk20, 2, 0)) {
        PVec3 tmp1 = *(PVec3 *)m_unk40;
        ((BGCollision *)mBGCollision__15EntityBaseClass)->CameraBGIntersect(*(PVec3 *)m_unk20, tmp1, 1.0f, 2, *(float *)((char *)m_unk6240 + 0x40), 0);
    }
    PVec3 tmp2 = *(PVec3 *)m_unk20;
    PVec3 tmp3 = *(PVec3 *)m_unk40;
    m_pCamera->SetSourceTarget(tmp2, tmp3);
}

// FUNCTION: 0x00173E70 SetSourceTarget__6CameraF5PVec35PVec3
void Camera::SetSourceTarget(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_src, arg0.m_v);
    sceVu0CopyVector(m_tgt, arg1.m_v);
}

// FUNCTION: 0x00173ED0 SetBossArenaValues__12CameraFollowFPA4_fffbbffb
void CameraFollow::SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7) {
    m_unk6324 = arg5;
    m_unk6328 = arg6;
    if (!arg7) {
        sceVu0CopyVector(m_unk6340, arg0[0]);
        m_unk6354 = arg1;
        m_unk6350 = arg2;
        m_unk6318 = 1;
        m_unk631C = 1;
        m_unk6370 = arg3;
        m_unk6371 = arg4;
        m_unk6360 = 0;
        sceVu0CopyVector(m_unk6330, arg0[0]);
        sceVu0CopyVector(m_unk40, arg0[0]);
        sceVu0CopyVector(m_unk20, m_unk180);
        m_unk636C = arg0[0][1];
        printf("## SetBossArenaValues ##\n");
        printf("\tTarget spring = %f\n", fptodp(m_unk6324));
        printf("\tSource spring = %f\n", fptodp(m_unk6328));
        printf("\tArena centre = %f,%f,%f\n", fptodp(m_unk6340[0]), fptodp(m_unk6340[1]), fptodp(m_unk6340[2]));
        printf("\tRadius ( min/max = %f, %f )\n", fptodp(m_unk6354), fptodp(m_unk6350));
        printf("\tLOS collide = %d\n", m_unk6370);
        printf("\tMove up past rad. = %d\n", m_unk6371);
        printf("\tBoss pos ( %f, %f, %f )\n", fptodp(m_unk6330[0]), fptodp(m_unk6330[1]), fptodp(m_unk6330[2]));
        printf("\tCam pos ( %f, %f, %f )\n", fptodp(m_unk20[0]), fptodp(m_unk20[1]), fptodp(m_unk20[2]));
        printf("\tTarget pos ( %f, %f, %f )\n", fptodp(m_unk40[0]), fptodp(m_unk40[1]), fptodp(m_unk40[2]));
        printf("\tBoss Y = %f\n", fptodp(m_unk636C));
    }
}

// DRAFT: 0x00174110 UpdateBossCam__12CameraFollowFv
// note: 398 words; original frame -0x1A0 with five saved GPRs, ours -0x190 with four (moved not in a saved reg); pointer-alias variant kept
void CameraFollow::UpdateBossCam() {
    float b0[4];
    float c70[4];
    float d0[4];
    float t80[4];
    float e0[4];
    float e90[4];
    float f0[4];
    float a0[4];
    float h100[4];
    float c0[4];
    float v120[4];
    float v130[4];
    float v180[4];
    float v190[4];
    float m140[4][4];
    float f20;
    float f3;
    float f2;
    float len;
    float len2;
    bool s1;
    bool moved;
    int mode1;
    int mode2;
    float *pY = &t80[1];
    float *pZ = &t80[2];

    s1 = false;
    moved = false;
    if (m_unk631C) {
        m_unk631C = 0;
        m_unk6320 = 10.0f;
        m_unk6358 = 0.0f;
        s1 = true;
        m_unk635C = 5.0f;
        m_unk6368 = m_unk636C + m_unk635C;
    }
    sceVu0CopyVector(b0, m_unk20);
    sceVu0CopyVector(c70, m_unk40);
    sceVu0CopyVector(m_unk40, m_unk6330);
    m_unk40[1] += m_unk6358;
    __mi__5PVec3FR5PVec3(d0, m_unk40, c70);
    sceVu0CopyVector(m_unk10, d0);
    if (!s1) {
        m_unk40[0] = c70[0] + m_unk10[0] * m_unk6324;
        m_unk40[1] = c70[1] + m_unk10[1] * m_unk6324;
        m_unk40[2] = c70[2] + m_unk10[2] * m_unk6324;
    }
    sceVu0SubVector(m_unk10, m_unk180, m_unk40);
    m_unk10[1] = 0.0f;
    sceVu0Normalize(m_unk10, m_unk10);
    t80[0] = m_unk180[0] + m_unk10[0] * m_unk6320;
    (*pY) = m_unk180[1] + m_unk635C;
    (*pZ) = m_unk180[2] + m_unk10[2] * m_unk6320;
    f20 = 0.0f;
    mode1 = *(int *)((char *)gEng + 0x19A78);
    if (mode1 == 3) {
        float d = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk6330, (float (*)[4])m_unk180);
        if (d < 20.0f) {
            f20 = -5.0f * (1.0f - d / 20.0f);
        }
    }
    (*pY) += f20;
    __mi__5PVec3FR5PVec3(e0, t80, m_unk40);
    sceVu0CopyVector(e90, e0);
    __mi__5PVec3FR5PVec3(f0, t80, m_unk6340);
    sceVu0CopyVector(a0, f0);
    len = sqrtf(a0[0] * a0[0] + a0[2] * a0[2]);
    moved = false;
    mode2 = *(int *)((char *)gEng + 0x19A78);
    switch (mode2) {
    case 0x14:
    case 0x13:
        goto L464;
    case 7:
        goto L43C;
    case 3:
        goto L3A0;
    default:
        goto L504;
    }
L3A0:
    if (len > m_unk6350) {
        f3 = len - m_unk6350;
        (*pY) = m_unk6368 + 1.2f * f3;
        f20 = 0.008f * f3;
        if (f20 > 1.0f) {
            f20 = 1.0f;
        }
        moved = true;
        __mi__5PVec3FR5PVec3(c0, m_unk180, m_unk40);
        m_unk40[0] += c0[0] * f20;
        m_unk40[2] += c0[2] * f20;
    }
    goto L504;
L464:
    if (len > m_unk6350) {
        f3 = len - m_unk6350;
        (*pY) = m_unk6368 + 0.8f * f3;
        f2 = 0.0005f * f3;
        if (f2 > 1.0f) {
            f2 = 1.0f;
        }
        moved = true;
        m_unk40[0] += e90[0] * f2;
        m_unk40[1] += e90[1] * f2;
        m_unk40[2] += e90[2] * f2;
    }
    goto L504;
L43C:
    if (*(unsigned int *)((char *)m_pCamera + 0x2C0) & 4) {
        (*pY) += *(float *)((char *)m_pCamera + 0x2C4);
    }
    goto L504;
L504:
    switch (m_unk6360) {
    case 0:
        break;
    case 1:
        if ((*pY) < (float)m_unk6364) {
            (*pY) = (float)m_unk6364;
        }
        break;
    default:
        break;
    }
    len2 = sqrtf(e90[0] * e90[0] + e90[2] * e90[2]);
    if (len2 < m_unk6354) {
        t80[0] = m_unk40[0] + m_unk10[0] * m_unk6354;
        (*pZ) = m_unk40[2] + m_unk10[2] * m_unk6354;
    }
    __mi__5PVec3FR5PVec3(h100, t80, b0);
    sceVu0CopyVector(m_unk10, h100);
    if (!moved) {
        m_unk20[0] = b0[0] + m_unk10[0] * m_unk6328;
        m_unk20[1] = b0[1] + m_unk10[1] * m_unk6328;
        m_unk20[2] = b0[2] + m_unk10[2] * m_unk6328;
    } else {
        sceVu0CopyVector(m_unk20, t80);
    }
    CheckCameraShake__6CameraFR5PVec3R5PVec3b(m_pCamera, m_unk20, m_unk40, moved);
    if (m_unk6370) {
        *(u_long128 *)m_unk10 = *(u_long128 *)m_unk180;
        ((BGCollision *)mBGCollision__15EntityBaseClass)->CameraBGIntersect(*(PVec3 *)m_unk20, *(PVec3 *)m_unk10, 1.5f, 0x40000002, m_unk6280, 0);
    }
    *(u_long128 *)v120 = *(u_long128 *)m_unk20;
    *(u_long128 *)v130 = *(u_long128 *)m_unk40;
    CreateViewMatrix__6CameraFR5PMat45PVec35PVec3(m_pCamera, (float *)((char *)this + 0x60), v120, v130);
    sceVu0CopyMatrix((float (*)[4])m140, (float (*)[4])((char *)this + 0x60));
    SetViewMatrix__6CameraF5PMat4(m_pCamera, (float *)m140);
    *(u_long128 *)v180 = *(u_long128 *)m_unk20;
    *(u_long128 *)v190 = *(u_long128 *)m_unk40;
    UpdatePos__6CameraF5PVec35PVec3(m_pCamera, v180, v190);
}

// FUNCTION: 0x00174770 UpdatePos__6CameraF5PVec35PVec3
void Camera::UpdatePos(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_src, arg0.m_v);
    sceVu0CopyVector(m_tgt, arg1.m_v);
}

// FUNCTION: 0x001747B0 ProcessRightAnalogue__12CameraFollowFv
void CameraFollow::ProcessRightAnalogue() {
    float sp30[4];
    float sp40[4];
    float cs;
    float sn;
    float ang;
    float var20;
    float t;

    if (m_unk1BA != 0) {
        if (m_unk1E0 != 0) {
            m_unk1F4 = m_unk184[1];
            m_unk1E0 = 0;
        }
        if (m_unk184[1] == m_unk1F4) {
            m_unk1E4 = GetAngleBetweenCamAndPlayer(m_unk1E8);
        }
        m_unk1A8 = 10.0f * (m_unk1E4 / 180.0f);
        m_unk1A8 = (m_unk1E8 < 0.0f) ? m_unk1A8 : -m_unk1A8;
    }
    if (!(FastMath_Fabs__Ff(m_unk1A8) <= 0.3f)) {
        if (m_unk1F0 == 0) {
            m_unk1EC = 1.5f;
        }
        m_unk110 = 1;
        m_unk1F0 = 1;
        if (m_unk1BA == 0) {
            t = m_unk1EC;
            if (t < 3.0f) {
                m_unk1EC = t * (1.02f * m_unk16C);
            }
            var20 = m_unk1A8 * m_unk1EC;
        } else {
            var20 = m_unk1A8 * m_unk16C;
            t = m_unk1E4 - FastMath_Fabs__Ff(var20);
            m_unk1E4 = t;
            if (t < 5.0f) {
                m_unk1BA = 0;
            }
        }
        ang = 0.017453292f * var20;
        cs = cosf(ang);
        sn = sinf(ang);
        if (m_unk62F0 != 0) {
            m_unk1F0 = 0;
            return;
        }
        if (m_unk62F1 != 0) {
            m_unk1F0 = 0;
            return;
        }
        if (DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk20, (float (*)[4])m_unk40) < 0.5f) {
            m_unk1F0 = 0;
            return;
        }
        __mi__5PVec3FR5PVec3(sp30, m_unk20, m_unk40);
        sceVu0CopyVector(m_unk10, sp30);
        m_unk10[2] = m_unk10[2] * cs - m_unk10[0] * sn;
        m_unk10[0] = m_unk10[2] * sn + m_unk10[0] * cs;
        __pl__5PVec3FR5PVec3(sp40, m_unk40, m_unk10);
        sceVu0CopyVector(m_unk20, sp40);
        return;
    }
    m_unk1F0 = 0;
    m_unk62F1 = 0;
}

// DRAFT: 0x00174A40 AddTwistEffect__12CameraFollowFv
// note: 42 words differ; original builds float literals with lui/ori/mtc1 (0.01f hoisted to v1 before the saves, 0.15f and 180.0f inline), draft loads them from $gp pool with lwc1; the mul/add operand order also differs
void CameraFollow::AddTwistEffect() {
    if (!(m_unk170 <= 0.01f)) {
        float t = m_unk124 + 0.15f * m_unk16C;
        m_unk124 = t;
        if (!(t <= 180.0f)) {
            m_unk124 = t - 360.0f;
        }
        Round180__Ff(m_unk124);
        *(float *)((char *)m_pCamera + 0xD0) = 5.0f * FastMath_Sin180__Ff(m_unk124);
    }
}

// FUNCTION: 0x00174AF0 SetSourceAndTarget__12CameraFollowF5PVec35PVec3
void CameraFollow::SetSourceAndTarget(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_unk20, arg0.m_v);
    sceVu0CopyVector(m_unk40, arg1.m_v);
}

// DRAFT: 0x00174B30 ProcessCamBox__12CameraFollowFv
// note: 46 lines; 0.1f is pooled (lwc1 0x0($gp)) where the original builds it inline (lui/ori/mtc1), which shifts the branch layout; case 0 first gave 54, case 1 first is kept.
int CameraFollow::ProcessCamBox() {
    float diff;
    switch (m_unk210) {
    case 1:
        if (m_unk144 != m_unk214) {
            diff = m_unk214 - m_unk144;
            if (FastMath_Fabs__Ff(diff) <= 0.1f) {
                m_unk144 = m_unk214;
            } else {
                m_unk144 = m_unk144 + (diff * (0.1f * m_unk16C));
            }
        }
        break;
    case 0:
        if (m_unk144 != m_unk174) {
            diff = m_unk174 - m_unk144;
            if (FastMath_Fabs__Ff(diff) <= 0.1f) {
                m_unk144 = m_unk174;
            } else {
                m_unk144 = m_unk144 + (diff * (0.1f * m_unk16C));
            }
        }
        break;
    }
    return 1;
}

// DRAFT: 0x00174C60 ProcessHeadCam__12CameraFollowFv
// note: DIFF 64: sp40 frame at 0x30 not 0x40 (local reorder no effect); clamp branch shapes; fptodp via jalr not jal (direct call gave 125); double constant register order.
void CameraFollow::ProcessHeadCam() {
    float sp30[3];
    float sp40[4][4];
    float sp80[4];
    float sp90[4][4];
    float spD0[4][4];
    float var_f1;
    float var_f1_2;

    sceVu0UnitMatrix(sp40[0]);
    if (m_unk1F8 != 0) {
        m_unk1F8 = 0;
        m_unk1B0 = 0.0f;
        m_unk1B4 = 0.0f;
        m_unk200 = m_unk184[0];
        m_unk204 = m_unk184[1];
        m_unk208 = m_unk184[2];
    }
    if (!(FastMath_Fabs__Ff(m_unk1A8) < 0.3f)) {
        var_f1 = m_unk1B0 - m_unk1A8;
        if (var_f1 < 0.0f) {
            if (var_f1 < -90.0f) {
                var_f1 = -90.0f;
            }
        } else if (!(var_f1 <= 90.0f)) {
            var_f1 = 90.0f;
        }
        m_unk1B0 = var_f1;
    }
    if (_dpfge(((long long (*)(float))fptodp)(FastMath_Fabs__Ff(m_unk1AC)), 0x3FD3333333333333LL) != 0) {
        var_f1_2 = m_unk1B4 + m_unk1AC;
        if (var_f1_2 < 0.0f) {
            if (var_f1_2 < -45.0f) {
                var_f1_2 = -45.0f;
            }
        } else if (!(var_f1_2 <= 45.0f)) {
            var_f1_2 = 45.0f;
        }
        m_unk1B4 = var_f1_2;
    }
    Round180__Ff(m_unk1B0);
    Round180__Ff(m_unk1B4);
    RotateY__5PMat4Ff(sp40[0], m_unk1B0);
    RotateX__5PMat4Ff(sp40[0], m_unk1B4);
    m_unk20[0] = m_unk180[0];
    m_unk20[1] = m_unk180[1] + m_unk164;
    m_unk20[2] = m_unk180[2];
    sp30[0] = -m_unkA0[8];
    sp30[1] = -m_unkA0[9];
    sp30[2] = -m_unkA0[10];
    CheckCameraShake__6CameraFR5PVec3R5PVec3b(m_pCamera, m_unk20, m_unk40, 0);
    MakeViewMatrix__5PMat4FPfPfPf((float *)_pad060, m_unk20, sp30, (float *)&m_unk0E0);
    sceVu0CopyMatrix(sp90, (float (*)[4])_pad060);
    Mul__5PMat4F5PMat4(spD0[0], sp40[0], sp90[0]);
    sceVu0CopyMatrix((float (*)[4])_pad060, spD0);
    sp80[0] = Round180__Ff(sp80[0] = m_unk200 + m_unk1B4);
    sp80[1] = Round180__Ff(sp80[1] = m_unk204 + m_unk1B0);
    sp80[2] = 0.0f;
    SetPosAndRot__6CameraFPA4_fPA4_f(m_pCamera, (float (*)[4])m_unk20, (float (*)[4])sp80);
}

// DRAFT: 0x00174F20 CanDoHeadcam__12CameraFollowFv
// note: 33 lines; abs calls and 0.01f literal (gp pool vs lui/ori/mtc1) and branch shape differ; block-scope int abs(int) decl stops abs inlining; goto-shaped exit gave 34.
int CameraFollow::CanDoHeadcam() {
    int abs(int);
    if (m_unk62F0 != 0) { return 0; }
    if (abs(m_unk1B8) >= 0x33) { return 0; }
    if (abs(m_unk1B9) >= 0x33) { return 0; }
    if (!(m_unk1A0 <= 0.01f)) { return 0; }
    if (m_unk6290 != 0) { return 0; }
    if (m_unk2C0 != 0) { return 0; }
    return 1;
}

// DRAFT: 0x00174FC0 CreatePathToPlayer__12CameraFollowFv
// note: size 0x1D4 vs 0x1D0 (116 words); original frame 0xA0 keeps this in s2 and saves s0/s1 only, ours frame 0xB0 saves s3; tried local mid before/after copies, loop for m_unk10 copy: no change
void CameraFollow::CreatePathToPlayer() {
    ((CameraSpline *)_pad2D0)->Reset();
    ((CameraSpline *)_pad2D0)->AddControlPoint(*(PVec3 *)m_unk20);
    ((CameraSpline *)_pad2D0)->AddControlPoint(*(PVec3 *)m_unk20);
    PVec3 mid;
    mid.m_v[0] = m_unk20[0] + 0.5f * (m_unk2B0[0] - m_unk20[0]);
    mid.m_v[1] = m_unk20[1] + 0.5f * (m_unk2B0[1] - m_unk20[1]);
    mid.m_v[2] = m_unk20[2] + 0.5f * (m_unk2B0[2] - m_unk20[2]);
    ((CameraSpline *)_pad2D0)->AddControlPoint(mid);
    ((CameraSpline *)_pad2D0)->AddControlPoint(*(PVec3 *)m_unk2B0);
    m_unk10[0] = m_unk180[0];
    m_unk10[1] = m_unk180[1];
    m_unk10[2] = m_unk180[2];
    mid.m_v[0] = m_unk2B0[0] + 0.5f * (m_unk10[0] - m_unk2B0[0]);
    mid.m_v[1] = m_unk2B0[1] + 0.5f * (m_unk10[1] - m_unk2B0[1]);
    mid.m_v[2] = m_unk2B0[2] + 0.5f * (m_unk10[2] - m_unk2B0[2]);
    ((CameraSpline *)_pad2D0)->AddControlPoint(mid);
    ((CameraSpline *)_pad2D0)->Create();
    m_unk6190 = 0;
    m_unk6254 = 0x3F800000;
    m_unk6258 = 0;
}

// DRAFT: 0x00175190 CalcNewCameraViewpointPos__12CameraFollowFv
// note: DIFF 64 words; size 0x178 vs 0x188. Both loop counters now advance in the for header (66 to 64, kept). Still differs: the PVec3 copy at 0x84-0xA0 (original uses addiu-materialized addresses and a delay-slot store), the bnez targets at 0x50/0x70, the sqrt/div order at 0xB8-0xF0, and the sceVu0CopyVector reloc at 0x14C. Tried: pointer-held copy addresses (no change, reverted).
int CameraFollow::CalcNewCameraViewpointPos() {
    float sp40[4];
    float sp50[4];
    float sp60[4];
    float sp70[4];
    int i;
    int off;

    CalcNewCameraOffsets();
    i = 0;
    off = 0;
    for (; i < 8; i++, off += 0x10) {
        sceVu0CopyVector(m_unk10, (float *)(_pad230 + off));
        if (((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk20, *(PVec3 *)m_unk10, 2, 0) == 0 &&
            ((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk40, *(PVec3 *)m_unk10, 2, 0) == 0) {
            __mi__5PVec3FR5PVec3(sp60, m_unk40, m_unk20);
            *(u_long128 *)sp40 = *(u_long128 *)sp60;
            __mi__5PVec3FR5PVec3(sp70, m_unk10, m_unk20);
            *(u_long128 *)sp50 = *(u_long128 *)sp70;
            float dot = sp40[0] * sp50[0] + sp40[2] * sp50[2];
            float angle = FastMath_Fabs__Ff(57.295776f * acosf(dot / (sqrtf(sp40[0] * sp40[0] + sp40[2] * sp40[2]) * sqrtf(sp50[0] * sp50[0] + sp50[2] * sp50[2]))));
            if (angle < 180.0f && !(angle < 30.0f)) {
                sceVu0CopyVector(m_unk2B0, m_unk10);
                return 1;
            }
        }
    }
    return 0;
}

// DRAFT: 0x00175320 CalcNewCameraOffsets__12CameraFollowFv
// note: DIFF 10 words, register picks and load order in the neg.s blocks. Tried: a-first scoped locals (20), b-first (10, kept), single-block flips (12, 13, 10).
void CameraFollow::CalcNewCameraOffsets() {
    float sp50[4];
    float sp60[4];

    {
        float b = m_unk20[1];
        float a = m_unk140;
        sp50[0] = 0.0f;
        sp50[1] = b;
        sp50[2] = a;
        sp50[3] = 1.0f;
        sceVu0ApplyMatrix(sp60, m_unkA0, sp50);
        sceVu0CopyVector((float *)(_pad230 + 0x00), sp60);
    }
    {
        float b = m_unk20[1];
        float a = m_unk140;
        sp50[0] = -a;
        sp50[1] = b;
        sp50[2] = a;
        sp50[3] = 1.0f;
        sceVu0ApplyMatrix(sp60, m_unkA0, sp50);
        sceVu0CopyVector((float *)(_pad230 + 0x10), sp60);
    }
    {
        float b = m_unk20[1];
        float a = m_unk140;
        sp50[0] = a;
        sp50[1] = b;
        sp50[2] = a;
        sp50[3] = 1.0f;
        sceVu0ApplyMatrix(sp60, m_unkA0, sp50);
        sceVu0CopyVector((float *)(_pad230 + 0x20), sp60);
    }
    {
        float b = m_unk20[1];
        float a = m_unk140;
        sp50[0] = -a;
        sp50[1] = b;
        sp50[2] = 0.0f;
        sp50[3] = 1.0f;
        sceVu0ApplyMatrix(sp60, m_unkA0, sp50);
        sceVu0CopyVector((float *)(_pad230 + 0x30), sp60);
    }
    {
        float b = m_unk20[1];
        float a = m_unk140;
        sp50[0] = a;
        sp50[1] = b;
        sp50[2] = 0.0f;
        sp50[3] = 1.0f;
        sceVu0ApplyMatrix(sp60, m_unkA0, sp50);
        sceVu0CopyVector((float *)(_pad230 + 0x40), sp60);
    }
    {
        float b = m_unk20[1];
        float a = m_unk140;
        sp50[0] = -a;
        sp50[1] = b;
        sp50[2] = -a;
        sp50[3] = 1.0f;
        sceVu0ApplyMatrix(sp60, m_unkA0, sp50);
        sceVu0CopyVector((float *)(_pad230 + 0x50), sp60);
    }
    {
        float b = m_unk20[1];
        float a = m_unk140;
        sp50[0] = a;
        sp50[1] = b;
        sp50[2] = -a;
        sp50[3] = 1.0f;
        sceVu0ApplyMatrix(sp60, m_unkA0, sp50);
        sceVu0CopyVector((float *)(_pad230 + 0x60), sp60);
    }
    {
        float b = m_unk20[1];
        float a = m_unk140;
        sp50[0] = 0.0f;
        sp50[1] = b;
        sp50[2] = -a;
        sp50[3] = 1.0f;
        sceVu0ApplyMatrix(sp60, m_unkA0, sp50);
        sceVu0CopyVector((float *)(_pad230 + 0x70), sp60);
    }
}

// DRAFT: 0x00175540 CamCollideSphere__12CameraFollowF5PVec3f
// note: 33 words differ in all copy variants (direct, pointer-cast, pointer-local, 128-bit temp); original takes d's address via addiu v0,sp,0x50 then lq, and reuses a0=sp+0x40 for the store and GetLength arg
void CameraFollow::CamCollideSphere(PVec3 arg0, float arg1) {
    float n[4];
    float d[4];
    __mi__5PVec3FR5PVec3(d, m_unk20, arg0.m_v);
    *(u_long128 *)n = *(u_long128 *)d;
    if (GetLength__5PVec3Fv(n) < arg1) {
        sceVu0Normalize(n, n);
        m_unk20[0] = arg0.m_v[0] + n[0] * arg1;
        m_unk20[1] = arg0.m_v[1] + n[1] * arg1;
        m_unk20[2] = arg0.m_v[2] + n[2] * arg1;
        m_unk22C = 1;
    }
}

// DRAFT: 0x00175600 CamCollideCylinder__12CameraFollowF5PVec3ff
// note: 40 words differ; same copy-addressing mismatch as CamCollideSphere (original keeps a0=sp+0x40 live from the sq into GetLength, draft re-materializes it); n-before-d order gave 41 to 40
void CameraFollow::CamCollideCylinder(PVec3 arg0, float arg1, float arg2) {
    float n[4];
    float d[4];
    __mi__5PVec3FR5PVec3(d, m_unk20, arg0.m_v);
    *(u_long128 *)n = *(u_long128 *)d;
    n[1] = 0.0f;
    if (!(m_unk20[1] < arg0.m_v[1]) && m_unk20[1] <= arg0.m_v[1] + arg2) {
        if (GetLength__5PVec3Fv(n) < arg1) {
            sceVu0Normalize(n, n);
            m_unk20[0] = arg0.m_v[0] + n[0] * arg1;
            m_unk20[2] = arg0.m_v[2] + n[2] * arg1;
            m_unk22C = 1;
        }
    }
}

// DRAFT: 0x001756F0 GetAngleBetweenCamAndPlayer__12CameraFollowFRf
// note: 48 words differ; c and a volatile matches stack slots (65 without); tried local reorder, c-only volatile (62), dot-before-arg0 (49), range-check form (48); remaining is schedule and c[2]/a[2] pointer use.
float CameraFollow::GetAngleBetweenCamAndPlayer(float &arg0) {
    float v[4];
    volatile float c[4];
    volatile float a[4];
    float d[4];
    __mi__5PVec3FR5PVec3(d, m_unk20, m_unk40);
    sceVu0CopyVector(v, d);
    c[0] = m_unkA0[8];
    c[2] = m_unkA0[10];
    a[0] = m_unkA0[0];
    a[2] = m_unkA0[2];
    arg0 = v[0] * a[0] + v[2] * a[2];
    float dot = v[0] * c[0] + v[2] * c[2];
    float q = dot / (sqrtf(v[0] * v[0] + v[2] * v[2]) * sqrtf(c[0] * c[0] + c[2] * c[2]));
    float ang = 0.0f;
    if (q >= -1.0f && q <= 1.0f) {
        ang = 57.295776f * acosf(q);
    }
    return FastMath_Fabs__Ff(ang);
}

// DRAFT: 0x00175830 PlayerIsIdle__12CameraFollowFv
// note: 23 lines with block-scope int abs(int) decl (27 without); remaining diff is the 0.01f literal (gp pool lwc1 vs lui/ori/mtc1) and branch layout around the abs calls; abs(signed char) and dont_inline did not stop abs inlining.
int CameraFollow::PlayerIsIdle() {
    int abs(int);
    if (abs(m_unk1B8) >= 0x33) {
        return 0;
    }
    if (abs(m_unk1B9) >= 0x33) {
        return 0;
    }
    if (m_unk1A0 <= 0.01f) {
        return 1;
    }
    return 0;
}

// DRAFT: 0x001758A0 MoveCameraToNewViewpoint__12CameraFollowFv
// note: DIFF 22 words. Open: early-return epilogue (b at 0x5C targets 0x6B, ours 0x69); float x/K register order at 0x68-0x78; bc1 sense; cvt/lui/or split layout; blend load order from 0xCC. Tried: `K <= x` (103), `x >= K` (103), local fx (103), `!(x < K)` member form (22), blend operand swap (22), hoisted 0.1f*16C local (90).
int CameraFollow::MoveCameraToNewViewpoint() {
    PVec3 sp20;
    unsigned int idx;

    sceVu0CopyVector(m_unk10, m_unk20);
    if (((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk40, *(PVec3 *)m_unk10, 2, 0) == 0) {
        m_unk6258 += 1;
        if (m_unk6258 >= 0x14) {
            return 1;
        }
    } else {
        m_unk6258 = 0;
    }
    if (!(*(float *)&m_unk6190 < 2147483648.0f)) {
        idx = (unsigned int)(int)(*(float *)&m_unk6190 - 2147483648.0f) | 0x80000000;
    } else {
        idx = (unsigned int)(int)*(float *)&m_unk6190;
    }
    if (idx < (unsigned int)m_unk2D8) {
        ((CameraSpline *)_pad2D0)->GetPosition(idx, sp20);
        m_unk20[0] = m_unk20[0] + (0.1f * m_unk16C) * (sp20.m_v[0] - m_unk20[0]);
        m_unk20[2] = m_unk20[2] + (0.1f * m_unk16C) * (sp20.m_v[2] - m_unk20[2]);
        if (*(float *)&m_unk6254 < 3.0f) {
            *(float *)&m_unk6254 = *(float *)&m_unk6254 * (1.2f * m_unk16C);
        }
        *(float *)&m_unk6190 += *(float *)&m_unk6254 * m_unk16C;
        ((CameraSpline *)_pad2D0)->GetPosition(m_unk2D8 - 1, *(PVec3 *)m_unk10);
        if (((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk40, *(PVec3 *)m_unk10, 2, 0) != 0 &&
            CalcNewCameraViewpointPos() != 0) {
            m_unk2C0 = 1;
            m_unk62D1 = 0;
            CreatePathToPlayer();
        }
        return 0;
    }
    sceVu0CopyVector(m_unk10, m_unk20);
    if (((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk40, *(PVec3 *)m_unk10, 2, 0) != 0) {
        ForceReset(false);
    }
    return 1;
}

// FUNCTION: 0x00175AC0 ResetFromCamBox__12CameraFollowFv
void CameraFollow::ResetFromCamBox() {
    Init(true);
    m_unk17C = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk20, (float (*)[4])m_unk40);
    m_unk6398 = 0.085f;
    m_unk140 = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk20, (float (*)[4])m_unk40);
}

// DRAFT: 0x00175B20 IdleFreezeCheck__12CameraFollowFv
// note: 24 lines; literal and GAME_FPS registers f0/f1 swapped, m_unk6314 reload sits in bc1t delay slot in original, outer beqz/bnez offsets off by one; swapped-arm form gave 28.
void CameraFollow::IdleFreezeCheck() {
    unsigned int v;
    if (PlayerIsIdle() != 0) {
        if (m_unk6310 == 0) {
            m_unk6314++;
            if (2.1474836e9f > GAME_FPS) {
                v = (unsigned int)(int)GAME_FPS;
            } else {
                v = (unsigned int)(int)(GAME_FPS - 2.1474836e9f) | 0x80000000;
            }
            if (v < m_unk6314) {
                m_unk6310 = 1;
            }
        }
    } else {
        m_unk6310 = 0;
        m_unk6314 = 0;
    }
}

// DRAFT: 0x00175BD0 KeepUpWithPlayer__12CameraFollowFv
// note: compiles; not matched. Body follows the mapped asm, but f21 register reuse (m140, ground Y, m160/m180) and the blend store order differ. Tried one variant only.
void CameraFollow::KeepUpWithPlayer() {
    float sp40[4];
    float tgt[4];
    float sp90[4];
    float spA0[4];
    float sp50, sp58, sp60, sp68, sp70, sp78;
    float angle;
    float f20, f21, f22, f4, d;
    PGroundPos gp;

    f22 = GetAngleBetweenCamAndPlayer(angle);
    __mi__5PVec3FR5PVec3(spA0, m_unk20, m_unk40);
    sceVu0CopyVector(m_unk10, spA0);
    m_unk10[1] = 0.0f;
    if (f22 < 90.0f) {
        sp40[0] = m_unkA0[8];
        sp40[1] = 0.0f;
        sp40[2] = m_unkA0[10];
        sceVu0Normalize(sp40, sp40);
    }
    f20 = sqrtf(m_unk10[0] * m_unk10[0] + m_unk10[2] * m_unk10[2]);
    f21 = m_unk140;
    sceVu0Normalize(m_unk10, m_unk10);
    if (f22 < 90.0f && m_unk1A0 > 0.04f) {
        sp50 = m_unk40[0] + sp40[0] * f21;
        sp58 = m_unk40[2] + sp40[2] * f21;
        sp60 = m_unk40[0] + m_unk10[0] * f21;
        sp68 = m_unk40[2] + m_unk10[2] * f21;
        sp70 = sp50 - sp60;
        sp78 = sp58 - sp68;
        tgt[0] = sp60 + 0.085f * sp70;
        tgt[2] = sp68 + 0.085f * sp78;
    } else {
        tgt[0] = m_unk40[0] + m_unk10[0] * f21;
        tgt[2] = m_unk40[2] + m_unk10[2] * f21;
    }
    if (m_unk6250 != -1000.0f && !(m_unk20[1] <= m_unk6250 - 1.0f)) {
        m_unk144 -= 0.1f * m_unk16C;
    }
    {
        unsigned int u = m_unk148;
        float t = m_unk144 + (float)u;
        m_unk220 = t;
        if (t < 3.0f) {
            m_unk220 = 3.0f;
        }
    }
    {
        void *p = *(void **)((char *)m_unk114 + 0x38);
        gp = ((Physics *)p)->GetGroundPos();
    }
    f21 = gp.y;
    if (gp.y == -1000.0f) {
        f21 = m_unk160;
    } else if (m_unk180[1] - gp.y < 0.5f) {
        m_unk160 = gp.y;
    } else {
        f21 = (m_unk160 == 0.0f) ? m_unk180[1] : m_unk160;
    }
    sceVu0CopyVector(m_unk10, m_unk20);
    m_unk10[1] -= 100.0f;
    ((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk20, *(PVec3 *)m_unk10, 2, 0);
    if (m_unk10[1] != -1000.0f) {
        m_unk15C = m_unk10[1];
    }
    m_unk224 = (f21 < m_unk15C) ? m_unk15C : f21;
    if (m_unk140 < 5.0f) {
        if (m_unk20[1] > m_unk40[1]) {
            m_unk224 = 1.0f + m_unk180[1];
        }
    }
    tgt[1] = m_unk224 + m_unk220;
    sceVu0SubVector(sp90, tgt, m_unk20);
    f4 = f20 / m_unk140;
    if (f4 < 1.0f) {
        f4 = 1.0f;
    }
    if (m_unk6310 == 0) {
        m_unk20[0] += sp90[0] * ((0.15f * f4) * m_unk16C);
        m_unk20[1] += sp90[1] * ((0.05f * f4) * m_unk16C);
        m_unk20[2] += sp90[2] * ((0.15f * f4) * m_unk16C);
    }
    d = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk20, (float (*)[4])m_unk40);
    if (d > m_unk17C) {
        sceVu0SubVector(m_unk10, m_unk20, m_unk40);
        sceVu0Normalize(m_unk10, m_unk10);
        sceVu0ScaleVector(m_unk10, m_unk10, m_unk17C);
        sceVu0AddVector(m_unk20, m_unk40, m_unk10);
    }
    if (FastMath_Fabs__Ff(m_unk17C - 15.0f) > 0.1f) {
        m_unk17C += 0.02f * (15.0f - m_unk17C);
    }
}

// DRAFT: 0x00176170 GetGroundPos__7PhysicsFv
// note: 1 word differs: ours sets v0 to the result pointer; the original returns without it. Tried member-init and field-copy constructors, a local copy, a destructor. The earlier whole-asm body copied C-emittable instructions and does not count.
PGroundPos Physics::GetGroundPos() {
    return PGroundPos(&m_unkB0);
}

// FUNCTION: 0x001761A0 FollowPlayer__12CameraFollowFv
void CameraFollow::FollowPlayer() {
    if (m_unk2C0 != 0) {
        if (MoveCameraToNewViewpoint() != 0) {
            m_unk2C0 = 0;
        }
    } else {
        KeepUpWithPlayer();
        ProcessRightAnalogue();
    }
}

// FUNCTION: 0x001761F0 ResetTrackingVars__12CameraFollowFv
void CameraFollow::ResetTrackingVars() {
    sceVu0SubVector(m_unk10, m_unk40, m_unk20);
    sceVu0Normalize(m_unk10, m_unk10);
    m_unk6378 = m_unk10[0];
    m_unk637C = m_unk10[1];
    m_unk6380 = m_unk10[2];
    m_unk638C = m_unk6378;
    m_unk6390 = m_unk637C;
    m_unk6394 = m_unk6380;
    m_unk6398 = 0.85f;
}

// DRAFT: 0x00176270 UpdateCameraPos__12CameraFollowFv
// note: 475 differing words of ~486; size 0x798 vs 0x78C, frame 0x170 vs 0x160; case-1 block and case-0 branch layout differ; __mi__/__pl__ operands and BG/QuatSlerp arguments are guessed
int CameraFollow::UpdateCameraPos() {
    PVec3 sp110;
    PVec3 sp100;
    PVec3 spF0;
    PVec3 spE0;
    PVec3 spD0;
    PVec3 spC0;
    PVec3 spB0;
    PVec3 spA0;
    PVec3 sp90;
    PVec3 sp80;
    PVec3 sp20;
    float sp120[4][4];
    float sp40[4][4];
    float var_f0;
    unsigned char var_v0;

    switch (m_unk118) {
    case 0:
        if (m_unk6290 == 0) {
            FollowPlayer();
        }
    default:
        CheckCameraShake__6CameraFR5PVec3R5PVec3b(m_pCamera, m_unk20, m_unk40, 0);
        if (m_unk6290 != 0) {
            sceVu0ScaleVector(m_unk10, m_unk6260, 0.1f);
            sceVu0AddVector(m_unk20, m_unk20, m_unk10);
            m_unk628C = m_unk628C - *(float *)((char *)gEng + 0x1E8);
            if (m_unk628C < 0.0f) {
                m_unk6290 = 0;
            }
            goto block_37;
        }
        if (m_unk1F0 == 0) {
            sceVu0CopyVector(m_unk10, m_unk20);
            sp80.m_v[0] = m_unk30[0];
            sp80.m_v[1] = m_unk30[1];
            sp80.m_v[2] = m_unk30[2];
            sp80.m_v[3] = m_unk30[3];
            if (((BGCollision *)mBGCollision__15EntityBaseClass)->CameraBGIntersect(*(PVec3 *)m_unk10, sp80, 1.0f, 2U, m_unk6280, 0) != 0) {
                if (!(m_unk6280 <= 0.5f) || (m_unk62F8 != 0)) {
                    sceVu0CopyVector(m_unk20, m_unk30);
                    __mi__5PVec3FR5PVec3(sp90.m_v, m_unk40, m_unk20);
                    sceVu0CopyVector(m_unk10, sp90.m_v);
                    m_unk140 = sqrtf(m_unk10[0] * m_unk10[0] + m_unk10[1] * m_unk10[1] + m_unk10[2] * m_unk10[2]);
                    if (!(m_unk140 <= 10.0f)) {
                        sceVu0Normalize(m_unk6260, m_unk6260);
                        m_unk6290 = 1;
                        m_unk628C = 10.0f;
                    }
                } else {
                    if (m_unk62F4 == 0) {
                        m_unk6300[0] = m_unk20[0];
                    }
                    m_unk62F4 += 1;
                    if (m_unk62F4 >= 6) {
                        m_unk62F4 = 0;
                        var_v0 = 0;
                        if (Distance__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk6300, (float (*)[4])m_unk20) < 0.2f) {
                            var_v0 = 1;
                        }
                        m_unk62F8 = var_v0;
                    }
                    sceVu0SubVector(m_unk10, m_unk10, m_unk30);
                    sceVu0AddVector(m_unk20, m_unk30, m_unk10);
                }
            } else {
                m_unk62F4 = 0;
                m_unk62F8 = 0;
                if (m_unk140 < m_unk178) {
                    var_f0 = m_unk140 + (0.1f * m_unk16C);
                    goto block_36;
                }
                if (!(m_unk140 <= (0.1f + m_unk178))) {
                    var_f0 = m_unk140 - (0.1f * m_unk16C);
                    goto block_36;
                }
            }
            goto block_37;
        }
        m_unk6310 = 0;
        m_unk6314 = 0;
        sceVu0CopyVector(m_unk10, m_unk20);
        spA0.m_v[0] = m_unk30[0];
        spA0.m_v[1] = m_unk30[1];
        spA0.m_v[2] = m_unk30[2];
        spA0.m_v[3] = m_unk30[3];
        if (((BGCollision *)mBGCollision__15EntityBaseClass)->CameraBGIntersect(*(PVec3 *)m_unk10, spA0, 1.0f, 2U, m_unk6280, 0) != 0) {
            sceVu0CopyVector(sp20.m_v, m_unk10);
            if (IsHanging__6PlayerFv(m_unk114) != 0) {
                m_unk62F1 = 1;
                sceVu0SubVector(m_unk10, m_unk10, m_unk30);
                sceVu0AddVector(m_unk20, m_unk30, m_unk10);
            } else {
                __mi__5PVec3FR5PVec3(spB0.m_v, m_unk20, m_unk40);
                sceVu0CopyVector(m_unk10, spB0.m_v);
                sceVu0Normalize(m_unk10, m_unk10);
                sceVu0ScaleVector(m_unk10, m_unk10, 1.0f);
                sceVu0AddVector(m_unk62A0, m_unk20, m_unk10);
                sceVu0CopyVector(m_unk10, m_unk62A0);
                if (((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk40, *(PVec3 *)m_unk62A0, 2U, 0) != 0) {
                    __mi__5PVec3FR5PVec3(spC0.m_v, m_unk62A0, m_unk20);
                    sceVu0CopyVector(sp20.m_v, spC0.m_v);
                    __pl__5PVec3FR5PVec3(spD0.m_v, m_unk20, m_unk10);
                    sceVu0CopyVector(m_unk20, spD0.m_v);
                    var_f0 = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk20, (float (*)[4])m_unk40);
                } else {
                    sceVu0SubVector(m_unk10, sp20.m_v, m_unk30);
                    sceVu0AddVector(m_unk20, m_unk30, m_unk10);
                    var_f0 = m_unk140 * 0.9f;
                }
                goto block_36;
            }
        } else {
            if (m_unk140 < m_unk178) {
                var_f0 = m_unk140 + (0.1f * m_unk16C);
                goto block_36;
            }
            if (!(m_unk140 <= (0.1f + m_unk178))) {
                var_f0 = m_unk140 - (0.1f * m_unk16C);
block_36:
                m_unk140 = var_f0;
            }
block_37:
            if (!(DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk40, (float (*)[4])m_unk20) <= 0.5f)) {
                sceVu0SubVector(m_unk10, m_unk40, m_unk20);
                sceVu0Normalize(m_unk10, m_unk10);
                if ((m_unk10[0] != m_unk6378) || (m_unk10[1] != m_unk637C) || (m_unk10[2] != m_unk6380)) {
                    m_unk6378 = m_unk10[0];
                    m_unk637C = m_unk10[1];
                    m_unk6380 = m_unk10[2];
                    m_unk6384 = 0.0f;
                }
                if (m_unk6398 < 0.85f) {
                    m_unk6398 = m_unk6398 * 1.1f;
                }
                m_unk6384 = m_unk6384 + (m_unk6398 * *(float *)((char *)gEng + 0x1E8));
                if (!(m_unk6384 <= 1.0f)) {
                    m_unk6384 = 1.0f;
                }
                QuatSlerp__7MathAPIFP9tag_EQuatP9tag_EQuatfP9tag_EQuat((char *)this + 0x6388, &m_unk6374, m_unk6384, (char *)this + 0x6388);
            } else {
                m_unk6398 = 0.05f;
            }
            if (*(unsigned char *)((char *)m_unk114 + 0x33A) != 0) {
                m_unk20[1] = 5.0f + m_unk180[1];
                m_unk40[1] = 2.0f + m_unk180[1];
                spE0.m_v[0] = m_unk20[0];
                spE0.m_v[1] = m_unk20[1];
                spE0.m_v[2] = m_unk20[2];
                spE0.m_v[3] = m_unk20[3];
                spF0.m_v[0] = m_unk40[0];
                spF0.m_v[1] = m_unk40[1];
                spF0.m_v[2] = m_unk40[2];
                spF0.m_v[3] = m_unk40[3];
                CreateViewMatrix__6CameraFR5PMat45PVec35PVec3(m_pCamera, (float *)((char *)this + 0x60), spE0.m_v, spF0.m_v);
            } else {
                m_unk10[0] = m_unk20[0] + m_unk638C;
                m_unk10[1] = m_unk20[1] + m_unk6390;
                m_unk10[2] = m_unk20[2] + m_unk6394;
                m_unk10[3] = 1.0f;
                sp100.m_v[0] = m_unk20[0];
                sp100.m_v[1] = m_unk20[1];
                sp100.m_v[2] = m_unk20[2];
                sp100.m_v[3] = m_unk20[3];
                sp110.m_v[0] = m_unk10[0];
                sp110.m_v[1] = m_unk10[1];
                sp110.m_v[2] = m_unk10[2];
                sp110.m_v[3] = m_unk10[3];
                CreateViewMatrix__6CameraFR5PMat45PVec35PVec3(m_pCamera, (float *)((char *)this + 0x60), sp100.m_v, sp110.m_v);
            }
            sceVu0CopyMatrix(sp120, (float (*)[4])((char *)this + 0x60));
            SetViewMatrix__6CameraF5PMat4(m_pCamera, (float *)sp120);
        }
        return 0;
    case 1:
        ProcessHeadCam();
        sceVu0CopyMatrix(sp40, (float (*)[4])((char *)this + 0x60));
        SetViewMatrix__6CameraF5PMat4(m_pCamera, (float *)sp40);
        return 1;
    }
}

// DRAFT: 0x00176A00 UpdateTargetPos__12CameraFollowFv
// note: size 0x318 vs 0x320, DIFF 172 words; the 16-byte GetGroundPos copy at 0x58 lacks the two addiu pointer loads (ptr locals, temp, folded); tried flag order (kept), pointer locals and temp (no change)
void CameraFollow::UpdateTargetPos() {
    float tgt[4];
    float cur[4];
    float gpc[4];
    float raw[4];
    float pA;
    float pB;
    float pC;
    float pD;
    float d1;
    float d2;
    int flag1;
    int flag2;

    sceVu0CopyVector(m_unk50, m_unk40);
    flag1 = 0;
    flag2 = 0;
    sceVu0CopyVector(tgt, m_unk180);
    GetGroundPos__7PhysicsFv(raw, *(void **)((char *)m_unk114 + 0x38));
    *(u_long128 *)gpc = *(u_long128 *)raw;

    if (m_unk180[1] - gpc[1] < 0.1f) {
        tgt[1] = m_unk180[1] + 5.0f;
    } else {
        tgt[1] = m_unk40[1];
    }

    if (m_unk218 == 0 && m_unk140 > 8.0f) {
        mpFrustum__15EntityBaseClass->GetPlaneEquation(PFrustrum::FRUSTUM_PLANE_1, pA, pB, pC, pD);

        *(u_long128 *)cur = *(u_long128 *)m_unk180;
        cur[1] += 6.5f;
        d1 = pA * cur[0] + pB * cur[1] + pC * cur[2] + pD;
        if (d1 > 0.0f) {
            flag1 = 1;
        }

        mpFrustum__15EntityBaseClass->GetPlaneEquation(PFrustrum::FRUSTUM_PLANE_2, pA, pB, pC, pD);

        *(u_long128 *)cur = *(u_long128 *)m_unk180;
        cur[1] -= 3.0f;
        d2 = pA * cur[0] + pB * cur[1] + pC * cur[2] + pD;
        if (d2 > 0.0f) {
            flag2 = 1;
        }
    }

    if (flag1) {
        m_unk14C = d1;
    } else if (flag2) {
        m_unk14C = -d2;
    } else {
        m_unk14C = 0.0f;
    }

    if (m_unk120 != 0 || ((unsigned char *)m_unk114)[0x26A] != 0) {
        sceVu0CopyVector(m_unk40, tgt);
        m_unk40[1] = 5.0f + m_unk180[1];
    } else if (m_unk140 > 5.0f) {
        tgt[1] = tgt[1] + m_unk14C;
    }

    m_unk6240[0] = (tgt[0] - m_unk50[0]) * 0.05f;
    m_unk6240[1] = (tgt[1] - m_unk50[1]) * 0.05f;
    m_unk6240[2] = (tgt[2] - m_unk50[2]) * 0.05f;

    m_unk40[0] = m_unk50[0] + m_unk6240[0];
    m_unk40[1] = m_unk50[1] + m_unk6240[1];
    m_unk40[2] = m_unk50[2] + m_unk6240[2];
}

// FUNCTION: 0x00176D20 GetPlayerDetails__12CameraFollowFv
void CameraFollow::GetPlayerDetails() {
    {
        char *pPlay = (char *)m_unk114;
        char *pSub = *(char **)(pPlay + 0x3C);
        m_unk180 = (float *)(pSub ? pSub + 0x80 : pPlay + 0x190);
    }
    sceVu0SubVector(m_unk130, m_unk180, m_unk190);
    {
        char *pPlay = (char *)m_unk114;
        char *pSub = *(char **)(pPlay + 0x3C);
        m_unk184 = (float *)(pSub ? pSub + 0x90 : pPlay + 0x1A0);
    }
    float *pDetail = *(float **)((char *)m_unk114 + 0x38);
    if (pDetail == 0) {
        CdsAssert__FPciPc("CameraFollow.cpp", 0x240, "pPlayerPhysics");
    }
    m_unk188 = pDetail;
    sceVu0CopyMatrix((float (*)[4])m_unkA0, (float (*)[4])(*(char **)((char *)m_unk114 + 0x3C) + 0x40));
    if (m_unk188[0] == 0.0f && m_unk188[1] == 0.0f && m_unk188[2] == 0.0f) {
        float diff[4];
        sceVu0SubVector(diff, m_unk180, m_unk190);
        sceVu0CopyVector(m_unk190, m_unk180);
        m_unk1A0 = sqrtf(sceVu0InnerProduct(diff, diff));
        diff[1] = 0.0f;
        m_unk170 = sqrtf(sceVu0InnerProduct(diff, diff));
    } else {
        m_unk1A0 = sqrtf(sceVu0InnerProduct(m_unk188, m_unk188));
        m_unk170 = sqrtf(m_unk188[0] * m_unk188[0] + m_unk188[2] * m_unk188[2]);
        sceVu0CopyVector(m_unk190, m_unk180);
    }
    m_unk6250 = *(float *)(*(char **)((char *)m_unk114 + 0x38) + 0xC8);
}

// DRAFT: 0x00176ED0 ProcessPlayerIO__12CameraFollowFv
// note: 2 words differ, both `jal abs`: our call relocates to abs__Fi (block-scope int abs(int) gets C++ linkage) vs original C abs; extern "C" block decl is a compile error, dropping the decl inlines abs (DIFF 110), dont_inline pragma still inlines.
void CameraFollow::ProcessPlayerIO() {
    int abs(int);
    int var_s1;
    int var_a0;

    if (*(int *)((char *)m_pCamera + 0x2C0) & 4) {
        m_unk1A5 = 0;
        m_unk1A4 = 0;
    } else {
        char *pPlay = (char *)m_unk114;
        m_unk1A4 = *(signed char *)(pPlay + 0x1B6);
        m_unk1A5 = *(signed char *)(pPlay + 0x1B7);
    }
    m_unk1B8 = *(signed char *)(gPad + 0x114);
    m_unk1B9 = *(signed char *)(gPad + 0x115);
    var_s1 = (signed char)(abs(m_unk1A4) >> 4);
    var_a0 = (signed char)(abs(m_unk1A5) >> 4);
    if (var_s1 != 0 && m_unk1A4 > 0) {
        var_s1 = (signed char)(var_s1 + 1);
    }
    if (var_a0 != 0 && m_unk1A5 > 0) {
        var_a0 = (signed char)(var_a0 + 1);
    }
    m_unk1A8 = (float)var_s1 / 8.0f;
    m_unk1AC = (float)var_a0 / 8.0f;
    if (m_unk1A8 > 0.5f) {
        m_unk1BA = 0;
    }
    m_unk1A8 = (m_unk1A4 < 0) ? -m_unk1A8 : m_unk1A8;
    m_unk1AC = (m_unk1A5 < 0) ? -m_unk1AC : m_unk1AC;
    if (m_unk118 != 1) {
        if ((*(int *)((char *)m_pCamera + 0x2C0) & 2) == 0 &&
            (*(unsigned short *)((char *)m_unk114 + 0x1B0) & 0x400) != 0) {
            if (m_unk1BB == 0) {
                m_unk1BB = 1;
                m_unk1BC = 1;
            }
        } else {
            m_unk1BB = 0;
        }
    }
}

// DRAFT: 0x00177090 PlayerMovedSinceLastSwing__12CameraFollowFv
// note: 68 lines; 0.1f pooled via gp where the original builds it inline (lui/ori/mtc1), which shifts branch layout. Shared-exit variant gave 79.
int CameraFollow::PlayerMovedSinceLastSwing() {
    sceVu0SubVector(m_unk10, m_unk1C0, m_unk180);
    if (FastMath_Fabs__Ff(m_unk10[0]) <= 0.1f) {
        if (!(FastMath_Fabs__Ff(m_unk10[1]) <= 0.1f) || !(FastMath_Fabs__Ff(m_unk10[2]) <= 0.1f)) {
            return 1;
        }
        sceVu0SubVector(m_unk10, m_unk1D0, (float *)m_unk184);
        if (!(FastMath_Fabs__Ff(m_unk10[0]) <= 0.1f)) {
            return 1;
        }
        if (!(FastMath_Fabs__Ff(m_unk10[1]) <= 0.1f)) {
            return 1;
        }
        if (FastMath_Fabs__Ff(m_unk10[2]) <= 0.1f) {
            return 0;
        }
    }
    return 1;
}

// FUNCTION: 0x001771D0 PlayerExitingLevel__12CameraFollowFv
int CameraFollow::PlayerExitingLevel() {
    return *(int *)((char *)m_unk114 + 0x20) == 2;
}

// DRAFT: 0x001771F0 Update__12CameraFollowFv
// note: DIFF 219 words; compiler keeps BG pointer and this+0x6280 in saved regs (s0/s1), frame 0xA0 with s2 vs original 0x80 with s0 only; spelling variant 292 words
void CameraFollow::Update() {
    float fAngle;
    float diff[4];

    m_unk16C = *(float *)((char *)gEng + 0x1E8);
    sceVu0CopyVector(m_unk30, m_unk20);
    StorePlayerPos();
    GetPlayerDetails();
    sceVu0CopyVector(m_unk10, m_unk40);
    m_unk62F0 = ((BGCollision *)((char *)mBGCollision__15EntityBaseClass + 0x2270))->CameraBGIntersect(*(PVec3 *)m_unk10, *(PVec3 *)m_unk10, 2.0f, 2, *(float *)((char *)m_unk6240 + 0x40), 0) != 0;

    if (*(unsigned char *)((char *)m_unk114 + 0x33A) == 0 && m_unk218 == 0 && m_unk6318 == 0) {
        sceVu0CopyVector(m_unk10, m_unk20);
        if (((BGCollision *)((char *)mBGCollision__15EntityBaseClass + 0x2270))->FindIntersect(*(PVec3 *)m_unk40, *(PVec3 *)m_unk10, 2, 0)) {
            sceVu0CopyVector(m_unk62E0, m_unk10);
            sceVu0CopyVector(m_unk10, m_unk40);
            if (((BGCollision *)((char *)mBGCollision__15EntityBaseClass + 0x2270))->FindIntersect(*(PVec3 *)m_unk20, *(PVec3 *)m_unk10, 2, 0) == 0) {
                sceVu0SubVector(m_unk10, m_unk40, m_unk62E0);
                sceVu0ScaleVector(m_unk10, m_unk10, 0.1f);
                sceVu0AddVector(m_unk30, m_unk62E0, m_unk10);
                sceVu0CopyVector(m_unk20, m_unk62E0);
                ((BGCollision *)((char *)mBGCollision__15EntityBaseClass + 0x2270))->CameraBGIntersect(*(PVec3 *)m_unk20, *(PVec3 *)m_unk30, 1.0f, 2, *(float *)((char *)m_unk6240 + 0x40), 0);
                printf("(Camera) - Reset due to outside world\n");
            }
        }
    }

    if (m_unk6318 != 0) {
        UpdateBossCam();
        return;
    }
    ProcessPlayerIO();
    if (m_unk1BC != 0) {
        m_unk1BC = 0;
        if (GetAngleBetweenCamAndPlayer(fAngle) > 1.0f && PlayerMovedSinceLastSwing()) {
            m_unk1BA = 1;
            m_unk1E0 = 1;
        } else {
            m_unk1BA = 0;
        }
    }
    if (ProcessCamBox()) {
        UpdateTargetPos();
        IdleFreezeCheck();
        if (UpdateCameraPos()) {
            return;
        }
    }
    AddTwistEffect();
    if (m_unk218 != 0) {
        m_unk218 = m_unk218 - 1;
        return;
    }

    {
        int mode = *(int *)((char *)gEng + 0x19A78);
        if (mode == 5 || mode == 11) {
            if (*(int *)((char *)m_pCamera + 0x2C0) & 0x10) {
                m_unk178 = *(float *)((char *)m_pCamera + 0x2C4);
            } else if (m_unk178 != 10.0f) {
                m_unk178 = 10.0f;
            }
        }
    }

    if (!PlayerExitingLevel() && m_unk1F0 == 0 && m_unk2C0 == 0 && (*(int *)((char *)m_pCamera + 0x2C0) & 0x8) == 0) {
        sceVu0CopyVector(m_unk10, m_unk40);
        if (((BGCollision *)((char *)mBGCollision__15EntityBaseClass + 0x2270))->FindIntersect(*(PVec3 *)m_unk20, *(PVec3 *)m_unk10, 2, 0)) {
            int idle = 0;
            if (FastMath_Fabs__Ff(m_unk1A8) > 0.3f) {
                if (PlayerIsIdle()) {
                    m_unk2C0 = 0;
                    idle = 1;
                }
            }
            if (!idle && !PlayerIsIdle()) {
                if (CalcNewCameraViewpointPos()) {
                    CreatePathToPlayer();
                    m_unk2C0 = 1;
                    m_unk62D1 = 0;
                } else {
                    CreatePathFromPlayersRoute();
                    m_unk2C0 = 1;
                    m_unk62D1 = 1;
                }
            }
        }
    }

    m_pCamera->UpdatePos(*(PVec3 *)m_unk20, *(PVec3 *)m_unk40);
    m_unk120 = 0;
    __mi__5PVec3FR5PVec3(diff, m_unk30, m_unk20);
    m_unk22C = 0;
    sceVu0CopyVector(m_unk10, diff);
    m_unk168 = sqrtf(m_unk10[0] * m_unk10[0] + m_unk10[1] * m_unk10[1] + m_unk10[2] * m_unk10[2]);
}

// DRAFT: 0x00177680 CreatePathFromPlayersRoute__12CameraFollowFv
// note: DIFF 56 words; first loop's FP temps are saved (f20..f23) and the copies to the call temps are scheduled differently. Tried: inline PVec3 copies (106), hoisted float d (106), per-call scoped temps (106), shared temp (56, kept).
void CameraFollow::CreatePathFromPlayersRoute() {
    float best = 9999.0f;
    int bestIdx = 0;
    for (int i = 9; i >= 0; i--) {
        float d = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk20, &m_unk61A0[i]);
        if (d < best) {
            best = d;
            bestIdx = i;
        }
    }
    ((CameraSpline *)_pad2D0)->Reset();
    PVec3 start = *(PVec3 *)m_unk20;
    ((CameraSpline *)_pad2D0)->AddControlPoint(start);
    ((CameraSpline *)_pad2D0)->AddControlPoint(start);
    for (int j = bestIdx; j >= 0; j--) {
        sceVu0CopyVector(m_unk10, m_unk61A0[j]);
        m_unk10[1] = m_unk20[1];
        ((CameraSpline *)_pad2D0)->AddControlPoint(*(PVec3 *)m_unk10);
    }
    ((CameraSpline *)_pad2D0)->Create();
    PVec3 pos;
    ((CameraSpline *)_pad2D0)->GetPosition(((CameraSpline *)_pad2D0)->m_unk8 - 1, pos);
    if (((BGCollision *)mBGCollision__15EntityBaseClass)->FindIntersect(*(PVec3 *)m_unk40, pos, 2, 0)) {
        ForceReset(false);
    }
    m_unk6190 = 0;
    m_unk6254 = 0x3F800000;
    m_unk6258 = 0;
}

// FUNCTION: 0x00177820 StorePlayerPos__12CameraFollowFv
void CameraFollow::StorePlayerPos() {
    int idx;
    int off;
    sceVu0SubVector(m_unk10, m_unk61A0[0], m_unk180);
    if (!(GetLength__5PVec3Fv(m_unk10) <= 3.0f)) {
        idx = 8;
        off = 0x80;
        do {
            sceVu0CopyVector((float *)((char *)this + (idx + 1) * 0x10 + 0x61A0), (float *)((char *)this + off + 0x61A0));
            idx -= 1;
            off -= 0x10;
        } while (idx >= 0);
        sceVu0CopyVector(m_unk61A0[0], m_unk180);
    }
}

// FUNCTION: 0x001778C0 SetFollowCameraParams__12CameraFollowFff
void CameraFollow::SetFollowCameraParams(float arg0, float arg1) {
    m_unk174 = arg1;
    m_unk178 = arg0;
    m_unk17C = 100.0f;
}

// DRAFT: 0x001778E0 SetHeadCam__12CameraFollowFb
// note: 50 words differ; CanDoHeadcam test is an inverted branch (beqz to the return-0 tail in the original, bnez skip in ours); the _pad060 variant cut 103 to 50 words.
int CameraFollow::SetHeadCam(bool arg0) {
    if (arg0) {
        if (m_unk118 == 1) {
            return 1;
        }
        if (!CanDoHeadcam()) {
            return 0;
        }
        sceVu0CopyVector(m_unkF0, m_unk20);
        sceVu0CopyVector(m_unk100, m_unk40);
        m_unk1F8 = 1;
        m_unk11C = m_unk118;
        m_unk118 = 1;
        return 1;
    }
    if (m_unk118 != 1) {
        return 1;
    }
    sceVu0CopyVector(m_unk20, m_unkF0);
    sceVu0CopyVector(m_unk40, m_unk100);
    m_unk11C = m_unk118;
    m_unk118 = 0;
    ReleaseHeadCamera__6PlayerFv(m_unk114);

    float tmp20[4];
    float tmp30[4];
    float tmp40[4];
    float tmp50[4];
    float tmpMat[4][4];

    tmp20[0] = m_unk20[0];
    tmp20[1] = m_unk20[1];
    tmp20[2] = m_unk20[2];
    tmp20[3] = m_unk20[3];
    tmp30[0] = m_unk40[0];
    tmp30[1] = m_unk40[1];
    tmp30[2] = m_unk40[2];
    tmp30[3] = m_unk40[3];
    UpdatePos__6CameraF5PVec35PVec3(m_pCamera, tmp20, tmp30);

    tmp40[0] = m_unk20[0];
    tmp40[1] = m_unk20[1];
    tmp40[2] = m_unk20[2];
    tmp40[3] = m_unk20[3];
    tmp50[0] = m_unk40[0];
    tmp50[1] = m_unk40[1];
    tmp50[2] = m_unk40[2];
    tmp50[3] = m_unk40[3];
    CreateViewMatrix__6CameraFR5PMat45PVec35PVec3(m_pCamera, (float *)_pad060, tmp40, tmp50);
    sceVu0CopyMatrix(tmpMat, (float (*)[4])_pad060);
    SetViewMatrix__6CameraF5PMat4(m_pCamera, (float *)tmpMat);
    InitFrustrum__6PWorldFP5PMat4PA4_f(gEng, (float *)_pad060, (float (*)[4])m_unk20);
    return 1;
}

// DRAFT: 0x00177A80 Init__12CameraFollowFb
// note: 95 words; u_long128 save placement, register assignment, gEng lui/addiu and frame size 0x180 vs 0x17c differ
void CameraFollow::Init(bool arg0) {
    u_long128 tmp20[1];
    u_long128 tmp40[1];
    if (arg0) {
        tmp20[0] = *(u_long128 *)m_unk20;
        tmp40[0] = *(u_long128 *)m_unk40;
    }
    Reset();
    char *pMgr = gEng + 0x137E0;
    if (pMgr == 0) {
        CdsAssert__FPciPc("CameraFollow.cpp", 0x8D, "pEntityMgr");
    }
    m_unk114 = *(void **)(pMgr + 0x505C);
    if (m_unk114 == 0) {
        CdsAssert__FPciPc("CameraFollow.cpp", 0x8F, "m_pPlayer");
    }
    char *pSub = *(char **)((char *)m_unk114 + 0x3C);
    m_unk180 = (float *)(pSub ? pSub + 0x80 : (char *)m_unk114 + 0x190);
    pSub = *(char **)((char *)m_unk114 + 0x3C);
    m_unk184 = (float *)(pSub ? pSub + 0x90 : (char *)m_unk114 + 0x1A0);
    sceVu0UnitMatrix(m_unkA0);
    if (m_unk184[0] != 0.0f) {
        RotateX__5PMat4Ff(m_unkA0, m_unk184[0]);
    }
    if (m_unk184[1] != 0.0f) {
        RotateY__5PMat4Ff(m_unkA0, m_unk184[1]);
    }
    if (m_unk184[2] != 0.0f) {
        RotateZ__5PMat4Ff(m_unkA0, m_unk184[2]);
    }
    ForceReset(true);
    if (arg0) {
        *(u_long128 *)m_unk20 = tmp20[0];
        *(u_long128 *)m_unk40 = tmp40[0];
    }
    ResetTrackingVars();
}

// FUNCTION: 0x00177C00 __dt__12CameraFollowFv
extern "C" CameraFollow *__dt__12CameraFollowFv(CameraFollow *pThis, short nFlag) {
    if (pThis != 0) {
        __destroy_arr((char *)pThis + 0x61A0, __dt__5PVec3Fv, 0x10, 0xA);
        if (pThis->_pad2D0 != 0) {
            __destroy_arr((char *)pThis + 0x60A0, __dt__15tag_ControlDataFv, 0x10, 0xF);
            __destroy_arr((char *)pThis + 0x2E0, __dt__13tag_CurveDataFv, 0x20, 0x2EE);
        }
        __destroy_arr((char *)pThis + 0x230, __dt__5PVec3Fv, 0x10, 8);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00177CC0 Reset__12CameraFollowFv
void CameraFollow::Reset() {
    m_unk20[2] = 0.0f;
    m_unk20[1] = 0.0f;
    m_unk20[0] = 0.0f;
    m_unk20[3] = 1.0f;
    m_unk40[2] = 0.0f;
    m_unk40[1] = 0.0f;
    m_unk40[0] = 0.0f;
    m_unk40[3] = 1.0f;
    m_unk10[2] = 0.0f;
    m_unk10[1] = 0.0f;
    m_unk10[0] = 0.0f;
    m_unk10[3] = 1.0f;
    m_unk144 = 7.0f;
    m_unk140 = 6.0f;
    m_unk174 = 7.0f;
    m_unk178 = 10.0f;
    m_unk17C = 15.0f;
    m_unk1F8 = 1;
    m_unk2C0 = 0;
    m_unk1F0 = 0;
    m_unk1BB = 0;
    m_unk120 = 1;
    m_unk22C = 0;
    m_unk220 = 0;
    m_unk6318 = 0;
    m_unk636C = 0;
    m_unk160 = 0;
    m_unk1BA = 0;
    m_unk110 = 0;
    m_unk6371 = 0;
    m_unk62B0 = 0;
    m_unk62F1 = 0;
    m_unk6378 = 0.0f;
    m_unk637C = 0.0f;
    m_unk6380 = 0.0f;
    m_unk6374 = 1.0f;
    m_unk6384 = 0;
    m_unk6398 = 0.01f;
    m_unk62F4 = 0;
    m_unk62F8 = 0;
    m_unk148 = 0;
    m_unk6290 = 0;
    m_unk628C = 0;
    m_unk170 = 0.0f;
    m_unk180 = 0;
    m_unk184 = 0;
    m_unk188 = 0;
    m_unk118 = 0;
    m_unk210 = 0;
    m_unk228 = 0;
    m_unk218 = 5;
    m_unk124 = 0.0f;
    m_unk6360 = 0;
    m_unk6310 = 0;
    m_unk6314 = 0;
    for (int i = 0; i < 10; i++) {
        m_unk61A0[i][0] = 0.0f;
        m_unk61A0[i][1] = 0.0f;
        m_unk61A0[i][2] = 0.0f;
        m_unk61A0[i][3] = 1.0f;
    }
    m_unk164 = 5.0f;
}

// DRAFT: 0x00177EA0 __ct__12CameraFollowFP6Camera
// note: original spills this to 0x2C(sp), keeps pCam in s0, frame 0x30, returns this; ours keeps this in s1 (no spill, no reload), frame 0x20 with s1 saved, size 0xa4 vs 0xc4; member form and extern pThis form (with and without return) tried, all differ the same way.
extern "C" CameraFollow *__ct__12CameraFollowFP6Camera(CameraFollow *pThis, Camera *pCam) {
    sceVu0UnitMatrix((float *)((char *)pThis + 0x60));
    sceVu0UnitMatrix((float *)((char *)pThis + 0xA0));
    __construct_array((char *)pThis + 0x230, __ct__5PVec3Fv, __dt__5PVec3Fv, 0x10, 8);
    __ct__12CameraSplineFv((char *)pThis + 0x2D0);
    __construct_array((char *)pThis + 0x61A0, __ct__5PVec3Fv, __dt__5PVec3Fv, 0x10, 0xA);
    pThis->m_pCamera = pCam;
    pThis->m_unk0E0 = 0;
    pThis->m_unk0E4 = -1.0f;
    pThis->m_unk0E8 = 0;
    pThis->m_unk0EC = 1.0f;
    return pThis;
}
