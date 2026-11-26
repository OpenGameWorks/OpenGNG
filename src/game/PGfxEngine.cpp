// FLAGS: -str readonly
#include "types.h"
#define PGFXENGINE_EMBED_DISPLAYLIST

// TODO(header): foreign declarations
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0MulVector(float *pDst, float *pSrc, float *pW);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void iFlushCache(int nMode);
extern "C" void FlushCache(int nMode);
extern "C" void sceGsSyncPath(int nMode, int nArg);
extern "C" int sceGsSyncV(int nMode);
extern "C" void sceGsSetHalfOffset(void *pBuf, int nW, int nH, unsigned char nFlag);
struct sceGsDBuff;
int GsSwapDBuff(sceGsDBuff *pBuf, int nIdx);
extern "C" void sceGsResetPath();
extern "C" void sceDevVu1Reset();
extern "C" void sceDmaReset(int nMode);
extern "C" void sceDevVif0Reset();
extern "C" void sceDevVif1Reset();
extern "C" void sceDevVu0Reset();
extern "C" void SetupExceptionHandlers__Fv();
extern "C" int AddIntcHandler(int nLine, int (*pHandler)(int), int nArg);
extern "C" void EnableIntc(int nLine);
extern "C" int Init__16PParticleManagerFv(void *pThis);
extern "C" void GsSetFullScreenSprites__FP22tagGsFullScreenSpritesccccbbb(void *pSprites, char cA, char cB, char cC, char cD, bool bA, bool bB, bool bC);
extern "C" int Animate__5PGridFf(void *pThis, float fStep);
extern "C" void sceGsResetGraph(int nA, int nB, short nC, int nD);
void GsClearVRAM(unsigned char nA, unsigned char nB, unsigned char nC, unsigned char nD, short nE, short nF, short nG);
extern char vu_clip_microcode_dma_packet[];
extern char vu_shadow_microcode_dma_packet[];
extern char vu_fx_microcode_dma_packet[];
extern char vu_debug_microcode_dma_packet[];
extern char vu_noclip_microcode_dma_packet[];
extern char vu_noclip_bfc_microcode_dma_packet[];
extern char vu_clip_bfc_microcode_dma_packet[];
extern char noclip_lit_bfc_projection_mesh_init[];
extern char noclip_unlit_bfc_projection_mesh_init[];
extern char noclip_lit_projection_mesh_init[];
extern char noclip_unlit_projection_mesh_init[];
extern char clip_lit_bfc_projection_mesh_init[];
extern char clip_unlit_bfc_projection_mesh_init[];
extern char clip_lit_projection_mesh_init[];
extern char clip_unlit_projection_mesh_init[];
extern char noclip_lit_bfc_projection_cull_mesh_init[];
extern char noclip_unlit_bfc_projection_cull_mesh_init[];
extern char noclip_lit_projection_cull_mesh_init[];
extern char noclip_unlit_projection_cull_mesh_init[];
extern char clip_unlit_spline_patch_init[];
extern char dbg_display_init[];
extern char fx_instance_mesh_init[];
extern char fx_instance_heathaze_init[];
extern char fx_instance_particle_init[];
extern char fx_line_clip_init[];
extern char fx_heathaze_fan_clip_init[];
extern char fx_glow_particle_clip_init[];
extern char fx_fog_particle_clip_init[];
extern char fx_rot_particle_clip_init[];
extern char fx_particle_clip_init[];
extern char fx_sprite_noclip_init[];
extern char fx_instance_screen_st_mesh_init[];
extern char noclip_static_instance_cull_mesh_init[];
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern int gCDSVBlankCount[1];
extern "C" void Kick__16PTextureDmaChainFb(void *pThis, bool bFlag);
void DmaWaitForCompletion(int nArg, bool bFlag);
void GsDumpFrameBuffersAsBmp(int nFrame, int nFlag);
#include "Debug.h"
extern Debug gDebug;
extern float GAME_FPS;
extern float gUnitMatrix[16];
extern char shared_vertices_start[];
extern "C" void sceVu0CopyVector(float *dst, float *src);
void ShellSort(bool (*pCmp)(void *, void *), void **pArray, int nCount);
extern "C" void sceGsSetDefDispEnv(void *, short, short, short, short, short);
extern unsigned char MODE_PAL;
extern "C" void DisableIntc(int nLine);
extern "C" void RemoveIntcHandler(int nLine, int nId);
extern "C" void __destroy_arr(void *pBlock, void *(*pDtor)(void *, short), int nSize, int nCount);
extern "C" void __dl__FPv(void *pMem);
extern "C" void __dt__5PGridFv(void *pThis, short nFlag);
extern "C" void *__dt__5PMat4Fv(void *pThis, short nFlag);
extern "C" void *__dt__Q210PGfxEngine22tagBlendedFragmentInfoFv(void *pThis, short nFlag);
extern "C" void __dt__13PShadowBufferFv(void *pThis, short nFlag);
extern "C" void __dt__16PParticleManagerFv(void *pThis, short nFlag);
extern "C" void __dt__15PTextureManagerFv(void *pThis, short nFlag);
extern "C" void __dt__12PDisplayListFv(void *pThis, short nFlag);
extern "C" void __ct__12PDisplayListFv(void *pThis);
extern "C" void EndMesh__12PDisplayListFv(void *pThis);
extern "C" void __ct__15PTextureManagerFv(void *pThis);
extern "C" void __ct__16PParticleManagerFv(void *pThis);
extern "C" void __ct__13PShadowBufferFv(void *pThis);
extern "C" void __ct__5PGridFv(void *pThis);
extern "C" void *__ct__5PMat4Fv(void *pThis);
extern "C" void *__ct__Q210PGfxEngine22tagBlendedFragmentInfoFv(void *pThis);
extern "C" void __construct_array(void *pBlock, void *(*pCtor)(void *), void *(*pDtor)(void *, short), int nSize, int nCount);
extern "C" int Init__12PDisplayListFv(void *pThis);
extern "C" void sceGsSetDefDBuff(void *pBuf, short nA, short nB, short nC, short nD, short nE, short nF);
extern "C" int Init__15PTextureManagerFiii(void *pThis, int nA, int nB, int nC);
extern "C" int Init__5PGridFffiiPfUiUiUiUi(void *pThis, float fA, float fB, int nA, int nB, float *pAlpha, unsigned int nC, unsigned int nD, unsigned int nE, unsigned int nF);
extern "C" int Create__13PShadowBufferFiiiisf(void *pThis, int nA, int nB, int nC, int nD, short nE, float fA);
extern "C" void InitHeatHazeBuffer__16PParticleManagerFv(void *pThis);
extern "C" void InitExceptionDisplay__Fv();
extern unsigned char g8x16GridAlpha[612];
class PMat4;
class PDisplayList;

class PGrid {
public:
    void Enable(bool bEnable);
    void Render();
};

class PTextureDmaChain {
public:
    void NextBatch();
};

struct tagGsClut256;
struct tagGsTextureEnvironment;

class PTextureManager {
public:
    void SetTexture(int nIndex, PDisplayList *pDisplayList, struct tagGsTextureEnvironment **ppEnv, bool &bFlag);
    void PrepareDynamicClutPacket(struct tagGsClut256 *pClut, struct tagGsTextureEnvironment *pEnv, bool bFlag, PDisplayList *pDisplayList);
    void ResetDynamicBuffers();
};

#include "PGfxEngine.h"

// TODO(header): foreign declarations (global engine pointer, gp-relative)
extern PGfxEngine *gpGfxEngine;

// TODO(header): foreign declarations (GS helpers and globals, placed after the class header for eGsContext)
struct tagGsTextureEnvironment;
void GsInitTexEnv(tagGsTextureEnvironment *pEnv, unsigned int nA, unsigned int nB, unsigned int nC, bool bFlag, eGsContext eCtx);
void GsSetTexBaseAddr(tagGsTextureEnvironment *pEnv, unsigned int nAddr);
unsigned int GsGetBufferWidth(unsigned int nWidth, unsigned int nDepth);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

// TODO(header): foreign declarations (PMeshFragment layout as used here; PMesh.h owns the full class)
class PMNode {
public:
    void AddBoneMatrixToDisplayList(bool bFlag);
};

class PMeshFragment {
public:
    char _pad000[0xC];
    char m_unkC[4];                     // 0x0C, sub-block whose address DrawFragment checks
    int m_unk10;                        // 0x10, flag word (bit 2 and bit 7 read by RenderBlendedFragment)
    unsigned int m_unk14;               // 0x14, element count walked by AddBlendedFragment
    char _pad018[0x4C - 0x18];
    int m_unk4C;                        // 0x4C, fragment type (5 = blended)
    char _pad050[0x64 - 0x50];
    int m_unk64;                        // 0x64, matrix pointer, or 0 / -1 for the slot matrix
    char _pad068[0x70 - 0x68];
    float m_unk70[4];                   // 0x70, vector
    char _pad080[0x90 - 0x80];
    void Render(bool bFlag, int nIdx, bool *pOut);
};

// TODO(header): foreign declarations for PZBufferFog and PParticleManager, which belong to their own headers.
class PZBufferFog {
public:
    void Animate(float fDelta);
    void Render();
    char _pad0000[0x17A8];
    unsigned char m_unk17A8;            // 0x17A8
};

class PParticleManager {
public:
    int Render(ePSLayer eLayer, bool bFlag);
};

// FUNCTION: 0x00184640 ComputeDistanceSq__FPfPfPA4_A4_fPA4_A4_fPfPf
static void ComputeDistanceSq(float *pA, float *pB, float (*pMatA)[4][4], float (*pMatB)[4][4], float *pSrc, float *pDst)
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

