// FLAGS: -str readonly
#include "types.h"
#include "PCyclocksFx.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
extern char gGfxEng[1504384];
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void __dl__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);

// FUNCTION: 0x001F7850 StopFx__11PCyclocksFxFUi
void PCyclocksFx::StopFx(unsigned int hFx) {
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    if (pMgr == 0) {
        CdsAssert__FPciPc("PCyclocksFx.cpp", 0x95, "apFxMgr");
    }
    pMgr->Stop(hFx);
}

// FUNCTION: 0x001F7AD0 StopEyeBeam__11PCyclocksFxFv
void PCyclocksFx::StopEyeBeam() {
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    for (int i = 0; i < 3; i++) {
        pMgr->Stop(m_unk00[i]);
    }
    pMgr->Stop(m_unk0C);
}

// DRAFT: 0x001F7CF0 CreateEyeBeamForAchille__11PCyclocksFxFv
// note: prologue and handle literal copy match; loop body computes handles[i] as addu/lw 0x50(v0) where original uses addiu sp,0x50 / addu / lw 0(v0). Tried array init, byte pointer, per-iteration &handles[i], and *(handles + i); all DIFF 23 words.
void PCyclocksFx::CreateEyeBeamForAchille() {
    unsigned int handles[3] = {0x830002F1, 0x830002F2, 0x830002F0};
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    for (int i = 0; i < 3; i++) {
        m_unk00[i] = (int)pMgr->Create(handles[i], 0.0f, 0.0f, 0.0f, 0, true);
    }
    m_unk0C = 0;
}

// FUNCTION: 0x001F7E70 __dt__11PCyclocksFxFv
PCyclocksFx::~PCyclocksFx() {
    DestroyEyeBeam();
}

// FUNCTION: 0x001F7ED0 __ct__11PCyclocksFxFv
PCyclocksFx::PCyclocksFx() {
    memset(this, 0, 0xC);
    m_unk0C = 0;
}
