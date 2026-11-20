#include "types.h"
#include "PParticleGas.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern unsigned char __vt__12PParticleGas[];

// FUNCTION: 0x001EC810 FadeOut__12PParticleGasFf
void PParticleGas::FadeOut(float fFade) {
    m_unk138 = fFade;
    m_unk164 = fFade;
    m_unk168 = 1;
}

// FUNCTION: 0x001EC830 Stop__12PParticleGasFv
void PParticleGas::Stop() {
    if (m_unk138) {
        FadeOut(m_unk138);
    } else {
        m_unk18 = 0;
    }
}

// FUNCTION: 0x001EC890 FadeAndDie__12PParticleGasFUi
void PParticleGas::FadeAndDie(unsigned int nUnused) {
    PParticleSystem::FadeAndDie(nUnused);
    if (!m_unk138) {
        return;
    }
    FadeOut(m_unk138);
}

// FUNCTION: 0x001ED650 __dt__12PParticleGasFv
PParticleGas::~PParticleGas() {
    *(unsigned char **)this = __vt__12PParticleGas;
    if (m_unk150) {
        __dla__FPv(m_unk150);
        m_unk150 = 0;
    }
    __dt__15PParticleSystemFv(this, 0);
}

// DRAFT: 0x001ED6D0 __ct__12PParticleGasFv
// note: vtable, memset of 0x70 bytes at 0xE0, then zeroing of 0x150..0x168 match in order; original keeps this in a 0x1C(sp) spill slot with no s0 save, ours saves s0 (25 words differ). Embedded init member (inline memset ctor) gave 26 words.
PParticleGas::PParticleGas() {
    *(unsigned char **)this = __vt__12PParticleGas;
    memset((char *)this + 0xE0, 0, 0x70);
    m_unk150 = 0;
    m_unk154 = 0;
    m_unk160 = 0;
    m_unk164 = 0;
    m_unk168 = 0;
}
