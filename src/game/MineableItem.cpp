#include "types.h"
#include "MineableItem.h"

// TODO(header): foreign declarations
extern unsigned char __vt__12MineableItem[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nIndex, int nValue);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nIndex, char cType, unsigned int nData);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bFlag0, bool bFlag1);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);

// FUNCTION: 0x001B42E0 __dt__12MineableItemFv
extern "C" MineableItem *__dt__12MineableItemFv(MineableItem *pThis, short nFlag)
{
    if (pThis != 0) {
        pThis->m_unk0 = __vt__12MineableItem;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001B4360 SetEditableVars__12MineableItemFPc
void MineableItem::SetEditableVars(char *arg0)
{
    memcpy(&m_unk1B0, arg0, 0x10);
    CheckVariable__15EntityBaseClassFii(this, m_unk1B0, 1);
    m_unk10C |= 0x02000000;
    m_unk103 = 0xFF;
    if (m_unk1B8 != 0) {
        m_unk1BC = 0;
    }
}

// FUNCTION: 0x001B43D0 OnHitEvent__12MineableItemFP15EntityBaseClassiUiUi
int MineableItem::OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3)
{
    if (arg1 == 0) {
        return 0;
    }
    if (*((unsigned char *)arg0 + 0x10C) == 1) {
        if ((arg2 & ~0x5C0) == 2 || m_unk1C0 >= 3) {
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 2, 0);
            WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0);
            SetState__15EntityBaseClassFi(this, 3);
            EnableSleep__15EntityBaseClassFbb(this, 0, 0);
            m_unk10C &= 0xFDFFFFFF;
        } else {
            SetState__15EntityBaseClassFi(this, 1);
        }
        m_unk1C8 = arg2;
    }
    return 1;
}

// FUNCTION: 0x001B4A30 __ct__12MineableItemFv
extern "C" MineableItem *__ct__12MineableItemFv(MineableItem *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 2, 0);
    pThis->m_unk0 = __vt__12MineableItem;
    pThis->m_unk1C0 = 0;
    pThis->m_unk1C4 = 0;
    return pThis;
}
