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
    void SetSourceTarget(float *arg0, float *arg1);
    void ModifyBossCamera(float arg0, float arg1, float arg2);
    void SetBossPosition(float (*arg0)[4]);
    void SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7);
    void ResetFollowCamera();

    float m_unk00[4];       // 0x000
    float m_unk10[4];       // 0x010
    char _pad020[0x94];
    int m_unkB4;            // 0x0B4
    char _pad0B8[4];
    void *m_unkBC;          // 0x0BC (CameraFollow *)
    void *m_unkC0;          // 0x0C0 (CameraCutManager *)
};

#endif
