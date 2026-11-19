#include "types.h"
#include "PTextureManager.h"

// TODO(header): foreign declarations
extern "C" void FlushCache(int nMode);
extern "C" void sceDmaSend(int nChannel, void *pBuf);
extern "C" void DmaWaitForCompletion__Fib(int nChannel, bool bFlag);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memcpy(void *, const void *, unsigned int);

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

// DRAFT: 0x00189F80 FlipTextureBuffers__15PTextureManagerFv
// note: 27 lines differ: original keeps a nop in the bne delay slot where mine fills it, and the copy uses a3 in the original but a2 in mine; tried if-only form (36 lines), reversed compare (38), kept ternary (27)
void PTextureManager::FlipTextureBuffers() {
    m_pCurBuf = (m_pCurBuf == &m_aBuf0) ? &m_aBuf1 : &m_aBuf0;
    m_pCurBuf->m_unk8 = m_pCurBuf->m_unk0;
    m_pCurBuf->m_unk14 = m_pCurBuf->m_unkC;
    m_pCurBuf->m_unkD8 = 0;
    for (int i = 0; i < 0x30; i++) {
        if (m_aBuf0.m_apTex[i] != 0) {
            m_aBuf0.m_apTex[i]->m_unkA8 = 0;
        }
    }
    for (int i = 0; i < 0x30; i++) {
        if (m_aBuf1.m_apTex[i] != 0) {
            m_aBuf1.m_apTex[i]->m_unkA8 = 0;
        }
    }
}

// FUNCTION: 0x0018A850 __dt__8PTextureFv
PTexture::~PTexture() {
    if (m_unk34 != 0) {
        __dla__FPv(m_unk34);
        m_unk34 = 0;
    }
    if (m_unk30 != 0) {
        __dla__FPv(m_unk30);
        m_unk30 = 0;
    }
}

// DRAFT: 0x0018A8E0 InitRendered__8PTextureFP19tagPs2TexDataHeaderP23tagGsTextureEnvironment13eTextureGroup
// note: 24 lines differ: the 8-byte "pTexEnv" literal is gp-relative in mine but lui/addiu in the original, so the second assert block is one instruction short; literal placement is not controlled from source, no variant tried this session
int PTexture::InitRendered(tagPs2TexDataHeader *pTexHeader, tagGsTextureEnvironment *pTexEnv, eTextureGroup eGroup) {
    if (pTexHeader == 0) {
        CdsAssert__FPciPc("PTexture.h", 0x4D, "pTexHeader");
    }
    if (pTexEnv == 0) {
        CdsAssert__FPciPc("PTexture.h", 0x4E, "pTexEnv");
    }
    memcpy(m_unk4, pTexHeader, 0x2C);
    memcpy(m_unk40, pTexEnv, 0x60);
    m_unkA0 = eGroup;
    m_unkA4 = 2;
    return 1;
}

// DRAFT: 0x0018AA60 UnloadAllRenderedTextures__15PTextureManagerFv
// note: 32 words differ: frame 0x40 vs 0x50 (original keeps this in s3 and a byte-offset induction in s2, needing a 4th saved reg); tried while-loop, outer nCount>0 guard removed, 0<nCount guard (kept, 44->32 words), i declared outside for
void PTextureManager::UnloadAllRenderedTextures() {
    int nCount = m_nRenderedCount;
    if (0 < nCount) {
        for (int i = 0; i < nCount; i++) {
            PTexture *p = 0;
            if ((unsigned int)i < (unsigned int)m_nRenderedCount) {
                p = m_apRendered[i];
            }
            if (p != 0) {
                delete p;
            }
        }
    }
    if (m_apRendered != 0) {
        m_nRenderedCount = 0;
        m_unk254 = 0;
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

// FUNCTION: 0x0018C6B0 __dt__15PTextureManagerFv
PTextureManager::~PTextureManager() {
    Shutdown();
    __dt__6PArrayFv((char *)this + 0x250, -1);
    __dt__6PArrayFv((char *)this + 0x1DC, -1);
}
