#ifndef EXITLEVEL_H
#define EXITLEVEL_H

#include "types.h"

// ExitLevel embeds an EntityBaseClass at offset 0; the base is not declared as a
// C++ base here, so the constructor and destructor call its methods explicitly.
class EntityBaseClass;

class ExitLevel {
public:
    void OutputDebug();

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x1D4 - 0x04];
    int m_unk1D4;               // 0x1D4 level number, printed by OutputDebug
    int m_unk1D8;               // 0x1D8 time value, printed by OutputDebug
};

#endif
