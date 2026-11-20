// FLAGS: -str readonly
#include "types.h"
#include "Interface.h"
#include "PTextureManager.h"

// TODO(header): foreign declarations
class Player {
public:
    void SwapAbility(int arg0);
};
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    void StopStreamsAndRequestEEControl();
    int GetEEControlStatus();
    void SetAllowCallOneFrameHasElapsed(bool flag);
    void AbilityScreenEnter();
    void AbilityScreenLeave();
    void PlaySoundUbiquitous(unsigned int id);
    char _pad000[0x10];
};
extern PSound gSound;

class FileUtils {
public:
    void LoadingHangCheckInit();
};

class PParticleManager {
public:
    void Remove(PParticleSystem *pSystem);
};
extern char gGfxEng[1504384];

// PDisplayList is declared in PDisplayList.h without ClearFrameBuffer; only the two members used here are listed.
class PDisplayList {
public:
    void SetGsRegisters(u_long128 *pRegData, int nNumRegs);
    void ClearFrameBuffer(short x0, short x1, short x2, short x3, char r, char g, char b, char a, unsigned int z);
};

extern unsigned char fst_bUseOldLoadingDisplay;

// Pad is reached via lui/addiu; the placeholder keeps gPad above the 8-byte small-data threshold.
class Pad {
public:
    void PauseVibrate(bool flag);

    char _pad000[0x110];
    unsigned short m_unk110;    // 0x110 button state
};
extern Pad gPad;

// Polymorphic embedded object; Slot04 is the vtable word at offset 0x18
// (the compiler places the first virtual slot at offset 0x8).
class PVirtObj {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03(int flag);
    virtual void Slot04();
    virtual void Slot05(int flag);
};

// Object at PMNode+0x24; virtual slots 10, 12, 13 and 15 are called by GameHud::UpdateStatus.
class PVirtSlots {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(int flag);
    virtual void Slot11();
    virtual void Slot12(int flag);
    virtual void Slot13(short flag);
    virtual void Slot14();
    virtual void Slot15(float flag);
};

// Only the mangled name (13eBoxIntersect) matters here; the enumerator names are placeholders.
enum eBoxIntersect { eBoxIntersect_Value0 = 0, eBoxIntersect_Value1 = 1 };

class PMat4;

class PMNode {
public:
    virtual void Slot00(int flag);
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04(float fA, float fB, PMat4 *pMat, int arg3, bool bFlag);
    void ProcessFxTriggers(float arg0, PMat4 *arg1, bool arg2, bool arg3);
    PMNode *Find(unsigned int id);
    void RecurseSetSTAnimOptions(bool flag);
    void SetAllFrustrumTest(eBoxIntersect arg0);
    void RecurseSetLoopRateByID(unsigned int id, int arg1, float arg2);
    void ScaleSet(float arg0, float arg1, float arg2, float arg3);
    void EnableAnim(bool arg0, bool arg1);
    void SetAnimLoopCount(int arg0, bool arg1);

    char _pad004[0x8];
    int m_unkC;                 // 0x00C
    char _pad010[0x70];
    float m_unk80;              // 0x080
};

// Placeholder size; the original object is larger than the 8-byte small-data threshold.
extern char CoinAnim[0x10];
extern char DefaultLoopAnim[0x10];

// Placeholder size; gDebug is reached via lui/addiu, so its type must exceed the 8-byte small-data threshold.
extern char gDebug[0x10];
extern "C" void DebugClear__5DebugFv(void *pThis);
extern "C" void DebugDispPos__5DebugFPcUiUii(void *pThis, char *text, unsigned int x, unsigned int y, int color);
extern "C" void RefreshDisplay__10PGfxEngineFv(void *pThis);
extern "C" void SoundOneFrameHasElapsed_R__9MaxEngineFRiRi(void *pThis, int *pA, int *pB);
extern "C" void IncrementSecondarySyncCounts__9MaxEngineFv(void *pThis);
extern "C" void SetFrameRate__6PMNodeFfb(PMNode *pThis, float rate, bool flag);
extern unsigned char MODE_PAL;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
// PMat4 member; the call passes the matrix object as pThis. PMat4.h has no declaration for it.
extern "C" void MakeParallelProjectionMatrix__5PMat4Fffffffffffff(void *pThis, float, float, float, float, float, float, float, float, float, float, float, float);

class HudData {
public:
    unsigned int m_unk0;
    signed char m_unk4;
    unsigned char m_unk5;
};

class HudInventory {
public:
    HudInventory();
    void AddIcon(int id);
    void Reset();
    void UpdateGroup(int arg0);
    void UpdateStatus(bool flag);
    int SwapCheck(unsigned int arg0);
    void UpdateShieldIcon();

    char _pad000[0x4];
    void *m_unk4;               // 0x004
    char _pad008[0x7];
    signed char m_unkF;         // 0x00F
    unsigned char m_unk10;      // 0x010
    char _pad011[0xB];
    void *m_unk1C;              // 0x01C element with a PArray at 0x14 (index 0x18, storage 0x1C)
    char _pad020[0x1C];
    int m_unk3C;                // 0x03C
    int m_unk40;                // 0x040 icon index, used by SwapCheck
};

extern unsigned char __vt__7GameHud[];
extern unsigned char __vt__12HudInventory[];
extern unsigned char __vt__7HudGrim[];
extern unsigned char __vt__8HudCombo[];
extern unsigned char __vt__12HudBossMeter[];
extern unsigned char __vt__8HudSuper[];
extern unsigned char __vt__9HudHealth[];
class HudHealth;
extern "C" void __dl__FPv(void *pMem);

class PArray {
public:
    void Allocate(unsigned int count);
    void Add(void *item);
    void Remove(void *item);
};

