#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "types.h"

// Projectile entity. It derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class EntityBaseClass;
class PMNode;
class Physics;
class Shadow;

// One 36-byte record of ProjectileTable, indexed by Projectile::m_unk1B0.
struct ProjectileRecord {
    int m_unk0;              // 0x000 mesh id passed to LoadMesh
    int m_unk4;              // 0x004 anim id (0 = none)
    int m_unk8;              // 0x008 sound id (0 = none)
    int m_unkC;              // 0x00C sound id (0 = none)
    float m_unk10;           // 0x010 Projectile::m_unk1B4 and the anim flag
    float m_unk14;           // 0x014 velocity passed to Physics::SetVelocity
    unsigned short m_unk18;  // 0x018 copied to Projectile::m_unk15C
    unsigned short m_unk1A;  // 0x01A copied to Projectile::m_unk15E
    float m_unk1C;           // 0x01C anim data float
    int m_unk20;             // 0x020 state (0 = none)
};

// Four-byte member whose type declares a destructor. Its presence makes the
// constructor keep `this` in its stack slot instead of a callee-saved register.
struct ProjectileGuard {
    int m_unk0;
    ~ProjectileGuard() {}
};

class Projectile {
public:
    Projectile();
    void Delete();
    void DoDamage(bool bFlag);
    void InitIceDoom(int nIndex, float (*pOut)[4], float (*pIn)[4]);
    void OnAttackEvent(EntityBaseClass *pArg, int nArg);

    enum ProjectileType { PROJECTILE_TYPE_COUNT = 31 };
    void InitProjectile(ProjectileType nType, float (*pA)[4], float (*pB)[4], float (*pC)[4]);
    void Execute();

    void *m_unk0;                    // 0x000 vtable pointer
    char _pad004[0x1C];
    int m_unk20;                     // 0x020 state switched on by Execute
    char _pad024[0x14];
    Physics *m_unk38;                // 0x038 physics object, created by InitProjectile
    PMNode *m_unk3C;                 // 0x03C effect node; Delete processes its triggers and clears it
    char _pad040[0xD4 - 0x40];
    Shadow *m_unkD4;                 // 0x0D4 shadow object, created by InitProjectile
    char _padD8[0xE8 - 0xD8];
    unsigned char m_unkE8;           // 0x0E8 set by InitProjectile
    unsigned char m_unkE9;           // 0x0E9
    char _padEA[0x10C - 0xEA];
    int m_unk10C;                    // 0x10C flag word edited by InitProjectile
    char _pad110[0x15C - 0x110];
    unsigned short m_unk15C;         // 0x15C damage value written by DoDamage
    unsigned short m_unk15E;         // 0x15E second value written by DoDamage
    unsigned char m_unk160;          // 0x160
    char _pad161[0x190 - 0x161];
    u_long128 m_unk190;              // 0x190 copy of pA
    u_long128 m_unk1A0;              // 0x1A0 copy of pB

    int m_unk1B0;                    // 0x1B0 index into ProjectileTable
    float m_unk1B4;                  // 0x1B4 float, role not yet identified
    ProjectileGuard m_unk1B8;        // 0x1B8 guard member (see ProjectileGuard)
    int m_unk1BC;                    // 0x1BC zeroed by the constructor
    u_long128 m_unk1C0;              // 0x1C0 vector written by InitIceDoom
    u_long128 m_unk1D0;              // 0x1D0 vector written by InitIceDoom
    float m_unk1E0;                  // 0x1E0
    float m_unk1E4;                  // 0x1E4
    float m_unk1E8;                  // 0x1E8 frame-scaled value read by Execute
    EntityBaseClass *m_unk1EC;       // 0x1EC
    unsigned int m_unk1F0;           // 0x1F0
    int m_unk1F4;                    // 0x1F4 zeroed by the constructor
};

extern ProjectileRecord ProjectileTable[31];

#endif
