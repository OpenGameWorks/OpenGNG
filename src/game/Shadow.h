#ifndef SHADOW_H
#define SHADOW_H

#include "types.h"

class PShadowVolume;

// Shadow: one entry per shadowed entity. Size 0x10.
// Enum names are inferred from the constructors. Float ctor: eType 0 loads
// the mesh through PResourceManager and PMNode::GetFirstMesh; any other value
// skips the mesh. Uint ctor: eType 1 (eShadowParticle) registers a particle
// shadow volume; any other value leaves m_unk4 cleared.
class Shadow {
public:
    enum ShadowType {
        eShadowNone = 0,
        eShadowParticle = 1,
        eShadowMesh = 2
    };

    unsigned char m_unk0;   // 0x00 flag, cleared by both ctors
    char _pad1[3];
    void *m_unk4;           // 0x04 mesh from PMNode::GetFirstMesh, cleared by dtor
    float m_unk8;           // 0x08 float value from the float ctor
    PShadowVolume *m_unkC;  // 0x0C shadow volume registered with PShadowBuffer
};

#endif
