// FLAGS: -str readonly
#include "types.h"
#include "MemoryCard.h"

// TODO(header): foreign declarations
extern unsigned char gInterface[2656];
extern "C" void RemoveText__11FontManagerFUs(void *pThis, unsigned short nId);
extern "C" void RemoveText__11FontManagerFP8FontNode(void *pThis, FontNode *pNode);
extern "C" void __dl__FPv(void *pMem);
extern "C" int CheckPlayerData__6PlayerFPQ26Player10PlayerData(void *pThis);
extern "C" int DisplayString__11FontManagerFiiib(void *pThis, int nX, int nY, int nZ, bool bFlag);
extern "C" FontNode *DisplayString__11FontManagerFPcffi9FontColor9FontAlign(void *pThis, char *pStr, float fX, float fY, int nZ, int nColor, int nAlign);
extern char gEng[105360];
extern "C" void *GetResource__16PResourceManagerFUib(void *pThis, unsigned int nId, bool bFlag);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void AddMeshLayer__9InterfaceFP6PMNode(void *pThis, void *pNode);
extern "C" void *Find__6PMNodeFUi(void *pThis, unsigned int nId);
extern "C" void ScaleSet__6PMNodeFffff(void *pThis, float fX, float fY, float fZ, float fW);
extern unsigned int SlotNames[6];
extern float BoxSize[4];
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
extern "C" void PlaySoundNonPositional__6PSoundFUi(void *pThis, unsigned int nSnd);
extern "C" void SetColor__8FontNodeF9FontColor(void *pThis, int nColor);
extern "C" void SetAnimLoopCount__6PMNodeFib(void *pThis, int nCount, bool bFlag);
extern char DefaultLoopAnim[0x10];
extern "C" int sceMcInit();
extern "C" int sceMcUnformat(int nPort, int nSlot);
extern "C" int sceMcSync(int nMode, int *pResult, int *pCount);
extern "C" void InitRenderFrame__9MaxEngineFbUi(void *pThis, bool bFlag, unsigned int nVal);
extern "C" void Render__9InterfaceFi(void *pThis, int nArg);
extern int iDebugMC;
extern char BootMC[16];
extern char SaveMC[16];
extern float GAME_FPS;
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" int strcasecmp(const char *pA, const char *pB);
extern char IconSysName[9];
extern char MaximoDir[21];
extern unsigned int Icon_tbl[6];
extern char iconSys[964];
struct SlotPosition {
    float fX;
    float fY;
};
extern SlotPosition SlotPos[6];

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("MemoryCard.cpp", line, #cond))

// Virtual interface at 0x3F6C; slot 0x18 is virtual index 4, slot 0x08 is the destructor.
class MemoryCardView {
public:
    virtual ~MemoryCardView();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4(int nA, int nB, int nC, float fX, float fY);
};

// Cast view of PMNode for its virtual table; SetAllAnimFlags is virtual index 5 (slot 0x1C).
class PMNodeView {
public:
    virtual ~PMNodeView();
    virtual void Render();
    virtual void SetFrameTime();
    virtual void CreateObjectDisplayList();
    virtual void Animate(float fA, float fB, void *pMat, int nC, bool bD);
    virtual void SetAllAnimFlags(void *pAnim);
    virtual void Slot20(void *pNode);
};

// DRAFT: 0x0014FD40 UpdateHeader__10MemoryCardFUc
// note: 12 words differ: original keeps loop byte in v1 and i*0x31 in t1 (ours t1/t2), and reloads m_unk22E into a1 in a different order; tried pointer walk (16), nSum before header block (18), cached level (67)
void MemoryCard::UpdateHeader(unsigned char nVal) {
    if (nVal > m_unk22E) {
        m_unk22E = nVal;
        m_unk22C = nVal;
    }
    int nSum = 0;
    for (int i = 0; i <= m_unk22E && i < 0x15; i++) {
        signed char nVal2 = _pad2B0[i * 0x31];
        if (nVal2 >= 0) {
            if (nVal2 >= 0x65) {
                nVal2 = 0x64;
            }
            nSum += nVal2;
        }
    }
    float fVal = (float)(nSum * 100) / 2100.0f;
    if (fVal < 99.5f) {
        fVal += 0.5f;
    }
    m_unk22D = (unsigned char)(unsigned int)fVal;
}

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

// FUNCTION: 0x0014FF00 GetSetting__10MemoryCardFP13MemorySetting
void MemoryCard::GetSetting(MemorySetting *pDst) {
    memcpy(pDst, &m_unk218, 10);
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

// FUNCTION: 0x001501D0 CheckFree__10MemoryCardFv
int MemoryCard::CheckFree() {
    int nIndex;
    char *pName;
    int nOff;
    char *pEntry;
    int nNeed;
    int nCount;

    ResetFileStatus();
    for (nIndex = 0, nOff = 0; nIndex < m_unk1C0; nOff += 0x40, nIndex++) {
        pEntry = (char *)this + nOff;
        pName = pEntry + 0x20;
        if (strcasecmp(pName, IconSysName) == 0 && *(int *)(pEntry + 0x10) == 0x3C4) {
            m_unk1FA = nIndex;
        } else if (strcasecmp(pName, iconSys + 0x104) == 0 &&
                   *(unsigned int *)(pEntry + 0x10) == Icon_tbl[1] - Icon_tbl[0]) {
            m_unk1FB = nIndex;
        } else if (strcasecmp(pName, iconSys + 0x144) == 0 &&
                   *(unsigned int *)(pEntry + 0x10) == Icon_tbl[3] - Icon_tbl[2]) {
            m_unk1FC = nIndex;
        } else if (strcasecmp(pName, iconSys + 0x184) == 0 &&
                   *(unsigned int *)(pEntry + 0x10) == Icon_tbl[5] - Icon_tbl[4]) {
            m_unk1FD = nIndex;
        } else if (strcasecmp(pName, MaximoDir + 1) == 0) {
            m_unk1FE = (*(int *)(pEntry + 0x10) == 0x1C48) ? nIndex : -2;
        } else if (strcasecmp(pName, ".") == 0 && *(int *)(pEntry + 0x10) == 0) {
            m_unk1FF = nIndex;
        }
    }

    nNeed = (m_unk1C0 < 0) ? 2 : 0;
    nCount = 0;
    if (m_unk1FA < 0) {
        nNeed += 1;
        nCount += 1;
    }
    if (m_unk1FB < 0) {
        nCount += 1;
        nNeed += ((Icon_tbl[1] - Icon_tbl[0]) + 0x3FF) >> 10;
    }
    if (m_unk1FC < 0) {
        nCount += 1;
        nNeed += ((Icon_tbl[3] - Icon_tbl[2]) + 0x3FF) >> 10;
    }
    if (m_unk1FD < 0) {
        nCount += 1;
        nNeed += ((Icon_tbl[5] - Icon_tbl[4]) + 0x3FF) >> 10;
    }
    if (m_unk1FE < 0) {
        nNeed += 8;
        nCount += 1;
    }
    nNeed += (unsigned int)(nCount + 1) >> 1;
    if (m_unk1D4 >= (unsigned int)nNeed) {
        return 1;
    }
    return 0;
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
    void *pFont = gInterface + 0x80;
    *(int *)((char *)this + 0x204) = *(int *)pFont;
    m_unk200 = DisplayString__11FontManagerFiiib(pFont, nArg, 0, 0, 0);
}

// DRAFT: 0x001504F0 SelectSlot__10MemoryCardFUi
// note: 109 words differ; original uses 0x70 frame saving s0-s5, branch-tree layout for the 0x4000/0x1000/0xF0 tests with s0 shared exit, and re-reads m_unk210 per use. Tried straight-line early returns (118), shared nRet with reloads (109).
int MemoryCard::SelectSlot(unsigned int nArg) {
    int nRet = -1;
    if (m_unk1C8 == 0xB) {
        if (nArg & 0x4000) {
            nRet = 0xB;
        } else if (nArg & 0x1000) {
            m_unk1E6 = 0x1000;
            nRet = 9;
        } else if (nArg & 0xF0) {
            PlaySoundNonPositional__6PSoundFUi(gSound, 0x40);
            SetColor__8FontNodeF9FontColor(m_unk3F88[m_unk210][0], 7);
            if (m_unk3F88[m_unk210][1]) {
                SetColor__8FontNodeF9FontColor(m_unk3F88[m_unk210][1], 7);
            }
            SetAnimLoopCount__6PMNodeFib(m_unk3F70[m_unk210], 1, false);
            int q = m_unk210 / 3;
            int r = m_unk210 % 3;
            if (nArg & 0x50) {
                r += (nArg & 0x10) ? -1 : 1;
                if ((unsigned int)r >= 3) {
                    r = (nArg & 0x10) ? 2 : 0;
                }
            }
            if (nArg & 0xA0) {
                q ^= 1;
            }
            m_unk210 = r + q * 3;
            SetColor__8FontNodeF9FontColor(m_unk3F88[m_unk210][0], 4);
            if (m_unk3F88[m_unk210][1]) {
                SetColor__8FontNodeF9FontColor(m_unk3F88[m_unk210][1], 4);
            }
            ((PMNodeView *)m_unk3F70[m_unk210])->SetAllAnimFlags(DefaultLoopAnim);
        }
    }
    return nRet;
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
    InitScreen();
    char *pInfo = *(char **)(gInterface + 0x180);
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x80, *(char **)(pInfo + 0x78), 0.0f, 175.0f, *(signed char *)(pInfo + 0x82), 4, 1);
}

// DRAFT: 0x00151E90 SaveGame__10MemoryCardFv
// note: 143 words; original frame 0xA0 saves s0-s5 and f20, ours 0x70 saves s0-s2 with this in s1 (orig s2). Tried goto nine (146->143), buf hoist and nSlot/pFont order (no change).
int MemoryCard::SaveGame() {
    m_unk3F6C->Slot4(0, 0, 0, 0.0f, 1.0f);
    int nRet = ProcessCommand();
    if (nRet == 9) goto nine;
    if (nRet == 0xC) goto countdown_tick;
    if (nRet == 8) goto countdown_init;
    if (nRet != 0xB) return -1;
    DisplayMCText(0x3D);
    {
        unsigned char *pFont = gInterface + 0x80;
        int nSlot = m_unk210;
        if (m_unk3F88[nSlot][0] != 0) RemoveText__11FontManagerFP8FontNode(pFont, m_unk3F88[nSlot][0]);
        if (m_unk3F88[nSlot][1] != 0) RemoveText__11FontManagerFP8FontNode(pFont, m_unk3F88[nSlot][1]);
        char *pStr = (*(int *)((char *)this + 0x6F0 + nSlot * 0x4B4) == 0) ? (char *)"No Data" : (char *)"Saved";
        float fY = SlotPos[nSlot].fY;
        m_unk3F88[nSlot][0] = DisplayString__11FontManagerFPcffi9FontColor9FontAlign(pFont, pStr, SlotPos[nSlot].fX, fY, 3, 4, 0);
        char buf[32];
        sprintf(buf, "%d%s", *(unsigned char *)((char *)this + 0x6ED + nSlot * 0x4B4), "%");
        m_unk3F88[nSlot][1] = DisplayString__11FontManagerFPcffi9FontColor9FontAlign(pFont, buf, SlotPos[nSlot].fX, fY - 25.0f, 3, 4, 0);
    }
countdown_init:
    m_unk1DC = 0;
    m_unk1E0 = 0x3C;
countdown_tick:
    m_unk1E0 = m_unk1E0 - 1;
    if (m_unk1E0 > 0) return -1;
    DeleteScreen();
    EnableAllText__11FontManagerFb(gInterface + 0x80, true);
    return 0xB;
nine:
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x41);
    if (m_unk1F8 == 0) goto countdown_init;
    m_unk1E0 = 0x2F;
    DisplaySlot(true);
    m_unk1EC = -0x14;
    *(int *)((char *)this + 0x1F0) = 1;
    DisplayMCText(0x52);
    return -1;
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
    unsigned char *pFont = gInterface + 0x80;
    EnableAllText__11FontManagerFb(pFont, 0);
    InitScreen();
    char *pInfo = *(char **)(pFont + 0x100);
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(pFont, *(char **)(pInfo + 0x90), 0.0f, 175.0f, *(signed char *)(pInfo + 0x9A), 4, 1);
}

