#ifndef BRIDGE_H
#define BRIDGE_H

#include "types.h"

// Bridge derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class EntityBaseClass;
class PLightManager;
class PMeshNode;
class PMNode;
class BridgeView;
class BridgeSource;

class Bridge {
public:
    Bridge();
    ~Bridge();
    PMNode *IsEntityOnNode(EntityBaseClass *arg0, PMeshNode *arg1);
    int Render(PLightManager *arg0);
    void Clamp(float &arg0);
    void UpdateBridgeRope();
    void LoadBridgeRope();
    void LoadBridgeParts();
    void LeanOnSides();
    void OnTimerEvent(unsigned int arg0);
    void PushPlank(int arg0, float arg1, float arg2);
    void RunPhysics();
    void Execute();
    void OnHitEvent(EntityBaseClass *, int, unsigned int, unsigned int);
    void OnTouchEvent(EntityBaseClass *);
    void SetEditableVars(char *);

    const char *GetClassName();
    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    int m_unk4;                 // 0x004
    char _pad008[0x1B - 0x08];
    unsigned char m_unk1B;      // 0x01B
    char _pad01C[0x20 - 0x1C];
    int m_unk20;                // 0x020 switch selector in Execute
    char _pad024[0x3C - 0x24];
    BridgeSource *m_unk3C;      // 0x03C
    char _pad040[0xE9 - 0x40];
    unsigned char m_unkE9;      // 0x0E9
    char _padEA[0x10C - 0xEA];
    int m_unk10C;               // 0x10C
    char _pad110[0x190 - 0x110];
    float m_unk190[4];          // 0x190 vector copied into PMNode+0x80
    float m_unk1A0[4];          // 0x1A0 vector copied into PMNode+0x90
    int m_unk1B0;               // 0x1B0 rope reload flag
    char _pad1B4[0x1C0 - 0x1B4];
    float m_unk1C0[9];          // 0x1C0 float array, stride 4
    void *m_unk1E4[9];          // 0x1E4 per-segment PMNode pointers, indexed by byte offset
    char _pad208[0x330 - 0x208];
    int m_unk330;               // 0x330 segment count
    int m_unk334;               // 0x334 record index, scaled by 32 into the 0x220 record array
    int m_unk338;               // 0x338
    int m_unk33C;               // 0x33C
    unsigned char m_unk340;     // 0x340
    char _pad341[0x344 - 0x341];
    int m_unk344;               // 0x344 timer-event id
    float m_unk348;             // 0x348 divisor for the per-segment fabs(lean / m_unk348)
    BridgeView *m_unk34C;       // 0x34C
    void *m_unk350[9];          // 0x350 per-segment PMNode pointers, +0x84 float
    float m_unk374[9];          // 0x374 per-segment float offsets
};

#endif
