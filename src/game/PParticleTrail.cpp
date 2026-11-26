#include "types.h"
#include "PParticleTrail.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern unsigned char __vt__14PParticleTrail[];
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern "C" void __dla__FPv(void *);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" int rand(void);
extern "C" float sqrtf(float x);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
float FastMath_Sin180(float fAngle);
float FastMath_Cos180(float fAngle);

// SKIP: 0x001C5650 AnimateSmoothTrail__14PParticleTrailFv: 0x8B4 bytes (557 instructions) with an LCG random chain on unkD0, FastMath sin/cos and sceVu0ScaleVectorXYZ calls; not drafted in this run.
// FUNCTION: 0x001C5F10 Start__14PParticleTrailFv
void PParticleTrail::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk1B4 = 0;
}

// FUNCTION: 0x001C5F30 ModifyPosition__14PParticleTrailFP5PMat4
void PParticleTrail::ModifyPosition(PMat4 *pMat) {
    *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk190;
    pMat->MulVector(m_unk190, &m_unkE0);
    m_unk80 = m_unk190[0];
    m_unk84 = m_unk190[1];
    m_unk88 = m_unk190[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001C5F90 SetPosition__14PParticleTrailFPfPf
void PParticleTrail::SetPosition(float *pPos, float *pUnused) {
    *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk190;
    sceVu0CopyVector(m_unk190, pPos);
    m_unk80 = m_unk190[0];
    m_unk84 = m_unk190[1];
    m_unk88 = m_unk190[2];
    m_unk8C = 0x3F800000;
}

// DRAFT: 0x001C5FE0 Animate__14PParticleTrailFf
// note: 554 words differ; prologue saves f20-f26 (original f20-f24 only), no s5 copy of this, m_unk1B4 clamp and LCG/madd/colour order not matched.
static inline float ClampRangeDraft(float fVal, float fHi) {
    float fOut = fVal;
    float fT = fHi;
    if (fVal < fHi) {
        fT = fVal;
    }
    if (!(fT <= 0.0f)) {
        if (fVal < fHi) {
        } else {
            fOut = fHi;
        }
    } else {
        fOut = 0.0f;
    }
    return fOut;
}

void PParticleTrail::Animate(float fDt) {
    float spB0[4];
    float vC[4];
    unsigned int nDead;
    unsigned int nNext;
    unsigned int s2;
    unsigned int s3;
    unsigned int s4;
    int nA;
    int nB;
    float *pPart;
    float *pV;
    float *pVec;
    float fW;
    float fRatio;
    float fA;
    float fB0;
    float fT;
    float fFrac;
    float fF3;
    float fF5;
    float fF7;
    float fF22;
    float fF22s;
    float fF23;
    float fF24;
    float fBase;
    float fHalf;
    float fTwo;
    float fNeg;
    float fLerp;
    float fR;
    float fC;
    unsigned char b17;

    nDead = 0;
    if (m_unk15 != 0 && m_unk16 == 0) {
        if (fDt == 0.0f) {
            return;
        }
        m_unkD0 = m_unk1BC;
        if ((unsigned int)m_unk1B4 < m_unk04) {
            nNext = (unsigned int)m_unk1B4 + 1;
            m_unk1B4 = (nNext >= m_unk04) ? (int)m_unk04 : (int)nNext;
        }
        if (m_unk160 == 0) {
            AnimateSmoothTrail();
            goto block_68;
        }
        sceVu0SubVector(spB0, m_unk1A0, m_unk190);
        sceVu0Normalize(spB0, spB0);
        s2 = 0;
        s3 = 0;
        s4 = 0;
loop_67:
        if (s2 >= m_unk04) {
block_68:
            ComputeBoundingBox();
        } else {
            pPart = (float *)((char *)m_unk08 + s3);
            if (s2 >= (unsigned int)m_unk1B4) {
                pPart[3] = 0.0f;
                pPart[7] = 0.0f;
                goto block_66;
            }
            fF3 = m_unk154;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            pV = (float *)((char *)m_unk180 + s4);
            pV[3] = pV[3] + fDt * (fF3 + (1.0f - fF3) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)));
            fB0 = m_unk1B0;
            pV = (float *)((char *)m_unk180 + s4);
            if (!(pV[3] <= fB0)) {
                pV[3] = fB0;
                b17 = m_unk17;
                if (b17 != 0 || m_unk18 == 0) {
                    nDead++;
                    if (nDead >= m_unk130) {
                        m_unk16 = b17;
                        m_unk15 = 0;
                        return;
                    }
                    goto block_18;
                }
                pV[3] = pV[3] - m_unk1B0;
                *(u_long128 *)pV = *(u_long128 *)m_unk190;
                pV[1] = m_unk190[1];
                pV[2] = m_unk190[2];
                sceVu0ScaleVectorXYZ((float *)((char *)m_unk184 + s4), spB0, m_unk140);
                goto block_18;
            }
block_18:
            pV = (float *)((char *)m_unk180 + s4);
            fW = pV[3];
            fRatio = fW / m_unk1B0;
            if (fRatio < 0.9999999f) {
            } else {
                fRatio = 0.9999999f;
            }
            pVec = (float *)((char *)m_unk184 + s4);
            fA = m_unk120;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            pPart[0] = (pV[0] + (-fA + (fA + fA) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)))) + fRatio * pVec[0];
            fA = m_unk124;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            pPart[1] = (pV[1] + (-fA + (fA + fA) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)))) + fRatio * pVec[1];
            fA = m_unk128;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            pPart[2] = (pV[2] + (-fA + (fA + fA) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)))) + fRatio * pVec[2];
            fT = fRatio * m_unk148;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            fF5 = 0.75f * m_unk158;
            fFrac = fT - (float)(int)fT;
            if (fFrac <= 0.5f) {
                fLerp = m_unk134;
                fR = fLerp + (2.0f * (fFrac * (m_unk138 - fLerp)));
            } else {
                fLerp = m_unk138;
                fR = fLerp + (2.0f * ((fFrac - 0.5f) * (m_unk13C - fLerp)));
            }
            pPart[3] = fR;
            pPart[3] = pPart[3] * (1.0f + (-fF5 + (2.0f * fF5 * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)))));
            if (m_unk19 != 0) {
                fF7 = 30.0f * m_unk2C;
                m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
                nA = m_unkD0;
                m_unkD0 = nA * 0x343FD + 0x269EC3;
                nB = m_unkD0;
                fBase = 0.001f + (0.0139999995f * m_unk28);
                fHalf = 0.2f * fBase;
                fTwo = 2.0f * fHalf;
                fNeg = -fHalf;
                m_unkD0 = nB * 0x343FD + 0x269EC3;
                fF22 = 180.0f * ((((float)((int)(fW * (fF7 + ((0.5f * fF7) - fF7) * (0.000030517578f * (float)((nA >> 16) & 0x7FFF)))) % 360)) / 180.0f) - 1.0f);
                fF23 = fBase + (fNeg + (fTwo * (0.000030517578f * (float)((nB >> 16) & 0x7FFF))));
                fF24 = fBase + (fNeg + (fTwo * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF))));
                fF22s = FastMath_Sin180(fF22);
                pPart[4] = fF23 * FastMath_Cos180(fF22);
                pPart[5] = fF24 * fF22s;
            } else {
                fT = fRatio * m_unk14C;
                fFrac = fT - (float)(int)fT;
                if (fFrac <= 0.5f) {
                    vC[0] = m_unk100 - m_unkF0;
                    vC[1] = m_unk104 - m_unkF4;
                    vC[2] = m_unk108 - m_unkF8;
                    sceVu0ScaleVectorXYZ(vC, vC, 2.0f * fFrac);
                    vC[0] += m_unkF0;
                    vC[1] += m_unkF4;
                    vC[2] += m_unkF8;
                } else {
                    vC[0] = m_unk110 - m_unk100;
                    vC[1] = m_unk114 - m_unk104;
                    vC[2] = m_unk118 - m_unk108;
                    sceVu0ScaleVectorXYZ(vC, vC, 2.0f * (fFrac - 0.5f));
                    vC[0] += m_unk100;
                    vC[1] += m_unk104;
                    vC[2] += m_unk108;
                }
                pPart[4] = ClampRangeDraft(vC[0], 255.0f);
                pPart[5] = ClampRangeDraft(vC[1], 255.0f);
                pPart[6] = ClampRangeDraft(vC[2], 255.0f);
            }
            fT = fRatio * m_unk150;
            fFrac = fT - (float)(int)fT;
            if (fFrac <= 0.5f) {
                fC = m_unkFC;
                fLerp = ((m_unk10C - fC) * (2.0f * fFrac)) + fC;
            } else {
                fC = m_unk10C;
                fLerp = ((m_unk11C - fC) * (2.0f * (fFrac - 0.5f))) + fC;
            }
            pPart[7] = ClampRangeDraft(fLerp, 128.0f);
