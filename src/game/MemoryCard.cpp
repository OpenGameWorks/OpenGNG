#include "types.h"
#include "MemoryCard.h"

// TODO(header): foreign declarations
extern unsigned char gInterface[2656];
extern "C" void RemoveText__11FontManagerFUs(void *pThis, unsigned short nId);
extern "C" void __dl__FPv(void *pMem);
extern "C" int CheckPlayerData__6PlayerFPQ26Player10PlayerData(void *pThis);
extern "C" int DisplayString__11FontManagerFiiib(void *pThis, int nX, int nY, int nZ, bool bFlag);
extern "C" void DisplayString__11FontManagerFPcffi9FontColor9FontAlign(void *pThis, char *pStr, float fX, float fY, int nZ, int nColor, int nAlign);
extern "C" void InitScreen__10MemoryCardFv(void *pThis);
extern "C" void EnableAllText__11FontManagerFb(void *pThis, bool bFlag);
extern char LoadGameMC[16];
extern char SaveGameMC[16];
extern "C" void DeleteMeshLayer__9InterfaceFP6PMNode(void *pThis, void *pNode);
extern "C" void RemoveAll__11FontManagerFb(void *pThis, bool bFlag);
extern "C" void memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void EnableVibrate__3PadFb(void *pThis, unsigned char bFlag);
extern "C" void SetMainMusicRelVolume__6PSoundFUi(void *pThis, unsigned int nVol);
extern "C" void SetEffectsRelVolume__6PSoundFUi(void *pThis, unsigned int nVol);
extern "C" void SetTvOffset__10PGfxEngineFii(void *pThis, int nX, int nY);
extern unsigned char DefaultSetting[16];
extern unsigned char gPad[448];
extern unsigned char gSound[98496];
extern unsigned char gGfxEng[1504384];
extern "C" void ResetPlayerData__6PlayerFPQ26Player10PlayerData(void *pThis);

// Virtual interface at 0x3F6C; slot 0x18 is virtual index 4, slot 0x08 is the destructor.
class MemoryCardView {
public:
    virtual ~MemoryCardView();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4(int nA, int nB, int nC, float fX, float fY);
};

// FUNCTION: 0x0014FE70 SetSetting__10MemoryCardFP13MemorySetting
int MemoryCard::SetSetting(MemorySetting *pSetting) {
    if (pSetting->m_unk0 != DefaultSetting[0]) {
        return 0;
    }
    memcpy(&m_unk218, pSetting, 10);
    EnableVibrate__3PadFb(gPad, m_unk218.m_unk1);
    SetMainMusicRelVolume__6PSoundFUi(gSound, m_unk218.m_unk4);
    SetEffectsRelVolume__6PSoundFUi(gSound, m_unk218.m_unk5);
    SetTvOffset__10PGfxEngineFii(gGfxEng, m_unk218.m_unk6, m_unk218.m_unk8);
    return 1;
}

// DRAFT: 0x0014FF20 ResetGameData__10MemoryCardFv
// note: 25 words differ; second-loop shape (beqz target, nop at 0x98/0xA4, per-iteration offset recompute), m_unk6B5 store not hoisted, 0x234 arg order; size 0xD4 vs 0xD8. Tried do-while/nOffset/per-iteration variants.
void MemoryCard::ResetGameData() {
    signed char cKeep = m_unk22F;
    memset(&m_unk224, 0, 0x4B4);
    int nIndex = 0;
    int nOffset = 0;
    do {
        unsigned char *pEntry = (unsigned char *)this + nOffset;
        nIndex += 8;
        pEntry[0x2B0] = 0xFF;
        pEntry[0x2E1] = 0xFF;
        nOffset += 0x188;
        pEntry[0x312] = 0xFF;
        pEntry[0x343] = 0xFF;
        pEntry[0x374] = 0xFF;
        pEntry[0x3A5] = 0xFF;
        pEntry[0x3D6] = 0xFF;
        pEntry[0x407] = 0xFF;
    } while (nIndex < 0xD);
    if (nIndex < 0x15) {
        nOffset = nIndex * 0x31;
        do {
            nIndex += 1;
            ((unsigned char *)this + nOffset)[0x2B0] = 0xFF;
            nOffset += 0x31;
        } while (nIndex < 0x15);
    }
    m_unk6B5 = 1;
    m_unk22F = cKeep;
    ResetPlayerData__6PlayerFPQ26Player10PlayerData(m_unk234);
    m_unk208 = 0;
    m_unk20C = 0;
}