// DRAFT: 0x001846D0 ZCompareFragments__FPvPv
// note: 26 words differ: fDist at sp+0x18 (orig sp+0x10); matrix branch order; bc1t vs bc1f on the return compare. Tried: scratch vector, member-array slot bases, hoisted vec loads (53->29), int returns (->26), fDist first (no change), flipped 158F01 test (27), flipped pMat0 test (no change).
int ZCompareFragments(void *pIdx0, void *pIdx1)
{
    float fDist[2];
    char *pSlot0 = gpGfxEngine->m_unk159310 + ((int)pIdx0 << 8);
    char *pSlot1 = gpGfxEngine->m_unk159310 + ((int)pIdx1 << 8);
    PMeshFragment *pFrag0 = *(PMeshFragment **)pSlot0;
    PMeshFragment *pFrag1 = *(PMeshFragment **)pSlot1;
    float *pVec0 = pFrag0->m_unk70;
    float *pVec1 = pFrag1->m_unk70;
    float (*pMat0)[4][4];
    float (*pMat1)[4][4];

    if (pFrag0->m_unk64 != 0 && pFrag0->m_unk64 != -1) {
        pMat0 = (float (*)[4][4])(pFrag0->m_unk64 + 0x40);
    } else {
        pMat0 = (float (*)[4][4])(gpGfxEngine->m_unk169320 + (*(int *)(pSlot0 + 4) << 6));
    }
    if (pFrag1->m_unk64 != 0 && pFrag1->m_unk64 != -1) {
        pMat1 = (float (*)[4][4])(pFrag1->m_unk64 + 0x40);
    } else {
        pMat1 = (float (*)[4][4])(gpGfxEngine->m_unk169320 + (*(int *)(pSlot1 + 4) << 6));
    }
    ComputeDistanceSq(pVec0, pVec1, pMat0, pMat1, gpGfxEngine->m_unk16D330, fDist);
    if (gpGfxEngine->m_unk158F01 != 0) {
        return fDist[0] > fDist[1] ? 1 : 0;
    }
    return fDist[0] <= fDist[1] ? 1 : 0;
}

// DRAFT: 0x184800 VBlankEndInterruptHandler__Fi
// note: 2 words differ: the original places daddu v1,zero,zero before sd ra; ours emits sd ra first. Tried: scalar/array counter, consolidated/split COP0 asm, lui/sync as .word, nop, daddu in its own asm, unused and used zero local (X2: 29 words; X3 asm block with zero local: 5 words), mfpc reads with named local (10 lines, wrong v0/a0 allocation).
static int VBlankEndInterruptHandler(int nIrq) {
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

// DRAFT: 0x184880 Vif1InterruptHandler__Fi
// note: compiler hoists lui v1,0x1000 base across blocks (original reloads lui at per access); 0x3C00 volatile re-read needed; tried all-volatile, 3C30 plain, 3C10 volatile: all 52 words
int Vif1InterruptHandler(int nIrq) {
    if (!(*(unsigned int *)0x10003C00 & 0x800)) {
        *(unsigned int *)0x10003C10 = 8;
        asm {
            sync
            ei
        }
        return 0;
    }
    if (*(volatile unsigned int *)0x10003C00 & 0x40) {
        unsigned int nTag = *(unsigned int *)0x10003C30;
        unsigned int nCount;
        *(unsigned int *)0x10003C30 = 0;
        asm {
            sync
            sync.p
        }
        if (nTag == 0x1000) {
            asm {
                mfc0 nCount, $9
            }
            gpGfxEngine->m_unk158E14 = nCount;
        } else if (nTag == 0x2000) {
            asm {
                mfc0 nCount, $9
            }
            gpGfxEngine->m_unk158E18 = nCount;
        }
    } else {
        char *pBase = (char *)gpGfxEngine;
        if ((char *)gpGfxEngine->m_unk154C80 == pBase) {
            pBase += 0xAA640;
        }
        Kick__16PTextureDmaChainFb(pBase + 0xA3380, true);
    }
    *(unsigned int *)0x10003C10 = 8;
    asm {
        sync
        ei
    }
    return 0;
}

// FUNCTION: 0x184980 DrawSplinePatch__10PGfxEngineFP19tagVuSplinePatchKeyiifb
void PGfxEngine::DrawSplinePatch(struct tagVuSplinePatchKey *pKey, int nA, int nB, float fC, bool bFlag) {
    m_unk154C80->DrawSplinePatch(pKey, nA, nB, fC, bFlag, 0x10);
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

// DRAFT: 0x00184A40 BeginHeatHazeInstances__10PGfxEngineFP13tagVuParticleiffb
// note: frame 0x50 vs 0x60; fA/fB kept in f20/f21 instead of spilled to 0x48/0x4C; tried struct reorder, float locals, address-taken locals; still 80 words
void PGfxEngine::BeginHeatHazeInstances(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag) {
    float fLocalA = fA;
    float fLocalB = fB;
    struct {
        int n;
        float b;
        float a;
        int z;
    } sBuf;

    if (pParticles == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x881, "pParticles");
    }
    if (nCount == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x882, "iNumParticles");
    }
    if (m_unk158E1C != vu_fx_microcode_dma_packet) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x883, "mpvCurVu1CodeBank == FX_MICROCODE_PACKET");
    }
    if (nCount >= 0x15) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x884, "iNumParticles <= fx_i_heathaze_instance_max_vertices");
    }
    sBuf.n = nCount;
    sBuf.z = 0;
    sBuf.a = fLocalA;
    sBuf.b = fLocalB;
    m_unk154C80->WriteToVu1Mem(0x328, (u_long128 *)&sBuf, 1);
    m_unk154C80->AddVifPacket((u_long128 *)pParticles, nCount * 2, 0, ((unsigned int)(nCount << 17)) | 0x6C000329);
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_instance_heathaze_init + 0x35D0)) >> 3);
}

// DRAFT: 0x00184B90 BeginParticleInstances__10PGfxEngineFP13tagVuParticleiffb
// note: frame 0x40 vs 0x60; fA/fB kept in f20/f21 instead of spilled to 0x48/0x4C and reloaded via lw; same 80-word diff as BeginHeatHazeInstances; tried direct fA/fB, local float pair
void PGfxEngine::BeginParticleInstances(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag) {
    struct {
        int n;
        float b;
        float a;
        int z;
    } sBuf;

    if (pParticles == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x869, "pParticles");
    }
    if (nCount == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x86A, "iNumParticles");
    }
    if (m_unk158E1C != vu_fx_microcode_dma_packet) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x86B, "mpvCurVu1CodeBank == FX_MICROCODE_PACKET");
    }
    if (nCount >= 0x29) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x86C, "iNumParticles <= fx_i_particle_instance_max_vertices");
    }
    sBuf.n = nCount;
    sBuf.z = 0;
    sBuf.a = fA;
    sBuf.b = fB;
    m_unk154C80->WriteToVu1Mem(0x288, (u_long128 *)&sBuf, 1);
    m_unk154C80->AddVifPacket((u_long128 *)pParticles, nCount * 2, 0, ((unsigned int)(nCount << 17)) | 0x6C000289);
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_instance_particle_init + 0x2FE0)) >> 3);
}

// FUNCTION: 0x00184CE0 BeginFxInstances__10PGfxEngineFPvib
void PGfxEngine::BeginFxInstances(void *pData, int nSize, bool bFlag) {
    if (pData == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x852, "pvMasterMeshPacket");
    }
    if (nSize == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x853, "iSize");
    }
    if (m_unk158E1C != vu_fx_microcode_dma_packet) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x854, "mpvCurVu1CodeBank == FX_MICROCODE_PACKET");
    }
    m_unk154C80->AddVifPacket((u_long128 *)pData, nSize >> 4, 0x11000000, ((unsigned int)((nSize >> 4) << 16)) | 0x6C000207);
    if (bFlag) {
        m_unk154C80->BeginFxLoop(((unsigned int)(fx_instance_screen_st_mesh_init + 0x26F0)) >> 3);
        return;
    }
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_instance_mesh_init + 0x2B78)) >> 3);
}

// FUNCTION: 0x00184E10 BeginStaticInstances__10PGfxEngineFPvi
void PGfxEngine::BeginStaticInstances(void *pData, int nSize) {
    if (pData == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x83D, "pvMasterMeshPacket");
    }
    if (nSize == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x83E, "iSize");
    }
    m_unk154C80->AddVifPacket((u_long128 *)pData, nSize >> 4, 0x11000000, ((unsigned int)((nSize >> 4) << 16)) | 0x6C000218);
    if (m_unk158E1C != vu_noclip_microcode_dma_packet) {
        m_unk154C80->m_unkA3348 = 1;
        m_unk158E1C = vu_noclip_microcode_dma_packet;
        m_unk154C80->SetVu1Microcode(m_unk158E1C);
    }
    m_unk154C80->BeginMesh(((unsigned int)(noclip_static_instance_cull_mesh_init + 0x2248)) >> 3);
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

// FUNCTION: 0x00185010 RenderParticleSystems__10PGfxEngineF8ePSLayerP11PZBufferFog
int PGfxEngine::RenderParticleSystems(ePSLayer eLayer, PZBufferFog *pFog) {
    int nRet;

    m_unk158E25 = (m_unk16D40C != 0) && (eLayer == ePSLayer_2);
    RenderBlendedFragments(m_unk16D330);
    if (pFog && eLayer == ePSLayer_2 && !pFog->m_unk17A8) {
        pFog->Animate(1.0f);
        pFog->Render();
    }
    BeginFxRender();
    m_unk154C80->SetScreenMatrix((PMat4 *)m_unk16D3C0);
    m_unk154C80->SetViewMatrix((PMat4 *)m_unk16D380);
    m_unk154C80->SetClipMatrix((PMat4 *)m_unk16D340);
    nRet = ((PParticleManager *)((char *)this + 0x154F00))->Render(eLayer, m_unk158E25);
    m_unk158E25 = 0;
    EndFxRender();
    if (pFog && eLayer == ePSLayer_2 && pFog->m_unk17A8) {
        pFog->Animate(1.0f);
        pFog->Render();
    }
    return nRet;
}

