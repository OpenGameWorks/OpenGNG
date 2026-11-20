// FLAGS: -sdatathreshold 0
#include "BGCollision.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *);
extern float vUp_1253[4];
extern float vGDown[4];
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" float sceVu0InnerProduct(float *, float *);
extern "C" float sqrtf(float);
extern "C" void sceVu0ScaleVectorXYZ(float *, float *, float);
extern "C" void sceVu0AddVector(float *, float *, float *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
float FastMath_Fabs(float f);
float Fabs(float f);
struct STCollisionPoly;
int BoxLineCheck(float (*pBox)[2][4]);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern "C" void sceVu0InversMatrix(float *, float *);
void InversMatrix(float (*)[4][4], float (*)[4][4]);

// DRAFT: 0x0016C8A0 CheckCeiling__11BGCollisionFPA4_f
// note: only the two lui/addiu words differ; the reloc target is vUp$1253, which C++ cannot name (vUp_1253 emitted).
int BGCollision::CheckCeiling(float (*pVec)[4])
{
    return CheckIntersectAnim(pVec, &vUp_1253, 0, 0x40) != 0;
}

// DRAFT: 0x0016EDA0 BGDetection__11BGCollisionFPA2_A4_fP5PMat4fR11SurfaceInfoiP9PMeshNode
// note: 1 differing line: fLen compare at 0x24 emits c.eq.s f0,f12 (original f12,f0); tried !(fLen==0), 0.0f!=fLen, empty-then, all same.
void BGCollision::BGDetection(float (*pArr)[2][4], PMat4 *pMat, float fLen, SurfaceInfo &rSurf, int nFlag, PMeshNode *pMesh)
{
    char *pS = (char *)&rSurf;
    *(u_long128 *)(pS + 0x10) = *(u_long128 *)((char *)pMat + 0x30);
    *(int *)(pS + 0x20) = 0;
    *(int *)(pS + 0x48) = 0;
    *(int *)(pS + 0x44) = 0;
    *(float *)(pS + 0x14) = -1000.0f;
    *(float *)(pS + 0x24) = -1000.0f;
    *(float *)(pS + 0x28) = 1000.0f;
    *(int *)(pS + 0x2C) = 0;
    *(int *)(pS + 0x40) = 0;
    if (fLen != 0.0f) {
        float t = 0.5f * fLen;
        pArr[0][0][1] -= t;
        pArr[0][1][1] += FastMath_Fabs(t);
    }
    BGDetectionST(pArr, pMat, &rSurf, nFlag);
    BGDetectionAnim(pArr, pMat, &rSurf, nFlag, pMesh);
    float f1 = *(float *)(pS + 0x28);
    if (1000.0f == f1 || f1 < *(float *)(pS + 0x14)) {
        *(float *)(pS + 0x28) = -1000.0f;
    } else if (!(*(float *)(pS + 0x24) <= f1)) {
        *(float *)(pS + 0x24) = -1000.0f;
    }
    if (*(float *)(pS + 0x24) < *(float *)(pS + 0x14)) {
        *(int *)(pS + 0x48) &= 0xFFEEFFFE;
        *(float *)(pS + 0x24) = -1000.0f;
    }
}

// FUNCTION: 0x0016F340 FindGroundPos__FP15STCollisionPolyPA4_f
int FindGroundPos(STCollisionPoly *pPoly, float (*pOut)[4])
{
    asm {
        .set noreorder
        lw v1, 0x0(a0)
        lqc2 vf3, 0x10(a0)
        lqc2 vf4, 0x0(v1)
        vmul.xyz vf9, vf27, vf3
        lw v1, 0x4(a0)
        vsub.xyz vf7, vf26, vf4
        vmul.xyz vf8, vf7, vf3
        vaddy.x vf9, vf9, vf9y
        vaddz.x vf9, vf9, vf9z
        vaddy.x vf8, vf8, vf8y
        vaddz.x vf8, vf8, vf8z
        vdiv Q, vf8x, vf9x
        lqc2 vf5, 0x0(v1)
        lw v1, 0x8(a0)
        lqc2 vf6, 0x0(v1)
        vsub.xyz vf5, vf5, vf4
        vsub.xyz vf6, vf6, vf4
        vwaitq
        vmulq.xyz vf8, vf27, Q
        vsub.xyz vf7, vf7, vf8
        vmul.xyz vf9, vf6, vf6
        vmul.xyz vf13, vf5, vf5
        vaddy.x vf9, vf9, vf9y
        vaddz.x vf9, vf9, vf9z
        vaddy.x vf13, vf13, vf13y
        vaddz.x vf13, vf13, vf13z
        vmax.x vf3, vf9, vf13
        vrsqrt Q, vf5w, vf3x
        lui v1, 0xB3D6
        ori v1, v1, 0xBF95
        mtc1 v1, f1
        vwaitq
        vmulq.xyz vf5, vf5, Q
        vmulq.xyz vf6, vf6, Q
        vmulq.xyz vf7, vf7, Q
        vmul.xyz vf8, vf5, vf6
        vmul.xyz vf9, vf6, vf6
        vmul.xyz vf10, vf5, vf7
        vmul.xyz vf11, vf6, vf7
        vaddy.x vf8, vf8, vf8y
        vaddz.x vf8, vf8, vf8z
        vaddy.x vf9, vf9, vf9y
        vaddz.x vf9, vf9, vf9z
        vaddy.x vf10, vf10, vf10y
        vaddz.x vf10, vf10, vf10z
        vaddy.x vf11, vf11, vf11y
        vaddz.x vf11, vf11, vf11z
        vmula.x ACC, vf9, vf10
        vmsub.x vf12, vf8, vf11
        qmfc2.ni v1, vf12
        mtc1 v1, f0
        paddub v0, zero, zero
        c.lt.s f0, f1
        bc1tl fgp_ret
        nop
        vmul.xyz vf13, vf5, vf5
        vaddy.x vf13, vf13, vf13y
        vaddz.x vf13, vf13, vf13z
        vmula.x ACC, vf13, vf11
        vmsub.x vf14, vf8, vf10
        qmfc2.ni v1, vf14
        mtc1 v1, f0
        c.lt.s f0, f1
        bc1tl fgp_ret
        nop
        vaddx.x vf12, vf12, vf14x
        vmula.x ACC, vf13, vf9
        vmsub.x vf13, vf8, vf8
        vabs.x vf13, vf13
        vsub.x vf10, vf13, vf12
        qmfc2.ni v1, vf10
        mtc1 v1, f0
        c.lt.s f0, f1
        bc1tl fgp_ret
        nop
        .word 0x4A0303BD
        addi v0, zero, 0x1
        vwaitq
        vmulq.xyz vf7, vf7, Q
        vadd.xyzw vf7, vf7, vf4
        vmove.w vf7, vf0
        sqc2 vf7, 0x0(a1)
    fgp_ret:
        jr ra
        nop
    }
}

// DRAFT: 0x0016F490 GetGround__11BGCollisionFPA4_fUi
// note: 109 differing lines. vf26/vf27 loads in asm (vGDown via C pointer; asm symbol form rejected); frame 0xC0 vs 0x90 (loop n/pp kept in s-regs across the FindGroundPos call), sqrt.s/c1 hit-scale path and d[] vGDown load absent.
int BGCollision::GetGround(float (*pArr)[4], unsigned int nFlags)
{
    float fBest = -1000.0f;
    unsigned int nRet = 0;
    float out[4];
    float d[4];
    int nX;
    int nZ;
    if (m_unk40 != 0 && FindGrid(pArr, nX, nZ) != 0) {
        int *pBlk = *(int **)((char *)m_unk40 + nX * 4 + nZ * m_unk38 * 4);
        if (pBlk != 0) {
            float *pG = vGDown;
            asm {
                lqc2 vf26, 0x0(pArr)
                lqc2 vf27, 0x0(pG)
            }
            int n = pBlk[2];
            STCollisionPoly **pp = (STCollisionPoly **)(pBlk + 3);
            while (n != 0) {
                STCollisionPoly *pPoly = *pp;
                if ((*(unsigned int *)((char *)pPoly + 0xC) & nFlags) &&
                    !(*(float *)((char *)pPoly + 0x14) <= 0.0f) &&
                    FindGroundPos(pPoly, (float (*)[4])out) != 0 &&
                    out[1] <= pArr[0][1] && !(out[1] <= fBest)) {
                    nRet = *(unsigned int *)((char *)pPoly + 0xC);
                    fBest = out[1];
                }
                n--;
                pp++;
            }
        }
    }
    d[0] = 0.0f;
    d[1] = fBest - pArr[0][1];
    d[2] = 0.0f;
    d[3] = 0.0f;
    float inner = sceVu0InnerProduct(d, d);
    float slot = inner;
    STCollisionPoly *hit = FindIntersectAnim(pArr, (float (*)[4])d, slot, nFlags, 0);
    if (hit != 0) {
        nRet = *(unsigned int *)((char *)hit + 0xC);
        sceVu0ScaleVectorXYZ(d, d, sqrtf(slot) / sqrtf(inner));
    }
    pArr[0][1] += d[1];
    return nRet;
}

struct BGAnimObj {
    char _pad00[0x4];
    unsigned int m_unk4;        // 0x004 type id, 0x207 selects a node
};

struct BGAnimNode {
    char _pad00[0x24];
    BGAnimObj *m_unk24;         // 0x024 object, type id at +4
    char _pad28[0x4];
    float m_unk2C;              // 0x02C compared with 0.5f
    char _pad30[0xE];
    unsigned char m_unk3E;      // 0x03E flags, bit 2 selects InversMatrix
    char _pad3F[0x1];
    float m_unk40[4][4];        // 0x040 matrix inverted into the local copy
    char _pad80[0x80];
    unsigned short m_unk100;    // 0x100 must be zero when bit 30 is set
    char _pad102[0x2];
    void *m_unk104;             // 0x104 collision map
    char _pad108[0x8];
    float m_unk110[2][4];       // 0x110 box
};

struct BGAnimMap {
    char _pad00[0x8];
    unsigned int m_unk8;        // 0x008 polygon count
    STCollisionPoly *m_unkC[1]; // 0x00C polygon pointers
};

// DRAFT: 0x0016F690 FindIntersectAnim__11BGCollisionFPA4_fPA4_fRfUiPA4_f
// note: 163 words differ (size 0x2e4 vs 0x304): frame 0x140 vs 0x150, pB/rT spill slots, entry branch, and the VU0 lqc2 pair before BoxLineCheck (not expressible in C); tried while and for loop shapes, and (void)&pB, all 163
STCollisionPoly *BGCollision::FindIntersectAnim(float (*pA)[4], float (*pB)[4], float &rT, unsigned int nFlags, float (*pOut)[4])
{
    float mat[4][4];
    float vA[4];
    float vB[4];
    float vG[4];
    float vD[4];
    STCollisionPoly *pRet = 0;
    float f20 = 1.0f;
    float f21;

    m_unk70.m_unk4 = 0;
    BGAnimNode *pNode = (m_unk70.m_unk0 != 0) ? (BGAnimNode *)m_unk70.m_unk8[0] : 0;
    while (pNode != 0) {
        if (!(pNode->m_unk2C < 0.5f) && !(pNode->m_unk3E & 0x20)) {
            BGAnimObj *pObj = pNode->m_unk24;
            unsigned int nType = (pObj != 0) ? pObj->m_unk4 : 0;
            if (nType == 0x207) {
                if (pNode->m_unk104 == 0) {
                    CdsAssert__FPciPc("BGCollision.cpp", 0x2DB, "pNode->GetCollisionMap()");
                }
                if (!(nFlags & 0x40000000) || pNode->m_unk100 == 0) {
                    if (pNode->m_unk3E & 4) {
                        InversMatrix(&mat, &pNode->m_unk40);
                    } else {
                        sceVu0InversMatrix((float *)mat, (float *)pNode->m_unk40);
                    }
                    sceVu0ApplyMatrix(vA, (float *)mat, (float *)pA);
                    sceVu0ApplyMatrix(vB, (float *)mat, (float *)pB);
                    if (BoxLineCheck(&pNode->m_unk110)) {
                        f21 = f20 * sceVu0InnerProduct(vB, vB);
                        BGAnimMap *pMap = (BGAnimMap *)pNode->m_unk104;
                        unsigned int n = pMap->m_unk8;
                        STCollisionPoly **pp = pMap->m_unkC;
                        for (; n != 0; --n, ++pp) {
                            STCollisionPoly *pPoly = *pp;
                            unsigned int s3 = *(unsigned int *)((char *)pPoly + 0xC) & nFlags;
                            if (s3 != 0 && FindGroundPos(pPoly, (float (*)[4])vG) != 0) {
                                sceVu0SubVector(vD, vG, vA);
                                if (!(sceVu0InnerProduct(vD, vB) < 0.0f)) {
                                    float f0 = sceVu0InnerProduct(vD, vD);
                                    if (!(f0 <= 1.0f) && f0 < f21) {
                                        f20 = f0 / f21;
                                        pRet = pPoly;
                                        if (pOut != 0) {
                                            sceVu0ApplyMatrix((float *)pOut, (float *)mat, (float *)((char *)pPoly + 0x10));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        unsigned int nIdx = m_unk70.m_unk4 + 1;
        m_unk70.m_unk4 = nIdx;
        pNode = (nIdx < m_unk70.m_unk0) ? (BGAnimNode *)m_unk70.m_unk8[nIdx] : 0;
    }
    if (pRet != 0) {
        rT *= f20;
    }
    return pRet;
}

// DRAFT: 0x0016F9A0 FindIntersectST__11BGCollisionFiiPA4_fPA4_fRfUi
// note: 101 differing lines. vf26/vf27 asm loads before BoxLineCheck tried, count unchanged; prologue saves and s-reg set differ.
STCollisionPoly *BGCollision::FindIntersectST(int nX, int nZ, float (*pA)[4], float (*pB)[4], float &rT, unsigned int nFlags)
{
    STCollisionPoly *pRet = 0;
    if ((unsigned int)nX < m_unk38 && (unsigned int)nZ < m_unk3C) {
        int *pBlk = *(int **)((char *)m_unk40 + nX * 4 + nZ * m_unk38 * 4);
        if (pBlk != 0) {
            *(float *)((char *)this + 0x54) = *(float *)pBlk;
            *(float *)((char *)this + 0x64) = *((float *)pBlk + 1);
            if (BoxLineCheck((float (*)[2][4])((char *)this + 0x50))) {
                int n = pBlk[2];
                STCollisionPoly **pp = (STCollisionPoly **)(pBlk + 3);
                while (n != 0) {
                    STCollisionPoly *pPoly = *pp;
                    if (*(unsigned int *)((char *)pPoly + 0xC) & nFlags) {
                        if (sceVu0InnerProduct((float *)pB, (float *)((char *)pPoly + 0x10)) < 0.0f) {
                            float out[4];
                            float diff[4];
                            if (FindGroundPos(pPoly, (float (*)[4])out) != 0) {
                                sceVu0SubVector(diff, out, (float *)pA);
                                if (!(sceVu0InnerProduct(diff, (float *)pB) < 0.0f)) {
                                    float fd = sceVu0InnerProduct(diff, diff);
                                    if (fd > 1.0f && fd < rT) {
                                        rT = fd;
                                        pRet = pPoly;
                                    }
                                }
                            }
                        }
                    }
                    n--;
                    pp++;
                }
            }
        }
    }
    return pRet;
}

// DRAFT: 0x0016FB60 FindIntersect__11BGCollisionFR5PVec3R5PVec3UiPA4_f
// note: DIFF 149; prologue saves and nRet=0 placement (hoisted, DIFF 173 when moved before m_unk40) still differ; pF/pT locals replaced by reference casts (152 to 149)
int BGCollision::FindIntersect(PVec3 &rFrom, PVec3 &rTo, unsigned int nFlags, float (*pOut)[4])
{
    float diff[4];
    float fT;
    int x0, z0, x1, z1;
    int nRet = 0;
    ((float *)&rTo)[3] = 1.0f;
    ((float *)&rFrom)[3] = 1.0f;
    sceVu0SubVector(diff, ((float *)&rTo), ((float *)&rFrom));
    float fLen = sceVu0InnerProduct(diff, diff);
    fT = fLen;
    if (fLen > 10000.0f) {
        sceVu0ScaleVector(diff, diff, 100.0f / sqrtf(fLen));
        sceVu0AddVector(((float *)&rTo), ((float *)&rFrom), diff);
        fT = 10000.0f;
    }
    if (m_unk40 != 0) {
        FindGrid((float (*)[4])((float *)&rFrom), x0, z0);
        m_unk50 = m_unk0 + ((float)x0 + 0.5f) * m_unk30;
        m_unk58 = m_unk8 + ((float)z0 + 0.5f) * m_unk34;
        FindGrid((float (*)[4])((float *)&rTo), x1, z1);
        bool bFlag = !(Fabs(diff[0]) < Fabs(diff[2]));
        for (;;) {
            STCollisionPoly *pPoly = FindIntersectST(x0, z0, (float (*)[4])((float *)&rFrom), (float (*)[4])diff, fT, nFlags);
            if (pPoly != 0) {
                nRet = 1;
                sceVu0ScaleVectorXYZ(diff, diff, fT / sqrtf(fT));
                sceVu0AddVector(((float *)&rTo), ((float *)&rFrom), diff);
                if (pOut != 0) {
                    *(u_long128 *)pOut = *(u_long128 *)((char *)pPoly + 0x10);
                }
                break;
            }
            int dx = x1 - x0;
            int dz = z1 - z0;
            if (dx == 0 && dz == 0) {
                break;
            }
            FindNextGrid(x0, z0, dx, dz, (float (*)[4])((float *)&rFrom), (float (*)[4])diff, bFlag);
        }
    }
    if (FindIntersectAnim((float (*)[4])((float *)&rFrom), (float (*)[4])diff, fT, nFlags, pOut)) {
        sceVu0ScaleVectorXYZ(diff, diff, fT / sqrtf(fT));
        sceVu0AddVector(((float *)&rTo), ((float *)&rFrom), diff);
        return 1;
    }
    return nRet;
}

// FUNCTION: 0x0016FE70 FindNextGrid__11BGCollisionFRiRiiiPA4_fPA4_fb
void BGCollision::FindNextGrid(int &rX, int &rZ, int nDX, int nDZ, float (*pA)[4], float (*pB)[4], bool bFlag)
{
    float tmp[4];
    float fX0 = m_unk0 + (float)rX * m_unk30;
    float fZ0 = m_unk8 + (float)rZ * m_unk34;
    float fX;
    float fZ;

    if (bFlag) {
        fX = (pB[0][0] < 0.0f) ? fX0 : fX0 + m_unk30;
        sceVu0ScaleVector(tmp, (float *)pB, (fX - pA[0][0]) / pB[0][0]);
        sceVu0AddVector(tmp, (float *)pA, tmp);
        tmp[0] = fX;
        if (tmp[2] < fZ0 || tmp[2] > fZ0 + m_unk34) {
            fZ = (pB[0][2] < 0.0f) ? fZ0 : fZ0 + m_unk34;
            sceVu0ScaleVector(tmp, (float *)pB, (fZ - pA[0][2]) / pB[0][2]);
            sceVu0AddVector(tmp, (float *)pA, tmp);
            tmp[2] = fZ;
        }
    } else {
        fZ = (pB[0][2] < 0.0f) ? fZ0 : fZ0 + m_unk34;
        sceVu0ScaleVector(tmp, (float *)pB, (fZ - pA[0][2]) / pB[0][2]);
        sceVu0AddVector(tmp, (float *)pA, tmp);
        tmp[2] = fZ;
        if (tmp[0] < fX0 || tmp[0] > fX0 + m_unk30) {
            fX = (pB[0][0] < 0.0f) ? fX0 : fX0 + m_unk30;
            sceVu0ScaleVector(tmp, (float *)pB, (fX - pA[0][0]) / pB[0][0]);
            sceVu0AddVector(tmp, (float *)pA, tmp);
            tmp[0] = fX;
        }
    }

    if (nDX != 0) {
        if (tmp[0] <= fX0) {
            rX--;
            m_unk50 -= m_unk30;
        } else if (tmp[0] >= fX0 + m_unk30) {
            rX++;
            m_unk50 += m_unk30;
        }
    }
    if (nDZ != 0) {
        if (tmp[2] <= fZ0) {
            rZ--;
            m_unk58 -= m_unk34;
        } else if (tmp[2] >= fZ0 + m_unk34) {
            rZ++;
            m_unk58 += m_unk34;
        }
    }
}

// FUNCTION: 0x001701E0 FindGrid__11BGCollisionFPA4_fRiRi
int BGCollision::FindGrid(float (*pArr)[4], int &rX, int &rZ)
{
    float diff[4];
    sceVu0SubVector(diff, pArr[0], (float *)this);
    rX = (int)(diff[0] / m_unk30);
    if (!(m_unk0 + (float)rX * m_unk30 <= pArr[0][0])) {
        rX--;
    }
    rZ = (int)(diff[2] / m_unk34);
    if (!(m_unk8 + (float)rZ * m_unk34 <= pArr[0][2])) {
        rZ--;
    }
    int ok = (unsigned int)rX < m_unk38;
    if (ok) {
        ok = (unsigned int)rZ < m_unk3C;
    }
    return ok;
}

// DRAFT: 0x00170300 CheckIntersectAnim__11BGCollisionFPA4_fPA4_fPA4_fUi
// note: 2 lqc2 VU loads before BoxLineCheck are not expressible in C; test
int BGCollision::CheckIntersectAnim(float (*pA)[4], float (*pB)[4], float (*pC)[4], unsigned int nFlags)
{
    float mat[4][4];
    float vA[4];
    float vB[4];
    float vC[4];
    float vG[4];
    float vD[4];
    float f20;

    m_unk70.m_unk4 = 0;
    BGAnimNode *pNode = (m_unk70.m_unk0 != 0) ? (BGAnimNode *)m_unk70.m_unk8[0] : 0;
    while (pNode != 0) {
        if (pNode->m_unk104 == 0) {
            CdsAssert__FPciPc("BGCollision.cpp", 0x1C4, "pNode->GetCollisionMap()");
        }
        if (pNode->m_unk3E & 4) {
            InversMatrix(&mat, &pNode->m_unk40);
        } else {
            sceVu0InversMatrix((float *)mat, (float *)pNode->m_unk40);
        }
        sceVu0ApplyMatrix(vA, (float *)mat, (float *)pA);
        sceVu0ApplyMatrix(vB, (float *)mat, (float *)pB);
        if (pC != 0) {
            sceVu0ApplyMatrix(vC, (float *)mat, (float *)pC);
        }
        if (BoxLineCheck(&pNode->m_unk110)) {
            f20 = sceVu0InnerProduct(vB, vB);
            BGAnimMap *pMap = (BGAnimMap *)pNode->m_unk104;
            unsigned int n = pMap->m_unk8;
            STCollisionPoly **pp = pMap->m_unkC;
            for (; n != 0; --n, ++pp) {
                STCollisionPoly *pPoly = *pp;
                unsigned int s3 = *(unsigned int *)((char *)pPoly + 0xC) & nFlags;
                if (s3 != 0 && !(s3 & 0x20) &&
                    (pC == 0 || sceVu0InnerProduct(vC, (float *)((char *)pPoly + 0x10)) <= -0.5f) &&
                    FindGroundPos(pPoly, (float (*)[4])vG) != 0) {
                    sceVu0SubVector(vD, vG, vA);
                    if (!(sceVu0InnerProduct(vB, vD) < 0.0f)) {
                        float f0 = sceVu0InnerProduct(vD, vD);
                        if (!(f0 <= 1.0f) && f0 < f20) {
                            return (int)s3;
                        }
                    }
                }
            }
        }
        unsigned int nIdx = m_unk70.m_unk4 + 1;
        m_unk70.m_unk4 = nIdx;
        pNode = (nIdx < m_unk70.m_unk0) ? (BGAnimNode *)m_unk70.m_unk8[nIdx] : 0;
    }
    return 0;
}

// DRAFT: 0x00170580 CheckIntersectST__11BGCollisionFiiPA4_fPA4_fPA4_fUi
// note: 112 differing lines. vf26/vf27 loads in asm before BoxLineCheck (was 114); frame 0x90 and saved s-regs differ (BoxLineCheck clobber set unknown to the compiler).
int BGCollision::CheckIntersectST(int nX, int nZ, float (*pA)[4], float (*pB)[4], float (*pC)[4], unsigned int nFlags)
{
    if ((unsigned int)nX >= m_unk38 || (unsigned int)nZ >= m_unk3C) {
        return 0;
    }
    int *pBlk = *(int **)((char *)m_unk40 + nX * 4 + nZ * m_unk38 * 4);
    if (pBlk == 0) {
        return 0;
    }
    *(float *)((char *)this + 0x54) = *(float *)pBlk;
    *(float *)((char *)this + 0x64) = *((float *)pBlk + 1);
    asm {
        lqc2 vf26, 0x0(pA)
        lqc2 vf27, 0x0(pB)
    }
    if (!BoxLineCheck((float (*)[2][4])((char *)this + 0x50))) {
        return 0;
    }
    float fLenSq = sceVu0InnerProduct((float *)pB, (float *)pB);
    int n = pBlk[2];
    STCollisionPoly **pp = (STCollisionPoly **)(pBlk + 3);
    while (n != 0) {
        STCollisionPoly *pPoly = *pp;
        unsigned int nPolyFlags = *(unsigned int *)((char *)pPoly + 0xC) & nFlags;
        if (nPolyFlags != 0 && (nPolyFlags & 0x20) == 0) {
            if (pC == 0 || sceVu0InnerProduct((float *)pC, (float *)((char *)pPoly + 0x10)) <= -0.5f) {
                float out[4];
                float diff[4];
                if (FindGroundPos(pPoly, (float (*)[4])out) != 0) {
                    sceVu0SubVector(diff, out, (float *)pA);
                    if (!(sceVu0InnerProduct((float *)pB, diff) < 0.0f)) {
                        float fd = sceVu0InnerProduct(diff, diff);
                        if (fd > 1.0f && fd < fLenSq) {
                            return nPolyFlags;
                        }
                    }
                }
            }
        }
        n--;
        pp++;
    }
    return 0;
}

// FUNCTION: 0x00170760 CheckIntersect__11BGCollisionFRA4_fRA4_fPA4_fUi
int BGCollision::CheckIntersect(float (&pA)[4], float (&pB)[4], float (*pC)[4], unsigned int nFlags)
{
    float diff[4];
    int nX0;
    int nZ0;
    int nX1;
    int nZ1;
    int dx;
    int dz;
    int ret;
    bool bFlag;

    sceVu0SubVector(diff, pB, pA);
    diff[3] = 0.0f;
    ret = 0;
    if (m_unk40 != 0) {
        FindGrid(&pA, nX0, nZ0);
        m_unk50 = m_unk0 + (0.5f + (float)nX0) * m_unk30;
        m_unk58 = m_unk8 + (0.5f + (float)nZ0) * m_unk34;
        FindGrid(&pB, nX1, nZ1);
        float fA = Fabs(diff[0]);
        bFlag = fA >= Fabs(diff[2]);
        for (;;) {
            ret = CheckIntersectST(nX0, nZ0, &pA, (float (*)[4])&diff, pC, nFlags);
            if (ret != 0) {
                break;
            }
            dx = nX1 - nX0;
            dz = nZ1 - nZ0;
            if (dx != 0 || dz != 0) {
                FindNextGrid(nX0, nZ0, dx, dz, &pA, (float (*)[4])&diff, bFlag);
            } else {
                break;
            }
        }
    }
    if (ret == 0) {
        ret = CheckIntersectAnim(&pA, (float (*)[4])&diff, pC, nFlags);
    }
    return ret;
}

// FUNCTION: 0x00170910 BoxLineCheck__FPA2_A4_f
int BoxLineCheck(float (*pBox)[2][4])
{
    asm {
        .set noreorder
        lqc2 vf3, 0x0(a0)
        lqc2 vf8, 0x10(a0)
        vmove.xyzw vf4, vf27
        lui v0, 0x3F00
        qmtc2.ni v0, vf1
        vmulx.xyz vf4, vf4, vf1x
        vadd.xyz vf1, vf4, vf26
        vsub.xyz vf1, vf1, vf3
        vabs.xyz vf2, vf1
        vabs.xyz vf9, vf4
        vadd.xyz vf9, vf9, vf8
        vsub.xyz vf9, vf9, vf2
        qmfc2.ni t0, vf9
        pcgtw t0, zero, t0
        bnez t0, box_ret
        addi v0, zero, 0x0
        prot3w t0, t0
        bnez t0, box_ret
        vsub.xyz vf3, vf26, vf3
        vopmula.xyz ACC, vf4, vf3
        vopmsub.xyz vf3, vf3, vf4
        vabs.xyz vf6, vf4
        vabs.xyz vf7, vf3
        vopmula.xyz ACC, vf8, vf6
        vsub.xyz vf9, vf0, vf6
        vopmsub.xyz vf6, vf9, vf8
        vsub.xyz vf9, vf7, vf6
        qmfc2.ni t0, vf9
        pcgtw v0, zero, t0
        bnez v0, box_ret
        nop
        prot3w v0, v0
    box_ret:
        jr ra
        nop
    }
}

// FUNCTION: 0x001709A0 GetGroundPos__11BGCollisionFPA4_f
int BGCollision::GetGroundPos(float (*pPos)[4])
{
    float from[4];
    float to[4];

    pPos[0][3] = 1.0f;
    *(u_long128 *)to = *(u_long128 *)pPos[0];
    to[1] -= 100.0f;
    *(u_long128 *)from = *(u_long128 *)pPos[0];
    if (FindIntersect((PVec3 &)from, (PVec3 &)to, 0x40, 0) != 0) {
        *(u_long128 *)pPos[0] = *(u_long128 *)to;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00170DD0 Destroy__11BGCollisionFv
void BGCollision::Destroy()
{
    void *p = m_unk4C;
    if (p != 0) {
        __dl__FPv(p);
        m_unk4C = 0;
        m_unk40 = 0;
    }
    if (m_unk70.m_unk8 != 0) {
        m_unk70.m_unk0 = 0;
        m_unk70.m_unk4 = 0;
    }
}

// FUNCTION: 0x00170E20 __ct__11BGCollisionFv
BGCollision::BGCollision()
{
    m_unk4C = 0;
    m_unk40 = 0;
    m_unk44 = 0;
    m_unk70.Allocate(0x80);
}
