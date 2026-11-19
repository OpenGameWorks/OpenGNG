#include "types.h"
#include "ClockworkStinger.h"

// TODO(header): foreign declarations
class TimerAPI {
public:
    char _pad000[40];
    void KillTimer(unsigned int);
    int CreateTimer(unsigned int, unsigned int, bool);
};
extern TimerAPI mTimerAPI__13EntityManager;
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern unsigned char __vt__16ClockworkStinger[];
extern int miRandom__7MathAPI;

// FUNCTION: 0x001E6BA0 SetRiseAndAttack__16ClockworkStingerFPA4_fff
void ClockworkStinger::SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2) {
    m_unk1B8 = arg0[0][0];
    m_unk1BC = arg0[0][1];
    m_unk1C0 = arg0[0][2];
    m_unk1C8 = arg0[0][0];
    m_unk1CC = arg0[0][1];
    m_unk1D0 = arg0[0][2];
    m_unk1C4 = arg1;
    m_unk1D4 = arg2;
}

// FUNCTION: 0x001E6CB0 SetDefaultVars__16ClockworkStingerFv
void ClockworkStinger::SetDefaultVars() {
    miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
    m_unk1FC = !(miRandom__7MathAPI & 1) ? 0xB4 : 0x6E;
    *(int *)&m_unk1C4 = 0x41C80000;
    *(int *)&m_unk1D4 = 0x420C0000;
    m_unk1B0 = 0;
    m_unk1E0 = 0;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1D8 = 0;
    m_unk1F8 = 0x3DCCCCCD;
    m_unk1F4 = 0;
}

// FUNCTION: 0x001E6DE0 OnStopAttack__16ClockworkStingerFv
void ClockworkStinger::OnStopAttack() {
    if ((m_unk1B0 == 0) && (m_unk20 != 4)) {
        m_unk258 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 2, false);
        SetState__15EntityBaseClassFi(this, 4);
    }
}

// FUNCTION: 0x001E6E40 OnTimerEvent__16ClockworkStingerFUi
void ClockworkStinger::OnTimerEvent(unsigned int arg0) {
    if (arg0 == (unsigned int)m_unk240) {
        m_unk240 = 0;
        return;
    }
    if (arg0 == (unsigned int)m_unk254) {
        m_unk254 = 0;
        return;
    }
    if (arg0 == (unsigned int)m_unk258) {
        m_unk258 = 0;
    }
}

// FUNCTION: 0x001E8CF0 __dt__16ClockworkStingerFv
extern "C" ClockworkStinger *__dt__16ClockworkStingerFv(ClockworkStinger *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__16ClockworkStinger;
        DestroyDamageFx__15EntityBaseClassFUi(pThis, pThis->m_unk250);
        pThis->m_unk250 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
