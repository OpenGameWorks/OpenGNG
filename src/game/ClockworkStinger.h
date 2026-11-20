#ifndef CLOCKWORKSTINGER_H
#define CLOCKWORKSTINGER_H

#include "types.h"

class PMNode;

class ClockworkStinger {
public:
    void SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2);
    void SetSpawnedFromEntity(float *arg0, float *arg1, int arg2);
    void SetDefaultVars();
    void SetEditableVars(char *arg0);
    void OnStopAttack();
    void OnTimerEvent(unsigned int arg0);
    void OnEffectDelete(unsigned int arg0);
    int GetSequenceState();
    int IsStalled(float arg0, float (*arg1)[4]);
    int MoveTo(float (*arg0)[4]);
    void DetermineStateChange();

    char _pad000[4];
    unsigned int m_unk4;            // 0x004 timer argument for CreateTimer
    char _pad008[0x20 - 0x08];
    int m_unk20;                    // 0x020 state
    char _pad024[0x3C - 0x24];
    PMNode *m_unk3C;                // 0x03C animation node
    char _pad040[0x103 - 0x40];
    unsigned char m_unk103;         // 0x103 ctor default 0x10
    int m_unk104;                   // 0x104 ctor default 2.0f
    int m_unk108;                   // 0x108 ctor default 1.5f
    char _pad10C[0x140 - 0x10C];
    unsigned int *m_unk140;         // 0x140 current sequence
    char _pad144[0x166 - 0x144];
    unsigned char m_unk166;         // 0x166 ctor default 1
    char _pad167[0x1B0 - 0x167];
    int m_unk1B0;                   // 0x1B0 nonzero blocks OnStopAttack
    char _pad1B4[0x1B8 - 0x1B4];
    float m_unk1B8;                 // 0x1B8 copied from arg0[0]
    float m_unk1BC;                 // 0x1BC copied from arg0[1]
    float m_unk1C0;                 // 0x1C0 copied from arg0[2]
    float m_unk1C4;                 // 0x1C4 arg1 in SetRiseAndAttack, 25.0f default
    float m_unk1C8;                 // 0x1C8 copied from arg0[0]
    float m_unk1CC;                 // 0x1CC copied from arg0[1]
    float m_unk1D0;                 // 0x1D0 copied from arg0[2]
    float m_unk1D4;                 // 0x1D4 arg2 in SetRiseAndAttack, 35.0f default
    int m_unk1D8;                   // 0x1D8
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;                   // 0x1E0
    int m_unk1E4;                   // 0x1E4
    int m_unk1E8;                   // 0x1E8
    int m_unk1EC;                   // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    int m_unk1F4;                   // 0x1F4
    int m_unk1F8;                   // 0x1F8 float bits 0.1f
    int m_unk1FC;                   // 0x1FC random 0xB4 or 0x6E
    int m_unk200;
    int m_unk204;
    int m_unk208;
    int m_unk20C;
    int m_unk210;
    int m_unk214;
    int m_unk218;
    int m_unk21C;
    u_long128 m_unk220;             // 0x220 16-byte slot, written by MoveTo
    int m_unk230;
    int m_unk234;
    int m_unk238;
    int m_unk23C;
    int m_unk240;                   // 0x240 timer id slot
    int m_unk244;
    int m_unk248;
    int m_unk24C;
    unsigned int m_unk250;          // 0x250 damage fx handle, destroyed in dtor
    int m_unk254;                   // 0x254 timer id slot
    int m_unk258;                   // 0x258 timer id slot
    unsigned char m_unk25C;
    char _pad25D[3];
    int m_unk260;
    int m_unk264;
    unsigned char m_unk268;
};

#endif
