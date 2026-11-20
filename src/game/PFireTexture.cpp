// FLAGS: -str readonly
#include "PFireTexture.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void Reset__16PParticleTextureFv(void *pThis);
extern "C" void Update__16PParticleTextureFf(void *pThis, float fStep);
extern "C" void __ct__16PParticleTextureFv(void *pThis);
extern "C" void __dt__16PParticleTextureFv(void *pThis, short nFlags);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0UnitMatrix(float (*pMatrix)[4]);

// FUNCTION: 0x001EF270 Reset__12PFireTextureFv
void PFireTexture::Reset()
{
    if (m_unk5F0 != 0) {
        delete m_unk5F0;
        m_unk5F0 = 0;
    }
    m_unk0 = 0;
    Reset__16PParticleTextureFv(m_unk10);
}

// DRAFT: 0x001EF2D0 Update__12PFireTextureFv
// note: compiles; branch sense differs (original bnez to call then b to exit, ours beqz over call). Tried nested, &&, double early return, if/else variants: all DIFF 11 words.
void PFireTexture::Update()
{
    if (m_unk0 != 0) {
        if (m_unk5F0 != 0) {
            Update__16PParticleTextureFf(m_unk10, 1.0f);
        }
    }
}

// FUNCTION: 0x001EF320 Init__12PFireTextureFP24tagProceduralTextureDataP6PArray
int PFireTexture::Init(struct tagProceduralTextureData *pData, PArray *pArray)
{
    int nIndex;
    int nResult;
    int nSlot;

    if (pData == 0) {
        CdsAssert__FPciPc("PFireTexture.cpp", 0x2B, "pData");
    }
    if (pArray == 0) {
        CdsAssert__FPciPc("PFireTexture.cpp", 0x2C, "poTextureHandles");
    }
    nSlot = *(int *)((char *)pData + 0x24);
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

// FUNCTION: 0x001EF480 __dt__12PFireTextureFv
PFireTexture::~PFireTexture()
{
    Reset();
    __dt__16PParticleTextureFv(m_unk10, -1);
}

// DRAFT: 0x001EF4E0 __ct__12PFireTextureFv
// note: original spills this to 0x1C(sp) and reloads it per store (member with dtor); char[0x560] embedding keeps this in s0. A dtor-bearing member would add an implicit dtor call to the matched dtor.
PFireTexture::PFireTexture()
{
    __ct__16PParticleTextureFv(m_unk10);
    sceVu0UnitMatrix(m_unk570);
    sceVu0UnitMatrix(m_unk5B0);
    m_unk0 = 0;
    m_unk5F0 = 0;
}
