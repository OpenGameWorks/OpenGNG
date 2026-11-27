// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
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
extern "C" int printf(const char *pFmt, ...);
extern "C" int sceMcGetInfo(int nPort, int nSlot, int *pType, unsigned int *pFree);
extern "C" int sceMcOpen(int nPort, int nSlot, const char *pName, int nFlags);
extern "C" int sceMcClose(int nFd);
extern "C" int sceMcRead(int nFd, void *pBuf, int nSize);
extern "C" int sceMcWrite(int nFd, const void *pBuf, int nSize);
extern "C" int sceMcGetDir(int nPort, int nSlot, const char *pPath, int nFlags);
extern "C" int sceMcFormat(int nPort, int nSlot);
extern "C" int sceMcMkdir(int nPort, int nSlot, const char *pPath);
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

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("MemoryCard.cpp", line, #cond))

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

// FUNCTION: 0x0014FD40 UpdateHeader__10MemoryCardFUc
void MemoryCard::UpdateHeader(unsigned char nVal) {
    if (nVal > m_unk22E) {
        m_unk22E = nVal;
    }
    m_unk22C = nVal;
    int nSum = 0;
    for (int i = 0, nOff = 0; i <= m_unk22E && i < 0x15; nOff += 0x31, i++) {
        signed char nVal2 = _pad2B0[nOff];
        if (nVal2 >= 0) {
            signed char nC = nVal2;
            if (nC > 100) {
                nC = 100;
            }
            nSum += nC;
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
// note: 17 words differ on default build (matches under mwcps2-3.0-011126 with do-while form); second-loop shape (beqz target, nop at 0x98/0xA4, per-iteration offset recompute), m_unk6B5 store not hoisted, 0x234 arg order; size 0xD4 vs 0xD8. Tried do-while/nOffset/per-iteration variants.
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

// FUNCTION: 0x00150000 ResetSetting__10MemoryCardFv
int MemoryCard::ResetSetting() {
    return SetSetting((MemorySetting *)DefaultSetting);
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
// note: 10 words differ, all from one extra nop before the short loop's bnez (original size 0x44, ours 0x40); matches under 011126 padding. Tried for, do-while, while(i--), while(i--!=0), mid-body decrement.
int MemoryCard::CheckSum(unsigned char *pBuf) {
    int nSum = 0;
    int i = 0x1C38;
    do {
        unsigned char c = *pBuf++;
        nSum += c;
    } while (--i);
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

// DRAFT: 0x001506D0 ProcessCommand__10MemoryCardFv
// note: goto state machine from m2c; register allocation and branch layout differ.
int MemoryCard::ProcessCommand()
{
    int sp9C;
    char sp50[0x40];
    int temp_a0;
    int temp_a0_2;
    int temp_a0_4;
    FontNode *var_a0;
    FontNode *var_a0_2;
    FontNode *var_a0_3;
    FontNode *var_a0_4;
    int temp_s0;
    int temp_s0_2;
    int temp_s2;
    int temp_s2_2;
    int temp_v0;
    int temp_v0_10;
    int temp_v0_11;
    int temp_v0_12;
    int temp_v0_15;
    int temp_v0_16;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v0_7;
    int temp_v0_8;
    int temp_v0_9;
    int temp_v1_10;
    int temp_v1_12;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_5;
    int temp_v1_6;
    int temp_v1_7;
    int temp_v1_8;
    int var_a1;
    int var_s2;
    int var_s3_2;
    int var_v0_2;
    signed char temp_a1;
    signed char temp_a2;
    signed char temp_v0_13;
    signed char temp_v0_14;
    signed char temp_v0_2;
    signed char var_s3;
    unsigned short temp_v1;
    unsigned short var_s0;
    unsigned short var_v0;
    unsigned int temp_v1_13;
    unsigned int temp_v1_14;
    unsigned int temp_v1_15;
    unsigned int temp_v1_16;
    char *var_s2_2;
    char *temp_a0_3;
    char *temp_a0_5;
    char *temp_s0_3;
    char *temp_s0_4;
    char *temp_v1_11;
    char *temp_v1_9;

    if (this->m_unk1DC != 0) {
        goto block_2;
    }
    return 0xC;
block_2:
    temp_v0_2 = this->m_unk1F6;
    if (temp_v0_2 == 0) {
        goto block_4;
    }
    this->m_unk1F6 = temp_v0_2 - 1;
    return -1;
block_4:
    temp_s0 = *(unsigned short *)(gPad + 0x10A) & 0xF0;
    if (temp_s0 != 0) {
        goto block_6;
    }
    var_s0 = *(unsigned short *)(gPad + 0x110);
    goto block_7;
block_6:
    var_s0 = temp_s0 | (*(unsigned short *)(gPad + 0x110) & ~0xF0);
block_7:
    if (gInterface[0x425] == 0) {
        goto block_9;
    }
    var_s0 = 0;
block_9:
    temp_v1 = this->m_unk1E4;
    if (temp_v1 == 0) {
        goto block_13;
    }
    if (this->m_unk1E6 != 0) {
        goto block_12;
    }
    this->m_unk1E6 = var_s0 & (short)temp_v1;
block_12:
block_13:
    temp_v0_3 = sceMcSync(1, &sp9C, &this->m_unk1C8);
    if (temp_v0_3 == -1) {
        goto loop_93;
    }
    if (temp_v0_3 == 1) {
        goto block_17;
    }
    if (temp_v0_3 == 0) {
        goto block_248;
    }
    goto block_247;
block_17:
    temp_v1_2 = this->m_unk1E0;
    if (sp9C != *(signed char *)(this->m_unk1DC + temp_v1_2)) {
        goto loop_93;
    }
    if (sp9C == 0) {
        goto loop_93;
    }
    if (sp9C == 0x10) {
        goto block_88;
    }
    if (sp9C == 0xD) {
        goto block_83;
    }
    if (sp9C == 0xB) {
        goto block_77;
    }
    if (sp9C == 6) {
        goto block_72;
    }
    if (sp9C == 5) {
        goto block_63;
    }
    if (sp9C == 3) {
        goto block_56;
    }
    if (sp9C == 2) {
        goto block_44;
    }
    if (sp9C == 1) {
        goto block_28;
    }
    goto block_92;
block_28:
    temp_v1_3 = this->m_unk1C8;
    if (temp_v1_3 == -2) {
        goto block_38;
    }
    if (temp_v1_3 == 0) {
        goto block_32;
    }
    if (temp_v1_3 == -1) {
        goto block_32;
    }
    goto block_41;
block_32:
    if (this->m_unk1D0 == 2) {
        goto block_34;
    }
    goto block_41;
block_34:
    if (this->m_unk1D8 != 0) {
        goto block_37;
    }
    this->m_unk1C8 = 2;
    goto block_42;
block_37:
    this->m_unk1C8 = 0xB;
    goto block_43;
block_38:
    if (this->m_unk1D0 == 2) {
        goto block_40;
    }
    goto block_41;
block_40:
    this->m_unk1C8 = 2;
    goto block_42;
block_41:
    this->m_unk1C8 = 0;
block_42:
    temp_v0_4 = this->m_unk1C4 + 1;
    this->m_unk1C4 = temp_v0_4;
    if (temp_v0_4 < 0xA) {
        goto block_248;
    }
block_43:
    this->m_unk1C4 = 0;
    this->m_unk1E0 += 1;
    goto loop_93;
block_44:
    this->m_unk1CC = this->m_unk1C8;
    if (this->m_unk1C8 < 0) {
        goto block_46;
    }
    this->m_unk1C4 = 0;
    this->m_unk1E0 += 2;
    goto loop_93;
block_46:
    temp_v0_5 = this->m_unk1C4 + 1;
    this->m_unk1C4 = temp_v0_5;
    if (temp_v0_5 < 0xA) {
        goto block_248;
    }
    temp_v1_4 = this->m_unk1C8;
    if (temp_v1_4 == -4) {
        goto block_53;
    }
    if (temp_v1_4 == -7) {
        goto block_52;
    }
    if (temp_v1_4 == -5) {
        goto block_51;
    }
    goto block_54;
block_51:
block_52:
    return 8;
block_53:
    printf("MC file not found", sp9C, 1, -1);
    return 5;
block_54:
    if (this->m_unk1F4 != 0) {
        goto block_76;
    }
    this->m_unk1E0 = 0;
    this->m_unk1C4 = 0;
    goto loop_93;
block_56:
    temp_v1_5 = this->m_unk1C8;
    if (temp_v1_5 == -4) {
        goto block_59;
    }
    if (temp_v1_5 == 0) {
        goto block_59;
    }
    goto block_60;
block_59:
    this->m_unk1C4 = 0;
    this->m_unk1E0 += 1;
    this->RemoveMCText();
    goto loop_93;
block_60:
    temp_v0_6 = this->m_unk1C4 + 1;
    this->m_unk1C4 = temp_v0_6;
    if (temp_v0_6 < 0xA) {
        goto block_248;
    }
    if (this->m_unk1F4 != 0) {
        goto block_75;
    }
    this->m_unk1E0 = 0;
    this->m_unk1C4 = 0;
    goto loop_93;
block_63:
    if (this->m_unk1C8 < this->m_unk1E8) {
        goto block_65;
    }
    this->m_unk1C4 = 0;
    this->m_unk1E0 += 2;
    goto loop_93;
block_65:
    temp_v0_7 = this->m_unk1C4 + 1;
    this->m_unk1C4 = temp_v0_7;
    if (temp_v0_7 < 0xA) {
        goto block_248;
    }
    this->m_unk1C4 = 0;
    temp_v1_6 = this->m_unk1C8;
    if (temp_v1_6 == -5) {
        goto block_71;
    }
    if (temp_v1_6 == -3) {
        goto block_70;
    }
    if (temp_v1_6 >= 0) {
        goto block_70;
    }
    this->m_unk1E0 = 0;
    goto loop_93;
block_70:
block_71:
    this->DisplayMCText(0x41);
    this->m_unk1F5 = 1;
    this->m_unk1F6 = (signed char)(int)(2.0f * GAME_FPS);
    this->m_unk1E0 += 3;
    return -1;
block_72:
    if (this->m_unk1C8 < this->m_unk1E8) {
        goto block_74;
    }
    this->m_unk1C4 = 0;
    this->m_unk1E0 += 2;
    goto loop_93;
block_74:
    temp_v0_8 = this->m_unk1C4 + 1;
    this->m_unk1C4 = temp_v0_8;
    if (temp_v0_8 < 0xA) {
        goto block_248;
    }
block_75:
block_76:
    this->DisplayMCText(0x40);
    this->m_unk1F5 = 2;
    this->m_unk1F6 = (signed char)(int)(2.0f * GAME_FPS);
    this->m_unk1C4 = 0;
    this->m_unk1E0 = 0;
    return -1;
block_77:
    temp_v1_7 = this->m_unk1C8;
    if (temp_v1_7 == -4) {
        goto block_80;
    }
    if (temp_v1_7 == 0) {
        goto block_80;
    }
    goto block_81;
block_80:
    this->m_unk1C4 = 0;
    this->m_unk1E0 += 1;
    goto loop_93;
block_81:
    temp_v0_9 = this->m_unk1C4 + 1;
    this->m_unk1C4 = temp_v0_9;
    if (temp_v0_9 < 0xA) {
        goto block_248;
    }
    goto block_75;
block_83:
    temp_v1_8 = this->m_unk1C8;
    if (temp_v1_8 >= 0) {
        goto block_85;
    }
    if (temp_v1_8 != -4) {
        goto block_86;
    }
block_85:
    this->m_unk1C0 = temp_v1_8;
    this->m_unk1E0 += 1;
    this->m_unk1C4 = 0;
    goto loop_93;
block_86:
    temp_v0_10 = this->m_unk1C4 + 1;
    this->m_unk1C4 = temp_v0_10;
    if (temp_v0_10 < 0xA) {
        goto block_248;
    }
    this->m_unk1C4 = 0;
    this->m_unk1E0 = 0;
    goto loop_93;
block_88:
    if (this->m_unk1C8 != 0) {
        goto block_90;
    }
    this->m_unk1E0 = temp_v1_2 + 1;
    this->m_unk1C4 = 0;
    this->m_unk1D4 = 0x3E8;
    goto loop_93;
block_90:
    temp_v0_11 = this->m_unk1C4 + 1;
    this->m_unk1C4 = temp_v0_11;
    if (temp_v0_11 < 0xA) {
        goto block_248;
    }
    this->m_unk1C4 = 0;
    this->m_unk1E0 = 0;
    goto loop_93;
block_92:
    printf("Unknown MC command %d\n", sp9C, 1, -1);
    CdsAssert("MemoryCard.cpp", 0x302, "0");
loop_93:
    temp_v0_12 = this->m_unk1E0;
    temp_v1_9 = (char *)this->m_unk1DC + temp_v0_12;
    temp_a1 = temp_v1_9[0];
    if (temp_a1 == -0x14) {
        goto block_248;
    }
    if (temp_a1 == -0x12) {
        goto block_243;
    }
    if (temp_a1 == -0x11) {
        goto block_236;
    }
    if (temp_a1 == -0x10) {
        goto block_231;
    }
    if (temp_a1 == -0xF) {
        goto block_228;
    }
    if (temp_a1 == -8) {
        goto block_222;
    }
    if (temp_a1 == -7) {
        goto block_222;
    }
    if (temp_a1 == -6) {
        goto block_205;
    }
    if (temp_a1 == -5) {
        goto block_198;
    }
    if (temp_a1 == -0x13) {
        goto block_194;
    }
    if (temp_a1 == -4) {
        goto block_193;
    }
    if (temp_a1 == -3) {
        goto block_185;
    }
    if (temp_a1 == -2) {
        goto block_179;
    }
    var_s2 = -1;
    if (temp_a1 == -1) {
        goto block_168;
    }
    if (temp_a1 == 0) {
        goto block_167;
    }
    if (temp_a1 == 0x10) {
        goto block_164;
    }
    if (temp_a1 == 0xD) {
        goto block_161;
    }
    if (temp_a1 == 0xB) {
        goto block_156;
    }
    if (temp_a1 == 6) {
        goto block_144;
    }
    if (temp_a1 == 5) {
        goto block_140;
    }
    if (temp_a1 == 3) {
        goto block_136;
    }
    if (temp_a1 == 2) {
        goto block_119;
    }
    if (temp_a1 == 1) {
        goto block_117;
    }
    goto block_246;
block_117:
    if (sceMcGetInfo(0, 0, &this->m_unk1D0, &this->m_unk1D4) <= 0) {
        goto block_248;
    }
    printf("sceMcGetInfo() error\n");
    goto block_248;
block_119:
    temp_a2 = temp_v1_9[3];
    if ((unsigned int)(temp_a2 + 0xE) >= 6U) {
        goto block_126;
    }
    switch (temp_a2) {
    case -14:
    case -9:
        sprintf(sp50, "%s%s", MaximoDir, MaximoDir);
        goto block_128;
    case -10:
        var_s2 = 3;
        sprintf(sp50, "%s/%s", MaximoDir, (char *)iconSys + 0x184);
        goto block_128;
    case -11:
        var_s2 = 2;
        sprintf(sp50, "%s/%s", MaximoDir, (char *)iconSys + 0x144);
        goto block_128;
    case -12:
        var_s2 = 1;
        sprintf(sp50, "%s/%s", MaximoDir, (char *)iconSys + 0x104);
        goto block_128;
    case -13:
        var_s2 = 0;
        sprintf(sp50, "%s/icon.sys", MaximoDir, 3);
        goto block_128;
    }
block_126:
    sprintf(sp50, "Invalid icon file ID %d", temp_a2, 3);
    if (sp50 == 0) {
        goto block_128;
    }
    CdsAssert("MemoryCard.cpp", 0x32A, "!name");
block_128:
    temp_v1_10 = this->m_unk1E0;
    var_s3 = ((unsigned char *)this->m_unk1DC + temp_v1_10)[1];
    if (!(var_s3 & 2)) {
        goto block_132;
    }
    var_s3 |= 0x200;
    if (var_s2 < 0) {
        goto block_132;
    }
    if (*(signed char *)((char *)this + var_s2 + 0x1FA) < 0) {
        goto block_132;
    }
    this->m_unk1E0 = temp_v1_10 + 5;
    goto loop_93;
block_132:
    if (sceMcOpen(0, 0, sp50, var_s3) == 0) {
        goto block_135;
    }
    printf("sceMcOpen() error\n");
    goto block_248;
block_135:
    this->DisplayMCText(!(var_s3 & 2) ? 0x43 : 0x3A);
    goto block_248;
block_136:
    if (this->m_unk1CC >= 0) {
        goto block_138;
    }
    CdsAssert("MemoryCard.cpp", 0x33E, "miFd >= 0");
block_138:
    if (sceMcClose(this->m_unk1CC) == 0) {
        goto block_248;
    }
    printf("sceMcClose() error\n");
    goto block_248;
block_140:
    if (this->m_unk1CC >= 0) {
        goto block_142;
    }
    CdsAssert("MemoryCard.cpp", 0x344, "miFd >= 0");
block_142:
    this->m_unk1E8 = 0x1C48;
    memset((char *)this + 0x2320, 0, 0x1C48);
    if (sceMcRead(this->m_unk1CC, (char *)this + 0x2320, this->m_unk1E8) == 0) {
        goto block_248;
    }
    printf("sceMcRead() error\n");
    goto block_248;
block_144:
    if (this->m_unk1CC >= 0) {
        goto block_146;
    }
    CdsAssert("MemoryCard.cpp", 0x34D, "miFd >= 0");
block_146:
    temp_v0_13 = ((signed char *)this->m_unk1DC)[1 + this->m_unk1E0];
    var_s2_2 = 0;
    if ((unsigned int)(temp_v0_13 + 0xE) >= 6U) {
        goto block_153;
    }
    switch (temp_v0_13) {
    case -14:
    case -9:
        var_s2_2 = (char *)this + 0x2320;
        this->m_unk1E8 = 0x1C48;
        goto block_154;
    case -13:
        var_s2_2 = (char *)iconSys;
        this->m_unk1E8 = 0x3C4;
        goto block_154;
    case -12:
        var_s2_2 = (char *)Icon_tbl[0];
        this->m_unk1E8 = Icon_tbl[1] - Icon_tbl[0];
        goto block_154;
    case -11:
        var_s2_2 = (char *)Icon_tbl[2];
        this->m_unk1E8 = Icon_tbl[3] - Icon_tbl[2];
        goto block_154;
    case -10:
        var_s2_2 = (char *)Icon_tbl[4];
        this->m_unk1E8 = Icon_tbl[5] - Icon_tbl[4];
        goto block_154;
    }
block_153:
    CdsAssert("MemoryCard.cpp", 0x368, "0");
block_154:
    if (sceMcWrite(this->m_unk1CC, var_s2_2, this->m_unk1E8) == 0) {
        goto block_248;
    }
    printf("sceMcWrite() error\n");
    goto block_248;
block_156:
    if (this->m_unk1C0 <= 0) {
        goto block_158;
    }
    this->m_unk1E0 = temp_v0_12 + 1;
    goto loop_93;
block_158:
    if (sceMcMkdir(0, 0, MaximoDir) == 0) {
        goto block_248;
    }
    printf("sceMcMkdir() error\n");
    goto block_248;
block_161:
    memset(this, 0, 0x1C0);
    this->m_unk1C0 = -1;
    sprintf(sp50, "%s/*", MaximoDir);
    if (sceMcGetDir(0, 0, sp50, 0) == 0) {
        goto block_248;
    }
    printf("sceMcGetDir() error\n");
    goto block_248;
block_164:
    if (sceMcFormat(0, 0) == 0) {
        goto block_248;
    }
    printf("sceMcFormat() error\n");
    goto block_248;
block_167:
    this->m_unk1DC = 0;
    this->RemoveMCText();
    return 0xB;
block_168:
    temp_a0 = this->m_unk1C8;
    if (temp_a0 == 2) {
        goto block_174;
    }
    if (temp_a0 == 0) {
        goto block_173;
    }
    if (temp_a0 == 0xB) {
        goto block_172;
    }
    goto loop_93;
block_172:
    this->m_unk1E0 = temp_v0_12 + 1;
    goto loop_93;
block_173:
    var_v0 = 8;
    var_a1 = 0x10;
    goto block_175;
block_174:
    var_v0 = 8;
    var_a1 = 0x14;
block_175:
    this->m_unk1E4 = var_v0;
    this->m_unk1E0 = 0;
    this->m_unk1EC = 0;
block_176:
    this->DisplayMCText(var_a1);
    if (this->m_unk1E6 == 0) {
        goto loop_93;
    }
    return 9;
block_179:
    if (this->CheckFree() == 0) {
        goto block_181;
    }
    this->m_unk1E0 += 1;
    goto loop_93;
block_181:
    var_v0 = 0x1000;
    if (this->m_unk1E0 != 3) {
        goto block_184;
    }
    var_v0 = 8;
    var_a1 = 0x36;
    goto block_175;
block_184:
    var_a1 = 0x2F;
    goto block_175;
block_185:
    temp_a0_2 = this->m_unk1C8;
    if (temp_a0_2 == 2) {
        goto block_191;
    }
    if (temp_a0_2 == 0) {
        goto block_190;
    }
    if (temp_a0_2 == 0xB) {
        goto block_189;
    }
    goto loop_93;
block_189:
    this->m_unk1E0 = temp_v0_12 + 4;
    goto loop_93;
block_190:
    var_v0 = 0x1000;
    var_a1 = 0x33;
    goto block_175;
block_191:
    this->m_unk1E0 = temp_v0_12 + 1;
    if (this->m_unk1EC != 0) {
        goto loop_93;
    }
    this->m_unk1F0 = 1;
    var_a1 = 0x21;
    this->m_unk1EC = 1;
    this->m_unk1E4 = 0x4000;
    this->m_unk1E6 = 0;
    goto block_176;
block_193:
    this->m_unk1E0 = temp_v0_12 + temp_v1_9[1];
    goto loop_93;
block_194:
    temp_s0_2 = this->m_unk3F64;
    if (temp_s0_2 != this->CheckSum((unsigned char *)this + 0x232C)) {
        goto block_197;
    }
    if (this->CheckLoadData() == 0) {
        goto block_197;
    }
    return 0xB;
block_197:
    this->m_unk1E0 += 1;
    this->m_unk1F6 = (signed char)(int)(2.0f * GAME_FPS);
    this->DisplayMCText(0x1A);
    goto block_310;
block_198:
    if (this->m_unk1FF < 0) {
        goto block_203;
    }
    if (this->m_unk1FE >= 0) {
        goto block_202;
    }
    this->m_unk1E0 = temp_v0_12 + 6;
    if (CheckFiles() != 0) {
        goto block_204;
    }
    DisplayMCText(0x1A);
    this->m_unk1F6 = (signed char)(int)(2.0f * GAME_FPS);
    *(int *)((char *)this + 0x2338) = 0;
    *(int *)((char *)this + 0x27EC) = 0;
    *(int *)((char *)this + 0x2CA0) = 0;
    *(int *)((char *)this + 0x3154) = 0;
    *(int *)((char *)this + 0x3608) = 0;
    *(int *)((char *)this + 0x3ABC) = 0;
    return -1;
block_202:
    this->m_unk1E0 = temp_v0_12 + 1;
    goto loop_93;
block_203:
    this->m_unk1E0 = temp_v0_12 + 6;
block_204:
    *(int *)((char *)this + 0x2338) = 0;
    *(int *)((char *)this + 0x27EC) = 0;
    *(int *)((char *)this + 0x2CA0) = 0;
    *(int *)((char *)this + 0x3154) = 0;
    *(int *)((char *)this + 0x3608) = 0;
    *(int *)((char *)this + 0x3ABC) = 0;
    goto loop_93;
block_205:
    this->DisplayMCText(0x4C);
    temp_v0_14 = this->m_unk1FF;
    if (temp_v0_14 < 0) {
        goto block_209;
    }
    temp_a0_3 = (char *)this + (temp_v0_14 << 6);
    temp_v0_15 = this->m_unk208 == *(int *)temp_a0_3;
    var_s3_2 = temp_v0_15 & 0xFF;
    if (temp_v0_15 == 0) {
        goto block_208;
    }
    var_s3_2 = (this->m_unk20C == *(int *)(temp_a0_3 + 4)) & 0xFF;
block_208:
    goto block_210;
block_209:
    var_s3_2 = 0;
block_210:
    temp_s2 = this->m_unk3F64;
    if (temp_s2 != this->CheckSum((unsigned char *)this + 0x232C)) {
        goto block_212;
    }
    if (CheckLoadData() != 0) {
        goto block_215;
    }
block_212:
    if (var_s3_2 == 0) {
        goto block_214;
    }
    memcpy((char *)this + 0x232C, (char *)this + 0x6E4, 0x1C38);
    goto block_215;
block_214:
    *(int *)((char *)this + 0x2338) = 0;
    *(int *)((char *)this + 0x27EC) = 0;
    *(int *)((char *)this + 0x2CA0) = 0;
    *(int *)((char *)this + 0x3154) = 0;
    *(int *)((char *)this + 0x3608) = 0;
    *(int *)((char *)this + 0x3ABC) = 0;
block_215:
    if (var_s3_2 != 0) {
        goto block_217;
    }
    this->m_unk210 = 0;
    goto block_221;
block_217:
    var_v0_2 = this->m_unk214;
    if (var_v0_2 < 0) {
        goto block_219;
    }
    goto block_220;
block_219:
    var_v0_2 = 0;
block_220:
    this->m_unk210 = var_v0_2;
block_221:
    this->DisplaySlot(0);
    this->m_unk1EC = 2;
    this->m_unk1E0 += 1;
    goto loop_93;
block_222:
    if (this->m_unk1E6 != 0x1000) {
        goto block_224;
    }
    this->RemoveMCText();
    return 9;
block_224:
    if (this->m_unk1C8 == 0xB) {
        goto block_226;
    }
    goto block_227;
block_226:
    this->m_unk1E0 -= 1;
    goto loop_93;
block_227:
    this->m_unk1E0 = 0;
    this->m_unk1EC = 0;
    this->DisplaySlot(1);
    goto loop_93;
block_228:
    this->CheckFree();
    if (this->m_unk1FE < 0) {
        goto block_230;
    }
    temp_v1_11 = (char *)this + (this->m_unk1FF << 6);
    this->m_unk208 = *(int *)temp_v1_11;
    this->m_unk20C = *(int *)(temp_v1_11 + 4);
    this->m_unk214 = this->m_unk210;
    memcpy((char *)this + 0x6D8, (char *)this + 0x2320, 0x1C48);
block_230:
    this->m_unk1E0 += 1;
    goto loop_93;
block_231:
    temp_s2_2 = this->m_unk3F64;
    if (temp_s2_2 != this->CheckSum((unsigned char *)this + 0x232C)) {
        goto block_234;
    }
    if (CheckLoadData() == 0) {
        goto block_234;
    }
    this->DisplayMCText(0x46);
    this->m_unk210 = 0;
    this->DisplaySlot(0);
    this->m_unk1EC = 4;
    goto block_235;
block_234:
    this->DisplayMCText(0x1D);
    this->m_unk1EC = 5;
    this->m_unk1E4 = 0x1000;
    this->m_unk1E6 = 0;
block_235:
    this->m_unk1E0 += 1;
    goto loop_93;
block_236:
    temp_a0_4 = this->m_unk1C8;
    if (temp_a0_4 == 2) {
        goto block_240;
    }
    if (temp_a0_4 == 0xB) {
        goto block_239;
    }
    goto block_241;
block_239:
    this->m_unk1E0 = temp_v0_12 + 1;
    goto loop_93;
block_240:
    var_v0 = 0x1000;
    var_a1 = 0x2B;
    goto block_175;
block_241:
    var_v0 = 0x1000;
    var_a1 = 0x33;
    goto block_175;
block_243:
    this->CheckFree();
    if (this->m_unk1FE < 0) {
        goto block_245;
    }
    this->m_unk1E0 += 1;
    this->m_unk1E4 = 0;
    this->m_unk1E6 = 0;
    this->RemoveMCText();
    goto loop_93;
block_245:
    this->m_unk1E0 = 0;
    var_a1 = (CheckFiles() == 0) ? 0x1D : 0x49;
    this->m_unk1E4 = 0x1000;
    goto block_176;
block_246:
    printf("Unknown MC command %d\n", (int)temp_a1);
    CdsAssert("MemoryCard.cpp", 0x47B, "0");
    goto block_248;
block_247:
    printf("sceMcSync() error %d\n", temp_v0_3, 1, -1);
    CdsAssert("MemoryCard.cpp", 0x483, "0");
block_248:
    temp_v1_12 = this->m_unk1EC;
    if (temp_v1_12 == -0x14) {
        goto block_297;
    }
    if (temp_v1_12 == 5) {
        goto block_294;
    }
    if (temp_v1_12 == 4) {
        goto block_288;
    }
    if (temp_v1_12 == 3) {
        goto block_279;
    }
    if (temp_v1_12 == 2) {
        goto block_269;
    }
    if (temp_v1_12 == 1) {
        goto block_256;
    }
    goto block_310;
block_256:
    if (!(var_s0 & 0xA0)) {
        goto block_264;
    }
    temp_v1_13 = this->m_unk204 + 3 + this->m_unk1F0;
    var_a0 = 0;
    if (temp_v1_13 >= *(unsigned int *)(gInterface + 0x80)) {
        goto block_260;
    }
    var_a0 = *(FontNode **)(*(char **)(gInterface + 0x88) + temp_v1_13 * 4);
block_260:
    SetColor__8FontNodeF9FontColor(var_a0, 7);
    this->m_unk1F0 ^= 1;
    temp_v1_14 = this->m_unk204 + 3 + this->m_unk1F0;
    var_a0_2 = 0;
    if (temp_v1_14 >= *(unsigned int *)(gInterface + 0x80)) {
        goto block_263;
    }
    var_a0_2 = *(FontNode **)(*(char **)(gInterface + 0x88) + temp_v1_14 * 4);
block_263:
    SetColor__8FontNodeF9FontColor(var_a0_2, 4);
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x40U);
    goto block_310;
block_264:
    if (!(this->m_unk1E6 & 0x4000)) {
        goto block_310;
    }
    if (this->m_unk1F0 == 0) {
        goto block_267;
    }
    this->DisplayMCText(0x2A);
    return 9;
block_267:
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x41U);
    var_a1 = 0x27;
    this->m_unk1E0 = 4;
    this->m_unk1EC = 0;
    this->m_unk1E6 = 0;
    this->m_unk1E4 = 0;
    goto block_176;
block_269:
    temp_v0_16 = this->SelectSlot(var_s0);
    if (temp_v0_16 == 9) {
        goto block_277;
    }
    if (temp_v0_16 == 0xB) {
        goto block_272;
    }
    goto block_310;
block_272:
    if (*(int *)((char *)this + 0x2338 + this->m_unk210 * 0x4B4) == 0) {
        goto block_274;
    }
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x41U);
    this->DisplayMCText(0x4F);
    this->m_unk1E0 = 0x10;
    this->m_unk1EC = 3;
    this->m_unk1F7 = 0;
    goto block_310;
block_274:
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x41U);
    memcpy((char *)this + 0x2320, (char *)this + 0x218, 0xA);
    if (this->m_unk230 != 0) {
        goto block_276;
    }
    this->m_unk230 = 1;
block_276:
    memcpy((char *)this + this->m_unk210 * 0x4B4 + 0x232C, (char *)this + 0x224, 0x4B4);
    this->m_unk3F64 = this->CheckSum((unsigned char *)this + 0x232C);
    this->m_unk1E0 = 0x12;
    this->m_unk1EC = 0;
    goto block_310;
block_277:
    return 9;
block_279:
    if (!(var_s0 & 0x1000)) {
        goto block_282;
    }
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x41U);
    this->DisplayMCText(0x4C);
    this->m_unk1E0 = 0xE;
    this->m_unk1EC = 2;
    this->m_unk1F7 = 0;
    goto block_284;
block_282:
    if (!(var_s0 & 0x4000)) {
        goto block_284;
    }
    this->m_unk1F7 = 1;
block_284:
    if (this->m_unk1F7 == 0) {
        goto block_310;
    }
    if (this->m_unk1C8 == 0xB) {
        goto block_274;
    }
    goto block_310;
block_288:
    temp_v0 = this->SelectSlot(var_s0);
    if (temp_v0 == 0xB) {
        goto block_290;
    }
    goto block_292;
block_290:
    if (*(int *)((char *)this + 0x2338 + this->m_unk210 * 0x4B4) == 0) {
        goto block_310;
    }
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x41U);
    memcpy((char *)this + 0x6D8, (char *)this + 0x2320, 0x1C48);
    memcpy((char *)this + 0x224, (char *)this + this->m_unk210 * 0x4B4 + 0x6E4, 0x4B4);
    this->m_unk214 = this->m_unk210;
    temp_a0_5 = (char *)this + (this->m_unk1FF << 6);
    this->m_unk208 = *(int *)temp_a0_5;
    this->m_unk20C = *(int *)(temp_a0_5 + 4);
    return 0xB;
block_292:
    return temp_v0;
block_294:
    if (!(var_s0 & 0x1000)) {
        goto block_310;
    }
    return 9;
block_297:
    if (!(var_s0 & 0x4000)) {
        goto block_302;
    }
    if (this->m_unk1F0 == 0) {
        goto block_300;
    }
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x41U);
    this->m_unk1E0 = 0;
    this->m_unk1EC = 0;
    this->m_unk1E6 = 0;
    this->m_unk1E4 = 0;
    goto block_310;
