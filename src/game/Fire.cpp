#include "types.h"
#include "Fire.h"
#include "TimerAPI.h"

// TODO(header): foreign declarations
class EntityBaseClass;
extern unsigned char __vt__4Fire[];
extern TimerAPI mTimerAPI__13EntityManager;
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern char gEng[105360];
extern unsigned int Fire_IdleSeq;
extern unsigned int Steam_IdleSeq;
extern "C" int CheckVariable__15EntityBaseClassFii(void *pThis, int a, int b);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" unsigned int PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" void StopSoundBySoundRef__15EntityBaseClassFUi(void *pThis, unsigned int nRef);
extern "C" void SetAnimLoopCount__6PMNodeFib(void *pThis, int nCount, bool bFlag);
extern "C" void *Find__6PMNodeFUi(void *pThis, unsigned int nId);
extern "C" void ResetCollisions__15EntityBaseClassFv(void *pThis);

// FUNCTION: 0x001B3F70 __dt__4FireFv
Fire::~Fire() {
    m_unk0 = __vt__4Fire;
    __dt__15EntityBaseClassFv(this, 0);
}

// FUNCTION: 0x001B3FF0 OnAttackEvent__4FireFP15EntityBaseClassi
void Fire::OnAttackEvent(EntityBaseClass *arg0, int arg1) {
    if (m_unk1BC == 0) {
        m_unk1BC = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 1, false);
    }
}

// FUNCTION: 0x001B4040 OnTimerEvent__4FireFUi
void Fire::OnTimerEvent(unsigned int arg0) {
    if ((int)arg0 == m_unk1BC) {
        ResetCollisions__15EntityBaseClassFv(this);
        mTimerAPI__13EntityManager.KillTimer(m_unk1BC);
        m_unk1BC = 0;
    }
}

// DRAFT: 0x001B4090 Execute__4FireFv
// note: DIFF 118; original dispatch chain and case-0 block layout differ (tried switch orders, local float, if-chain in -2,1,0,-1 order)
void Fire::Execute() {
    if (m_unk20 == -2) {
        return;
    }
    if (m_unk20 == 1) {
        m_unk1C4 = m_unk1C4 - *(float *)&gEng[0x1E8];
        if (m_unk1C4 <= 0.0f) {
            SetState__15EntityBaseClassFi(this, 0);
        }
        return;
    }
    if (m_unk20 == 0) {
        if (m_unkE9 != 0) {
            unsigned int *seq;
            if (m_unk1B0 != 0) {
                seq = &Steam_IdleSeq;
            } else {
                seq = &Fire_IdleSeq;
            }
            PlaySequence__15EntityBaseClassFPUi(this, seq);
            if (m_unk1B0 == 1 || m_unk1B0 == 2) {
                StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk1C8);
                m_unk1C8 = PlaySound__15EntityBaseClassFUi(this, 0xAF);
            }
            PMNode *node = m_unk3C;
            if (node != 0) {
                SetAnimLoopCount__6PMNodeFib(node, m_unk1B4, 1);
                if (m_unk1B0 == 2) {
                    void *found = Find__6PMNodeFUi(node, 0xA4293D97);
                    if (found == 0) {
                        CdsAssert__FPciPc("Fire.cpp", 0x4F, "pConeNode");
                    }
                    *(int *)((char *)found + 0x2C) = 0;
                    return;
                }
            }
        } else if (m_unk160 == 0) {
            m_unk1C4 = 60.0f * m_unk1B8;
            SetState__15EntityBaseClassFi(this, 1);
            if (m_unk1B0 == 1 || m_unk1B0 == 2) {
                StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk1C8);
                m_unk1C8 = PlaySound__15EntityBaseClassFUi(this, 0x97);
                return;
            }
        }
        return;
    }
    if (m_unk20 == -1) {
        CheckVariable__15EntityBaseClassFii(this, m_unk1B0, 3);
        SetState__15EntityBaseClassFi(this, 0);
        m_unk1BC = 0;
        m_unk1C0 = 0;
        if (m_unk1B0 == 1 || m_unk1B0 == 2) {
            m_unk1C8 = PlaySound__15EntityBaseClassFUi(this, 0x97);
        }
    }
}

// FUNCTION: 0x001B4290 __ct__4FireFv
Fire::Fire() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 0);
    m_unk0 = __vt__4Fire;
    m_unk1BC = 0;
    m_unk10C = 0x02000108;
}
