#ifndef PMESHFRAGMENT_H
#define PMESHFRAGMENT_H

#include "types.h"
#include "PMesh.h"

class PPakFile;
class PArray;

// Mesh fragment, 0x90 bytes. Vertex data and its count sit at the front; the shader is embedded at 0x0C.
class PMeshFragment {
public:
    PMeshFragment();
    int Load(PPakFile *pPakFile, PArray *pTextures, ePsx2FileVersion eVersion, bool bFlag);
    void Render(bool bFlag, int nArg, bool *pbOut);
    void Destroy();

    void *m_unk0;               // 0x00 vertex data, freed with __dla__FPv
    unsigned int m_unk4;        // 0x04 vertex data count
    unsigned short m_unk8;      // 0x08 loaded from header +0x30
    unsigned short m_unkA;      // 0x0A low halfword of header flags
    char m_unkC[0x58];          // 0x0C embedded PShader
    int m_unk64;                // 0x64 loaded from header +0x34
    char m_unk68[8];            // 0x68 unused
    char m_unk70[0x20];         // 0x70 block copied from header +0x10
};

#endif
