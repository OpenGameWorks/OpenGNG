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
    float m_unk10;         // 0x10 (accumulated arc length)
    char _pad014[0xC];
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
    float m_unkC;                       // 0x00C (minimum arc length)
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
    void ProcessHeadCam();
    int PlayerMovedSinceLastSwing();
    int PlayerExitingLevel();
    void SetFollowCameraParams(float arg0, float arg1);
    int SetHeadCam(bool arg0);
    void GetPlayerDetails();
    void ProcessPlayerIO();
    void CreatePathFromPlayersRoute();
    void CreatePathToPlayer();
    void DrawTextDebug();
    void SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7);

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
    unsigned char m_unk110; // 0x110
    char _pad111[0x114 - 0x111];
    void *m_unk114;         // 0x114
    int m_unk118;           // 0x118
    int m_unk11C;           // 0x11C
    unsigned char m_unk120; // 0x120
    char _pad121[0x124 - 0x121];
    float m_unk124;         // 0x124
    char _pad128[0x130 - 0x128];
    float m_unk130[4];      // 0x130
    float m_unk140;         // 0x140
    float m_unk144;         // 0x144
    short m_unk148;         // 0x148
    char _pad14A[0x160 - 0x14A];
    int m_unk160;           // 0x160
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
    float m_unk1B0;         // 0x1B0
    float m_unk1B4;         // 0x1B4
    signed char m_unk1B8;   // 0x1B8
    signed char m_unk1B9;   // 0x1B9
    unsigned char m_unk1BA; // 0x1BA
    unsigned char m_unk1BB; // 0x1BB
    signed char m_unk1BC;   // 0x1BC
    char _pad1BD[0x1C0 - 0x1BD];
    float m_unk1C0[4];      // 0x1C0
    float m_unk1D0[4];      // 0x1D0
    unsigned char m_unk1E0; // 0x1E0
    char _pad1E1[0x1E4 - 0x1E1];
    float m_unk1E4;         // 0x1E4
    float m_unk1E8;         // 0x1E8
    float m_unk1EC;         // 0x1EC
    unsigned char m_unk1F0; // 0x1F0
    char _pad1F1[0x1F4 - 0x1F1];
    float m_unk1F4;         // 0x1F4
    unsigned char m_unk1F8; // 0x1F8
    char _pad1F9[0x200 - 0x1F9];
    float m_unk200;         // 0x200
    float m_unk204;         // 0x204
    float m_unk208;         // 0x208
    char _pad20C[0x210 - 0x20C];
    int m_unk210;           // 0x210
    float m_unk214;         // 0x214
    int m_unk218;           // 0x218
    char _pad21C[0x220 - 0x21C];
    int m_unk220;           // 0x220
    float m_unk224;         // 0x224
    int m_unk228;           // 0x228
    unsigned char m_unk22C; // 0x22C
    char _pad22D[0x230 - 0x22D];
    char _pad230[0x80];     // PVec3 array, 8 entries
    float m_unk2B0[4];      // 0x2B0
    unsigned char m_unk2C0; // 0x2C0
    char _pad2C1[0x2D0 - 0x2C1];
    char _pad2D0[0x8];      // CameraSpline, 0x2D0..0x6190
    int m_unk2D8;           // 0x2D8
    char _pad2DC[0x6190 - 0x2DC];
    int m_unk6190;          // 0x6190
    char _pad6194[0x61A0 - 0x6194];
    float m_unk61A0[10][4]; // 0x61A0
    char _pad6240[0x6250 - 0x6240];
    float m_unk6250;        // 0x6250
    int m_unk6254;          // 0x6254
    int m_unk6258;          // 0x6258
    char _pad625C[0x628C - 0x625C];
    int m_unk628C;          // 0x628C
    unsigned char m_unk6290; // 0x6290
    char _pad6291[0x62B0 - 0x6291];
    unsigned char m_unk62B0; // 0x62B0
    char _pad62B1[0x62D1 - 0x62B1];
    unsigned char m_unk62D1; // 0x62D1
    char _pad62D2[0x62F0 - 0x62D2];
    unsigned char m_unk62F0; // 0x62F0
    unsigned char m_unk62F1; // 0x62F1
    char _pad62F2[0x62F4 - 0x62F2];
    int m_unk62F4;          // 0x62F4
    unsigned char m_unk62F8; // 0x62F8
    char _pad62F9[0x6310 - 0x62F9];
    unsigned char m_unk6310; // 0x6310
    char _pad6311[3];
    unsigned int m_unk6314;  // 0x6314
    int m_unk6318;          // 0x6318
    unsigned char m_unk631C; // 0x631C
    char _pad631D[0x6324 - 0x631D];
    float m_unk6324;        // 0x6324
    float m_unk6328;        // 0x6328
    char _pad632C[0x6330 - 0x632C];
    float m_unk6330[4];     // 0x6330
    float m_unk6340[4];     // 0x6340
    float m_unk6350;        // 0x6350
    float m_unk6354;        // 0x6354
    char _pad6358[0x6360 - 0x6358];
    int m_unk6360;          // 0x6360
    char _pad6364[0x636C - 0x6364];
    float m_unk636C;        // 0x636C
    unsigned char m_unk6370; // 0x6370
    unsigned char m_unk6371; // 0x6371
    char _pad6372[0x6374 - 0x6372];
    float m_unk6374;        // 0x6374
    float m_unk6378;        // 0x6378
    float m_unk637C;        // 0x637C
    float m_unk6380;        // 0x6380
    int m_unk6384;          // 0x6384
    char _pad6388[4];
    float m_unk638C;        // 0x638C
    float m_unk6390;        // 0x6390
    float m_unk6394;        // 0x6394
    float m_unk6398;        // 0x6398
    char m_unk639C[0x40];   // 0x639C debug text buffer for DrawTextDebug; size not verified
};

#endif
