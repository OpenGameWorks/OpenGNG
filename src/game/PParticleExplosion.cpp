// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PMat4.h"
#include "PDisplayList.h"
#include "PParticleExplosion.h"
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);

// TODO(header): foreign declarations
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
float FastMath_Sin180(float fAngle);
float FastMath_Cos180(float fAngle);
extern char gGfxEng[1504384];
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" int rand(void);
extern "C" float sqrtf(float x);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
void FastMath_VectorFabs(float *pDst, float *pSrc);
extern unsigned char __vt__18PParticleExplosion[];

// FUNCTION: 0x001B5390 ModifyPosition__18PParticleExplosionFP5PMat4
void PParticleExplosion::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk1C0, m_unkE0);
}

// FUNCTION: 0x001B53B0 SetPosition__18PParticleExplosionFPfPf
void PParticleExplosion::SetPosition(float *pA, float *pB) {
    sceVu0CopyVector(m_unk1C0, pA);
}

// FUNCTION: 0x001B53C0 Start__18PParticleExplosionFv
void PParticleExplosion::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk1A4 = 0;
    m_unk1D0 = (int)(0.5f + (12345.0f + 41976.0f * ((float)rand() / 2147483648.0f)));
    *(u_long128 *)m_unk1B0 = *(u_long128 *)m_unk1C0;
    m_unk80 = m_unk1C0[0];
    m_unk84 = m_unk1C0[1];
    m_unk88 = m_unk1C0[2];
    m_unk8C = 0x3F800000;
}

// The particle colour, position and size samples are drawn from the LCG at m_unkD0.
#define PE_FRAC(v) ((float)(((v) >> 16) & 0x7FFF) * 0.000030517578f)

