// FLAGS: -str readonly
#include "types.h"
#include "PRandom.h"
#include "Debug.h"
#include "PParticleEnergyStream.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" float sqrtf(float x);
extern unsigned char __vt__21PParticleEnergyStream[];
// TODO(header): gGfxEng is the PGfxEngine global; only m_unk154C80 (display list pointer) is used here.
struct PGfxEngineRef {
    char _pad000[0x154C80];
    void *m_unk154C80;
};
extern PGfxEngineRef gGfxEng;
extern unsigned char fx_spline_particle_clip_init[];
extern "C" int printf(const char *, ...);
extern "C" void *AllocParticles__12PDisplayListFii(void *, int, int);
extern "C" void BeginFxLoop__12PDisplayListFUi(void *, unsigned int);
extern "C" void DrawSplineParticles__12PDisplayListFP14tagVuSplineKeyiifbi(void *, void *, int, int, float, bool, int);
extern "C" void ComputeVuSplineKeys__21PParticleEnergyStreamFP13tagVuParticleiP14tagVuSplineKeyi(void *, void *, int, void *, int);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *, void *);
extern "C" int rand(void);
extern "C" float FastMath_Sin180__Ff(float fValue);
extern "C" float FastMath_Cos180__Ff(float fValue);

// FUNCTION: 0x001F5510 ComputeVuSplineKeys__21PParticleEnergyStreamFP13tagVuParticleiP14tagVuSplineKeyi
void PParticleEnergyStream::ComputeVuSplineKeys(tagVuParticle *pParticles, int nUnused, tagVuSplineKey *pKeys, int nCount) {
    float vecA[4];
    float vecB[4];
    float vecC[4];
    float fScale = (1.0f - m_unk130) / 2.0f;
    int nIdx = 1;
    if (1 < nCount - 1) {
        int nSrc = 0;
        int nDst = 0x40;
        do {
            sceVu0CopyVector((char *)pKeys + nDst, (float *)((char *)pParticles + nSrc));
            sceVu0CopyVector((char *)pKeys + nDst + 0x10, (float *)((char *)pParticles + nSrc + 0x10));
            nIdx += 1;
            nSrc += 0x20;
            nDst += 0x40;
        } while (nIdx < nCount - 1);
    }
    memcpy(pKeys, (char *)pKeys + 0x40, 0x40);
    memcpy((char *)pKeys + ((nCount - 1) << 6), (char *)pKeys + ((nCount - 2) << 6), 0x40);
    int nK = 0;
    if (0 < nCount - 3) {
        int nOff = 0;
        do {
            char *pNext = (char *)pKeys + ((nK + 1) << 6);
            char *pCur = (char *)pKeys + nOff;
            sceVu0SubVector(vecC, (float *)pNext, (float *)pCur);
            char *pNext2 = (char *)pKeys + ((nK + 2) << 6);
            sceVu0SubVector(vecA, (float *)pNext2, (float *)pNext);
            sceVu0AddVector(vecA, vecC, vecA);
            sceVu0ScaleVector((float *)(pCur + 0x20), vecA, fScale);
            sceVu0SubVector(vecC, (float *)pNext2, (float *)pNext);
            sceVu0SubVector(vecB, (float *)((char *)pKeys + ((nK + 3) << 6)), (float *)pNext2);
            sceVu0AddVector(vecB, vecC, vecB);
            sceVu0ScaleVector((float *)(pCur + 0x30), vecB, fScale);
            nK += 1;
            nOff += 0x40;
        } while (nK < nCount - 3);
    }
}

// FUNCTION: 0x001F56F0 SetPosition__21PParticleEnergyStreamFPfPf
void PParticleEnergyStream::SetPosition(float *pFrom, float *pTo) {
    sceVu0CopyVector(m_unkE0, pFrom);
    sceVu0CopyVector(m_unk180, pTo);
    sceVu0SubVector(m_unk110, m_unk180, m_unkE0);
    m_unk128 = sqrtf(sceVu0InnerProduct(m_unk110, m_unk110));
    sceVu0Normalize(m_unk110, m_unk110);
    if (m_unk08 == 0) {
        CdsAssert("PParticleEnergyStream.cpp", 0x12A, "mpVuParticles");
    }
    sceVu0CopyVector((char *)m_unk08 + ((m_unk04 - 1) << 5), m_unk180);
    sceVu0CopyVector(m_unk08, m_unkE0);
    m_unk80 = (m_unk180[0] + m_unkE0[0]) * 0.5f;
    m_unk84 = (m_unk180[1] + m_unkE0[1]) * 0.5f;
    m_unk88 = (m_unk180[2] + m_unkE0[2]) * 0.5f;
    *(float *)&m_unk8C = 1.0f;
    m_unk90 = m_unk128 * 0.5f;
    m_unk94 = m_unk128 * 0.5f;
    m_unk98 = m_unk128 * 0.5f;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
}

