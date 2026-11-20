#ifndef CAMERAAPI_H
#define CAMERAAPI_H

#include "types.h"

class Camera;
class EntityBaseClass;

class CameraAPI {
public:
    void SetFollowCameraParams(float arg0, float arg1);
    void ReleaseControlOfCamera(EntityBaseClass *arg0, bool arg1);
    void SetCameraLookAtParams(EntityBaseClass *arg0, float *arg1, float *arg2);
    bool TakeControlOfCamera(EntityBaseClass *arg0, bool arg1);
    void FollowCamInBossMode();
    void ModifyBossCamera(float arg0, float arg1, float arg2);
    void SetBossPosition(float (*arg0)[4]);
    void SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7);
    void ShakeScreenUsingTable(int arg0, unsigned int arg1);
    void ShakeScreen(float arg0, float arg1, float arg2, unsigned int arg3);

    Camera *m_unk0;     // 0x000 (m_pCamera)
};

#endif
