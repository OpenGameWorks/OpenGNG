#include "types.h"
#include "Debug.h"
#include "PTextureDmaChain.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void FlushCache(int nMode);
extern "C" void iFlushCache(int nMode);
extern "C" void __dl__FPv(void *pMem);

// DRAFT: 0x00189080 Kick__16PTextureDmaChainFb
// note: 6 words differ. Original hoists the index shift and 0x7088 base into beqz delay slot; ours folds 0x7088 into the lw offset. Tried hoisted nIdx local and pTable pointer variants, no gain. Also tried cast-arith *(int*)((uint)this+0x7088+(i<<2)) with/without nIdx local (42), unsigned nIdx (43), nIdx local, int* offset pointer, byte-offset table read, reversed compare (8), pointer to entry (all 6).
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

// DRAFT: 0x00189150 NextBatch__16PTextureDmaChainFv
// note: 40 words differ. Prologue, both asserts and return match; body register allocation differs (0x7088 folded into the store, value and dst scheduled in other order). Six variants tried: dst-first, nIdx/nVal locals, hoisted pTable, pointer-arithmetic store, separate tag local.
int PTextureDmaChain::NextBatch() {
    if ((m_unk7080 + 2) >= 0x700) {
        CdsAssert("PTextureDmaChain.cpp", 0x44, "(miNumEntries + 2) < TEX_DMA_CHAIN_SIZE");
    }
    int *pTable = m_unk7088;
    unsigned int nIdx = m_unk7080;
    unsigned int nTag = (unsigned int)&m_unk7290;
    long long nVal = ((long long)nTag << 32) | 1;
    *(long long *)((unsigned int)(m_unk40 + (nIdx << 4)) | 0x20000000) = nVal;
    m_unk7080 = m_unk7080 + 1;
    m_unk7084 = 0;
    m_unk728C = m_unk728C + 1;
    *(pTable + m_unk728C) = m_unk7080;
    if (m_unk728C >= 0x80) {
        CdsAssert("PTextureDmaChain.cpp", 0x50, "miNumBatches < MAX_TEX_PER_FRAME");
    }
    asm { sync }
    return 1;
}

// FUNCTION: 0x00189230 AllocEntries__16PTextureDmaChainFi
void *PTextureDmaChain::AllocEntries(int nCount) {
    unsigned int nNew;
    unsigned int nOld;
    nOld = m_unk7080;
    void *pEntry = 0;
    nNew = nOld + nCount;
    if (0x700 > nNew) {
        m_unk7080 = nNew;
        m_unk7084 += nCount;
        pEntry = m_unk40 + (nOld << 4);
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
