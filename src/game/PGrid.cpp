// FLAGS: -str readonly
#include "PGrid.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern "C" int rand();
extern "C" void __dla__FPv(void *pData);
extern "C" void __dl__FPv(void *pData);
extern "C" float FastMath_Sin180__Ff(float fAngle);
void FTOI4(float *pDst, float *pSrc);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern float GAME_FPS;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern "C" void *__nwa__FUi(unsigned int nSize);

// 16-byte base row for InitStrip's float vector; the original value sits in bss and is set at run time.
static u_long128 kStripBase;

struct PGridAlphaTable {
    float v[8];
};
static const PGridAlphaTable kAlphaTable = {{10.0f, -15.0f, 16.0f, 27.0f, 51.0f, -32.0f, 13.0f, -46.0f}};

// Large enough that gGfxEng is addressed with lui/addiu; the display list pointer sits at +0x154C80.
struct PGridGfxEngine {
    char _pad000[0x154C80];
    PDisplayList *pDisplayList;
};
extern PGridGfxEngine gGfxEng;

// DRAFT: 0x001F1DC0 AnimateAlphaGrid__5PGridFf
// note: 85 words differ: prologue store order (sq s0/swc1 f20, daddu s2), frame 0xB0 vs 0xC0 (one fewer saved s-reg), loop-entry b targets, table read folded into lwc1 0xA0(v1), wrap-compare block order. Tried: while-loop form, pointer table read, >= wrap compare (all 85).
void PGrid::AnimateAlphaGrid(float fAngle) {
    PGridAlphaTable table = kAlphaTable;
    float fAcc = fAngle;
    int nRow = 0;
    int nTable = 0;
    int nRowOff = 0;
    int nColOff;
    int nCol;
    char *pCell;
    float *pAlpha;
    float fVal;

    while (nRow <= m_0C) {
        nColOff = 0;
        nCol = 0;
        while (nCol < m_08) {
            fAcc = fAcc + table.v[nTable];
            nTable++;
            if (nTable >= 8) {
                nTable = 0;
            }
            if (fAcc < 0.0f) {
                fAcc = 360.0f + fAcc;
            } else if (!(fAcc < 360.0f)) {
                fAcc = fAcc - 360.0f;
            }
            pCell = (char *)this + nRowOff + nColOff;
            pAlpha = (float *)(pCell + 0x1014);
            if (*pAlpha != 0.0f) {
                fVal = *pAlpha * (0.75f * (1.0f + FastMath_Sin180__Ff(fAcc - 180.0f)));
                if (fVal > 1.0f) {
                    fVal = 1.0f;
                }
                *(float *)(pCell + 0x14) = fVal;
            }
            nColOff += 4;
            nCol++;
        }
        nRowOff += 0x80;
        nRow++;
    }
}

// DRAFT: 0x001F1F70 SetGridVertexAlpha__5PGridFv
// note: 121 words differ: loop-1 cell address and unsigned-scale branch layout (original hoists lui 0x8000, bltz delay slot), loop-2 register allocation (t0/t3 vs a3/t1), wrap b/bottom test. Tried: cell*cf vs cf*cell (129, same), pCell before cf in loop 1 (121), pCell in loop 2 (121), cf before pCell (121).
void PGrid::SetGridVertexAlpha() {
    unsigned char *base;
    int i;
    int a1;
    int col;
    int vOff;
    int cOff;
    int vcol;
    int ccol;
    int cellRow;
    float cf;
    float f;
    unsigned int r;

    base = (unsigned char *)m_10;
    vOff = 0;
    cOff = 0;
    for (i = 0; i < m_08; i++) {
        float *pCell = (float *)((unsigned char *)this + cOff + 0x14);
        cf = (float)m_2014;
        f = m_2018 * (*pCell * cf);
        r = (unsigned int)f;
        *(unsigned int *)(base + vOff + 0x1C) = r;
        cOff += 4;
        vOff += 0x60;
    }
    cellRow = 0x80;
    for (a1 = 1; a1 < m_0C; a1++) {
        vcol = 0;
        ccol = 0;
        for (col = 0; col < m_08; col++) {
            cf = (float)m_2014;
            f = m_2018 * (cf * *(float *)((unsigned char *)this + cellRow + ccol + 0x14));
            r = (unsigned int)f;
            *(unsigned int *)(base + a1 * m_08 * 0x60 + vcol + 0x1C) = r;
            *(unsigned int *)(base + (a1 - 1) * m_08 * 0x60 + vcol + 0x4C) = r;
            if (a1 == m_0C - 1) {
                cf = (float)m_2014;
                f = m_2018 * (cf * *(float *)((unsigned char *)this + cellRow + 0x80 + ccol + 0x14));
                *(unsigned int *)(base + a1 * m_08 * 0x60 + vcol + 0x4C) = (unsigned int)f;
            }
            vcol += 0x60;
            ccol += 4;
        }
        cellRow += 0x80;
    }
}

