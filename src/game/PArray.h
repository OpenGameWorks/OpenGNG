#ifndef PARRAY_H
#define PARRAY_H

// Growable pointer array (PArray.cpp, 0x12EBB0-0x12F158). Classes embed it
// as a real member: CodeWarrior then constructs it implicitly and keeps
// `this` spilled at 0x1C(sp) in the owner's constructor, which a manual
// __ct__6PArrayFv call does not reproduce.
class PArray {
public:
    PArray();
    ~PArray();
    void RemoveAt(int nIndex);
    void RemoveCurrent();
    int Remove(void *pItem);
    void InsertBefore(void *pItem);
    void Add(void *pItem);
    void Allocate(unsigned int nSize);

    unsigned int m_unk0;    // 0x00 cleared by ctor, dtor and owners' Destroy
    int m_unk4;             // 0x04 current index
    void **m_unk8;          // 0x08 storage freed with delete[]
    unsigned int m_unkC;    // 0x0C
};

#endif
