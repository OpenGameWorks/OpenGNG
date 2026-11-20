// FLAGS: -str readonly
#include "types.h"
#include "PSlideShow.h"
#include "PGfxEngine.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern PGfxEngine gGfxEng;
struct tagGdlGlobal { PDisplayList *m_pdl; char _pad004[0x10]; };
extern tagGdlGlobal gUnk45B300;
extern "C" void FastMath_ComputeMatrixLite__FPA4_A4_fPA4_fPA4_fPA4_fPA4_A4_f(void);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, char *pExpr);
extern "C" int rand(void);
float FastMath_Sin180__Ff(float fAngle);
float FastMath_Cos180__Ff(float fAngle);

// DRAFT: 0x00214BA0 AnimateFadingTiles__10PSlideShowFf
// note: 67 words differ (was 74); prologue constant/seed scheduling and a0-a3 register allocation differ from the original; tried for-loop shape, hoisted poly base, seed store first, reordered locals, column counter outside, inverted fade test.
void PSlideShow::AnimateFadingTiles(float fTime)
{
    m_unk38 = m_unk3C;
    int nTotal = m_unk14 * m_unk18;
    char *pPolyBase = (char *)m_unk24 + 0x10;
    int nFaded = 0;
    int nRow = 0;
    for (nRow = 0; nRow < m_unk14; nRow++) {
        for (int nCol = 0; nCol < m_unk18; nCol++) {
            int nIdx = nCol + nRow * m_unk18;
            tagTile *pTile = (tagTile *)((char *)m_unkC + nIdx * 0x30);
            tagGsPoly *pPoly = (tagGsPoly *)(pPolyBase + nIdx * 0x90);
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            float fY = pTile->m_fUnk2C;
            if (!(fY <= 0.0f)) {
                fY = fY - (2.0f + 1.0f * (0.000030517578f * (float)((m_unk38 >> 16) & 0x7FFF)));
                pTile->m_fUnk2C = fY;
                if (!(fY >= 0.0f)) {
                    fY = 0.0f;
                }
                pTile->m_fUnk2C = fY;
                pPoly->m_unkC = (int)fY;
            } else {
                nFaded++;
                pPoly->m_unkC = 0;
                if (nFaded >= nTotal) {
                    m_unk3C = (int)(0.5f + (12345.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
                    ResetTiles();
                    m_ucUnk41 = 0;
                    m_unk04 = m_nNextImage;
                    m_nNextImage = 0;
                    return;
                }
            }
            nCol++;
        }
        nRow++;
    }
}

#define POLY_F(p, off) (*(float *)((char *)(p) + (off)))
#define POLY_I(p, off) (*(int *)((char *)(p) + (off)))

// DRAFT: 0x00214D70 AnimateVanishingTiles__10PSlideShowFf
// note: 332 words differ; frame is 0x110 (ours 0xA0), extra fp spill, loop/local register allocation and operand order differ; 2 variants tried (add operand order, original order), both 332
void PSlideShow::AnimateVanishingTiles(float fTime)
{
    m_unk38 = m_unk3C;
    m_unk34 = 0.001953125f + m_unk34;
    int nTotal = m_unk14 * m_unk18;
    char *pPolyBase = (char *)m_unk24 + 0x10;
    int nFaded = 0;
    for (int nRow = 0; nRow < m_unk14; nRow++) {
        for (int nCol = 0; nCol < m_unk18; nCol++) {
            int nIdx = nCol + nRow * m_unk18;
            tagTile *pTile = (tagTile *)((char *)m_unkC + nIdx * 0x30);
            tagGsPoly *pPoly = (tagGsPoly *)(pPolyBase + nIdx * 0x90);
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            float fDraw1 = 0.000030517578f * (float)((m_unk38 >> 16) & 0x7FFF);
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            float fDraw2 = 0.000030517578f * (float)((m_unk38 >> 16) & 0x7FFF);
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            float fDraw3 = 0.000030517578f * (float)((m_unk38 >> 16) & 0x7FFF);
            float fY = pTile->m_fUnk2C;
            if (!(fY <= 0.0f)) {
                float fA = 1.5f + 1.0f * fDraw3;
                float fNew18 = pTile->m_unk18 + (-3.0f + 6.0f * fDraw2);
                pTile->m_unk18 = fNew18;
                if (!(fNew18 <= 180.0f)) {
                    pTile->m_unk18 = fNew18 - 360.0f;
                } else if (fNew18 < -180.0f) {
                    pTile->m_unk18 = fNew18 + 360.0f;
                }
                float fNew1C = pTile->m_unk1C + (-3.0f + 6.0f * fDraw1);
                pTile->m_unk1C = fNew1C;
                if (!(fNew1C <= 180.0f)) {
                    pTile->m_unk1C = fNew1C - 360.0f;
                } else if (fNew1C < -180.0f) {
                    pTile->m_unk1C = fNew1C + 360.0f;
                }
                float fNewY = pTile->m_fUnk2C - fA;
                pTile->m_fUnk2C = fNewY;
                if (!(0.0f <= fNewY)) {
                    fNewY = 0.0f;
                }
                pTile->m_fUnk2C = fNewY;
                pPoly->m_unkC = (int)fNewY;
                POLY_F(pPoly, 0x10) = (float)nCol * (1.0f / (float)m_unk18);
                POLY_F(pPoly, 0x14) = (float)nRow * (1.0f / (float)m_unk14);
                POLY_I(pPoly, 0x18) = 0x3F800000;
                POLY_F(pPoly, 0x30) = POLY_F(pPoly, 0x10);
                POLY_F(pPoly, 0x34) = POLY_F(pPoly, 0x14) + (1.0f / (float)m_unk14);
                POLY_I(pPoly, 0x38) = 0x3F800000;
                POLY_F(pPoly, 0x50) = POLY_F(pPoly, 0x10) + (1.0f / (float)m_unk18);
                POLY_F(pPoly, 0x54) = POLY_F(pPoly, 0x14);
                POLY_I(pPoly, 0x58) = 0x3F800000;
                POLY_F(pPoly, 0x70) = POLY_F(pPoly, 0x50);
                POLY_F(pPoly, 0x74) = POLY_F(pPoly, 0x34);
                POLY_I(pPoly, 0x78) = 0x3F800000;
                float fSin = FastMath_Sin180__Ff(pTile->m_unk18);
                float fCos = FastMath_Cos180__Ff(pTile->m_unk1C);
                POLY_F(pPoly, 0x10) = POLY_F(pPoly, 0x10) + m_unk34 * fCos;
                POLY_F(pPoly, 0x14) = POLY_F(pPoly, 0x14) + fSin * (m_unk34 * fSin);
                POLY_F(pPoly, 0x30) = POLY_F(pPoly, 0x30) + m_unk34 * fCos;
                POLY_F(pPoly, 0x34) = POLY_F(pPoly, 0x34) + fCos * (m_unk34 * fSin);
                POLY_F(pPoly, 0x50) = POLY_F(pPoly, 0x50) + fSin * (m_unk34 * fCos);
                POLY_F(pPoly, 0x54) = POLY_F(pPoly, 0x54) + m_unk34 * fSin;
                POLY_F(pPoly, 0x70) = POLY_F(pPoly, 0x70) + m_unk34 * fCos;
                POLY_F(pPoly, 0x74) = POLY_F(pPoly, 0x74) + fSin * (fCos * (m_unk34 * fSin));
            } else {
                nFaded++;
                pPoly->m_unkC = 0;
                if (nFaded >= nTotal) {
                    m_unk3C = (int)(0.5f + (12345.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
                    ResetTiles();
                    m_ucUnk41 = 0;
                    m_unk04 = m_nNextImage;
                    m_nNextImage = 0;
                    return;
                }
            }
        }
    }
}

// DRAFT: 0x00215250 AnimateFallingTiles__10PSlideShowFf
// note: 233 words; prologue saves fp (original saves only s0-s7), unk14/unk18/unk24 load into different a-regs, and the unk0 adda/madd/sin/mul/add order differs. Tried: pointer form for pPoly (233), split fBase sum (233), hoisted nRow/nFaded (236), inline poly base (288).
void PSlideShow::AnimateFallingTiles(float fTime)
{
    m_unk38 = m_unk3C;
    int nTotal = m_unk14 * m_unk18;
    char *pPolyBase = (char *)m_unk24 + 0x10;
    int nFaded = 0;
    for (int nRow = 0; nRow < m_unk14; nRow++) {
        for (int nCol = 0; nCol < m_unk18; nCol++) {
            int nIdx = nCol + nRow * m_unk18;
            tagTile *pTile = (tagTile *)((char *)m_unkC + nIdx * 0x30);
            tagGsPoly *pPoly = (tagGsPoly *)(pPolyBase + nIdx * 0x90);
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            int r1 = m_unk38;
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            int r2 = m_unk38;
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            int r3 = m_unk38;
            int r3Hi = (r3 >> 16) & 0x7FFF;
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            m_unk38 = m_unk38 * 0x343FD + 0x269EC3;
            int r5 = ((int)m_unk38 >> 16) & 0x7FFF;
            int nUnk20 = m_unk20;
            int nHalf = nUnk20 >> 1;
            if (nUnk20 < 0) {
                nHalf = (nUnk20 + 1) >> 1;
            }
            float fF20 = 2.0f + 1.0f * (0.000030517578f * (float)r5);
            if (pTile->m_fY < 16.0f + (2048.0f + (float)nHalf)) {
                float fA = *(float *)&pTile->m_unk10 + (5.0f + (5.0f * (0.000030517578f * (float)((r1 >> 16) & 0x7FFF))));
                *(float *)&pTile->m_unk10 = fA;
                if (!(fA <= 180.0f)) {
                    *(float *)&pTile->m_unk10 = fA - 360.0f;
                } else if (fA < -180.0f) {
                    *(float *)&pTile->m_unk10 = fA + 360.0f;
                }
                float fB = *(float *)&pTile->m_unk14 + (5.0f + (5.0f * (0.000030517578f * (float)((r2 >> 16) & 0x7FFF))));
                *(float *)&pTile->m_unk14 = fB;
                if (!(fB <= 180.0f)) {
                    *(float *)&pTile->m_unk14 = fB - 360.0f;
                } else if (fB < -180.0f) {
                    *(float *)&pTile->m_unk14 = fB + 360.0f;
                }
                float fC = *(float *)&pTile->m_unk1C + (0.5f + (3.5f * (0.000030517578f * (float)r3Hi)));
                *(float *)&pTile->m_unk1C = fC;
                if (!(fC <= 180.0f)) {
                    *(float *)&pTile->m_unk1C = fC - 360.0f;
                } else if (fC < -180.0f) {
                    *(float *)&pTile->m_unk1C = fC + 360.0f;
                }
                int nHalfC = m_unk1C >> 1;
                if (m_unk1C < 0) {
                    nHalfC = (m_unk1C + 1) >> 1;
                }
                pTile->m_fX = 16.0f + (2048.0f - (float)nHalfC) + 32.0f * (float)nCol + 32.0f * FastMath_Sin180__Ff(*(float *)&pTile->m_unk1C);
                pTile->m_fY += fF20;
                ApplyTileOnGsPoly(pPoly, pTile);
            } else {
                nFaded++;
                pPoly->m_unkC = 0;
                if (nFaded >= nTotal) {
                    m_unk3C = (int)(0.5f + (12345.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
                    ResetTiles();
                    m_ucUnk41 = 0;
                    m_unk04 = m_nNextImage;
                    m_nNextImage = 0;
                    return;
                }
            }
        }
    }
}

// DRAFT: 0x00215710 ResetTiles__10PSlideShowFv
// note: 67 words; frame 0x70 vs 0x60 from the u_long128 local used for the (0,0,0,1.0f) store; original builds it with dsll32/pcpyld and no stack slot. Tried: (u_long128)<<96 and <<64 (compile error), two sd stores (82), pf[13]/pf[20] reread through pointer (86); scratchpad stores and X/Y formulas already in asm order.
void PSlideShow::ResetTiles()
{
    *(float *)0x70001000 = 16.0f;
    *(float *)0x70001004 = 8.0f;
    *(float *)0x70001008 = 0.0f;
    *(float *)0x7000100C = 1.0f;
    *(float *)0x70001010 = 16.0f;
    *(float *)0x70001014 = -8.0f;
    *(float *)0x70001018 = 0.0f;
    *(float *)0x7000101C = 1.0f;

    char *pPolyBase = (char *)m_unk24 + 0x10;
    for (int nRow = 0; nRow < m_unk14; nRow++) {
        for (int nCol = 0; nCol < m_unk18; nCol++) {
            int nIdx = nCol + nRow * m_unk18;
            tagTile *pTile = (tagTile *)((char *)m_unkC + nIdx * 0x30);
            tagGsPoly *pPoly = (tagGsPoly *)(pPolyBase + nIdx * 0x90);
            pTile->m_fUnk2C = 128.0f;
            pTile->m_fX = 16.0f + (2048.0f - (float)(m_unk1C / 2)) + 32.0f * (float)nCol;
            pTile->m_fY = 8.0f + (2048.0f - (float)(m_unk20 / 2)) + 16.0f * (float)nRow;
            u_long128 vOne;
            ((unsigned long long *)&vOne)[0] = 0;
            ((unsigned long long *)&vOne)[1] = 0x3F80000000000000ULL;
            *(u_long128 *)&pTile->m_unk10 = vOne;
            SetGsPolyPos(pPoly, pTile, (float *)0x70001000, (float *)0x70001010);

            float fU = (float)nCol * (1.0f / (float)m_unk18);
            float fV = (float)nRow * (1.0f / (float)m_unk14);
            float *pf = (float *)pPoly;
            pf[4] = fU;
            pf[5] = fV;
            pf[12] = pf[4];
            pf[13] = fV + (1.0f / (float)m_unk14);
            pf[20] = fU + (1.0f / (float)m_unk18);
            pf[21] = pf[5];
            pf[28] = pf[20];
            pf[29] = pf[13];
        }
    }
}

// DRAFT: 0x00215990 ApplyTileOnGsPoly__10PSlideShowFPQ210PSlideShow9tagGsPolyPQ210PSlideShow7tagTile
// note: asm transcription of the original, not C; needs a C body (scratchpad 0x70001000 vector stores).
asm void PSlideShow::ApplyTileOnGsPoly(tagGsPoly *pPoly, tagTile *pTile)
{
    .set noreorder
    addiu sp, sp, -0x40
        lui v0, 0x7000
        sd ra, 0x30(sp)
        daddu a3, a2, zero
        sq s2, 0x20(sp)
        ori t4, v0, 0x1060
        sq s1, 0x10(sp)
        daddu s2, a1, zero
        sq s0, 0x0(sp)
        ori a1, v0, 0x1040
        ori s0, v0, 0x1000
        ori s1, v0, 0x1050
        ori t5, v0, 0x1070
        ori t6, v0, 0x1080
        lui t3, 0x3F80
        lui t2, 0xC180
        dsll32 v0, t3, 0
        lui t1, 0xC100
        or v0, t3, v0
        lui v1, 0x4100
        pcpyld v0, v0, v0
        sq v0, 0x0(a1)
        daddu a0, s0, zero
        sw t2, 0x0(s1)
        lui v0, 0x4180
        sw t1, 0x4(s1)
        addiu a2, a3, 0x10
        sw zero, 0x8(s1)
        daddu t0, zero, zero
        sw t3, 0xC(s1)
        sw t2, 0x0(t4)
        sw v1, 0x4(t4)
        sw zero, 0x8(t4)
        sw t3, 0xC(t4)
        sw v0, 0x0(t5)
        sw t1, 0x4(t5)
        sw zero, 0x8(t5)
        sw t3, 0xC(t5)
        sw v0, 0x0(t6)
        sw v1, 0x4(t6)
        sw zero, 0x8(t6)
        jal FastMath_ComputeMatrixLite__FPA4_A4_fPA4_fPA4_fPA4_fPA4_A4_f
        sw t3, 0xC(t6)
        lqc2 vf1, 0x0(s0)
        lqc2 vf2, 0x10(s0)
        lqc2 vf3, 0x20(s0)
        lqc2 vf4, 0x30(s0)
        lqc2 vf5, 0x0(s1)
        lqc2 vf6, 0x10(s1)
        lqc2 vf7, 0x20(s1)
        lqc2 vf8, 0x30(s1)
        vmulax.xyzw ACC, vf1, vf5x
        vmadday.xyzw ACC, vf2, vf5y
        vmaddaz.xyzw ACC, vf3, vf5z
        vmaddw.xyzw vf5, vf4, vf0w
        vmulax.xyzw ACC, vf1, vf6x
        vmadday.xyzw ACC, vf2, vf6y
        vmaddaz.xyzw ACC, vf3, vf6z
        vmaddw.xyzw vf6, vf4, vf0w
        vftoi4.xyzw vf5, vf5
        vmulax.xyzw ACC, vf1, vf7x
        vmadday.xyzw ACC, vf2, vf7y
        vmaddaz.xyzw ACC, vf3, vf7z
        vmaddw.xyzw vf7, vf4, vf0w
        vftoi4.xyzw vf6, vf6
        vmulax.xyzw ACC, vf1, vf8x
        vmadday.xyzw ACC, vf2, vf8y
        vmaddaz.xyzw ACC, vf3, vf8z
        vmaddw.xyzw vf8, vf4, vf0w
        vftoi4.xyzw vf7, vf7
        sqc2 vf5, 0x20(s2)
        sqc2 vf6, 0x40(s2)
        sqc2 vf7, 0x60(s2)
        vftoi4.xyzw vf8, vf8
        vnop
        vnop
        vnop
        sqc2 vf8, 0x80(s2)
        lbu v1, 0x2D(s2)
        addiu a0, zero, -0x81
        daddiu a1, zero, 0x80
        and v1, v1, a0
        or v1, v1, a1
        sb v1, 0x2D(s2)
        lbu v1, 0x4D(s2)
        and v1, v1, a0
        or v1, v1, a1
        sb v1, 0x4D(s2)
        ld ra, 0x30(sp)
        lq s2, 0x20(sp)
        lq s1, 0x10(sp)
        lq s0, 0x0(sp)
        jr ra
        addiu sp, sp, 0x40
}

// DRAFT: 0x00215B10 SetGsPolyPos__10PSlideShowFPQ210PSlideShow9tagGsPolyPQ210PSlideShow7tagTilePfPf
// note: 13 words; VU0 block and m_unkC store match. Flag updates differ: original keeps 0x80 in a register (daddiu a3) for both `or`s, ours folds it to immediates. Tried: unsigned int pair (13, kept), shift form (13), unsigned char (15), long pair (16), signed mask (worse).
void PSlideShow::SetGsPolyPos(tagGsPoly *pPoly, tagTile *pTile, float *pA, float *pB)
{
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a2)
        lqc2 vf2, 0x0(a3)
        lqc2 vf3, 0x0(t0)
        vsub.xyzw vf5, vf5, vf5
        vsub.xyzw vf6, vf6, vf6
        vsub.xyzw vf7, vf7, vf7
        vsub.xyzw vf8, vf8, vf8
        vsub.xyz vf5, vf1, vf2
        vsub.xyz vf6, vf1, vf3
        vadd.xyz vf7, vf1, vf3
        vadd.xyz vf8, vf1, vf2
        vftoi4.xyzw vf5, vf5
        vftoi4.xyzw vf6, vf6
        vftoi4.xyzw vf7, vf7
        vftoi4.xyzw vf8, vf8
        sqc2 vf5, 0x20(a1)
        sqc2 vf6, 0x40(a1)
        sqc2 vf7, 0x60(a1)
        sqc2 vf8, 0x80(a1)
    }
    unsigned int nFlag = 0x80;
    unsigned int nMask = ~nFlag;
    pPoly->m_ucUnk2D = (pPoly->m_ucUnk2D & nMask) | nFlag;
    pPoly->m_ucUnk4D = (pPoly->m_ucUnk4D & nMask) | nFlag;
    pPoly->m_unkC = (int)pTile->m_fUnk2C;
}

// FUNCTION: 0x00215BA0 InitTiles__10PSlideShowFPQ210PSlideShow7tagTile
void PSlideShow::InitTiles(tagTile *pTile)
{
    float fX = 16.0f + (2048.0f - (float)(m_unk1C / 2));
    float fY = 8.0f + (2048.0f - (float)(m_unk20 / 2));
    int nRow;
    int nCol;

    for (nRow = 0; nRow < m_unk14; nRow++) {
        for (nCol = 0; nCol < m_unk18; nCol++) {
            tagTile *p = &pTile[nCol + nRow * m_unk18];
            p->m_fX = fX;
            p->m_fY = fY;
            p->m_unk08 = 0;
            fX += 32.0f;
            p->m_unk0C = 0x3F800000;
            p->m_unk10 = 0;
            p->m_unk14 = 0;
            p->m_unk18 = 0;
            p->m_unk1C = 0;
            p->m_unk20 = 0x43000000;
            p->m_unk24 = 0x43000000;
            p->m_unk28 = 0x43000000;
            *(int *)&p->m_fUnk2C = 0x43000000;
        }
        fX = 16.0f + (2048.0f - (float)(m_unk1C / 2));
        fY += 16.0f;
    }
}

// DRAFT: 0x00215CF0 CreateImagePacket__10PSlideShowFRiPQ210PSlideShow7tagTile
// note: 89 words; register allocation differs (original keeps m_unk14*m_unk18 in s2 across __nwa, ours folds it into v1). Tried: inline post-call size (192), named nCount local in header and nQwc (168), -str readonly on line 1 (89, no change).
void *PSlideShow::CreateImagePacket(int &nOffset, tagTile *pTile)
{
    int nQwc = (m_unk14 * m_unk18) * 9 + 1;
    unsigned char *pPacket = (unsigned char *)__nwa__FUi(nQwc * 0x10);
    if (pPacket == 0) {
        CdsAssert__FPciPc("PSlideShow.cpp", 0xC4, "apPacket");
    }
    *(u_long128 *)pPacket = 0;
    *(u_long128 *)pPacket = (u_long128)((unsigned long long)(long long)(m_unk14 * m_unk18) | 0x8000ULL | (0x900E4000ULL << 32));
    pPacket[8] = (pPacket[8] & ~0xF) | 1;
    pPacket[8] = (pPacket[8] & ~0xF0) | 0x20;
    pPacket[9] = (pPacket[9] & ~0xF) | 5;
    pPacket[9] = (pPacket[9] & ~0xF0) | 0x20;
    pPacket[0xA] = (pPacket[0xA] & ~0xF) | 5;
    pPacket[0xA] = (pPacket[0xA] & ~0xF0) | 0x20;
    pPacket[0xB] = (pPacket[0xB] & ~0xF) | 5;
    pPacket[0xB] = (pPacket[0xB] & ~0xF0) | 0x20;
    pPacket[0xC] = (pPacket[0xC] & ~0xF) | 5;
    *(int *)0x70001000 = 0x41800000;
    *(int *)0x70001004 = 0x41000000;
    *(int *)0x70001008 = 0;
    *(int *)0x7000100C = 0x3F800000;
    *(int *)0x70001010 = 0x41800000;
    *(int *)0x70001014 = 0xC1000000;
    *(int *)0x70001018 = 0;
    *(int *)0x7000101C = 0x3F800000;
    unsigned char *pBase = pPacket + 0x10;
    for (int nRow = 0; nRow < m_unk14; nRow++) {
        for (int nCol = 0; nCol < m_unk18; nCol++) {
            int nIdx = nCol + nRow * m_unk18;
            tagGsPoly *pPoly = (tagGsPoly *)(pBase + nIdx * 0x90);
            int *pI = (int *)pPoly;
            float *pF = (float *)pPoly;
            pI[0] = 0x80;
            pI[1] = 0x80;
            pI[2] = 0x80;
            pI[3] = 0x80;
            pF[4] = (float)nCol * (1.0f / (float)m_unk18);
            pF[5] = (float)nRow * (1.0f / (float)m_unk14);
            pI[6] = 0x3F800000;
            pF[0xC] = pF[4];
            pF[0xD] = pF[5] + (1.0f / (float)m_unk14);
            pI[0xE] = 0x3F800000;
            pF[0x14] = pF[4] + (1.0f / (float)m_unk18);
            pF[0x15] = pF[5];
            pI[0x16] = 0x3F800000;
            pF[0x1C] = pF[0x14];
            pF[0x1D] = pF[0xD];
            pI[0x1E] = 0x3F800000;
            SetGsPolyPos(pPoly, pTile + nIdx, (float *)0x70001000, (float *)0x70001010);
        }
    }
    nOffset = nQwc * 0x10;
    return pPacket;
}

// DRAFT: 0x00216000 Render__10PSlideShowFv
// note: 80 differing words; quad stores and constant scheduling differ (original loads 0x18/0x1B and 0x44/0x42 into v0/v1 before storing and keeps sp+0x30 in a0). Tried: direct array stores (80), pointer cursor per quad (80).
void PSlideShow::Render()
{
    long long aGs[8];
    long long *p;

    gGfxEng.SetZBufferUpdate(false, (eGsContext)0);
    if (m_nNextImage != 0) {
        aGs[0] = 0;
        aGs[1] = 0x1A;
        p = &aGs[2];
        p[0] = 0x18;
        p[1] = 0x1B;
        p = &aGs[4];
        p[0] = 0x44;
        p[1] = 0x42;
        p = &aGs[6];
        p[0] = 0x30000;
        p[1] = 0x47;
        gGfxEng.m_unk154C80->SetGsRegisters((u_long128 *)aGs, 4);
        gGfxEng.SetTexture(m_nNextImage);
        gUnk45B300.m_pdl->SendGsPacket(m_unk28, m_unk2C, false);
    }
    aGs[0] = 0;
    aGs[1] = 0x1A;
    p = &aGs[2];
    p[0] = ((long long)m_ucUnk42 << 6) | 0x18;
    p[1] = 0x1B;
    p = &aGs[4];
    p[0] = 0x44;
    p[1] = 0x42;
    p = &aGs[6];
    p[0] = 0x30000;
    p[1] = 0x47;
    gGfxEng.m_unk154C80->SetGsRegisters((u_long128 *)aGs, 4);
    gGfxEng.SetTexture(m_unk04);
    gUnk45B300.m_pdl->SendGsPacket(m_unk24, m_unk2C, true);
    gGfxEng.SetZBufferUpdate(true, (eGsContext)0);
}

// DRAFT: 0x00216190 Animate__10PSlideShowFf
// note: 26 differing lines. The original has an early `beq` exit with a duplicated epilogue and a shared epilogue at 0x80, and dispatches the switch with beq; ours shares the epilogue at 0x74 and emits bne compare chains.
void PSlideShow::Animate(float fTime)
{
    if (m_ucUnk40 != 0) {
        if (m_ucUnk41 != 0) {
            if (m_nMode == 2) {
                AnimateVanishingTiles(fTime);
            } else if (m_nMode == 3) {
                AnimateFadingTiles(fTime);
            } else if (m_nMode == 1) {
                AnimateFallingTiles(fTime);
            }
        }
    }
}

// FUNCTION: 0x00216220 SetNextImage__10PSlideShowFi
void PSlideShow::SetNextImage(int nImage)
{
    m_nNextImage = nImage;
    m_ucUnk41 = 1;
    m_unk34 = 0;
    m_nMode = 2;
    if (m_nMode == 3 || m_nMode == 2) {
        m_ucUnk42 = 1;
    } else {
        m_ucUnk42 = 0;
    }
}

// FUNCTION: 0x00216270 SetFirstImage__10PSlideShowFi
void PSlideShow::SetFirstImage(int nImage)
{
    m_unk04 = nImage;
    m_ucUnk40 = 1;
    m_nNextImage = 0;
    m_ucUnk41 = 0;
}

// FUNCTION: 0x00216290 Create__10PSlideShowFii
int PSlideShow::Create(int nWidth, int nHeight)
{
    int nRows = nHeight >> 4;
    if (nHeight < 0) {
        nRows = (nHeight + 0xF) >> 4;
    }
    m_unk14 = nRows;
    int nCols = nWidth >> 5;
    if (nWidth < 0) {
        nCols = (nWidth + 0x1F) >> 5;
    }
    m_unk18 = nCols;
    m_unk1C = nWidth;
    m_unk20 = nHeight;
    m_unkC = __nwa__FUi(m_unk14 * m_unk18 * 0x30);
    if (m_unkC == 0) {
        CdsAssert__FPciPc("PSlideShow.cpp", 0x4E, "mpImage1Tiles");
    }
    InitTiles((tagTile *)m_unkC);
    m_unk10 = __nwa__FUi(m_unk14 * m_unk18 * 0x30);
    if (m_unk10 == 0) {
        CdsAssert__FPciPc("PSlideShow.cpp", 0x52, "mpImage2Tiles");
    }
    InitTiles((tagTile *)m_unk10);
    m_unk24 = CreateImagePacket(m_unk2C, (tagTile *)m_unkC);
    m_unk28 = CreateImagePacket(m_unk2C, (tagTile *)m_unk10);
    m_unk3C = (int)(0.5f + (12345.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
    m_unk34 = 0;
    return 1;
}

// FUNCTION: 0x00216410 __dt__10PSlideShowFv
PSlideShow::~PSlideShow()
{
    if (m_unkC != 0) {
        __dla__FPv(m_unkC);
        m_unkC = 0;
    }
    if (m_unk10 != 0) {
        __dla__FPv(m_unk10);
        m_unk10 = 0;
    }
    if (m_unk24 != 0) {
        __dla__FPv(m_unk24);
        m_unk24 = 0;
    }
    if (m_unk28 != 0) {
        __dla__FPv(m_unk28);
        m_unk28 = 0;
    }
}

// FUNCTION: 0x002164C0 __ct__10PSlideShowFv
PSlideShow::PSlideShow()
{
    m_unk04 = 0;
    m_nNextImage = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
    m_ucUnk40 = 0;
    m_ucUnk42 = 0;
}
