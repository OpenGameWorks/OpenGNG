#ifndef PGASTEXTURE_H
#define PGASTEXTURE_H

#include "types.h"

struct tagProceduralTextureData;
class PArray;

// Placeholder for the objects owned at 0x570 and 0x574. Only their virtual
// destructor is used: slot 0 (offset 8) is called with a1 = 1 when the pointer
// is deleted.
class PGasTextureHandle {
public:
    virtual ~PGasTextureHandle();
};

class PGasTexture {
public:
    PGasTexture();
    ~PGasTexture();
    void Reset();
    void Update();
    int Init(struct tagProceduralTextureData *pData, PArray *pArray);
    int Init(int nIndex);

    int m_unk0;                      // 0x00 active flag
    char _pad4[0xC];                 // 0x04
    char m_unk10[0x560];             // 0x10 embedded PParticleTexture
    PGasTextureHandle *m_unk570;     // 0x570
    PGasTextureHandle *m_unk574;     // 0x574
};

#endif
