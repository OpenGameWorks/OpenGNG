#include "types.h"
#include "PParticleBlowingLeaves.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern "C" void *memset(void *, int, unsigned int);
extern unsigned char __vt__22PParticleBlowingLeaves[];
extern "C" void *__nwa__FUi(unsigned int);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void QwordCopy__FP1P1Ui(u_long128 *pDst, u_long128 *pSrc, unsigned int nQwords);
extern "C" void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
void FastMath_RotateMatrix(float (*)[4][4], float (*)[4][4], float (*)[4], float (*)[4][4]);

// FUNCTION: 0x001FD130 GenerateLeafMeshData__22PParticleBlowingLeavesFv
void PParticleBlowingLeaves::GenerateLeafMeshData() {
    float blkA[24] = {
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f, 0.0f,
        0.5f, 1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f,
    };
    float blkB[24] = {
        -0.5f, 0.35f, -0.5f, 1.0f,
        -0.5f, 0.35f, 0.5f, 1.0f,
        0.0f, 0.0f, -0.5f, 1.0f,
        0.0f, 0.0f, 0.5f, 1.0f,
        0.5f, 0.35f, -0.5f, 1.0f,
        0.5f, 0.35f, 0.5f, 1.0f,
    };
    int blkC[24] = {
        128, 128, 128, 128, 128, 128, 128, 128,
        128, 128, 128, 128, 128, 128, 128, 128,
        128, 128, 128, 128, 128, 128, 128, 128,
    };
    void *pBuf = __nwa__FUi(0x970);
    if (pBuf == 0) {
        CdsAssert__FPciPc("PParticleBlowingLeaves.cpp", 0x19D, "apPacket");
    }
    ((int *)pBuf)[0] = 6;
    ((int *)pBuf)[1] = 0;
    ((int *)pBuf)[2] = 0;
    ((int *)pBuf)[3] = 0;
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pBuf + 0x10), (u_long128 *)&blkA, 6);
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pBuf + 0x330), (u_long128 *)&blkC, 6);
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pBuf + 0x650), (u_long128 *)&blkB, 6);
    m_unkA54 = 0x970;
    m_unkA50 = pBuf;
}

// FUNCTION: 0x001FD290 ComputeWindAxes__22PParticleBlowingLeavesFPf
void PParticleBlowingLeaves::ComputeWindAxes(float *pWind) {
    float mtx[4][4];
    FastMath_RotateMatrix((float (*)[4][4])mtx, 0, (float (*)[4])pWind, 0);
    float vx[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
    float vy[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
    float vz[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
    sceVu0ApplyMatrix(m_unkA10, mtx, vx);
    sceVu0ApplyMatrix(m_unkA20, mtx, vy);
    sceVu0ApplyMatrix(m_unkA30, mtx, vz);
    sceVu0Normalize(m_unkA10, m_unkA10);
    sceVu0Normalize(m_unkA20, m_unkA20);
    sceVu0Normalize(m_unkA30, m_unkA30);
}

// DRAFT: 0x001FD6F0 InitLeafRotations__22PParticleBlowingLeavesFv
// note: 60 words; register allocation differs (original a2=count, a3=offset, constant in a1; ours offset in a1, pointer in a3); tried quad store as scalars (65), (u_long128)0x3F800000<<96 (compile error), 64-bit shifted quad (60), declaration order swap (60)
void PParticleBlowingLeaves::InitLeafRotations() {
    int i = 0;
    int off = 0;
    do {
        char *pLeaf = (char *)this + off;
        i++;
        *(u_long128 *)(pLeaf + 0xF0) = (u_long128)((unsigned long long)0x3F800000 << 32);
        off += 0x70;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pLeaf + 0x100) = 2.0f + 4.0f * (3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pLeaf + 0x104) = 1.0f + 1.0f * (3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        float f = 0.5f + 1.5f * (3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF));
        *(float *)(pLeaf + 0x110) = f;
        *(float *)(pLeaf + 0x114) = 1.0f;
        *(float *)(pLeaf + 0x118) = f;
        *(float *)(pLeaf + 0x11C) = 1.0f;
    } while (i < 0x14);
}

// FUNCTION: 0x001FE2F0 __dt__22PParticleBlowingLeavesFv
extern "C" void *__dt__22PParticleBlowingLeavesFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleBlowingLeaves *pSelf = (PParticleBlowingLeaves *)pThis;
        *(void **)pThis = __vt__22PParticleBlowingLeaves;
        if (pSelf->m_unkE0 != 0) {
            __dla__FPv(pSelf->m_unkE0);
            pSelf->m_unkE0 = 0;
        }
        if (pSelf->m_unkA50 != 0) {
            __dla__FPv(pSelf->m_unkA50);
            pSelf->m_unkA50 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001FE390 __ct__22PParticleBlowingLeavesFv
PParticleBlowingLeaves::PParticleBlowingLeaves() {
    *(void **)this = __vt__22PParticleBlowingLeaves;
    m_unkE0 = 0;
    m_unkE4 = 0;
    m_unkA50 = 0;
    m_unkA54 = 0;
    memset(m_unkF0, 0, 0x8C0);
    m_unk9B0 = 0;
    GenerateLeafMeshData();
}
