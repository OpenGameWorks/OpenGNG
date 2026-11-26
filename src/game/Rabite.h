#ifndef RABITE_H
#define RABITE_H

#include "types.h"

class EntityBaseClass;

class Rabite {
public:
    Rabite();
    void LoadCorrectMesh();
    void OnWakeEvent();
    void OnAttackEvent(EntityBaseClass *pAttacker, int nArg);
    void SetEditableVars(char *pData);
    int OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB);
    void SetupHopToPoint();
    void Execute();
    int GetHealth();
    const char *GetClassName();
    int GetTallyType();
    int GetArenaWaveID();
    bool IsArenaApparition();
    int NeedsToBeWoken();
    int GetWokenVarPos();

    void *m_unk0;                   // 0x000 vtable pointer
    char _pad004[0x20 - 0x04];
    int m_unk20;                    // 0x020 state
    char _pad024[0x38 - 0x24];
    void *m_unk38;                  // 0x038 Physics object, created by Execute
    void *m_unk3C;                  // 0x03C pointer; +0x80 used as a hop target
    char _pad040[0xD4 - 0x40];
    void *m_unkD4;                  // 0x0D4 Shadow object, created by Execute
    char _padD8[0xE9 - 0xD8];
    unsigned char m_unkE9;          // 0x0E9 nonzero while the rabite is active
    unsigned char m_unkEA;          // 0x0EA cleared by constructor
    char _padEB[0xF8 - 0xEB];
    float m_unkF8;                  // 0x0F8 set to 0.3f by constructor
    float m_unkFC;                  // 0x0FC set to 0.6f by constructor
    char _pad100[0x103 - 0x100];
    unsigned char m_unk103;         // 0x103 set to 0x10 by constructor
    float m_unk104;                 // 0x104 set to 0.5f by constructor
    float m_unk108;                 // 0x108 set to 1.0f by constructor
    int m_unk10C;                   // 0x10C flag word masked and set by SetEditableVars
    char _pad110[0x15C - 0x110];
    short m_unk15C;                 // 0x15C cleared by constructor
    short m_unk15E;                 // 0x15E set to 0x100C by constructor
    unsigned char m_unk160;         // 0x160 nonzero while the attack animation runs
    char _pad161[0x179 - 0x161];
    unsigned char m_unk179;         // 0x179 cleared by SetEditableVars
    char _pad17A[0x18C - 0x17A];
    float m_unk18C;                 // 0x18C editable value copied by SetEditableVars
    float m_unk190;                 // 0x190 editable value copied by SetEditableVars
    float m_unk194;                 // 0x194 editable value copied by SetEditableVars
    float m_unk198;                 // 0x198 editable value copied by SetEditableVars
    char _pad19C[0x1A0 - 0x19C];
    float m_unk1A0[4];              // 0x1A0 vector stored into the attach point by Execute
    float m_unk1B0;                 // 0x1B0 start of the 0x30-byte block filled by memcpy
    float m_unk1B4;                 // 0x1B4 same block
    float m_unk1B8;                 // 0x1B8 same block
    float m_unk1BC;                 // 0x1BC same block, hop trigger radius
    float m_unk1C0[3];              // 0x1C0 vector copied to m_unk1F0 by Execute
    float m_unk1CC;                 // 0x1CC set from 0x18C when m_unk1D0 is set
    int m_unk1D0;                   // 0x1D0 selects the 0x18C override
    char _pad1D4[0x1D8 - 0x1D4];
    int m_unk1D8;                   // 0x1D8 copied to m_unk218 as a flag
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;                   // 0x1E0 hit points, reduced by OnHitEvent
    char _pad1E4[0x1F0 - 0x1E4];
    float m_unk1F0[4];              // 0x1F0 vector added to each hop offset
    float m_unk200;                 // 0x200 hop result x, written by SetupHopToPoint
    float m_unk204;                 // 0x204 hop result y
    float m_unk208;                 // 0x208 hop result z
    char _pad20C[0x214 - 0x20C];
    int m_unk214;                   // 0x214 sound reference from PlaySound
    unsigned char m_unk218;         // 0x218 selects the alternate mesh
    char _pad219[0x21C - 0x219];
    int m_unk21C;                   // 0x21C joint index on the player, -1 when detached
    float m_unk220;                 // 0x220 random rotation chosen by OnAttackEvent
    char _pad224[0x230 - 0x224];
    float m_unk230[4];              // 0x230 joint offsets filled by OnAttackEvent; [1..3] used by Execute
    int m_unk240;                   // 0x240 cleared by destructor
};

#endif
