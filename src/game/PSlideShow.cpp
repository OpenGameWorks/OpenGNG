#include "types.h"
#include "PSlideShow.h"

// TODO(header): foreign declarations
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);

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
