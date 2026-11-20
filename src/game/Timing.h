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
    int GenerateStringWSuffix(char *pOut, unsigned int nArg);
    void GenerateString(char *pOut, unsigned int nArg, unsigned int nArg2);
    int GetTime();

    int m_unk000;               // 0x000 start counter sample, read by StopTimer
    unsigned int m_unk004;      // 0x004 one-frame value, cleared by ETiming::ZeroAllOneFrameVals
    unsigned int m_unk008;      // 0x008 maximum of m_unk004
    unsigned int m_unk00C;      // 0x00C cleared by ZeroTimer
    unsigned int m_unk010;      // 0x010 cleared by ZeroTimer
    unsigned int m_unk014;      // 0x014 maximum of m_unk004
    char _pad018[0x3C - 0x18];
    int m_unk03C;               // 0x03C cleared by the constructor
    int m_unk040;               // 0x040 cleared by the constructor
    unsigned char m_unk044;     // 0x044 running flag, cleared by StopTimer
    unsigned char m_unk045;     // 0x045 nonzero blocks StopSubTimer and FindTimer; set by the constructor
    unsigned char m_unk046;     // 0x046 cleared by ZeroTimer
    char _pad047[0x1];
};                              // size 0x48, the ETiming entry stride

class ETiming {
public:
    void PrintPerformanceMeter(unsigned int nUnused, PMat4 *pMat);
    void PrintDisplayListStatusMeter(unsigned int nUnused, PMat4 *pMat);
    void PrintCalcTimings();
    void PrintRenderTimings();
    int GenerateStringWSuffixAndCat(char *pDest, unsigned int nId);
    void ZeroAllOneFrameVals();
    int StartSubTimer(unsigned int nId);
    int InitSubTimer(unsigned int nId, const char *pName, unsigned int nArg);
    int StopSubTimer(unsigned int nId);
    ESubTimer *FindTimer(unsigned int nId);
    void MaxesUpdate();
    void InitTimers();

    int m_unk0;                 // 0x000 header
    ESubTimer m_aTimers[0x16];  // 0x004 22 timers, 0x48 bytes each
    char _pad634[0x640 - 0x634];
    char m_unk640[0x890 - 0x640];  // 0x640 PProgressBar, first performance bar
    char m_unk890[0xD30 - 0x890];  // 0x890 PProgressBar, second performance bar
    unsigned int m_unkD30;      // 0xD30 ring index into the per-frame max history, wraps at 9
    int m_unkD34;               // 0xD34 countdown, reset to 0x14 when it reaches zero
    int m_unkD38;               // 0xD38 frame value, read by the print functions
};                              // size 0xD3C

#endif
