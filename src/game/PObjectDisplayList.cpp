// FLAGS: -str readonly
#include "types.h"
#include "PObjectDisplayList.h"

#include "PArray.h"
#include "PDynamicBuffer.h"

// TODO(header): foreign declarations
class PShader {
public:
    void *m_unk0;
    char _pad004[0x4];
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
    int Render(int nFlags, bool *pFlags, bool bFlag);
};

class PDisplayList {
public:
    void EndMesh();
};

class PMNodeChildList {
public:
    int m_unk0;             // 0x00 child count
    int m_unk4;             // 0x04 current index
    PMNode **m_unk8;        // 0x08 child array
};

class PMNode {
public:
    PMNode *m_unk0;         // 0x000
    int m_unk4;             // 0x004
    int m_unk8;             // 0x008 ghost data offset
    int m_unkC;             // 0x00C dma count tag
    PMesh *m_unk10;         // 0x010
    PMNodeChildList m_apoChildList;  // 0x014
    char _pad020[0xB0];
    int m_unkD0;            // 0x0D0
};

class MemoryManager {
public:
    void DeAllocateAligned(void *pMem);
    void *AllocateAligned(int nSize, unsigned int nAlign);
    char _pad000[0x38C];    // MemMgr is 908 bytes
};

class PFragment {
public:
    void *m_unk0;           // 0x00
    unsigned int m_unk4;    // 0x04
    unsigned short m_unk8;  // 0x08
    char _pad00A[0xE];
    int m_unk18;            // 0x18 matched against PShader::m_unkC
    char _pad01C[0x74];     // entry size 0x90
};

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void UploadTextures__15PTextureManagerFPiiP12PDisplayList(void *pThis, int *pTextures, int nCount, void *pDisplayList);
extern "C" void *GetTexEnv__15PTextureManagerFi(void *pThis, int nHandle);
extern "C" void AddVifDmaPacket__12PDisplayListFP1i(void *pThis, void *pPacket, int nNumQW);
extern "C" void SetVu1Microcode__12PDisplayListFPv(void *pThis, void *pData);
extern MemoryManager MemMgr;
extern PGfxEngine gGfxEng;
extern PDynamicBuffer gPDynamicBuffer;
extern float gUnitMatrix[16];
extern "C" void QwordCopy__FP1P1Ui(u_long128 *, u_long128 *, unsigned int);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void __dl__FPv(void *);
extern "C" void *__nw__FUi(unsigned int nSize);

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PObjectDisplayList.cpp", line, #cond))

