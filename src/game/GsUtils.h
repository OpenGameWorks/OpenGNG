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

void GsInitClut256(tagGsClut256 *pClut);
void FudgeBytesToBMPFormat(char *pBuf, int nWidth, int nHeight, float fA, float fB);
int GsSwapDBuff(sceGsDBuff *pDBuff, int nIdx);
void GsSetFrameBufferCopyInfo(tagGsFrameBufferCopy *pInfo, int nX, int nY);
void GsSetTCC(tagGsTextureEnvironment *pTexEnv, bool bFlag);

#endif
