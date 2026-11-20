#include "types.h"
#include "PParticleLiteFire.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void __dla__FPv(void *);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern unsigned char __vt__17PParticleLiteFire[];
extern char gGfxEng[1504384];
extern "C" void sceVu0SubVector(float *pDst, float *pSrc0, float *pSrc1);
extern "C" void sceVu0AddVector(float *pDst, float *pSrc0, float *pSrc1);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void Vu0_SinCos(void);
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, int nCount, int nSize);
extern "C" void DmaScratchPadToMainMem__FPvPvsbb(void *pSpad, void *pMain, short nSize, bool bFlagA, bool bFlagB);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pMsg);

// Advances the LCG seed and returns the sampled value scaled to [0, 1).
static inline float NextRandom(int *pSeed) {
    *pSeed = (*pSeed * 0x343FD) + 0x269EC3;
    return 0.000030517578f * (float)((*pSeed >> 0x10) & 0x7FFF);
}

// DRAFT: 0x001C9560 AnimateRotatableParticles__17PParticleLiteFireFf
// note: VU0 bounds, Vu0_SinCos rotation and the VU0 output stores are scalar approximations; compiles, not matched.
void PParticleLiteFire::AnimateRotatableParticles(float fDt) {
    unsigned int nAlive = 0;
    unsigned int i;
    unsigned int k;
    float fStep = fDt;
    float fFade;
    float fLo;
    float fHi;
    float fMin;
    float fMax;
    float fRate;
    float fT;
    float fAngle;
    float fScale;
    float fTri;
    float fWave;
    float fSpin;
    float fRadius;
    float sp80[4];
    float sp90[4];
    float spA0[4];
    float bMin[4];
    float bMax[4];
    float spE[4];
    float spF[4];
    float *pAge;
    void *pOut;

    if (m_unk16 != 0) {
        return;
    }
    if (m_unk17 == 0 && m_unk18 != 0 && m_unk190 == 0 && m_unkA4 != 0 && m_unk15 == 0) {
        return;
    }
    if (m_unk190 != 0) {
        fFade = m_unk18C - fStep;
        m_unk18C = fFade;
        if (fFade <= 0.0f) {
            m_unk17 = 1;
            m_unk18 = 0;
            m_unk190 = 0;
            m_unk18C = 0.0f;
        }
    }
    m_unkD0 = m_unk188;
    fLo = m_unk138 - m_unk134;
    fHi = m_unk13C - m_unk138;
    sceVu0SubVector(sp80, (float *)(_pad0E0 + 0x20), (float *)(_pad0E0 + 0x10));
    sceVu0SubVector(sp90, (float *)(_pad0E0 + 0x30), (float *)(_pad0E0 + 0x20));
    spA0[0] = m_unk120;
    spA0[1] = m_unk124;
    spA0[2] = m_unk128;
    spA0[3] = 0.75f * m_unk14C;
    if (m_unk154 != 0) {
        for (k = 0; k < 3; k++) {
            bMin[k] = 1000000.0f;
            bMax[k] = -1000000.0f;
        }
    }
    pOut = AllocParticles__12PDisplayListFii(gGfxEng + 0x154C80, m_unk04, 3);
    if (pOut == 0) {
        CdsAssert__FPciPc("PParticleLiteFire.cpp", 0x26C, "apVuParticles");
    }
    m_unk08 = pOut;
    if (m_unk04 < 0xABU) {
        pOut = (void *)0x70001000;
        if ((m_unk04 * 0x30) >= 0x2001U) {
            CdsAssert__FPciPc("PParticleLiteFire.cpp", 0x274, "(sizeof(VuRotatableParticle) * muNumParticles) <= SPAD_TEMP_BUFFER_SIZE");
        }
    }
    if (m_unk18 == 0 || m_unk17 != 0) {
        fStep *= 2.0f;
    }

    i = 0;
    while (i < m_unk04) {
        fRate = m_unk148;
        pAge = m_unk180 + i;
        *pAge += fStep * (fRate + ((1.0f - fRate) * NextRandom(&m_unkD0)));
        if (!(*pAge < m_unk184)) {
            *pAge = m_unk184;
            if (m_unk17 != 0 || m_unk18 == 0) {
                nAlive++;
                if (nAlive >= m_unk130) {
                    m_unk16 = m_unk17;
                    m_unk15 = 0;
                    return;
                }
            } else {
                *pAge -= m_unk184;
                if (m_unk160 != 0) {
                    *(u_long128 *)((char *)m_unk160 + (i * 0x10)) = *(u_long128 *)m_unk170;
                }
            }
        }

        fMin = *(float *)&m_unk20;
        fMax = *(float *)&m_unk24;
        fAngle = *pAge * (fMin + ((fMax - fMin) * NextRandom(&m_unkD0)));
        while (fAngle > 180.0f || fAngle < -180.0f) {
            if (fAngle > 180.0f) {
                fAngle -= 360.0f;
            } else {
                fAngle += 360.0f;
            }
        }

        fT = *pAge / m_unk184;
        if (!(fT < 0.9999999f)) {
            fT = 0.9999999f;
        }
        fScale = fT * (0.5f + (3.5f * NextRandom(&m_unkD0)));
        fTri = fScale - (float)(int)fScale;
        if (fTri <= 0.5f) {
            fWave = -1.0f + (4.0f * fTri);
        } else {
            fWave = 1.0f + (-4.0f * (fTri - 0.5f));
        }
        fSpin = fWave * m_unk150;

        spE[0] = NextRandom(&m_unkD0);
        spE[1] = NextRandom(&m_unkD0);
        spE[2] = NextRandom(&m_unkD0);
        spE[3] = NextRandom(&m_unkD0);
        if (fT <= 0.5f) {
            fRadius = spE[3] * (m_unk134 + (2.0f * (fT * fLo)));
        } else {
            fRadius = spE[3] * (m_unk138 + (2.0f * ((fT - 0.5f) * fHi)));
        }
        spE[3] = fRadius;

        spF[0] = fSpin;
        spF[1] = fT * m_unk140;
        spF[2] = -fSpin;
        spF[3] = 0.0f;
        sceVu0AddVector((float *)((char *)pOut + (i * 0x30)), spE, spF);

        if (m_unk154 != 0) {
            float *pV = (float *)((char *)pOut + (i * 0x30));
            for (k = 0; k < 3; k++) {
                if (pV[k] < bMin[k]) {
                    bMin[k] = pV[k];
                }
                if (pV[k] > bMax[k]) {
                    bMax[k] = pV[k];
                }
            }
        }
        i++;
    }
    if (((int)pOut & 0x70000000) == 0x70000000) {
        DmaScratchPadToMainMem__FPvPvsbb(pOut, m_unk08, (short)(m_unk04 * 0x30), false, false);
    }
}

