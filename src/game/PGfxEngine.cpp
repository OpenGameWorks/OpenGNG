// FLAGS: -str readonly
#include "types.h"

// TODO(header): foreign declarations
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void iFlushCache(int nMode);
extern char vu_clip_microcode_dma_packet[];
extern char vu_shadow_microcode_dma_packet[];
extern char vu_fx_microcode_dma_packet[];
extern char vu_debug_microcode_dma_packet[];
extern char vu_noclip_microcode_dma_packet[];
extern char clip_unlit_spline_patch_init[];
extern char dbg_display_init[];
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern int gCDSVBlankCount[1];
extern float GAME_FPS;
extern float gUnitMatrix[16];
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
    void SetGsRegisters(u_long128 *pRegData, int nNumRegs);
    void SetWorldMatrix(PMat4 *pMat);
    void BeginMesh(unsigned int nFlags);
    void SetTexSyncPacket();

    char _pad000[0xA3348];
    int m_unkA3348;                     // 0xA3348
};

class PGrid {
public:
    void Enable(bool bEnable);
};

class PTextureDmaChain {
public:
    void NextBatch();
};

class PTextureManager {
public:
    void SetTexture(int nIndex, PDisplayList *pDisplayList, struct tagGsTextureEnvironment **ppEnv, bool &bFlag);
};

#include "PGfxEngine.h"

// TODO(header): foreign declarations (GS helpers and globals, placed after the class header for eGsContext)
struct tagGsTextureEnvironment;
void GsInitTexEnv(tagGsTextureEnvironment *pEnv, unsigned int nA, unsigned int nB, unsigned int nC, bool bFlag, eGsContext eCtx);
void GsSetTexBaseAddr(tagGsTextureEnvironment *pEnv, unsigned int nAddr);
unsigned int GsGetBufferWidth(unsigned int nWidth, unsigned int nDepth);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

// FUNCTION: 0x00184640 ComputeDistanceSq__FPfPfPA4_A4_fPA4_A4_fPfPf
void ComputeDistanceSq(float *pA, float *pB, float (*pMatA)[4][4], float (*pMatB)[4][4], float *pSrc, float *pDst)
{
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a2)
        lqc2 vf2, 0x10(a2)
        lqc2 vf3, 0x20(a2)
        lqc2 vf4, 0x30(a2)
        lqc2 vf5, 0x0(a0)
        lqc2 vf7, 0x0(a3)
        lqc2 vf8, 0x10(a3)
        lqc2 vf9, 0x20(a3)
        lqc2 vf10, 0x30(a3)
        lqc2 vf11, 0x0(a1)
        lqc2 vf13, 0x0(t0)
        vmulax.xyzw ACC, vf1, vf5x
        vmadday.xyzw ACC, vf2, vf5y
        vmaddaz.xyzw ACC, vf3, vf5z
        vmaddw.xyzw vf6, vf4, vf0w
        vmulax.xyzw ACC, vf7, vf11x
        vmadday.xyzw ACC, vf8, vf11y
        vmaddaz.xyzw ACC, vf9, vf11z
        vmaddw.xyzw vf12, vf10, vf0w
        vsub.xyzw vf14, vf6, vf13
        vmul.xyz vf15, vf14, vf14
        vaddy.x vf15, vf15, vf15y
        vaddz.x vf31, vf15, vf15z
        vsub.xyzw vf16, vf12, vf13
        vmul.xyz vf17, vf16, vf16
        vaddx.y vf17, vf17, vf17x
        vaddz.y vf31, vf17, vf17z
        vnop
        vnop
        vnop
        sqc2 vf31, 0x0(t1)
        jr ra
        nop
    }
}

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

// FUNCTION: 0x1849A0 BeginSplinePatch__10PGfxEngineFv
void PGfxEngine::BeginSplinePatch() {
    if (m_unk158E1C != &vu_noclip_microcode_dma_packet) {
        m_unk154C80->m_unkA3348 = 1;
        m_unk158E1C = &vu_noclip_microcode_dma_packet;
        m_unk154C80->SetVu1Microcode(m_unk158E1C);
    }
    m_unk154C80->BeginMesh((unsigned int)(clip_unlit_spline_patch_init + 0x1880) >> 3);
}

