#include "types.h"
#include "ExitLevel.h"
#include "Debug.h"
#include "Font.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern unsigned char __vt__9ExitLevel[];
extern unsigned char gInterface[];
extern Debug gDebug;
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern void *mpEntMgr__15EntityBaseClass;
extern PArray mTempArray__15EntityBaseClass;
extern unsigned char gEng[0x19B90];
extern unsigned char gSound[0x100];
extern int miSpawnLevel__12LiftOperator;
extern float GAME_FPS;
extern unsigned char jtbl_0026A860[0x10];
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *pThis, unsigned int nId);
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(void *pThis, int nLoadClass, PArray *pArr, float (*pPos)[4], float fRadius, int nFlag, bool bA, bool bB);
extern "C" int Ready2Clear__6PlayerFv(void *pThis);
extern "C" void Kill__6PlayerFv(void *pThis);
extern "C" int PlaySoundUbiquitous__6PSoundFUi(void *pThis, unsigned int nSound);
extern "C" int TriggerSystemSound__6PSoundFUiUiP6PMNode(void *pThis, unsigned int nA, unsigned int nB, void *pNode);
extern "C" void *FindAnimNode__6PMNodeFUi(void *pThis, unsigned int uID);
extern "C" int RecurseApplyAnimLoopByID__6PMNodeFUisib(void *pThis, unsigned int uID, short sA, int nB, bool bC);
extern "C" int StartCutScene__10MaximoMainFi(void *pThis, int nScene);
extern "C" void SetLevelClear__10MaximoMainFv(void *pThis);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);

