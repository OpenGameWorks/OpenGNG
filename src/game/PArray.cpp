// COMPILER: mwcps2-3.0-011126
// FLAGS: -str readonly
#include "PArray.h"
#include "Debug.h"

// TODO(header): foreign declarations
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dla__FPv(void *pMem);

// FUNCTION: 0x0012EBB0 RemoveAt__6PArrayFi
void PArray::RemoveAt(int nIndex) {
    unsigned int nSlot = nIndex;
    if (nSlot >= m_unk0) {
        CdsAssert("PArray.cpp", 0xCD, "(unsigned int)iPos < muNumArray");
    }
    unsigned int nOff = nSlot * 4;
    m_unk0--;
    while ((int)nSlot < (int)m_unk0) {
        nSlot++;
        unsigned int *pDst = (unsigned int *)((char *)m_unk8 + nOff);
        *pDst = pDst[1];
        nOff += 4;
    }
}

// FUNCTION: 0x0012EC40 RemoveCurrent__6PArrayFv
void PArray::RemoveCurrent() {
    int bOk = (int)m_unk4 >= 0;
    if (bOk) {
        bOk = m_unk0 != 0;
    }
    if (!bOk) {
        CdsAssert("PArray.cpp", 0xC3, "miCurrent >= 0 && muNumArray");
    }
    m_unk0--;
    int i = m_unk4;
    unsigned int nOff = i * 4;
    while (i < (int)m_unk0) {
        i++;
        unsigned int *pDst = (unsigned int *)((char *)m_unk8 + nOff);
        *pDst = pDst[1];
        nOff += 4;
    }
    m_unk4--;
}

// FUNCTION: 0x0012ECF0 Remove__6PArrayFPv
int PArray::Remove(void *pItem) {
    if (pItem == 0 || m_unk8 == 0) {
        return 0;
    }
    unsigned int nIdx = 0;
    unsigned int nOff = 0;
    while (nIdx < m_unk0) {
        if (*(void **)((char *)m_unk8 + nOff) == pItem) {
            unsigned int nRem = nIdx * 4;
            m_unk0--;
            while (nIdx < m_unk0) {
                nIdx++;
                unsigned int *pDst = (unsigned int *)((char *)m_unk8 + nRem);
                *pDst = pDst[1];
                nRem += 4;
            }
            m_unk4 = 0;
            return 1;
        }
        nOff += 4;
        nIdx++;
    }
    return 0;
}

// DRAFT: 0x0012EDA0 InsertBefore__6PArrayFPv
// note: 33 words; unsigned grow-copy index (sltu, was slt) fixed one diff. Remaining: a1/a0 temp for m_unkC (original zeroes pFree in the bnez delay slot, ours in the else arm); shift-loop and grow-loop layout differ. Tried: pFree=0 hoisted above the if (63 words, both void** and void*), pFree=0 in else (33), fresh nCap local (33), while-form shift loop (33)
void PArray::InsertBefore(void *pItem) {
    if (m_unk4 < 0) {
        CdsAssert("PArray.cpp", 0x87, "miCurrent >= 0");
    }
    void **pSrc = m_unk8;
    void **pDst = pSrc;
    void **pFree;
    if (m_unk0 >= m_unkC) {
        m_unkC = m_unkC + 4;
        void **pNew = (void **)__nwa__FUi(m_unkC * 4);
        if (pNew == 0) {
            CdsAssert("PArray.cpp", 0x8F, "pNew");
        }
        m_unk8 = pNew;
        pFree = pSrc;
        pDst = pNew;
        for (unsigned int i = 0; i < m_unk4; i++) {
            pDst[i] = pSrc[i];
        }
    } else {
        pFree = 0;
    }
    for (int i = (int)m_unk0 - 1; i >= m_unk4; i--) {
        pDst[i + 1] = pSrc[i];
    }
    pDst[m_unk4] = pItem;
    if (pFree != 0) {
        __dla__FPv(pFree);
    }
    m_unk0++;
}

// DRAFT: 0x0012EEF0 Add__6PArrayFPv
// note: 31 words, size 0xe0 vs 0xe8; original keeps old pointer in s3 as copy source and copies it to a0 for __dla before the loop, mine keeps pOld in s3 and copies src to v1; tried swapping src to loop cursor (45 words, reverted)
void PArray::Add(void *pItem) {
    if (m_unk0 >= m_unkC) {
        unsigned int nCap = m_unkC;
        m_unkC = nCap + 4;
        void **pOld = m_unk8;
        void **pNew = (void **)__nwa__FUi(m_unkC * 4);
        if (pNew == 0) {
            CdsAssert("PArray.cpp", 0x4A, "pNew");
        }
        m_unk8 = pNew;
        if (pOld != 0) {
            unsigned int n = nCap;
            void **src = pOld;
            void **dst = pNew;
            if (n != 0) {
                do {
                    n--;
                    *dst = *src;
                    src++;
                    dst++;
                } while (n != 0);
            }
            __dla__FPv(pOld);
        }
    }
    m_unk8[m_unk0] = pItem;
    m_unk0++;
}

// FUNCTION: 0x0012EFE0 Allocate__6PArrayFUi
void PArray::Allocate(unsigned int nSize) {
    if (nSize != 0) {
        nSize = (nSize + 3) & ~3u;
        void **pNew = (void **)__nwa__FUi(nSize * 4);
        if (pNew == 0) {
            CdsAssert("PArray.cpp", 0x2A, "pNew");
        }
        if (m_unk8 != 0) {
            if (m_unk0 != 0) {
                if (nSize < m_unk0) {
                    CdsAssert("PArray.cpp", 0x2D, "iSize >= muNumArray");
                }
                unsigned int n = m_unk0;
                void **src = m_unk8;
                void **dst = pNew;
                if (n != 0) {
                    do {
                        n--;
                        *dst = *src;
                        src++;
                        dst++;
                    } while (n != 0);
                }
            }
            __dla__FPv(m_unk8);
        }
        m_unk8 = pNew;
        m_unkC = nSize;
        m_unk4 = 0;
    }
}

// FUNCTION: 0x0012F0D0 __dt__6PArrayFv
PArray::~PArray() {
    if (m_unk8 != 0) {
        __dla__FPv(m_unk8);
        m_unk8 = 0;
    }
    m_unk0 = 0;
}

// FUNCTION: 0x0012F140 __ct__6PArrayFv
PArray::PArray() {
    m_unkC = 0;
    m_unk8 = 0;
    m_unk0 = 0;
    m_unk4 = 0;
}
