#ifndef RAVEN_H
#define RAVEN_H

#include "types.h"

// Raven derives from EntityBaseClass at offset 0; the base is not declared here,
// so every member is named by its offset from the object start.
class EntityBaseClass;
class PMNode;
class Physics;

class Raven {
public:
    Raven();
    int GetSoundID(unsigned int nId);
    void OutputDebug();
    int CanAttack();
    void FlyAway();
    void FlyToFlyToPos(int nMode);
    void SetEditableVars(char *pArg);
    void OnTimerEvent(unsigned int nId);
    int OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB);
    void OnTouchEvent(EntityBaseClass *pArg);
    void Execute();

    void *m_unk0;                   // 0x000 vtable pointer (__vt__5Raven)
    int m_unk4;                     // 0x004 editable count, printed by SetEditableVars
    char _pad008[0x20 - 0x08];
    int m_unk20;                    // 0x020 state
    char _pad024[0x38 - 0x24];
    Physics *m_unk38;               // 0x038 physics object (0x120 bytes)
    PMNode *m_unk3C;                // 0x03C
    char _pad040[0xE9 - 0x40];
    unsigned char m_unkE9;          // 0x0E9 first-frame flag, read by Execute
    char _pad0EA[0xEB - 0xEA];
    signed char m_unkEB;            // 0x0EB
    char _pad0EC[0x103 - 0xEC];
    unsigned char m_unk103;         // 0x103 animation or flag byte
    int m_unk104;                   // 0x104 float bits (0x3F800000 = 1.0f)
    int m_unk108;                   // 0x108 float bits (0x3F000000 = 0.5f)
    int m_unk10C;                   // 0x10C flag word
    char _pad110[0x140 - 0x110];
    unsigned int *m_unk140;         // 0x140 current sequence pointer
    char _pad144[0x15C - 0x144];
    short m_unk15C;                 // 0x15C
    short m_unk15E;                 // 0x15E
    unsigned char m_unk160;         // 0x160 animation finished flag
    char _pad161[0x179 - 0x161];
    signed char m_unk179;           // 0x179
    char _pad17A[0x190 - 0x17A];
    float m_unk190[4];              // 0x190 default activation values (three floats plus pad)
    char _pad1A0[0x1B0 - 0x1A0];
    float m_unk1B0;                 // 0x1B0 (copied from SetEditableVars argument, 0x14 bytes)
    float m_unk1B4;                 // 0x1B4
    float m_unk1B8;                 // 0x1B8
    float m_unk1BC;                 // 0x1BC activation radius
    int m_unk1C0;                   // 0x1C0 variant index (0, 1, 2)
    unsigned char m_unk1C4;         // 0x1C4 idle toggle
    unsigned char m_unk1C5;         // 0x1C5
    unsigned char m_unk1C6;         // 0x1C6
    unsigned char m_unk1C7;         // 0x1C7
    int m_unk1C8;                   // 0x1C8 timer id
    float m_unk1CC;                 // 0x1CC activation radius, compared against player distance
    float m_unk1D0[4];              // 0x1D0 home position (16 bytes)
    float m_unk1E0[4];              // 0x1E0 position (16 bytes, passed to MathAPI::DistanceXZ)
    char _pad1F0[0x210 - 0x1F0];
    float m_unk210[4];              // 0x210 direction vector (16 bytes); m_unk210[1] is 0x214
    float m_unk220[4];              // 0x220 vector (16 bytes)
    float m_unk230[4];              // 0x230 vector (16 bytes)
    float m_unk240;                 // 0x240 scale applied to the direction
    int m_unk244;                   // 0x244
    float m_unk248;                 // 0x248 turn rate
    float m_unk24C;                 // 0x24C interpolation fraction
    EntityBaseClass *m_unk250;      // 0x250 spawned apparition
    EntityBaseClass *m_unk254;      // 0x254 apparition handle
    int m_unk258;                   // 0x258 timer id
    int m_unk25C;                   // 0x25C timer id
    int m_unk260;                   // 0x260 frame counter
};

#endif
