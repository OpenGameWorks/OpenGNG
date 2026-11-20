// FLAGS: -str readonly
#include "types.h"
#include "PTextureManager.h"
#include "PPakFile.h"
#include "PTextureDmaChain.h"

// TODO(header): foreign declarations
extern "C" void FlushCache(int nMode);
extern "C" void sceDmaSend(int nChannel, void *pBuf);
extern "C" void DmaWaitForCompletion__Fib(int nChannel, bool bFlag);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PTextureManager.cpp", line, #cond))
#define CDS_ASSERT_TEX(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PTexture.h", line, #cond))
// Assert whose message text is not the stringified condition.
#define CDS_ASSERT_MSG(line, cond, msg) ((cond) ? (void)0 : CdsAssert__FPciPc("PTextureManager.cpp", line, msg))
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void memset(void *, int, unsigned int);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nSize);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
void GsSetTexBaseAddr(tagGsTextureEnvironment *pEnv, unsigned int nBase);
void GsSetClutBaseAddr(tagGsTextureEnvironment *pEnv, unsigned int nBase);
extern "C" int sceDmaGetChan(int nChannel);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" char __vt__8PTexture[0x10];
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuf, unsigned int nSize);
enum eGsContext {
    eGsContext_0 = 0
};
void GsInitTexEnv(tagGsTextureEnvironment *pEnv, unsigned int nA, unsigned int nB, unsigned int nC, bool bFlag, eGsContext eCtx);
unsigned int GsGetBufferWidth(unsigned int nWidth, unsigned int nDepth);
void GsSetTexClamp(tagGsTextureEnvironment *pEnv, bool bFlag);
extern short gi32BitExtraVramTable[0x20][5][2];
extern short gi16BitExtraVramTable[0x20][5][2];

// PArray is defined by another worker. This stub holds the members that AddTexture touches.
class PArray {
public:
    int m_nCount;               // 0x00 element count
    int m_unk4;                 // 0x04
    PTexture **m_apItems;       // 0x08 element storage
    unsigned int m_nCapacity;   // 0x0C
};

// GS image transfer parameter block: a GIF tag followed by the A+D register pairs.
struct tagGsImageXferInfo {
    long long unk0;            // 0x00 GIF tag (low qword)
    unsigned char unk8;        // 0x08 low nibble holds the GIF register count
    char _pad9[7];
    long long unk10;           // 0x10 data, BITBLTBUF DBP/DBW/DPSM
    long long unk18;           // 0x18 address BITBLTBUF
    long long unk20;           // 0x20 data, TRXPOS
    long long unk28;           // 0x28 address TRXPOS
    long long unk30;           // 0x30 data, TRXREG
    long long unk38;           // 0x38 address TRXREG
    long long unk40;           // 0x40 data, TRXDIR
    long long unk48;           // 0x48 address TRXDIR
};

// DMA packet holding a GIF tag, an image transfer block and a data qword.
struct tagImageDmaPacket {
    long long unk0;            // 0x00 GIF tag (low qword)
    char _pad8[0x8];
    tagGsImageXferInfo xfer;   // 0x10 image transfer block
    long long unk60;           // 0x60 data qword
};

// FUNCTION: 0x00189350 GetTexture__15PTextureManagerFbQ28PTexture12eTextureTypei
PTexture *PTextureManager::GetTexture(bool bFlag, PTexture::eTextureType eType, int nIndex) {
    PTexture *pTex = 0;

    if (nIndex < 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x750, "iIndex >= 0");
    }
    if (bFlag) {
        return 0;
    }
    switch ((int)eType) {
    case 1:
        if (!((unsigned int)nIndex < (unsigned int)m_nDynCount)) {
            CdsAssert__FPciPc("PTextureManager.cpp", 0x75B, "iIndex < moDynamicImageTextures.GetCount()");
        }
        pTex = ((unsigned int)nIndex < (unsigned int)m_nDynCount) ? m_apDyn[nIndex] : 0;
        break;
    case 2:
        if (!((unsigned int)nIndex < (unsigned int)m_nRenderedCount)) {
            CdsAssert__FPciPc("PTextureManager.cpp", 0x760, "iIndex < moRenderedTextures.GetCount()");
        }
        pTex = ((unsigned int)nIndex < (unsigned int)m_nRenderedCount) ? m_apRendered[nIndex] : 0;
        break;
    case 3:
        CdsAssert__FPciPc("PTextureManager.cpp", 0x766, "0");
        break;
    default:
        CdsAssert__FPciPc("PTextureManager.cpp", 0x76A, "0");
        break;
    }
    return pTex;
}

// DRAFT: 0x001894D0 DecodeTextureHandle__15PTextureManagerFiRbRQ28PTexture12eTextureTypeRi
// note: 2 lines differ: original shifts a1 directly (dsll32 8/dsrl32 8), mine zero-extends nHandle first (dsll32 0/dsrl32 0); tried signed (long long) intermediate, unsigned int store cast, 64-bit local
void PTextureManager::DecodeTextureHandle(int nHandle, bool &bFlag, PTexture::eTextureType &eType, int &nIndex) {
    bFlag = (((unsigned int)nHandle & 0x80000000) >> 31) != 0;
    eType = (PTexture::eTextureType)((nHandle & 0x7F000000) >> 24);
    nIndex = (int)(((unsigned long long)nHandle << 40) >> 40);
}

