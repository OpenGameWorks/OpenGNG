#include "CameraCutscene.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" void __dt__5PListFv(void *pThis, short nFlag);
extern "C" void __ct__5PListFv(void *pThis);
extern "C" void RemoveAll__5PListFv(void *pThis);
extern "C" void RemoveCurrent__5PListFv(void *pThis);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void __dl__FPv(void *p);
extern unsigned char mbGlobalSleep__15EntityBaseClass;
extern unsigned char gInterface[];
extern char gEng[105360];
extern "C" void CallAllOnStopAttack__19EntityAttackManagerFv(void *pThis);
extern "C" void ReleaseHeadCamera__6PlayerFv(void *pThis);
extern "C" void UpdatePos__6CameraF5PVec35PVec3(void *pThis, float *pA, float *pB);
extern "C" void CheckCameraShake__6CameraFR5PVec3R5PVec3b(void *pThis, float *pA, float *pB, bool bFlag);
extern "C" void CreateViewMatrix__6CameraFR5PMat45PVec35PVec3(void *pThis, float *pMatrix, float *pA, float *pB);
extern "C" void SetViewMatrix__6CameraF5PMat4(void *pThis, float *pMatrix);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern int InnocentDialogID[0x100];
extern "C" void *__nw__FUi(unsigned int);
// MemMgr is 908 bytes; the field at offset 0x18 is saved and cleared around the allocation.
extern char MemMgr[908];

class FontManager {
public:
    void RemoveAll(bool bFlag);
    void DisplayString(int nDialogID, int nX, int nY, bool bFlag);
};

class Camera {
public:
    void RestoreFollowCamPos(bool bRestore);
    void SetCamMode(short nMode, bool bFlag);
    char _pad000[0x10];
    float m_unk10[4];
    char _pad020[0x2B8 - 0x20];
    unsigned char m_unk2B8;
    char _pad2B9[0x2F0 - 0x2B9];
    float m_unk2F0[4];
    float m_unk300[4];
};

class PVec3 {
public:
    PVec3(const PVec3 &) {}
    float m_v[4];
};

class CutSceneCamera_Generic {
public:
    float m_unk0;
    float m_unk4;
    unsigned char m_unk8;
    char _pad009[3];
    unsigned int m_unkC;
    int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1C;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned char m_unk28;
    unsigned char m_unk29;
    char _pad02A[6];
    float m_unk30[4];
    unsigned int m_unk40;
    char _pad044[0xC];
    unsigned int m_unk50;
    char _pad054[0xC];
    float m_unk60[4];
    float m_unk70[4];
    float m_unk80[4];
    float m_unk90[4];
};

// DRAFT: 0x0017A9A0 CutCameraMovesPlayer__16CameraCutManagerFUi
// note: entry layout matches via ternary entry; loop body uses a2 for the node where the original uses v1 (register allocation). Variants: pNext hoisting, inner-block decls, lbu flag, local reorder, if-else entry, cast ternary.
int CameraCutManager::CutCameraMovesPlayer(unsigned int arg0) {
    char *pNode;
    char *pElem;
    char *pNext;
    m_unk7C = m_unk74;
    pNode = m_unk74 != 0 ? *(char **)m_unk74 : (char *)0;
    while (pNode != 0) {
        if (*(unsigned int *)pNode == arg0) {
            *(char **)(pNode + 0x10) = *(char **)(pNode + 8);
            pElem = 0;
            if (*(char **)(pNode + 8) != 0) {
                pElem = *(char **)(*(char **)(pNode + 8));
            }
            while (pElem != 0) {
                if (*(unsigned char *)(pElem + 0x29) != 0) {
                    return 1;
                }
                if (*(char **)(pNode + 0x10) == 0) {
                    *(char **)(pNode + 0x10) = *(char **)(pNode + 8);
                    pElem = 0;
                    if (*(char **)(pNode + 8) != 0) {
                        pElem = *(char **)(*(char **)(pNode + 8));
                    }
                } else {
                    pNext = *(char **)(*(char **)(pNode + 0x10) + 4);
                    if (pNext != 0) {
                        *(char **)(pNode + 0x10) = pNext;
                        pElem = *(char **)(*(char **)(pNode + 0x10));
                    } else {
                        pElem = 0;
                    }
                }
            }
        }
        if (m_unk7C != 0) {
            pNext = *(char **)(m_unk7C + 4);
            if (pNext != 0) {
                m_unk7C = pNext;
                pNode = *(char **)m_unk7C;
            } else {
                pNode = 0;
            }
        } else {
            m_unk7C = m_unk74;
            pNode = 0;
            if (m_unk74 != 0) {
                pNode = *(char **)m_unk74;
            }
        }
    }
    return 0;
}

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