// FUNCTION: 0x001F5850 Stop__21PParticleEnergyStreamFv
void PParticleEnergyStream::Stop() {
    m_unk18 = 0;
}

// FUNCTION: 0x001F5860 Start__21PParticleEnergyStreamFv
void PParticleEnergyStream::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk190 = 1.0f;
    m_unk19C = 0;
    m_unk194 = 1.0f;
}

// FUNCTION: 0x001F5880 FadeAndDie__21PParticleEnergyStreamFUi
void PParticleEnergyStream::FadeAndDie(unsigned int nUnused) {
    PParticleSystem::FadeAndDie(nUnused);
}

// FUNCTION: 0x001F5890 ModifyPosition__21PParticleEnergyStreamFP5PMat4
void PParticleEnergyStream::ModifyPosition(PMat4 *pMat) {
    sceVu0CopyMatrix((float (*)[4])((char *)this + 0x40), (float (*)[4])pMat);
}

// DRAFT: 0x001F58A0 Render__21PParticleEnergyStreamFv
// note: DIFF 80; size 0x170 vs 0x178. Original keeps bnez-to-body plus b-to-epilogue (ld ra in delay slot) for the m_unk08 return and loads the 0x154C80 offset before lw nCount; ours uses beqz and schedules differently. Tried nested if, early return, -str readonly; no change.
void PParticleEnergyStream::Render() {
    if (m_unk15 != 0 && m_unk14 != 0 && m_unkA4 != 0) {
        if (m_unk08 == 0) {
            return;
        }
        int nCount = m_unk124 + 2;
        void *pKeys = AllocParticles__12PDisplayListFii(gGfxEng.m_unk154C80, nCount, 4);
        if (pKeys == 0) {
            printf("\nToo many particles! Particles pool is full. Spline trail not rendered!\n");
            return;
        }
        ComputeVuSplineKeys__21PParticleEnergyStreamFP13tagVuParticleiP14tagVuSplineKeyi(this, m_unk08, m_unk04, pKeys, nCount);
        float vec[4];
        sceVu0CopyVector(vec, &m_unkC0);
        vec[3] *= m_unk190 * m_unk194;
        SetMaterial__10PGfxEngineFiPfbUlUl(&gGfxEng, m_unk10, vec, 1, (unsigned long)m_unk30, 0x50000);
        SetWorldMatrix__10PGfxEngineFP5PMat4(&gGfxEng, &m_unk40);
        BeginFxLoop__12PDisplayListFUi(gGfxEng.m_unk154C80, ((unsigned int)fx_spline_particle_clip_init + 0x778) >> 3);
        int nWidth = m_unk120;
        DrawSplineParticles__12PDisplayListFP14tagVuSplineKeyiifbi(gGfxEng.m_unk154C80, pKeys, nCount, nWidth, 1.0f / (float)nWidth, 0, 30);
    }
}

