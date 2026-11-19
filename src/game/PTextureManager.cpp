#include "types.h"
#include "PTextureManager.h"

// TODO(header): foreign declarations
extern "C" void FlushCache(int nMode);
extern "C" void sceDmaSend(int nChannel, void *pBuf);
extern "C" void DmaWaitForCompletion__Fib(int nChannel, bool bFlag);
extern "C" void __dla__FPv(void *pMem);

// DRAFT: 0x001894D0 DecodeTextureHandle__15PTextureManagerFiRbRQ28PTexture12eTextureTypeRi
// note: 2 lines differ: original shifts a1 directly (dsll32 8/dsrl32 8), mine zero-extends nHandle first (dsll32 0/dsrl32 0); tried signed (long long) intermediate, unsigned int store cast, 64-bit local
void PTextureManager::DecodeTextureHandle(int nHandle, bool &bFlag, PTexture::eTextureType &eType, int &nIndex) {
    bFlag = (((unsigned int)nHandle & 0x80000000) >> 31) != 0;
    eType = (PTexture::eTextureType)((nHandle & 0x7F000000) >> 24);
    nIndex = (int)(((unsigned long long)nHandle << 40) >> 40);
}

// DRAFT: 0x00189510 EncodeTextureHandle__15PTextureManagerFbQ28PTexture12eTextureTypei
// note: 2 lines differ: original shifts a3 directly (dsll32 8/dsrl32 8), mine zero-extends nIndex first (dsll32 0/dsrl32 0); tried signed (long long) intermediate and an unsigned int cast
int PTextureManager::EncodeTextureHandle(bool bFlag, PTexture::eTextureType eType, int nIndex) {
    return (int)((((bFlag & 0xFF) << 31) | (eType << 24)) | (((unsigned long long)nIndex << 40) >> 40));
}

// FUNCTION: 0x00189530 KickDmaChain__15PTextureManagerFPvb
void PTextureManager::KickDmaChain(void *pBuf, bool bWait) {
    FlushCache(0);
    sceDmaSend(m_unk0, pBuf);
    if (bWait) {
        DmaWaitForCompletion__Fib(2, 0);
    }
}

// FUNCTION: 0x0018AFE0 UnloadStaticTextures__15PTextureManagerFv
void PTextureManager::UnloadStaticTextures() {
    if (m_unk1D0 != 0) {
        __dla__FPv(m_unk1D0);
        m_unk1D0 = 0;
    }
    m_unk1D4 = 0;
    m_unk10 = 0;
    m_unk1D8 = 0;
}

// FUNCTION: 0x0018C4E0 Shutdown__15PTextureManagerFv
void PTextureManager::Shutdown() {
    UnloadStaticTextures();
    UnloadAllDynamicTextures();
    UnloadAllRenderedTextures();
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk0 = 0;
}
