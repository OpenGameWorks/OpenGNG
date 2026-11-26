// FLAGS: -str readonly
#include "PDynamicBuffer.h"
#include "PShader.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern char mBuffer[0x5000];
extern char shared_vertices_start[];

struct PDynamicBufferTag {
    long long nTag;
    unsigned int nWord8;
    unsigned int nWordC;
};

// FUNCTION: 0x001D5810 Allocate__14PDynamicBufferFUi
void *PDynamicBuffer::Allocate(unsigned int nQuadwords) {
    if (m_uCurOffset + nQuadwords > 0x5000) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0x116, "(muCurOffset + uSize) <= sizeof(mBuffer)");
    }
    void *pRet = m_pBuffer + m_uCurOffset;
    m_uCurOffset += nQuadwords;
    if (m_uCurOffset > m_uCurSize) {
        m_uCurSize += nQuadwords;
    }
    return pRet;
}

// DRAFT: 0x001D58A0 WriteShader__14PDynamicBufferFP7PShaderPbPib
// note: 132 words differ: pOut is not kept in fp and pShader not in s6 (orig copies a3 to fp first); spill slots 0xD7/0xD8 vs 0xDB/0xDC. Tried: hoisting pMat/pPacket (170), nRet moved after Allocate (172), nCount=0 moved late (132, kept).
int PDynamicBuffer::WriteShader(PShader *pShader, bool *pFlag, int *pOut, bool bFlag) {
    unsigned int i;
    int nQw;
    int nCount;
    int nOffset = 0;
    int nRet = m_uCurOffset;
    unsigned int nTagOffset;
    unsigned int nHdrOffset;
    if (pShader == 0) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0xB1, "pShader");
    }
    if (pFlag == 0) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0xB2, "pbRenderPassStatus");
    }
    if (pOut == 0) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0xB3, "piTexEnvOffsets");
    }
    memset(pOut, 0, 0x10);
    nTagOffset = m_uCurOffset;
    if (Allocate(1) == 0) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0xBB, "apTag");
    }
    nHdrOffset = m_uCurOffset;
    nQw = 1;
    if (Allocate(1) == 0) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0xC0, "apHeader");
    }
    nCount = 0;
    for (i = 0; i < pShader->m_unk8; i++) {
        if (pFlag[i] != 0) {
            char *pMat;
            char *pPacket;
            nCount++;
            pMat = (i < pShader->m_unk8) ? (char *)pShader->m_unk0 + i * 0xA0 : 0;
            if (pMat == 0) {
                CdsAssert__FPciPc("PDynamicBuffer.cpp", 0xCF, "apMaterial");
            }
            nQw += 0x12;
            *(int *)((char *)pOut + nOffset) = m_uCurOffset;
            pPacket = (char *)Allocate(0x12);
            if (pPacket == 0) {
                CdsAssert__FPciPc("PDynamicBuffer.cpp", 0xDC, "apPacket");
            }
            *(u_long128 *)(pPacket + 0x60) = *(u_long128 *)(pMat + 0x10);
            *(u_long128 *)(pPacket + 0x70) = *(u_long128 *)(pMat + 0x20);
            *(u_long128 *)(pPacket + 0x80) = *(u_long128 *)(pMat + 0x30);
            *(u_long128 *)(pPacket + 0x90) = *(u_long128 *)(pMat + 0x40);
            *(u_long128 *)(pPacket + 0xA0) = *(u_long128 *)(pMat + 0x50);
            *(u_long128 *)(pPacket + 0xB0) = *(u_long128 *)(pMat + 0x60);
            *(u_long128 *)(pPacket + 0xC0) = *(u_long128 *)(pMat + 0x70);
            *(u_long128 *)(pPacket + 0xD0) = *(u_long128 *)(pMat + 0x80);
            if (nCount == 1) {
                *(int *)(pPacket + 0xC0) = 0;
                *(unsigned int *)(pPacket + 0xC4) = bFlag ? (((unsigned int)shared_vertices_start + 0x2C10) >> 3) : 0;
            }
        }
        nOffset += 4;
    }
    {
        PDynamicBufferTag *pHdr = (PDynamicBufferTag *)(m_pBuffer + nHdrOffset);
        pHdr->nTag = (long long)(unsigned int)(nCount - 1);
        pHdr->nWord8 = 0;
        pHdr->nWordC = 0;
    }
    {
        PDynamicBufferTag *pTag = (PDynamicBufferTag *)(m_pBuffer + nTagOffset);
        pTag->nTag = (long long)nQw | 0x10000000;
        pTag->nWord8 = 0x10000000;
        pTag->nWordC = (nQw << 16) | 0x6C000372;
    }
    return nRet;
}

