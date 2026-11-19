// FLAGS: -str readonly
#include "types.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
struct tagParticleRainParams;
class PFlashScreen;

extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" PParticleRain *__ct__13PParticleRainFv(PParticleRain *pThis);
extern "C" void *__dt__12PParticleFogFv(PParticleFog *pThis, short nFlags);

class PParticleRain {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    void SetLightningDensity(float fDensity);
    void SetDensity(float fDensity, bool bFlag);
    void Create(tagParticleRainParams *pParams, float (*pA)[4], float (*pB)[4], PFlashScreen *pScreen);
    char _pad000[0x8];
    int m_unkC;                 // 0x0C
    char _pad010[0xC4];
    int m_unkD4;                // 0xD4
};

class PArray {
public:
    int Find(void *pItem);
    void Add(void *pItem);
};

class PMovingFog {
public:
    virtual void Slot00(int bFlag);
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
};

class PParticleSystem {
public:
    virtual void Slot00();
    virtual void Slot01(float fDt);
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
};

class PEweedFx {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual int Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08(float *pA, float *pB);
    virtual void Slot09();
    char _pad004[0x11];
    unsigned char m_unk15;      // 0x15
};

class PParticleOneShot {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05(int bFlag);
    virtual void Slot06();
};

class PParticleLiteExplosion {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08(float *pA, float *pB);
    void Start(float fScale);
    char _pad004[0x11];
    unsigned char m_unk15;      // 0x15
};

class PStaticInstanceGroup {
public:
    void RenderParticleInstances(bool bFlag);
};

struct tagGroundDustParams {
    char _pad000[0x80];
    float m_unk80;              // 0x80
};

extern tagGroundDustParams gGroundDustParams;

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" int printf(const char *fmt, ...);

struct tagVuParticle {
    char _pad000[0xC];
    int m_unkC;                 // 0x0C
    char _pad010[0xC];
    int m_unk1C;                // 0x1C
};

// DRAFT: 0x001B7F90 RenderEweedReactionFx__16PParticleManagerFv
// note: 5 words differ; original is bottom-tested (no entry b) with an empty join nop at 0x44 before i++ and off+=4 in the bnez delay slot. Tried index loop with Slot04 (28), byte-offset do-while (11), swapped increments (11), for with off at body end (5).
void PParticleManager::RenderEweedReactionFx() {
    for (int i = 0, off = 0; i < 8; i++) {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20DC);
        if (pFx->m_unk15 != 0) {
            pFx->Slot02();
        }
        off += 4;
    }
}

// FUNCTION: 0x001B80C0 DestroyEweedReactionFx__16PParticleManagerFv
void PParticleManager::DestroyEweedReactionFx() {
    int i = 0;
    int off = 0;
    do {
        PMovingFog *pFx = *(PMovingFog **)((char *)this + off + 0x20DC);
        if (pFx != 0 && pFx != 0) {
            pFx->Slot00(1);
        }
        i++;
        off += 4;
    } while (i < 8);
}

// DRAFT: 0x001B8130 InitEweedReactionFx__16PParticleManagerFv
// note: 20 lines differ, DRAFT; s-regs match (i,pFx,off order); only diff is delay slot: orig fills bnez slot with the lui of the assert path and joins at addu; ours hoists the join addu into the slot and duplicates it. Tried i++ before store, paren offset (worse).
void PParticleManager::InitEweedReactionFx() {
    int i = 0;
    PParticleOneShot *pFx;
    int off = 0;
    do {
        pFx = Create(0x83000346, 0.0f, 0.0f, 0.0f, 0, false);
        if (pFx == 0) {
            CdsAssert("PParticleManager.cpp", 0x5A1, "apFx");
        }
        *(PParticleOneShot **)((char *)this + off + 0x20DC) = pFx;
        i++;
        off += 4;
    } while (i < 8);
}

// DRAFT: 0x001B81D0 RenderSulphurReactionFx__16PParticleManagerFv
// note: 5 words differ; original is bottom-tested (no entry b) with an empty join nop at 0x44 before i++. Tried do-while (11), for with off in increment (6), empty else (6), continue (19), for with off at body end (5).
void PParticleManager::RenderSulphurReactionFx() {
    for (int i = 0, off = 0; i < 8; i++) {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20BC);
        if (pFx->m_unk15 != 0) {
            pFx->Slot02();
        }
        off += 4;
    }
}

