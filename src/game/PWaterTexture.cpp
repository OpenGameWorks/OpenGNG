#include "types.h"
#include "PWaterTexture.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
float FastMath_IntCos180(int nAngle);
float FastMath_IntSin180(int nAngle);

// DRAFT: 0x001EEB60 WobbleSTGrids__13PWaterTextureFP21tagGsWobbleCopyStripsf
// note: loop, wrap and FastMath calls follow the asm; the VU0 lqc2/vmul/vadd/sqc2 chain is plain C with z=w=0, not byte-matched.
void PWaterTexture::WobbleSTGrids(tagGsWobbleCopyStrips *pStrips, float fScale) {
    int nPhase = (int)fScale;
    char *pBase = (char *)pStrips;
    for (int nRow = 1; nRow < 16; nRow++) {
        char *pCur = pBase + nRow * 2112 + 0x10;
        char *pPrev = pBase + (nRow - 1) * 2112 + 0x10;
        for (int nCol = 1; nCol < 32; nCol++) {
            nPhase -= 0xF;
            if (nPhase < 0) {
                nPhase += 0x168;
            } else if (nPhase >= 0x168) {
                nPhase -= 0x168;
            }
            float fCos = FastMath_IntCos180(nPhase - 0xB4);
            float fSin = FastMath_IntSin180(nPhase - 0xB4);
            float *pSrc = (float *)(pCur + nCol * 64);
            float *pDst = (float *)(pPrev + nCol * 64 + 0x20);
            float fZ = 0.0f;
            float fW = 0.0f;
            float fX = pSrc[0] + fCos * fZ + (fCos * fSin) * fZ;
            float fY = pSrc[1] + fSin * fZ + (fSin * fZ) * (fW * (fSin * fCos));
            pDst[0] = fX;
            pDst[1] = fY;
            pDst[2] = pSrc[2];
            pDst[3] = pSrc[3];
        }
    }
}

// FUNCTION: 0x001EECE0 Reset__13PWaterTextureFv
void PWaterTexture::Reset() {
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk4 = 0;
    m_unk86A0 = 0;
    m_unk86A4 = 0x40A00000;
    m_unk86A8 = 0;
    m_unk86AC = 0x40000000;
}

// FUNCTION: 0x001EEEE0 Init__13PWaterTextureFiii
int PWaterTexture::Init(int nA, int nB, int nC) {
    m_unk0 = nA;
    m_unk4 = nB;
    m_unk8 = nC;
    InitWobblePacket((tagGsWobbleCopy *)m_unk10, (tagGsWobbleCopyStrips *)m_unk150, m_unk0, m_unk8, false, 0, 0x44, 0, m_unk86B0, m_unk86B4);
    if (m_unk4 != 0) {
        InitWobblePacket((tagGsWobbleCopy *)m_unk8560, 0, m_unk4, m_unk8, true, (char)(int)m_unk86C0, 0x49, 0, m_unk86B8, m_unk86BC);
    }
    m_unk86A0 = 0;
    m_unk86A4 = 0x40A00000;
    m_unk86A8 = 0;
    m_unk86AC = 0x40000000;
    return 1;
}

// FUNCTION: 0x001EF1B0 __dt__13PWaterTextureFv
extern "C" PWaterTexture *__dt__13PWaterTextureFv(PWaterTexture *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001EF200 __ct__13PWaterTextureFv
PWaterTexture::PWaterTexture() {
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk4 = 0;
    memset(m_unk10, 0, 0x140);
    memset(m_unk8560, 0, 0x140);
    memset(m_unk150, 0, 0x8410);
}