// FUNCTION: 0x184F40 EndShadowRender__10PGfxEngineFv
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

// FUNCTION: 0x1851B0 DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb
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

// FUNCTION: 0x185460 EndFxRender__10PGfxEngineFv
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

// FUNCTION: 0x185840 BeginSharedMesh__10PGfxEngineF13eBoxIntersectP6PMNode
void PGfxEngine::BeginSharedMesh(eBoxIntersect eBox, PMNode *pNode) {
    m_unk158E24 = 1;
    m_unk16D400 = pNode;
    m_unk154C80->SetWorldMatrix((PMat4 *)gUnitMatrix);
    unsigned char saved = m_unk158E21;
    m_unk158E21 = 0;
    BeginMesh(eBox);
    m_unk158E21 = saved;
}

// FUNCTION: 0x1858E0 UpdateLights__10PGfxEngineFP17tagVuLightingInfo
void PGfxEngine::UpdateLights(struct tagVuLightingInfo *pInfo) {
    if (m_unk158E23 != 0) {
        m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)pInfo, 13);
        return;
    }
    m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)pInfo, 9);
}

// FUNCTION: 0x185940 CopyVuLightingInfo__10PGfxEngineFP17tagVuLightingInfoP17tagVuLightingInfo
void PGfxEngine::CopyVuLightingInfo(struct tagVuLightingInfo *pDst, struct tagVuLightingInfo *pSrc) {
    if (pDst == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x6AC, "pDest");
    }
    if (pSrc == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x6AD, "pSrc");
    }
    memcpy(pDst, pSrc, 0x40);
    memcpy((char *)pDst + 0x40, (char *)pSrc + 0x40, 0x40);
    *(u_long128 *)((char *)pDst + 0x80) = *(u_long128 *)((char *)pSrc + 0x80);
    *(u_long128 *)((char *)pDst + 0x90) = *(u_long128 *)((char *)pSrc + 0x90);
    *(u_long128 *)((char *)pDst + 0xA0) = *(u_long128 *)((char *)pSrc + 0xA0);
    *(u_long128 *)((char *)pDst + 0xB0) = *(u_long128 *)((char *)pSrc + 0xB0);
    *(u_long128 *)((char *)pDst + 0xC0) = *(u_long128 *)((char *)pSrc + 0xC0);
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

// DRAFT: 0x185F60 SetDirLight__10PGfxEngineFiPfPf
// note: 38 diff lines; original keeps this+0x158E30 as lui 0x15/ori base per array and orders index*4 and scale-call pointer differently; tried plain array index, explicit (char*) and (int) casts, unsigned consts, float/int member split, local offset var
void PGfxEngine::SetDirLight(int nIndex, float *pDir, float *pScale) {
    if ((nIndex < 4) && (nIndex >= 0)) {
        *(float *)((int)this + 0x158E30 + nIndex * 4) = -pDir[0];
        *(float *)((int)this + 0x158E40 + nIndex * 4) = -pDir[1];
        *(float *)((int)this + 0x158E50 + nIndex * 4) = -pDir[2];
        *(int *)((int)this + 0x158E60 + nIndex * 4) = 0x3F800000;
        sceVu0ScaleVector((float *)&m_unk158E70[nIndex], pScale, 128.0f);
    }
}