class FontNode;

class FontManager {
public:
    void Init();
    void RemoveText(FontNode *pNode);
    void RemoveText(unsigned short arg0);
    int DisplayString(int arg0, int arg1, int arg2, bool arg3);
    void RemoveAll(bool flag);
    void RenderWarning(int arg0);
};

// MemMgr is 908 bytes; the field at offset 0x18 is saved and cleared around AddIcon.
extern char MemMgr[908];

extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern Interface gInterface;
// HintTable is 120 bytes (symbols.tsv); element size taken from the lw/sll 2 indexing.
extern int HintTable[30];
// BoxSize is a table of 12-byte entries; the float fields at offsets 4 and 8 are read by InitNode.
extern char BoxSize[0x100];
// gEng is 105360 bytes; the array size keeps it out of small data. InitRender reads gEng + 0x50.
extern char gEng[105360];
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0ScaleVectorXYZ(float *dst, float *src, float scale);
extern "C" void RenderBlendedFragments__10PGfxEngineFPf(void *pThis, float *pBuf);
extern "C" void vu1ZBufferUpdate__Fb(bool bEnable);
extern "C" void vu1ClearZBuffer__Fv(void);
extern "C" void vu1SetScreenMatrix__FP5PMat4(void *pMat);
extern "C" void vu1SetViewMatrix__FP5PMat4(void *pMat);
extern "C" void vu1SetClipMatrix__FP5PMat4(void *pMat);

// FUNCTION: 0x13F800 __dt__7HudGrimFv
extern "C" HudGrim *__dt__7HudGrimFv(HudGrim *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__7HudGrim;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x13F880 SoundGainEEControl__9InterfaceFv
void Interface::SoundGainEEControl() {
    gSound.StopStreamsAndRequestEEControl();
    WaitForEEControl();
}

// FUNCTION: 0x13F8C0 WaitForEEControl__9InterfaceFv
void Interface::WaitForEEControl() {
    ((FileUtils *)this)->LoadingHangCheckInit();
    for (unsigned int i = 0;; i++) {
        if (gSound.GetEEControlStatus() == 3) {
            gSound.SetAllowCallOneFrameHasElapsed(false);
            break;
        }
        LoadingDisplay(i, 6);
    }
}

// FUNCTION: 0x13F940 SetPause__9InterfaceFv
void Interface::SetPause() {
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    ((PVirtObj *)((char *)this + 0x1FC))->Slot05(1);
    ((PVirtObj *)((char *)this + 0x1EC))->Slot05(1);
    ((PVirtObj *)((char *)this + 0x21C))->Slot05(1);
    ((PVirtObj *)((char *)this + 0x20C))->Slot05(1);
    *(int *)(MemMgr + 0x18) = saved;
}

// FUNCTION: 0x13F9D0 LevelClear__9InterfaceFv
void Interface::LevelClear() {
    ((PVirtObj *)((char *)this + 0x290))->Slot04();
    ((PVirtObj *)((char *)this + 0x250))->Slot04();
    m_unk1C0 &= ~8;
}

// FUNCTION: 0x13FB90 HudUpdate__9InterfaceFi
void Interface::HudUpdate(int arg0) {
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    ((PVirtObj *)((char *)this + 0x1CC))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x1DC))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x1EC))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x1FC))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x20C))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x21C))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x22C))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x250))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x270))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x290))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x2E8))->Slot03(arg0);
    *(int *)(MemMgr + 0x18) = saved;
}

// TODO(header): mpPlayerData__7GameHud is a pointer-sized small-data global.
extern GameHud *mpPlayerData__7GameHud;
// TODO(header): IconTable is a 0x20-byte-stride table indexed by icon type; AbilityTable is shared with Player.cpp.
extern char IconTable[0x1100];
extern signed char AbilityTable[];

// FUNCTION: 0x13FEC0 UpdateStatus__7HudGrimFb
void HudGrim::UpdateStatus(bool arg0) {
    m_unkF = 1;
    *(int *)((char *)m_unk4 + 0xC) = 1;
}

// FUNCTION: 0x13FEE0 UpdateCover__7HudGrimFv
void HudGrim::UpdateCover() {
    int threshold = 0x14;
    int hp = *(int *)((char *)mpPlayerData__7GameHud + 0x34);
    int i = 0;
    int off = 0;
    do {
        void *elem = *(void **)((char *)this + off + 0x14);
        if (elem != 0) {
            int val;
            if (hp >= threshold) {
                val = 1;
            } else {
                val = 0;
            }
            *(int *)((char *)elem + 0xC) = val;
        }
        i += 1;
        off += 4;
        threshold += 0xA;
    } while (i < 3);
}

// FUNCTION: 0x140180 Delete__7HudGrimFv
void HudGrim::Delete() {
    PParticleSystem *temp_a1 = m_unk20;
    if (temp_a1 != 0) {
        ((PParticleManager *)(gGfxEng + 0x154F00))->Remove(temp_a1);
        m_unk20 = 0;
    }
}

// Cover element IDs; the original local object GrimCover$1444 at 0x241200 (12 bytes).
static unsigned int GrimCover_1444[3] = {0x0D3B7139, 0x2F38C229, 0xC132DB59};

