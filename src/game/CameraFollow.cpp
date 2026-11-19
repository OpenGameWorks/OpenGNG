#include "CameraFollow.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" int abs(int);

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
    sceVu0CopyVector(m_ctrlPts[idx], arg0.m_v);
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

// FUNCTION: 0x00174AF0 SetSourceAndTarget__12CameraFollowF5PVec35PVec3
void CameraFollow::SetSourceAndTarget(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_unk20, arg0.m_v);
    sceVu0CopyVector(m_unk40, arg1.m_v);
}

// DRAFT: 0x00175830 PlayerIsIdle__12CameraFollowFv
// note: MW inlines builtin abs (neg/movz) where the original calls libc abs at 0x122520; abs(signed char), abs(...) and dont_inline pragma did not stop it.
int CameraFollow::PlayerIsIdle() {
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
