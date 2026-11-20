// FLAGS: -str readonly
#include "types.h"
#include "PMeshFragment.h"

// TODO(header): foreign declarations
class PPakFile;
class PArray;

class PCDFile {
public:
    int Read(void *pBuf, unsigned int nSize);
};

class PDisplayList {
public:
    void DrawVertices(void *pvData, int iSize);
};

// gGfxEng is a PGfxEngine object; the display list pointer is its m_unk154C80 member at offset 0x154C80.
extern char gGfxEng[1504384];

extern "C" int Load__7PShaderFP8PPakFileP6PArrayb(void *pThis, PPakFile *pPakFile, PArray *pTextures, bool bFlag);
extern "C" void Render__7PShaderFibPb(void *pThis, int nArg, bool bFlag, bool *pbOut);
extern "C" void Destroy__7PShaderFv(void *pThis);
extern "C" void *__ct__7PShaderFv(void *pThis);
extern "C" void __dt__7PShaderFv(void *pThis, short nFlag);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);

// FUNCTION: 0x0018FEA0 Load__13PMeshFragmentFP8PPakFileP6PArray16ePsx2FileVersionb
int PMeshFragment::Load(PPakFile *pPakFile, PArray *pTextures, ePsx2FileVersion eVersion, bool bFlag) {
    struct Header {
        unsigned int nFlags;          // 0x00
        unsigned int nCount;          // 0x04
        unsigned int nUnk08;          // 0x08
        char _pad0C[4];
        unsigned char aBlock[0x20];   // 0x10 copied to m_unk70
        unsigned short nUnk30;        // 0x30
        char _pad32[2];
        unsigned int nUnk34;          // 0x34
        char _pad38[4];
    } header;
    void *pVertexData;
    unsigned int *pCount;

    if (pPakFile == 0) {
        CdsAssert__FPciPc("PMeshFragment.cpp", 0x67, "poFile");
    }
    if (pTextures == 0) {
        CdsAssert__FPciPc("PMeshFragment.cpp", 0x68, "poTextureHandles");
    }
    Destroy();
    if (Load__7PShaderFP8PPakFileP6PArrayb(m_unkC, pPakFile, pTextures, bFlag) == 0) {
        return 0;
    }
    if (((PCDFile *)pPakFile)->Read(&header, 0x3C) != 0x3C) {
        return 0;
    }
    pCount = &header.nCount;
    if (*pCount == 0) {
        return 0;
    }
    m_unk8 = header.nUnk30;
    m_unk64 = header.nUnk34;
    memcpy(m_unk70, header.aBlock, 0x20);
    if ((header.nFlags & 2) && header.nUnk08 != 0) {
        return 0;
    }
    pVertexData = __nwa__FUi(*pCount);
    if (pVertexData == 0) {
        return 0;
    }
    m_unkA = (unsigned short)header.nFlags;
    if (header.nFlags & 1) {
        if (((PCDFile *)pPakFile)->Read(pVertexData, *pCount) != *pCount) {
            __dla__FPv(pVertexData);
            return 0;
        }
        m_unk0 = pVertexData;
        m_unk4 = *pCount;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00190040 Render__13PMeshFragmentFbiPb
void PMeshFragment::Render(bool bFlag, int nArg, bool *pbOut) {
    if (m_unk0 == 0) {
        CdsAssert__FPciPc("PMeshFragment.cpp", 0x57, "mpvVertexData");
    }
    Render__7PShaderFibPb(m_unkC, nArg, bFlag, pbOut);
    ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->DrawVertices(m_unk0, m_unk4);
}

// FUNCTION: 0x001900D0 Destroy__13PMeshFragmentFv
void PMeshFragment::Destroy() {
    Destroy__7PShaderFv(m_unkC);
    if (m_unk0 != 0) {
        __dla__FPv(m_unk0);
        m_unk0 = 0;
    }
    m_unkA = 0;
}

// FUNCTION: 0x00190120 __dt__13PMeshFragmentFv
extern "C" PMeshFragment *__dt__13PMeshFragmentFv(PMeshFragment *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->Destroy();
        __dt__7PShaderFv(pThis->m_unkC, -1);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00190180 __ct__13PMeshFragmentFv
PMeshFragment::PMeshFragment() {
    __ct__7PShaderFv(m_unkC);
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk64 = 0;
    m_unkA = 0;
}
