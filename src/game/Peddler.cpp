#include "Peddler.h"

// TODO(header): foreign declarations
class EntityBaseClass;
// The second argument is not set by the caller; the original passes a1 through unchanged.
extern "C" int InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);

class Debug {
public:
    void DebugDisp(char *pText);

    // Debug size is unknown; the placeholder keeps gDebug out of small data (threshold 8 bytes).
    char _pad000[0x10];
};
extern Debug gDebug;

extern "C" int sprintf(char *pDst, const char *pFmt, ...);

struct ItemEntry {
    char _pad000[4];
    int m_unk4;                     // 0x04
    char _pad008[0x14 - 0x08];
};
extern ItemEntry ItemTable[0x3C];

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" void Remove__6PArrayFPv(void *pThis, void *pItem);
extern "C" void AddMeshLayer__9InterfaceFP6PMNode(void *pThis, PMNode *pNode);
extern "C" void DeleteMeshLayer__9InterfaceFP6PMNode(void *pThis, PMNode *pNode);
extern unsigned char gInterface[];

// Engine size is unknown; the placeholder keeps gEng out of small data (threshold 8 bytes).
class Engine {
public:
    char _pad000[0x1E8];
    float m_unk1E8;                 // 0x1E8
    char _pad1EC[0x10];
};
extern Engine gEng;

class PArray;
class EntityManagerState {
public:
    char _pad000[0x229];
    signed char m_unk229;           // 0x229 compared against 4
};
class EntityManager {
public:
    char _pad000[0x505C];
    EntityManagerState *m_unk505C;  // 0x505C
};
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(EntityManager *pThis, int eLoadClass, PArray *pArray, float (*pBox)[4], float fRadius, int nFlags, bool bFlagA, bool bFlagB);

struct tagWaypointGroup {
    char _pad000[4];
    unsigned int m_unk4;            // 0x04 waypoint count
};
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void Add2DependencyList__13EntityManagerFUiUi(EntityManager *pThis, unsigned int nFrom, unsigned int nTo);
extern unsigned char __vt__7Peddler[];
extern "C" void *__dt__15EntityBaseClassFv(EntityBaseClass *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);

// Entity instance as seen through its vtable. Only slots 0x30 (void, one int) and 0x44 (int) are called here; the other slots are placeholders that keep those two at their offsets.
class EntityInstance {
public:
    virtual void Slot08() {}
    virtual void Slot0C() {}
    virtual void Slot10() {}
    virtual void Slot14() {}
    virtual void Slot18() {}
    virtual void Slot1C() {}
    virtual void Slot20() {}
    virtual void Slot24() {}
    virtual void Slot28() {}
    virtual void Slot2C() {}
    virtual void SetSlot30(int nArg) {}
    virtual void Slot34() {}
    virtual void Slot38() {}
    virtual void Slot3C() {}
    virtual void Slot40() {}
    virtual int Slot44() { return 0; }

    unsigned int m_unk4;            // 0x04
    char _pad008[0x1A - 0x08];
    unsigned char m_unk1A;          // 0x1A
};

// FUNCTION: 0x001D0530 EnemiesInCheckRadius__7PeddlerFv
int Peddler::EnemiesInCheckRadius() {
    int result;

    if (mpEntMgr__15EntityBaseClass->m_unk505C->m_unk229 == 4 || ActivatedEnemiesDead() == 0) {
        result = 1;
    } else {
        float box[4];

        box[0] = m_unk1E4;
        box[1] = m_unk1E8;
        box[2] = m_unk1EC;
        box[3] = m_unk1F0;
        result = GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, 0, &box, box[3], -2, false, true);
    }
    return result;
}

// FUNCTION: 0x001D05D0 TrappedEntityRemoved__7PeddlerFv
bool Peddler::TrappedEntityRemoved() {
    return !InstanceIsValid__15EntityBaseClassFUi(m_unk200);
}

// DRAFT: 0x001D0600 ActivatedEnemiesDead__7PeddlerFv
// note: 47 diff lines; original frame 0x50 keeps a slot pointer in s3 (saves ra+s0..s3), ours frame 0x40 with s0..s2 only. Tried: index loop (47), pointer+counter loop (48), slot-address local (47), unsigned counter (47).
int Peddler::ActivatedEnemiesDead() {
    int i;

    if (m_unk294 == 0) {
        return 1;
    }
    if (m_unk2A6 == 0) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (m_unk2C8[i] != 0) {
            void *pInst = (void *)InstanceIsValid__15EntityBaseClassFUi(m_unk2C8[i]);
            if (pInst != 0) {
                int (*pfn)(void *) = *(int (**)(void *))((char *)*(void **)pInst + 0x34);
                if (pfn(pInst) > 0) {
                    return 0;
                }
            }
            m_unk2C8[i] = 0;
        }
    }
    return 1;
}