// DRAFT: 0x00189510 EncodeTextureHandle__15PTextureManagerFbQ28PTexture12eTextureTypei
// note: 2 lines differ: original shifts a3 directly (dsll32 8/dsrl32 8), mine zero-extends nIndex first (dsll32 0/dsrl32 0); tried signed (long long) intermediate and an unsigned int cast
int PTextureManager::EncodeTextureHandle(bool bFlag, PTexture::eTextureType eType, int nIndex) {
    return (int)((((bFlag & 0xFF) << 31) | (eType << 24)) | (((unsigned long long)nIndex << 40) >> 40));
}

// FUNCTION: 0x00189530 KickDmaChain__15PTextureManagerFPvb
void PTextureManager::KickDmaChain(void *pBuf, bool bWait) {
    FlushCache(0);
    sceDmaSend(m_unk0, pBuf);
    if (bWait) {
        DmaWaitForCompletion__Fib(2, 0);
    }
}

// DRAFT: 0x00189590 PrepareStaticTextureForDma__15PTextureManagerFP1P19tagPs2TexDataHeaderPvPvP23tagGsTextureEnvironment
// note: 5 words differ: nWidth goes to t1 in the original (ours t0) at 0x0F8/0x0FC and the 0x128 copy direction is reversed; lw a3,unk8 precedes lb t2,unk4 at 0x1A0/0x1A8
int PTextureManager::PrepareStaticTextureForDma(u_long128 *pDmaChain, tagPs2TexDataHeader *pTexHeader, void *pvTexClutPacket, void *pvTexImagePacket, tagGsTextureEnvironment *pTexEnv) {
    int nQwords = 0;
    int nWidth;
    int nBase;
    int nW;
    int nH;
    CDS_ASSERT(0x6FD, pTexHeader);
    CDS_ASSERT(0x6FE, pvTexImagePacket);
    CDS_ASSERT(0x6FF, pTexEnv);
    CDS_ASSERT(0x700, pDmaChain);
    if (pTexHeader->type == 0x14 || pTexHeader->type == 0x13) {
        CDS_ASSERT(0x705, pvTexClutPacket);
        nQwords = 7;
        if (pTexHeader->type == 0x14) {
            nWidth = 8;
        } else {
            nWidth = 0x10;
        }
        nBase = m_unk4 / 256 + pTexHeader->unk28;
        PrepareImageDmaPacket((tagImageDmaPacket *)pDmaChain, pvTexClutPacket, pTexHeader->unk24, nWidth, nWidth, 0, nBase);
        GsSetClutBaseAddr(pTexEnv, nBase << 8);
    }
    tagImageDmaPacket *pPacket = (tagImageDmaPacket *)(pDmaChain + nQwords);
    if (pTexHeader->unk6 == 0 || pTexHeader->unk7 == 0) {
        nW = 1 << pTexHeader->unk0;
        nH = 1 << pTexHeader->unk1;
    } else {
        nW = 1 << pTexHeader->unk6;
        nH = 1 << pTexHeader->unk7;
    }
    nBase = m_unk4 / 256 + pTexHeader->unk2A;
    PrepareImageDmaPacket(pPacket, pvTexImagePacket, pTexHeader->unk8, nW, nH, pTexHeader->unk4, nBase);
    GsSetTexBaseAddr(pTexEnv, nBase << 8);
    m_unk10 += pTexHeader->unk26 << 8;
    return nQwords + 7;
}

// DRAFT: 0x001897A0 PrepareImageXferInfo__15PTextureManagerFP18tagGsImageXferInfoiiii
// note: 64 lines differ: struct and lbu/sb now match; register allocation differs (original holds tag in v1, 0xE in t2, nBlocks in v1; mine uses t2 for tag/nBlocks); tried 0xE hoisted local (andi mask appears), tag local (no change), unsigned nCtl load (lbu match)
void PTextureManager::PrepareImageXferInfo(tagGsImageXferInfo *pInfo, int nWidth, int nHeight, int nPsm, int nBase) {
    int nBlocks;
    long long nTag = 0x1000000000000004LL;
    *(u_long128 *)pInfo = 0;
    *(long long *)&pInfo->unk0 = nTag;
    unsigned int nCtl = pInfo->unk8;
    pInfo->unk8 = (nCtl & ~0xF) | 0xE;
    if (nPsm == 0x14 || nPsm == 0x13) {
        nBlocks = nWidth / 64;
        if (nBlocks < 3) {
            nBlocks = 2;
        }
    } else {
        nBlocks = nWidth / 64;
        if (nBlocks < 2) {
            nBlocks = 1;
        }
    }
    pInfo->unk18 = 0x50;
    pInfo->unk10 = ((long long)nPsm << 56) | ((long long)nBase << 32) | ((long long)nBlocks << 48);
    pInfo->unk38 = 0x52;
    pInfo->unk30 = (long long)nWidth | ((long long)nHeight << 32);
    pInfo->unk28 = 0x51;
    pInfo->unk20 = 0;
    pInfo->unk48 = 0x53;
    pInfo->unk40 = 0;
}