block_66:
            s3 += 0x20;
            s4 += 0x10;
            s2 += 1;
            goto loop_67;
        }
    }
}

// DRAFT: 0x001C69F0 Create__14PParticleTrailFP22tagParticleTrailParamsfff
// note: 10 words differ: clamp fMax and m_unkA0 ternaries match in shape; the post-clamp store order and sqrt tail (0x2B8-0x2C0) still differ. Tried fLo<=fMid vs fLo>fMid spellings, per-store reloads, nested-if clamp.
int PParticleTrail::Create(tagParticleTrailParams *pParams, float fA, float fB, float fC) {
    if (PParticleSystem::Create(pParams->m_unk50, true) == 0) {
        return 0;
    }
    m_unk0C = 4;
    m_unk30 = 0x48;
    memcpy(&m_unkE0, pParams, 0xA0);
    m_unkE0 += fA;
    m_unkE4 += fB;
    m_unkE8 += fC;
    *(u_long128 *)m_unk190 = *(u_long128 *)&m_unkE0;
    *(u_long128 *)m_unk1A0 = *(u_long128 *)&m_unkE0;
    m_unk1B0 = 10.0f + (80.0f * (1.0f - m_unk144));
    m_unk1BC = (int)(0.5f + (56789.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
    m_unk1B8 = 0;
    m_unk158 = 1.0f - m_unk158;
    m_unk1B4 = 0;
    if (m_unk160 != 0) {
        m_unk180 = __nwa__FUi(pParams->m_unk50 * 0x10);
        if (m_unk180 == 0) {
            return 0;
        }
        m_unk184 = __nwa__FUi(pParams->m_unk50 * 0x10);
        if (m_unk184 == 0) {
            return 0;
        }
        unsigned int i = 0;
        unsigned int off = 0;
        for (; i < m_unk04;) {
            ++i;
            *(float *)((unsigned char *)m_unk180 + off) = m_unk190[0];
            *(float *)((unsigned char *)m_unk180 + off + 4) = m_unk190[1];
            *(float *)((unsigned char *)m_unk180 + off + 8) = m_unk190[2];
            *(float *)((unsigned char *)m_unk180 + off + 12) = 1.0f + m_unk1B0;
            float *pB = (float *)((unsigned char *)m_unk184 + off);
            pB[2] = 0.0f;
            off += 0x10;
            pB[1] = 0.0f;
            pB[0] = 0.0f;
            pB[3] = 1.0f;
        }
    } else {
        unsigned int i = 0;
        unsigned int off = 0;
        for (; i < m_unk04;) {
            ++i;
            float *pA = (float *)((unsigned char *)m_unk08 + off);
            pA[0] = m_unk190[0];
            pA[1] = m_unk190[1];
            pA[2] = m_unk190[2];
            off += 0x20;
        }
    }
    float fLo = m_unk134;
    float fMid = m_unk138;
    float fMax = (fLo > fMid) ? fLo : fMid;
    m_unkA0 = (fMax <= m_unk13C) ? m_unk13C : ((fLo <= fMid) ? fMid : fLo);
    m_unk80 = m_unk190[0];
    m_unk84 = m_unk190[1];
    m_unk88 = m_unk190[2];
    m_unk8C = 0x3F800000;
    m_unk90 = m_unkA0 + m_unk120;
    m_unk94 = m_unkA0 + m_unk124;
    m_unk98 = m_unkA0 + m_unk128;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001C6D50 __dt__14PParticleTrailFv
PParticleTrail::~PParticleTrail() {
    *(unsigned char **)this = __vt__14PParticleTrail;
    if (m_unk180) {
        __dla__FPv(m_unk180);
        m_unk180 = 0;
    }
    if (m_unk184) {
        __dla__FPv(m_unk184);
        m_unk184 = 0;
    }
}

// FUNCTION: 0x001C6DF0 __ct__14PParticleTrailFv
PParticleTrail::PParticleTrail() {
    *(unsigned char **)this = __vt__14PParticleTrail;
    m_unk180 = 0;
    m_unk184 = 0;
    m_unk1B8 = 0;
}
