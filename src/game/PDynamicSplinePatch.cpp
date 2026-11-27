// COMPILER: mwcps2-3.0-011126
#include "types.h"
#include "Debug.h"
#include "PDynamicSplinePatch.h"
#include "PGfxEngine.h"

// TODO(header): foreign declarations
extern "C" void sceVu0InterVectorXYZ(float *, float *, float *, float);
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void __dl__FPv(void *pData);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void QwordMemset__FP1Ui1(u_long128 *pDst, unsigned int nQwords, u_long128 nValue);
extern "C" void Vu0_Compute_Spline_Tangents(void);
extern "C" void Vu0_Compute_Spline_Patch_Color_ST(void);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" void Vu0_Compute_Spline_Patch_Pos(void);
float FastMath_Sin180(float fAngle);
float FastMath_Cos180(float fAngle);
void FastMath_VectorFabs(float *pDst, float *pSrc);
extern float gfAngleDiff[8];

// A 16-byte .rodata constant as floats; the q member is the quadword copied to the VU0 registers.
union tagLitF4 {
    float f[4];
    u_long128 q;
};
extern char gGfxEng[1504384];
class PMNode;

// FUNCTION: 0x001F3280 InitMatrixCache__19PDynamicSplinePatchFv
void PDynamicSplinePatch::InitMatrixCache() {
    char *pNode = (char *)m_unk1F6C;
    if (pNode != 0) {
        char *pSrc = pNode + 0x40;
        int i = 0;
        int off = 0;
        char *pDst;
        do {
            pDst = (char *)this + off;
            i += 8;
            off += 0x200;
            *(u_long128 *)(pDst + 0x1690) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x16A0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x16B0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x16C0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x16D0) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x16E0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x16F0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1700) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1710) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1720) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1730) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1740) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1750) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1760) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1770) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1780) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1790) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x17A0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x17B0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x17C0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x17D0) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x17E0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x17F0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1800) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1810) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1820) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1830) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1840) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1850) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1860) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1870) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1880) = *(u_long128 *)(pSrc + 0x20);
        } while (i < 0x20);
        i = 0;
        off = 0;
        do {
            pDst = (char *)this + off;
            i += 8;
            off += 0x200;
            *(u_long128 *)(pDst + 0x1210) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1220) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1230) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1240) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1250) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1260) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1270) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1280) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1290) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x12A0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x12B0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x12C0) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x12D0) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x12E0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x12F0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1300) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1310) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1320) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1330) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1340) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1350) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x1360) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x1370) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1380) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x1390) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x13A0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x13B0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x13C0) = *(u_long128 *)(pSrc + 0x30);
            *(u_long128 *)(pDst + 0x13D0) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pDst + 0x13E0) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pDst + 0x13F0) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pDst + 0x1400) = *(u_long128 *)(pSrc + 0x30);
        } while (i < 0x0A);
        while (i < 0x12) {
            char *pRow = (char *)this + (i << 6);
            i += 1;
            *(u_long128 *)(pRow + 0x1210) = *(u_long128 *)(pSrc + 0x00);
            *(u_long128 *)(pRow + 0x1220) = *(u_long128 *)(pSrc + 0x10);
            *(u_long128 *)(pRow + 0x1230) = *(u_long128 *)(pSrc + 0x20);
            *(u_long128 *)(pRow + 0x1240) = *(u_long128 *)(pSrc + 0x30);
        }
    }
}

