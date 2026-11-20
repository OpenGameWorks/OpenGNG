#ifndef PSCROLLINGTREES_H
#define PSCROLLINGTREES_H

#include "types.h"

class PResourceManager;

// The 8 resource ids CreateFloor loads, one per tree record.
struct PScrollingTreeIds {
    unsigned int v[8];
};

// Four floats copied from a literal; the third one steps down each CreateFloor iteration.
struct PScrollingTreeQuad {
    float f[4];
};

// One 0x10-byte record of the tree table at 0x34. The dtor frees the pointer at +0x4.
struct PScrollingTreeEntry {
    int m_unk0;       // 0x0
    void *m_unk4;     // 0x4
    int m_unk8;       // 0x8, element count
    char _pad0C[4];   // 0xC
};

// One 0x50-byte element of a tree record; Animate scrolls the float at +0x38.
struct PScrollingTreeNode {
    char _pad00[0x38];  // 0x00
    float m_unk38;      // 0x38
    char _pad3C[0x14];  // 0x3C
};

class PScrollingTrees {
public:
    PScrollingTrees();
    ~PScrollingTrees();
    void Animate(float fTime);
    void Init(float *pVecA, float *pVecB, float fScale, PResourceManager *pResMgr);
    int CreateFloor();

private:
    char _pad00[0x10];                 // 0x00
    float m_unk10[4];                  // 0x10
    float m_unk20[4];                  // 0x20
    float m_unk30;                     // 0x30
    PScrollingTreeEntry m_unk34[3];    // 0x34
    char _pad64[0xC];                  // 0x64
    char m_unk70[0x600];               // 0x70
    PResourceManager *m_unk670;        // 0x670
};

#endif
