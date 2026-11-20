#ifndef PIOPFILE_H
#define PIOPFILE_H

#include "types.h"

class PIOPFile {
public:
    PIOPFile();
    void FrameMaintenacePartA();
    void FrameMaintenacePartB();
    void RemoveFromOpenFilesList();
    int GetSize();
    void RequestNextBuf(unsigned int nSize);
    int WaitOnBufferFill();
    int ReadEx(void *pBuf, unsigned int nSize);
    int Read(void *pBuf, unsigned int nSize);
    int OpenByFileID(unsigned int nFileID);
    int OpenEx();
    int Close();
    void InitMembers();
    ~PIOPFile();

private:
    static PIOPFile *mst_pOpenFiles[2];
    char _pad0[0x100];               // 0x000
    unsigned char m_unk100;          // 0x100
    char _pad101[0xB];               // 0x101
    int m_unk10C;                    // 0x10C
    int m_unk110;                    // 0x110 sound stream id
    int m_unk114;                    // 0x114 compared against gSndEEDSSR entries
    char _pad118[0x5C];              // 0x118
    char m_unk174[0x50];             // 0x174 two IOP_Tran entries, 0x28 bytes each
};

#endif
