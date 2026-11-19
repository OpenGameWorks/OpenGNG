#include "Camera.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);

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

    char _pad000[0x6318];
    unsigned int m_unk6318; // 0x6318
};

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

// FUNCTION: 0x0017A780 ResetFollowCamera__6CameraFv
void Camera::ResetFollowCamera() {
    if (m_unkBC != 0) {
        m_unkB4 = 0;
        ((CameraFollow *)m_unkBC)->Init(false);
    }
}