// DRAFT: 0x001B5480 Animate__18PParticleExplosionFf
// note: DIFF 785/811 words; original saves f20-f27 and keeps this in s5 while the draft uses s0, and the LCG draw order and expression order differ throughout. One variant tried.
void PParticleExplosion::Animate(float fDelta) {
    int nLoop = 0;
    unsigned int nIndex = 0;
    int nOffset = 0;
    float fAge;
    float fLife;
    float fRatio;
    float fScale;
    float fX;
    float fY;
    float fZ;
    float fBox[4];
    float fVec[4];
    float fT;
    float fAmp;
    float fAngle;
    float fSin;
    float fCos;
    float fG;
    float fH;
    float fFrac;
    float fS;
    float fNeg;
    float fH6;
    float fH7;
    float fV21;
    float fV22;
    float *pP;
    char *pBase;
    int r1;
    int r2;
    int r3;
    int r4;
    int r5;
    int r6;
    int r7;
    int r8;
    int r9;
    int r10;

    UpdateLoopDelay(fDelta);
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk16 != 0) {
        return;
    }
    m_unkD0 = m_unk1D0;
    pBase = (char *)((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->AllocParticles(m_unk04, 2);
    ((pBase != 0) ? (void)0 : CdsAssert("PParticleExplosion.cpp", 0x62, "apVuParticles"));
    m_unk08 = pBase;
    nIndex = 0;
    nOffset = 0;
    m_unk1A4 += fDelta;
    while (nIndex < m_unk04) {
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        fAge = m_unk1A4 * (m_unk190 + ((1.0f - m_unk190) * PE_FRAC(m_unkD0)));
        fLife = m_unk1A0;
        if (!(fAge < fLife)) {
            nLoop += 1;
            fAge = fLife;
            if (nLoop >= m_unk160) {
                fAge = 0.0f;
                m_unk1A4 = 0.0f;
                m_unk1D0 = (int)(0.5f + (12345.0f + 41976.0f * ((float)rand() / 2147483648.0f)));
                UpdateLoopCounter();
                *(u_long128 *)m_unk1B0 = *(u_long128 *)m_unk1C0;
                m_unk80 = m_unk1C0[0];
                m_unk84 = m_unk1C0[1];
                m_unk88 = m_unk1C0[2];
                m_unk8C = 0x3F800000;
                if (m_unk15 == 0) {
                    return;
                }
            }
        }

        fRatio = fAge / m_unk1A0;
        if (!(fRatio < 0.99999f)) {
            fRatio = 0.99999f;
        }
        fScale = 1.0f - (fRatio * m_unk178);

        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        r1 = m_unkD0;
        m_unkD0 = r1 * 0x343FD + 0x269EC3;
        r2 = m_unkD0;
        m_unkD0 = r2 * 0x343FD + 0x269EC3;
        r3 = m_unkD0;
        fX = m_unkF0[0] + ((m_unk100[0] - m_unkF0[0]) * PE_FRAC(r1));
        fY = m_unkF0[1] + ((m_unk100[1] - m_unkF0[1]) * PE_FRAC(r2));
        fZ = m_unkF0[2] + ((m_unk100[2] - m_unkF0[2]) * PE_FRAC(r3));
        fBox[0] = fX;
        fBox[1] = 0.0f;
        fBox[2] = fZ;
        sceVu0Normalize(fBox, fBox);

        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        r4 = m_unkD0;
        fBox[1] = m_unk110[1] + ((m_unk120[1] - m_unk110[1]) * PE_FRAC(r4));

        if (fBox[0] > m_unk120[0]) {
            fBox[0] = m_unk120[0];
        }
        if (fBox[0] < m_unk110[0]) {
            fBox[0] = m_unk110[0];
        }
        if (fBox[2] > m_unk120[2]) {
            fBox[2] = m_unk120[2];
        }
        if (fBox[2] < m_unk110[2]) {
            fBox[2] = m_unk110[2];
        }
        sceVu0ScaleVector(fBox, fBox, fScale);

        fT = 30.0f * m_unk180;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        r5 = m_unkD0;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        r6 = m_unkD0;
        fAmp = m_unk17C + ((-(0.5f * m_unk17C)) + (2.0f * (0.5f * m_unk17C) * PE_FRAC(r6)));

        fAngle = 180.0f * ((float)((int)(fAge * (fT + (((0.5f * fT) - fT) * PE_FRAC(r5)))) % 360) / 180.0f - 1.0f);
        fSin = FastMath_Sin180(fAngle);
        fCos = FastMath_Cos180(fAngle);

        pP = (float *)(pBase + nOffset);
        pP[0] = (fAmp * fSin) + (m_unk1B0[0] + fX + (fRatio * (m_unk170 * fBox[0])));
        pP[2] = (fAmp * fSin) + (m_unk1B0[2] + fZ + (fRatio * (m_unk170 * fBox[2])));
        pP[1] = (fAmp * fCos) + (m_unk1B0[1] + fY + (fRatio * (m_unk170 * fBox[1])));

        fG = m_unk174;
        fH = 0.75f * fG;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        r7 = m_unkD0;
        pP[1] = pP[1] - (fRatio * (fRatio * fRatio * (fG + ((-fH) + (2.0f * fH * PE_FRAC(r7))))));

        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        r8 = m_unkD0;
        fH = 0.75f * m_unk194;
        fFrac = (0.5f * (fRatio * m_unk184));
        fFrac = fFrac - (float)(int)fFrac;
        if (fFrac <= 0.5f) {
            pP[3] = m_unk164 + (2.0f * (fFrac * (m_unk168 - m_unk164)));
        } else {
            pP[3] = m_unk168 + (2.0f * ((fFrac - 0.5f) * (m_unk164 - m_unk168)));
        }
        pP[3] = pP[3] * (1.0f + ((-fH) + (2.0f * fH * PE_FRAC(r8))));

        if (m_unk19 != 0) {
            fT = 30.0f * *(float *)&m_unk2C;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            r9 = m_unkD0;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            r10 = m_unkD0;
            fS = 0.001f + (0.0139999995f * *(float *)&m_unk28);
            fH6 = 0.2f * fS;
            fH7 = 2.0f * fH6;
            fNeg = -fH6;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            fV21 = fS + (fNeg + (fH7 * PE_FRAC(r10)));
            fAngle = 180.0f * ((float)((int)(fAge * (fT + (((0.5f * fT) - fT) * PE_FRAC(r9)))) % 360) / 180.0f - 1.0f);
            fV22 = fS + (fNeg + (fH7 * PE_FRAC(m_unkD0)));
            fSin = FastMath_Sin180(fAngle);
            pP[4] = fV21 * FastMath_Cos180(fAngle);
            pP[5] = fV22 * fSin;
        } else {
            fFrac = fRatio * m_unk188;
            fFrac = fFrac - (float)(int)fFrac;
            if (fFrac <= 0.5f) {
                fVec[0] = m_unk140[0] - m_unk130[0];
                fVec[1] = m_unk140[1] - m_unk130[1];
                fVec[2] = m_unk140[2] - m_unk130[2];
                sceVu0ScaleVectorXYZ(fVec, fVec, 2.0f * fFrac);
                fVec[0] += m_unk130[0];
                fVec[1] += m_unk130[1];
                fVec[2] += m_unk130[2];
            } else {
                fVec[0] = m_unk150[0] - m_unk140[0];
                fVec[1] = m_unk150[1] - m_unk140[1];
                fVec[2] = m_unk150[2] - m_unk140[2];
                sceVu0ScaleVectorXYZ(fVec, fVec, 2.0f * (fFrac - 0.5f));
                fVec[0] += m_unk140[0];
                fVec[1] += m_unk140[1];
                fVec[2] += m_unk140[2];
            }
            if (fVec[0] > 255.0f) {
                fVec[0] = 255.0f;
            }
            if (fVec[0] < 0.0f) {
                fVec[0] = 0.0f;
            }
            if (fVec[1] > 255.0f) {
                fVec[1] = 255.0f;
            }
            if (fVec[1] < 0.0f) {
                fVec[1] = 0.0f;
            }
            if (fVec[2] > 255.0f) {
                fVec[2] = 255.0f;
            }
            if (fVec[2] < 0.0f) {
                fVec[2] = 0.0f;
            }
            pP[4] = fVec[0];
            pP[5] = fVec[1];
            pP[6] = fVec[2];
        }

        fT = fRatio * m_unk18C;
        fFrac = fT - (float)(int)fT;
        if (fFrac <= 0.5f) {
            fT = m_unk130[3] + ((m_unk140[3] - m_unk130[3]) * (2.0f * fFrac));
        } else {
            fT = m_unk140[3] + ((m_unk150[3] - m_unk140[3]) * (2.0f * (fFrac - 0.5f)));
        }
        if (fT > 128.0f) {
            fT = 128.0f;
        }
        if (fT < 0.0f) {
            fT = 0.0f;
        }
        pP[7] = fT;

        nOffset += 0x20;
        nIndex += 1;
    }
}

// FUNCTION: 0x001B6130 Create__18PParticleExplosionFP26tagParticleExplosionParamsfff
int PParticleExplosion::Create(tagParticleExplosionParams *pParams, float fA, float fB, float fC) {
    float aVec[4];

    if (!PParticleSystem::Create(pParams->m_unk80, false)) {
        return 0;
    }
    m_unk0C = 2;
    m_unk30 = 0x48;
    memcpy(m_unkE0, pParams, 0xC0);
    m_unk194 = 1.0f - m_unk194;
    m_unkE0[0] += fA;
    m_unkE0[1] += fB;
    m_unkE0[2] += fC;
    *(u_long128 *)m_unk1C0 = *(u_long128 *)m_unkE0;
    m_unk1A0 = 5.0f + 175.0f * (1.0f - m_unk16C);
    m_unk1A4 = 0;
    m_unk1D0 = (int)(0.5f + (12345.0f + 41976.0f * ((float)rand() / 2147483648.0f)));
    m_unk80 = m_unk1C0[0];
    m_unk84 = m_unk1C0[1];
    m_unk88 = m_unk1C0[2];
    m_unk8C = 0x3F800000;
    sceVu0SubVector(aVec, m_unk100, m_unkF0);
    FastMath_VectorFabs(aVec, aVec);
    m_unk90 = (m_unk170 > aVec[0]) ? m_unk170 : aVec[0];
    m_unk94 = (m_unk170 > aVec[1]) ? m_unk170 : aVec[1];
    m_unk98 = (m_unk170 > aVec[2]) ? m_unk170 : aVec[2];
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001B6360 __dt__18PParticleExplosionFv
extern "C" void *__dt__18PParticleExplosionFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__18PParticleExplosion;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001B63C0 __ct__18PParticleExplosionFv
extern "C" void *__ct__18PParticleExplosionFv(void *pThis) {
    __ct__15PParticleSystemFv(pThis);
    *(void **)pThis = __vt__18PParticleExplosion;
    return pThis;
}