// FUNCTION: 0x001B8300 DestroySulphurReactionFx__16PParticleManagerFv
void PParticleManager::DestroySulphurReactionFx() {
    int i = 0;
    int off = 0;
    do {
        PMovingFog *pFx = *(PMovingFog **)((char *)this + off + 0x20BC);
        if (pFx != 0 && pFx != 0) {
            pFx->Slot00(1);
        }
        i++;
        off += 4;
    } while (i < 8);
}

// DRAFT: 0x001B8370 InitSulphurReactionFx__16PParticleManagerFv
// note: 20 lines differ, DRAFT; s-regs and string addressing match (i,pFx,off order, -str readonly); only diff is the bnez delay slot hoisting the join addu (same as Eweed). Tried i++ before store, paren offset (worse).
void PParticleManager::InitSulphurReactionFx() {
    int i = 0;
    PParticleOneShot *pFx;
    int off = 0;
    do {
        pFx = Create(0x8300025A, 0.0f, 0.0f, 0.0f, 0, false);
        if (pFx == 0) {
            CdsAssert("PParticleManager.cpp", 0x572, "apFx");
        }
        *(PParticleOneShot **)((char *)this + off + 0x20BC) = pFx;
        i++;
        off += 4;
    } while (i < 8);
}

// DRAFT: 0x001B8410 RenderGroundDustFx__16PParticleManagerFv
// note: 5 words differ; same loop shape as RenderSulphurReactionFx (entry b and join nop at 0x44). Tried do-while (11), for with off at body end (5).
void PParticleManager::RenderGroundDustFx() {
    for (int i = 0, off = 0; i < 12; i++) {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x208C);
        if (pFx->m_unk15 != 0) {
            pFx->Slot02();
        }
        off += 4;
    }
}

// FUNCTION: 0x001B8540 DestroyGroundDustFx__16PParticleManagerFv
void PParticleManager::DestroyGroundDustFx() {
    int i = 0;
    int off = 0;
    do {
        PMovingFog *pFx = *(PMovingFog **)((char *)this + off + 0x208C);
        if (pFx != 0 && pFx != 0) {
            pFx->Slot00(1);
        }
        i++;
        off += 4;
    } while (i < 12);
}

// FUNCTION: 0x001B8750 CreateEweedReaction__16PParticleManagerFPf
int PParticleManager::CreateEweedReaction(float *pPos) {
    int i = 0;
    int off = 0;
    do {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20DC);
        if (pFx->m_unk15 == 0) {
            pFx->Slot08(pPos, pPos);
            pFx->Slot06();
            return 1;
        }
        i++;
        off += 4;
    } while (i < 8);
    return 0;
}

// FUNCTION: 0x001B87D0 CreateSulphurReaction__16PParticleManagerFPff
int PParticleManager::CreateSulphurReaction(float *pPos, float fUnused) {
    int i = 0;
    int off = 0;
    do {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20BC);
        if (pFx->m_unk15 == 0) {
            pFx->Slot08(pPos, pPos);
            pFx->Slot06();
            return 1;
        }
        i++;
        off += 4;
    } while (i < 8);
    return 0;
}

// FUNCTION: 0x001B8850 CreateGroundDust__16PParticleManagerFPff
int PParticleManager::CreateGroundDust(float *pPos, float fScale) {
    int i = 0;
    int off = 0;
    do {
        PParticleLiteExplosion *pFx = *(PParticleLiteExplosion **)((char *)this + off + 0x208C);
        if (pFx->m_unk15 == 0) {
            pFx->Slot08(pPos, pPos);
            pFx->Start(gGroundDustParams.m_unk80 * fScale);
            return 1;
        }
        i++;
        off += 4;
    } while (i < 12);
    return 0;
}

// DRAFT: 0x001B8A00 FreeAuraParticle__16PParticleManagerFP13tagVuParticle
// note: the zero path stores $zero directly (sw) where the original does daddu v1,zero,zero then sw v1; branch offset of the b differs by one word.
void PParticleManager::FreeAuraParticle(tagVuParticle *pParticle) {
    if (pParticle != 0) {
        pParticle->m_unkC = 0;
        pParticle->m_unk1C = 0;
        int n = m_unkEC0 - 1;
        if (n > 0) {
            m_unkEC0 = n;
            return;
        }
        n = 0;
        m_unkEC0 = n;
    }
}

