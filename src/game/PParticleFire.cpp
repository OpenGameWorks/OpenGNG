#include "types.h"
#include "PParticleFire.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern unsigned char __vt__13PParticleFire[];

// FUNCTION: 0x001B6400 Enable__13PParticleFireFb
void PParticleFire::Enable(bool bEnable) {
    m_unk15 = bEnable;
    m_unk198 = (m_unk198 | !bEnable) != 0;
}

// FUNCTION: 0x001B6440 ModifyPosition__13PParticleFireFP5PMat4
void PParticleFire::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk180, m_unkF0);
    m_unk80 = m_unk180[0];
    m_unk84 = m_unk180[1] + 0.5f * m_unk150;
    m_unk88 = m_unk180[2];
    m_unk8C = 0x3F800000;
    if (m_unk198) {
        if (m_unkE4) {
            unsigned int i = 0;
            for (i = 0; i < m_unk04; i++) {
                ((u_long128 *)m_unkE4)[i] = *(u_long128 *)m_unk180;
            }
            m_unk198 = 0;
        }
    }
}

// FUNCTION: 0x001B6500 SetPosition__13PParticleFireFPfPf
void PParticleFire::SetPosition(float *pPos, float *pUnused) {
    sceVu0CopyVector(m_unk180, pPos);
    m_unk80 = m_unk180[0];
    m_unk84 = m_unk180[1] + 0.5f * m_unk150;
    m_unk88 = m_unk180[2];
    m_unk8C = 0x3F800000;
    if (m_unk198) {
        if (m_unkE4) {
            unsigned int i = 0;
            for (i = 0; i < m_unk04; i++) {
                ((u_long128 *)m_unkE4)[i] = *(u_long128 *)m_unk180;
            }
            m_unk198 = 0;
        }
    }
}

// FUNCTION: 0x001B74F0 __dt__13PParticleFireFv
PParticleFire::~PParticleFire() {
    *(unsigned char **)this = __vt__13PParticleFire;
    if (m_unkE0) {
        __dla__FPv(m_unkE0);
        m_unkE0 = 0;
    }
    if (m_unkE4) {
        __dla__FPv(m_unkE4);
        m_unkE4 = 0;
    }
    __dt__15PParticleSystemFv(this, 0);
}

// FUNCTION: 0x001B7590 __ct__13PParticleFireFv
PParticleFire::PParticleFire() {
    *(unsigned char **)this = __vt__13PParticleFire;
    m_unkE4 = 0;
    m_unkE0 = 0;
}
