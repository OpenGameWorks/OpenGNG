#ifndef PPARTICLEVERTEXGLOW_H
#define PPARTICLEVERTEXGLOW_H

#include "types.h"
#include "PParticleSystem.h"

class PFrustrum;
class PMNode;
struct tagParticleVertexGlowParams;

// Placeholder for the PFxMesh subobject: its constructor and destructor are
// defined elsewhere in the original, and only the 0x18-byte layout is known.
class PFxMesh {
public:
    PFxMesh();
    ~PFxMesh();
    char _pad000[0x18];
};

// Vertex glow particle system. The PParticleSystem base occupies the first
// 0xE0 bytes; the members below start at 0xE0.
class PParticleVertexGlow : public PParticleSystem {
public:
    void Start();
    void FadeAndDie(unsigned int nUnused);
    void FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar);
    void Render();
    void Animate(float fDelta);
    bool Create(tagParticleVertexGlowParams *pParams, PMNode *poGlowObj, PMNode *poAnimObj);

    float m_unkE0[4];           // 0x0E0 vector scratch used by Animate
    float m_unkF0[4];           // 0x0F0 vector scratch used by Animate
    float m_unk100[4];          // 0x100 vector scratch used by Animate
    char _pad110[0x4];          // 0x110
    float m_unk114;             // 0x114 limit of the first animation timer
    float m_unk118;             // 0x118 first key of the glow size lerp
    float m_unk11C;             // 0x11C middle key of the glow size lerp
    float m_unk120;             // 0x120 last key of the glow size lerp
    float m_unk124;             // 0x124 limit of the second animation timer
    char _pad128[0x218];        // 0x128
    PFxMesh m_unk340;           // 0x340 mesh subobject, constructed and destroyed explicitly
    void *m_unk358;             // 0x358 source data pointer; cleared by the constructor and destructor
    char _pad35C[0x4];          // 0x35C
    float m_unk360;             // 0x360 glow colour, passed to SetGlowSizeAndColor
    int m_unk364;               // 0x364 cleared by Create
    int m_unk368;               // 0x368 cleared by Create
    int m_unk36C;               // 0x36C set to 1.0f by Create
    float m_unk370;             // 0x370 glow size, passed to SetGlowSizeAndColor
    float m_unk374;             // 0x374 second animation timer, cleared by the constructor
    float m_unk378;             // 0x378 second timer rate, cleared by the constructor
    float m_unk37C;             // 0x37C first animation timer, cleared by the constructor
    float m_unk380;             // 0x380 first timer rate, cleared by the constructor
};

#endif