// FUNCTION: 0x001B8A40 AllocAuraParticle__16PParticleManagerFv
void *PParticleManager::AllocAuraParticle() {
    int i = 0;
    int off = 0;
    do {
        if (*(float *)((char *)this + off + 0x9CC) == 0.0f && *(float *)((char *)this + off + 0x9DC) == 0.0f) {
            m_unkEC0++;
            return (char *)this + (i << 5) + 0x9C0;
        }
        i++;
        off += 0x20;
    } while (i < 0x28);
    printf("\n**Too many Aura Particles! Ask Vn to increase array size!\n", off);
    return 0;
}

// DRAFT: 0x001B8AD0 DestroyMovingFog__16PParticleManagerFv
// note: the original has one null check with the vtable call and store inside; ours emits an extra beqz before the vtable load (variants: local pointer, early return, store outside guard).
void PParticleManager::DestroyMovingFog() {
    if (m_unk9B4 != 0) {
        m_unk9B4->Slot00(1);
        m_unk9B4 = 0;
    }
}

// FUNCTION: 0x001B8CF0 SetLightningDensity__16PParticleManagerFf
void PParticleManager::SetLightningDensity(float fDensity) {
    if (m_pRain != 0) {
        m_pRain->SetLightningDensity(fDensity);
    }
}

// FUNCTION: 0x001B8D20 SetRainDensity__16PParticleManagerFfb
void PParticleManager::SetRainDensity(float fDensity, bool bFlag) {
    if (m_pRain != 0) {
        SetRainDensity((unsigned int)m_pRain, fDensity / 100.0f, bFlag);
    }
}

// FUNCTION: 0x001B8D70 DestroyRain__16PParticleManagerFv
void PParticleManager::DestroyRain() {
    if (m_pRain != 0) {
        Remove((PParticleSystem *)m_pRain);
        m_pRain = 0;
    }
}

// DRAFT: 0x001B8EB0 SetRainDensity__16PParticleManagerFUifb
// note: 1 word differs at 0x1C; ours beqz $s0 (local pRain) vs original beqz $a1 (hRain). Tried nested if (6 words), and no local (6 words).
void PParticleManager::SetRainDensity(unsigned int hRain, float fDensity, bool bFlag) {
    PParticleRain *pRain = (PParticleRain *)hRain;
    if (hRain != 0 && IsValid((PParticleSystem *)hRain) && pRain->m_unkC == 8) {
        pRain->SetDensity(fDensity, bFlag);
    }
}

// FUNCTION: 0x001B8F20 CreateRain__16PParticleManagerFP21tagParticleRainParams
PParticleRain *PParticleManager::CreateRain(tagParticleRainParams *pParams) {
    PParticleRain *pRain = (PParticleRain *)__nw__FUi(0x2C0);
    if (pRain != 0) {
        pRain = __ct__13PParticleRainFv(pRain);
    }
    PParticleRain *pResult = 0;
    if (pRain != 0) {
        pRain->Create(pParams, (float (*)[4])((char *)this + 0x680), (float (*)[4])((char *)this + 0x690), (PFlashScreen *)((char *)this + 0x6B0));
        pRain->m_unkD4 = 2;
        pRain->Slot06();
        Add((PParticleSystem *)pRain);
        pResult = pRain;
    }
    return pResult;
}

// FUNCTION: 0x001B92E0 CreateOneShot__16PParticleManagerFUifff
PParticleOneShot *PParticleManager::CreateOneShot(unsigned int hFx, float fA, float fB, float fC) {
    PParticleOneShot *pFx = Create(hFx, fA, fB, fC, 0, true);
    if (pFx != 0) {
        pFx->Slot06();
        pFx->Slot05(0);
    }
    return pFx;
}

// FUNCTION: 0x001B9B50 IsValid__16PParticleManagerFP15PParticleSystem
int PParticleManager::IsValid(PParticleSystem *pSystem) {
    if ((pSystem != 0) && (((PArray *)this)->Find(pSystem) >= 0)) {
        return 1;
    }
    return 0;
}

// DRAFT: 0x001BA3F0 UpdateMasterParticleInstances__16PParticleManagerFfP9PFrustrum
// note: 10 lines: original reloads 0x207C after the store and keeps fDt copy in the branch delay slot; tried if/else tail (worse, 14)
void PParticleManager::UpdateMasterParticleInstances(float fDt, PFrustrum *pFrustrum) {
    PParticleSystem *pSystem;
    m_unk207C = 0;
    if (m_unk2078 != 0) {
        pSystem = m_unk2080[0];
    } else {
        pSystem = 0;
    }
    if (pSystem != 0) {
        do {
            pSystem->Slot01(fDt);
            ++m_unk207C;
            pSystem = 0;
            if (m_unk207C < m_unk2078) {
                pSystem = m_unk2080[m_unk207C];
            }
        } while (pSystem != 0);
    }
}

