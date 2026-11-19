#ifndef PMESH_H
#define PMESH_H

class PMeshFragment;

// Mesh header: fragment array at 0x00, fragment count at 0x04, and two
// 128-bit bounding corners at 0x10 and 0x20. Size 0x30.
class PMesh {
public:
    PMesh();
    void SetSTAnimFlag();
    void SetBoundBox(float (*pBox)[2][4]);
    void Destroy();

    PMeshFragment *m_unk0;  // 0x00 fragment array, 0x90 bytes each, freed with delete[]
    unsigned int m_unk4;    // 0x04 fragment count
    short m_unk8;           // 0x08
    short m_unkA;           // 0x0A
    unsigned char m_unkC;   // 0x0C set when a fragment has flag bit 0 at 0x10
    unsigned char m_unkD;   // 0x0D set by SetBoundBox
    unsigned char m_unkE;   // 0x0E
    char _pad0F;           // 0x0F
    float m_unk10[2][4];    // 0x10 bounding box corners
};

#endif
