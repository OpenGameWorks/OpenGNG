// FLAGS: -str readonly
#include "MemoryManager.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void DisplayDebugPs2__10MemoryPoolFi(void *pThis, int nArg);
extern "C" void __dl__FPv(void *pMem);

// FUNCTION: 0x0012AA40 __dt__13MemoryManagerFv
MemoryManager::~MemoryManager() {
}

// FUNCTION: 0x0012AAA0 DisplayDebug__13MemoryManagerFv
void MemoryManager::DisplayDebug() {
    if (m_unk1C) {
        DisplayDebugPs2__10MemoryPoolFi(&m_aoPool[0], 0);
        DisplayDebugPs2__10MemoryPoolFi(&m_aoPool[1], 1);
        DisplayDebugPs2__10MemoryPoolFi(&m_aoPool[2], 2);
    }
}

// FUNCTION: 0x0012AAF0 DeletePoolContents__13MemoryManagerFi
void MemoryManager::DeletePoolContents(int nPool) {
    if ((unsigned int)nPool >= 3) {
        CdsAssert__FPciPc("MemoryManager.cpp", 0xC7, "(unsigned int)iPID < MAX_MEMORY_POOL");
    }
    m_aoPool[nPool].DeletePoolContents();
}

// FUNCTION: 0x0012AC60 DeAllocateAligned__13MemoryManagerFPv
void MemoryManager::DeAllocateAligned(void *pMem) {
    void *pRef;
    if (m_oAlignedTable.Lookup(pMem, pRef)) {
        Delete(pRef);
        m_oAlignedTable.Remove(pMem);
    } else {
        CdsAssert__FPciPc("MemoryManager.cpp", 0x9A, "Couldn't delete aligned memory\n");
    }
}

// FUNCTION: 0x0012AD80 New__13MemoryManagerFUi
void *MemoryManager::New(unsigned int nSize) {
    if (!m_unk1D) {
        CdsAssert__FPciPc("MemoryManager.cpp", 0x73, "0");
    }
    if ((unsigned int)m_unk18 >= 3) {
        CdsAssert__FPciPc("MemoryManager.cpp", 0x76, "(unsigned int)iPoolID < MAX_MEMORY_POOL");
    }
    return m_aoPool[m_unk18].Allocate(nSize, m_unk18);
}
