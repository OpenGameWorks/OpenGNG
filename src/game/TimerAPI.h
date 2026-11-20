#ifndef TIMERAPI_H
#define TIMERAPI_H

#include "types.h"

// Timer node: 0x10 bytes, allocated with __nw(0x10).
struct TimerNode {
    unsigned long long nTime;
    unsigned int nId;
    int nSeq;
};

// PList link: data pointer at 0x00, next link at 0x04.
struct TimerLink {
    void *pData;
    TimerLink *pNext;
};

class EntityManager;

// Timer list owner, embedded as a static (EntityManager::mTimerAPI). Size 0x28:
// sequence counter at 0x00, PList block at 0x04 (list head at 0x08, cursor at 0x10),
// two 8-byte fields at 0x18 and 0x20.
class TimerAPI {
public:
    TimerAPI();
    void KillAllApparitionTimers(unsigned int nId, bool bFlag);
    void ProcessTimers(EntityManager *pEntityManager);
    void KillTimer(unsigned int nSeq);
    int CreateTimer(unsigned int nId, unsigned int nTime, bool bPal);

private:
    int m_unk0;
    char m_unk4[4];
    TimerLink *m_unk8;
    void *m_unkC;
    TimerLink *m_unk10;
    char m_unk14[4];
    unsigned long long m_unk18;
    unsigned long long m_unk20;
};

#endif
