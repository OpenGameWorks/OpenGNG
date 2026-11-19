#ifndef CLOCKWORKSTALKER_H
#define CLOCKWORKSTALKER_H

#include "types.h"

// ClockworkStalker derives from EntityBaseClass; the base is not declared here,
// so every member is named by its offset from the object start.
class ClockworkStalker {
public:
    void DeleteEffects();
    int InBlockableState();
    int PlayerFacingUs();
    void OnWakeEvent();
    void OnStopAttack();

    char _pad000[0x20];
    int m_unk20;                    // 0x020 state
    char _pad024[0x3C - 0x24];
    char *m_unk3C;                  // 0x03C
    char _pad040[0x140 - 0x40];
    unsigned int *m_unk140;         // 0x140
    char _pad144[0x163 - 0x144];
    unsigned char m_unk163;         // 0x163
    char _pad164[0x190 - 0x164];
    char m_unk190;                  // 0x190 start of the embedded EntityBaseClass block
    char _pad191[0x2E0 - 0x191];
    unsigned int m_unk2E0;          // 0x2E0 effect id
    unsigned int *m_unk2E4;         // 0x2E4 sequence pointer
};

#endif
