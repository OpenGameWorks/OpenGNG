#ifndef PSHADOWVOLUME_H
#define PSHADOWVOLUME_H

#include "types.h"
#include "PArray.h"

class PMNode;
class PPakFile;

// Shadow node built by Load (0x28 bytes from __nw__FUi(0x28)).
struct PShadowVolumeNode {
    int m_unk0;                 // 0x00 id matched against PMNode::Find
    void *m_unk4;               // 0x04 vertex data, freed with delete[] when m_unk24 is set
    unsigned int m_unk8;        // 0x08 vertex data size in bytes
    char m_unkC[0x10];          // 0x0C copied from the file entry
    void *m_unk1C;              // 0x1C set by SetShadowCaster
    void *m_unk20;              // 0x20 set by SetShadowCaster
    unsigned char m_unk24;      // 0x24 set by Load; the dtor frees m_unk4 only when set
    char _pad25[3];             // 0x25
};

// Array of shadow nodes: the PArray base holds the node pointers.
class PShadowVolume : public PArray {
public:
    PShadowVolume();
    PShadowVolume(PShadowVolume *pSource);
    ~PShadowVolume();
    void SetShadowCaster(PMNode *pNode);
    int Load(PPakFile *pFile);
    void Render(float *, float *, float *, float *, float *, float);

    int m_unk10;               // 0x10 initialised to 0xC9742400
    int m_unk14;                // 0x14 cleared by ctor and dtor
    unsigned char m_unk18;      // 0x18 cleared by ctor, copy ctor and SetShadowCaster
};

#endif