// FUNCTION: 0x001851A0 EndFxLines__10PGfxEngineFv
void PGfxEngine::EndFxLines() {
}

// FUNCTION: 0x1851B0 DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb
void PGfxEngine::DrawFxLines(struct tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag) {
    m_unk154C80->DrawParticles((struct tagVuParticle *)pLines, nCount, fB, fA, bFlag, 0x23);
}

// FUNCTION: 0x1851D0 BeginFxLines__10PGfxEngineFv
void PGfxEngine::BeginFxLines() {
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_line_clip_init + 0x23D8)) >> 3);
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

// FUNCTION: 0x00185250 EndHeatHaze__10PGfxEngineFv
void PGfxEngine::EndHeatHaze() {
}

// FUNCTION: 0x185260 DrawHeatHaze__10PGfxEngineFP13tagVuParticleiffb
void PGfxEngine::DrawHeatHaze(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag) {
    m_unk154C80->DrawParticles(pParticles, nCount, fA, fB, bFlag, 0x14);
}

// FUNCTION: 0x185280 BeginHeatHaze__10PGfxEngineFv
void PGfxEngine::BeginHeatHaze() {
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_heathaze_fan_clip_init + 0x1788)) >> 3);
}

// FUNCTION: 0x001852A0 EndVertexGlow__10PGfxEngineFv
void PGfxEngine::EndVertexGlow() {
}

// FUNCTION: 0x1852B0 BeginVertexGlow__10PGfxEngineFv
void PGfxEngine::BeginVertexGlow() {
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_glow_particle_clip_init + 0x1390)) >> 3);
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

// FUNCTION: 0x00185350 EndFogParticles__10PGfxEngineFv
void PGfxEngine::EndFogParticles() {
}

// FUNCTION: 0x00185360 DrawFogParticles__10PGfxEngineFPA4_fifffPf
void PGfxEngine::DrawFogParticles(float (*pVerts)[4], int nCount, float fA, float fB, float fC, float *pColor) {
    m_unk154C80->DrawFogParticles(pVerts, nCount, fA, fB, fC, pColor);
}

// FUNCTION: 0x185370 BeginFogParticles__10PGfxEngineF13eBoxIntersect
void PGfxEngine::BeginFogParticles(eBoxIntersect eBox) {
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_fog_particle_clip_init + 0x1030)) >> 3);
}

// FUNCTION: 0x1853B0 BeginRotatableParticles__10PGfxEngineFv
void PGfxEngine::BeginRotatableParticles() {
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_rot_particle_clip_init + 0xBA8)) >> 3);
}

// FUNCTION: 0x185390 DrawRotatableParticles__10PGfxEngineFP22tagVuRotatableParticleiffb
void PGfxEngine::DrawRotatableParticles(struct tagVuRotatableParticle *pParticles, int nCount, float fA, float fB, bool bFlag) {
    m_unk154C80->DrawRotatableParticles(pParticles, nCount, fA, fB, bFlag, 0x1E);
}

// FUNCTION: 0x001853D0 EndParticles__10PGfxEngineFv
void PGfxEngine::EndParticles() {
}

// FUNCTION: 0x1853E0 DrawParticles__10PGfxEngineFP13tagVuParticleiffb
void PGfxEngine::DrawParticles(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag) {
    m_unk154C80->DrawParticles(pParticles, nCount, fA, fB, bFlag, 0x28);
}

// FUNCTION: 0x185400 BeginParticles__10PGfxEngineF13eBoxIntersect
void PGfxEngine::BeginParticles(eBoxIntersect eBox) {
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_particle_clip_init + 0x418)) >> 3);
}

// FUNCTION: 0x00185420 EndSprites__10PGfxEngineFv
void PGfxEngine::EndSprites() {
}

// FUNCTION: 0x00185430 DrawSprites__10PGfxEngineFP11tagVuSpriteib
void PGfxEngine::DrawSprites(struct tagVuSprite *pSprite, int nCount, bool bFlag) {
    m_unk154C80->DrawSprites(pSprite, nCount, bFlag);
}

// FUNCTION: 0x185440 BeginSprites__10PGfxEngineFv
void PGfxEngine::BeginSprites() {
    m_unk154C80->BeginFxLoop(((unsigned int)(fx_sprite_noclip_init + 0x150)) >> 3);
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

// FUNCTION: 0x00185530 EndDebugRender__10PGfxEngineFv
void PGfxEngine::EndDebugRender() {
}

// DRAFT: 0x185540 DrawBox__10PGfxEngineFPA2_A4_ffff
// note: 27 words; loop register allocation differs (counter/pointer in a0/a1 vs offset in a2, base not hoisted); index, char-base and pointer-walk loop forms tried
void PGfxEngine::DrawBox(float (*pBox)[2][4], float arg1, float arg2, float arg3) {
    if (pBox == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x6EF, "pBox");
    }
    float Xd = pBox[0][0][0] - pBox[0][1][0];
    float Yd = pBox[0][0][1] - pBox[0][1][1];
    float Zd = pBox[0][0][2] - pBox[0][1][2];
    float Xs = pBox[0][0][0] + pBox[0][1][0];
    float Ys = pBox[0][0][1] + pBox[0][1][1];
    float Zs = pBox[0][0][2] + pBox[0][1][2];
    float lines[12][4][4];

    lines[0][0][0] = Xd; lines[0][0][1] = Yd; lines[0][0][2] = Zd; lines[0][0][3] = 1.0f;
    lines[0][1][0] = Xd; lines[0][1][1] = Ys; lines[0][1][2] = Zd; lines[0][1][3] = 1.0f;
    lines[1][0][0] = Xd; lines[1][0][1] = Ys; lines[1][0][2] = Zd; lines[1][0][3] = 1.0f;
    lines[1][1][0] = Xs; lines[1][1][1] = Ys; lines[1][1][2] = Zd; lines[1][1][3] = 1.0f;
    lines[2][0][0] = Xs; lines[2][0][1] = Ys; lines[2][0][2] = Zd; lines[2][0][3] = 1.0f;
    lines[2][1][0] = Xs; lines[2][1][1] = Yd; lines[2][1][2] = Zd; lines[2][1][3] = 1.0f;
    lines[3][0][0] = Xs; lines[3][0][1] = Yd; lines[3][0][2] = Zd; lines[3][0][3] = 1.0f;
    lines[3][1][0] = Xd; lines[3][1][1] = Yd; lines[3][1][2] = Zd; lines[3][1][3] = 1.0f;
    lines[4][0][0] = Xd; lines[4][0][1] = Yd; lines[4][0][2] = Zs; lines[4][0][3] = 1.0f;
    lines[4][1][0] = Xd; lines[4][1][1] = Ys; lines[4][1][2] = Zs; lines[4][1][3] = 1.0f;
    lines[5][0][0] = Xd; lines[5][0][1] = Ys; lines[5][0][2] = Zs; lines[5][0][3] = 1.0f;
    lines[5][1][0] = Xs; lines[5][1][1] = Ys; lines[5][1][2] = Zs; lines[5][1][3] = 1.0f;
    lines[6][0][0] = Xs; lines[6][0][1] = Ys; lines[6][0][2] = Zs; lines[6][0][3] = 1.0f;
    lines[6][1][0] = Xs; lines[6][1][1] = Yd; lines[6][1][2] = Zs; lines[6][1][3] = 1.0f;
    lines[7][0][0] = Xs; lines[7][0][1] = Yd; lines[7][0][2] = Zs; lines[7][0][3] = 1.0f;
    lines[7][1][0] = Xd; lines[7][1][1] = Yd; lines[7][1][2] = Zs; lines[7][1][3] = 1.0f;
    lines[8][0][0] = Xd; lines[8][0][1] = Yd; lines[8][0][2] = Zd; lines[8][0][3] = 1.0f;
    lines[8][1][0] = Xd; lines[8][1][1] = Yd; lines[8][1][2] = Zs; lines[8][1][3] = 1.0f;
    lines[9][0][0] = Xd; lines[9][0][1] = Ys; lines[9][0][2] = Zd; lines[9][0][3] = 1.0f;
    lines[9][1][0] = Xd; lines[9][1][1] = Ys; lines[9][1][2] = Zs; lines[9][1][3] = 1.0f;
    lines[10][0][0] = Xs; lines[10][0][1] = Yd; lines[10][0][2] = Zd; lines[10][0][3] = 1.0f;
    lines[10][1][0] = Xs; lines[10][1][1] = Yd; lines[10][1][2] = Zs; lines[10][1][3] = 1.0f;
    lines[11][0][0] = Xs; lines[11][0][1] = Ys; lines[11][0][2] = Zd; lines[11][0][3] = 1.0f;
    lines[11][1][0] = Xs; lines[11][1][1] = Ys; lines[11][1][2] = Zs; lines[11][1][3] = 1.0f;

    int i = 0;
    float (*row)[4][4] = lines;
    for (; i < 12; i++, row++) {
        (*row)[2][0] = arg1;
        (*row)[2][1] = arg2;
        (*row)[2][2] = arg3;
        (*row)[2][3] = 128.0f;
        (*row)[3][0] = arg1;
        (*row)[3][1] = arg2;
        (*row)[3][2] = arg3;
        (*row)[3][3] = 128.0f;
    }
    DrawLines((struct tagVuLine *)lines, 12);
}

