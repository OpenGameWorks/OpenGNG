#include "types.h"
#include "PParticleLiteExplosion.h"
#include "PMat4.h"
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" int rand(void);
extern "C" float sqrtf(float x);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
void FastMath_VectorFabs(float *pDst, float *pSrc);
extern unsigned char __vt__22PParticleLiteExplosion[];
extern char gGfxEng[1504384];
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, int nCount, int nSize);
extern "C" void DmaScratchPadToMainMem__FPvPvsbb(void *pSpad, void *pMain, short nSize, bool bFlagA, bool bFlagB);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pMsg);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void Vu0_Normalize_Vector(void);
extern "C" float FastMath_Sin180__Ff(float fAngle);
extern "C" float FastMath_Cos180__Ff(float fAngle);

#define LITE_ASSERT(line, cond, msg) ((cond) ? (void)0 : CdsAssert__FPciPc("PParticleLiteExplosion.cpp", line, msg))

// Advances the LCG seed and returns its 15-bit high half.
static inline int LiteSeedStep(int *pSeed) {
    *pSeed = *pSeed * 0x343FD + 0x269EC3;
    return (*pSeed >> 16) & 0x7FFF;
}

// Advances the LCG seed and returns a sample in [0, 1).
static inline float LiteRand01(int *pSeed) {
    return 0.000030517578f * (float)LiteSeedStep(pSeed);
}

// DRAFT: 0x001F6610 AnimateRotatableParticles__22PParticleLiteExplosionFf
// note: 422 words differ. Normalize block is asm; SinCos block adds a word (reverted); vmini/vmax and vmulx/vadd have no draft C counterpart; frame 0xC0 vs 0xB0 shifts saves.
void PParticleLiteExplosion::AnimateRotatableParticles(float fDt) {
    float vSub[4];
    float vRand[4];
    float fA4;
    float fAC;
    unsigned int nHits;
    unsigned int i;
    void *pOut;
    float fF20;
    float fF21;

    nHits = 0;
    UpdateLoopDelay(fDt);
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk16 != 0) {
        return;
    }
    m_unkD0 = m_unk1C0;
    pOut = AllocParticles__12PDisplayListFii(gGfxEng + 0x154C80, m_unk04, 3);
    LITE_ASSERT(0x176, pOut != 0, "apVuParticles");
    m_unk08 = pOut;
    if (m_unk04 < 0xAB) {
        pOut = (void *)0x70001000;
        LITE_ASSERT(0x17E, (m_unk04 * 0x30) < 0x2001, "(sizeof(VuRotatableParticle) * muNumParticles) <= SPAD_TEMP_BUFFER_SIZE");
    }
    m_unk194 += fDt;
    sceVu0SubVector(vSub, m_unk140, m_unk130);
    fF20 = m_unk16C;
    for (i = 0; i < m_unk04; i++) {
        float *pP = (float *)((char *)pOut + i * 0x30);
        float fF6;
        float fAng;
        float fT;
        float fF3;
        float fTmp;
        bool bEmit = false;

        fF21 = m_unk194 * (fF20 + ((1.0f - fF20) * LiteRand01(&m_unkD0)));
        if (fF21 < m_unk190) {
            bEmit = true;
        } else {
            nHits += 1;
            fF21 = m_unk190;
            if (nHits < m_unk150) {
                bEmit = true;
            } else {
                fF21 = 0.0f;
                m_unk194 = 0.0f;
                m_unk1C0 = (int)(0.5f + (12345.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
                UpdateLoopCounter();
                *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk1B0;
                m_unk80 = m_unk1B0[0];
                m_unk84 = m_unk1B0[1];
                m_unk88 = m_unk1B0[2];
                m_unk8C = 0x3F800000;
                if (m_unk15 != 0) {
                    bEmit = true;
                }
            }
        }
        if (bEmit) {
            fF6 = *(float *)&m_unk20;
            fF3 = fF21 * (fF6 + ((*(float *)&m_unk24 - fF6) * LiteRand01(&m_unkD0)));
            while (!(fF3 <= 180.0f) || (fF3 < -180.0f)) {
                if (!(fF3 <= 180.0f)) {
                    fF3 -= 360.0f;
                } else {
                    fF3 += 360.0f;
                }
            }
            fT = fF21 / m_unk190;
            vRand[0] = (float)LiteSeedStep(&m_unkD0);
            vRand[1] = (float)LiteSeedStep(&m_unkD0);
            vRand[2] = (float)LiteSeedStep(&m_unkD0);
            vRand[3] = (float)LiteSeedStep(&m_unkD0);
            sceVu0ScaleVector(vRand, vRand, 0.000030517578f);
            {
                float *pLo = m_unkF0;
                float *pHi = m_unk100;
                float *pRnd = vRand;
                asm {
                    lqc2 vf1, 0x0(pLo)
                    lqc2 vf2, 0x0(pHi)
                    lqc2 vf3, 0x0(pRnd)
                    vsub.xyzw vf4, vf2, vf1
                    vmul.xyzw vf5, vf4, vf3
                    vadd.xyzw vf6, vf5, vf1
                    sqc2 vf6, 0x0(pRnd)
                    lqc2 vf5, 0x0(pRnd)
                    vcallms Vu0_Normalize_Vector
                }
            }
            pP[0] = vRand[0] * fT;
            pP[1] = vRand[1] * fT;
            pP[2] = vRand[2] * fT;
            fTmp = 0.75f * m_unk170;
            fAng = m_unk154 + (fT * (m_unk158 - m_unk154));
            pP[3] = fAng;
            pP[3] = fAng * (1.0f + (-fTmp + (2.0f * fTmp * LiteRand01(&m_unkD0))));
            fA4 = m_unk110[1] + ((m_unk120[1] - m_unk110[1]) * LiteRand01(&m_unkD0));
            fAC = 1.0f - (fT * m_unk168);
            if (m_unk164 != 0.0f) {
                fTmp = 0.75f * m_unk164;
                pP[1] = pP[1] - (fT * (fT * (fT * (m_unk164 + (-fTmp + (2.0f * fTmp * LiteRand01(&m_unkD0)))))));
            }
            pP[2] = fA4 * fAC;
        }
    }
    if (((int)pOut & 0x70000000) == 0x70000000) {
        DmaScratchPadToMainMem__FPvPvsbb(pOut, m_unk08, (short)(m_unk04 * 0x30), false, true);
    }
}

// FUNCTION: 0x001F6CF0 Start__22PParticleLiteExplosionFf
void PParticleLiteExplosion::Start(float fScale) {
    m_unk160 = fScale;
    m_unk90 = fScale;
    m_unk94 = m_unk160;
    m_unk98 = m_unk160;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    ((PParticleLiteExplosionView *)this)->Start();
}

// FUNCTION: 0x001F6D40 SetPosition__22PParticleLiteExplosionFPfPf
void PParticleLiteExplosion::SetPosition(float *pA, float *pB) {
    sceVu0CopyVector(m_unk1B0, pA);
}

// FUNCTION: 0x001F6D50 ModifyPosition__22PParticleLiteExplosionFP5PMat4
void PParticleLiteExplosion::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk1B0, m_unkE0);
}

