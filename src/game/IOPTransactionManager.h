#ifndef IOPTRANSACTIONMANAGER_H
#define IOPTRANSACTIONMANAGER_H

#include "types.h"

// One IOP transaction slot. Id at +0, state at +0x18, value at +0x20.
class IOP_Tran {
public:
    int m_unk0;
    int m_unk4;
    int m_unk8;
    int m_unkC;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
};

// Size 0xC8 (gIOPTransactionManager, 200 bytes).
class IOPTransactionManager {
public:
    int InitMembers();
    int FrameMaintenacePartA();
    int FrameMaintenacePartB();
    int TranAdd(const IOP_Tran *pTran);

    int m_unk0;
    int m_unk4;
    IOP_Tran m_unk8[4];
    char m_unkA8[0x10];
    char m_unkB8[0x10];
};

#endif
