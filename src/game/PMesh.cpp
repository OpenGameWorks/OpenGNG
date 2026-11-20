// FLAGS: -str readonly
#include "types.h"
#include "PMesh.h"

// TODO(header): foreign declarations
extern "C" void __dt__13PMeshFragmentFv(void);
extern "C" void __destroy_new_array(void *pArray, void *pDtor);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void PBoundBoxToBoundBox__FPA2_A4_fPA2_A4_f(float (*pSrc)[2][4], float (*pDst)[2][4]);
extern "C" void MakePBoundBox__FPfPfPA2_A4_f(float *pMin, float *pMax, float (*pBox)[2][4]);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *__construct_new_array(void *pArray, void *pCtor, void *pDtor, unsigned int nSize, unsigned int nCount);
extern "C" void __ct__13PMeshFragmentFv(void);
extern "C" int Load__13PMeshFragmentFP8PPakFileP6PArray16ePsx2FileVersionb(void *pThis, PPakFile *pPakFile, PArray *pTextures, ePsx2FileVersion eVersion, bool bFlag);

class PShader {
public:
    void SetSTAnimOptions(bool bFlag);
    void Animate(float fDelta, bool bFlag);
};

class PDisplayList {
public:
    void DrawVertices(void *pvData, int iSize);
};

// gGfxEng is a PGfxEngine object; the original reads its first word as the display list pointer.
extern char gGfxEng[1504384];

// DRAFT: 0x0018F590 SetSTAnimFlag__5PMeshFv
// note: original is 0x58 bytes with a bottom-tested loop and a join nop before jr; ours is 0x50. Tried while+return and for+break (9 words).
void PMesh::SetSTAnimFlag() {
    unsigned int nIndex;
    int nOffset;

    m_unkC = 0;
    nIndex = 0;
    nOffset = 0;
    while (nIndex < m_unk4) {
        if (*(unsigned int *)((char *)m_unk0 + nOffset + 0x10) & 1) {
            m_unkC = 1;
            return;
        }
        nOffset += 0x90;
        nIndex++;
    }
}

// FUNCTION: 0x0018F5F0 SetSTAnimOptions__5PMeshFb
void PMesh::SetSTAnimOptions(bool bFlag) {
    unsigned int nIndex;
    int nOffset;

    nIndex = 0;
    nOffset = 0;
    while (nIndex < m_unk4) {
        ((PShader *)((char *)m_unk0 + nOffset + 0xC))->SetSTAnimOptions(bFlag);
        nOffset += 0x90;
        nIndex++;
    }
}

// DRAFT: 0x0018F670 ComputeBoundingBox__5PMeshFv
// note: 13 words differ. Pointer locals (pMin/pMax/pTemp) cut 31 to 13. Still differs: loop prologue register assignment (original j in a2, aMax in v1, aTemp in a1, aMin in a0), and the zero-compare at 0x11C/0x120 loads into f1 where ours loads f0. Tried: int/unsigned j, swapped zero-compare operands, reordered pointer assignments (no change).
void PMesh::ComputeBoundingBox() {
    float aTemp[2][4];
    float aMin[4];
    float aMax[4];
    unsigned int nIndex;
    int nOffset;
    unsigned int j;
    float *pMin;
    float *pMax;
    float *pTemp;

    if (m_unk0 == 0) {
        CdsAssert__FPciPc("PMesh.cpp", 0x13D, "mpMeshFragments");
    }
    aMin[0] = aMin[1] = aMin[2] = 32767.0f;
    aMax[0] = aMax[1] = aMax[2] = -32767.0f;
    aMin[3] = aMax[3] = 1.0f;
    nIndex = 0;
    nOffset = 0;
    while (nIndex < m_unk4) {
        PBoundBoxToBoundBox__FPA2_A4_fPA2_A4_f((float (*)[2][4])((char *)m_unk0 + nOffset + 0x70), &aTemp);
        pMax = aMax;
        pTemp = &aTemp[0][0];
        pMin = aMin;
        for (j = 0; j < 3; j++) {
            if (pTemp[j] < pMin[j]) {
                pMin[j] = pTemp[j];
            }
            if (pTemp[4 + j] > pMax[j]) {
                pMax[j] = pTemp[4 + j];
            }
        }
        nOffset += 0x90;
        nIndex++;
    }
    MakePBoundBox__FPfPfPA2_A4_f(aMin, aMax, &m_unk10);
    if (m_unk10[1][0] == 0.0f) {
        m_unk10[1][0] = 0.5f;
    }
    if (m_unk10[1][1] == 0.0f) {
        m_unk10[1][1] = 0.5f;
    }
    if (m_unk10[1][2] == 0.0f) {
        m_unk10[1][2] = 0.5f;
    }
    m_unkE = 0x20;
    m_unkD = 1;
}

