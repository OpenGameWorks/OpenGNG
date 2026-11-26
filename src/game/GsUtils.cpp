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
static void Vif1DmaFrameBuffer(u_long128 *pBuf, short nA, short nB, short nC, short nD, short nE, short nF, short nG);
extern int guGrabFrameNumber;
extern int SCREEN_WIDTH;
extern u_long128 *gpFrameGrabBuf1;
extern u_long128 *gpFrameGrabBuf2;
extern "C" void sceVif1PkInit(void *pPk, void *pBuf);
extern "C" void sceVif1PkReset(void *pPk);
extern "C" void sceVif1PkAddCode(void *pPk, unsigned int nCode);
extern "C" void sceVif1PkAddGsData(void *pPk, unsigned long long nData);
extern "C" void sceVif1PkTerminate(void *pPk);
extern "C" void FlushCache(int nOp);
extern "C" void exit(int nCode);
extern "C" int sceGsGetIMR(void);
extern "C" int sceGsPutIMR(int nVal);

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

// DRAFT: 0x0017DE30 Vif1DmaFrameBuffer__FP1sssssss
// note: 105 differing words, size 0x458 vs 0x450; nQwc>=0x8000 compare uses v0 not at, hardware-address base reloaded per store (lui v1); variants tried: switch, if-chain, shift folded, volatile MMIO, base+offset MMIO
static void Vif1DmaFrameBuffer(u_long128 *pBuf, short nA, short nB, short nC, short nD, short nE, short nF, short nG) {
    static u_long128 enable_path3;
    char spA0[0x20];
    u_long128 spC0[0xA];
    int nQwc;
    int nLoop;
    int nIMR;

    if (nB == 0) {
        nQwc = (((int)nE * (int)nF) << 5) >> 7;
    } else if (nB == 1) {
        nQwc = ((int)nE * (int)nF * 0x18) >> 7;
    } else if (nB == 2) {
        nQwc = ((int)nE * (int)nF * 0x10) >> 7;
    } else if (nB == 19) {
        nQwc = ((int)nE * (int)nF * 8) >> 7;
    } else {
        nQwc = ((int)nE * (int)nF * 4) >> 7;
    }
    if (nQwc >= 0x8000) {
        printf("ERROR: Texture QWC is greater then NLOOP! line:(%d), file:(%s)\n", 0x463, "GsUtils.cpp");
        exit(0);
    }
    nLoop = nG >> 6;
    if (nLoop <= 0) {
        nLoop = 1;
    }
    sceVif1PkInit(spA0, spC0);
    sceVif1PkReset(spA0);
    sceVif1PkAddCode(spA0, 0);
    sceVif1PkAddCode(spA0, 0x06008000);
    sceVif1PkAddCode(spA0, 0x13000000);
    sceVif1PkAddCode(spA0, 0x50000006);
    sceVif1PkAddGsData(spA0, 0x8005ULL | (0x10000000ULL << 32));
    sceVif1PkAddGsData(spA0, 0xE);
    sceVif1PkAddGsData(spA0, ((long long)nB << 24) | ((long long)nA | ((long long)nLoop << 16)));
    sceVif1PkAddGsData(spA0, 0x50);
    sceVif1PkAddGsData(spA0, (long long)nC | ((long long)nD << 16));
    sceVif1PkAddGsData(spA0, 0x51);
    sceVif1PkAddGsData(spA0, (long long)nE | ((long long)nF << 32));
    sceVif1PkAddGsData(spA0, 0x52);
    sceVif1PkAddGsData(spA0, 0);
    sceVif1PkAddGsData(spA0, 0x61);
    sceVif1PkAddGsData(spA0, 1);
    sceVif1PkAddGsData(spA0, 0x53);
    sceVif1PkTerminate(spA0);
    nIMR = sceGsPutIMR(sceGsGetIMR() | 0x200);
    *(volatile unsigned long long *)0x12001000 = 2;
    FlushCache(0);
    *(volatile unsigned int *)0x10009020 = 7;
    *(volatile unsigned int *)0x10009010 = *(unsigned int *)&spA0[4] & 0x0FFFFFFF;
    asm { sync }
    *(volatile unsigned int *)0x10009000 = 0x101;
    while (*(volatile unsigned int *)0x10009000 & 0x100) {
    }
    printf(" 5 GS registers set\n");
    while (!(*(volatile unsigned long long *)0x12001000 & 2)) {
    }
    printf(" Finish event complete\n");
    *(volatile unsigned int *)0x10003C00 = 0x800000;
    *(volatile unsigned long long *)0x12001040 = 1;
    asm { sync }
    printf(" Changed VIF1 and GS direction complete\n");
    FlushCache(0);
    *(volatile unsigned int *)0x10009020 = nQwc;
    *(volatile unsigned int *)0x10009010 = (unsigned int)pBuf & 0x0FFFFFFF;
    asm { sync }
    *(volatile unsigned int *)0x10009000 = 0x100;
    while (*(volatile unsigned int *)0x10009000 & 0x100) {
    }
    printf(" Transferred:(%d) QW from GS -> MEM complete\n", nQwc);
    *(volatile unsigned int *)0x10003C00 = 0;
    *(volatile unsigned long long *)0x12001040 = 0;
    sceGsPutIMR(nIMR);
    *(volatile unsigned long long *)0x12001000 = 2;
    printf(" Restore VIF1 and GS direction complete\n");
    *(volatile u_long128 *)0x10005000 = enable_path3;
    printf(" Restore PATH3 direction complete\n");
}

