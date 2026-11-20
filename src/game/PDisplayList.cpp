// FLAGS: -str readonly
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
extern "C" void FlushCache(int nMode);
void DmaWaitForCompletion(int nChannel, bool bWait);
extern "C" void sceGsSetDefClear(void *pPacket, int nW, short nCX, short nCY, short nX, short nY, int nZero0, int nZero1, int nZero2, int nZero3, unsigned int nFlags);

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

// FUNCTION: 0x180550 RenderShadowVolume__12PDisplayListFPvi
void PDisplayList::RenderShadowVolume(void *pvData, int iSize) {
    if (pvData == 0) {
        CdsAssert("PDisplayList.cpp", 0x8F8, "pvData");
    }
    if (iSize == 0) {
        CdsAssert("PDisplayList.cpp", 0x8F9, "iSize");
    }
    int nPacket = AllocEntries(1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x8FE, "0");
    }
    *(long long *)nPacket = ((unsigned long long)(unsigned int)pvData << 32) | 0x30000000ULL | (long long)(iSize >> 4);
    ((unsigned int *)nPacket)[2] = 0;
    ((unsigned int *)nPacket)[3] = 0;
    asm {
        sync
    }
}

// FUNCTION: 0x180630 BeginShadowVolume__12PDisplayListFP5PMat4PfPfPfPfPf
void PDisplayList::BeginShadowVolume(PMat4 *pMat, float *pA, float *pB, float *pC, float *pD, float *pE) {
    if (pMat == 0) {
        CdsAssert("PDisplayList.cpp", 0x8C2, "pWorldMat");
    }
    int nPacket = AllocEntries(0xD);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x8C7, "0");
    }
    *(long long *)nPacket = 0x1000000CLL;
    ((unsigned int *)nPacket)[2] = 0x11000000;
    ((unsigned int *)nPacket)[3] = 0x6C0C8000;
    *(u_long128 *)(nPacket + 0x10) = *(u_long128 *)pMat;
    *(u_long128 *)(nPacket + 0x20) = *(u_long128 *)((char *)pMat + 0x10);
    *(u_long128 *)(nPacket + 0x30) = *(u_long128 *)((char *)pMat + 0x20);
    *(u_long128 *)(nPacket + 0x40) = *(u_long128 *)((char *)pMat + 0x30);
    *(u_long128 *)(nPacket + 0x50) = *(u_long128 *)pA;
    *(u_long128 *)(nPacket + 0x60) = *(u_long128 *)pB;
    *(u_long128 *)(nPacket + 0x70) = *(u_long128 *)pC;
    *(u_long128 *)(nPacket + 0x90) = *(u_long128 *)pE;
    *(u_long128 *)(nPacket + 0x80) = *(u_long128 *)pD;
    *(long long *)(nPacket + 0xA0) = 0x4021C00000000000LL;
    *(long long *)(nPacket + 0xA8) = 0x5551LL;
    *(long long *)(nPacket + 0xB0) = 0x5022400000000000LL;
    *(long long *)(nPacket + 0xB8) = 0x55551LL;
    *(long long *)(nPacket + 0xC0) = 0x2022C00000000000LL;
    *(long long *)(nPacket + 0xC8) = 0x51LL;
    asm { sync }
}

