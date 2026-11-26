#include "types.h"
#include "PParticleLiteExplosion.h"
#include "PMat4.h"
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" int rand(void);
extern "C" float sqrtf(float x);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
void FastMath_VectorFabs(float *pDst, float *pSrc);
extern unsigned char __vt__22PParticleLiteExplosion[];

// FUNCTION: 0x001F6CF0 Start__22PParticleLiteExplosionFf
void PParticleLiteExplosion::Start(float fScale) {
    m_unk160 = fScale;
    m_unk90 = fScale;
    m_unk94 = m_unk160;
    m_unk98 = m_unk160;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    ((PParticleLiteExplosionView *)this)->Start();
}

// FUNCTION: 0x001F6D40 SetPosition__22PParticleLiteExplosionFPfPf
void PParticleLiteExplosion::SetPosition(float *pA, float *pB) {
    sceVu0CopyVector(m_unk1B0, pA);
}

// FUNCTION: 0x001F6D50 ModifyPosition__22PParticleLiteExplosionFP5PMat4
void PParticleLiteExplosion::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk1B0, m_unkE0);
}

// FUNCTION: 0x001F6D70 Start__22PParticleLiteExplosionFv
void PParticleLiteExplosion::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk194 = 0;
    m_unk1C0 = (int)(0.5f + (12345.0f + 41976.0f * ((float)rand() / 2147483648.0f)));
    *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk1B0;
    m_unk80 = m_unk1B0[0];
    m_unk84 = m_unk1B0[1];
    m_unk88 = m_unk1B0[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001F75C0 Create__22PParticleLiteExplosionFP30tagParticleLiteExplosionParamsfff
int PParticleLiteExplosion::Create(tagParticleLiteExplosionParams *pParams, float fA, float fB, float fC) {
    float aVec[4];

    if (!PParticleSystem::Create(pParams->m_unk70, false)) {
        return 0;
    }
    m_unk0C = 0x11;
    m_unk30 = 0x48;
    memcpy(m_unkE0, pParams, 0xB0);
    m_unk170 = 1.0f - m_unk170;
    m_unkE0[0] += fA;
    m_unkE0[1] += fB;
    m_unkE0[2] += fC;
    *(u_long128 *)m_unk1B0 = *(u_long128 *)m_unkE0;
    m_unk190 = 5.0f + 175.0f * (1.0f - m_unk15C);
    m_unk194 = 0;
    m_unk1C0 = (int)(0.5f + (12543.0f + 21978.0f * ((float)rand() / 2147483648.0f)));
    m_unk80 = m_unk1B0[0];
    m_unk84 = m_unk1B0[1];
    m_unk88 = m_unk1B0[2];
    m_unk8C = 0x3F800000;
    sceVu0SubVector(aVec, m_unk100, m_unkF0);
    FastMath_VectorFabs(aVec, aVec);
    m_unk90 = m_unk160 + aVec[0];
    m_unk94 = m_unk160 + aVec[1];
    m_unk98 = m_unk160 + aVec[2];
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001F77B0 __dt__22PParticleLiteExplosionFv
extern "C" void *__dt__22PParticleLiteExplosionFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__22PParticleLiteExplosion;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F7810 __ct__22PParticleLiteExplosionFv
extern "C" void *__ct__22PParticleLiteExplosionFv(void *pThis) {
    __ct__15PParticleSystemFv(pThis);
    *(void **)pThis = __vt__22PParticleLiteExplosion;
    return pThis;
}