// FUNCTION: 0x001F3510 GenerateAndRenderVuSplinePatch__19PDynamicSplinePatchFv
void PDynamicSplinePatch::GenerateAndRenderVuSplinePatch() {
    tagLitF4 qCtl;
    float mtx[16];
    float fStepS;
    float fStepT;
    char *pKeyBase;
    char *pRow;
    int i;
    int j;

    sceVu0UnitMatrix(mtx);
    pKeyBase = (char *)0x70001000;
    tagLitF4 qA = {{0.0f, 0.0f, 0.0f, 0.0f}};
    tagLitF4 qB = {{0.0f, 1.0f, 0.0f, 0.0f}};
    tagLitF4 qC = {{0.5f, 0.0f, 0.0f, 0.0f}};
    fStepT = 1.0f / (float)(m_unk00 - 1);
    fStepS = 1.0f / (float)(m_unk08 - 1);
    {
        char *p1 = (char *)this + 0x1FB0;
        char *p2 = (char *)this + 0x1FC0;
        char *pQC = (char *)&qC;
        asm {
            .set noreorder
            lqc2 vf5, 0x0(p1)
            lqc2 vf6, 0x0(p2)
            lqc2 vf9, 0x0(pQC)
            .set reorder
        }
    }
    gGfxEng[0x158E22] = 0;
    ((PGfxEngine *)gGfxEng)->SetMaterial(m_unk1FE0, m_unk2000, m_unk2010, m_unk1FF0, m_unk1FE8);
    ((PGfxEngine *)gGfxEng)->SetWorldMatrix((PMat4 *)mtx);
    ((PGfxEngine *)gGfxEng)->BeginSplinePatch();
    for (i = 0; i < m_unk00; i++) {
        char *pA = (char *)&qA;
        char *pB = (char *)&qB;
        asm {
            .set noreorder
            lqc2 vf7, 0x0(pA)
            lqc2 vf8, 0x0(pB)
            .set reorder
        }
        qCtl.q = 0;
        j = 0;
        char *pCtl = (char *)&qCtl;
        pRow = (char *)this + i * 0x120;
        for (; j < m_unk04 - 2; j++) {
            if (j <= m_unk08 - 1) {
                char *pSrc = pRow + (j << 4) + 0x10;
                asm {
                    .set noreorder
                    lqc2 vf1, 0x0(pSrc)
                    lqc2 vf2, 0x10(pSrc)
                    lqc2 vf3, 0x20(pSrc)
                    lqc2 vf4, 0x30(pSrc)
                    lqc2 vf10, 0x0(pCtl)
                    vcallms Vu0_Compute_Spline_Tangents
                    .set reorder
                }
            }
            {
                *(u_long128 *)(pKeyBase + j * 0x50) = *(u_long128 *)(pRow + (j + 1) * 0x10 + 0x10);
                char *pKey = pKeyBase + j * 0x50;
                qCtl.f[0] += fStepS;
                asm {
                    .set noreorder
                    qmtc2.i v0, vf0
                    vcallms Vu0_Compute_Spline_Patch_Color_ST
                    sqc2 vf28, 0x30(pKey)
                    sqc2 vf29, 0x40(pKey)
                    qmtc2.i v0, vf0
                    sqc2 vf30, 0x10(pKey)
                    sqc2 vf31, 0x20(pKey)
                    .set reorder
                }
            }
        }
        ((PGfxEngine *)gGfxEng)->DrawSplinePatch((struct tagVuSplinePatchKey *)pKeyBase, m_unk08, m_unk0C + 1, 1.0f / (float)m_unk0C, true);
        qA.f[0] += fStepT;
        qB.f[0] = qA.f[0];
    }
    gGfxEng[0x158E22] = 1;
}

