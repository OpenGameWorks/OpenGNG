#include "types.h"
#include "CutableItem.h"
#include "EntityBaseClass.h"
#include "EntityManager.h"
#include "Physics.h"

// TODO(header): foreign declarations
// Placeholder for the object at CutableItem::m_unk3C. Only its vtable slot 0x1C
// (index 5, the sixth virtual after the dtor) and its byte at +0x3F are used.
class CutableItemState {
public:
    virtual ~CutableItemState();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Notify(int nZero, int nType, int nOffset);
    char _pad004[0x3F - 0x04];
    signed char m_unk3F;
};
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__11CutableItem[];
extern int mstuiShrubCount__11CutableItem;
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nA, int nB);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int printf(const char *pFmt, ...);
extern unsigned char ItemTable[0x24 * 0x3C];

// FUNCTION: 0x001BB100 __dt__11CutableItemFv
extern "C" CutableItem *__dt__11CutableItemFv(CutableItem *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->m_unk0 = __vt__11CutableItem;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001BB160 SetEditableVars__11CutableItemFPc
void CutableItem::SetEditableVars(char *pArg) {
    memcpy(&m_unk1B0, pArg, 0x10);
    CheckVariable__15EntityBaseClassFii(this, m_unk1B0, 0x12);
    if (*(int *)(ItemTable + m_unk1B0 * 36) == 0) {
        printf("CutableItem %d was removed\n", m_unk1B0);
        SetState__15EntityBaseClassFi(this, -2);
    }
}

// DRAFT: 0x001BB1E0 OnHitEvent__11CutableItemFP15EntityBaseClassiUiUi
// note: DIFF 76 words. Early nHit return epilogue offset, idx*36 computed after ItemTable base load, and type-1/mask return tails differ. Variants: switch on type (75, not kept), if-chain (76), positive mask chain (76), if/else tail (76), offset local (76), wrapped nHit body (76).
int CutableItem::OnHitEvent(EntityBaseClass *pArg, int nHit, unsigned int nFlagsA, unsigned int nFlagsB) {
    if (nHit != 0) {
    int nIndex = m_unk1B0;
    if (nIndex == 0 || nIndex == 0x10 || nIndex == 0x11) {
        if (pArg->m_unk08 == 0x2D && *(int *)((char *)pArg + 0x1B0) < 9) {
            return 0;
        }
    }
    int nOffset = nIndex * 36;
    int nType = *(int *)(ItemTable + nOffset + 0x1C);
    if (nType == 2) {
        unsigned int nMasked = nFlagsA & ~0x580;
        if (nMasked == 0x220 || nMasked == 0x201 || nMasked == 0x4F || nMasked == 0x44 || nMasked == 0x42 || nMasked == 3) {
            SetState__15EntityBaseClassFi(this, 3);
            return 1;
        }
        return 0;
    }
    if (nType == 1) {
        SetState__15EntityBaseClassFi(this, 3);
        if (nFlagsA & 0x800) {
            return 0;
        } else {
            return 1;
        }
    }
    if (nType == 0) {
        SetState__15EntityBaseClassFi(this, 3);
    }
    return 1;
    }
    return 0;
}

// FUNCTION: 0x001BB330 OnTouchEvent__11CutableItemFP15EntityBaseClass
void CutableItem::OnTouchEvent(EntityBaseClass *pArg) {
    int nIndex = m_unk1B0;
    int nType = *(signed char *)(ItemTable + nIndex * 36 + 0x20);
    switch (nType) {
    case 1:
        if (!(pArg->m_unkE8 & mpEntMgr__15EntityBaseClass->m_unk5058)) {
            Physics *pPhys = pArg->m_unk38;
            if (pPhys != 0 && ((*(unsigned short *)((char *)pPhys + 0x106)) & 4) && m_unk20 != 3) {
                SetState__15EntityBaseClassFi(this, 3);
            }
        }
        break;
    case 2: {
        CutableItemState *pObj = (CutableItemState *)m_unk3C;
        if ((signed char)(pObj->m_unk3F & 7) == 0) {
            Physics *pPhys = pArg->m_unk38;
            if (pPhys != 0 && (pPhys->m_unk108 & 0x49) == 0x41) {
                pObj->Notify(0, nType, nIndex * 36);
            }
        }
        break;
    }
    }
}

// FUNCTION: 0x001BBB10 GetClassName__11CutableItemFv
const char *CutableItem::GetClassName() {
    int nIndex = m_unk1B0;
    if ((unsigned int)nIndex < 0x12) {
        unsigned char *pBase = ItemTable + 0x10;
        const char *pName = *(const char **)(pBase + nIndex * 36);
        if (pName != 0) {
            return pName;
        }
    }
    return "CutableItem";
}

// FUNCTION: 0x001BBB60 __ct__11CutableItemFv
CutableItem::CutableItem() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 2, 2U);
    this->m_unk0 = __vt__11CutableItem;
    mstuiShrubCount__11CutableItem = 0;
}
