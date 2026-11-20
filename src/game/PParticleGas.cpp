#include "types.h"
#include "PParticleGas.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" int rand(void);
extern "C" void sceVu0SubVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0AddVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0ScaleVectorXYZ(void *pDst, void *pSrc, float fScale);
extern "C" float sqrtf(float fValue);
extern u_long128 lit_0024CCE0;
extern u_long128 lit_0024CCF0;
extern unsigned char __vt__12PParticleGas[];
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, int nCount, int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void DmaScratchPadToMainMem__FPvPvsbb(void *pDst, void *pSrc, short nSize, bool bA, bool bB);
extern "C" void sceVu0MulVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" float FastMath_Sin180__Ff(float fAngle);
extern "C" float FastMath_Cos180__Ff(float fAngle);
extern char gGfxEng[1504384];

// Parameter block passed to PParticleGas::Create (0x70 bytes, copied into the object at 0xE0).
struct tagParticleGasParams {
    int m_unk0;
    int m_unk4;
    int m_unk8;
    float m_unkC;
    float m_unk10;
    float m_unk14;
    float m_unk18;
    float m_unk1C;
    float m_unk20;
    float m_unk24;
    float m_unk28;
    float m_unk2C;
    float m_unk30;
    float m_unk34;
    float m_unk38;
    float m_unk3C;
    float m_unk40;
    int m_unk44;
    float m_unk48;
    float m_unk4C;
    char _pad50[0x20];
};

// FUNCTION: 0x001EC810 FadeOut__12PParticleGasFf
void PParticleGas::FadeOut(float fFade) {
    m_unk138 = fFade;
    m_unk164 = fFade;
    m_unk168 = 1;
}

// FUNCTION: 0x001EC830 Stop__12PParticleGasFv
void PParticleGas::Stop() {
    if (m_unk138) {
        FadeOut(m_unk138);
    } else {
        m_unk18 = 0;
    }
}

// FUNCTION: 0x001EC870 Start__12PParticleGasFv
void PParticleGas::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    *(float *)&m_unk160 = m_unk12C;
    m_unk168 = 0;
}

// FUNCTION: 0x001EC890 FadeAndDie__12PParticleGasFUi
void PParticleGas::FadeAndDie(unsigned int nUnused) {
    PParticleSystem::FadeAndDie(nUnused);
    if (!m_unk138) {
        return;
    }
    FadeOut(m_unk138);
}

