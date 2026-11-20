#ifndef PZBUFFERFOG_H
#define PZBUFFERFOG_H

#include "types.h"

struct tagClutFogData;
struct GsRGBA;

class PZBufferFog {
public:
    PZBufferFog();
    ~PZBufferFog();
    void TweenClutFog(tagClutFogData *pStart, tagClutFogData *pEnd, float fTime);
    void SetClutFogTable(GsRGBA *pClut);
    void SetClutFogTable(tagClutFogData *pData);
    void SetColor(float *pColor, bool bFlag, float fTime);
    void SetClutFogAlpha(float fAlpha);
    void SetDensity(float fDensity, bool bFlag, float fTime);
    void Animate(float fDelta);
    void Render();
    void Init();

    char _pad0000[0x12F0];                      // 0x0000
    char m_unk12F0[0x60];                       // 0x12F0 tagGsClut256
    char m_unk1350[0x400];                      // 0x1350 GsRGBA clut table
    int m_unk1750;                              // 0x1750
    float m_unk1754;                            // 0x1754
    float m_unk1758;                            // 0x1758
    float m_unk175C;                            // 0x175C
    int m_unk1760;                              // 0x1760
    int m_unk1764;                              // 0x1764
    char _pad1768[0x8];                         // 0x1768
    int m_unk1770[4];                           // 0x1770 vector, reset to (0,0,0,1)
    int m_unk1780[4];                           // 0x1780 vector, target colour
    int m_unk1790[4];                           // 0x1790 vector, per-frame delta
    int m_unk17A0;                              // 0x17A0
    int m_unk17A4;                              // 0x17A4
    char m_unk17A8;                             // 0x17A8
    unsigned char m_unk17A9;                    // 0x17A9
    unsigned char m_unk17AA;                    // 0x17AA
    unsigned char m_unk17AB;                    // 0x17AB
    unsigned char m_unk17AC;                    // 0x17AC
    char _pad17AD[0x3];                         // 0x17AD
    char m_unk17B0[0x50];                       // 0x17B0 tagClutFogData
    char m_unk1800[0x50];                       // 0x1800 tagClutFogData
    float m_unk1850;                            // 0x1850
    float m_unk1854;                            // 0x1854
};

#endif
