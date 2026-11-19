#include "types.h"
#include "Interface.h"

// TODO(header): foreign declarations
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    void StopStreamsAndRequestEEControl();
    char _pad000[0x10];
};
extern PSound gSound;

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
    void AddIcon(int id);
};

class PArray {
public:
    void Allocate(unsigned int count);
};

class FontManager {
public:
    void Init();
};

// MemMgr is 908 bytes; the field at offset 0x18 is saved and cleared around AddIcon.
extern char MemMgr[908];

// FUNCTION: 0x13F880 SoundGainEEControl__9InterfaceFv
void Interface::SoundGainEEControl() {
    gSound.StopStreamsAndRequestEEControl();
    WaitForEEControl();
}

// FUNCTION: 0x13F9D0 LevelClear__9InterfaceFv
void Interface::LevelClear() {
    ((PVirtObj *)((char *)this + 0x290))->Slot04();
    ((PVirtObj *)((char *)this + 0x250))->Slot04();
    m_unk1C0 &= ~8;
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

// FUNCTION: 0x1459D0 Init__9InterfaceFv
void Interface::Init() {
    ((FontManager *)((char *)this + 0x80))->Init();
    ((PArray *)((char *)this + 0x404))->Allocate(8);
    InitMatrices();
}
