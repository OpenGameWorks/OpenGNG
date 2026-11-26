#ifndef PMOVIEOVERLAYENGINE_H
#define PMOVIEOVERLAYENGINE_H

#include "types.h"

class PTextureManager;
class PDisplayList;
class PMat4;
struct tagGsMaterial;
struct tagVuSprite;

class PMovieOverlayEngine {
public:
    PMovieOverlayEngine();
    ~PMovieOverlayEngine();
    void BeginSprites();
    void BeginRender(unsigned int nFlags);
    void SetMaterial(int nIndex, float *pColor, bool bFlag, unsigned long nA, unsigned long nB);
    int InitTextures(int *pData, int nCount);
    int Init(short a, short b, short c);
    void EndSprites();
    void EndRender();
    void DrawSprites(struct tagVuSprite *pSprite, int nCount, bool bFlag);
    void SetViewMatrix(PMat4 *pMat);
    void SetWorldMatrix(PMat4 *pMat);
    void SetScreenMatrix(PMat4 *pMat);

    PTextureManager *m_unk0;        // 0x00
    PDisplayList *m_unk4;           // 0x04
    char _pad08[0x8];
    unsigned short m_unk10;         // 0x10, also the GS register block passed as this+0x10
    char _pad12[0x12];
    unsigned char m_unk24;          // 0x24
    char _pad25[0x6B];
    int m_unk90;                    // 0x90
};

#endif
