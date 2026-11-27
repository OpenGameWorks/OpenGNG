// FLAGS: -str readonly
#include "PFireTexture.h"
#include "Debug.h"
#include "PArray.h"
#include "PParticleManager.h"
#include "PParticleTexture.h"

// TODO(header): foreign declarations
extern char gGfxEng[1504384];
extern "C" void Reset__16PParticleTextureFv(void *pThis);
extern "C" void Update__16PParticleTextureFf(void *pThis, float fStep);
extern "C" void __ct__16PParticleTextureFv(void *pThis);
extern "C" void __dt__16PParticleTextureFv(void *pThis, short nFlags);
extern "C" void sceVu0UnitMatrix(float (*pMatrix)[4]);

// Leading virtuals of PParticleSystem's vtable (__vt__15PParticleSystem). Slot 0x20
// is index 6 counting the destructor as 0; a call through this view loads it into
// $t9 as the original's virtual call does.
class PParticleSystemVirtuals {
public:
    virtual ~PParticleSystemVirtuals();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Start();
};

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

// FUNCTION: 0x001EF2D0 Update__12PFireTextureFv
void PFireTexture::Update()
{
    if (!m_unk0 || !m_unk5F0) {
        return;
    }
    Update__16PParticleTextureFf(m_unk10, 1.0f);
}

// FUNCTION: 0x001EF320 Init__12PFireTextureFP24tagProceduralTextureDataP6PArray
int PFireTexture::Init(struct tagProceduralTextureData *pData, PArray *pArray)
{
    int nIndex;
    int nResult;
    int nSlot;

    if (pData == 0) {
        CdsAssert("PFireTexture.cpp", 0x2B, "pData");
    }
    if (pArray == 0) {
        CdsAssert("PFireTexture.cpp", 0x2C, "poTextureHandles");
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

// FUNCTION: 0x001EF3D0 Init__12PFireTextureFi
int PFireTexture::Init(int nIndex)
{
    m_unk0 = nIndex;
    if (m_unk0 != 0) {
        PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
        m_unk5F0 = (PFireTextureHandle *)pMgr->Create(0x83000144U, 0.0f, -4.0f, 0.0f, 0, false);
        if (m_unk5F0 == 0) {
            CdsAssert("PFireTexture.cpp", 0x1F, "mpFireFx");
        }
        ((PParticleSystemVirtuals *)m_unk5F0)->Start();
        ((PParticleTexture *)m_unk10)->Init(m_unk0, (PParticleSystem *)m_unk5F0, 0, false);
    }
    return 1;
}

// FUNCTION: 0x001EF480 __dt__12PFireTextureFv
PFireTexture::~PFireTexture()
{
    Reset();
    __dt__16PParticleTextureFv(m_unk10, -1);
}

// FUNCTION: 0x001EF4E0 __ct__12PFireTextureFv
// note: `this` lives only in a stack slot (spilled at entry, reloaded per access), reproduced by a volatile pThis.
extern "C" PFireTexture *__ct__12PFireTextureFv(PFireTexture *volatile pThis)
{
    __ct__16PParticleTextureFv(pThis->m_unk10);
    sceVu0UnitMatrix(pThis->m_unk570);
    sceVu0UnitMatrix(pThis->m_unk5B0);
    pThis->m_unk0 = 0;
    pThis->m_unk5F0 = 0;
    return pThis;
}