// DRAFT: 0x001898C0 PrepareImageDmaPacket__15PTextureManagerFP17tagImageDmaPacketPviiiii
// note: 49 lines differ, all from parameter copy order: original copies this->s6, pPacket->s5 ... nPsm->s0 in declaration order, mine puts nPsm in s6 and this in s5; tried reassigning pPacket (50), if/else store (49), pDma local with nVal (49, kept)
void PTextureManager::PrepareImageDmaPacket(tagImageDmaPacket *pPacket, void *pData, int nSize, int nWidth, int nHeight, int nPsm, int nBase) {
    tagImageDmaPacket *pDma;
    long long nVal;

    if (pPacket == 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x6B7, "pPacket");
    }
    pDma = (tagImageDmaPacket *)((unsigned int)pPacket | 0x20000000);
    pDma->unk0 = 0x10000005;
    PrepareImageXferInfo(&pDma->xfer, nWidth, nHeight, nPsm, nBase);
    nVal = 0x30000000;
    if (pData != 0) {
        nVal = ((long long)(unsigned int)pData << 32) | 0x30000000 | (long long)(nSize >> 4);
    }
    pDma->unk60 = nVal;
    asm { sync }
}

// FUNCTION: 0x001899C0 LoadTexture__15PTextureManagerFP8PPakFileP19tagPs2TexDataHeaderPPvPPv
int PTextureManager::LoadTexture(PPakFile *poFile, tagPs2TexDataHeader *pTexHeader, void **ppvTexClutPacket, void **ppvTexImagePacket) {
    CDS_ASSERT(0x678, poFile);
    CDS_ASSERT(0x679, pTexHeader);
    CDS_ASSERT(0x67A, ppvTexImagePacket);
    CDS_ASSERT(0x67B, ppvTexClutPacket);
    *ppvTexClutPacket = 0;
    *ppvTexImagePacket = 0;
    if (poFile->Read(pTexHeader, 0x2C) != 0x2C) {
        CDS_ASSERT(0x683, 0);
        return 0;
    }
    CDS_ASSERT(0x688, pTexHeader->cNumMipMaps == 0);
    *ppvTexImagePacket = __nwa__FUi(pTexHeader->unk8);
    CDS_ASSERT(0x692, *ppvTexImagePacket);
    if (pTexHeader->unk24 != 0) {
        *ppvTexClutPacket = __nwa__FUi(pTexHeader->unk24);
        CDS_ASSERT(0x699, *ppvTexClutPacket);
        if (poFile->Read(*ppvTexClutPacket, pTexHeader->unk24) != pTexHeader->unk24) {
            __dl__FPv(*ppvTexClutPacket);
            __dl__FPv(*ppvTexImagePacket);
            *ppvTexClutPacket = 0;
            *ppvTexImagePacket = 0;
            CDS_ASSERT(0x6A1, 0);
            return 0;
        }
    }
    if (poFile->Read(*ppvTexImagePacket, pTexHeader->unk8) != pTexHeader->unk8) {
        __dl__FPv(*ppvTexClutPacket);
        __dl__FPv(*ppvTexImagePacket);
        *ppvTexClutPacket = 0;
        *ppvTexImagePacket = 0;
        CDS_ASSERT(0x6AC, 0);
        return 0;
    }
    return 1;
}

// DRAFT: 0x00189BF0 AddTexture__15PTextureManagerFP8PTextureP6PArray
// note: 54 differing lines; loop guard is slt/beqz with count in a0 but entry delay slot and b to bottom test differ; tried while (55), comma init (55), i++ placement (54)
int PTextureManager::AddTexture(PTexture *pTex, PArray *pArray) {
    int nOff;
    int nCount;
    unsigned int i;
    PTexture *pEntry;

    if (pTex == 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x660, "poTexture");
    }
    if (pArray == 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x661, "poTextureArray");
    }
    nCount = pArray->m_nCount;
    nOff = 0;
    for (i = 0; (int)i < nCount;) {
        pEntry = 0;
        if (i < (unsigned int)nCount) {
            pEntry = *(PTexture **)((char *)pArray->m_apItems + nOff);
        }
        if (pEntry == 0) {
            if (i < pArray->m_nCapacity) {
                pArray->m_apItems[i] = pTex;
            }
            return EncodeTextureHandle(0, (PTexture::eTextureType)pTex->m_unkA4, i);
        }
        i++;
        nOff += 4;
    }
    if (pArray->m_nCapacity < (unsigned int)nCount) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x66F, "poTextureArray->GetCount() <= poTextureArray->GetSize()");
    }
    Add__6PArrayFPv(pArray, pTex);
    return EncodeTextureHandle(0, (PTexture::eTextureType)pTex->m_unkA4, pArray->m_nCount - 1);
}

