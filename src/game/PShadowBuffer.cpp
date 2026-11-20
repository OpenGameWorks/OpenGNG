// FLAGS: -str readonly
#include "types.h"
#include "PShadowBuffer.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" void DestroyRenderedTexture__15PTextureManagerFi(void *pThis, int hTexture);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern char gGfxEng[1504384];

// FUNCTION: 0x001D8460 RemoveShadowVolume__13PShadowBufferFP13PShadowVolume
void PShadowBuffer::RemoveShadowVolume(PShadowVolume *pVolume) {
    int nIndex = Find__6PArrayFPv(this, pVolume);
    if (nIndex >= 0) {
        RemoveAt(nIndex);
    }
}

// FUNCTION: 0x001D84A0 AddShadowVolume__13PShadowBufferFP13PShadowVolume
void PShadowBuffer::AddShadowVolume(PShadowVolume *pVolume) {
    if (pVolume == 0) {
        CdsAssert__FPciPc("PShadowBuffer.cpp", 0x89, "poVolume");
    }
    if (Find__6PArrayFPv(this, pVolume) < 0) {
        if (m_unk0 >= 0x40U) {
            CdsAssert__FPciPc("PShadowBuffer.cpp", 0x8D, "moShadowVolumes.GetCount() < MAX_SHADOW_VOLUMES");
        }
        Add(pVolume);
    }
}

// FUNCTION: 0x001D85D0 Destroy__13PShadowBufferFv
void PShadowBuffer::Destroy() {
    if (m_unk34 != 0) {
        DestroyRenderedTexture__15PTextureManagerFi(gGfxEng, m_unk34);
        m_unk34 = 0;
    }
    if (m_unk8 != 0) {
        m_unk0 = 0;
        m_unk4 = 0;
    }
}

// DRAFT: 0x001D8830 __dt__13PShadowBufferFv
// note: 1 word differs: implicit base dtor call passes flag 0, original passes -1 (explicit __dt__6PArrayFv(this,-1) call gives 15 words)
PShadowBuffer::~PShadowBuffer() {
    Destroy();
}

// FUNCTION: 0x001D8890 __ct__13PShadowBufferFv
PShadowBuffer::PShadowBuffer() {
    memset(&_pad10, 0, 0x28);
    Allocate(0x40U);
}
