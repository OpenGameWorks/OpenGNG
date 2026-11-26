#include "PParticleSystem.h"
#include "PGfxEngine.h"
#include "types.h"

// TODO(header): foreign declarations
class PMat4;
extern unsigned char __vt__15PParticleSystem[0x40];
extern PGfxEngine gGfxEng; // TODO(header): PGfxEngine.h does not declare the global gGfxEng.
extern "C" void BeginHeatHaze__10PGfxEngineFv(PGfxEngine *pEng);
extern "C" void EndHeatHaze__10PGfxEngineFv(PGfxEngine *pEng);
extern "C" void BeginParticles__10PGfxEngineF13eBoxIntersect(PGfxEngine *pEng, eBoxIntersect eBox);
extern "C" void BeginRotatableParticles__10PGfxEngineFv(PGfxEngine *pEng);
extern "C" void EndParticles__10PGfxEngineFv(PGfxEngine *pEng);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern "C" float sqrtf(float x);
extern "C" int IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(PFrustrum *pFrustrum, float (*pBox)[4], PMat4 *pMat);
extern "C" void MulVector__5PMat4FPfPf(PMat4 *pMat, float *pDst, float *pSrc);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pExpr);

// FUNCTION: 0x001B4A80 Stop__15PParticleSystemFv
void PParticleSystem::Stop() {
    m_unk18 = 0;
}

// FUNCTION: 0x001B4A90 UpdateLoopDelay__15PParticleSystemFf
void PParticleSystem::UpdateLoopDelay(float fDelta) {
    if (m_unkB4 > 0.0f) {
        m_unkB4 = m_unkB4 - fDelta;
        if (!(m_unkB4 > 0.0f)) {
            m_unk15 = 1;
            m_unk18 = 1;
            m_unkB4 = 0.0f;
        }
    }
}

// FUNCTION: 0x001B4AE0 UpdateLoopCounter__15PParticleSystemFv
void PParticleSystem::UpdateLoopCounter() {
    int nCount;
    if (m_unkAC != -1) {
        m_unkB4 = m_unkB0;
        nCount = m_unkAC - 1;
        m_unkAC = (nCount > 0) ? nCount : 0;
        if (m_unkAC == 0) {
            m_unk16 = m_unk17;
            m_unkB4 = 0.0f;
        }
    } else {
        m_unk16 = m_unk17;
        m_unkB4 = m_unkB0;
    }
    m_unk15 = 0;
    m_unk18 = 0;
}

// DRAFT: 0x001B4B50 ComputeBoundingBox__15PParticleSystemFv
// note: 26 words differ; min/max accumulator registers and loop temporaries are allocated differently. Tried: load reorder, min/max declaration order, function-scope temps, forward and reversed chained init (26 best).
void PParticleSystem::ComputeBoundingBox() {
    unsigned int i = 0;
    int nOffset = 0;
    float fMinX, fMinY, fMinZ;
    float fMaxX, fMaxY, fMaxZ;
    fMinZ = fMinY = fMinX = 32767.0f;
    fMaxZ = fMaxX = fMaxY = -32767.0f;

    float fX;
    float fY;
    float fZ;

    for (; i < m_unk04; i++) {
        float *pVec = (float *)((char *)m_unk08 + nOffset);
        fX = pVec[0];
        if (fX < fMinX) {
            fMinX = fX;
        }
        fY = pVec[1];
        if (fY < fMinY) {
            fMinY = fY;
        }
        fZ = pVec[2];
        if (fZ < fMinZ) {
            fMinZ = fZ;
        }
        if (!(fX <= fMaxX)) {
            fMaxX = fX;
        }
        if (!(fY <= fMaxY)) {
            fMaxY = fY;
        }
        if (!(fZ <= fMaxZ)) {
            fMaxZ = fZ;
        }
        nOffset += 0x20;
    }
    m_unk80 = (fMaxX + fMinX) / 2.0f;
    m_unk84 = (fMaxY + fMinY) / 2.0f;
    m_unk88 = (fMaxZ + fMinZ) / 2.0f;
    m_unk8C = 0x3F800000;
    m_unk90 = (m_unkA0 / 2.0f) + (m_unk80 - fMinX);
    m_unk94 = (m_unkA0 / 2.0f) + (m_unk84 - fMinY);
    m_unk98 = m_unk88 - fMinZ;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
}