// DRAFT: 0x001F3770 ApplyControlMatrices__19PDynamicSplinePatchFv
// note: 128 words differ; needs global_optimizer off to stop hoisting (registers then match), original keeps nop-free assert delay slot (full scheduling); tried opt_common_subs/strength_reduction/lifetimes off, typed members, local base pointers.
#pragma global_optimizer off
void PDynamicSplinePatch::ApplyControlMatrices() {
    if (m_unk1F6C == 0) {
        CdsAssert("PDynamicSplinePatch.cpp", 0x132, "mpoControlNode");
    }
    char *pBase = (char *)this;
    int nIdx;
    char *pT = (char *)m_unk1F6C + 0x40;
    float *pNode = (float *)(pT + 0x30);
    int i;
    for (i = 0; i < m_unk04; i++) {
        nIdx = m_unk1F68 - ((int *)(pBase + 0x1F20))[i] - 1;
        if (nIdx < 0) {
            nIdx += 0x20;
        }
        if (nIdx >= 0x20) {
            CdsAssert("PDynamicSplinePatch.cpp", 0x140, "aiMatrixIndex < SPLINE_PATCH_MAX_MATRIX_CACHE_SIZE");
        }
        float *pA = (float *)(pBase + i * 0x40 + 0x1210);
        sceVu0InterVectorXYZ(pA, (float *)(pBase + nIdx * 0x40 + 0x1690), pA, ((float *)(pBase + 0x1ED8))[i]);
        float *pB = (float *)(pBase + i * 0x40 + 0x1220);
        sceVu0InterVectorXYZ(pB, (float *)(pBase + nIdx * 0x40 + 0x16A0), pB, ((float *)(pBase + 0x1ED8))[i]);
        float *pC = (float *)(pBase + i * 0x40 + 0x1230);
        sceVu0InterVectorXYZ(pC, (float *)(pBase + nIdx * 0x40 + 0x16B0), pC, ((float *)(pBase + 0x1ED8))[i]);
        float *pD = (float *)(pBase + i * 0x40 + 0x1240);
        sceVu0InterVectorXYZ(pD, pNode, pD, ((float *)(pBase + 0x1E90))[i]);
    }
    for (i = 1; i < m_unk04 - 1; i++) {
        u_long128 *pMat = (u_long128 *)(pBase + i * 0x40 + 0x1210);
        asm {
            lqc2 vf1, 0x0(pMat)
            lqc2 vf2, 0x10(pMat)
            lqc2 vf3, 0x20(pMat)
            lqc2 vf4, 0x30(pMat)
        }
        int j;
        for (j = 0; j < m_unk00; j++) {
            u_long128 *pRow = (u_long128 *)(pBase + j * 0x120) + 1;
            u_long128 *pVec = pRow + i;
            asm {
                lqc2 vf5, 0x0(pVec)
                vmulax.xyz ACC, vf1, vf5x
                vmadday.xyz ACC, vf2, vf5y
                vmaddaz.xyz ACC, vf3, vf5z
                vmaddw.xyz vf5, vf4, vf0w
                vnop
                vnop
                vnop
                sqc2 vf5, 0x0(pVec)
            }
            pRow[0] = pRow[1];
            pRow[m_unk04 - 1] = pRow[m_unk04 - 2];
        }
    }
}

