#include "types.h"
#include "PParticleRain.h"
#include "PSound.h"

// TODO(header): foreign declarations
// Symbols at PGfxEngine's member addresses; gGfxEng is the engine block at 0x306680.
extern "C" void DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(void *pThis, void *pLines, int nCount, float fA, float fB, bool bFlag);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nIdx, float *pVals, bool bFlag, unsigned long nA, unsigned long nB);
extern "C" void BeginFxLines__10PGfxEngineFv(void *pThis);
extern "C" void EndFxLines__10PGfxEngineFv(void *pThis);
extern char gGfxEng[1504384];
extern PSound gSound;
extern "C" char __vt__13PParticleRain[0x40];
extern "C" void __ct__13PRainSplatterFv(void *pThis);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);

// DRAFT: 0x001CC110 RenderQuadrant__13PParticleRainFUi
// note: 16 words differ; load and float-constant order and the gGfxEng lui/addiu reloc form differ (tried direct offsets, shared offset, PRainQuadrant indexing).
void PParticleRain::RenderQuadrant(unsigned int nIndex) {
    char *pBase = (char *)this + 0x140;
    unsigned int nOff = nIndex * 0x50;
    unsigned int nStart = *(unsigned int *)(pBase + nOff);
    void *pBuf = m_unk248;
    unsigned int nCount = *(unsigned int *)((char *)this + 0x148 + nOff);
    DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(gGfxEng, (char *)pBuf + (nStart << 5), nCount, 0.0f, 128.0f, 1);
}

// DRAFT: 0x001CC5F0 SetNumRainParticles__13PParticleRainFUi
// note: 11 words differ; branch layout around the rem test and the loop stride differ.
void PParticleRain::SetNumRainParticles(unsigned int nNum) {
    unsigned int nRem;
    unsigned int k;

    if (nNum < 4) {
        nNum = 4;
    }
    if (nNum >= 0x29) {
        nRem = nNum % 0x28;
        if (nRem != 0 && nRem < 4) {
            nNum += 4 - nRem;
        }
    }
    for (k = 0; k < 4; k++) {
        unsigned int nMax = m_unk04 >> 2;
        *(unsigned int *)(m_unk100 + 0x48 + k * 0x50) = (nNum < nMax) ? nNum : nMax;
    }
}

// DRAFT: 0x001CCAD0 Render__13PParticleRainFv
// note: guard branches are beqz/beqz nested here, original uses bnez over nop;b; gGfxEng reloc addend differs; nested and && forms gave the same count.
void PParticleRain::Render() {
    if (m_unk15 != 0) {
        if (m_unk14 != 0) {
        SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (char *)this + 0x40);
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, 0, (float *)((char *)this + 0xC0), true, m_unk30, 0x50000);
        BeginFxLines__10PGfxEngineFv(gGfxEng);
        RenderQuadrant(m_unk240);
        RenderQuadrant(m_unk244);
        EndFxLines__10PGfxEngineFv(gGfxEng);
        m_unk270.Render();
        }
    }
}

// FUNCTION: 0x001CD360 __dt__13PParticleRainFv
PParticleRain::~PParticleRain() {
    *(void **)this = __vt__13PParticleRain;
    if (m_unk248 != 0) {
        __dla__FPv(m_unk248);
        m_unk248 = 0;
    }
    if (m_unk2B0 != 0) {
        gSound.StopSoundBySoundRef(m_unk2B0);
        m_unk2B0 = 0;
    }
}

// FUNCTION: 0x001CD410 __ct__13PParticleRainFv
PParticleRain::PParticleRain() : PParticleSystem() {
    *(void **)this = __vt__13PParticleRain;
    __ct__13PRainSplatterFv(&m_unk270);
    memset(m_unkE0, 0, 0x20);
    memset(m_unk100, 0, 0x140);
    m_unk240 = 0;
    m_unk244 = 0;
    m_unk248 = 0;
    m_unk25C = 0;
    SetLightningDensity(0.0f);
    m_unk2B0 = 0;
}
