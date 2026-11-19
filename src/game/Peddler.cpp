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
