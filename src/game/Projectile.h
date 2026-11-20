#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "types.h"

// Projectile entity. It derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class EntityBaseClass;
class PMNode;

// One 36-byte record of ProjectileTable, indexed by Projectile::m_unk1B0.
struct ProjectileRecord {
    char _pad000[0x18];
    unsigned short m_unk18;  // 0x018 copied to Projectile::m_unk15C
    unsigned short m_unk1A;  // 0x01A copied to Projectile::m_unk15E
    char _pad01C[0x24 - 0x1C];
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

    void *m_unk0;                    // 0x000 vtable pointer
    char _pad004[0x3C - 0x04];
    PMNode *m_unk3C;                 // 0x03C effect node; Delete processes its triggers and clears it
    char _pad040[0x15C - 0x40];
    unsigned short m_unk15C;         // 0x15C damage value written by DoDamage
    unsigned short m_unk15E;         // 0x15E second value written by DoDamage
    char _pad160[0x1B0 - 0x160];
    int m_unk1B0;                    // 0x1B0 index into ProjectileTable
    float m_unk1B4;                  // 0x1B4 float, role not yet identified
    ProjectileGuard m_unk1B8;        // 0x1B8 guard member (see ProjectileGuard)
    int m_unk1BC;                    // 0x1BC zeroed by the constructor
    u_long128 m_unk1C0;              // 0x1C0 vector written by InitIceDoom
    u_long128 m_unk1D0;              // 0x1D0 vector written by InitIceDoom
    char _pad1E0[0x1F4 - 0x1E0];
    int m_unk1F4;                    // 0x1F4 zeroed by the constructor
};

extern ProjectileRecord ProjectileTable[31];

#endif
