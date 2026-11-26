// FLAGS: -str readonly
#include "types.h"
#include "PMovieOverlayEngine.h"

// TODO(header): foreign declarations
struct tagGsTextureEnvironment;
struct tagGsMaterial;

class PTextureManager {
public:
    tagGsTextureEnvironment *GetTexEnv(int nHandle);
    void UploadDynamicTexturesToVram(int *pData, int nA, int nB, int nC, bool bFlag);
};

class PDisplayList {
public:
    void SetGsRegisters(u_long128 *pRegData, int nNumRegs);
    void Reset();
    void KickVifDmaChain(bool bWait);
    void SetVu1Microcode(void *pMicrocode);
    void SetMaterials(tagGsMaterial *pMat, int nIndex, bool bA, bool bB, float *pF, unsigned long *pC, unsigned long *pD);
    void BeginFxLoop(unsigned int nAddr);
    char _padA0000[0xA3348];
    int m_unkA3348;             // 0xA3348
};

extern "C" void sceGsSetDefDrawEnv(void *pEnv, short nPsm, short nW, short nH, int nA, int nB);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);
extern char gGfxEng[1504384];
extern char vu_fx_microcode_dma_packet[];
extern char fx_sprite_noclip_init[];

// The halfword at 0x10 holds a 9-bit field in its low bits. BeginRender writes it
// as a bitfield: the hand-written mask-and-or form allocates v0/v1 the other way.
struct PMovieOverlayRenderBits {
    unsigned short nLow : 9;
    unsigned short nHigh : 7;
};

// FUNCTION: 0x0020DA20 BeginRender__19PMovieOverlayEngineFUi
void PMovieOverlayEngine::BeginRender(unsigned int nFlags) {
    ((PMovieOverlayRenderBits *)&m_unk10)->nLow = nFlags;
    m_unk4->SetGsRegisters((u_long128 *)&m_unk10, 8);
}

// FUNCTION: 0x0020DA70 BeginSprites__19PMovieOverlayEngineFv
void PMovieOverlayEngine::BeginSprites() {
    m_unk4->BeginFxLoop(((unsigned int)(fx_sprite_noclip_init + 0x150)) >> 3);
}

// The packet is a local at sp+0x20: GIF tag at +0x10, four A+D quads at +0x20, colour copy at +0x60.
struct MovieMaterialPacket {
    unsigned int nHead;                     // 0x00
    tagGsTextureEnvironment *pTexEnv;       // 0x04
    unsigned long long nPad08;              // 0x08
    unsigned char aTag[16];                 // 0x10 GIF tag
    struct {
        unsigned long long nData;           // lo doubleword
        unsigned long long nReg;            // hi doubleword, GS register address
    } aQ[4];                                // 0x20
    float aColor[4];                        // 0x60
    u_long128 qZero70;                      // 0x70
    u_long128 qZero80;                      // 0x80
    unsigned int nZero90;                   // 0x90
};

// DRAFT: 0x0020DA90 SetMaterial__19PMovieOverlayEngineFiPfbUlUl
// note: 39 words differ; frame 0xC0 matches. Remaining: GIF tag RMW ordering (original reads tag bytes after the sh and writes them last), the flag word (ours uses dsll32/dsra32 on the sd value), and quad store order. Tried: 64-bit casts on the flag (46), tag byte locals (74), tag-first store order (72)
void PMovieOverlayEngine::SetMaterial(int nIndex, float *pColor, bool bFlag, unsigned long nA, unsigned long nB) {
    MovieMaterialPacket p;
    p.aQ[0].nReg = 0x42;
    p.aQ[0].nData = nA;
    p.aQ[1].nReg = 0x47;
    p.aQ[1].nData = nB;
    p.aQ[2].nReg = 0x1A;
    p.aQ[2].nData = 0;
    p.aQ[3].nReg = 0x1B;
    p.aQ[3].nData = ((nIndex != 0) * 0x10) | 8 | ((bFlag & 0xFF) << 6);
    *(u_long128 *)p.aTag = 0;
    *(unsigned short *)p.aTag = (*(unsigned short *)p.aTag & 0x8000) | 4;
    *(u_long128 *)&p.qZero70 = 0;
    *(u_long128 *)&p.qZero80 = 0;
    p.nZero90 = 0;
    p.aTag[1] = (p.aTag[1] & ~0x80) | 0x80;
    p.aTag[7] = (p.aTag[7] & ~0xF0) | 0x10;
    p.aTag[8] = (p.aTag[8] & ~0xF) | 0xE;
    *(u_long128 *)p.aColor = *(u_long128 *)pColor;
    p.pTexEnv = m_unk0->GetTexEnv(nIndex);
    m_unk4->SetMaterials((tagGsMaterial *)&p, 1, false, false, 0, 0, 0);
}

// FUNCTION: 0x0020DBE0 InitTextures__19PMovieOverlayEngineFPii
int PMovieOverlayEngine::InitTextures(int *pData, int nCount) {
    m_unk0->UploadDynamicTexturesToVram(pData, nCount, m_unk90, 0x400000 - m_unk90, true);
    return 1;
}

// DRAFT: 0x0020DC10 Init__19PMovieOverlayEngineFsss
// note: 48 words differ; ours loads m_unk24 with lb (original lbu) and folds the |1 to ori (original keeps a bool 1 in a register); lui a2 precedes lui a0 for the assert literals (original reverses); tried a bool local for the flag and for KickVifDmaChain (48), unsigned char temp (no change).
int PMovieOverlayEngine::Init(short a, short b, short c) {
    sceGsSetDefDrawEnv((void *)&m_unk10, a, b, c, 1, 0x30);
    m_unk24 = (m_unk24 & ~1) | 1;
    m_unk0 = (PTextureManager *)(gGfxEng + 0x154C90);
    m_unk4 = (PDisplayList *)gGfxEng;
    m_unk4->Reset();
    m_unk4->m_unkA3348 = 2;
    m_unk4->SetVu1Microcode(vu_fx_microcode_dma_packet);
    m_unk4->KickVifDmaChain(true);
    if (a != 0) {
        CdsAssert__FPciPc("PMovieOverlayEngine.cpp", 0x2A, "sPixelFormat == SCE_GS_PSMCT32");
    }
    m_unk90 = (b * c) << 3;
    return 1;
}

// FUNCTION: 0x0020DD20 __dt__19PMovieOverlayEngineFv
extern "C" PMovieOverlayEngine *__dt__19PMovieOverlayEngineFv(PMovieOverlayEngine *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0020DD70 __ct__19PMovieOverlayEngineFv
PMovieOverlayEngine::PMovieOverlayEngine() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk90 = 0;
}