// FUNCTION: 0x00152490 DeleteScreen__10MemoryCardFv
void MemoryCard::DeleteScreen() {
    RemoveMCText();
    DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, *(void **)((char *)this + 0x3F6C));
    RemoveAll__11FontManagerFb(gInterface + 0x80, true);
    *(int *)(gInterface + 0x1C0) = *(int *)((char *)this + 0x3F68);
}

// FUNCTION: 0x001524E0 InitScreen__10MemoryCardFv
void MemoryCard::InitScreen() {
    char *pEng = gEng + 0x188A4;
    m_unk3F6C = (MemoryCardView *)GetResource__16PResourceManagerFUib(pEng, 0x810003E5, 0);
    if (m_unk3F6C == 0) {
        CdsAssert__FPciPc("MemoryCard.cpp", 0x15A, "mpSaveNode");
    }
    void *pNode = GetResource__16PResourceManagerFUib(pEng, 0x820006AE, 0);
    ((PMNodeView *)m_unk3F6C)->Slot20(pNode);
    AddMeshLayer__9InterfaceFP6PMNode(gInterface, m_unk3F6C);
    m_unk3F68 = *(int *)(gInterface + 0x1C0);
    *(int *)(gInterface + 0x1C0) = 0xC9;
    for (int i = 0; i < 6; i++) {
        m_unk3F70[i] = (PMNode *)Find__6PMNodeFUi(m_unk3F6C, SlotNames[i]);
        m_unk3F88[i][0] = 0;
        m_unk3F88[i][1] = 0;
    }
    void *pFind = Find__6PMNodeFUi(m_unk3F6C, 0xBBCD34F9);
    if (pFind != 0) {
        ScaleSet__6PMNodeFffff(pFind, BoxSize[*(signed char *)(gInterface + 0x93)], 1.0f, 1.0f, 1.0f);
    }
    ((PMNodeView *)m_unk3F6C)->Animate(0.0f, 1.0f, 0, 0, false);
}