// DRAFT: 0x1401C0 Init__7HudGrimFP9PMeshNodeP7HudData
// note: 10 words differ; GrimCover table reloc names GrimCover_1444 (original GrimCover$1444, '$' rejected), and the Find arg setup and store address order differ. Tried: static table, do/while with offset walk.
void HudGrim::Init(PMeshNode *meshNode, HudData *hud) {
    ((GameHud *)this)->Init(meshNode, hud);
    m_unk10 = ((PMNode *)meshNode)->Find(0x303B74C6);
    if (m_unk4 != 0) {
        m_unk4->RecurseSetSTAnimOptions(false);
    }
    int n = 0;
    int off = 0;
    do {
        n++;
        *(void **)((char *)m_unk14 + off) = ((PMNode *)meshNode)->Find(*(unsigned int *)((char *)GrimCover_1444 + off));
        off += 4;
    } while (n < 3);
    m_unk20 = 0;
}

// FUNCTION: 0x140270 Update__8HudSuperFi
void HudSuper::Update(int arg0) {
    short cur = m_unkC;
    int target = *(int *)((char *)mpPlayerData__7GameHud + 0x3C);
    int diff = target - cur;
    if (diff != 0) {
        if (diff > 0) {
            m_unkC = cur + 4;
            if (target < m_unkC) {
                m_unkC = (short)target;
            }
        } else {
            m_unkC = cur - 4;
            if (m_unkC < target) {
                m_unkC = (short)target;
            }
        }
        UpdateBar(m_unkC);
    }
}

// FUNCTION: 0x1411C0 AbilityScreen__9InterfaceFv
int Interface::AbilityScreen() {
    int buttons = gPad.m_unk110;
    if (m_unk324 < 0) {
        if (buttons & 1) {
            m_unk1C0 &= ~8;
            gGfxEng[0x1558B0] = 0;
            SetPause();
            DisplayLevelName(-1, 0xF0);
            ((PVirtObj *)((char *)this + 0x2E8))->Slot05(0);
            gPad.PauseVibrate(true);
            ((FontManager *)((char *)this + 0x80))->RemoveAll(true);
        } else {
            return 0;
        }
    }
    return 1;
}

// FUNCTION: 0x141270 AddAbility__9InterfaceFi
void Interface::AddAbility(int arg0) {
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    ((HudInventory *)((char *)this + 0x2E8))->AddIcon(arg0);
    *(int *)(MemMgr + 0x18) = saved;
}

// FUNCTION: 0x001412B0 SetMaxValue__12HudBossMeterFsi
void HudBossMeter::SetMaxValue(short arg0, int arg1) {
    float oldMax = *(float *)&m_unk10;
    m_unkC = arg0;
    *(float *)&m_unk10 = (float)arg0;
    if (m_unk14 < 0) {
        m_unk14 = arg0;
    } else {
        m_unk14 = (short)(((float)m_unk14 * *(float *)&m_unk10) / oldMax);
    }
    if ((unsigned char)m_unkF != 2) {
        m_unkF = 1;
        *(float *)((char *)m_unk4 + 0x84) = m_unk8 - 5.0f;
    }
    if (arg1 > 0 && arg1 != m_unk16) {
        m_unk16 = (signed char)arg1;
        SetFace();
    }
    ((PMNode *)m_unk4)->Slot04(0.0f, 0.0f, 0, 8, false);
    *(int *)((char *)m_unk4 + 0xC) = 1;
}

// FUNCTION: 0x1413A0 SetValue__12HudBossMeterFs
void HudBossMeter::SetValue(short value) {
    m_unkC = value;
    if (value < m_unk14) {
        float f = (float)value / *(float *)&m_unk10;
        if (!(f <= 1.0f)) {
            f = 1.0f;
        }
        *(float *)((char *)m_unk18 + 0xA0) = f;
        *((unsigned char *)m_unk18 + 0x3E) |= 8;
    }
}

// FUNCTION: 0x141630 SetFace__12HudBossMeterFv
void HudBossMeter::SetFace() {
    static unsigned int FaceID[3] = {0x00000000, 0x902DF890, 0x4B01E2EE};
    int i = 0;
    int off = 0;
    do {
        PMNode *node = ((PMNode *)m_unk4)->Find(*(unsigned int *)((char *)FaceID + off));
        if (node != 0) {
            *(int *)((char *)node + 0xC) = (i == m_unk16) ? 1 : 0;
        }
        i++;
        off += 4;
    } while (i < 3);
}

// FUNCTION: 0x1416B0 Reset__12HudBossMeterFv
void HudBossMeter::Reset() {
    *(int *)((char *)m_unk4 + 0xC) = 0;
    *(int *)((char *)m_unk4 + 0x2C) = 0x3F800000;
    *(float *)((char *)m_unk4 + 0x84) = m_unk8 - 5.0f;
    *(int *)((char *)m_unk18 + 0xA0) = 0x3F800000;
    *(int *)((char *)m_unk1C + 0xA0) = 0;
    m_unkF = 0;
    m_unk14 = -1;
    m_unk10 = 0x42C80000;
    m_unk17 = 1;
}

// DRAFT: 0x141710 Init__12HudBossMeterFP9PMeshNodeP7HudData
// note: DIFF 28 words; branch layout and shared sb $zero,0x16 delay slot differ. Tried ==/!= polarity (33, 28), pre-branch m_unk16 store (44).
void HudBossMeter::Init(PMeshNode *meshNode, HudData *hud) {
    m_unk4 = ((PMNode *)meshNode)->Find(hud->m_unk0);
    m_unkF = hud->m_unk5;
    m_unkE = hud->m_unk4;
    m_unk8 = *(float *)((char *)m_unk4 + 0x84);
    if (hud->m_unk0 != 0xA389995D) {
        m_unk18 = ((PMNode *)m_unk4)->Find(0x463547C7U);
        m_unk1C = ((PMNode *)m_unk4)->Find(0x6780BC04U);
        m_unk16 = 2;
    } else {
        m_unk18 = ((PMNode *)m_unk4)->Find(0x2291CBBBU);
        m_unk1C = ((PMNode *)m_unk4)->Find(0x20DDED4AU);
        m_unk16 = 0;
    }
    SetFace();
}

