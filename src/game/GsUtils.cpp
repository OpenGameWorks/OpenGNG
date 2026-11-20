// FLAGS: -str readonly
#include "types.h"
#include "GsUtils.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("GsUtils.cpp", line, #cond))
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void sceGsPutDispEnv(void *pEnv);
extern "C" void sceGsPutDrawEnv(void *pEnv);
extern int SCREEN_OFFSET_X;
extern int SCREEN_OFFSET_Y;
extern int SCREEN_HEIGHT;
extern unsigned char MODE_PAL;
void FTOI4(float *pDst, float *pSrc);
struct sceGifPacket {
    unsigned int m_unk0;
    unsigned int m_unk4;
    unsigned int m_unk8;
    unsigned int m_unkC;
};
struct GsDmaTag {
    unsigned long long m_unk0;
    unsigned int m_unk8;
    unsigned int m_unkC;
};
extern "C" void sceGifPkInit(sceGifPacket *pPk, unsigned int nFlags);
extern "C" void sceGifPkReset(sceGifPacket *pPk);
extern "C" void sceGifPkAddGsData(sceGifPacket *pPk, unsigned long long nData);
extern "C" void sceGifPkTerminate(sceGifPacket *pPk);
extern "C" unsigned int sceGifPkSize(sceGifPacket *pPk);
extern "C" int sceGsSyncPath(int nMode, int nWait);
void DmaSendSrcChain(int nChannel, void *pData, bool bWait, bool bFlag, bool bTte);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" int printf(const char *pFmt, ...);
extern "C" int sceOpen(const char *pName, int nFlags);
extern "C" int sceWrite(int nFd, void *pBuf, int nSize);
extern "C" int sceClose(int nFd);
void Vif1DmaFrameBuffer(u_long128 *pBuf, short nA, short nB, short nC, short nD, short nE, short nF, short nG);
extern int guGrabFrameNumber;
extern int SCREEN_WIDTH;
extern u_long128 *gpFrameGrabBuf1;
extern u_long128 *gpFrameGrabBuf2;

// FUNCTION: 0x0017D750 GsInitClut256__FP12tagGsClut256
void GsInitClut256(tagGsClut256 *pClut) {
    CDS_ASSERT(0x599, pClut);
    memset(pClut, 0, 0x460);
    pClut->m_unk50 = 0;
    *(long long *)&pClut->m_unk50 = 0x0800000000008040LL;
}

