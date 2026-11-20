// FLAGS: -str readonly
#include "types.h"
#include "PMeshNode.h"

// TODO(header): foreign declarations
class PArray {
public:
    unsigned int count;
    int index;
    void *table;
    unsigned int size;          // 0x0C GetSize()
    int Find(void *pItem);
    void RemoveAt(int idx);
    void Remove(void *pItem);
    void Add(void *pItem);
};

class PLight {
public:
    char _pad00[0x4C];
    int m_unk4C;
};

class PAnim {
public:
    char _pad00[8];
    short m_unk8;
};

class PMNode {
public:
    void InitMembers();
    PMNode *Find(unsigned int uID);
    void RecurseDetachAnim();
    void AttachAnim(PAnim *pAnim, bool bFlag);
    void AddFxTriggers(PArray *pArr, bool bFlag);
    void CopyMNode(PMNode &src, bool bFlag);
};

extern "C" void *__ct__6PArrayFv(void *pThis);
extern "C" void __dt__6PArrayFv(void *pThis, short flags);
extern "C" void __dt__6PMNodeFv(void *pThis, short flags);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void CdsAssert__FPciPc(const char *pFile, int line, const char *pExpr);
extern "C" void *__nwa__FUi(unsigned int size);
extern "C" void FlushCache(int mode, unsigned int addr, void *pTable, int count);

class PCDFile {
public:
    int Read(void *pBuf, unsigned int size);
};

extern unsigned char __vt__9PMeshNode[];
extern unsigned char __vt__6PMNode[];
extern unsigned char __vt__9PResource[];
extern float gUnitMatrix[16];

