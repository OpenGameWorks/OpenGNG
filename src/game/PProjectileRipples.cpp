// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PProjectileRipples.h"
#include "PRandom.h"

// TODO(header): foreign declarations
extern "C" void FadeAndDie__15PParticleSystemFUi(void *, unsigned int);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__18PProjectileRipples[];
extern "C" void SetMaterial__10PGfxEngineFPfbUlUl(void *, float *, bool, unsigned long, unsigned long);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void BeginFxInstances__10PGfxEngineFPvib(void *, void *, int, unsigned char);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *, void *, int, bool);
extern unsigned char gGfxEng[0x10];
extern unsigned char gDisplayListPtr[0x10];
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0OuterProduct(float *dst, float *a, float *b);
extern "C" void sceVu0Normalize(float *dst, float *src);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" float FastMath_Sin180__Ff(float f);
extern "C" float FastMath_Cos180__Ff(float f);
extern "C" void *__nwa__FUi(unsigned int);
extern "C" void QwordCopy__FP1P1Ui(u_long128 *, u_long128 *, unsigned int);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" int rand(void);
extern "C" void sceVu0UnitMatrix(float (*pMatrix)[4]);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" void sceVu0MulMatrix(float (*dst)[4], float (*a)[4], float (*b)[4]);
extern "C" void *AllocParticles__12PDisplayListFii(void *, int, int);
extern "C" float FastMath_IntSin180__Fi(int);
extern "C" float FastMath_IntCos180__Fi(int);


// DRAFT: 0x00217410 InitRingMeshPacket__18PProjectileRipplesFRiib
// note: DIFF 5; head and both CreateRingTriStrip calls match (hoisted fLo/fHi/fEnd locals, int n set to 0 in else, byte-offset pointers); only the p0/p1 base/offset register choice (a0/v1 swapped, addu operand order) differs; tried base-first/offset-first per pointer, char* base local, offset locals
void *PProjectileRipples::InitRingMeshPacket(int &arg0, int arg1, bool arg2) {
    float sp40[0x32][4];
    float sp360[0x32][4];
    float sp680[0x32][4];
    int s0;
    int s1;
    int n;
    float fHi = 0.375f;
    float fLo = 0.25f;
    float fEnd = 0.5f;
    if (arg2) {
        s0 = CreateRingTriStrip(arg1, fLo, fHi, 0, 0xFF, sp40, sp360, sp680);
        unsigned int off = s0 << 4;
        n = CreateRingTriStrip(arg1, fHi, fEnd, 0xFF, 0, (float(*)[4])((unsigned int)sp40 + off), (float(*)[4])((unsigned int)sp360 + off), (float(*)[4])((unsigned int)sp680 + off));
    } else {
        s0 = CreateRingTriStrip(arg1, 0.0f, 0.5f, 0x80, 0x80, sp40, sp360, sp680);
        n = 0;
    }
    s1 = s0 + n;
    if (s1 >= 0x32) {
        CdsAssert("PProjectileRipples.cpp", 0x18A, "iNumVerts < fx_i_instance_max_vertices");
    }
    unsigned int *p0 = (unsigned int *)((s0 << 4) + (unsigned int)sp40);
    unsigned int *p1 = (unsigned int *)(((s0 + 1) << 4) + (unsigned int)sp40);
    p0[3] |= 0x8000;
    p1[3] |= 0x8000;
    int *pkt = (int *)__nwa__FUi(0x970);
    if (pkt == 0) {
        CdsAssert("PProjectileRipples.cpp", 0x192, "apPacket");
    }
    pkt[0] = s1;
    pkt[1] = 0;
    pkt[2] = 0;
    pkt[3] = 0;
    QwordCopy__FP1P1Ui((u_long128 *)(pkt + 4), (u_long128 *)sp360, 0x32);
    QwordCopy__FP1P1Ui((u_long128 *)(pkt + 0xCC), (u_long128 *)sp680, 0x32);
    QwordCopy__FP1P1Ui((u_long128 *)(pkt + 0x194), (u_long128 *)sp40, 0x32);
    arg0 = 0x970;
    return pkt;
}
// FUNCTION: 0x002175C0 CreateRingTriStrip__18PProjectileRipplesFiffiiPA4_fPA4_fPA4_f
int PProjectileRipples::CreateRingTriStrip(int arg0, float arg1, float arg2, int arg3, int arg4, float (*arg5)[4], float (*arg6)[4], float (*arg7)[4]) {
    int count = arg0 * 2 + 2;
    int i;
    float angle = 0.0f;
    float step = 360.0f / (float)arg0;
    for (i = 0; i < count; i += 2) {
        float s = FastMath_Sin180__Ff(angle - 180.0f);
        float c = FastMath_Cos180__Ff(angle - 180.0f);
        arg5[i][0] = arg1 * c;
        arg5[i][1] = arg1 * s;
        arg5[i][2] = 0.0f;
        arg5[i][3] = 1.0f;
        angle += step;
        float half = 0.5f * (arg1 / arg2);
        arg6[i][0] = 0.5f + c * half;
        arg6[i][1] = 0.5f + s * half;
        int (*ci)[4] = (int (*)[4])arg7;
        ci[i][0] = 0x80;
        ci[i][1] = 0x80;
        ci[i][2] = 0x80;
        ci[i][3] = arg3;
        int (*cn)[4] = ci + (i + 1);
        cn[0][0] = 0x80;
        cn[0][1] = 0x80;
        cn[0][2] = 0x80;
        cn[0][3] = arg4;
        arg5[i + 1][0] = arg2 * c;
        arg5[i + 1][1] = arg2 * s;
        arg5[i + 1][2] = 0.0f;
        arg5[i + 1][3] = 1.0f;
        arg6[i + 1][0] = 0.5f + 0.5f * c;
        arg6[i + 1][1] = 0.5f + 0.5f * s;
    }
    return count;
}