#pragma global_optimizer on
// DRAFT: 0x001F39C0 InitSplineKeys__19PDynamicSplinePatchFPfPf
// note: 5 words differ: the original's `= 1.0f` store address carries an extra `addiu v1,v1,0` between the row and column terms (this+0x1C+row*288+0+col*16); typed m_unk10[r].m_pt[c][3], PSplinePatchRow casts, offsetof-style and `+ 0` spellings fold it or CSE the slot address.
void PDynamicSplinePatch::InitSplineKeys(float *pVecA, float *pVecB) {
    float diff[4];
    float cvec[4];
    float *pM1F80;
    float *pCvec;
    float *pVec;
    float fAngle;
    float fSin;
    float fCos;
    float fInv;
    float fT;
    int nAngIdx;
    int nRow;
    int nCol;
    char *pSlot;
    u_long128 *pDst;
    u_long128 *pRow;

    sceVu0SubVector(diff, pVecB, pVecA);
    FastMath_VectorFabs(diff, diff);
    float scale[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float vec[4];
    scale[0] = diff[0] / (float)(m_unk00 - 1);
    scale[1] = diff[1] / (float)(m_unk00 - 1);
    scale[2] = diff[2] / (float)(m_unk08 - 1);

    m_unk1F70 += m_unk1F74;
    if (m_unk1F70 > 360.0f) {
        m_unk1F70 -= 360.0f;
    }
    fT = 0.0f;
    nAngIdx = 0;
    fAngle = m_unk1F70 + gfAngleDiff[nAngIdx];
    if (fAngle >= 360.0f) {
        fAngle -= 360.0f;
    } else if (fAngle <= 0.0f) {
        fAngle += 360.0f;
    }
    pVec = vec;
    nAngIdx++;
    if (nAngIdx >= 8) {
        nAngIdx = 0;
    }

    sceVu0CopyVector(pVec, pVecA);
    pM1F80 = &m_unk1F80;
    asm {
        .set noreorder
        lqc2 vf12, 0x0(pM1F80)
        .set reorder
    }
    vec[3] = 0.0f;
    fInv = 1.0f / (float)m_unk08;

    for (nRow = 0; nRow < m_unk00;) {
        for (nCol = 1; nCol < m_unk04 - 1; nCol++) {
            fSin = FastMath_Sin180(fAngle - 180.0f);
            fCos = FastMath_Cos180(fAngle - 180.0f);
            cvec[1] = fCos;
            cvec[2] = fT;
            cvec[0] = fSin;
            cvec[3] = fSin;
            pCvec = cvec;
            pVec = vec;
            asm {
                .set noreorder
                lqc2 vf11, 0x0(pCvec)
                lqc2 vf13, 0x0(pVec)
                vcallms Vu0_Compute_Spline_Patch_Pos
                .set reorder
            }
            vec[2] = vec[2] + scale[2];
            fT = (float)(nCol - 1) * fInv;
            fAngle = fAngle + gfAngleDiff[nAngIdx];
            if (fAngle >= 360.0f) {
                fAngle -= 360.0f;
            } else if (fAngle <= 0.0f) {
                fAngle += 360.0f;
            }
            nAngIdx++;
            if (nAngIdx >= 8) {
                nAngIdx = 0;
            }
            pSlot = (char *)this + nRow * 288 + nCol * 16;
            pDst = (u_long128 *)(pSlot + 0x10);
            asm {
                .set noreorder
                qmtc2.i v0, vf0
                sqc2 vf14, 0x0(pDst)
                .set reorder
            }
            if (m_unk1F8C == 0.0f) {
                *(float *)((unsigned int)this + 0x1C + nRow * 288 + nCol * 16) = 1.0f;
            } else if (m_unk1F78) {
                *(float *)(pSlot + 0x1C) = m_unk1F78 + (1.0f - m_unk1F78) * *(float *)(pSlot + 0x1C);
            }
        }
        nAngIdx = 0;
        fT = 0.0f;
        pRow = (u_long128 *)((char *)this + nRow * 288);
        nRow++;
        pRow[1] = pRow[2];
        *(u_long128 *)((unsigned int)pRow + (m_unk04 - 1) * 16 + 0x10) = *(u_long128 *)((unsigned int)pRow + (m_unk04 - 2) * 16 + 0x10);
        vec[0] = vec[0] + scale[0];
        vec[2] = pVecA[2];
    }
}

// FUNCTION: 0x001F3D80 Render__19PDynamicSplinePatchFv
void PDynamicSplinePatch::Render() {
    if (m_unk2011 != 0) {
        GenerateAndRenderVuSplinePatch();
    }
}

// FUNCTION: 0x001F3DB0 Animate__19PDynamicSplinePatchFf
void PDynamicSplinePatch::Animate(float fTime) {
    if (m_unk2011 != 0) {
        InitSplineKeys(m_unk1F90, m_unk1FA0);
        char *pNode = (char *)m_unk1F6C;
        if (pNode != 0) {
            if (m_unk2012 != 0) {
                InitMatrixCache();
                m_unk2012 = 0;
            } else {
                char *pDst = m_unk1690 + (m_unk1F68 << 6);
                *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pNode + 0x40);
                *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pNode + 0x50);
                *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pNode + 0x60);
                *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pNode + 0x70);
            }
            m_unk1F68 = m_unk1F68 + 1;
            if (m_unk1F68 >= 32) {
                m_unk1F68 = 0;
            }
            ApplyControlMatrices();
        }
    }
}

// FUNCTION: 0x001F3E60 SetControlNode__19PDynamicSplinePatchFP6PMNode
void PDynamicSplinePatch::SetControlNode(PMNode *pNode) {
    m_unk1F6C = pNode;
    m_unk1F68 = 0;
    if (m_unk1F6C != 0) {
        char *pSrc = (char *)m_unk1F6C;
        char *pDst = m_unk1690 + (m_unk1F68 << 6);
        *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x40);
        *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x50);
        *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x60);
        *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x70);
        *(u_long128 *)m_unk1FD0 = *(u_long128 *)(pSrc + 0x70);
        m_unk1F68 = m_unk1F68 + 1;
    }
}

