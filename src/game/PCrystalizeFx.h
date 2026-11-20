#ifndef PCRYSTALIZEFX_H
#define PCRYSTALIZEFX_H

#include "types.h"
#include "PParticleSystem.h"

class PMNode;

// Crystalize particle effect. The PParticleSystem base occupies the first
// 0xE0 bytes; the members below start at 0xE0. The vtable (__vt__13PCrystalizeFx)
// is stored by the constructor and destructor, not by a C++ virtual.
class PCrystalizeFx : public PParticleSystem {
public:
    PCrystalizeFx();
    void GetValidNodes(PMNode *pNode, PMNode **pOut);
    void Render();
    void Animate(float fDelta);
    void UpdateInstances();

    char m_unkE0[0x100];        // 0x0E0 cleared by the constructor (memset)
    void *m_unk1E0;             // 0x1E0 freed with __dla__ by the destructor
    int m_unk1E4;               // 0x1E4 count of valid nodes collected by GetValidNodes (max 0x41)
    void *m_unk1E8;             // 0x1E8 effect block: shader, count, entry array
    int m_unk1EC;               // 0x1EC
    void *m_unk1F0;             // 0x1F0
    int m_unk1F4;               // 0x1F4 copied to m_unkD0 by Animate
    unsigned char m_unk1F8;     // 0x1F8 set to 1 by the constructor
    unsigned char m_unk1F9;     // 0x1F9 set to 1 by the constructor
    unsigned char m_unk1FA;     // 0x1FA set to 1 by the constructor
};

#endif
