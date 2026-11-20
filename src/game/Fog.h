#ifndef FOG_H
#define FOG_H

#include "types.h"
#include "EntityBaseClass.h"

class PZBufferFog;

// Fog derives from EntityBaseClass, which occupies 0x000..0x18F; Fog fields start at 0x190.
// The inherited m_unk20 is the state selector: -2 applies the fog object, -1 resets it, 0 idles.
class Fog : public EntityBaseClass {
public:
    Fog();
    virtual ~Fog();
    void Execute();
    void SetEditableVars(char *pSrc);

    char _pad190[0x1B0 - 0x190];
    float m_unk1B0;             // 0x1B0 density; the 0x6C-byte editable block starts here
    float m_unk1B4;             // 0x1B4 colour R (scaled by 255 into the fog colour)
    float m_unk1B8;             // 0x1B8 colour G
    float m_unk1BC;             // 0x1BC colour B
    char _pad1C0[0x1C4 - 0x1C0];
    int m_unk1C4;               // 0x1C4 flag copied to m_FogObj->m_unk17AA
    float m_unk1C8;             // 0x1C8 gradient end key 0 (R)
    float m_unk1CC;             // 0x1CC gradient end key 0 (G)
    float m_unk1D0;             // 0x1D0 gradient end key 0 (B)
    float m_unk1D4;             // 0x1D4 gradient end key 0 (A)
    float m_unk1D8;             // 0x1D8 gradient key 1 (R)
    float m_unk1DC;             // 0x1DC gradient key 1 (G)
    float m_unk1E0;             // 0x1E0 gradient key 1 (B)
    float m_unk1E4;             // 0x1E4 gradient key 1 (A)
    float m_unk1E8;             // 0x1E8 gradient key 2 (R)
    float m_unk1EC;             // 0x1EC gradient key 2 (G)
    float m_unk1F0;             // 0x1F0 gradient key 2 (B)
    float m_unk1F4;             // 0x1F4 gradient key 2 (A)
    float m_unk1F8;             // 0x1F8 gradient key 3 (R)
    float m_unk1FC;             // 0x1FC gradient key 3 (G)
    float m_unk200;             // 0x200 gradient key 3 (B)
    float m_unk204;             // 0x204 gradient key 3 (A)
    float m_unk208;             // 0x208 gradient start (R)
    float m_unk20C;             // 0x20C gradient start (G)
    float m_unk210;             // 0x210 gradient start (B)
    float m_unk214;             // 0x214 gradient start (A)
    float m_unk218;             // 0x218 fog alpha, passed to SetClutFogAlpha
    PZBufferFog *m_unk21C;      // 0x21C m_FogObj, the PZBufferFog driven by this volume
};

#endif
