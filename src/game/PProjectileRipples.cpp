#include "types.h"
#include "PProjectileRipples.h"

// TODO(header): foreign declarations
extern "C" void FadeAndDie__15PParticleSystemFUi(void *, unsigned int);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__18PProjectileRipples[];
extern "C" void SetMaterial__10PGfxEngineFPfbUlUl(void *, float *, bool, unsigned long, unsigned long);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void BeginFxInstances__10PGfxEngineFPvib(void *, void *, int, bool);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *, void *, int, bool);
extern unsigned char gGfxEng[0x10];
extern unsigned char gDisplayListPtr[0x10];

// DRAFT: 0x00217790 FindFreeRing__18PProjectileRipplesFv
// note: loop shape differs; original has an extra nop before the bottom slt and a b to jr ra at +0x48 (ours +0x44); tried index, running offset, while, break, continue, comma increment
int PProjectileRipples::FindFreeRing() {
    int i = 0;
    int count = m_unk10C;
    int off = 0;
    for (; i < count; off += 0x60, i++) {
        if (((PProjectileRing *)((char *)m_unk120 + off))->m_unk50 == 0) {
            return i;
        }
    }
    return -1;
}

// FUNCTION: 0x00217A70 FadeAndDie__18PProjectileRipplesFUi
void PProjectileRipples::FadeAndDie(unsigned int uArg) {
    FadeAndDie__15PParticleSystemFUi(this, uArg);
    m_unk18 = 0;
}

// DRAFT: 0x00217AA0 Render__18PProjectileRipplesFv
// note: 49 differing lines; gate branches and m_unk138 layout differ (original shares one epilogue via b, ours uses direct beqz); tried nested gates, combined &&, early returns, locals at top
void PProjectileRipples::Render() {
    if (m_unk15 != 0) {
        if (m_unk124 != 0) {
            if (m_unk138 != 0) {
                if (m_unk19 != 0) {
                    float a[4] = {1.1f, 1.1f, 1.1f, 1.0f};
                    SetMaterial__10PGfxEngineFPfbUlUl(gGfxEng, a, true, m_unk30, 0x50000);
                } else {
                    float b[4] = {1.0f, 1.0f, 1.0f, 0.8f};
                    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk10, b, true, m_unk30, 0x50000);
                }
                BeginFxInstances__10PGfxEngineFPvib(gGfxEng, m_unk12C, m_unk130, m_unk19);
                DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)gDisplayListPtr, m_unk134, m_unk138, false);
            }
        }
    }
}

// FUNCTION: 0x00218030 __dt__18PProjectileRipplesFv
extern "C" void *__dt__18PProjectileRipplesFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PProjectileRipples *pSelf = (PProjectileRipples *)pThis;
        *(void **)pThis = __vt__18PProjectileRipples;
        if (pSelf->m_unk12C != 0) {
            __dla__FPv(pSelf->m_unk12C);
            pSelf->m_unk12C = 0;
            pSelf->m_unk130 = 0;
        }
        if (pSelf->m_unk120 != 0) {
            __dla__FPv(pSelf->m_unk120);
            pSelf->m_unk120 = 0;
        }
        pSelf->m_unk124 = 0;
        pSelf->m_unk134 = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x002180D0 __ct__18PProjectileRipplesFv
PProjectileRipples::PProjectileRipples() {
    __ct__15PParticleSystemFv(this);
    m_unk000 = __vt__18PProjectileRipples;
    m_unk12C = 0;
    m_unk130 = 0;
    m_unk124 = 0;
    m_unk134 = 0;
}
