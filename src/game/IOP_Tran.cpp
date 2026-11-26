#include "types.h"
#include "IOP_Tran.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nBytes);

// FUNCTION: 0x001DA9C0 IOP_TranSet__8IOP_TranFUiUiUiUiUiUiUi
void IOP_Tran::IOP_TranSet(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3,
                           unsigned int a4, unsigned int a5, unsigned int a6)
{
    InitMembers();
    m_unk0 = a0;
    m_unk4 = a1;
    m_unk8 = a2;
    m_unkC = a3;
    m_unk10 = a4;
    m_unk14 = a5;
    m_unk24 = a6;
}

// FUNCTION: 0x001DAA60 IOP_TranReset__8IOP_TranFv
void IOP_Tran::IOP_TranReset() {
    InitMembers();
}

// FUNCTION: 0x001DAA70 InitMembers__8IOP_TranFv
void IOP_Tran::InitMembers()
{
    memset(this, 0, sizeof(IOP_Tran));
}

// FUNCTION: 0x001DAA80 __ct__8IOP_TranFv
IOP_Tran::IOP_Tran()
{
    InitMembers();
}
