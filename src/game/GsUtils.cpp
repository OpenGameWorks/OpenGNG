// FLAGS: -str readonly
#include "types.h"
#include "GsUtils.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pExpr, int nLine, char *pFile);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceGsPutDispEnv(void *pEnv);
extern "C" void sceGsPutDrawEnv(void *pEnv);

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