// DRAFT: 0x001D3B80 CreateDisplayList__18PObjectDisplayListFv
// note: compiles, 225 words differ: frame 0x49C vs 0x4C4 size, loop s-register allocation and i*4/i*0x10 strength reduction differ; 6 variants tried
int PObjectDisplayList::CreateDisplayList() {
    PMNode *info;
    PShader *shader;
    PFragment *apFragment;
    PMNode *apNodeInfo;
    PMesh *apMesh;
    PMesh *mesh;
    PMNode *e;
    char *slot;
    int i;
    int j;
    int k;
    int m;
    unsigned int count;

    gPDynamicBuffer.Open();
    if (m_unk8 != 0) {
        gPDynamicBuffer.WriteDmaCntTag(((PMNode *)m_unk8)->m_unk4 * 5, 0x10000000, 0);
        ((PMNode *)m_unk8)->m_unk8 = gPDynamicBuffer.WriteGhostData(((PMNode *)m_unk8)->m_unk4 * 5);
        gPDynamicBuffer.WriteMatrix((PMat4 *)gUnitMatrix, 0x336);
        ((PMNode *)m_unk8)->m_unkC = gPDynamicBuffer.WriteDmaCntTag(0, 0, 0);
        for (i = 0; i < m_unk20; i++) {
            shader = m_apoShaders[i];
            if (shader != 0) {
                gPDynamicBuffer.WriteShader(shader, (bool *)m_unk1E0, (int *)((char *)m_unk8 + i * 0x10 + 0x10), true);
                for (j = 0; j < (int)(((((PMesh *)((PMNode *)m_unk8)->m_unkD0)->m_unk4 - ((PMesh *)((PMNode *)m_unk8)->m_unkD0)->m_unk8)) & 0xFFFF); j++) {
                    mesh = (PMesh *)((PMNode *)m_unk8)->m_unkD0;
                    apFragment = (j < mesh->m_unk4) ? (PFragment *)((char *)mesh->m_unk0 + j * 0x90) : 0;
                    CDS_ASSERT(0x2F7, apFragment);
                    if (apFragment->m_unk18 == shader->m_unkC) {
                        gPDynamicBuffer.WriteDmaRefTag(apFragment->m_unk0, apFragment->m_unk4 >> 4, false, 0x11000000, 0);
                        m_unk1C += apFragment->m_unk8;
                    }
                }
            }
        }
    }
    if ((&m_unkC)->m_unk0 != 0) {
        for (k = 0; k < m_unk20; k++) {
            shader = m_apoShaders[k];
            if (shader != 0) {
                gPDynamicBuffer.WriteShader(shader, (bool *)m_unk1E0, (int *)((char *)this + 0x24 + k * 0x10), false);
                count = (&m_unkC)->m_unk0;
                for (m = 0; m < (int)count; m++) {
                    e = (m < (int)count) ? (PMNode *)(&m_unkC)->m_unk8[m] : 0;
                    apNodeInfo = e;
                    CDS_ASSERT(0x316, apNodeInfo);
                    apMesh = e->m_unk0->m_unk10;
                    CDS_ASSERT(0x31A, apMesh);
                    slot = (char *)e + k * 4;
                    *(int *)(slot + 4) = -1;
                    *(int *)(slot + 0x34) = -1;
                    for (j = 0; j < (int)((apMesh->m_unk4 - apMesh->m_unk8) & 0xFFFF); j++) {
                        apFragment = (j < (int)apMesh->m_unk4) ? (PFragment *)((char *)apMesh->m_unk0 + j * 0x90) : 0;
                        CDS_ASSERT(0x323, apFragment);
                        if (apFragment->m_unk18 == shader->m_unkC) {
                            *(int *)(slot + 4) = gPDynamicBuffer.WriteMatrix((PMat4 *)gUnitMatrix, 0x336);
                            *(int *)(slot + 0x34) = gPDynamicBuffer.WriteDmaCntTag(0, 0, 0);
                            gPDynamicBuffer.WriteDmaRefTag(apFragment->m_unk0, apFragment->m_unk4 >> 4, false, 0x11000000, 0);
                            m_unk1C += apFragment->m_unk8;
                        }
                    }
                }
            }
        }
    }
    m_unk4 = gPDynamicBuffer.m_uCurSize;
    m_unk0 = MemMgr.AllocateAligned(m_unk4 << 4, 0x80);
    CDS_ASSERT(0x341, m_unk0);
    QwordCopy__FP1P1Ui((u_long128 *)m_unk0, gPDynamicBuffer.m_pBuffer, m_unk4);
    gPDynamicBuffer.Close();
    m_unk1E5 = 1;
}