// DRAFT: 0x185EE0 SetDirLightColor__10PGfxEngineFifff
// note: original has 0x80 bytes with this+idx*16 computed before the member constant (folded into store displacements, 128.0f reloaded per store); ours folds the constant first. Tried: swapped range test, local pointer (best, 29 words), pointer+index, operand swap, index-first pointer math.
void PGfxEngine::SetDirLightColor(int nIndex, float fR, float fG, float fB) {
    if (nIndex < 4 && nIndex >= 0) {
        tagDirLightColor *pLight = &m_unk158E70[nIndex];
        pLight->m_fR = 128.0f * fR;
        pLight->m_fG = 128.0f * fG;
        pLight->m_fB = 128.0f * fB;
        pLight->m_nW = 0;
    }
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

// FUNCTION: 0x186F10 BeginMesh__10PGfxEngineF13eBoxIntersect
void PGfxEngine::BeginMesh(eBoxIntersect eBox) {
    unsigned int nOffset = 0;
    m_unk16D328 = (int)eBox;
    void *pMicrocode = ComputeMicrocodeOffset(eBox, nOffset);
    if (pMicrocode != m_unk158E1C) {
        m_unk154C80->SetVu1Microcode(pMicrocode);
        m_unk158E1C = pMicrocode;
    }
    m_unk154C80->BeginMesh(nOffset);
}

// DRAFT: 0x186FA0 SetZBufferUpdate__10PGfxEngineFb10eGsContext
// note: 24 words differ (current form, re-measured): original selects 0x4E/0x4F with movn and builds flag<<32 before the select; ours uses beqz. Tried: unsigned int nData (26), ternary select (22), reordered OR (24), hoisted flag shift (23), int flag (24). An earlier note cited 18 for the reordered OR; re-measuring did not reproduce it.
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
    m_unk154C80->SetGsRegisters((u_long128 *)aGs, 1);
}

// FUNCTION: 0x187020 SetMaterial__10PGfxEngineFiPfbUlUl
void PGfxEngine::SetMaterial(int nIndex, float *pVec, bool bFlag, unsigned long nA, unsigned long nB) {
    unsigned char cSaved = m_unk158F00;
    int nUse = (m_unk16D408 != 0) ? m_unk16D408 : nIndex;
    m_unk158F00 = bFlag;
    SetMaterial(nUse, pVec, nA, nB, 0, 0, 0);
    m_unk158F00 = cSaved;
}

// FUNCTION: 0x1872C0 SetPrevFrameBufferAsTexture__10PGfxEngineFv
void PGfxEngine::SetPrevFrameBufferAsTexture() {
    u_long128 aTexEnv[6];
    unsigned int nSize;

    GsInitTexEnv((tagGsTextureEnvironment *)&aTexEnv[0], 0xA, 8, 1, false, (eGsContext)0);
    *(unsigned long long *)&aTexEnv[3] = ((unsigned long long)GsGetBufferWidth(SCREEN_WIDTH, 1) << 14) | 0x2000000228100000ULL;
    nSize = 0;
    if (m_unk158DF0 != 0) {
        nSize = 0;
    } else {
        nSize = SCREEN_WIDTH * SCREEN_HEIGHT * 4;
    }
    GsSetTexBaseAddr((tagGsTextureEnvironment *)&aTexEnv[0], nSize);
    m_unk154C80->SetGsRegisters(&aTexEnv[1], 5);
}

// DRAFT: 0x187380 SetTexture__10PGfxEngineFi
// note: 35 lines differ. pEnv sits at sp+0x28 (original sp+0x20), and the original's no-op v0/a1 swap after the nIndex compare is not reproduced. Tried: nTex override in a register, with and without the nTex local, combined and nested conditions.
void PGfxEngine::SetTexture(int nIndex) {
    tagGsTextureEnvironment *pEnv;
    bool bFlag;
    int nTex;

    bFlag = false;
    pEnv = 0;
    nTex = nIndex;
    if (m_unk16D408 != 0) {
        if (nIndex != m_unk16D408) {
            nTex = m_unk16D408;
        }
    }
    ((PTextureManager *)m_unk154C90)->SetTexture(nTex, m_unk154C80, &pEnv, bFlag);
    if (bFlag) {
        ((PTextureDmaChain *)((char *)m_unk154C80 + 0xA3380))->NextBatch();
        m_unk154C80->SetTexSyncPacket();
    }
    m_unk154C80->SetGsRegisters((u_long128 *)((char *)pEnv + 0x10), 5);
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
