#ifndef INTERFACE_H
#define INTERFACE_H

class PParticleSystem;
class PMeshNode;
class PMNode;
class HudData;

class HudGrim {
public:
    void Update(int arg0);
    void UpdateCover();
    void UpdateStatus(bool arg0);
    void Init(PMeshNode *meshNode, HudData *hud);
    void Reset();
    void Delete();

    char _pad000[0x4];
    PMNode *m_unk4;             // 0x004
    char _pad008[0x4];
    short m_unkC;               // 0x00C signed index, compared against the 10-entry particle ring
    unsigned char m_unkE;       // 0x00E player-data index (mpPlayerData array selector)
    unsigned char m_unkF;       // 0x00F set to 1 by UpdateStatus
    void *m_unk10;              // 0x010 PMNode::Find(0x303B74C6) result
    void *m_unk14[3];           // 0x014 cover element pointers
    PParticleSystem *m_unk20;   // 0x020
};

class HudSuper {
public:
    void Update(int arg0);
    void UpdateBar(int arg0);
    void UpdateMaxSuper();
    void Reset();

    char _pad000[0x4];
    void *m_unk4;               // 0x004 element list walked by UpdateBar
    char _pad008[0x4];
    short m_unkC;               // 0x00C current super value, stepped toward the player's target
};

class HudBossMeter {
public:
    void Reset();
    void SetValue(short value);
    void SetMaxValue(short arg0, int arg1);
    void SetFace();
    void Init(PMeshNode *meshNode, HudData *hud);
    void Update(int arg0);

    char _pad000[0x4];
    void *m_unk4;               // 0x004 pointer to a HUD element (fields at 0x0C, 0x2C, 0x84)
    float m_unk8;               // 0x008
    short m_unkC;               // 0x00C
    signed char m_unkE;         // 0x00E
    signed char m_unkF;         // 0x00F
    int m_unk10;                // 0x010
    short m_unk14;              // 0x014
    signed char m_unk16;        // 0x016
    signed char m_unk17;        // 0x017
    void *m_unk18;              // 0x018 element with field at 0xA0
    void *m_unk1C;              // 0x01C element with field at 0xA0
};

class HudCombo {
public:
    void ComboFinish();
    void ComboNumber();
    void UpdateStatus(bool flag);
    void Update(int arg0);
    void InitCombo(PMeshNode *arg0, HudData *arg1, PMNode *arg2);

    char _pad000[0x4];
    PMNode *m_unk4;             // 0x004 node whose frustum test and frame rate are set
    int m_unk8;                 // 0x008 float bits, 0x40000000 is 2.0f
    short m_unkC;               // 0x00C HUD value looked up from the player table
    unsigned char m_unkE;       // 0x00E index into the player table
    unsigned char m_unkF;       // 0x00F state, 0..3
    PMNode *m_unk10[10];        // 0x010 ring of 10 nodes indexed by digit, built by ComboNumber
    void *m_unk38;              // 0x038
    void **m_unk3C;             // 0x03C
    void **m_unk40;             // 0x040
    void *m_unk44;             // 0x044 polymorphic element, slot 5 called by UpdateStatus
    void *m_unk48;              // 0x048
    void *m_unk4C;              // 0x04C polymorphic element, slot 5 called by UpdateStatus
    float m_unk50;              // 0x050 copied from the table entry at 0x80 by InitCombo
    float m_unk54;              // 0x054 copied from the table entry at 0x84 by InitCombo
};

class HudHint {
public:
    void Init(unsigned int arg0);
    void InitHint();
    void DisplayTitle(int arg0);
    void WriteHint();
    void InitNode(PMeshNode *node);
    void EnableBG(bool arg0);
    int HintScreen();

    int m_unk0;                 // 0x000
    int m_unk4;                 // 0x004
    unsigned int m_unk8;        // 0x008 bitmask of hint slots
    int m_unkC;                 // 0x00C index into m_unk38
    int m_unk10;                // 0x010
    int m_unk14;                // 0x014
    int m_unk18;                // 0x018
    int m_unk1C;                // 0x01C
    int m_unk20;                // 0x020
    int m_unk24;                // 0x024
    int m_unk28;                // 0x028
    int m_unk2C;                // 0x02C
    int m_unk30;                // 0x030
    int m_unk34;                // 0x034
    int m_unk38[0x1E];          // 0x038 indexed by m_unkC, values index HintTable
    int m_unkB0;                // 0x0B0 count of set bits written into m_unk38
    PMNode *m_unkB4;            // 0x0B4 node found by InitNode
};

class GameHud {
public:
    ~GameHud();
    void Init(PMeshNode *meshNode, HudData *hud);
    void Reset();
    void SetNumber();
    void UpdateStatus(bool arg0);
    void Update(int arg0);

