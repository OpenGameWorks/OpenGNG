#ifndef INTERFACE_H
#define INTERFACE_H

class PParticleSystem;

class HudGrim {
public:
    void Delete();

    char _pad000[0x20];
    PParticleSystem *m_unk20;   // 0x020
};

class HudCombo {
public:
    void ComboFinish();

    char _pad000[0x38];
    void *m_unk38;              // 0x038
    char _pad03C[0xC];
    void *m_unk48;              // 0x048
};

class Interface {
public:
    void SoundGainEEControl();
    void WaitForEEControl();
    void LoadingDisplay(unsigned int arg0, int arg1);
    void LoadingDisplayOld(unsigned int arg0, int arg1);
    void LoadingDisplayNew(unsigned int arg0);
    void InitScreenFadeVars();

    char _pad000[0x418];
    int m_unk418;               // 0x418
    int m_unk41C;               // 0x41C
    int m_unk420;               // 0x420
    signed char m_unk424;       // 0x424
    signed char m_unk425;       // 0x425
    signed char m_unk426;       // 0x426
};

#endif
