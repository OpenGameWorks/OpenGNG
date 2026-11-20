// FLAGS: -str readonly
#include "types.h"
#include "GsUtils.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pExpr, int nLine, char *pFile);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceGsPutDispEnv(void *pEnv);
extern "C" void sceGsPutDrawEnv(void *pEnv);
extern int SCREEN_OFFSET_X;
extern int SCREEN_OFFSET_Y;
extern int SCREEN_HEIGHT;

// FUNCTION: 0x0017D750 GsInitClut256__FP12tagGsClut256
void GsInitClut256(tagGsClut256 *pClut) {
    if (pClut == 0) {
        CdsAssert__FPciPc("pClut", 0x599, "GsUtils.cpp");
    }
    memset(pClut, 0, 0x460);
    pClut->m_unk50 = 0;
    *(long long *)&pClut->m_unk50 = 0x0800000000008040LL;
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
    if (pInfo == 0) {
        CdsAssert__FPciPc("pInfo", 0x18B, "GsUtils.cpp");
    }
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
    if (pTexEnv == 0) {
        CdsAssert__FPciPc("pTexEnv", 0x10E, "GsUtils.cpp");
    }
    unsigned int nOld = pTexEnv->m_unk34;
    unsigned int nBit = ((unsigned int)bFlag & 1u) << 2;
    pTexEnv->m_unk34 = (nOld & ~4u) | nBit;
}
