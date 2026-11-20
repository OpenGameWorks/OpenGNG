// FLAGS: -str readonly
#include "PFogTexture.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void Reset__16PParticleTextureFv(void *pThis);
extern "C" void Update__16PParticleTextureFf(void *pThis, float fStep);
extern "C" void __ct__16PParticleTextureFv(void *pThis);
extern "C" void __dt__16PParticleTextureFv(void *pThis, short nFlags);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

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

// DRAFT: 0x001F0390 Update__11PFogTextureFv
// note: 11 words differ; original branches m_unk570 with bnez into the call and b to the epilogue; tried &&, reversed &&, early return, else-return: 11-13 words
void PFogTexture::Update()
{
    if (m_unk0 != 0) {
        if (m_unk570 != 0) {
            Update__16PParticleTextureFf(m_unk10, 1.0f);
        }
    }
}

// FUNCTION: 0x001F03E0 Init__11PFogTextureFP24tagProceduralTextureDataP6PArray
int PFogTexture::Init(struct tagProceduralTextureData *pData, PArray *pArray)
{
    int nIndex;
    int nResult;
    int nSlot;

    if (pData == 0) {
        CdsAssert__FPciPc("PFogTexture.cpp", 0x45, "pData");
    }
    if (pArray == 0) {
        CdsAssert__FPciPc("PFogTexture.cpp", 0x46, "poTextureHandles");
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
