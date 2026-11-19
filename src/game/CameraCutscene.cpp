#include "CameraCutscene.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" void __dt__5PListFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *p);
extern unsigned char mbGlobalSleep__15EntityBaseClass;
extern unsigned char gInterface[];

class Camera {
public:
    void RestoreFollowCamPos(bool bRestore);
    void SetCamMode(short nMode, bool bFlag);
    char _pad000[0x2B8];
    unsigned char m_unk2B8;
};

class PVec3 {
public:
    PVec3(const PVec3 &) {}
    float m_v[4];
};

// FUNCTION: 0x0017AAE0 CutCameraExists__16CameraCutManagerFUi
int CameraCutManager::CutCameraExists(unsigned int arg0) {
    return GetFirstCutCamera(arg0) != 0;
}

// FUNCTION: 0x0017AD40 StopCutCamera__16CameraCutManagerFb
void CameraCutManager::StopCutCamera(bool bRestore) {
    m_unk88 = 1;
    if (bRestore) {
        m_unk0->RestoreFollowCamPos(true);
    }
    m_unk0->SetCamMode(0, false);
    m_unk0->m_unk2B8 = 0;
    m_unk85 = 0;
    HideText();
    mbGlobalSleep__15EntityBaseClass = m_unkCC;
    *(unsigned short *)(gInterface + 0x1B24) = 0;
    *(unsigned int *)(gInterface + 0x18D0) |= 0xE;
}

// FUNCTION: 0x0017B240 GetTargetPositionFromInstance__16CameraCutManagerFUiR5PVec3
void CameraCutManager::GetTargetPositionFromInstance(unsigned int nInstance, PVec3 &arg1) {
    char *pEntity = (char *)InstanceIsValid__15EntityBaseClassFUi(nInstance);
    if (pEntity != 0) {
        char *pAlt = *(char **)(pEntity + 0x3C);
        float *pSrc;
        if (pAlt != 0) {
            pSrc = (float *)(pAlt + 0x80);
        } else {
            pSrc = (float *)(pEntity + 0x190);
        }
        arg1.m_v[0] = pSrc[0];
        arg1.m_v[1] = pSrc[1];
        arg1.m_v[2] = pSrc[2];
    }
}

// FUNCTION: 0x0017B880 SetSourceTarget__16CameraCutManagerF5PVec35PVec3
void CameraCutManager::SetSourceTarget(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_unk50, arg0.m_v);
    sceVu0CopyVector(m_unk60, arg1.m_v);
}

// FUNCTION: 0x0017C740 __dt__16CameraCutManagerFv
CameraCutManager::~CameraCutManager() {
    __dt__5PListFv((void *)m_unk70, -1);
}
