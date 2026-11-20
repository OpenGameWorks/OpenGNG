// FLAGS: -str readonly
#include "PIOPFile.h"

// TODO(header): foreign declarations
class IOP_Tran {
public:
    char _pad[0x28];
};
extern "C" void *__ct__8IOP_TranFv(IOP_Tran *pThis);
extern "C" int printf(const char *fmt, ...);
extern "C" int SOUND_StopStream(unsigned int nStream);
extern char gSndEEDSSR[0x48];

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
