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
};

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

// FUNCTION: 0x001B8CF0 SetLightningDensity__16PParticleManagerFf
void PParticleManager::SetLightningDensity(float fDensity) {
    if (m_pRain != 0) {
        m_pRain->SetLightningDensity(fDensity);
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

// FUNCTION: 0x001BA9B0 RemoveAll__16PParticleManagerFv
void PParticleManager::RemoveAll() {
    RemoveAllParticleSystems();
    RemoveAllFogObjects();
}
