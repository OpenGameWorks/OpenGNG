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
extern char shared_vertices_start[];
extern char gHermiteMat[0x40];
extern char guFxPipelineVuConstants[0x280];
extern char gu3dPipelineVuConstants[0x280];
extern char vu_fx_microcode_dma_packet[0x10];
extern char vu_shadow_microcode_dma_packet[0x10];
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int SCREEN_OFFSET_X;
extern int SCREEN_OFFSET_Y;
void DmaScratchPadToMainMem(void *pSrc, void *pDst, short nQw, bool bA, bool bB);

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

// DRAFT: 0x00181770 SetMaterials__12PDisplayListFP13tagGsMaterialibbPfPUlPUl
// note: DIFF 193 words, size 0x284 vs 0x340; prologue saves/spills differ (this in s5 not fp, pTagB spilled), nHeader in s1 not stack, DeAllocEntries reloc at 0x023c/0x0304 misplaced; tried nHeader ternary vs if/else (same count 197 in the other body)
void PDisplayList::SetMaterials(struct tagGsMaterial *pMat, int nCount, bool bA, bool bB, float *pScale, unsigned long *pTagA, unsigned long *pTagB) {
    int nHeader;
    int nAddr;
    int nPacket;
    int nTotal;
    int nIdx;
    int nDone;
    char *pDst;
    char *pElem;
    char *pTagEl;

    if (pMat == 0) {
        CdsAssert("PDisplayList.cpp", 0x612, "pMaterials");
    }
    if (nCount <= 0 || nCount >= 5) {
        CdsAssert("PDisplayList.cpp", 0x613, "iNumPasses > 0 && iNumPasses <= MAX_PASSES_PER_SHADER");
    }
    nHeader = (m_unkA3348 == 2) ? 0x3AC : 0x372;
    if (nCount != 1) {
        CdsAssert("PDisplayList.cpp", 0x618, "iNumPasses == 1");
    }
    if (bA) {
        SetTexSyncPacket();
    }
    nTotal = nCount * 9 + 1;
    nPacket = AllocEntries(nTotal);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0x62D, "0");
    }
    ((int *)nPacket)[4] = nCount - 1;
    ((int *)nPacket)[5] = 0;
    ((int *)nPacket)[6] = 0;
    ((int *)nPacket)[7] = 0;

    pDst = (char *)nPacket + 0x20;
    nDone = 0;
    nAddr = ((unsigned int)shared_vertices_start + 0x2C10) >> 3;
    for (nIdx = 0; nIdx < nCount; nIdx++) {
        pElem = (char *)pMat + nIdx * 0x20;
        pTagEl = (char *)pElem + 0x90;
        ((int *)pDst)[0] = 0;
        ((int *)pDst)[1] = 0;
        ((int *)pDst)[2] = 0;
        ((int *)pDst)[3] = (*(int *)(pElem + 0x90) != 0) ? ((0x0E + 4) << 16) : (0x0E << 16);
        *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pElem + 0x00);
        *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pElem + 0x10);
        *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pElem + 0x20);
        *(u_long128 *)(pDst + 0x40) = *(u_long128 *)(pElem + 0x30);
        *(u_long128 *)(pDst + 0x50) = *(u_long128 *)(pElem + 0x40);
        *(u_long128 *)(pDst + 0x60) = *(u_long128 *)(pElem + 0x50);
        *(u_long128 *)(pDst + 0x70) = *(u_long128 *)(pElem + 0x10);
        *(u_long128 *)(pDst + 0x80) = *(u_long128 *)(pElem + 0x20);
        *(u_long128 *)(pDst + 0x90) = *(u_long128 *)(pElem + 0x30);
        *(u_long128 *)(pDst + 0xA0) = *(u_long128 *)(pElem + 0x40);
        *(u_long128 *)(pDst + 0xB0) = *(u_long128 *)(pElem + 0x50);
        *(u_long128 *)(pDst + 0xC0) = *(u_long128 *)(pElem + 0x60);
        *(u_long128 *)(pDst + 0xD0) = *(u_long128 *)(pElem + 0x70);
        ((int *)pDst)[0x34 / 4] = 0;
        ((int *)pDst)[0x35 / 4] = 0;
        if (bB) {
            ((float *)pDst)[0xCC / 4] = pScale[nIdx];
            *(long long *)(pDst + 0x90) = *(long long *)pTagA;
            *(long long *)(pDst + 0xB0) = *(long long *)pTagB;
        }
        pDst += 0xF0;
        nDone += 4;
    }

    ((int *)nPacket)[0] = (0x6C00 << 16) | nHeader;
    ((int *)nPacket)[1] = 0;
    ((int *)nPacket)[2] = 0x10000000;
    DeAllocEntries(nTotal - nDone);
    ((unsigned int *)nPacket)[3] = (0x6C01 << 16) | nHeader;
    asm {
        sync
    }
}