// DRAFT: 0x001F5A20 Animate__21PParticleEnergyStreamFf
// note: DIFF 329 words; original frame is 0x90 with s0..s6 live (draft uses 0x60, s0..s3); the operand swap of fDelta == 0.0f changed nothing.
void PParticleEnergyStream::Animate(float fDelta) {
    if (m_unk15 == 0 || m_unk16 != 0 || fDelta == 0.0f) {
        return;
    }
    if (m_unk17 == 0 && m_unkA4 != 0) {
        m_unkD0 = *(int *)((char *)this + 0x170);
        float fTime = m_unk19C + 15.0f * *(float *)((char *)this + 0x144);
        if (fTime < 360.0f) {
            m_unk19C = fTime;
        } else {
            m_unk19C = 0.0f;
        }
        int nStep = m_unk04 - 1;
        float fStep = 1.0f / (float)(nStep + nStep);
        float fAcc = 0.0f;
        float fAngle = m_unk19C;
        if (*(float *)((char *)this + 0x140) != 0.0f) {
            float fA = m_unk194 + m_unk198;
            if (fA > 0.0f) {
                m_unk194 = fA;
                if (fA < 1.0f) {
                    float fR = (float)rand() / 2147483648.0f;
                    *(int *)((char *)this + 0x170) = (int)(0.5f + (12340.0f + fR * 41920.0f));
                } else {
                    m_unk198 = -m_unk198;
                }
            }
            if (*(unsigned char *)((char *)this + 0x1A0) != 0) {
                for (int i = 0; i < 4; i++) {
                    float fR = (float)rand() / 2147483648.0f;
                    m_unk110[i] = -1.0f + 2.0f * fR;
                }
            }
            {
                int sb;
                float fScale = m_unk128;
                float *pA = (float *)((char *)this + 0x110);
                float *pB = (float *)((char *)this + 0xE0);
                float *pD = (float *)((char *)this + 0x180);
                asm { mfc1 sb, fScale }
                asm {
                    lqc2 vf1, 0x0(pA)
                    lqc2 vf2, 0x0(pB)
                    lqc2 vf5, 0x0(pD)
                    qmtc2.i sb, vf3
                    vmulx.xyz vf4, vf1, vf3x
                    vadd.xyz vf5, vf4, vf2
                    sqc2 vf5, 0x0(pD)
                }
            }
            m_unk80 = (m_unk180[0] + m_unkE0[0]) * 0.5f;
            m_unk84 = (m_unk180[1] + m_unkE0[1]) * 0.5f;
            m_unk88 = (m_unk180[2] + m_unkE0[2]) * 0.5f;
            int nCount = (*(unsigned char *)((char *)this + 0x1A0) != 0) ? m_unk04 - 1 : m_unk04;
            for (int s0 = 1; s0 < nCount; s0++) {
                fAcc += fStep;
                float fScale = m_unk128 * fAcc;
                float *pP = (float *)((char *)m_unk08 + (s0 << 5));
                int sb;
                float *pA = (float *)((char *)this + 0x110);
                float *pB = (float *)((char *)this + 0xE0);
                asm { mfc1 sb, fScale }
                asm {
                    lqc2 vf1, 0x0(pA)
                    lqc2 vf2, 0x0(pB)
                    lqc2 vf5, 0x0(pP)
                    qmtc2.i sb, vf3
                    vmulx.xyz vf4, vf1, vf3x
                    vadd.xyz vf5, vf4, vf2
                    sqc2 vf5, 0x0(pP)
                }
                float fU = ParticleRand01(m_unkD0);
                fAngle += -60.0f + 120.0f * fU;
                if (fAngle < 0.0f) {
                    fAngle += 360.0f;
                } else if (fAngle > 360.0f) {
                    fAngle -= 360.0f;
                }
                float fSin = FastMath_Sin180__Ff(fAngle - 180.0f);
                float fCos = FastMath_Cos180__Ff(fAngle - 180.0f);
                float fR2 = 2.0f * *(float *)((char *)this + 0x12C);
                pP[0] = pP[0] + fR2 * fSin;
                pP[1] = pP[1] + (fSin * fCos) * fR2;
                pP[2] = pP[2] + fR2 * fCos;
            }
        }
    }
    if (m_unk18 != 0 && m_unk17 != 0) {
        float fLeft = m_unk190 - *(float *)((char *)this + 0x13C);
        if (fLeft > 0.0f) {
            m_unk190 = fLeft;
        } else {
            m_unk190 = 0.0f;
        }
    }
    m_unk15 = 0;
    m_unk16 = m_unk17;
}

