#ifndef CAMERA_H
#define CAMERA_H

#include "types.h"

// TODO(header): foreign declarations
class CVector3;
class PVec3;
class PMat4;

class Camera {
public:
    void SetViewMatrix(PMat4 mat);
    Camera();
    float Distance(CVector3 arg0, CVector3 arg1);
    float Dot(CVector3 arg0, CVector3 arg1);
    float Magnitude(CVector3 arg0);
    CVector3 ClosestPointOnLine(CVector3 arg0, CVector3 arg1, CVector3 arg2);
    void SetEntityYOffset(unsigned short arg0);
    unsigned short GetEntityYOffset();
    int ControlledByApp(unsigned int arg0);
    int ShakeScreenTable(PVec3 &arg0, PVec3 &arg1, bool arg2);
    void ResetCamBoxCount();
    void GetForwardVector(float (&arg0)[4]);
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
    void SetupCutCamera_Pan(unsigned int arg0, unsigned int arg1, float arg2, float arg3, PVec3 arg4, PVec3 arg5, PVec3 arg6, PVec3 arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool arg12, PVec3 arg13, bool arg14, unsigned int arg15);
    void SetupCutCamera_Fixed(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, bool arg11, PVec3 arg12, bool arg13, unsigned int arg14);
    void SetupCutCamera_MoveTo(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, PVec3 arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool arg12, PVec3 arg13, bool arg14, unsigned int arg15);
    void ResetAfterReposition();
    int FollowCamInBossMode();
    void SetFollowCameraParams(float arg0, float arg1);
    void SetSourceTarget(float *arg0, float *arg1);
    void ModifyBossCamera(float arg0, float arg1, float arg2);
    void SetBossPosition(float (*arg0)[4]);
    void SetPosAndRot(float (*arg0)[4], float (*arg1)[4]);
    void SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7);
    void SetCamBoxData(int arg0, void *arg1);
    void SetupShakeScreen(float arg0, float arg1, float arg2, int arg3, int arg4, unsigned int arg5);
    void CamCollideSphere(PVec3 arg0, float arg1);
    bool PlayerInFixedCamBox();
    int SetHeadCam(bool arg0);
    void TextDebug();
    void ResetFollowCamera();
    int SetControlled(unsigned int arg0, bool arg1);
    void RestoreFollowCamPos(bool arg0);
    void SetCamMode(short arg0, bool arg1);
    void Init();
    void Update();
    int UpdateFromCamBox();

    float m_unk00[4];       // 0x000
    float m_unk10[4];       // 0x010
    float m_unk20[4];       // 0x020
    float m_unk30[4][4];    // 0x030 (sceVu0UnitMatrix target)
    float m_unk70[4][4];    // 0x070 (sceVu0UnitMatrix target)
    unsigned char m_unkB0;  // 0x0B0
    unsigned char m_unkB1;  // 0x0B1
    char _pad0B2[2];
    int m_unkB4;           // 0x0B4
    int m_unkB8;            // 0x0B8
    void *m_unkBC;          // 0x0BC (CameraFollow *)
    void *m_unkC0;          // 0x0C0 (CameraCutManager *)
    void *m_unkC4;          // 0x0C4 (CameraDebug *)
    unsigned char m_unkC8;  // 0x0C8
    char _pad0C9[0xCC - 0xC9];
    int m_unkCC;            // 0x0CC
    int m_unkD0;            // 0x0D0
    int m_unkD4[20];        // 0x0D4
    int m_unk124;           // 0x124
    unsigned char m_unk128; // 0x128
    char _pad129[0x130 - 0x129];
    float m_unk130;         // 0x130
    float m_unk134;         // 0x134
    float m_unk138;         // 0x138
    char _pad13C[0x140 - 0x13C];
    float m_unk140;         // 0x140
    int m_unk144;           // 0x144
    int m_unk148;           // 0x148
    int m_unk14C;           // 0x14C
    char _pad150[0x154 - 0x150];
    float m_unk154;         // 0x154
    float m_unk158;         // 0x158
    float m_unk15C;         // 0x15C
    float m_unk160;         // 0x160
    char _pad164[0x168 - 0x164];
    float m_unk168;         // 0x168
    char _pad16C[0x170 - 0x16C];
    unsigned char m_unk170; // 0x170
    char _pad171[0x174 - 0x171];
    float m_unk174;         // 0x174
    unsigned char m_unk178; // 0x178
    unsigned char m_unk179; // 0x179
    char _pad17A[0x17C - 0x17A];
    int m_unk17C[3];        // 0x17C
    char _pad188[0x2B0 - 0x188];
    int m_unk2B0;           // 0x2B0
    void *m_unk2B4;         // 0x2B4
    unsigned char m_unk2B8; // 0x2B8
    char _pad2B9[3];
    int m_unk2BC;           // 0x2BC
    int m_unk2C0;           // 0x2C0
    char _pad2C4[4];
    int m_unk2C8;           // 0x2C8
    char _pad2CC[4];
    float m_unk2D0;         // 0x2D0
    float m_unk2D4;         // 0x2D4
    float m_unk2D8;         // 0x2D8
    char _pad2DC[4];
    float m_unk2E0;         // 0x2E0
    unsigned int m_unk2E4;  // 0x2E4
    char _pad2E8[0x2F0 - 0x2E8];
    float m_unk2F0[4];      // 0x2F0
    float m_unk300[4];      // 0x300
};

#endif