// DRAFT: 0x001F21F0 InitStrip__5PGridFP18tagGridStripVertexssssUiUiUiUifffb
// note: 99 words differ: sB/sD kept in fp instead of sp+0xCA/0xC8 spill slots, this at sp+0xEC not 0xCC, original computes fU+fW after the kStripBase copy (ours hoists it). Tried: volatile pSelf and nStep (99, from 114), volatile sB (99), volatile sD (107), volatile sB+sD (107), local volatile copies of sB/sD (109), fU+fW hoisted before the copy (99), non-volatile pSelf (115), non-volatile nStep (100), pSelf declared first (99).
void PGrid::InitStrip(tagGridStripVertex *pVerts, short sA, short sB, short sC, short sD,
                      unsigned int uA, unsigned int uB, unsigned int uC, unsigned int uD,
                      float fU, float fV, float fW, bool bFlag) {
    PGrid *volatile pSelf = this;
    int iv[4];
    float vec[4];
    int nRow;
    volatile int nStep;
    int nVOff;
    int nCol;
    tagGridStripVertex *pA;
    tagGridStripVertex *pB;

    if (pVerts == 0) {
        CdsAssert("PGrid.cpp", 211, "pStrip");
    }
    nRow = sA << 4;
    nStep = sC << 4;
    nVOff = 0;
    nCol = 0;
    float fSum = fU + fW;
    *(u_long128 *)vec = kStripBase;
    vec[1] = fU;
    vec[3] = fSum;
    for (nCol = 0; nCol < pSelf->m_08; nCol++) {
        FTOI4((float *)iv, vec);
        pA = (tagGridStripVertex *)((char *)pVerts + nVOff);
        pB = pA + 1;
        pA->m_00 = iv[0];
        pA->m_04 = iv[1];
        pA->m_10 = uA;
        pA->m_14 = uB;
        pA->m_18 = uC;
        pA->m_1C = uD;
        pA->m_20 = nRow;
        pA->m_24 = sB << 4;
        pB->m_00 = iv[2];
        pB->m_04 = iv[3];
        pB->m_10 = uA;
        pB->m_14 = uB;
        pB->m_18 = uC;
        pB->m_1C = uD;
        pB->m_20 = pA->m_20;
        pB->m_24 = (sB + sD) << 4;
        if (bFlag && nCol == 0) {
            pA->m_2D = (pA->m_2D & ~0x80) | 0x80;
            pB->m_2D = (pB->m_2D & ~0x80) | 0x80;
        }
        vec[0] = vec[0] + fV;
        vec[2] = vec[2] + fV;
        nVOff += 0x60;
        nRow += nStep;
    }
}

// FUNCTION: 0x001F23F0 Enable__5PGridFb
void PGrid::Enable(bool bEnable) {
    if (bEnable) {
        m_2018 = 0;
        m_201C = 1.0f / m_2024;
        m_2030 = 60.0f + (240.0f * ((float)rand() / 2147483648.0f));
        m_bEnabled = 1;
        return;
    }
    m_201C = -1.0f / m_2028;
}

// DRAFT: 0x001F24A0 Animate__5PGridFf
// note: 67 words differ: f-register load order at 0x5C-0x64, clamp branch layout (bc1f/mov.s delay slot), beqz target, lbu readback after tail sb, SetGridVertexAlpha unclaimed.
void PGrid::Animate(float fStep) {
    float fAlpha;
    float fClamp;

    if (m_bEnabled == 0) {
        return;
    }
    if (m_202C != 0.0f) {
        m_202C = m_202C - fStep;
        if (m_202C <= 0.0f) {
            Enable(false);
            m_202C = 0.0f;
        }
    }
    float fDelta = fStep * m_201C;
    m_2018 = m_2018 + fDelta;
    if (m_2018 <= 0.0f || !(m_2018 < 1.0f)) {
        m_201C = 0.0f;
        fAlpha = m_2018;
        fClamp = 1.0f;
        if (fAlpha < 1.0f) {
            fClamp = fAlpha;
        }
        if (!(fClamp <= 0.0f)) {
            if (!(fAlpha < 1.0f)) {
                fAlpha = 1.0f;
            }
        } else {
            fAlpha = 0.0f;
        }
        m_2018 = fAlpha;
    }
    m_2030 = m_2030 + 1.5f * fStep;
    if (!(m_2030 <= 360.0f)) {
        m_2030 = m_2030 - 360.0f;
    }
    if (m_pData != 0 && m_2018 != 0.0f) {
        AnimateAlphaGrid(m_2030);
        SetGridVertexAlpha();
    }
    m_bEnabled = m_2018 > 0.0f;
}

