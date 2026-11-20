#ifndef GSUTILS_H
#define GSUTILS_H

#include "types.h"

typedef struct tagGsClut256 {
    char _pad000[0x50];
    u_long128 m_unk50;          // 0x050 CLUT packet head
} tagGsClut256;                 // size >= 0x60

typedef struct tagGsFrameBufferCopy {
    char _pad000[0x40];
    long long m_unk40;          // 0x040 frame buffer copy info, low half
    char _pad048[0x78];
    long long m_unkC0;          // 0x0C0 frame buffer copy info, high half
} tagGsFrameBufferCopy;         // size >= 0xC8

typedef struct tagGsTextureEnvironment {
    char _pad000[0x34];
    unsigned char m_unk34;      // 0x034 TCC bit lives in bit 2
} tagGsTextureEnvironment;      // size >= 0x35

typedef struct sceGsDBuff {
    char _pad000[0x50];
    char m_unk50[0x10];         // 0x050 draw environment 0 head
    int m_unk60;                // 0x060 frame value, draw environment 0
    char _pad064[0xDC];         // 0x064 rest of draw environment 0
    char m_unk140[0x10];        // 0x140 draw environment 1 head
    int m_unk150;               // 0x150 frame value, draw environment 1
} sceGsDBuff;                   // size >= 0x154

typedef struct sprite_tag {
    int m_unk00;                // 0x000 packet header word, set to 0x80
    int m_unk04;                // 0x004 packet header word, set to 0x80
    int m_unk08;                // 0x008 packet header word, set to 0x80
    int m_unk0C;                // 0x00C packet header word, set to 0x80
    int m_unk10;                // 0x010 x0, screen offset + m_unk38
    int m_unk14;                // 0x014 y0, screen offset + m_unk3C
    int m_unk18;                // 0x018 x1, m_unk10 + m_unk30
    int m_unk1C;                // 0x01C y1, m_unk14 + m_unk34
    int m_unk20;                // 0x020 vertex x0, shifted by 4
    int m_unk24;                // 0x024 vertex x1, shifted by 4
    int m_unk28;                // 0x028 vertex x2, shifted by 4
    int m_unk2C;                // 0x02C vertex x3, shifted by 4
    int m_unk30;                // 0x030 width, shifted by 4
    int m_unk34;                // 0x034 height, shifted by 4
    int m_unk38;                // 0x038 offset x, shifted by 4
    int m_unk3C;                // 0x03C offset y, shifted by 4
} sprite_tag;                   // size >= 0x40

typedef struct tagFogSpritePacket {
    u_long128 m_unk00;          // 0x000 GIF tag
    long long m_unk10;          // 0x010 register data 0x70000
    long long m_unk18;          // 0x018 register data 0x47
    long long m_unk20;          // 0x020 register data 0x11
    long long m_unk28;          // 0x028 register data 0x42
    long long m_unk30;          // 0x030 register data 0x46
    long long m_unk38;          // 0x038 register data 0
    long long m_unk40;          // 0x040 RGB with Q = 1.0
    long long m_unk48;          // 0x048 register data 1
    char m_unk50[0x280];        // 0x050 twenty pairs of XYZ2 words, 0x20 apart
} tagFogSpritePacket;           // size >= 0x2D0

typedef struct tagGsClearSprites {
    char _pad000[0x460];        // 0x000 GIF tag, clear sprite pairs; memset target
} tagGsClearSprites;            // size >= 0x460

typedef struct tagTexturedFogSpritePacket {
    char _pad000[0x290];        // 0x000 GIF tag, fog sprite pairs (stride 0x40)
} tagTexturedFogSpritePacket;   // size >= 0x290

void GsInitClut256(tagGsClut256 *pClut);
void FudgeBytesToBMPFormat(char *pBuf, int nWidth, int nHeight, float fA, float fB);
int GsSwapDBuff(sceGsDBuff *pDBuff, int nIdx);
void GsSetFrameBufferCopyInfo(tagGsFrameBufferCopy *pInfo, int nX, int nY);
void GsSetTCC(tagGsTextureEnvironment *pTexEnv, bool bFlag);
void GsSetSpriteCoords(sprite_tag *pSprite, short nX0, short nX1, short nX2, short nX3, int nOffX, int nOffY, int nW, int nH, short nFlag);
int GsInitClearPacket(tagGsClearSprites *pPacket, int nW, int nH, char cR, char cG, char cB, char cA, bool bFlag);
void GsInitTexturedFogSprite(tagTexturedFogSpritePacket *pPacket, char cR, char cG, char cB, unsigned int nZ);
void GsInitFogSprite(tagFogSpritePacket *pPacket, char cR, char cG, char cB, unsigned int nZ);

#endif
