#ifndef INTERFACE_H
#define INTERFACE_H

class PParticleSystem;
class PMeshNode;
class PMNode;
class HudData;

class HudGrim {
public:
    void UpdateCover();
    void Delete();

    char _pad000[0x14];
    void *m_unk14[3];           // 0x014 cover element pointers
    PParticleSystem *m_unk20;   // 0x020
};

class HudBossMeter {
public:
    void Reset();

    char _pad000[0x4];
    void *m_unk4;               // 0x004 pointer to a HUD element (fields at 0x0C, 0x2C, 0x84)
    float m_unk8;               // 0x008
    char _pad00C[0x3];
    signed char m_unkF;         // 0x00F
    int m_unk10;                // 0x010
    short m_unk14;              // 0x014
    char _pad016[0x1];
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

class GameHud {
public:
    ~GameHud();
    void Init(PMeshNode *meshNode, HudData *hud);

    void *m_unk0;               // 0x000 vtable pointer (__vt__7GameHud)
    void *m_unk4;               // 0x004
    char _pad008[0x6];
    signed char m_unkE;         // 0x00E
    unsigned char m_unkF;       // 0x00F
};

class Interface {
public:
    void SoundGainEEControl();
    void WaitForEEControl();
    void LoadingDisplay(unsigned int arg0, int arg1);
    void LoadingDisplayOld(unsigned int arg0, int arg1);
    void LoadingDisplayNew(unsigned int arg0);
    void InitScreenFadeVars();
    void LevelClear();
    void AddAbility(int arg0);
    int IsTreasureOK();
    void Init();
    void InitMatrices();
    void DeleteMeshLayer(PMNode *node);

    char _pad000[0x80];
    int m_unk80;                // 0x080 first word of the embedded FontManager
    char _pad084[0x134];
    int m_unk1B8;               // 0x1B8
    char _pad1BC[0x4];
    int m_unk1C0;               // 0x1C0
    char _pad1C4[0x133];
    unsigned char m_unk2F7;     // 0x2F7
    char _pad2F8[0x120];
    int m_unk418;               // 0x418
    int m_unk41C;               // 0x41C
    int m_unk420;               // 0x420
    signed char m_unk424;       // 0x424
    signed char m_unk425;       // 0x425
    signed char m_unk426;       // 0x426
};

#endif
