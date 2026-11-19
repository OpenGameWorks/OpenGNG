#ifndef PEDDLER_H
#define PEDDLER_H

class EntityBaseClass;
class PeddlerItems;
struct tagWaypointGroup;

class Peddler {
public:
    Peddler();
    bool TrappedEntityRemoved();
    void OutputDebug();
    void OnTimerEvent(unsigned int arg0);
    unsigned int FindItem(int arg0);
    int EnemiesInCheckRadius();
    int ActivatedEnemiesDead();
    void ActivateAttackingEnemies();
    int HideItems();
    void InitItems();
    void ValidateItems();
    int GetNextPosition(float (&afPos)[4]);

    void *m_unk0;                   // 0x000 vtable pointer
    unsigned int m_unk4;            // 0x004 owner id passed to Add2DependencyList
    char _pad008[4];
    int m_unkC;                     // 0x00C passed to the entity's 0x30 slot
    char _pad010[0x20 - 0x10];
    int m_unk20;                    // 0x020
    char _pad024[0x0D4 - 0x24];
    int m_unkD4;                    // 0x0D4 cleared by constructor
    char _pad0D8[0x1E4 - 0x0D8];
    float m_unk1E4;                 // 0x1E4
    float m_unk1E8;                 // 0x1E8
    float m_unk1EC;                 // 0x1EC
    float m_unk1F0;                 // 0x1F0
    EntityBaseClass *m_unk1F4[3];   // 0x1F4
    EntityBaseClass *m_unk200;      // 0x200
    char _pad204[0x218 - 0x204];
    PeddlerItems *m_unk218[5];      // 0x218 cleared by constructor
    int m_unk22C;                   // 0x22C
    char _pad230[0x244 - 0x230];
    unsigned char m_unk244;         // 0x244
    char _pad245[0x248 - 0x245];
    int m_unk248;                   // 0x248
    int m_unk24C;                   // 0x24C
    char _pad250[0x284 - 0x250];
    tagWaypointGroup *m_unk284;     // 0x284
    int m_unk288;                   // 0x288
    char _pad28C[0x294 - 0x28C];
    int m_unk294;                   // 0x294
    char _pad298[0x29C - 0x298];
    unsigned char m_unk29C;         // 0x29C
    char _pad29D[0x2A5 - 0x29D];
    unsigned char m_unk2A5;         // 0x2A5 set to 1 by constructor
    unsigned char m_unk2A6;         // 0x2A6
    unsigned char m_unk2A7;         // 0x2A7
    unsigned char m_unk2A8;         // 0x2A8 cleared by constructor
    char _pad2A9[0x2B4 - 0x2A9];
    int m_unk2B4;                   // 0x2B4 cleared by constructor
    char _pad2B8[0x2BC - 0x2B8];
    int m_unk2BC;                   // 0x2BC
    char _pad2C0[0x2C4 - 0x2C0];
    int m_unk2C4;                   // 0x2C4
    EntityBaseClass *m_unk2C8[3];   // 0x2C8
    int m_unk2D4;                   // 0x2D4
    unsigned char m_unk2D8;         // 0x2D8
};

class PMNode;

class PeddlerItems {
public:
    ~PeddlerItems();
    void EnableDisplay(bool bEnable);
    int AnimateFloat(float &fVal, float fTarget, float fStep);
    int AnimateVector(float (&afVec)[4], float (&afTarget)[4], float fStep);
    int Hide();
    void Reset(float fAngle);
    PMNode *CopyItemMesh(int nIndex);

    PMNode *m_unk0;                 // 0x000 item node
    PMNode *m_unk4;                 // 0x004 rotate node
    float m_unk8;                   // 0x008 animated scale
    float m_unkC;                   // 0x00C animated fade
};

unsigned int GetItemID(unsigned int arg0);

#endif
