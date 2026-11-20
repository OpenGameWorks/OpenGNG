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

// FUNCTION: 0x0012B3C0 SetLength__10MemoryPoolFPQ210MemoryPool5BlockUi
void MemoryPool::SetLength(Block *block, unsigned int len) {
    block->m_unk4 = len | (block->m_unk4 & 0x80000000);
}

// FUNCTION: 0x0012B3E0 GetStatus__10MemoryPoolFPQ210MemoryPool5Block
int MemoryPool::GetStatus(Block *block) {
    return (block->m_unk4 & 0x80000000) != 0;
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

// DRAFT: 0x0012B4A0 Allocate__10MemoryPoolFUii
// note: 4 words differ: original uses t0/at as scratch for m_unk100<<4 and the >=2 compare, ours reuses v0. Tried blocks-before-cursor (32->4), shift local (no change), remainder local (worse, 20+ words).
void *MemoryPool::Allocate(unsigned int size, int arg1) {
    m_unk118++;
    m_unk11C = 0;
    if (size == 0) {
        sprintf((char *)this, "MemoryPool %d ( Allocate Failed : Can't allocate <%d> bytes )\n", arg1, size);
        CdsAssert__FPciPc("MemoryPool.cpp", 0x15F, (char *)this);
    }
    if ((m_unk100 << 4) < size) {
        sprintf((char *)this, "MemoryPool %d ( Allocate Failed : Can't allocate <%d> bytes. Max for this pool is <%d> bytes )\n", arg1, size);
        CdsAssert__FPciPc("MemoryPool.cpp", 0x165, (char *)this);
    }
    unsigned int blocks = (size + 0x1F) >> 4;
    Block *pBlock = m_unk110->m_unk8;
    while (pBlock != m_unk110) {
        if (GetLength(pBlock) >= blocks) {
            break;
        }
        pBlock = pBlock->m_unk8;
    }
    if (pBlock == m_unk110) {
        sprintf((char *)this, "MemoryPool %d ( Allocate Failed on <%d> bytes : Memory full )\n", arg1, size);
        CdsAssert__FPciPc("MemoryPool.cpp", 0x17F, (char *)this);
    }
    if (blocks < (unsigned int)GetLength(pBlock)) {
        if (GetLength(pBlock) - blocks >= 2) {
            Block *split = pBlock + blocks;
            SetStatus(split, eStatus_0);
            SetLength(split, GetLength(pBlock) - blocks);
            SetLength(pBlock, blocks);
            Remove(pBlock);
            SetStatus(pBlock, eStatus_1);
            InsertSorted(split);
            m_unk104 -= blocks;
            return (void *)(pBlock + 1);
        }
        blocks += 1;
    }
    Remove(pBlock);
    SetStatus(pBlock, eStatus_1);
    m_unk104 -= blocks;
    return (void *)(pBlock + 1);
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

// DRAFT: 0x0012B780 DeAllocate__10MemoryPoolFPvi
// note: first diff at 0x9C: the two trailing %x varargs of the NextBlockCorrupted sprintf are lq 0xB0/0xE0(sp) (caller-frame reads), ours pass literal 0; not expressible from FPvi params (72 words).
void MemoryPool::DeAllocate(void *ptr, int arg1) {
    if (ptr == 0) {
        CdsAssert__FPciPc("MemoryPool.cpp", 0xF2, "pBlock");
    }
    m_unk114++;
    if (m_unk11C != 0) {
        CdsAssert__FPciPc("MemoryPool.cpp", 0xFB, "0");
    }
    if (m_unk104 == m_unk100) {
        CdsAssert__FPciPc("MemoryPool.cpp", 0x101, "0");
    }
    Block *block = (Block *)((char *)ptr - 0x10);
    if (NextBlockCorrupted(block)) {
        sprintf((char *)this, "MemoryPool %d ( DeAllocate Failed : Deleted by 0x%x or 0x%x )\n", arg1, 0, 0);
        CdsAssert__FPciPc("MemoryPool.cpp", 0x112, (char *)this);
    }
    if ((unsigned int)block < (unsigned int)m_unk108 ||
        (unsigned int)block >= (unsigned int)((char *)m_unk108 + (m_unk100 << 4))) {
        sprintf((char *)this, "MemoryPool %d ( DeAllocate Failed : Invalid Adr. <0x%x> Passed )\n", arg1, block);
        CdsAssert__FPciPc("MemoryPool.cpp", 0x119, (char *)this);
    }
    if (GetStatus(block) != 1) {
        sprintf((char *)this, "MemoryPool %d ( DeAllocate Failed : Block <0x%x> not allocated by %x or %x)\n", arg1, block, 0, 0);
        CdsAssert__FPciPc("MemoryPool.cpp", 0x122, (char *)this);
    }
    m_unk104 += GetLength(block);
    SetStatus(block, eStatus_0);
    InsertSorted(block);
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
