// FLAGS: -str readonly
#include "types.h"
#include "Rain.h"

// TODO(header): foreign declarations
extern unsigned char __vt__4Rain[];
extern char gGfxEng[1504384];
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void CreateRain__16PParticleManagerFf(void *pThis, float fDensity);
extern "C" void SetLightningDensity__16PParticleManagerFf(void *pThis, float fDensity);
extern "C" void DestroyRain__16PParticleManagerFv(void *pThis);

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("Rain.cpp", line, #cond))

// DRAFT: 0x001CD4E0 Execute__4RainFv
// note: size 0xC8 vs 0xD0; -1 create block is inline with bne, original has beq to an out-of-line block after a b to epilogue; tried empty-then, early return, return-then-create.
void Rain::Execute() {
    if (m_unk20 != -2) {
        if (m_unk20 != 0) {
            if (m_unk20 != -1) {
                return;
            } else {
                void *apParticleMgr = gGfxEng;
                CDS_ASSERT(0x22, apParticleMgr);
                CreateRain__16PParticleManagerFf(apParticleMgr, m_unk1B0);
                SetLightningDensity__16PParticleManagerFf(apParticleMgr, m_unk1B4);
                SetState(0);
            }
        }
    } else {
        void *apParticleMgr = gGfxEng;
        CDS_ASSERT(0x30, apParticleMgr);
        DestroyRain__16PParticleManagerFv(apParticleMgr);
    }
}

// FUNCTION: 0x001CD5B0 __dt__4RainFv
Rain::~Rain() {
    void *apParticleMgr = gGfxEng;
    CDS_ASSERT(0x12, apParticleMgr);
    DestroyRain__16PParticleManagerFv(apParticleMgr);
}

// DRAFT: 0x001CD650 __ct__4RainFv
// note: size 0x5C vs 0x4C; compiler emits a vtable store before the base ctor call and again after it, original has one store after; explicit store removed (21->18 words).
Rain::Rain() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 0U);
    EnableSleep__15EntityBaseClassFbb(this, false, false);
}
