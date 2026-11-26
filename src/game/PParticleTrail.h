#ifndef PPARTICLETRAIL_H
#define PPARTICLETRAIL_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;

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

    char _pad0E0[0xA0];         // 0x0E0 MulVector output written by ModifyPosition; the trail's own state up to 0x180
    void *m_unk180;             // 0x180 owned buffer, released by the destructor
    void *m_unk184;             // 0x184 owned buffer, released by the destructor
    char _pad188[0x08];         // 0x188
    float m_unk190[4];          // 0x190 position read by ModifyPosition and written by SetPosition
    float m_unk1A0[4];          // 0x1A0 copy of m_unk190 made at the start of ModifyPosition and SetPosition
    char _pad1B0[0x04];         // 0x1B0
    int m_unk1B4;               // 0x1B4 cleared by Start
    int m_unk1B8;               // 0x1B8 cleared by the constructor
};

#endif
