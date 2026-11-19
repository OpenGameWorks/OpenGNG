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

    char _pad000[0x20];
};

class CameraSpline {
public:
    CameraSpline();
    void AddControlPoint(PVec3 arg0);

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

    Camera *m_pCamera;      // 0x000
    char _pad004[0x10 - 0x004];
    float m_unk10[4];       // 0x010
    float m_unk20[4];       // 0x020
    char _pad030[0x40 - 0x30];
    float m_unk40[4];       // 0x040
    char _pad050[0x0E0 - 0x050];
    int m_unk0E0;           // 0x0E0
    float m_unk0E4;         // 0x0E4
    int m_unk0E8;           // 0x0E8
    float m_unk0EC;         // 0x0EC
    char _pad0F0[0x124 - 0x0F0];
    float m_unk124;         // 0x124
    char _pad128[0x140 - 0x128];
    float m_unk140;         // 0x140
    char _pad144[0x16C - 0x144];
    float m_unk16C;         // 0x16C
    float m_unk170;         // 0x170
    char _pad174[0x17C - 0x174];
    float m_unk17C;         // 0x17C
    float *m_unk180;        // 0x180
    char _pad184[0x1A0 - 0x184];
    float m_unk1A0;         // 0x1A0
    char _pad1A4[0x1B8 - 0x1A4];
    signed char m_unk1B8;   // 0x1B8
    signed char m_unk1B9;   // 0x1B9
    char _pad1BA[0x22C - 0x1BA];
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