// DRAFT: 0x00141960 UpdateStatus__8HudComboFb
// note: 54 words differ; original hoists the state constant 2 to entry, loads the mpPlayerData pointer and adds 4 before the index, and compares 2,1,3,0; ours folds +4 into lh offset. Tried: case orders 2,3,1,0 (69) and 2,1,3,0 (64); short-indexed global load (56).
void HudCombo::UpdateStatus(bool flag) {
    m_unkC = *(short *)((char *)mpPlayerData__7GameHud + 4 + (m_unkE * 4));
    switch (m_unkF) {
    case 0:
        m_unkF = 1;
        m_unk4->SetAllFrustrumTest((eBoxIntersect)1);
        ((PVirtObj *)m_unk4)->Slot05(0);
        ComboNumber();
        return;
    case 2:
        if (flag) {
            m_unk8 = 0x40000000;
            return;
        }
        m_unkF = 1;
        break;
    case 3:
        SetFrameRate__6PMNodeFfb(m_unk4, 0.5f, false);
        m_unkF = 1;
        break;
    case 1:
        break;
    default:
        return;
    }
    ComboNumber();
    if (m_unk44 != 0) {
        ((PVirtObj *)m_unk44)->Slot05(0);
    }
    if (m_unk4C != 0) {
        ((PVirtObj *)m_unk4C)->Slot05(0);
    }
}

// FUNCTION: 0x141A80 ComboFinish__8HudComboFv
void HudCombo::ComboFinish() {
    void *temp_a1 = m_unk48;
    if (temp_a1 != 0) {
        *(int *)((char *)temp_a1 + 0x2C) = 0x3F800000;
    }
    void *temp_a0 = m_unk38;
    if (temp_a0 != 0) {
        *(int *)((char *)temp_a0 + 0x2C) = 0x3F800000;
    }
}

// DRAFT: 0x1424A0 UpdateStatus__7GameHudFb
// note: switch on m_unkF with case order 0,3,2,1 gives DIFF 54 (if-chain 65, case order 2,3,1,0 67); compare sequence 1,2,3,0 vs original 2,3,1,0 and register use in the CoinAnim/virtual calls differ.
void GameHud::UpdateStatus(bool arg0) {
    m_unk8 = arg0 ? 2.0f : 80.0f;
    switch (m_unkF) {
    case 0:
        m_unkF = 1;
        SetNumber();
        ((PMNode *)m_unk4)->SetAllFrustrumTest((eBoxIntersect)1);
        ((PVirtObj *)m_unk4)->Slot05((int)&CoinAnim);
        break;
    case 3:
        m_unkF = 1;
        {
            PVirtSlots *pSlots = *(PVirtSlots **)((char *)m_unk4 + 0x24);
            pSlots->Slot15(1.0f);
            pSlots->Slot12(1);
            pSlots->Slot10(0);
            pSlots->Slot13(*(short *)(CoinAnim + 4));
        }
        break;
    case 2:
        if (!arg0) {
            m_unkF = 1;
            ((PMNode *)m_unk4)->EnableAnim(true, false);
            ((PMNode *)m_unk4)->SetAnimLoopCount(0, false);
        }
        break;
    case 1:
        break;
    }
}

// DRAFT: 0x142620 Reset__7GameHudFv
// note: 30 words differ; lbu/bltz match, but the original loads the mpPlayerData pointer before andi and folds +4 into addiu before the index add; ours folds +4 into the lh offset and reloads the global after andi. Tried: int local for m_unkE, char* base + 4, int table view, explicit offset variable.
void GameHud::Reset() {
    int idx = m_unkE;
    if (idx >= 0) {
        char *base = (char *)mpPlayerData__7GameHud;
        int off = (idx & 0xFF) << 2;
        m_unkC = *(short *)(base + 4 + off);
        if (m_unkC == 0) {
            *(int *)((char *)m_unk4 + 0xC) = 0;
            m_unkF = 0;
            return;
        }
        m_unkF = 1;
        SetNumber();
        ((PMNode *)m_unk4)->SetAllFrustrumTest((eBoxIntersect)1);
        ((PVirtObj *)m_unk4)->Slot05((int)&CoinAnim);
    }
}

// DRAFT: 0x142900 SwapCheck__12HudInventoryFUi
// note: 69 words differ. Separate early returns where the original shares one return-0 exit; hud + 0x5B is reassociated; gp reload order. Tried: base in two steps, single result variable (84), hudRow temp (69).
int HudInventory::SwapCheck(unsigned int arg0) {
    if (!(arg0 & 0x4000)) {
        return 0;
    }
    int idx = m_unk40;
    if (idx >= 0x18) {
        return 0;
    }
    int group = 2;
    if (idx < 0xC) {
        group = 0;
    }
    int slot = idx % 12;
    if (slot >= 7) {
        group++;
        slot -= 7;
    }
    char *hud = (char *)mpPlayerData__7GameHud;
    char *base = hud + 0x5B + (group << 3);
    char *cell = base + slot;
    int icon = *cell;
    if (slot == 0) {
        if (group != 2 && group != 0) {
            return 0;
        }
        if (*(int *)(hud + 0x2C) == icon) {
            return 0;
        }
    }
    if (icon < 0) {
        return 0;
    }
    if (AbilityTable[(icon << 4) + 6] != -2) {
        return 0;
    }
    *cell = *base;
    *base = icon;
    UpdateGroup(group);
    ((Player *)*(char **)(gEng + 0x1883C))->SwapAbility(icon);
    m_unk40 = *(int *)(IconTable + 0x1008 + (group << 5));
    return 1;
}