// DRAFT: 0x00190390 AdjustPickup__9PMeshNodeFv
// note: 11 words differ; original addresses the first clamp through m_unk10+0x10 (one base reg) and reloads m_unk10 for the second clamp. Tried a cached local pointer (15 words, worse).
void PMeshNode::AdjustPickup() {
    if (m_unk10 != 0) {
        if (m_unk10->m_unk20 < 1.0f) {
            m_unk10->m_unk20 = 1.0f;
        }
        if (m_unk10->m_unk28 < 1.0f) {
            m_unk10->m_unk28 = 1.0f;
        }
    }
    m_unk18 = 0;
    PMeshNode *var = (m_unk14 != 0) ? m_unk1C[0] : 0;
    if (var != 0) {
        do {
            var->AdjustPickup();
            unsigned int next = m_unk18 + 1;
            m_unk18 = next;
            var = (next < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (var != 0);
    }
}

// FUNCTION: 0x00190490 DetachLight__9PMeshNodeFP6PLight
void PMeshNode::DetachLight(PLight *pLight) {
    if (pLight == 0) {
        CdsAssert__FPciPc("PMeshNode.cpp", 0x256, "pLight");
    }
    int idx = ((PArray *)&m_unk130)->Find(pLight);
    if (idx >= 0) {
        ((PArray *)&m_unk130)->RemoveAt(idx);
        pLight->m_unk4C = 0;
    }
    if (((PArray *)&m_unk130)->count == 0) {
        m_unk102 = 0;
    }
}

// FUNCTION: 0x00190510 RemoveFromCollisionArray__9PMeshNodeFP6PArray
void PMeshNode::RemoveFromCollisionArray(PArray *pArr) {
    if (m_unk104 != 0) {
        pArr->Remove(this);
    }
    m_unk18 = 0;
    PMeshNode *var = (m_unk14 != 0) ? m_unk1C[0] : 0;
    if (var != 0) {
        do {
            if (var->m_unk04 == 3) {
                return;
            }
            var->RemoveFromCollisionArray(pArr);
            unsigned int next = m_unk18 + 1;
            m_unk18 = next;
            var = (next < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (var != 0);
    }
}

// DRAFT: 0x001905D0 BuildCollisionArray__9PMeshNodeFP6PArrayUi
// note: 14 words differ; assert compare now matches. Remaining: set-to-1 is addiu (ours) vs daddiu (orig), early return jumps to a shared exit in the original (ours duplicates it in the delay slot), and branch offsets at 0x8C/0xA4. Tried break for shared exit (worse).
int PMeshNode::BuildCollisionArray(PArray *pArr, unsigned int flag) {
    int result = 0;
    if (m_unk104 != 0) {
        if (pArr->size <= pArr->count) {
            CdsAssert__FPciPc("PMeshNode.cpp", 0x202, "pArray->GetSize() > pArray->GetCount()");
        }
        pArr->Add(this);
        m_unk100 = (short)flag;
        result = 1;
    }
    m_unk18 = 0;
    PMeshNode *var = (m_unk14 != 0) ? m_unk1C[0] : 0;
    if (var != 0) {
        do {
            if (var->m_unk04 == 3) {
                return result;
            }
            if (var->BuildCollisionArray(pArr, flag) != 0) {
                result = 1;
            }
            unsigned int next = m_unk18 + 1;
            m_unk18 = next;
            var = (next < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (var != 0);
    }
    return result;
}

// DRAFT: 0x001906F0 LoadCollision__9PMeshNodeFP8PPakFile
// note: 33 words differ; mask/tag constant in a0/v1 not v3/a1, tbase in a1 not t0, `or` store value duplicated into the bnez delay slot (orig computes it after sync+nop), count-- hoisted above sw. Tried a local tag constant, table store order, and hoisting the store (all 33).
void PMeshNode::LoadCollision(PPakFile *pPak) {
    unsigned int size;
    if (((PCDFile *)pPak)->Read(&size, 4) == 4) {
        int *block = (int *)__nwa__FUi(size);
        if (block == 0) {
            CdsAssert__FPciPc("PMeshNode.cpp", 0x1E0, "p");
        }
        if (size != (unsigned int)((PCDFile *)pPak)->Read(block, size)) {
            __dla__FPv(block);
            return;
        }
        m_unk104 = (void *)((unsigned int)block | 0x30000000);
        m_unk103 = 1;
        int *table = (int *)((char *)block + 0xC);
        int count = block[2];
        int *entry = (int *)((char *)block + (((count + 6) & ~3) * 4));
        unsigned int tbase = ((unsigned int)entry + (count << 5)) | 0x20000000;
        while (count != 0) {
            int v = entry[0];
            if (!(v & 0x20000000)) {
                entry[0] = tbase + v * 16;
                entry[1] = tbase + entry[1] * 16;
                entry[2] = tbase + entry[2] * 16;
                asm { sync }
            }
            *table++ = (int)entry | 0x20000000;
            count--;
            entry += 8;
        }
        FlushCache(0, 0x20000000, table, count);
    }
}

// One 0x18-byte entry of a PMeshNodeAnimDataTable: key, anim, then a PArray at +8.
struct AnimTableEntry {
    unsigned int key;
    PAnim *anim;
    char arr[0x10];
};

// DRAFT: 0x00190DC0 RecurseAttachAnim__9PMeshNodeFP22PMeshNodeAnimDataTable
// note: 76 words differ; the frame is 0x80 not 0x90 and the original keeps this in s6, entries in s7, pAnimDataTable in s0. Tried a do-while, a for loop over entries[i], and a for loop with an offset.
int PMeshNode::RecurseAttachAnim(PMeshNodeAnimDataTable *pAnimDataTable) {
    if (pAnimDataTable == 0) {
        CdsAssert__FPciPc("PMeshNode.cpp", 0x50, "pAnimDataTable");
    }
    ((PMNode *)this)->RecurseDetachAnim();
    AnimTableEntry *entries = (AnimTableEntry *)pAnimDataTable->m_unk0C;
    if (entries == 0) {
        CdsAssert__FPciPc("PMeshNode.cpp", 0x56, "apAnimTable");
    }
    unsigned int count = pAnimDataTable->m_unk08;
    unsigned int off = 0;
    for (unsigned int i = 0; i < count; i++, off += 0x18) {
        AnimTableEntry *e = (AnimTableEntry *)((char *)entries + off);
        PMNode *found = ((PMNode *)this)->Find(e->key);
        if (found != 0) {
            found->AttachAnim(e->anim, true);
            found->AddFxTriggers((PArray *)e->arr, true);
            short animTime = e->anim->m_unk8;
            if (m_unk108 < animTime) {
                m_unk108 = animTime;
            }
        }
        m_unk108 -= 1;
    }
    return 1;
}

// FUNCTION: 0x00190F00 __dt__9PMeshNodeFv
PMeshNode::~PMeshNode() {
    m_unk00 = __vt__9PMeshNode;
    DetachAllLights();
    if (m_unk103) {
        __dla__FPv(m_unk104);
        m_unk104 = 0;
        m_unk103 = 0;
    }
    __dt__6PArrayFv(&m_unk130, -1);
    __dt__6PMNodeFv(this, 0);
}

// DRAFT: 0x00190F90 __ct__9PMeshNodeFR9PMeshNode
// note: 51 words differ; original spills this to 0x28/0x2C and keeps other in s0 (ours keeps this in s0, other in s1); spill needs PArray-with-dtor members, header uses char arrays. Not fixed.
PMeshNode::PMeshNode(PMeshNode &other) {
    *(void **)this = __vt__9PResource;
    m_unk04 = 0;
    *(void **)this = __vt__6PMNode;
    __ct__6PArrayFv(&m_unk14);
    sceVu0UnitMatrix(&m_unk40[0][0]);
    __ct__6PArrayFv(&m_unkD8);
    ((PMNode *)this)->InitMembers();
    *(void **)this = __vt__9PMeshNode;
    __ct__6PArrayFv(&m_unk130);
    InitMembers();
    ((PMNode *)this)->CopyMNode(*(PMNode *)&other, true);
    m_unk104 = other.m_unk104;
    *(u_long128 *)m_unk110 = *(u_long128 *)other.m_unk110;
    *(u_long128 *)m_unk120 = *(u_long128 *)other.m_unk120;
}

// DRAFT: 0x00191070 __ct__9PMeshNodeFQ29PResource11eResObjType
// note: 40 words differ; m2c draft; base-class vtable stores and PResource/PMNode ctor sequence not matched (PArray ctor/member layout as in copy ctor).
PMeshNode::PMeshNode(PResource::eResObjType eType) {
    *(void **)this = __vt__9PResource;
    m_unk04 = 0;
    *(void **)this = __vt__6PMNode;
    __ct__6PArrayFv(&m_unk14);
    sceVu0UnitMatrix(&m_unk40[0][0]);
    __ct__6PArrayFv(&m_unkD8);
    ((PMNode *)this)->InitMembers();
    *(void **)this = __vt__9PMeshNode;
    __ct__6PArrayFv(&m_unk130);
    InitMembers();
    m_unk04 = (int)eType;
}

// FUNCTION: 0x00191120 InitMembers__9PMeshNodeFv
void PMeshNode::InitMembers() {
    m_unk103 = 0;
    m_unk104 = 0;
    m_unk100 = 0;
    m_unk108 = 0;
    *(u_long128 *)m_unk110 = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)m_unk120 = *(u_long128 *)&gUnitMatrix[12];
    m_unk04 = 1;
    m_unk102 = 1;
}
