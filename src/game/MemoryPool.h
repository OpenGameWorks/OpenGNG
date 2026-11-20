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
        char _pad08[0x8];    // 0x08
    };

    void AddToLength(Block *block, unsigned int len);
    void SetStatus(Block *block, Status status);
    bool NextBlockCorrupted(Block *block);
    void *AllocateAligned(unsigned int size, int arg1, unsigned int align, void *&ref);
    void GetStartEnd(void *&start, void *&end);

    int GetLength(Block *block);
    void SetLength(Block *block, unsigned int len);
    void *Allocate(unsigned int size, int arg1);

    char _pad000[0x100]; // 0x000
    int m_unk100;        // 0x100
    char _pad104[0x4];   // 0x104
    void *m_unk108;      // 0x108
};

#endif
