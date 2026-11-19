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
extern unsigned char __vt__7Peddler[];

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

// FUNCTION: 0x001D06C0 OutputDebug__7PeddlerFv
void Peddler::OutputDebug() {
    char buf[0x100];

    sprintf(buf, "State = %d\n", m_unk20);
    gDebug.DebugDisp(buf);
    sprintf(buf, "Wp id = %d\n", m_unk288);
    gDebug.DebugDisp(buf);
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

// FUNCTION: 0x001D12F0 __dt__12PeddlerItemsFv
PeddlerItems::~PeddlerItems() {
    if (m_unk0 != 0) {
        DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, m_unk0);
        m_unk0 = 0;
        m_unk4 = 0;
    }
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
