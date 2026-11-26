// FLAGS: -str readonly
#include "MemoryManager.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void DisplayDebugPs2__10MemoryPoolFi(void *pThis, int nArg);
extern "C" void __dl__FPv(void *pMem);
extern "C" void DeAllocate__10MemoryPoolFPvi(void *pPool, void *pMem, int nPool);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" void Add__10PHashTableFPvPv(void *pThis, void *pKey, void *pValue);

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

// DRAFT: 0x0012AB60 Delete__13MemoryManagerFPv
// note: 6 words after permuter (spelling from build/permuter/0012AB60/best.cpp). Earlier: 12 words differ; masked address, index and offset registers are swapped vs original; frame 0xE0 vs ours. Tried: plain while (23), do-while (17), pointer walk (63), mask-first decl order (17), early copy/late mask (39), dropping nOffset (12).
void MemoryManager::Delete(void *pMem) {
    void *pStart;
    void *pEnd;
    char buf[0x88];
    if (!m_unk1D) {
        CdsAssert__FPciPc("MemoryManager.cpp", 0xA8, "0");
    }
    int nPool = 0;
    int nAddr = (unsigned int)pMem & 0x0FFFFFFF;
    do {
        m_aoPool[nPool].GetStartEnd(pStart, pEnd);
        if (nAddr >= (unsigned int)pStart && (unsigned int)pEnd >= nAddr) {
            DeAllocate__10MemoryPoolFPvi(&m_aoPool[nPool], (void *)nAddr, nPool);
            return;
        }
        nPool += 1;
    } while (3 > nPool);
    sprintf(buf, "Pointer passed to delete not in any pools! at 0x%x\n", nAddr);
    CdsAssert__FPciPc("MemoryManager.cpp", 0xBC, buf);
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

// FUNCTION: 0x0012ACE0 AllocateAligned__13MemoryManagerFiUi
void *MemoryManager::AllocateAligned(int nSize, unsigned int nAlign) {
    if ((unsigned int)m_unk18 >= 3) {
        CdsAssert__FPciPc("MemoryManager.cpp", 0x81, "(unsigned int)iPoolID < MAX_MEMORY_POOL");
    }
    void *pRef;
    void *pMem = m_aoPool[m_unk18].AllocateAligned(nSize, m_unk18, nAlign, pRef);
    Add__10PHashTableFPvPv(&m_oAlignedTable, pMem, pRef);
    return pMem;
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
