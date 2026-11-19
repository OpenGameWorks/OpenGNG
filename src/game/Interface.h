#ifndef INTERFACE_H
#define INTERFACE_H

class PParticleSystem;
class PMeshNode;
class PMNode;
class HudData;

class HudGrim {
public:
    void UpdateCover();
    void Init(PMeshNode *meshNode, HudData *hud);
    void Delete();

    char _pad000[0x4];
    PMNode *m_unk4;             // 0x004
    char _pad008[0x8];
    void *m_unk10;              // 0x010 PMNode::Find(0x303B74C6) result
    void *m_unk14[3];           // 0x014 cover element pointers
    PParticleSystem *m_unk20;   // 0x020
};

class HudSuper {
public:
    void Update(int arg0);
    void UpdateBar(int arg0);

    char _pad000[0xC];
    short m_unkC;               // 0x00C current super value, stepped toward the player's target
};

class HudBossMeter {
public:
    void Reset();
    void SetValue(short value);
    void SetFace();

    char _pad000[0x4];
    void *m_unk4;               // 0x004 pointer to a HUD element (fields at 0x0C, 0x2C, 0x84)
    float m_unk8;               // 0x008
    short m_unkC;               // 0x00C
    char _pad00E[0x1];
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

    char _pad000[0x38];
    void *m_unk38;              // 0x038
    char _pad03C[0xC];
    void *m_unk48;              // 0x048
};

class HudHint {
public:
    void Init(unsigned int arg0);
    void WriteHint();

    int m_unk0;                 // 0x000
    int m_unk4;                 // 0x004
    unsigned int m_unk8;        // 0x008
    int m_unkC;                 // 0x00C index into m_unk38
    char _pad010[0x28];
    int m_unk38[1];             // 0x038 indexed by m_unkC, values index HintTable
};

class GameHud {
public:
    ~GameHud();
    void Init(PMeshNode *meshNode, HudData *hud);
    void Reset();
    void SetNumber();

    void *m_unk0;               // 0x000 vtable pointer (__vt__7GameHud)
    void *m_unk4;               // 0x004
    char _pad008[0x4];
    short m_unkC;               // 0x00C
    unsigned char m_unkE;       // 0x00E
    unsigned char m_unkF;       // 0x00F
};

class Interface {
public:
    void SoundGainEEControl();
    void WaitForEEControl();
    void LoadingDisplay(unsigned int arg0, int arg1);
    void LoadingDisplayOld(unsigned int arg0, int arg1);
    void LoadingDisplayNew(unsigned int arg0);
    void LoadingDisplayGuts(unsigned int arg0);
    void InitScreenFadeVars();
    void LevelClear();
    void AddAbility(int arg0);
    int IsTreasureOK();
    void DisplayLevelName(int arg0, int arg1);
    void Init();
    void InitMatrices();
    void SetPause();
    void InitRender();
    void DeleteMeshLayer(PMNode *node);
    void AddMeshLayer(PMNode *node);
    void DeleteMeshLayer();
    void DisplayFadeRectangle();
    int AbilityScreen();
    // Enumerator names are placeholders; only the type identity (Q29Interface10eFadeColor) matters.
    enum eFadeColor { eFadeColor_Value0 = 0, eFadeColor_Value1 = 1, eFadeColor_Value2 = 2 };
    void FadeScreen(float arg0, float arg1, bool arg2, eFadeColor arg3);

    char _pad000[0x80];
    int m_unk80;                // 0x080 first word of the embedded FontManager
    char _pad084[0x134];
    int m_unk1B8;               // 0x1B8
    int m_unk1BC;               // 0x1BC
    int m_unk1C0;               // 0x1C0
    char _pad1C4[0x133];
    unsigned char m_unk2F7;     // 0x2F7
    char _pad2F8[0x2C];
    int m_unk324;               // 0x324 sign tested by AbilityScreen
    char _pad328[0xDC];
    int m_unk404;               // 0x404 mesh layer list count, then entries (PArray)
    unsigned int m_unk408;      // 0x408 loop index into the mesh layer list
    char _pad40C[0xC];
    int m_unk418;               // 0x418
    int m_unk41C;               // 0x41C
    int m_unk420;               // 0x420
    signed char m_unk424;       // 0x424
    signed char m_unk425;       // 0x425
    signed char m_unk426;       // 0x426
    unsigned char m_unk427;     // 0x427 nonzero enables the warning and display-refresh path
};

#endif
