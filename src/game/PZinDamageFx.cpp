// FLAGS: -str readonly
#include "types.h"
#include "PZinDamageFx.h"
#include "EntityBaseClass.h"
#include "PParticleManager.h"
#include "PArray.h"

// TODO(header): foreign declarations
class PMat4;
class PFrustrum;
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int rand(void);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern unsigned char __vt__12PZinDamageFx[];
extern char gGfxEng[1504384];

// Virtual view of a PParticleSystem subobject. Slot 0x08 is the virtual
// destructor, 0x0C an unnamed slot, then Render, ModifyPosition,
// FrustrumTest, FadeAndDie, Start (0x20), Stop (0x24) and SetPosition (0x28).
// The view does not derive from PParticleSystem, so the derived layout is unchanged.
class PZinDamageFxView {
public:
    virtual ~PZinDamageFxView();
    virtual void Slot0C(float fArg);
    virtual void Render();
    virtual void ModifyPosition(PMat4 *pMat);
    virtual void FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar);
    virtual void FadeAndDie(unsigned int nUnused);
    virtual void Start();
    virtual void Stop();
    virtual void SetPosition(float *pPos, float *pPrev);
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

// DRAFT: 0x002029C0 Animate__12PZinDamageFxFf
// note: DIFF 143; first-branch delay slot holds lui not nop, string addends differ, size 0x26c vs 0x294. Tried fArg copy at entry, unconditional timer store, store inside branch (worse).
void PZinDamageFx::Animate(float fArg) {
    float vec[4];
    PArray *pArr;
    char *pPick;
    float fRand;
    float fCount;
    int nIdx;
    float fTimer;
    float fBase;

    ((m_unkE4) ? (void)0 : CdsAssert__FPciPc("PZinDamageFx.cpp", 0x41, "mpMasterFx"));
    ((m_unkE0) ? (void)0 : CdsAssert__FPciPc("PZinDamageFx.cpp", 0x42, "mpObj"));
    if (!m_unk15) {
        return;
    }
    if (((PParticleSystem *)m_unkE0)->m_unk1C) {
        return;
    }
    pPick = 0;
    if (m_unkE0->m_unk3C == 0 || *(int *)(m_unkE0->m_unk3C + 4) != 2) {
        goto tail;
    }
    pArr = (PArray *)(m_unkE0->m_unk3C + 0x150);
    m_unkA4 = 1;
    if (pArr == 0) {
        goto timer;
    }
    fRand = (float)rand() / 2147483648.0f;
    fCount = (float)(pArr->m_unk0 - 1);
    nIdx = (int)(0.5f + fRand * fCount);
    pPick = ((unsigned int)nIdx < pArr->m_unk0) ? (char *)pArr->m_unk8[nIdx] : 0;
    ((pPick) ? (void)0 : CdsAssert__FPciPc("PZinDamageFx.cpp", 0x56, "apNode"));
    sceVu0CopyVector(vec, (float *)(pPick + 0x70));
    pPick = (char *)1;

timer:
    fTimer = m_unkEC - fArg;
    m_unkEC = fTimer;
    if (fTimer <= 0.0f) {
        fBase = m_unkE8;
        fRand = (float)rand() / 2147483648.0f;
        m_unkEC = fBase + (0.6f * fBase - fBase) * fRand;
        if (pPick) {
            ((PZinDamageFxView *)m_unkE4)->SetPosition(vec, vec);
            ((PZinDamageFxView *)m_unkE4)->Start();
            m_unkE0->PlaySound(0x100);
        }
    }
    if (m_unkE4) {
        ((PZinDamageFxView *)m_unkE4)->Slot0C(fArg);
    }
    m_unk16 = m_unkE4->m_unk16;
    return;

tail:
    m_unk16 = m_unk17;
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
