#include "types.h"
#include "PMidasShieldRings.h"

// TODO(header): foreign declarations
extern "C" void FadeAndDie__15PParticleSystemFUi(void *, unsigned int);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__17PMidasShieldRings[];
extern "C" void SetMaterial__10PGfxEngineFPfbUlUl(void *, float *, bool, unsigned long, unsigned long);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void BeginFxInstances__10PGfxEngineFPvib(void *, void *, int, bool);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *, void *, int, bool);
extern unsigned char gGfxEng[0x10];
extern unsigned char gDisplayListPtr[0x10];

// FUNCTION: 0x001F8D10 FindFreeRing__17PMidasShieldRingsFv
int PMidasShieldRings::FindFreeRing() {
    int i = 0;
    int off = 0;
    do {
        if (m_unk15C[off] == 0) {
            return i;
        }
        i++;
        off += 0x14;
    } while (i < 8);
    return -1;
}

// FUNCTION: 0x001F8E80 FadeAndDie__17PMidasShieldRingsFUi
void PMidasShieldRings::FadeAndDie(unsigned int uArg) {
    FadeAndDie__15PParticleSystemFUi(this, uArg);
    m_unk18 = 0;
}

// DRAFT: 0x001F8EB0 Render__17PMidasShieldRingsFv
// note: 49 differing lines; m_unk200 gate uses beqz to the epilogue, original uses bnez to body plus b to epilogue; tried nested gates, early returns, goto done
void PMidasShieldRings::Render() {
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk1EC == 0) {
        return;
    }
    if (m_unk200 == 0) {
        goto done;
    }
    if (m_unk19 != 0) {
        float a[4] = {1.1f, 1.1f, 1.1f, 1.0f};
        SetMaterial__10PGfxEngineFPfbUlUl(gGfxEng, a, true, m_unk30, 0x50000);
    } else {
        float b[4] = {1.0f, 1.0f, 1.0f, 0.8f};
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk10, b, true, m_unk30, 0x50000);
    }
    BeginFxInstances__10PGfxEngineFPvib(gGfxEng, m_unk1F4, m_unk1F8, m_unk19);
    DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)gDisplayListPtr, m_unk1FC, m_unk200, false);
done:
    return;
}

// FUNCTION: 0x001F9770 __dt__17PMidasShieldRingsFv
extern "C" void *__dt__17PMidasShieldRingsFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PMidasShieldRings *pSelf = (PMidasShieldRings *)pThis;
        *(void **)pThis = __vt__17PMidasShieldRings;
        if (pSelf->m_unk1F4 != 0) {
            __dla__FPv(pSelf->m_unk1F4);
            pSelf->m_unk1F4 = 0;
            pSelf->m_unk1F8 = 0;
        }
        pSelf->m_unk1EC = 0;
        pSelf->m_unk1FC = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F9800 __ct__17PMidasShieldRingsFv
PMidasShieldRings::PMidasShieldRings() {
    __ct__15PParticleSystemFv(this);
    m_unk000 = __vt__17PMidasShieldRings;
    m_unk1F4 = 0;
    m_unk1F8 = 0;
    m_unk1EC = 0;
    m_unk1FC = 0;
}
