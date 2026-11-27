// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PParticleTexture.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void __dl__FPv(void *pBlock);
extern "C" void *GetTexEnv__15PTextureManagerFi(void *pThis, int nHandle);
extern "C" int GsGetTexByteAddr__FP23tagGsTextureEnvironment(void *pEnv);
extern "C" int GsInitClearPacket__FP17tagGsClearSpritesiiccccb(void *pPacket, int nW, int nH, char c0, char c1, char c2, char c3, bool bFlag);
extern "C" int GsCreateMoveRG2BAPacket__FiiiiiRi(int a0, int a1, int a2, int a3, int a4, int *pOut);
extern "C" void GsSetTCC__FP23tagGsTextureEnvironmentb(void *pEnv, bool bFlag);
extern "C" void MakeViewMatrix__5PMat4FPfPfPf(void *pThis, float *pEye, float *pView, float *pUp);
extern "C" void MakeScreenMatrix__5PMat4Ffffffffff(void *pThis, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8);
extern "C" void BeginFxRender__10PGfxEngineFv(void *pThis);
extern "C" void EndFxRender__10PGfxEngineFv(void *pThis);
extern "C" void SetGsRegisters__12PDisplayListFP1i(void *pThis, u_long128 *pRegs, int nCount);
extern "C" void SendGsPacket__12PDisplayListFPvib(void *pThis, void *pPacket, int nSize, bool bFlag);
extern "C" void SetClipMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMatrix);
extern "C" void SetScreenMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMatrix);
extern "C" void SetViewMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMatrix);
extern char gGfxEng[1504384];

// Virtual numbers follow PParticleSystem's vtable: Start is slot 0x20, virtual number 6.
class PParticleSystemView {
public:
    virtual ~PParticleSystemView();
    virtual void Slot1(float fStep);
    virtual void Render();
    virtual void ModifyPosition(void *pMatrix);
    virtual void FrustrumTest(void *pFrustrum, float fA, float fB, float fC);
    virtual void FadeAndDie(unsigned int nFlags);
    virtual void Start();
};

// DRAFT: 0x001EFA70 InitGsRegs__16PParticleTextureFib
// note: stores and asserts follow the asm; bit-field expression shapes not yet matched.
void PParticleTexture::InitGsRegs(int nIndex, bool bFlag) {
    if (nIndex == 0) {
        CdsAssert("PParticleTexture.cpp", 0xD6, "hTargetTexture");
    }
    int nHandle = *(int *)(gGfxEng + 0x16D408);
    char *pEnv = (char *)GetTexEnv__15PTextureManagerFi(gGfxEng + 0x154C90, nHandle ? nHandle : nIndex);
    if (pEnv == 0) {
        CdsAssert("PParticleTexture.cpp", 0xDA, "apTargetTexEnv");
    }
    int nAddr = GsGetTexByteAddr__FP23tagGsTextureEnvironment(pEnv);
    long long nQ = *(long long *)(pEnv + 0x30);
    int nS1 = 1 << ((unsigned long long)((long long)*(unsigned char *)(pEnv + 0x33) << 58) >> 60);
    int nS2 = 1 << ((unsigned long long)(nQ << 30) >> 60);
    int nV = nAddr >> 13;
    if (nAddr < 0) {
        nV = (nAddr + 0x1FFF) >> 13;
    }
    *(long long *)(m_unk10 + 0x0) = (((unsigned long long)((long long)*(unsigned short *)(pEnv + 0x32) << 0x36) >> 0x3A) << 0x18)
        | ((long long)nV) | ((((unsigned long long)(nQ << 0x2C)) >> 0x3A) << 0x10);
    *(long long *)(m_unk10 + 0x8) = 0x4C;
    *(long long *)(m_unk10 + 0x10) = ((long long)(0x800 - (nS1 >> 1)) * 0x10) | (((long long)(0x800 - (nS2 >> 1)) * 0x10) << 0x20);
    *(long long *)(m_unk10 + 0x18) = 0x18;
    *(long long *)(m_unk10 + 0x20) = ((long long)(nS1 - 1) << 0x10) | ((long long)(nS2 - 1) << 0x30);
    *(long long *)(m_unk10 + 0x28) = 0x40;
    int nX = *(int *)(gGfxEng + 0x158E04);
    long long nSat = (long long)((nX << 13) >> 13);
    if (nX & 0x40000) {
        nSat = (long long)((nX << 13) + 0x1FFF) >> 13;
    }
    *(long long *)(m_unk10 + 0x30) = ((long long)(int)nSat) | ((long long)*(short *)(gGfxEng + 0x158E02) << 0x18) | (1LL << 0x20);
    *(long long *)(m_unk10 + 0x38) = 0x4E;
    *(long long *)(m_unk10 + 0x40) = bFlag ? 0 : 1;
    *(long long *)(m_unk10 + 0x48) = 0x4A;
    m_unk4C0 = GsInitClearPacket__FP17tagGsClearSpritesiiccccb(_pad60, nS1, nS2, 0, 0, 0, 0, 0);
    if (bFlag) {
        m_unk4C4 = (void *)GsCreateMoveRG2BAPacket__FiiiiiRi(nAddr, nS1, nS2,
            (int)((unsigned long long)((long long)*(unsigned char *)(pEnv + 0x33) << 0x3A) >> 0x3C),
            (int)((unsigned long long)(*(long long *)(pEnv + 0x30) << 0x1E) >> 0x3C),
            (int *)_pad4C8);
    }
}

