#include "types.h"
#include "PRainSplatter.h"

// TODO(header): foreign declarations
class PMat4;
struct tagVuParticle;
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, PMat4 *pMat);
extern "C" void BeginParticles__10PGfxEngineF13eBoxIntersect(void *pThis, int eBox);
extern "C" void DrawParticles__10PGfxEngineFP13tagVuParticleiffb(void *pThis, tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag);
extern "C" void EndParticles__10PGfxEngineFv(void *pThis);
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, int nCount, int nFlag);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);

// DRAFT: 0x001D00B0 Render__13PRainSplatterFv
// note: 4 words; DrawParticles float constants: original materialises 1.0f (f13) before 0.5f (f12); literal {1,1,1,1} fixed. Tried locals in both orders, const locals, scaled and summed constants, PGfxEngine member calls (all 4).
void PRainSplatter::Render() {
    float vec[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk30, vec, 1, 0x48, 0x50000);
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)gUnitMatrix);
    BeginParticles__10PGfxEngineF13eBoxIntersect(gGfxEng, 2);
    float fA = 0.5f;
    float fB = 1.0f;
    DrawParticles__10PGfxEngineFP13tagVuParticleiffb(gGfxEng, (tagVuParticle *)m_unk00, m_unk04, fA, fB, 0);
    EndParticles__10PGfxEngineFv(gGfxEng);
}

// DRAFT: 0x001D0160 Animate__13PRainSplatterFf
// note: DIFF 86 words. VU0 block is asm (lqc2/qmtc2.i/vmulx/vadd/sqc2) with xb read as int from pIn+0xC (lw, not mfc1), frame 0x40 matches; constant registers, loop bottom b and bc1t layout differ. Tried *(int*)&x (88, frame 0x50), union (88), x declared before if (89).
void PRainSplatter::Animate(float fDelta) {
    float vec[4];
    sceVu0SubVector(vec, m_unk20, m_unk10);
    void *pOut = AllocParticles__12PDisplayListFii(*(void **)(gGfxEng + 0x154C80), m_unk04, 2);
    if (pOut == 0) {
        CdsAssert__FPciPc("PRainSplatter.cpp", 0x49, "apVuParticles");
    }
    m_unk00 = pOut;
    for (int i = 0; i < m_unk04; i++) {
        char *pIn = (char *)m_unk08 + i * 0x10;
        char *pEl = (char *)pOut + i * 0x20;
        *(float *)(pIn + 0xC) += 0.04f;
        if (!(*(float *)(pIn + 0xC) <= 1.0f)) {
            *(float *)(pIn + 0xC) = 1.0f;
            *(int *)(pEl + 0xC) = 0;
        } else {
            *(float *)(pEl + 0x0) = *(float *)(pIn + 0x0);
            *(float *)(pEl + 0x4) = *(float *)(pIn + 0x4);
            *(float *)(pEl + 0x8) = *(float *)(pIn + 0x8);
            *(float *)(pEl + 0xC) = 0.2f + 0.3f * *(float *)(pIn + 0xC);
            int xb = *(int *)(pIn + 0xC);
            float *pSrc = m_unk10;
            float *pDst = (float *)(pEl + 0x10);
            float *pVec = vec;
            asm {
                lqc2 vf1, 0x0(pVec)
                lqc2 vf2, 0x0(pSrc)
                qmtc2.i xb, vf3
                vmulx.xyzw vf4, vf1, vf3x
                vnop
                vnop
                vnop
                vadd.xyzw vf5, vf4, vf2
                vnop
                vnop
                vnop
                sqc2 vf5, 0x0(pDst)
            }
        }
    }
}

// DRAFT: 0x001D0320 Splatter__13PRainSplatterFPf
// note: DIFF 32 words. Loop bottom b offset and bc1t target differ; 0.5f lui hoisted before sw; 4 variants tried.
void PRainSplatter::Splatter(float *pPos) {
    int i;
    int off;
    for (i = 0, off = 0; i < m_unk04; i++, off += 0x10) {
        if (!(*(float *)((char *)m_unk08 + off + 0xC) < 1.0f)) {
            int o = i * 0x10;
            char *p = (char *)m_unk08 + 0xC;
            *(int *)(p + o) = 0;
            *(float *)((char *)m_unk08 + o) = pPos[0];
            *(float *)((char *)m_unk08 + o + 4) = 0.5f + pPos[1];
            *(float *)((char *)m_unk08 + o + 8) = pPos[2];
            return;
        }
    }
}

// FUNCTION: 0x001D03D0 Create__13PRainSplatterFiPf
int PRainSplatter::Create(int nCount, float *pPos) {
    m_unk04 = nCount;
    m_unk08 = __nwa__FUi(nCount * 0x10);
    if (m_unk08 == 0) {
        CdsAssert__FPciPc("PRainSplatter.cpp", 0x20, "mpParticlePosAge");
    }
    memset(m_unk08, 0, nCount * 0x10);
    sceVu0CopyVector(m_unk10, pPos);
    sceVu0CopyVector(m_unk20, pPos);
    m_unk2C = 0;
    m_unk00 = 0;
    return 1;
}

// FUNCTION: 0x001D0470 __dt__13PRainSplatterFv
PRainSplatter::~PRainSplatter() {
    if (m_unk08 != 0) {
        __dla__FPv(m_unk08);
        m_unk08 = 0;
    }
}
