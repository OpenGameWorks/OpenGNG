#ifndef INNOCENT_H
#define INNOCENT_H

#include "types.h"

class EntityBaseClass;
class PMNode;

class Innocent {
public:
    Innocent();
    int AnimationViewer(int arg0);
    void OnWakeEvent();
    int TrappedEntityRemoved();

    void *m_unk0;                   // 0x000 vtable pointer
    char _pad004[0x3C - 0x04];
    PMNode *m_unk3C;                // 0x03C
    char _pad040[0xD4 - 0x40];
    int m_unkD4;                    // 0x0D4 cleared by constructor
    char _padD8[0x103 - 0xD8];
    unsigned char m_unk103;         // 0x103 set to 0xFE by constructor
    int m_unk104;                   // 0x104 set to 2.0f bits by constructor
    int m_unk108;                   // 0x108 set to 4.0f bits by constructor
    char _pad10C[0x1B0 - 0x10C];
    int m_unk1B0;                   // 0x1B0 state; 3 selects the wake scale-up
    char _pad1B4[0x1EC - 0x1B4];
    EntityBaseClass *m_unk1EC[3];   // 0x1EC..0x1F7 tracked entity handles
    char _pad1F8[0x272 - 0x1F8];
    unsigned char m_unk272;         // 0x272 cleared by constructor
    char _pad273[0x274 - 0x273];
    int m_unk274;                   // 0x274 cleared by constructor
    char _pad278[0x288 - 0x278];
    int m_unk288;                   // 0x288 cleared by constructor
};

#endif