// FUNCTION: 0x001EFCE0 Reset__16PParticleTextureFv
void PParticleTexture::Reset() {
    m_unk0 = 0;
    m_unk550 = 0;
    m_unk554 = 0;
    memset(m_unk10, 0, 0x50);
    m_unk4C0 = 0;
    if (m_unk4C4 != 0) {
        __dla__FPv(m_unk4C4);
        m_unk4C4 = 0;
    }
}

// DRAFT: 0x001EFD40 Update__16PParticleTextureFf
// note: DIFF 180 words; only 18 of 198 words match. MWCC hoists the BeginFxRender `lui a0` into the first bnez delay slot (original keeps a nop there). Tried: runtime gGfxEng+0x154C80 for the first SetGsRegisters (197, worse); goto body with one or two early-return branches (180, size 0x2F4 vs 0x318); plain early return (180). aPacket table copy (original ld/sd through t2..t7) not matched.
void PParticleTexture::Update(float fStep) {
    PParticleMatrix sp50;
    PParticleMatrix sp90;
    long long aPacket[12];
    void *pEnv0 = 0;
    void *pEnv1 = 0;

    if (m_unk0 == 0) {
        return;
    }
    if (m_unk550 != 0 || m_unk554 != 0) {
        BeginFxRender__10PGfxEngineFv(gGfxEng);
        SetGsRegisters__12PDisplayListFP1i(*(void **)(gGfxEng + 0x154C80), (u_long128 *)m_unk10, 5);
        SendGsPacket__12PDisplayListFPvib(*(void **)(gGfxEng + 0x154C80), _pad60, m_unk4C0, true);
        sceVu0CopyMatrix((float (*)[4])&sp50, (float (*)[4])(gGfxEng + 0x16D380));
        sceVu0CopyMatrix((float (*)[4])&sp90, (float (*)[4])(gGfxEng + 0x16D3C0));
        SetScreenMatrix__10PGfxEngineFP5PMat4(gGfxEng, &m_unk510);
        SetViewMatrix__10PGfxEngineFP5PMat4(gGfxEng, &m_unk4D0);
        SetClipMatrix__10PGfxEngineFP5PMat4(gGfxEng, (char *)((int)gGfxEng + 0x16D340));
        if (m_unk550 != 0) {
            ((PParticleSystemView *)m_unk550)->Slot1(fStep);
            int nHandle = *(int *)(gGfxEng + 0x16D408);
            pEnv0 = GetTexEnv__15PTextureManagerFi(gGfxEng + 0x154C90, nHandle ? nHandle : *(int *)((char *)m_unk550 + 0x10));
            GsSetTCC__FP23tagGsTextureEnvironmentb(pEnv0, false);
            ((PParticleSystemView *)m_unk550)->Render();
        }
        if (m_unk554 != 0) {
            ((PParticleSystemView *)m_unk554)->Slot1(fStep);
            int nHandle = *(int *)(gGfxEng + 0x16D408);
            pEnv1 = GetTexEnv__15PTextureManagerFi(gGfxEng + 0x154C90, nHandle ? nHandle : *(int *)((char *)m_unk554 + 0x10));
            GsSetTCC__FP23tagGsTextureEnvironmentb(pEnv1, false);
            ((PParticleSystemView *)m_unk554)->Render();
        }
        if (m_unk4C4 != 0) {
            SendGsPacket__12PDisplayListFPvib(*(void **)(gGfxEng + 0x154C80), m_unk4C4, *(int *)_pad4C8, false);
        }
        {
            char *pTable;
            if (*(int *)(gGfxEng + 0x158DE0) & 1) {
                pTable = gGfxEng + 0x158C10;
            } else {
                pTable = gGfxEng + 0x158D00;
            }
            aPacket[0] = 1;
            aPacket[1] = 0x3F;
            aPacket[2] = *(long long *)(pTable + 0x0);
            aPacket[3] = 0x4C;
            aPacket[4] = *(long long *)(pTable + 0x20);
            aPacket[5] = 0x18;
            aPacket[6] = *(long long *)(pTable + 0x30);
            aPacket[7] = 0x40;
            aPacket[8] = *(long long *)(pTable + 0x10);
            aPacket[9] = 0x4E;
            aPacket[10] = 0;
            aPacket[11] = 0x4A;
        }
        SetGsRegisters__12PDisplayListFP1i(*(void **)(gGfxEng + 0x154C80), (u_long128 *)aPacket, 6);
        EndFxRender__10PGfxEngineFv(gGfxEng);
        SetScreenMatrix__10PGfxEngineFP5PMat4(gGfxEng, &sp90);
        SetViewMatrix__10PGfxEngineFP5PMat4(gGfxEng, &sp50);
        SetClipMatrix__10PGfxEngineFP5PMat4(gGfxEng, gGfxEng + 0x16D340);
        if (pEnv0 != 0) {
            GsSetTCC__FP23tagGsTextureEnvironmentb(pEnv0, true);
        }
        if (pEnv1 != 0) {
            GsSetTCC__FP23tagGsTextureEnvironmentb(pEnv1, true);
        }
    }
}