// FUNCTION: 0x00150010 ResetMCData__10MemoryCardFv
void MemoryCard::ResetMCData() {
    memcpy(&m_unk218, DefaultSetting, 10);
    memset(&m_unk224, 0, 0x4B4);
    ResetPlayerData__6PlayerFPQ26Player10PlayerData(m_unk234);
    *(signed char *)((char *)this + 0x6EC) = 0;
    *(signed char *)((char *)this + 0x6EE) = 0;
    *(int *)((char *)this + 0x6F0) = 0;
    *(signed char *)((char *)this + 0xBA0) = 0;
    *(signed char *)((char *)this + 0xBA2) = 0;
    *(int *)((char *)this + 0xBA4) = 0;
    *(signed char *)((char *)this + 0x1054) = 0;
    *(signed char *)((char *)this + 0x1056) = 0;
    *(int *)((char *)this + 0x1058) = 0;
    *(signed char *)((char *)this + 0x1508) = 0;
    *(signed char *)((char *)this + 0x150A) = 0;
    *(int *)((char *)this + 0x150C) = 0;
    *(signed char *)((char *)this + 0x19BC) = 0;
    *(signed char *)((char *)this + 0x19BE) = 0;
    *(int *)((char *)this + 0x19C0) = 0;
    *(signed char *)((char *)this + 0x1E70) = 0;
    *(signed char *)((char *)this + 0x1E72) = 0;
    *(int *)((char *)this + 0x1E74) = 0;
}

// FUNCTION: 0x001500B0 CheckLoadData__10MemoryCardFv
int MemoryCard::CheckLoadData() {
    int nIndex = 0;
    int nOffset = 0;
    do {
        char *pSlot = (char *)this + nOffset;
        if (*(int *)(pSlot + 0x6F0) != 0) {
            if (CheckPlayerData__6PlayerFPQ26Player10PlayerData(pSlot + 0x6F4) == 0) {
                return 0;
            }
        }
        nIndex++;
        nOffset += 0x4B4;
    } while (nIndex < 6);
    return 1;
}

// DRAFT: 0x00150130 CheckSum__10MemoryCardFPUc
// note: 6 words differ; original has no entry branch and two nops before bnez, ours has a daddu copy of the counter. Tried for, do-while, while(i--), while(i--!=0), mid-body decrement.
int MemoryCard::CheckSum(unsigned char *pBuf) {
    int nSum = 0;
    int i = 0x1C38;
    while (i--) {
        nSum += *pBuf++;
    }
    if (nSum != 0) {
        return nSum;
    }
    return -1;
}

// FUNCTION: 0x00150180 CheckFiles__10MemoryCardFv
int MemoryCard::CheckFiles() {
    int nIndex = 1;
    char nFirst = m_unk1FA;
    do {
        if (((&m_unk1FA)[nIndex] ^ nFirst) < 0) {
            return 0;
        }
        nIndex++;
    } while (nIndex < 6);
    return 1;
}

// FUNCTION: 0x00150470 ResetFileStatus__10MemoryCardFv
void MemoryCard::ResetFileStatus() {
    m_unk1FA = -1;
    m_unk1FB = -1;
    m_unk1FC = -1;
    m_unk1FD = -1;
    m_unk1FE = -1;
    m_unk1FF = -1;
}

// FUNCTION: 0x00150490 DisplayMCText__10MemoryCardFi
void MemoryCard::DisplayMCText(int nArg) {
    RemoveMCText();
    void *pFont = gInterface + 0x1790;
    *(int *)((char *)this + 0x204) = *(int *)pFont;
    m_unk200 = DisplayString__11FontManagerFiiib(pFont, nArg, 0, 0, 0);
}