// FUNCTION: 0x00189D30 AllocDynamicVramForTexture__15PTextureManagerFP19tagPs2TexDataHeaderiRiRiRbb
int PTextureManager::AllocDynamicVramForTexture(tagPs2TexDataHeader *pHeader, int nSecond, int &nVram, int &nTmp, bool &bOut, bool bFlag) {
    int nSize;
    int nShift5;
    PTextureBuffer *pBuf;

    ((pHeader != 0) ? (void)0 : CdsAssert__FPciPc("PTextureManager.cpp", 0x60C, "pTexInfo"));
    ((m_aBuf0.m_unk4 == m_aBuf1.m_unk4) ? (void)0 : CdsAssert__FPciPc("PTextureManager.cpp", 0x60D, "mDynamicBuffer1.ImageBuffer.iSize == mDynamicBuffer2.ImageBuffer.iSize"));
    ((m_aBuf0.m_unk10 == m_aBuf1.m_unk10) ? (void)0 : CdsAssert__FPciPc("PTextureManager.cpp", 0x60E, "mDynamicBuffer1.ClutBuffer.iSize == mDynamicBuffer2.ClutBuffer.iSize"));

    bOut = false;
    nTmp = -1;
    nVram = -1;
    nShift5 = pHeader->unk5 << 8;
    nSize = nSecond + ((pHeader->unk26 - pHeader->unk5) << 8);
    if (m_unk260 == 0) {
        if ((nSize + nShift5) < m_unkC) {
            nVram = m_aBuf0.m_unk0;
            nTmp = nVram + nSize;
            if (nSecond != 0) {
                nVram = nSecond * ((nVram + nSecond - 1) / nSecond);
            }
            bOut = true;
            FlipTextureBuffers();
            return 1;
        }
        return 0;
    }
    pBuf = m_pCurBuf;
    if (pBuf->m_unk4 < nSize) {
        return 0;
    }
    if (!bFlag) {
        if (((pBuf->m_unk8 + nSize) >= (pBuf->m_unk0 + pBuf->m_unk4)) || ((pBuf->m_unk14 + nShift5) >= (pBuf->m_unkC + pBuf->m_unk10))) {
            goto flip;
        }
    } else {
flip:
        bOut = true;
        FlipTextureBuffers();
    }
    nVram = m_pCurBuf->m_unk8;
    nTmp = m_pCurBuf->m_unk14;
    if (nSecond != 0) {
        nVram = nSecond * ((nVram + nSecond - 1) / nSecond);
    }
    m_pCurBuf->m_unk8 = m_pCurBuf->m_unk8 + nSize;
    m_pCurBuf->m_unk14 = m_pCurBuf->m_unk14 + nShift5;
    return 1;
}

// FUNCTION: 0x00189F80 FlipTextureBuffers__15PTextureManagerFv
void PTextureManager::FlipTextureBuffers() {
    m_pCurBuf = (m_pCurBuf == &m_aBuf0) ? &m_aBuf1 : &m_aBuf0;
    m_pCurBuf->m_unk8 = m_pCurBuf->m_unk0;
    m_pCurBuf->m_unk14 = m_pCurBuf->m_unkC;
    m_pCurBuf->m_unkD8 = 0;
    for (int i = 0; i < 0x30; i++) {
        if (m_aBuf0.m_apTex[i] != 0) {
            m_aBuf0.m_apTex[i]->m_unkA8 = 0;
        }
    }
    for (int i = 0; i < 0x30; i++) {
        if (m_aBuf1.m_apTex[i] != 0) {
            m_aBuf1.m_apTex[i]->m_unkA8 = 0;
        }
    }
}

// DRAFT: 0x0018A3C0 AllocRenderedTexture__15PTextureManagerFiiRbb
// note: store block at 0x108-0x118 pairs base/index registers reversed (v1 base, v0 index in ours; v0 base, v1 index in original); 7 variants tried.
int PTextureManager::AllocRenderedTexture(int nHandle, int nSecond, bool &bOut, bool bFlag) {
    PTexture::eTextureType eType = (PTexture::eTextureType)0;
    bool bDecFlag = 0;
    int nIndex = -1;
    int nTmp = -1;
    int nVram = -1;
    PTexture *pTex;

    DecodeTextureHandle(nHandle, bDecFlag, eType, nIndex);
    if (nIndex < 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x505, "aiIndex >= 0");
    }
    if (!bDecFlag && eType == 2) {
        pTex = GetTexture(bDecFlag, eType, nIndex);
        if (pTex == 0) {
            CdsAssert__FPciPc("PTextureManager.cpp", 0x50B, "apoTexture");
        }
        if (AllocDynamicVramForTexture((tagPs2TexDataHeader *)pTex->m_unk4, nSecond, nVram, nTmp, bOut, bFlag) == 0) {
            CdsAssert__FPciPc("PTextureManager.cpp", 0x513, "0");
        }
        pTex->m_unkA8 = 1;
        PTexture **ppSlot = m_pCurBuf->m_apTex;
        ppSlot += m_pCurBuf->m_unkD8;
        *ppSlot = pTex;
        m_pCurBuf->m_unkD8++;
        if (m_pCurBuf->m_unkD8 >= 0x30) {
            CdsAssert__FPciPc("PTextureManager.cpp", 0x520, "mpCurDynamicBuffer->iCurEntry < MAX_TEX_PER_BATCH");
        }
        GsSetTexBaseAddr((tagGsTextureEnvironment *)pTex->m_unk40, nVram);
    }
    return nVram;
}