// FUNCTION: 0x001C4C60 __dt__9ExitLevelFv
extern "C" ExitLevel *__dt__9ExitLevelFv(ExitLevel *pThis, short nFlag)
{
    if (pThis != 0) {
        pThis->m_unk0 = __vt__9ExitLevel;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001C4CD0 OutputDebug__9ExitLevelFv
void ExitLevel::OutputDebug()
{
    char buf[0x20];

    sprintf(buf, "Time : %d, Level %d\n", m_unk1D4, m_unk1D8);
    gDebug.DebugDisp(buf);
}

void DisplayTime0(int nTime, float fTime);

// DRAFT: 0x001C4D20 Execute__9ExitLevelFv
// note: 373 words; size 0x79c vs 0x7dc (missing block), epilogue delay slot (ld ra vs nop), jump-table lui/addiu placeholders, frame layout, branches at 0x140/0x164/0x190, SetState reloc at 0x7b4; tried ternary assert, FLAGS readonly, colour ternary, if/else pSrc, case order 3 then 0 (kept), default break (375, worse)
void ExitLevel::Execute()
{
    char buf[0x20];
    float vDiff[4];
    char *pPlayer;
    char *pSrc;
    char *pApp;
    char *pEntry;
    char *pv;
    FontManager *pFont;
    void *pNode;
    unsigned int nId;
    int t;
    int nTime;
    int nLevel;
    float fRadius;
    float fTemp;

    switch (m_unk20) {
    case -1:
        SetState__15EntityBaseClassFi(this, 0);
        EnableSleep__15EntityBaseClassFbb(this, false, false);
        ((m_unk1B8 < 4) ? (void)0 : CdsAssert__FPciPc("ExitLevel.cpp", 0x2F, "mEVars.miExitType < EXIT_MAX"));
        m_unk1C0 = m_unk190;
        m_unk1B4 = 0;
        m_unk1D4 = 0;
        m_unk1E0 = 0.0f;
        m_unk1DC = (m_unk1B8 == 2) ? 0xF0 : 0;
        return;
    case 0:
        fRadius = m_unk1B0;
        switch (m_unk1B8) {
        case 3:
        case 0:
            pPlayer = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
            pv = *(char **)(pPlayer + 0x3C);
            if (pv != 0) {
                pSrc = pv + 0x80;
            } else {
                pSrc = pPlayer + 0x190;
            }
            sceVu0SubVector(vDiff, (float *)pSrc, (float *)&m_unk1C0);
            if (sceVu0InnerProduct(vDiff, vDiff) <= fRadius * fRadius) {
                SetState__15EntityBaseClassFi(pPlayer, 2);
                m_unk1D0 = 0;
                SetState__15EntityBaseClassFi(this, 3);
                return;
            }
            return;
        case 1:
            if (GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, 0, (float (*)[4])&m_unk190, fRadius, 0, false, false) == 0) {
                if (mTempArray__15EntityBaseClass.m_unk8 != 0) {
                    mTempArray__15EntityBaseClass.m_unk0 = 0;
                    mTempArray__15EntityBaseClass.m_unk4 = 0;
                }
                if (GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 6, &mTempArray__15EntityBaseClass, (float (*)[4])&m_unk190, fRadius, 0, false, false) != 0) {
                    mTempArray__15EntityBaseClass.m_unk4 = 0;
                    nId = 0;
                    if (mTempArray__15EntityBaseClass.m_unk0 != 0) {
                        nId = (unsigned int)mTempArray__15EntityBaseClass.m_unk8[0];
                    }
                    if (nId != 0) {
loop_26:
                        pApp = (char *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, nId);
                        if ((pApp == 0) || (*(int *)(pApp + 0x20) == 9)) {
                            t = mTempArray__15EntityBaseClass.m_unk4 + 1;
                            mTempArray__15EntityBaseClass.m_unk4 = t;
                            nId = 0;
                            if ((unsigned int)t < mTempArray__15EntityBaseClass.m_unk0) {
                                nId = (unsigned int)mTempArray__15EntityBaseClass.m_unk8[mTempArray__15EntityBaseClass.m_unk4];
                            }
                            if (nId == 0) {
                                goto block_32;
                            }
                            goto loop_26;
                        }
                    } else {
                        goto block_32;
                    }
                } else {
block_32:
                    m_unk1D0 = (int)GAME_FPS * 3;
                    SetState__15EntityBaseClassFi(this, 4);
                    return;
                }
            }
            break;
        case 2:
            if (mTempArray__15EntityBaseClass.m_unk8 != 0) {
                mTempArray__15EntityBaseClass.m_unk0 = 0;
                mTempArray__15EntityBaseClass.m_unk4 = 0;
            }
            if (GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 5, &mTempArray__15EntityBaseClass, (float (*)[4])&m_unk190, fRadius, 0x1E, false, false) != 0) {
                mTempArray__15EntityBaseClass.m_unk4 = 0;
                nId = 0;
                if (mTempArray__15EntityBaseClass.m_unk0 != 0) {
                    nId = (unsigned int)mTempArray__15EntityBaseClass.m_unk8[0];
                }
                if (nId != 0) {
                    do {
                        pApp = (char *)ApparitionIsValid__15EntityBaseClassFUi(nId);
                        if (pApp != 0) {
                            t = *(int *)(pApp + 8);
                            if ((t == 0x1E) && (((int (*)(void *))(*(void ***)pApp)[13])(pApp) <= 0)) {
                                mTempArray__15EntityBaseClass.RemoveCurrent();
                            }
                        }
                        t = mTempArray__15EntityBaseClass.m_unk4 + 1;
                        mTempArray__15EntityBaseClass.m_unk4 = t;
                        nId = 0;
                        if ((unsigned int)t < mTempArray__15EntityBaseClass.m_unk0) {
                            nId = (unsigned int)mTempArray__15EntityBaseClass.m_unk8[mTempArray__15EntityBaseClass.m_unk4];
                        }
                    } while (nId != 0);
                }
                if (mTempArray__15EntityBaseClass.m_unk0 != 0) {
                    nTime = m_unk1D4;
                    if (nTime < 0x4650) {
                        m_unk1D4 = nTime + 1;
                    }
                    m_unk1D8 = 7 - ((m_unk1D4 / 3000) + ((unsigned int)m_unk1D4 >> 0x1F));
                    if ((int)mTempArray__15EntityBaseClass.m_unk0 < m_unk1D8) {
                        m_unk1D8 = (int)mTempArray__15EntityBaseClass.m_unk0;
                    }
                    miSpawnLevel__12LiftOperator = m_unk1D8;
                    if (m_unk1DC >= 0) {
                        pFont = (FontManager *)(gInterface + 0x80);
                        pFont->RemoveText((unsigned short)1);
                        fTemp = m_unk1E0 - *(float *)(gEng + 0x1E8);
                        m_unk1E0 = fTemp;
                        nLevel = m_unk1DC;
                        if (fTemp <= 0.0f) {
                            t = nLevel - 1;
                            m_unk1DC = t;
                            if (t < 0) {
                                pPlayer = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
                                nLevel = 0;
                                if (*(int *)(pPlayer + 0x20) == 0) {
                                    Kill__6PlayerFv(pPlayer);
                                }
                            } else {
                                nLevel -= 1;
                            }
                            if (m_unk1DC < 0xA) {
                                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x336);
                            }
                            m_unk1E0 = 60.0f;
                        }
                        pEntry = (char *)(pFont->m_unk100 + 0x420);
                        sprintf(buf, *(char **)pEntry, nLevel / 60, nLevel % 60);
                        pNode = pFont->DisplayString(buf, (float)*(short *)(pEntry + 4), -210.0f,
                                                     *(signed char *)(pEntry + 8),
                                                     (m_unk1DC < 0x3C) ? FONTCOLOR_1 : FONTCOLOR_0, FONTALIGN_0);
                        ((FontNode *)pNode)->m_unk6 = 1;
                        return;
                    }
                } else {
                    goto block_67;
                }
            } else {
block_67:
                miSpawnLevel__12LiftOperator = 0;
                if (GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, 0, (float (*)[4])&m_unk190, fRadius, 0, false, false) != 0) {
                    DisplayTime0(m_unk1DC, m_unk1E0);
                    return;
                }
                m_unk1D0 = (int)GAME_FPS * 5;
                SetState__15EntityBaseClassFi(this, 3);
                return;
            }
            break;
        default:
            return;
        }
        break;
    case 4:
        t = m_unk1D0 - 1;
        m_unk1D0 = t;
        if (t == 0) {
            SetState__15EntityBaseClassFi(this, 1);
            return;
        }
        break;
    case 3:
        if (m_unk1B8 == 2) {
            DisplayTime0(m_unk1DC, m_unk1E0);
        }
        t = m_unk1D0;
        if (t != 0) {
            m_unk1D0 = t - 1;
            return;
        }
        pPlayer = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
        if (Ready2Clear__6PlayerFv(pPlayer) != 0) {
            SetState__15EntityBaseClassFi(pPlayer, 2);
            SetState__15EntityBaseClassFi(this, 1);
            return;
        }
        break;
    case 1:
        pPlayer = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
        if (((int (*)(void *, void *))(*(void ***)pPlayer)[13])(pPlayer, jtbl_0026A860) <= 0) {
            SetState__15EntityBaseClassFi(this, 5);
            return;
        }
        pFont = (FontManager *)(gInterface + 0x80);
        pFont->RemoveAll(true);
        t = m_unk1BC;
        if (t >= 0) {
            if (m_unk1B8 == 3) {
                pNode = FindAnimNode__6PMNodeFUi(*(void **)gEng, 0x1F3);
                if (pNode != 0) {
                    TriggerSystemSound__6PSoundFUiUiP6PMNode(gSound, 0x1F3, *(unsigned int *)((char *)pNode + 0xE8), pNode);
                    RecurseApplyAnimLoopByID__6PMNodeFUisib(*(void **)gEng, 0x1F3, 0, 1, false);
                }
            }
            StartCutScene__10MaximoMainFi(gEng, t);
            SetState__15EntityBaseClassFi(this, 2);
            return;
        }
        /* fall through */
    case 2:
        SetLevelClear__10MaximoMainFv(gEng);
        SetState__15EntityBaseClassFi(this, 5);
        break;
    }
}

// FUNCTION: 0x001C5500 DisplayTime0__Fif
void DisplayTime0(int nTime, float fTime)
{
    char buf[0x40];
    FontManager *pFont = (FontManager *)(gInterface + 0x80);
    char *pEntry;

    pFont->RemoveText((unsigned short)1);
    pEntry = (char *)(pFont->m_unk100 + 0x420);
    if (nTime < 0) {
        fTime = 0.0f;
        nTime = 0;
    }
    sprintf(buf, *(char **)pEntry, nTime / 60, nTime % 60, (int)(100.0f * fTime / 60.0f));
    FontNode *pNode = pFont->DisplayString(buf, (float)*(short *)(pEntry + 4), -210.0f,
                                           *(signed char *)(pEntry + 8),
                                           (nTime < 60) ? FONTCOLOR_1 : FONTCOLOR_0, FONTALIGN_0);
    pNode->m_unk6 = 1;
}

// FUNCTION: 0x001C5610 __ct__9ExitLevelFv
extern "C" ExitLevel *__ct__9ExitLevelFv(ExitLevel *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 5, 0);
    pThis->m_unk0 = __vt__9ExitLevel;
    return pThis;
}
