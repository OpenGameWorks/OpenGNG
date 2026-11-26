#ifndef PSHADOWBUFFER_H
#define PSHADOWBUFFER_H

#include "types.h"
#include "PArray.h"

class PShadowVolume;

// Shadow volume list: the PArray base holds the volume pointers (max 0x40).
// The ctor clears 0x28 bytes from 0x10 and Destroy frees the texture at 0x34.
class PShadowBuffer {
public:
    PShadowBuffer();
    ~PShadowBuffer();
    void AddShadowVolume(PShadowVolume *pVolume);
    void RemoveShadowVolume(PShadowVolume *pVolume);
    void Destroy();
    void BeginRender();
    void Render();
    void EndRender();
    void SetZBufferRange(float fNear, float fFar);
    bool Create(int nArg0, int nArg1, int nArg2, int nArg3, short sArg4, float fArg5);

    PArray m_array;         // 0x00 shadow volumes; a member, so ~PShadowBuffer destroys it with flag -1
    char _pad10[0x24];      // 0x10 cleared by ctor
    int m_unk34;            // 0x34 rendered texture handle, freed by Destroy
    char _pad38[0x1A78];    // 0x38 render state
    float m_unk1AB0[4];     // 0x1AB0 shadow matrix row
    float m_unk1AC0[4];     // 0x1AC0 viewport centre and depth range
    float m_unk1AD0[4];     // 0x1AD0 depth scale and bias
    float m_unk1AE0[4];     // 0x1AE0 projection
    float m_unk1AF0[4];     // 0x1AF0 projection
};

#endif