// FUNCTION: 0x00217790 FindFreeRing__18PProjectileRipplesFv
int PProjectileRipples::FindFreeRing() {
    int i = 0;
    int off = 0;
    for (; i < m_unk10C; off += 0x60, i++) {
        if (((PProjectileRing *)((char *)m_unk120 + off))->m_unk50 == 0) {
            return i;
        }
    }
    return -1;
}

// FUNCTION: 0x002177E0 ComputeAxes__18PProjectileRipplesFPfPfPfPf
void PProjectileRipples::ComputeAxes(float *pSrc, float *pAxis0, float *pAxis1, float *pVec) {
    sceVu0CopyVector(pVec, pSrc);
    pAxis0[2] = 0.0f;
    pAxis0[1] = 0.0f;
    pAxis0[0] = 0.0f;
    pAxis0[3] = 1.0f;
    float fx = FastMath_Fabs__Ff(pVec[0]);
    float fy = FastMath_Fabs__Ff(pVec[1]);
    float fz = FastMath_Fabs__Ff(pVec[2]);
    if (fx <= fy) {
        if (fz <= fx) {
            pAxis0[2] = 1.0f;
        } else {
            pAxis0[0] = 1.0f;
        }
    } else if (fz <= fy) {
        pAxis0[2] = 1.0f;
    } else {
        pAxis0[1] = 1.0f;
    }
    sceVu0OuterProduct(pAxis1, pAxis0, pVec);
    sceVu0Normalize(pAxis1, pAxis1);
    sceVu0OuterProduct(pAxis0, pAxis1, pVec);
    sceVu0Normalize(pAxis0, pAxis0);
    pAxis0[3] = 0.0f;
    pAxis1[3] = 0.0f;
    pVec[3] = 0.0f;
}

