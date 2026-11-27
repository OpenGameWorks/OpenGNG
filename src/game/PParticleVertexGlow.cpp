// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PParticleVertexGlow.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void *__ct__7PFxMeshFv(void *);
extern "C" void *__dt__7PFxMeshFv(void *, short);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__19PParticleVertexGlow[];
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern char gGfxEng[1504384];
extern "C" void SetGlowSizeAndColor__10PGfxEngineFffPf(void *pThis, float fA, float fB, float *pColor);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void Render__7PFxMeshFv(void *pThis);
extern "C" bool Init__7PFxMeshFP6PMNodeP6PMNode(void *pThis, PMNode *poGlowObj, PMNode *poAnimObj);
extern "C" void sceVu0AddVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0SubVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0ScaleVector(void *pDst, void *pSrc, float fScale);

// FUNCTION: 0x001BE770 Start__19PParticleVertexGlowFv
void PParticleVertexGlow::Start() {
    m_unk15 = 1;
    m_unk374 = 0;
    m_unk37C = 0;
}

// FUNCTION: 0x001BE790 Stop__19PParticleVertexGlowFv
void PParticleVertexGlow::Stop() {
    *(unsigned char *)((char *)this + 0x18) = 0;
    *(unsigned char *)((char *)this + 0x15) = 0;
}

// FUNCTION: 0x001BE7A0 FadeAndDie__19PParticleVertexGlowFUi
void PParticleVertexGlow::FadeAndDie(unsigned int nUnused) {
    m_unk17 = 1;
    m_unk16 = 1;
    m_unk15 = 0;
    m_unk358 = 0;
    m_unkAC = 0;
}

// FUNCTION: 0x001BE7C0 FrustrumTest__19PParticleVertexGlowFP9PFrustrumPfff
void PParticleVertexGlow::FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar) {
    if (m_unk358 != 0) {
        sceVu0CopyMatrix((float (*)[4])&m_unk40, (float (*)[4])((char *)m_unk358 + 0x40));
        if (*(int *)((char *)m_unk358 + 0x28) != 0) {
            memcpy(&m_unk80, (void *)*(int *)((char *)m_unk358 + 0x28), 0x20);
            PParticleSystem::FrustrumTest(pFrustrum, pVec, fNear, fFar);
            return;
        }
        m_unkA4 = 1;
    }
}

// FUNCTION: 0x001BE870 Render__19PParticleVertexGlowFv
void PParticleVertexGlow::Render() {
    if (!m_unkA4 || !m_unk15 || !m_unk14) {
        return;
    }
    float fSize = m_unk370;
    SetGlowSizeAndColor__10PGfxEngineFffPf(gGfxEng, fSize, fSize, &m_unk360);
    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk10, &m_unkC0, true, m_unk30, 0x50000);
    Render__7PFxMeshFv(&m_unk340);
}