// DRAFT: 0x0017D7C0 GsCreateMoveRG2BAPacket__FiiiiiRi
// note: 231 words differ, size 0x3B8 vs 0x3D0: nE/nD/nC land in fp/s7/s6 with nE spilled to 0xAC (original fp=nE, s7=nD, s6=nC, rSize at 0xAC); nS3 branch shape and sign-test branches differ; second CdsAssert string relocation (@602) differs. Tried: do/while vs while loop, nS3 if/else, nVa8 move (kept), nVa1 reuse in quad (234).
tagMoveRgToBaPacket *GsCreateMoveRG2BAPacket(int nA, int nB, int nC, int nD, int nE, int &rSize) {
    int nTiles;
    int nTotal;
    int nS3;
    int nVa0;
    int nVa1;
    int nVb;
    int nVa8;
    int nI;
    int nX0;
    int nX1;
    int nT3;
    unsigned char *pb;
    unsigned char *pv;
    unsigned char *apPacket;

    nTiles = nB >> 4;
    if (nB < 0) {
        nTiles = (nB + 0xF) >> 4;
    }
    nS3 = 2;
    if (nB == 0x20) {
        nS3 = 0xA;
    }
    nTotal = (nTiles * 4) + 0x11;
    apPacket = (unsigned char *)__nwa__FUi(nTotal * 0x10);
    CDS_ASSERT(0x53A, apPacket);
    rSize = nTotal * 0x10;
    pb = apPacket;
    *(unsigned short *)pb = (unsigned short)((*(unsigned short *)pb & ~0x7FFF) | ((nTotal - 1) & 0x7FFF));
    pb[1] = (unsigned char)((pb[1] & ~0x80) | 0x80);
    pb[7] = (unsigned char)((pb[7] & ~0xF0) | 0x10);
    pb[8] = (unsigned char)((pb[8] & ~0xF) | 0xE);
    *(long long *)(pb + 0x10) = 0;
    *(long long *)(pb + 0x18) = 0x3F;
    nVb = nB >> 6;
    if (nB < 0) {
        nVb = (nB + 0x3F) >> 6;
    }
    nVa1 = 1;
    if (nVb >= 2) {
        nVa1 = nVb;
    }
    nVa0 = nA >> 0xD;
    if (nA < 0) {
        nVa0 = (nA + 0x1FFF) >> 0xD;
    }
    nVa8 = nA >> 8;
    if (nA < 0) {
        nVa8 = (nA + 0xFF) >> 8;
    }
    *(long long *)(pb + 0x20) = ((long long)nS3 << 0x18) | ((long long)nVa0 | ((long long)nVa1 << 0x10)) | (0x7FFFLL << 0x20);
    *(long long *)(pb + 0x28) = 0x4C;
    *(long long *)(pb + 0x30) = 0;
    *(long long *)(pb + 0x38) = 0x4A;
    *(long long *)(pb + 0x40) = 0;
    *(long long *)(pb + 0x48) = 0x18;
    *(long long *)(pb + 0x50) = 0x0FFF0000LL | (0x0FFF0000LL << 0x20);
    *(long long *)(pb + 0x58) = 0x40;
    *(long long *)(pb + 0x60) = 0;
    *(long long *)(pb + 0x68) = 8;
    *(long long *)(pb + 0x70) = 0x31001;
    *(long long *)(pb + 0x78) = 0x47;
    *(long long *)(pb + 0x80) = 0x2ALL | (0x80LL << 0x20);
    *(long long *)(pb + 0x88) = 0x42;
    *(long long *)(pb + 0x90) = 1;
    *(long long *)(pb + 0x98) = 0x1A;
    *(long long *)(pb + 0xA0) = 0;
    *(long long *)(pb + 0xA8) = 0x45;
    *(long long *)(pb + 0xB0) = 0x80LL << 0x20;
    *(long long *)(pb + 0xB8) = 0x3B;
    *(long long *)(pb + 0xC0) = 1;
    *(long long *)(pb + 0xC8) = 0x14;
    pv = pb + 0x100;
    *(long long *)(pb + 0xD0) = ((((long long)(nE + 1)) << 0x1E) | (((long long)nD) << 0x1A) | (((long long)nS3) << 0x14) | ((long long)nVa8 | (((long long)((nVb < 2) ? 1 : nVb)) << 0xE))) | (0xCLL << 0x20);
    *(long long *)(pb + 0xD8) = 6;
    *(long long *)(pb + 0xE0) = 0x116;
    *(long long *)(pb + 0xE8) = 0;
    *(long long *)(pb + 0xF0) = (0x8080LL << 0x10) | 0x8080LL | (0x3F800000LL << 0x20);
    *(long long *)(pb + 0xF8) = 1;
    nI = 0;
    if (nTiles > 0) {
        nX0 = 0;
        nX1 = 0;
        nT3 = nC << 5;
        do {
            *(long long *)pv = (long long)(nX0 + 8) | 0x80000;
            *(long long *)(pv + 0x8) = 3;
            *(long long *)(pv + 0x10) = (long long)(nX1 + 0x80);
            *(long long *)(pv + 0x18) = 5;
            *(long long *)(pv + 0x20) = (long long)(nX0 + 0x88) | ((long long)(nT3 + 8) << 0x10);
            *(long long *)(pv + 0x28) = 3;
            nI += 1;
            *(long long *)(pv + 0x30) = (long long)(nX1 + 0x100) | ((long long)nT3 << 0x10);
            nX0 += 0x100;
            *(long long *)(pv + 0x38) = 5;
            nX1 += 0x100;
            pv += 0x40;
        } while (nI < nTiles);
    }
    *(long long *)pv = 0;
    *(long long *)(pv + 0x8) = 0x1A;
    return (tagMoveRgToBaPacket *)apPacket;
}

