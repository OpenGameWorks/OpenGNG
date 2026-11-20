#ifndef PGFXENGINE_H
#define PGFXENGINE_H

class PMat4;
class PMNode;
class PMeshFragment;
struct tagGsClut256;
struct tagVuFxLine;
struct tagVuParticle;
struct tagVuRotatableParticle;
struct tagVuLightingInfo;
class PZBufferFog;
// TODO(header): ePSLayer belongs to PParticleManager.h. Placeholder until that header is included; only the name matters for mangling.
#ifndef PPARTICLEMANAGER_H
enum ePSLayer { ePSLayer_2 = 2 };
#endif
// TODO(header): eBoxIntersect belongs to PMNode.h. Placeholder until that header is included; only the name matters for mangling.
#ifndef PMNODE_H
enum eBoxIntersect { eBoxIntersect_Placeholder = 0 };
#endif
// TODO(header): eGsContext belongs to the GS context header. Placeholder until that header defines it; only the name matters for mangling.
enum eGsContext { eGsContext_Placeholder = 0 };

struct tagDirLightColor {
    float m_fR;
    float m_fG;
    float m_fB;
    int m_nW;
};

class PGfxEngine {
public:
    struct tagBlendedFragmentInfo {
        ~tagBlendedFragmentInfo();
        PMeshFragment *m_unk0;              // 0x00
        int m_unk4;                         // 0x04, shifted left 6 to index the world matrix block
        int m_unk8;                         // 0x08, eBoxIntersect
        int m_unkC;                         // 0x0C, int argument of PMeshFragment::Render
        PMNode *m_unk10;                    // 0x10, non-null selects the shared-mesh path
        char _pad14[0x20 - 0x14];
        char m_unk20[0xF0 - 0x20];          // 0x20, tagVuLightingInfo block passed to UpdateLights
        unsigned char m_unkF0;              // 0xF0, lighting flag
        bool m_unkF1;                       // 0xF1, bFlag argument of AddBlendedFragment
        unsigned char m_unkF2;              // 0xF2, selects the bool output pointer for Render
        bool m_unkF3;                       // 0xF3, bool output of Render
    };

    void EndShadowRender();
    void BeginShadowRender();
    void DrawFxLines(struct tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag);
    void DrawHeatHaze(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag);
    void DrawRotatableParticles(struct tagVuRotatableParticle *pParticles, int nCount, float fA, float fB, bool bFlag);
    void DrawParticles(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag);
    void BeginFxLines();
    void BeginHeatHaze();
    void BeginVertexGlow();
    void BeginFogParticles(eBoxIntersect eBox);
    void BeginRotatableParticles();
    void BeginParticles(eBoxIntersect eBox);
    void BeginSprites();
    int RenderParticleSystems(ePSLayer eLayer, PZBufferFog *pFog);
    void RenderBlendedFragments(float *pVec);
    void RenderBlendedFragment(tagBlendedFragmentInfo *pInfo);
    void SetFullAmbientLight();
    void SetAmbientLight(float *pVec);
    void SetBlurHazeSourcePoint(float *pPos, float fW);
    void EndFxRender();
    void BeginFxRender();
    void BeginDebugRender();
    void DrawBox(float (*pBox)[2][4], float arg1, float arg2, float arg3);
    void DrawLines(struct tagVuLine *pLines, int nCount);
    void RenderRefractionMappedFragments();
    void UpdateLights(struct tagVuLightingInfo *pInfo);
    void UpdateLights(PMat4 *pDirMat, PMat4 *pColorMat, float (*pAmbient)[4]);
    void UpdateLights();
    void ResetVuLightingInfo();
    void CopyVuLightingInfo(struct tagVuLightingInfo *pDst, struct tagVuLightingInfo *pSrc);
    void BeginSplinePatch();
    void DrawSplinePatch(struct tagVuSplinePatchKey *pKey, int nA, int nB, float fC, bool bFlag);
    void SetScreenMatrix(PMat4 *pMat);
    void SetViewMatrix(PMat4 *pMat);
    void SetClipMatrix(PMat4 *pMat);
    void SetZBufferUpdate(bool bEnable, eGsContext eCtx);
    void SetGlowSizeAndColor(float fA, float fB, float *pColor);
    void EnableFullScreenFx(bool bEnable);
    void FadeFullScreenMotionBlur(char cTarget, int nFrames);
    void RenderFullScreenMotionBlur(float fParam);
    void BeginSharedMesh(eBoxIntersect eBox, PMNode *pNode);
    void BeginMesh(eBoxIntersect eBox);
    void *ComputeMicrocodeOffset(eBoxIntersect eBox, unsigned int &nOffset);
    void SetDirLight(int nIndex, float *pDir, float *pScale);
    void SetDirLightColor(int nIndex, float fR, float fG, float fB);
    void SetMaterial(int nIndex, float *pVec, bool bFlag, unsigned long nA, unsigned long nB);
    void SetMaterial(int nIndex, float *pVec, unsigned long nA, unsigned long nB, unsigned int *pC, unsigned int *pD, float (*pMat)[4][4]);
    void SetMaterial(float *pVec, bool bFlag, unsigned long nA, unsigned long nB);
    void SetCurFrameBufferAs8BitTexture(struct tagGsClut256 *pClut);
    void SetPrevFrameBufferAsTexture();
    void SetTexture(int nIndex);
    void GetLightingInfo(PMat4 *pA, PMat4 *pB, float (*pOut)[4]);
    void ModulateAllLights(float *pVec);
    void ResetBlendedFragmentTable();
    void SetWorldMatrix(PMat4 *pMat);
    void SetOverrideTexture(int nIndex);
    void BeginFxInstances(void *pData, int nSize, bool bFlag);
    void BeginHeatHazeInstances(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag);
    void BeginParticleInstances(struct tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag);
    void BeginStaticInstances(void *pData, int nSize);
    int AddBlendedFragment(PMeshFragment *pFrag, int nIdx, bool *pOut, bool bFlag);
    void DrawFragment(PMeshFragment *pFrag, bool bFlag, int nIdx, bool *pOut);
    void ErrorRefreshDisplay(bool bFlag);
    void RefreshDisplay();
    void SetTvOffset(int nX, int nY);
    void Reset();
    int Init(short nA, short nB, short nC, short nD, short nE, short nF, int nG, int nH);
    void ResetDisplay(short nA, short nB, short nC, short nD, short nE, short nF, int nG, int nH);

