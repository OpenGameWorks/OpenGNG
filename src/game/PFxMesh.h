#ifndef PFXMESH_H
#define PFXMESH_H

#include "types.h"
#include "PArray.h"

class PMat4;
class PMesh;
class PMNode;

// Effect mesh node: a world matrix, a mesh to draw, and child PFxMesh
// nodes kept in an embedded PArray (size 0x18).
class PFxMesh {
public:
    PFxMesh();
    ~PFxMesh();
    void Render();
    bool Init(PMNode *pFxObj, PMNode *pAnimObj);

    PMat4 *m_unk0;      // 0x00
    PMesh *m_unk4;      // 0x04
    PArray m_unk8;      // 0x08 child count, index, storage, unused
};

#endif
