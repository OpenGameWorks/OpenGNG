// FLAGS: -str readonly
#include "types.h"
#include "PParticleTracers.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" long long fptodp(float arg0);
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, int nCount, int nSize);
extern "C" int _dpfgt(long long a, long long b);
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
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PParticleTracers.cpp", line, #cond))
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
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *GetResource__16PParticleManagerFUi(void *pThis, unsigned int nId);

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
// note: 105 words differ. VU0 block is asm over pT/pA/pB and matches the original ops. Remaining diff: frame 0x60 vs 0x40 and `this` copied to s4 with a 0xD0 pointer in s3, because the compiler strength-reduces i<<5 into a running offset (s2). Tried: m_unkD0 member seed (106), i*32 (106), while loop (106), local loop bound n (115), local seed pointer (124).
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
        {
            float *pA = m_unk100;
            float *pB = m_unk160;
            asm {
                lqc2 vf1, 0x0(pT)
                lqc2 vf2, 0x0(pA)
                lqc2 vf3, 0x0(pB)
                vsub.xyz vf4, vf2, vf2
                vsub.xyz vf4, vf4, vf2
                vsub.xyz vf5, vf2, vf4
                vmul.xyz vf6, vf5, vf1
                vadd.xyz vf7, vf6, vf4
                vadd.xyz vf1, vf7, vf3
                sqc2 vf1, 0x0(pT)
            }
        }
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

// DRAFT: 0x00203A10 Animate__16PParticleTracersFf
// note: DIFF 326 words; frame 0xB0 vs 0x90, this in s6 vs s5, 9 saved GPRs vs 7 (fp, s7 extra), VU0 blocks and pO[3] lerp order unresolved.
void PParticleTracers::Animate(float fA) {
    unsigned int i;
    int nDone = 0;
    float *pT;
    float *pO;
    float t;
    float fMul;
    void *apFxInstances;
    void *apLines;

    if (!m_unk15) return;
    if (m_unk16) return;
    m_unkD0 = m_unk150;
    if (m_unk178 != 0) {
        apFxInstances = AllocParticles__12PDisplayListFii(*(void **)gGfxEng, m_unk04, 6);
        CDS_ASSERT(0x72, apFxInstances);
        m_unk08 = apFxInstances;
    } else {
        apLines = AllocParticles__12PDisplayListFii(*(void **)gGfxEng, m_unk04, 2);
        CDS_ASSERT(0x79, apLines);
        m_unk08 = apLines;
    }
    for (i = 0; i < m_unk04; i++) {
        pT = (float *)((char *)m_unk174 + (i << 5));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        pT[3] = pT[3] + fA * (0.25f + 0.75f * ((float)((m_unkD0 >> 16) & 0x7FFF) * 0.000030517578125f));
        if (!(pT[3] < m_unk170)) {
            pT[3] = m_unk170;
            if (m_unk17 == 0 && m_unk18 != 0) {
                m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
                pT[0] = (float)((m_unkD0 >> 16) & 0x7FFF);
                m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
                pT[1] = (float)((m_unkD0 >> 16) & 0x7FFF);
                m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
                pT[2] = (float)((m_unkD0 >> 16) & 0x7FFF);
                sceVu0ScaleVectorXYZ(pT, pT, 0.000030517578125f);
                float *pA = m_unk100;
                float *pB = m_unk160;
                asm {
                    lqc2 vf1, 0x0(pT)
                    lqc2 vf2, 0x0(pA)
                    lqc2 vf3, 0x0(pB)
                    vsub.xyz vf4, vf2, vf2
                    vsub.xyz vf4, vf4, vf2
                    vsub.xyz vf5, vf2, vf4
                    vmul.xyz vf6, vf5, vf1
                    vadd.xyz vf7, vf6, vf4
                    vadd.xyz vf1, vf7, vf3
                    sqc2 vf1, 0x0(pT)
                }
                *(u_long128 *)(pT + 4) = *(u_long128 *)m_unkF0;
                pT[3] = 0.0f;
            } else {
                nDone++;
                if (nDone >= m_unk120) {
                    m_unk16 = m_unk17;
                    m_unk15 = 0;
                    return;
                }
            }
        }
        t = pT[3] / m_unk170;
        if (m_unk178 != 0) {
            pO = (float *)((char *)apFxInstances + i * 96);
            *(u_long128 *)pO = *(u_long128 *)m_unk180;
            *(u_long128 *)(pO + 4) = *(u_long128 *)((char *)this + 0x194);
            *(u_long128 *)(pO + 8) = *(u_long128 *)((char *)this + 0x1A8);
            fMul = m_unk124 * t;
            asm {
                lqc2 vf1, 0x10(pT)
                lqc2 vf2, 0x0(pT)
                lqc2 vf5, 0x30(pO)
                mfc1 $t0, $f0
                qmtc2.i $t0, vf3
                vmulx.xyz vf4, vf1, vf3x
                vnop
                vnop
                vnop
                vadd.xyz vf5, vf4, vf2
                vnop
                vnop
                vnop
                sqc2 vf5, 0x30(pO)
            }
            pO[15] = 1.0f;
            pO[16] = 1.0f;
            pO[17] = 1.0f;
            pO[18] = 1.0f;
            if (_dpfgt(fptodp(t), 0x3FE999999999999ALL) != 0) {
                pO[19] = m_unk134 + (t - 0.8f) / (1.0f - 0.8f) * (m_unk138 - m_unk134);
            } else {
                pO[19] = m_unk134;
            }
        } else {
            pO = (float *)((char *)apLines + (i << 5));
            *(u_long128 *)(pO + 4) = *(u_long128 *)(pT + 4);
            fMul = m_unk124 * t;
            asm {
                lqc2 vf1, 0x10(pT)
                lqc2 vf2, 0x0(pT)
                lqc2 vf5, 0x0(pO)
                mfc1 $t0, $f0
                qmtc2.i $t0, vf3
                vmulx.xyz vf4, vf1, vf3x
                vnop
                vnop
                vnop
                vadd.xyz vf5, vf4, vf2
                vnop
                vnop
                vnop
                sqc2 vf5, 0x0(pO)
            }
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            pO[3] = m_unk130 + (m_unk12C - m_unk130) * ((float)((m_unkD0 >> 16) & 0x7FFF) * 0.000030517578125f);
            if (_dpfgt(fptodp(t), 0x3FE999999999999ALL) != 0) {
                pO[7] = m_unk134 + (t - 0.8f) / (1.0f - 0.8f) * (m_unk138 - m_unk134);
            } else {
                pO[7] = m_unk134;
            }
        }
    }
}

