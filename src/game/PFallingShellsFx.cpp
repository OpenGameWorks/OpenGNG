#include "types.h"
#include "PFallingShellsFx.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern unsigned char __vt__16PFallingShellsFx[];

// FUNCTION: 0x0020CB90 FindFreeShell__16PFallingShellsFxFv
int PFallingShellsFx::FindFreeShell() {
    int i;
    int off;
    for (i = 0, off = 0; i < 0x40; i++, off += 0x70) {
        if (((unsigned char *)this)[off + 0x1B2] == 0) {
            return i;
        }
    }
    return -1;
}

static const float kUnitW[4] = {0.0f, 0.0f, 0.0f, 1.0f};

// DRAFT: 0x0020CE60 ModifyPosition__16PFallingShellsFxFP5PMat4
// note: DIFF 39; original frame 0x90 with this in s0, no dtor call, row-3 (0,0,0,1) store at sp+0x70. Tried float mat[4][4] local (DIFF 42), kept PMat4 local.
void PFallingShellsFx::ModifyPosition(PMat4 *pMat) {
    float vec[4];
    PMat4 mat;
    float dir[4];

    if (pMat == 0) {
        CdsAssert__FPciPc("PFallingShellsFx.cpp", 0x113, "pMat");
    }
    pMat->MulVector(m_unkF0, m_unkE0);
    *(u_long128 *)vec = *(u_long128 *)kUnitW;
    vec[1] = m_unk140;
    pMat->MulVector(vec, vec);
    m_unk144 = vec[1];
    sceVu0UnitMatrix((float *)&mat);
    sceVu0CopyMatrix((float (*)[4])&mat, (float (*)[4])pMat);
    mat.MulVector(dir, m_unk100);
    SetDirection(dir);
}

// FUNCTION: 0x0020CF40 SetDirection__16PFallingShellsFxFPf
void PFallingShellsFx::SetDirection(float *pDir) {
    float mat[4][4];

    sceVu0UnitMatrix((float *)mat);
    ((PMat4 *)mat)->RotateY(0.5f * m_unk138);
    ((PMat4 *)mat)->MulVector(m_unk110, pDir);
    sceVu0Normalize(m_unk110, m_unk110);
    sceVu0UnitMatrix((float *)mat);
    ((PMat4 *)mat)->RotateY(-0.5f * m_unk138);
    ((PMat4 *)mat)->MulVector(m_unk120, pDir);
    sceVu0Normalize(m_unk120, m_unk120);
}

// FUNCTION: 0x0020D780 __dt__16PFallingShellsFxFv
extern "C" void *__dt__16PFallingShellsFxFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PFallingShellsFx *pSelf = (PFallingShellsFx *)pThis;
        *(void **)pThis = __vt__16PFallingShellsFx;
        pSelf->m_unk148 = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x0020D7F0 __ct__16PFallingShellsFxFv
// note: DIFF 19; original keeps this in s0 without spill to 0x1C(sp); memset from 0x14C variant left the count unchanged.
PFallingShellsFx::PFallingShellsFx() {
    *(void **)this = __vt__16PFallingShellsFx;
    m_unk148 = 0;
    memset((char *)this + 0x14C, 0, 0x1C00);
    *(int *)((char *)this + 0x1D4C) = 0;
}