// FUNCTION: 0x001B4CE0 Cleanup__15PParticleSystemFv
void PParticleSystem::Cleanup() {
    if (m_unk1A != 0) {
        if (m_unk08 != 0) {
            __dla__FPv(m_unk08);
        }
    }
    m_unk08 = 0;
    m_unk1A = 0;
    m_unk0C = 0;
    m_unk10 = 0;
    m_unk15 = 0;
    m_unk14 = 0;
    m_unkA8 = -1;
}

// FUNCTION: 0x001B4D50 FadeAndDie__15PParticleSystemFUi
void PParticleSystem::FadeAndDie(unsigned int nUnused) {
    if (m_unk15 == 0) {
        m_unk16 = 1;
        m_unk17 = 1;
        m_unk18 = 0;
    } else {
        m_unk17 = 1;
        m_unkAC = 0;
    }
}

// DRAFT: 0x001B4D80 FrustrumTest__15PParticleSystemFP9PFrustrumPfff
// note: 55 words differ; this/pVec are swapped between $s0/$s1 (original keeps this in $s0), clamp 1.0f literal lands in $f3 instead of $f2. Tried: pVec local alias (55), fNear/fFar mapping, comparison swap (59), inverted distance branch (55, kept), fRatio split (55, reverted).
void PParticleSystem::FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar) {
    float vTmp[4];
    float fDist;
    float fT;
    if (pFrustrum != 0) {
        m_unkA4 = IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(pFrustrum, (float (*)[4])&m_unk80, (PMat4 *)&m_unk40);
        if (m_unkA4 != 0) {
            if (m_unk1C != 0) {
                MulVector__5PMat4FPfPf((PMat4 *)&m_unk40, vTmp, &m_unk80);
                sceVu0SubVector(vTmp, pVec, vTmp);
                fDist = vTmp[0] * vTmp[0] + vTmp[1] * vTmp[1] + vTmp[2] * vTmp[2];
                if (fDist > fFar) {
                    fT = 1.0f - (fDist - fFar) / (fNear - fFar);
                    m_unkCC = fT;
                    if (fT <= 0.0f) {
                        fT = 0.0f;
                    } else if (!(fT < 1.0f)) {
                        fT = 1.0f;
                    }
                    m_unkCC = fT;
                    if (fT == 0.0f) {
                        m_unkA4 = 0;
                    }
                } else {
                    m_unkCC = 1.0f;
                }
            }
        }
    }
}

// FUNCTION: 0x001B4EE0 ModifyPosition__15PParticleSystemFP5PMat4
void PParticleSystem::ModifyPosition(PMat4 *pMat) {
    m_unk40 = *(u_long128 *)((char *)pMat + 0x00);
    m_unk50 = *(u_long128 *)((char *)pMat + 0x10);
    m_unk60 = *(u_long128 *)((char *)pMat + 0x20);
    m_unk70 = *(u_long128 *)((char *)pMat + 0x30);
}

