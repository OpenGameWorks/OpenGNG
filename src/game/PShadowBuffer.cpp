// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PShadowBuffer.h"

// TODO(header): foreign declarations
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

// DRAFT: 0x001D7C90 EndRender__13PShadowBufferFv
// note: frame 0x160 and s0..s7 match; this copy lands in s0 not s4, packet pointer CSE and store order differ (270 words). Tried: 0x170 fp frame (272), char *self base (270).
void PShadowBuffer::EndRender() {
    long long pkt[26];
    char *self = (char *)this;
    int nVar;
    int nTemp;

    nVar = *(int *)(self + 0x28);
    nTemp = nVar >> 13;
    if (nVar < 0) {
        nTemp = (nVar + 0x1FFF) >> 13;
    }
    pkt[0] = (long long)nTemp
           | ((long long)((*(int *)(self + 0x18) + 0x3F) >> 6) << 16)
           | (0xFFFFFFLL << 32);
    pkt[1] = 0x4C;
    pkt[2] = 0x31001;
    pkt[3] = 0x47;
    SetGsRegisters__12PDisplayListFP1i(*(void **)(gGfxEng + 0x154C80), pkt, 2);
    SendGsPacket__12PDisplayListFPvib(*(void **)(gGfxEng + 0x154C80), self + 0x1430, 0x680, 1);

    int nFloat = (int)*(float *)(self + 0x10);
    int nY = *(int *)(self + 0x14);
    int nYa = (nY < 0) ? ((nY + 0xFF) >> 8) : (nY >> 8);
    pkt[0] = ((long long)*(int *)(self + 0x24) << 30)
           | ((long long)*(int *)(self + 0x20) << 26)
           | ((long long)*(short *)(self + 0x30) << 20)
           | (long long)nYa
           | ((long long)(*(int *)(self + 0x18) >> 6) << 14)
           | (0xCLL << 32);
    pkt[1] = 6;
    pkt[2] = 0;
    pkt[3] = 0x14;
    pkt[4] = (long long)nFloat | 0x8000;
    pkt[5] = 0x3B;
    pkt[6] = ((long long)nFloat << 4) | 0x30009;
    pkt[7] = 0x47;
    nVar = *(int *)(self + 0x28);
    nTemp = nVar >> 13;
    if (nVar < 0) {
        nTemp = (nVar + 0x1FFF) >> 13;
    }
    pkt[8] = (long long)nTemp
           | ((long long)((*(int *)(self + 0x18) + 0x3F) >> 6) << 16)
           | (0xFFFFFFLL << 32);
    pkt[9] = 0x4C;
    pkt[10] = ((0x800LL - (long long)(*(int *)(self + 0x18) >> 1)) << 4)
            | ((0x800LL - (long long)(*(int *)(self + 0x1C) >> 1)) << 36);
    pkt[11] = 0x18;
    pkt[12] = 0;
    pkt[13] = 0x3F;
    pkt[14] = 1;
    pkt[15] = 0x46;
    SetGsRegisters__12PDisplayListFP1i(*(void **)(gGfxEng + 0x154C80), pkt, 8);
    SendGsPacket__12PDisplayListFPvib(*(void **)(gGfxEng + 0x154C80), self + 0x730, 0x680, 1);

    nVar = *(int *)(self + 0x28);
    nTemp = nVar >> 13;
    if (nVar < 0) {
        nTemp = (nVar + 0x1FFF) >> 13;
    }
    pkt[0] = (long long)nTemp
           | ((long long)((*(int *)(self + 0x18) + 0x3F) >> 6) << 16);
    pkt[1] = 0x4C;
    pkt[2] = 0x30000;
    pkt[3] = 0x47;
    pkt[4] = 0x99;
    pkt[5] = 0x42;
    pkt[6] = 0;
    pkt[7] = 0x3F;
    SetGsRegisters__12PDisplayListFP1i(*(void **)(gGfxEng + 0x154C80), pkt, 4);
    SendGsPacket__12PDisplayListFPvib(*(void **)(gGfxEng + 0x154C80), self + 0xDB0, 0x680, 1);

    pkt[16] = 0;
    pkt[17] = 0x1A;
    pkt[18] = 0x18;
    pkt[19] = 0x1B;
    if (*(int *)(gGfxEng + 0x158DE0) & 1) {
        pkt[20] = *(long long *)(gGfxEng + 0x158C30);
    } else {
        pkt[20] = *(long long *)(gGfxEng + 0x158D20);
    }
    pkt[21] = 0x18;
    nVar = *(int *)(self + 0x2C);
    nTemp = nVar >> 13;
    if (nVar < 0) {
        nTemp = (nVar + 0x1FFF) >> 13;
    }
    pkt[22] = (long long)nTemp | ((long long)*(short *)(self + 0x32) << 24);
    pkt[23] = 0x4E;
    pkt[24] = (0x80LL << 32) | 0x8080;
    pkt[25] = 0x3B;
    SetGsRegisters__12PDisplayListFP1i(*(void **)(gGfxEng + 0x154C80), &pkt[16], 5);

    if (MODE_PAL != 0) {
        NextBatch__16PTextureDmaChainFv((char *)*(void **)(gGfxEng + 0x154C80) + 0xA3380);
        SetTexSyncPacket__12PDisplayListFv(*(void **)(gGfxEng + 0x154C80));
        NextBatch__16PTextureDmaChainFv((char *)*(void **)(gGfxEng + 0x154C80) + 0xA3380);
        SetTexSyncPacket__12PDisplayListFv(*(void **)(gGfxEng + 0x154C80));
    }
}