// DRAFT: 0x0017DB90 GsClearVRAM__FUcUcUcUcsss
// note: DIFF 56 words; prologue copies nA/nX/nY into s6/s2/s1 in the wrong order (ours nY/nA/nX), which shifts the width term and scissor word; tried scissor operand order, nXi first, nA-first colour OR, and nY<<20 final term (no drop)
void GsClearVRAM(unsigned char nR, unsigned char nG, unsigned char nB, unsigned char nA, short nX, short nY, short nW) {
    sceGifPacket pk;
    sceGifPkInit(&pk, 0x70001000);
    sceGifPkReset(&pk);
    sceGifPkAddGsData(&pk, (0x10000000ULL << 32) | 0x800B);
    sceGifPkAddGsData(&pk, 0xE);
    sceGifPkAddGsData(&pk, 1);
    sceGifPkAddGsData(&pk, 0x1A);
    int nXi = nX;
    sceGifPkAddGsData(&pk, (long long)(nXi / 64) << 16);
    sceGifPkAddGsData(&pk, 0x4C);
    sceGifPkAddGsData(&pk, (1ULL << 32) | 0x31000180);
    sceGifPkAddGsData(&pk, 0x4E);
    sceGifPkAddGsData(&pk, 0);
    sceGifPkAddGsData(&pk, 0x18);
    sceGifPkAddGsData(&pk, ((long long)nX << 16) | ((long long)nY << 48));
    sceGifPkAddGsData(&pk, 0x40);
    sceGifPkAddGsData(&pk, 0x30000);
    sceGifPkAddGsData(&pk, 0x47);
    sceGifPkAddGsData(&pk, 0x44);
    sceGifPkAddGsData(&pk, 0x42);
    sceGifPkAddGsData(&pk, 6);
    sceGifPkAddGsData(&pk, 0);
    sceGifPkAddGsData(&pk, (unsigned long long)nR | ((unsigned long long)nG << 8) | ((unsigned long long)nB << 16) | ((unsigned long long)nA << 24) | (0x3F800000ULL << 32));
    sceGifPkAddGsData(&pk, 1);
    sceGifPkAddGsData(&pk, 0);
    sceGifPkAddGsData(&pk, 4);
    sceGifPkAddGsData(&pk, (((long long)nY << 4) << 16) | (long long)(nXi << 4));
    sceGifPkAddGsData(&pk, 4);
    sceGifPkTerminate(&pk);
    unsigned int nSize = sceGifPkSize(&pk);
    GsDmaTag tag;
    tag.m_unk0 = ((unsigned long long)pk.m_unk4 << 32) | 0x8000000000000000ULL | nSize;
    tag.m_unk8 = 0;
    tag.m_unkC = 0;
    DmaSendSrcChain(2, &tag, false, false, true);
    sceGsSyncPath(0, 0);
}

// FUNCTION: 0x0017E280 FudgeBytesToBMPFormat__FPciiff
void FudgeBytesToBMPFormat(char *pBuf, int nWidth, int nHeight, float fA, float fB) {
    for (int i = 0; i < nWidth * nHeight; i += nHeight) {
        char *p = pBuf + i;
        char c = p[0];
        p[0] = p[2];
        p[2] = c;
    }
}

#pragma pack(1)
struct BmpFileHeader {
    unsigned short m_unk0;
    unsigned int m_unk2;
    unsigned short m_unk6;
    unsigned short m_unk8;
    unsigned int m_unkA;
};
#pragma pack()

struct BmpInfoHeader {
    unsigned int m_unk0;
    int m_unk4;
    int m_unk8;
    unsigned short m_unkC;
    unsigned short m_unkE;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18[4];
};

