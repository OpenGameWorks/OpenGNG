#ifndef PMESH_H
#define PMESH_H

class PMeshFragment;
class PPakFile;
class PArray;

#include "Psx2FileVersion.h"

// Mesh header: fragment array at 0x00, fragment count at 0x04, and two
// 128-bit bounding corners at 0x10 and 0x20. Size 0x30.
class PMesh {
public:
    PMesh();
    void SetSTAnimFlag();
    void SetSTAnimOptions(bool bFlag);
    void ComputeBoundingBox();
    void SetBoundBox(float (*pBox)[2][4]);
    int Load(PPakFile *pPakFile, PArray *pTextures, unsigned int nCount, unsigned int nUnk, ePsx2FileVersion eVersion, bool bFlag);
    int RenderAllPolys();
    int Render(int nArg, bool *pbOut, bool bFlag);
    void AnimateShaders(float fDelta, bool bFlag);
    void Destroy();

    PMeshFragment *m_unk0;  // 0x00 fragment array, 0x90 bytes each, freed with delete[]
    unsigned int m_unk4;    // 0x04 fragment count
    unsigned short m_unk8;  // 0x08 loaded from Load's nUnk argument
    unsigned short m_unkA;  // 0x0A sum of fragment m_unk8 values
    unsigned char m_unkC;   // 0x0C set when a fragment has flag bit 0 at 0x10
    unsigned char m_unkD;   // 0x0D set by SetBoundBox
    unsigned char m_unkE;   // 0x0E
    char _pad0F;           // 0x0F
    float m_unk10[2][4];    // 0x10 bounding box corners
};

#endif
