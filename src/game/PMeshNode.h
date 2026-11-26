#ifndef PMESHNODE_H
#define PMESHNODE_H

#include "types.h"

class PArray;
class PLight;
class PPakFile;
class PAnim;
class PFrustrum;

// Placeholder for the anim table passed to RecurseAttachAnim; only the layout used by that function is known.
class PMeshNodeAnimDataTable {
public:
    char _pad00[8];
    unsigned int m_unk08;       // 0x08 entry count
    void *m_unk0C;              // 0x0C entry array, 0x18 bytes per entry
};

// TODO(header): PResource::eResObjType belongs to the PResource header. Placeholder until that header defines it; only the name matters for mangling.
class PResource {
public:
    enum eResObjType { eResObjType_Placeholder = 0 };
};

#include "PMesh.h"

// Pickup record reached through PMeshNode::m_unk10; only the two floats clamped by AdjustPickup are named.
class PMeshPickup {
public:
    char _pad00[0xD];
    unsigned char m_unk0D;      // 0x0D nonzero: the box at +0x10 is valid
    char _pad0E[0x2];
    float m_unk10[2][4];        // 0x10 bounding box; AdjustPickup clamps [1][0] and [1][2] to at least 1.0f
};

class PMeshNode {
public:
    PMeshNode(PResource::eResObjType eType);
    PMeshNode(PMeshNode &other);
    ~PMeshNode();
    void AdjustPickup();
    void TestMeshNodeInFrustum(PFrustrum *pFrustrum);
    void DetachLight(PLight *pLight);
    void RemoveFromCollisionArray(PArray *pArr);
    bool BuildCollisionArray(PArray *pArr, unsigned int flag);
    void DetachAllLights();
    void InitMembers();
    int RecurseAttachAnim(PMeshNodeAnimDataTable *pAnimDataTable);
    void LoadCollision(PPakFile *pPak);
    int Load(PPakFile *pPak, PArray *pArr, ePsx2FileVersion ver);
    void ComputeBoundingBox();

    void *m_unk00;              // 0x000 vtable
    int m_unk04;                // 0x004 PResource state; 1 after InitMembers
    int m_unk8;                 // 0x008 header word copied from the file record
    int m_unkC;                // 0x00C result of PFrustrum::IntersectBox
    PMeshPickup *m_unk10;       // 0x010 pickup record; PMeshPickup fields at +0x20 and +0x28
    unsigned int m_unk14;       // 0x014 child count (PArray)
    unsigned int m_unk18;       // 0x018 child index (PArray)
    PMeshNode **m_unk1C;        // 0x01C child array (PArray)
    char _pad020[0xC];
    float m_unk2C;              // 0x02C fade factor set by TestMeshNodeInFrustum
    char _pad030[0xE];
    unsigned char m_unk3E;      // 0x03E flags; bit 0x4 clamps m_unkA0..A8, bit 0x20 sets m_unk2C
    char _pad03F[0x1];
    float m_unk40[4][4];        // 0x040 matrix
    float m_unk80[4];           // 0x080 offset added to the child's m_unk110 by ComputeBoundingBox
    float m_unk90[4];           // 0x090 copied from the file record
    float m_unkA0;              // 0x0A0 scale clamp input
    float m_unkA4;              // 0x0A4 scale clamp input
    float m_unkA8;              // 0x0A8 scale clamp input
    float m_unkAC;              // 0x0AC
    float m_unkB0[4];           // 0x0B0 copied from the file record
    float m_unkC0[4];           // 0x0C0 copied from the file record
    char _padD0[0x8];
    char m_unkD8[0xC];          // 0x0D8 PArray, size 0xC, not recovered further
    char _padE4[0x1C];
    short m_unk100;             // 0x100
    unsigned char m_unk102;     // 0x102 set by InitMembers; cleared when the light list empties
    unsigned char m_unk103;     // 0x103 flag: m_unk104 is owned
    void *m_unk104;             // 0x104 owned buffer, freed with delete[] in dtor
    int m_unk108;               // 0x108
    char _pad10C[0x4];
    float m_unk110[4];          // 0x110 copy of gUnitMatrix row 3
    float m_unk120[4];          // 0x120 copy of gUnitMatrix row 3
    unsigned int m_unk130;      // 0x130 light PArray count
    int m_unk134;               // 0x134 light PArray index
    void *m_unk138;             // 0x138 light PArray table
    char _pad13C[0x4];          // 0x13C tail padding; the original allocates 0x140 bytes
};

#endif