// DRAFT: 0x0017E2C0 GsDumpFrameBuffersAsBmp__Fii
// note: DIFF 6 words: the second FudgeBytesToBMPFormat call reloads a2=3 (original reuses it), and the nOff-branch block at 0x1DC has an extra nop. Tried: loop var before offset (fixed s3/s4 swap), nOff update before printf (fixed delay slot), `!nA == !nB` (broke prologue).
void GsDumpFrameBuffersAsBmp(int nA, int nB) {
    BmpInfoHeader ih;
    char szName[0x80];
    BmpFileHeader fh;
    guGrabFrameNumber++;
    sprintf(szName, "host:Frame%06d.bmp", guGrabFrameNumber);
    int fd = sceOpen(szName, 0x602);
    fh.m_unk0 = 0x4D42;
    fh.m_unk2 = SCREEN_WIDTH * (SCREEN_HEIGHT * 2) * 3 + 0x36;
    fh.m_unk6 = 0;
    fh.m_unk8 = 0;
    fh.m_unkA = 0x36;
    memset(&ih, 0, 0x28);
    ih.m_unk0 = 0x28;
    ih.m_unkC = 1;
    ih.m_unk10 = 0;
    ih.m_unkE = 0x18;
    ih.m_unk4 = SCREEN_WIDTH;
    ih.m_unk8 = SCREEN_HEIGHT * 2;
    ih.m_unk14 = SCREEN_WIDTH * (SCREEN_HEIGHT * 2) * 3;
    sceWrite(fd, &fh, 0xE);
    sceWrite(fd, &ih, 0x28);
    u_long128 *pBuf1 = gpFrameGrabBuf1;
    u_long128 *pBuf2 = gpFrameGrabBuf2;
    Vif1DmaFrameBuffer(pBuf1, 0, 1, 0, 0, 0x280, 0xE0, 0x280);
    Vif1DmaFrameBuffer(pBuf2, (short)((SCREEN_WIDTH * SCREEN_HEIGHT) / 64), 1, 0, 0, 0x280, 0xE0, 0x280);
    int i;
    int nOff = 0x68880;
    for (i = 0; i < 0xE0; i++) {
        char *pS1 = (char *)pBuf1 + nOff;
        FudgeBytesToBMPFormat(pS1, 0x280, 3, 0.3f, 0.3f);
        char *pS2 = (char *)pBuf2 + nOff;
        FudgeBytesToBMPFormat(pS2, 0x280, 3, 0.3f, 0.3f);
        if ((!nA && !nB) || (nA && nB)) {
            sceWrite(fd, pS1, 0x780);
            sceWrite(fd, pS2, 0x780);
        } else {
            sceWrite(fd, pS2, 0x780);
            sceWrite(fd, pS1, 0x780);
        }
        nOff -= 0x780;
        printf("written line:%d\n", i);
    }
    sceClose(fd);
}

