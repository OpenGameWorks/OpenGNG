#include "Camera.h"

// TODO(header): foreign declarations
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

    char _pad000[0x6318];
    unsigned int m_unk6318; // 0x6318
};

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
