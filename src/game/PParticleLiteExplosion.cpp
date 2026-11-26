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
// note: VU0 runs (lqc2/sqc2, vmini/vmax, vmulx/vadd, Vu0_SinCos, Vu0_Normalize_Vector) are scalar stand-ins; compiles, not matched.
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
