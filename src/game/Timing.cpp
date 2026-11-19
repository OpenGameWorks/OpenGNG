#include "types.h"
#include "Timing.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *pMem);

// FUNCTION: 0x001699C0 __ct__9ESubTimerFv
ESubTimer::ESubTimer() {
    ZeroTimer();
    m_unk040 = 0;
    m_unk03C = 0;
    m_unk045 = 1;
}

// DRAFT: 0x00169E30 ZeroAllOneFrameVals__7ETimingFv
// note: guarded do-while matches the loop; 4 differing lines remain, one extra nop before the loop bnez; top-tested, counted and byte-step forms were worse.
void ETiming::ZeroAllOneFrameVals() {
    ESubTimer *pTimer = m_aTimers;
    ESubTimer *pEnd = (ESubTimer *)((char *)this + 0x634);
    if (pTimer < pEnd) {
        do {
            pTimer->m_unk004 = 0;
            pTimer++;
        } while (pTimer < pEnd);
    }
}

// FUNCTION: 0x00169FF0 StopSubTimer__7ETimingFUi
int ETiming::StopSubTimer(unsigned int nId) {
    if (nId >= 0x16) {
        return 0;
    }
    ESubTimer *pTimer = &m_aTimers[nId];
    if (pTimer->m_unk045 != 0) {
        return 0;
    }
    pTimer->StopTimer();
    return 1;
}

// FUNCTION: 0x0016A130 FindTimer__7ETimingFUi
ESubTimer *ETiming::FindTimer(unsigned int nId) {
    if (nId >= 0x16) {
        return 0;
    }
    ESubTimer *pTimer = &m_aTimers[nId];
    if (pTimer->m_unk045 != 0) {
        return 0;
    }
    return pTimer;
}

// FUNCTION: 0x0016A390 __dt__9ESubTimerFv
extern "C" void *__dt__9ESubTimerFv(ESubTimer *pThis, short nFlag) {
    if (pThis != 0) {
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
