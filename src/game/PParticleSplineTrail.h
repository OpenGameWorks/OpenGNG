#ifndef PPARTICLESPLINETRAIL_H
#define PPARTICLESPLINETRAIL_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
class PFrustrum;
struct tagVuParticle;
struct tagVuSplineKey;
struct tagParticleSplineTrailParams;

// Spline trail emitter. The PParticleSystem base occupies the first 0xE0 bytes;
// the members below start at 0xE0.
class PParticleSplineTrail : public PParticleSystem {
public:
    void Start();
    void ComputeVuSplineKeys(struct tagVuParticle *pParticles, int nUnused, struct tagVuSplineKey *pKeys, int nCount);
    void SetPosition(float *pFrom, float *pTo);
    void ModifyPosition(PMat4 *pMat);
    void Render();
    void FrustrumTest(PFrustrum *pFrustum, float *pVec, float fA, float fB);
    void Animate(float fDelta);
    void UpdateTrailKeys();
    int Create(struct tagParticleSplineTrailParams *pParams, float fA, float fB, float fC);

    float m_unkE0[4];           // 0x0E0 offset vector passed to PMat4::MulVector by ModifyPosition
    float m_unkF0[4];           // 0x0F0
    float m_unk100[4];          // 0x100
    int m_unk110;               // 0x110 particle count base; Render allocates m_unk110 + 2 entries
    int m_unk114;               // 0x114 divisor for the fx scale passed to DrawSplineParticles
    float m_unk118;             // 0x118 lower bound of the length range used by Create
    float m_unk11C;             // 0x11C upper bound of the length range used by Create
    float m_unk120;             // 0x120
    float m_unk124;             // 0x124
    float m_unk128;             // 0x128 decrement applied to m_unk160 by Animate
    char _pad12C[0x14];         // 0x12C
    int m_unk140;               // 0x140 key count base used by ComputeVuSplineKeys
    char _pad144[0xC];          // 0x144
    float m_unk150[4];          // 0x150 source vector copied by SetPosition and ModifyPosition
    float m_unk160;             // 0x160 set to 1.0f by Start
};

#endif