// FUNCTION: 0x001857B0 DrawLines__10PGfxEngineFP9tagVuLinei
void PGfxEngine::DrawLines(struct tagVuLine *pLines, int nCount) {
    m_unk154C80->DrawLines(pLines, nCount);
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

// FUNCTION: 0x1859F0 GetLightingInfo__10PGfxEngineFP5PMat4P5PMat4PA4_f
void PGfxEngine::GetLightingInfo(PMat4 *pA, PMat4 *pB, float (*pOut)[4]) {
    if (pA == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x6A0, "pLightDirMat");
    }
    if (pB == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x6A1, "pLightColorMat");
    }
    if (pOut == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x6A2, "pAmbientLight");
    }
    memcpy(pA, m_unk158E30, 0x40);
    memcpy(pB, m_unk158E70, 0x40);
    *(u_long128 *)pOut = *(u_long128 *)m_unk158EB0;
}

// FUNCTION: 0x185AD0 ResetVuLightingInfo__10PGfxEngineFv
void PGfxEngine::ResetVuLightingInfo() {
    m_unk158EC0[2] = 0;
    m_unk158EC0[1] = 0;
    m_unk158EC0[0] = 0;
    m_unk158EC0[3] = 0x3F800000;
    m_unk158EC0[10] = 0;
    m_unk158EC0[9] = 0;
    m_unk158EC0[8] = 0;
    m_unk158EC0[11] = 0x3F800000;
    m_unk158EC0[6] = 0;
    m_unk158EC0[5] = 0;
    m_unk158EC0[4] = 0;
    m_unk158EC0[7] = 0x3F800000;
    m_unk158EC0[14] = 0;
    m_unk158EC0[13] = 0;
    m_unk158EC0[12] = 0;
    m_unk158EC0[15] = 0x3F800000;
    memset((char *)this + 0x158E30, 0, 0x40);
    memset((char *)this + 0x158E70, 0, 0x40);
    SetFullAmbientLight();
}

// FUNCTION: 0x185BF0 UpdateLights__10PGfxEngineFP5PMat4P5PMat4PA4_f
void PGfxEngine::UpdateLights(PMat4 *pDirMat, PMat4 *pColorMat, float (*pAmbient)[4]) {
    if (pDirMat == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x684, "pLightDirMat");
    }
    if (pColorMat == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x685, "pLightColorMat");
    }
    if (pAmbient == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x686, "pAmbientLight");
    }
    memcpy(m_unk158E30, pDirMat, 0x40);
    memcpy(m_unk158E70, pColorMat, 0x40);
    *(u_long128 *)m_unk158EB0 = *(u_long128 *)pAmbient;
    m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)m_unk158E30, 9);
}

// FUNCTION: 0x185CF0 UpdateLights__10PGfxEngineFv
void PGfxEngine::UpdateLights() {
    if (m_unk158E23 != 0) {
        m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)m_unk158E30, 13);
        return;
    }
    m_unk154C80->WriteToVu1Mem(0x35E, (u_long128 *)m_unk158E30, 9);
}

// FUNCTION: 0x185D70 ModulateAllLights__10PGfxEngineFPf
void PGfxEngine::ModulateAllLights(float *pVec) {
    sceVu0MulVector((float *)&m_unk158E70[0], (float *)&m_unk158E70[0], pVec);
    sceVu0MulVector((float *)&m_unk158E70[1], (float *)&m_unk158E70[1], pVec);
    sceVu0MulVector((float *)&m_unk158E70[2], (float *)&m_unk158E70[2], pVec);
    sceVu0MulVector((float *)&m_unk158E70[3], (float *)&m_unk158E70[3], pVec);
    sceVu0MulVector(m_unk158EB0, m_unk158EB0, pVec);
    sceVu0MulVector((float *)((char *)this + 0x158ED0), (float *)((char *)this + 0x158ED0), pVec);
    sceVu0MulVector((float *)((char *)this + 0x158EF0), (float *)((char *)this + 0x158EF0), pVec);
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

// FUNCTION: 0x186020 RenderRefractionMappedFragments__10PGfxEngineFv
void PGfxEngine::RenderRefractionMappedFragments() {
    if (m_unk16D40C != 0 && m_unk169310 != 0) {
        m_unk154C80->m_unkA3348 = 1;
        m_unk154C80->SetScreenMatrix((PMat4 *)m_unk16D3C0);
        m_unk154C80->SetViewMatrix((PMat4 *)m_unk16D380);
        m_unk154C80->SetClipMatrix((PMat4 *)m_unk16D340);
        m_unk158F00 = 1;
        m_unk158E20 = true;
        SetZBufferUpdate(true, (eGsContext)0);
        unsigned char nSavedF0 = m_unk158E22;
        for (int i = 0; i < m_unk169310; i++) {
            tagBlendedFragmentInfo *pInfo = (tagBlendedFragmentInfo *)(m_unk159310 + (*(int *)(m_unk158F04 + i * 4) << 8));
            if (pInfo->m_unkF1 != 0) {
                RenderBlendedFragment(pInfo);
            }
        }
        ResetBlendedFragmentTable();
        m_unk158E24 = 0;
        m_unk16D400 = 0;
        m_unk158F00 = 0;
        m_unk158E20 = false;
        m_unk158E22 = nSavedF0;
        SetZBufferUpdate(false, (eGsContext)0);
        BeginFxRender();
        m_unk154C80->SetScreenMatrix((PMat4 *)m_unk16D3C0);
        m_unk154C80->SetViewMatrix((PMat4 *)m_unk16D380);
        m_unk154C80->SetClipMatrix((PMat4 *)m_unk16D340);
    }
}

// FUNCTION: 0x186240 RenderBlendedFragment__10PGfxEngineFPQ210PGfxEngine22tagBlendedFragmentInfo
void PGfxEngine::RenderBlendedFragment(tagBlendedFragmentInfo *pInfo) {
    m_unk158E22 = pInfo->m_unkF0;
    PMeshFragment *pFrag = pInfo->m_unk0;
    m_unk158E20 = (pFrag->m_unk10 & 4) != 0;
    SetZBufferUpdate((pFrag->m_unk10 & 0x80) != 0, (eGsContext)0);
    if (pInfo->m_unk10 != 0) {
        m_unk154C80->BeginMatrixList();
        pInfo->m_unk10->AddBoneMatrixToDisplayList(true);
        m_unk154C80->EndMatrixList();
        if (pInfo->m_unkF0 != 0) {
            UpdateLights((tagVuLightingInfo *)pInfo->m_unk20);
        }
        BeginSharedMesh((eBoxIntersect)pInfo->m_unk8, m_unk16D400);
        if (pInfo->m_unkF2 != 0) {
            pInfo->m_unk0->Render(true, pInfo->m_unkC, &pInfo->m_unkF3);
        } else {
            pInfo->m_unk0->Render(true, pInfo->m_unkC, 0);
        }
        m_unk158E24 = 0;
        m_unk16D400 = 0;
        return;
    }
    m_unk154C80->SetWorldMatrix((PMat4 *)(m_unk169320 + (pInfo->m_unk4 << 6)));
    if (pInfo->m_unkF0 != 0) {
        UpdateLights((tagVuLightingInfo *)pInfo->m_unk20);
    }
    BeginMesh((eBoxIntersect)pInfo->m_unk8);
    if (pInfo->m_unkF2 != 0) {
        pInfo->m_unk0->Render(true, pInfo->m_unkC, &pInfo->m_unkF3);
    } else {
        pInfo->m_unk0->Render(true, pInfo->m_unkC, 0);
    }
    EndMesh__12PDisplayListFv(m_unk154C80);
}

// DRAFT: 0x186410 RenderBlendedFragments__10PGfxEngineFPf
// note: 45 words differ; loop 1 loads F1 before m_unk0 (original loads m_unk0 first), a1 setup order differs. Tried: pFrag hoist (102-103 words), +0xC word-index form, nested if.
void PGfxEngine::RenderBlendedFragments(float *pVec) {
    sceVu0CopyVector(m_unk16D330, pVec);
    if (m_unk169310 != 0) {
        m_unk158F00 = 1;
        unsigned char nSavedF0 = m_unk158E22;
        ShellSort((bool (*)(void *, void *))ZCompareFragments, (void **)m_unk158F04, m_unk169310);
        for (int i = 0; i < m_unk169310; i++) {
            tagBlendedFragmentInfo *pInfo = (tagBlendedFragmentInfo *)(m_unk159310 + (((int *)m_unk158F04)[i] << 8));
            if (!pInfo->m_unkF1 && (pInfo->m_unk0->m_unk10 & 8) == 0) {
                RenderBlendedFragment(pInfo);
            }
        }
        for (int i = 0; i < m_unk169310; i++) {
            tagBlendedFragmentInfo *pInfo = (tagBlendedFragmentInfo *)(m_unk159310 + (((int *)m_unk158F04)[i] << 8));
            if (!pInfo->m_unkF1 && (pInfo->m_unk0->m_unk10 & 8) != 0) {
                RenderBlendedFragment(pInfo);
            }
        }
        if (!m_unk158E25) {
            ResetBlendedFragmentTable();
        }
        m_unk158F00 = 0;
        m_unk158E20 = false;
        m_unk158E22 = nSavedF0;
        SetZBufferUpdate(true, (eGsContext)0);
    }
}

// DRAFT: 0x1865F0 AddBlendedFragment__10PGfxEngineFP13PMeshFragmentiPbb
// note: DIFF 27 vs original; original is 0x1BC bytes (ours 0x1AC), tail table address is (this+0x158F04)+idx*4 via lui 0x15 + addu and it reloads m_unk169310 and m_unk16D324 with fresh lui 0x17; return-0 branch targets 0x4A (ours 0x46). Tried: direct member index (DIFF 30), pointer local with m_unk169310 index (30), re-read counter with nIndex store (30), pointer local with nIndex index (30), pOut loop via pDst pointer (50), hoisted loop bound (51).
int PGfxEngine::AddBlendedFragment(PMeshFragment *pFrag, int nIdx, bool *pOut, bool bFlag) {
    if (pFrag == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x515, "pFragment");
    }
    int nCount = m_unk169310;
    if (nCount >= 0x100) {
        return 0;
    }
    tagBlendedFragmentInfo *pInfo = (tagBlendedFragmentInfo *)(m_unk159310 + (nCount << 8));
    pInfo->m_unk0 = pFrag;
    pInfo->m_unk8 = m_unk16D328;
    pInfo->m_unk4 = m_unk16D320;
    pInfo->m_unkC = nIdx;
    pInfo->m_unk10 = m_unk16D400;
    pInfo->m_unkF0 = m_unk158E22;
    pInfo->m_unkF1 = bFlag;
    pInfo->m_unkF2 = 0;
    if (pInfo->m_unkF0 != 0) {
        CopyVuLightingInfo((tagVuLightingInfo *)pInfo->m_unk20, (tagVuLightingInfo *)m_unk158E30);
    }
    if (pOut != 0) {
        for (unsigned int i = 0; i < pFrag->m_unk14; i++) {
            (&pInfo->m_unkF3)[i] = pOut[i];
            if (pOut[i] == 0) {
                pInfo->m_unkF2 = 1;
            }
        }
    }
    int nIndex = m_unk169310;
    *(int *)&m_unk158F04[nIndex * 4] = nIndex;
    m_unk169310 = nIndex + 1;
    m_unk16D324 += 1;
    return 1;
}