// FUNCTION: 0x00151D10 IssueCommand__10MemoryCardFPCc
void MemoryCard::IssueCommand(const char *pCmd) {
    m_unk1DC = (int)pCmd | 0x30000000;
    m_unk1E0 = 0;
    m_unk1E4 = 0;
    m_unk1E6 = 0;
    m_unk1EC = 0;
    m_unk1F5 = 0;
    m_unk1F6 = 0;
}

// DRAFT: 0x00151D40 LoadGame__10MemoryCardFv
// note: 31 words differ; original chains tests 12,8,9,11 with case bodies out of line (11,9,8 order), ours inlines case 8; float args f12/f13 load in swapped order. Tried switch (binary-search tree), if/else chain (31 words), 12-then-switch (38 words).
int MemoryCard::LoadGame() {
    m_unk3F6C->Slot4(0, 0, 0, 0.0f, 1.0f);
    int nResult = ProcessCommand();
    if (nResult == 12) {
    } else if (nResult == 8) {
        m_unk1DC = 0;
        m_unk1E0 = 0x3C;
    } else if (nResult == 9) {
        DeleteScreen();
        return 9;
    } else if (nResult == 11) {
        SetSetting(&m_unk6D8);
        DeleteScreen();
        return 11;
    } else {
        return -1;
    }
    m_unk1E0 = m_unk1E0 - 1;
    if (m_unk1E0 <= 0) {
        DeleteScreen();
        return 11;
    }
    return -1;
}

// FUNCTION: 0x00151E20 InitLoadGame__10MemoryCardFv
void MemoryCard::InitLoadGame() {
    m_unk1F4 = 0;
    IssueCommand(LoadGameMC);
    InitScreen__10MemoryCardFv(this);
    char *pInfo = *(char **)(gInterface + 0x1890);
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x1790, *(char **)(pInfo + 0x78), 0.0f, 175.0f, *(signed char *)(pInfo + 0x82), 4, 1);
}

// FUNCTION: 0x001520F0 InitSaveGame__10MemoryCardFPQ26Player10PlayerDataib
void MemoryCard::InitSaveGame(Player::PlayerData *pData, int nVal, bool bFlag) {
    m_unk1F8 = bFlag;
    m_unk1F9 = 0;
    m_unk231C = 0;
    m_unk1F4 = 1;
    IssueCommand(SaveGameMC);
    m_unk22C = nVal;
    if (pData != 0) {
        memcpy(m_unk234, pData, 0x7C);
    }
    unsigned char *pFont = gInterface + 0x1790;
    EnableAllText__11FontManagerFb(pFont, 0);
    InitScreen__10MemoryCardFv(this);
    char *pInfo = *(char **)(pFont + 0x100);
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(pFont, *(char **)(pInfo + 0x90), 0.0f, 175.0f, *(signed char *)(pInfo + 0x9A), 4, 1);
}

// FUNCTION: 0x00152490 DeleteScreen__10MemoryCardFv
void MemoryCard::DeleteScreen() {
    RemoveMCText();
    DeleteMeshLayer__9InterfaceFP6PMNode(gInterface + 0x1710, *(void **)((char *)this + 0x3F6C));
    RemoveAll__11FontManagerFb(gInterface + 0x1790, true);
    *(int *)(gInterface + 0x18D0) = *(int *)((char *)this + 0x3F68);
}

// FUNCTION: 0x001528F0 RemoveMCText__10MemoryCardFv
void MemoryCard::RemoveMCText() {
    if (m_unk200 != 0) {
        RemoveText__11FontManagerFUs(gInterface + 0x1790, 10);
        m_unk200 = 0;
    }
}

// FUNCTION: 0x00152930 __dt__10MemoryCardFv
extern "C" MemoryCard *__dt__10MemoryCardFv(MemoryCard *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
