#ifndef PFIRETEXTURE_H
#define PFIRETEXTURE_H

#include "types.h"

struct tagProceduralTextureData;
class PArray;

// Placeholder for the object owned at 0x5F0. Only its virtual destructor is
// used: slot 0 (offset 8) is called with a1 = 1 when the pointer is deleted.
class PFireTextureHandle {
public:
    virtual ~PFireTextureHandle();
};

class PFireTexture {
public:
    PFireTexture();
    ~PFireTexture();
    void Reset();
    void Update();
    int Init(struct tagProceduralTextureData *pData, PArray *pArray);
    int Init(int nIndex);

    int m_unk0;                    // 0x00 active flag
    char _pad4[0xC];               // 0x04
    char m_unk10[0x560];           // 0x10 embedded PParticleTexture
    float m_unk570[4][4];          // 0x570 matrix set to identity by the constructor
    float m_unk5B0[4][4];          // 0x5B0 matrix set to identity by the constructor
    PFireTextureHandle *m_unk5F0;  // 0x5F0
};

#endif
