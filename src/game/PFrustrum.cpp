// FLAGS: -str readonly
#include "types.h"
#include "PFrustrum.h"

// TODO(header): foreign declarations
extern float gUnitMatrix[16];
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0ApplyMatrix(u_long128 *pOut, PMat4 *pMat, float (*pIn)[2][4]);
extern "C" void sceVu0SubVector(u_long128 *pOut, u_long128 *pA, u_long128 *pB);
extern "C" float sceVu0InnerProduct(u_long128 *pA, u_long128 *pB);

// DRAFT: 0x0018DE90 GetPlaneEquation__9PFrustrumFQ29PFrustrum13eFrustumPlaneRfRfRfRf
// note: 26 words differ. Frame, saves and assert branch match; the compiler folds +0x80..+0x8C into load displacements, and the original recomputes this+N before each add. Tried: separate char* base pointers (same 26). Size 0xA4 vs 0xC0.
void PFrustrum::GetPlaneEquation(eFrustumPlane ePlane, float &fA, float &fB, float &fC, float &fD) {
    if (!(ePlane < FRUSTUM_MAX_PLANES)) {
        CdsAssert__FPciPc((char *)"PFrustrum.cpp", 0x133, (char *)"ePlane < FRUSTUM_MAX_PLANES");
    }
    int nOff = (int)ePlane << 4;
    char *p0 = (char *)this + 0x80;
    char *p1 = (char *)this + 0x84;
    char *p2 = (char *)this + 0x88;
    char *p3 = (char *)this + 0x8C;
    fA = *(float *)(p0 + nOff);
    fB = *(float *)(p1 + nOff);
    fC = *(float *)(p2 + nOff);
    fD = *(float *)(p3 + nOff);
}

// DRAFT: 0x0018DF50 IntersectBox__9PFrustrumFPA2_A4_fP5PMat4
// note: 44 words differ. Prologue saves order and float saves (f20/f21) differ, and the loop/switch shape does not match the asm (original 0x1A4 bytes). Tried: one draft, not reconstructed from asm.
int PFrustrum::IntersectBox(float (*pBox)[2][4], PMat4 *pMat) {
    u_long128 sp90;
    u_long128 spA0;
    float fExtent;
    float fRadius;
    float fDist;
    int bPartial = 0;
    int bHitE0 = 0;
    int nOutside = 0;
    int nPlane = 0;
    int nOff = 0;

    fExtent = pBox[0][1][3];
    if (pMat != 0) {
        sceVu0ApplyMatrix(&sp90, pMat, pBox);
    } else {
        sp90 = *(u_long128 *)pBox;
    }
    sceVu0SubVector(&spA0, &sp90, (u_long128 *)((char *)this + 0xD0));
    fRadius = *(float *)((char *)this + 0xDC) + fExtent;
    if (!(sceVu0InnerProduct(&spA0, &spA0) <= fRadius * fRadius)) {
        return 0;
    }
    bHitE0 = 0;
    do {
        fDist = *(float *)((char *)this + nOff + 0x8C) + sceVu0InnerProduct(&sp90, (u_long128 *)((char *)this + nOff + 0x80));
        if (!(fDist <= fExtent)) {
            return 0;
        }
        if (fDist < -fExtent) {
            nOutside += 1;
        } else {
            switch (nPlane) {
            case 0:
                bHitE0 = 1;
                *(float *)((char *)this + 0xE0) = fDist;
                break;
            case 4:
            case 3:
                bPartial = 1;
                break;
            }
        }
        nPlane += 1;
        nOff += 0x10;
    } while (nPlane < 5);

    if (nOutside == 5) {
        return 1;
    }
    if (bHitE0 != 0) {
        return 4;
    }
    return bPartial ? 3 : 2;
}

// FUNCTION: 0x0018E430 __dt__9PFrustrumFv
extern "C" PFrustrum *__dt__9PFrustrumFv(PFrustrum *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0018E480 __ct__9PFrustrumFv
extern "C" PFrustrum *__ct__9PFrustrumFv(PFrustrum *pThis) {
    char *base = (char *)pThis;
    memset(base + 0x80, 0, 0x50);
    *(u_long128 *)(base + 0x00) = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)(base + 0x40) = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)(base + 0x10) = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)(base + 0x50) = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)(base + 0x20) = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)(base + 0x60) = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)(base + 0x30) = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)(base + 0x70) = *(u_long128 *)gUnitMatrix;
    return pThis;
}