// FUNCTION: 0x001D06C0 OutputDebug__7PeddlerFv
void Peddler::OutputDebug() {
    char buf[0x100];

    sprintf(buf, "State = %d\n", m_unk20);
    gDebug.DebugDisp(buf);
    sprintf(buf, "Wp id = %d\n", m_unk288);
    gDebug.DebugDisp(buf);
}

// DRAFT: 0x001D0730 ActivateAttackingEnemies__7PeddlerFv
// note: 16 diff lines; loop tail and epilogue shifted (original tail ordering around the nop at 0x9C differs). Tried: index loop, do-while, declaration reorder, EntityInstance virtual class (t9 call fixed), slot-offset placeholders (0x30/0x44 fixed), tail reorder (19 to 16).
void Peddler::ActivateAttackingEnemies() {
    EntityBaseClass **ppSlot;
    int i;
    EntityBaseClass *pEnt;
    EntityInstance *pInst;
    unsigned int nOff;

    ppSlot = m_unk1F4;
    nOff = 0;
    i = 0;
    do {
        pEnt = *ppSlot;
        if (pEnt != 0) {
            pInst = (EntityInstance *)InstanceIsValid__15EntityBaseClassFUi(pEnt);
            if (pInst != 0) {
                if (pInst->Slot44() == 0) {
                    pInst->m_unk1A = 1;
                }
                pInst->SetSlot30(m_unkC);
                *(EntityBaseClass **)((char *)this + nOff + 0x2C8) = pEnt;
                Add2DependencyList__13EntityManagerFUiUi(mpEntMgr__15EntityBaseClass, pInst->m_unk4, m_unk4);
            }
        }
        i++;
        ppSlot++;
        nOff += 4;
    } while (i < 3);
    m_unk2A6 = 1;
}

