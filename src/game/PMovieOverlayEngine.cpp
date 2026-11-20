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
    char _padA0000[0xA3348];
    int m_unkA3348;             // 0xA3348
};

extern "C" void sceGsSetDefDrawEnv(void *pEnv, short nPsm, short nW, short nH, int nA, int nB);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);
extern char gGfxEng[1504384];
extern char vu_fx_microcode_dma_packet[];

// DRAFT: 0x0020DA20 BeginRender__19PMovieOverlayEngineFUi
// note: 3 words differ: mask -0x200 and flag 0x1FF swap v0/v1; tried swapped operands (4 words), explicit 0xFFFFFE00 (4), hoisted flag temp (4), mask temp (3).
void PMovieOverlayEngine::BeginRender(unsigned int nFlags) {
    unsigned int nOld = m_unk10;
    m_unk10 = (nFlags & 0x1FF) | (nOld & ~0x1FF);
    m_unk4->SetGsRegisters((u_long128 *)&m_unk10, 8);
}

// DRAFT: 0x0020DA90 SetMaterial__19PMovieOverlayEngineFiPfbUlUl
// note: frame is 0xC0 vs original 0x60; the GS packet layout (quadword stores, byte edits) is a guess and does not match.
void PMovieOverlayEngine::SetMaterial(int nIndex, float *pColor, bool bFlag, unsigned long nA, unsigned long nB) {
    unsigned char aMat[0x40];
    unsigned long long *pQ = (unsigned long long *)aMat;
    pQ[0] = 0x42;
    pQ[1] = 0x47;
    pQ[2] = 0x1A;
    pQ[3] = 0;
    pQ[4] = 0x1B;
    pQ[5] = ((nIndex != 0) * 0x10) | 8 | ((bFlag & 0xFF) << 6);
    *(unsigned long long *)&aMat[0x30] = 0;
    aMat[0x31] = (aMat[0x31] & ~0x80) | 0x80;
    aMat[0x37] = (aMat[0x37] & ~0xF0) | 0x10;
    aMat[0x38] = (aMat[0x38] & ~0xF) | 0xE;
    m_unk0->GetTexEnv(nIndex);
    m_unk4->SetMaterials((tagGsMaterial *)aMat, 1, false, false, 0, 0, 0);
}

// FUNCTION: 0x0020DBE0 InitTextures__19PMovieOverlayEngineFPii
int PMovieOverlayEngine::InitTextures(int *pData, int nCount) {
    m_unk0->UploadDynamicTexturesToVram(pData, nCount, m_unk90, 0x400000 - m_unk90, true);
    return 1;
}

// DRAFT: 0x0020DC10 Init__19PMovieOverlayEngineFsss
// note: 48 words differ; the original keeps constant 1 in a1 shared with the KickVifDmaChain call, ours reloads it; m_unk24 flag ordering not yet matched; unsigned char temp for m_unk24 made no difference.
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