// FUNCTION: 0x0017E280 FudgeBytesToBMPFormat__FPciiff
static void FudgeBytesToBMPFormat(char *pBuf, int nWidth, int nHeight, float fA, float fB) {
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

// FUNCTION: 0x0017E2C0 GsDumpFrameBuffersAsBmp__Fii
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

// FUNCTION: 0x0017EBD0 GsInitFogSprite__FP18tagFogSpritePacketcccUi
void GsInitFogSprite(tagFogSpritePacket *pPacket, char cR, char cG, char cB, unsigned int nZ) {
    GifTag *pTag = (GifTag *)pPacket;
    pPacket->m_unk00 = 0;
    pTag->NLOOP = 0x2C;
    pTag->EOP = 1;
    pTag->NREG = 1;
    pTag->REGS0 = 0xE;
    pPacket->m_unk10 = 0x70000;
    pPacket->m_unk18 = 0x47;
    pPacket->m_unk30 = 0x46;
    pPacket->m_unk38 = 0;
    pPacket->m_unk20 = 0x11;
    pPacket->m_unk28 = 0x42;
    pPacket->m_unk40 = (unsigned long)cR | ((unsigned long)cG << 8) | ((unsigned long)cB << 16) | ((unsigned long)0x80 << 24) | ((unsigned long)0x3F800000 << 32);
    pPacket->m_unk48 = 1;
    int i;
    int nX;
    int nOff;
    nX = 0;
    for (i = 0, nOff = 0; i < 20; i++) {
        char *pV = (char *)pPacket + nOff;
        *(unsigned long *)(pV + 0x50) = (unsigned long)((SCREEN_OFFSET_X + nX) << 4) | ((unsigned long)(SCREEN_OFFSET_Y << 4) << 16) | ((unsigned long)nZ << 32);
        *(long long *)(pV + 0x58) = 5;
        *(unsigned long *)(pV + 0x60) = (unsigned long)((SCREEN_OFFSET_X + (nX + 0x20)) << 4) | ((unsigned long)((SCREEN_OFFSET_Y + SCREEN_HEIGHT) << 4) << 16) | ((unsigned long)nZ << 32);
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

// DRAFT: 0x0017F100 GsSetFullScreenSprites__FP22tagGsFullScreenSpritesccccbbb
// note: size 0x3B4 vs 0x3E4; frame 0xF0 vs 0xE0, char spill order, FTOI4 reloc; six short locals tried (228 words)
void GsSetFullScreenSprites(tagGsFullScreenSprites *pInfo, char cA, char cB, char cC, char cD, bool bA, bool bB, bool bC) {
    float aSrc[4];
    int aDst[4];
    unsigned char *pB;
    unsigned char *pE;
    short sHalfW;
    short sHalfH;
    short sStep;
    short sX;
    short sY;
    short sH;
    int i;

    CDS_ASSERT(0x211, pInfo);
    *(u_long128 *)pInfo = 0;
    pB = (unsigned char *)pInfo;
    *(unsigned short *)pB = (*(unsigned short *)pB & 0x8000) | 2;
    pB[1] = (pB[1] & 0x7F) | ((0 & 1) << 7);
    pB[7] = (pB[7] & 0xF0) | 0x10;
    pB[8] = (pB[8] & 0xF0) | 0x0E;
    *(long long *)(pB + 0x10) = 0;
    *(long long *)(pB + 0x18) = 0x1A;
    *(long long *)(pB + 0x20) = ((long long)(bC & 0xFF) << 9) | ((long long)(bA & 0xFF) << 4) | ((long long)(bB & 0xFF) << 6) | 0x100;
    *(long long *)(pB + 0x28) = 0x1B;
    *(u_long128 *)(pB + 0x30) = 0;
    *(long long *)(pB + 0x30) = (*(long long *)(pB + 0x30) & 0xFC007FFFFFFFFFFFLL) | (6LL << 47);
    pB[0x35] = (pB[0x35] & 0xBF) | 0x40;
    *(unsigned short *)(pB + 0x30) = (*(unsigned short *)(pB + 0x30) & 0x8000) | 0x14;
    pB[0x31] = (pB[0x31] & 0x7F) | 0x80;
    pB[0x37] = (pB[0x37] & 0xF0) | 0x50;
    pB[0x37] = (pB[0x37] & 0xF3) | ((0 & 3) * 4);
    pB[0x38] = (pB[0x38] & 0xF0) | 3;
    pB[0x38] = (pB[0x38] & 0x0F) | 0x10;
    pB[0x39] = (pB[0x39] & 0xF0) | 5;
    pB[0x39] = (pB[0x39] & 0x0F) | 0x30;
    pB[0x3A] = (pB[0x3A] & 0xF0) | 5;

    sH = SCREEN_HEIGHT;
    sHalfW = SCREEN_WIDTH / 2;
    sStep = SCREEN_WIDTH / 20;
    sHalfH = SCREEN_HEIGHT / 2;
    sX = 0x800 - sHalfW;
    sY = 0x800 - sHalfH;
    aSrc[0] = 0.0f;
    aSrc[1] = 0.0f;
    aSrc[2] = 0.0f;
    aSrc[3] = (float)SCREEN_HEIGHT;
    for (i = 0; i < 20; i++) {
        pE = (unsigned char *)pInfo + i * 0x50;
        FTOI4((float *)aDst, aSrc);
        *(int *)(pE + 0x40) = aDst[0];
        *(int *)(pE + 0x44) = aDst[1];
        *(int *)(pE + 0x50) = cA;
        *(int *)(pE + 0x54) = cB;
        *(int *)(pE + 0x58) = cC;
        *(int *)(pE + 0x5C) = cD;
        *(int *)(pE + 0x60) = sX * 0x10;
        *(int *)(pE + 0x64) = sY * 0x10;
        *(int *)(pE + 0x68) = 0;
        *(int *)(pE + 0x70) = aDst[2];
        *(int *)(pE + 0x74) = aDst[3];
        *(int *)(pE + 0x80) = (sX + sStep) * 0x10;
        *(int *)(pE + 0x84) = (sY + sH) * 0x10;
        *(int *)(pE + 0x88) = 0;
        sX += sStep;
        aSrc[0] += 32.0f;
        aSrc[2] += 32.0f;
    }
}

// DRAFT: 0x0017F4F0 Gs16BitShadowBufferSetup__FP27tagGs16BitShadowBufferSetupP21tagShadowVolumeBuffer
// note: 314 of 324 words differ; frame 0xC0 vs 0xE0 (arrays at sp+0xA0 vs C0/D0), size 0x500 vs 0x504; tag0 bitfield RMW order and tag1 PRIM as ld/sd mask were tried, bitfield-only tag1 gave 318
void Gs16BitShadowBufferSetup(tagGs16BitShadowBufferSetup *pInfo, tagShadowVolumeBuffer *pBufferInfo)
{
    float aSrc[4] = {0.5f, 0.5f, 32.5f, 0.0f};
    int aDst[4];
    int nFlag = 0;
    short nHalfW;
    short nTop;
    short nLeft;
    short nStep;
    int nRowY;
    int nRowStep;
    int nOff;
    int i;

    CDS_ASSERT(0x1B4, pInfo);
    CDS_ASSERT(0x1B5, pBufferInfo);

    *(u_long128 *)pInfo = 0;
    pInfo->tag0.NLOOP = 9;
    pInfo->tag0.EOP = nFlag;
    pInfo->tag0.NREG = 1;
    pInfo->tag0.REGS0 = 0xE;
    pInfo->m_unk10 = 0xFFFFFFFF01000000LL | ((long long)(pBufferInfo->m_unk08 / 64) << 16) | (long long)(pBufferInfo->m_unk1C / 0x2000);
    pInfo->m_unk18 = 0x4D;
    pInfo->m_unk20 = ((long long)((0x800 - (pBufferInfo->m_unk08 >> 1)) << 4)) | ((long long)((0x800 - (pBufferInfo->m_unk0C >> 1)) << 4));
    pInfo->m_unk28 = 0x19;
    pInfo->m_unk30 = ((long long)(pBufferInfo->m_unk08 - 1) << 16) | ((long long)(pBufferInfo->m_unk0C - 1) << 48);
    pInfo->m_unk38 = 0x41;
    pInfo->m_unk40 = (long long)(pBufferInfo->m_unk04 / 0x2000) | 0x3A000000LL;
    pInfo->m_unk48 = 0x4F;
    pInfo->m_unk50 = 0x30000;
    pInfo->m_unk58 = 0x48;
    pInfo->m_unk60 = (0x80LL << 32) | 0xA4;
    pInfo->m_unk68 = 0x43;
    pInfo->m_unk70 = 0;
    pInfo->m_unk78 = 0x4B;
    pInfo->m_unk80 = 1;
    pInfo->m_unk88 = 0x1A;
    pInfo->m_unk90 = 0x240;
    pInfo->m_unk98 = 0x1B;
    *(u_long128 *)&pInfo->tag1 = 0;
    *(long long *)&pInfo->tag1 = (*(long long *)&pInfo->tag1 & 0xFC007FFFFFFFFFFFLL) | (0x246LL << 47);
    pInfo->tag1.PRE = 1;
    pInfo->tag1.NLOOP = 0x14;
    pInfo->tag1.EOP = 1;
    pInfo->tag1.NREG = 5;
    pInfo->tag1.FLG = nFlag & 3;
    pInfo->tag1.REGS0 = 0xF;
    pInfo->tag1.REGS1 = 1;
    pInfo->tag1.REGS2 = 5;
    pInfo->tag1.REGS3 = 0xF;
    pInfo->tag1.REGS4 = 3;

    nHalfW = (short)pBufferInfo->m_unk0C;
    nStep = (short)(pBufferInfo->m_unk08 / 20);
    nLeft = (short)(0x800 - pBufferInfo->m_unk08 / 2);
    nTop = (short)(0x800 - pBufferInfo->m_unk0C / 2);
    aSrc[3] = 0.5f + (float)pBufferInfo->m_unk0C;

    nRowY = nLeft << 4;
    nRowStep = nStep << 4;
    nOff = 0;
    for (i = 0; i < 20; i++) {
        char *base;
        FTOI4((float *)aDst, aSrc);
        base = (char *)pInfo + nOff;
        *(int *)(base + 0xB0) = aDst[0];
        *(int *)(base + 0xB4) = aDst[1];
        *(int *)(base + 0xC0) = 0xFF;
        *(int *)(base + 0xC4) = 0xFF;
        *(int *)(base + 0xC8) = 0xFF;
        *(int *)(base + 0xCC) = 0xFF;
        *(int *)(base + 0xD0) = nRowY;
        *(int *)(base + 0xD4) = nTop << 4;
        nRowY += nRowStep;
        *(int *)(base + 0xD8) = 0;
        *(int *)(base + 0xE0) = aDst[2];
        *(int *)(base + 0xE4) = aDst[3];
        *(int *)(base + 0xF0) = (nLeft + nStep) << 4;
        *(int *)(base + 0xF4) = (nTop + nHalfW) << 4;
        *(int *)(base + 0xF8) = 0;
        nLeft = (short)(nLeft + nStep);
        aSrc[0] = aSrc[0] + 32.0f;
        aSrc[2] = aSrc[2] + 32.0f;
        nOff += 0x50;
    }
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

// FUNCTION: 0x001800A0 GsSetTCC__FP23tagGsTextureEnvironmentb
void GsSetTCC(tagGsTextureEnvironment *pTexEnv, bool bFlag) {
    CDS_ASSERT(0x10E, pTexEnv);
    pTexEnv->m_bTCC = bFlag;
}
