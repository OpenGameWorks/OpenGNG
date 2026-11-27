// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PParticleSplineTrail.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern "C" void sceVu0AddVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0SubVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0ScaleVector(void *pDst, void *pSrc, float fScale);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern unsigned char __vt__20PParticleSplineTrail[];
// TODO(header): gGfxEng is the PGfxEngine global; only m_unk154C80 (display list pointer) is used here.
struct PGfxEngineRef {
    char _pad000[0x154C80];
    void *m_unk154C80;
};
extern PGfxEngineRef gGfxEng;
extern unsigned char fx_spline_blurhaze_fan_clip_init[];
extern unsigned char fx_spline_particle_clip_init[];
extern "C" int printf(const char *, ...);
extern "C" void *AllocParticles__12PDisplayListFii(void *, int, int);
extern "C" void BeginFxLoop__12PDisplayListFUi(void *, unsigned int);
extern "C" void DrawSplineParticles__12PDisplayListFP14tagVuSplineKeyiifbi(void *, void *, int, int, float, bool, int);
extern "C" void SetBlurHazeSourcePoint__10PGfxEngineFPff(void *, float *, float);
extern "C" void SetMaterial__10PGfxEngineFPfbUlUl(void *, float *, bool, unsigned long, unsigned long);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *, void *);
extern "C" float sqrtf(float);
extern "C" int rand(void);
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("PParticleSplineTrail.cpp", line, #cond))

// DRAFT: 0x001F0E20 Start__20PParticleSplineTrailFv
// note: 7 words differ; the nOffset and nVal registers still swap (orig offset a3, const a1). Tried (8 attempts): nOffset-before-nVal, unsigned nVal, unsigned nOffset, nOffset/i/nVal order, split nVal assignment, nVal in the for-init (7), inline literal (7).
void PParticleSplineTrail::Start() {
    m_unk160 = 1.0f;
    int nVal = 0xC9742400;
    int nOffset;
    unsigned int i;
    for (i = 0, nOffset = 0; i < m_unk04; i++) {
        *(int *)((char *)m_unk08 + nOffset) = nVal;
        *(int *)((char *)m_unk08 + nOffset + 8) = nVal;
        nOffset += 0x20;
    }
    m_unk15 = 1;
    m_unk18 = 1;
}

// FUNCTION: 0x001F0E80 ComputeVuSplineKeys__20PParticleSplineTrailFP13tagVuParticleiP14tagVuSplineKeyi
void PParticleSplineTrail::ComputeVuSplineKeys(struct tagVuParticle *pParticles, int nUnused, struct tagVuSplineKey *pKeys, int nCount) {
    float fHalf = (1.0f - m_unk124) / 2.0f;
    int nIdx = m_unk140;
    int nStep = 1;
    if (1 < (nCount - 1)) {
        int nOff = 0x40;
        do {
            char *pSrc = (char *)pParticles + (nIdx << 5);
            char *pDst = (char *)pKeys + nOff;
            sceVu0CopyVector(pDst, (float *)pSrc);
            sceVu0CopyVector(pDst + 0x10, (float *)(pSrc + 0x10));
            nIdx -= 1;
            if (nIdx < 0) {
                nIdx = nUnused - 1;
            }
            nStep += 1;
            nOff += 0x40;
        } while (nStep < nCount - 1);
    }
    memcpy(pKeys, (char *)pKeys + 0x40, 0x40);
    memcpy((char *)pKeys + ((nCount - 1) << 6), (char *)pKeys + ((nCount - 2) << 6), 0x40);
    if (0 < (nCount - 3)) {
        int nI = 0;
        int nOff = 0;
        do {
            char *pNext = (char *)pKeys + ((nI + 1) << 6);
            char *pCur = (char *)pKeys + nOff;
            float vB0[4];
            float vC0[4];
            float vD0[4];
            sceVu0SubVector(vD0, pNext, pCur);
            char *pNext2 = (char *)pKeys + ((nI + 2) << 6);
            sceVu0SubVector(vB0, pNext2, pNext);
            sceVu0AddVector(vB0, vD0, vB0);
            sceVu0ScaleVector(pCur + 0x20, vB0, fHalf);
            sceVu0SubVector(vD0, pNext2, pNext);
            char *pNext3 = (char *)pKeys + ((nI + 3) << 6);
            sceVu0SubVector(vC0, pNext3, pNext2);
            sceVu0AddVector(vC0, vD0, vC0);
            sceVu0ScaleVector(pCur + 0x30, vC0, fHalf);
            nI += 1;
            nOff += 0x40;
        } while (nI < nCount - 3);
    }
}

static inline float Jitter(float fR) {
    return -fR + 2.0f * fR * ((float)rand() / 2.1474836e9f);
}

// DRAFT: 0x001F1090 UpdateTrailKeys__20PParticleSplineTrailFv
// note: DIFF ~140 words; 5th float reg (f24) and 0x10 larger frame: 2.0f*fR is CSE'd (original recomputes fR+fR per axis, no hoisted 2.0f); goto entry still becomes blez. Tried inline Jitter helper, (fR+fR), bare if(m_unk120), goto loop, hoisted fFrac.
void PParticleSplineTrail::UpdateTrailKeys() {
    m_unk140 += 1;
    if (m_unk140 >= (int)m_unk04) {
        m_unk140 = 0;
    }
    float fT = 0.0f;
    float *pKey = (float *)((char *)m_unk08 + (m_unk140 << 5));
    pKey[0] = m_unk150[0];
    pKey[1] = m_unk150[1];
    pKey[2] = m_unk150[2];
    int nI = (int)m_unk04;
    int nIdx = m_unk140;
    float vDiff[4];
    sceVu0SubVector(vDiff, m_unk100, m_unkF0);
    float fRange = m_unk11C - m_unk118;
    float fFrac;
    goto test;
loop:
    {
        fFrac = fT / (float)(unsigned int)(m_unk04 - 1);
        pKey = (float *)((char *)m_unk08 + (nIdx << 5));
        if (pKey[0] == -1000000.0f) {
            ((int *)pKey)[7] = 0;
            pKey[3] = 0.0f;
        } else {
            if (m_unk120) {
                float fR = 0.3f * m_unk120 * fFrac;
                pKey[0] = pKey[0] + Jitter(fR);
                pKey[1] = pKey[1] + Jitter(fR);
                pKey[2] = pKey[2] + Jitter(fR);
            }
            pKey[3] = m_unk118 + fFrac * fRange;
            float *pOut = pKey + 4;
            float *pBase = m_unkF0;
            float *pDiff = vDiff;
            asm {
                lqc2 vf1, 0x0(pDiff)
                lqc2 vf2, 0x0(pBase)
                mfc1 t0, fFrac
                qmtc2.i t0, vf3
                vmulx.xyzw vf4, vf1, vf3x
                vnop
                vnop
                vnop
                vadd.xyzw vf5, vf4, vf2
                vnop
                vnop
                vnop
                sqc2 vf5, 0x0(pOut)
            }
        }
        nIdx -= 1;
        nI -= 1;
        if (nIdx < 0) {
            nIdx = (int)m_unk04 - 1;
        }
        fT += 1.0f;
    }
test:
    if (nI > 0) goto loop;
}

// FUNCTION: 0x001F1340 SetPosition__20PParticleSplineTrailFPfPf
void PParticleSplineTrail::SetPosition(float *pFrom, float *pTo) {
    sceVu0CopyVector(m_unk150, pFrom);
    m_unk80 = m_unk150[0];
    m_unk84 = m_unk150[1];
    m_unk88 = m_unk150[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001F1390 ModifyPosition__20PParticleSplineTrailFP5PMat4
void PParticleSplineTrail::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk150, m_unkE0);
    m_unk80 = m_unk150[0];
    m_unk84 = m_unk150[1];
    m_unk88 = m_unk150[2];
    m_unk8C = 0x3F800000;
}

// DRAFT: 0x001F13E0 Render__20PParticleSplineTrailFv
// note: 101 words differ; this lives in s2 (orig s0), nCount in s0 (orig s1). Tried else-return early exit (123->101, kept), hoisted nCount (109), nested ifs (101, no change).
void PParticleSplineTrail::Render() {
    if ((m_unk15 != 0) && (m_unk14 != 0) && (m_unkA4 != 0)) {
        if (m_unk08 != 0) {
        int nCount = m_unk110 + 2;
        float *pKeys = (float *)AllocParticles__12PDisplayListFii(gGfxEng.m_unk154C80, nCount, 4);
        if (pKeys == 0) {
            printf("\nToo many particles! Particles pool is full. Spline trail not rendered!\n");
            return;
        }
        ComputeVuSplineKeys((struct tagVuParticle *)m_unk08, m_unk04, (struct tagVuSplineKey *)pKeys, nCount);
        float vec[4];
        sceVu0CopyVector(vec, &m_unkC0);
        vec[3] *= m_unk160;
        if (m_unk19 != 0) {
            SetMaterial__10PGfxEngineFPfbUlUl(&gGfxEng, vec, true, (unsigned long)m_unk30, 0x50000);
            SetWorldMatrix__10PGfxEngineFP5PMat4(&gGfxEng, &m_unk40);
            SetBlurHazeSourcePoint__10PGfxEngineFPff(&gGfxEng, pKeys, pKeys[3]);
            BeginFxLoop__12PDisplayListFUi(gGfxEng.m_unk154C80, ((unsigned int)fx_spline_blurhaze_fan_clip_init + 0x1C88) >> 3);
            DrawSplineParticles__12PDisplayListFP14tagVuSplineKeyiifbi(gGfxEng.m_unk154C80, pKeys, nCount, m_unk114, 1.0f / (float)m_unk114, false, 30);
            return;
        }
        SetMaterial__10PGfxEngineFiPfbUlUl(&gGfxEng, m_unk10, vec, true, (unsigned long)m_unk30, 0x50000);
        SetWorldMatrix__10PGfxEngineFP5PMat4(&gGfxEng, &m_unk40);
        BeginFxLoop__12PDisplayListFUi(gGfxEng.m_unk154C80, ((unsigned int)fx_spline_particle_clip_init + 0x778) >> 3);
        DrawSplineParticles__12PDisplayListFP14tagVuSplineKeyiifbi(gGfxEng.m_unk154C80, pKeys, nCount, m_unk114, 1.0f / (float)m_unk114, true, 30);
        } else {
            return;
        }
    }
}

// DRAFT: 0x001F1600 FrustrumTest__20PParticleSplineTrailFP9PFrustrumPfff
// note: DIFF 26 after 6 attempts (2 of 8 budget left). Differs in the bc1t target (+0x27 orig, +0x25 ours) at the dist<=fB branch and the clamp/store ordering. Tried: early-return dist<=fB (46), fDist>fB/else store (38), fVal-based clamp (28), unconditional store with fClamp (42), fClamp=1.0f init with conditional store (26, kept), fClamp>=1 test (31).
void PParticleSplineTrail::FrustrumTest(PFrustrum *pFrustum, float *pVec, float fA, float fB) {
    float vTmp[4];
    float fDist;
    float fVal;
    float fClamp;
    m_unkA4 = 1;
    ((PMat4 *)((char *)this + 0x40))->MulVector(vTmp, (float *)((char *)this + 0x80));
    sceVu0SubVector(vTmp, pVec, vTmp);
    fDist = vTmp[0] * vTmp[0] + vTmp[1] * vTmp[1] + vTmp[2] * vTmp[2];
    if (fDist > fB) {
        fVal = 1.0f - (fDist - fB) / (fA - fB);
        m_unkCC = fVal;
        fClamp = 1.0f;
        if (fVal < 1.0f) {
            fClamp = fVal;
        }
        if (fClamp <= 0.0f) {
            fClamp = 0.0f;
        } else if (fVal >= 1.0f) {
            fClamp = 1.0f;
        }
        if (fClamp == 0.0f) {
            m_unkCC = fClamp;
            m_unkA4 = 0;
        }
    } else {
        m_unkCC = 1.0f;
    }
}

// DRAFT: 0x001F1740 Animate__20PParticleSplineTrailFf
// note: 14 words differ (5 attempts). Original loads m_unk128 before m_unk160 and subtracts as m160-m128 (sub.s f0,f0,f1); no ordering of the local reproduces both. The fDelta tail compiles as bc1t+jal, original as bc1f+b to a shared exit; empty-then, early-return, else-return, trailing-return, goto-exit and reversed `0.0f == fDelta` forms all gave 14.
void PParticleSplineTrail::Animate(float fDelta) {
    if ((m_unk18 == 0) || (m_unk17 != 0)) {
        float fVal = m_unk160 - m_unk128;
        m_unk160 = fVal;
        if (fVal <= 0.0f) {
            m_unk160 = 0.0f;
            m_unk15 = 0;
            m_unk16 = m_unk17;
        }
    }
    if ((m_unk15 != 0) && (m_unk16 == 0) && (m_unkA4 != 0)) {
        if (fDelta == 0.0f) {
            return;
        } else {
            UpdateTrailKeys();
        }
    }
}

// DRAFT: 0x001F17F0 Create__20PParticleSplineTrailFP28tagParticleSplineTrailParamsfff
// note: DIFF 133 words; clamp of m_unk110/114 uses wrong branch shape and register (v0 vs v1), m_unk128 divide operand order, and every later word is shifted. Tried: lower-first, upper-first, else-if, ternary clamps.
int PParticleSplineTrail::Create(struct tagParticleSplineTrailParams *pParams, float fA, float fB, float fC) {
    CDS_ASSERT(27, pParams);
    memcpy((char *)this + 0xE0, pParams, 0x60);
    int n110 = m_unk110;
    if (n110 < 5) {
        n110 = 4;
    } else if (n110 >= 0x1C) {
        n110 = 0x1C;
    }
    m_unk110 = n110;
    int n114 = m_unk114;
    if (n114 < 5) {
        n114 = 4;
    } else if (n114 >= 0x3C) {
        n114 = 0x3C;
    }
    m_unk114 = n114;
    if (m_unk128 <= 0.0f) {
        m_unk128 = 0.1428571f;
    }
    m_unk128 = 1.0f / m_unk128;
    m_unkE0[0] += fA;
    m_unkE0[1] += fB;
    m_unkE0[2] += fC;
    m_unkE0[3] = 1.0f;
    sceVu0CopyVector(m_unk150, m_unkE0);
    if (PParticleSystem::Create(m_unk110, true) == 0) {
        return 0;
    }
    m_unk0C = 0xD;
    m_unk140 = 0;
    m_unk160 = 1.0f;
    for (unsigned int i = 0; i < m_unk04; i++) {
        float *p = (float *)((char *)m_unk08 + i * 0x20);
        p[0] = -1000000.0f;
        p[1] = -1000000.0f;
        p[2] = -1000000.0f;
    }
    if (m_unk118 <= m_unk11C) {
        m_unkA0 = m_unk118;
    } else {
        m_unkA0 = m_unk11C;
    }
    m_unk80 = m_unk150[0];
    m_unk84 = m_unk150[1];
    m_unk88 = m_unk150[2];
    m_unk8C = 0x3F800000;
    m_unk90 = m_unkA0;
    m_unk94 = m_unkA0;
    m_unk98 = m_unkA0;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001F1A70 __dt__20PParticleSplineTrailFv
extern "C" void *__dt__20PParticleSplineTrailFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__20PParticleSplineTrail;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F1AD0 __ct__20PParticleSplineTrailFv
extern "C" void *__ct__20PParticleSplineTrailFv(void *pThis) {
    __ct__15PParticleSystemFv(pThis);
    *(void **)pThis = __vt__20PParticleSplineTrail;
    return pThis;
}
