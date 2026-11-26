#ifndef CAMERACUTSCENE_H
#define CAMERACUTSCENE_H

#include "types.h"
#include "PList.h"
#include "CameraDebug.h"

// TODO(header): foreign declarations
class Camera;
class PVec3;
class CutSceneCamera_Generic;

// One instance's cut cameras: the instance ID followed by its camera list (0x14 bytes).
struct CutCameraGroup {
    unsigned int m_unk0;        // 0x00 instance ID
    PList m_unk4;               // 0x04 CutSceneCamera_Generic items
};

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
    void *GetNextCutCamera(unsigned int nInstance, unsigned int nValue);
    int CutCameraMovesPlayer(unsigned int arg0);
    void StartCutCamera(unsigned int arg0, bool bArg);
    /**
     * Advances the cut-camera state machine for the current frame.
     *
     * Runs states in sequence until one waits for a later frame.
     *
     * @return The m_unk85 active flag: 1 while a cut camera is running, 0 when idle.
     */
    int ProcessCutCameras();
    bool ProcessCutCamera();
    int Update();
    void HideText();
    void ShowText();
    void ActivateInstances(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
    void FreeUpCameraStructure(CutSceneCamera_Generic *arg0);

    Camera *m_unk0;             // 0x000
    char _pad004[0x0C];
    CameraDebugMat m_unk10;     // 0x010 identity-initialised matrix
    float m_unk50[4];           // 0x050
    float m_unk60[4];           // 0x060
    PList m_unk70;              // 0x070 cut-camera groups (CutCameraGroup items)
    CutCameraGroup *m_unk80;    // 0x080 group selected by GetNextCutCamera
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
    char _padA4[0xB0 - 0xA4];
    float m_unkB0[4];           // 0x0B0
    int m_unkC0;                // 0x0C0
    float m_unkC4;              // 0x0C4
    unsigned char m_unkC8;      // 0x0C8
    unsigned char m_unkC9;      // 0x0C9
    unsigned char m_unkCA;      // 0x0CA
    unsigned char m_unkCB;      // 0x0CB
    unsigned char m_unkCC;      // 0x0CC
};

#endif
