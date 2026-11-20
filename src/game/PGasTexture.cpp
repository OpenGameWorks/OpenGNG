// FLAGS: -str readonly
#include "PGasTexture.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void Reset__16PParticleTextureFv(void *pThis);
extern "C" void Update__16PParticleTextureFf(void *pThis, float fStep);
extern "C" void __ct__16PParticleTextureFv(void *pThis);
extern "C" void __dt__16PParticleTextureFv(void *pThis, short nFlags);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

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

// DRAFT: 0x001EF5B0 Update__11PGasTextureFv
// note: DIFF 12 words; original reaches the call through a bnez with a fall-through b to the shared exit; nested if/else, early-return and flat && forms all DIFF 12
void PGasTexture::Update()
{
    if (m_unk0 != 0 && m_unk570 != 0 && m_unk574 != 0) {
        Update__16PParticleTextureFf(m_unk10, 1.0f);
    }
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
