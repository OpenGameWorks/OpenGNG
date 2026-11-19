#include "types.h"

// TODO(header): foreign declarations
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void iFlushCache(int nMode);
extern char vu_clip_microcode_dma_packet[];
extern char vu_shadow_microcode_dma_packet[];
extern char vu_fx_microcode_dma_packet[];
extern char vu_debug_microcode_dma_packet[];
extern char dbg_display_init[];
extern int gCDSVBlankCount[1];
extern float GAME_FPS;
class PMat4;

class PDisplayList {
public:
    void SetVu1Microcode(void *pMicrocode);
    void DrawParticles(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag, int nMode);
    void WriteToVu1Mem(unsigned int nAddr, u_long128 *pData, int nCount);
    void SetViewMatrix(PMat4 *pMat);
    void SetClipMatrix(PMat4 *pMat);
    void SetScreenMatrix(PMat4 *pMat);
    void SetVifCodes(unsigned int nA, unsigned int nB);
    void SetGsRegisters(int *pData);

    char _pad000[0xA3348];
    int m_unkA3348;                     // 0xA3348
};

class PGrid {
public:
    void Enable(bool bEnable);
};

#include "PGfxEngine.h"

// DRAFT: 0x184800 VBlankEndInterruptHandler__Fi
// note: 2 words differ: the original places daddu v1,zero,zero before sd ra; ours emits sd ra first (6 variants: scalar/array counter, consolidated/split COP0 asm, lui/sync as .word, nop, daddu moved to its own asm before the counter).
int VBlankEndInterruptHandler(int nIrq) {
    asm { .word 0x0000182D }
    gCDSVBlankCount[0]++;
    asm {
        .word 0x4002C801
        .word 0x3C017F00
        .word 0x34210001
        .word 0x0041082A
        .word 0x14200002
        nop
        .word 0x4083C801
        .word 0x4002C803
        .word 0x3C017F00
        .word 0x34210001
        .word 0x0041082A
        .word 0x14200002
        nop
        .word 0x4083C803
        .word 0x0000000F
        .word 0x0000040F
    }
    iFlushCache(0);
    asm {
        .word 0x0000000F
        ei
    }
    return 0;
}

// DRAFT: 0x184F40 EndShadowRender__10PGfxEngineFv
// note: original tail-calls SetVu1Microcode with j and no frame; this compiler emits jal plus a frame for every tail-position call (20 words differ).
void PGfxEngine::EndShadowRender() {
    m_unk154C80->m_unkA3348 = 1;
    m_unk158E1C = &vu_clip_microcode_dma_packet;
    m_unk154C80->SetVu1Microcode(m_unk158E1C);
}

// FUNCTION: 0x184F90 BeginShadowRender__10PGfxEngineFv
void PGfxEngine::BeginShadowRender() {
    m_unk154C80->m_unkA3348 = 1;
    void *pShadow = &vu_shadow_microcode_dma_packet;
    if (m_unk158E1C != pShadow) {
        m_unk158E1C = pShadow;
        m_unk154C80->SetVu1Microcode(m_unk158E1C);
    }
}

// DRAFT: 0x1851B0 DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb
// note: original tail-calls DrawParticles with j and no frame; this compiler emits jal plus a frame for every tail-position call (13 words differ).
void PGfxEngine::DrawFxLines(struct tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag) {
    m_unk154C80->DrawParticles((struct tagVuParticle *)pLines, nCount, fB, fA, bFlag, 0x23);
}

// FUNCTION: 0x1851F0 SetBlurHazeSourcePoint__10PGfxEngineFPff
void PGfxEngine::SetBlurHazeSourcePoint(float *pPos, float fW) {
    unsigned int nX;
    unsigned int nY;
    unsigned int nZ;
    unsigned int nW;
    nW = *(unsigned int *)&fW;
    nZ = *(unsigned int *)&pPos[2];
    nY = *(unsigned int *)&pPos[1];
    nX = *(unsigned int *)&pPos[0];
    unsigned int aPos[4];
    aPos[0] = nX;
    aPos[1] = nY;
    aPos[2] = nZ;
    aPos[3] = nW;
    m_unk154C80->WriteToVu1Mem(0x3C7, (u_long128 *)aPos, 1);
}

// DRAFT: 0x1852D0 SetGlowSizeAndColor__10PGfxEngineFffPf
// note: frame 0x40 matches with volatile colour copy; the four colour loads are one-at-a-time, original batches loads then stores (struct copy is dropped as dead without volatile).
void PGfxEngine::SetGlowSizeAndColor(float fA, float fB, float *pColor) {
    unsigned int aData[4];
    volatile unsigned int aColor[4];
    aData[0] = *(unsigned int *)&fA;
    aData[2] = 0;
    aData[1] = *(unsigned int *)&fB;
    aData[3] = 0;
    aColor[0] = *(unsigned int *)&pColor[0];
    aColor[1] = *(unsigned int *)&pColor[1];
    aColor[2] = *(unsigned int *)&pColor[2];
    aColor[3] = *(unsigned int *)&pColor[3];
    m_unk154C80->WriteToVu1Mem(0x3C3, (u_long128 *)aData, 2);
}