// FUNCTION: 0x142FF0 UpdateStatus__12HudInventoryFb
void HudInventory::UpdateStatus(bool flag) {
    float rate;
    if (flag) {
        m_unkF = 3;
        rate = -0.5f;
        m_unk10 = 1;
        m_unk3C = -1;
        gPad.PauseVibrate(false);
        gSound.AbilityScreenLeave();
    } else {
        m_unkF = 1;
        gSound.AbilityScreenEnter();
        *(int *)((char *)m_unk4 + 0xC) = 1;
        rate = 0.5f;
        m_unk3C = 0;
    }
    ((PMNode *)m_unk4)->RecurseSetLoopRateByID(-1U, 1, rate);
    gSound.PlaySoundUbiquitous(0x3A);
}

// DRAFT: 0x1430D0 UpdateShieldIcon__12HudInventoryFv
// note: 64 words differ, size 0x110 vs 0x128. Original keeps elem in v1 and the PArray in a0; the m44 switch lays out 0x6A last; tail loop uses positive-branch sb body. Tried: if/else-if node (73), ternary node (73), switch m44 (73), if-chain m44 (67), reordered tail compares (73), explicit PArray pointer (65), ternary store (64), restored compare order (64).
void HudInventory::UpdateShieldIcon() {
    char *elem = (char *)m_unk1C;
    *(int *)(elem + 0x18) = 0;
    char *pa = elem + 0x14;
    char *node = 0;
    if (*(unsigned int *)pa != 0) {
        node = ((char **)*(char ***)(pa + 8))[0];
    }
    int m44 = *(int *)((char *)mpPlayerData__7GameHud + 0x44);
    int sel;
    int val;
    switch (m44) {
    case 0x6A:
        sel = 2;
        val = 0x13;
        break;
    case 0x9F:
        sel = 1;
        val = 0x12;
        break;
    default:
        sel = 0;
        val = 4;
        break;
    }
    for (int i = 0; i < 3; i++) {
        char *e = 0;
        if ((unsigned int)i < *(unsigned int *)(node + 0x14)) {
            e = ((char **)*(char ***)(node + 0x1C))[i];
        }
        if (e) {
            *(int *)(e + 0xC) = (i == sel) ? 1 : 0;
        }
    }
    char *p = (char *)mpPlayerData__7GameHud + 0x63;
    for (int k = 0; k < 3; k++, p++) {
        signed char v = *p;
        if (v == 4 || v == 0x12 || v == 0x13) {
            *p = (signed char)val;
        }
    }
}

// DRAFT: 0x00143200 AddIcon__12HudInventoryFi
// note: 68 words differ. Early branch at 0x20 targets 0x50 (orig 0x3B) so the copy loop is unrolled by eight in ours and the exit lands later. Tried: IconTable offset folded into index, i=0 before w=1, w declared before i, copy loop as base[i] (no change).
void HudInventory::AddIcon(int arg0) {
    signed char sp18[8];
    signed char *entry;
    signed char *base;
    int iconType;
    int count;
    int w;
    int i;
    signed char slot;
    signed char c;
    signed char *dst;

    entry = AbilityTable + arg0 * 16;
    iconType = entry[5];
    if ((unsigned int)iconType < 4) {
        slot = entry[6];
        if (slot != -1) {
            count = *(int *)(IconTable + (iconType << 5));
            if (slot == -2) {
                sp18[0] = arg0;
                i = 0;
                w = 1;
                base = (signed char *)mpPlayerData__7GameHud + 0x5B + iconType * 8;
                for (; i < count; i++) {
                    c = base[i];
                    if (c != arg0) {
                        sp18[w] = c;
                        w++;
                    }
                }
                dst = base;
                for (i = 0; i < count; i++) {
                    *dst = sp18[i];
                    dst++;
                }
            } else {
                base = (signed char *)mpPlayerData__7GameHud + 0x5B + iconType * 8;
                base[count + slot] = arg0;
            }
            UpdateGroup(iconType);
        }
    }
}

// DRAFT: 0x143510 Reset__12HudInventoryFv
// note: 8 words differ; size 0x88 vs 0x8c. The original has an extra nop before the loop bnez, and the call-site reloc set is otherwise equal. Tried: pointer local for this+4 (CSE into s0), member m_unk4, for-loop form (16 words), UpdateGroup(i++) (12 words).
void HudInventory::Reset() {
    if (m_unk4 != 0) {
        ((PVirtObj *)m_unk4)->Slot05((int)&DefaultLoopAnim);
        *(int *)((char *)m_unk4 + 0xC) = 0;
        *(signed char *)((char *)this + 0xF) = 0;
    }
    *(signed char *)((char *)this + 0x10) = 1;
    *(int *)((char *)this + 0x3C) = -1;
    *(int *)((char *)this + 0x40) = 0;
    int i = 0;
    do {
        UpdateGroup(i);
        i += 1;
    } while (i < 4);
}

// FUNCTION: 0x143770 __ct__12HudInventoryFv
HudInventory::HudInventory() {
    *(void **)this = __vt__7GameHud;
    *(int *)((char *)this + 0x4) = 0;
    *(void **)this = __vt__12HudInventory;
    *(int *)((char *)this + 0x4) = 0;
    *(signed char *)((char *)this + 0x10) = 1;
    *(int *)((char *)this + 0x14) = 0;
    *(int *)((char *)this + 0x18) = 0;
    *(int *)((char *)this + 0x1C) = 0;
    *(int *)((char *)this + 0x20) = 0;
    *(int *)((char *)this + 0x24) = 0;
    *(int *)((char *)this + 0x28) = 0;
    *(int *)((char *)this + 0x2C) = 0;
    *(int *)((char *)this + 0x30) = 0;
    *(int *)((char *)this + 0x3C) = -1;
}

