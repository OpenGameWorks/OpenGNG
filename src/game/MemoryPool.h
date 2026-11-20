#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

enum Status {
    eStatus_0 = 0,
    eStatus_1 = 1
};

class MemoryPool {
public:
    struct Block {
        unsigned int m_unk0; // 0x00 magic 0xA0A0A0A0 on a valid header
        unsigned int m_unk4; // 0x04 bit 31 status, low 31 bits length
        Block *m_unk8;       // 0x08 free-list next
        Block *m_unkC;       // 0x0C free-list prev
    };

    void AddToLength(Block *block, unsigned int len);
    void SetStatus(Block *block, Status status);
    bool NextBlockCorrupted(Block *block);
    void *AllocateAligned(unsigned int size, int arg1, unsigned int align, void *&ref);
    void GetStartEnd(void *&start, void *&end);
    void DeletePoolContents();
    void Remove(Block *block);
    void MergeBlocks(Block *block);
    void InsertSorted(Block *block);
    void *Init(char *buf, unsigned int size);

    int GetStatus(Block *block);
    int GetLength(Block *block);
    void SetLength(Block *block, unsigned int len);
    void *Allocate(unsigned int size, int arg1);

    char _pad000[0x100]; // 0x000
    int m_unk100;        // 0x100
    int m_unk104;        // 0x104
    void *m_unk108;      // 0x108
    Block *m_unk10C;     // 0x10C
    Block *m_unk110;     // 0x110
    int m_unk114;        // 0x114
    int m_unk118;        // 0x118
    unsigned char m_unk11C; // 0x11C
};

#endif
