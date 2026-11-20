#ifndef MEMORYCARD_H
#define MEMORYCARD_H

#include "types.h"

// Forward declaration of the nested player record that InitSaveGame copies from.
class Player {
public:
    class PlayerData;
};

// 10-byte setting record. MemoryCard keeps one copy at m_unk218 and one at m_unk6D8.
class MemorySetting {
public:
    unsigned char m_unk0;       // 0x00 compared against DefaultSetting
    unsigned char m_unk1;       // 0x01 vibrate flag
    char _pad2[2];
    signed char m_unk4;         // 0x04 main music relative volume
    signed char m_unk5;         // 0x05 effects relative volume
    short m_unk6;               // 0x06 TV offset X
    short m_unk8;               // 0x08 TV offset Y
};

// Virtual interface stored at 0x3F6C; LoadGame calls its slot at 0x18.
class MemoryCardView;
class PMNode;
class FontNode;

// MemoryCard has no base class and no vtable; every member is named by its offset from the object start.
class MemoryCard {
public:
    void UpdateHeader(unsigned char nVal);
    int SetSetting(MemorySetting *pSetting);
    void GetSetting(MemorySetting *pDst);
    void ResetGameData();
    void ResetMCData();
    int CheckLoadData();
    int CheckSum(unsigned char *pBuf);
    int CheckFiles();
    void ResetFileStatus();
    void IssueCommand(const char *pCmd);
    int LoadGame();
    void RemoveMCText();
    void DisplayMCText(int nArg);
    int SelectSlot(unsigned int nArg);
    void InitLoadGame();
    void DisplaySlot(bool bFlag);
    void InitSaveGame(Player::PlayerData *pData, int nVal, bool bFlag);
    void DeleteScreen();
    void InitScreen();
    int ProcessCommand();
    int Init();
    int SaveGame();

    char _pad000[0x1C8];
    int m_unk1C8;                   // 0x1C8 must equal 0xB for SelectSlot to act
    char _pad1CC[0x1DC - 0x1CC];
    int m_unk1DC;                   // 0x1DC command word, written as (pCmd | 0x30000000)
    int m_unk1E0;                   // 0x1E0 countdown, reset to 0x3C by LoadGame
    short m_unk1E4;                 // 0x1E4
    short m_unk1E6;                 // 0x1E6
    char _pad1E8[0x1EC - 0x1E8];
    int m_unk1EC;                   // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    char m_unk1F4;                  // 0x1F4 set to 1 by InitSaveGame, cleared by InitLoadGame
    char m_unk1F5;                  // 0x1F5
    char m_unk1F6;                  // 0x1F6
    char _pad1F7[0x1F8 - 0x1F7];
    char m_unk1F8;                  // 0x1F8 bFlag argument of InitSaveGame
    char m_unk1F9;                  // 0x1F9 cleared by InitSaveGame
    char m_unk1FA;                  // 0x1FA file status byte, -1 after ResetFileStatus
    char m_unk1FB;                  // 0x1FB
    char m_unk1FC;                  // 0x1FC
    char m_unk1FD;                  // 0x1FD
    char m_unk1FE;                  // 0x1FE
    char m_unk1FF;                  // 0x1FF
    int m_unk200;                   // 0x200 flag, nonzero while the MC text is shown
    char _pad204[0x208 - 0x204];
    int m_unk208;                   // 0x208 cleared by ResetGameData
    int m_unk20C;                   // 0x20C cleared by ResetGameData
    int m_unk210;                   // 0x210 signed slot index, side * 3 + column
    char _pad214[0x218 - 0x214];
    MemorySetting m_unk218;         // 0x218 active setting, filled by SetSetting or ResetMCData
    char _pad222[0x224 - 0x222];
    char m_unk224[0x22C - 0x224];   // 0x224 start of the 0x4B4-byte save block cleared by memset
    signed char m_unk22C;           // 0x22C nVal argument of InitSaveGame
    unsigned char m_unk22D;         // 0x22D header byte, computed by UpdateHeader
    unsigned char m_unk22E;         // 0x22E header level, raised to nVal by UpdateHeader
    signed char m_unk22F;           // 0x22F preserved across ResetGameData
    char _pad230[0x234 - 0x230];
    char m_unk234[0x7C];            // 0x234 Player::PlayerData record
    char _pad2B0[0x6B5 - 0x2B0];    // 0x2B0 per-entry 0xFF table, written by ResetGameData
    char m_unk6B5;                  // 0x6B5 set to 1 by ResetGameData
    char _pad6B6[0x6D8 - 0x6B6];
    MemorySetting m_unk6D8;         // 0x6D8 setting passed to SetSetting by LoadGame
    char _pad6E2[0x6EC - 0x6E2];
    short m_unk6EC;                 // 0x6EC slot table, stride 0x4B4
    short m_unk6EE;
    short m_unk6F0;
    char _pad6F2[0xBA0 - 0x6F2];
    short m_unkBA0;
    short m_unkBA2;
    short m_unkBA4;
    char _padBA6[0x1054 - 0xBA6];
    short m_unk1054;
    short m_unk1056;
    short m_unk1058;
    char _pad105A[0x1508 - 0x105A];
    short m_unk1508;
    short m_unk150A;
    short m_unk150C;
    char _pad150E[0x19BC - 0x150E];
    short m_unk19BC;
    short m_unk19BE;
    short m_unk19C0;
    char _pad19C2[0x1E70 - 0x19C2];
    short m_unk1E70;
    short m_unk1E72;
    short m_unk1E74;
    char _pad1E76[0x231C - 0x1E76];
    int m_unk231C;                  // 0x231C cleared by InitSaveGame
    char _pad2320[0x3F68 - 0x2320];
    int m_unk3F68;                  // 0x3F68 saved gInterface word 0x18D0, written by InitScreen
    MemoryCardView *m_unk3F6C;      // 0x3F6C virtual interface, slot 0x18 called by LoadGame
    PMNode *m_unk3F70[6];           // 0x3F70 per-slot PMNode, indexed by m_unk210
    FontNode *m_unk3F88[6][2];      // 0x3F88 per-slot FontNode pair, indexed by m_unk210 (stride 8)
};

#endif
