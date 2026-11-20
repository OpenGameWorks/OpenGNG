// FLAGS: -str readonly
#include "types.h"
#include "PParticleEnergyStream.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" float sqrtf(float x);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern unsigned char __vt__21PParticleEnergyStream[];
// TODO(header): gGfxEng is the PGfxEngine global; only m_unk154C80 (display list pointer) is used here.
struct PGfxEngineRef {
    char _pad000[0x154C80];
    void *m_unk154C80;
};
extern PGfxEngineRef gGfxEng;
extern unsigned char fx_spline_particle_clip_init[];
extern "C" int printf(const char *, ...);
extern "C" void *AllocParticles__12PDisplayListFii(void *, int, int);
extern "C" void BeginFxLoop__12PDisplayListFUi(void *, unsigned int);
extern "C" void DrawSplineParticles__12PDisplayListFP14tagVuSplineKeyiifbi(void *, void *, int, int, float, bool, int);
extern "C" void ComputeVuSplineKeys__21PParticleEnergyStreamFP13tagVuParticleiP14tagVuSplineKeyi(void *, void *, int, void *, int);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *, void *);

// FUNCTION: 0x001F5510 ComputeVuSplineKeys__21PParticleEnergyStreamFP13tagVuParticleiP14tagVuSplineKeyi
void PParticleEnergyStream::ComputeVuSplineKeys(tagVuParticle *pParticles, int nUnused, tagVuSplineKey *pKeys, int nCount) {
    float vecA[4];
    float vecB[4];
    float vecC[4];
    float fScale = (1.0f - m_unk130) / 2.0f;
    int nIdx = 1;
    if (1 < nCount - 1) {
        int nSrc = 0;
        int nDst = 0x40;
        do {
            sceVu0CopyVector((char *)pKeys + nDst, (float *)((char *)pParticles + nSrc));
            sceVu0CopyVector((char *)pKeys + nDst + 0x10, (float *)((char *)pParticles + nSrc + 0x10));
            nIdx += 1;
            nSrc += 0x20;
            nDst += 0x40;
        } while (nIdx < nCount - 1);
    }
    memcpy(pKeys, (char *)pKeys + 0x40, 0x40);
    memcpy((char *)pKeys + ((nCount - 1) << 6), (char *)pKeys + ((nCount - 2) << 6), 0x40);
    int nK = 0;
    if (0 < nCount - 3) {
        int nOff = 0;
        do {
            char *pNext = (char *)pKeys + ((nK + 1) << 6);
            char *pCur = (char *)pKeys + nOff;
            sceVu0SubVector(vecC, (float *)pNext, (float *)pCur);
            char *pNext2 = (char *)pKeys + ((nK + 2) << 6);
            sceVu0SubVector(vecA, (float *)pNext2, (float *)pNext);
            sceVu0AddVector(vecA, vecC, vecA);
            sceVu0ScaleVector((float *)(pCur + 0x20), vecA, fScale);
            sceVu0SubVector(vecC, (float *)pNext2, (float *)pNext);
            sceVu0SubVector(vecB, (float *)((char *)pKeys + ((nK + 3) << 6)), (float *)pNext2);
            sceVu0AddVector(vecB, vecC, vecB);
            sceVu0ScaleVector((float *)(pCur + 0x30), vecB, fScale);
            nK += 1;
            nOff += 0x40;
        } while (nK < nCount - 3);
    }
}

// FUNCTION: 0x001F56F0 SetPosition__21PParticleEnergyStreamFPfPf
void PParticleEnergyStream::SetPosition(float *pFrom, float *pTo) {
    sceVu0CopyVector(m_unkE0, pFrom);
    sceVu0CopyVector(m_unk180, pTo);
    sceVu0SubVector(m_unk110, m_unk180, m_unkE0);
    m_unk128 = sqrtf(sceVu0InnerProduct(m_unk110, m_unk110));
    sceVu0Normalize(m_unk110, m_unk110);
    if (m_unk08 == 0) {
        CdsAssert__FPciPc("PParticleEnergyStream.cpp", 0x12A, "mpVuParticles");
    }
    sceVu0CopyVector((char *)m_unk08 + ((m_unk04 - 1) << 5), m_unk180);
    sceVu0CopyVector(m_unk08, m_unkE0);
    m_unk80 = (m_unk180[0] + m_unkE0[0]) * 0.5f;
    m_unk84 = (m_unk180[1] + m_unkE0[1]) * 0.5f;
    m_unk88 = (m_unk180[2] + m_unkE0[2]) * 0.5f;
    *(float *)&m_unk8C = 1.0f;
    m_unk90 = m_unk128 * 0.5f;
    m_unk94 = m_unk128 * 0.5f;
    m_unk98 = m_unk128 * 0.5f;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
}

// FUNCTION: 0x001F5860 Start__21PParticleEnergyStreamFv
void PParticleEnergyStream::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk190 = 1.0f;
    m_unk19C = 0;
    m_unk194 = 1.0f;
}

// DRAFT: 0x001F58A0 Render__21PParticleEnergyStreamFv
// note: DIFF 80; size 0x170 vs 0x178. Original keeps bnez-to-body plus b-to-epilogue (ld ra in delay slot) for the m_unk08 return and loads the 0x154C80 offset before lw nCount; ours uses beqz and schedules differently. Tried nested if, early return, -str readonly; no change.
void PParticleEnergyStream::Render() {
    if (m_unk15 != 0 && m_unk14 != 0 && m_unkA4 != 0) {
        if (m_unk08 == 0) {
            return;
        }
        int nCount = m_unk124 + 2;
        void *pKeys = AllocParticles__12PDisplayListFii(gGfxEng.m_unk154C80, nCount, 4);
        if (pKeys == 0) {
            printf("\nToo many particles! Particles pool is full. Spline trail not rendered!\n");
            return;
        }
        ComputeVuSplineKeys__21PParticleEnergyStreamFP13tagVuParticleiP14tagVuSplineKeyi(this, m_unk08, m_unk04, pKeys, nCount);
        float vec[4];
        sceVu0CopyVector(vec, &m_unkC0);
        vec[3] *= m_unk190 * m_unk194;
        SetMaterial__10PGfxEngineFiPfbUlUl(&gGfxEng, m_unk10, vec, 1, (unsigned long)m_unk30, 0x50000);
        SetWorldMatrix__10PGfxEngineFP5PMat4(&gGfxEng, &m_unk40);
        BeginFxLoop__12PDisplayListFUi(gGfxEng.m_unk154C80, ((unsigned int)fx_spline_particle_clip_init + 0x778) >> 3);
        int nWidth = m_unk120;
        DrawSplineParticles__12PDisplayListFP14tagVuSplineKeyiifbi(gGfxEng.m_unk154C80, pKeys, nCount, nWidth, 1.0f / (float)nWidth, 0, 30);
    }
}

// FUNCTION: 0x001F6560 __dt__21PParticleEnergyStreamFv
extern "C" void *__dt__21PParticleEnergyStreamFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__21PParticleEnergyStream;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001F65C0 __ct__21PParticleEnergyStreamFv
// note: DIFF 15; original spills this to 0x1C(sp) and returns it in v0, ours keeps this in s0. Tried explicit base call (DIFF 16), memset on m_unkE0 (DIFF 15), -Cpp_exceptions on (DIFF 15).
PParticleEnergyStream::PParticleEnergyStream() {
    *(void **)this = __vt__21PParticleEnergyStream;
    memset((char *)this + 0xE0, 0, 0x90);
}