// FUNCTION: 0x1D4050 Destroy__18PObjectDisplayListFv
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
    m_unkC.m_unk4 = 0;
    for (pChild = (PMNode *)(m_unkC.m_unk0 != 0 ? m_unkC.m_unk8[0] : 0); pChild != 0;
         pChild = (PMNode *)(++m_unkC.m_unk4 < m_unkC.m_unk0 ? m_unkC.m_unk8[m_unkC.m_unk4] : 0)) {
        __dl__FPv(pChild);
    }
    if (m_unkC.m_unk8 != 0) {
        m_unkC.m_unk0 = 0;
        m_unkC.m_unk4 = 0;
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

// FUNCTION: 0x1D4160 IsTextureUnique__18PObjectDisplayListFi
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
// note: 22 differing words; guard is `i < nCount` (sltu+beqz form), element select pre-zeroed (`pElem = 0; if (...)`). Left: pElem in a0 in the then-arm, original uses v1 with a b/addu delay slot; ternary, inverted if, unsigned decls gave no gain.
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
    if (i < nCount) {
        off = 0;
        do {
            pElem = 0;
            if (i < pMesh->m_unk4) {
                pElem = (char *)pMesh->m_unk0 + off;
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

// DRAFT: 0x1D4350 FindUniqueShaders__18PObjectDisplayListFP6PArray
// note: 63 words differ; element-base if/else lays out zero in beqz slot, original falls through then-path with b over else; IsShaderUnique call order at 0x9C-0xB4 differs. Tried ternary, 0<nCount guard, inverted if/else (65).
void PObjectDisplayList::FindUniqueShaders(PArray *pArray) {
    PMNode *pNode;
    unsigned int nCount;
    unsigned int i;
    PMesh *pMesh;
    PShader *pShader;
    int off;
    char *pElem;

    pArray->m_unk4 = 0;
    pNode = (pArray->m_unk0 != 0) ? (PMNode *)pArray->m_unk8[0] : 0;
    while (pNode != 0) {
        pMesh = pNode->m_unk10;
        if (pMesh != 0) {
            nCount = (pMesh->m_unk4 - pMesh->m_unk8) & 0xFFFF;
            i = 0;
            if (i < nCount) {
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
                            CdsAssert("PObjectDisplayList.cpp", 0x269, "miNumShaders < MAX_SHADERS");
                        }
                        m_apoShaders[m_unk20] = pShader;
                        m_unk20 += 1;
                    }
                    i += 1;
                    off += 0x90;
                } while (i < nCount);
            }
        }
        pArray->m_unk4 += 1;
        pNode = (pArray->m_unk4 < pArray->m_unk0) ? (PMNode *)pArray->m_unk8[pArray->m_unk4] : 0;
    }
}

// DRAFT: 0x1D44D0 FindUniqueShaders__18PObjectDisplayListFP6PMNode
// note: 97 words differ; pNode guard and i < nCount form match, but element-base if/else puts zero in beqz slot (0x68), nCount guard at 0x4C; tried 16-bit nCount (107), no-break flag loop (105), unsigned nFlag (97), pElem=0 pre-init (98).
void PObjectDisplayList::FindUniqueShaders(PMNode *pNode) {
    unsigned int nCount;
    unsigned int i;
    PMesh *pMesh;
    PShader *pShader;
    int off;
    char *pElem;
    int nFlag;
    unsigned int j;
    PMNodeChildList *pChildList;
    PMNode *pChild;

    if (pNode != 0) {
        pMesh = pNode->m_unk10;
        if (pMesh != 0) {
            nCount = (pMesh->m_unk4 - pMesh->m_unk8) & 0xFFFF;
            i = 0;
            if (i < nCount) {
                off = 0;
                do {
                    if (i < pMesh->m_unk4) {
                        pElem = (char *)pMesh->m_unk0 + off;
                    } else {
                        pElem = 0;
                    }
                    pShader = (PShader *)(pElem + 0xC);
                    if (pShader != 0 && IsShaderUnique(pShader)) {
                        nFlag = 0;
                        j = 0;
                        while (j < pShader->m_unk8) {
                            if (m_unk1E0[j] != 0) {
                                nFlag = 1;
                                break;
                            }
                            j += 1;
                        }
                        if (nFlag != 0) {
                            if (m_unk20 >= 0xC) {
                                CdsAssert("PObjectDisplayList.cpp", 0x23A, "miNumShaders < MAX_SHADERS");
                            }
                            m_apoShaders[m_unk20] = pShader;
                            m_unk20 += 1;
                        }
                    }
                    i += 1;
                    off += 0x90;
                } while (i < nCount);
            }
        }

        pChildList = &pNode->m_apoChildList;
        if (pChildList == 0) {
            CdsAssert("PObjectDisplayList.cpp", 0x249, "apoChildList");
        }
        pChildList->m_unk4 = 0;
        pChild = (pChildList->m_unk0 != 0) ? (PMNode *)pChildList->m_unk8[0] : 0;
        while (pChild != 0) {
            FindUniqueShaders(pChild);
            pChildList->m_unk4 += 1;
            pChild = (pChildList->m_unk4 < pChildList->m_unk0) ? (PMNode *)pChildList->m_unk8[pChildList->m_unk4] : 0;
        }
    }
}

// DRAFT: 0x1D46C0 FindUniqueTextures__18PObjectDisplayListFv
// note: 62 differing words; declaration orders (4 permutations: 62-67) and the outer-loop form did not reduce it. Remaining diffs: outer/inner branch layout, off/i update order, CdsAssert argument setup.
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

// FUNCTION: 0x1D47D0 GetNumSharedBones__18PObjectDisplayListFP6PMNodePi
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
    pChild = (pList->m_unk0 != 0) ? pList->m_unk8[0] : 0;
    while (pChild != 0) {
        GetNumSharedBones(pChild, pCount);
        {
            int nIndex = pList->m_unk4 + 1;
            pList->m_unk4 = nIndex;
            pChild = ((unsigned int)nIndex < (unsigned int)pList->m_unk0) ? pList->m_unk8[pList->m_unk4] : 0;
        }
    }
}

