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
};

class PMNode {
public:
    virtual void Slot00(int flag);
    PMNode *Find(unsigned int id);
};

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
};

extern unsigned char __vt__7GameHud[];
extern unsigned char __vt__12HudInventory[];

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
    int DisplayString(int arg0, int arg1, int arg2, bool arg3);
};

// MemMgr is 908 bytes; the field at offset 0x18 is saved and cleared around AddIcon.
extern char MemMgr[908];

extern "C" void FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(void *, float, float, bool, int);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern Interface gInterface;

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

// FUNCTION: 0x1459D0 Init__9InterfaceFv
void Interface::Init() {
    ((FontManager *)((char *)this + 0x80))->Init();
    ((PArray *)((char *)this + 0x404))->Allocate(8);
    InitMatrices();
}
