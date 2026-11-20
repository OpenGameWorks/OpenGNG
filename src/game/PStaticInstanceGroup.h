#ifndef PSTATICINSTANCEGROUP_H
#define PSTATICINSTANCEGROUP_H

#include "types.h"
#include "PMesh.h"

class PPakFile;
class PArray;
struct tagVuStaticInstance;

// Group of static instances: an instance array of 0x50-byte entries, its count, and the master mesh. Size 0xC.
class PStaticInstanceGroup {
public:
    PStaticInstanceGroup();
    ~PStaticInstanceGroup();
    int Load(PPakFile *pFile, PArray *pMasterMeshes, ePsx2FileVersion eVersion);
    unsigned int Render();
    unsigned int RenderParticleInstances(bool bFlag);

    tagVuStaticInstance *m_unk0;     // 0x00 instance array, 0x50 bytes per entry
    int m_unk4;                      // 0x04 instance count
    void *m_unk8;                    // 0x08 master mesh
};

#endif
