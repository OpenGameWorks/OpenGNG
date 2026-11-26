// FLAGS: -str readonly
#include "types.h"
#include "PParticleMovingFog.h"

// TODO(header): foreign declarations
class PFrustrum;
extern "C" void sceVu0UnitMatrix(float (*pMatrix)[4]);
extern "C" void sceVu0ScaleVectorXYZ(float *dst, float *src, float scale);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void __construct_array(void *pBlock, void (*pCtor)(void *), void (*pDtor)(void *, short), unsigned int nElemSize, unsigned int nCount);
extern "C" void __ct__5PMat4Fv(void *pThis);
extern "C" void __dt__5PMat4Fv(void *pThis, short nFlag);

// FUNCTION: 0x001D63E0 Render__18PParticleMovingFogFv
void PParticleMovingFog::Render() {
    float mtx[4][4];
    sceVu0UnitMatrix(mtx);
    for (unsigned int i = 0; i < m_unk4A0; i++) {
        m_unk60[i].Render(&m_unk320[i]);
    }
}

// FUNCTION: 0x001D6460 FrustrumTest__18PParticleMovingFogFP9PFrustrumPfff
void PParticleMovingFog::FrustrumTest(PFrustrum *pFrustum, float *pPos, float fNear, float fFar) {
    for (unsigned int i = 0; i < m_unk4A0; i++) {
        m_unk60[i].FrustrumTest(pFrustum, pPos, fNear, fFar, &m_unk320[i]);
    }
}

// FUNCTION: 0x001D6730 Create__18PParticleMovingFogFP26tagParticleMovingFogParams
int PParticleMovingFog::Create(tagParticleMovingFogParams *pParams) {
    memcpy(m_unk10, pParams, 0x50);
    m_unk4A0 = 6;
    sceVu0ScaleVectorXYZ(m_unk40, m_unk40, 255.0f);
    m_unk40[3] *= 128.0f;
    CreateFogObjects();
    return 1;
}

// FUNCTION: 0x001D67A0 __dt__18PParticleMovingFogFv
PParticleMovingFog::~PParticleMovingFog() {}

// FUNCTION: 0x001D6830 __ct__18PParticleMovingFogFv
PParticleMovingFog::PParticleMovingFog() {
    __construct_array(m_unk320, __ct__5PMat4Fv, __dt__5PMat4Fv, 0x40, 6);
    memset(m_unk10, 0, 0x50);
    m_unk4A0 = 0;
}
