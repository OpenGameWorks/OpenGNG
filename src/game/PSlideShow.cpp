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
// note: VU0 block and the m_unkC store match; the flag updates differ (8 lines, 0x54..0x70). Ours uses `ori imm` and `or`; the original keeps 0x80 in $a3 via daddiu. Tried: int flag, unsigned pair (best), long pair (worse), signed mask (worse).
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