// DRAFT: 0x001826F0 DrawSplineParticles__12PDisplayListFP14tagVuSplineKeyiifbi
// note: 167 words differ, size 0x368 vs 0x36C; frame 0xC0 vs 0xB0 (pChunk spilled to 0xA0, original keeps it in s1); nCount/this/bFlag registers differ; declaring n per loop changed nothing
void PDisplayList::DrawSplineParticles(struct tagVuSplineKey *pKeys, int nCount, int nTag, float fA, bool bFlag, int nChunk) {
    if (pKeys == 0) { CdsAssert("PDisplayList.cpp", 0x38F, "pKeys"); }
    if (nCount == 0) { CdsAssert("PDisplayList.cpp", 0x390, "iNumKeys"); }
    if (nCount >= 4) {
        int nLoops = nCount / nChunk;
        if (nCount % nChunk) { nLoops++; }
        int nIdx = 0;
        int n;
        if (bFlag) {
            while (nIdx < nLoops) {
                n = (nCount < nChunk) ? nCount : nChunk;
                nCount -= n;
                char *pChunk = (char *)pKeys + nIdx * nChunk * 64;
                if (n < 5) { break; }
                char *pPkt = (char *)AllocEntries(4 * n + 3);
                if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x3B1, "0"); }
                int nQw = 4 * n + 2;
                *(long long *)pPkt = (long long)nQw | 0x10000000;
                *(unsigned int *)(pPkt + 8) = 0x10000000;
                *(unsigned int *)(pPkt + 0xC) = ((nQw - 1) << 16) | 0x6C000000;
                pPkt += 0x10;
                *(int *)pPkt = n;
                *(int *)(pPkt + 4) = nTag;
                *(unsigned int *)(pPkt + 8) = *(unsigned int *)&fA;
                *(unsigned int *)(pPkt + 0xC) = 0;
                pPkt += 0x10;
                QwordCopy((u_long128 *)pPkt, (u_long128 *)pChunk, nQw - 2);
                nIdx++;
                pPkt += (nQw - 2) << 4;
                *(unsigned int *)pPkt = 0x11000000;
                *(unsigned int *)(pPkt + 4) = 0x17000000;
                *(unsigned int *)(pPkt + 8) = 0;
                *(unsigned int *)(pPkt + 0xC) = 0;
            }
        } else {
            while (nIdx < nLoops) {
                n = (nCount < nChunk) ? nCount : nChunk;
                nCount -= n;
                char *pChunk = (char *)pKeys + nIdx * nChunk * 64;
                if (n < 5) { break; }
                char *pPkt = (char *)AllocEntries(2);
                if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x3DC, "0"); }
                *(long long *)pPkt = 0x10000001;
                *(unsigned int *)(pPkt + 8) = 0x10000000;
                *(unsigned int *)(pPkt + 0xC) = 0x6C010000;
                pPkt += 0x10;
                *(int *)pPkt = n;
                *(int *)(pPkt + 4) = nTag;
                *(unsigned int *)(pPkt + 8) = *(unsigned int *)&fA;
                *(unsigned int *)(pPkt + 0xC) = 0;
                pPkt = (char *)AllocEntries(1);
                if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x3EC, "0"); }
                *(unsigned long long *)pPkt = ((unsigned long long)(unsigned int)pChunk << 32) | 0x30000000 | (unsigned int)(n << 2);
                *(unsigned int *)(pPkt + 8) = 0;
                *(unsigned int *)(pPkt + 0xC) = ((unsigned int)(n << 2) << 16) | 0x6C000001;
                pPkt = (char *)AllocEntries(1);
                if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x3F8, "0"); }
                *(long long *)pPkt = 0x10000000;
                nIdx++;
                *(unsigned int *)(pPkt + 8) = 0x11000000;
                *(unsigned int *)(pPkt + 0xC) = 0x17000000;
            }
        }
    }
}

