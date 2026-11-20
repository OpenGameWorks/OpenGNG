// FLAGS: -str readonly
#include "PDynamicBuffer.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);

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

// FUNCTION: 0x001D5C80 WriteDmaCntTag__14PDynamicBufferFUiUiUi
int PDynamicBuffer::WriteDmaCntTag(unsigned int nQwCount, unsigned int nWord8, unsigned int nWordC) {
    int nRet = m_uCurOffset;
    PDynamicBufferTag *pTag = (PDynamicBufferTag *)Allocate(1);
    pTag->nTag = (long long)(unsigned int)nQwCount | 0x10000000;
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

// DRAFT: 0x001D5DF0 Open__14PDynamicBufferFv
// note: 2 words differ: the original materializes (size != 0) with sltu then xori 1; ours folds to xor/sltiu. Tried !(size), (size!=0)==1, !(!size), local bool != 0 ==1 (6 words each).
int PDynamicBuffer::Open() {
    int bZero = (m_uCurSize == 0);
    if (bZero == 0) {
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
