// FLAGS: -str readonly
#include "PFogTexture.h"
#include "Debug.h"
#include "PArray.h"
#include "PParticleSystem.h"

// TODO(header): foreign declarations
extern "C" void Reset__16PParticleTextureFv(void *pThis);
extern "C" void Update__16PParticleTextureFf(void *pThis, float fStep);
extern "C" void __ct__16PParticleTextureFv(void *pThis);
extern "C" void __dt__16PParticleTextureFv(void *pThis, short nFlags);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void __ct__12PParticleGasFv(void *pThis);
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

class PFogParticleView {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Render();
    virtual void ModifyPosition();
    virtual void FrustrumTest();
    virtual void FadeAndDie(unsigned int nUnused);  // 0x1C
    virtual void Start();                           // 0x20
    virtual void Stop();                            // 0x24
    virtual void SetPosition(float *pA, float *pB); // 0x28
    virtual void Enable(bool bFlag);                // 0x2C
};

// FUNCTION: 0x001F0330 Reset__11PFogTextureFv
void PFogTexture::Reset()
{
    if (m_unk570 != 0) {
        delete m_unk570;
        m_unk570 = 0;
    }
    m_unk0 = 0;
    Reset__16PParticleTextureFv(m_unk10);
}

// FUNCTION: 0x001F0390 Update__11PFogTextureFv
void PFogTexture::Update()
{
    if (!m_unk0 || !m_unk570) {
        return;
    }
    Update__16PParticleTextureFf(m_unk10, 1.0f);
}

// FUNCTION: 0x001F03E0 Init__11PFogTextureFP24tagProceduralTextureDataP6PArray
int PFogTexture::Init(struct tagProceduralTextureData *pData, PArray *pArray)
{
    int nIndex;
    int nResult;
    int nSlot;

    if (pData == 0) {
        CdsAssert("PFogTexture.cpp", 0x45, "pData");
    }
    if (pArray == 0) {
        CdsAssert("PFogTexture.cpp", 0x46, "poTextureHandles");
    }
    nResult = 1;
    nSlot = *(int *)((char *)pData + 0x28);
    if (nSlot >= 0) {
        nIndex = 0;
        if ((unsigned int)nSlot < pArray->m_unk0) {
            nIndex = (int)pArray->m_unk8[nSlot];
        }
        nResult = Init(nIndex);
    }
    return nResult;
}

// DRAFT: 0x001F0490 Init__11PFogTextureFi
// note: 85 words differ; original memsets params (0x70) and copies a rodata template before GetFxTexture, then stores fields after it; tried struct init before/after call (85/86), if(!=0) restructure (86), memset+field stores (88), = {} aggregate (101)
int PFogTexture::Init(int nIndex)
{
    int hTexture;

    m_unk0 = nIndex;
    if (m_unk0 == 0) {
        return m_unk0;
    }
    hTexture = GetFxTexture__16PParticleManagerFUi(gGfxEng, 0x84000006);
    tagParticleGasParams params = {
        0, 0, 0,
        1.0f,
        2.5f, 2.5f, 2.5f,
        1.0f,
        160.0f, 160.0f, 160.0f,
        70.0f,
        0.4f, 0.62f, 0.7f, 1.25f, 1.75f,
        60,
        1.0f
    };
    m_unk570 = (PFogTextureHandle *)__nw__FUi(0x170);
    if (m_unk570 != 0) {
        __ct__12PParticleGasFv(m_unk570);
    }
    if (m_unk570 == 0) {
        CdsAssert("PFogTexture.cpp", 0x37, "mpFogFx");
    }
    Create__12PParticleGasFP20tagParticleGasParamsfff(m_unk570, &params, 0.0f, 0.0f, 0.0f);
    ((PParticleSystem *)m_unk570)->m_unk10 = hTexture;
    ((PParticleSystem *)m_unk570)->m_unk30 = 0x48;
    ((PFogParticleView *)m_unk570)->Start();
    Init__16PParticleTextureFiP15PParticleSystemP15PParticleSystemb(m_unk10, m_unk0, m_unk570, 0, true);
    return 1;
}

// FUNCTION: 0x001F0610 __dt__11PFogTextureFv
PFogTexture::~PFogTexture()
{
    Reset();
    __dt__16PParticleTextureFv(m_unk10, -1);
}

// FUNCTION: 0x001F0670 __ct__11PFogTextureFv
PFogTexture::PFogTexture()
{
    __ct__16PParticleTextureFv(m_unk10);
    m_unk0 = 0;
    m_unk570 = 0;
}
