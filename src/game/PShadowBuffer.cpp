// FLAGS: -str readonly
#include "types.h"
#include "PShadowBuffer.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" void DestroyRenderedTexture__15PTextureManagerFi(void *pThis, int hTexture);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern char gGfxEng[1504384];
extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;
extern unsigned char MODE_PAL;
extern "C" int AllocRenderedTexture__15PTextureManagerFiiRbb(void *pThis, int nWidth, int nHeight, bool *pFlag, bool bFlag);
extern "C" void SetVifCodes__12PDisplayListFUiUi(void *pThis, unsigned int nVif0, unsigned int nVif1);
extern "C" void NextBatch__16PTextureDmaChainFv(void *pThis);
extern "C" void SetTexSyncPacket__12PDisplayListFv(void *pThis);
extern "C" void SendGsPacket__12PDisplayListFPvib(void *pThis, void *pData, int nSize, int nFlag);
extern "C" void SetGsRegisters__12PDisplayListFP1i(void *pThis, void *pRegs, int nCount);
extern "C" int CreateRenderedTexture__15PTextureManagerFsssss13eTextureGroupb(void *pThis, short sA, short sB, short sC, short sD, short sE, int nGroup, bool bFlag);
extern "C" void GsSetFullScreenSprites__FP22tagGsFullScreenSpritesccccbbb(void *pSprites, char cA, char cB, char cC, char cD, bool bA, bool bB, bool bC);
extern "C" void Gs16BitShadowBufferSetup__FP27tagGs16BitShadowBufferSetupP21tagShadowVolumeBuffer(void *pSetup, void *pBuffer);
class PGfxEngine {
public:
    void BeginShadowRender();
    void EndShadowRender();
};
class PShadowVolume {
public:
    void Render(float *, float *, float *, float *, float *, float);
};

// DRAFT: 0x001D8110 BeginRender__13PShadowBufferFv
// note: compiles; PAL/non-PAL alloc paths and the 16-entry GS packet build are written, but the 64-bit packet ops and gGfxEng address order differ
void PShadowBuffer::BeginRender() {
    bool bRendered = false;
    *(int *)((char *)this + 0x28) = *(int *)(gGfxEng + 0x158DF0);
    if (MODE_PAL != 0) {
        gGfxEng[0x154EF0] = 0;
        *(int *)((char *)this + 0x14) = AllocRenderedTexture__15PTextureManagerFiiRbb(gGfxEng + 0x154C90, m_unk34, 0x2000, &bRendered, true);
        SetVifCodes__12PDisplayListFUiUi(*(void **)(gGfxEng + 0x154C80), 0x13000000U, 0x13000000U);
        gGfxEng[0x154EF0] = 1;
    } else {
        *(int *)((char *)this + 0x14) = AllocRenderedTexture__15PTextureManagerFiiRbb(gGfxEng + 0x154C90, m_unk34, 0x2000, &bRendered, true);
        if (bRendered) {
            NextBatch__16PTextureDmaChainFv((char *)*(void **)(gGfxEng + 0x154C80) + 0xA3380);
            SetTexSyncPacket__12PDisplayListFv(*(void **)(gGfxEng + 0x154C80));
        }
    }
    int nPages = *(int *)((char *)this + 0x14);
    int nPageA = nPages >> 13;
    if (nPages < 0) {
        nPageA = (nPages + 0x1FFF) >> 13;
    }
    *(long long *)((char *)this + 0x80) = (long long)nPageA | ((long long)*(short *)((char *)this + 0x30) << 24);
    SendGsPacket__12PDisplayListFPvib(*(void **)(gGfxEng + 0x154C80), (char *)this + 0x40, 0x6F0, 1);

    long long pkt[16];
    int nPagesB = *(int *)((char *)this + 0x14);
    int nPageB = nPagesB >> 13;
    if (nPagesB < 0) {
        nPageB = (nPagesB + 0x1FFF) >> 13;
    }
    pkt[0] = ((long long)*(short *)((char *)this + 0x30) << 24)
           | (long long)nPageB
           | ((long long)((*(int *)((char *)this + 0x18) + 0x3F) >> 6) << 16)
           | (long long)0xFF00000000000000ULL;
    pkt[1] = 0x4C;

    int nPagesC = *(int *)((char *)this + 0x2C);
    int nPageC = nPagesC >> 13;
    if (nPagesC < 0) {
        nPageC = (nPagesC + 0x1FFF) >> 13;
    }
    pkt[2] = (long long)nPageC
           | ((long long)*(short *)((char *)this + 0x32) << 24)
           | (1LL << 32);
    pkt[3] = 0x4E;
    pkt[4] = 0x68LL | (0x80LL << 32);
    pkt[5] = 0x42;
    pkt[6] = 0x71001LL;
    pkt[7] = 0x47;
    pkt[8] = 0;
    pkt[9] = 0x46;
    pkt[10] = 1;
    pkt[11] = 0x1A;
    pkt[12] = 0x40;
    pkt[13] = 0x1B;
    pkt[14] = 0;
    pkt[15] = 0x3F;
    SetGsRegisters__12PDisplayListFP1i(*(void **)(gGfxEng + 0x154C80), pkt, 8);
}

