#include "Camera.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" float sqrtf(float x);

class CVector3 {
public:
    float m_unk0;
    float m_unk4;
    float m_unk8;
};

class PVec3 {
public:
    float m_v[4];
};

class CameraCutManager {
public:
    void CleanUpCutCameras();

    char _pad000[0x85];
    unsigned char m_unk85;  // 0x085
};

class CameraFollow {
public:
    void ResetAfterReposition();
    void SetFollowCameraParams(float arg0, float arg1);
    void ModifyBossCamera(float arg0, float arg1, float arg2);
    void SetBossPosition(float (*arg0)[4]);
    void SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7);
    void Init(bool arg0);
    void CamCollideCylinder(PVec3 arg0, float arg1, float arg2);
    void DrawPolyDebug();

    char _pad000[0x6318];
    unsigned int m_unk6318; // 0x6318
};

// FUNCTION: 0x00178380 Magnitude__6CameraF8CVector3
float Camera::Magnitude(CVector3 arg0) {
    return sqrtf(arg0.m_unk0 * arg0.m_unk0 + arg0.m_unk4 * arg0.m_unk4 + arg0.m_unk8 * arg0.m_unk8);
}

// FUNCTION: 0x001788E0 SetSourceTarget__6CameraFPfPf
void Camera::SetSourceTarget(float *arg0, float *arg1) {
    sceVu0CopyVector(m_unk00, arg0);
    sceVu0CopyVector(m_unk10, arg1);
}

// FUNCTION: 0x00178410 PlayingCutCamera__6CameraFv
unsigned char Camera::PlayingCutCamera() {
    CameraCutManager *temp_v0 = (CameraCutManager *)m_unkC0;
    if (temp_v0 != 0) {
        return temp_v0->m_unk85;
    }
    return 0;
}

// FUNCTION: 0x00178500 CleanUpCutCameras__6CameraFv
void Camera::CleanUpCutCameras() {
    CameraCutManager *temp_a0 = (CameraCutManager *)m_unkC0;
    if (temp_a0 != 0) {
        temp_a0->CleanUpCutCameras();
    }
}

// DRAFT: 0x00178940 SetControlled__6CameraFUib
// note: 12 differing lines; branch layout of the arg1 && m_unk2E4 test and the return paths differs. Tried ternary, early return, single trailing return; all 12-16 lines.
int Camera::SetControlled(unsigned int arg0, bool arg1) {
    if (m_unk2E4 == 0 || arg0 == 0) {
        m_unk2E4 = arg0;
        if (arg1 && m_unk2E4 != 0) {
            m_unk2B8 = 1;
        } else {
            m_unk2B8 = 0;
        }
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00178990 ResetAfterReposition__6CameraFv
void Camera::ResetAfterReposition() {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->ResetAfterReposition();
    }
}

// FUNCTION: 0x001789C0 FollowCamInBossMode__6CameraFv
int Camera::FollowCamInBossMode() {
    CameraFollow *temp_v0 = (CameraFollow *)m_unkBC;
    if (temp_v0 != 0) {
        return (temp_v0->m_unk6318 != 0) ? 1 : 0;
    }
    return 0;
}

// FUNCTION: 0x00178A10 SetFollowCameraParams__6CameraFff
void Camera::SetFollowCameraParams(float arg0, float arg1) {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->SetFollowCameraParams(arg0, arg1);
    }
}

// FUNCTION: 0x00178A40 ModifyBossCamera__6CameraFfff
void Camera::ModifyBossCamera(float arg0, float arg1, float arg2) {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->ModifyBossCamera(arg0, arg1, arg2);
    }
}

// FUNCTION: 0x00178A70 SetBossPosition__6CameraFPA4_f
void Camera::SetBossPosition(float (*arg0)[4]) {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->SetBossPosition(arg0);
    }
}

// FUNCTION: 0x00178AA0 SetBossArenaValues__6CameraFPA4_fffbbffb
void Camera::SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7) {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->SetBossArenaValues(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

// FUNCTION: 0x00179F20 CheckCameraShake__6CameraFR5PVec3R5PVec3b
void Camera::CheckCameraShake(PVec3 &arg0, PVec3 &arg1, bool arg2) {
    if (m_unk179 != 0) {
        if (ShakeScreen(arg0, arg1, arg2)) {
            m_unk179 = 0;
        }
    }
}

// DRAFT: 0x0017A070 CamCollideCylinder__6CameraF5PVec3ff
// note: 18 differing words; original keeps the copied PVec3 address in v0 and has no null recheck before the reload of m_unkBC; ours uses v1 and adds a recheck. Tried a temp local and direct m_unkBC access.
void Camera::CamCollideCylinder(PVec3 arg0, float arg1, float arg2) {
    if (m_unkBC != 0) {
        ((CameraFollow *)m_unkBC)->CamCollideCylinder(arg0, arg1, arg2);
    }
}

// DRAFT: 0x0017A280 PolyDebug__6CameraFv
// note: 11 differing words; original branches with b to the shared jr ra exit (ld in delay slot), ours uses bnez. Tried &&, early return, nested if/else, explicit returns; count unchanged.
void Camera::PolyDebug() {
    if (m_unkB4 == 0 && m_unkB0 != 0) {
        ((CameraFollow *)m_unkBC)->DrawPolyDebug();
    }
}

// FUNCTION: 0x0017A780 ResetFollowCamera__6CameraFv
void Camera::ResetFollowCamera() {
    if (m_unkBC != 0) {
        m_unkB4 = 0;
        ((CameraFollow *)m_unkBC)->Init(false);
    }
}