// FUNCTION: 0x001D0810 GetNextPosition__7PeddlerFRA4_f
int Peddler::GetNextPosition(float (&afPos)[4]) {
    tagWaypointGroup *pGroup;
    unsigned char bFlag;
    float *pWaypoint;

    pGroup = m_unk284;
    if (pGroup != 0) {
        if (m_unk288 < pGroup->m_unk4) {
            pWaypoint = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, pGroup, m_unk288, bFlag);
            afPos[0] = pWaypoint[0];
            afPos[1] = pWaypoint[1];
            afPos[2] = pWaypoint[2];
            m_unk288++;
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x001D0C80 EnableDisplay__12PeddlerItemsFb
void PeddlerItems::EnableDisplay(bool bEnable) {
    if (m_unk0 == 0) {
        CdsAssert("Peddler.cpp", 0x6B9, "m_pRotateNode");
    }
    if (bEnable) {
        if (Find__6PArrayFPv(gInterface + 0x404, m_unk0) < 0) {
            AddMeshLayer__9InterfaceFP6PMNode(gInterface, m_unk0);
        }
    } else {
        Remove__6PArrayFPv(gInterface + 0x404, m_unk0);
    }
}

// DRAFT: 0x001D0E10 AnimateFloat__12PeddlerItemsFRfff
// note: 33 diff lines; original keeps fDelta in f13 (fStep's register) and uses addiu flags, the -1.0f negate is mul.s with f0 as first operand, and the branch layout differs. Tried: int/unsigned char/bool flags (33 each), operand swap (33), fDelta declared first (33).
int PeddlerItems::AnimateFloat(float &fVal, float fTarget, float fStep) {
    float fDelta;
    bool bUp;
    bool bDone;

    bUp = 1;
    fDelta = fStep * gEng.m_unk1E8;
    if (!(fVal < fTarget)) {
        bUp = 0;
    }
    if (bUp == 0) {
        fDelta *= -1.0f;
    }
    fVal += fDelta;
    bDone = 1;
    if (bUp != 0) {
        if (fVal <= fTarget) {
            bDone = 0;
        }
    } else {
        if (!(fVal < fTarget)) {
            bDone = 0;
        }
    }
    if (bDone != 0) {
        fVal = fTarget;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001D12F0 __dt__12PeddlerItemsFv
PeddlerItems::~PeddlerItems() {
    if (m_unk0 != 0) {
        DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, m_unk0);
        m_unk0 = 0;
        m_unk4 = 0;
    }
}

// DRAFT: 0x001D18A0 HideItems__7PeddlerFv
// note: 6 diff lines; this and slot pointer swap s3/s4 (orig this=s4, slot=s3). Tried 4 local orders (nOff/i/bAll/ppSlot 11, bAll/i/nOff/ppSlot 13, nOff-first 12, bAll-first 12); ppSlot-first best.
int Peddler::HideItems() {
    PeddlerItems **ppSlot;
    int bAll;
    int i;
    unsigned int nOff;

    nOff = 0;
    i = 0;
    bAll = 1;
    do {
        ppSlot = (PeddlerItems **)((char *)this + nOff + 0x218);
        if (*ppSlot != 0) {
            if ((*ppSlot)->m_unk4 == 0) {
                CdsAssert("Peddler.cpp", 0x58E, "m_pItems[iItem]->IsValid()");
            }
            bAll = bAll & (*ppSlot)->Hide() & 0xFF;
        }
        i++;
        nOff += 4;
    } while (i < 5);
    return bAll;
}

// FUNCTION: 0x001D1DB0 OnTimerEvent__7PeddlerFUi
void Peddler::OnTimerEvent(unsigned int arg0) {
    if (arg0 == (unsigned int)m_unk2C4) {
        m_unk29C = 1;
        return;
    }
    if (arg0 == (unsigned int)m_unk2BC) {
        m_unk2A7 = 1;
        return;
    }
    if (arg0 == (unsigned int)m_unk2D4) {
        m_unk2D8 = 1;
    }
}

// DRAFT: 0x001D1F90 FindItem__7PeddlerFi
// note: original has one extra nop after the increments (0x2C) before the loop test; 8 diff lines. Tried: index loop (large diff), p++ in body (10), while form (8), i++ in header with p++ in body (10).
unsigned int Peddler::FindItem(int arg0) {
    unsigned int i;
    ItemEntry *p;

    for (i = 0, p = ItemTable; i < 0x3C; i++, p++) {
        if (p->m_unk4 == arg0) {
            return i;
        }
    }
    return 0;
}

// DRAFT: 0x001D3870 __dt__7PeddlerFv
// note: 18 diff lines; register permutation of this/nFlag/slot (orig this=s4, nFlag=s3, slot=s2). Tried 3 local orders (nOff,ppSlot,i best; ppSlot-first 20, nOff-first alt 18).
extern "C" Peddler *__dt__7PeddlerFv(Peddler *pThis, short nFlag) {
    unsigned int nOff;
    PeddlerItems **ppSlot;
    int i;

    if (pThis != 0) {
        pThis->m_unk0 = __vt__7Peddler;
        i = 0;
        nOff = 0;
        do {
            ppSlot = (PeddlerItems **)((char *)pThis + nOff + 0x218);
            if (*ppSlot != 0) {
                if ((*ppSlot)->m_unk4 == 0) {
                    CdsAssert("Peddler.cpp", 0x17B, "m_pItems[i]->IsValid()");
                }
                delete *ppSlot;
                *ppSlot = 0;
            }
            i++;
            nOff += 4;
        } while (i < 5);
        __dt__15EntityBaseClassFv((EntityBaseClass *)pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001D3950 __ct__7PeddlerFv
// note: 36 diff lines; original spills this to 0x1C(sp) with frame 0x20 and reloads it per store, ours keeps this in s0 with a 0x10 frame. Tried: void* param, cast to EntityBaseClass*, volatile local pointer (41), flags -inline off (36), -O0 (38), -opt nolink (36).
Peddler::Peddler() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 6, 0);
    m_unk0 = __vt__7Peddler;
    m_unk24C = 0;
    m_unk248 = 0;
    m_unk22C = 0;
    m_unk284 = 0;
    m_unk244 = 1;
    m_unk2A5 = 1;
    m_unkD4 = 0;
    m_unk2B4 = 0;
    m_unk2A8 = 0;
    memset(m_unk218, 0, 0x14);
}

// FUNCTION: 0x001D39F0 GetItemID__FUi
unsigned int GetItemID(unsigned int arg0) {
    unsigned int i = 0;
    ItemEntry *p = ItemTable;

    do {
        if ((unsigned int)p->m_unk4 == arg0) {
            return i;
        }
        i++;
        p++;
    } while (i < 0x3C);
    return 0;
}
