#ifndef PMESHNODEANIMDATA_H
#define PMESHNODEANIMDATA_H

#include "types.h"
#include "PArray.h"

class PAnim;
class PPakFile;

#include "Psx2FileVersion.h"

// One 0x28-byte fx trigger record held in PMeshNodeAnimData::m_unk8; only the two trailing words are named.
struct tagPMeshNodeFxTrigger {
    char _pad00[0x20];
    int m_unk20;                     // 0x20
    int m_unk24;                     // 0x24
};

// Per-node animation data: an int at 0x00, the PAnim at 0x04, and a PArray of fx trigger records at 0x08. Size 0x18.
class PMeshNodeAnimData {
public:
    PMeshNodeAnimData();
    ~PMeshNodeAnimData();
    void DestroyFxTriggers();
    int LoadFxTriggers(PPakFile *pFile);
    int Load(PPakFile *pFile, ePsx2FileVersion eVersion);

    int m_unk0;                      // 0x00
    PAnim *m_unk4;                   // 0x04
    PArray m_unk8;                   // 0x08 fx trigger records
};

#endif