// DRAFT: 0x1807A0 DrawLines__12PDisplayListFP9tagVuLinei
// note: DIFF 108; original frame 0x90 with s0-s7 saved, ours needs fp (0xA0); tried data pointer before alloc, batch count via ternary, index increment before tail; register map and loop-bottom layout still differ
void PDisplayList::DrawLines(struct tagVuLine *pLines, int nCount) {
    int nLeft = nCount;
    int nBatch;
    int nRem;
    int nIdx;
    if (pLines == 0) {
        CdsAssert("PDisplayList.cpp", 0x886, "pLines");
    }
    nBatch = nCount >> 4;
    if (nCount == 0) {
        CdsAssert("PDisplayList.cpp", 0x887, "iNumLines");
        nBatch = nCount >> 4;
    }
    nRem = nCount & 0xF;
    if (nCount < 0) {
        nBatch = (nCount + 0xF) >> 4;
        nRem = nCount & 0xF;
        if (nRem != 0) {
            nRem -= 0x10;
        }
    }
    if (nRem != 0) {
        nBatch += 1;
    }
    nIdx = 0;
    while (nIdx < nBatch) {
        int nNum = (nLeft < 0x10) ? nLeft : 0x10;
        u_long128 *pData = (u_long128 *)((char *)pLines + (nIdx << 10));
        nLeft -= nNum;
        int nPacket = AllocEntries(nNum * 4 + 3);
        if (nPacket == 0) {
            CdsAssert("PDisplayList.cpp", 0x89D, "0");
        }
        int nQw = nNum * 4 + 1;
        *(long long *)nPacket = (long long)(nQw | 0x10000000);
        ((unsigned int *)nPacket)[2] = 0;
        ((unsigned int *)nPacket)[3] = (nQw << 16) | 0x6C008000;
        ((int *)nPacket)[4] = nNum;
        QwordCopy((u_long128 *)(nPacket + 0x20), pData, nQw - 1);
        nIdx += 1;
        int nEnd = nPacket + 0x20 + (nQw - 1) * 0x10;
        *(long long *)nEnd = 0x10000000LL;
        ((unsigned int *)nEnd)[2] = 0;
        ((unsigned int *)nEnd)[3] = 0x17000000;
    }
    asm {
        sync
    }
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

// FUNCTION: 0x180A10 AddMatrix__12PDisplayListFP5PMat4Ui
void PDisplayList::AddMatrix(PMat4 *pMat, unsigned int nTag) {
    if (pMat == 0) {
        CdsAssert("PDisplayList.cpp", 0x851, "pMat");
    }
    if (m_unkA334C == 0) {
        CdsAssert("PDisplayList.cpp", 0x852, "mpMatrixListDmaTag");
    }
    int nPacket = AllocEntries(5);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x857, "0");
    }
    ((unsigned int *)nPacket)[0] = 0;
    ((unsigned int *)nPacket)[1] = 0;
    ((unsigned int *)nPacket)[2] = 0;
    ((unsigned int *)nPacket)[3] = nTag | 0x6C040000;
    *(u_long128 *)(nPacket + 0x10) = *(u_long128 *)pMat;
    *(u_long128 *)(nPacket + 0x20) = *(u_long128 *)((char *)pMat + 0x10);
    *(u_long128 *)(nPacket + 0x30) = *(u_long128 *)((char *)pMat + 0x20);
    *(u_long128 *)(nPacket + 0x40) = *(u_long128 *)((char *)pMat + 0x30);
    m_unkA3350 += 1;
    asm {
        sync
    }
}

// FUNCTION: 0x180B20 BeginMatrixList__12PDisplayListFv
void PDisplayList::BeginMatrixList() {
    m_unkA334C = AllocEntries(1);
    if (m_unkA334C == 0) {
        CdsAssert("PDisplayList.cpp",0x844, "0");
    }
    m_unkA3350 = 0;
}

// DRAFT: 0x180B90 ClearFrameBuffer__12PDisplayListFssssccccUi
// note: DIFF 105; ours hoists the 0x10000007 header lui into the bnez delay slot and duplicates it (original delay slot holds the assert string lui, header uses v0); also v0/v1 swapped. Tried (unsigned char) arg casts: no change.
void PDisplayList::ClearFrameBuffer(short nX, short nY, short nW, short nH, char nR, char nG, char nB, char nA, unsigned int nFlags) {
    int nPacket = AllocEntries(8);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp",0x820, "0");
    }
    *(long long *)nPacket = 0x10000007LL;
    ((unsigned int *)nPacket)[2] = 0x11000000;
    ((unsigned int *)nPacket)[3] = 0x50000007;
    short nCX = nX - nW / 2;
    short nCY = nY - nH / 2;
    sceGsSetDefClear((void *)(nPacket + 0x20), 1, nCX, nCY, nW, nH, (unsigned char)nR, (unsigned char)nG, (unsigned char)nB, (unsigned char)nA, nFlags);
    *(unsigned char *)(nPacket + 0x20) = (*(unsigned char *)(nPacket + 0x20) & 0xFE) | 1;
    *(unsigned char *)(nPacket + 0x20) = (*(unsigned char *)(nPacket + 0x20) & 0xF1) | ((0 & 7) * 2);
    *(unsigned char *)(nPacket + 0x21) = (*(unsigned char *)(nPacket + 0x21) & 0xCF) | 0x10;
    *(u_long128 *)(nPacket + 0x10) = 0;
    *(unsigned short *)(nPacket + 0x10) = (*(unsigned short *)(nPacket + 0x10) & 0x8000) | 6;
    *(unsigned char *)(nPacket + 0x11) = (*(unsigned char *)(nPacket + 0x11) & 0x7F) | 0x80;
    *(unsigned char *)(nPacket + 0x17) = (*(unsigned char *)(nPacket + 0x17) & 0x0F) | 0x10;
    *(unsigned char *)(nPacket + 0x18) = (*(unsigned char *)(nPacket + 0x18) & 0xF0) | 0x0E;
    asm {
        sync
    }
}

