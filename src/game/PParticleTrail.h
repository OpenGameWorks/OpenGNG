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
    void AnimateSmoothTrail();

    float m_unkE0;             // 0x0E0 MulVector output written by ModifyPosition; copied from the params
    float m_unkE4;              // 0x0E4
    float m_unkE8;              // 0x0E8
    char _padEC[0x04];          // 0x0EC
    float m_unkF0;              // 0x0F0
    float m_unkF4;              // 0x0F4
    float m_unkF8;              // 0x0F8
    float m_unkFC;              // 0x0FC
    float m_unk100;             // 0x100
    float m_unk104;             // 0x104
    float m_unk108;             // 0x108
    float m_unk10C;             // 0x10C
    float m_unk110;             // 0x110
    float m_unk114;             // 0x114
    float m_unk118;             // 0x118
    float m_unk11C;             // 0x11C
    float m_unk120;             // 0x120
    float m_unk124;             // 0x124
    float m_unk128;             // 0x128
    char _pad12C[0x04];         // 0x12C
    unsigned int m_unk130;      // 0x130 dead-particle count limit read by Animate
    float m_unk134;             // 0x134
    float m_unk138;             // 0x138
    float m_unk13C;             // 0x13C
    float m_unk140;            // 0x140
    float m_unk144;             // 0x144
    float m_unk148;             // 0x148
    float m_unk14C;             // 0x14C
    float m_unk150;             // 0x150
    float m_unk154;             // 0x154
    float m_unk158;             // 0x158
    float m_unk15C;             // 0x15C
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
