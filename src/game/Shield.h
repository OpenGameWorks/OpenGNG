#ifndef SHIELD_H
#define SHIELD_H

#include "types.h"

#include "EntityBaseClass.h"

class Physics;

// Base members (0x038 Physics *m_unk38 physics object, 0x03C char *m_unk3C) come from EntityBaseClass.
class Shield : public EntityBaseClass {
public:
    Shield();
    virtual ~Shield();
    void Animate(int arg0, float arg1);
    int OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3);
    void OnAttackEvent(EntityBaseClass *arg0, int arg1);
    int CheckRicochet(EntityBaseClass *arg0);
    float ShieldDistance(float (*arg0)[4]);
    int HoverCheck();
    void DeleteShield();
    void Execute();

    char _pad190[0x20];
    int m_unk1B0;                   // 0x1B0 compared against 2 by OnAttackEvent
    float m_unk1B4;                 // 0x1B4 written by Execute
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
