#ifndef PTEXTUREMANAGER_H
#define PTEXTUREMANAGER_H

#include "types.h"

// Texture header read from the pak file, 0x2C bytes.
struct tagPs2TexDataHeader {
    char unk0;                  // 0x00
    char unk1;                  // 0x01
    char type;                  // 0x02 texture type, 0x13 and 0x14 carry a CLUT
    char cNumMipMaps;           // 0x03
    char unk4;                  // 0x04
    char unk5;                  // 0x05
    char unk6;                  // 0x06
    char unk7;                  // 0x07
    int unk8;                   // 0x08 image data size
    char _pad0C[0x24 - 0x0C];   // 0x0C
    short unk24;                // 0x24 CLUT data size
    short unk26;                // 0x26
    short unk28;                // 0x28
    short unk2A;                // 0x2A
};

struct tagGsTextureEnvironment;
struct tagGsImageXferInfo;
struct tagImageDmaPacket;
struct tagGsClut256;
class PArray;
class PDisplayList;
class PPakFile;

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

    virtual ~PTexture();               // vtable slot 0x08 (deleting dtor)
    virtual int InitRendered(tagPs2TexDataHeader *pTexHeader, tagGsTextureEnvironment *pTexEnv, eTextureGroup eGroup); // vtable slot 0x0C

    // 0x000 vtable pointer is implicit (virtual dtor).
    int InitProcedural();
    char m_unk4[0x2C];          // 0x004 copied texture header
    void *m_unk30;              // 0x030
    void *m_unk34;              // 0x034
    char m_unk38[0x40 - 0x38];
    char m_unk40[0x60];         // 0x040 copied texture environment
    int m_unkA0;               // 0x0A0
    int m_unkA4;               // 0x0A4
    unsigned char m_unkA8;     // 0x0A8
    int m_unkAC;               // 0x0AC
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
    PTextureManager();
    ~PTextureManager();

    void DecodeTextureHandle(int nHandle, bool &bFlag, PTexture::eTextureType &eType, int &nIndex);
    int EncodeTextureHandle(bool bFlag, PTexture::eTextureType eType, int nIndex);
    PTexture *GetTexture(bool bFlag, PTexture::eTextureType eType, int nIndex);
    tagGsTextureEnvironment *GetTexEnv(int nHandle);
    void KickDmaChain(void *pBuf, bool bWait);
    void UnloadStaticTextures();
    void Shutdown();
    void FlipTextureBuffers();
    void ResetDynamicBuffers();
    int Init(int nTexMemStart, int nStaticSize, int nDynamicSize);

    void DestroyRenderedTexture(int nHandle);
    void UnloadDynamicTexture(int nHandle);
    void UnloadAllDynamicTextures();
    void UnloadAllRenderedTextures();
    void UnloadDynamicTextures(eTextureGroup eGroup);
    int LoadDynamicTextures(PPakFile *poFile, eTextureGroup eGroup, PArray *pArray);
    int LoadStaticTextures(PPakFile *poFile, eTextureGroup eGroup, PArray *pArray);
    void PrepareImageXferInfo(tagGsImageXferInfo *pInfo, int nWidth, int nHeight, int nPsm, int nBase);
    void PrepareImageDmaPacket(tagImageDmaPacket *pPacket, void *pData, int nSize, int nWidth, int nHeight, int nPsm, int nBase);
    int AddTexture(PTexture *pTex, PArray *pArray);
    int AllocRenderedTexture(int nHandle, int nSecond, bool &bOut, bool bFlag);
    int CreateRenderedTexture(short nWidth, short nHeight, short nDepth, short nX, short nY, eTextureGroup eGroup, bool bFlag);
    int AllocDynamicVramForTexture(tagPs2TexDataHeader *pHeader, int nSecond, int &nVram, int &nTmp, bool &bOut, bool bFlag);
    void PrepareDynamicClutPacket(tagGsClut256 *pClut, tagGsTextureEnvironment *pTexEnv, bool bFlag, PDisplayList *pDisplayList);
    int PrepareStaticTextureForDma(u_long128 *pDmaChain, tagPs2TexDataHeader *pTexHeader, void *pvTexClutPacket, void *pvTexImagePacket, tagGsTextureEnvironment *pTexEnv);
    int LoadTexture(PPakFile *poFile, tagPs2TexDataHeader *pTexHeader, void **ppvTexClutPacket, void **ppvTexImagePacket);
    void SetTexture(int nHandle, PDisplayList *pDisplayList, tagGsTextureEnvironment **ppEnv, bool &bOut);
    int SetTextures(int *pHandles, int nCount, PDisplayList *pDisplayList, bool &bOut);
    int UploadTextures(int *pHandles, int nCount, PDisplayList *pDisplayList);
    void UploadDynamicTexturesToVram(int *pArray, int nCount, int nA, int nB, bool bFlag);

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
    int m_nDynCount;            // 0x1DC PArray element count
    int m_unk1E0;               // 0x1E0 PArray unknown
    PTexture **m_apDyn;         // 0x1E4 PArray element storage
    int m_unk1E8;               // 0x1E8 PArray capacity
    char m_unk1EC[0x1F0 - 0x1EC];
    char m_unk1F0[0x250 - 0x1F0]; // 0x1F0 tagGsTextureEnvironment, passed to GsInitTexEnv by Init
    int m_nRenderedCount;       // 0x250 PArray element count
    int m_unk254;               // 0x254
    PTexture **m_apRendered;    // 0x258 PArray element storage
    int m_unk25C;               // 0x25C PArray capacity
    unsigned char m_unk260;     // 0x260 set to 1 by the constructor
};

#endif
