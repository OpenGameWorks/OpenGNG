// FLAGS: -str readonly
#include "PHashTable.h"

#include "types.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);
extern "C" void __dla__FPv(void *pMem);

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

// FUNCTION: 0x00130570 __dt__10PHashTableFv
PHashTable::~PHashTable() {
    if (m_unk8 != 0) {
        Destroy();
    }
}