// DRAFT: 0x0017E560 GsInitClearPacket__FP17tagGsClearSpritesiiccccb
// note: first C draft from asm; header words, RGBAQ and loop not yet compared
int GsInitClearPacket(tagGsClearSprites *pPacket, int nW, int nH, char cR, char cG, char cB, char cA, bool bFlag) {
    int nCount = nW / 32;
    int nSize = 0x460 - ((0x20 - nCount) << 5);
    unsigned char *pB = (unsigned char *)pPacket;
    unsigned long long nRgbaq;
    unsigned short nHdr;
    short nX;
    short nY;
    short nYH;
    int i;

    memset(pPacket, 0, 0x460);
    *(u_long128 *)pPacket = 0;

    nRgbaq = (unsigned long long)(long long)cR | ((unsigned long long)(long long)cG << 8) | ((unsigned long long)(long long)cB << 16) | ((unsigned long long)(long long)cA << 24) | ((unsigned long long)0x3F800000 << 32);

    nHdr = *(unsigned short *)pPacket;
    *(unsigned short *)pPacket = (nHdr & 0x8000) | (((nCount << 1) + 5) & 0x7FFF);
    pB[1] = (pB[1] & 0x7F) | 0x80;
    pB[7] = (pB[7] & 0x0F) | 0x10;
    pB[8] = (pB[8] & 0xF0) | 0x0E;

    *(unsigned long long *)(pB + 0x30) = 0x30000;
    *(unsigned long long *)(pB + 0x38) = 0x47;
    *(unsigned long long *)(pB + 0x10) = 1;
    *(unsigned long long *)(pB + 0x18) = 0x1A;
    *(unsigned long long *)(pB + 0x20) = ((unsigned long long)bFlag << 6) | 6;
    *(unsigned long long *)(pB + 0x28) = 0;
    *(unsigned long long *)(pB + 0x40) = 0x44;
    *(unsigned long long *)(pB + 0x48) = 0x42;
    *(unsigned long long *)(pB + 0x50) = nRgbaq;
    *(unsigned long long *)(pB + 0x58) = 1;

    nX = (short)(0x800 - nW / 2);
    nY = (short)(0x800 - nH / 2);
    nYH = (short)nH;

    for (i = 0; i < nCount; i++) {
        unsigned char *pE = pB + i * 0x20;
        *(short *)(pE + 0x60) = (short)(nX << 4);
        *(short *)(pE + 0x62) = (short)(nY << 4);
        nX += 0x20;
        *(short *)(pE + 0x70) = (short)(nX << 4);
        *(short *)(pE + 0x72) = (short)((nY + nYH) << 4);
        *(unsigned long long *)(pE + 0x68) = 5;
        *(unsigned long long *)(pE + 0x78) = 5;
        *(unsigned long long *)(pE + 0x60) = (*(unsigned long long *)(pE + 0x60) & ~0ULL) | 0;
        *(unsigned long long *)(pE + 0x70) = (*(unsigned long long *)(pE + 0x70) & ~0ULL) | 0;
    }

    return nSize;
}

// FUNCTION: 0x0017E820 GsSetSpriteCoords__FP10sprite_tagssssiiiis
void GsSetSpriteCoords(sprite_tag *pSprite, short nX0, short nX1, short nX2, short nX3, int nOffX, int nOffY, int nW, int nH, short nFlag) {
    pSprite->m_unk20 = nX0 << 4;
    pSprite->m_unk24 = nX1 << 4;
    pSprite->m_unk28 = nX2 << 4;
    pSprite->m_unk2C = nX3 << 4;
    if (nFlag != 0) {
        pSprite->m_unk20 += 8;
        pSprite->m_unk28 += 8;
        pSprite->m_unk24 += 8;
        pSprite->m_unk2C += 8;
    }
    pSprite->m_unk38 = nOffX << 4;
    pSprite->m_unk3C = nOffY << 4;
    pSprite->m_unk30 = nW << 4;
    pSprite->m_unk34 = nH << 4;
    int nScrX = SCREEN_OFFSET_X * 16;
    pSprite->m_unk10 = nScrX + pSprite->m_unk38;
    int nScrY = SCREEN_OFFSET_Y * 16;
    pSprite->m_unk14 = nScrY + pSprite->m_unk3C;
    pSprite->m_unk18 = pSprite->m_unk10 + pSprite->m_unk30;
    pSprite->m_unk1C = pSprite->m_unk14 + pSprite->m_unk34;
    pSprite->m_unk00 = 0x80;
    pSprite->m_unk04 = 0x80;
    pSprite->m_unk08 = 0x80;
    pSprite->m_unk0C = 0x80;
}

