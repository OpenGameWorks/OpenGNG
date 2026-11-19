// FLAGS: -str readonly
#include "types.h"
#include "PObjectDisplayList.h"

// TODO(header): foreign declarations
class PArray {
public:
    PArray();
    ~PArray();
};

class PShader {
public:
    char _pad000[0x8];
    unsigned int m_unk8;    // 0x008 texture count
    int m_unkC;             // 0x00C
    char _pad010[0x10];
    int m_unk20[0x10];      // 0x020 texture ids
};

class PMesh {
public:
    void *m_unk0;           // 0x00 element base
    unsigned int m_unk4;    // 0x04 element count
    unsigned short m_unk8;  // 0x08
};

class PMNodeChildList {
public:
    int m_unk0;             // 0x00 child count
    int m_unk4;             // 0x04 current index
    PMNode **m_unk8;        // 0x08 child array
};

class PMNode {
public:
    char _pad000[0x14];
    PMNodeChildList m_apoChildList;  // 0x014
    char _pad020[0xB0];
    int m_unkD0;            // 0x0D0
};

class MemoryManager {
public:
    void DeAllocateAligned(void *pMem);
    char _pad000[0x38C];    // MemMgr is 908 bytes
};

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern MemoryManager MemMgr;
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void __dl__FPv(void *);
extern "C" void *__nw__FUi(unsigned int nSize);

// DRAFT: 0x1D4050 Destroy__18PObjectDisplayListFv
// note: 50 differing lines; ours saves s1 as this with a 0x30 frame, original uses s0 only with 0x20 and a do-while loop; do-while (68) and raw-offset (70) variants were worse.
void PObjectDisplayList::Destroy() {
    PMNode *pChild;

    if (m_unk0 != 0) {
        MemMgr.DeAllocateAligned(m_unk0);
        m_unk0 = 0;
    }
    if (m_unk8 != 0) {
        __dl__FPv(m_unk8);
        m_unk8 = 0;
    }
    ((PMNodeChildList *)m_unkC)->m_unk4 = 0;
    pChild = 0;
    if (((PMNodeChildList *)m_unkC)->m_unk0 != 0) {
        pChild = ((PMNodeChildList *)m_unkC)->m_unk8[0];
    }
    while (pChild != 0) {
        __dl__FPv(pChild);
        ((PMNodeChildList *)m_unkC)->m_unk4 += 1;
        pChild = 0;
        if ((unsigned int)((PMNodeChildList *)m_unkC)->m_unk4 < (unsigned int)((PMNodeChildList *)m_unkC)->m_unk0) {
            pChild = ((PMNodeChildList *)m_unkC)->m_unk8[((PMNodeChildList *)m_unkC)->m_unk4];
        }
    }
    if (((PMNodeChildList *)m_unkC)->m_unk8 != 0) {
        ((PMNodeChildList *)m_unkC)->m_unk0 = 0;
        ((PMNodeChildList *)m_unkC)->m_unk4 = 0;
    }
    m_unk20 = 0;
    m_unk114 = 0;
    memset(m_unk24, 0, 0xC0);
    memset(m_apoShaders, 0, 0x30);
    memset(m_unk118, 0, 0xC0);
    m_unk1E5 = 0;
    m_unk1E4 = 0;
    m_unk1C = 0;
}

// DRAFT: 0x1D4160 IsTextureUnique__18PObjectDisplayListFi
// note: 8 words differ; the original's extra nop at 0x2C (target of the loop-entry branch) is missing. Tried off+=4 in the header, i++ at body end, i+=1: no gain.
int PObjectDisplayList::IsTextureUnique(int nTexture) {
    int i;
    int off;
    int t;
    i = 0;
    off = 0;
    for (; i < m_unk114; i++) {
        t = *(int *)((char *)this + off + 0x118);
        if (t == nTexture) {
            return 0;
        }
        off += 4;
    }
    return 1;
}

// FUNCTION: 0x1D41B0 IsShaderUnique__18PObjectDisplayListFP7PShader
int PObjectDisplayList::IsShaderUnique(PShader *pShader) {
    int i;
    int off;
    if (pShader == 0) {
        CdsAssert("PObjectDisplayList.cpp", 0x291, "pShader");
    }
    for (i = 0, off = 0; i < m_unk20; off += 4, i++) {
        if (pShader->m_unkC == (*(PShader **)((char *)this + off + 0xE4))->m_unkC) {
            return 0;
        }
    }
    return 1;
}

// DRAFT: 0x1D4240 FindUniqueShaders__18PObjectDisplayListFP5PMesh
// note: 50 differing lines; the original guards with sltu (nCount != 0) and uses a b/addu-delay element select and an extra entry branch; unsigned short nCount, 0<nCount, swapped arms gave no gain.
void PObjectDisplayList::FindUniqueShaders(PMesh *pMesh) {
    unsigned int nCount;
    unsigned int i;
    PShader *pShader;
    int off;
    char *pElem;

    if (pMesh == 0) {
        return;
    }
    nCount = (pMesh->m_unk4 - pMesh->m_unk8) & 0xFFFF;
    i = 0;
    if (0 < nCount) {
        off = 0;
        do {
            if (i < pMesh->m_unk4) {
                pElem = (char *)pMesh->m_unk0 + off;
            } else {
                pElem = 0;
            }
            pShader = (PShader *)(pElem + 0xC);
            if (pShader != 0 && IsShaderUnique(pShader)) {
                if (m_unk20 >= 0xC) {
                    CdsAssert("PObjectDisplayList.cpp", 0x286, "miNumShaders < MAX_SHADERS");
                }
                m_apoShaders[m_unk20] = pShader;
                m_unk20 += 1;
            }
            i += 1;
            off += 0x90;
        } while (i < nCount);
    }
}