// FUNCTION: 0x1437D0 __dt__7GameHudFv
GameHud::~GameHud() {
    m_unk0 = __vt__7GameHud;
    ((PVirtObj *)this)->Slot01();
}

// DRAFT: 0x143D40 WriteHint__7HudHintFv
// note: 20 differing lines; index load goes to v1 where original uses a1 (addiu v1,s1,0x38 precedes the index scale). Tried: local idx, base pointer m_unk38, pointer arithmetic, pointer-offset form; codegen identical in all four.
void HudHint::WriteHint() {
    FontManager *fm = (FontManager *)((char *)&gInterface + 0x80);
    fm->RemoveText((unsigned short)0x14);
    fm->DisplayString(HintTable[m_unk38[m_unkC]] + 1, 0, 10, false);
}

// FUNCTION: 0x144180 Init__7HudHintFUi
void HudHint::Init(unsigned int arg0) {
    m_unk0 = 0;
    m_unk8 = arg0;
    gInterface.FadeScreen(255.0f, 17.0f, true, (Interface::eFadeColor)0);
    m_unk4 = gInterface.m_unk1C0;
    gInterface.m_unk1C0 = m_unk4 | 0x10;
}

// FUNCTION: 0x1441F0 InitNode__7HudHintFP9PMeshNode
void HudHint::InitNode(PMeshNode *node) {
    m_unkB4 = ((PMNode *)node)->Find(0xFBD2D937U);
    if (m_unkB4 == 0) {
        CdsAssert__FPciPc("Interface.cpp", 0x3A0, "mpBG");
    }
    m_unkB4->m_unkC = 0;
    float *pBox = (float *)(BoxSize + *(signed char *)((char *)&gInterface + 0x93) * 0xC);
    PMNode *pNode = ((PMNode *)node)->Find(0x4FEFC567U);
    if (pNode != 0) {
        pNode->ScaleSet(pBox[1], 1.0f, 1.0f, 1.0f);
        pNode->m_unk80 += pBox[2];
    }
}

// FUNCTION: 0x001442C0 ResetGameHud__9InterfaceFv
class HudResetElement {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Reset();       // virtual slot 4, vtable offset 0x18
};

void Interface::ResetGameHud() {
    m_unk1C0 |= 2;
    ((HudResetElement *)((char *)this + 0x1CC))->Reset();
    ((HudResetElement *)((char *)this + 0x1DC))->Reset();
    ((HudResetElement *)((char *)this + 0x1EC))->Reset();
    ((HudResetElement *)((char *)this + 0x1FC))->Reset();
    ((HudResetElement *)((char *)this + 0x20C))->Reset();
    ((HudResetElement *)((char *)this + 0x21C))->Reset();
    ((HudResetElement *)((char *)this + 0x22C))->Reset();
    ((HudResetElement *)((char *)this + 0x250))->Reset();
    ((HudResetElement *)((char *)this + 0x270))->Reset();
    ((HudResetElement *)((char *)this + 0x290))->Reset();
    ((HudResetElement *)((char *)this + 0x2E8))->Reset();
}

// FUNCTION: 0x144690 Init__7GameHudFP9PMeshNodeP7HudData
void GameHud::Init(PMeshNode *meshNode, HudData *hud) {
    m_unk4 = ((PMNode *)meshNode)->Find(hud->m_unk0);
    m_unkF = hud->m_unk5;
    m_unkE = hud->m_unk4;
}

// FUNCTION: 0x144930 LoadingDisplayGuts__9InterfaceFUi
void Interface::LoadingDisplayGuts(unsigned int arg0) {
    static int st_uCount;
    static signed char init;
    if (init == 0) {
        st_uCount = 0;
        init = 1;
    }
    DebugClear__5DebugFv(gDebug);
    st_uCount += 1;
    if (arg0 == 0) {
        st_uCount = 0;
    }
    if (st_uCount & 0x10) {
        DebugDispPos__5DebugFPcUiUii(gDebug, "LOADING...", 10, 20, 7);
    }
    RefreshDisplay__10PGfxEngineFv(gGfxEng);
}

// FUNCTION: 0x144B90 LoadingDisplayOld__9InterfaceFUii
void Interface::LoadingDisplayOld(unsigned int arg0, int arg1) {
    int a;
    int b;
    if (m_unk427 != 0) {
        int msg = 0x28F;
        switch (arg1) {
        case 2:
            msg = 0x28E;
            break;
        case 3:
            msg = 0x28B;
            break;
        case 1:
        case 4:
            msg = 0x290;
            break;
        case 6:
            msg = 0x292;
            break;
        }
        ((FontManager *)((char *)this + 0x80))->RenderWarning(msg);
    }
    SoundOneFrameHasElapsed_R__9MaxEngineFRiRi(gEng, &a, &b);
    if (m_unk427 != 0) {
        RefreshDisplay__10PGfxEngineFv(gGfxEng);
    }
    IncrementSecondarySyncCounts__9MaxEngineFv(gEng);
}

// FUNCTION: 0x144C60 LoadingDisplay__9InterfaceFUii
void Interface::LoadingDisplay(unsigned int arg0, int arg1) {
    if (fst_bUseOldLoadingDisplay != 0) {
        LoadingDisplayOld(arg0, arg1);
        return;
    }
    LoadingDisplayNew(arg0);
}

// FUNCTION: 0x144CA0 AddMeshLayer__9InterfaceFP6PMNode
void Interface::AddMeshLayer(PMNode *node) {
    if ((unsigned int)m_unk404 >= 8) {
        CdsAssert__FPciPc("Interface.cpp", 0x1ED, "mMeshLayerList.GetCount() < MAX_MESHLAYER");
    }
    ((PArray *)&m_unk404)->Add(node);
    m_unk1C0 |= 8;
}

