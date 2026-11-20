// FLAGS: -str readonly
#include "PIOPFile.h"
#include "Interface.h"

// TODO(header): foreign declarations
extern Interface gInterface;
void CdsAssert(char *pFile, int nLine, char *pExpr);
class IOP_Tran {
public:
    char _pad[0x28];
};
extern "C" void *__ct__8IOP_TranFv(IOP_Tran *pThis);
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
    m_unk144 = 2;
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
