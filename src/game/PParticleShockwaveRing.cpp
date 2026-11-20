// FLAGS: -str readonly
#include "types.h"
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
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern u_long128 lit_0024DDB0;

// FUNCTION: 0x001F9850 Start__22PParticleShockwaveRingFv
void PParticleShockwaveRing::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk1E0 = 0.0f;
}

// DRAFT: 0x001F9890 Animate__22PParticleShockwaveRingFf
// note: 113 words differ; guard branch layout (original beqz to body + b to exit) and body shift; size 0x1f4 vs 0x1fc; tried &&, nested, else-return guards and sin/cos tail (dead sin call, cos reused)
void PParticleShockwaveRing::Animate(float fDelta) {
    u_long128 vTmp30;
    u_long128 vTmp40;

    if (m_unk15 != 0) {
    if (m_unk16 == 0) {
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
        ((float *)&vTmp40)[0] = 0.0f;
        ((float *)&vTmp40)[1] = 1.0f;
        ((float *)&vTmp40)[2] = 0.0f;
        ((float *)&vTmp40)[3] = 0.0f;
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
        FastMath_Sin180(fAngle);
        float fCos = FastMath_Cos180(fAngle);
        m_unk130 = m_unk1C4 * fCos;
        m_unk134 = m_unk1C8 * fCos;
    }
    } else {
        return;
    }
    }
}

// DRAFT: 0x001F9A90 Create__22PParticleShockwaveRingFP30tagParticleShockwaveRingParamsfff
// note: 32 words differ; frame 0x60 and s2 base (addiu s2,s1,0x140) missing, 16-byte constant loaded via lui/addiu in original but unresolved lui $at on ours; tried readonly flag, direct m_unkD0 reads, pVec removal, raw-address constant (34 words, worse), pointer-variable constant (34 words, worse)
void PParticleShockwaveRing::Create(tagParticleShockwaveRingParams *pParams, float fA, float fB, float fC) {
    if (pParams == 0) {
        CdsAssert__FPciPc("PParticleShockwaveRing.cpp", 0x1B, "pParams");
    }
    PParticleSystem::Create(1, false);
    memcpy(&m_unk140, pParams, 0xA0);
    ((float *)&m_unk140)[0] = ((float *)&m_unk140)[0] + fA;
    ((float *)&m_unk140)[1] = ((float *)&m_unk140)[1] + fB;
    ((float *)&m_unk140)[2] = ((float *)&m_unk140)[2] + fC;
    ((float *)&m_unk140)[3] = 1.0f;

    if (*(float *)((char *)pParams + 0x70) == -1.0f) {
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        m_unk1B0[0] = -180.0f + 360.0f * ((float)((m_unkD0 >> 16) & 0x7FFF) * 3.0517578125e-05f);
    }
    if (*(float *)((char *)pParams + 0x74) == -1.0f) {
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        m_unk1B0[1] = -180.0f + 360.0f * ((float)((m_unkD0 >> 16) & 0x7FFF) * 3.0517578125e-05f);
    }
    if (*(float *)((char *)pParams + 0x78) == -1.0f) {
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        m_unk1B0[2] = -180.0f + 360.0f * ((float)((m_unkD0 >> 16) & 0x7FFF) * 3.0517578125e-05f);
    }

    {
        u_long128 vScale = lit_0024DDB0;
        sceVu0MulVector((float *)&m_unk150, (float *)&m_unk150, (float *)&vScale);
        sceVu0MulVector((float *)&m_unk160, (float *)&m_unk160, (float *)&vScale);
        sceVu0MulVector((float *)&m_unk170, (float *)&m_unk170, (float *)&vScale);
    }

    m_unk1E0 = 0.0f;
    m_unk1E4 = 1.0f / *(float *)((char *)pParams + 0x80);
    m_unk1E8 = 0.0f;
    m_unk0C = 0x13;
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

// DRAFT: 0x001F9D90 __ct__22PParticleShockwaveRingFv
// note: 19 words differ; base ctor call and this spill match; original reloads this from 0x1C(sp) before each use and keeps no s0, ours saves s0 across memset; tried extern C void* form (explicit base call, 19 words), member form (19 words), extern C form without base call (20 words, wrong: original does call base at 0x0C)
PParticleShockwaveRing::PParticleShockwaveRing() {
    *(void **)this = (void *)__vt__22PParticleShockwaveRing;
    m_unk1E0 = 0.0f;
    m_unk1E4 = 0.0f;
    memset((char *)this + 0xE0, 0, 0x60);
}
