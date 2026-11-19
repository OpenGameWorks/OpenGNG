#include "types.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
class PParticleRain {
public:
    void SetLightningDensity(float fDensity);
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

void CdsAssert(char *pFile, int nLine, char *pExpr);

struct tagVuParticle {
    char _pad000[0xC];
    int m_unkC;                 // 0x0C
    char _pad010[0xC];
    int m_unk1C;                // 0x1C
};

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