// DRAFT: 0x180D90 ClearZBuffer__12PDisplayListFsssUi
// note: s-register map is rotated (ours s4<-nW, s3<-nX, s2<-nY; original s4<-nX, s3<-nY, s2<-nW); tried locals before/after AllocEntries, int locals; 92 words in all
void PDisplayList::ClearZBuffer(short nX, short nY, short nW, unsigned int nFlags) {
    int nPacket = AllocEntries(8);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp",0x7FB, "0");
    }
    *(long long *)nPacket = 0x10000007LL;
    ((unsigned int *)nPacket)[2] = 0x11000000;
    ((unsigned int *)nPacket)[3] = 0x50000007;
    short nCX = 0x800 - nX / 2;
    short nCY = 0x800 - nY / 2;
    sceGsSetDefClear((void *)(nPacket + 0x20), nW, nCX, nCY, nX, nY, 0, 0, 0, 0, nFlags);
    *(unsigned char *)(nPacket + 0x20) = (*(unsigned char *)(nPacket + 0x20) & 0xFE) | 1;
    *(unsigned char *)(nPacket + 0x20) = (*(unsigned char *)(nPacket + 0x20) & 0xF1) | 0;
    *(unsigned char *)(nPacket + 0x21) = (*(unsigned char *)(nPacket + 0x21) & 0xCF) | 0x20;
    *(u_long128 *)(nPacket + 0x10) = 0;
    *(unsigned short *)(nPacket + 0x10) = (*(unsigned short *)(nPacket + 0x10) & 0x8000) | 6;
    *(unsigned char *)(nPacket + 0x11) = (*(unsigned char *)(nPacket + 0x11) & 0x7F) | 0x80;
    *(unsigned char *)(nPacket + 0x17) = (*(unsigned char *)(nPacket + 0x17) & 0x0F) | 0x10;
    *(unsigned char *)(nPacket + 0x18) = (*(unsigned char *)(nPacket + 0x18) & 0xF0) | 0x0E;
    asm {
        sync
    }
}

// FUNCTION: 0x180F50 WriteToVu1Mem__12PDisplayListFUiP1i
void PDisplayList::WriteToVu1Mem(unsigned int uVu1MemOffset, u_long128 *pData, int nQwords) {
    if (pData == 0) {
        CdsAssert("PDisplayList.cpp", 0x7DF, "pData");
    }
    if (nQwords == 0) {
        CdsAssert("PDisplayList.cpp", 0x7E0, "iNumQW");
    }
    int nPacket = AllocEntries(nQwords + 1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x7E5, "0");
    }
    *(long long *)nPacket = (long long)nQwords | 0x10000000LL;
    ((unsigned int *)nPacket)[2] = 0x11000000;
    ((unsigned int *)nPacket)[3] = uVu1MemOffset | (nQwords << 16) | 0x6C000000;
    QwordCopy((u_long128 *)(nPacket + 0x10), pData, nQwords);
    asm {
        sync
    }
}