// DRAFT: 0x181AB0 DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib
// note: 180 words differ; frame 0xB0 vs 0xA0 (this spilled to 0xAC(sp), fp not used), arg registers a1..a3 not s7/s1/s0, packet store order
void PDisplayList::DrawFxInstances(struct tagVuFxInstance *pInstances, int nNum, bool bFlag) {
    int i;
    int nBatch;
    int nLeft;
    int nCount;
    int nPacket;
    int nQw;
    char *pBatch;
    unsigned int qw;

    if (pInstances == 0) {
        CdsAssert("PDisplayList.cpp", 0x553, "pInstances");
    }
    if (nNum == 0) {
        CdsAssert("PDisplayList.cpp", 0x554, "iNumInstances");
    }
    nBatch = nNum / 30;
    if (nNum % 30 != 0) {
        nBatch++;
    }
    nLeft = nNum;
    if (bFlag) {
        for (i = 0; i < nBatch; i++) {
            nCount = nLeft;
            if (nLeft >= 30) {
                nCount = 30;
            }
            nLeft -= nCount;
            pBatch = (char *)pInstances + i * 0xB40;
            nPacket = AllocEntries(nCount * 6 + 3);
            if (nPacket == 0) {
                CdsAssert("PDisplayList.cpp", 0x56B, "0");
            }
            nQw = nCount * 6 + 2;
            *(long long *)nPacket = (long long)nQw | 0x10000000LL;
            ((unsigned int *)nPacket)[2] = 0;
            ((unsigned int *)nPacket)[3] = ((nQw - 1) << 16) | 0x6C000000;
            ((unsigned int *)nPacket)[4] = nCount;
            ((unsigned int *)nPacket)[5] = 0;
            ((unsigned int *)nPacket)[6] = 0;
            ((unsigned int *)nPacket)[7] = 0;
            if (((int)pBatch & 0x70000000) == 0x70000000) {
                DmaScratchPadToMainMem(pBatch, (void *)(nPacket + 0x20), (short)(nQw - 2), 0, 0);
            } else {
                QwordCopy((u_long128 *)(nPacket + 0x20), (u_long128 *)pBatch, nQw - 2);
            }
            ((unsigned int *)(nPacket + 0x20 + (nQw - 2) * 0x10))[0] = 0x17000000;
            ((unsigned int *)(nPacket + 0x20 + (nQw - 2) * 0x10))[1] = 0;
            ((unsigned int *)(nPacket + 0x20 + (nQw - 2) * 0x10))[2] = 0;
            ((unsigned int *)(nPacket + 0x20 + (nQw - 2) * 0x10))[3] = 0;
        }
    } else {
        for (i = 0; i < nBatch; i++) {
            nCount = nLeft;
            if (nLeft >= 30) {
                nCount = 30;
            }
            nLeft -= nCount;
            pBatch = (char *)pInstances + i * 0xB40;
            nPacket = AllocEntries(4);
            if (nPacket == 0) {
                CdsAssert("PDisplayList.cpp", 0x598, "0");
            }
            qw = (unsigned int)(nCount * 0x60) >> 4;
            *(long long *)nPacket = 0x10000001LL;
            ((unsigned int *)nPacket)[2] = 0x10000000;
            ((unsigned int *)nPacket)[3] = 0x6C010000;
            ((unsigned int *)nPacket)[4] = nCount;
            *(long long *)(nPacket + 0x20) = ((long long)(unsigned int)pBatch << 32) | 0x30000000LL | (long long)qw;
            ((unsigned int *)nPacket)[10] = 0;
            ((unsigned int *)nPacket)[11] = (qw << 16) | 0x6C000001;
            *(long long *)(nPacket + 0x30) = 0x10000000LL;
            ((unsigned int *)nPacket)[14] = 0x11000000;
            ((unsigned int *)nPacket)[15] = 0x17000000;
        }
    }
    asm {
        sync
    }
}

// DRAFT: 0x181DF0 DrawStaticInstances__12PDisplayListFP19tagVuStaticInstanceiiiib
// note: packet and source pointers as in the asm; frame and store order still differ
void PDisplayList::DrawStaticInstances(struct tagVuStaticInstance *pInstances, int nNum, int nBatch, int nA, int nB, bool bFlag) {
    if (pInstances == 0) {
        CdsAssert("PDisplayList.cpp", 0x4F1, "pInstances");
    }
    if (nNum == 0) {
        CdsAssert("PDisplayList.cpp", 0x4F2, "iNumInstances");
    }
    int nLoops = nNum / nBatch;
    if (nNum % nBatch != 0) {
        nLoops += 1;
    }
    int nIdx = 0;
    if (bFlag) {
        while (nIdx < nLoops) {
            int n = (nNum < nBatch) ? nNum : nBatch;
            char *pSrc = (char *)pInstances + (((nIdx * nBatch) * 5) << 4);
            nNum -= n;
            char *pPkt = (char *)AllocEntries(n * 5 + 3);
            if (pPkt == 0) {
                CdsAssert("PDisplayList.cpp", 0x509, "0");
            }
            int nCount = n * 5 + 2;
            *(long long *)pPkt = (long long)(nCount | 0x10000000);
            *(int *)(pPkt + 8) = 0x10000000;
            *(int *)(pPkt + 0xC) = nA | ((nCount - 1) << 16) | 0x6C000000;
            pPkt += 0x10;
            *(int *)pPkt = n;
            *(int *)(pPkt + 4) = 0;
            *(int *)(pPkt + 8) = 0;
            *(int *)(pPkt + 0xC) = 0;
            pPkt += 0x10;
            QwordCopy((u_long128 *)pPkt, (u_long128 *)pSrc, nCount - 2);
            pPkt += (nCount - 2) << 4;
            nIdx += 1;
            *(unsigned int *)pPkt = 0x11000000;
            *(unsigned int *)(pPkt + 4) = 0x17000000;
            *(int *)(pPkt + 8) = 0;
            *(int *)(pPkt + 0xC) = 0;
        }
    } else {
        while (nIdx < nLoops) {
            int n = (nNum < nBatch) ? nNum : nBatch;
            char *pSrc = (char *)pInstances + (((nIdx * nBatch) * 5) << 4);
            nNum -= n;
            char *pPkt = (char *)AllocEntries(4);
            if (pPkt == 0) {
                CdsAssert("PDisplayList.cpp", 0x52F, "0");
            }
            int nQw = n * 5;
            *(long long *)pPkt = 0x10000001LL;
            *(int *)(pPkt + 8) = 0x10000000;
            *(int *)(pPkt + 0xC) = nA | 0x6C010000;
            *(int *)(pPkt + 0x10) = n;
            *(long long *)(pPkt + 0x20) = ((long long)(unsigned int)pSrc << 32) | 0x30000000LL | (long long)nQw;
            *(int *)(pPkt + 0x28) = 0;
            *(int *)(pPkt + 0x2C) = nB | (nQw << 16) | 0x6C000000;
            *(long long *)(pPkt + 0x30) = 0x10000000LL;
            *(unsigned int *)(pPkt + 0x38) = 0x11000000;
            *(unsigned int *)(pPkt + 0x3C) = 0x17000000;
            nIdx += 1;
        }
    }
}

