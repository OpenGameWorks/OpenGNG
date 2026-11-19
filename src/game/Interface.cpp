#include "types.h"
#include "Interface.h"

// TODO(header): foreign declarations
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    void StopStreamsAndRequestEEControl();
    int GetEEControlStatus();
    void SetAllowCallOneFrameHasElapsed(bool flag);
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

extern unsigned char fst_bUseOldLoadingDisplay;

// Polymorphic embedded object; Slot04 is the vtable word at offset 0x18
// (the compiler places the first virtual slot at offset 0x8).
class PVirtObj {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05(int flag);
};

// Only the mangled name (13eBoxIntersect) matters here; the enumerator names are placeholders.
enum eBoxIntersect { eBoxIntersect_Value0 = 0, eBoxIntersect_Value1 = 1 };

class PMNode {
public:
    virtual void Slot00(int flag);
    PMNode *Find(unsigned int id);
    void RecurseSetSTAnimOptions(bool flag);
    void SetAllFrustrumTest(eBoxIntersect arg0);
};

// Placeholder size; the original object is larger than the 8-byte small-data threshold.
extern char CoinAnim[0x10];
extern char DefaultLoopAnim[0x10];

// Placeholder size; gDebug is reached via lui/addiu, so its type must exceed the 8-byte small-data threshold.
extern char gDebug[0x10];
extern "C" void DebugClear__5DebugFv(void *pThis);
extern "C" void DebugDispPos__5DebugFPcUiUii(void *pThis, char *text, unsigned int x, unsigned int y, int color);
extern "C" void RefreshDisplay__10PGfxEngineFv(void *pThis);

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

    char _pad000[0x4];
    void *m_unk4;               // 0x004
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
};

// MemMgr is 908 bytes; the field at offset 0x18 is saved and cleared around AddIcon.
extern char MemMgr[908];

extern "C" void FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(void *, float, float, bool, int);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern Interface gInterface;
// HintTable is 120 bytes (symbols.tsv); element size taken from the lw/sll 2 indexing.
extern int HintTable[30];
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

// DRAFT: 0x13F8C0 WaitForEEControl__9InterfaceFv
// note: 6 words off; original leaves a nop in the delay slot of the exit `b`, ours fills it with the epilogue ld ra. Tried break/return/for-increment forms, same count.
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

// TODO(header): mpPlayerData__7GameHud is a pointer-sized small-data global.
extern GameHud *mpPlayerData__7GameHud;

// DRAFT: 0x13FEE0 UpdateCover__7HudGrimFv
// note: 2 words differ; the original runs the i<3 compare before the off+=4 update, the compiler emits off+=4 first. Tried local orders, off=i<<2, explicit condition variable.
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

// FUNCTION: 0x141270 AddAbility__9InterfaceFi
void Interface::AddAbility(int arg0) {
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    ((HudInventory *)((char *)this + 0x2E8))->AddIcon(arg0);
    *(int *)(MemMgr + 0x18) = saved;
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

// DRAFT: 0x141630 SetFace__12HudBossMeterFv
// note: byte-offset do-while matches body; differs at FaceID lui/addiu (reloc) and missing join nop at 0x54. Tried: index loop, pointer walk, for loop, precomputed value, empty else, if-form value.
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
    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(&gInterface, 255.0f, 17.0f, true, 0);
    m_unk4 = gInterface.m_unk1C0;
    gInterface.m_unk1C0 = m_unk4 | 0x10;
}

// FUNCTION: 0x144690 Init__7GameHudFP9PMeshNodeP7HudData
void GameHud::Init(PMeshNode *meshNode, HudData *hud) {
    m_unk4 = ((PMNode *)meshNode)->Find(hud->m_unk0);
    m_unkF = hud->m_unk5;
    m_unkE = hud->m_unk4;
}

// DRAFT: 0x144930 LoadingDisplayGuts__9InterfaceFUi
// note: 7 words differ; only the local-static reloc names differ (ours init$182/st_uCount$181, original init$722/st_uCount$721; the MW $N counter is per-TU). Tried: file-scope statics (names cannot carry '$').
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