// DRAFT: 0x181050 SendGsPacket__12PDisplayListFPvib
// note: iSize/bFlag swapped between s0/s1 (ours: iSize in s0); variants tried: bFlag != 0 (75 words), inverted if/else (60 words); baseline 23 words.
void PDisplayList::SendGsPacket(void *pvData, int iSize, bool bFlag) {
    if (pvData == 0) {
        CdsAssert("PDisplayList.cpp", 0x7B4, "pvData");
    }
    if (iSize == 0) {
        CdsAssert("PDisplayList.cpp", 0x7B5, "iSize");
    }
    int nCount = iSize >> 4;
    if (bFlag) {
        int nPacket = AllocEntries(nCount + 1);
        if (nPacket == 0) {
            CdsAssert("PDisplayList.cpp", 0x7BE, "0");
        }
        *(long long *)nPacket = (long long)nCount | 0x10000000LL;
        ((unsigned int *)nPacket)[2] = 0x11000000;
        ((unsigned int *)nPacket)[3] = nCount | 0x50000000;
        QwordCopy((u_long128 *)(nPacket + 0x10), (u_long128 *)pvData, nCount);
    } else {
        int nPacket = AllocEntries(1);
        if (nPacket == 0) {
            CdsAssert("PDisplayList.cpp", 0x7CE, "0");
        }
        *(long long *)nPacket = ((long long)(unsigned int)pvData << 32) | 0x30000000LL | (long long)nCount;
        ((unsigned int *)nPacket)[2] = 0x11000000;
        ((unsigned int *)nPacket)[3] = nCount | 0x50000000;
    }
    asm { sync }
}

// DRAFT: 0x1811B0 SetGsRegisters__12PDisplayListFP1i
// note: 37 differing lines; mask constants and lhu/sq order are scheduled differently; tried lh/lb vs lhu/lbu (39->37), hoisted masks, 64-bit temporaries (no change).
void PDisplayList::SetGsRegisters(u_long128 *pRegData, int nNumRegs) {
    if (pRegData == 0) {
        CdsAssert("PDisplayList.cpp", 0x790, "pRegData");
    }
    if (nNumRegs == 0) {
        CdsAssert("PDisplayList.cpp", 0x791, "iNumRegs");
    }
    int nPacket = AllocEntries(nNumRegs + 2);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x797, "0");
    }
    *(long long *)nPacket = ((long long)nNumRegs + 1) | 0x10000000LL;
    ((unsigned int *)nPacket)[2] = 0x11000000;
    ((unsigned int *)nPacket)[3] = (nNumRegs + 1) | 0x50000000;
    *(u_long128 *)(nPacket + 0x10) = 0;
    unsigned int uField = *(unsigned short *)(nPacket + 0x10);
    *(unsigned short *)(nPacket + 0x10) = (uField & ~0x7FFF) | (nNumRegs & 0x7FFF);
    uField = *(unsigned char *)(nPacket + 0x11);
    *(unsigned char *)(nPacket + 0x11) = (uField & ~0x80) | 0x80;
    uField = *(unsigned char *)(nPacket + 0x17);
    *(unsigned char *)(nPacket + 0x17) = (uField & ~0xF0) | 0x10;
    uField = *(unsigned char *)(nPacket + 0x18);
    *(unsigned char *)(nPacket + 0x18) = (uField & ~0xF) | 0xE;
    QwordCopy((u_long128 *)(nPacket + 0x20), pRegData, nNumRegs);
    asm {
        sync
    }
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