// FUNCTION: 0x00203F40 Create__16PParticleTracersFP24tagParticleTracersParamsfff
int PParticleTracers::Create(tagParticleTracersParams *pParams, float fA, float fB, float fC) {
    CDS_ASSERT(0x24, pParams);
    if (PParticleSystem::Create(pParams->m_unk40, false) == 0) {
        return 0;
    }
    memcpy(&m_unkE0, pParams, 0x70);
    m_unk0C = 0x19;
    m_unk30 = 0x48;
    memcpy(&m_unkE0, pParams, 0x70);
    m_unkE0[0] += fA;
    m_unkE0[1] += fB;
    m_unkE0[2] += fC;
    *(u_long128 *)m_unk160 = *(u_long128 *)m_unkE0;
    m_unk150 = (int)(0.5f + (12335.0f + (18991.0f * ((float)rand() / 2.1474836e9f))));
    m_unk170 = 15.0f + (15.0f * (1.0f - m_unk128));
    m_unk80 = m_unk160[0];
    m_unk84 = m_unk160[1];
    m_unk88 = m_unk160[2];
    m_unk8C = 0x3F800000;
    m_unk90 = m_unk124;
    m_unk94 = m_unk124;
    m_unk98 = m_unk124;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    sceVu0ScaleVectorXYZ(&m_unkC0, m_unk110, 1.0f / 255.0f);
    m_unkCC = 1.0f;
    m_unk174 = __nwa__FUi(m_unk04 << 5);
    if (m_unk174 == 0) {
        return 0;
    }
    if (m_unk13C != 0) {
        m_unk178 = (int)GetResource__16PParticleManagerFUi((void *)(gGfxEng + 0x154F00), m_unk13C);
    }
    return 1;
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
