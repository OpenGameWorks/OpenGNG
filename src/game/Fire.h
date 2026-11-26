#ifndef FIRE_H
#define FIRE_H

#include "types.h"

// Fire derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class EntityBaseClass;
class PMNode;

class Fire {
public:
    Fire();
    ~Fire();
    void OnAttackEvent(EntityBaseClass *arg0, int arg1);
    void OnTimerEvent(unsigned int arg0);
    void Execute();
    void SetEditableVars(char *);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    unsigned int m_unk4;        // 0x004 timer id source
    char _pad008[0x20 - 0x08];
    int m_unk20;              // 0x020 state selector
    char _pad024[0x3C - 0x24];
    PMNode *m_unk3C;            // 0x03C
    char _pad040[0xE9 - 0x40];
    unsigned char m_unkE9;      // 0x0E9 flag
    char _padEA[0x10C - 0xEA];
    unsigned int m_unk10C;      // 0x10C
    char _pad110[0x160 - 0x110];
    unsigned char m_unk160;     // 0x160 flag
    char _pad161[0x1B0 - 0x161];
    int m_unk1B0;               // 0x1B0 mode
    int m_unk1B4;               // 0x1B4 anim loop count
    float m_unk1B8;             // 0x1B8
    int m_unk1BC;               // 0x1BC timer sequence id
    int m_unk1C0;               // 0x1C0
    float m_unk1C4;             // 0x1C4
    int m_unk1C8;               // 0x1C8 sound reference
};

#endif