// DRAFT: 0x0018A550 CreateRenderedTexture__15PTextureManagerFsssss13eTextureGroupb
// note: DIFF 84 words: slti branch sense (0x64-0x74), table index order (0x194-0x1F8), gi32/gi16 reloc addends 0x5468/0x54D8 need symbols at 0x245468/0x2454D8 (only 0x2454E0/0x245550 exist); tried separate ifs (170), positive form (84), gi32 base offset (84)
int PTextureManager::CreateRenderedTexture(short nWidth, short nHeight, short nDepth, short nX, short nY, eTextureGroup eGroup, bool bFlag)
{
    char aEnv[0x60];
    unsigned long long nTex0;
    tagPs2TexDataHeader aHeader;
    PTexture *pTex;

    if (nDepth < nX || nDepth >= 5 || nX >= 5 || (nY != 0 && nY != 10)) {
        return 0;
    }

    GsInitTexEnv((tagGsTextureEnvironment *)aEnv, nDepth, nX, nY, false, eGsContext_0);
    nTex0 = ((unsigned long long)nX << 30) |
            (((unsigned long long)nDepth << 26) |
             (((unsigned long long)nY << 20) |
              ((unsigned long long)GsGetBufferWidth(nWidth, nY) << 14))) |
            0x2000000400000000ULL;
    *(unsigned long long *)(aEnv + 0x30) = nTex0;
    GsSetTexClamp((tagGsTextureEnvironment *)aEnv, bFlag);

    memset(&aHeader, 0, 0x2C);
    aHeader.unk0 = nDepth;
    aHeader.unk1 = nX;
    aHeader.type = nY;
    aHeader.unk4 = nY;

    if (nY == 0) {
        aHeader.unk26 = (gi32BitExtraVramTable[nX][nDepth][0] + ((nWidth * nHeight) << 2)) / 256;
    } else if (nY == 10) {
        aHeader.unk26 = (gi16BitExtraVramTable[nX][nDepth][0] + ((nWidth * nHeight) << 1)) / 256;
    }

    pTex = (PTexture *)__nw__FUi(0xB0);
    if (pTex) {
        *(void **)pTex = __vt__8PTexture;
        pTex->m_unk30 = 0;
        pTex->m_unk34 = 0;
        pTex->m_unkA4 = 0;
        pTex->m_unkA8 = 0;
        pTex->m_unkAC = 0;
    }
    CDS_ASSERT(1261, pTex);

    if (pTex->InitRendered(&aHeader, (tagGsTextureEnvironment *)aEnv, eGroup)) {
        return AddTexture(pTex, (PArray *)&m_nRenderedCount);
    }
    if (pTex) {
        delete pTex;
    }
    return 0;
}

// FUNCTION: 0x0018A850 __dt__8PTextureFv
PTexture::~PTexture() {
    if (m_unk34 != 0) {
        __dla__FPv(m_unk34);
        m_unk34 = 0;
    }
    if (m_unk30 != 0) {
        __dla__FPv(m_unk30);
        m_unk30 = 0;
    }
}

// FUNCTION: 0x0018A8E0 InitRendered__8PTextureFP19tagPs2TexDataHeaderP23tagGsTextureEnvironment13eTextureGroup
int PTexture::InitRendered(tagPs2TexDataHeader *pTexHeader, tagGsTextureEnvironment *pTexEnv, eTextureGroup eGroup) {
    CDS_ASSERT_TEX(0x4D, pTexHeader);
    CDS_ASSERT_TEX(0x4E, pTexEnv);
    memcpy(m_unk4, pTexHeader, 0x2C);
    memcpy(m_unk40, pTexEnv, 0x60);
    m_unkA0 = eGroup;
    m_unkA4 = 2;
    return 1;
}

// FUNCTION: 0x0018A990 DestroyRenderedTexture__15PTextureManagerFi
void PTextureManager::DestroyRenderedTexture(int nHandle) {
    bool bFlag;
    PTexture::eTextureType eType;
    int nIndex = -1;
    DecodeTextureHandle(nHandle, bFlag, eType, nIndex);
    if (!bFlag && nIndex >= 0 && eType == 2) {
        PTexture *p = 0;
        if ((unsigned int)nIndex < (unsigned int)m_nRenderedCount) {
            p = m_apRendered[nIndex];
        }
        if (p != 0) {
            delete p;
            if ((unsigned int)nIndex < (unsigned int)m_unk25C) {
                m_apRendered[nIndex] = 0;
            }
        }
    }
}

// DRAFT: 0x0018AA60 UnloadAllRenderedTextures__15PTextureManagerFv
// note: 32 words differ: frame 0x40 vs 0x50 (original keeps this in s3 and a byte-offset induction in s2, needing a 4th saved reg); tried while-loop, outer nCount>0 guard removed, 0<nCount guard (kept, 44->32 words), i declared outside for
void PTextureManager::UnloadAllRenderedTextures() {
    int nCount = m_nRenderedCount;
    if (0 < nCount) {
        for (int i = 0; i < nCount; i++) {
            PTexture *p = 0;
            if ((unsigned int)i < (unsigned int)m_nRenderedCount) {
                p = m_apRendered[i];
            }
            if (p != 0) {
                delete p;
            }
        }
    }
    if (m_apRendered != 0) {
        m_nRenderedCount = 0;
        m_unk254 = 0;
    }
}

// FUNCTION: 0x0018AB10 UnloadDynamicTexture__15PTextureManagerFi
void PTextureManager::UnloadDynamicTexture(int nHandle) {
    bool bFlag;
    PTexture::eTextureType eType;
    int nIndex = -1;
    DecodeTextureHandle(nHandle, bFlag, eType, nIndex);
    if (!bFlag && nIndex >= 0 && eType == 1) {
        PTexture *p = 0;
        if ((unsigned int)nIndex < (unsigned int)m_nDynCount) {
            p = m_apDyn[nIndex];
        }
        if (p != 0) {
            delete p;
            if ((unsigned int)nIndex < (unsigned int)m_unk1E8) {
                m_apDyn[nIndex] = 0;
            }
        }
    }
}

// FUNCTION: 0x0018ABE0 UnloadAllDynamicTextures__15PTextureManagerFv
void PTextureManager::UnloadAllDynamicTextures() {
    int i = 0;
    int nCount = m_nDynCount;
    if (0 < nCount) {
        int nOff = 0;
        do {
            PTexture *p = 0;
            if ((unsigned int)i < (unsigned int)m_nDynCount) {
                p = *(PTexture **)((char *)m_apDyn + nOff);
            }
            if (p != 0) {
                delete p;
            }
            i++;
            nOff += 4;
        } while (i < nCount);
    }
    if (m_apDyn != 0) {
        m_nDynCount = 0;
        m_unk1E0 = 0;
    }
}