// FUNCTION: 0x00217900 CreateRing__18PProjectileRipplesFPfPf
void PProjectileRipples::CreateRing(float *arg0, float *arg1) {
    float sp40[4];
    float sp50[4];
    float sp60[4];
    int idx = FindFreeRing();
    if (idx < 0) {
        return;
    }
    PProjectileRing *pRing = m_unk120 + idx;
    pRing->m_unk40 = 0.0f;
    pRing->m_unk44 = 1.0f / m_unk108;
    pRing->m_unk48 = -0.02f + 0.04f * ParticleRand01(m_unkD0);
    pRing->m_unk4C = -0.02f + 0.04f * ParticleRand01(m_unkD0);
    pRing->m_unk50 = 1;
    ComputeAxes(arg1, sp40, sp50, sp60);
    *(u_long128 *)pRing->m_unk00 = *(u_long128 *)sp40;
    *(u_long128 *)pRing->m_unk10 = *(u_long128 *)sp50;
    *(u_long128 *)pRing->m_unk20 = *(u_long128 *)sp60;
    *(u_long128 *)pRing->m_unk30 = *(u_long128 *)arg0;
    pRing->m_unk30[3] = 1.0f;
    m_unk124++;
}

// FUNCTION: 0x00217A70 FadeAndDie__18PProjectileRipplesFUi
void PProjectileRipples::FadeAndDie(unsigned int uArg) {
    FadeAndDie__15PParticleSystemFUi(this, uArg);
    m_unk18 = 0;
}

// FUNCTION: 0x00217AA0 Render__18PProjectileRipplesFv
void PProjectileRipples::Render() {
    if (m_unk15 == 0 || m_unk124 == 0 || m_unk138 == 0) {
        return;
    }
    if (m_unk19 != 0) {
        float a[4] = {1.1f, 1.1f, 1.1f, 1.0f};
        SetMaterial__10PGfxEngineFPfbUlUl(gGfxEng, a, true, m_unk30, 0x50000);
    } else {
        float b[4] = {1.0f, 1.0f, 1.0f, 0.8f};
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk10, b, true, m_unk30, 0x50000);
    }
    BeginFxInstances__10PGfxEngineFPvib(gGfxEng, m_unk12C, m_unk130, m_unk19);
    DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)(gGfxEng + 0x154C80), m_unk134, m_unk138, false);
}

// DRAFT: 0x00217B90 Animate__18PProjectileRipplesFf
// note: 153 words differ; frame 0xB0 vs 0x80 with s4/s5 saved (original keeps this in s3); original frame 0x80 with s0-s3 saved, ours 0xB0 with s4/s5; original's AllocParticles arg is *(void **)(gGfxEng+0x154C80) (offset form tried, count unchanged at 153); tried rot-ref removal (185->153), diff moved into loop (178), sub/tmp merged (181), angle uninitialized (157), f3 loaded before out (157), while loop (153), for-scoped i (153)
void PProjectileRipples::Animate(float arg0) {
    float scale = arg0;
    float angle = 0.0f;
    float sub[4];
    float tmp[4];
    int i;

    if (m_unk15 == 0) {
        return;
    }
    if (m_unk18 == 0) {
        scale *= 4.0f;
    }
    if (m_unk124 == 0) {
        m_unk16 = m_unk17;
        m_unk15 = m_unk18;
        return;
    }
    m_unk134 = AllocParticles__12PDisplayListFii(*(void **)gGfxEng, m_unk124, 6);
    if (m_unk134 == 0) {
        CdsAssert("PProjectileRipples.cpp", 0x6B, "mpFxInstances");
    }
    m_unk138 = 0;
    if (m_unk19 != 0) {
        float rot = *(float *)&m_unk128 + 3.0f * scale;
        if (!(rot < 360.0f)) {
            rot = rot - 360.0f;
        }
        *(float *)&m_unk128 = rot;
        angle = rot;
    }
    sceVu0SubVector(sub, m_unkF0, m_unkE0);
    float diff = m_unk104 - m_unk100;
    for (i = 0; i < m_unk10C; i++) {
        PProjectileRing *ring = m_unk120 + i;
        if (m_unk19 != 0) {
            angle += 25.0f;
            if (!(angle < 360.0f)) {
                angle -= 360.0f;
            }
        }
        if (ring->m_unk50 != 0) {
            PProjectileRing *out = (PProjectileRing *)((char *)m_unk134 + m_unk138 * 0x60);
            float f3 = ring->m_unk40;
            {
                int bits = *(int *)&f3;
                float *pE0 = m_unkE0;
                float *pSub = sub;
                float *pTmp = tmp;
                asm {
                    lqc2 vf1, 0x0(pSub)
                    lqc2 vf2, 0x0(pE0)
                    qmtc2.i bits, vf3
                    vmulx.xyzw vf4, vf1, vf3x
                    vnop
                    vnop
                    vnop
                    vadd.xyzw vf5, vf4, vf2
                    vnop
                    vnop
                    vnop
                    sqc2 vf5, 0x0(pTmp)
                }
            }
            float f1 = f3 + ring->m_unk44 * scale;
            float x = m_unk100 + diff * f3;
            ring->m_unk40 = f1;
            if (!(f1 < 1.0f)) {
                ring->m_unk50 = 0;
                x = 0.0f;
                tmp[3] = 0.0f;
                m_unk124 -= 1;
            }
            sceVu0UnitMatrix((float (*)[4])out);
            out->m_unk00[0] = x;
            out->m_unk10[1] = x;
            *(u_long128 *)&out->m_unk40 = *(u_long128 *)tmp;
            sceVu0MulMatrix((float (*)[4])out, (float (*)[4])ring, (float (*)[4])out);
            if (m_unk19 != 0) {
                float a = angle - 180.0f;
                float s = FastMath_IntSin180__Fi((int)a);
                *(float *)&out->m_unk50 = ring->m_unk48 * FastMath_IntCos180__Fi((int)a);
                *(float *)((char *)out + 0x54) = ring->m_unk4C * s;
            }
            m_unk138 += 1;
        }
    }
}

