#ifndef PMNODE_H
#define PMNODE_H

#include "types.h"

class PMNode {
public:
    float GetFrameRate();
    int GetWorldMeshCenter(float *pOut);
    void DisableAllHitBox();
    void ScaleSet(float a, float b, float c, float d);
    void DestroyMesh();
    void *GetFirstMesh();
    void StopAmbientSoundsByObject();

    char _pad000[0x10];
    void *m_unk10;          // 0x010 PMesh *
    unsigned int m_unk14;   // 0x014 child count
    unsigned int m_unk18;   // 0x018 child index
    PMNode **m_unk1C;       // 0x01C child array
    char _pad020[0x4];
    void *m_unk24;          // 0x024 object whose vtable slot 0x48 returns a frame rate
    int m_unk28;            // 0x028
    char _pad02C[0x10];
    unsigned char m_unk3C;  // 0x03C
    char _pad03D[0x1];
    unsigned char m_unk3E;  // 0x03E flags: 0x01 owns mesh, 0x08 scale set
    char _pad03F[0x1];
    float m_unk40[4][4];    // 0x040 matrix; row 3 (0x070) is a vector
    char _pad080[0x20];
    float m_unkA0[4];       // 0x0A0
};

#endif
