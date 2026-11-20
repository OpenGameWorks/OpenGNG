#include "types.h"
#include "PTextureDmaChain.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void FlushCache(int nMode);
extern "C" void iFlushCache(int nMode);
extern "C" void __dl__FPv(void *pMem);

// DRAFT: 0x00189080 Kick__16PTextureDmaChainFb
// note: 6 words differ. Original hoists the index shift and 0x7088 base into beqz delay slot; ours folds 0x7088 into the lw offset. Tried hoisted nIdx local and pTable pointer variants, no gain.
void PTextureDmaChain::Kick(bool bFlag) {
    NextBatch();
    if (m_unk7288 < m_unk728C) {
        int *pTable = m_unk7088;
        unsigned int nAddr = (unsigned int)((char *)this + 0x40 + (pTable[m_unk7288] << 4));
        *(volatile unsigned int *)0x1000E020 = 4;
        *(volatile unsigned int *)0x1000A020 = 0;
        *(volatile unsigned int *)0x1000A030 = nAddr & 0x0FFFFFFF;
        *(volatile unsigned int *)0x1000E010 = 4;
        if (bFlag) {
            iFlushCache(0);
        } else {
            FlushCache(0);
        }
        asm { sync }
        asm { sync.p }
        *(volatile unsigned int *)0x1000A000 = 0x105;
        asm { sync }
        asm { sync.p }
        m_unk7288 = m_unk7288 + 1;
    }
}

// DRAFT: 0x00189230 AllocEntries__16PTextureDmaChainFi
// note: 5 words differ. Original keeps nOld in a2 and the sum in v1, stores 0x7080 before the sll, and exits through a shared jr ra with v0 zeroed in the beqz delay slot. Eight variants tried.
void *PTextureDmaChain::AllocEntries(int nCount) {
    unsigned int nOld = m_unk7080;
    unsigned int nNew = nOld + nCount;
    void *pEntry = 0;
    if (nNew < 0x700) {
        m_unk7080 = nNew;
        pEntry = m_unk40 + (nOld << 4);
        m_unk7084 += nCount;
    }
    return pEntry;
}

// FUNCTION: 0x00189270 Reset__16PTextureDmaChainFv
void PTextureDmaChain::Reset() {
    m_unk7288 = 0;
    m_unk728C = 0;
    memset(m_unk7088, 0, 0x200);
    memset(m_unk40, 0, 0x7000);
    m_unk7080 = 0;
    m_unk7084 = 0;
}

// FUNCTION: 0x001892C0 __dt__16PTextureDmaChainFv
extern "C" PTextureDmaChain *__dt__16PTextureDmaChainFv(PTextureDmaChain *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00189310 __ct__16PTextureDmaChainFv
PTextureDmaChain::PTextureDmaChain() {
    m_unk7290 = 0;
    *(long long *)&m_unk7290 = 0x8000;
    Reset();
}
