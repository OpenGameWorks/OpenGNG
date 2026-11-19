#ifndef CAMERA_H
#define CAMERA_H

#include "types.h"

class Camera {
public:
    unsigned char PlayingCutCamera();
    void CleanUpCutCameras();
    void ResetAfterReposition();
    int FollowCamInBossMode();
    void SetFollowCameraParams(float arg0, float arg1);

    char _pad000[0xBC];
    void *m_unkBC;          // 0x0BC (CameraFollow *)
    void *m_unkC0;          // 0x0C0 (CameraCutManager *)
};

#endif