// FUNCTION: 0x1867B0 ResetBlendedFragmentTable__10PGfxEngineFv
void PGfxEngine::ResetBlendedFragmentTable() {
    int i;
    int nOff;

    memset((char *)this + 0x158F04, 0, 0x400);
    memset((char *)this + 0x159310, 0, 0x10000);
    m_unk169310 = 0;
    m_unk16D320 = 0;
    m_unk16D324 = 0;
    m_unk16D40C = 0;
    i = 0;
    nOff = 0;
    do {
        sceVu0UnitMatrix((char *)this + nOff + 0x169320);
        i++;
        nOff += 0x40;
    } while (i < 256);
    m_unk16D328 = 4;
    m_unk16D400 = 0;
}

// DRAFT: 0x00186890 DrawFragment__10PGfxEngineFP13PMeshFragmentbiPb
// note: 37 words differ; frame is 0x70 with s0..s5 vs original 0x60 with s0..s4, and m_unk4C loads fold onto a saved pFrag+0xC. Tried: array/int m_unkC, &-address check, early and late m_unk4C local (37 best, 78 otherwise).
void PGfxEngine::DrawFragment(PMeshFragment *pFrag, bool bFlag, int nIdx, bool *pOut) {
    if (pFrag == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x4E6, "pFragment");
    }
    int nType = pFrag->m_unk4C;
    if (pFrag->m_unkC == 0) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x4E9, "apShader");
    }
    if (nType == 5 && m_unk16D408 == 0) {
        if (AddBlendedFragment(pFrag, nIdx, pOut, true) != 0) {
            m_unk16D40C++;
        }
    } else {
        if (bFlag) {
            if (m_unk16D408 == 0) {
                AddBlendedFragment(pFrag, nIdx, pOut, false);
                return;
            }
        }
        pFrag->Render(false, nIdx, pOut);
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

// FUNCTION: 0x186B20 SetWorldMatrix__10PGfxEngineFP5PMat4
void PGfxEngine::SetWorldMatrix(PMat4 *pMat) {
    u_long128 *pDst;
    u_long128 *pSrc;

    m_unk154C80->SetWorldMatrix(pMat);
    if (m_unk16D324 > 0) {
        m_unk16D320 += 1;
        m_unk16D324 = 0;
    }
    if (m_unk16D320 >= 0x100) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0x4A9, "miCurWorldMatrixIndex < MAX_BLENDED_FRAGMENTS");
    }
    pDst = (u_long128 *)(m_unk169320 + (m_unk16D320 << 6));
    pSrc = (u_long128 *)pMat;
    pDst[0] = pSrc[0];
    pDst[1] = pSrc[1];
    pDst[2] = pSrc[2];
    pDst[3] = pSrc[3];
}

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PGfxEngine.cpp", line, #cond))

