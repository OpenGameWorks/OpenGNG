#ifndef CAMERAAPI_H
#define CAMERAAPI_H

#include "types.h"

class Camera;
class EntityBaseClass;

class CameraAPI {
public:
    void SetFollowCameraParams(float arg0, float arg1);
    void SetCameraLookAtParams(EntityBaseClass *arg0, float *arg1, float *arg2);
    bool TakeControlOfCamera(EntityBaseClass *arg0, bool arg1);
    void FollowCamInBossMode();
    void SetBossPosition(float (*arg0)[4]);

    Camera *m_unk0;     // 0x000 (m_pCamera)
};

#endif
