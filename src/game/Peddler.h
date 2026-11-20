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
    int IsAlive();
    void LookAtPeddler();
    int AnimateItems();
    void ExitPeddlerView();
    int OnHitEvent(EntityBaseClass *pEntity, int nArg1, unsigned int nEvent, unsigned int nArg2);

    void *m_unk0;                   // 0x000 vtable pointer
    unsigned int m_unk4;            // 0x004 owner id passed to Add2DependencyList
    char _pad008[4];
    int m_unkC;                     // 0x00C passed to the entity's 0x30 slot
    char _pad010[0x20 - 0x10];
    int m_unk20;                    // 0x020
    char _pad024[0x038 - 0x024];
    char *m_unk38;                  // 0x038 object with 0x11C float
    char *m_unk3C;                  // 0x03C object with 0x80 vector
    char _pad040[0x0D4 - 0x040];
    int m_unkD4;                    // 0x0D4 cleared by constructor
    char _pad0D8[0x0E8 - 0x0D8];
    unsigned char m_unkE8;          // 0x0E8 set to 3 by OnHitEvent
    char _padE9[0x1CC - 0x0E9];
    int m_unk1CC;                   // 0x1CC alive when greater than zero
    char _pad1D0[0x1E4 - 0x1D0];
    float m_unk1E4;                 // 0x1E4
    float m_unk1E8;                 // 0x1E8
    float m_unk1EC;                 // 0x1EC
    float m_unk1F0;                 // 0x1F0
    EntityBaseClass *m_unk1F4[3];   // 0x1F4
    EntityBaseClass *m_unk200;      // 0x200
    char _pad204[0x214 - 0x204];
    int m_unk214;                   // 0x214 nonzero when the look target is set
    PeddlerItems *m_unk218[5];      // 0x218 cleared by constructor
    int m_unk22C;                   // 0x22C
    char _pad230[0x244 - 0x230];
    unsigned char m_unk244;         // 0x244
    char _pad245[0x246 - 0x245];
    unsigned short m_unk246;        // 0x246 hit argument
    int m_unk248;                   // 0x248
    int m_unk24C;                   // 0x24C
    char _pad250[0x284 - 0x250];
    tagWaypointGroup *m_unk284;     // 0x284
    int m_unk288;                   // 0x288
    int m_unk28C;                   // 0x28C
    char _pad290[0x294 - 0x290];
    int m_unk294;                   // 0x294
    int m_unk298;                   // 0x298 state saved by OnHitEvent
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
    PeddlerItems(int nIndex);
    ~PeddlerItems();
    void EnableDisplay(bool bEnable);
    int AnimateFloat(float &fVal, float fTarget, float fStep);
    int AnimateVector(float (&afVec)[4], float (&afTarget)[4], float fStep);
    int Animate(float fA, float fB, float fC, float fD);
    int Hide();
    void Reset(float fAngle);
    PMNode *CopyItemMesh(int nIndex);
    void ReplaceItem(int nItem);

    PMNode *m_unk0;                 // 0x000 rotate node (PArray at +0x14)
    PMNode *m_unk4;                 // 0x004 item node
    float m_unk8;                   // 0x008 animated scale
    float m_unkC;                   // 0x00C animated fade
    char _pad010[0x10];             // 0x010 unit matrix copy
    char _pad020[0x10];             // 0x020 unit matrix copy
};

unsigned int GetItemID(unsigned int arg0);

#endif
