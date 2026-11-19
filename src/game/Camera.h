#ifndef CAMERA_H
#define CAMERA_H

#include "types.h"

// TODO(header): foreign declarations
class CVector3;
class PVec3;

class Camera {
public:
    float Magnitude(CVector3 arg0);
    void CheckCameraShake(PVec3 &arg0, PVec3 &arg1, bool arg2);
    void CamCollideCylinder(PVec3 arg0, float arg1, float arg2);
    void PolyDebug();
    bool ShakeScreen(PVec3 &arg0, PVec3 &arg1, bool arg2);
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
    int SetControlled(unsigned int arg0, bool arg1);

    float m_unk00[4];       // 0x000
    float m_unk10[4];       // 0x010
    char _pad020[0x90];
    unsigned char m_unkB0;  // 0x0B0
    char _pad0B1[3];
    int m_unkB4;            // 0x0B4
    char _pad0B8[4];
    void *m_unkBC;          // 0x0BC (CameraFollow *)
    void *m_unkC0;          // 0x0C0 (CameraCutManager *)
    char _pad0C4[0x179 - 0xC4];
    unsigned char m_unk179; // 0x179
    char _pad17A[0x2B8 - 0x17A];
    unsigned char m_unk2B8; // 0x2B8
    char _pad2B9[0x2E4 - 0x2B9];
    unsigned int m_unk2E4;  // 0x2E4
};

#endif
