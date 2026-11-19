#ifndef TIMING_H
#define TIMING_H

#include "types.h"

class ESubTimer {
public:
    ESubTimer();
    void ZeroTimer();
    void StopTimer();

    char _pad000[0x4];
    int m_unk004;               // 0x004 one-frame value, cleared by ETiming::ZeroAllOneFrameVals
    char _pad008[0x3C - 0x08];
    int m_unk03C;               // 0x03C cleared by the constructor
    int m_unk040;               // 0x040 cleared by the constructor
    char _pad044[0x1];
    unsigned char m_unk045;     // 0x045 nonzero blocks StopSubTimer and FindTimer; set by the constructor
    char _pad046[0x2];
};                              // size 0x48, the ETiming entry stride

class ETiming {
public:
    void ZeroAllOneFrameVals();
    int StopSubTimer(unsigned int nId);
    ESubTimer *FindTimer(unsigned int nId);

    int m_unk0;                 // 0x000 header
    ESubTimer m_aTimers[0x16];  // 0x004 22 timers, 0x48 bytes each
};                              // size 0x634

#endif
