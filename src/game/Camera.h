#ifndef CAMERA_H
#define CAMERA_H

#include "types.h"

// TODO(header): foreign declarations
class CVector3;
class PVec3;
class PMat4;

class Camera {
public:
    float Distance(CVector3 arg0, CVector3 arg1);
    float Dot(CVector3 arg0, CVector3 arg1);
    float Magnitude(CVector3 arg0);
    CVector3 Normalize(CVector3 arg0);
    void UpdateFromApparition();
    void CreateViewMatrix(PMat4 &arg0, PVec3 arg1, PVec3 arg2);
    void SetCamBoxValue_FollowHeight(float arg0);
    void CheckCameraShake(PVec3 &arg0, PVec3 &arg1, bool arg2);
    void CamCollideCylinder(PVec3 arg0, float arg1, float arg2);
    void PolyDebug();
    bool ShakeScreen(PVec3 &arg0, PVec3 &arg1, bool arg2);
    unsigned char PlayingCutCamera();
    void CleanUpCutCameras();
    void RestoreCamBox();
    void StartCutCamera(unsigned int arg0, bool arg1);
    void SetupCutCamera_Fixed(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, bool arg11, PVec3 arg12, bool arg13, unsigned int arg14);
    void ResetAfterReposition();
    int FollowCamInBossMode();
    void SetFollowCameraParams(float arg0, float arg1);
    void SetSourceTarget(float *arg0, float *arg1);
    void ModifyBossCamera(float arg0, float arg1, float arg2);
    void SetBossPosition(float (*arg0)[4]);
    void SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7);
    void SetCamBoxData(int arg0, void *arg1);
    void SetupShakeScreen(float arg0, float arg1, float arg2, int arg3, int arg4, unsigned int arg5);
    void CamCollideSphere(PVec3 arg0, float arg1);
    bool PlayerInFixedCamBox();
    int SetHeadCam(bool arg0);
    void TextDebug();
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
    void *m_unkC4;          // 0x0C4 (CameraDebug *)
    unsigned char m_unkC8;  // 0x0C8
    char _pad0C9[0x148 - 0xC9];
    int m_unk148;           // 0x148
    int m_unk14C;           // 0x14C
    char _pad150[0x158 - 0x150];
    float m_unk158;         // 0x158
    float m_unk15C;         // 0x15C
    char _pad160[0x170 - 0x160];
    unsigned char m_unk170; // 0x170
    char _pad171[0x174 - 0x171];
    float m_unk174;         // 0x174
    char _pad178[0x179 - 0x178];
    unsigned char m_unk179; // 0x179
    char _pad17A[0x17C - 0x17A];
    int m_unk17C[3];        // 0x17C
    char _pad188[0x2B0 - 0x188];
    int m_unk2B0;           // 0x2B0
    void *m_unk2B4;         // 0x2B4
    unsigned char m_unk2B8; // 0x2B8
    char _pad2B9[0x2E4 - 0x2B9];
    unsigned int m_unk2E4;  // 0x2E4
};

#endif
