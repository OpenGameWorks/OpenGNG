#ifndef PGFXENGINE_H
#define PGFXENGINE_H

class PGfxEngine {
public:
    struct tagBlendedFragmentInfo {
        ~tagBlendedFragmentInfo();
    };

    void EndShadowRender();
    void DrawFxLines(struct tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag);
    void SetFullAmbientLight();
    void SetAmbientLight(float *pVec);

    char _pad000[0x154C80];
    struct PDisplayList *m_unk154C80;   // 0x154C80
    char _pad154C84[0x158E1C - 0x154C84];
    void *m_unk158E1C;                  // 0x158E1C
    char _pad158E20[0x158EB0 - 0x158E20];
    float m_unk158EB0[4];               // 0x158EB0
};

#endif
