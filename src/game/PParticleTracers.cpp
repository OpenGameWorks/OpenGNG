#include "types.h"
#include "PParticleTracers.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" float sqrtf(float x);
extern "C" int rand(void);
extern unsigned char __vt__16PParticleTracers[];

// FUNCTION: 0x00203710 ModifyPosition__16PParticleTracersFP5PMat4
void PParticleTracers::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk160, m_unkE0);
    m_unk80 = m_unk160[0];
    m_unk84 = m_unk160[1];
    m_unk88 = m_unk160[2];
}

// FUNCTION: 0x00203760 SetPosition__16PParticleTracersFPfPf
void PParticleTracers::SetPosition(float *pFrom, float *pTo) {
    sceVu0CopyVector(m_unk160, pFrom);
    sceVu0SubVector(m_unkF0, pTo, pFrom);
    m_unk124 = sqrtf(sceVu0InnerProduct(m_unkF0, m_unkF0));
    sceVu0Normalize(m_unkF0, m_unkF0);
    m_unk80 = m_unk160[0];
    m_unk84 = m_unk160[1];
    m_unk88 = m_unk160[2];
    if (m_unk178 != 0) {
        ComputeTracerAxes();
    }
}

// FUNCTION: 0x00203810 Start__16PParticleTracersFv
void PParticleTracers::Start() {
    m_unk150 = (int)(0.5f + (12335.0f + (18991.0f * ((float)rand() / 2.1474836e9f))));
    InitTracers();
    m_unk15 = 1;
    m_unk18 = 1;
}

// FUNCTION: 0x00204170 __dt__16PParticleTracersFv
extern "C" void *__dt__16PParticleTracersFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleTracers *pSelf = (PParticleTracers *)pThis;
        *(void **)pThis = __vt__16PParticleTracers;
        if (pSelf->m_unk174 != 0) {
            __dla__FPv(pSelf->m_unk174);
            pSelf->m_unk174 = 0;
        }
        pSelf->m_unk178 = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x002041F0 __ct__16PParticleTracersFv
PParticleTracers::PParticleTracers() {
    *(void **)this = __vt__16PParticleTracers;
    m_unk174 = 0;
    m_unk178 = 0;
}
