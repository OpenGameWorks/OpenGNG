#ifndef EXITLEVEL_H
#define EXITLEVEL_H

#include "types.h"

// ExitLevel embeds an EntityBaseClass at offset 0; the base is not declared as a
// C++ base here, so the constructor and destructor call its methods explicitly.
class EntityBaseClass;

class ExitLevel {
public:
    void OutputDebug();
    void Execute();
    const char *GetClassName();
    void SetEditableVars(char *);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                // 0x020 state, switched on by Execute
    char _pad024[0x190 - 0x24];
    u_long128 m_unk190;         // 0x190 saved copy of the 128-bit value at 0x1C0
    char _pad1A0[0x10];
    float m_unk1B0;             // 0x1B0 timer
    int m_unk1B4;               // 0x1B4 cutscene flag
    int m_unk1B8;               // 0x1B8 sub-state, switched on by Execute
    int m_unk1BC;               // 0x1BC
    u_long128 m_unk1C0;         // 0x1C0 working copy of the 128-bit value at 0x190
    int m_unk1D0;               // 0x1D0 countdown
    int m_unk1D4;               // 0x1D4 level number, printed by OutputDebug
    int m_unk1D8;               // 0x1D8 time value, printed by OutputDebug
    int m_unk1DC;               // 0x1DC display colour flag
    float m_unk1E0;             // 0x1E0 time value passed to DisplayTime0
};

#endif
