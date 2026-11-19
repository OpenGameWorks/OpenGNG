#include "PParticleSystem.h"
#include "types.h"

// TODO(header): foreign declarations
class PMat4;
extern unsigned char __vt__15PParticleSystem[0x40];
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);

// FUNCTION: 0x001B4A90 UpdateLoopDelay__15PParticleSystemFf
void PParticleSystem::UpdateLoopDelay(float fDelta) {
    if (m_unkB4 > 0.0f) {
        m_unkB4 = m_unkB4 - fDelta;
        if (!(m_unkB4 > 0.0f)) {
            m_unk15 = 1;
            m_unk18 = 1;
            m_unkB4 = 0.0f;
        }
    }
}

// FUNCTION: 0x001B4CE0 Cleanup__15PParticleSystemFv
void PParticleSystem::Cleanup() {
    if (m_unk1A != 0) {
        if (m_unk08 != 0) {
            __dla__FPv(m_unk08);
        }
    }
    m_unk08 = 0;
    m_unk1A = 0;
    m_unk0C = 0;
    m_unk10 = 0;
    m_unk15 = 0;
    m_unk14 = 0;
    m_unkA8 = -1;
}

// FUNCTION: 0x001B4D50 FadeAndDie__15PParticleSystemFUi
void PParticleSystem::FadeAndDie(unsigned int nUnused) {
    if (m_unk15 == 0) {
        m_unk16 = 1;
        m_unk17 = 1;
        m_unk18 = 0;
    } else {
        m_unk17 = 1;
        m_unkAC = 0;
    }
}

// FUNCTION: 0x001B4EE0 ModifyPosition__15PParticleSystemFP5PMat4
void PParticleSystem::ModifyPosition(PMat4 *pMat) {
    m_unk40 = *(u_long128 *)((char *)pMat + 0x00);
    m_unk50 = *(u_long128 *)((char *)pMat + 0x10);
    m_unk60 = *(u_long128 *)((char *)pMat + 0x20);
    m_unk70 = *(u_long128 *)((char *)pMat + 0x30);
}

// FUNCTION: 0x001B51C0 __dt__15PParticleSystemFv
extern "C" PParticleSystem *__dt__15PParticleSystemFv(PParticleSystem *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__15PParticleSystem;
        pThis->Cleanup();
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
