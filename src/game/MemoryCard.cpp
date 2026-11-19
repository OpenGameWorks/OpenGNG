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
extern char LoadGameMC[16];
extern "C" void DeleteMeshLayer__9InterfaceFP6PMNode(void *pThis, void *pNode);
extern "C" void RemoveAll__11FontManagerFb(void *pThis, bool bFlag);

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

// FUNCTION: 0x00151E20 InitLoadGame__10MemoryCardFv
void MemoryCard::InitLoadGame() {
    m_unk1F4 = 0;
    IssueCommand(LoadGameMC);
    InitScreen__10MemoryCardFv(this);
    char *pInfo = *(char **)(gInterface + 0x1890);
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x1790, *(char **)(pInfo + 0x78), 0.0f, 175.0f, *(signed char *)(pInfo + 0x82), 4, 1);
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
