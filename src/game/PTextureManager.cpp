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
extern "C" void memset(void *, int, unsigned int);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nSize);

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

// FUNCTION: 0x0018A990 DestroyRenderedTexture__15PTextureManagerFi
void PTextureManager::DestroyRenderedTexture(int nHandle) {
    bool bFlag;
    PTexture::eTextureType eType;
    int nIndex = -1;
    DecodeTextureHandle(nHandle, bFlag, eType, nIndex);
    if (!bFlag && nIndex >= 0 && eType == 2) {
        PTexture *p = 0;
        if ((unsigned int)nIndex < (unsigned int)m_nRenderedCount) {
            p = m_apRendered[nIndex];
        }
        if (p != 0) {
            delete p;
            if ((unsigned int)nIndex < (unsigned int)m_unk25C) {
                m_apRendered[nIndex] = 0;
            }
        }
    }
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

// FUNCTION: 0x0018AB10 UnloadDynamicTexture__15PTextureManagerFi
void PTextureManager::UnloadDynamicTexture(int nHandle) {
    bool bFlag;
    PTexture::eTextureType eType;
    int nIndex = -1;
    DecodeTextureHandle(nHandle, bFlag, eType, nIndex);
    if (!bFlag && nIndex >= 0 && eType == 1) {
        PTexture *p = 0;
        if ((unsigned int)nIndex < (unsigned int)m_nDynCount) {
            p = m_apDyn[nIndex];
        }
        if (p != 0) {
            delete p;
            if ((unsigned int)nIndex < (unsigned int)m_unk1E8) {
                m_apDyn[nIndex] = 0;
            }
        }
    }
}

// FUNCTION: 0x0018ABE0 UnloadAllDynamicTextures__15PTextureManagerFv
void PTextureManager::UnloadAllDynamicTextures() {
    int i = 0;
    int nCount = m_nDynCount;
    if (0 < nCount) {
        int nOff = 0;
        do {
            PTexture *p = 0;
            if ((unsigned int)i < (unsigned int)m_nDynCount) {
                p = *(PTexture **)((char *)m_apDyn + nOff);
            }
            if (p != 0) {
                delete p;
            }
            i++;
            nOff += 4;
        } while (i < nCount);
    }
    if (m_apDyn != 0) {
        m_nDynCount = 0;
        m_unk1E0 = 0;
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

// DRAFT: 0x0018B410 ResetDynamicBuffers__15PTextureManagerFv
// note: 41 lines differ: extra nop after each sb and loop tail offset by one slot; tried indexed for loops (40+), do-while with byte offset (41), p hoisted out of loops (41), nOff+=4 before i++ (41); kept the byte-offset do-while
void PTextureManager::ResetDynamicBuffers() {
    int i = 0;
    int nOff = 0;
    do {
        PTexture *p = *(PTexture **)((char *)this + nOff + 0x2C);
        if (p != 0) {
            p->m_unkA8 = 0;
        }
        i++;
        nOff += 4;
    } while (i < 0x30);
    i = 0;
    nOff = 0;
    do {
        PTexture *p = *(PTexture **)((char *)this + nOff + 0x108);
        if (p != 0) {
            p->m_unkA8 = 0;
        }
        i++;
        nOff += 4;
    } while (i < 0x30);
    memset(m_aBuf0.m_apTex, 0, 0xC0);
    memset(m_aBuf1.m_apTex, 0, 0xC0);
    m_aBuf0.m_unkD8 = 0;
    m_aBuf1.m_unkD8 = 0;
    m_aBuf0.m_unk8 = m_aBuf0.m_unk0;
    m_aBuf0.m_unk14 = m_aBuf0.m_unkC;
    m_aBuf1.m_unk8 = m_aBuf1.m_unk0;
    m_aBuf1.m_unk14 = m_aBuf1.m_unkC;
    m_pCurBuf = &m_aBuf0;
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

// DRAFT: 0x0018C720 __ct__15PTextureManagerFv
// note: 48 words differ: this spilled to 0x1C(sp) and frame is 0x20 vs 0x40 (only s0 kept, orig s0..s2); member-address and pointer-local variants both 48 words
PTextureManager::PTextureManager() {
    __ct__6PArrayFv(&m_nDynCount);
    __ct__6PArrayFv(&m_nRenderedCount);
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    memset(&m_aBuf0, 0, 0xDC);
    memset(&m_aBuf1, 0, 0xDC);
    m_pCurBuf = 0;
    m_unk1D0 = 0;
    m_unk1D4 = 0;
    m_unk1D8 = 0;
    m_unk0 = 0;
    Allocate__6PArrayFUi(&m_nDynCount, 0x180);
    Allocate__6PArrayFUi(&m_nRenderedCount, 0x40);
    m_unk260 = 1;
}
