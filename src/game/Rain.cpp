// FLAGS: -str readonly
#include "types.h"
#include "Rain.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
extern unsigned char __vt__4Rain[];
extern char gGfxEng[1504384];
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void CreateRain__16PParticleManagerFf(void *pThis, float fDensity);
extern "C" void SetLightningDensity__16PParticleManagerFf(void *pThis, float fDensity);
extern "C" void DestroyRain__16PParticleManagerFv(void *pThis);

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("Rain.cpp", line, #cond))

// FUNCTION: 0x001CD4B0 OutputDebug__4RainFv
void Rain::OutputDebug() {
}

// FUNCTION: 0x001CD4C0 GetClassName__4RainFv
const char *Rain::GetClassName() {
    return "Rain";
}

// FUNCTION: 0x001CD4D0 SetEditableVars__4RainFPc
void Rain::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x8);
}

// FUNCTION: 0x001CD4E0 Execute__4RainFv
void Rain::Execute() {
    switch (m_unk20) {
    case -1: {
        void *apParticleMgr = gGfxEng + 0x154F00;
        CDS_ASSERT(0x22, apParticleMgr);
        CreateRain__16PParticleManagerFf(apParticleMgr, m_unk1B0);
        SetLightningDensity__16PParticleManagerFf(apParticleMgr, m_unk1B4);
        SetState(0);
        break;
    }
    case 0:
        break;
    case -2: {
        void *apParticleMgr = gGfxEng + 0x154F00;
        CDS_ASSERT(0x30, apParticleMgr);
        DestroyRain__16PParticleManagerFv(apParticleMgr);
        break;
    }
    }
}

// FUNCTION: 0x001CD5B0 __dt__4RainFv
Rain::~Rain() {
    void *apParticleMgr = gGfxEng + 0x154F00;
    CDS_ASSERT(0x12, apParticleMgr);
    DestroyRain__16PParticleManagerFv(apParticleMgr);
}

// FUNCTION: 0x001CD650 __ct__4RainFv
Rain::Rain() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
