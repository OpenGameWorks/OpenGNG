#include "types.h"
#include "BlowingLeaves.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__13BlowingLeaves[];
extern char gGfxEng[1504384];
extern u_long128 lit_0024E340;
extern "C" void Destroy__16PParticleManagerFUi(void *pThis, unsigned int hSystem);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" unsigned int CreateBlowingLeaves__16PParticleManagerFPfPfPfifb(void *pThis, float *pA, float *pB, float *pC, int nA, float fB, bool bC);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);

// DRAFT: 0x001FCE80 Execute__13BlowingLeavesFv
// note: DIFF 94: this in s0 (original s1, so mgr takes s1 instead of s0); -2 block inline with bne (original beq out-of-line at 0x1FCFD4). Tried early-return if-chain (94), switch (94), -2/-1/0 else-if chain (97), -2/0/-1 else-if chain (94).
void BlowingLeaves::Execute() {
    if (m_unk20 == -2) {
        void *mgr = gGfxEng;
        if (mgr == 0) {
            CdsAssert__FPciPc("BlowingLeaves.cpp", 0x42, "apParticleMgr");
        }
        Destroy__16PParticleManagerFUi(mgr, m_unk1F0);
        m_unk1F0 = 0;
    } else if (m_unk20 == 0) {
    } else if (m_unk20 == -1) {
        void *mgr = gGfxEng;
        if (mgr == 0) {
            CdsAssert__FPciPc("BlowingLeaves.cpp", 0x25, "apParticleMgr");
        }
        float vecA[4];
        float vecB[3];
        float vecC[3];
        float clamped = m_unk1B4;
        float lim = 100.0f;
        *(u_long128 *)vecA = *(u_long128 *)&lit_0024E340;
        vecB[0] = m_unk1CC[0];
        vecB[1] = m_unk1CC[1];
        vecB[2] = m_unk1CC[2];
        vecC[0] = m_unk1DC[0];
        vecC[1] = m_unk1DC[1];
        vecC[2] = m_unk1DC[2];
        if (clamped < 100.0f) {
            lim = clamped;
        }
        if (lim <= 0.0f) {
            clamped = 0.0f;
        } else if (m_unk1B4 >= 100.0f) {
            clamped = 100.0f;
        }
        m_unk1F0 = CreateBlowingLeaves__16PParticleManagerFPfPfPfifb(mgr, vecA, vecB, vecC, m_unk1B0, clamped / 100.0f, m_unk1B8 != 0);
        SetState__15EntityBaseClassFi(this, 0);
    }
}

// FUNCTION: 0x001FD020 __dt__13BlowingLeavesFv
BlowingLeaves::~BlowingLeaves() {
    m_unk0 = __vt__13BlowingLeaves;
    if (m_unk1F0 != 0) {
        void *mgr = gGfxEng;
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