// FUNCTION: 0x1D48B0 WriteBoneMatrices__18PObjectDisplayListFP6PMNodePi
void PObjectDisplayList::WriteBoneMatrices(PMNode *pNode, int *pCount) {
    PMNodeChildList *pList;
    PMNode *pChild;

    int nBone = pNode->m_unkD0;

    if (nBone >= 0) {
        char *pDst = (char *)m_unk0 + (*(int *)((char *)m_unk8 + 8) * 0x10) + (*pCount * 0x50);
        *(int *)(pDst + 0x0) = 0;
        *(int *)(pDst + 0x4) = 0;
        *(int *)(pDst + 0x8) = 0;
        *(int *)(pDst + 0xC) = ((nBone * 4) + 0x296) | 0x6C040000;
        *(u_long128 *)(pDst + 0x10) = *(u_long128 *)((char *)pNode + 0x40);
        *(u_long128 *)(pDst + 0x20) = *(u_long128 *)((char *)pNode + 0x50);
        *(u_long128 *)(pDst + 0x30) = *(u_long128 *)((char *)pNode + 0x60);
        *(u_long128 *)(pDst + 0x40) = *(u_long128 *)((char *)pNode + 0x70);
        *pCount += 1;
    }
    pList = &pNode->m_apoChildList;
    if (pList == 0) {
        CdsAssert("PObjectDisplayList.cpp", 0x1EC, "apoChildList");
    }
    pList->m_unk4 = 0;
    pChild = (pList->m_unk0 != 0) ? pList->m_unk8[0] : 0;
    if (pChild != 0) {
        do {
            WriteBoneMatrices(pChild, pCount);
            {
                int nIndex = pList->m_unk4 + 1;
                pList->m_unk4 = nIndex;
                pChild = ((unsigned int)nIndex < (unsigned int)pList->m_unk0) ? pList->m_unk8[pList->m_unk4] : 0;
            }
        } while (pChild != 0);
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

// FUNCTION: 0x1D4AF0 SetupNodeInfo__18PObjectDisplayListFP6PMNode
void PObjectDisplayList::SetupNodeInfo(PMNode *pNode) {
    void *pInfo;
    PMesh *pMesh;
    PMNodeChildList *pList;
    PMNode *pChild;

    if (pNode != 0) {
        pMesh = pNode->m_unk10;
        if (pMesh != 0) {
            pInfo = __nw__FUi(0x64);
            if (pInfo == 0) {
                CdsAssert("PObjectDisplayList.cpp", 0x1A2, "apNodeInfo");
            }
            memset(pInfo, 0, 4);
            (&m_unkC)->Add(pInfo);
            *(PMNode **)pInfo = pNode;
            m_unk1E4 |= pMesh->m_unk8 > 0;
        }
        pList = &pNode->m_apoChildList;
        if (pList == 0) {
            CdsAssert("PObjectDisplayList.cpp", 0x1AD, "apoChildList");
        }
        pList->m_unk4 = 0;
        pChild = 0;
        if (pList->m_unk0 != 0) {
            pChild = pList->m_unk8[0];
        }
        if (pChild != 0) {
            do {
                SetupNodeInfo(pChild);
                {
                    int nIndex = pList->m_unk4 + 1;
                    pList->m_unk4 = nIndex;
                    pChild = ((unsigned int)nIndex < (unsigned int)pList->m_unk0) ? pList->m_unk8[pList->m_unk4] : 0;
                }
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x1D4C30 SetupNodeInfo__18PObjectDisplayListFP6PArray
void PObjectDisplayList::SetupNodeInfo(PArray *pArray) {
    PMNodeChildList *pList;
    void *pInfo;
    PMesh *pMesh;
    PMNode *pNode;

    if (pArray == 0) {
        CdsAssert("PObjectDisplayList.cpp", 0x184, "poNodes");
    }
    pList = (PMNodeChildList *)pArray;
    pList->m_unk4 = 0;
    pNode = (pList->m_unk0 != 0) ? pList->m_unk8[0] : 0;
    if (pNode != 0) {
        do {
            pMesh = pNode->m_unk10;
            if (pMesh != 0) {
                pInfo = __nw__FUi(0x64);
                if (pInfo == 0) {
                    CdsAssert("PObjectDisplayList.cpp", 0x18D, "apNodeInfo");
                }
                memset(pInfo, 0, 4);
                (&m_unkC)->Add(pInfo);
                *(PMNode **)pInfo = pNode;
                m_unk1E4 |= pMesh->m_unk8 > 0;
            }
            {
                int nIndex = pList->m_unk4 + 1;
                pList->m_unk4 = nIndex;
                pNode = ((unsigned int)nIndex < (unsigned int)pList->m_unk0) ? pList->m_unk8[pList->m_unk4] : 0;
            }
        } while (pNode != 0);
    }
}

// DRAFT: 0x1D4D60 RenderBlendedFragments__18PObjectDisplayListF13eBoxIntersect
// note: 28 words differ, all saved-register allocation (original this=s4, eBox=s3, index=s2, offset=s1); tried i-first (35), reversed decls (35), cached count (91)
int PObjectDisplayList::RenderBlendedFragments(eBoxIntersect eBox) {
    int nTotal;
    PMesh *pMesh;
    PMNode *pNode;
    void *pInfo;
    unsigned int i;

    nTotal = 0;
    pNode = (PMNode *)m_unk8;
    if (pNode != 0) {
        pMesh = (PMesh *)pNode->m_unkD0;
        if (pMesh != 0) {
            if (pMesh->m_unk8 != 0) {
                gGfxEng.BeginSharedMesh(eBox, pNode->m_unk0);
                nTotal += pMesh->Render(0x80, (bool *)m_unk1E0, true);
                *(unsigned char *)((char *)&gGfxEng + 0x158E24) = 0;
                *(int *)((char *)&gGfxEng + 0x16D400) = 0;
            }
        }
    }
    for (i = 0; i < (&m_unkC)->m_unk0; i++) {
        pInfo = (i < (&m_unkC)->m_unk0) ? (&m_unkC)->m_unk8[i] : 0;
        if (pInfo == 0) {
            CdsAssert("PObjectDisplayList.cpp", 0x172, "apNodeInfo");
        }
        pNode = *(PMNode **)pInfo;
        pMesh = pNode->m_unk10;
        if (pMesh != 0 && pMesh->m_unk8 != 0) {
            gGfxEng.SetWorldMatrix((PMat4 *)((char *)pNode + 0x40));
            gGfxEng.BeginMesh(eBox);
            nTotal += pMesh->Render(0x80, (bool *)m_unk1E0, true);
            (*(PDisplayList **)0x45B300)->EndMesh();
        }
    }
    return nTotal;
}

// DRAFT: 0x001D4ED0 Render__18PObjectDisplayListF13eBoxIntersect
// note: 318 words best; frame 0xE0 vs 0xC0, shared epilogue vs split returns, cache store placement (inside-if 334, outside 318), pass copy scheduling not compared
int PObjectDisplayList::Render(eBoxIntersect eBox) {
    int nTotal;
    void *pTexEnv;
    void *pMicro;
    unsigned int nOffset;
    int nBones;
    int fp;
    int s4;
    int i;
    PShader *pShader;
    char *pRec;
    char *pSrc;
    char *pElem;
    char *pInfo;
    char *pNode;
    char *pDst;
    int nIdx;

    nTotal = m_unk1C;
    pTexEnv = 0;
    if (m_unk1E5 == 0) {
        return 0;
    }
    nOffset = 0;
    pMicro = gGfxEng.ComputeMicrocodeOffset(eBox, nOffset);
    if (pMicro != gGfxEng.m_unk158E1C) {
        SetVu1Microcode__12PDisplayListFPv(gGfxEng.m_unk154C80, pMicro);
    }
    gGfxEng.m_unk158E1C = pMicro;
    if (gGfxEng.m_unk16D408 != 0) {
        UploadTextures__15PTextureManagerFPiiP12PDisplayList((void *)gGfxEng.m_unk154C90, &gGfxEng.m_unk16D408, 1, gGfxEng.m_unk154C80);
    } else {
        UploadTextures__15PTextureManagerFPiiP12PDisplayList((void *)gGfxEng.m_unk154C90, m_unk118, m_unk114, gGfxEng.m_unk154C80);
    }
    if (gGfxEng.m_unk16D408 > 0) {
        pTexEnv = GetTexEnv__15PTextureManagerFi((void *)gGfxEng.m_unk154C90, gGfxEng.m_unk16D408);
        if (pTexEnv == 0) {
            CdsAssert("PObjectDisplayList.cpp", 0xB8, "apOverrideTexEnv");
        }
    }
    if (m_unk8 != 0) {
        for (fp = 0; fp < m_unk20; fp++) {
            pShader = (PShader *)m_apoShaders[fp];
            if (pShader != 0) {
                for (s4 = 0; s4 < pShader->m_unk8; s4++) {
                    if (m_unk1E0[s4] != 0) {
                        if (pTexEnv == 0) {
                            pRec = (s4 < pShader->m_unk8) ? (char *)pShader->m_unk0 + s4 * 0xA0 : 0;
                            if (pRec == 0) {
                                CdsAssert("PObjectDisplayList.cpp", 0xD5, "apMaterial");
                            }
                            pSrc = *(char **)(pRec + 4);
                        } else {
                            pSrc = (char *)pTexEnv;
                        }
                        nIdx = *(int *)((char *)m_unk8 + (fp << 4) + (s4 << 2) + 0x10);
                        pDst = (char *)m_unk0 + (nIdx << 4);
                        *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x00);
                        *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x10);
                        *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x20);
                        *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x30);
                        *(u_long128 *)(pDst + 0x40) = *(u_long128 *)(pSrc + 0x40);
                        *(u_long128 *)(pDst + 0x50) = *(u_long128 *)(pSrc + 0x50);
                        pElem = *(char **)((char *)pShader + (s4 << 2) + 0x30);
                        if (pElem != 0) {
                            *(unsigned char *)(pElem + 2) = 0;
                            pSrc = pElem + 0x20;
                        } else {
                            pSrc = 0;
                        }
                        if (pSrc != 0) {
                            pDst = (char *)m_unk0 + ((nIdx + 14) << 4);
                            *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x00);
                            *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x10);
                            *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x20);
                            *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x30);
                        }
                    }
                }
            }
        }
        nBones = 0;
        WriteBoneMatrices(((PMNode *)m_unk8)->m_unk0, &nBones);
        *(unsigned int *)((char *)m_unk0 + (((PMNode *)m_unk8)->m_unkC << 4) + 0xC) = nOffset | 0x14000000;
    }
    for (fp = 0; fp < m_unk20; fp++) {
        pShader = (PShader *)m_apoShaders[fp];
        if (pShader != 0) {
            for (s4 = 0; s4 < pShader->m_unk8; s4++) {
                if (m_unk1E0[s4] != 0) {
                    if (pTexEnv == 0) {
                        pRec = (s4 < pShader->m_unk8) ? (char *)pShader->m_unk0 + s4 * 0xA0 : 0;
                        if (pRec == 0) {
                            CdsAssert("PObjectDisplayList.cpp", 0x110, "apMaterial");
                        }
                        pSrc = *(char **)(pRec + 4);
                    } else {
                        pSrc = (char *)pTexEnv;
                    }
                    nIdx = *(int *)((char *)this + (fp << 4) + (s4 << 2) + 0x24);
                    pDst = (char *)m_unk0 + (nIdx << 4);
                    *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x00);
                    *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x10);
                    *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x20);
                    *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x30);
                    *(u_long128 *)(pDst + 0x40) = *(u_long128 *)(pSrc + 0x40);
                    *(u_long128 *)(pDst + 0x50) = *(u_long128 *)(pSrc + 0x50);
                    pElem = *(char **)((char *)pShader + (s4 << 2) + 0x30);
                    if (pElem != 0) {
                        *(unsigned char *)(pElem + 2) = 0;
                        pSrc = pElem + 0x20;
                    } else {
                        pSrc = 0;
                    }
                    if (pSrc != 0) {
                        pDst = (char *)m_unk0 + ((nIdx + 14) << 4);
                        *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x00);
                        *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x10);
                        *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x20);
                        *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x30);
                    }
                }
            }
            for (i = 0; i < (&m_unkC)->m_unk0; i++) {
                pInfo = (i < (&m_unkC)->m_unk0) ? (char *)(&m_unkC)->m_unk8[i] : 0;
                if (pInfo == 0) {
                    CdsAssert("PObjectDisplayList.cpp", 0x130, "apNodeInfo");
                }
                pNode = *(char **)pInfo;
                nIdx = *(int *)(pInfo + (fp << 2) + 4);
                if (nIdx != -1) {
                    pDst = (char *)m_unk0 + (nIdx << 4);
                    *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pNode + 0x40);
                    *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pNode + 0x50);
                    *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pNode + 0x60);
                    *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pNode + 0x70);
                    nIdx = *(int *)(pInfo + (fp << 2) + 0x34);
                    *(unsigned int *)((char *)m_unk0 + (nIdx << 4) + 0xC) = nOffset | 0x14000000;
                }
            }
        }
    }
    AddVifDmaPacket__12PDisplayListFP1i(gGfxEng.m_unk154C80, m_unk0, m_unk4);
    if ((unsigned char)m_unk1E4 != 0) {
        nTotal += RenderBlendedFragments(eBox);
    }
    return nTotal;
}

