#include "types.h"
#include "Debug.h"
#include "RainTrigger.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
extern unsigned char __vt__11RainTrigger[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" void SetRainDensity__16PParticleManagerFfb(void *pThis, float fDensity, bool bFlag);
extern "C" void SetLightningDensity__16PParticleManagerFf(void *pThis, float fDensity);
extern char gGfxEng[1504384];
extern char *mPlayerAPI__13EntityManager;

// FUNCTION: 0x001CD6A0 __dt__11RainTriggerFv
extern "C" RainTrigger *__dt__11RainTriggerFv(RainTrigger *pThis, short nFlag)
{
    if (pThis != 0) {
        pThis->m_unk0 = __vt__11RainTrigger;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001CD700 GetClassName__11RainTriggerFv
const char *RainTrigger::GetClassName() {
    return "RainTrigger";
}

// FUNCTION: 0x001CD710 SetEditableVars__11RainTriggerFPc
void RainTrigger::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x1C);
}

// FUNCTION: 0x001CD720 Execute__11RainTriggerFv
void RainTrigger::Execute()
{
    char *pPlayer;
    char *pTarget;
    char *pAlt;
    char *pSelf;
    void *mgr;

    switch (m_unk20) {
    case -1:
        SetState__15EntityBaseClassFi(this, 0);
        break;
    case 0: {
        if (m_unk1CC == 0) {
            pPlayer = mPlayerAPI__13EntityManager;
            pAlt = *(char **)(pPlayer + 0x3C);
            pTarget = pPlayer + 0x190;
            if (pAlt != 0) {
                pTarget = pAlt + 0x80;
            }
            pSelf = (char *)m_unk190;
            pAlt = (char *)m_unk3C;
            if (pAlt != 0) {
                pSelf = pAlt + 0x80;
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pSelf, (float (*)[4])pTarget) <= m_unk1C8) {
                SetState__15EntityBaseClassFi(this, 1);
            }
        }
        {
            char *pP = mPlayerAPI__13EntityManager;
            char *pA = *(char **)(pP + 0x3C);
            pTarget = pP + 0x190;
            if (pA != 0) {
                pTarget = pA + 0x80;
            }
        }
        pSelf = (char *)m_unk190;
        pAlt = (char *)m_unk3C;
        if (pAlt != 0) {
            pSelf = pAlt + 0x80;
        }
        if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pSelf, (float (*)[4])pTarget) <= m_unk1C8)) {
            m_unk1CC = 0;
        }
        break;
    }
    case 1: {
        mgr = gGfxEng + 0x154F00;
        if (mgr == 0) {
            CdsAssert("RainTrigger.cpp", 0x2D, "apParticleMgr");
        }
        SetRainDensity__16PParticleManagerFfb(mgr, m_unk1B0, m_unk1B4 != 0);
        SetLightningDensity__16PParticleManagerFf(mgr, m_unk1B8);
        m_unk1CC = 1;
        SetState__15EntityBaseClassFi(this, 0);
        break;
    }
    case -2:
        break;
    }
}

// FUNCTION: 0x001CD880 __ct__11RainTriggerFv
extern "C" RainTrigger *__ct__11RainTriggerFv(RainTrigger *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 2, 0);
    pThis->m_unk0 = __vt__11RainTrigger;
    pThis->m_unk1CC = 0;
    return pThis;
}