    char _pad000[0x154C80];
    struct PDisplayList *m_unk154C80;   // 0x154C80
    char _pad154C84[0x154C90 - 0x154C84];
    char m_unk154C90[0x158B00 - 0x154C90]; // 0x154C90, PTextureManager (SetTexture)
    char m_unk158B00[0x158BB0 - 0x158B00]; // 0x158B00, material block (SetMaterial copies from +0x60..+0xA0)
    char m_unk158BB0[0x158BE8 - 0x158BB0]; // 0x158BB0, sceGsDBuff passed to GsSwapDBuff; second display block at +0x28
    unsigned short m_unk158BE8;         // 0x158BE8, display size field masked by SetTvOffset
    char _pad158BEA[0x158C10 - 0x158BEA];
    char m_unk158C10[0x158C90 - 0x158C10]; // 0x158C10, display target used on even ErrorRefreshDisplay frames
    unsigned long long m_unk158C90;     // 0x158C90, GS register value 0x30001
    char _pad158C98[0x158D00 - 0x158C98];
    char m_unk158D00[0x158D80 - 0x158D00]; // 0x158D00, display target used on odd ErrorRefreshDisplay frames
    unsigned long long m_unk158D80;     // 0x158D80, GS register value 0x30001
    char _pad158D88[0x158DE0 - 0x158D88];
    int m_unk158DE0;                    // 0x158DE0, ErrorRefreshDisplay frame counter
    int m_unk158DE4;                    // 0x158DE4, TV offset X (SetTvOffset)
    int m_unk158DE8;                    // 0x158DE8, TV offset Y (SetTvOffset)
    unsigned char m_unk158DEC;          // 0x158DEC, set from the sceGsSyncV result (1 when zero)
    char _pad158DED[0x158DF0 - 0x158DED];
    int m_unk158DF0;                    // 0x158DF0, non-zero skips the frame-buffer size term in SetPrevFrameBufferAsTexture
    int m_unk158DF4;                    // 0x158DF4, INTC handler id for line 5, removed by the destructor
    int m_unk158DF8;                    // 0x158DF8, INTC handler id for line 3, removed by the destructor
    short m_unk158DFC;                  // 0x158DFC, display y passed to sceGsSetDefDispEnv
    short m_unk158DFE;                 // 0x158DFE, display x passed to sceGsSetDefDispEnv
    short m_unk158E00;                  // 0x158E00, GS register value source (RefreshDisplay)
    short m_unk158E02;                 // 0x158E02
    unsigned int m_unk158E04;           // 0x158E04
    short m_unk158E08;                  // 0x158E08, display width used by SetTvOffset
    short m_unk158E0A;                  // 0x158E0A, display height used by SetTvOffset
    int m_unk158E0C;                    // 0x158E0C, Count sampled by RefreshDisplay before DmaWaitForCompletion
    int m_unk158E10;                    // 0x158E10, Count sampled by RefreshDisplay after sceGsSyncPath
    unsigned int m_unk158E14;           // 0x158E14, Count sampled by Vif1InterruptHandler on the 0x1000 DMA tag
    unsigned int m_unk158E18;           // 0x158E18, Count sampled by Vif1InterruptHandler on the 0x2000 DMA tag
    void *m_unk158E1C;                  // 0x158E1C
    bool m_unk158E20;                   // 0x158E20, set from PMeshFragment flag bit 4
    unsigned char m_unk158E21;          // 0x158E21
    unsigned char m_unk158E22;          // 0x158E22, copy of tagBlendedFragmentInfo::m_unkF0
    unsigned char m_unk158E23;          // 0x158E23
    unsigned char m_unk158E24;          // 0x158E24
    bool m_unk158E25;                   // 0x158E25, RenderParticleSystems flag (eLayer == 2 while m_unk16D40C is set)
    char _pad158E26[0x158E30 - 0x158E26];
    float m_unk158E30[4];               // 0x158E30, VU lighting block (DMA source address only)
    float m_unk158E40[4];               // 0x158E40
    float m_unk158E50[4];               // 0x158E50
    int m_unk158E60[4];                 // 0x158E60
    tagDirLightColor m_unk158E70[4];    // 0x158E70, per-light colour (4 lights of 0x10 bytes)
    float m_unk158EB0[4];               // 0x158EB0
    unsigned int m_unk158EC0[16];       // 0x158EC0, four (0, 0, 0, 1.0f) vectors written by ResetVuLightingInfo
    unsigned char m_unk158F00;          // 0x158F00, material flag, saved and restored around SetMaterial
    unsigned char m_unk158F01;          // 0x158F01, selects comparison direction in ZCompareFragments
    char _pad158F02[0x158F04 - 0x158F02];
    char m_unk158F04[0x159310 - 0x158F04]; // 0x158F04, cleared by ResetBlendedFragmentTable
    char m_unk159310[0x10000];          // 0x159310, cleared by ResetBlendedFragmentTable
    int m_unk169310;                    // 0x169310
    char _pad169314[0x169320 - 0x169314];
    char m_unk169320[0x4000];           // 0x169320, 256 world matrices of 0x40 bytes, indexed by m_unk16D320
    int m_unk16D320;                    // 0x16D320, world matrix index
    int m_unk16D324;                    // 0x16D324, set when a world matrix is pending
    int m_unk16D328;                    // 0x16D328, last eBoxIntersect passed to BeginMesh
    char _pad16D32C[0x16D330 - 0x16D32C];
    float m_unk16D330[4];               // 0x16D330, scratch vector passed to ComputeDistanceSq
    char m_unk16D340[0x40];             // 0x16D340, copy of a PMat4 (clip)
    char m_unk16D380[0x40];             // 0x16D380, copy of a PMat4 (view)
    char m_unk16D3C0[0x40];             // 0x16D3C0, copy of a PMat4 (screen)
    PMNode *m_unk16D400;                // 0x16D400
    char m_unk16D404;                   // 0x16D404
    char m_unk16D405;                   // 0x16D405
    char m_unk16D406;                   // 0x16D406
    char _pad16D407[1];
    int m_unk16D408;                    // 0x16D408, material index override (0 = use argument)
    int m_unk16D40C;                    // 0x16D40C, cleared by ResetBlendedFragmentTable
    char m_unk16D410[0x202C];           // 0x16D410, PGrid
    float m_unk16F43C;                  // 0x16F43C
    char _pad16F440[4];
    unsigned char m_unk16F444;          // 0x16F444, dump pending flag (RefreshDisplay)
    char _pad16F445[3];
    int m_unk16F448;                    // 0x16F448, frames to wait before dumping frame buffers
};

#endif
