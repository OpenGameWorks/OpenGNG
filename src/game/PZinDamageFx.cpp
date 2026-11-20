// FLAGS: -str readonly
#include "types.h"
#include "PZinDamageFx.h"
#include "EntityBaseClass.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
class PMat4;
class PFrustrum;
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern unsigned char __vt__12PZinDamageFx[];
extern char gGfxEng[1504384];

// Virtual view of a PParticleSystem subobject. Slot 0x08 is the virtual
// destructor, 0x0C an unnamed slot, then Render, ModifyPosition,
// FrustrumTest and FadeAndDie. The view does not derive from PParticleSystem,
// so the derived layout is unchanged.
class PZinDamageFxView {
public:
    virtual ~PZinDamageFxView();
    virtual void Slot0C();
    virtual void Render();
    virtual void ModifyPosition(PMat4 *pMat);
    virtual void FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar);
    virtual void FadeAndDie(unsigned int nUnused);
};


// FUNCTION: 0x00202900 FadeAndDie__12PZinDamageFxFUi
void PZinDamageFx::FadeAndDie(unsigned int nUnused) {
    PParticleSystem::FadeAndDie(nUnused);
    if (m_unkE4) {
        ((PZinDamageFxView *)m_unkE4)->FadeAndDie(nUnused);
    }
}

// FUNCTION: 0x00202950 Render__12PZinDamageFxFv
void PZinDamageFx::Render() {
    if (!m_unk15) {
        return;
    }
    if (!m_unkE4) {
        return;
    }
    if (!m_unkE4->m_unk15) {
        return;
    }
    if (!m_unkA4) {
        return;
    }
    if (((PParticleSystem *)m_unkE0)->m_unk1C) {
        return;
    }
    ((PZinDamageFxView *)m_unkE4)->Render();
}

// FUNCTION: 0x00202C60 Create__12PZinDamageFxFP15EntityBaseClassfUi
int PZinDamageFx::Create(EntityBaseClass *pOwner, float fArg, unsigned int nArg) {
    m_unkE0 = pOwner;
    m_unkE8 = fArg;
    m_unkEC = fArg;
    m_unkE4 = (PParticleSystem *)((PParticleManager *)(gGfxEng + 0x154F00))->Create(nArg, 0.0f, 0.0f, 0.0f, 0, false);
    ((m_unkE4) ? (void)0 : CdsAssert__FPciPc("PZinDamageFx.cpp", 0x36, "mpMasterFx"));
    PParticleSystem::Create(1, false);
    m_unk0C = 0x1A;
    return 1;
}

// FUNCTION: 0x00202D00 __dt__12PZinDamageFxFv
PZinDamageFx::~PZinDamageFx() {
    *(unsigned char **)this = __vt__12PZinDamageFx;
    if (m_unkE4) {
        delete (PZinDamageFxView *)m_unkE4;
        m_unkE4 = 0;
    }
    m_unkE0 = 0;
    __dt__15PParticleSystemFv(this, 0);
}

// FUNCTION: 0x00202D90 __ct__12PZinDamageFxFv
PZinDamageFx::PZinDamageFx() : PParticleSystem() {
    *(unsigned char **)this = __vt__12PZinDamageFx;
    m_unkE4 = 0;
    m_unkE0 = 0;
    m_unkE8 = 0.0f;
    m_unkEC = 0.0f;
}