// FUNCTION: 0x00217E80 FrustrumTest__18PProjectileRipplesFP9PFrustrumPfff
void PProjectileRipples::FrustrumTest(PFrustrum *, float *, float, float) {
    *(int *)((char *)this + 0xA4) = 1;
}

// FUNCTION: 0x00217E90 Create__18PProjectileRipplesFP25tagProjectileRippesParams
void PProjectileRipples::Create(tagProjectileRippesParams *pParams) {
    if (pParams == 0) {
        CdsAssert("PProjectileRipples.cpp", 0x2D, "pParams");
    }
    if (m_unk12C != 0) {
        CdsAssert("PProjectileRipples.cpp", 0x2E, "mpRingMeshPacket == NULL");
    }
    memcpy((char *)this + 0xE0, pParams, 0x40);
    m_unk12C = InitRingMeshPacket(m_unk130, 8, true);
    if (m_unk12C == 0) {
        CdsAssert("PProjectileRipples.cpp", 0x33, "mpRingMeshPacket");
    }
    m_unk120 = (PProjectileRing *)__nwa__FUi(m_unk10C * 0x60);
    if (m_unk120 == 0) {
        CdsAssert("PProjectileRipples.cpp", 0x36, "mpRings");
    }
    memset(m_unk120, 0, m_unk10C * 0x60);
    m_unk124 = 0;
    m_unk128 = 0;
    m_unk134 = 0;
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk14 = 1;
    sceVu0UnitMatrix(m_unk40);
    m_unkC = 0x12;
    m_unk19 = m_unk110;
    m_unkD0 = (int)(0.5f + (26731.0f + (-12208.0f * ((float)rand() / 2147483648.0f))));
    m_unk30 = 0x44;
}

// FUNCTION: 0x00218030 __dt__18PProjectileRipplesFv
extern "C" void *__dt__18PProjectileRipplesFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PProjectileRipples *pSelf = (PProjectileRipples *)pThis;
        *(void **)pThis = __vt__18PProjectileRipples;
        if (pSelf->m_unk12C != 0) {
            __dla__FPv(pSelf->m_unk12C);
            pSelf->m_unk12C = 0;
            pSelf->m_unk130 = 0;
        }
        if (pSelf->m_unk120 != 0) {
            __dla__FPv(pSelf->m_unk120);
            pSelf->m_unk120 = 0;
        }
        pSelf->m_unk124 = 0;
        pSelf->m_unk134 = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x002180D0 __ct__18PProjectileRipplesFv
PProjectileRipples::PProjectileRipples() {
    __ct__15PParticleSystemFv(this);
    m_unk000 = __vt__18PProjectileRipples;
    m_unk12C = 0;
    m_unk130 = 0;
    m_unk124 = 0;
    m_unk134 = 0;
}