// DRAFT: 0x182100 DrawFogParticles__12PDisplayListFPA4_fifffPf
// note: 102 differing words; frame 0xC0 vs 0xB0 with pColor spilled and extra locals live across the call (tried 5 variants, best kept)
void PDisplayList::DrawFogParticles(float (*pVerts)[4], int nCount, float fA, float fB, float fC, float *pColor) {
    if (pVerts == 0) {
        CdsAssert("PDisplayList.cpp", 0x4A7, "pParticles");
    }
    if (nCount == 0) {
        CdsAssert("PDisplayList.cpp", 0x4A8, "iNumParticles");
    }
    int nLoops = nCount / 61;
    if (nCount % 61 != 0) {
        nLoops += 1;
    }
    int nIndex = 0;
    while (nIndex < nLoops) {
        int nChunk = (nCount < 61) ? nCount : 61;
        float (*pChunk)[4] = pVerts + nIndex * 61;
        nCount -= nChunk;
        if (nChunk < 5) {
            break;
        }
        int nPacket = AllocEntries(5);
        if (nPacket == 0) {
            CdsAssert("PDisplayList.cpp", 0x4C1, "0");
        }
        *(long long *)nPacket = 0x10000002LL;
        ((unsigned int *)nPacket)[2] = 0;
        ((unsigned int *)nPacket)[3] = 0x6C028000;
        ((unsigned int *)nPacket)[4] = nChunk;
        nIndex++;
        ((float *)nPacket)[6] = fA;
        ((float *)nPacket)[5] = fB;
        ((float *)nPacket)[7] = fC;
        *(u_long128 *)(nPacket + 0x20) = *(u_long128 *)pColor;
        *(long long *)(nPacket + 0x30) = ((long long)(unsigned int)pChunk << 32) | 0x30000000LL | (long long)nChunk;
        ((unsigned int *)nPacket)[14] = 0;
        ((unsigned int *)nPacket)[15] = (nChunk << 16) | 0x6C008004;
        *(long long *)(nPacket + 0x40) = 0x10000000LL;
        ((unsigned int *)nPacket)[18] = 0x17000000;
        ((unsigned int *)nPacket)[19] = 0;
    }
    asm {
        sync
    }
}

// DRAFT: 0x00182320 DrawSplinePatch__12PDisplayListFP19tagVuSplinePatchKeyiifbi
// note: 199 words differ; frame 0xB0 vs 0xC0, spills 0xA8/0xAC/0xA4 vs 0xB0/0xBC/0xAC, bFlag s1 vs s0, nIdx s0 vs s7; loop increment moved to bottom (199, same), nIdx declared per branch (204, worse)
void PDisplayList::DrawSplinePatch(struct tagVuSplinePatchKey *pKeys, int nCount, int nTag, float fA, bool bFlag, int nChunk) {
    if (pKeys == 0) { CdsAssert("PDisplayList.cpp", 0x411, "pKeys"); }
    if (nCount == 0) { CdsAssert("PDisplayList.cpp", 0x412, "iNumKeys"); }
    if (nCount < 4) { return; }
    int nLoops = nCount / nChunk;
    if (nCount % nChunk) { nLoops++; }
    int nIdx = 0;
    int n;
    if (bFlag) {
        while (nIdx < nLoops) {
            n = (nCount < nChunk) ? nCount : nChunk;
            nCount -= n;
            char *pChunk = (char *)pKeys + nIdx * nChunk * 0x50;
            if (n < 5) { break; }
            char *pPkt = (char *)AllocEntries(5 * n + 3);
            if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x433, "0"); }
            int nQw = 5 * n + 2;
            *(long long *)pPkt = (long long)nQw | 0x10000000;
            *(unsigned int *)(pPkt + 8) = 0x10000000;
            *(unsigned int *)(pPkt + 0xC) = ((nQw - 1) << 16) | 0x6C000000;
            pPkt += 0x10;
            *(int *)pPkt = n;
            *(int *)(pPkt + 4) = nTag;
            *(unsigned int *)(pPkt + 8) = *(unsigned int *)&fA;
            *(unsigned int *)(pPkt + 0xC) = 0;
            pPkt += 0x10;
            if (((unsigned int)pChunk & 0x70000000) == 0x70000000) {
                DmaScratchPadToMainMem(pChunk, pPkt, (short)(nQw - 2), false, false);
            } else {
                QwordCopy((u_long128 *)pPkt, (u_long128 *)pChunk, nQw - 2);
            }
            nIdx++;
            pPkt += (nQw - 2) << 4;
            *(unsigned int *)pPkt = 0x11000000;
            *(unsigned int *)(pPkt + 4) = 0x17000000;
            *(unsigned int *)(pPkt + 8) = 0;
            *(unsigned int *)(pPkt + 0xC) = 0;
        }
    } else {
        while (nIdx < nLoops) {
            n = (nCount < nChunk) ? nCount : nChunk;
            nCount -= n;
            char *pChunk = (char *)pKeys + nIdx * nChunk * 0x50;
            if (n < 5) { break; }
            char *pPkt = (char *)AllocEntries(2);
            if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x464, "0"); }
            *(long long *)pPkt = 0x10000001;
            *(unsigned int *)(pPkt + 8) = 0x10000000;
            *(unsigned int *)(pPkt + 0xC) = 0x6C010000;
            pPkt += 0x10;
            *(int *)pPkt = n;
            *(int *)(pPkt + 4) = nTag;
            *(unsigned int *)(pPkt + 8) = *(unsigned int *)&fA;
            *(unsigned int *)(pPkt + 0xC) = 0;
            pPkt = (char *)AllocEntries(1);
            if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x474, "0"); }
            *(long long *)pPkt = ((long long)(unsigned int)pChunk << 32) | 0x30000000 | (5 * n);
            *(unsigned int *)(pPkt + 8) = 0;
            *(unsigned int *)(pPkt + 0xC) = ((5 * n) << 16) | 0x6C000001;
            pPkt = (char *)AllocEntries(1);
            if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x480, "0"); }
            *(long long *)pPkt = 0x10000000;
            nIdx++;
            *(unsigned int *)(pPkt + 8) = 0x11000000;
            *(unsigned int *)(pPkt + 0xC) = 0x17000000;
        }
    }
}

