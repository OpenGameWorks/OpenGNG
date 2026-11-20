#include "types.h"
#include "PParticleFog.h"

// TODO(header): foreign declarations
class PFrustrum;
class PMat4;
extern "C" void __dla__FPv(void *pBlock);
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, PMat4 *pMat);
extern "C" void BeginFogParticles__10PGfxEngineF13eBoxIntersect(void *pThis, int eBox);
extern "C" void DrawFogParticles__10PGfxEngineFPA4_fifffPf(void *pThis, float (*pParticles)[4], int nCount, float fA, float fB, float fC, float *pVec);
extern "C" void EndFogParticles__10PGfxEngineFv(void *pThis);
extern "C" int IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(void *pThis, float (*pBox)[2][4], PMat4 *pMat);
extern "C" void MulVector__5PMat4FPfPf(void *pThis, float *pA, float *pB);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);

// DRAFT: 0x001BDDA0 FrustrumTest__12PParticleFogFP9PFrustrumPfffP5PMat4
// note: 64 words differ, register allocation: original keeps this in s0, pPos in s2, pMat in s1 (ours this=s2, pMat=s0); early-return form and nested form both 64 words.
void PParticleFog::FrustrumTest(PFrustrum *pFrustum, float *pPos, float fNear, float fFar, PMat4 *pMat) {
    if (pFrustum != 0) {
        float vec[4];
        if (pMat != 0) {
            m_unk50 = IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(pFrustum, &m_unk30, pMat);
        } else {
            m_unk50 = IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(pFrustum, &m_unk30, (PMat4 *)gUnitMatrix);
        }
        if (m_unk50 != 0) {
            if (pMat != 0) {
                MulVector__5PMat4FPfPf(pMat, vec, m_unk30[0]);
            } else {
                MulVector__5PMat4FPfPf((PMat4 *)gUnitMatrix, vec, m_unk30[0]);
            }
            sceVu0SubVector(vec, pPos, vec);
            float fDist = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
            if (fDist <= fFar) {
                m_unk20 = 1.0f;
            } else {
                float fAlpha = 1.0f - ((fDist - fFar) / (fNear - fFar));
                m_unk20 = fAlpha;
                if (fAlpha <= 0.0f) {
                    fAlpha = 0.0f;
                } else if (!(fAlpha < 1.0f)) {
                    fAlpha = 1.0f;
                }
                m_unk20 = fAlpha;
                if (fAlpha == 0.0f) {
                    m_unk50 = 0;
                }
            }
        }
    }
}

// DRAFT: 0x001BDF40 Render__12PParticleFogFP5PMat4
// note: 4 words differ, load order only: original loads a1 (0x54) before the 64-bit a4 (0x58) and a2 before a1 for DrawFogParticles; tried local for nCount, local copy of m_unk58 (10 words), both worse or same.
void PParticleFog::Render(PMat4 *pMat) {
    if (m_unk50 != 0) {
        float vec[4] = {1.0f, 0.0f, 0.0f, m_unk20};
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk54, vec, true, m_unk58, 0x50000);
        if (pMat != 0) {
            SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, pMat);
        } else {
            SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)gUnitMatrix);
        }
        BeginFogParticles__10PGfxEngineF13eBoxIntersect(gGfxEng, m_unk50);
        DrawFogParticles__10PGfxEngineFPA4_fifffPf(gGfxEng, m_unk00, m_unk04, m_unk08, m_unk0C, 1.5f, m_unk10);
        EndFogParticles__10PGfxEngineFv(gGfxEng);
    }
}

// FUNCTION: 0x001BE6E0 __dt__12PParticleFogFv
PParticleFog::~PParticleFog() {
    if (m_unk00) {
        __dla__FPv(m_unk00);
        m_unk00 = 0;
    }
    m_unk04 = 0;
}

// FUNCTION: 0x001BE750 __ct__12PParticleFogFv
PParticleFog::PParticleFog() {
    m_unk00 = 0;
    m_unk04 = 0;
    m_unk54 = 0;
    m_unk50 = 1;
}
