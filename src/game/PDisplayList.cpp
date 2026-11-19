// FLAGS: -sdatathreshold 0
#include "types.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern "C" void __ct__16PTextureDmaChainFv(void *pThis);
extern "C" void __dt__16PTextureDmaChainFv(void *pThis, short nFlag);
extern "C" void Reset__16PTextureDmaChainFv(void *pThis);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" int printf(const char *fmt, ...);
void ExceptionCleanup();
void DisplayExceptionMessage(char *pMsg, bool bFatal, bool bReboot);
void QwordCopy(u_long128 *pDst, u_long128 *pSrc, unsigned int nQwords);

// FUNCTION: 0x180400 DeAllocEntries__12PDisplayListFi
void PDisplayList::DeAllocEntries(int nCount) {
    m_unkA3340 -= nCount;
}

// DRAFT: 0x180420 AllocEntries__12PDisplayListFi
// note: 9 words differ with -sdatathreshold 0; original reloads m_unkA3340 for the += (mwcc reuses the compare-time value in v0); tried assign form (28 words), shift form (9), swapped compare (10)
int PDisplayList::AllocEntries(int nCount) {
    int nResult = 0;
    if (m_unkA3340 + nCount < 0x8000) {
        nResult = (int)((char *)this + m_unkA3340 * 16 + 0x40) | 0x20000000;
        m_unkA3340 += nCount;
    } else {
        printf("\n*** Display List Full!! ***\n");
        ExceptionCleanup();
        DisplayExceptionMessage("Critical Error : Display List Full", true, false);
    }
    return nResult;
}

// FUNCTION: 0x1804C0 AllocParticles__12PDisplayListFii
void *PDisplayList::AllocParticles(int nCount, int nSize) {
    int nBytes = nCount * nSize;
    nBytes = nBytes + nBytes % 4;
    if (m_unkA3344 + nBytes >= 0x2328) {
        printf("\nParticle pool is full!!", nBytes);
        return 0;
    }
    int nOld = m_unkA3344;
    m_unkA3344 += nBytes;
    return (char *)this + nOld * 16 + 0x80080;
}

// DRAFT: 0x180960 EndMatrixList__12PDisplayListFv
// note: 39 lines differ; first m_unkA334C load uses lui v1/ori/addu/lw 0(v1) where original uses lui at/addu at/lw 0x334C(at), shifting the rest by one word; 64-bit arithmetic matches; tried void* member, !ptr test, local copy (void* and int), = int local (41 lines)
void PDisplayList::EndMatrixList() {
    if (m_unkA334C == 0) {
        CdsAssert("PDisplayList.cpp", 0x871, "mpMatrixListDmaTag");
    }
    int nCount = m_unkA3350;
    *(long long *)m_unkA334C = ((long long)nCount * 4 + nCount) | 0x10000000;
    ((unsigned int *)m_unkA334C)[2] = 0x10000000;
    ((unsigned int *)m_unkA334C)[3] = 0;
    asm {
        sync
    }
    m_unkA334C = 0;
}

// FUNCTION: 0x180B20 BeginMatrixList__12PDisplayListFv
void PDisplayList::BeginMatrixList() {
    m_unkA334C = AllocEntries(1);
    if (m_unkA334C == 0) {
        CdsAssert("PDisplayList.cpp",0x844, "0");
    }
    m_unkA3350 = 0;
}

// FUNCTION: 0x181300 SetTexSyncPacket__12PDisplayListFv
void PDisplayList::SetTexSyncPacket() {
    int nPacket = AllocEntries(2);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp",0x775, "0");
    }
    *(long long *)nPacket = 0x10000001LL;
    ((unsigned int *)nPacket)[2] = 0x13000000;
    ((unsigned int *)nPacket)[3] = 0;
    ((unsigned int *)nPacket)[4] = 0;
    ((unsigned int *)nPacket)[5] = 0;
    ((unsigned int *)nPacket)[6] = 0;
    ((unsigned int *)nPacket)[7] = 0x80000000;
    asm {
        sync
    }
}

