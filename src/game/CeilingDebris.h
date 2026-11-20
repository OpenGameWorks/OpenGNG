#ifndef CEILINGDEBRIS_H
#define CEILINGDEBRIS_H

#include "types.h"

// Stub of EntityBaseClass covering only the 0x20 bytes CeilingDebris reuses; the real
// header lays out 0x190 bytes, so it cannot be included without shifting these offsets.
class EntityBaseClass {
public:
    enum LoadClass { LoadClass_Unrecovered = 0 };
    EntityBaseClass(LoadClass eLoadClass, unsigned int nFlags);
    virtual ~EntityBaseClass();

    char _pad004[0x20 - 0x04];
};

// CeilingDebris derives from EntityBaseClass at offset 0; members are named by their offset.
class CeilingDebris : public EntityBaseClass {
public:
    CeilingDebris();
    virtual ~CeilingDebris();
    void Execute();


    int m_unk20;                // 0x020 state: -2 done, -1 waiting on linked entity, 0 falling
    char _pad024[0xE9 - 0x24];
    unsigned char m_unkE9;      // 0x0E9 nonzero selects the debris sequence by type
    char _padEA[0x160 - 0xEA];
    unsigned char m_unk160;     // 0x160 nonzero keeps the debris alive
    char _pad161[0x1B0 - 0x161];
    int m_unk1B0;               // 0x1B0 debris type: 0 church, 1 deadsea
    void *m_unk1B4;             // 0x1B4 linked entity instance
};

#endif
