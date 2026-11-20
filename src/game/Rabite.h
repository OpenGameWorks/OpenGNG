#ifndef RABITE_H
#define RABITE_H

#include "types.h"

class EntityBaseClass;

class Rabite {
public:
    Rabite();
    void LoadCorrectMesh();
    void OnWakeEvent();
    int OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB);

    void *m_unk0;                   // 0x000 vtable pointer
    char _pad004[0x20 - 0x04];
    int m_unk20;                    // 0x020 state
    char _pad024[0xEA - 0x24];
    unsigned char m_unkEA;          // 0x0EA cleared by constructor
    char _padEB[0xF8 - 0xEB];
    float m_unkF8;                  // 0x0F8 set to 0.3f by constructor
    float m_unkFC;                  // 0x0FC set to 0.6f by constructor
    char _pad100[0x103 - 0x100];
    unsigned char m_unk103;         // 0x103 set to 0x10 by constructor
    float m_unk104;                 // 0x104 set to 0.5f by constructor
    float m_unk108;                 // 0x108 set to 1.0f by constructor
    char _pad10C[0x15C - 0x10C];
    short m_unk15C;                 // 0x15C cleared by constructor
    short m_unk15E;                 // 0x15E set to 0x100C by constructor
    char _pad160[0x1E0 - 0x160];
    int m_unk1E0;                   // 0x1E0 hit points, reduced by OnHitEvent
    char _pad1E4[0x218 - 0x1E4];
    unsigned char m_unk218;         // 0x218 selects the alternate mesh
    char _pad219[0x21C - 0x219];
    int m_unk21C;                   // 0x21C joint index on the player, -1 when detached
    char _pad220[0x240 - 0x220];
    int m_unk240;                   // 0x240 cleared by destructor
};

#endif
