#ifndef PSHADER_H
#define PSHADER_H

#include "types.h"

class PSTAnim;
class PPakFile;
class PArray;

// Embedded at offset 0x0C of each PMeshFragment; size 0x58.
class PShader {
public:
    PShader();
    void Render(int nArg, bool bFlag, bool *pbOut);
    void Animate(float fTime, bool bFlag);
    void SetSTAnimOptions(bool bFlag);
    int Load(PPakFile *pPakFile, PArray *pTextures, bool bFlag);
    int LoadRenderPass(PPakFile *pPakFile, PArray *pTextures, unsigned int nIndex, bool bFlag);
    void Destroy();

    void *m_unk0;              // 0x00 heap block, freed with __dla__FPv
    int m_unk4;                // 0x04 flags, bit 0 gates the animation loops
    unsigned int m_unk8;       // 0x08 element count
    int m_unkC;                // 0x0C
    float m_unk10[4];          // 0x10 per-element scale
    int m_unk20[4];            // 0x20 texture ids
    PSTAnim *m_unk30[4];       // 0x30 animation pointers
    int m_unk40[4];            // 0x40 per-element values
    unsigned char m_unk50[4];  // 0x50 per-element flags
    unsigned char m_unk54[4];  // 0x54 per-element flags
};

#endif
