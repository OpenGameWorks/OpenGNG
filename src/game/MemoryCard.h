#ifndef MEMORYCARD_H
#define MEMORYCARD_H

#include "types.h"

// MemoryCard has no base class and no vtable; every member is named by its offset from the object start.
class MemoryCard {
public:
    int CheckLoadData();
    int CheckSum(unsigned char *pBuf);
    int CheckFiles();
    void ResetFileStatus();
    void IssueCommand(const char *pCmd);
    void RemoveMCText();
    void DisplayMCText(int nArg);
    void InitLoadGame();
    void DeleteScreen();

    char _pad000[0x1DC];
    int m_unk1DC;                   // 0x1DC command word, written as (pCmd | 0x30000000)
    int m_unk1E0;                   // 0x1E0
    short m_unk1E4;                 // 0x1E4
    short m_unk1E6;                 // 0x1E6
    char _pad1E8[0x1EC - 0x1E8];
    int m_unk1EC;                   // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    char m_unk1F4;                  // 0x1F4 cleared by InitLoadGame
    char m_unk1F5;                  // 0x1F5
    char m_unk1F6;                  // 0x1F6
    char _pad1F7[0x1FA - 0x1F7];
    char m_unk1FA;                  // 0x1FA file status byte, -1 after ResetFileStatus
    char m_unk1FB;                  // 0x1FB
    char m_unk1FC;                  // 0x1FC
    char m_unk1FD;                  // 0x1FD
    char m_unk1FE;                  // 0x1FE
    char m_unk1FF;                  // 0x1FF
    int m_unk200;                   // 0x200 flag, nonzero while the MC text is shown
};

#endif
