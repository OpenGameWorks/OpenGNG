#include "types.h"
#include "PParticleRain.h"
#include "PSound.h"
#include "PMat4.h"

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
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
float FastMath_Fabs(float f);

// One quadrant of the rain volume, 0x50 bytes apart from 0x120: the box spawns particles [m_nStart, m_nEnd).
struct PRainBox {
    char _pad000[0x120];
    float m_fMin[4];            // 0x120
    float m_fMax[4];            // 0x130
    unsigned int m_nStart;      // 0x140
    unsigned int m_nEnd;        // 0x144
};

#define m_pParts ((PRainParticle *)m_unk248)
struct PRainParticle {
    float m_fPos[4];
    float m_fVel[4];
};
#define PR_STEP() (m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3)
#define PR_RND() (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF))

// FUNCTION: 0x001CC100 FrustrumTest__13PParticleRainFP9PFrustrumPfff
void PParticleRain::FrustrumTest(PFrustrum *, float *, float, float) {
    *(int *)((char *)this + 0xA4) = 1;
}

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

// DRAFT: 0x001CC3B0 InitParticles__13PParticleRainFv
// note: order matches; FP and saved-register numbering differ (constant in f0 and box pointers in s3..s5 in the original). Tried macro, inline RNG, hi/lo/range temporaries.
void PParticleRain::InitParticles() {
    unsigned int q;
    for (q = 0; q < 4; q++) {
        PRainBox *pBox = (PRainBox *)((char *)this + q * 0x50);
        float &fMaxZ = pBox->m_fMax[2];
        float &fMinZ = pBox->m_fMin[2];
        FastMath_Fabs(fMaxZ - fMinZ);
        unsigned int i;
        for (i = pBox->m_nStart; i < pBox->m_nEnd; i++) {
            float fHi = pBox->m_fMax[0];
            float fLo = pBox->m_fMin[0];
            float fRange = fHi - fLo;
            PR_STEP();
            m_pParts[i].m_fPos[0] = fLo + fRange * PR_RND();
            m_pParts[i].m_fPos[1] = pBox->m_fMax[1];
            fHi = fMaxZ;
            fLo = fMinZ;
            fRange = fHi - fLo;
            PR_STEP();
            m_pParts[i].m_fPos[2] = fLo + fRange * PR_RND();
            fHi = ((float *)m_unkE0)[6];
            fLo = ((float *)m_unkE0)[5];
            fRange = fHi - fLo;
            PR_STEP();
            m_pParts[i].m_fPos[3] = fLo + fRange * PR_RND();
            m_pParts[i].m_fVel[0] = ((float *)m_unkE0)[0];
            m_pParts[i].m_fVel[1] = ((float *)m_unkE0)[1];
            m_pParts[i].m_fVel[2] = ((float *)m_unkE0)[2];
            PR_STEP();
            m_pParts[i].m_fVel[3] = 0.3f + 0.14999998f * PR_RND();
        }
    }
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

// FUNCTION: 0x001CC680 SetLightningDensity__13PParticleRainFf
void PParticleRain::SetLightningDensity(float fDensity) {
    int nBase;
    float fLo;
    float fHi;
    float fScaled;
    float fRand;
    float fDiff;

    m_unk260 = (unsigned int)fDensity;
    if (m_unk260 != 0) {
        nBase = (unsigned int)(2100.0f - (1800.0f * (fDensity / 100.0f)));
        m_unk264 = nBase - 0xF0;
        m_unk268 = nBase + 0xF0;
        fHi = (float)(unsigned int)m_unk268;
        fLo = (float)(unsigned int)m_unk264;
        m_unkD0 = (m_unkD0 * 0x343FD) + 0x269EC3;
        fRand = 0.000030517578f * (float)(((int)m_unkD0 >> 0x10) & 0x7FFF);
        fDiff = fHi - fLo;
        fScaled = fLo + (fDiff * fRand);
        m_unk26C = (unsigned int)fScaled;
    }
}

// DRAFT: 0x001CC850 SetDensity__13PParticleRainFfb
// note: 23 words differ; the zero clamp is laid out before the 1.0 body and the inner empty then-branch has no second jump (ternary, single if, outer-first and fMin-else forms tried, 23-27 words).
void PParticleRain::SetDensity(float fDensity, bool bFlag) {
    float fMin = 1.0f;

    if (fDensity < 1.0f) {
        fMin = fDensity;
    }
    if (!(fMin <= 0.0f)) {
        if (fDensity < 1.0f) {
        } else {
            fDensity = 1.0f;
        }
    } else {
        fDensity = 0.0f;
    }
    if (bFlag) {
        m_unk254 = fDensity;
        m_unk258 = (fDensity - m_unk250) / 600.0f;
    } else {
        m_unk254 = fDensity;
        m_unk250 = fDensity;
        m_unk258 = 0.0f;
    }
}

// FUNCTION: 0x001CC900 SetCameraPosRot__13PParticleRainFPA4_fPA4_f
void PParticleRain::SetCameraPosRot(float (*arg0)[4], float (*arg1)[4]) {
    float mat[4][4];
    float fAngle;
    unsigned int i;
    unsigned int off;

    sceVu0UnitMatrix(&mat[0][0]);
    ((PMat4 *)mat)->Translate(arg0[0][0], arg0[0][1], arg0[0][2]);
    i = 0;
    off = 0;
    do {
        char *p = (char *)this + off;
        ((PMat4 *)mat)->MulVector((float *)(p + 0x120), (float *)(p + 0x100));
        ((PMat4 *)mat)->MulVector((float *)(p + 0x130), (float *)(p + 0x110));
        i += 1;
        off += 0x50;
    } while (i < 4);
    fAngle = 180.0f + arg1[0][1];
    if (!(fAngle <= 45.0f)) {
        if (fAngle <= 135.0f) {
            m_unk240 = 0;
            m_unk244 = 2;
            return;
        }
    }
    if (!(fAngle <= 135.0f)) {
        if (fAngle <= 225.0f) {
            m_unk240 = 2;
            m_unk244 = 3;
            return;
        }
    }
    if (!(fAngle <= 225.0f)) {
        if (fAngle <= 315.0f) {
            m_unk240 = 1;
            m_unk244 = 3;
            return;
        }
    }
    if (!(fAngle <= 315.0f) || (fAngle <= 45.0f)) {
        m_unk240 = 0;
        m_unk244 = 1;
    }
}

// FUNCTION: 0x001CCAD0 Render__13PParticleRainFv
void PParticleRain::Render() {
    if (!m_unk15 || !m_unk14) {
        return;
    }
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (char *)this + 0x40);
    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, 0, (float *)((char *)this + 0xC0), true, m_unk30, 0x50000);
    BeginFxLines__10PGfxEngineFv(gGfxEng);
    RenderQuadrant(m_unk240);
    RenderQuadrant(m_unk244);
    EndFxLines__10PGfxEngineFv(gGfxEng);
    m_unk270.Render();
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
