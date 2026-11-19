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
    ~CameraCutManager();

    void *GetFirstCutCamera(unsigned int arg0);
    void HideText();
    void ShowText();
    void ActivateInstances(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
    void FreeUpCameraStructure(CutSceneCamera_Generic *arg0);

    Camera *m_unk0;             // 0x000
    char _pad004[0x50 - 0x04];
    float m_unk50[4];           // 0x050
    float m_unk60[4];           // 0x060
    char m_unk70[0x10];         // 0x070 (PList, extent assumed)
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
    char _padCA[2];
    unsigned char m_unkCC;      // 0x0CC
};

#endif
