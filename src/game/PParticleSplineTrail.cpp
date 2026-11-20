// FLAGS: -str readonly
#include "types.h"
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

// DRAFT: 0x001F0E20 Start__20PParticleSplineTrailFv
// note: 8 words differ; the loop matches except the offset and constant registers swap (orig offset a3, const a1). Declaration order variants did not change it.
void PParticleSplineTrail::Start() {
    m_unk160 = 1.0f;
    int nVal = 0xC9742400;
    int nOffset = 0;
    for (unsigned int i = 0; i < m_unk04; i++) {
        *(int *)((char *)m_unk08 + nOffset) = nVal;
        *(int *)((char *)m_unk08 + nOffset + 8) = nVal;
        nOffset += 0x20;
    }
    m_unk15 = 1;
    m_unk18 = 1;
}

// DRAFT: 0x001F0E80 ComputeVuSplineKeys__20PParticleSplineTrailFP13tagVuParticleiP14tagVuSplineKeyi
// note: 10 words differ after 8 attempts (second-loop temp slots and register assignment). Tried: if (0 < nCount-3) (79->39), pSrc/pDst decl swap (39->33), vB0/vC0/vD0 reorder (33->24), if (1 < nCount-1) (24->15), pNext before pCur (15->10), if (nCount >= 3) (101, reverted).
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
            char *pNext2 = (char *)pKeys + ((nI + 2) << 6);
            char *pNext3 = (char *)pKeys + ((nI + 3) << 6);
            float vB0[4];
            float vC0[4];
            float vD0[4];
            sceVu0SubVector(vD0, pNext, pCur);
            sceVu0SubVector(vB0, pNext2, pNext);
            sceVu0AddVector(vB0, vD0, vB0);
            sceVu0ScaleVector(pCur + 0x20, vB0, fHalf);
            sceVu0SubVector(vD0, pNext2, pNext);
            sceVu0SubVector(vC0, pNext3, pNext2);
            sceVu0AddVector(vC0, vD0, vC0);
            sceVu0ScaleVector(pCur + 0x30, vC0, fHalf);
            nI += 1;
            nOff += 0x40;
        } while (nI < nCount - 3);
    }
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
// note: 14 words differ. Original loads m_unk128 before m_unk160 and subtracts as m160-m128 (sub.s f0,f0,f1); no ordering of the local reproduces both. The fDelta tail compiles as bc1t+jal, original as bc1f+b to a shared exit; empty-then, early-return and else-return forms all gave the same layout.
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
