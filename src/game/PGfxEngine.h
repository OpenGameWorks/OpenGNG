#ifndef PGFXENGINE_H
#define PGFXENGINE_H

class PMat4;
struct tagVuFxLine;
struct tagVuLightingInfo;

class PGfxEngine {
public:
    struct tagBlendedFragmentInfo {
        ~tagBlendedFragmentInfo();
    };

    void EndShadowRender();
    void DrawFxLines(struct tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag);
    void SetFullAmbientLight();
    void SetAmbientLight(float *pVec);
    void SetBlurHazeSourcePoint(float *pPos, float fW);
    void EndFxRender();
    void UpdateLights(struct tagVuLightingInfo *pInfo);
    void SetScreenMatrix(PMat4 *pMat);
    void FadeFullScreenMotionBlur(char cTarget, int nFrames);

    char _pad000[0x154C80];
    struct PDisplayList *m_unk154C80;   // 0x154C80
    char _pad154C84[0x158E1C - 0x154C84];
    void *m_unk158E1C;                  // 0x158E1C
    char _pad158E20[3];
    unsigned char m_unk158E23;          // 0x158E23
    char _pad158E24[0x158EB0 - 0x158E24];
    float m_unk158EB0[4];               // 0x158EB0
    char _pad158EC0[0x16D3C0 - 0x158EC0];
    char m_unk16D3C0[0x40];             // 0x16D3C0, copy of a PMat4
    char _pad16D400[0x16D404 - 0x16D400];
    char m_unk16D404;                   // 0x16D404
    char m_unk16D405;                   // 0x16D405
    char m_unk16D406;                   // 0x16D406
};

#endif
