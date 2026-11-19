#ifndef PHYSICS_H
#define PHYSICS_H

#include "types.h"
#include "PArray.h"

class PMeshNode;

// Background-animation list shared by all Physics instances (symbol
// mBGAnimList__7Physics, 0x3065B0).
extern PArray mBGAnimList__7Physics;

class Physics {
public:
    int SulfurCheck();
    void AddBGAnimNode(PMeshNode *pNode);
    void BuildBGAnimList(PMeshNode *pNode);
    void SetVelocity(float fAngle, float fSpeed);
    void ResetPhysics(PMeshNode *pNode);

    float m_unk0;                   // 0x00 velocity X (SetVelocity), start of 16-byte matrix copy
    char _pad004[0x4];
    float m_unk8;                   // 0x08 velocity Z (SetVelocity)
    char _pad00C[0x4];
    u_long128 m_unk10;              // 0x10 matrix copy (ResetPhysics)
    char _pad020[0x74];
    float m_unk94;                  // 0x94
    char _pad098[0x8];
    u_long128 m_unkA0;              // 0xA0 copy of PMeshNode 0x80 (ResetPhysics)
    char _padB0[0x4];
    float m_unkB4;                  // 0xB4
    char _padB8[0xC];
    float m_unkC4;                  // 0xC4
    char _padC8[0x4];
    unsigned int m_unkCC;           // 0xCC
    char _padD0[0x14];
    unsigned int m_unkE4;           // 0xE4
    unsigned int m_unkE8;           // 0xE8 flags, bit 0x100000 read by SulfurCheck
    char _padEC[0xC];
    unsigned int m_unkF8;           // 0xF8
    float m_unkFC;                  // 0xFC
    char _pad100[0x8];
    unsigned int m_unk108;          // 0x108
    char _pad10C[0x8];
    unsigned int m_unk114;          // 0x114
    char _pad118[0x4];
    float m_unk11C;                 // 0x11C
};

#endif