// DRAFT: 0x182A60 DrawRotatableParticles__12PDisplayListFP22tagVuRotatableParticleiffbi
// note: 164 words differ; frame 0xC0 vs 0xB0, float spills 0xB8/0xBC vs 0xA8/0xAC, params in s3/s1/s0 vs s0/s1/s2, branch shapes and nLoops div operands differ; nCount-as-remainder tried, same 164.
void PDisplayList::DrawRotatableParticles(struct tagVuRotatableParticle *pParticles, int nCount, float fA, float fB, bool bFlag, int nChunk) {
    if (pParticles == 0) { CdsAssert("PDisplayList.cpp", 0x319, "pParticles"); }
    if (nCount == 0) { CdsAssert("PDisplayList.cpp", 0x31A, "iNumParticles"); }
    if (nCount >= 5) {
        int nLoops = nCount / nChunk;
        if (nCount % nChunk) { nLoops++; }
        int nRem = nCount;
        int nIdx = 0;
        int n;
        if (bFlag) {
            while (nIdx < nLoops) {
                n = (nRem < nChunk) ? nRem : nChunk;
                nRem -= n;
                char *pChunk = (char *)pParticles + nIdx * nChunk * 48;
                if (n < 5) { break; }
                char *pPkt = (char *)AllocEntries(3 * n + 3);
                if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x33B, "0"); }
                int nQw = 3 * n + 2;
                *(long long *)pPkt = (long long)nQw | 0x10000000;
                *(unsigned int *)(pPkt + 8) = 0;
                *(unsigned int *)(pPkt + 0xC) = ((nQw - 1) << 16) | 0x6C008000;
                pPkt += 0x10;
                *(int *)pPkt = n;
                *(unsigned int *)(pPkt + 4) = *(unsigned int *)&fB;
                *(unsigned int *)(pPkt + 8) = *(unsigned int *)&fA;
                *(unsigned int *)(pPkt + 0xC) = 0;
                pPkt += 0x10;
                QwordCopy((u_long128 *)pPkt, (u_long128 *)pChunk, nQw - 2);
                nIdx++;
                pPkt += (nQw - 2) << 4;
                *(unsigned int *)pPkt = 0x17000000;
                *(unsigned int *)(pPkt + 4) = 0;
                *(unsigned int *)(pPkt + 8) = 0;
                *(unsigned int *)(pPkt + 0xC) = 0;
            }
        } else {
            while (nIdx < nLoops) {
                n = (nRem < nChunk) ? nRem : nChunk;
                nRem -= n;
                char *pChunk = (char *)pParticles + nIdx * nChunk * 48;
                if (n < 5) { break; }
                char *pPkt = (char *)AllocEntries(4);
                if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x366, "0"); }
                nIdx++;
                *(long long *)pPkt = 0x10000001;
                *(unsigned int *)(pPkt + 8) = 0;
                *(unsigned int *)(pPkt + 0xC) = 0x6C018000;
                *(int *)(pPkt + 0x10) = n;
                unsigned int nQ = ((unsigned int)(n * 0x30)) >> 4;
                *(float *)(pPkt + 0x18) = fA;
                *(float *)(pPkt + 0x14) = fB;
                *(unsigned long long *)(pPkt + 0x20) = ((unsigned long long)(unsigned int)pChunk << 32) | 0x30000000 | nQ;
                *(unsigned int *)(pPkt + 0x28) = 0;
                *(unsigned int *)(pPkt + 0x2C) = (nQ << 16) | 0x6C008001;
                *(long long *)(pPkt + 0x30) = 0x10000000;
                *(unsigned int *)(pPkt + 0x38) = 0x17000000;
                *(unsigned int *)(pPkt + 0x3C) = 0;
            }
        }
    }
    asm {
        sync
    }
}

