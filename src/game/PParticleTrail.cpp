#include "types.h"
#include "PParticleTrail.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern unsigned char __vt__14PParticleTrail[];
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern "C" void __dla__FPv(void *);

// FUNCTION: 0x001C5F10 Start__14PParticleTrailFv
void PParticleTrail::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk1B4 = 0;
}

// FUNCTION: 0x001C5F30 ModifyPosition__14PParticleTrailFP5PMat4
void PParticleTrail::ModifyPosition(PMat4 *pMat) {
    *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk190;
    pMat->MulVector(m_unk190, (float *)_pad0E0);
    m_unk80 = m_unk190[0];
    m_unk84 = m_unk190[1];
    m_unk88 = m_unk190[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001C5F90 SetPosition__14PParticleTrailFPfPf
void PParticleTrail::SetPosition(float *pPos, float *pUnused) {
    *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk190;
    sceVu0CopyVector(m_unk190, pPos);
    m_unk80 = m_unk190[0];
    m_unk84 = m_unk190[1];
    m_unk88 = m_unk190[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001C6D50 __dt__14PParticleTrailFv
PParticleTrail::~PParticleTrail() {
    *(unsigned char **)this = __vt__14PParticleTrail;
    if (m_unk180) {
        __dla__FPv(m_unk180);
        m_unk180 = 0;
    }
    if (m_unk184) {
        __dla__FPv(m_unk184);
        m_unk184 = 0;
    }
}

// FUNCTION: 0x001C6DF0 __ct__14PParticleTrailFv
PParticleTrail::PParticleTrail() {
    *(unsigned char **)this = __vt__14PParticleTrail;
    m_unk180 = 0;
    m_unk184 = 0;
    m_unk1B8 = 0;
}