// FUNCTION: 0x144D10 DeleteMeshLayer__9InterfaceFP6PMNode
void Interface::DeleteMeshLayer(PMNode *node) {
    if (node != 0) {
        node->Slot00(1);
    }
    ((PArray *)((char *)this + 0x404))->Remove(node);
}

// DRAFT: 0x144D60 DeleteMeshLayer__9InterfaceFv
// note: 25 differing words; frame (0x20) and s0-only saves match; original has a nop after the Slot00 jalr and reloads m_unk408 for the list index (ours keeps idx in a1), so the loop skip is 0x17 vs ours 0x15. Tried NULL->0, if/else on first list read, m_unk408 header field (37 -> 31 -> 25), if/else in loop tail (27), m_unk408 index in tail (27); last two reverted.
void Interface::DeleteMeshLayer() {
    PMNode *node;
    unsigned int idx;
    m_unk408 = 0;
    if (m_unk404 != 0) {
        node = (PMNode *)(*(void ***)((char *)this + 0x40C))[0];
    } else {
        node = 0;
    }
    if (node != 0) {
        do {
            if (node != 0) {
                node->Slot00(1);
            }
            idx = m_unk408 + 1;
            m_unk408 = idx;
            node = 0;
            if (idx < (unsigned int)m_unk404) {
                node = (PMNode *)(*(void ***)((char *)this + 0x40C))[idx];
            }
        } while (node != 0);
    }
    if (*(void ***)((char *)this + 0x40C) != 0) {
        m_unk404 = 0;
        m_unk408 = 0;
    }
}

// DRAFT: 0x00144E20 Destroy__9InterfaceFv
// note: 60 words differ, original frame 0x30 keeps this in s1 with field slots in s0 (addiu s0,s1,0x1C4/0x1C8); ours keeps this in s0 and folds the offsets; tried slot pointers, hoisted slot, declaration reorder, self local (6 attempts)
void Interface::Destroy() {
    Interface *self;
    PMNode **slot;
    PMNode *node;
    void **obj;
    void ***objSlot;
    self = this;
    slot = (PMNode **)((char *)self + 0x1C4);
    node = *(PMNode **)((char *)self + 0x1C4);
    if (node != 0) {
        node->ProcessFxTriggers(-1.0f, 0, true, false);
        node = *slot;
        if (node != 0) {
            node->Slot00(1);
        }
        *slot = 0;
        ((PVirtObj *)((char *)this + 0x22C))->Slot01();
        ((PVirtObj *)((char *)this + 0x290))->Slot01();
        ((PTextureManager *)((char *)gGfxEng + 0x154C90))->UnloadDynamicTextures((eTextureGroup)0x6A);
    }
    objSlot = (void ***)((char *)self + 0x1C8);
    obj = *(void ***)((char *)self + 0x1C8);
    if (obj != 0) {
        if (obj != 0) {
            ((PMNode *)obj)->Slot00(1);
        }
        *objSlot = 0;
    }
    *(signed char *)((char *)this + 0x2F8) = 1;
    *(signed char *)((char *)this + 0x3E4) = 0;
    m_unk1C0 = 1;
    DeleteMeshLayer();
    ((FontManager *)((char *)this + 0x80))->RemoveAll(true);
    *(short *)((char *)this + 0x414) = 0;
    *(short *)((char *)this + 0x416) = 0;
}

// DRAFT: 0x001450D0 ProcessScreenFade__9InterfaceFv
// note: 2 words differ, mul.s operand order and c.eq.s operand order; tried swapped mul operands, read-modify-write form, local temp (4), and both branch forms
void Interface::ProcessScreenFade() {
    if (*(unsigned char *)&m_unk425 != 0) {
        *(float *)&m_unk41C += *(float *)(gEng + 0x1E8) * *(float *)&m_unk418;
        if (((*(float *)&m_unk418 < 0.0f) && (*(float *)&m_unk41C <= *(float *)&m_unk420)) ||
            (!(*(float *)&m_unk418 <= 0.0f) && !(*(float *)&m_unk41C < *(float *)&m_unk420))) {
            *(float *)&m_unk41C = *(float *)&m_unk420;
            m_unk425 = 0;
        }
        DisplayFadeRectangle();
        return;
    }
    if (*(float *)&m_unk41C != 0.0f) {
        DisplayFadeRectangle();
    }
}

// DRAFT: 0x001451B0 DisplayFadeRectangle__9InterfaceFv
// note: 42 words; gs store order and branch shape differ, gGfxEng+0x154C80 load scheduled earlier; size 0xf8 vs 0xe8. Tried gs initializer (56), (int) alpha cast (54), per-use table index (54).
void Interface::DisplayFadeRectangle() {
    static char vFadeRGB[2][3] = {{0, 0, 0}, {-128, -128, -128}};
    unsigned long long gs[6];
    gs[2] = 0;
    gs[3] = 0x1A;
    gs[4] = 0x48;
    gs[5] = 0x1B;
    if (m_unk426 != 0) {
        gs[0] = 0x48;
        gs[1] = 0x42;
    } else {
        gs[0] = 0x44;
        gs[1] = 0x42;
    }
    PDisplayList *pd = *(PDisplayList **)(gGfxEng + 0x154C80);
    pd->SetGsRegisters((u_long128 *)gs, 3);
    pd = *(PDisplayList **)(gGfxEng + 0x154C80);
    char *rgb = vFadeRGB[m_unk426];
    pd->ClearFrameBuffer(0x800, 0x800, 0x800, 0x800, rgb[0], rgb[1],
                         rgb[2], (char)(int)*(float *)&m_unk41C, 0x3F800000);
}

