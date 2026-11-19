#include "types.h"

// TODO(header): foreign declarations
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern char vu_clip_microcode_dma_packet[];

class PDisplayList {
public:
    void SetVu1Microcode(void *pMicrocode);
    void DrawParticles(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag, int nMode);

    char _pad000[0xA3348];
    int m_unkA3348;                     // 0xA3348
};

#include "PGfxEngine.h"

// DRAFT: 0x184F40 EndShadowRender__10PGfxEngineFv
// note: original tail-calls SetVu1Microcode with j and no frame; this compiler emits jal plus a frame for every tail-position call (20 words differ).
void PGfxEngine::EndShadowRender() {
    m_unk154C80->m_unkA3348 = 1;
    m_unk158E1C = &vu_clip_microcode_dma_packet;
    m_unk154C80->SetVu1Microcode(m_unk158E1C);
}

// DRAFT: 0x1851B0 DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb
// note: original tail-calls DrawParticles with j and no frame; this compiler emits jal plus a frame for every tail-position call (13 words differ).
void PGfxEngine::DrawFxLines(struct tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag) {
    m_unk154C80->DrawParticles((struct tagVuParticle *)pLines, nCount, fB, fA, bFlag, 0x23);
}

// FUNCTION: 0x185E50 SetFullAmbientLight__10PGfxEngineFv
void PGfxEngine::SetFullAmbientLight() {
    m_unk158EB0[0] = 128.0f;
    m_unk158EB0[1] = 128.0f;
    m_unk158EB0[2] = 128.0f;
    m_unk158EB0[3] = 0.0f;
}

// FUNCTION: 0x185E90 SetAmbientLight__10PGfxEngineFPf
void PGfxEngine::SetAmbientLight(float *pVec) {
    sceVu0ScaleVector(m_unk158EB0, pVec, 128.0f);
    m_unk158EB0[3] = 0.0f;
}

// FUNCTION: 0x188900 __dt__Q210PGfxEngine22tagBlendedFragmentInfoFv
PGfxEngine::tagBlendedFragmentInfo::~tagBlendedFragmentInfo() {}
