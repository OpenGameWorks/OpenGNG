#ifndef SHIELD_H
#define SHIELD_H

#include "types.h"

class EntityBaseClass;
class Physics;

class Shield {
public:
    Shield();
    int OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3);
    float ShieldDistance(float (*arg0)[4]);
    int HoverCheck();
    void DeleteShield();

    void *m_unk0;                   // 0x000 vtable pointer, set by constructor
    char _pad004[0x38 - 0x04];
    Physics *m_unk38;               // 0x038 physics object, SetPhysicsType target
    char *m_unk3C;                  // 0x03C
    char _pad040[0x1B8 - 0x40];
    void *m_unk1B8;                 // 0x1B8
    EntityBaseClass *m_unk1BC;      // 0x1BC cleared by constructor
    void *m_unk1C0;                 // 0x1C0 cleared by constructor
    unsigned int m_unk1C4;          // 0x1C4 cleared by constructor, DeleteEffect handle
    unsigned int m_unk1C8;          // 0x1C8 cleared by constructor, Destroy handle
    unsigned int m_unk1CC;          // 0x1CC cleared by constructor, Destroy handle
    unsigned int m_unk1D0;          // 0x1D0 cleared by constructor, StopSoundBySoundRef reference
    int m_unk1D4;                   // 0x1D4 cleared by constructor
    unsigned char m_unk1D8;         // 0x1D8 cleared by constructor
    unsigned char m_unk1D9;         // 0x1D9 cleared by constructor
    unsigned char m_unk1DA;         // 0x1DA cleared by constructor, set to 1 by OnHitEvent
    unsigned char m_unk1DB;         // 0x1DB cleared by constructor
};

#endif
