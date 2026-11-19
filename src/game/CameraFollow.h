#ifndef CAMERAFOLLOW_H
#define CAMERAFOLLOW_H

#include "types.h"

// TODO(header): foreign declarations
class PVec3;

class tag_ControlData {
public:
    ~tag_ControlData();
};

class tag_CurveData {
public:
    ~tag_CurveData();
};

class CameraSpline {
public:
    void AddControlPoint(PVec3 arg0);

    int m_iNumCtrlPoints;               // 0x000
    char _pad004[0x5DD0 - 0x004];
    float m_ctrlPts[15][4];             // 0x5DD0
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

    char _pad000[0x20];
    float m_unk20[4];       // 0x020
    char _pad030[0x40 - 0x30];
    float m_unk40[4];       // 0x040
    char _pad050[0x140 - 0x50];
    float m_unk140;         // 0x140
    char _pad144[0x17C - 0x144];
    float m_unk17C;         // 0x17C
    char _pad180[0x1A0 - 0x180];
    float m_unk1A0;         // 0x1A0
    char _pad1A4[0x1B8 - 0x1A4];
    signed char m_unk1B8;   // 0x1B8
    signed char m_unk1B9;   // 0x1B9
    char _pad1BA[0x2C0 - 0x1BA];
    unsigned char m_unk2C0; // 0x2C0
    char _pad2C1[0x6398 - 0x2C1];
    int m_unk6398;          // 0x6398
};

#endif
