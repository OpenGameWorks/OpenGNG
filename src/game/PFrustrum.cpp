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
extern "C" void sceVu0InversMatrix(float (*pOut)[4], PMat4 *pIn);
extern "C" void sceVu0MulMatrix(float (*pOut)[4], float (*pA)[4], float (*pB)[4]);
extern "C" void sceVu0OuterProduct(u_long128 *pOut, u_long128 *pA, u_long128 *pB);
extern "C" void sceVu0Normalize(u_long128 *pOut, u_long128 *pIn);
extern "C" float tanf(float fX);

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

// Function-local static of Init in the original ($267); the alias name differs from the original reloc.
static float gMatRotX180_267[4][4] = {
    {1.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, -1.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, -1.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 1.0f},
};

// DRAFT: 0x0018E100 Init__9PFrustrumFffffP5PMat4PA4_f
// note: 180 words differ. Frame, box store and plane math match; base is in s0 where the original keeps this in s1 and pMat in s0, and the 0.5f literal loads after the 0.0174 constant. Tried: mat declared first (184 to 180), per-iteration base (180), no base pointer (235, frame 0x200), fHalfY assigned first in body (180), base declared after nOff (180).
void PFrustrum::Init(float fFovY, float fAspect, float fNear, float fFar, PMat4 *pMat, float (*pBox)[4]) {
    float mat[4][4];
    u_long128 aPlane[5][3];
    char *base = (char *)this;
    float fHalfY = 0.5f * fFovY;
    float fTanX;
    float fTanY;
    int nIdx;
    int nOff;

    *(u_long128 *)(base + 0xD0) = *(u_long128 *)pBox;
    *(float *)(base + 0xDC) = fFar;
    fTanX = tanf(0.017453292f * (fHalfY * fAspect));
    fTanY = tanf(0.017453292f * fHalfY);

    *(float *)(base + 0x08) = -fNear;
    *(float *)(base + 0x18) = -fNear;
    *(float *)(base + 0x28) = -fNear;
    *(float *)(base + 0x38) = -fNear;
    *(float *)(base + 0x48) = -fFar;
    *(float *)(base + 0x58) = -fFar;
    *(float *)(base + 0x68) = -fFar;
    *(float *)(base + 0x78) = -fFar;

    *(float *)(base + 0x00) = fNear * fTanX;
    *(float *)(base + 0x10) = fNear * fTanX;
    *(float *)(base + 0x20) = -(fNear * fTanX);
    *(float *)(base + 0x30) = -(fNear * fTanX);
    *(float *)(base + 0x40) = fFar * fTanX;
    *(float *)(base + 0x50) = fFar * fTanX;
    *(float *)(base + 0x60) = -(fFar * fTanX);
    *(float *)(base + 0x70) = -(fFar * fTanX);

    *(float *)(base + 0x04) = fNear * fTanY;
    *(float *)(base + 0x34) = fNear * fTanY;
    *(float *)(base + 0x14) = -(fNear * fTanY);
    *(float *)(base + 0x24) = -(fNear * fTanY);
    *(float *)(base + 0x44) = fFar * fTanY;
    *(float *)(base + 0x74) = fFar * fTanY;
    *(float *)(base + 0x54) = -(fFar * fTanY);
    *(float *)(base + 0x64) = -(fFar * fTanY);

    sceVu0InversMatrix(mat, pMat);
    sceVu0MulMatrix(mat, mat, gMatRotX180_267);

    nIdx = 0;
    nOff = 0;
    do {
        sceVu0ApplyMatrix((u_long128 *)(base + nOff), (PMat4 *)mat, (float (*)[2][4])(base + nOff));
        sceVu0ApplyMatrix((u_long128 *)(base + nOff + 0x40), (PMat4 *)mat, (float (*)[2][4])(base + nOff + 0x40));
        nIdx += 1;
        nOff += 0x10;
    } while (nIdx < 4);

    sceVu0SubVector(&aPlane[0][2], (u_long128 *)(base + 0x20), (u_long128 *)(base + 0x10));
    sceVu0SubVector(&aPlane[0][1], (u_long128 *)(base + 0x10), (u_long128 *)(base + 0x00));
    sceVu0OuterProduct(&aPlane[0][0], &aPlane[0][2], &aPlane[0][1]);
    sceVu0Normalize((u_long128 *)(base + 0x80), &aPlane[0][0]);
    *(float *)(base + 0x8C) = -sceVu0InnerProduct((u_long128 *)(base + 0x80), (u_long128 *)(base + 0x20));

    sceVu0SubVector(&aPlane[1][2], (u_long128 *)(base + 0x40), (u_long128 *)(base + 0x70));
    sceVu0SubVector(&aPlane[1][1], (u_long128 *)(base + 0x70), (u_long128 *)(base + 0x30));
    sceVu0OuterProduct(&aPlane[1][0], &aPlane[1][2], &aPlane[1][1]);
    sceVu0Normalize((u_long128 *)(base + 0x90), &aPlane[1][0]);
    *(float *)(base + 0x9C) = -sceVu0InnerProduct((u_long128 *)(base + 0x90), (u_long128 *)(base + 0x40));

    sceVu0SubVector(&aPlane[2][2], (u_long128 *)(base + 0x20), (u_long128 *)(base + 0x60));
    sceVu0SubVector(&aPlane[2][1], (u_long128 *)(base + 0x60), (u_long128 *)(base + 0x50));
    sceVu0OuterProduct(&aPlane[2][0], &aPlane[2][2], &aPlane[2][1]);
    sceVu0Normalize((u_long128 *)(base + 0xA0), &aPlane[2][0]);
    *(float *)(base + 0xAC) = -sceVu0InnerProduct((u_long128 *)(base + 0xA0), (u_long128 *)(base + 0x20));

    sceVu0SubVector(&aPlane[3][2], (u_long128 *)(base + 0x30), (u_long128 *)(base + 0x70));
    sceVu0SubVector(&aPlane[3][1], (u_long128 *)(base + 0x70), (u_long128 *)(base + 0x60));
    sceVu0OuterProduct(&aPlane[3][0], &aPlane[3][2], &aPlane[3][1]);
    sceVu0Normalize((u_long128 *)(base + 0xB0), &aPlane[3][0]);
    *(float *)(base + 0xBC) = -sceVu0InnerProduct((u_long128 *)(base + 0xB0), (u_long128 *)(base + 0x30));

    sceVu0SubVector(&aPlane[4][2], (u_long128 *)(base + 0x50), (u_long128 *)(base + 0x40));
    sceVu0SubVector(&aPlane[4][1], (u_long128 *)(base + 0x40), (u_long128 *)(base + 0x00));
    sceVu0OuterProduct(&aPlane[4][0], &aPlane[4][2], &aPlane[4][1]);
    sceVu0Normalize((u_long128 *)(base + 0xC0), &aPlane[4][0]);
    *(float *)(base + 0xCC) = -sceVu0InnerProduct((u_long128 *)(base + 0xC0), (u_long128 *)(base + 0x50));
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
    *(u_long128 *)(base + 0x00) = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)(base + 0x40) = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)(base + 0x10) = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)(base + 0x50) = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)(base + 0x20) = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)(base + 0x60) = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)(base + 0x30) = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)(base + 0x70) = *(u_long128 *)&gUnitMatrix[12];
    return pThis;
}