// DRAFT: 0x00152670 Init__10MemoryCardFv
// note: 94 words; the dispatch on the ProcessCommand result and nop placement after the loop differ from the original.
int MemoryCard::Init() {
    int nRet;
    int nRes;

    if (sceMcInit() != 0) {
        CDS_ASSERT(0xFA, !"sceMcInit() error\n");
    }
    *(unsigned char *)(gInterface + 0x424) = 0;
    m_unk214 = -1;
    ResetMCData();
    m_unk210 = 0;
    m_unk1F4 = 0;
    IssueCommand(BootMC);
    nRet = 0;
    for (;;) {
        InitRenderFrame__9MaxEngineFbUi(gEng, false, 0);
        int nCmd = ProcessCommand();
        if (nCmd == 5) {
            goto join;
        }
        if (nCmd == 0xB) {
            goto set;
        }
        if (nCmd == -1) {
            goto render;
        }
        break;
    set:
        if (m_unk1F5 == 0) {
            SetSetting(&m_unk6D8);
        }
    join:
        if (m_unk1F5 != 0 || CheckFiles() != 0) {
            nRet = 1;
            break;
        }
        m_unk1F5 = 1;
        m_unk1F6 = (char)(int)(2.0f * GAME_FPS);
        DisplayMCText(0x1A);
        m_unk1E0 = 10;
    render:
        Render__9InterfaceFi(gInterface, 0);
    }
    RemoveMCText();
    Render__9InterfaceFi(gInterface, 0);
    if (iDebugMC == 2) {
        ResetMCData();
        IssueCommand(SaveMC);
        nRet = 0;
        for (;;) {
            InitRenderFrame__9MaxEngineFbUi(gEng, false, 0);
            int nCmd = ProcessCommand();
            if (nCmd == 0xB) {
                nRet = 1;
                break;
            }
            if (nCmd == -1) {
                Render__9InterfaceFi(gInterface, 0);
                continue;
            }
            break;
        }
        RemoveMCText();
        Render__9InterfaceFi(gInterface, 0);
        return nRet;
    }
    if (iDebugMC == 1) {
        sceMcUnformat(0, 0);
        sceMcSync(0, &nRes, &m_unk1C8);
    }
    *(unsigned char *)(gInterface + 0x424) = 1;
    return nRet;
}

// FUNCTION: 0x001528F0 RemoveMCText__10MemoryCardFv
void MemoryCard::RemoveMCText() {
    if (m_unk200 != 0) {
        RemoveText__11FontManagerFUs(gInterface + 0x80, 10);
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
