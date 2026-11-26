#include "types.h"
#include "BlowingLeaves.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__13BlowingLeaves[];
extern char gGfxEng[1504384];
extern "C" void Destroy__16PParticleManagerFUi(void *pThis, unsigned int hSystem);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" unsigned int CreateBlowingLeaves__16PParticleManagerFPfPfPfifb(void *pThis, float *pA, float *pB, float *pC, int nA, float fB, bool bC);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);

// FUNCTION: 0x001FCE80 Execute__13BlowingLeavesFv
void BlowingLeaves::Execute() {
    switch (m_unk20) {
    case -1: {
        void *mgr = (char *)gGfxEng + 0x154F00;
        if (mgr == 0) {
            CdsAssert__FPciPc("BlowingLeaves.cpp", 0x25, "apParticleMgr");
        }
        float vecA[4] = {0.0f, 5.0f, 0.0f, 1.0f};
        float vecB[3];
        float vecC[3];
        vecB[0] = m_unk1CC[0];
        vecB[1] = m_unk1CC[1];
        vecB[2] = m_unk1CC[2];
        vecC[0] = m_unk1DC[0];
        vecC[1] = m_unk1DC[1];
        vecC[2] = m_unk1DC[2];
        float fRate = m_unk1B4;
        float lim = (fRate < 100.0f) ? fRate : 100.0f;
        if (lim > 0.0f) {
            fRate = (fRate < 100.0f) ? fRate : 100.0f;
        } else {
            fRate = 0.0f;
        }
        fRate /= 100.0f;
        m_unk1F0 = CreateBlowingLeaves__16PParticleManagerFPfPfPfifb(mgr, vecA, vecB, vecC, m_unk1B0, fRate, m_unk1B8 != 0);
        SetState__15EntityBaseClassFi(this, 0);
        break;
    }
    case 0:
        break;
    case -2: {
        void *mgr = (char *)gGfxEng + 0x154F00;
        if (mgr == 0) {
            CdsAssert__FPciPc("BlowingLeaves.cpp", 0x42, "apParticleMgr");
        }
        Destroy__16PParticleManagerFUi(mgr, m_unk1F0);
        m_unk1F0 = 0;
        break;
    }
    }
}

// FUNCTION: 0x001FD020 __dt__13BlowingLeavesFv
BlowingLeaves::~BlowingLeaves() {
    m_unk0 = __vt__13BlowingLeaves;
    if (m_unk1F0 != 0) {
        void *mgr = gGfxEng + 0x154F00;
        if (mgr == 0) {
            CdsAssert__FPciPc("BlowingLeaves.cpp", 0x14, "apParticleMgr");
        }
        Destroy__16PParticleManagerFUi(mgr, m_unk1F0);
        m_unk1F0 = 0;
    }
    __dt__15EntityBaseClassFv(this, 0);
}

// FUNCTION: 0x001FD0D0 __ct__13BlowingLeavesFv
BlowingLeaves::BlowingLeaves() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 0);
    m_unk0 = __vt__13BlowingLeaves;
    EnableSleep__15EntityBaseClassFbb(this, 0, 0);
    m_unk1F0 = 0;
}
