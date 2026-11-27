// FLAGS: -str readonly
#include "types.h"
#include "PRandom.h"
#include "Debug.h"
#include "PParticleShockwaveRing.h"

// TODO(header): foreign declarations
extern "C" void sceVu0InterVector(float *pDst, float *pA, float *pB, float fT);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
void FastMath_RotateMatrix(float (*pDst)[4][4], float (*pSrc)[4][4], float (*pAngles)[4], float (*pMat)[4][4]);
float FastMath_Sin180(float fAngle);
float FastMath_Cos180(float fAngle);
extern "C" void sceVu0MulVector(float *pDst, float *pSrc, float *pT);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__22PParticleShockwaveRing[0x40];

// FUNCTION: 0x001F9850 Start__22PParticleShockwaveRingFv
void PParticleShockwaveRing::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk1E0 = 0.0f;
}

// FUNCTION: 0x001F9870 FrustrumTest__22PParticleShockwaveRingFP9PFrustrumPfff
void PParticleShockwaveRing::FrustrumTest(PFrustrum *, float *, float, float) {
    *(int *)((char *)this + 0xA4) = 1;
}

// FUNCTION: 0x001F9880 Render__22PParticleShockwaveRingFv
void PParticleShockwaveRing::Render() {
}

// DRAFT: 0x001F9890 Animate__22PParticleShockwaveRingFf
// note: 13 words differ, all in `m_unk1E0 += m_unk1E4 * fDelta`: the original loads m_unk1E4 into f2 and m_unk1E0 into f1 and schedules the mul without a nop; ours swaps the registers. Tried +=, operand orders, fStep/fCur/fRate locals, an fT local for the compare.
void PParticleShockwaveRing::Animate(float fDelta) {
    u_long128 vTmp30;
    u_long128 vTmp40;

    if (!m_unk15 || m_unk16) {
        return;
    }
    m_unk1E8 = m_unk1E8 + 3.0f * fDelta;
    if (m_unk1E8 >= 360.0f) {
        m_unk1E8 = m_unk1E8 - 360.0f;
    }
    if (m_unk1E0 < 0.5f) {
        sceVu0InterVector((float *)&vTmp40, (float *)&m_unk190, (float *)&m_unk180, 2.0f * m_unk1E0);
        sceVu0InterVector((float *)&vTmp30, (float *)&m_unk160, (float *)&m_unk150, 2.0f * m_unk1E0);
    } else {
        sceVu0InterVector((float *)&vTmp40, (float *)&m_unk1A0, (float *)&m_unk190, 2.0f * (m_unk1E0 - 0.5f));
        sceVu0InterVector((float *)&vTmp30, (float *)&m_unk170, (float *)&m_unk160, 2.0f * (m_unk1E0 - 0.5f));
    }
    m_unk1E0 = m_unk1E0 + m_unk1E4 * fDelta;
    if (m_unk1E0 >= 1.0f) {
        m_unk15 = 0;
        m_unk16 = m_unk17;
        vTmp40 = (u_long128)0x3F80000000000000ULL;
        ((unsigned int *)&vTmp30)[3] = 0;
    }
    sceVu0UnitMatrix(m_unkE0);
    m_unkE0[0][0] = ((float *)&vTmp40)[0];
    m_unkE0[1][1] = ((float *)&vTmp40)[1];
    m_unkE0[2][2] = ((float *)&vTmp40)[2];
    sceVu0CopyVector(m_unkE0[3], (float *)&m_unk140);
    FastMath_RotateMatrix(&m_unkE0, &m_unkE0, &m_unk1B0, (float (*)[4][4])&m_unk40);
    *(u_long128 *)&m_unk120 = vTmp30;
    {
        float fAngle = m_unk1E8 - 180.0f;
        float fSin = FastMath_Sin180(fAngle);
        float fCos = FastMath_Cos180(fAngle);
        m_unk130 = m_unk1C4 * fCos;
        m_unk134 = m_unk1C8 * fSin;
    }
}

// FUNCTION: 0x001F9A90 Create__22PParticleShockwaveRingFP30tagParticleShockwaveRingParamsfff
int PParticleShockwaveRing::Create(tagParticleShockwaveRingParams *pParams, float fA, float fB, float fC) {
    if (pParams == 0) {
        CdsAssert("PParticleShockwaveRing.cpp", 0x1B, "pParams");
    }
    PParticleSystem::Create(1, false);
    memcpy(&m_unk140, pParams, 0xA0);
    ((float *)&m_unk140)[0] = ((float *)&m_unk140)[0] + fA;
    ((float *)&m_unk140)[1] = ((float *)&m_unk140)[1] + fB;
    ((float *)&m_unk140)[2] = ((float *)&m_unk140)[2] + fC;
    ((float *)&m_unk140)[3] = 1.0f;

    if (*(float *)((char *)pParams + 0x70) == -1.0f) {
        m_unk1B0[0] = -180.0f + 360.0f * ParticleRand01(m_unkD0);
    }
    if (*(float *)((char *)pParams + 0x74) == -1.0f) {
        m_unk1B0[1] = -180.0f + 360.0f * ParticleRand01(m_unkD0);
    }
    if (*(float *)((char *)pParams + 0x78) == -1.0f) {
        m_unk1B0[2] = -180.0f + 360.0f * ParticleRand01(m_unkD0);
    }

    {
        float vScale[4] = {0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f};
        sceVu0MulVector((float *)&m_unk150, (float *)&m_unk150, (float *)&vScale);
        sceVu0MulVector((float *)&m_unk160, (float *)&m_unk160, (float *)&vScale);
        sceVu0MulVector((float *)&m_unk170, (float *)&m_unk170, (float *)&vScale);
    }

    m_unk1E0 = 0.0f;
    m_unk1E4 = 1.0f / *(float *)((char *)pParams + 0x80);
    m_unk1E8 = 0.0f;
    m_unk0C = 0x13;
    return 1;
}

// FUNCTION: 0x001F9D30 __dt__22PParticleShockwaveRingFv
extern "C" void *__dt__22PParticleShockwaveRingFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = (void *)__vt__22PParticleShockwaveRing;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F9D90 __ct__22PParticleShockwaveRingFv
PParticleShockwaveRing::PParticleShockwaveRing() {
    *(void **)this = (void *)__vt__22PParticleShockwaveRing;
    m_unk1E0 = 0.0f;
    m_unk1E4 = 0.0f;
    memset((char *)this + 0xE0, 0, 0x60);
}
