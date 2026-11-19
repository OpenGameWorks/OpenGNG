#include "types.h"

// TODO(header): foreign declarations
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern char vu_clip_microcode_dma_packet[];
class PMat4;

class PDisplayList {
public:
    void SetVu1Microcode(void *pMicrocode);
    void DrawParticles(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag, int nMode);
    void WriteToVu1Mem(unsigned int nAddr, void *pData, int nCount);
    void SetScreenMatrix(PMat4 *pMat);

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

// DRAFT: 0x1851F0 SetBlurHazeSourcePoint__10PGfxEngineFPff
// note: 4 words differ: load order and register assignment of the float words (7 variants tried, declaration order nX,nY,nZ,nW kept) plus the WriteToVu1Mem jal name, which cannot match the declared name.
void PGfxEngine::SetBlurHazeSourcePoint(float *pPos, float fW) {
    unsigned int nX = *(unsigned int *)&pPos[0];
    unsigned int nY = *(unsigned int *)&pPos[1];
    unsigned int nZ = *(unsigned int *)&pPos[2];
    unsigned int nW = *(unsigned int *)&fW;
    unsigned int aPos[4];
    aPos[0] = nX;
    aPos[1] = nY;
    aPos[2] = nZ;
    aPos[3] = nW;
    m_unk154C80->WriteToVu1Mem(0x3C7, aPos, 1);
}

// DRAFT: 0x185460 EndFxRender__10PGfxEngineFv
// note: original tail-calls SetVu1Microcode with j and no frame; this compiler emits jal plus a frame for every tail-position call.
void PGfxEngine::EndFxRender() {
    m_unk154C80->m_unkA3348 = 1;
    m_unk158E1C = &vu_clip_microcode_dma_packet;
    m_unk154C80->SetVu1Microcode(m_unk158E1C);
}

// DRAFT: 0x1858E0 UpdateLights__10PGfxEngineFP17tagVuLightingInfo
// note: only the two jal targets differ; the original names WriteToVu1Mem__12PDisplayListFUiP1i (two parameters) while the call passes three, so the declared name FUiPvi cannot match.
void PGfxEngine::UpdateLights(struct tagVuLightingInfo *pInfo) {
    if (m_unk158E23 != 0) {
        m_unk154C80->WriteToVu1Mem(0x35E, pInfo, 13);
        return;
    }
    m_unk154C80->WriteToVu1Mem(0x35E, pInfo, 9);
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

// FUNCTION: 0x1869D0 SetScreenMatrix__10PGfxEngineFP5PMat4
void PGfxEngine::SetScreenMatrix(PMat4 *pMat) {
    m_unk154C80->SetScreenMatrix(pMat);
    u_long128 *pDst = (u_long128 *)m_unk16D3C0;
    u_long128 *pSrc = (u_long128 *)pMat;
    pDst[0] = pSrc[0];
    pDst[1] = pSrc[1];
    pDst[2] = pSrc[2];
    pDst[3] = pSrc[3];
}

// FUNCTION: 0x187BB0 FadeFullScreenMotionBlur__10PGfxEngineFci
void PGfxEngine::FadeFullScreenMotionBlur(char cTarget, int nFrames) {
    m_unk16D405 = cTarget;
    if (nFrames != 0) {
        m_unk16D406 = (char)((m_unk16D405 - m_unk16D404) / nFrames);
        return;
    }
    m_unk16D404 = cTarget;
}

// FUNCTION: 0x188900 __dt__Q210PGfxEngine22tagBlendedFragmentInfoFv
PGfxEngine::tagBlendedFragmentInfo::~tagBlendedFragmentInfo() {}