// DRAFT: 0x001B4F10 Render__15PParticleSystemFv
// note: m_unk08 test laid out as beqz-to-end, original is bnez-to-body plus b-to-end; the body's delay slots and gGfxEng reloads also differ. Tried m_unk08 == 0 empty-then, != 0 wrap, and early return: all DIFF 87.
void PParticleSystem::Render() {
    if (m_unk15 == 0) return;
    if (m_unk14 == 0) return;
    if (m_unkA4 == 0) return;
    if (m_unk08 != 0) {
        if (m_unk19 != 0) {
            m_unkC0 = 1.1f;
            m_unkC4 = 1.1f;
            m_unkC8 = 1.1f;
            gGfxEng.SetMaterial(&m_unkC0, true, m_unk30, 0x50000);
            gGfxEng.SetWorldMatrix((PMat4 *)&m_unk40);
            BeginHeatHaze__10PGfxEngineFv(&gGfxEng);
            gGfxEng.DrawHeatHaze((tagVuParticle *)m_unk08, m_unk04, m_unkB8, m_unkBC, m_unk1A);
            EndHeatHaze__10PGfxEngineFv(&gGfxEng);
        } else if (m_unk1B != 0) {
            gGfxEng.SetMaterial(m_unk10, &m_unkC0, true, m_unk30, 0x50000);
            gGfxEng.SetWorldMatrix((PMat4 *)&m_unk40);
            BeginRotatableParticles__10PGfxEngineFv(&gGfxEng);
            gGfxEng.DrawRotatableParticles((tagVuRotatableParticle *)m_unk08, m_unk04, m_unkB8, m_unkBC, m_unk1A);
            EndParticles__10PGfxEngineFv(&gGfxEng);
        } else {
            gGfxEng.SetMaterial(m_unk10, &m_unkC0, true, m_unk30, 0x50000);
            gGfxEng.SetWorldMatrix((PMat4 *)&m_unk40);
            BeginParticles__10PGfxEngineF13eBoxIntersect(&gGfxEng, (eBoxIntersect)m_unkA4);
            gGfxEng.DrawParticles((tagVuParticle *)m_unk08, m_unk04, m_unkB8, m_unkBC, m_unk1A);
            EndParticles__10PGfxEngineFv(&gGfxEng);
        }
        if (m_unk1A == 0) m_unk08 = 0;
    }
}

// FUNCTION: 0x001B50F0 Create__15PParticleSystemFUib
int PParticleSystem::Create(unsigned int nNum, bool bAlloc) {
    if (nNum == 0) {
        CdsAssert__FPciPc("PParticleSystem.cpp", 0x45, "uNumParticles");
    }
    if (m_unk08 != 0) {
        CdsAssert__FPciPc("PParticleSystem.cpp", 0x46, "mpVuParticles == NULL");
    }
    if (bAlloc) {
        m_unk08 = __nwa__FUi(nNum << 5);
        if (m_unk08 == 0) {
            return 0;
        }
        m_unk1A = 1;
    }
    m_unk04 = nNum;
    m_unk15 = 0;
    m_unk18 = 0;
    m_unk14 = 1;
    sceVu0UnitMatrix(&m_unk40);
    return 1;
}

// FUNCTION: 0x001B51C0 __dt__15PParticleSystemFv
extern "C" PParticleSystem *__dt__15PParticleSystemFv(PParticleSystem *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__15PParticleSystem;
        pThis->Cleanup();
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001B5220 __ct__15PParticleSystemFv
// note: 89 words differ; size 0xe0 vs 0x168. Original spills this to 0x1C(sp) and reloads before each store (no s0 save, 0x20 frame); ours keeps this in a register. Tried: local guard object (88 words, but it drops the vtable store, so not kept).
PParticleSystem::PParticleSystem() {
    *(unsigned char **)this = __vt__15PParticleSystem;
    sceVu0UnitMatrix(&m_unk40);
    m_unk04 = 0;
    m_unk08 = 0;
    m_unk0C = 0;
    m_unk10 = 0;
    m_unk15 = 0;
    m_unk14 = 0;
    m_unkA0 = 0.0f;
    m_unk16 = 0;
    m_unk1C = 1;
    m_unk30 = 0x44;
    m_unkA4 = 1;
    memset(&m_unk80, 0, 0x20);
    m_unkA8 = -1;
    m_unkB8 = 1.0f;
    m_unkBC = 1.0f;
    m_unkD0 = 0;
    m_unkC0 = 1.0f;
    m_unkC4 = 1.0f;
    m_unkC8 = 1.0f;
    m_unkCC = 1.0f;
    m_unkAC = 0;
    m_unkB0 = 0.0f;
    m_unkB4 = 0.0f;
    m_unk19 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
    m_unk1B = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unkD4 = 2;
    m_unk1A = 0;
    m_unk18 = 0;
    m_unk17 = 0;
    m_unk1B = 0;
}
