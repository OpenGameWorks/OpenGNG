// FLAGS: -str readonly
#include "PIOPFile.h"
#include "Interface.h"
#include "IOPTransactionManager.h"

// TODO(header): foreign declarations
extern Interface gInterface;
extern IOPTransactionManager gIOPTransactionManager;
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void *__ct__8IOP_TranFv(IOP_Tran *pThis);
extern "C" void IOP_TranSet__8IOP_TranFUiUiUiUiUiUiUi(IOP_Tran *pThis, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int printf(const char *fmt, ...);
extern "C" int sprintf(char *pDst, const char *fmt, ...);
extern "C" char *strcpy(char *pDst, const char *pSrc);
extern "C" int SOUND_StopStream(unsigned int nStream);
extern char gSndEEDSSR[0x48];
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void __dl__FPv(void *pMem);
extern "C" int SOUND_MakeSoundStreamRef();
extern "C" int SOUND_MakeStreamTransactionID();
extern "C" int SOUND_DataDestEEBuffered(unsigned int, int, unsigned int, unsigned int, int, unsigned int, unsigned int, short, long long, long long);
extern "C" void FlushCache(int nMode);
extern "C" int TranProcess__21IOPTransactionManagerFP8IOP_TranUi(IOPTransactionManager *pThis, IOP_Tran *pTran, unsigned int nTranID);
extern "C" void IOP_TranReset__8IOP_TranFv(IOP_Tran *pThis);

// FUNCTION: 0x001DAAC0 FrameMaintenacePartA__8PIOPFileFv
void PIOPFile::FrameMaintenacePartA() {
    unsigned int i;
    for (i = 0; i < 2; i++) {
        PIOPFile *pFile = mst_pOpenFiles[i];
        if (pFile != 0) {
            unsigned int j = 0;
            int off = 0;
            while (j < 2) {
                if (*(int *)(gSndEEDSSR + off) == pFile->m_unk114) {
                    break;
                }
                j++;
                off += 0x24;
            }
        }
    }
}

// FUNCTION: 0x001DAB30 RemoveFromOpenFilesList__8PIOPFileFv
void PIOPFile::RemoveFromOpenFilesList() {
    unsigned int i = 0;
    do {
        if (mst_pOpenFiles[i] == this) {
            mst_pOpenFiles[i] = 0;
        }
        i++;
    } while (i < 2);
}

// FUNCTION: 0x001DAB70 GetSize__8PIOPFileFv
int PIOPFile::GetSize() {
    if (m_unk100 == 0) {
        printf("PIOPFile::GetSize failed, no file open\n");
        return 0;
    }
    printf("PIOPFile::GetSize = %u\n", m_unk10C);
    return m_unk10C;
}

// DRAFT: 0x001DABD0 RequestNextBuf__8PIOPFileFUi
// note: 69 words differ; the store, search loop and an 8-byte size deficit remain (unsigned guard tried, byte-offset store tried)
int PIOPFile::RequestNextBuf(unsigned int nBuf) {
    IOP_Tran tran;
    __ct__8IOP_TranFv(&tran);
    if ((unsigned int)m_unk130 < (unsigned int)m_unk10C && m_unk118 == 0) {
        unsigned int nSize = m_unk10C - m_unk130;
        if (nSize > 0x8000) {
            nSize = 0x8000;
        }
        *(m_unk144 + nBuf) = 2;
        m_unk118 = SOUND_MakeStreamTransactionID();
        if (nBuf != 0 && nBuf != 1) {
            CdsAssert("PIOPFile.cpp", 0x219, "0");
        }
        IOP_TranSet__8IOP_TranFUiUiUiUiUiUiUi(&tran, m_unk118, m_unk114, (&m_unk1C4)[nBuf], m_unk130, nSize, 0, nBuf);
        unsigned int i = 0;
        IOP_Tran *pSlot;
        do {
            pSlot = (IOP_Tran *)(m_unk174 + (m_unk170 + i) * 0x28);
            if (pSlot->m_unk0 == 0) {
                break;
            }
            i++;
        } while (i < 2);
        if (i >= 2) {
            CdsAssert("PIOPFile.cpp", 0x22A, "ii < kNEEBuffers");
        }
        memcpy(pSlot, &tran, 0x28);
        gIOPTransactionManager.TranAdd(&tran);
    }
    return 0;
}

// DRAFT: 0x001DAD40 WaitOnBufferFill__8PIOPFileFv
// note: 131 words differ; the loop entry lacks the `b` to the bottom test (ours folds bLoop==1), so every later instruction is shifted by one; `!= 0`, the delay-slot bLoop and post-ctor bLoop variants tried
int PIOPFile::WaitOnBufferFill() {
    int bLoop = 1;
    IOP_Tran tran;
    __ct__8IOP_TranFv(&tran);
    FlushCache(0);
    asm {
        sync
        sync.p
    }
    if (m_unk170 < 0) {
        CdsAssert("PIOPFile.cpp", 0x1BD, "mTranIDRingHead >= 0");
    }
    unsigned int nTranID = ((IOP_Tran *)(m_unk174 + m_unk170 * 0x28))->m_unk0;
    IOP_Tran *pSlot = (IOP_Tran *)(m_unk174 + m_unk170 * 0x28);
    m_unk168 = 0;
    while (bLoop) {
        gInterface.LoadingDisplay(m_unk168++, 0);
        FlushCache(0);
        asm {
            sync
        }
        m_unk16C++;
        char *pEntry = gSndEEDSSR + (m_unk110 - 2) * 0x24;
        if (*(int *)pEntry == m_unk114 && (*(int *)(pEntry + 0xC) & 0x18) == 0x18) {
            if (TranProcess__21IOPTransactionManagerFP8IOP_TranUi(&gIOPTransactionManager, &tran, nTranID) == 0) {
                if (tran.m_unk24 != m_unk154) {
                    CdsAssert("PIOPFile.cpp", 0x1D5, "retrievedIOP_Tran.mTranEEBufNum == muTranEEBufNum");
                }
                if (m_unk144[m_unk154] != 2) {
                    CdsAssert("PIOPFile.cpp", 0x1D6, "kBufStatusFilling == muBufStatus[muTranEEBufNum]");
                }
                m_unk134[m_unk154] = m_unk130;
                m_unk13C[m_unk154] = tran.m_unk20;
                m_unk144[m_unk154] = 1;
                m_unk150++;
                m_unk130 += tran.m_unk20;
                m_unk15C += 0x7FFF;
                m_unk15C++;
                m_unk11C = m_unk118;
                m_unk118 = 0;
                m_unk154 = (m_unk154 == 0);
                if (tran.m_unk20 < 0x8000 && m_unk130 != m_unk10C) {
                    CdsAssert("PIOPFile.cpp", 0x1E6, "muLogicalCachePosLim == muFileSize");
                }
                IOP_TranReset__8IOP_TranFv(pSlot);
                bLoop = 0;
            }
        }
    }
    return 0;
}

// DRAFT: 0x001DAFC0 ReadEx__8PIOPFileFPvUi
// note: DIFF 205 words, size 0x344 vs 0x394. Prologue save order and s-register map differ, entry branch lands in loop top not bottom test, EOF exit returns through v0 path. Tried: while(nDone<nSize) (205), while(nRemaining!=0&&nDone<nSize) (209), pBuf direct copy (205)
int PIOPFile::ReadEx(void *pBuf, unsigned int nSize) {
    unsigned int nDone = 0;
    unsigned int nRemaining = nSize;
    char *pDst = (char *)pBuf;
    if ((unsigned int)m_unk104 >= (unsigned int)m_unk10C) {
        printf("Read %s failed, no data left\n", this);
        m_unk102 = 1;
        return 0;
    }
    while (nDone < nSize) {
        if ((unsigned int)m_unk104 >= (unsigned int)m_unk10C) {
            m_unk101 = 1;
            m_unk102 = 1;
            return nDone;
        }
        if (m_unk144[m_unk120] != 1 && (unsigned int)m_unk130 < (unsigned int)m_unk10C) {
            WaitOnBufferFill();
            RequestNextBuf(m_unk154);
        }
        if (m_unk104 < m_unk134[m_unk120]) {
            CdsAssert("PIOPFile.cpp", 0x16A, "muLogicalReadPosition >= muBufLogicalStart[muBufNumCur]");
        }
        if (!(m_unk104 < m_unk134[m_unk120] + m_unk13C[m_unk120])) {
            CdsAssert("PIOPFile.cpp", 0x16B, "muLogicalReadPosition < muBufLogicalStart[muBufNumCur] + muBufActiveSize[muBufNumCur]");
        }
        if (!(m_unk128 < 0x8000)) {
            CdsAssert("PIOPFile.cpp", 0x16D, "muWithinBufferReadOffset < kBufferSize");
        }
        if (!(m_unk128 < m_unk13C[m_unk120])) {
            CdsAssert("PIOPFile.cpp", 0x16E, "muWithinBufferReadOffset < muBufActiveSize[muBufNumCur]");
        }
        if (!(m_unk13C[m_unk120] <= 0x8000)) {
            CdsAssert("PIOPFile.cpp", 0x16F, "muBufActiveSize[muBufNumCur] <= kBufferSize");
        }
        unsigned int nAvail = (unsigned int)(m_unk13C[m_unk120] - m_unk128);
        unsigned int nChunk;
        int bEnd;
        if (nRemaining < nAvail) {
            nChunk = nRemaining;
            bEnd = 0;
        } else {
            nChunk = nAvail;
            bEnd = 1;
        }
        FlushCache(0);
        asm {
            sync
            sync.p
        }
        memcpy(pDst, (void *)(((unsigned int)(&m_unk1C4)[m_unk120] + m_unk128) | 0x20000000), nChunk);
        nDone += nChunk;
        pDst += nChunk;
        m_unk104 += nChunk;
        m_unk128 += nChunk;
        nRemaining -= nChunk;
        if (m_unk104 >= m_unk10C) {
            m_unk102 = 1;
        }
        if (bEnd) {
            if (m_unk128 >= 0x8000) {
                m_unk144[m_unk120] = 0;
                m_unk13C[m_unk120] = 0;
                m_unk128 = 0;
                int nOld = m_unk120;
                m_unk120 = m_unk124;
                m_unk124 = nOld;
            } else if (nRemaining != 0) {
                CdsAssert("PIOPFile.cpp", 0x19B, "0 == uRemaining");
            }
        }
    }
    return nDone;
}

// FUNCTION: 0x001DB360 Read__8PIOPFileFPvUi
void PIOPFile::Read(void *pBuf, unsigned int nSize) {
    if (pBuf == 0) {
        CdsAssert("PIOPFile.cpp", 0x115, "pBuffer");
    }
    if (m_unk10C == 0) {
        CdsAssert("PIOPFile.cpp", 0x116, "muFileSize");
    }
    if (nSize == 0) {
        CdsAssert("PIOPFile.cpp", 0x117, "nSize");
    }
    m_unk168 = 0;
    int nRead = ReadEx(pBuf, nSize);
    if (nRead != nSize) {
        do {
            gInterface.LoadingDisplay(m_unk168++, 0);
            m_unk16C++;
            nRead = ReadEx(pBuf, nSize);
        } while (nRead != nSize);
    }
}

// FUNCTION: 0x001DB450 OpenByFileID__8PIOPFileFUi
int PIOPFile::OpenByFileID(unsigned int nFileID) {
    char buf[0x100];
    if (m_unk10C != 0) {
        printf("File %s not closed\n", m_unk10C);
    }
    if (m_unk10C != 0) {
        CdsAssert("PIOPFile.cpp", 0xF8, "0 == muFileSize");
    }
    InitMembers();
    sprintf(buf, "FName_OpenedByFileID_%d", nFileID);
    strcpy((char *)this, buf);
    m_unk108 = nFileID;
    OpenEx();
    RequestNextBuf(m_unk154);
    return 1;
}

// FUNCTION: 0x001DB500 OpenEx__8PIOPFileFv
int PIOPFile::OpenEx() {
    m_unk114 = SOUND_MakeSoundStreamRef();
    m_unk118 = SOUND_MakeStreamTransactionID();
    m_unk154 = 0;
    m_unk158 = m_unk1C4;
    m_unk160 = 0;
    SOUND_DataDestEEBuffered(m_unk110, (unsigned int)m_unk108, (unsigned int)m_unk114, 0, -1, (unsigned int)m_unk158, 0x8000, 2, 0, m_unk118);
    m_unk168 = 0;
    char *pEntry;
    do {
        gInterface.LoadingDisplay(m_unk168++, 0);
        m_unk16C++;
        pEntry = gSndEEDSSR + (m_unk110 - 2) * 0x24;
    } while (*(int *)pEntry != m_unk114 || (*(int *)(pEntry + 0xC) & 0x18) != 0x18);
    m_unk118 = 0;
    m_unk100 = 1;
    m_unk10C = *(int *)(pEntry + 8);
    m_unk144[0] = 2;
    return 0;
}

// FUNCTION: 0x001DB600 Close__8PIOPFileFv
int PIOPFile::Close() {
    printf("Close\n");
    if (m_unk100 == 0) {
        printf("Close called with no file being open\n");
        return 1;
    }
    SOUND_StopStream(m_unk110);
    RemoveFromOpenFilesList();
    m_unk100 = 0;
    m_unk10C = 0;
    return 1;
}

// FUNCTION: 0x001DB670 InitMembers__8PIOPFileFv
void PIOPFile::InitMembers() {
    memset(this, 0, (char *)&m_unk10300 - (char *)this + 4);
    memset(this, 0, (char *)&m_unk1C4 - (char *)this);
    m_unk110 = 2;
    m_unk124 = 1;
    m_unk1C4 = (int)((char *)this + 0x200);
    m_unk1C8 = (int)((char *)this + 0x8200);
    m_unk10300 = 0x4946494C;
}

// FUNCTION: 0x001DB700 __dt__8PIOPFileFv
PIOPFile::~PIOPFile() {
    if (m_unk100 != 0) {
        Close();
    }
    m_unk10300 = 0;
}

// DRAFT: 0x001DB770 __ct__8PIOPFileFv
// note: loop bottom lacks the nop after sltu (ours 0x54 bytes, original 0x58); tried unsigned, char*, int compares and a for loop, none fixed it
PIOPFile::PIOPFile() {
    IOP_Tran *pTran = (IOP_Tran *)m_unk174;
    do {
        __ct__8IOP_TranFv(pTran);
        pTran++;
    } while (pTran < (IOP_Tran *)((char *)this + 0x1C4));
    InitMembers();
}
