#ifndef PGFXENGINE_H
#define PGFXENGINE_H

class PMat4;
struct tagVuFxLine;
struct tagVuLightingInfo;
// TODO(header): eGsContext belongs to the GS context header. Placeholder until that header defines it; only the name matters for mangling.
enum eGsContext { eGsContext_Placeholder = 0 };

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
    void SetScreenMatrix(PMat4 *pMat);
    void SetViewMatrix(PMat4 *pMat);
    void SetClipMatrix(PMat4 *pMat);
    void SetZBufferUpdate(bool bEnable, eGsContext eCtx);
    void SetGlowSizeAndColor(float fA, float fB, float *pColor);
    void EnableFullScreenFx(bool bEnable);
    void FadeFullScreenMotionBlur(char cTarget, int nFrames);

    char _pad000[0x154C80];
    struct PDisplayList *m_unk154C80;   // 0x154C80
    char _pad154C84[0x158E02 - 0x154C84];
    short m_unk158E02;                  // 0x158E02
    unsigned int m_unk158E04;           // 0x158E04
    char _pad158E08[0x158E1C - 0x158E08];
    void *m_unk158E1C;                  // 0x158E1C
    char _pad158E20[3];
    unsigned char m_unk158E23;          // 0x158E23
    char _pad158E24[0x158E30 - 0x158E24];
    char m_unk158E30[0x158EB0 - 0x158E30]; // 0x158E30, VU lighting block (DMA source address only)
    float m_unk158EB0[4];               // 0x158EB0
    char _pad158EC0[0x16D340 - 0x158EC0];
    char m_unk16D340[0x40];             // 0x16D340, copy of a PMat4 (clip)
    char m_unk16D380[0x40];             // 0x16D380, copy of a PMat4 (view)
    char m_unk16D3C0[0x40];             // 0x16D3C0, copy of a PMat4 (screen)
    char _pad16D400[0x16D404 - 0x16D400];
    char m_unk16D404;                   // 0x16D404
    char m_unk16D405;                   // 0x16D405
    char m_unk16D406;                   // 0x16D406
    char _pad16D407[0x16D410 - 0x16D407];
    char m_unk16D410[0x202C];           // 0x16D410, PGrid
    float m_unk16F43C;                  // 0x16F43C
};

#endif
