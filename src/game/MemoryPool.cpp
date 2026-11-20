// FLAGS: -str readonly
#include "types.h"
#include "MemoryPool.h"

// TODO(header): foreign declarations
extern "C" int sprintf(char *pBuf, const char *fmt, ...);
extern "C" void CdsAssert__FPciPc(char *, int, char *);

// FUNCTION: 0x0012B360 AddToLength__10MemoryPoolFPQ210MemoryPool5BlockUi
void MemoryPool::AddToLength(Block *block, unsigned int len) {
    int cur = GetLength(block);
    cur += len;
    SetLength(block, cur);
}

// FUNCTION: 0x0012B400 SetStatus__10MemoryPoolFPQ210MemoryPool5Block6Status
void MemoryPool::SetStatus(Block *block, Status status) {
    if (status == eStatus_1) {
        block->m_unk4 |= 0x80000000;
    } else {
        block->m_unk4 &= 0x7FFFFFFF;
    }
}

// FUNCTION: 0x0012B440 NextBlockCorrupted__10MemoryPoolFPQ210MemoryPool5Block
bool MemoryPool::NextBlockCorrupted(Block *block) {
    if (block->m_unk0 != 0xA0A0A0A0) {
        return false;
    }
    return (block + GetLength(block))->m_unk0 != 0xA0A0A0A0;
}

// FUNCTION: 0x0012B6C0 AllocateAligned__10MemoryPoolFUiiUiRPv
void *MemoryPool::AllocateAligned(unsigned int size, int arg1, unsigned int align, void *&ref) {
    void *ptr;

    if (align != 0x20 && align != 0x40 && align != 0x80 && align != 0x100) {
        sprintf((char *)this, "MemoryPool %d ( Allocate Failed : Illegal Alignment )\n", arg1);
        CdsAssert__FPciPc("MemoryPool.cpp", 0x13A, (char *)this);
    }
    size += align;
    ptr = Allocate(size, arg1);
    ref = ptr;
    return (void *)(((unsigned int)ptr + align) - ((unsigned int)ptr & (align - 1)));
}

// FUNCTION: 0x0012BC50 GetStartEnd__10MemoryPoolFRPvRPv
void MemoryPool::GetStartEnd(void *&start, void *&end) {
    start = m_unk108;
    end = (Block *)m_unk108 + (m_unk100 - 1);
}