// DRAFT: 0x001BE900 Animate__19PParticleVertexGlowFf
// note: guard branches and timer-1 clamp order differ (DIFF 149); tried nested guards, merged && guard, early returns, if/else clamp, ternary clamp, empty-if m_unk14 form (166), else-return (149).
void PParticleVertexGlow::Animate(float fDelta) {
    if (m_unkA4 == 0) return;
    if (m_unk15 == 0) return;
    if (m_unk14 != 0) {
        {
            float fTime = m_unk37C + m_unk380 * fDelta;
            float fMax = m_unk114;
            float fMin = (fTime < fMax) ? fTime : fMax;
            if (fMin <= 0.0f) {
                m_unk37C = 0.0f;
            } else {
                m_unk37C = (fTime < fMax) ? fTime : fMax;
            }
            if (m_unk37C >= m_unk114 || m_unk37C <= 0.0f) {
                m_unk380 = -m_unk380;
            }
            float fRatio = m_unk37C / m_unk114;
            if (fRatio <= 0.5f) {
                sceVu0SubVector(&m_unk360, m_unkF0, m_unkE0);
                sceVu0ScaleVector(&m_unk360, &m_unk360, 2.0f * fRatio);
                sceVu0AddVector(&m_unk360, &m_unk360, m_unkE0);
            } else {
                sceVu0SubVector(&m_unk360, m_unk100, m_unkF0);
                sceVu0ScaleVector(&m_unk360, &m_unk360, 2.0f * (fRatio - 0.5f));
                sceVu0AddVector(&m_unk360, &m_unk360, m_unkF0);
            }
            float fTime2 = m_unk374 + m_unk378 * fDelta;
            float fMax2 = m_unk124;
            float fMin2 = (fTime2 < fMax2) ? fTime2 : fMax2;
            if (fMin2 <= 0.0f) {
                m_unk374 = 0.0f;
            } else {
                m_unk374 = (fTime2 < fMax2) ? fTime2 : fMax2;
            }
            if (m_unk374 >= m_unk124 || m_unk374 <= 0.0f) {
                m_unk378 = -m_unk378;
            }
            float fRatio2 = m_unk374 / m_unk124;
            if (fRatio2 <= 0.5f) {
                m_unk370 = m_unk118 + 2.0f * (fRatio2 * (m_unk11C - m_unk118));
            } else {
                m_unk370 = m_unk11C + 2.0f * ((fRatio2 - 0.5f) * (m_unk120 - m_unk11C));
            }
        }
    } else {
        return;
    }
}

// FUNCTION: 0x001BEBF0 Create__19PParticleVertexGlowFP27tagParticleVertexGlowParamsP6PMNodeP6PMNode
bool PParticleVertexGlow::Create(tagParticleVertexGlowParams *pParams, PMNode *poGlowObj, PMNode *poAnimObj) {
    if (pParams == 0) CdsAssert("PParticleVertexGlow.cpp", 0x1C, "pParams");
    if (poGlowObj == 0) CdsAssert("PParticleVertexGlow.cpp", 0x1D, "poGlowObj");
    if (poAnimObj == 0) CdsAssert("PParticleVertexGlow.cpp", 0x1E, "poAnimObj");
    memcpy(&m_unkE0, pParams, 0x260);
    bool bResult = Init__7PFxMeshFP6PMNodeP6PMNode(&m_unk340, poGlowObj, poAnimObj);
    m_unk358 = poAnimObj;
    m_unk374 = 0;
    m_unk378 = 1.0f;
    m_unk37C = 0;
    m_unk380 = 1.0f;
    m_unk15 = 0;
    m_unk14 = 1;
    *(int *)((char *)this + 0xC) = 3;
    m_unk370 = 0;
    m_unk368 = 0;
    m_unk364 = 0;
    m_unk360 = 0;
    m_unk36C = 0x3F800000;
    return bResult;
}

// FUNCTION: 0x001BECF0 __dt__19PParticleVertexGlowFv
extern "C" void *__dt__19PParticleVertexGlowFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleVertexGlow *pSelf = (PParticleVertexGlow *)pThis;
        *(void **)pThis = __vt__19PParticleVertexGlow;
        pSelf->m_unk358 = 0;
        __dt__7PFxMeshFv(&pSelf->m_unk340, -1);
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001BED70 __ct__19PParticleVertexGlowFv
extern "C" void *__ct__19PParticleVertexGlowFv(void *volatile pThis) {
    __ct__15PParticleSystemFv(pThis);
    *(void **)pThis = __vt__19PParticleVertexGlow;
    __ct__7PFxMeshFv(&((PParticleVertexGlow *)pThis)->m_unk340);
    ((PParticleVertexGlow *)pThis)->m_unk374 = 0;
    ((PParticleVertexGlow *)pThis)->m_unk378 = 0;
    ((PParticleVertexGlow *)pThis)->m_unk37C = 0;
    ((PParticleVertexGlow *)pThis)->m_unk380 = 0;
    ((PParticleVertexGlow *)pThis)->m_unk358 = 0;
    return pThis;
}