// FUNCTION: 0x001BA490 RenderParticleInstanceGroups__16PParticleManagerFb
void PParticleManager::RenderParticleInstanceGroups(bool bFlag) {
    PStaticInstanceGroup *pGroup;
    m_unk206C = 0;
    if (m_unk2068 != 0) {
        pGroup = m_unk2070[0];
    } else {
        pGroup = 0;
    }
    if (pGroup != 0) {
        do {
            pGroup->RenderParticleInstances(bFlag);
            unsigned int idx = m_unk206C + 1;
            m_unk206C = idx;
            if (idx < m_unk2068) {
                pGroup = m_unk2070[m_unk206C];
            } else {
                pGroup = 0;
            }
        } while (pGroup != 0);
    }
}

// DRAFT: 0x001BA530 AddParticleInstanceGroup__16PParticleManagerFP20PStaticInstanceGroup
// note: the "pGroup" literal is gp-relative (addiu a2,gp) in ours but lui/addiu in the original, so the then-branch is 5 words not 6; tried (char*) casts, !pGroup, local char* expr (all 13 diff lines).
void PParticleManager::AddParticleInstanceGroup(PStaticInstanceGroup *pGroup) {
    if (pGroup == 0) {
        CdsAssert("PParticleManager.cpp", 0x1B2, "pGroup");
    }
    ((PArray *)((char *)this + 0x2068))->Add(pGroup);
}

// DRAFT: 0x001BA590 AddMasterParticleInstance__16PParticleManagerFP15PParticleSystem
// note: 13 words differ; "pFx" literal is gp-relative (addiu a2,gp) in ours but lui/addiu in the original, which shifts the bnez offset by one word. Tried const char* CdsAssert (13), char* (13).
void PParticleManager::AddMasterParticleInstance(PParticleSystem *pFx) {
    if (pFx == 0) {
        CdsAssert("PParticleManager.cpp", 0x1AA, "pFx");
    }
    ((PArray *)((char *)this + 0x2078))->Add(pFx);
}

// DRAFT: 0x001BA5F0 RemoveAllFogObjects__16PParticleManagerFv
// note: 8 lines: original reloads 0x24 after the store (sw v1 then lw a1); ours reuses the register; postfix ++ same count
void PParticleManager::RemoveAllFogObjects() {
    PParticleFog *pFog;
    m_unk24 = 0;
    if (m_unk20 != 0) {
        pFog = m_unk28[0];
    } else {
        pFog = 0;
    }
    if (pFog != 0) {
        do {
            __dt__12PParticleFogFv(pFog, 1);
            ++m_unk24;
            pFog = 0;
            if (m_unk24 < m_unk20) {
                pFog = m_unk28[m_unk24];
            }
        } while (pFog != 0);
    }
    if (m_unk28 != 0) {
        m_unk20 = 0;
        m_unk24 = 0;
    }
}

// FUNCTION: 0x001BA9B0 RemoveAll__16PParticleManagerFv
void PParticleManager::RemoveAll() {
    RemoveAllParticleSystems();
    RemoveAllFogObjects();
}

// FUNCTION: 0x001BA9E0 Stop__16PParticleManagerFUi
void PParticleManager::Stop(unsigned int hSystem) {
    PParticleSystem *pSystem = (PParticleSystem *)hSystem;
    if (pSystem != 0 && IsValid(pSystem)) {
        pSystem->Slot07();
    }
}

// FUNCTION: 0x001BAA30 StopFx__16PParticleManagerFUi
void PParticleManager::StopFx(unsigned int hSystem) {
    PParticleSystem *pSystem = (PParticleSystem *)hSystem;
    if (pSystem != 0 && IsValid(pSystem)) {
        pSystem->Slot07();
    }
}

// FUNCTION: 0x001BAA80 Destroy__16PParticleManagerFUi
void PParticleManager::Destroy(unsigned int hSystem) {
    PParticleSystem *pSystem = (PParticleSystem *)hSystem;
    if (pSystem != 0 && IsValid(pSystem)) {
        pSystem->Slot07();
        Remove(pSystem);
    }
}