// DRAFT: 0x186C10 ComputeMicrocodeOffset__10PGfxEngineF13eBoxIntersectRUi
// note: 141 words differ; case 1 early return keeps nSel in v0 (original keeps it in s1 and tail-merges sw into the delay slot of a b to the return move); variants tried: case 3 before case 2, early return in case 1.
void *PGfxEngine::ComputeMicrocodeOffset(eBoxIntersect eBox, unsigned int &nOffset) {
    void *pBase;
    unsigned int nSel = 0;

    switch ((int)eBox) {
    case 1:
        if (m_unk158E20) {
            pBase = vu_noclip_bfc_microcode_dma_packet;
            if (m_unk158E22) {
                nSel = (unsigned int)(noclip_lit_bfc_projection_mesh_init + 0xB78) >> 3;
            } else {
                nSel = (unsigned int)(noclip_unlit_bfc_projection_mesh_init + 0x1A8) >> 3;
            }
        } else {
            pBase = vu_noclip_microcode_dma_packet;
            if (m_unk158E22) {
                nSel = (unsigned int)(noclip_lit_projection_mesh_init + 0xBC8) >> 3;
            } else {
                nSel = (unsigned int)(noclip_unlit_projection_mesh_init + 0x1A8) >> 3;
            }
        }
        nOffset = nSel;
        return pBase;
    case 4:
        if (m_unk158E20) {
            if (m_unk158E21) {
                pBase = vu_clip_bfc_microcode_dma_packet;
                if (m_unk158E22) {
                    nSel = (unsigned int)(clip_lit_bfc_projection_mesh_init + 0x5E0) >> 3;
                } else {
                    nSel = (unsigned int)(clip_unlit_bfc_projection_mesh_init + 0x1A8) >> 3;
                }
            } else {
                pBase = vu_noclip_bfc_microcode_dma_packet;
                if (m_unk158E22) {
                    nSel = (unsigned int)(noclip_lit_bfc_projection_cull_mesh_init + 0x1398) >> 3;
                } else {
                    nSel = (unsigned int)(noclip_unlit_bfc_projection_cull_mesh_init + 0x670) >> 3;
                }
            }
        } else if (m_unk158E21) {
            pBase = vu_clip_microcode_dma_packet;
            if (m_unk158E22) {
                nSel = (unsigned int)(clip_lit_projection_mesh_init + 0x5A0) >> 3;
            } else {
                nSel = (unsigned int)(clip_unlit_projection_mesh_init + 0x1A8) >> 3;
            }
        } else {
            pBase = vu_noclip_microcode_dma_packet;
            if (m_unk158E22) {
                nSel = (unsigned int)(noclip_lit_projection_cull_mesh_init + 0x11E8) >> 3;
            } else {
                nSel = (unsigned int)(noclip_unlit_projection_cull_mesh_init + 0x688) >> 3;
            }
        }
        break;
    case 3:
    case 2:
        if (m_unk158E20) {
            pBase = vu_noclip_bfc_microcode_dma_packet;
            if (m_unk158E22) {
                nSel = (unsigned int)(noclip_lit_bfc_projection_cull_mesh_init + 0x1398) >> 3;
            } else {
                nSel = (unsigned int)(noclip_unlit_bfc_projection_cull_mesh_init + 0x670) >> 3;
            }
        } else {
            pBase = vu_noclip_microcode_dma_packet;
            if (m_unk158E22) {
                nSel = (unsigned int)(noclip_lit_projection_cull_mesh_init + 0x11E8) >> 3;
            } else {
                nSel = (unsigned int)(noclip_unlit_projection_cull_mesh_init + 0x688) >> 3;
            }
        }
        break;
    case 0:
        CDS_ASSERT(0x485, !"Begin mesh called with Box Outside!");
        break;
    default:
        CDS_ASSERT(0x489, !"Begin mesh called with unknown clip type!");
        break;
    }

    nOffset = nSel;
    return pBase;
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
// note: 16 words differ (current form, v2): original selects 0x4E/0x4F with movn after building flag<<32; ours uses beqz and different t-register numbers. Tried: unsigned int nData (26), ternary select (22), reordered OR (24), hoisted flag shift (23), int flag (24), inverted ternary with original OR order (21), if-select form (17).
void PGfxEngine::SetZBufferUpdate(bool bEnable, eGsContext eCtx) {
    unsigned long long aGs[2];
    unsigned long long nData = m_unk158E04;
    unsigned char cFlag = !bEnable;
    int nCtx = (eCtx == 0) ? 0x4E : 0x4F;
    unsigned long long nFlag = (unsigned long long)cFlag << 32;
    aGs[1] = nCtx;
    aGs[0] = (nData | ((unsigned long long)m_unk158E02 << 24)) | nFlag;
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

// DRAFT: 0x1870B0 SetMaterial__10PGfxEngineFPfbUlUl
// note: 32 words differ; the ternary/if shift term joins at the wrong point and the bool argument for SetMaterials gets an sltu and a single load of m_unk158E24 where the original reloads the raw byte. Tried ternary, explicit if, pointer-index copy, and (char*)this offsets.
void PGfxEngine::SetMaterial(float *pVec, bool bFlag, unsigned long nA, unsigned long nB) {
    u_long128 aMat[10];
    u_long128 *pQ = &aMat[1];

    pQ[0] = *(u_long128 *)(m_unk158B00 + 0x60);
    pQ[1] = *(u_long128 *)(m_unk158B00 + 0x70);
    pQ[2] = *(u_long128 *)(m_unk158B00 + 0x80);
    pQ[3] = *(u_long128 *)(m_unk158B00 + 0x90);
    pQ[4] = *(u_long128 *)(m_unk158B00 + 0xA0);
    *(unsigned long *)((char *)aMat + 0x20) = nA;
    *(unsigned long *)((char *)aMat + 0x30) = nB;
    *(unsigned long *)((char *)aMat + 0x50) = (((unsigned long)(unsigned char)bFlag) << 6) | 0x18;
    *(char **)((char *)aMat + 0x4) = m_unk158B00;
    *(unsigned int *)((char *)aMat + 0x90) = 0;
    *(u_long128 *)((char *)aMat + 0x70) = 0;
    *(u_long128 *)((char *)aMat + 0x80) = 0;
    unsigned int nShift = 0;
    if (m_unk158E24) {
        nShift = (unsigned int)(shared_vertices_start + 0x2C10) >> 3;
    }
    *(unsigned int *)((char *)aMat + 0x74) = nShift;
    sceVu0CopyVector((float *)((char *)aMat + 0x60), pVec);
    m_unk154C80->SetMaterials((struct tagGsMaterial *)aMat, 1, false, m_unk158E24, 0, 0, 0);
}

// FUNCTION: 0x1871C0 SetCurFrameBufferAs8BitTexture__10PGfxEngineFP12tagGsClut256
void PGfxEngine::SetCurFrameBufferAs8BitTexture(struct tagGsClut256 *pClut) {
    u_long128 aTexEnv[6];
    unsigned int nWidth;
    unsigned long long nTag;

    GsInitTexEnv((tagGsTextureEnvironment *)&aTexEnv[0], 0xA, 8, 0x1B, false, (eGsContext)0);
    nWidth = GsGetBufferWidth(SCREEN_WIDTH, 0);
    *(unsigned long long *)&aTexEnv[2] = 0;
    nTag = 0x20000006ULL;
    *(unsigned long long *)&aTexEnv[3] = ((unsigned long long)nWidth << 14) | ((nTag << 32) | 0x29B00000ULL);
    GsSetTexBaseAddr((tagGsTextureEnvironment *)&aTexEnv[0], m_unk158DF0);
    ((PTextureManager *)m_unk154C90)->PrepareDynamicClutPacket(pClut, (tagGsTextureEnvironment *)&aTexEnv[0], false, m_unk154C80);
    m_unk154C80->SendGsPacket(pClut, 0x460, true);
    m_unk154C80->SetGsRegisters(&aTexEnv[1], 5);
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

// FUNCTION: 0x187380 SetTexture__10PGfxEngineFi
void PGfxEngine::SetTexture(int nIndex) {
    // The original places pEnv on a 16-byte boundary (sp+0x20, bFlag at sp+0x2F).
    tagGsTextureEnvironment *pEnv __attribute__((aligned(16)));
    bool bFlag;
    int nTex;

    bFlag = false;
    pEnv = 0;
    nTex = m_unk16D408;
    if (nTex == 0 || nIndex != nTex) {
        nTex = nIndex;
    }
    ((PTextureManager *)m_unk154C90)->SetTexture(nTex, m_unk154C80, &pEnv, bFlag);
    if (bFlag) {
        ((PTextureDmaChain *)((char *)m_unk154C80 + 0xA3380))->NextBatch();
        m_unk154C80->SetTexSyncPacket();
    }
    m_unk154C80->SetGsRegisters((u_long128 *)((char *)pEnv + 0x10), 5);
}

// DRAFT: 0x00187450 SetMaterial__10PGfxEngineFiPfUlUlPUiPUiPA4_A4_f
// note: DIFF 98 words, size 0x1D4 vs 0x1C8; first copy uses -0x74A0(at) not 0(v1), nA/nB stores go through a2/t2 not sp+0x80/0x90; a local base pointer did not change the count.
void PGfxEngine::SetMaterial(int nIndex, float *pVec, unsigned long nA, unsigned long nB, unsigned int *pC, unsigned int *pD, float (*pMat)[4][4]) {
    struct {
        char _pad00[4];                 // 0x60
        tagGsTextureEnvironment *pEnv;  // 0x64, ppEnv output of SetTexture
        char _pad68[0x70 - 0x68];
        char aBlock[0x50];              // 0x70, copy of this+0x158B60; nA, nB and flags overwrite its low doublewords
        float aVec[4];                  // 0xC0
        unsigned int aC[4];             // 0xD0
        unsigned int aD[4];             // 0xE0
        float (*pMatField)[4][4];       // 0xF0
        char _padF4[0x10F - 0xF4];
        bool bFlag;                     // 0x10F
    } aBuf;
    int nIdx;

    *(u_long128 *)(aBuf.aBlock + 0x00) = *(u_long128 *)((char *)this + 0x158B60);
    *(u_long128 *)(aBuf.aBlock + 0x10) = *(u_long128 *)((char *)this + 0x160000 - 0x7490);
    *(u_long128 *)(aBuf.aBlock + 0x20) = *(u_long128 *)((char *)this + 0x160000 - 0x7480);
    *(u_long128 *)(aBuf.aBlock + 0x30) = *(u_long128 *)((char *)this + 0x160000 - 0x7470);
    *(u_long128 *)(aBuf.aBlock + 0x40) = *(u_long128 *)((char *)this + 0x160000 - 0x7460);
    *(unsigned long long *)(aBuf.aBlock + 0x10) = nA;
    *(unsigned long long *)(aBuf.aBlock + 0x20) = nB;
    *(unsigned long long *)(aBuf.aBlock + 0x40) = (m_unk158F00 << 6) | ((nIndex != 0) << 4) | 8;
    if (pC != 0) {
        memcpy(aBuf.aC, pC, 0x10);
    } else {
        *(u_long128 *)aBuf.aC = 0;
    }
    if (pD != 0) {
        memcpy(aBuf.aD, pD, 0x10);
    } else {
        *(u_long128 *)aBuf.aD = 0;
    }
    {
        unsigned int nDma = 0;
        if (m_unk158E24 != 0) {
            nDma = ((unsigned int)shared_vertices_start + 0x2C10) >> 3;
        }
        aBuf.aC[1] = nDma;
    }
    aBuf.pMatField = pMat;
    sceVu0CopyVector(aBuf.aVec, pVec);
    nIdx = m_unk16D408;
    if (nIdx == 0) {
        nIdx = nIndex;
    }
    ((PTextureManager *)m_unk154C90)->SetTexture(nIdx, m_unk154C80, &aBuf.pEnv, aBuf.bFlag);
    m_unk154C80->SetMaterials((struct tagGsMaterial *)&aBuf, 1, aBuf.bFlag, m_unk158E24, 0, 0, 0);
}

// FUNCTION: 0x187620 SetOverrideTexture__10PGfxEngineFi
void PGfxEngine::SetOverrideTexture(int nIndex) {
    bool bFlag;
    tagGsTextureEnvironment *pEnv __attribute__((aligned(16)));

    m_unk16D408 = nIndex;
    if (m_unk16D408 != 0) {
        bFlag = false;
        pEnv = 0;
        ((PTextureManager *)m_unk154C90)->SetTexture(m_unk16D408, m_unk154C80, &pEnv, bFlag);
        if (bFlag) {
            ((PTextureDmaChain *)((char *)m_unk154C80 + 0xA3380))->NextBatch();
            m_unk154C80->SetTexSyncPacket();
        }
        m_unk154C80->SetGsRegisters((u_long128 *)((char *)pEnv + 0x10), 5);
    }
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

// DRAFT: 0x1878F0 RenderFullScreenMotionBlur__10PGfxEngineFf
// note: 132 words differ; size 0x2A0 vs 0x2C0. Sprite-buffer/GS packet stack layout (sp+0x30..0x6D0), rate-byte register (a0 vs v0), and nSum in v1 not matched. Tried: goto vs ternary reset test (152/157), local order, sum operand order (all 132 or worse).
void PGfxEngine::RenderFullScreenMotionBlur(float fParam) {
    unsigned long long aRegs1[6];
    unsigned long long aRegs2[6];
    char aSprites[0x680];
    if (m_unk16D406 <= 0 || m_unk16D404 < m_unk16D405) {
        if (m_unk16D406 < 0) {
            if (m_unk16D405 >= m_unk16D404) {
                goto reset_fade;
            }
        }
    } else {
    reset_fade:
        m_unk16D406 = 0;
        m_unk16D404 = m_unk16D405;
    }
    int nSum = m_unk16D404 + m_unk16D406;
    m_unk16D404 = (nSum > 0) ? ((nSum < 0x80) ? nSum : 0x80) : 0;
    if (m_unk16D404 != 0) {
        GsSetFullScreenSprites__FP22tagGsFullScreenSpritesccccbbb(aSprites, -0x80, -0x80, -0x80, m_unk16D404, true, true, false);
        SetPrevFrameBufferAsTexture();
        aRegs1[0] = 0x44;
        aRegs1[1] = 0x42;
        aRegs1[2] = 0x30000;
        aRegs1[3] = 0x47;
        aRegs1[4] = 5;
        aRegs1[5] = 8;
        m_unk154C80->SetGsRegisters((u_long128 *)aRegs1, 3);
        m_unk154C80->SendGsPacket(aSprites, 0x680, true);
        aRegs1[0] = 0;
        aRegs1[1] = 8;
        m_unk154C80->SetGsRegisters((u_long128 *)aRegs1, 1);
        return;
    }
    if (Animate__5PGridFf(m_unk16D410, fParam) != 0) {
        SetPrevFrameBufferAsTexture();
        aRegs2[0] = 0x44;
        aRegs2[1] = 0x42;
        aRegs2[2] = 0x30000;
        aRegs2[3] = 0x47;
        aRegs2[4] = 5;
        aRegs2[5] = 8;
        m_unk154C80->SetGsRegisters((u_long128 *)aRegs2, 3);
        ((PGrid *)m_unk16D410)->Render();
        aRegs2[0] = 0;
        aRegs2[1] = 8;
        m_unk154C80->SetGsRegisters((u_long128 *)aRegs2, 1);
    } else {
        m_unk16D406 = 0;
        m_unk16D404 = 0;
        m_unk16D405 = 0;
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

// FUNCTION: 0x001876F0 SetTvOffset__10PGfxEngineFii
void PGfxEngine::SetTvOffset(int nX, int nY) {
    // m_unk158BE8 is the DISPFB2 register of the second display environment (sceGsDispfb layout).
    struct Dispfb { unsigned long FBP : 9; unsigned long FBW : 6; unsigned long PSM : 5; unsigned long p0 : 12; unsigned long DBX : 11; unsigned long DBY : 11; unsigned long p1 : 10; };
    m_unk158DE4 = nX;
    m_unk158DE8 = nY;
    if (MODE_PAL != 0) {
        m_unk158DE4 += 8;
        m_unk158DE8 -= 8;
    }
    sceGsSetDefDispEnv(m_unk158BB0, m_unk158DFE, m_unk158E08, m_unk158E0A, m_unk158DE4, m_unk158DE8);
    sceGsSetDefDispEnv(m_unk158BB0 + 0x28, m_unk158DFE, m_unk158E08, m_unk158E0A, m_unk158DE4, m_unk158DE8);
    ((Dispfb *)&m_unk158BE8)->FBP = ((m_unk158E08 + 0x3F) / 64) * ((m_unk158E0A + 0x1F) / 32);
}

// DRAFT: 0x00187C10 RefreshDisplay__10PGfxEngineFv
// note: DIFF 184 words, size 0x31c vs 0x314; first diff at 0x20 (this->m_unk154C80 load folded to lui/ori/addu lw 0 instead of lui at/addu/lw 0x4C80(at)); also GsRegs stores order, Count reg and display-target select differ. Header _pad000 split tried, no change.
void PGfxEngine::RefreshDisplay() {
    int nCount;
    long long aGsRegs[6];

    RenderBlendedFragments(m_unk16D330);
    m_unk154C80->SetVifCodes(0x07002000, 0x93000000);
    gDebug.RenderPerformanceMeters();
    aGsRegs[0] = 0x44;
    aGsRegs[1] = 0x42;
    aGsRegs[3] = 0x47;
    aGsRegs[4] = 1;
    aGsRegs[5] = 0x1A;
    aGsRegs[2] = ((long long)m_unk158E00 << 0x11) | 0x10000;
    m_unk154C80->SetGsRegisters((u_long128 *)aGsRegs, 3);
    asm {
        mfc0 nCount, $9
    }
    m_unk158E0C = nCount;
    DmaWaitForCompletion(1, false);
    sceGsSyncPath(0, 0);
    if (m_unk16F444 == 0) {
        gDebug.FrameEnd();
    }
    asm {
        mfc0 nCount, $9
    }
    m_unk158E10 = nCount;
    m_unk158DE0 += 1;
    m_unk158DEC = sceGsSyncV(0) == 0;
    int nWait = m_unk16F448;
    if (nWait > 0) {
        m_unk16F448 = nWait - 1;
    } else if (m_unk16F444 != 0) {
        GsDumpFrameBuffersAsBmp((m_unk158DE0 - 1) & 1, (m_unk158DEC == 0) & 0xFF);
        m_unk16F444 = 0;
        m_unk16F448 = 0;
    }
    sceGsSetHalfOffset((m_unk158DE0 & 1) ? (void *)m_unk158D00 : (void *)m_unk158C10, 0x800, 0x800, m_unk158DEC);
    FlushCache(0);
    m_unk158DF0 = GsSwapDBuff((sceGsDBuff *)m_unk158BB0, m_unk158DE0);
    sceGsSyncPath(0, 0);
    asm {
        mtc0 $0, $9
    }
    Kick__16PTextureDmaChainFb((void *)((char *)m_unk154C80 + 0xA3380), false);
    m_unk154C80->KickVifDmaChain(false);
    PDisplayList *pNext = (PDisplayList *)this;
    if (m_unk154C80 == pNext) {
        pNext = (PDisplayList *)((char *)this + 0xAA640);
    }
    m_unk154C80 = pNext;
    m_unk154C80->Reset();
    ((PTextureManager *)m_unk154C90)->ResetDynamicBuffers();
    m_unk154C80->SetVifCodes(0x07001000, 0x80000000);
    m_unk154C80->SetVifCodes(0x13000000, 0);
    m_unk154C80->SetVifCodes(0, 0x80000000);
}

// FUNCTION: 0x00187F30 ErrorRefreshDisplay__10PGfxEngineFb
void PGfxEngine::ErrorRefreshDisplay(bool bFlag) {
    m_unk158C90 = 0x30001;
    m_unk158D80 = 0x30001;
    sceGsSyncPath(0, 0);
    int *pCounter = &m_unk158DE0;
    *pCounter = *pCounter + 1;
    m_unk158DEC = ((sceGsSyncV(0) != 0) ^ 1);
    sceGsSetHalfOffset((m_unk158DE0 & 1) ? (void *)m_unk158D00 : (void *)m_unk158C10, 0x800, 0x800, m_unk158DEC);
    if (bFlag) {
        iFlushCache(0);
    } else {
        FlushCache(0);
    }
    m_unk158DF0 = GsSwapDBuff((sceGsDBuff *)m_unk158BB0, m_unk158DE0);
    sceGsSyncPath(0, 0);
}

// FUNCTION: 0x00188060 Reset__10PGfxEngineFv
void PGfxEngine::Reset() {
    sceGsSyncPath(0, 0);
    sceGsResetPath();
    sceDevVu1Reset();
    *(unsigned int *)0x10003C20 = 6;
    sceDmaReset(1);
    asm {
        sync
        sync.p
    }
    sceGsSyncV(0);
    sceGsResetGraph(0, 1, *(short *)((char *)this + 0x158DFC), 1);
    GsClearVRAM(0, 0, 0, 0, 0x400, 0x400, 0);
    int nV = sceGsSyncV(0);
    m_unk158DEC = (nV != 0) ^ 1;
    asm {
        sync
        sync.p
    }
    int nBit = (*(volatile unsigned long long *)0x12001000 & 0x2000) != 0;
    asm {
        sync
        sync.p
    }
    m_unk158DE0 = nBit;
    ((PDisplayList *)this)->Reset();
    ((PDisplayList *)((char *)this + 0xAA640))->Reset();
    m_unk154C80 = (PDisplayList *)this;
    unsigned long long aGs[16];
    aGs[0] = 0x44;
    aGs[1] = 0x42;
    aGs[2] = ((long long)*(short *)((char *)this + 0x158E00) << 17) | 0x10000;
    aGs[3] = 0x47;
    aGs[4] = 0;
    aGs[5] = 0x08;
    aGs[6] = 0;
    aGs[7] = 0x49;
    aGs[8] = 0x807F | (0x81ULL << 32);
    aGs[9] = 0x3B;
    aGs[10] = 0;
    aGs[11] = 0x4A;
    aGs[12] = 0;
    aGs[13] = 0x1A;
    aGs[14] = 0;
    aGs[15] = 0x00;
    ((PDisplayList *)this)->SetGsRegisters((u_long128 *)aGs, 8);
    ((PDisplayList *)this)->SetVu1Microcode(m_unk158E1C);
    ((PDisplayList *)this)->KickVifDmaChain(true);
    *(unsigned int *)0x10003010 = 4;
    asm {
        sync
        sync.p
    }
}

// DRAFT: 0x00188230 ResetDisplay__10PGfxEngineFssssssii
// note: DIFF 190 words (size 0x38c vs 0x394); original reloads lui at,0x16 base per field store (no CSE) and interleaves arg daddu copies with sq saves in the prologue; ours shares base regs. Tried: v1 frame 0x90 (202), TextureManager size from members (190), hoisted nA*nB (190, no change).
void PGfxEngine::ResetDisplay(short nA, short nB, short nC, short nD, short nE, short nF, int nG, int nH) {
    int nProd = nA * nB;
    m_unk158DFC = nD;
    m_unk158DFE = nC;
    m_unk158E00 = nE;
    m_unk158E02 = nF;
    m_unk158E08 = nA;
    m_unk158E0A = nB;
    m_unk158E04 = ((unsigned int)nProd << 3) >> 13;
    Init__12PDisplayListFv(this);
    Init__12PDisplayListFv((char *)this + 0xAA640);
    m_unk154C80 = (PDisplayList *)this;
    Reset();
    sceGsSetDefDBuff(m_unk158BB0, nC, nA, nB, nE, nF, 1);
    *(unsigned long long *)((char *)this + 0x158CB0) = 0x3F80000080000000ULL;
    *(unsigned long long *)((char *)this + 0x158DA0) = 0x3F80000080000000ULL;
    sceGsSetDefDispEnv(m_unk158BB0, m_unk158DFE, m_unk158E08, m_unk158E0A, *(short *)((char *)this + 0x158DE4), *(short *)((char *)this + 0x158DE8));
    sceGsSetDefDispEnv(m_unk158BB0 + 0x28, m_unk158DFE, m_unk158E08, m_unk158E0A, *(short *)((char *)this + 0x158DE4), *(short *)((char *)this + 0x158DE8));
    int w = (m_unk158E08 + 63) / 64;
    int h = (m_unk158E0A + 31) / 32;
    m_unk158BE8 = (m_unk158BE8 & 0xFE00) | ((w * h) & 0x1FF);
    int nTex = (nC == 2) ? 2 : 4;
    Init__15PTextureManagerFiii((char *)this + 0x154C90, nTex * (3 * (m_unk158E08 * m_unk158E0A)), nG, nH);
    Init__5PGridFffiiPfUiUiUiUi((char *)this + 0x16D410, 0.0f, 0.0f, 8, 0x10, (float *)g8x16GridAlpha, 0x8C, 0x5A, 0x46, 0x73);
    Create__13PShadowBufferFiiiisf((char *)this + 0x157000, SCREEN_WIDTH, SCREEN_HEIGHT, 10, 8, 10, 95.0f);
    InitHeatHazeBuffer__16PParticleManagerFv((char *)this + 0x154F00);
    for (int i = 0; i < 20; i++) {
        sceGsSyncV(0);
    }
    m_unk158DEC = (sceGsSyncV(0) == 0);
    asm {
        sync
        sync.p
    }
    int nBit = (*(volatile unsigned long long *)0x12001000 & 0x2000) != 0;
    asm {
        sync
        sync.p
    }
    m_unk158DE0 = nBit;
    InitExceptionDisplay__Fv();
}

// DRAFT: 0x001885D0 Init__10PGfxEngineFssssssii
// note: DIFF 33 words; original recomputes lui 0x16/addu per access for the DF4 store and reload, ours CSEs the base into a0; DF8 block and bne delay slot also differ. Tried member vs explicit-base forms for DF4/DF8 stores and compares (DIFF 33/52/53/78). mtc0 Count is inline asm; draft.py cannot model sync or mtc0.
int PGfxEngine::Init(short nA, short nB, short nC, short nD, short nE, short nF, int nG, int nH) {
    sceGsResetPath();
    sceDevVif0Reset();
    sceDevVif1Reset();
    sceDevVu0Reset();
    sceDevVu1Reset();
    *(unsigned int *)0x10003C20 = 6;
    sceDmaReset(1);
    SetupExceptionHandlers__Fv();
    asm {
        mtc0 $0, $9
    }
    *(int *)((char *)this + 0x160000 - 0x720C) = AddIntcHandler(5, Vif1InterruptHandler, 0);
    if (*(int *)((char *)this + 0x160000 - 0x720C) == -1) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0xF0, "miVif1IntcHandle != -1");
    }
    EnableIntc(5);
    m_unk158DF8 = AddIntcHandler(3, VBlankEndInterruptHandler, 0);
    if (m_unk158DF8 == -1) {
        CdsAssert__FPciPc("PGfxEngine.cpp", 0xF5, "miVBlankIntcHandle != -1");
    }
    EnableIntc(3);
    ResetDisplay(nA, nB, nC, nD, nE, nF, nG, nH);
    SetTvOffset(0, 0);
    if (Init__16PParticleManagerFv((char *)this + 0x154F00)) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001887A0 __dt__10PGfxEngineFv
extern "C" PGfxEngine *__dt__10PGfxEngineFv(PGfxEngine *pThis, short nFlag) {
    if (pThis) {
        sceGsSyncPath(0, 0);
        DisableIntc(5);
        DisableIntc(3);
        RemoveIntcHandler(5, pThis->m_unk158DF4);
        RemoveIntcHandler(3, pThis->m_unk158DF8);
        pThis->m_unk158DF4 = -1;
        pThis->m_unk158DF8 = -1;
        __dt__5PGridFv(pThis->m_unk16D410, -1);
        __destroy_arr(pThis->m_unk169320, __dt__5PMat4Fv, 0x40, 0x100);
        __destroy_arr(pThis->m_unk159310, __dt__Q210PGfxEngine22tagBlendedFragmentInfoFv, 0x100, 0x100);
        __dt__13PShadowBufferFv((char *)pThis + 0x157000, -1);
        __dt__16PParticleManagerFv((char *)pThis + 0x154F00, -1);
        __dt__15PTextureManagerFv(pThis->m_unk154C90, -1);
        __dt__12PDisplayListFv((char *)pThis + 0xAA640, -1);
        __dt__12PDisplayListFv(pThis, -1);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x188900 __dt__Q210PGfxEngine22tagBlendedFragmentInfoFv
PGfxEngine::tagBlendedFragmentInfo::~tagBlendedFragmentInfo() {}

// DRAFT: 0x00188950 __ct__10PGfxEngineFv
// note: member-ctor form DIFF 362 words, size 0x5b4 vs 0x63c; frame 0x30 with only s0 (original 0xB0 with fp,s7..s0), constants hoisted differently in tail; local char* pMat for 0x158E30 worse (385).
PGfxEngine::PGfxEngine() {
    __ct__15PTextureManagerFv(this->m_unk154C90);
    __ct__16PParticleManagerFv((char *)this + 0x154F00);
    __ct__13PShadowBufferFv((char *)this + 0x157000);
    sceVu0UnitMatrix(this->m_unk158E30);
    sceVu0UnitMatrix(this->m_unk158E70);
    __construct_array(this->m_unk159310, __ct__Q210PGfxEngine22tagBlendedFragmentInfoFv, __dt__Q210PGfxEngine22tagBlendedFragmentInfoFv, 0x100, 0x100);
    __construct_array(this->m_unk169320, __ct__5PMat4Fv, __dt__5PMat4Fv, 0x40, 0x100);
    sceVu0UnitMatrix(this->m_unk16D340);
    sceVu0UnitMatrix(this->m_unk16D380);
    sceVu0UnitMatrix(this->m_unk16D3C0);
    __ct__5PGridFv(this->m_unk16D410);
    this->m_unk154C80 = 0;
    this->m_unk158DE0 = 0;
    this->m_unk158DEC = 0;
    this->m_unk158E00 = 0;
    this->m_unk158E02 = 0;
    this->m_unk158E14 = 0;
    this->m_unk158E18 = 0;
    this->m_unk158E0C = 0;
    this->m_unk158E04 = 0;
    this->m_unk158E08 = 0;
    this->m_unk158E0A = 0;
    this->m_unk158F00 = 0;
    this->m_unk158F01 = 0;
    gpGfxEngine = this;
    this->m_unk158E1C = vu_clip_microcode_dma_packet;
    this->m_unk158E20 = 0;
    this->m_unk158E21 = 1;
    this->m_unk158E22 = 0;
    this->m_unk158E24 = 0;
    this->m_unk158E25 = 0;
    this->m_unk158E26 = 1;
    this->m_unk16D406 = 0;
    this->m_unk16D404 = 0;
    this->m_unk16D405 = 0;
    this->ResetVuLightingInfo();
    this->ResetBlendedFragmentTable();
    this->m_unk16D330[2] = 0.0f;
    this->m_unk16D330[1] = 0.0f;
    this->m_unk16D330[0] = 0.0f;
    this->m_unk16D330[3] = 1.0f;
    this->m_unk16D408 = 0;
    this->m_unk16F444 = 0;
    this->m_unk16F448 = 2;
    *(long long *)(this->m_unk158B00 + 0x70) = 0x44;
    *(long long *)(this->m_unk158B00 + 0x78) = 0x42;
    *(long long *)(this->m_unk158B00 + 0x80) = 0x50000;
    *(long long *)(this->m_unk158B00 + 0x88) = 0x47;
    *(long long *)(this->m_unk158B00 + 0x90) = 0;
    *(long long *)(this->m_unk158B00 + 0x98) = 0x1A;
    *(long long *)(this->m_unk158B00 + 0xA0) = 0x18;
    *(long long *)(this->m_unk158B00 + 0xA8) = 0x1B;
    *(unsigned short *)(this->m_unk158B00 + 0x60) = 0;
    *(unsigned short *)(this->m_unk158B00 + 0x60) = (*(unsigned short *)(this->m_unk158B00 + 0x60) & ~0x7FFF) | 4;
    this->m_unk158DF4 = -1;
    this->m_unk158DF8 = -1;
    this->m_unk158DE4 = 0;
    this->m_unk158DE8 = 0;
    *(unsigned short *)(this->m_unk158B00 + 0x0) = 0;
    *(unsigned short *)(this->m_unk158B00 + 0x0) = (*(unsigned short *)(this->m_unk158B00 + 0x0) & ~0x7FFF) | 5;
    this->m_unk158B00[0x1] = (this->m_unk158B00[0x1] & ~0x80) | ((0 & 1) << 7);
    this->m_unk158B00[0x61] = (this->m_unk158B00[0x61] & ~0x80) | 0x80;
    this->m_unk158B00[0x67] = (this->m_unk158B00[0x67] & ~0xF0) | 0x10;
    this->m_unk158B00[0x68] = (this->m_unk158B00[0x68] & ~0xF) | 0xE;
    this->m_unk158B00[0x7] = (this->m_unk158B00[0x7] & ~0xF0) | 0x10;
    this->m_unk158B00[0x8] = (this->m_unk158B00[0x8] & ~0xF) | 0xF;
    *(long long *)(this->m_unk158B00 + 0x10) = 0;
    *(long long *)(this->m_unk158B00 + 0x20) = 0;
    *(long long *)(this->m_unk158B00 + 0x30) = 0;
    *(long long *)(this->m_unk158B00 + 0x40) = 0;
    *(long long *)(this->m_unk158B00 + 0x50) = 0;
    return;
}
