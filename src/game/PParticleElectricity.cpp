#include "types.h"
#include "PParticleElectricity.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, int nCount, int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__20PParticleElectricity[];
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" float sqrtf(float x);
extern char gGfxEng[1504384];
struct tagVuFxLine;
struct tagVuParticle;
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, PMat4 *pMat);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void BeginFxLines__10PGfxEngineFv(void *pThis);
extern "C" void DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(void *pThis, tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag);
extern "C" void EndFxLines__10PGfxEngineFv(void *pThis);
extern "C" void BeginParticles__10PGfxEngineF13eBoxIntersect(void *pThis, int eBox);
extern "C" void DrawParticles__10PGfxEngineFP13tagVuParticleiffb(void *pThis, tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag);
extern "C" void EndParticles__10PGfxEngineFv(void *pThis);

// FUNCTION: 0x001F4A80 SetupGlowParticles__20PParticleElectricityFPQ220PParticleElectricity20tagElectricityBranch
void PParticleElectricity::SetupGlowParticles(tagElectricityBranch *pBranch) {
    void *pBuf = AllocParticles__12PDisplayListFii(*(void **)&gGfxEng[0x154C80], m_unk04, 2);
    if (pBuf == 0) {
        CdsAssert__FPciPc("PParticleElectricity.cpp", 0xCA, "apVuParticles");
    }
    pBranch->m_unk04 = pBuf;
    for (unsigned int i = 0, off = 0; i < pBranch->m_unk34; i++, off += 0x20) {
        float *pSrc = (float *)((char *)pBranch->m_unk00 + off);
        float *pDst = (float *)((char *)pBuf + off);
        pDst[0] = pSrc[0];
        pDst[1] = pSrc[1];
        pDst[2] = pSrc[2];
        pDst[3] = m_unk134;
        pDst[4] = 128.0f;
        pDst[5] = 128.0f;
        pDst[6] = 128.0f;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        pDst[7] = 85.0f + 10.0f * (3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF));
    }
}

// DRAFT: 0x001F4BB0 Render__20PParticleElectricityFv
// note: 86 words; guard shape differs (orig bnez m14 + b to exit with ld ra in delay slot; ours beqz m14 direct, exit 3 words earlier); tried nested if, positive if, else-empty, early returns, combined && positive if
void PParticleElectricity::Render() {
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk14 == 0) {
        return;
    }
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)&m_unk40);
    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, 0, &m_unkC0, true, m_unk30, 0x50000);
    BeginFxLines__10PGfxEngineFv(gGfxEng);
    for (int i = 0, off = 0; i < m_unk130; i++, off += 0x40) {
        char *pElem = (char *)m_unkE0 + off;
        DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(gGfxEng, *(tagVuFxLine **)pElem, *(int *)(pElem + 0x34), 128.0f, 128.0f, true);
    }
    EndFxLines__10PGfxEngineFv(gGfxEng);
    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk10, &m_unkC0, true, m_unk30, 0x50000);
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)&m_unk40);
    BeginParticles__10PGfxEngineF13eBoxIntersect(gGfxEng, m_unkA4);
    for (int i = 0, off = 0; i < m_unk130; i++, off += 0x40) {
        char *pElem = (char *)m_unkE0 + off;
        DrawParticles__10PGfxEngineFP13tagVuParticleiffb(gGfxEng, *(tagVuParticle **)(pElem + 4), *(int *)(pElem + 0x34), m_unkB8, m_unkBC, false);
    }
    EndParticles__10PGfxEngineFv(gGfxEng);
}

// FUNCTION: 0x001F4D30 SetPosition__20PParticleElectricityFPfPf
void PParticleElectricity::SetPosition(float *pFrom, float *pTo) {
    float vec[4];

    sceVu0CopyVector(m_unkF0, pFrom);
    sceVu0CopyVector(vec, pTo);
    sceVu0SubVector(m_unk100, vec, m_unkF0);
    m_unk124 = sqrtf(sceVu0InnerProduct(m_unk100, m_unk100));
    sceVu0Normalize(m_unk100, m_unk100);
    m_unk80 = (vec[0] + m_unkF0[0]) * 0.5f;
    m_unk84 = (vec[1] + m_unkF0[1]) * 0.5f;
    m_unk88 = (vec[2] + m_unkF0[2]) * 0.5f;
    *(float *)&m_unk8C = 1.0f;
    m_unk90 = m_unk124 * 0.5f;
    m_unk94 = m_unk124 * 0.5f;
    m_unk98 = m_unk124 * 0.5f;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
}

// FUNCTION: 0x001F5450 __dt__20PParticleElectricityFv
extern "C" void *__dt__20PParticleElectricityFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleElectricity *pSelf = (PParticleElectricity *)pThis;
        *(void **)pThis = __vt__20PParticleElectricity;
        if (pSelf->m_unkE0 != 0) {
            __dla__FPv(pSelf->m_unkE0);
            pSelf->m_unkE0 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F54D0 __ct__20PParticleElectricityFv
PParticleElectricity::PParticleElectricity() {
    *(void **)this = __vt__20PParticleElectricity;
}