// DRAFT: 0x185460 EndFxRender__10PGfxEngineFv
// note: original tail-calls SetVu1Microcode with j and no frame; this compiler emits jal plus a frame for every tail-position call.
void PGfxEngine::EndFxRender() {
    m_unk154C80->m_unkA3348 = 1;
    m_unk158E1C = &vu_clip_microcode_dma_packet;
    m_unk154C80->SetVu1Microcode(m_unk158E1C);
}

// FUNCTION: 0x1854B0 BeginFxRender__10PGfxEngineFv
void PGfxEngine::BeginFxRender() {
    m_unk154C80->m_unkA3348 = 2;
    void *pFx = &vu_fx_microcode_dma_packet;
    if (m_unk158E1C != pFx) {
        m_unk158E1C = pFx;
        m_unk154C80->SetVu1Microcode(m_unk158E1C);
    }
}

// FUNCTION: 0x1857C0 BeginDebugRender__10PGfxEngineFv
void PGfxEngine::BeginDebugRender() {
    void *pDbg = &vu_debug_microcode_dma_packet;
    m_unk154C80->SetVu1Microcode(pDbg);
    m_unk158E1C = pDbg;
    m_unk154C80->SetVifCodes(0U, ((unsigned int)dbg_display_init >> 3) | 0x14000000);
}

// FUNCTION: 0x1858E0 UpdateLights__10PGfxEngineFP17tagVuLightingInfo
void PGfxEngine::UpdateLights(struct tagVuLightingInfo *pInfo) {
    if (m_unk158E23 != 0) {
        m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)pInfo, 13);
        return;
    }
    m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)pInfo, 9);
}

// FUNCTION: 0x185CF0 UpdateLights__10PGfxEngineFv
void PGfxEngine::UpdateLights() {
    if (m_unk158E23 != 0) {
        m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)m_unk158E30, 13);
        return;
    }
    m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)m_unk158E30, 9);
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

// FUNCTION: 0x186A40 SetViewMatrix__10PGfxEngineFP5PMat4
void PGfxEngine::SetViewMatrix(PMat4 *pMat) {
    m_unk154C80->SetViewMatrix(pMat);
    u_long128 *pDst = (u_long128 *)m_unk16D380;
    u_long128 *pSrc = (u_long128 *)pMat;
    pDst[0] = pSrc[0];
    pDst[1] = pSrc[1];
    pDst[2] = pSrc[2];
    pDst[3] = pSrc[3];
}

// FUNCTION: 0x186AB0 SetClipMatrix__10PGfxEngineFP5PMat4
void PGfxEngine::SetClipMatrix(PMat4 *pMat) {
    m_unk154C80->SetClipMatrix(pMat);
    u_long128 *pDst = (u_long128 *)m_unk16D340;
    u_long128 *pSrc = (u_long128 *)pMat;
    pDst[0] = pSrc[0];
    pDst[1] = pSrc[1];
    pDst[2] = pSrc[2];
    pDst[3] = pSrc[3];
}

// DRAFT: 0x186FA0 SetZBufferUpdate__10PGfxEngineFb10eGsContext
// note: 18 words differ: original selects 0x4E/0x4F with movn and builds flag<<32 before the select; ours uses beqz and computes flag<<32 after it. Tried: unsigned int nData (26), ternary select (22), reordered OR (18), hoisted flag shift (23), int flag (24).
void PGfxEngine::SetZBufferUpdate(bool bEnable, eGsContext eCtx) {
    unsigned long long aGs[2];
    unsigned long long nData = m_unk158E04;
    unsigned char cFlag = !bEnable;
    int nCtx = 0x4E;
    if (eCtx != 0) {
        nCtx = 0x4F;
    }
    aGs[1] = nCtx;
    aGs[0] = ((unsigned long long)cFlag << 32) | (nData | ((unsigned long long)m_unk158E02 << 24));
    m_unk154C80->SetGsRegisters((int *)aGs);
}

// FUNCTION: 0x187880 EnableFullScreenFx__10PGfxEngineFb
void PGfxEngine::EnableFullScreenFx(bool bEnable) {
    ((PGrid *)m_unk16D410)->Enable(bEnable);
    if (bEnable) {
        m_unk16F43C = GAME_FPS * 2.5f;
    } else {
        m_unk16F43C = 0.0f;
    }
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
