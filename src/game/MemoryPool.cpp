// FLAGS: -str readonly
#include "types.h"
#include "MemoryPool.h"

// TODO(header): foreign declarations
extern "C" int sprintf(char *pBuf, const char *fmt, ...);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);

// FUNCTION: 0x0012B290 DeletePoolContents__10MemoryPoolFv
void MemoryPool::DeletePoolContents() {
    memset(m_unk108, 0, m_unk100 << 4);
    m_unk110 = (Block *)((char *)m_unk108 + (m_unk100 << 4));
    SetStatus(m_unk110, eStatus_1);
    m_unk110->m_unk8 = m_unk110;
    m_unk110->m_unkC = m_unk110;
    m_unk110->m_unk0 = 0xA0A0A0A0;
    Block *pBlock = (Block *)m_unk108;
    SetStatus(pBlock, eStatus_0);
    SetLength(pBlock, m_unk100);
    InsertSorted(pBlock);
    m_unk104 = m_unk100;
    m_unk118 = 0;
    m_unk114 = 0;
    m_unk11C = 1;
}

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

// FUNCTION: 0x0012B950 Remove__10MemoryPoolFPQ210MemoryPool5Block
void MemoryPool::Remove(Block *block) {
    if (block == 0) {
        CdsAssert__FPciPc("MemoryPool.cpp", 0xC8, "pBlock");
    }
    if (GetStatus(block) != 1) {
        if (block->m_unk8 != m_unk110) {
            m_unk10C = block->m_unk8;
            m_unk10C->m_unkC = block->m_unkC;
            m_unk10C = block->m_unkC;
            m_unk10C->m_unk8 = block->m_unk8;
            return;
        }
        m_unk10C = block->m_unkC;
        m_unk10C->m_unk8 = m_unk110;
        return;
    }
    sprintf((char *)this, "MemoryPool ( Remove failed : Tried to remove a reserved block <0x%x>\n", block);
    CdsAssert__FPciPc("MemoryPool.cpp", 0xE5, (char *)this);
}

// DRAFT: 0x0012BA30 MergeBlocks__10MemoryPoolFPQ210MemoryPool5Block
// note: 32 words differ, all in s-register permutation: ours this/block/merged-next = s4/s3/s2, original = s3/s2/s4. Tried next-first, unmerged-first, next-per-block (best), renamed local.
void MemoryPool::MergeBlocks(Block *block) {
    Block *prev = block->m_unkC;
    int unmerged = 1;
    if (prev != m_unk110) {
        if (prev + GetLength(prev) == block) {
            Remove(block);
            unmerged = 0;
            AddToLength(prev, GetLength(block));
            Block *next = prev->m_unk8;
            if (next != m_unk110) {
                if (prev + GetLength(prev) == next) {
                    Remove(next);
                    AddToLength(prev, GetLength(next));
                }
            }
        }
    }
    if (unmerged) {
        Block *next = block->m_unk8;
        if (next != m_unk110) {
            if (block + GetLength(block) == next) {
                Remove(next);
                AddToLength(block, GetLength(next));
            }
        }
    }
}

// DRAFT: 0x0012BB70 InsertSorted__10MemoryPoolFPQ210MemoryPool5Block
// note: 48 words differ: original tests empty sentinel with xor/sltiu/beqz (value-materialized compare) and keeps first in a3, sentinel in v1; ours uses bne. Tried operand order (no change), sentinel local (50->49), link pointer &sentinel->m_unk8 (49->48), bool local for compare (no change).
void MemoryPool::InsertSorted(Block *block) {
    block->m_unk0 = 0xA0A0A0A0;
    Block *sentinel = m_unk110;
    Block **link = &sentinel->m_unk8;
    Block *first = *link;
    if (first == sentinel) {
        *link = block;
        block->m_unk8 = sentinel;
        block->m_unkC = sentinel;
        return;
    }
    m_unk10C = first;
    while (m_unk10C != m_unk110) {
        if (block < m_unk10C) {
            block->m_unkC = m_unk10C->m_unkC;
            block->m_unk8 = m_unk10C;
            m_unk10C->m_unkC = block;
            m_unk10C = block->m_unkC;
            m_unk10C->m_unk8 = block;
            MergeBlocks(block);
            return;
        }
        Block *next = m_unk10C->m_unk8;
        if (next == m_unk110) {
            m_unk10C->m_unk8 = block;
            block->m_unk8 = m_unk110;
            block->m_unkC = m_unk10C;
            MergeBlocks(block);
            return;
        }
        m_unk10C = next;
    }
}

// FUNCTION: 0x0012BC50 GetStartEnd__10MemoryPoolFRPvRPv
void MemoryPool::GetStartEnd(void *&start, void *&end) {
    start = m_unk108;
    end = (Block *)m_unk108 + (m_unk100 - 1);
}

// FUNCTION: 0x0012BC80 Init__10MemoryPoolFPcUi
void *MemoryPool::Init(char *buf, unsigned int size) {
    m_unk100 = (size + 0xF) >> 4;
    m_unk108 = buf;
    m_unk110 = (Block *)((char *)m_unk108 + (m_unk100 << 4));
    SetStatus(m_unk110, eStatus_1);
    m_unk110->m_unk8 = m_unk110;
    m_unk110->m_unkC = m_unk110;
    m_unk110->m_unk0 = 0xA0A0A0A0;
    Block *pBlock = (Block *)m_unk108;
    SetStatus(pBlock, eStatus_0);
    SetLength(pBlock, m_unk100);
    InsertSorted(pBlock);
    m_unk104 = m_unk100;
    m_unk118 = 0;
    m_unk114 = 0;
    m_unk11C = 0;
    return (char *)m_unk108 + ((m_unk100 + 1) << 4);
}
