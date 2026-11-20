// FLAGS: -str readonly
#include "types.h"
#include "IOPTransactionManager.h"

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("IOPTransactionManager.cpp", line, #cond))

// TODO(header): foreign declarations
extern "C" void __ct__8IOP_TranFv(IOP_Tran *pThis);
extern "C" void __dl__FPv(void *pBlock);
extern char gSndRecentTransaction_IOPImageArray[0x30];
extern "C" void SOUND_TranAcks(int nId, void *pBuf);
extern "C" void SOUND_TranCancels(int nId, void *pBuf);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void SOUND_TranAdd(int a0, int a1, int a2, int a3, int a4, int a5);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

// DRAFT: 0x001DA610 FrameMaintenacePartB__21IOPTransactionManagerFv
// note: 46 differing words; original keeps global base in a2 and uses i*5*8 index multiplies, ours uses running offsets; tried multiplied indices, running char pointers, running offsets with this base.
int IOPTransactionManager::FrameMaintenacePartB() {
    unsigned int i = 0;
    unsigned int offG = 0;
    unsigned int offO = 0;
    char *pThis = (char *)this;
    do {
        int id = *(int *)((char *)gSndRecentTransaction_IOPImageArray + offG);
        if (id != 0) {
            unsigned int j = 0;
            unsigned int offJ = 0;
            do {
                if (id == *(int *)(pThis + offJ + 0x8) && *(int *)(pThis + offO + 0x20) == 1) {
                    *(int *)(pThis + offO + 0x20) = 2;
                    *(int *)(pThis + offO + 0x28) = *(int *)(gSndRecentTransaction_IOPImageArray + offG + 0x10);
                    return 1;
                }
                j++;
                offJ += 0x28;
            } while (j < 4);
        }
        i++;
        offG += 0x18;
        offO += 0x28;
    } while (i < 2);
    return 1;
}

// FUNCTION: 0x001DA6D0 FrameMaintenacePartA__21IOPTransactionManagerFv
int IOPTransactionManager::FrameMaintenacePartA() {
    if (m_unk0 != 0) {
        SOUND_TranAcks(m_unk0, m_unkA8);
        memset(m_unkA8, 0, 0x10);
    }
    if (m_unk4 != 0) {
        SOUND_TranCancels(m_unk4, m_unkB8);
        memset(m_unkB8, 0, 0x10);
    }
    m_unk0 = 0;
    m_unk4 = 0;
    return 1;
}

// FUNCTION: 0x001DA750 TranProcess__21IOPTransactionManagerFP8IOP_TranUi
int IOPTransactionManager::TranProcess(IOP_Tran *o_pTran, unsigned int nId) {
    CDS_ASSERT(0x11F, o_pTran);
    unsigned int i = 0;
    do {
        if (nId == m_unk8[i].m_unk0 && m_unk8[i].m_unk18 == 2) {
            if (o_pTran != 0) {
                memcpy(o_pTran, &m_unk8[i], 0x28);
            }
            memset(&m_unk8[i], 0, 0x28);
            return 0;
        }
        i++;
    } while (i < 4);
    return 1;
}

// DRAFT: 0x001DA840 TranAdd__21IOPTransactionManagerFPC8IOP_Tran
// note: 24 differing words; bnez at 0x2C targets one insn late, state write computes this+0x20 then adds index in other order (orig addiu/addu/sw, ours addu/sw 0x20(v0)); tried pState base and separate off variable, both still 24.
int IOPTransactionManager::TranAdd(const IOP_Tran *pTran) {
    unsigned int i = 0;
    do {
        if (m_unk8[i].m_unk0 == 0) {
            memcpy(&m_unk8[i], pTran, 0x28);
            unsigned int off = i * 0x28;
            *(int *)((char *)this + 0x20 + off) = 1;
            SOUND_TranAdd(pTran->m_unk0, pTran->m_unk4, pTran->m_unk8, pTran->m_unkC, pTran->m_unk10, pTran->m_unk14);
            return 1;
        }
        i++;
    } while (i < 4);
    return 0;
}

// FUNCTION: 0x001DA8F0 InitMembers__21IOPTransactionManagerFv
int IOPTransactionManager::InitMembers() {
    return (int)memset(this, 0, (char *)m_unkB8 - (char *)this + sizeof(m_unkB8));
}

// FUNCTION: 0x001DA910 __dt__21IOPTransactionManagerFv
extern "C" IOPTransactionManager *__dt__21IOPTransactionManagerFv(IOPTransactionManager *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001DA960 __ct__21IOPTransactionManagerFv
// note: one extra nop after loop sltu (orig size 0x58, ours 0x54); tried 6 loop/pointer variants, best is 11 differing words.
extern "C" IOPTransactionManager *__ct__21IOPTransactionManagerFv(IOPTransactionManager *pThis) {
    IOP_Tran *p = pThis->m_unk8;
    do {
        __ct__8IOP_TranFv(p);
        p += 1;
    } while (p < (IOP_Tran *)((char *)pThis + 0xA8));
    pThis->InitMembers();
    return pThis;
}
