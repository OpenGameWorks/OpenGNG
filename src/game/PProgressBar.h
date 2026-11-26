#ifndef PPROGRESSBAR_H
#define PPROGRESSBAR_H

#include "types.h"

// Progress bar: four 4-float vertex rows at 0x00, 0x20, 0x80..0xBC and four
// RGBA colour rows at 0xC0..0xFF. The ctor clears 0x000..0x1FF.
class PProgressBar {
public:
    PProgressBar();
    ~PProgressBar();
    int Init(float fX, float fY, float fW, float fH, int nArg4);
    void SetRange(float fRange);
    void SetReading(float fReading);
    void SetBgColor(float fR, float fG, float fB, float fA);
    void SetColor1(float fR, float fG, float fB, float fA);
    void SetColor2(float fR, float fG, float fB, float fA);
    void ResetReading();
    void Render();

    float m_unk0;           // 0x00 vertex x, y, 1, 1
    float m_unk4;
    float m_unk8;
    float m_unkC;
    char _pad10[0x10];      // 0x10 cleared by ctor
    float m_unk20;          // 0x20 vertex row
    float m_unk24;
    float m_unk28;
    float m_unk2C;
    char _pad30[0x10];      // 0x30 cleared by ctor
    unsigned int m_unk40[4];// 0x40 colour row 0, written by SetColor1
    unsigned int m_unk50[4];// 0x50 colour row 1, written by SetColor1 when m_unk230 is 0
    unsigned int m_unk60[4];// 0x60 colour row 2, written by SetColor1 when m_unk230 is set
    char _pad70[0x10];      // 0x70 cleared by ctor
    float m_unk80;          // 0x80 vertex row
    float m_unk84;
    float m_unk88;
    float m_unk8C;
    float m_unk90;          // 0x90 vertex row
    float m_unk94;
    float m_unk98;
    float m_unk9C;
    float m_unkA0;          // 0xA0 vertex row
    float m_unkA4;
    float m_unkA8;
    float m_unkAC;
    float m_unkB0;          // 0xB0 vertex row
    float m_unkB4;
    float m_unkB8;
    float m_unkBC;
    unsigned int m_unkC0[16]; // 0xC0 background colour, four rows of r, g, b, a
    char _pad100[0x100];    // 0x100 cleared by ctor (0x100..0x1FF)
    float m_unk200[4];      // 0x200 colour floats, written by SetColor1
    float m_unk210;         // 0x210 cleared by ctor, SetColor2 r
    float m_unk214;         // 0x214 SetColor2 g
    float m_unk218;         // 0x218 SetColor2 b
    float m_unk21C;         // 0x21C 1.0f in ctor, SetColor2 a
    float m_unk220;         // 0x220 Init x
    float m_unk224;         // 0x224 Init y
    float m_unk228;         // 0x228 Init width
    float m_unk22C;         // 0x22C Init height
    unsigned char m_unk230; // 0x230 set to 1 by ctor
    float m_unk234;         // 0x234 range, set by SetRange
    float m_unk238;         // 0x238 reading
    int m_unk23C;
    int m_unk240;
    int m_unk244;           // 0x244 Init arg, 60 in ctor
    int m_unk248;           // 0x248 copy of 0x244
};

#endif
