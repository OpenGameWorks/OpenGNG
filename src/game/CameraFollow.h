#ifndef CAMERAFOLLOW_H
#define CAMERAFOLLOW_H

#include "types.h"

// TODO(header): foreign declarations
class PVec3;
class Camera;

class tag_ControlData {
public:
    tag_ControlData();
    ~tag_ControlData();

    float m_v[4];          // 0x00
};

class tag_CurveData {
public:
    tag_CurveData();
    ~tag_CurveData();

    float m_v[4];          // 0x00
    char _pad010[0x10];
};

class CameraSpline {
public:
    CameraSpline();
    void AddControlPoint(PVec3 arg0);
    void GetPosition(unsigned int arg0, PVec3 &arg1);
    void Reset();
    void Create();

    int m_iNumCtrlPoints;               // 0x000
    int m_unk4;                         // 0x004
    int m_unk8;                         // 0x008
    char _pad00C[0x10 - 0x00C];
    tag_CurveData m_curves[750];        // 0x010
    tag_ControlData m_ctrlPts[15];      // 0x5DD0
};

class CameraFollow {
public:
    CameraFollow(Camera *pCam);
    void SetSourceAndTarget(PVec3 arg0, PVec3 arg1);
    void Init(bool arg0);
    void ForceReset(bool arg0);
    void Reset();
    int MoveCameraToNewViewpoint();
    void KeepUpWithPlayer();
    void ProcessRightAnalogue();
    void ResetFromCamBox();
    int PlayerIsIdle();
    void FollowPlayer();
    int CanDoHeadcam();
    void CalcNewCameraOffsets();
    int CalcNewCameraViewpointPos();
    void IdleFreezeCheck();
    void ResetTrackingVars();
    void StorePlayerPos();
    void AddTwistEffect();
    void CamCollideSphere(PVec3 arg0, float arg1);
    void CamCollideCylinder(PVec3 arg0, float arg1, float arg2);
    float GetAngleBetweenCamAndPlayer(float &arg0);
    int ProcessCamBox();
    int PlayerMovedSinceLastSwing();
    int PlayerExitingLevel();
    void SetFollowCameraParams(float arg0, float arg1);
    int SetHeadCam(bool arg0);
    void GetPlayerDetails();
    void ProcessPlayerIO();
    void CreatePathFromPlayersRoute();

    Camera *m_pCamera;      // 0x000
    char _pad004[0x10 - 0x004];
    float m_unk10[4];       // 0x010
    float m_unk20[4];       // 0x020
    char _pad030[0x40 - 0x30];
    float m_unk40[4];       // 0x040
    char _pad050[0x060 - 0x050];
    char _pad060[0x0A0 - 0x060];
    float m_unkA0[16];      // 0x0A0 (PMat4, 64 bytes)
    int m_unk0E0;           // 0x0E0
    float m_unk0E4;         // 0x0E4
    int m_unk0E8;           // 0x0E8
    float m_unk0EC;         // 0x0EC
    float m_unkF0[4];       // 0x0F0
    float m_unk100[4];      // 0x100
    char _pad110[0x114 - 0x110];
    void *m_unk114;         // 0x114
    int m_unk118;           // 0x118
    int m_unk11C;           // 0x11C
    char _pad120[0x124 - 0x120];
    float m_unk124;         // 0x124
    char _pad128[0x130 - 0x128];
    float m_unk130[4];      // 0x130
    float m_unk140;         // 0x140
    float m_unk144;         // 0x144
    char _pad148[0x164 - 0x148];
    float m_unk164;         // 0x164
    char _pad168[0x16C - 0x168];
    float m_unk16C;         // 0x16C
    float m_unk170;         // 0x170
    float m_unk174;         // 0x174
    float m_unk178;         // 0x178
    float m_unk17C;         // 0x17C
    float *m_unk180;        // 0x180
    float *m_unk184;        // 0x184
    float *m_unk188;        // 0x188
    char _pad18C[4];
    float m_unk190[4];      // 0x190
    float m_unk1A0;         // 0x1A0
    signed char m_unk1A4;   // 0x1A4
    signed char m_unk1A5;   // 0x1A5
    char _pad1A6[0x1A8 - 0x1A6];
    float m_unk1A8;         // 0x1A8
    float m_unk1AC;         // 0x1AC
    char _pad1B0[0x1B8 - 0x1B0];
    signed char m_unk1B8;   // 0x1B8
    signed char m_unk1B9;   // 0x1B9
    signed char m_unk1BA;   // 0x1BA
    unsigned char m_unk1BB; // 0x1BB
    signed char m_unk1BC;   // 0x1BC
    char _pad1BD[0x1C0 - 0x1BD];
    float m_unk1C0[4];      // 0x1C0
    float m_unk1D0[4];      // 0x1D0
    char _pad1E0[0x1F8 - 0x1E0];
    signed char m_unk1F8;   // 0x1F8
    char _pad1F9[0x210 - 0x1F9];
    int m_unk210;           // 0x210
    float m_unk214;         // 0x214
    char _pad218[0x224 - 0x218];
    float m_unk224;         // 0x224
    char _pad228[0x22C - 0x228];
    unsigned char m_unk22C; // 0x22C
    char _pad22D[0x230 - 0x22D];
    char _pad230[0x80];     // PVec3 array, 8 entries
    char _pad2B0[0x2C0 - 0x2B0];
    unsigned char m_unk2C0; // 0x2C0
    char _pad2C1[0x2D0 - 0x2C1];
    char _pad2D0[0x5EC0];   // CameraSpline, 0x2D0..0x6190
    int m_unk6190;          // 0x6190
    char _pad6194[0x61A0 - 0x6194];
    float m_unk61A0[10][4]; // 0x61A0
    char _pad6240[0x6250 - 0x6240];
    float m_unk6250;        // 0x6250
    int m_unk6254;          // 0x6254
    int m_unk6258;          // 0x6258
    char _pad625C[0x6290 - 0x625C];
    unsigned char m_unk6290; // 0x6290
    char _pad6291[0x62F0 - 0x6291];
    unsigned char m_unk62F0; // 0x62F0
    char _pad62F1[0x6310 - 0x62F1];
    unsigned char m_unk6310; // 0x6310
    char _pad6311[3];
    unsigned int m_unk6314;  // 0x6314
    char _pad6318[0x6378 - 0x6318];
    float m_unk6378;        // 0x6378
    float m_unk637C;        // 0x637C
    float m_unk6380;        // 0x6380
    char _pad6384[8];
    float m_unk638C;        // 0x638C
    float m_unk6390;        // 0x6390
    float m_unk6394;        // 0x6394
    int m_unk6398;          // 0x6398
};

#endif