// DRAFT: 0x0017E920 GsInitTexturedFogSprite__FP26tagTexturedFogSpritePacketcccUi
// note: first C draft from asm; header/byte RMW, fixed stores, PAL float init and 20-step loop written, not yet compared
void GsInitTexturedFogSprite(tagTexturedFogSpritePacket *pPacket, char cR, char cG, char cB, unsigned int nZ) {
    float aSrc[4];
    int aDst[4];
    unsigned long long nZHi = (unsigned long long)nZ << 32;
    long long nRGB = (long long)cR | ((long long)cG << 8) | ((long long)cB << 16) | 0x3F80000080000000LL;
    *(u_long128 *)pPacket = 0;
    unsigned short nHdr = *(unsigned short *)pPacket;
    *(unsigned short *)pPacket = (nHdr & 0x8000) | 0x54;
    unsigned char *pB = (unsigned char *)pPacket;
    pB[1] = (pB[1] & 0x7F) | 0x80;
    pB[7] = (pB[7] & 0x0F) | 0x10;
    pB[8] = (pB[8] & 0xF0) | 0x0E;
    *(long long *)(pB + 0x10) = 0x70000;
    *(long long *)(pB + 0x18) = 0x47;
    *(long long *)(pB + 0x30) = 0x156;
    *(long long *)(pB + 0x38) = 0;
    *(long long *)(pB + 0x20) = 0x11;
    *(long long *)(pB + 0x28) = 0x42;
    *(long long *)(pB + 0x40) = nRGB;
    *(long long *)(pB + 0x48) = 1;
    if (MODE_PAL != 0) {
        aSrc[0] = 0.5f;
        aSrc[1] = 0.5f;
        aSrc[2] = 32.5f;
        aSrc[3] = 0.5f + (float)SCREEN_HEIGHT;
    } else {
        aSrc[0] = 0.0f;
        aSrc[1] = 0.0f;
        aSrc[2] = 32.0f;
        aSrc[3] = (float)SCREEN_HEIGHT;
    }
    for (int i = 0; i < 20; i++) {
        int nOff = i * 0x20;
        unsigned char *pE = (unsigned char *)pPacket + i * 0x40;
        *(long long *)(pE + 0x60) = nZHi | ((long long)((SCREEN_OFFSET_Y << 4)) << 16) | (long long)((SCREEN_OFFSET_X + nOff) << 4);
        *(long long *)(pE + 0x68) = 5;
        *(long long *)(pE + 0x80) = nZHi | ((long long)((SCREEN_OFFSET_Y + SCREEN_HEIGHT) << 4) << 16) | (long long)((SCREEN_OFFSET_X + nOff + 0x20) << 4);
        *(long long *)(pE + 0x88) = 5;
        *(long long *)(pE + 0x58) = 3;
        *(long long *)(pE + 0x78) = 3;
        FTOI4((float *)aDst, aSrc);
        *(unsigned short *)(pE + 0x50) = (*(unsigned short *)(pE + 0x50) & 0xC000) | (aDst[0] & 0x3FFF);
        *(unsigned short *)(pE + 0x52) = (*(unsigned short *)(pE + 0x52) & 0xC000) | (aDst[1] & 0x3FFF);
        *(unsigned short *)(pE + 0x70) = (*(unsigned short *)(pE + 0x70) & 0xC000) | (aDst[2] & 0x3FFF);
        *(unsigned short *)(pE + 0x72) = (*(unsigned short *)(pE + 0x72) & 0xC000) | (aDst[3] & 0x3FFF);
        aSrc[0] = aSrc[0] + 32.0f;
        aSrc[2] = aSrc[2] + 32.0f;
    }
}

// DRAFT: 0x0017EBD0 GsInitFogSprite__FP18tagFogSpritePacketcccUi
// note: DIFF 102; original has 0x40 frame saving s0..s3 and 0x198 body, ours 0x10 frame and 0x16c body, lhu vs lh header load; tried separate/shared nOff and early constant (no change)
void GsInitFogSprite(tagFogSpritePacket *pPacket, char cR, char cG, char cB, unsigned int nZ) {
    long long nRGB = (long long)cR | ((long long)cG << 8) | ((long long)cB << 16);
    pPacket->m_unk00 = 0;
    unsigned short nHdr = *(unsigned short *)pPacket;
    *(unsigned short *)pPacket = (nHdr & 0x8000) | 0x2C;
    unsigned char *pB = (unsigned char *)pPacket;
    pB[1] = (pB[1] & ~0x80) | 0x80;
    pB[7] = (pB[7] & ~0xF0) | 0x10;
    pB[8] = (pB[8] & ~0x0F) | 0x0E;
    pPacket->m_unk10 = 0x70000;
    pPacket->m_unk18 = 0x47;
    pPacket->m_unk30 = 0x46;
    pPacket->m_unk38 = 0;
    pPacket->m_unk20 = 0x11;
    pPacket->m_unk28 = 0x42;
    pPacket->m_unk40 = nRGB | 0x3F80000080000000LL;
    pPacket->m_unk48 = 1;
    unsigned long long nZHi = (unsigned long long)nZ << 32;
    int nX = 0;
    int nOff = 0;
    for (int i = 0; i < 20; i++) {
        char *pV = (char *)pPacket + nOff;
        long long nX0 = (SCREEN_OFFSET_X + nX) << 4;
        long long nY0 = (long long)(SCREEN_OFFSET_Y << 4) << 16;
        *(long long *)(pV + 0x50) = nX0 | nY0 | nZHi;
        *(long long *)(pV + 0x58) = 5;
        long long nX1 = (SCREEN_OFFSET_X + nX + 0x20) << 4;
        long long nY1 = (long long)((SCREEN_OFFSET_Y + SCREEN_HEIGHT) << 4) << 16;
        *(long long *)(pV + 0x60) = nX1 | nY1 | nZHi;
        *(long long *)(pV + 0x68) = 5;
        nX += 0x20;
        nOff += 0x20;
    }
}