// FUNCTION: 0x1D54A0 Create__18PObjectDisplayListFP6PMNodePb
int PObjectDisplayList::Create(PMNode *pNode, bool *pFlags) {
    PMNodeChildList *pList;
    PMNode *pChild;
    PMesh *pMesh;
    int i;
    int nOffset;

    if (m_unk1E5 != 0) {
        Destroy();
    }
    memcpy(m_unk1E0, pFlags, 4);
    FindUniqueShaders(pNode);
    for (i = 0, nOffset = 0; i < m_unk20; nOffset += 4, i++) {
        if (((PShader *)*(PShader **)((char *)this + nOffset + 0xE4))->m_unkC == 0) {
            return 0;
        }
    }
    FindUniqueTextures();
    if (m_unk20 == 0) {
        return 0;
    }
    if (pNode->m_unk4 == 2) {
        pMesh = pNode->m_unk10;
        pNode->m_apoChildList.m_unk4 = 0;
        pList = &pNode->m_apoChildList;
        if (pList->m_unk0 != 0) {
            pChild = pList->m_unk8[0];
        } else {
            pChild = 0;
        }
        if (pMesh != 0 && pChild != 0) {
            SetupSharedMeshInfo(pMesh, pChild);
        }
        SetupNodeInfo(pChild);
    } else {
        SetupNodeInfo(pNode);
    }
    return CreateDisplayList();
}

// FUNCTION: 0x1D55E0 Create__18PObjectDisplayListFP6PArrayP6PMNodeP5PMeshPb
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
}

// FUNCTION: 0x1D5760 __ct__18PObjectDisplayListFv
PObjectDisplayList::PObjectDisplayList() {
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
