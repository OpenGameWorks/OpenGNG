#ifndef PSTATICINSTANCEMESH_H
#define PSTATICINSTANCEMESH_H

#include "types.h"
#include "PMesh.h"

class PPakFile;
class PArray;
class PShader;
class PParticleOneShot;

// One 8-byte entry of the instance array: a vertex count and its vertex data.
struct PStaticInstanceEntry {
    unsigned int m_unk0;             // 0x00 vertex count
    void *m_unk4;                    // 0x04 vertex data, freed with __dla__FPv
};

// Static instance mesh: one shader, the entry count, the entry array, and a
// one-shot particle effect. Size 0x14.
class PStaticInstanceMesh {
public:
    PStaticInstanceMesh();
    ~PStaticInstanceMesh();
    int Load(PPakFile *pFile, PArray *pArray, ePsx2FileVersion eVersion);

    PShader *m_unk0;                 // 0x00
    int m_unk4;                      // 0x04
    unsigned int m_unk8;             // 0x08 entry count
    PStaticInstanceEntry *m_unkC;    // 0x0C entry array, 8 bytes each
    PParticleOneShot *m_unk10;       // 0x10
};

#endif