// DRAFT: 0x0018AC90 UnloadDynamicTextures__15PTextureManagerF13eTextureGroup
// note: 16 lines differ: one missing nop after the jalr and a nop at the loop-tail join (original has both, ours does not); tried 0<nCount guard (25), VFunc2 before dtor (24), operand swap on eGroup compare (24, reverted), m_unk1E8 > i (24, reverted), removing inner null check (24, reverted)
void PTextureManager::UnloadDynamicTextures(eTextureGroup eGroup) {
    int nCount;
    int nOff;
    unsigned int i;
    PTexture *pEntry;

    nCount = m_nDynCount;
    i = 0;
    if (0 < nCount) {
        nOff = 0;
        do {
            pEntry = 0;
            if (i < (unsigned int)m_nDynCount) {
                pEntry = *(PTexture **)((char *)m_apDyn + nOff);
            }
            if (pEntry != 0 && pEntry->m_unkA0 == (int)eGroup) {
                if (pEntry != 0) {
                    delete pEntry;
                }
                if (i < m_unk1E8) {
                    *(PTexture **)((char *)m_apDyn + nOff) = 0;
                }
            }
            i++;
            nOff += 4;
        } while ((int)i < nCount);
    }
}

// Header of a dynamic texture file, read as one 0x20-byte block.
struct tagDynTexFileHeader {
    int iMagic;                 // 0x00 must be 0x13246879
    int unk4;                   // 0x04
    int iNumTextures;           // 0x08
    char _pad0C[0x20 - 0x0C];   // 0x0C
};

// DRAFT: 0x0018AD70 LoadDynamicTextures__15PTextureManagerFP8PPakFile13eTextureGroupP6PArray
// note: DIFF 152; frame 0x238 vs 0x264, prologue keeps 7 saves (original 9: fp, s7..s0) and maps eGroup/pArray to s3/s2; piCount, local reorder and in-loop clut/image zeroing did not change the count.
int PTextureManager::LoadDynamicTextures(PPakFile *poFile, eTextureGroup eGroup, PArray *pArray) {
    tagDynTexFileHeader aFileHeader;
    tagPs2TexDataHeader aTexHeader;
    char aTexEnv[0x60];
    void *pvTexClutPacket;
    void *pvTexImagePacket;
    PTexture *pTex;
    int i;

    CDS_ASSERT_MSG(0x433, poFile, "pMemFile");
    CDS_ASSERT_MSG(0x434, pArray, "pTextureHandles");
    if (Read__7PCDFileFPvUi((void *)poFile, &aFileHeader, 0x20) != 0x20) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x43A, "0");
        return 0;
    }
    if (aFileHeader.iMagic == 0x13246879) {
        for (i = 0; i < aFileHeader.iNumTextures; i++) {
            if (!LoadTexture(poFile, &aTexHeader, &pvTexClutPacket, &pvTexImagePacket)) {
                return 0;
            }
            GsInitTexEnv((tagGsTextureEnvironment *)aTexEnv, aTexHeader.unk0, aTexHeader.unk1, aTexHeader.type, false, (eGsContext)0);
            pTex = (PTexture *)__nw__FUi(0xB0);
            if (pTex != 0) {
                *(void **)pTex = (void *)__vt__8PTexture;
                pTex->m_unk30 = 0;
                pTex->m_unk34 = 0;
                pTex->m_unkA4 = 0;
                pTex->m_unkA8 = 0;
                pTex->m_unkAC = 0;
            }
            CDS_ASSERT_MSG(0x452, pTex, "apoTexture");
            CDS_ASSERT_TEX(0x3D, pvTexImagePacket);
            memcpy(pTex->m_unk4, &aTexHeader, 0x2C);
            memcpy(pTex->m_unk40, aTexEnv, 0x60);
            pTex->m_unk30 = pvTexClutPacket;
            pTex->m_unk34 = pvTexImagePacket;
            pTex->m_unkA0 = (int)eGroup;
            pTex->m_unkA4 = 1;
            Add__6PArrayFPv(pArray, (void *)AddTexture(pTex, (PArray *)&m_nDynCount));
        }
    }
    CDS_ASSERT_MSG(0x45D, pArray->m_nCount == aFileHeader.iNumTextures, "pTextureHandles->GetCount() == aFileHeader.iNumTextures");
    return 1;
}

// FUNCTION: 0x0018AFE0 UnloadStaticTextures__15PTextureManagerFv
void PTextureManager::UnloadStaticTextures() {
    if (m_unk1D0 != 0) {
        __dla__FPv(m_unk1D0);
        m_unk1D0 = 0;
    }
    m_unk1D4 = 0;
    m_unk10 = 0;
    m_unk1D8 = 0;
}

// FUNCTION: 0x0018B410 ResetDynamicBuffers__15PTextureManagerFv
void PTextureManager::ResetDynamicBuffers() {
    int i = 0;
    int nOff = 0;
    do {
        PTexture *p = *(PTexture **)((char *)this + nOff + 0x2C);
        if (p != 0) {
            p->m_unkA8 = 0;
        }
        i++;
        nOff += 4;
    } while (i < 0x30);
    i = 0;
    nOff = 0;
    do {
        PTexture *p = *(PTexture **)((char *)this + nOff + 0x108);
        if (p != 0) {
            p->m_unkA8 = 0;
        }
        i++;
        nOff += 4;
    } while (i < 0x30);
    memset(m_aBuf0.m_apTex, 0, 0xC0);
    memset(m_aBuf1.m_apTex, 0, 0xC0);
    m_aBuf0.m_unkD8 = 0;
    m_aBuf1.m_unkD8 = 0;
    m_aBuf0.m_unk8 = m_aBuf0.m_unk0;
    m_aBuf0.m_unk14 = m_aBuf0.m_unkC;
    m_aBuf1.m_unk8 = m_aBuf1.m_unk0;
    m_aBuf1.m_unk14 = m_aBuf1.m_unkC;
    m_pCurBuf = &m_aBuf0;
}

