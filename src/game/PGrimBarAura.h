#ifndef PGRIMBARAURA_H
#define PGRIMBARAURA_H

#include "types.h"
#include "PParticleSystem.h"

// Aura particle system used by the Grim Bar. The PParticleSystem base occupies
// the first 0xE0 bytes; the members below start at 0xE0. The vtable
// (__vt__12PGrimBarAura) is stored by the constructor and destructor.
class PGrimBarAura : public PParticleSystem {
public:
    PGrimBarAura();
    void EnableParticle(int nIndex, bool bEnable);
    void SetParticlePos(int nIndex, float *pPos);
    int Create(int nNum, float fA, float fB, float fC, float *pPos);

    char *m_unkE0;              // 0x0E0 particle array, 0x20 bytes per element; freed by the destructor
    char _pad0E4[0xC];          // 0x0E4
    u_long128 m_unkF0;          // 0x0F0 position copied from the Create argument
    float m_unk100;             // 0x100 Create argument, decay input
    float m_unk104;             // 0x104 Create argument
    float m_unk108;             // 0x108 -(1 / (60 * (1 - m_unk100))), clamped to at least 2
    int m_unk10C;               // 0x10C 1.0f in the constructor
};

#endif
