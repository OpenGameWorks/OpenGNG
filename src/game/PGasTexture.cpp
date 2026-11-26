// FLAGS: -str readonly
#include "PGasTexture.h"
#include "PArray.h"
#include "PParticleSystem.h"

// TODO(header): foreign declarations
extern "C" void Reset__16PParticleTextureFv(void *pThis);
extern "C" void Update__16PParticleTextureFf(void *pThis, float fStep);
extern "C" void __ct__16PParticleTextureFv(void *pThis);
extern "C" void __dt__16PParticleTextureFv(void *pThis, short nFlags);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__12PParticleGasFv(void *pThis);
extern "C" int GetFxTexture__16PParticleManagerFUi(void *pThis, unsigned int hFx);
extern "C" void Create__12PParticleGasFP20tagParticleGasParamsfff(void *pThis, struct tagParticleGasParams *pParams, float fA, float fB, float fC);
extern "C" void Init__16PParticleTextureFiP15PParticleSystemP15PParticleSystemb(void *pThis, int nIndex, void *pGas, void *pNull, bool bFlag);
extern char gGfxEng[1504384];

struct tagParticleGasParams {
    int m_unk0;
    int m_unk4;
    int m_unk8;
    float m_unkC;
    float m_unk10;
    float m_unk14;
    float m_unk18;
    float m_unk1C;
    float m_unk20;
    float m_unk24;
    float m_unk28;
    float m_unk2C;
    float m_unk30;
    float m_unk34;
    float m_unk38;
    float m_unk3C;
    float m_unk40;
    int m_unk44;
    float m_unk48;
    char _pad4C[0x24];
};

class PGasParticleView {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Render();
    virtual void ModifyPosition();
    virtual void FrustrumTest();
    virtual void FadeAndDie(unsigned int nUnused);  // 0x1C
    virtual void Start();                           // 0x20
};

// FUNCTION: 0x001EF530 Reset__11PGasTextureFv
void PGasTexture::Reset()
{
    if (m_unk570 != 0) {
        delete m_unk570;
        m_unk570 = 0;
    }
    if (m_unk574 != 0) {
        delete m_unk574;
        m_unk574 = 0;
    }
    m_unk0 = 0;
    Reset__16PParticleTextureFv(m_unk10);
}

// FUNCTION: 0x001EF5B0 Update__11PGasTextureFv
void PGasTexture::Update()
{
    if (!m_unk0 || !m_unk570 || !m_unk574) {
        return;
    }
    Update__16PParticleTextureFf(m_unk10, 1.0f);
}

// FUNCTION: 0x001EF600 Init__11PGasTextureFP24tagProceduralTextureDataP6PArray
int PGasTexture::Init(struct tagProceduralTextureData *pData, PArray *pArray)
{
    int nIndex;
    int nResult;
    int nSlot;

    if (pData == 0) {
        CdsAssert__FPciPc("PGasTexture.cpp", 0x5C, "pData");
    }
    if (pArray == 0) {
        CdsAssert__FPciPc("PGasTexture.cpp", 0x5D, "poTextureHandles");
    }
    nSlot = *(int *)((char *)pData + 0x20);
    nResult = 1;
    if (nSlot > 0) {
        nIndex = 0;
        if ((unsigned int)nSlot < pArray->m_unk0) {
            nIndex = (int)pArray->m_unk8[nSlot];
        }
        nResult = Init(nIndex);
    }
    return nResult;
}

// FUNCTION: 0x001EF6B0 Init__11PGasTextureFi
int PGasTexture::Init(int nIndex)
{
    void *pGas;
    int hTexture;
    tagParticleGasParams params;

    m_unk0 = nIndex;
    if (m_unk0 != 0) {
        memset(&params, 0, 0x70);
        hTexture = GetFxTexture__16PParticleManagerFUi(gGfxEng + 0x154F00, 0x84000006U);
        params.m_unk0 = 0;
        params.m_unk4 = 0;
        params.m_unk8 = 0;
        params.m_unkC = 1.0f;
        params.m_unk10 = 2.25f;
        params.m_unk14 = 2.25f;
        params.m_unk18 = 2.25f;
        params.m_unk1C = 1.0f;
        params.m_unk20 = 130.0f;
        params.m_unk24 = 130.0f;
        params.m_unk28 = 130.0f;
        params.m_unk2C = 55.0f;
        params.m_unk30 = 0.5f;
        params.m_unk44 = 80;
        params.m_unk38 = 0.8f;
        params.m_unk3C = 1.25f;
        params.m_unk40 = 1.75f;
        params.m_unk34 = 0.4f;
        params.m_unk48 = 1.0f;

        pGas = __nw__FUi(0x170);
        if (pGas != 0) {
            pGas = __ct__12PParticleGasFv(pGas);
        }
        m_unk570 = (PGasTextureHandle *)pGas;
        ((void)((m_unk570) ? (void)0 : CdsAssert__FPciPc("PGasTexture.cpp", 0x3A, "mpGasFx1")));
        Create__12PParticleGasFP20tagParticleGasParamsfff(m_unk570, &params, 0.0f, 0.0f, 0.0f);
        ((PParticleSystem *)m_unk570)->m_unk10 = hTexture;
        ((PParticleSystem *)m_unk570)->m_unk30 = 0x48;
        ((PGasParticleView *)m_unk570)->Start();

        params.m_unk0 = 0;
        params.m_unk4 = 0;
        params.m_unk8 = 0;
        params.m_unkC = 1.0f;
        params.m_unk10 = 2.25f;
        params.m_unk14 = 2.25f;
        params.m_unk18 = 2.25f;
        params.m_unk1C = 1.0f;
        params.m_unk20 = 130.0f;
        params.m_unk24 = 130.0f;
        params.m_unk28 = 130.0f;
        params.m_unk2C = 35.0f;
        params.m_unk30 = 0.1f;
        params.m_unk44 = 80;
        params.m_unk38 = 0.4f;
        params.m_unk3C = 1.25f;
        params.m_unk40 = 1.75f;
        params.m_unk34 = 0.8f;
        params.m_unk48 = 1.0f;

        pGas = __nw__FUi(0x170);
        if (pGas != 0) {
            pGas = __ct__12PParticleGasFv(pGas);
        }
        m_unk574 = (PGasTextureHandle *)pGas;
        ((void)((m_unk574) ? (void)0 : CdsAssert__FPciPc("PGasTexture.cpp", 0x4D, "mpGasFx2")));
        Create__12PParticleGasFP20tagParticleGasParamsfff(m_unk574, &params, 0.0f, 0.0f, 0.0f);
        ((PParticleSystem *)m_unk574)->m_unk10 = hTexture;
        ((PParticleSystem *)m_unk574)->m_unk30 = 0x48;
        ((PGasParticleView *)m_unk574)->Start();

        Init__16PParticleTextureFiP15PParticleSystemP15PParticleSystemb(m_unk10, m_unk0, m_unk570, m_unk574, true);
    }
    return 1;
}

// FUNCTION: 0x001EF9D0 __dt__11PGasTextureFv
PGasTexture::~PGasTexture()
{
    Reset();
    __dt__16PParticleTextureFv(m_unk10, -1);
}

// FUNCTION: 0x001EFA30 __ct__11PGasTextureFv
PGasTexture::PGasTexture()
{
    __ct__16PParticleTextureFv(m_unk10);
    m_unk0 = 0;
    m_unk570 = 0;
    m_unk574 = 0;
}
