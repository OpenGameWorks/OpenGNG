#ifndef ANIMTRIGGER_H
#define ANIMTRIGGER_H

#include "types.h"

// AnimTrigger derives from EntityBaseClass at offset 0; the base is not
// declared here, so members are named by their offset from the object start.
class AnimTrigger {
public:
    void Execute();
    const char *GetClassName();
    int NeedsToBeWoken();
    int GetWokenVarPos();
    void SetEditableVars(char *);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    int m_unk4;                 // 0x004 passed to the TriggerSystem constructor
    char _pad008[0x20 - 0x08];
    int m_unk20;                // 0x020 Execute runs only while this is -1
    char _pad024[0x3C - 0x24];
    void *m_unk3C;              // 0x03C optional object; +0x80 is used as a float[4] when set
    char _pad040[0x190 - 0x40];
    float m_unk190[4];          // 0x190 float[4] used when m_unk3C is null
    char _pad1A0[0x1B0 - 0x1A0];
    float m_unk1B0;             // 0x1B0 float argument to the TriggerSystem constructor
    unsigned int m_unk1B4;      // 0x1B4
    int m_unk1B8;               // 0x1B8 sign tested and truncated to short
    short m_unk1BC;             // 0x1BC
    char _pad1BE[0x1D0 - 0x1BE];
    int m_unk1D0;               // 0x1D0 copied into the TriggerSystem at +0xA when non-zero
    void *m_unk1D4;             // 0x1D4 tested for non-null
    unsigned int m_unk1D8;      // 0x1D8
    unsigned int m_unk1DC;      // 0x1DC
    unsigned int m_unk1E0;      // 0x1E0
    unsigned int m_unk1E4;      // 0x1E4
    unsigned int m_unk1E8;      // 0x1E8
    unsigned int m_unk1EC;      // 0x1EC
    unsigned int m_unk1F0;      // 0x1F0
    unsigned int m_unk1F4;      // 0x1F4
    unsigned int m_unk1F8;      // 0x1F8
    unsigned int m_unk1FC;      // 0x1FC
    int m_unk200;               // 0x200 tested for non-zero
    int m_unk204;               // 0x204 tested for non-zero
};

#endif
