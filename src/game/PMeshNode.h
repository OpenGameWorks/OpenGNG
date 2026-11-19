#ifndef PMESHNODE_H
#define PMESHNODE_H

#include "types.h"

class PArray;
class PLight;

// TODO(header): PResource::eResObjType belongs to the PResource header. Placeholder until that header defines it; only the name matters for mangling.
class PResource {
public:
    enum eResObjType { eResObjType_Placeholder = 0 };
};

class PMeshNode {
public:
    PMeshNode(PResource::eResObjType eType);
    ~PMeshNode();
    void DetachLight(PLight *pLight);
    void RemoveFromCollisionArray(PArray *pArr);
    void DetachAllLights();
    void InitMembers();

    void *m_unk00;              // 0x000 vtable
    int m_unk04;                // 0x004 PResource state; 1 after InitMembers
    char _pad008[0xC];
    unsigned int m_unk14;       // 0x014 child count (PArray)
    unsigned int m_unk18;       // 0x018 child index (PArray)
    PMeshNode **m_unk1C;        // 0x01C child array (PArray)
    char _pad020[0x20];
    float m_unk40[4][4];        // 0x040 matrix
    char _pad080[0x58];
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
};

#endif