// DRAFT: 0x1D46C0 FindUniqueTextures__18PObjectDisplayListFv
// note: 54 differing lines; register allocation matches after declaration reorder and unsigned flag array; remaining diffs are outer/inner branch layout, off/i update order, and CdsAssert argument setup (inner for-loop and outer for-loop with off += 4 also 54).
void PObjectDisplayList::FindUniqueTextures() {
    int i;
    PShader *pShader;
    int nTexture;
    int off;
    unsigned int j;

    off = 0;
    i = 0;
    while (i < m_unk20) {
        pShader = *(PShader **)((char *)this + off + 0xE4);
        j = 0;
        if (pShader != 0) {
            while (j < pShader->m_unk8) {
                nTexture = pShader->m_unk20[j];
                if (nTexture != 0 && IsTextureUnique(nTexture) != 0 && m_unk1E0[j] != 0) {
                    m_unk118[m_unk114] = nTexture;
                    m_unk114 += 1;
                    if ((unsigned int)m_unk114 >= 0xC1) {
                        CdsAssert("PObjectDisplayList.cpp", 0x217, "miNumTextures <= sizeof(mhTextures)");
                    }
                }
                j += 1;
            }
        }
        off += 4;
        i += 1;
    }
}

// DRAFT: 0x1D47D0 GetNumSharedBones__18PObjectDisplayListFP6PMNodePi
// note: first attempt; child-list loop shape still differs.
void PObjectDisplayList::GetNumSharedBones(PMNode *pNode, int *pCount) {
    PMNodeChildList *pList;
    PMNode *pChild;

    if (pNode->m_unkD0 >= 0) {
        *pCount += 1;
    }
    pList = &pNode->m_apoChildList;
    if (pList == 0) {
        CdsAssert("PObjectDisplayList.cpp", 0x1FF, "apoChildList");
    }
    pList->m_unk4 = 0;
    pChild = 0;
    if (pList->m_unk0 != 0) {
        pChild = pList->m_unk8[0];
    }
    while (pChild != 0) {
        GetNumSharedBones(pChild, pCount);
        pList->m_unk4 += 1;
        pChild = 0;
        if ((unsigned int)pList->m_unk4 < (unsigned int)pList->m_unk0) {
            pChild = pList->m_unk8[pList->m_unk4];
        }
    }
}

// FUNCTION: 0x1D49F0 SetupSharedMeshInfo__18PObjectDisplayListFP5PMeshP6PMNode
void PObjectDisplayList::SetupSharedMeshInfo(PMesh *pMesh, PMNode *pNode) {
    if (pMesh == 0) {
        CdsAssert("PObjectDisplayList.cpp", 0x1BB, "poSharedMesh");
    }
    if (pNode == 0) {
        CdsAssert("PObjectDisplayList.cpp", 0x1BC, "poRootBone");
    }
    if ((pMesh->m_unk4 - pMesh->m_unk8) & 0xFFFF) {
        m_unk8 = __nw__FUi(0xD4);
        if (m_unk8 == 0) {
            CdsAssert("PObjectDisplayList.cpp", 0x1C1, "mpSharedMeshInfo");
        }
        memset(m_unk8, 0, 0xD4);
        *(PMNode **)m_unk8 = pNode;
        *(PMesh **)((char *)m_unk8 + 0xD0) = pMesh;
        GetNumSharedBones(pNode, (int *)((char *)m_unk8 + 4));
    }
    m_unk1E4 |= pMesh->m_unk8 > 0;
}

// DRAFT: 0x1D55E0 Create__18PObjectDisplayListFP6PArrayP6PMNodeP5PMeshPb
// note: 33 differing lines; the early return 0 in the shader loop jumps to the ld ra epilogue instead of sharing the ld-in-delay exit (lq s4 target), and the loop tail is missing the nop before slt. Tried while, for-loop, break+post-check (43), all in this file.
int PObjectDisplayList::Create(PArray *pArray, PMNode *pNode, PMesh *pMesh, bool *pFlags) {
    int i;
    int off;
    PShader *pShader;

    if (m_unk1E5 != 0) {
        Destroy();
    }
    memcpy(m_unk1E0, pFlags, 4);
    FindUniqueShaders(pArray);
    if (pMesh != 0) {
        FindUniqueShaders(pMesh);
    }
    for (i = 0, off = 0; i < m_unk20; off += 4, i++) {
        pShader = *(PShader **)((char *)this + off + 0xE4);
        if (pShader->m_unkC == 0) {
            return 0;
        }
    }
    FindUniqueTextures();
    if (m_unk20 == 0) {
        m_unk1E5 = 0;
        return 0;
    }
    if (pMesh != 0 && pNode != 0) {
        SetupSharedMeshInfo(pMesh, pNode);
    }
    SetupNodeInfo(pArray);
    return CreateDisplayList();
}

// FUNCTION: 0x1D5700 __dt__18PObjectDisplayListFv
PObjectDisplayList::~PObjectDisplayList() {
    Destroy();
    ((PArray *)m_unkC)->~PArray();
}

// DRAFT: 0x1D5760 __ct__18PObjectDisplayListFv
// note: 39 differing lines; first attempt, memset/PArray ctor sequence not yet aligned with the original.
PObjectDisplayList::PObjectDisplayList() {
    __ct__6PArrayFv(m_unkC);
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk114 = 0;
    memset(m_unk24, 0, 0xC0);
    memset(m_apoShaders, 0, 0x30);
    memset(m_unk118, 0, 0xC0);
    m_unk1E4 = 0;
    m_unk1E5 = 0;
}
