#include "types.h"
#include "PParticleLiteFire.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void __dla__FPv(void *);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern unsigned char __vt__17PParticleLiteFire[];

// FUNCTION: 0x001C9E70 Enable__17PParticleLiteFireFb
void PParticleLiteFire::Enable(bool bEnable) {
    m_unk15 = bEnable;
    m_unk191 = (m_unk191 | !bEnable) != 0;
}

// DRAFT: 0x001C9EB0 FadeAndDie__17PParticleLiteFireFUi
// note: 4 words differ at 0x4C-0x58: original uses $v1 for constant 1 and $at for the compare; ours uses $a0 and $v1. Tried negated compare (DIFF 4), store moved after if (DIFF 6), local compare temp (more diffs than 4).
void PParticleLiteFire::FadeAndDie(unsigned int nArg) {
    PParticleSystem::FadeAndDie(nArg);
    m_unk18C = (float)nArg;
    m_unk190 = 1;
    if (nArg >= 2U) {
        m_unk17 = 0;
    }
}

// FUNCTION: 0x001C9F30 ModifyPosition__17PParticleLiteFireFP5PMat4
void PParticleLiteFire::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk170, (float *)_pad0E0);
    if (m_unk191) {
        unsigned int i = 0;
        if (m_unk160) {
            for (i = 0; i < m_unk04; i++) {
                ((u_long128 *)m_unk160)[i] = *(u_long128 *)m_unk170;
            }
            m_unk191 = 0;
        }
    }
    m_unk80 = m_unk170[0];
    m_unk84 = m_unk170[1] + 0.5f * m_unk140;
    m_unk88 = m_unk170[2];
}

// FUNCTION: 0x001C9FE0 SetPosition__17PParticleLiteFireFPfPf
void PParticleLiteFire::SetPosition(float *pPos, float *pUnused) {
    sceVu0CopyVector(m_unk170, pPos);
    if (m_unk191) {
        unsigned int i = 0;
        if (m_unk160) {
            for (i = 0; i < m_unk04; i++) {
                ((u_long128 *)m_unk160)[i] = *(u_long128 *)m_unk170;
            }
            m_unk191 = 0;
        }
    }
    m_unk80 = m_unk170[0];
    m_unk84 = m_unk170[1] + 0.5f * m_unk140;
    m_unk88 = m_unk170[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001CADE0 __dt__17PParticleLiteFireFv
PParticleLiteFire::~PParticleLiteFire() {
    *(unsigned char **)this = __vt__17PParticleLiteFire;
    if (m_unk180) {
        __dla__FPv(m_unk180);
        m_unk180 = 0;
    }
    if (m_unk160) {
        __dla__FPv(m_unk160);
        m_unk160 = 0;
    }
}

// FUNCTION: 0x001CAE80 __ct__17PParticleLiteFireFv
PParticleLiteFire::PParticleLiteFire() {
    *(unsigned char **)this = __vt__17PParticleLiteFire;
    m_unk180 = 0;
    m_unk160 = 0;
    m_unk18C = 0;
    m_unk190 = 0;
    m_unk191 = 0;
}