// DRAFT: 0x1452A0 FadeScreen__9InterfaceFffbQ29Interface10eFadeColor
// note: 1 differing line, c.eq.s operand order (orig $f20,$f0 vs ours $f0,$f20); tried 0.0f!=v, arg1!=0, inverted ==0 layout (18 diffs), !(v==0).
void Interface::FadeScreen(float arg0, float arg1, bool arg2, eFadeColor arg3) {
    float var_f20 = arg1;
    if ((int)arg3 >= 2) {
        CdsAssert__FPciPc("Interface.cpp", 0x14E, "eColor < FADE_COLOR_MAX");
    }
    m_unk426 = (signed char)arg3;
    m_unk424 = arg2;
    if (!(var_f20 == 0.0f)) {
        m_unk425 = 1;
        *(float *)&m_unk420 = arg0;
        if (arg0 < *(float *)&m_unk41C) {
            var_f20 = -var_f20;
        }
        *(float *)&m_unk418 = var_f20;
        return;
    }
    m_unk425 = 0;
    *(float *)&m_unk41C = arg0;
    DisplayFadeRectangle();
    *(float *)&m_unk418 = arg0;
}

// FUNCTION: 0x145370 InitScreenFadeVars__9InterfaceFv
void Interface::InitScreenFadeVars() {
    m_unk425 = 0;
    m_unk418 = 0;
    m_unk41C = 0x43000000;
    m_unk420 = 0x43000000;
    m_unk426 = 0;
    m_unk424 = 1;
}

// DRAFT: 0x1453A0 IsTreasureOK__9InterfaceFv
// note: 11 words differ; original shares one false exit and keeps the 0x80 test as bnez, compiler emits beqz/sltu/xori. Tried bool, int, result-var, nested-guard and inverted-test layouts.
int Interface::IsTreasureOK() {
    if (m_unk2F7 != 0) {
        return 0;
    }
    if (m_unk1B8 != 0) {
        return 1;
    }
    if (m_unk80 == 0) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x1453E0 DisplayLevelName__9InterfaceFii
void Interface::DisplayLevelName(int arg0, int arg1) {
    if (m_unk1B8 != 0) {
        ((FontManager *)((char *)this + 0x80))->RemoveText((FontNode *)m_unk1B8);
        m_unk1B8 = 0;
    }
    if (arg0 >= 0) {
        m_unk1B8 = ((FontManager *)((char *)this + 0x80))->DisplayString(arg0 + 0x270, arg1, 0, false);
        m_unk1BC = arg1;
    }
}

// FUNCTION: 0x145820 InitRender__9InterfaceFv
void Interface::InitRender() {
    float v[4];
    sceVu0CopyVector(v, (float *)((char *)this + 0x70));
    sceVu0ScaleVectorXYZ(v, v, -1.0f);
    RenderBlendedFragments__10PGfxEngineFPf(gGfxEng, v);
    vu1ZBufferUpdate__Fb(true);
    vu1ClearZBuffer__Fv();
    vu1SetScreenMatrix__FP5PMat4(this);
    vu1SetViewMatrix__FP5PMat4((char *)this + 0x40);
    vu1SetClipMatrix__FP5PMat4(gEng + 0x50);
    gGfxEng[0x158E22] = 0;
}

// FUNCTION: 0x1458B0 InitMatrices__9InterfaceFv
void Interface::InitMatrices() {
    if (MODE_PAL != 0) {
        float h = (float)SCREEN_HEIGHT;
        float f2 = 9.75f * (h / 224.0f);
        float w = (float)SCREEN_WIDTH;
        MakeParallelProjectionMatrix__5PMat4Fffffffffffff(this, 2048.0f, 2048.0f, w, h, 100.0f, 16777215.0f, (float)-SCREEN_WIDTH / 19.5f, w / 19.5f, h / f2, -h / f2, -100.0f, 100.0f);
    } else {
        *(int *)((char *)this + 0x00) = 0x411C0000;
        *(int *)((char *)this + 0x14) = 0x409C0000;
        *(int *)((char *)this + 0x28) = 0xC7A3D6C9;
        *(int *)((char *)this + 0x30) = 0x45000000;
        *(int *)((char *)this + 0x34) = 0x45000000;
        *(int *)((char *)this + 0x38) = 0x4B000031;
    }
    *(int *)((char *)this + 0x54) = 0xBF733333;
    *(int *)((char *)this + 0x68) = 0xBF800000;
    *(int *)((char *)this + 0x78) = 0x4210CCCD;
}

// FUNCTION: 0x1459D0 Init__9InterfaceFv
void Interface::Init() {
    ((FontManager *)((char *)this + 0x80))->Init();
    ((PArray *)((char *)this + 0x404))->Allocate(8);
    InitMatrices();
}

// FUNCTION: 0x145E40 __dt__12HudInventoryFv
extern "C" HudInventory *__dt__12HudInventoryFv(HudInventory *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__12HudInventory;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x145EC0 __dt__8HudComboFv
extern "C" HudCombo *__dt__8HudComboFv(HudCombo *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__8HudCombo;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x145F40 __dt__12HudBossMeterFv
extern "C" HudBossMeter *__dt__12HudBossMeterFv(HudBossMeter *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__12HudBossMeter;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x145FC0 __dt__8HudSuperFv
extern "C" HudSuper *__dt__8HudSuperFv(HudSuper *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__8HudSuper;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x146040 __dt__9HudHealthFv
extern "C" HudHealth *__dt__9HudHealthFv(HudHealth *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__9HudHealth;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