// FUNCTION: 0x001D8390 Render__13PShadowBufferFv
void PShadowBuffer::Render() {
    ((PGfxEngine *)gGfxEng)->BeginShadowRender();
    BeginRender();
    m_unk4 = 0;
    PShadowVolume *pVolume = (m_unk0 != 0) ? (PShadowVolume *)m_unk8[0] : 0;
    while (pVolume != 0) {
        pVolume->Render(m_unk1AB0, m_unk1AC0, m_unk1AD0, m_unk1AE0, m_unk1AF0, *(float *)((char *)this + 0x10));
        pVolume = (++m_unk4 < m_unk0) ? (PShadowVolume *)m_unk8[m_unk4] : 0;
    }
    EndRender();
    ((PGfxEngine *)gGfxEng)->EndShadowRender();
}

// DRAFT: 0x001D8530 SetZBufferRange__13PShadowBufferFff
// note: 24 words differ; original keeps the halved width in f1 and stores it second, and the lui order for 0x4500/0x4380/0x3F00 and gp loads differ (width-first, height-first, int locals, direct stores tried)
void PShadowBuffer::SetZBufferRange(float fNear, float fFar) {
    int nWidth = SCREEN_WIDTH / 2;
    int nHeight = SCREEN_HEIGHT / 2;
    m_unk1AC0[0] = (float)nWidth;
    m_unk1AC0[1] = (float)nHeight;
    m_unk1AC0[2] = -(0.5f * (fFar - fNear));
    *(int *)&m_unk1AC0[3] = 0;
    *(int *)&m_unk1AD0[0] = 0x45000000;
    *(int *)&m_unk1AD0[1] = 0x45000000;
    m_unk1AD0[2] = 0.5f * (fFar + fNear);
    *(int *)&m_unk1AD0[3] = 0;
    m_unk1AD0[2] += 256.0f;
    *(int *)&m_unk1AD0[3] = 0xBF800000;
}

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
        DestroyRenderedTexture__15PTextureManagerFi(gGfxEng + 0x154C90, m_unk34);
        m_unk34 = 0;
    }
    if (m_unk8 != 0) {
        m_unk0 = 0;
        m_unk4 = 0;
    }
}

// DRAFT: 0x001D8620 Create__13PShadowBufferFiiiisf
// note: 130 words differ, size 0x208 vs 0x20c; original keeps all six args in s0-s6 across the Destroy call (frame 0x80), ours reuses s3 for this (frame 0x70). Call arguments now match the asm.
bool PShadowBuffer::Create(int nArg0, int nArg1, int nArg2, int nArg3, short sArg4, float fArg5) {
    Destroy();
    *(float *)((char *)this + 0x10) = fArg5;
    *(int *)((char *)this + 0x14) = 0;
    *(int *)((char *)this + 0x18) = nArg0;
    *(int *)((char *)this + 0x1C) = nArg1;
    *(int *)((char *)this + 0x20) = nArg2;
    *(int *)((char *)this + 0x24) = nArg3;
    *(int *)((char *)this + 0x28) = 0;
    *(int *)((char *)this + 0x2C) = *(int *)(gGfxEng + 0x158E04) << 13;
    *(short *)((char *)this + 0x30) = sArg4;
    *(short *)((char *)this + 0x32) = *(short *)(gGfxEng + 0x158E02);
    GsSetFullScreenSprites__FP22tagGsFullScreenSpritesccccbbb((char *)this + 0x730, 0, 0, 0, 0, true, false, false);
    GsSetFullScreenSprites__FP22tagGsFullScreenSpritesccccbbb((char *)this + 0xDB0, 0, 0, 0, 0, false, true, false);
    Gs16BitShadowBufferSetup__FP27tagGs16BitShadowBufferSetupP21tagShadowVolumeBuffer((char *)this + 0x40, (char *)this + 0x10);
    GsSetFullScreenSprites__FP22tagGsFullScreenSpritesccccbbb((char *)this + 0x1430, 0, 0, 0, -128, false, false, false);
    *(int *)&m_unk1AB0[0] = 0;
    *(int *)&m_unk1AB0[1] = 0x3F800000;
    *(int *)&m_unk1AB0[2] = 0;
    SetZBufferRange(128.0f, 16777216.0f);
    *(int *)&m_unk1AB0[3] = 0x3F800000;
    if (sArg4 == 0xA) {
        *(int *)&m_unk1AF0[2] = 8;
        *(int *)&m_unk1AF0[1] = 8;
        *(int *)&m_unk1AF0[0] = 8;
        *(int *)&m_unk1AE0[2] = 0xF8;
        *(int *)&m_unk1AE0[1] = 0xF8;
        *(int *)&m_unk1AE0[0] = 0xF8;
    } else if (sArg4 == 1) {
        *(int *)&m_unk1AF0[2] = 1;
        *(int *)&m_unk1AF0[1] = 1;
        *(int *)&m_unk1AF0[0] = 1;
        *(int *)&m_unk1AE0[2] = 0xFF;
        *(int *)&m_unk1AE0[1] = 0xFF;
        *(int *)&m_unk1AE0[0] = 0xFF;
    }
    *(int *)&m_unk1AF0[3] = 0;
    *(int *)&m_unk1AE0[3] = 0xBF800000;
    m_unk34 = CreateRenderedTexture__15PTextureManagerFsssss13eTextureGroupb(gGfxEng + 0x154C90, (short)nArg0, (short)nArg1, (short)nArg2, (short)nArg3, sArg4, 0x6B, true);
    return m_unk34 > 0;
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
