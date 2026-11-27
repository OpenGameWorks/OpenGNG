// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PCyclocksFx.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
extern char gGfxEng[1504384];
extern "C" void __dl__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);

struct tagParticleSplineTrailParams {
    char m_unk00[0x0C];
    float m_unk0C;
    float m_unk10;
    float m_unk14;
    float m_unk18;
    float m_unk1C;
    float m_unk20;
    float m_unk24;
    float m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    float m_unk38;
    float m_unk3C;
    float m_unk40;
    float m_unk44;
    float m_unk48;
    char m_unk4C[0x14];
};


// Three handle IDs (12 bytes) in .rodata at 0x24DD10; the last word is a float-typed slot.
struct tagEyeBeamHandles {
    long long m_unk00;
    float m_unk08;
};
extern tagEyeBeamHandles lit_0024DD10;

class PParticleSplineTrail {
public:
    PParticleSplineTrail();
    void Create(tagParticleSplineTrailParams *pParams, float fA, float fB, float fC);

    char m_unk00[0x10];
    int m_unk10;
    char m_unk14[0x1C];
    long long m_unk30;
    char m_unk38[0x170 - 0x38];
};

// Virtual view of PParticleSystem; slot 0x08 + 4 * index.
class PParticleSystemView {
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

// FUNCTION: 0x001F7850 StopFx__11PCyclocksFxFUi
void PCyclocksFx::StopFx(unsigned int hFx) {
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    if (pMgr == 0) {
        CdsAssert("PCyclocksFx.cpp", 0x95, "apFxMgr");
    }
    pMgr->Stop(hFx);
}

// FUNCTION: 0x001F78B0 CreateSplineTrail__11PCyclocksFxFffffff
PParticleSplineTrail *PCyclocksFx::CreateSplineTrail(float p0, float p1, float p2, float p3, float p4, float p5) {
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    tagParticleSplineTrailParams sp = {{0}, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0x14, 0xF, 0.0f, 0.0f, 0.0f, 0.0f, 20.0f};
    sp.m_unk1C = p5;
    sp.m_unk38 = p0;
    sp.m_unk3C = p1;
    sp.m_unk10 = p2;
    sp.m_unk20 = p2;
    sp.m_unk14 = p3;
    sp.m_unk24 = p3;
    sp.m_unk18 = p4;
    sp.m_unk28 = p4;
    if (pMgr == 0) {
        CdsAssert("PCyclocksFx.cpp", 0x83, "apFxMgr");
    }
    PParticleSplineTrail *trail = new PParticleSplineTrail;
    if (trail == 0) {
        CdsAssert("PCyclocksFx.cpp", 0x86, "apFx");
    }
    trail->Create(&sp, 0.0f, 0.0f, 0.0f);
    trail->m_unk30 = 0x48;
    trail->m_unk10 = pMgr->GetFxTexture(0x84000004);
    pMgr->Add((PParticleSystem *)trail);
    return trail;
}

// FUNCTION: 0x001F79E0 SetEyeBeamPos__11PCyclocksFxFPfPf
void PCyclocksFx::SetEyeBeamPos(float *pA, float *pB) {
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    for (int i = 0; i < 3; i++) {
        PParticleSystemView *pSys = (PParticleSystemView *)m_unk00[i];
        if (pSys != 0 && pMgr->IsValid((PParticleSystem *)pSys)) {
            pSys->SetPosition(pA, pB);
        }
    }
    PParticleSystemView *pSys = (PParticleSystemView *)m_unk0C;
    if (pSys != 0 && pMgr->IsValid((PParticleSystem *)pSys)) {
        pSys->SetPosition(pA, pB);
    }
}

// FUNCTION: 0x001F7AD0 StopEyeBeam__11PCyclocksFxFv
void PCyclocksFx::StopEyeBeam() {
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    for (int i = 0; i < 3; i++) {
        pMgr->Stop(m_unk00[i]);
    }
    pMgr->Stop(m_unk0C);
}

// FUNCTION: 0x001F7B50 StartEyeBeam__11PCyclocksFxFv
void PCyclocksFx::StartEyeBeam() {
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    for (int i = 0; i < 3; i++) {
        PParticleSystemView *pSys = (PParticleSystemView *)m_unk00[i];
        if (pSys != 0 && pMgr->IsValid((PParticleSystem *)pSys)) {
            pSys->Start();
        }
    }
    PParticleSystemView *pSys = (PParticleSystemView *)m_unk0C;
    if (pSys != 0 && pMgr->IsValid((PParticleSystem *)pSys)) {
        pSys->Start();
    }
}

// DRAFT: 0x001F7C10 DestroyEyeBeam__11PCyclocksFxFv
// note: frame 0x60 and gGfxEng relocation match; loop puts element in s2 and offset in s1 where original has offset s1, element s2, address s3 (44 words). Tried pointer walk (54), slot pointer &m_unk00[i] (45), nested if (44).
void PCyclocksFx::DestroyEyeBeam() {
    for (int i = 0; i < 3; i++) {
        PParticleSystemView *pSys = (PParticleSystemView *)m_unk00[i];
        if (pSys != 0) {
            if (((PParticleManager *)(gGfxEng + 0x154F00))->IsValid((PParticleSystem *)pSys)) {
                pSys->FadeAndDie(0);
            }
            m_unk00[i] = 0;
        }
    }
    PParticleSystemView *pSys = (PParticleSystemView *)m_unk0C;
    if (pSys != 0) {
        if (((PParticleManager *)(gGfxEng + 0x154F00))->IsValid((PParticleSystem *)pSys)) {
            pSys->FadeAndDie(0);
        }
    }
}

// DRAFT: 0x001F7CF0 CreateEyeBeamForAchille__11PCyclocksFxFv
// note: prologue and handle literal copy match; loop body computes handles[i] as addu/lw 0x50(v0) where original uses addiu sp,0x50 / addu / lw 0(v0). Tried array init, byte pointer, per-iteration &handles[i], and *(handles + i); all DIFF 23 words.
void PCyclocksFx::CreateEyeBeamForAchille() {
    unsigned int handles[3] = {0x830002F1, 0x830002F2, 0x830002F0};
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    for (int i = 0; i < 3; i++) {
        m_unk00[i] = (int)pMgr->Create(handles[i], 0.0f, 0.0f, 0.0f, 0, true);
    }
    m_unk0C = 0;
}

// DRAFT: 0x001F7DA0 CreateEyeBeam__11PCyclocksFxFv
// note: pending; compiling first draft.
void PCyclocksFx::CreateEyeBeam() {
    tagEyeBeamHandles sp = lit_0024DD10;
    PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
    for (int i = 0; i < 3; i++) {
        m_unk00[i] = (int)pMgr->Create(*(unsigned int *)((char *)&sp + i * 4), 0.0f, 0.0f, 0.0f, 0, true);
    }
    m_unk0C = (int)pMgr->Create(0x830001AC, 0.0f, 0.0f, 0.0f, 0, true);
}

// FUNCTION: 0x001F7E70 __dt__11PCyclocksFxFv
PCyclocksFx::~PCyclocksFx() {
    DestroyEyeBeam();
}

// FUNCTION: 0x001F7ED0 __ct__11PCyclocksFxFv
PCyclocksFx::PCyclocksFx() {
    memset(this, 0, 0xC);
    m_unk0C = 0;
}
