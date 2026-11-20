#ifndef PWATERTEXTURE_H
#define PWATERTEXTURE_H

class tagGsWobbleCopy;
class tagGsWobbleCopyStrips;
class tagWobbleStrip;
class tagProceduralTextureData;
class PArray;

// Water texture object. Three ints at 0x00, a 0x140 block at 0x10, a 0x8410
// block at 0x150, a 0x140 block at 0x8560, four words at 0x86A0 and five
// floats at 0x86B0.
class PWaterTexture {
public:
    PWaterTexture();
    void Reset();
    void Update();
    int Init(int nA, int nB, int nC);
    int Init(tagProceduralTextureData *pData, PArray *pArr);
    void InitWobblePacket(tagGsWobbleCopy *pPacket, tagGsWobbleCopyStrips *pStrips, int nA, int nB, bool bFlag, char cFlag, unsigned long nC, int nD, float fA, float fB);
    void WobbleSTGrids(tagGsWobbleCopyStrips *pStrips, float fScale);
    void InitWobbleStrip(tagWobbleStrip *pStrip, char cA, short sB, short sC, short sD, short sE, float fA, bool bFlag, float fB, float fC);

    int m_unk0;                 // 0x00
    int m_unk4;                 // 0x04
    int m_unk8;                 // 0x08
    char _pad0C[4];             // 0x0C
    char m_unk10[0x140];        // 0x10 zeroed by the constructor
    char m_unk150[0x8410];      // 0x150 zeroed by the constructor
    char m_unk8560[0x140];      // 0x8560 zeroed by the constructor
    int m_unk86A0;              // 0x86A0
    int m_unk86A4;              // 0x86A4 float 5.0f as bits
    int m_unk86A8;              // 0x86A8
    int m_unk86AC;              // 0x86AC float 2.0f as bits
    float m_unk86B0;            // 0x86B0 first InitWobblePacket f12
    float m_unk86B4;            // 0x86B4 first InitWobblePacket f13
    float m_unk86B8;            // 0x86B8 second InitWobblePacket f12
    float m_unk86BC;            // 0x86BC second InitWobblePacket f13
    float m_unk86C0;            // 0x86C0 converted to char for second call
};

#endif
