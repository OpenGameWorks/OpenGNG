#include "CameraCutscene.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" void __dt__5PListFv(void *pThis, short nFlag);
extern "C" void __ct__5PListFv(void *pThis);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void __dl__FPv(void *p);
extern unsigned char mbGlobalSleep__15EntityBaseClass;
extern unsigned char gInterface[];
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern int InnocentDialogID[0x100];

class FontManager {
public:
    void RemoveAll(bool bFlag);
    void DisplayString(int nDialogID, int nX, int nY, bool bFlag);
};

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

class CutSceneCamera_Generic {
public:
    char _pad000[0x10];
    int m_unk10;
};

// FUNCTION: 0x0017AAE0 CutCameraExists__16CameraCutManagerFUi
int CameraCutManager::CutCameraExists(unsigned int arg0) {
    return GetFirstCutCamera(arg0) != 0;
}

// FUNCTION: 0x0017AB00 HideText__16CameraCutManagerFv
void CameraCutManager::HideText() {
    char *pCam = m_pCurrentCamera;
    if (pCam == 0) {
        pCam = m_unk98;
    }
    if (pCam == 0) {
        CdsAssert("CameraCutscene.cpp", 0x48C, "apCamera");
    }
    if (*(int *)(pCam + 0x40) != 0) {
        FontManager *pFont = (FontManager *)(gInterface + 0x1790);
        if (pFont == 0) {
            CdsAssert("CameraCutscene.cpp", 0x493, "apoFontManager");
        }
        pFont->RemoveAll(true);
    }
}

// FUNCTION: 0x0017AB90 ShowText__16CameraCutManagerFv
void CameraCutManager::ShowText() {
    if (m_pCurrentCamera == 0) {
        CdsAssert("CameraCutscene.cpp", 0x470, "m_pCurrentCamera");
    }
    if (*(int *)(m_pCurrentCamera + 0x40) != 0) {
        FontManager *pFont = (FontManager *)(gInterface + 0x1790);
        if (pFont == 0) {
            CdsAssert("CameraCutscene.cpp", 0x477, "apoFontManager");
        }
        if ((unsigned int)*(int *)(m_pCurrentCamera + 0x40) >= 0x100) {
            CdsAssert("CameraCutscene.cpp", 0x479, "m_pCurrentCamera->m_iTextID < MAX_DIALOG");
        }
        pFont->DisplayString(InnocentDialogID[*(int *)(m_pCurrentCamera + 0x40)], 0, 0, false);
    }
}

// DRAFT: 0x0017AC60 ActivateInstances__16CameraCutManagerFUiUiUiUi
// note: 20 differing lines; only register allocation differs (arg2 and p swapped between s0 and s1). Tried char*/void* p per block or at function scope, compound and truthiness guards, and p = 0 init; none dropped below 20.
void CameraCutManager::ActivateInstances(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    void *p = 0;
    if (arg0) {
        p = (void *)InstanceIsValid__15EntityBaseClassFUi(arg0);
        if (p != 0 && ((int (*)(void *))((void **)*(void ***)p)[0x11])(p) == 0) {
            ((char *)p)[0x1A] = 1;
        }
    }
    if (arg1) {
        p = (void *)InstanceIsValid__15EntityBaseClassFUi(arg1);
        if (p != 0 && ((int (*)(void *))((void **)*(void ***)p)[0x11])(p) == 0) {
            ((char *)p)[0x1A] = 1;
        }
    }
    if (arg2) {
        p = (void *)InstanceIsValid__15EntityBaseClassFUi(arg2);
        if (p != 0 && ((int (*)(void *))((void **)*(void ***)p)[0x11])(p) == 0) {
            ((char *)p)[0x1A] = 1;
        }
    }
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

// FUNCTION: 0x0017C3D0 FreeUpCameraStructure__16CameraCutManagerFP22CutSceneCamera_Generic
void CameraCutManager::FreeUpCameraStructure(CutSceneCamera_Generic *arg0) {
    switch (arg0->m_unk10) {
    case 1:
        if (arg0 != 0) {
            __dl__FPv(arg0);
        }
        break;
    case 2:
        if (arg0 != 0) {
            __dl__FPv(arg0);
        }
        break;
    case 3:
        if (arg0 != 0) {
            __dl__FPv(arg0);
        }
        break;
    default:
        CdsAssert("CameraCutscene.cpp", 0x95, "Tried to free invalid camera type");
        break;
    }
}

// FUNCTION: 0x0017C740 __dt__16CameraCutManagerFv
CameraCutManager::~CameraCutManager() {
    __dt__5PListFv((void *)m_unk70, -1);
}

// DRAFT: 0x0017C7A0 __ct__16CameraCutManagerFP6Camera
// note: 39 differing words; original keeps this in s1 across the calls (frame 0x30, saves s1 at 0x10, ra at 0x20), draft reloads this from the stack. Local self copy and the plain form both give 39.
CameraCutManager::CameraCutManager(Camera *arg0) {
    sceVu0UnitMatrix((float *)((char *)this + 0x10));
    __ct__5PListFv((void *)m_unk70);
    m_unk0 = arg0;
    m_unk80 = 0;
    m_unk84 = 0;
    m_unk88 = 1;
    m_pCurrentCamera = 0;
    m_unk8C = 0;
    m_unk90 = 0;
    m_unk9C = 0;
    m_unkA0 = 0;
    m_unk85 = 0;
    m_unkC8 = 0;
    m_unkC9 = 0;
}
