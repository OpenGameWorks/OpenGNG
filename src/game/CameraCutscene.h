#ifndef CAMERACUTSCENE_H
#define CAMERACUTSCENE_H

#include "types.h"

// TODO(header): foreign declarations
class Camera;
class PVec3;

class CameraCutManager {
public:
    int CutCameraExists(unsigned int arg0);
    void StopCutCamera(bool bRestore);
    void GetTargetPositionFromInstance(unsigned int nInstance, PVec3 &arg1);
    void SetSourceTarget(PVec3 arg0, PVec3 arg1);
    ~CameraCutManager();

    void *GetFirstCutCamera(unsigned int arg0);
    void HideText();

    Camera *m_unk0;             // 0x000
    char _pad004[0x50 - 0x04];
    float m_unk50[4];           // 0x050
    float m_unk60[4];           // 0x060
    char m_unk70[0x85 - 0x70];  // 0x070 (PList, extent assumed)
    unsigned char m_unk85;      // 0x085
    char _pad086[2];
    int m_unk88;                // 0x088
    char _pad08C[0x40];
    unsigned char m_unkCC;      // 0x0CC
};

#endif
