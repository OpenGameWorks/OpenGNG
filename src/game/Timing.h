#ifndef TIMING_H
#define TIMING_H

#include "types.h"

struct PMat4;

class ESubTimer {
public:
    ESubTimer();
    void ZeroTimer();
    void StartTimer();
    void StopTimer();
    void GenerateStringWSuffix(char *pOut, unsigned int nArg);

    int m_unk000;               // 0x000 start counter sample, read by StopTimer
    unsigned int m_unk004;      // 0x004 one-frame value, cleared by ETiming::ZeroAllOneFrameVals
    unsigned int m_unk008;      // 0x008 maximum of m_unk004
    char _pad00C[0x14 - 0x0C];
    unsigned int m_unk014;      // 0x014 maximum of m_unk004
    char _pad018[0x3C - 0x18];
    int m_unk03C;               // 0x03C cleared by the constructor
    int m_unk040;               // 0x040 cleared by the constructor
    unsigned char m_unk044;     // 0x044 running flag, cleared by StopTimer
    unsigned char m_unk045;     // 0x045 nonzero blocks StopSubTimer and FindTimer; set by the constructor
    char _pad046[0x2];
};                              // size 0x48, the ETiming entry stride

class ETiming {
public:
    void PrintDisplayListStatusMeter(unsigned int nUnused, PMat4 *pMat);
    int GenerateStringWSuffixAndCat(char *pDest, unsigned int nId);
    void ZeroAllOneFrameVals();
    int StartSubTimer(unsigned int nId);
    int InitSubTimer(unsigned int nId, const char *pName, unsigned int nArg);
    int StopSubTimer(unsigned int nId);
    ESubTimer *FindTimer(unsigned int nId);

    int m_unk0;                 // 0x000 header
    ESubTimer m_aTimers[0x16];  // 0x004 22 timers, 0x48 bytes each
};                              // size 0x634

#endif