// FUNCTION: 0x0018B4E0 PrepareDynamicClutPacket__15PTextureManagerFP12tagGsClut256P23tagGsTextureEnvironmentbP12PDisplayList
void PTextureManager::PrepareDynamicClutPacket(tagGsClut256 *pClut, tagGsTextureEnvironment *pTexEnv, bool bFlag, PDisplayList *pDisplayList) {
    char header[0x38];
    int nVram = 0;
    int nTmp = 0;
    if (pClut == 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x349, "pClut");
    }
    if (pTexEnv == 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x34A, "pTexEnv");
    }
    if (pDisplayList == 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x34B, "pDisplayList");
    }
    memset(header, 0, 0x2C);
    *(signed char *)(header + 5) = 4;
    *(short *)(header + 0x26) = *(signed char *)(header + 5);
    bFlag = false;
    if (AllocDynamicVramForTexture((tagPs2TexDataHeader *)header, 0, nVram, nTmp, bFlag, false) == 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x358, "0");
    }
    PrepareImageXferInfo((tagGsImageXferInfo *)pClut, 0x10, 0x10, 0, nTmp / 256);
    GsSetClutBaseAddr(pTexEnv, nTmp);
}

// DRAFT: 0x0018C070 SetTexture__15PTextureManagerFiP12PDisplayListPP23tagGsTextureEnvironmentRb
// note: 139 words differ: prologue s1/s2 copy order, pHeader/pDisplayList register swap, store order 0x17C-0x1A8, lb vs lbu at 0xF0, branch offsets 0x50/0xD8/0x108
void PTextureManager::SetTexture(int nHandle, PDisplayList *pDisplayList, tagGsTextureEnvironment **ppEnv, bool &bOut) {
    PTexture::eTextureType eType = PTexture::eTextureType_Unknown;
    bool bFlag = false;
    int nIndex = -1;
    int nTmp;
    int nVram;
    bool bLocal;

    if (nHandle == 0) {
        *ppEnv = (tagGsTextureEnvironment *)m_unk1F0;
        bOut = false;
        return;
    }
    DecodeTextureHandle(nHandle, bFlag, eType, nIndex);
    CDS_ASSERT_MSG(0x150, nIndex >= 0, "aiIndex >= 0");
    if (bFlag) {
        CDS_ASSERT_MSG(0x154, nIndex < m_unk1D4, "aiIndex < miNumStaticTextures");
        *ppEnv = (tagGsTextureEnvironment *)((char *)m_unk1D0 + nIndex * 0x60);
        bOut = false;
        return;
    }
    PTexture *pTex = GetTexture(bFlag, eType, nIndex);
    tagPs2TexDataHeader *pHeader = (tagPs2TexDataHeader *)pTex->m_unk4;
    if (pTex->m_unkA8) {
        *ppEnv = (tagGsTextureEnvironment *)pTex->m_unk40;
        bOut = false;
        return;
    }
    CDS_ASSERT_MSG(0x172, eType == 1, "aeType == PTexture::TEXTURE_IMAGE");
    CDS_ASSERT_MSG(0x180, AllocDynamicVramForTexture(pHeader, 0, nVram, nTmp, bLocal, false), "0");
    pTex->m_unkA8 = 1;
    m_pCurBuf->m_apTex[m_pCurBuf->m_unkD8] = pTex;
    m_pCurBuf->m_unkD8++;
    CDS_ASSERT_MSG(0x189, m_pCurBuf->m_unkD8 < 0x30, "mpCurDynamicBuffer->iCurEntry < MAX_TEX_PER_BATCH");
    if (bLocal) {
        ((PTextureDmaChain *)((char *)pDisplayList + 0xA3380))->NextBatch();
    }
    if (eType == 1) {
        tagImageDmaPacket *pClut;
        tagImageDmaPacket *pImage;
        if (pHeader->type == 0x13 || pHeader->type == 0x14) {
            pClut = (tagImageDmaPacket *)((PTextureDmaChain *)((char *)pDisplayList + 0xA3380))->AllocEntries(0xE);
            CDS_ASSERT_MSG(0x19E, pClut, "apDmaChain");
            pImage = (tagImageDmaPacket *)((char *)pClut + 0x70);
        } else {
            pImage = (tagImageDmaPacket *)((PTextureDmaChain *)((char *)pDisplayList + 0xA3380))->AllocEntries(7);
            CDS_ASSERT_MSG(0x1A7, pImage, "apDmaChain");
            pClut = 0;
        }
        if (pClut) {
            int nDim = (pHeader->type == 0x14) ? 8 : 0x10;
            PrepareImageDmaPacket(pClut, pTex->m_unk30, *(short *)(pTex->m_unk4 + 0x24), nDim, nDim, 0, nTmp / 256);
            GsSetClutBaseAddr((tagGsTextureEnvironment *)pTex->m_unk40, nTmp);
        }
        int nW;
        int nH;
        if (pHeader->unk6 != 0 && pHeader->unk7 != 0) {
            nW = 1 << pHeader->unk6;
            nH = 1 << pHeader->unk7;
        } else {
            nW = 1 << pHeader->unk0;
            nH = 1 << pHeader->unk1;
        }
        PrepareImageDmaPacket(pImage, pTex->m_unk34, *(int *)(pTex->m_unk4 + 8), nW, nH, pHeader->unk4, nVram / 256);
    }
    GsSetTexBaseAddr((tagGsTextureEnvironment *)pTex->m_unk40, nVram);
    *ppEnv = (tagGsTextureEnvironment *)pTex->m_unk40;
    bOut = bLocal;
}

