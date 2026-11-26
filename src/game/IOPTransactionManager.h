#ifndef IOPTRANSACTIONMANAGER_H
#define IOPTRANSACTIONMANAGER_H

#include "types.h"

#include "IOP_Tran.h"

// Size 0xC8 (gIOPTransactionManager, 200 bytes).
class IOPTransactionManager {
public:
    int InitMembers();
    int FrameMaintenacePartA();
    int FrameMaintenacePartB();
    int TranAdd(const IOP_Tran *pTran);
    int TranProcess(IOP_Tran *pTran, unsigned int nId);

    int m_unk0;
    int m_unk4;
    IOP_Tran m_unk8[4];
    char m_unkA8[0x10];
    char m_unkB8[0x10];
};

#endif
