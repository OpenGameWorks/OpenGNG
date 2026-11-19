#ifndef CAMERAFOLLOW_H
#define CAMERAFOLLOW_H

#include "types.h"

// TODO(header): foreign declarations
class PVec3;

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

    char _pad000[0x10];
    float m_unk10[4];       // 0x010
    float m_unk20[4];       // 0x020
    char _pad030[0x40 - 0x30];
    float m_unk40[4];       // 0x040
    char _pad050[0x140 - 0x50];
    float m_unk140;         // 0x140
    char _pad144[0x17C - 0x144];
    float m_unk17C;         // 0x17C
    float *m_unk180;        // 0x180
    char _pad184[0x1A0 - 0x184];
    float m_unk1A0;         // 0x1A0
    char _pad1A4[0x1B8 - 0x1A4];
    signed char m_unk1B8;   // 0x1B8
    signed char m_unk1B9;   // 0x1B9
    char _pad1BA[0x2C0 - 0x1BA];
    unsigned char m_unk2C0; // 0x2C0
    char _pad2C1[0x61A0 - 0x2C1];
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
