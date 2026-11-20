// FLAGS: -str readonly
#include "types.h"
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
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

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

// DRAFT: 0x001BE870 Render__19PParticleVertexGlowFv
// note: body instructions match; original branches bnez m_unk14 to an out-of-line body then b to the epilogue, ours uses beqz to the exit. Tried early returns, nested guards, else-return, empty else, m_unk14 outermost (DIFF 25, 28).
void PParticleVertexGlow::Render() {
    if (m_unkA4 != 0 && m_unk15 != 0) {
        if (m_unk14 != 0) {
            float fSize = m_unk370;
            SetGlowSizeAndColor__10PGfxEngineFffPf(gGfxEng, fSize, fSize, &m_unk360);
            SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk10, &m_unkC0, true, m_unk30, 0x50000);
            Render__7PFxMeshFv(&m_unk340);
        }
    }
}

// FUNCTION: 0x001BEBF0 Create__19PParticleVertexGlowFP27tagParticleVertexGlowParamsP6PMNodeP6PMNode
bool PParticleVertexGlow::Create(tagParticleVertexGlowParams *pParams, PMNode *poGlowObj, PMNode *poAnimObj) {
    if (pParams == 0) CdsAssert__FPciPc("PParticleVertexGlow.cpp", 0x1C, "pParams");
    if (poGlowObj == 0) CdsAssert__FPciPc("PParticleVertexGlow.cpp", 0x1D, "poGlowObj");
    if (poAnimObj == 0) CdsAssert__FPciPc("PParticleVertexGlow.cpp", 0x1E, "poAnimObj");
    memcpy(_pad0E0, pParams, 0x260);
    bool bResult = Init__7PFxMeshFP6PMNodeP6PMNode(&m_unk340, poGlowObj, poAnimObj);
    m_unk358 = poAnimObj;
    m_unk374 = 0;
    m_unk378 = 0x3F800000;
    m_unk37C = 0;
    m_unk380 = 0x3F800000;
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