// FUNCTION: 0x0017ADC0 StartCutCamera__16CameraCutManagerFUib
void CameraCutManager::StartCutCamera(unsigned int arg0, bool bArg) {
    if (m_unk85 == 0) {
        m_unk8C = arg0;
        m_unk88 = 2;
        m_unkC8 = 0;
        m_unkC9 = 0;
        m_unkCB = 0;
        Camera *pCam = m_unk0;
        sceVu0CopyVector(pCam->m_unk2F0, (float *)pCam);
        sceVu0CopyVector(pCam->m_unk300, pCam->m_unk10);
        m_unk0->SetCamMode(1, false);
        m_unk0->m_unk2B8 = 1;
        m_unk85 = 1;
        m_unkCA = bArg;
        if (CutCameraMovesPlayer(arg0) != 0) {
            m_unkCA = 1;
        }
        CallAllOnStopAttack__19EntityAttackManagerFv((void *)(gEng + 0x3250));
        ReleaseHeadCamera__6PlayerFv(*(void **)(gEng + 0x82AC));
        m_unkCC = mbGlobalSleep__15EntityBaseClass;
        mbGlobalSleep__15EntityBaseClass = 0;
        *(short *)(gInterface + 0x1B24) = 0x1E;
        *(int *)(gInterface + 0x18D0) &= ~0xE;
    }
}