// FUNCTION: 0x001C9E70 Enable__17PParticleLiteFireFb
void PParticleLiteFire::Enable(bool bEnable) {
    m_unk15 = bEnable;
    m_unk191 = (m_unk191 | !bEnable) != 0;
}

// DRAFT: 0x001C9EB0 FadeAndDie__17PParticleLiteFireFUi
// note: 4 words differ at 0x4C-0x58: original uses $v1 for constant 1 and $at for the compare; ours uses $a0 and $v1. Tried negated compare (DIFF 4), store moved after if (DIFF 6), local compare temp (more diffs than 4).
void PParticleLiteFire::FadeAndDie(unsigned int nArg) {
    PParticleSystem::FadeAndDie(nArg);
    m_unk18C = (float)nArg;
    m_unk190 = 1;
    if (nArg >= 2U) {
        m_unk17 = 0;
    }
}

// FUNCTION: 0x001C9F30 ModifyPosition__17PParticleLiteFireFP5PMat4
void PParticleLiteFire::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk170, (float *)_pad0E0);
    if (m_unk191) {
        unsigned int i = 0;
        if (m_unk160) {
            for (i = 0; i < m_unk04; i++) {
                ((u_long128 *)m_unk160)[i] = *(u_long128 *)m_unk170;
            }
            m_unk191 = 0;
        }
    }
    m_unk80 = m_unk170[0];
    m_unk84 = m_unk170[1] + 0.5f * m_unk140;
    m_unk88 = m_unk170[2];
}

