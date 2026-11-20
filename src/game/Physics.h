#ifndef PHYSICS_H
#define PHYSICS_H

#include "types.h"
#include "PArray.h"

class PMeshNode;
class EntityBaseClass;
class BGCollision;

// Background-animation list shared by all Physics instances (symbol
// mBGAnimList__7Physics, 0x3065B0).
extern PArray mBGAnimList__7Physics;

class Physics {
public:
    Physics();
    int SulfurCheck();
    int IsAnimatedWallHit();
    void CheckBGAnim(float (&vPos)[4], float fOffset);
    void SetPhysicsType(unsigned int nType, float (*pPos)[4]);
    void AddBGAnimNode(PMeshNode *pNode);
    void BuildBGAnimList(PMeshNode *pNode);
    void SetVelocity(float fAngle, float fSpeed);
    void ResetPhysics(PMeshNode *pNode);
    void AdjustFaceAngle(PMeshNode *pNode, float fRate);
    int ApplyGroundMove(float (&vOut)[4], PMeshNode *pNode);
    void CalculateVelocity(float fSpeed, float (*pMatrix)[4]);
    void RunPhysics(EntityBaseClass *pEntity, float fDelta, int nFlag, BGCollision *pBG);

    float m_unk0;                   // 0x00 velocity X (SetVelocity), start of 16-byte matrix copy
    char _pad004[0x4];
    float m_unk8;                   // 0x08 velocity Z (SetVelocity)
    char _pad00C[0x4];
    u_long128 m_unk10;              // 0x10 matrix copy (ResetPhysics)
    float m_unk20[4];               // 0x20 vector (ApplyGroundMove); m_unk20[3] is 0x2C, zeroed there
    char _pad030[0xC];
    float m_unk3C;                  // 0x3C (IsAnimatedWallHit)
    float m_unk40[16];              // 0x40 matrix copy (SetPhysicsType)
    char _pad080[0x14];
    float m_unk94;                  // 0x94
    char _pad098[0x8];
    u_long128 m_unkA0;              // 0xA0 copy of PMeshNode 0x80 (ResetPhysics)
    char _padB0[0x4];
    float m_unkB4;                  // 0xB4
    char _padB8[0x8];
    unsigned int m_unkC0;           // 0xC0 (SetPhysicsType)
    float m_unkC4;                  // 0xC4
    char _padC8[0x4];
    unsigned int m_unkCC;           // 0xCC
    u_long128 m_unkD0;              // 0xD0 matrix source (ApplyGroundMove)
    unsigned int m_unkE0;           // 0xE0 (IsAnimatedWallHit)
    unsigned int m_unkE4;           // 0xE4
    unsigned int m_unkE8;           // 0xE8 flags, bit 0x100000 read by SulfurCheck
    unsigned int m_unkEC;           // 0xEC
    char _padF0[0x4];
    float m_unkF4;                  // 0xF4
    unsigned int m_unkF8;           // 0xF8
    float m_unkFC;                  // 0xFC
    float m_unk100;                 // 0x100 velocity scale (CalculateVelocity)
    short m_unk104;                 // 0x104 (constructor)
    unsigned short m_unk106;        // 0x106 (SetPhysicsType)
    unsigned int m_unk108;          // 0x108
    unsigned int m_unk10C;          // 0x10C (constructor)
    float m_unk110;                 // 0x110 (constructor)
    unsigned int m_unk114;          // 0x114
    float m_unk118;                 // 0x118 turn rate (AdjustFaceAngle)
    float m_unk11C;                 // 0x11C
};

#endif
