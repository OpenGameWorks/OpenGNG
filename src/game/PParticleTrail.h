#ifndef PPARTICLETRAIL_H
#define PPARTICLETRAIL_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

// Parameter block passed to PParticleTrail::Create. The first 0xA0 bytes are
// copied into the trail at 0xE0; m_unk50 is the particle count.
struct tagParticleTrailParams {
    char _pad0[0x50];
    unsigned int m_unk50;       // 0x50 particle count
    char _pad54[0x4C];
};

// Trail emitter. The PParticleSystem base occupies the first 0xE0 bytes; the
// members below start at 0xE0. The constructor clears the two buffer pointers
// at 0x180 and 0x184 and the int at 0x1B8. The destructor releases the two
// buffers with __dla__.
class PParticleTrail : public PParticleSystem {
public:
    PParticleTrail();
    ~PParticleTrail();
    void Start();
    void Animate(float fDt);
    void ModifyPosition(PMat4 *pMat);
    void SetPosition(float *pPos, float *pUnused);
    int Create(tagParticleTrailParams *pParams, float fA, float fB, float fC);

    float m_unkE0;             // 0x0E0 MulVector output written by ModifyPosition; copied from the params
    float m_unkE4;              // 0x0E4
    float m_unkE8;              // 0x0E8
    char _padEC[0x34];          // 0x0EC
    float m_unk120;             // 0x120
    float m_unk124;             // 0x124
    float m_unk128;             // 0x128
    char _pad12C[0x08];         // 0x12C
    float m_unk134;             // 0x134
    float m_unk138;             // 0x138
    float m_unk13C;             // 0x13C
    char _pad140[0x04];         // 0x140
    float m_unk144;             // 0x144
    char _pad148[0x10];         // 0x148
    float m_unk158;             // 0x158
    char _pad15C[0x04];         // 0x15C
    unsigned char m_unk160;     // 0x160 nonzero selects the 0x10-byte buffer layout
    char _pad161[0x1F];         // 0x161
    void *m_unk180;             // 0x180 owned buffer, released by the destructor
    void *m_unk184;             // 0x184 owned buffer, released by the destructor
    char _pad188[0x08];         // 0x188
    float m_unk190[4];          // 0x190 position read by ModifyPosition and written by SetPosition
    float m_unk1A0[4];          // 0x1A0 copy of m_unk190 made at the start of ModifyPosition and SetPosition
    float m_unk1B0;             // 0x1B0
    int m_unk1B4;               // 0x1B4 cleared by Start
    int m_unk1B8;               // 0x1B8 cleared by the constructor
    int m_unk1BC;               // 0x1BC
};

#endif
