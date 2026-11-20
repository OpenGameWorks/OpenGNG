#ifndef PFOGTEXTURE_H
#define PFOGTEXTURE_H

#include "types.h"

struct tagProceduralTextureData;
class PArray;

// Placeholder for the object owned at 0x570. Only its virtual destructor is
// used: slot 0 (offset 8) is called with a1 = 1 when the pointer is deleted.
class PFogTextureHandle {
public:
    virtual ~PFogTextureHandle();
};

class PFogTexture {
public:
    PFogTexture();
    ~PFogTexture();
    void Reset();
    void Update();
    int Init(struct tagProceduralTextureData *pData, PArray *pArray);
    int Init(int nIndex);

    int m_unk0;                 // 0x00 active flag
    char _pad4[0xC];            // 0x04
    char m_unk10[0x560];        // 0x10 embedded PParticleTexture
    PFogTextureHandle *m_unk570; // 0x570
};

#endif