// DRAFT: 0x001F0060 Init__16PParticleTextureFiP15PParticleSystemP15PParticleSystemb
// note: 15 words differ. Tried: ternary scale (76), if/else scale (59), switch ascending (23), switch descending (15). Left: MakeScreenMatrix float-constant load order near 0x1E8 and the return-0 branch target at 0x28 (0x78 vs 0x77).
int PParticleTexture::Init(int nIndex, PParticleSystem *pSystemA, PParticleSystem *pSystemB, bool bFlag) {
    if (nIndex == 0 || (pSystemA == 0 && pSystemB == 0)) {
        return 0;
    }
    m_unk0 = nIndex;
    m_unk550 = pSystemA;
    m_unk554 = pSystemB;
    m_unk558 = bFlag;
    if (m_unk550 != 0) {
        ((PParticleSystemView *)m_unk550)->Start();
    }
    if (m_unk554 != 0) {
        ((PParticleSystemView *)m_unk554)->Start();
    }
    InitGsRegs(m_unk0, m_unk558);
    int nHandle = *(int *)(gGfxEng + 0x16D408);
    int nTexIndex = m_unk0;
    char *pEnv = (char *)GetTexEnv__15PTextureManagerFi(gGfxEng + 0x154C90, nHandle ? nHandle : nTexIndex);
    if (pEnv == 0) {
        CdsAssert("PParticleTexture.cpp", 50, "apTexEnv");
    }
    if (!m_unk558) {
        GsSetTCC__FP23tagGsTextureEnvironmentb(pEnv, false);
    }
    int nSize = 1 << ((unsigned long long)((long long)*(unsigned char *)(pEnv + 0x33) << 58) >> 60);
    float fScale = 0.0f;
    switch (nSize) {
    case 0x200:
        fScale = -7.0f;
        break;
    case 0x100:
        fScale = -13.25f;
        break;
    case 0x80:
        fScale = -25.0f;
        break;
    case 0x40:
        fScale = -50.0f;
        break;
    case 0x20:
        fScale = -100.0f;
        break;
    }
    float aView[4] = {0.0f, 0.0f, 1.0f, 1.0f};
    float aUp[4] = {0.0f, -1.0f, 0.0f, 1.0f};
    float aEye[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    aEye[2] = fScale;
    MakeViewMatrix__5PMat4FPfPfPf(&m_unk4D0, aEye, aView, aUp);
    MakeScreenMatrix__5PMat4Ffffffffff(&m_unk510, 360.0f, 1.0f, 1.0f, 2048.0f, 2048.0f, 128.0f, 16777216.0f, 1.0f, 5000.0f);
    return 1;
}

// FUNCTION: 0x001F0280 __dt__16PParticleTextureFv
PParticleTexture::~PParticleTexture() {
    Reset();
}

// FUNCTION: 0x001F02E0 __ct__16PParticleTextureFv
PParticleTexture::PParticleTexture() {
    sceVu0UnitMatrix((float *)&m_unk4D0);
    sceVu0UnitMatrix((float *)&m_unk510);
    m_unk4C4 = 0;
    Reset();
}