// DRAFT: 0x0017ED70 GsInitMoveRG2BAPacket__FP19tagMoveRgToBaPacketssss
// note: DIFF 216 words, size 0x370 vs 0x390; prologue spill order and nD sign-extension (s5), constant-store order and per-use SCREEN_* reloads differ. Tried: locals removed (227->216), (short) casts on nD (220, reverted).
void GsInitMoveRG2BAPacket(tagMoveRgToBaPacket *pPacket, short nA, short nB, short nC, short nD) {
    int nBlk8 = SCREEN_WIDTH / 8;
    int nX = 0;
    int nOff = 8;
    int nRow = 0;
    int k;
    sprite_tag sprite;

    pPacket->m_unk00 = 0;
    ((unsigned short *)pPacket)[0] = (((unsigned short *)pPacket)[0] & 0x8000) | ((((nBlk8 / 2) << 2) + 12) & 0x7FFF);
    ((unsigned char *)pPacket)[1] = (((unsigned char *)pPacket)[1] & 0x7F) | 0x80;
    ((unsigned char *)pPacket)[7] = (((unsigned char *)pPacket)[7] & 0x0F) | 0x10;
    ((unsigned char *)pPacket)[8] = (((unsigned char *)pPacket)[8] & 0xF0) | 0x0E;
    ((long long *)pPacket)[2] = (long long)nB | ((long long)(SCREEN_WIDTH / 64) << 16) | 0x2000000LL | (0x3FFFLL << 32);
    ((long long *)pPacket)[3] = 0x4D;
    ((long long *)pPacket)[8] = (long long)(SCREEN_OFFSET_X << 4) | ((long long)(SCREEN_OFFSET_Y << 4) << 32);
    ((long long *)pPacket)[9] = 0x19;
    ((long long *)pPacket)[10] = ((long long)(SCREEN_WIDTH - 1) << 16) | ((long long)(SCREEN_HEIGHT * 2 - 1) << 48);
    ((long long *)pPacket)[4] = (long long)nC | (1LL << 32) | 0x31000000LL;
    ((long long *)pPacket)[5] = 0x4F;
    ((long long *)pPacket)[6] = 0x30000;
    ((long long *)pPacket)[7] = 0x48;
    ((long long *)pPacket)[11] = 0x41;
    ((long long *)pPacket)[12] = 0;
    ((long long *)pPacket)[13] = 0x3F;
    ((long long *)pPacket)[14] = 0x80LL << 32;
    ((long long *)pPacket)[15] = 0x3B;
    ((long long *)pPacket)[16] = 0;
    ((long long *)pPacket)[17] = 0x15;
    ((long long *)pPacket)[18] = (long long)nA | ((long long)(SCREEN_WIDTH / 64) << 14) | (0xAB20LL << 16) | (0xELL << 32);
    ((long long *)pPacket)[19] = 7;
    ((long long *)pPacket)[20] = 0x316;
    ((long long *)pPacket)[21] = 0;
    ((long long *)pPacket)[22] = (0x3F80LL << 32) | 0x80808080LL;
    ((long long *)pPacket)[23] = 1;

    for (k = 0; k < nBlk8; k += 2) {
        GsSetSpriteCoords(&sprite, (short)nX, 0, (short)(nX + 8), nD, nOff, 0, 8, nD, 1);
        *(long long *)((char *)pPacket + nRow + 0xC0) = (long long)sprite.m_unk20 | ((long long)sprite.m_unk24 << 16);
        *(long long *)((char *)pPacket + nRow + 0xC8) = 3;
        *(long long *)((char *)pPacket + nRow + 0xD0) = (long long)sprite.m_unk10 | ((long long)sprite.m_unk14 << 16);
        *(long long *)((char *)pPacket + nRow + 0xD8) = 5;
        *(long long *)((char *)pPacket + nRow + 0xE0) = (long long)sprite.m_unk28 | ((long long)sprite.m_unk2C << 16);
        *(long long *)((char *)pPacket + nRow + 0xE8) = 3;
        *(long long *)((char *)pPacket + nRow + 0xF0) = (long long)sprite.m_unk18 | ((long long)sprite.m_unk1C << 16);
        *(long long *)((char *)pPacket + nRow + 0xF8) = 5;
        nX += 0x10;
        nOff += 0x10;
        nRow += 0x40;
    }

    pPacket->m_unkAC0 = ((long long)(SCREEN_WIDTH - 1) << 16) | ((long long)(SCREEN_HEIGHT - 1) << 48);
    pPacket->m_unkAC8 = 0x40;
}