    void *m_unk0;               // 0x000 vtable pointer (__vt__7GameHud)
    void *m_unk4;               // 0x004
    float m_unk8;               // 0x008 set to 2.0f or 80.0f by UpdateStatus
    short m_unkC;               // 0x00C
    unsigned char m_unkE;       // 0x00E
    unsigned char m_unkF;       // 0x00F
};

// Zero-cost member whose type declares a destructor; it makes the Interface constructor spill `this` to the stack.
class InterfaceSpillGuard {
public:
    ~InterfaceSpillGuard() {}
};

class Interface {
public:
    Interface();
    ~Interface();
    void SoundGainEEControl();
    void WaitForEEControl();
    void LoadingDisplay(unsigned int arg0, int arg1);
    void LoadingDisplayOld(unsigned int arg0, int arg1);
    void LoadingDisplayNew(unsigned int arg0);
    void LoadingDisplayGuts(unsigned int arg0);
    void InitScreenFadeVars();
    void LevelClear();
    void HudUpdate(int arg0);
    void AddAbility(int arg0);
    int IsTreasureOK();
    void DisplayLevelName(int arg0, int arg1);
    void Init();
    void InitHud();
    void Destroy();
    PMNode *Load(const char *arg0);
    void InitMatrices();
    void SetPause();
    void InitRender();
    void DeleteMeshLayer(PMNode *node);
    void AddMeshLayer(PMNode *node);
    void DeleteMeshLayer();
    void DisplayFadeRectangle();
    void Render(int arg0);
    int AbilityScreen();
    void ResetGameHud();
    void ProcessScreenFade();
    void UpdateStatus(unsigned int arg0, bool arg1);
    int StaticDemo(const char *, unsigned int, unsigned int, int, unsigned short);
    // Enumerator names are placeholders; only the type identity (Q29Interface10eFadeColor) matters.
    enum eFadeColor { eFadeColor_Value0 = 0, eFadeColor_Value1 = 1, eFadeColor_Value2 = 2 };
    void FadeScreen(float arg0, float arg1, bool arg2, eFadeColor arg3);

    InterfaceSpillGuard m_spill000;
    char _pad001[0x7F];
    int m_unk80;                // 0x080 first word of the embedded FontManager
    char _pad084[0x11C];
    unsigned char m_unk1A0;     // 0x1A0 flag read by HudBossMeter::Update and HudCombo::UpdateStatus
    char _pad1A1[0x17];
    int m_unk1B8;               // 0x1B8
    int m_unk1BC;               // 0x1BC
    int m_unk1C0;               // 0x1C0
    void *m_unk1C4;             // 0x1C4 pointer to a list object (PArray at 0x14) walked by HudHint::EnableBG
    void *m_unk1C8;             // 0x1C8 polymorphic element cleared by Load; deleted via virtual slot 8 (a1=1)
    void *m_unk1CC;             // 0x1CC embedded object; its vtable slot 4 (offset 0x18) is called with &m_unk1CC
    char _pad1D0[0xC];
    void *m_unk1DC;             // 0x1DC same element kind as 0x1CC
    char _pad1E0[0xC];
    void *m_unk1EC;             // 0x1EC same element kind as 0x1CC
    char _pad1F0[0xC];
    void *m_unk1FC;             // 0x1FC same element kind as 0x1CC
    char _pad200[0xC];
    void *m_unk20C;             // 0x20C same element kind as 0x1CC
    char _pad210[0xC];
    void *m_unk21C;             // 0x21C same element kind as 0x1CC
    char _pad220[0xC];
    void *m_unk22C;             // 0x22C same element kind as 0x1CC
    char _pad230[0x20];
    void *m_unk250;             // 0x250 same element kind as 0x1CC
    char _pad254[0x1C];
    void *m_unk270;             // 0x270 same element kind as 0x1CC
    char _pad274[0x1C];
    void *m_unk290;             // 0x290 same element kind as 0x1CC
    char _pad294[0x54];
    void *m_unk2E8;             // 0x2E8 same element kind as 0x1CC
    char _pad2EC[0xB];
    unsigned char m_unk2F7;     // 0x2F7
    char _pad2F8[0x2C];
    int m_unk324;               // 0x324 sign tested by AbilityScreen
    char _pad328[0xBC];
    char mName[0x20];           // 0x3E4 level name copied by Load
    int m_unk404;               // 0x404 mesh layer list count, then entries (PArray)
    unsigned int m_unk408;      // 0x408 loop index into the mesh layer list
    char _pad40C[0x8];
    short m_unk414;             // 0x414 cleared by Load
    short m_unk416;             // 0x416 cleared by Load
    int m_unk418;               // 0x418
    int m_unk41C;               // 0x41C
    int m_unk420;               // 0x420
    signed char m_unk424;       // 0x424
    unsigned char m_unk425;     // 0x425
    signed char m_unk426;       // 0x426
    unsigned char m_unk427;     // 0x427 nonzero enables the warning and display-refresh path
    void *m_unk428;             // 0x428 polymorphic element deleted by the destructor (virtual slot 8, a1=1)
};

#endif