// FUNCTION: 0x001F6D70 Start__22PParticleLiteExplosionFv
void PParticleLiteExplosion::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk194 = 0;
    m_unk1C0 = (int)(0.5f + (12345.0f + 41976.0f * ((float)rand() / 2147483648.0f)));
    *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk1B0;
    m_unk80 = m_unk1B0[0];
    m_unk84 = m_unk1B0[1];
    m_unk88 = m_unk1B0[2];
    m_unk8C = 0x3F800000;
}

// DRAFT: 0x001F6E30 Animate__22PParticleLiteExplosionFf
// note: compiles; VU0 runs are asm from the disasm mnemonics, loop follows AnimateRotatableParticles; frame layout and scheduling not compared yet
static inline float LiteRandOf(int nSeed) {
    return 0.000030517578f * (float)((nSeed >> 16) & 0x7FFF);
}

void PParticleLiteExplosion::Animate(float fDt) {
    float vSub[4];
    float vRnd[4];
    float vA3[4];
    float vA2[4];
    float vT0[4];
    float vT1[4];
    float vT2[4];
    float fF20;
    float fF21;
    float fT;
    float fAng;
    float fTmp;
    float fA4;
    float fAC;
    float fF5;
    float fF6;
    float fF7;
    float fTmp2;
    float fTmp4;
    float fF22b;
    float fF23;
    float fF21a;
    float fSin;
    float fCos;
    int nSeedA;
    int nSeedB;
    int nBits;
    unsigned int nHits;
    unsigned int i;
    char *pBase;
    void *pOut;
    float *pP;

    if (m_unk1B != 0) {
        AnimateRotatableParticles(fDt);
        return;
    }
    UpdateLoopDelay(fDt);
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk16 != 0) {
        return;
    }
    m_unkD0 = m_unk1C0;
    pOut = AllocParticles__12PDisplayListFii(*(void **)(gGfxEng + 0x154C80), m_unk04, 2);
    LITE_ASSERT(0x74, pOut != 0, "apVuParticles");
    m_unk08 = pOut;
    pBase = (char *)pOut;
    if (m_unk04 < 0x101) {
        pBase = (char *)0x70001000;
        LITE_ASSERT(0x7C, (unsigned int)(m_unk04 << 5) < 0x2001u, "(sizeof(VuParticle) * muNumParticles) <= SPAD_TEMP_BUFFER_SIZE");
    }
    m_unk194 += fDt;
    sceVu0SubVector(vSub, m_unk140, m_unk130);
    fF20 = m_unk16C;
    nHits = 0;
    for (i = 0; i < m_unk04; i++) {
        bool bEmit = false;

        pP = (float *)(pBase + (i << 5));
        fF21 = m_unk194 * (fF20 + ((1.0f - fF20) * LiteRand01(&m_unkD0)));
        if (fF21 < m_unk190) {
            bEmit = true;
        } else {
            nHits += 1;
            fF21 = m_unk190;
            if (nHits < m_unk150) {
                bEmit = true;
            } else {
                fF21 = 0.0f;
                m_unk194 = 0.0f;
                m_unk1C0 = (int)(0.5f + (12345.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
                UpdateLoopCounter();
                *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk1B0;
                m_unk80 = m_unk1B0[0];
                m_unk84 = m_unk1B0[1];
                m_unk88 = m_unk1B0[2];
                m_unk8C = 0x3F800000;
                if (m_unk15 != 0) {
                    bEmit = true;
                }
            }
        }
        if (bEmit) {
            fT = fF21 / m_unk190;
            vRnd[0] = (float)LiteSeedStep(&m_unkD0);
            vRnd[1] = (float)LiteSeedStep(&m_unkD0);
            vRnd[2] = (float)LiteSeedStep(&m_unkD0);
            vRnd[3] = (float)LiteSeedStep(&m_unkD0);
            sceVu0ScaleVector(vRnd, vRnd, 0.000030517578f);
            {
                float *pLo = m_unkF0;
                float *pHi = m_unk100;
                float *pRnd = vRnd;
                asm {
                    lqc2 vf1, 0x0(pLo)
                    lqc2 vf2, 0x0(pHi)
                    lqc2 vf3, 0x0(pRnd)
                    vsub.xyzw vf4, vf2, vf1
                    vmul.xyzw vf5, vf4, vf3
                    vadd.xyzw vf6, vf5, vf1
                    sqc2 vf6, 0x0(pRnd)
                    lqc2 vf5, 0x0(pRnd)
                    vcallms Vu0_Normalize_Vector
                }
            }
            fTmp = 0.75f * m_unk170;
            fAng = m_unk154 + (fT * (m_unk158 - m_unk154));
            pP[3] = fAng;
            pP[3] = fAng * (1.0f + (-fTmp + (2.0f * fTmp * LiteRand01(&m_unkD0))));
            fA4 = m_unk110[1] + ((m_unk120[1] - m_unk110[1]) * LiteRand01(&m_unkD0));
            fAC = 1.0f - (fT * m_unk168);
            {
                float *pA3 = vA3;
                float *pA2 = vA2;
                float *pT0 = vT0;
                float *pT1 = vT1;
                float *pT2 = vT2;
                float *pA1 = pP;
                nBits = 0;
                asm {
                    qmtc2.i nBits, vf0
                    lqc2 vf29, 0x0(pA3)
                    vmini.xz vf31, vf29, vf31
                    lqc2 vf30, 0x0(pA2)
                    lqc2 vf28, 0x0(pT0)
                    lqc2 vf27, 0x0(pT2)
                    lqc2 vf26, 0x0(pT1)
                    vmax.xz vf31, vf31, vf30
                    vmove.y vf31, vf28
                    vnop
                    vadd.xyzw vf26, vf26, vf27
                    vmulw.xyz vf31, vf31, vf28w
                    vnop
                    vnop
                    vnop
                    sqc2 vf31, 0x0(pA1)
                    sqc2 vf26, 0x0(pT2)
                }
            }
            nBits = *(int *)&fAC;
            {
                float *pA1 = pP;
                float *pT2 = vT2;
                float *pP5 = pP;
                asm {
                    lqc2 vf1, 0x0(pA1)
                    lqc2 vf2, 0x0(pT2)
                    lqc2 vf5, 0x0(pP5)
                    qmtc2.i nBits, vf3
                    vmulx.xyz vf4, vf1, vf3x
                    vnop
                    vnop
                    vnop
                    vadd.xyz vf5, vf4, vf2
                    vnop
                    vnop
                    vnop
                    sqc2 vf5, 0x0(pP5)
                }
            }
            fF6 = m_unk164;
            if (fF6 != 0.0f) {
                fF5 = 0.75f * fF6;
                pP[1] = pP[1] - (fT * (fT * (fT * (fF6 + (-fF5 + (2.0f * fF5 * LiteRand01(&m_unkD0)))))));
            }
            if (m_unk19 != 0) {
                fF5 = 30.0f * m_unk2C;
                LiteSeedStep(&m_unkD0);
                nSeedA = m_unkD0;
                LiteSeedStep(&m_unkD0);
                nSeedB = m_unkD0;
                LiteSeedStep(&m_unkD0);
                fF7 = 0.001f + (0.0139999995f * m_unk28);
                fTmp2 = 0.2f * fF7;
                fTmp4 = -fTmp2;
                fF21a = 180.0f * (((float)((int)(fF21 * (fF5 + (((0.5f * fF5) - fF5) * LiteRandOf(nSeedA)))) % 360) / 180.0f) - 1.0f);
                fF22b = fF7 + (fTmp4 + (2.0f * fTmp2 * LiteRandOf(nSeedB)));
                fF23 = fF7 + (fTmp4 + (2.0f * fTmp2 * LiteRandOf(m_unkD0)));
                fSin = FastMath_Sin180__Ff(fF21a);
                fCos = FastMath_Cos180__Ff(fF21a);
                pP[4] = fF22b * fCos;
                pP[5] = fF23 * fSin;
            } else {
                float *pOutD = pP + 4;
                float *pV130 = m_unk130;
                float *pSub = vSub;
                nBits = *(int *)&fT;
                asm {
                    lqc2 vf1, 0x0(pSub)
                    lqc2 vf2, 0x0(pV130)
                    qmtc2.i nBits, vf3
                    vmulx.xyzw vf4, vf1, vf3x
                    vadd.xyzw vf5, vf4, vf2
                    sqc2 vf5, 0x0(pOutD)
                }
            }
        }
    }
    if (((unsigned int)pBase & 0x70000000) == 0x70000000) {
        DmaScratchPadToMainMem__FPvPvsbb(pBase, m_unk08, (short)(m_unk04 * 2), false, true);
    }
}

// FUNCTION: 0x001F75C0 Create__22PParticleLiteExplosionFP30tagParticleLiteExplosionParamsfff
int PParticleLiteExplosion::Create(tagParticleLiteExplosionParams *pParams, float fA, float fB, float fC) {
    float aVec[4];

    if (!PParticleSystem::Create(pParams->m_unk70, false)) {
        return 0;
    }
    m_unk0C = 0x11;
    m_unk30 = 0x48;
    memcpy(m_unkE0, pParams, 0xB0);
    m_unk170 = 1.0f - m_unk170;
    m_unkE0[0] += fA;
    m_unkE0[1] += fB;
    m_unkE0[2] += fC;
    *(u_long128 *)m_unk1B0 = *(u_long128 *)m_unkE0;
    m_unk190 = 5.0f + 175.0f * (1.0f - m_unk15C);
    m_unk194 = 0;
    m_unk1C0 = (int)(0.5f + (12543.0f + 21978.0f * ((float)rand() / 2147483648.0f)));
    m_unk80 = m_unk1B0[0];
    m_unk84 = m_unk1B0[1];
    m_unk88 = m_unk1B0[2];
    m_unk8C = 0x3F800000;
    sceVu0SubVector(aVec, m_unk100, m_unkF0);
    FastMath_VectorFabs(aVec, aVec);
    m_unk90 = m_unk160 + aVec[0];
    m_unk94 = m_unk160 + aVec[1];
    m_unk98 = m_unk160 + aVec[2];
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001F77B0 __dt__22PParticleLiteExplosionFv
extern "C" void *__dt__22PParticleLiteExplosionFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__22PParticleLiteExplosion;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F7810 __ct__22PParticleLiteExplosionFv
extern "C" void *__ct__22PParticleLiteExplosionFv(void *pThis) {
    __ct__15PParticleSystemFv(pThis);
    *(void **)pThis = __vt__22PParticleLiteExplosion;
    return pThis;
}