// FUNCTION: 0x0018F820 SetBoundBox__5PMeshFPA2_A4_f
void PMesh::SetBoundBox(float (*pBox)[2][4]) {
    if (pBox == 0) {
        CdsAssert__FPciPc("PMesh.cpp", 0x11F, "pBox");
    }
    *(u_long128 *)&m_unk10[0][0] = *(u_long128 *)&(*pBox)[0][0];
    *(u_long128 *)&m_unk10[1][0] = *(u_long128 *)&(*pBox)[1][0];
    m_unkD = 1;
}

// DRAFT: 0x0018F880 Load__5PMeshFP8PPakFileP6PArrayUiUi16ePsx2FileVersionb
// note: 7 words differ. nUnk is kept in s0 where the original uses s1, so nIndex/nOffset swap s0/s1. Tried local orders (nOffset-first 10, nFirst-first 7, nIndex-nOffset-nFirst 7, nOffset-nFirst-nIndex 10).
int PMesh::Load(PPakFile *pPakFile, PArray *pTextures, unsigned int nCount, unsigned int nUnk, ePsx2FileVersion eVersion, bool bFlag) {
    unsigned int nIndex;
    unsigned int nFirst;
    int nOffset;

    if (pPakFile == 0) {
        CdsAssert__FPciPc("PMesh.cpp", 0xD5, "poFile");
    }
    if (pTextures == 0) {
        CdsAssert__FPciPc("PMesh.cpp", 0xD6, "poTextureHandles");
    }
    if (nCount == 0) {
        return 1;
    }
    Destroy();
    m_unk0 = (PMeshFragment *)__construct_new_array(__nwa__FUi(nCount * 0x90 + 0x10), (void *)__ct__13PMeshFragmentFv, (void *)__dt__13PMeshFragmentFv, 0x90, nCount);
    if (m_unk0 == 0) {
        return 0;
    }
    m_unk4 = nCount;
    m_unk8 = nUnk;
    nFirst = m_unk4 - m_unk8;
    nOffset = 0;
    for (nIndex = 0; nIndex < nCount; nIndex++) {
        if (Load__13PMeshFragmentFP8PPakFileP6PArray16ePsx2FileVersionb((char *)m_unk0 + nOffset, pPakFile, pTextures, eVersion, nIndex >= nFirst) == 0) {
            Destroy();
            return 0;
        }
        m_unkA += *(unsigned short *)((char *)m_unk0 + nOffset + 8);
        nOffset += 0x90;
    }
    if (bFlag) {
        ComputeBoundingBox();
    }
    SetSTAnimFlag();
    return 1;
}

// DRAFT: 0x0018FA40 RenderAllPolys__5PMeshFv
// note: 5 words differ. Prologue maps nIndex to s2 where the original uses s0 (and the reverse at 0x6C); the a1/a2 loads at 0x7C/0x80 come in the opposite order. Tried: local orders (nSum/nIndex/nOffset), nIndex=0 inside the m_unk4 branch (28 words), and the nIndex init moved before the check (5 words, kept).
int PMesh::RenderAllPolys() {
    unsigned int nIndex;
    unsigned int nSum;
    int nOffset;

    nSum = 0;
    if (m_unk0 == 0) {
        CdsAssert__FPciPc("PMesh.cpp", 0xC0, "mpMeshFragments");
    }
    if (m_unk4 == 0) {
        CdsAssert__FPciPc("PMesh.cpp", 0xC1, "muNumFragments");
    }
    nOffset = 0;
    for (nIndex = 0; nIndex < m_unk4; nIndex++) {
        ((PDisplayList *)*(void **)gGfxEng)->DrawVertices(*(void **)((char *)m_unk0 + nOffset), *(int *)((char *)m_unk0 + nOffset + 4));
        nSum += *(unsigned short *)((char *)m_unk0 + nOffset + 8);
        nOffset += 0x90;
    }
    return nSum;
}

// FUNCTION: 0x0018FD10 AnimateShaders__5PMeshFfb
void PMesh::AnimateShaders(float fDelta, bool bFlag) {
    unsigned int nIndex;
    int nOffset;

    if (m_unkC != 0) {
        nIndex = 0;
        nOffset = 0;
        while (nIndex < m_unk4) {
            ((PShader *)((char *)m_unk0 + nOffset + 0xC))->Animate(fDelta, bFlag);
            nOffset += 0x90;
            nIndex++;
        }
    }
}

// FUNCTION: 0x0018FDA0 Destroy__5PMeshFv
void PMesh::Destroy() {
    if (m_unk0 != 0) {
        __destroy_new_array(m_unk0, (void *)__dt__13PMeshFragmentFv);
        m_unk0 = 0;
        m_unk4 = 0;
    }
    m_unkC = 0;
    m_unk8 = 0;
    m_unkE = 0;
}

// FUNCTION: 0x0018FDF0 __dt__5PMeshFv
extern "C" PMesh *__dt__5PMeshFv(PMesh *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->Destroy();
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0018FE50 __ct__5PMeshFv
PMesh::PMesh() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkA = 0;
    m_unkE = 0;
    memset(m_unk10, 0, 0x20);
    m_unkD = 0;
    m_unkC = 0;
}
