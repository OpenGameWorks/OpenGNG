// FLAGS: -str readonly
#include "PHashTable.h"

#include "types.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);
extern "C" void __dla__FPv(void *pMem);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);

// FUNCTION: 0x00130030 GetNodeAt__10PHashTableFPvRUi
void *PHashTable::GetNodeAt(void *pKey, unsigned int &uIndex) {
    if (m_unk8 == 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0xEC, "mpNodeArray");
    }
    uIndex = ((unsigned int)pKey >> 4) % m_unk0;
    PHashNode *pNode = m_unk8[uIndex];
    while (pNode != 0) {
        if (pNode->m_unk4 == pKey) {
            return pNode;
        }
        pNode = pNode->m_unk0;
    }
    return 0;
}

// FUNCTION: 0x001300F0 Lookup__10PHashTableFPvRPv
bool PHashTable::Lookup(void *pKey, void *&pValue) {
    unsigned int uIndex = 0;
    bool bFound = false;
    if (m_unk8 == 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0xCF, "mpNodeArray");
    }
    PHashNode *pNode = (PHashNode *)GetNodeAt(pKey, uIndex);
    if (pNode != 0) {
        bFound = 1;
        pValue = pNode->m_unk8;
    }
    return bFound;
}

// FUNCTION: 0x00130180 RemoveAll__10PHashTableFv
void PHashTable::RemoveAll() {
    if (m_unk8 == 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0xAC, "mpNodeArray");
    }
    for (unsigned int i = 0; i < m_unk0; i++) {
        PHashNode *pNode = m_unk8[i];
        if (pNode != 0) {
            do {
                PHashNode *pNext = pNode->m_unk0;
                __dl__FPv(pNode);
                pNode = pNext;
                m_unk4 -= 1;
            } while (pNode != 0);
        }
        m_unk8[i] = 0;
    }
    if (m_unk4 != 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0xC5, "muNumNodes == 0");
    }
}

// FUNCTION: 0x00130270 Remove__10PHashTableFPv
void *PHashTable::Remove(void *pKey) {
    if (m_unk8 == 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0x8D, "mpNodeArray");
    }
    PHashNode **ppSlot = &m_unk8[((unsigned int)pKey >> 4) % m_unk0];
    PHashNode *pNode = *ppSlot;
    while (pNode != 0) {
        if (pNode->m_unk4 == pKey) {
            void *pValue = pNode->m_unk8;
            *ppSlot = pNode->m_unk0;
            __dl__FPv(pNode);
            m_unk4 -= 1;
            return pValue;
        }
        ppSlot = &pNode->m_unk0;
        pNode = pNode->m_unk0;
    }
    return 0;
}

// FUNCTION: 0x00130330 Add__10PHashTableFPvPv
bool PHashTable::Add(void *pKey, void *pValue) {
    unsigned int uIndex = 0;
    bool bAdded = false;
    if (m_unk8 == 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0x60, "mpNodeArray");
    }
    PHashNode *pNode = (PHashNode *)GetNodeAt(pKey, uIndex);
    if (pNode != 0) {
        pNode->m_unk8 = pValue;
        bAdded = true;
    } else {
        PHashNode *pNew = (PHashNode *)__nw__FUi(0xC);
        if (pNew == 0) {
            CdsAssert__FPciPc("PHashTable.cpp", 0x6E, "apNode");
        }
        if (pNew != 0) {
            pNew->m_unk4 = pKey;
            pNew->m_unk8 = pValue;
            pNew->m_unk0 = m_unk8[uIndex];
            m_unk8[uIndex] = pNew;
            m_unk4 += 1;
            bAdded = true;
        }
    }
    return bAdded;
}

// FUNCTION: 0x00130440 Destroy__10PHashTableFv
void PHashTable::Destroy() {
    if (m_unk8 == 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0x3D, "mpNodeArray");
    }
    RemoveAll();
    __dla__FPv(m_unk8);
    m_unk8 = 0;
    m_unk0 = 0;
    m_unk4 = 0;
}

// DRAFT: 0x001304A0 Create__10PHashTableFUi
// note: 50 words differ; frame 0x40 with three saved regs vs original 0x30 with two (nBuckets*4 CSE'd into s0); memset/alloc size spelling does not change it
bool PHashTable::Create(unsigned int nBuckets) {
    if (nBuckets == 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0x1F, "uTheSize");
    }
    if (m_unk8 != 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0x20, "mpNodeArray == NULL");
    }
    if (m_unk8 != 0) {
        return false;
    }
    m_unk8 = (PHashNode **)__nwa__FUi(nBuckets * 4);
    if (m_unk8 == 0) {
        CdsAssert__FPciPc("PHashTable.cpp", 0x2B, "mpNodeArray");
    }
    if (m_unk8 != 0) {
        memset(m_unk8, 0, nBuckets * 4);
        m_unk0 = nBuckets;
        m_unk4 = 0;
        return true;
    }
    return false;
}

// FUNCTION: 0x00130570 __dt__10PHashTableFv
PHashTable::~PHashTable() {
    if (m_unk8 != 0) {
        Destroy();
    }
}

// FUNCTION: 0x001305D0 __ct__10PHashTableFv
PHashTable::PHashTable() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
}
