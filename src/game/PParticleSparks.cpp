#include "types.h"
#include "PParticleSparks.h"

// TODO(header): foreign declarations
class PMat4;
struct tagVuFxLine;
extern "C" void MulVector__5PMat4FPfPf(PMat4 *pMat, float *pSrc, float *pDst);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__15PParticleSparks[];
extern "C" int rand();
extern char gGfxEng[1504384];
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *, PMat4 *);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void BeginFxLines__10PGfxEngineFv(void *);
extern "C" void DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(void *, tagVuFxLine *, int, float, float, bool);
extern "C" void EndFxLines__10PGfxEngineFv(void *);

// FUNCTION: 0x001F8240 ModifyPosition__15PParticleSparksFP5PMat4
void PParticleSparks::ModifyPosition(PMat4 *pMat) {
    MulVector__5PMat4FPfPf(pMat, (float *)&m_unk150, (float *)&m_unkE0);
    m_unk80 = ((float *)&m_unk150)[0];
    m_unk84 = ((float *)&m_unk150)[1];
    m_unk88 = ((float *)&m_unk150)[2];
}

// FUNCTION: 0x001F8290 Start__15PParticleSparksFv
void PParticleSparks::Start() {
    m_unk148 = 0;
    m_unk170 = (int)(0.5f + (62315.0f + (-10989.0f * ((float)rand() / 2147483648.0f))));
    m_unk160 = m_unk150;
    InitSparkDirections();
    m_unk15 = 1;
    m_unk18 = 1;
}

// DRAFT: 0x001F8330 Render__15PParticleSparksFv
// note: DIFF 37; the m_unk08 test is bnez to body, nop, b epilogue in the original; ours is beqz to epilogue. Tried nested-if, if/else, empty-then, combined &&, four early returns, trailing return in body, trailing return after if.
void PParticleSparks::Render() {
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk16 != 0) {
        return;
    }
    if (m_unkA4 == 0) {
        return;
    }
    if (m_unk08 != 0) {
        SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)&m_unk40);
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, 0, (float *)&m_unkC0, true, m_unk30, 0x50000);
        BeginFxLines__10PGfxEngineFv(gGfxEng);
        DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(gGfxEng, (tagVuFxLine *)m_unk08, m_unk04, 0.0f, 128.0f, m_unk1A);
        EndFxLines__10PGfxEngineFv(gGfxEng);
    }
    return;
}

// FUNCTION: 0x001F88C0 __dt__15PParticleSparksFv
PParticleSparks::~PParticleSparks() {
    *(void **)this = __vt__15PParticleSparks;
    if (m_unk140 != 0) {
        __dla__FPv(m_unk140);
        m_unk140 = 0;
    }
    __dt__15PParticleSystemFv(this, 0);
}

// FUNCTION: 0x001F8940 __ct__15PParticleSparksFv
PParticleSparks::PParticleSparks() {
    *(void **)this = __vt__15PParticleSparks;
    m_unk140 = 0;
}
