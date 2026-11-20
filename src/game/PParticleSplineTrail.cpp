#include "types.h"
#include "PParticleSplineTrail.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern unsigned char __vt__20PParticleSplineTrail[];

// DRAFT: 0x001F0E20 Start__20PParticleSplineTrailFv
// note: loop matches except the offset and constant registers swap (orig offset a3, const a1); declaration order variants did not change it.
void PParticleSplineTrail::Start() {
    m_unk160 = 1.0f;
    int nVal = 0xC9742400;
    int nOffset = 0;
    for (unsigned int i = 0; i < m_unk04; i++) {
        *(int *)((char *)m_unk08 + nOffset) = nVal;
        *(int *)((char *)m_unk08 + nOffset + 8) = nVal;
        nOffset += 0x20;
    }
    m_unk15 = 1;
    m_unk18 = 1;
}

// FUNCTION: 0x001F1340 SetPosition__20PParticleSplineTrailFPfPf
void PParticleSplineTrail::SetPosition(float *pFrom, float *pTo) {
    sceVu0CopyVector(m_unk150, pFrom);
    m_unk80 = m_unk150[0];
    m_unk84 = m_unk150[1];
    m_unk88 = m_unk150[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001F1390 ModifyPosition__20PParticleSplineTrailFP5PMat4
void PParticleSplineTrail::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk150, m_unkE0);
    m_unk80 = m_unk150[0];
    m_unk84 = m_unk150[1];
    m_unk88 = m_unk150[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001F1A70 __dt__20PParticleSplineTrailFv
extern "C" void *__dt__20PParticleSplineTrailFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__20PParticleSplineTrail;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F1AD0 __ct__20PParticleSplineTrailFv
extern "C" void *__ct__20PParticleSplineTrailFv(void *pThis) {
    __ct__15PParticleSystemFv(pThis);
    *(void **)pThis = __vt__20PParticleSplineTrail;
    return pThis;
}
