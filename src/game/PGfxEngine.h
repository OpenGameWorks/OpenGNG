#ifndef PGFXENGINE_H
#define PGFXENGINE_H

class PMat4;
class PMNode;
struct tagVuFxLine;
struct tagVuLightingInfo;
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
    };

    void EndShadowRender();
    void BeginShadowRender();
    void DrawFxLines(struct tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag);
    void SetFullAmbientLight();
    void SetAmbientLight(float *pVec);
    void SetBlurHazeSourcePoint(float *pPos, float fW);
    void EndFxRender();
    void BeginFxRender();
    void BeginDebugRender();
    void UpdateLights(struct tagVuLightingInfo *pInfo);
    void UpdateLights();
    void CopyVuLightingInfo(struct tagVuLightingInfo *pDst, struct tagVuLightingInfo *pSrc);
    void BeginSplinePatch();
    void SetScreenMatrix(PMat4 *pMat);
    void SetViewMatrix(PMat4 *pMat);
    void SetClipMatrix(PMat4 *pMat);
    void SetZBufferUpdate(bool bEnable, eGsContext eCtx);
    void SetGlowSizeAndColor(float fA, float fB, float *pColor);
    void EnableFullScreenFx(bool bEnable);
    void FadeFullScreenMotionBlur(char cTarget, int nFrames);
    void BeginSharedMesh(eBoxIntersect eBox, PMNode *pNode);
    void BeginMesh(eBoxIntersect eBox);
    void *ComputeMicrocodeOffset(eBoxIntersect eBox, unsigned int &nOffset);
    void SetDirLight(int nIndex, float *pDir, float *pScale);
    void SetDirLightColor(int nIndex, float fR, float fG, float fB);
    void SetMaterial(int nIndex, float *pVec, bool bFlag, unsigned long nA, unsigned long nB);
    void SetMaterial(int nIndex, float *pVec, unsigned long nA, unsigned long nB, unsigned int *pC, unsigned int *pD, float (*pMat)[4][4]);
    void SetPrevFrameBufferAsTexture();
    void SetTexture(int nIndex);

    char _pad000[0x154C80];
    struct PDisplayList *m_unk154C80;   // 0x154C80
    char _pad154C84[0x154C90 - 0x154C84];
    char m_unk154C90[0x158DF0 - 0x154C90]; // 0x154C90, PTextureManager (SetTexture)
    int m_unk158DF0;                    // 0x158DF0, non-zero skips the frame-buffer size term in SetPrevFrameBufferAsTexture
    char _pad158DF4[0x158E02 - 0x158DF4];
    short m_unk158E02;                 // 0x158E02
    unsigned int m_unk158E04;           // 0x158E04
    char _pad158E08[0x158E1C - 0x158E08];
    void *m_unk158E1C;                  // 0x158E1C
    char _pad158E20[1];
    unsigned char m_unk158E21;          // 0x158E21
    char _pad158E22[1];
    unsigned char m_unk158E23;          // 0x158E23
    unsigned char m_unk158E24;          // 0x158E24
    char _pad158E25[0x158E30 - 0x158E25];
    float m_unk158E30[4];               // 0x158E30, VU lighting block (DMA source address only)
    float m_unk158E40[4];               // 0x158E40
    float m_unk158E50[4];               // 0x158E50
    int m_unk158E60[4];                 // 0x158E60
    tagDirLightColor m_unk158E70[4];    // 0x158E70, per-light colour (4 lights of 0x10 bytes)
    float m_unk158EB0[4];               // 0x158EB0
    char _pad158EC0[0x158F00 - 0x158EC0];
    unsigned char m_unk158F00;          // 0x158F00, material flag, saved and restored around SetMaterial
    char _pad158F01[0x16D328 - 0x158F01];
    int m_unk16D328;                    // 0x16D328, last eBoxIntersect passed to BeginMesh
    char _pad16D32C[0x16D340 - 0x16D32C];
    char m_unk16D340[0x40];             // 0x16D340, copy of a PMat4 (clip)
    char m_unk16D380[0x40];             // 0x16D380, copy of a PMat4 (view)
    char m_unk16D3C0[0x40];             // 0x16D3C0, copy of a PMat4 (screen)
    PMNode *m_unk16D400;                // 0x16D400
    char m_unk16D404;                   // 0x16D404
    char m_unk16D405;                   // 0x16D405
    char m_unk16D406;                   // 0x16D406
    char _pad16D407[1];
    int m_unk16D408;                    // 0x16D408, material index override (0 = use argument)
    char _pad16D40C[0x16D410 - 0x16D40C];
    char m_unk16D410[0x202C];           // 0x16D410, PGrid
    float m_unk16F43C;                  // 0x16F43C
};

#endif