// DRAFT: 0x1834F0 DrawRawVertices__12PDisplayListFPA4_fPA4_fPA4_fPA4_fi
// note: 109 differing lines. Local register allocation differs (nCount s3 vs s1, nOffset s0 vs s2, nBatch s1 vs s3), the dead div/mfhi by 0x1E is absent, and the loop test uses $v0 not $at. Tried: nBatch declared before nOffset (still 109).
void PDisplayList::DrawRawVertices(float (*p0)[4], float (*p1)[4], float (*p2)[4], float (*p3)[4], int nCount) {
    int nOffset = 0;
    while (nCount >= 3) {
        int nBatch = nCount;
        if (nBatch >= 0x1E) {
            nBatch = 0x1E;
        }
        nCount -= nBatch;
        int nPacket = AllocEntries(2);
        if (nPacket == 0) {
            CdsAssert("PDisplayList.cpp", 0x1CE, "0");
        }
        *(long long *)nPacket = 0x10000001LL;
        ((unsigned int *)nPacket)[2] = 0;
        ((unsigned int *)nPacket)[3] = 0x6C018000;
        ((unsigned int *)nPacket)[4] = nBatch;
        ((unsigned int *)nPacket)[5] = 0;
        ((unsigned int *)nPacket)[6] = 0;
        ((unsigned int *)nPacket)[7] = 0;
        if (p0 != 0) {
            SetVertexData(p0 + nOffset, nBatch, 0x3D);
        }
        if (p1 != 0) {
            SetVertexData(p1 + nOffset, nBatch, 1);
        }
        if (p2 != 0) {
            SetVertexData(p2 + nOffset, nBatch, 0x1F);
        }
        if (p3 != 0) {
            SetVertexData(p3 + nOffset, nBatch, 0x5B);
        }
        int nTail = AllocEntries(1);
        *(long long *)nTail = 0x10000000LL;
        nOffset += nBatch - 2;
        ((unsigned int *)nTail)[2] = 0;
        ((unsigned int *)nTail)[3] = 0x17000000;
        nCount += 2;
    }
    asm {
        sync
    }
}

// FUNCTION: 0x1836B0 DrawVertices__12PDisplayListFPvi
void PDisplayList::DrawVertices(void *pvData, int iSize) {
    if (pvData == 0) {
        CdsAssert("PDisplayList.cpp", 0x1A1, "pvData");
    }
    if (iSize == 0) {
        CdsAssert("PDisplayList.cpp", 0x1A2, "iSize");
    }
    int nPacket = AllocEntries(1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x1A7, "0");
    }
    *(long long *)nPacket = ((unsigned long long)(unsigned int)pvData << 32) | 0x30000000ULL | (long long)(iSize >> 4);
    ((unsigned int *)nPacket)[2] = 0x11000000;
    ((unsigned int *)nPacket)[3] = 0;
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

// FUNCTION: 0x183970 SetClipMatrix__12PDisplayListFP5PMat4
void PDisplayList::SetClipMatrix(PMat4 *pMat) {
    unsigned int nSize;
    if (m_unkA3348 == 1) {
        nSize = 0x342;
    } else {
        nSize = 0x394;
    }
    if (pMat == 0) {
        CdsAssert("PDisplayList.cpp", 0x94C, "pMat");
    }
    if (nSize >= 0x400) {
        CdsAssert("PDisplayList.cpp", 0x94D, "uVu1MemOffset < 1024");
    }
    int nPacket = AllocEntries(5);
    if (nPacket != 0) {
        *(long long *)nPacket = 0x10000004LL;
        ((unsigned int *)nPacket)[2] = 0x10000000;
        ((unsigned int *)nPacket)[3] = nSize | 0x6C040000;
        *(u_long128 *)(nPacket + 0x10) = *(u_long128 *)pMat;
        *(u_long128 *)(nPacket + 0x20) = *(u_long128 *)((char *)pMat + 0x10);
        *(u_long128 *)(nPacket + 0x30) = *(u_long128 *)((char *)pMat + 0x20);
        *(u_long128 *)(nPacket + 0x40) = *(u_long128 *)((char *)pMat + 0x30);
        asm {
            sync
        }
    }
}

// FUNCTION: 0x183A60 SetScreenMatrix__12PDisplayListFP5PMat4
void PDisplayList::SetScreenMatrix(PMat4 *pMat) {
    unsigned int nSize;
    if (m_unkA3348 == 1) {
        nSize = 0x33E;
    } else {
        nSize = 0x38C;
    }
    if (pMat == 0) {
        CdsAssert("PDisplayList.cpp", 0x94C, "pMat");
    }
    if (nSize >= 0x400) {
        CdsAssert("PDisplayList.cpp", 0x94D, "uVu1MemOffset < 1024");
    }
    int nPacket = AllocEntries(5);
    if (nPacket != 0) {
        *(long long *)nPacket = 0x10000004LL;
        ((unsigned int *)nPacket)[2] = 0x10000000;
        ((unsigned int *)nPacket)[3] = nSize | 0x6C040000;
        *(u_long128 *)(nPacket + 0x10) = *(u_long128 *)pMat;
        *(u_long128 *)(nPacket + 0x20) = *(u_long128 *)((char *)pMat + 0x10);
        *(u_long128 *)(nPacket + 0x30) = *(u_long128 *)((char *)pMat + 0x20);
        *(u_long128 *)(nPacket + 0x40) = *(u_long128 *)((char *)pMat + 0x30);
        asm {
            sync
        }
    }
}

