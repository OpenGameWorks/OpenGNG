#include "types.h"
#include "PParticleTracers.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pExpr);
extern "C" void sceVu0OuterProduct(float *pDst, float *pA, float *pB);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" float sqrtf(float x);
extern "C" int rand(void);
extern unsigned char __vt__16PParticleTracers[];
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];
extern unsigned char gDisplayListPtr[0x10];
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, PMat4 *pMat);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void BeginFxLines__10PGfxEngineFv(void *pThis);
extern "C" void DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(void *pThis, void *pLines, int nCount, float fA, float fB, bool bFlag);
extern "C" void EndFxLines__10PGfxEngineFv(void *pThis);
extern "C" void BeginFxInstances__10PGfxEngineFPvib(void *pThis, void *pData, int nSize, bool bFlag);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *pThis, void *pInstances, int nCount, bool bFlag);
extern "C" void Render__7PShaderFibPb(void *pThis, int nFlags, bool bFlag, bool *pOut);

// FUNCTION: 0x00203430 ComputeTracerAxes__16PParticleTracersFv
void PParticleTracers::ComputeTracerAxes() {
    sceVu0CopyVector(m_unk1A0, m_unkF0);
    sceVu0ScaleVector(m_unk1A0, m_unk1A0, -1.0f);
    m_unk180[2] = 0.0f;
    m_unk180[1] = 0.0f;
    m_unk180[0] = 0.0f;
    m_unk180[3] = 1.0f;
    float f20 = FastMath_Fabs__Ff(m_unk1A0[0]);
    float f21 = FastMath_Fabs__Ff(m_unk1A0[1]);
    float f0 = FastMath_Fabs__Ff(m_unk1A0[2]);
    if (f20 <= f21) {
        if (f0 <= f20) {
            m_unk180[2] = 1.0f;
        } else {
            m_unk180[0] = 1.0f;
        }
    } else if (f0 <= f21) {
        m_unk180[2] = 1.0f;
    } else {
        m_unk180[1] = 1.0f;
    }
    sceVu0OuterProduct(m_unk190, m_unk180, m_unk1A0);
    sceVu0Normalize(m_unk190, m_unk190);
    sceVu0OuterProduct(m_unk180, m_unk190, m_unk1A0);
    sceVu0Normalize(m_unk180, m_unk180);
    m_unk180[3] = 0.0f;
    m_unk190[3] = 0.0f;
    m_unk1A0[3] = 0.0f;
}

// DRAFT: 0x00203550 InitTracers__16PParticleTracersFv
// note: 124 words differ. The lqc2/vsub/vmul/vadd/sqc2 VU0 block is written as scalar math; frame is 0x60 vs 0x40 (extra saved regs). Tried: local seed pointer, direct this-cast seed (both 124).
void PParticleTracers::InitTracers() {
    for (int i = 0; i < m_unk120; i++) {
        float *pT = (float *)((char *)m_unk174 + (i << 5));
        if (pT == 0) {
            CdsAssert__FPciPc("PParticleTracers.cpp", 0x135, "apTracer");
        }
        *(int *)((char *)this + 0xD0) = *(int *)((char *)this + 0xD0) * 0x343FD + 0x269EC3;
        pT[0] = (float)((*(int *)((char *)this + 0xD0) >> 16) & 0x7FFF);
        *(int *)((char *)this + 0xD0) = *(int *)((char *)this + 0xD0) * 0x343FD + 0x269EC3;
        pT[1] = (float)((*(int *)((char *)this + 0xD0) >> 16) & 0x7FFF);
        *(int *)((char *)this + 0xD0) = *(int *)((char *)this + 0xD0) * 0x343FD + 0x269EC3;
        pT[2] = (float)((*(int *)((char *)this + 0xD0) >> 16) & 0x7FFF);
        sceVu0ScaleVectorXYZ(pT, pT, 0.000030517578f);
        pT[0] = ((m_unk100[0] + m_unk100[0]) * pT[0] - m_unk100[0]) + m_unk160[0];
        pT[1] = ((m_unk100[1] + m_unk100[1]) * pT[1] - m_unk100[1]) + m_unk160[1];
        pT[2] = ((m_unk100[2] + m_unk100[2]) * pT[2] - m_unk100[2]) + m_unk160[2];
        *(int *)((char *)this + 0xD0) = *(int *)((char *)this + 0xD0) * 0x343FD + 0x269EC3;
        pT[3] = 0.0f + ((m_unk170 - 0.0f) * (0.000030517578f * (float)((*(int *)((char *)this + 0xD0) >> 16) & 0x7FFF)));
        *(u_long128 *)(pT + 4) = *(u_long128 *)m_unkF0;
    }
}

