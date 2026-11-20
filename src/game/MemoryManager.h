#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "types.h"
#include "MemoryPool.h"
#include "PHashTable.h"

class MemoryManager {
public:
    ~MemoryManager();
    void DisplayDebug();
    void DeletePoolContents(int nPool);
    void DeAllocateAligned(void *pMem);
    void Delete(void *pMem);
    void *New(unsigned int nSize);

    char _pad000[0x18];         // 0x000
    int m_unk18;                // 0x018 pool index for New
    unsigned char m_unk1C;      // 0x01C enables DisplayDebug
    unsigned char m_unk1D;      // 0x01D checked by New
    char _pad01E[0x2];          // 0x01E
    MemoryPool m_aoPool[3];     // 0x020 three pools, 0x120 bytes apart
    PHashTable m_oAlignedTable; // 0x380 pointer-keyed table of aligned allocations
};

// MemMgr is 908 bytes (0x38C); the global is defined outside this file.

#endif
