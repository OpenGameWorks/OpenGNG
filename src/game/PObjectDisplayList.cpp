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
    char _pad000[0xC];
    int m_unkC;             // 0x00C
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

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void __ct__6PArrayFv(void *pThis);

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

// DRAFT: 0x1D41B0 IsShaderUnique__18PObjectDisplayListFP7PShader
// note: first attempt; register allocation and loop form still differ.
int PObjectDisplayList::IsShaderUnique(PShader *pShader) {
    int i;
    if (pShader == 0) {
        CdsAssert("PObjectDisplayList.cpp", 0x291, "pShader");
    }
    for (i = 0; i < m_unk20; i++) {
        if (pShader->m_unkC == m_apoShaders[i]->m_unkC) {
            return 0;
        }
    }
    return 1;
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
