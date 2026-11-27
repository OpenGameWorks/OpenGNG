#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "types.h"
#include "MemoryPool.h"
#include "PHashTable.h"

class MemoryManager {
public:
    MemoryManager();
    ~MemoryManager();
    void DisplayDebug();
    void DeletePoolContents(int nPool);
    void DeAllocateAligned(void *pMem);
    void Delete(void *pMem);
    void *AllocateAligned(int nSize, unsigned int nAlign);
    void *New(unsigned int nSize);

    unsigned int m_unk0;        // 0x000 bytes left for the pools (2 MB-aligned top minus the heap)
    char *pStartFreeMemory;     // 0x004 cursor the pools are carved from
    int m_unk8;                 // 0x008
    int m_unkC;                 // 0x00C
    char _pad010[0x8];          // 0x010
    int m_unk18;                // 0x018 pool index for New
    unsigned char m_unk1C;      // 0x01C enables DisplayDebug
    unsigned char m_unk1D;      // 0x01D checked by New
    char _pad01E[0x2];          // 0x01E
    MemoryPool m_aoPool[3];     // 0x020 three pools, 0x120 bytes apart
    PHashTable m_oAlignedTable; // 0x380 pointer-keyed table of aligned allocations
};

// MemMgr is 908 bytes (0x38C); the global is defined outside this file.

#endif