// FUNCTION: 0x001D5B80 WriteMatrix__14PDynamicBufferFP5PMat4Ui
int PDynamicBuffer::WriteMatrix(PMat4 *pMat, unsigned int nMemOffset) {
    int nRet = m_uCurOffset + 1;
    if (pMat == 0) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0x8D, "pMat");
    }
    if (nMemOffset >= 0x400) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0x8E, "uVu1MemOffset < 1024");
    }
    u_long128 *pBlock = (u_long128 *)Allocate(5);
    if (pBlock == 0) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0x92, "apMatrix");
    }
    PDynamicBufferTag *pTag = (PDynamicBufferTag *)pBlock;
    pTag->nTag = 0x10000004;
    pTag->nWord8 = 0x10000000;
    pTag->nWordC = nMemOffset | 0x6C040000;
    u_long128 *pSrc = (u_long128 *)pMat;
    pBlock[1] = pSrc[0];
    pBlock[2] = pSrc[1];
    pBlock[3] = pSrc[2];
    pBlock[4] = pSrc[3];
    return nRet;
}

// FUNCTION: 0x001D5C80 WriteDmaCntTag__14PDynamicBufferFUiUiUi
int PDynamicBuffer::WriteDmaCntTag(unsigned int nQwCount, unsigned int nWord8, unsigned int nWordC) {
    int nRet = m_uCurOffset;
    PDynamicBufferTag *pTag = (PDynamicBufferTag *)Allocate(1);
    pTag->nTag = (long long)(unsigned int)nQwCount | 0x10000000;
    pTag->nWord8 = nWord8;
    pTag->nWordC = nWordC;
    return nRet;
}

// FUNCTION: 0x001D5CF0 WriteDmaRefTag__14PDynamicBufferFPvUibUiUi
int PDynamicBuffer::WriteDmaRefTag(void *pAddr, unsigned int nQwCount, bool bFlag, unsigned int nWord8, unsigned int nWordC) {
    int nRet = m_uCurOffset;
    PDynamicBufferTag *pTag = (PDynamicBufferTag *)Allocate(1);
    long long nHi = ((long long)(unsigned char)bFlag << 63) | ((long long)(unsigned int)pAddr << 32);
    pTag->nTag = (long long)(unsigned int)nQwCount | (nHi | 0x30000000);
    pTag->nWord8 = nWord8;
    pTag->nWordC = nWordC;
    return nRet;
}

// FUNCTION: 0x001D5D90 WriteGhostData__14PDynamicBufferFUi
int PDynamicBuffer::WriteGhostData(unsigned int nQuadwords) {
    int nRet = m_uCurOffset;
    if (Allocate(nQuadwords) == 0) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0x53, "apAddr");
    }
    return nRet;
}

// FUNCTION: 0x001D5DE0 Close__14PDynamicBufferFv
void PDynamicBuffer::Close() {
    *(int *)((char *)this + 0x4) = 0;
    *(int *)((char *)this + 0x8) = 0;
}

// FUNCTION: 0x001D5DF0 Open__14PDynamicBufferFv
int PDynamicBuffer::Open() {
    // sltu $zero,size then xori 1 is an unsigned `> 0` test negated into a bool.
    bool b = !(m_uCurSize > 0);
    if (!b) {
        CdsAssert__FPciPc("PDynamicBuffer.cpp", 0x27, "!muCurSize");
    }
    m_uCurSize = 0;
    m_uCurOffset = 0;
    return 1;
}

// FUNCTION: 0x001D5E50 __dt__14PDynamicBufferFv
PDynamicBuffer::~PDynamicBuffer() {
    Close();
}

// FUNCTION: 0x001D5EB0 __ct__14PDynamicBufferFv
PDynamicBuffer::PDynamicBuffer() {
    m_pBuffer = (u_long128 *)mBuffer;
    m_uCurSize = 0;
    m_uCurOffset = 0;
}
