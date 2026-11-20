// FLAGS: -str readonly
#include "PSpacePartitionTree.h"
#include "PMeshFragment.h"
#include "PGfxEngine.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void Render__7PShaderFibPb(void *pThis, int nArg, bool bFlag, bool *pbOut);
extern "C" void *__dt__19PSpacePartitionNodeFv(void *pThis, short nFlag);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" int TestNodeWithFrustrum__19PSpacePartitionNodeFP9PFrustrumPP19PSpacePartitionNodeRUi(void *pThis, PFrustrum *pFrustrum, PSpacePartitionNode **ppNode, unsigned int *pCount);
extern u_long128 gCameraPos;
extern PGfxEngine gGfxEng;
extern "C" int Load__19PSpacePartitionNodeFP8PPakFileP6PArrayP6PArray16ePsx2FileVersion(PSpacePartitionNode *pThis, PPakFile *pFile, PArray *pArr1, PArray *pArr2, ePsx2FileVersion nVersion);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pDst, unsigned int nSize);
extern "C" int CountNodes__19PSpacePartitionNodeFv(PSpacePartitionNode *pThis);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" PSpacePartitionNode *__ct__19PSpacePartitionNodeFv(PSpacePartitionNode *pThis);

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("PSpacePartitionTree.cpp", line, #cond))

// DRAFT: 0x00198FF0 RenderMesh__19PSpacePartitionTreeFP5PMeshb
// note: 203 words differ; original sets s5=this, s4=pMesh, s3=bFlag with frame 0x80 and saves s0..s6, ours maps this to s4, pMesh to s3, bFlag to s2; tried CDS_ASSERT ternary, byte-offset pFrag, removing pShader, for-loop nFrag, hoisted nGroups, group offsets relative to pGroup, and hoisting nFrag/pFrag/pShader to function scope (all 203)
void PSpacePartitionTree::RenderMesh(PMesh *pMesh, bool bFlag) {
    int nFrag;
    PMeshFragment *pFrag;
    char *pShader;
    CDS_ASSERT(0x1DD, pMesh);
    for (nFrag = 0; nFrag < (int)(unsigned short)((unsigned short)pMesh->m_unk4 - pMesh->m_unk8); nFrag++) {
        pFrag = ((unsigned int)nFrag < pMesh->m_unk4) ? &pMesh->m_unk0[nFrag] : 0;
        pShader = (char *)pFrag + 0xC;
        CDS_ASSERT(0x1E3, pShader);
        bool bNotFound = true;
        if (*(int *)(pShader + 0x40) == 5) {
            gGfxEng.DrawFragment(pFrag, false, 0x80, 0);
        } else {
            int nGroup;
            for (nGroup = 0; nGroup < m_unk12898; nGroup++) {
                char *pGroup = (char *)this + nGroup * 0x30C;
                if (*(int *)(pShader + 0xC) == *(int *)(*(char **)(pGroup + 0x418) + 0xC)) {
                    if (bFlag) {
                        int *pCount = (int *)(pGroup + 0x71C);
                        ((PMeshFragment **)(pGroup + 0x41C))[*pCount] = pFrag;
                        (*pCount)++;
                        ((*pCount < 0x60) ? (void)0 : CdsAssert("PSpacePartitionTree.cpp", 0x1FC, "apGroup->iNumClipFragments < MAX_FRAGMENTS_PER_GROUP"));
                    } else {
                        int *pCount = (int *)(pGroup + 0x720);
                        ((PMeshFragment **)(pGroup + 0x59C))[*pCount] = pFrag;
                        (*pCount)++;
                        ((*pCount < 0x60) ? (void)0 : CdsAssert("PSpacePartitionTree.cpp", 0x202, "apGroup->iNumNoClipFragments < MAX_FRAGMENTS_PER_GROUP"));
                    }
                    bNotFound = false;
                    break;
                }
            }
            if (bNotFound) {
                char *pGroup = (char *)this + m_unk12898 * 0x30C;
                *(char **)(pGroup + 0x418) = pShader;
                if (bFlag) {
                    int *pCount = (int *)(pGroup + 0x71C);
                    ((PMeshFragment **)(pGroup + 0x41C))[*pCount] = pFrag;
                    (*pCount)++;
                    ((*pCount < 0x60) ? (void)0 : CdsAssert("PSpacePartitionTree.cpp", 0x214, "apGroup->iNumClipFragments < MAX_FRAGMENTS_PER_GROUP"));
                } else {
                    int *pCount = (int *)(pGroup + 0x720);
                    ((PMeshFragment **)(pGroup + 0x59C))[*pCount] = pFrag;
                    (*pCount)++;
                    ((*pCount < 0x60) ? (void)0 : CdsAssert("PSpacePartitionTree.cpp", 0x21A, "apGroup->iNumNoClipFragments < MAX_FRAGMENTS_PER_GROUP"));
                }
                m_unk12898++;
                ((m_unk12898 < 0x60) ? (void)0 : CdsAssert("PSpacePartitionTree.cpp", 0x21D, "miNumShaderGroups < MAX_SHADER_GROUPS"));
            }
        }
    }
}

// FUNCTION: 0x00199330 RenderShaderGroups__19PSpacePartitionTreeFb
void PSpacePartitionTree::RenderShaderGroups(bool bFlag) {
    if (bFlag) {
        int nIndex = 0;
        char *pSlot;
        int nFrag;
        int nByte;
        int nOffset = 0;
        while (nIndex < m_unk12898) {
            pSlot = (char *)this + nOffset + 0x418;
            if (*(int *)(pSlot + 0x304) != 0) {
                Render__7PShaderFibPb(*(void **)pSlot, 0x80, false, 0);
                nFrag = 0;
                nByte = 0;
                while (nFrag < *(int *)(pSlot + 0x304)) {
                    PMeshFragment *pFrag = *(PMeshFragment **)(pSlot + nByte + 4);
                    CDS_ASSERT(0x1BA, pFrag);
                    gGfxEng.m_unk154C80->DrawVertices(pFrag->m_unk0, pFrag->m_unk4);
                    nByte += 4;
                    nFrag++;
                }
            }
            nOffset += 0x30C;
            nIndex++;
        }
    } else {
        int nIndex = 0;
        char *pSlot;
        int nFrag;
        int nByte;
        int nOffset = 0;
        while (nIndex < m_unk12898) {
            pSlot = (char *)this + nOffset + 0x418;
            if (*(int *)(pSlot + 0x308) != 0) {
                Render__7PShaderFibPb(*(void **)pSlot, 0x80, false, 0);
                nFrag = 0;
                nByte = 0;
                while (nFrag < *(int *)(pSlot + 0x308)) {
                    PMeshFragment *pFrag = *(PMeshFragment **)(pSlot + nByte + 0x184);
                    CDS_ASSERT(0x1D1, pFrag);
                    gGfxEng.m_unk154C80->DrawVertices(pFrag->m_unk0, pFrag->m_unk4);
                    nByte += 4;
                    nFrag++;
                }
            }
            nOffset += 0x30C;
            nIndex++;
        }
    }
}

// FUNCTION: 0x00199500 ResetShaderGroups__19PSpacePartitionTreeFv
void PSpacePartitionTree::ResetShaderGroups() {
    int nIndex = 0;
    int nOffset = 0;
    while (nIndex < m_unk12898) {
        char *pGroup = (char *)this + nOffset;
        nIndex++;
        *(int *)(pGroup + 0x418) = 0;
        nOffset += 0x30C;
        *(int *)(pGroup + 0x71C) = 0;
        *(int *)(pGroup + 0x720) = 0;
    }
    m_unk12898 = 0;
}

// DRAFT: 0x00199910 CullToFrustrum__19PSpacePartitionTreeFP9PFrustrumPf
// note: 70 words differ; the asm move of nStart/nEnd shifts register allocation (pFrustrum/pOut move to s3/s2, extra save, 0x50 frame), branch over the m_unk0 block differs, float tail schedule differs, gCameraPos store offset differs (possibly relocation artifact)
void PSpacePartitionTree::CullToFrustrum(PFrustrum *pFrustrum, float *pOut) {
    unsigned int nStart;
    if (pFrustrum == 0) {
        CdsAssert("PSpacePartitionTree.cpp", 0x79, "poFrustrum");
    }
    if (m_unk0 != 0) {
        *(u_long128 *)&gCameraPos = *(u_long128 *)pOut;
        asm {
            .word 0x4011C801
            move nStart, $s1
        }
        m_unk404 = 0;
        m_unk410 = TestNodeWithFrustrum__19PSpacePartitionNodeFP9PFrustrumPP19PSpacePartitionNodeRUi(m_unk0, pFrustrum, &m_unk4, &m_unk404);
        unsigned int nEnd;
        asm {
            .word 0x4003C801
            move nEnd, $v1
        }
        int nDelta = nEnd - nStart;
        float fCount;
        if (nDelta >= 0) {
            fCount = (float)nDelta;
        } else {
            fCount = 2.0f * (float)(((unsigned int)nDelta >> 1) | (nDelta & 1));
        }
        float fTime = (3.333f * fCount) / 1000.0f;
        m_unk414 = fTime;
        m_unk414 = fTime / 1000.0f;
    }
}

// FUNCTION: 0x00199A00 Load__19PSpacePartitionTreeFP8PPakFileP6PArrayP6PArray16ePsx2FileVersion
int PSpacePartitionTree::Load(PPakFile *pFile, PArray *pArr1, PArray *pArr2, ePsx2FileVersion nVersion) {
    int nTag;
    if (pFile == 0) {
        CdsAssert("PSpacePartitionTree.cpp", 0x51, "poFile");
    }
    nTag = 0;
    if (Read__7PCDFileFPvUi((void *)pFile, &nTag, 4) != 4) {
        return 0;
    }
    if (nTag != 0xE) {
        return 0;
    }
    PSpacePartitionNode *pNode = (PSpacePartitionNode *)__nw__FUi(0x40);
    if (pNode != 0) {
        pNode = __ct__19PSpacePartitionNodeFv(pNode);
    }
    m_unk0 = pNode;
    if (m_unk0 == 0) {
        return 0;
    }
    if (Load__19PSpacePartitionNodeFP8PPakFileP6PArrayP6PArray16ePsx2FileVersion(m_unk0, pFile, pArr1, pArr2, nVersion) == 0) {
        __dt__19PSpacePartitionNodeFv(m_unk0, 1);
        m_unk0 = 0;
        return 0;
    }
    m_unk408 = CountNodes__19PSpacePartitionNodeFv(m_unk0);
    return 1;
}

// FUNCTION: 0x00199B20 __dt__19PSpacePartitionTreeFv
PSpacePartitionTree::~PSpacePartitionTree() {
    if (m_unk0) {
        __dt__19PSpacePartitionNodeFv(m_unk0, 1);
    }
}

// FUNCTION: 0x00199B80 __ct__19PSpacePartitionTreeFv
PSpacePartitionTree::PSpacePartitionTree() {
    m_unk0 = 0;
    m_unk408 = 0;
    m_unk404 = 0;
    m_unk414 = 0;
    m_unk40C = 0x3A98;
    m_unk410 = 0;
    m_unk12898 = 0;
    memset(_pad418, 0, 0x12480);
}
