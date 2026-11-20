#include "types.h"
#include "PMat4.h"
#include "PParticleExplosion.h"

// TODO(header): foreign declarations
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
