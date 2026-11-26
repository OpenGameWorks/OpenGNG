#ifndef IOP_TRAN_H
#define IOP_TRAN_H

#include "types.h"

// One IOP transaction slot, 0x28 bytes. IOP_TranSet fills 0x00..0x14 and 0x24; the manager tracks state at 0x18 and a value at 0x20.
class IOP_Tran {
public:
    IOP_Tran();
    void InitMembers();
    void IOP_TranSet(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3,
                     unsigned int a4, unsigned int a5, unsigned int a6);
    int m_unk0;                     // 0x00 id
    int m_unk4;                     // 0x04
    int m_unk8;                     // 0x08
    int m_unkC;                     // 0x0C
    int m_unk10;                    // 0x10
    int m_unk14;                    // 0x14
    int m_unk18;                    // 0x18 state
    int m_unk1C;                    // 0x1C
    int m_unk20;                    // 0x20 value
    int m_unk24;                    // 0x24
};

#endif
