#ifndef CAMERACUTSCENE_H
#define CAMERACUTSCENE_H

#include "types.h"

// TODO(header): foreign declarations
class Camera;
class PVec3;
class CutSceneCamera_Generic;

class CameraCutManager {
public:
    CameraCutManager(Camera *arg0);
    int CutCameraExists(unsigned int arg0);
    void StopCutCamera(bool bRestore);
    void GetTargetPositionFromInstance(unsigned int nInstance, PVec3 &arg1);
    void SetSourceTarget(PVec3 arg0, PVec3 arg1);
    void AddCutSceneCamera(void *pCam, unsigned int nArg);
    void SetupCutCamera_Pan(unsigned int arg0, unsigned int arg1, float fA, float fB, PVec3 v4, PVec3 v5, PVec3 v6, PVec3 v7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool b12, PVec3 v13, bool b14, unsigned int arg15);
    void SetupCutCamera_MoveTo(unsigned int arg0, unsigned int arg1, float fA, float fB, unsigned int arg4, PVec3 v5, PVec3 v6, PVec3 v7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool b12, PVec3 v13, bool b14, unsigned int arg15);
    void SetupCutCamera_Fixed(unsigned int arg0, unsigned int arg1, float fA, float fB, unsigned int arg4, PVec3 v5, PVec3 v6, unsigned int arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, bool b11, PVec3 v12, bool b13, unsigned int arg14);
    void CleanUpCutCameras();
    ~CameraCutManager();

    void *GetFirstCutCamera(unsigned int arg0);
    int CutCameraMovesPlayer(unsigned int arg0);
    void StartCutCamera(unsigned int arg0, bool bArg);
    int ProcessCutCameras();
    int Update();
    void HideText();
    void ShowText();
    void ActivateInstances(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
    void FreeUpCameraStructure(CutSceneCamera_Generic *arg0);

    Camera *m_unk0;             // 0x000
    char _pad004[0x0C];
    float m_unk10[16];          // 0x010 (4x4 matrix)
    float m_unk50[4];           // 0x050
    float m_unk60[4];           // 0x060
    char m_unk70[4];            // 0x070 (PList head, extent assumed)
    char *m_unk74;              // 0x074
    char _pad078[4];
    char *m_unk7C;              // 0x07C
    int m_unk80;                // 0x080
    unsigned char m_unk84;      // 0x084
    unsigned char m_unk85;      // 0x085
    char _pad086[2];
    int m_unk88;                // 0x088
    int m_unk8C;                // 0x08C
    int m_unk90;                // 0x090
    char *m_pCurrentCamera;     // 0x094
    char *m_unk98;              // 0x098
    int m_unk9C;                // 0x09C
    int m_unkA0;                // 0x0A0
    char _padA4[0xC8 - 0xA4];
    unsigned char m_unkC8;      // 0x0C8
    unsigned char m_unkC9;      // 0x0C9
    unsigned char m_unkCA;      // 0x0CA
    unsigned char m_unkCB;      // 0x0CB
    unsigned char m_unkCC;      // 0x0CC
};

#endif
