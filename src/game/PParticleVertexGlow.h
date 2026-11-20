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
    void FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar);
    void Render();
    bool Create(tagParticleVertexGlowParams *pParams, PMNode *poGlowObj, PMNode *poAnimObj);

    char _pad0E0[0x260];        // 0x0E0
    PFxMesh m_unk340;           // 0x340 mesh subobject, constructed and destroyed explicitly
    void *m_unk358;             // 0x358 source data pointer; cleared by the constructor and destructor
    char _pad35C[0x4];          // 0x35C
    float m_unk360;             // 0x360 glow colour, passed to SetGlowSizeAndColor
    int m_unk364;               // 0x364 cleared by Create
    int m_unk368;               // 0x368 cleared by Create
    int m_unk36C;               // 0x36C set to 1.0f by Create
    float m_unk370;             // 0x370 glow size, passed to SetGlowSizeAndColor
    int m_unk374;               // 0x374 cleared by the constructor
    int m_unk378;               // 0x378 cleared by the constructor
    int m_unk37C;               // 0x37C cleared by the constructor
    int m_unk380;               // 0x380 cleared by the constructor
};

#endif
