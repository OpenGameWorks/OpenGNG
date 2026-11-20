#ifndef PSHADOWBUFFER_H
#define PSHADOWBUFFER_H

#include "types.h"
#include "PArray.h"

class PShadowVolume;

// Shadow volume list: the PArray base holds the volume pointers (max 0x40).
// The ctor clears 0x28 bytes from 0x10 and Destroy frees the texture at 0x34.
class PShadowBuffer : public PArray {
public:
    PShadowBuffer();
    ~PShadowBuffer();
    void AddShadowVolume(PShadowVolume *pVolume);
    void RemoveShadowVolume(PShadowVolume *pVolume);
    void Destroy();

    char _pad10[0x24];      // 0x10 cleared by ctor
    int m_unk34;            // 0x34 rendered texture handle, freed by Destroy
};

#endif