// DRAFT: 0x182D90 DrawParticles__12PDisplayListFP13tagVuParticleiffbi
// note: 138 words differ; frame 0xC0 vs 0xB0 (pChunk spilled), params in s3/s1/s0 vs s0/s2/s1, bFlag not reused for n. Tried nCount as nRem, nIdx declared first, pChunk before n; none lowered the count.
void PDisplayList::DrawParticles(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag, int nChunk) {
    if (pParticles == 0) { CdsAssert("PDisplayList.cpp", 0x2A4, "pParticles"); }
    if (nCount == 0) { CdsAssert("PDisplayList.cpp", 0x2A5, "iNumParticles"); }
    if (nCount >= 5) {
        int nLoops = nCount / nChunk;
        if (nCount % nChunk) { nLoops++; }
        int nRem = nCount;
        int nIdx = 0;
        int n;
        if (bFlag) {
            while (nIdx < nLoops) {
                n = (nRem < nChunk) ? nRem : nChunk;
                nRem -= n;
                char *pChunk = (char *)pParticles + nIdx * nChunk * 32;
                if (n < 5) { break; }
                char *pPkt = (char *)AllocEntries(2 * n + 3);
                if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x2C6, "0"); }
                int nQw = 2 * n + 2;
                *(long long *)pPkt = (long long)nQw | 0x10000000;
                *(unsigned int *)(pPkt + 8) = 0;
                *(unsigned int *)(pPkt + 0xC) = ((nQw - 1) << 16) | 0x6C008000;
                pPkt += 0x10;
                *(int *)pPkt = n;
                *(unsigned int *)(pPkt + 4) = *(unsigned int *)&fB;
                *(unsigned int *)(pPkt + 8) = *(unsigned int *)&fA;
                *(unsigned int *)(pPkt + 0xC) = 0;
                pPkt += 0x10;
                QwordCopy((u_long128 *)pPkt, (u_long128 *)pChunk, nQw - 2);
                nIdx++;
                pPkt += (nQw - 2) << 4;
                *(unsigned int *)pPkt = 0x17000000;
                *(unsigned int *)(pPkt + 4) = 0;
                *(unsigned int *)(pPkt + 8) = 0;
                *(unsigned int *)(pPkt + 0xC) = 0;
            }
        } else {
            while (nIdx < nLoops) {
                n = (nRem < nChunk) ? nRem : nChunk;
                nRem -= n;
                char *pChunk = (char *)pParticles + nIdx * nChunk * 32;
                if (n < 5) { break; }
                char *pPkt = (char *)AllocEntries(4);
                if (pPkt == 0) { CdsAssert("PDisplayList.cpp", 0x2F1, "0"); }
                nIdx++;
                *(long long *)pPkt = 0x10000001;
                *(unsigned int *)(pPkt + 8) = 0;
                *(unsigned int *)(pPkt + 0xC) = 0x6C018000;
                *(int *)(pPkt + 0x10) = n;
                unsigned int nQ = ((unsigned int)(n << 5)) >> 4;
                *(float *)(pPkt + 0x18) = fA;
                *(float *)(pPkt + 0x14) = fB;
                *(unsigned long long *)(pPkt + 0x20) = ((unsigned long long)(unsigned int)pChunk << 32) | 0x30000000 | nQ;
                *(unsigned int *)(pPkt + 0x28) = 0;
                *(unsigned int *)(pPkt + 0x2C) = (nQ << 16) | 0x6C008001;
                *(long long *)(pPkt + 0x30) = 0x10000000;
                *(unsigned int *)(pPkt + 0x38) = 0x17000000;
                *(unsigned int *)(pPkt + 0x3C) = 0;
            }
        }
    }
    asm { sync }
}

