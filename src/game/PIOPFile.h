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
    int RequestNextBuf(unsigned int nBuf);
    int WaitOnBufferFill();
    int ReadEx(void *pBuf, unsigned int nSize);
    void Read(void *pBuf, unsigned int nSize);
    int OpenByFileID(unsigned int nFileID);
    int OpenEx();
    int Close();
    void InitMembers();
    ~PIOPFile();

private:
    static PIOPFile *mst_pOpenFiles[2];
    char _pad0[0x100];               // 0x000
    unsigned char m_unk100;          // 0x100 nonzero while a file is open
    char _pad101[0x7];               // 0x101
    int m_unk108;                    // 0x108 file id
    int m_unk10C;                    // 0x10C file size
    int m_unk110;                    // 0x110 sound stream id
    int m_unk114;                    // 0x114 compared against gSndEEDSSR entries
    int m_unk118;                    // 0x118
    int m_unk11C;                    // 0x11C
    char _pad120[0x4];               // 0x120
    int m_unk124;                    // 0x124
    char _pad128[0x8];               // 0x128
    int m_unk130;                    // 0x130 bytes already requested
    int m_unk134[2];                 // 0x134 per buffer
    int m_unk13C[2];                 // 0x13C per buffer
    int m_unk144[2];                 // 0x144 per buffer, 2 while requested
    char _pad14C[0x4];               // 0x14C
    int m_unk150;                    // 0x150
    int m_unk154;                    // 0x154 buffer request size
    int m_unk158;                    // 0x158 copy of m_unk1C4
    int m_unk15C;                    // 0x15C
    int m_unk160;                    // 0x160
    char _pad164[0x4];               // 0x164
    int m_unk168;                    // 0x168 loading display counter
    int m_unk16C;                    // 0x16C
    int m_unk170;                    // 0x170 current slot index
    char m_unk174[0x50];             // 0x174 two IOP_Tran entries, 0x28 bytes each
    int m_unk1C4;                    // 0x1C4 buffer pointer (this + 0x200)
    int m_unk1C8;                    // 0x1C8 buffer pointer (this + 0x8200)
    char _pad1CC[0x10300 - 0x1CC];   // 0x1CC
    int m_unk10300;                  // 0x10300 magic 0x4946494C
};

#endif