// FUNCTION: 0x001C9FE0 SetPosition__17PParticleLiteFireFPfPf
void PParticleLiteFire::SetPosition(float *pPos, float *pUnused) {
    sceVu0CopyVector(m_unk170, pPos);
    if (m_unk191) {
        unsigned int i = 0;
        if (m_unk160) {
            for (i = 0; i < m_unk04; i++) {
                ((u_long128 *)m_unk160)[i] = *(u_long128 *)m_unk170;
            }
            m_unk191 = 0;
        }
    }
    m_unk80 = m_unk170[0];
    m_unk84 = m_unk170[1] + 0.5f * m_unk140;
    m_unk88 = m_unk170[2];
    m_unk8C = 0x3F800000;
}

// DRAFT: 0x001CA090 Animate__17PParticleLiteFireFf
// note: size 0x6A8 vs 0xA04, DIFF 636 words; VU0 runs (lqc2/sqc2, vmulx/vadd, Vu0_SinCos, bbox vmini/vmax) are scalar stand-ins; sceVu0ScaleVector call and asm blocks not written.
void PParticleLiteFire::Animate(float fDt) {
    unsigned int nAlive = 0;
    unsigned int i;
    unsigned int k;
    float fStep = fDt;
    float fFade;
    float fLo;
    float fHi;
    float fRate;
    float fT;
    float fScale;
    float fTri;
    float fWave;
    float fSpin;
    float fRadius;
    float fSpan;
    float fHalf;
    float fSpreadA;
    float fSpreadB;
    float sp80[4];
    float sp90[4];
    float spC0[4];
    float spE[4];
    float spF[4];
    float bMin[4];
    float bMax[4];
    float sp100;
    float sp104;
    float *pAge;
    void *pOut;

    if (m_unk1B != 0) {
        AnimateRotatableParticles(fDt);
        return;
    }
    if (m_unk16 != 0) {
        return;
    }
    if (m_unk17 == 0 && m_unk18 != 0 && m_unk190 == 0) {
        if (m_unkA4 == 0 || m_unk15 == 0) {
            return;
        }
    }
    if (m_unk190 != 0) {
        fFade = m_unk18C - fStep;
        m_unk18C = fFade;
        if (fFade <= 0.0f) {
            m_unk17 = 1;
            m_unk18 = 0;
            m_unk190 = 0;
            m_unk18C = 0.0f;
        }
    }
    m_unkD0 = m_unk188;
    if (m_unk154 != 0) {
        for (k = 0; k < 3; k++) {
            bMin[k] = 1000000.0f;
            bMax[k] = -1000000.0f;
        }
    }
    fLo = m_unk138 - m_unk134;
    fHi = m_unk13C - m_unk138;
    sceVu0SubVector(sp80, (float *)(_pad0E0 + 0x20), (float *)(_pad0E0 + 0x10));
    sceVu0SubVector(sp90, (float *)(_pad0E0 + 0x30), (float *)(_pad0E0 + 0x20));
    spC0[0] = m_unk120;
    spC0[1] = m_unk124;
    spC0[2] = m_unk128;
    spC0[3] = 0.75f * m_unk14C;
    pOut = AllocParticles__12PDisplayListFii(gGfxEng + 0x154C80, m_unk04, 2);
    if (pOut == 0) {
        CdsAssert__FPciPc("PParticleLiteFire.cpp", 0xD3, "apVuParticles");
    }
    m_unk08 = pOut;
    if (m_unk04 < 0x101U) {
        pOut = (void *)0x70001000;
        if ((m_unk04 << 5) >= 0x2001U) {
            CdsAssert__FPciPc("PParticleLiteFire.cpp", 0xDB, "(sizeof(VuParticle) * muNumParticles) <= SPAD_TEMP_BUFFER_SIZE");
        }
    }
    if (m_unk18 == 0 || m_unk17 != 0) {
        fStep *= 2.0f;
    }

    i = 0;
    while (i < m_unk04) {
        fRate = m_unk148;
        pAge = m_unk180 + i;
        *pAge += fStep * (fRate + ((1.0f - fRate) * NextRandom(&m_unkD0)));
        if (!(*pAge < m_unk184)) {
            *pAge = m_unk184;
            if (m_unk17 != 0 || m_unk18 == 0) {
                nAlive++;
                if (nAlive >= m_unk130) {
                    m_unk16 = m_unk17;
                    m_unk15 = 0;
                    return;
                }
            } else {
                *pAge -= m_unk184;
                if (m_unk160 != 0) {
                    *(u_long128 *)((char *)m_unk160 + (i * 0x10)) = *(u_long128 *)m_unk170;
                }
            }
        }

        fT = *pAge / m_unk184;
        if (!(fT < 0.9999999f)) {
            fT = 0.9999999f;
        }
        fScale = fT * (0.5f + (3.5f * NextRandom(&m_unkD0)));
        fTri = fScale - (float)(int)fScale;
        if (fTri <= 0.5f) {
            fWave = -1.0f + (4.0f * fTri);
        } else {
            fWave = 1.0f + (-4.0f * (fTri - 0.5f));
        }
        fSpin = fWave * m_unk150;

        spE[0] = NextRandom(&m_unkD0);
        spE[1] = NextRandom(&m_unkD0);
        spE[2] = NextRandom(&m_unkD0);
        spE[3] = NextRandom(&m_unkD0);
        if (fT <= 0.5f) {
            fRadius = spE[3] * (m_unk134 + (2.0f * (fT * fLo)));
        } else {
            fRadius = spE[3] * (m_unk138 + (2.0f * ((fT - 0.5f) * fHi)));
        }
        spE[3] = fRadius;

        spF[0] = fSpin;
        spF[1] = fT * m_unk140;
        spF[2] = -fSpin;
        spF[3] = 0.0f;
        sceVu0AddVector((float *)((char *)pOut + (i << 5)), spE, spF);

        if (m_unk154 != 0) {
            float *pV = (float *)((char *)pOut + (i << 5));
            for (k = 0; k < 3; k++) {
                if (pV[k] < bMin[k]) {
                    bMin[k] = pV[k];
                }
                if (pV[k] > bMax[k]) {
                    bMax[k] = pV[k];
                }
            }
        }

        if (m_unk19 != 0) {
            NextRandom(&m_unkD0);
            fSpan = 0.001f + (0.0139999995f * m_unk28);
            fHalf = 0.2f * fSpan;
            fSpreadA = 2.0f * fHalf;
            fSpreadB = -fHalf;
            sp100 = fSpan + (fSpreadB + (fSpreadA * NextRandom(&m_unkD0)));
            sp104 = fSpan + (fSpreadB + (fSpreadA * NextRandom(&m_unkD0)));
        }
        i++;
    }
    if (((int)pOut & 0x70000000) == 0x70000000) {
        DmaScratchPadToMainMem__FPvPvsbb(pOut, m_unk08, (short)(m_unk04 * 2), false, false);
    }
}

// FUNCTION: 0x001CADE0 __dt__17PParticleLiteFireFv
PParticleLiteFire::~PParticleLiteFire() {
    *(unsigned char **)this = __vt__17PParticleLiteFire;
    if (m_unk180) {
        __dla__FPv(m_unk180);
        m_unk180 = 0;
    }
    if (m_unk160) {
        __dla__FPv(m_unk160);
        m_unk160 = 0;
    }
}

// FUNCTION: 0x001CAE80 __ct__17PParticleLiteFireFv
PParticleLiteFire::PParticleLiteFire() {
    *(unsigned char **)this = __vt__17PParticleLiteFire;
    m_unk180 = 0;
    m_unk160 = 0;
    m_unk18C = 0;
    m_unk190 = 0;
    m_unk191 = 0;
}
