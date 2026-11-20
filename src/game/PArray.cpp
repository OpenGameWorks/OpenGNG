// FLAGS: -str readonly
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dla__FPv(void *pMem);

// FUNCTION: 0x0012EBB0 RemoveAt__6PArrayFi
void PArray::RemoveAt(int nIndex) {
    unsigned int nSlot = nIndex;
    if (nSlot >= m_unk0) {
        CdsAssert__FPciPc("PArray.cpp", 0xCD, "(unsigned int)iPos < muNumArray");
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
        CdsAssert__FPciPc("PArray.cpp", 0xC3, "miCurrent >= 0 && muNumArray");
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

// DRAFT: 0x0012EFE0 Allocate__6PArrayFUi
// note: 51 words, size 0xdc vs 0xe4; prologue swaps this (s1 orig, s0 ours) and nAlloc (s0 orig, s1 ours); tried nAlloc copy, uninit decl, early return, nSize kept live, nested if
void PArray::Allocate(unsigned int nSize) {
    if (nSize != 0) {
        unsigned int nAlloc = (nSize + 3) & ~3u;
        void **pNew = (void **)__nwa__FUi(nAlloc * 4);
        if (pNew == 0) {
            CdsAssert__FPciPc("PArray.cpp", 0x2A, "pNew");
        }
        if (m_unk8 != 0) {
            if (m_unk0 != 0) {
                if (nAlloc < m_unk0) {
                    CdsAssert__FPciPc("PArray.cpp", 0x2D, "iSize >= muNumArray");
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
        m_unkC = nAlloc;
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
