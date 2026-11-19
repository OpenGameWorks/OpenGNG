#include "types.h"
#include "MemoryCard.h"

// TODO(header): foreign declarations
extern unsigned char gInterface[2656];
extern "C" void RemoveText__11FontManagerFUs(void *pThis, unsigned short nId);
extern "C" void __dl__FPv(void *pMem);

// DRAFT: 0x00150130 CheckSum__10MemoryCardFPUc
// note: 6 words differ; original has no entry branch and two nops before bnez, ours has a daddu copy of the counter. Tried for, do-while, while(i--), while(i--!=0), mid-body decrement.
int MemoryCard::CheckSum(unsigned char *pBuf) {
    int nSum = 0;
    int i = 0x1C38;
    while (i--) {
        nSum += *pBuf++;
    }
    if (nSum != 0) {
        return nSum;
    }
    return -1;
}

// FUNCTION: 0x00150470 ResetFileStatus__10MemoryCardFv
void MemoryCard::ResetFileStatus() {
    m_unk1FA = -1;
    m_unk1FB = -1;
    m_unk1FC = -1;
    m_unk1FD = -1;
    m_unk1FE = -1;
    m_unk1FF = -1;
}

// FUNCTION: 0x00151D10 IssueCommand__10MemoryCardFPCc
void MemoryCard::IssueCommand(const char *pCmd) {
    m_unk1DC = (int)pCmd | 0x30000000;
    m_unk1E0 = 0;
    m_unk1E4 = 0;
    m_unk1E6 = 0;
    m_unk1EC = 0;
    m_unk1F5 = 0;
    m_unk1F6 = 0;
}

// FUNCTION: 0x001528F0 RemoveMCText__10MemoryCardFv
void MemoryCard::RemoveMCText() {
    if (m_unk200 != 0) {
        RemoveText__11FontManagerFUs(gInterface + 0x1790, 10);
        m_unk200 = 0;
    }
}

// FUNCTION: 0x00152930 __dt__10MemoryCardFv
extern "C" MemoryCard *__dt__10MemoryCardFv(MemoryCard *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
