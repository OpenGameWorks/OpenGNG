#include "CameraFollow.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" int abs(int);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" void sceVu0Normalize(float *dst, float *src);
extern "C" float GetLength__5PVec3Fv(float *this_vec);
extern float GAME_FPS;
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void __dl__FPv(void *pMem);
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

class PVec3 {
public:
    PVec3(const PVec3 &) {}
    float m_v[4];
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

class Physics {
public:
    void GetGroundPos();

    float m_unk0;           // 0x000
    float m_unk4;           // 0x004
    float m_unk8;           // 0x008
    int m_unkC;             // 0x00C
};

// FUNCTION: 0x00173B30 AddControlPoint__12CameraSplineF5PVec3
void CameraSpline::AddControlPoint(PVec3 arg0) {
    if (m_iNumCtrlPoints >= 0xF) {
        CdsAssert__FPciPc("CameraFollow.cpp", 0x83F, "m_iNumCtrlPoints < MAX_CONTROL_POINTS");
    }
    int idx = m_iNumCtrlPoints;
    m_iNumCtrlPoints = idx + 1;
    sceVu0CopyVector(m_ctrlPts[idx].m_v, arg0.m_v);
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

// FUNCTION: 0x00173E70 SetSourceTarget__6CameraF5PVec35PVec3
void Camera::SetSourceTarget(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_src, arg0.m_v);
    sceVu0CopyVector(m_tgt, arg1.m_v);
}

// FUNCTION: 0x00174770 UpdatePos__6CameraF5PVec35PVec3
void Camera::UpdatePos(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_src, arg0.m_v);
    sceVu0CopyVector(m_tgt, arg1.m_v);
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

// FUNCTION: 0x00175AC0 ResetFromCamBox__12CameraFollowFv
void CameraFollow::ResetFromCamBox() {
    Init(true);
    m_unk17C = Distance__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk20, (float (*)[4])m_unk40);
    m_unk6398 = 0x3DAE147B;
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
    m_unk6398 = 0x3F59999A;
}

// FUNCTION: 0x00176170 GetGroundPos__7PhysicsFv
void Physics::GetGroundPos() {
    asm {
        lwc1 f0, 0xB0(a1)
        lui v1, 0x3F80
        swc1 f0, 0x0(a0)
        lwc1 f0, 0xB4(a1)
        swc1 f0, 0x4(a0)
        lwc1 f0, 0xB8(a1)
        swc1 f0, 0x8(a0)
        sw v1, 0xC(a0)
        jr ra
    }
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