// FUNCTION: 0x00203710 ModifyPosition__16PParticleTracersFP5PMat4
void PParticleTracers::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk160, m_unkE0);
    m_unk80 = m_unk160[0];
    m_unk84 = m_unk160[1];
    m_unk88 = m_unk160[2];
}

// FUNCTION: 0x00203760 SetPosition__16PParticleTracersFPfPf
void PParticleTracers::SetPosition(float *pFrom, float *pTo) {
    sceVu0CopyVector(m_unk160, pFrom);
    sceVu0SubVector(m_unkF0, pTo, pFrom);
    m_unk124 = sqrtf(sceVu0InnerProduct(m_unkF0, m_unkF0));
    sceVu0Normalize(m_unkF0, m_unkF0);
    m_unk80 = m_unk160[0];
    m_unk84 = m_unk160[1];
    m_unk88 = m_unk160[2];
    if (m_unk178 != 0) {
        ComputeTracerAxes();
    }
}

// FUNCTION: 0x00203810 Start__16PParticleTracersFv
void PParticleTracers::Start() {
    m_unk150 = (int)(0.5f + (12335.0f + (18991.0f * ((float)rand() / 2.1474836e9f))));
    InitTracers();
    m_unk15 = 1;
    m_unk18 = 1;
}

// DRAFT: 0x002038A0 Render__16PParticleTracersFv
// note: 79 words differ. Original keeps m_unk08 test as bnez to body plus b to epilogue (ld ra in delay slot); ours is beqz to epilogue. Tried: early returns, positive if(m_unk08!=0) nest, empty-if/else (all 79).
void PParticleTracers::Render() {
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk16 != 0) {
        return;
    }
    if (m_unkA4 == 0) {
        return;
    }
    if (m_unk08 != 0) {
        if (m_unk178 != 0) {
            SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)gUnitMatrix);
            Render__7PShaderFibPb(*(void **)m_unk178, 0x7E, true, 0);
            int a1 = 0;
            int a2 = 0;
            if (((int *)m_unk178)[2] != 0) {
                a2 = ((int *)((int *)m_unk178)[3])[0];
                a1 = ((int *)((int *)m_unk178)[3])[1];
            }
            BeginFxInstances__10PGfxEngineFPvib(gGfxEng, (void *)a1, a2, false);
            DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)gDisplayListPtr, (void *)m_unk08, m_unk04, false);
        } else {
            SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)&m_unk40);
            SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, 0, &m_unkC0, true, m_unk30, 0x50000);
            BeginFxLines__10PGfxEngineFv(gGfxEng);
            DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(gGfxEng, (void *)m_unk08, m_unk04, 0.0f, 128.0f, m_unk1A);
            EndFxLines__10PGfxEngineFv(gGfxEng);
        }
    }
}

// FUNCTION: 0x00204170 __dt__16PParticleTracersFv
extern "C" void *__dt__16PParticleTracersFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleTracers *pSelf = (PParticleTracers *)pThis;
        *(void **)pThis = __vt__16PParticleTracers;
        if (pSelf->m_unk174 != 0) {
            __dla__FPv(pSelf->m_unk174);
            pSelf->m_unk174 = 0;
        }
        pSelf->m_unk178 = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x002041F0 __ct__16PParticleTracersFv
PParticleTracers::PParticleTracers() {
    *(void **)this = __vt__16PParticleTracers;
    m_unk174 = 0;
    m_unk178 = 0;
}
