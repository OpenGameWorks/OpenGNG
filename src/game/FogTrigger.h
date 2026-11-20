#ifndef FOGTRIGGER_H
#define FOGTRIGGER_H

#include "types.h"

// FogTrigger derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class EntityBaseClass;
class PZBufferFog;

class FogTrigger {
public:
    void Execute();

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                // 0x020 state selector: -2 idle, -1 reset, 0 watch, 1 apply fog
    char _pad024[0x1B0 - 0x24];
    float m_unk1B0;             // 0x1B0 fog density
    int m_unk1B4;               // 0x1B4 density flag
    float m_unk1B8;             // 0x1B8 density time
    float m_unk1BC;             // 0x1BC color red (0..1)
    float m_unk1C0;             // 0x1C0 color green (0..1)
    float m_unk1C4;             // 0x1C4 color blue (0..1)
    char _pad1C8[0x1CC - 0x1C8];
    int m_unk1CC;               // 0x1CC color flag
    float m_unk1D0;             // 0x1D0 color time
    float m_unk1D4[3];          // 0x1D4 saved position (copied to m_unk1F0 on reset)
    float m_unk1E0;             // 0x1E0 trigger range
    char _pad1E4[0x1F0 - 0x1E4];
    float m_unk1F0[4];          // 0x1F0 current position (Distance operand)
    unsigned char m_unk200;     // 0x200 armed flag
    char _pad201[3];
    PZBufferFog *m_unk204;      // 0x204 fog object inside gEng
};

#endif
