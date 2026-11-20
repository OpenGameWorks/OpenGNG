#ifndef PZINDAMAGEFX_H
#define PZINDAMAGEFX_H

#include "types.h"
#include "PParticleSystem.h"

class EntityBaseClass;

// Damage effect attached to an entity. The PParticleSystem base occupies the
// first 0xE0 bytes; the members below start at 0xE0. The vtable
// (__vt__12PZinDamageFx) is stored by the constructor and destructor, so the
// class declares no virtuals.
class PZinDamageFx : public PParticleSystem {
public:
    PZinDamageFx();
    ~PZinDamageFx();
    void FadeAndDie(unsigned int nUnused);
    void Render();
    int Create(EntityBaseClass *pOwner, float fArg, unsigned int nArg);

    EntityBaseClass *m_unkE0;   // 0x0E0 owner entity; its byte at 0x1C gates Render
    PParticleSystem *m_unkE4;   // 0x0E4 particle system created by the manager
    float m_unkE8;              // 0x0E8
    float m_unkEC;              // 0x0EC
};

#endif
