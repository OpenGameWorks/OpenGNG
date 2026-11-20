// FLAGS: -sdatathreshold 0
#include "BGCollision.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *);
extern float vUp_1253[4];
extern "C" void sceVu0SubVector(float *, float *, float *);
float FastMath_Fabs(float f);
float Fabs(float f);
struct STCollisionPoly;

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
