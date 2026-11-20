#include "types.h"
#include "ExitLevel.h"
#include "Debug.h"
#include "Font.h"

// TODO(header): foreign declarations
extern unsigned char __vt__9ExitLevel[];
extern unsigned char gInterface[];
extern Debug gDebug;
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);

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