// FUNCTION: 0x0018C400 GetTexEnv__15PTextureManagerFi
tagGsTextureEnvironment *PTextureManager::GetTexEnv(int nHandle) {
    PTexture::eTextureType eType = PTexture::eTextureType_Unknown;
    bool bFlag = false;
    int nIndex = -1;

    if (nHandle == 0) {
        return (tagGsTextureEnvironment *)((char *)this + 0x1F0);
    }
    DecodeTextureHandle(nHandle, bFlag, eType, nIndex);
    if (nIndex < 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x9F, "aiIndex >= 0");
    }
    if (bFlag) {
        if (nIndex >= m_unk1D4) {
            CdsAssert__FPciPc("PTextureManager.cpp", 0xA3, "aiIndex < miNumStaticTextures");
        }
        return (tagGsTextureEnvironment *)((char *)m_unk1D0 + nIndex * 0x60);
    }
    {
        PTexture *pTex = GetTexture(bFlag, eType, nIndex);
        if (pTex != 0) {
            return (tagGsTextureEnvironment *)((char *)pTex + 0x40);
        }
    }
    return 0;
}

// FUNCTION: 0x0018C4E0 Shutdown__15PTextureManagerFv
void PTextureManager::Shutdown() {
    UnloadStaticTextures();
    UnloadAllDynamicTextures();
    UnloadAllRenderedTextures();
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk0 = 0;
}

// DRAFT: 0x0018C530 Init__15PTextureManagerFiii
// note: 50 lines differ. Assert now uses CDS_ASSERT (slt/bnez/literal match) but s-register map is reversed: original this=s0, nDynamic=s1, nStatic=s2, nTexMemStart=s3; ours this=s3, nDynamic=s0. Tried nHalf placement, n/2 form, unused local copies, assert after member stores (92, worse), sum order (a1+a2)+a3 (50, no change).
int PTextureManager::Init(int nTexMemStart, int nStaticSize, int nDynamicSize) {
    CDS_ASSERT(0x46, nDynamicSize + (nTexMemStart + nStaticSize) < 0x400001);
    m_unk4 = nTexMemStart;
    m_unk8 = nStaticSize;
    m_unkC = nDynamicSize;
    m_aBuf0.m_unk0 = m_unk4 + nStaticSize;
    m_aBuf0.m_unk8 = m_aBuf0.m_unk0;
    m_aBuf0.m_unk4 = nDynamicSize / 2 - 0x8000;
    m_aBuf0.m_unkC = m_aBuf0.m_unk0 + m_aBuf0.m_unk4;
    m_aBuf0.m_unk14 = m_aBuf0.m_unkC;
    m_aBuf0.m_unk10 = 0x8000;
    m_aBuf1.m_unk0 = m_aBuf0.m_unkC + m_aBuf0.m_unk10;
    m_aBuf1.m_unk8 = m_aBuf1.m_unk0;
    m_aBuf1.m_unk4 = m_aBuf0.m_unk4;
    m_aBuf1.m_unkC = m_aBuf1.m_unk0 + m_aBuf1.m_unk4;
    m_aBuf1.m_unk14 = m_aBuf1.m_unkC;
    m_aBuf1.m_unk10 = 0x8000;
    m_pCurBuf = &m_aBuf0;
    UnloadStaticTextures();
    m_unk1D0 = 0;
    m_unk1D4 = 0;
    m_unk1D8 = 0;
    m_unk0 = sceDmaGetChan(2);
    if (m_unk0 == 0) {
        CdsAssert__FPciPc("PTextureManager.cpp", 0x7A, "mpDmaGif");
    }
    GsInitTexEnv((tagGsTextureEnvironment *)m_unk1F0, 0, 0, 0, false, (eGsContext)0);
    return 1;
}

// FUNCTION: 0x0018C6B0 __dt__15PTextureManagerFv
PTextureManager::~PTextureManager() {
    Shutdown();
    __dt__6PArrayFv((char *)this + 0x250, -1);
    __dt__6PArrayFv((char *)this + 0x1DC, -1);
}

// DRAFT: 0x0018C720 __ct__15PTextureManagerFv
// note: 48 words differ: this spilled to 0x1C(sp) and frame is 0x20 vs 0x40 (only s0 kept, orig s0..s2); member-address and pointer-local variants both 48 words
PTextureManager::PTextureManager() {
    __ct__6PArrayFv(&m_nDynCount);
    __ct__6PArrayFv(&m_nRenderedCount);
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    memset(&m_aBuf0, 0, 0xDC);
    memset(&m_aBuf1, 0, 0xDC);
    m_pCurBuf = 0;
    m_unk1D0 = 0;
    m_unk1D4 = 0;
    m_unk1D8 = 0;
    m_unk0 = 0;
    Allocate__6PArrayFUi(&m_nDynCount, 0x180);
    Allocate__6PArrayFUi(&m_nRenderedCount, 0x40);
    m_unk260 = 1;
}