// DRAFT: 0x001EC8E0 Animate__12PParticleGasFf
// note: compiles; the m2c spawn-range vector layout, the VU0 operand registers and the loop-exit DMA gate are best guesses, not matched against the asm.
void PParticleGas::Animate(float fTime) {
    float vMin[4];
    float vMax[4];
    float vRnd[4];
    float vC[4];
    float vB[4];
    float vRot[4];
    float vT[4];
    float *pMin;
    float *pMax;
    float *pRnd;
    float *pC;
    float *pB;
    float *pT;
    float *pF;
    float *pOutF;
    void *pOut;
    char *pOutElem;
    char *pInElem;
    float fDt;
    float fScale;
    float fFade;
    float fLife;
    float fLimit;
    float fPhase;
    float fAngle;
    float fSin;
    float fCos;
    float fWave;
    float fFrac;
    float fTmp;
    unsigned int i;
    unsigned int nDead;
    unsigned int nCount;

    if (m_unk1B) {
        AnimateRotatableParticles(fTime);
        return;
    }
    if (!m_unk15 || m_unk16) {
        return;
    }
    if (!m_unk17 && !m_unkA4) {
        return;
    }

    fDt = fTime;
    nDead = 0;
    m_unkD0 = m_unk158;
    if (m_unk18 == 0 || m_unk17 != 0) {
        fDt *= m_unk130;
    }
    fScale = 1.0f;
    if (m_unk168 != 0) {
        fFade = m_unk164 - fDt;
        if (!(fFade >= 0.0f)) {
            fFade = 0.0f;
        }
        m_unk164 = fFade;
        fScale = fFade / m_unk138;
        if (fFade == 0.0f) {
            m_unk168 = 0;
            m_unk15 = 0;
            m_unk18 = 0;
            m_unk16 = m_unk17;
            return;
        }
    } else if (m_unk12C != 0.0f) {
        fFade = *(float *)&m_unk160 - fDt;
        if (!(fFade >= 0.0f)) {
            fFade = 0.0f;
        }
        *(float *)&m_unk160 = fFade;
        fScale = 1.0f - (fFade / m_unk12C);
    }

    pOut = AllocParticles__12PDisplayListFii((char *)gGfxEng + 0x154C80, m_unk04, 2);
    ((pOut) ? (void)0 : CdsAssert__FPciPc("PParticleGas.cpp", 0xAA, "apVuParticles"));
    m_unk08 = pOut;
    nCount = m_unk04;
    if (nCount < 0x101) {
        pOut = (void *)0x70001000;
        ((((nCount << 5) < 0x2001)) ? (void)0 : CdsAssert__FPciPc("PParticleGas.cpp", 0xB5, "(sizeof(VuParticle) * muNumParticles) <= SPAD_TEMP_BUFFER_SIZE"));
    }

    sceVu0SubVector(vMin, &m_unkE0, &m_unkF0[0]);
    sceVu0AddVector(vMax, &m_unkE0, &m_unkF0[0]);
    vB[0] = 1.0f;
    vB[1] = 0.0f;
    vB[2] = 0.0f;
    vB[3] = m_unk120;
    vC[0] = m_unk118;
    vC[1] = m_unk118;
    vC[2] = m_unk118;
    vC[3] = 0.0f;
    pMin = vMin;
    pMax = vMax;
    pRnd = vRnd;
    pC = vC;
    pB = vB;
    pT = vT;

    for (i = 0; i < m_unk04; i++) {
        pOutElem = (char *)pOut + (i << 5);
        pInElem = (char *)m_unk150 + (i << 5);

        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        vRnd[0] = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        vRnd[1] = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        vRnd[2] = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        vRnd[3] = (float)((m_unkD0 >> 16) & 0x7FFF);
        sceVu0ScaleVector(vRnd, vRnd, 3.0517578125e-05f);

        pF = (float *)pInElem;
        asm {
            lqc2 vf1, 0x0(pMin)
            lqc2 vf2, 0x0(pMax)
            lqc2 vf3, 0x0(pRnd)
            vsub.xyzw vf4, vf2, vf1
            vmul.xyzw vf5, vf4, vf3
            vadd.xyzw vf6, vf5, vf1
            sqc2 vf6, 0x0(pF)
        }

        fLife = *(float *)(pInElem + 0xC) + fDt * vRnd[0];
        *(float *)(pInElem + 0xC) = fLife;
        fLimit = *(float *)&m_unk154;
        if (!(fLife < fLimit)) {
            *(float *)(pInElem + 0xC) = fLimit;
            if (m_unk17 != 0 || m_unk18 == 0) {
                nDead += 1;
                if (nDead >= m_unk124) {
                    m_unk16 = m_unk17;
                    m_unk15 = 0;
                    return;
                }
            } else {
                *(float *)(pInElem + 0xC) = *(float *)(pInElem + 0xC) - fLimit;
                *(float *)(pInElem + 0x0) = vMin[0] + (vMax[0] - vMin[0]) * ((float)rand() / 2147483648.0f);
                *(float *)(pInElem + 0x4) = vMin[1] + (vMax[1] - vMin[1]) * ((float)rand() / 2147483648.0f);
                *(float *)(pInElem + 0x8) = vMin[2] + (vMax[2] - vMin[2]) * ((float)rand() / 2147483648.0f);
            }
        }

        fPhase = *(float *)(pInElem + 0xC) / *(float *)&m_unk154;
        if (!(fPhase < 0.9999999f)) {
            fPhase = 0.9999999f;
        }
        vT[0] = fPhase;

        pF = (float *)pInElem;
        asm {
            lqc2 vf1, 0x0(pC)
            lqc2 vf2, 0x0(pF)
            lqc2 vf3, 0x0(pT)
            vmove.xyzw vf5, vf2
            vmulx.xyz vf4, vf1, vf3
            vadd.xyz vf5, vf4, vf2
            sqc2 vf5, 0x0(pF)
        }

        fTmp = *(float *)(pInElem + 0x0);
        if ((fTmp <= vMin[0]) || !(fTmp < vMax[0])) {
            *(float *)(pInElem + 0x10) = -*(float *)(pInElem + 0x10);
        }
        fTmp = *(float *)(pInElem + 0x4);
        if ((fTmp <= vMin[1]) || !(fTmp < vMax[1])) {
            *(float *)(pInElem + 0x14) = -*(float *)(pInElem + 0x14);
        }
        fTmp = *(float *)(pInElem + 0x8);
        if ((fTmp <= vMin[2]) || !(fTmp < vMax[2])) {
            *(float *)(pInElem + 0x18) = -*(float *)(pInElem + 0x18);
        }

        fAngle = 360.0f * fPhase + vRnd[2];
        if (!(fAngle <= 360.0f)) {
            fAngle -= 360.0f;
        }
        fAngle = fAngle - 180.0f;
        fSin = FastMath_Sin180__Ff(fAngle);
        fCos = FastMath_Cos180__Ff(fAngle);
        fTmp = fSin * fCos;
        vRot[0] = fCos;
        vRot[1] = fTmp;
        vRot[2] = 2.0f * fSin * fTmp;
        vRot[3] = 0.0f;
        sceVu0MulVector(vRot, vRot, vC);

        pOutF = (float *)pOutElem;
        pF = (float *)pInElem;
        asm {
            lqc2 vf1, 0x0(pB)
            lqc2 vf2, 0x0(pF)
            lqc2 vf5, 0x0(pOutF)
            lqc2 vf3, 0x0(pT)
            vmulx.xyz vf4, vf1, vf3
            vadd.xyz vf5, vf4, vf2
            sqc2 vf5, 0x0(pOutF)
        }

        *(float *)(pOutElem + 0xC) = vRnd[3];
        sceVu0ScaleVectorXYZ(pOutElem + 0x10, &m_unk100[0], *(float *)(pInElem + 0x1C));

        fTmp = fPhase * m_unk134;
        fFrac = fTmp - (float)(int)fTmp;
        if (fFrac <= 0.5f) {
            fWave = m_unk10C * (2.0f * fFrac);
        } else {
            fWave = m_unk10C - (m_unk10C * (2.0f * (fFrac - 0.5f)));
        }
        *(float *)(pOutElem + 0x1C) = fWave;
        *(float *)(pOutElem + 0x1C) = *(float *)(pOutElem + 0x1C) * fScale;
    }

    if (((int)pOut & 0x70000000) == 0x70000000) {
        DmaScratchPadToMainMem__FPvPvsbb(pOut, m_unk08, (short)(m_unk04 * 2), false, false);
    }
}