// FUNCTION: 0x183380 BeginFxLoop__12PDisplayListFUi
void PDisplayList::BeginFxLoop(unsigned int nTag) {
    if (m_unkA3348 != 2) {
        CdsAssert("PDisplayList.cpp", 0x21F, "meVuMemMap == VU_FX_PIPELINE_MEMMAP");
    }
    int nPacket = AllocEntries(1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x224, "0");
    }
    *(long long *)nPacket = 0x10000000LL;
    ((unsigned int *)nPacket)[2] = 0x11000000;
    ((unsigned int *)nPacket)[3] = nTag | 0x14000000;
    asm {
        sync
    }
}

// FUNCTION: 0x183440 SetVertexData__12PDisplayListFPA4_fii
void PDisplayList::SetVertexData(float (*pVerts)[4], int nCount, int nFlags) {
    int nPacket = AllocEntries(nCount + 1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x207, "0");
    }
    *(long long *)nPacket = (long long)nCount | 0x10000000LL;
    ((unsigned int *)nPacket)[2] = 0;
    ((unsigned int *)nPacket)[3] = nFlags | 0x8000 | (nCount << 16) | 0x6C000000;
    QwordCopy((u_long128 *)(nPacket + 0x10), (u_long128 *)pVerts, nCount);
    asm {
        sync
    }
}

// FUNCTION: 0x183790 AddVifPacket__12PDisplayListFP1iUiUi
void PDisplayList::AddVifPacket(u_long128 *pTag, int nCount, unsigned int nCode0, unsigned int nCode1) {
    int nPacket = AllocEntries(1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x192, "0");
    }
    *(long long *)nPacket = ((unsigned long long)(unsigned int)pTag << 32) | 0x30000000ULL | (long long)nCount;
    ((unsigned int *)nPacket)[2] = nCode0;
    ((unsigned int *)nPacket)[3] = nCode1;
    asm {
        sync
    }
}

// FUNCTION: 0x183840 AddVifDmaPacket__12PDisplayListFP1i
void PDisplayList::AddVifDmaPacket(u_long128 *pPacket, int nNumQW) {
    if (pPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x17C, "pPacket");
    }
    if (nNumQW == 0) {
        CdsAssert("PDisplayList.cpp", 0x17D, "iNumQW");
    }
    int nDst = AllocEntries(nNumQW);
    if (nDst == 0) {
        CdsAssert("PDisplayList.cpp", 0x182, "0");
    }
    QwordCopy((u_long128 *)nDst, pPacket, nNumQW);
    asm {
        sync
    }
}

// FUNCTION: 0x183900 BeginMesh__12PDisplayListFUi
void PDisplayList::BeginMesh(unsigned int nTag) {
    int nPacket = AllocEntries(1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp",0x15B, "0");
    }
    *(long long *)nPacket = 0x10000000LL;
    ((unsigned int *)nPacket)[2] = 0;
    ((unsigned int *)nPacket)[3] = nTag | 0x14000000;
    asm {
        sync
    }
}

// FUNCTION: 0x183FC0 SetVifCodes__12PDisplayListFUiUi
void PDisplayList::SetVifCodes(unsigned int nCode0, unsigned int nCode1) {
    int nPacket = AllocEntries(1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp",0xCD, "0");
    }
    *(long long *)nPacket = 0x10000000LL;
    ((unsigned int *)nPacket)[2] = nCode0;
    ((unsigned int *)nPacket)[3] = nCode1;
    asm {
        sync
    }
}

// FUNCTION: 0x184120 Reset__12PDisplayListFv
void PDisplayList::Reset() {
    Reset__16PTextureDmaChainFv(m_unkA3380);
    m_unkA3340 = 0;
    m_unkA3344 = 0;
    m_unkA334C = 0;
    m_unkA3350 = 0;
}

// FUNCTION: 0x184570 __dt__12PDisplayListFv
PDisplayList::~PDisplayList() {
    __dt__16PTextureDmaChainFv(m_unkA3380, -1);
}

// FUNCTION: 0x1845D0 __ct__12PDisplayListFv
PDisplayList::PDisplayList() {
    __ct__16PTextureDmaChainFv(m_unkA3380);
    m_unkA3340 = 0;
    m_unkA3344 = 0;
    m_unkA334C = 0;
    m_unkA3350 = 0;
}