// FUNCTION: 0x0017FA00 GsSwapDBuff__FP10sceGsDBuffi
int GsSwapDBuff(sceGsDBuff *pDBuff, int nIdx) {
    int nBuf = nIdx & 1;
    sceGsPutDispEnv((char *)pDBuff + nBuf * 0x28);
    if (nBuf != 0) {
        sceGsPutDrawEnv(pDBuff->m_unk140);
        return (pDBuff->m_unk60 & 0x1FF) << 13;
    }
    sceGsPutDrawEnv(pDBuff->m_unk50);
    return (pDBuff->m_unk150 & 0x1FF) << 13;
}

// DRAFT: 0x0017FA80 GsSetFrameBufferCopyInfo__FP20tagGsFrameBufferCopyii
// note: 48 diff words; the compiler copies args into s1/s0/s2 in a different order from the original (pInfo s2, nX s1, nY s0); the 64-bit masks and sign-extension match; tried int-first vs mask-first order (no change)
void GsSetFrameBufferCopyInfo(tagGsFrameBufferCopy *pInfo, int nX, int nY) {
    CDS_ASSERT(0x18B, pInfo);
    int nV = nY >> 13;
    pInfo->m_unkC0 &= 0xFFFFFFFFFFFFFE00LL;
    if (nY < 0) {
        nV = (nY + 0x1FFF) >> 13;
    }
    pInfo->m_unkC0 |= (long long)(nV & 0x1FF);
    int nH = nX >> 8;
    pInfo->m_unk40 &= 0xFFFFFFFFFFFFC000LL;
    if (nX < 0) {
        nH = (nX + 0xFF) >> 8;
    }
    pInfo->m_unk40 |= (long long)nH & 0x3FFF;
}

// DRAFT: 0x001800A0 GsSetTCC__FP23tagGsTextureEnvironmentb
// note: DIFF 4 words; byte load (lbu a1) matches, but the bit term and ~4 mask swap registers (a0/v1); tried 8 operand and declaration orders
void GsSetTCC(tagGsTextureEnvironment *pTexEnv, bool bFlag) {
    CDS_ASSERT(0x10E, pTexEnv);
    unsigned int nOld = pTexEnv->m_unk34;
    unsigned int nBit = ((unsigned int)bFlag & 1u) << 2;
    pTexEnv->m_unk34 = (nOld & ~4u) | nBit;
}