// FUNCTION: 0x001F3EC0 Init__19PDynamicSplinePatchFiiiPfPf
int PDynamicSplinePatch::Init(int nA, int nB, int nC, float *pVecA, float *pVecB) {
    // MAX(MIN(n, hi), 2): the original re-evaluates the MIN in the taken arm, as a macro expansion does.
    m_unk00 = (((nA < 16) ? nA : 16) > 2) ? ((nA < 16) ? nA : 16) : 2;
    m_unk08 = (((nB < 16) ? nB : 16) > 2) ? ((nB < 16) ? nB : 16) : 2;
    m_unk04 = m_unk08 + 2;
    m_unk0C = (((nC < 10) ? nC : 10) > 2) ? ((nC < 10) ? nC : 10) : 2;

    sceVu0CopyVector(m_unk1F90, pVecA);
    sceVu0CopyVector(m_unk1FA0, pVecB);
    return 1;
}

// FUNCTION: 0x001F3FE0 __dt__19PDynamicSplinePatchFv
extern "C" void *__dt__19PDynamicSplinePatchFv(PDynamicSplinePatch *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->m_unk1F68 = 0;
        pThis->m_unk1F6C = 0;
        pThis->m_unk1FE0 = 0;
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F4030 __ct__19PDynamicSplinePatchFv
PDynamicSplinePatch::PDynamicSplinePatch() {
    m_unk00 = 0;
    m_unk04 = 0;
    m_unk08 = 0;
    m_unk0C = 0;
    QwordMemset__FP1Ui1((u_long128 *)m_unk10, 0x120, 0);
    QwordMemset__FP1Ui1((u_long128 *)m_unk1690, 0x80, 0);
    memset(m_unk1F20, 0, 0x48);
    m_unk1F68 = 0;
    m_unk1F6C = 0;
    m_unk1FE0 = 0;
    m_unk1FE8 = 0x50000;
    m_unk1FF0 = 0x44;
    m_unk2000[0] = 1.0f;
    m_unk2000[1] = 1.0f;
    m_unk2000[2] = 1.0f;
    m_unk2000[3] = 1.0f;
    m_unk2010 = 0;
    m_unk1F70 = 0;
    m_unk1F74 = 5.0f;
    m_unk1F80 = 0.4f;
    m_unk1F84 = 1.0f;
    m_unk1F88 = 0.4f;
    m_unk1F8C = 0;
    m_unk1FB0[0] = 128.0f;
    m_unk1FB0[1] = 128.0f;
    m_unk1FB0[2] = 128.0f;
    m_unk1FB0[3] = 128.0f;
    m_unk1FB0[4] = 128.0f;
    m_unk1FB0[5] = 128.0f;
    m_unk1FB0[6] = 128.0f;
    m_unk1FB0[7] = 128.0f;
    m_unk2011 = 1;
    m_unk2012 = 0;
    m_unk1F78 = 0;
    int i = 0;
    for (; i < 10; i += 8) {
        m_unk1E90[i + 0] = 1.0f;
        m_unk1ED8[i + 0] = 1.0f;
        m_unk1E90[i + 1] = 1.0f;
        m_unk1ED8[i + 1] = 1.0f;
        m_unk1E90[i + 2] = 1.0f;
        m_unk1ED8[i + 2] = 1.0f;
        m_unk1E90[i + 3] = 1.0f;
        m_unk1ED8[i + 3] = 1.0f;
        m_unk1E90[i + 4] = 1.0f;
        m_unk1ED8[i + 4] = 1.0f;
        m_unk1E90[i + 5] = 1.0f;
        m_unk1ED8[i + 5] = 1.0f;
        m_unk1E90[i + 6] = 1.0f;
        m_unk1ED8[i + 6] = 1.0f;
        m_unk1E90[i + 7] = 1.0f;
        m_unk1ED8[i + 7] = 1.0f;
    }
    for (; i < 18; i++) {
        m_unk1E90[i] = 1.0f;
        m_unk1ED8[i] = 1.0f;
    }
}
