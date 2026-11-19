#ifndef CLOCKWORKSTALKER_H
#define CLOCKWORKSTALKER_H

#include "types.h"

// ClockworkStalker derives from EntityBaseClass; the base is not declared here,
// so every member is named by its offset from the object start.
class ClockworkStalker {
public:
    void KillTimers();
    void DeleteEffects();
    int InBlockableState();
    int IsStalled(float fDist, float (*arg1)[4]);
    int PlayerFacingUs();
    void SetDefaultVars();
    void SetEditableVars(char *arg0);
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
    char _pad191[0x1B4 - 0x191];
    // 0x1B0..0x1FB is also the 0x4C-byte block copied by SetEditableVars
    int m_unk1B4;                   // 0x1B4
    int m_unk1B8;                   // 0x1B8
    int m_unk1BC;                   // 0x1BC
    int m_unk1C0;                   // 0x1C0
    int m_unk1C4;                   // 0x1C4 float bits 25.0f
    char _pad1C8[0x1D4 - 0x1C8];
    int m_unk1D4;                   // 0x1D4 float bits 35.0f
    int m_unk1D8;                   // 0x1D8
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;                   // 0x1E0
    int m_unk1E4;                   // 0x1E4
    int m_unk1E8;                   // 0x1E8
    int m_unk1EC;                   // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    int m_unk1F4;                   // 0x1F4
    int m_unk1F8;                   // 0x1F8 float bits 0.1f
    int m_unk1FC;                   // 0x1FC
    char _pad200[0x210 - 0x200];
    int m_unk210;                   // 0x210
    int m_unk214;                   // 0x214 timer id slot
    char _pad218[0x240 - 0x218];
    char m_unk240[0x2AC - 0x240];   // 0x240 MathAPI object, passed as this to DistanceXZ
    int m_unk2AC;                   // 0x2AC timer id slot
    char _pad2B0[0x2D0 - 0x2B0];
    int m_unk2D0;                   // 0x2D0 timer id slot
    char _pad2D4[0x2D8 - 0x2D4];
    int m_unk2D8;                   // 0x2D8 timer id slot
    char _pad2DC[0x2E0 - 0x2DC];
    unsigned int m_unk2E0;          // 0x2E0 effect id
    unsigned int *m_unk2E4;         // 0x2E4 sequence pointer
    unsigned int m_unk2E8;          // 0x2E8 damage fx handle, destroyed in dtor
};

#endif
