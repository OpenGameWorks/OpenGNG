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
    int MoveCameraToNewViewpoint();
    void KeepUpWithPlayer();
    void ProcessRightAnalogue();
    void ResetFromCamBox();
    int PlayerIsIdle();
    void FollowPlayer();
    int CanDoHeadcam();
    void IdleFreezeCheck();
    void ResetTrackingVars();
    void StorePlayerPos();
    void AddTwistEffect();
    void CamCollideSphere(PVec3 arg0, float arg1);
    void CamCollideCylinder(PVec3 arg0, float arg1, float arg2);
    float GetAngleBetweenCamAndPlayer(float &arg0);
    int ProcessCamBox();
    int PlayerMovedSinceLastSwing();

    Camera *m_pCamera;      // 0x000
    char _pad004[0x10 - 0x004];
    float m_unk10[4];       // 0x010
    float m_unk20[4];       // 0x020
    char _pad030[0x40 - 0x30];
    float m_unk40[4];       // 0x040
    char _pad050[0x0A0 - 0x050];
    float m_unkA0;          // 0x0A0
    char _padA4[0x0A8 - 0x0A4];
    float m_unkA8;          // 0x0A8
    char _padAC[0x0C0 - 0x0AC];
    float m_unkC0;          // 0x0C0
    char _padC4[0x0C8 - 0x0C4];
    float m_unkC8;          // 0x0C8
    char _padCC[0x0E0 - 0x0CC];
    int m_unk0E0;           // 0x0E0
    float m_unk0E4;         // 0x0E4
    int m_unk0E8;           // 0x0E8
    float m_unk0EC;         // 0x0EC
    char _pad0F0[0x124 - 0x0F0];
    float m_unk124;         // 0x124
    char _pad128[0x140 - 0x128];
    float m_unk140;         // 0x140
    float m_unk144;         // 0x144
    char _pad148[0x164 - 0x148];
    float m_unk164;         // 0x164
    char _pad168[0x16C - 0x168];
    float m_unk16C;         // 0x16C
    float m_unk170;         // 0x170
    float m_unk174;         // 0x174
    char _pad178[0x17C - 0x178];
    float m_unk17C;         // 0x17C
    float *m_unk180;        // 0x180
    int m_unk184;           // 0x184
    char _pad188[0x1A0 - 0x188];
    float m_unk1A0;         // 0x1A0
    char _pad1A4[0x1B8 - 0x1A4];
    signed char m_unk1B8;   // 0x1B8
    signed char m_unk1B9;   // 0x1B9
    char _pad1BA[0x1C0 - 0x1BA];
    float m_unk1C0[4];      // 0x1C0
    float m_unk1D0[4];      // 0x1D0
    char _pad1E0[0x210 - 0x1E0];
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
    char _pad6190[0x61A0 - 0x6190];
    float m_unk61A0[10][4]; // 0x61A0
    char _pad6240[0x6290 - 0x6240];
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
