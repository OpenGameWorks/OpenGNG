#ifndef PFLASHSCREEN_H
#define PFLASHSCREEN_H

#include "types.h"

class PFlashScreen {
public:
    PFlashScreen();
    ~PFlashScreen();

    void Render();
    void Animate();
    void Init(float fR, float fG, float fB, float fA, unsigned int nFadeIn, unsigned int nHold, unsigned int nFadeOut, int nSound);

    int m_unk0;
    float m_unk4;
    float m_unk8;
    unsigned int m_unkC;
    int m_unk10;
    unsigned char m_unk14;
    char _pad15[0xB];
    float m_unk20;
    float m_unk24;
    float m_unk28;
    float m_unk2C;
    char m_unk30[0x10];
    long long m_unk40;
    char _pad48[8];
    long long m_unk50;
    char _pad58[0x18];
    long long m_unk70;
};

#endif
