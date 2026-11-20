#ifndef PPARTICLESPURT_H
#define PPARTICLESPURT_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

struct tagParticleSpurtParams {
    char _pad00[0x80];
    unsigned int m_unk80;       // 0x080 particle count
};

// Spurt emitter. The PParticleSystem base occupies the first 0xE0 bytes; the
// members below start at 0xE0. The constructor zeroes the three pointers at
// 0xE0, 0xE8 and 0xE4, and the destructor releases them with __dla__.
class PParticleSpurt : public PParticleSystem {
public:
    PParticleSpurt();
    int Create(tagParticleSpurtParams *pParams, float fX, float fY, float fZ);
    void ModifyPosition(PMat4 *pMat);
    void SetupBoundingBox();

    void *m_unkE0;              // 0x0E0 owned buffer, released by the destructor
    void *m_unkE4;              // 0x0E4 owned buffer, released by the destructor
    void *m_unkE8;              // 0x0E8 owned buffer, released by the destructor
    char _pad0EC[0x04];         // 0x0EC
    float m_unkF0[4];           // 0x0F0 vector written by ModifyPosition
    char _pad100[0x30];         // 0x100
    float m_unk130[4];          // 0x130 offset vector read by SetupBoundingBox
    float m_unk140[4];          // 0x140 vector written by ModifyPosition
    char _pad150[0x10];         // 0x150
    float m_unk160[4];          // 0x160 vector read by SetupBoundingBox
    char _pad170[0x04];         // 0x170
    float m_unk174;             // 0x174 min selection source for m_unkA0
    float m_unk178;             // 0x178 min selection source for m_unkA0
    float m_unk17C;             // 0x17C min selection source for m_unkA0
    float m_unk180[4];          // 0x180 scale source (x 0.5f) for SetupBoundingBox
    char _pad190[0x04];         // 0x190
    float m_unk194;             // 0x194 scale source (x 0.5f) for SetupBoundingBox
    char _pad198[0x04];         // 0x198
    unsigned char m_unk19C;     // 0x19C nonzero selects the transform path in ModifyPosition
    char _pad19D[0x03];         // 0x19D
    char _pad1A0[0x10];         // 0x1A0
    float m_unk1B0[4];          // 0x1B0 vector normalised by ModifyPosition
    float m_unk1C0[4];          // 0x1C0 vector transformed by ModifyPosition
    float m_unk1D0[3];          // 0x1D0 axis selector set by Create
    char _pad1DC[0x04];         // 0x1DC
    float m_unk1E0;             // 0x1E0 initial value stored in each m_unkE0 slot
    int m_unk1E4;               // 0x1E4 random value set by Create
};

#endif