// FUNCTION: 0x001F2670 Render__5PGridFv
void PGrid::Render() {
    long long regs[4];
    long long *p;

    if (m_pData != 0 && m_bEnabled != 0) {
        regs[0] = 0;
        regs[1] = 0x1A;
        p = &regs[2];
        p[0] = 0x158;
        p[1] = 0x1B;
        gGfxEng.pDisplayList->SetGsRegisters((u_long128 *)regs, 2);
        gGfxEng.pDisplayList->SendGsPacket(m_pData, m_nSize * 0x10, true);
    }
}

// DRAFT: 0x001F2710 Init__5PGridFffiiPfUiUiUiUi
// note: 238 words, size 0x3a0 vs 0x408: prologue spills (nB reloaded from 0xF8(sp)), header bit-field byte edits (lbu/and/or vs sb of constants); SCREEN_*/GAME_FPS are gp-relative in the original too (relocs.tsv type 7). Tried: u_long128 clear (239), null-check restructure (238), h[5] write moved last (238).
int PGrid::Init(float fA, float fB, int nA, int nB, float *pSrc, unsigned int uA, unsigned int uB, unsigned int uC, unsigned int uD) {
    int halfW;
    int halfH;
    short sA;
    short sB;
    short sC;
    short sD;
    int i;
    int off;
    float fU;
    float fV;
    float fW;
    float *src;
    unsigned char *h;

    Destroy();
    m_08 = nB + 1;
    m_0C = nA;
    m_nSize = m_0C * m_08 * 6 + 1;
    h = (unsigned char *)__nwa__FUi(m_nSize * 0x10);
    m_pData = h;
    if (h == 0) {
        return 0;
    }
    *(u_long128 *)h = 0;
    *(long long *)h = (*(long long *)h & ((0xFFFF << 0x10) | 0xFFFF | ((long long)0xFC007FFF << 0x20))) | ((long long)4 << 0x2F);
    h[5] = (h[5] & ~0x40) | 0x40;
    *(short *)h = (short)((*(unsigned short *)h & ~0x7FFF) | ((m_08 * m_0C) & 0x7FFF));
    h[1] = (h[1] & ~0x80) | 0x80;
    h[7] = (h[7] & ~0xF0) | 0x60;
    h[7] = (h[7] & ~0xC) | 0;
    h[8] = (h[8] & ~0xF) | 3;
    h[8] = (h[8] & ~0xF0) | 0x10;
    h[9] = (h[9] & ~0xF) | 5;
    h[9] = (h[9] & ~0xF0) | 0x30;
    h[10] = (h[10] & ~0xF) | 1;
    h[10] = (h[10] & ~0xF0) | 0x50;
    m_10 = (int)m_pData + 0x10;

    halfW = SCREEN_WIDTH >> 1;
    sC = (short)(SCREEN_WIDTH / nB);
    sD = (short)(SCREEN_HEIGHT / nA);
    if (SCREEN_WIDTH < 0) {
        halfW = (SCREEN_WIDTH + 1) >> 1;
    }
    halfH = SCREEN_HEIGHT >> 1;
    sA = (short)(0x800 - halfW);
    if (SCREEN_HEIGHT < 0) {
        halfH = (SCREEN_HEIGHT + 1) >> 1;
    }
    i = 0;
    fU = 0.0f;
    sB = (short)(0x800 - halfH);
    fV = (float)SCREEN_WIDTH / (float)nB;
    fW = (float)SCREEN_HEIGHT / (float)nA;
    for (; i < m_0C; i++) {
        InitStrip((tagGridStripVertex *)((char *)m_10 + i * m_08 * 0x60), sA, sB, sC, sD, uA, uB, uC, uD, fU, fV, fW, i > 0);
        fU += fW;
        sB = (short)(sB + sD);
    }
    m_2014 = uD;
    off = 0;
    i = 0;
    src = pSrc;
    while (i <= m_0C) {
        memcpy((char *)this + off + 0x1014, src, m_08 * 4);
        off += 0x80;
        i++;
        src = &src[m_08];
    }
    memcpy((char *)this + 0x14, (char *)this + 0x1014, 0x1000);
    SetGridVertexAlpha();
    m_2024 = 0.25f * GAME_FPS;
    m_2028 = GAME_FPS;
    return 1;
}

// FUNCTION: 0x001F2B20 Destroy__5PGridFv
void PGrid::Destroy() {
    if (m_pData != 0) {
        __dla__FPv(m_pData);
        m_pData = 0;
    }
    m_nSize = 0;
    m_10 = 0;
}

// FUNCTION: 0x001F2B60 __dt__5PGridFv
PGrid::~PGrid() {
    Destroy();
}

// FUNCTION: 0x001F2BC0 __ct__5PGridFv
PGrid::PGrid() {
    m_nSize = 0;
    m_pData = 0;
    m_10 = 0;
    m_0C = 0;
    m_08 = 0;
    m_2018 = 0;
    m_201C = 0.0f;
    m_2030 = 0.0f;
    m_202C = 0;
    m_bEnabled = 0;
}
