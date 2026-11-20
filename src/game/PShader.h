#ifndef PSHADER_H
#define PSHADER_H

#include "types.h"

class PSTAnim;

// Embedded at offset 0x0C of each PMeshFragment; size 0x58.
class PShader {
public:
    PShader();
    void Animate(float fTime, bool bFlag);
    void SetSTAnimOptions(bool bFlag);
    void Destroy();

    void *m_unk0;              // 0x00 heap block, freed with __dla__FPv
    int m_unk4;                // 0x04 flags, bit 0 gates the animation loops
    unsigned int m_unk8;       // 0x08 element count
    int m_unkC;                // 0x0C
    char _pad10[0x10];         // 0x10
    int m_unk20[4];            // 0x20 texture ids
    PSTAnim *m_unk30[4];       // 0x30 animation pointers
    char _pad40[0x10];         // 0x40
    int m_unk50;               // 0x50
    unsigned char m_unk54[4];  // 0x54 per-element flags
};

#endif
