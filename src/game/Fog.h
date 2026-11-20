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

    char _pad190[0x21C - 0x190];
    PZBufferFog *m_unk21C;      // 0x21C m_FogObj, the PZBufferFog driven by this volume
};

#endif
