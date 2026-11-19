#include "types.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
class PParticleRain {
public:
    void SetLightningDensity(float fDensity);
    void SetDensity(float fDensity, bool bFlag);
    char _pad000[0xC];
    int m_unkC;                 // 0x0C
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
    virtual void Slot01();
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
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
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

void CdsAssert(char *pFile, int nLine, char *pExpr);

struct tagVuParticle {
    char _pad000[0xC];
    int m_unkC;                 // 0x0C
    char _pad010[0xC];
    int m_unk1C;                // 0x1C
};

// DRAFT: 0x001B7F90 RenderEweedReactionFx__16PParticleManagerFv
// note: 11 words differ; original has an extra nop at 0x44 after the Slot02 jalr, shifting the tail by one word. Tried index loop with Slot04 (28 words), byte-offset do-while (11), swapped increments (11).
void PParticleManager::RenderEweedReactionFx() {
    int i = 0;
    int off = 0;
    do {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20DC);
        if (pFx->m_unk15 != 0) {
            pFx->Slot02();
        }
        off += 4;
        i++;
    } while (i < 8);
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