// DRAFT: 0x1830A0 DrawSprites__12PDisplayListFP11tagVuSpriteib
// note: loop A (bFlag) and loop B packet layout as in the asm; frame and store order still differ
void PDisplayList::DrawSprites(struct tagVuSprite *pSprite, int nCount, bool bFlag) {
    if (pSprite == 0) {
        CdsAssert("PDisplayList.cpp", 0x23A, "pSprites");
    }
    if (nCount == 0) {
        CdsAssert("PDisplayList.cpp", 0x23B, "iNumSprites");
    }
    int nLoops = (nCount + 0x27) / 40;
    if (bFlag) {
        int nIdx = 0;
        while (nIdx < nLoops) {
            int n = (nCount < 40) ? nCount : 40;
            nCount -= n;
            if (nLoops >= 2 && nCount == 1) {
                nCount = 2;
                n -= 1;
            }
            char *pPkt = (char *)AllocEntries(n * 4 + 3);
            if (pPkt == 0) {
                CdsAssert("PDisplayList.cpp", 0x252, "0");
            }
            int nQw = n * 4 + 2;
            *(long long *)pPkt = (long long)(nQw | 0x10000000);
            *(int *)(pPkt + 8) = 0;
            *(int *)(pPkt + 0xC) = ((nQw - 1) << 16) | 0x6C008000;
            *(int *)(pPkt + 0x10) = n;
            pPkt += 0x20;
            QwordCopy((u_long128 *)pPkt, (u_long128 *)pSprite, nQw - 2);
            pSprite = (struct tagVuSprite *)((char *)pSprite + (n << 6));
            pPkt += (nQw - 2) << 4;
            *(unsigned int *)pPkt = 0x17000000;
            nIdx += 1;
            *(int *)(pPkt + 4) = 0;
            *(int *)(pPkt + 8) = 0;
            *(int *)(pPkt + 0xC) = 0;
        }
    } else {
        int nIdx = 0;
        while (nIdx < nLoops) {
            int n = (nCount < 40) ? nCount : 40;
            nCount -= n;
            char *pPkt = (char *)AllocEntries(4);
            if (pPkt == 0) {
                CdsAssert("PDisplayList.cpp", 0x27D, "0");
            }
            int nQw = n * 4;
            *(long long *)pPkt = 0x10000001LL;
            *(int *)(pPkt + 8) = 0;
            *(int *)(pPkt + 0xC) = 0x6C018000;
            *(int *)(pPkt + 0x10) = n;
            *(long long *)(pPkt + 0x20) = ((long long)(unsigned int)pSprite << 32) | 0x30000000LL | (long long)nQw;
            *(int *)(pPkt + 0x28) = 0;
            *(int *)(pPkt + 0x2C) = (nQw << 16) | 0x6C008001;
            *(long long *)(pPkt + 0x30) = 0x10000000LL;
            *(unsigned int *)(pPkt + 0x38) = 0x17000000;
            *(int *)(pPkt + 0x3C) = 0;
            pSprite = (struct tagVuSprite *)((char *)pSprite + (n << 6));
            nIdx += 1;
        }
    }
    asm { sync }
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

// DRAFT: 0x183D30 SetVu1Microcode__12PDisplayListFPv
// note: size 0x218 vs 0x284; frame 0x80 not 0x90 (no s7 save); locals s3/s2 swapped; tried decl reorder (148) and inverted branch (149), kept 147
void PDisplayList::SetVu1Microcode(void *pData) {
    unsigned int nMode;
    unsigned int nStart;
    unsigned int nVu1Offset;
    unsigned int nCode;
    char *pConst;
    int nQw;
    int nPacket;
    if (pData == vu_fx_microcode_dma_packet) {
        m_unkA3348 = 2;
        nMode = 0;
        pConst = guFxPipelineVuConstants;
        nQw = 0xA;
        nStart = 0x185;
        nVu1Offset = 0x3BF;
        nCode = 0x6C04039C;
    } else {
        m_unkA3348 = 1;
        nMode = 0;
        pConst = gu3dPipelineVuConstants;
        nQw = 0xF;
        nStart = 0x10A;
        nVu1Offset = 0x3BB;
        nCode = 0x6C040367;
    }
    ((gHermiteMat != 0) ? (void)0 : CdsAssert("PDisplayList.cpp", 0x94C, "pMat"));
    nPacket = AllocEntries(5);
    if (nPacket != 0) {
        *(long long *)nPacket = 0x10000004LL;
        ((unsigned int *)nPacket)[2] = 0x10000000;
        ((unsigned int *)nPacket)[3] = nCode;
        *(u_long128 *)(nPacket + 0x10) = *(u_long128 *)gHermiteMat;
        *(u_long128 *)(nPacket + 0x20) = *(u_long128 *)(gHermiteMat + 0x10);
        *(u_long128 *)(nPacket + 0x30) = *(u_long128 *)(gHermiteMat + 0x20);
        *(u_long128 *)(nPacket + 0x40) = *(u_long128 *)(gHermiteMat + 0x30);
        asm {
            sync
        }
    }
    nPacket = AllocEntries(1);
    if (nPacket == 0) {
        CdsAssert("PDisplayList.cpp", 0xFE, "0");
    }
    *(long long *)nPacket = ((long long)(unsigned int)pData << 32) | 0x50000000LL;
    ((unsigned int *)nPacket)[2] = 0x11000000;
    ((unsigned int *)nPacket)[3] = 0;
    if (pData != vu_shadow_microcode_dma_packet) {
        WriteToVu1Mem(nVu1Offset, (u_long128 *)pConst, nQw);
        nPacket = AllocEntries(1);
        if (nPacket == 0) {
            CdsAssert("PDisplayList.cpp", 0x115, "0");
        }
        *(long long *)nPacket = 0x10000000LL;
        ((unsigned int *)nPacket)[2] = nMode | 0x03000000;
        ((unsigned int *)nPacket)[3] = nStart | 0x02000000;
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

#define PDL_LO(p, v) (*(unsigned char *)(p) = (unsigned char)((*(unsigned char *)(p) & 0xF0) | (v)))
#define PDL_HI(p, v) (*(unsigned char *)(p) = (unsigned char)((*(unsigned char *)(p) & 0x0F) | ((v) << 4)))

// DRAFT: 0x184180 Init__12PDisplayListFv
// note: frame 0x50 vs original 0xA0, only s0/s1 saved vs s0..s7, constant registers not hoisted; 244 words differ (inverted nibble masks gave 247, quad merged into w gave 246)
void PDisplayList::Init() {
    int w[4];
    float *fw = (float *)w;
    u_long128 q;
    unsigned long long gif1;
    unsigned long long gif2;
    unsigned char *t8;
    unsigned char *s5;

    Reset__16PTextureDmaChainFv(m_unkA3380);
    m_unkA3348 = 1;
    *(int *)(gu3dPipelineVuConstants + 0x30) = 0x237;
    *(int *)(gu3dPipelineVuConstants + 0x3C) = 0x373;
    *(int *)(gu3dPipelineVuConstants + 0x34) = 0;
    *(int *)(gu3dPipelineVuConstants + 0x38) = 0;
    q = *(u_long128 *)(guFxPipelineVuConstants + 0xA0);
    *(u_long128 *)w = q;
    gif1 = 0x8000ULL | ((unsigned long long)0xF002C000 << 32);
    gif2 = 0x8000ULL | ((unsigned long long)0x90024000 << 32);
    fw[2] = (float)SCREEN_WIDTH;
    fw[3] = (float)SCREEN_HEIGHT;
    *(int *)(guFxPipelineVuConstants + 0x30) = w[0];
    *(int *)(guFxPipelineVuConstants + 0x34) = w[1];
    *(int *)(guFxPipelineVuConstants + 0x38) = w[2];
    *(int *)(guFxPipelineVuConstants + 0x3C) = w[3];

    t8 = (unsigned char *)(guFxPipelineVuConstants + 0x70);
    *(u_long128 *)t8 = 0;
    *(unsigned long long *)t8 = gif1;
    PDL_LO(t8 + 0x8, 0);
    PDL_HI(t8 + 0x8, 2);
    PDL_LO(t8 + 0x9, 1);
    PDL_HI(t8 + 0x9, 5);
    PDL_LO(t8 + 0xA, 2);
    PDL_HI(t8 + 0xA, 1);
    PDL_LO(t8 + 0xB, 5);
    PDL_HI(t8 + 0xB, 2);
    PDL_LO(t8 + 0xC, 5);
    PDL_HI(t8 + 0xC, 2);
    PDL_LO(t8 + 0xD, 5);
    PDL_HI(t8 + 0xD, 2);
    PDL_LO(t8 + 0xE, 5);
    PDL_HI(t8 + 0xE, 2);
    PDL_LO(t8 + 0xF, 5);

    s5 = (unsigned char *)(guFxPipelineVuConstants + 0x90);
    *(u_long128 *)s5 = 0;
    *(unsigned long long *)s5 = gif2;
    PDL_LO(s5 + 0x8, 2);
    PDL_HI(s5 + 0x8, 1);
    PDL_LO(s5 + 0x9, 5);
    PDL_HI(s5 + 0x9, 2);
    PDL_LO(s5 + 0xA, 5);
    PDL_HI(s5 + 0xA, 2);
    PDL_LO(s5 + 0xB, 5);
    PDL_HI(s5 + 0xB, 2);
    PDL_LO(s5 + 0xC, 5);

    w[0] = ((int *)&q)[0];
    w[1] = w[0];
    w[2] = 0;
    fw[3] = 1.0f;
    *(int *)(gu3dPipelineVuConstants + 0x80) = w[0];
    *(int *)(gu3dPipelineVuConstants + 0x84) = w[1];
    *(int *)(gu3dPipelineVuConstants + 0x88) = w[2];
    *(int *)(gu3dPipelineVuConstants + 0x8C) = w[3];
    fw[0] = (float)SCREEN_OFFSET_X;
    fw[1] = (float)SCREEN_OFFSET_Y;
    fw[2] = 1.0f / (float)SCREEN_WIDTH;
    fw[3] = 1.0f / (float)SCREEN_HEIGHT;
    *(int *)(gu3dPipelineVuConstants + 0x90) = w[0];
    *(int *)(gu3dPipelineVuConstants + 0x94) = w[1];
    *(int *)(gu3dPipelineVuConstants + 0x98) = w[2];
    *(int *)(gu3dPipelineVuConstants + 0x9C) = w[3];

    w[0] = 0;
    w[1] = 0;
    w[2] = 0;
    w[3] = 0;
    *(u_long128 *)(gu3dPipelineVuConstants + 0x50) = *(u_long128 *)w;
    w[0] = 0x457FF000;
    w[1] = 0x457FF000;
    w[2] = 0x457FF000;
    w[3] = 0x457FF000;
    *(u_long128 *)(gu3dPipelineVuConstants + 0x40) = *(u_long128 *)w;
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