block_300:
    this->m_unk1F8 = 0;
    return 9;
block_302:
    if (!(var_s0 & 0xA0)) {
        goto block_310;
    }
    temp_v1_15 = this->m_unk204 + 1 + this->m_unk1F0;
    var_a0_3 = 0;
    if (temp_v1_15 >= *(unsigned int *)(gInterface + 0x80)) {
        goto block_306;
    }
    var_a0_3 = *(FontNode **)(*(char **)(gInterface + 0x88) + temp_v1_15 * 4);
block_306:
    SetColor__8FontNodeF9FontColor(var_a0_3, 7);
    this->m_unk1F0 ^= 1;
    temp_v1_16 = this->m_unk204 + 1 + this->m_unk1F0;
    var_a0_4 = 0;
    if (temp_v1_16 >= *(unsigned int *)(gInterface + 0x80)) {
        goto block_309;
    }
    var_a0_4 = *(FontNode **)(*(char **)(gInterface + 0x88) + temp_v1_16 * 4);
block_309:
    SetColor__8FontNodeF9FontColor(var_a0_4, 4);
    PlaySoundNonPositional__6PSoundFUi(gSound, 0x40U);
block_310:
    return -1;
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
// note: 20 words differ; switch with cases in reverse-test order; original tests 12,8,9,11 and keeps case bodies out of line, ours is 0xE8 bytes vs 0xDC; float args f12 loaded before f13. Tried if/else chain (29), named float locals (22), reversed case order (36), early return -1 tail (23).
int MemoryCard::LoadGame() {
    m_unk3F6C->Slot4(0, 0, 0, 0.0f, 1.0f);
    int nResult = ProcessCommand();
    switch (nResult) {
    case 11:
        SetSetting(&m_unk6D8);
        DeleteScreen();
        return 11;
    case 9:
        DeleteScreen();
        return 9;
    case 8:
        m_unk1DC = 0;
        m_unk1E0 = 0x3C;
        break;
    case 12:
        break;
    default:
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

// DRAFT: 0x001521B0 DisplaySlot__10MemoryCardFb
// note: 8 words; only s4/s6 swapped (orig pData in s4, SlotPos ptr in s6). Tried decl order of locals, pSecond local, SlotPosition ptr local, pData hoist.
void MemoryCard::DisplaySlot(bool bFlag) {
    int nSel = m_unk214;
    if (nSel >= 0) {
        char *pEnt = (char *)this + (m_unk1FF << 6);
        if (m_unk208 != *(int *)pEnt || m_unk20C != *(int *)(pEnt + 4)) {
            nSel = -1;
        }
    }
    unsigned char *pFont = gInterface + 0x80;
    int nI;
    int nUsed;
    int nOff;
    FontNode **pFirst;
    char *pText = *(char **)(pFont + 0x100) + 0x3FC;
    for (nI = 0, nOff = 0; nI < 6; nI++) {
        pFirst = &m_unk3F88[nI][0];
        if (m_unk3F88[nI][0] != 0) RemoveText__11FontManagerFP8FontNode(pFont, m_unk3F88[nI][0]);
        if (m_unk3F88[nI][1] != 0) RemoveText__11FontManagerFP8FontNode(pFont, m_unk3F88[nI][1]);
        if (bFlag) {
            *pFirst = 0;
            m_unk3F88[nI][1] = 0;
            SetAnimLoopCount__6PMNodeFib(m_unk3F70[nI], 1, 0);
        } else {
            char *pData = (char *)this + nOff;
            nUsed = *(int *)(pData + 0x2338);
            char *pStr;
            if (nUsed != 0) {
                pStr = (nI == nSel) ? *(char **)pText : *(char **)(pText + 0xC);
            } else {
                pStr = *(char **)(pText + 0x18);
            }
            float fY = SlotPos[nI].fY;
            *pFirst = DisplayString__11FontManagerFPcffi9FontColor9FontAlign(pFont, pStr, SlotPos[nI].fX, fY, 3, (m_unk210 == nI) ? 4 : 7, 0);
            if (nUsed != 0) {
                char buf[32];
                char *pBase = *(char **)(pFont + 0x100) + 0x9C;
                sprintf(buf, "%d%s %s", *(unsigned char *)(pData + 0x2335), "%", (*(signed char *)(pData + 0x2337) != 0) ? *(char **)(pBase + 0xC) : *(char **)pBase);
                m_unk3F88[nI][1] = DisplayString__11FontManagerFPcffi9FontColor9FontAlign(pFont, buf, SlotPos[nI].fX, fY - 25.0f, 3, (m_unk210 == nI) ? 4 : 7, 0);
            } else if (m_unk3F88[nI][1] != 0) {
                m_unk3F88[nI][1] = 0;
            }
            if (nI == m_unk210) {
                ((PMNodeView *)m_unk3F70[nI])->SetAllAnimFlags(DefaultLoopAnim);
            } else {
                SetAnimLoopCount__6PMNodeFib(m_unk3F70[nI], 1, 0);
            }
        }
        nOff += 0x4B4;
    }
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
        CdsAssert("MemoryCard.cpp", 0x15A, "mpSaveNode");
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

// FUNCTION: 0x00152980 __ct__10MemoryCardFv
MemoryCard::MemoryCard() {
    m_unk200 = 0;
    m_unk1DC = 0;
}
