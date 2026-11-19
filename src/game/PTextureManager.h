#ifndef PTEXTUREMANAGER_H
#define PTEXTUREMANAGER_H

#include "types.h"

struct tagPs2TexDataHeader;
struct tagGsTextureEnvironment;

// Texture group argument of PTexture::InitRendered.
enum eTextureGroup {
    eTextureGroup_Unknown = 0
};

// PTexture is defined by another worker. This stub holds the members that the
// functions in this file touch, at their original offsets.
class PTexture {
public:
    enum eTextureType {
        eTextureType_Unknown = 0
    };

    virtual ~PTexture();
    int InitRendered(tagPs2TexDataHeader *pTexHeader, tagGsTextureEnvironment *pTexEnv, eTextureGroup eGroup);

    // 0x000 vtable pointer is implicit (virtual dtor).
    char m_unk4[0x2C];          // 0x004 copied texture header
    void *m_unk30;              // 0x030
    void *m_unk34;              // 0x034
    char m_unk38[0x40 - 0x38];
    char m_unk40[0x60];         // 0x040 copied texture environment
    int m_unkA0;               // 0x0A0
    int m_unkA4;               // 0x0A4
    char m_unkA8;              // 0x0A8
};

// One of the two per-frame texture lists owned by PTextureManager.
class PTextureBuffer {
public:
    int m_unk0;                 // 0x00
    int m_unk4;                 // 0x04
    int m_unk8;                 // 0x08
    int m_unkC;                 // 0x0C
    int m_unk10;                // 0x10
    int m_unk14;                // 0x14
    PTexture *m_apTex[0x30];    // 0x18
    int m_unkD8;                // 0xD8
};

class PTextureManager {
public:
    ~PTextureManager();

    void DecodeTextureHandle(int nHandle, bool &bFlag, PTexture::eTextureType &eType, int &nIndex);
    int EncodeTextureHandle(bool bFlag, PTexture::eTextureType eType, int nIndex);
    void KickDmaChain(void *pBuf, bool bWait);
    void UnloadStaticTextures();
    void Shutdown();
    void FlipTextureBuffers();

    void UnloadAllDynamicTextures();
    void UnloadAllRenderedTextures();

    int m_unk0;                 // 0x000
    int m_unk4;                 // 0x004
    int m_unk8;                 // 0x008
    int m_unkC;                 // 0x00C
    int m_unk10;                // 0x010
    PTextureBuffer m_aBuf0;     // 0x014
    PTextureBuffer m_aBuf1;     // 0x0F0
    PTextureBuffer *m_pCurBuf;  // 0x1CC
    void *m_unk1D0;             // 0x1D0
    int m_unk1D4;               // 0x1D4
    int m_unk1D8;               // 0x1D8
    char m_unk1DC[0x250 - 0x1DC]; // 0x1DC PArray (placeholder)
    int m_nRenderedCount;       // 0x250 PArray element count
    int m_unk254;               // 0x254
    PTexture **m_apRendered;    // 0x258 PArray element storage
};

#endif