// DRAFT: 0x001F5F70 Create__21PParticleEnergyStreamFP29tagParticleEnergyStreamParamsfff
// note: DIFF 369 words; original keeps this in s0 with frame 0x40 and saves only s0, ours keeps this in s2 and saves s0-s2 with frame 0x60; tried memcpy(m_unkE0) form (370).
int PParticleEnergyStream::Create(tagParticleEnergyStreamParams *pParams, float fA, float fB, float fC) {
    memcpy((char *)this + 0xE0, pParams, 0x90);
    if (m_unk124 >= 0x1C) {
        m_unk124 = 0x1C;
    } else if (m_unk124 < 5) {
        m_unk124 = 4;
    }
    if (m_unk120 >= 0x3C) {
        m_unk120 = 0x3C;
    } else if (m_unk120 < 5) {
        m_unk120 = 4;
    }
    if (m_unk13C <= 0.0f) {
        m_unk13C = 0.14285715f;
    }
    m_unk13C = 1.0f / m_unk13C;
    m_unkE0[0] += fA;
    m_unkE0[1] += fB;
    m_unkE0[2] += fC;
    m_unkE0[3] = 1.0f;
    if (m_unk110[0] == -1.0f && m_unk110[1] == -1.0f && m_unk110[2] == -1.0f) {
        m_unk1A0 = 1;
        m_unk110[0] = -1.0f + 2.0f * ((float)rand() / 2147483648.0f);
        m_unk110[1] = -1.0f + 2.0f * ((float)rand() / 2147483648.0f);
        m_unk110[2] = -1.0f + 2.0f * ((float)rand() / 2147483648.0f);
    } else {
        m_unk1A0 = 0;
    }
    {
        int sb;
        float fScale = m_unk128;
        float *pA = (float *)((char *)this + 0x110);
        float *pB = (float *)((char *)this + 0xE0);
        float *pD = (float *)((char *)this + 0x180);
        asm { mfc1 sb, fScale }
        asm {
            lqc2 vf1, 0x0(pA)
            lqc2 vf2, 0x0(pB)
            lqc2 vf5, 0x0(pD)
            qmtc2.i sb, vf3
            vmulx.xyz vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyz vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(pD)
        }
    }
    m_unk180[3] = 1.0f;
    if (PParticleSystem::Create(m_unk124, true) == 0) {
        return 0;
    }
    m_unk0C = 15;
    m_unk190 = 1.0f;
    float fR = (float)rand() / 2147483648.0f;
    float fX = 60.0f * (12345.0f + 41976.0f * fR);
    m_unk170 = (int)(0.5f + fX);
    m_unk19C = 0.0f;
    m_unk194 = 1.0f;
    float fD = fX * (1.0f - m_unk140);
    if (fD <= 2.0f) {
        fD = 2.0f;
    }
    m_unk198 = -(1.0f / fD);
    float fStep = 1.0f / (float)(m_unk04 - 1);
    float fAcc = 0.0f;
    float fTmp[4];
    sceVu0SubVector(fTmp, m_unk100, m_unkF0);
    for (unsigned int i = 0; i < m_unk04 - 1; i++) {
        float *pP = (float *)((char *)m_unk08 + (i << 5));
        float fS = m_unk128 * fAcc;
        int sb;
        float *pA = (float *)((char *)this + 0x110);
        float *pB = (float *)((char *)this + 0xE0);
        asm { mfc1 sb, fS }
        asm {
            lqc2 vf1, 0x0(pA)
            lqc2 vf2, 0x0(pB)
            lqc2 vf5, 0x0(pP)
            qmtc2.i sb, vf3
            vmulx.xyz vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyz vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(pP)
        }
        pP[3] = m_unk134 + fAcc * (m_unk138 - m_unk134);
        float *pT = fTmp;
        float *pC = (float *)((char *)this + 0xF0);
        float *pQ = (float *)((char *)pP + 0x10);
        asm { mfc1 sb, fAcc }
        asm {
            lqc2 vf1, 0x0(pT)
            lqc2 vf2, 0x0(pC)
            qmtc2.i sb, vf3
            vmulx.xyzw vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyzw vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(pQ)
        }
        fAcc += fStep;
    }
    sceVu0CopyVector((char *)m_unk08 + ((m_unk04 - 1) << 5), m_unk180);
    sceVu0CopyVector((char *)m_unk08 + ((m_unk04 - 1) << 5) + 0x10, m_unk100);
    *(float *)((char *)m_unk08 - 0x14 + (m_unk04 << 5)) = m_unk138;
    m_unkA0 = (m_unk134 > m_unk138) ? m_unk134 : m_unk138;
    m_unk80 = 0.5f * (m_unk180[0] + m_unkE0[0]);
    m_unk84 = 0.5f * (m_unk180[1] + m_unkE0[1]);
    m_unk88 = 0.5f * (m_unk180[2] + m_unkE0[2]);
    m_unk8C = 0x3F800000;
    m_unk90 = 0.5f * m_unk128;
    m_unk94 = 0.5f * m_unk128;
    m_unk98 = 0.5f * m_unk128;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
}

// FUNCTION: 0x001F6560 __dt__21PParticleEnergyStreamFv
extern "C" void *__dt__21PParticleEnergyStreamFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__21PParticleEnergyStream;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F65C0 __ct__21PParticleEnergyStreamFv
PParticleEnergyStream::PParticleEnergyStream() {
    *(void **)this = __vt__21PParticleEnergyStream;
    memset((char *)this + 0xE0, 0, 0x90);
}