// DRAFT: 0x001ED110 Create__12PParticleGasFP20tagParticleGasParamsfff
// note: 322 words differ; original frame 0xE0 saves s0-s7 with this in s0 and pParams in s1, ours frame 0x90 with this in s2, so the prologue and every line after it shift. Tried: loop base hoisted to pBase (332 -> 322, kept as v2), others not kept.
int PParticleGas::Create(tagParticleGasParams *pParams, float fA, float fB, float fC) {
    u_long128 vLo;
    u_long128 vHi;
    u_long128 vSub;
    u_long128 vAdd;
    u_long128 *pLo;
    u_long128 *pHi;
    u_long128 *pSub;
    u_long128 *pAdd;
    void *pV;
    char *pElem;
    char *pBase;
    unsigned int i;

    if (!PParticleSystem::Create(pParams->m_unk44, false)) {
        return 0;
    }
    m_unk0C = 12;
    *(long long *)&m_unk30 = 0x48;
    memcpy(&m_unkE0, pParams, 0x70);
    m_unkE0 += fA;
    m_unkE4 += fB;
    m_unkE8 += fC;
    *(float *)&m_unk154 = 30.0f + 570.0f * (1.0f - m_unk114);
    m_unk158 = (int)(0.5f + (24536.0f + 39006.0f * ((float)rand() / 2147483648.0f)));
    *(float *)&m_unk160 = pParams->m_unk4C;
    m_unk130 = (4.0f <= m_unk130) ? m_unk130 : 4.0f;
    m_unk134 = (1.0f <= m_unk134) ? m_unk134 : 1.0f;
    m_unk150 = __nwa__FUi(m_unk04 << 5);
    if (!m_unk150) {
        return 0;
    }
    vLo = lit_0024CCE0;
    vHi = lit_0024CCF0;
    sceVu0SubVector(&vSub, &m_unkE0, &m_unkF0[0]);
    sceVu0AddVector(&vAdd, &m_unkE0, &m_unkF0[0]);
    pLo = &vLo;
    pHi = &vHi;
    pSub = &vSub;
    pAdd = &vAdd;
    pBase = (char *)m_unk150;

    for (i = 0; i < m_unk04; i++) {
        pElem = pBase + (i << 5);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x10) = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x14) = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x18) = (float)((m_unkD0 >> 16) & 0x7FFF);
        sceVu0ScaleVectorXYZ(pElem + 0x10, pElem + 0x10, 3.0517578125e-05f);

        pV = pElem + 0x10;
        asm {
            lqc2 vf1, 0x0(pLo)
            lqc2 vf2, 0x0(pHi)
            lqc2 vf3, 0x0(pV)
            vsub.xyz vf4, vf2, vf1
            vmul.xyz vf5, vf4, vf3
            vadd.xyz vf3, vf5, vf1
            sqc2 vf3, 0x0(pV)
        }

        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x0) = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x4) = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x8) = (float)((m_unkD0 >> 16) & 0x7FFF);
        sceVu0ScaleVectorXYZ(pElem, pElem, 3.0517578125e-05f);

        pV = pElem;
        asm {
            lqc2 vf1, 0x0(pSub)
            lqc2 vf2, 0x0(pAdd)
            lqc2 vf3, 0x0(pV)
            vsub.xyz vf4, vf2, vf1
            vmul.xyz vf5, vf4, vf3
            vadd.xyz vf3, vf5, vf1
            sqc2 vf3, 0x0(pV)
        }

        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0xC) = 0.0f + (*(float *)&m_unk154 - 0.0f) * (3.0517578125e-05f * (float)((m_unkD0 >> 16) & 0x7FFF));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x1C) = 1.0f + (m_unk110 - 1.0f) * (3.0517578125e-05f * (float)((m_unkD0 >> 16) & 0x7FFF));
    }

    m_unkA0 = (m_unk11C <= m_unk120) ? m_unk120 : m_unk11C;
    m_unk80 = m_unkE0;
    m_unk84 = m_unkE4;
    m_unk88 = m_unkE8;
    m_unk8C = 0x3F800000;
    m_unk90 = m_unkA0 + m_unkF0[0];
    m_unk94 = m_unkA0 + m_unkF0[1];
    m_unk98 = m_unkA0 + m_unkF0[2];
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001ED650 __dt__12PParticleGasFv
PParticleGas::~PParticleGas() {
    *(unsigned char **)this = __vt__12PParticleGas;
    if (m_unk150) {
        __dla__FPv(m_unk150);
        m_unk150 = 0;
    }
}

// FUNCTION: 0x001ED6D0 __ct__12PParticleGasFv
PParticleGas::PParticleGas() {
    *(unsigned char **)this = __vt__12PParticleGas;
    memset((char *)this + 0xE0, 0, 0x70);
    m_unk150 = 0;
    m_unk154 = 0;
    m_unk160 = 0;
    m_unk164 = 0;
    m_unk168 = 0;
}
