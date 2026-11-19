#ifndef PTEXTUREMANAGER_H
#define PTEXTUREMANAGER_H

#include "types.h"

// PTexture is defined by another worker. This stub holds only the nested
// eTextureType, which the signatures below need to be complete.
class PTexture {
public:
    enum eTextureType {
        eTextureType_Unknown = 0
    };
};

class PTextureManager {
public:
    void DecodeTextureHandle(int nHandle, bool &bFlag, PTexture::eTextureType &eType, int &nIndex);
    int EncodeTextureHandle(bool bFlag, PTexture::eTextureType eType, int nIndex);
    void KickDmaChain(void *pBuf, bool bWait);
    void UnloadStaticTextures();
    void Shutdown();

    void UnloadAllDynamicTextures();
    void UnloadAllRenderedTextures();

    int m_unk0;                 // 0x000
    int m_unk4;                 // 0x004
    int m_unk8;                 // 0x008
    int m_unkC;                 // 0x00C
    int m_unk10;                // 0x010
    char _pad014[0x1D0 - 0x14];
    void *m_unk1D0;             // 0x1D0
    int m_unk1D4;               // 0x1D4
    int m_unk1D8;               // 0x1D8
};

#endif