// DRAFT: 0x0017B0E0 GetFirstCutCamera__16CameraCutManagerFUi
// note: 66 differing lines; the element sits in $a0 where the original uses $v1, and the outer loop and exit layout differ. Tried do-while guard, while loop, nValue at function scope, direct returns on the match path, shared exit label; none dropped below 66.
void *CameraCutManager::GetFirstCutCamera(unsigned int arg0) {
    char *pNode;
    char *pElem;
    char *pNext;
    char *pBest;
    unsigned int nMin;
    unsigned int nValue;

    m_unk7C = m_unk74;
    nMin = 0x270F;
    pNode = m_unk74 != 0 ? *(char **)m_unk74 : (char *)0;
    while (pNode != 0) {
        if (*(unsigned int *)pNode == arg0) {
            *(char **)(pNode + 0x10) = *(char **)(pNode + 8);
            pElem = *(char **)(pNode + 8) != 0 ? *(char **)(*(char **)(pNode + 8)) : (char *)0;
            if (pElem != 0) {
                do {
                    nValue = *(unsigned int *)(pElem + 0x50);
                    if (nValue < nMin) {
                        nMin = nValue;
                        pBest = pElem;
                    }
                    if (*(char **)(pNode + 0x10) != 0) {
                        pNext = *(char **)(*(char **)(pNode + 0x10) + 4);
                        if (pNext != 0) {
                            *(char **)(pNode + 0x10) = pNext;
                            pElem = *(char **)pNext;
                        } else {
                            pElem = (char *)0;
                        }
                    } else {
                        *(char **)(pNode + 0x10) = *(char **)(pNode + 8);
                        pElem = *(char **)(pNode + 8) != 0 ? *(char **)(*(char **)(pNode + 8)) : (char *)0;
                    }
                } while (pElem != 0);
            }
            return pBest;
        }
        if (m_unk7C == 0) {
            m_unk7C = m_unk74;
            pNode = m_unk74 != 0 ? *(char **)m_unk74 : (char *)0;
        } else {
            pNext = *(char **)(m_unk7C + 4);
            if (pNext != 0) {
                m_unk7C = pNext;
                pNode = *(char **)m_unk7C;
            } else {
                pNode = (char *)0;
            }
        }
    }
    return 0;
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

// FUNCTION: 0x0017BDD0 SetupCutCamera_Pan__16CameraCutManagerFUiUiff5PVec35PVec35PVec35PVec3UiUiUiUib5PVec3bUi
void CameraCutManager::SetupCutCamera_Pan(unsigned int arg0, unsigned int arg1, float fA, float fB, PVec3 v4, PVec3 v5, PVec3 v6, PVec3 v7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool b12, PVec3 v13, bool b14, unsigned int arg15) {
    CutSceneCamera_Generic *pCutCamera;
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    pCutCamera = (CutSceneCamera_Generic *)__nw__FUi(0x100);
    if (pCutCamera == 0) {
        CdsAssert("CameraCutscene.cpp", 0x143, "pCutCamera");
    }
    sceVu0CopyVector(pCutCamera->m_unk60, v4.m_v);
    sceVu0CopyVector(pCutCamera->m_unk70, v5.m_v);
    sceVu0CopyVector(pCutCamera->m_unk80, v6.m_v);
    sceVu0CopyVector(pCutCamera->m_unk90, v7.m_v);
    pCutCamera->m_unk0 = fB;
    pCutCamera->m_unk8 = 0;
    pCutCamera->m_unk10 = 3;
    pCutCamera->m_unk14 = arg0;
    pCutCamera->m_unk4 = 60.0f * fA;
    pCutCamera->m_unk28 = b14;
    pCutCamera->m_unk18 = arg8;
    pCutCamera->m_unk1C = arg9;
    pCutCamera->m_unk20 = arg10;
    pCutCamera->m_unk24 = arg11;
    pCutCamera->m_unk40 = arg15;
    pCutCamera->m_unk50 = arg1;
    pCutCamera->m_unk29 = b12;
    sceVu0CopyVector(pCutCamera->m_unk30, v13.m_v);
    AddCutSceneCamera(pCutCamera, arg0);
    *(int *)(MemMgr + 0x18) = saved;
}

// FUNCTION: 0x0017BF60 SetupCutCamera_MoveTo__16CameraCutManagerFUiUiffUi5PVec35PVec35PVec3UiUiUiUib5PVec3bUi
void CameraCutManager::SetupCutCamera_MoveTo(unsigned int arg0, unsigned int arg1, float fA, float fB, unsigned int arg4, PVec3 v5, PVec3 v6, PVec3 v7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool b12, PVec3 v13, bool b14, unsigned int arg15) {
    CutSceneCamera_Generic *pCutCamera;
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    pCutCamera = (CutSceneCamera_Generic *)__nw__FUi(0xB0);
    if (pCutCamera == 0) {
        CdsAssert("CameraCutscene.cpp", 0x10D, "pCutCamera");
    }
    pCutCamera->m_unk4 = fA;
    sceVu0CopyVector(pCutCamera->m_unk60, v5.m_v);
    sceVu0CopyVector(pCutCamera->m_unk70, v6.m_v);
    sceVu0CopyVector(pCutCamera->m_unk80, v7.m_v);
    pCutCamera->m_unk10 = 2;
    pCutCamera->m_unk8 = 0;
    pCutCamera->m_unkC = arg4;
    pCutCamera->m_unk0 = fB;
    pCutCamera->m_unk14 = arg0;
    pCutCamera->m_unk4 = 60.0f * fA;
    pCutCamera->m_unk28 = b14;
    pCutCamera->m_unk18 = arg8;
    pCutCamera->m_unk1C = arg9;
    pCutCamera->m_unk20 = arg10;
    pCutCamera->m_unk24 = arg11;
    pCutCamera->m_unk40 = arg15;
    pCutCamera->m_unk50 = arg1;
    pCutCamera->m_unk29 = b12;
    sceVu0CopyVector(pCutCamera->m_unk30, v13.m_v);
    AddCutSceneCamera(pCutCamera, arg0);
    *(int *)(MemMgr + 0x18) = saved;
}

// FUNCTION: 0x0017C0F0 SetupCutCamera_Fixed__16CameraCutManagerFUiUiffUi5PVec35PVec3UiUiUiUib5PVec3bUi
void CameraCutManager::SetupCutCamera_Fixed(unsigned int arg0, unsigned int arg1, float fA, float fB, unsigned int arg4, PVec3 v5, PVec3 v6, unsigned int arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, bool b11, PVec3 v12, bool b13, unsigned int arg14) {
    CutSceneCamera_Generic *pCutCamera;
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    pCutCamera = (CutSceneCamera_Generic *)__nw__FUi(0x80);
    if (pCutCamera == 0) {
        CdsAssert("CameraCutscene.cpp", 0xD8, "pCutCamera");
    }
    pCutCamera->m_unk0 = fB;
    pCutCamera->m_unk4 = fA;
    sceVu0CopyVector(pCutCamera->m_unk60, v5.m_v);
    sceVu0CopyVector(pCutCamera->m_unk70, v6.m_v);
    pCutCamera->m_unk10 = 1;
    pCutCamera->m_unk8 = 0;
    pCutCamera->m_unkC = arg4;
    pCutCamera->m_unk14 = arg0;
    pCutCamera->m_unk4 = 60.0f * fA;
    pCutCamera->m_unk28 = b13;
    pCutCamera->m_unk18 = arg7;
    pCutCamera->m_unk1C = arg8;
    pCutCamera->m_unk20 = arg9;
    pCutCamera->m_unk24 = arg10;
    pCutCamera->m_unk40 = arg14;
    pCutCamera->m_unk50 = arg1;
    pCutCamera->m_unk29 = b11;
    sceVu0CopyVector(pCutCamera->m_unk30, v12.m_v);
    AddCutSceneCamera(pCutCamera, arg0);
    *(int *)(MemMgr + 0x18) = saved;
}

// DRAFT: 0x0017C260 CleanUpCutCameras__16CameraCutManagerFv
// note: DIFF 70 words; entry exit 6 insns short, inner-loop nops at 0x60/0x64 and join nop at 0xC4 missing, RemoveAll arg hoisted into beqz delay. Tried: outer top-tested (81), inner top-tested (73), flat cursor else (70).
void CameraCutManager::CleanUpCutCameras() {
    char *pNode;
    char *pItem;
    char *pNext;
    if (*(int *)m_unk70 != 0) {
        m_unk7C = m_unk74;
        pNode = 0;
        if (m_unk74 != 0) {
            pNode = *(char **)m_unk74;
        }
        if (pNode != 0) {
            do {
                *(char **)(pNode + 0x10) = *(char **)(pNode + 8);
                pItem = 0;
                if (*(char **)(pNode + 8) != 0) {
                    pItem = *(char **)(*(char **)(pNode + 8));
                }
                if (pItem != 0) {
                    do {
                        FreeUpCameraStructure((CutSceneCamera_Generic *)pItem);
                        if (*(char **)(pNode + 0x10) == 0) {
                            *(char **)(pNode + 0x10) = *(char **)(pNode + 8);
                            pItem = 0;
                            if (*(char **)(pNode + 8) != 0) {
                                pItem = *(char **)(*(char **)(pNode + 8));
                            }
                        } else {
                            pNext = *(char **)(*(char **)(pNode + 0x10) + 4);
                            if (pNext != 0) {
                                *(char **)(pNode + 0x10) = pNext;
                                pItem = *(char **)(*(char **)(pNode + 0x10));
                            } else {
                                pItem = 0;
                            }
                        }
                    } while (pItem != 0);
                }
                RemoveAll__5PListFv(pNode + 4);
                if (pNode != 0) {
                    __dt__5PListFv(pNode + 4, -1);
                    __dl__FPv(pNode);
                }
                RemoveCurrent__5PListFv(m_unk70);
                if (m_unk7C != 0) {
                    pNext = *(char **)(m_unk7C + 4);
                    if (pNext != 0) {
                        m_unk7C = pNext;
                        pNode = *(char **)m_unk7C;
                    } else {
                        pNode = 0;
                    }
                } else {
                    m_unk7C = m_unk74;
                    pNode = 0;
                    if (m_unk74 != 0) {
                        pNode = *(char **)m_unk74;
                    }
                }
            } while (pNode != 0);
        }
    }
    m_unk85 = 0;
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

// FUNCTION: 0x0017C630 Update__16CameraCutManagerFv
int CameraCutManager::Update() {
    if (ProcessCutCameras() != 0) {
        float a[4];
        float b[4];
        *(PVec3 *)a = *(PVec3 *)m_unk50;
        *(PVec3 *)b = *(PVec3 *)m_unk60;
        UpdatePos__6CameraF5PVec35PVec3(m_unk0, a, b);
        CheckCameraShake__6CameraFR5PVec3R5PVec3b(m_unk0, m_unk50, m_unk60, false);
        float c[4];
        float d[4];
        *(PVec3 *)c = *(PVec3 *)m_unk50;
        *(PVec3 *)d = *(PVec3 *)m_unk60;
        float mat[16];
        CreateViewMatrix__6CameraFR5PMat45PVec35PVec3(m_unk0, m_unk10, c, d);
        sceVu0CopyMatrix((float (*)[4])mat, (float (*)[4])m_unk10);
        SetViewMatrix__6CameraF5PMat4(m_unk0, mat);
        return 1;
    }
    return 0;
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
