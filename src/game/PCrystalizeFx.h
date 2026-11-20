#ifndef PCRYSTALIZEFX_H
#define PCRYSTALIZEFX_H

#include "types.h"
#include "PParticleSystem.h"

class PMNode;
struct tagCrystalizeFxParams;

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
    int Create(PMNode *pNode, tagCrystalizeFxParams *pParams);

    char m_unkE0[0x100];        // 0x0E0 cleared by the constructor (memset)
    void *m_unk1E0;             // 0x1E0 freed with __dla__ by the destructor
    int m_unk1E4;               // 0x1E4 count of valid nodes collected by GetValidNodes (max 0x41)
    void *m_unk1E8;             // 0x1E8 effect block: shader, count, entry array
    float m_unk1EC;             // 0x1EC matrix element range start
    float m_unk1F0;             // 0x1F0 matrix element range end
    int m_unk1F4;               // 0x1F4 copied to m_unkD0 by Animate
    unsigned char m_unk1F8;     // 0x1F8 set to 1 by the constructor
    unsigned char m_unk1F9;     // 0x1F9 set to 1 by the constructor
    unsigned char m_unk1FA;     // 0x1FA set to 1 by the constructor
};

// Parameter block for PCrystalizeFx::Create. Offsets follow the Create asm.
struct tagCrystalizeFxParams {
    float m_unk00;
    float m_unk04;
    float m_unk08;
    float m_unk0C;
    float m_unk10;
    float m_unk14;
    float m_unk18;
    int m_unk1C;
    unsigned char m_unk20;
    unsigned char m_unk21;
    unsigned char m_unk22;
};

#endif