// DRAFT: 0x001D8110 BeginRender__13PShadowBufferFv
// note: 82 words. Self base, runtime gGfxEng store on the first write and nPageA before nPages helped. Still differs: the original batches the constant pkt[] stack stores at the end (ours interleaves them), and the register choice for the pkt[0] short and nPageB terms. Tried: pkt[0] operand reorder, hoisted short (83).
void PShadowBuffer::BeginRender() {
    char *self = (char *)this;
    *(int *)(self + 0x28) = *(int *)(gGfxEng + 0x158DF0);
    bool bRendered = false;
    if (MODE_PAL != 0) {
        *(char *)((int)gGfxEng + 0x154EF0) = 0;
        *(int *)(self + 0x14) = AllocRenderedTexture__15PTextureManagerFiiRbb(gGfxEng + 0x154C90, m_unk34, 0x2000, &bRendered, true);
        SetVifCodes__12PDisplayListFUiUi(*(void **)(gGfxEng + 0x154C80), 0x13000000U, 0x13000000U);
        gGfxEng[0x154EF0] = 1;
    } else {
        *(int *)(self + 0x14) = AllocRenderedTexture__15PTextureManagerFiiRbb(gGfxEng + 0x154C90, m_unk34, 0x2000, &bRendered, true);
        if (bRendered) {
            NextBatch__16PTextureDmaChainFv((char *)*(void **)(gGfxEng + 0x154C80) + 0xA3380);
            SetTexSyncPacket__12PDisplayListFv(*(void **)(gGfxEng + 0x154C80));
        }
    }
    int nPageA;
    int nPages = *(int *)(self + 0x14);
    nPageA = nPages >> 13;
    if (nPages < 0) {
        nPageA = (nPages + 0x1FFF) >> 13;
    }
    *(long long *)(self + 0x80) = (long long)nPageA | ((long long)*(short *)(self + 0x30) << 24);
    SendGsPacket__12PDisplayListFPvib(*(void **)(gGfxEng + 0x154C80), self + 0x40, 0x6F0, 1);

    long long pkt[16];
    int nPagesB = *(int *)(self + 0x14);
    int nPageB = nPagesB >> 13;
    if (nPagesB < 0) {
        nPageB = (nPagesB + 0x1FFF) >> 13;
    }
    pkt[0] = (long long)nPageB
           | ((long long)*(short *)(self + 0x30) << 24)
           | ((long long)((*(int *)(self + 0x18) + 0x3F) >> 6) << 16)
           | (long long)0xFF00000000000000ULL;
    pkt[1] = 0x4C;

    int nPagesC = *(int *)(self + 0x2C);
    int nPageC = nPagesC >> 13;
    if (nPagesC < 0) {
        nPageC = (nPagesC + 0x1FFF) >> 13;
    }
    pkt[2] = (long long)nPageC
           | ((long long)*(short *)(self + 0x32) << 24)
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
    m_array.m_unk4 = 0;
    PShadowVolume *pVolume = (m_array.m_unk0 != 0) ? (PShadowVolume *)m_array.m_unk8[0] : 0;
    while (pVolume != 0) {
        pVolume->Render(m_unk1AB0, m_unk1AC0, m_unk1AD0, m_unk1AE0, m_unk1AF0, *(float *)((char *)this + 0x10));
        pVolume = (++m_array.m_unk4 < m_array.m_unk0) ? (PShadowVolume *)m_array.m_unk8[m_array.m_unk4] : 0;
    }
    EndRender();
    ((PGfxEngine *)gGfxEng)->EndShadowRender();
}

// FUNCTION: 0x001D8530 SetZBufferRange__13PShadowBufferFff
void PShadowBuffer::SetZBufferRange(float fNear, float fFar) {
    float fH = (float)(SCREEN_HEIGHT / 2);
    m_unk1AC0[0] = (float)(SCREEN_WIDTH / 2);
    m_unk1AC0[1] = fH;
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
    int nIndex = Find__6PArrayFPv(&m_array, pVolume);
    if (nIndex >= 0) {
        m_array.RemoveAt(nIndex);
    }
}

// FUNCTION: 0x001D84A0 AddShadowVolume__13PShadowBufferFP13PShadowVolume
void PShadowBuffer::AddShadowVolume(PShadowVolume *pVolume) {
    if (pVolume == 0) {
        CdsAssert("PShadowBuffer.cpp", 0x89, "poVolume");
    }
    if (Find__6PArrayFPv(&m_array, pVolume) < 0) {
        if (m_array.m_unk0 >= 0x40U) {
            CdsAssert("PShadowBuffer.cpp", 0x8D, "moShadowVolumes.GetCount() < MAX_SHADOW_VOLUMES");
        }
        m_array.Add(pVolume);
    }
}

// FUNCTION: 0x001D85D0 Destroy__13PShadowBufferFv
void PShadowBuffer::Destroy() {
    if (m_unk34 != 0) {
        DestroyRenderedTexture__15PTextureManagerFi(gGfxEng + 0x154C90, m_unk34);
        m_unk34 = 0;
    }
    if (m_array.m_unk8 != 0) {
        m_array.m_unk0 = 0;
        m_array.m_unk4 = 0;
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

// FUNCTION: 0x001D8830 __dt__13PShadowBufferFv
PShadowBuffer::~PShadowBuffer() {
    Destroy();
}

// FUNCTION: 0x001D8890 __ct__13PShadowBufferFv
PShadowBuffer::PShadowBuffer() {
    memset(&_pad10, 0, 0x28);
    m_array.Allocate(0x40U);
}
