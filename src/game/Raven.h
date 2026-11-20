#ifndef RAVEN_H
#define RAVEN_H

#include "types.h"

// Raven derives from EntityBaseClass at offset 0; the base is not declared here,
// so every member is named by its offset from the object start.
class EntityBaseClass;
class PMNode;

class Raven {
public:
    Raven();
    int GetSoundID(unsigned int nId);
    void OutputDebug();
    int CanAttack();
    void FlyAway();
    void SetEditableVars(char *pArg);
    void OnTimerEvent(unsigned int nId);
    int OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB);
    void OnTouchEvent(EntityBaseClass *pArg);

    void *m_unk0;                   // 0x000 vtable pointer (__vt__5Raven)
    int m_unk4;                     // 0x004 editable count, printed by SetEditableVars
    char _pad008[0x20 - 0x08];
    int m_unk20;                    // 0x020 state
    char _pad024[0x38 - 0x24];
    u_long128 *m_unk38;             // 0x038 output vector (16 bytes)
    PMNode *m_unk3C;                // 0x03C
    char _pad040[0xEB - 0x40];
    signed char m_unkEB;            // 0x0EB
    char _pad0EC[0x10C - 0xEC];
    int m_unk10C;                   // 0x10C
    char _pad110[0x179 - 0x110];
    signed char m_unk179;           // 0x179
    char _pad17A[0x190 - 0x17A];
    float m_unk190[3];              // 0x190 default activation values (three floats)
    char _pad19C[0x1B0 - 0x19C];
    float m_unk1B0;                 // 0x1B0 (copied from SetEditableVars argument, 0x14 bytes)
    float m_unk1B4;                 // 0x1B4
    float m_unk1B8;                 // 0x1B8
    float m_unk1BC;                 // 0x1BC activation radius
    int m_unk1C0;                   // 0x1C0
    char _pad1C4[0x1C5 - 0x1C4];
    signed char m_unk1C5;           // 0x1C5
    signed char m_unk1C6;           // 0x1C6
    signed char m_unk1C7;           // 0x1C7
    int m_unk1C8;                   // 0x1C8
    char _pad1CC[0x1E0 - 0x1CC];
    float m_unk1E0[4];              // 0x1E0 position (16 bytes, passed to MathAPI::DistanceXZ)
    char _pad1F0[0x244 - 0x1F0];
    int m_unk244;                   // 0x244
    char _pad248[0x250 - 0x248];
    int m_unk250;                   // 0x250
    char _pad254[0x258 - 0x254];
    int m_unk258;                   // 0x258
    int m_unk25C;                   // 0x25C
};

#endif
