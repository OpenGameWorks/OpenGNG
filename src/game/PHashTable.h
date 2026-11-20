#ifndef PHASHTABLE_H
#define PHASHTABLE_H

#include "types.h"

// Chained hash table keyed by pointer (PHashTable.cpp, 0x130030-0x1305E4).
// The bucket index is ((unsigned int)key >> 4) % m_unk0.
struct PHashNode {
    PHashNode *m_unk0;  // 0x00 next node in the same bucket
    void *m_unk4;       // 0x04 key
    void *m_unk8;       // 0x08 value
};

class PHashTable {
public:
    ~PHashTable();
    void *GetNodeAt(void *pKey, unsigned int &uIndex);
    bool Lookup(void *pKey, void *&pValue);
    void *Remove(void *pKey);
    void RemoveAll();   // 0x130180, owned by another job
    void Destroy();

    unsigned int m_unk0;    // 0x00 bucket count
    int m_unk4;             // 0x04 entry count, decremented by Remove
    PHashNode **m_unk8;     // 0x08 bucket array, freed with delete[] by Destroy
};

#endif