// FUNCTION: 0x183B50 SetViewMatrix__12PDisplayListFP5PMat4
void PDisplayList::SetViewMatrix(PMat4 *pMat) {
    unsigned int nSize;
    if (m_unkA3348 == 1) {
        nSize = 0x33A;
    } else {
        nSize = 0x388;
    }
    if (pMat == 0) {
        CdsAssert("PDisplayList.cpp", 0x94C, "pMat");
    }
    if (nSize >= 0x400) {
        CdsAssert("PDisplayList.cpp", 0x94D, "uVu1MemOffset < 1024");
    }
    int nPacket = AllocEntries(5);
    if (nPacket != 0) {
        *(long long *)nPacket = 0x10000004LL;
        ((unsigned int *)nPacket)[2] = 0x10000000;
        ((unsigned int *)nPacket)[3] = nSize | 0x6C040000;
        *(u_long128 *)(nPacket + 0x10) = *(u_long128 *)pMat;
        *(u_long128 *)(nPacket + 0x20) = *(u_long128 *)((char *)pMat + 0x10);
        *(u_long128 *)(nPacket + 0x30) = *(u_long128 *)((char *)pMat + 0x20);
        *(u_long128 *)(nPacket + 0x40) = *(u_long128 *)((char *)pMat + 0x30);
        asm {
            sync
        }
    }
}

// FUNCTION: 0x183C40 SetWorldMatrix__12PDisplayListFP5PMat4
void PDisplayList::SetWorldMatrix(PMat4 *pMat) {
    unsigned int nSize;
    if (m_unkA3348 == 1) {
        nSize = 0x336;
    } else {
        nSize = 0x384;
    }
    if (pMat == 0) {
        CdsAssert("PDisplayList.cpp", 0x94C, "pMat");
    }
    if (nSize >= 0x400) {
        CdsAssert("PDisplayList.cpp", 0x94D, "uVu1MemOffset < 1024");
    }
    int nPacket = AllocEntries(5);
    if (nPacket != 0) {
        *(long long *)nPacket = 0x10000004LL;
        ((unsigned int *)nPacket)[2] = 0x10000000;
        ((unsigned int *)nPacket)[3] = nSize | 0x6C040000;
        *(u_long128 *)(nPacket + 0x10) = *(u_long128 *)pMat;
        *(u_long128 *)(nPacket + 0x20) = *(u_long128 *)((char *)pMat + 0x10);
        *(u_long128 *)(nPacket + 0x30) = *(u_long128 *)((char *)pMat + 0x20);
        *(u_long128 *)(nPacket + 0x40) = *(u_long128 *)((char *)pMat + 0x30);
        asm {
            sync
        }
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

// DRAFT: 0x184040 KickVifDmaChain__12PDisplayListFb
// note: 4 lines differ: original keeps 0x13000000 in a0 and masks the address with dsll32/dsrl32 by 4 (28-bit); mwcc uses v1 and folds the mask to 32-bit. Tried: 64-bit locals, pointer and signed casts, separate tag variable, inline tag constant (still 4 lines).
void PDisplayList::KickVifDmaChain(bool bWait) {
    int nPacket = AllocEntries(1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x9E, "0");
    }
    *(long long *)nPacket = 0x70000000LL;
    ((unsigned int *)nPacket)[2] = 0;
    ((unsigned int *)nPacket)[3] = 0x13000000;
    *(unsigned int *)0x10009020 = 0;
    *(unsigned int *)0x10009030 = (unsigned int)(((unsigned long long)((unsigned int)this + 0x40) << 36) >> 36);
    *(unsigned int *)0x1000E010 = 2;
    FlushCache(0);
    asm {
        sync
        sync.p
    }
    *(unsigned int *)0x10009000 = 0x145;
    asm {
        sync
        sync.p
    }
    if (bWait) {
        DmaWaitForCompletion(1, false);
        Reset();
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
