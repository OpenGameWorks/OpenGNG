#ifndef REVERSIBLEANIMTRIGGER_H
#define REVERSIBLEANIMTRIGGER_H

#include "types.h"

// ReversibleAnimTrigger derives from EntityBaseClass at offset 0; the base is not
// declared here, so members are named by their offset from the object start.
class EntityBaseClass;
class PMNode;

class ReversibleAnimTrigger {
public:
    ReversibleAnimTrigger();
    ~ReversibleAnimTrigger();
    void Execute();
    void OnTouchEvent(EntityBaseClass *arg0);
    int OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3);
    void OnTimerEvent(unsigned int arg0);
    void SetEditableVars(char *pVars);
    void CheckForSound(PMNode *pNode);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    int m_unk4;                 // 0x004 timer duration argument of CreateTimer
    char _pad008[0x20 - 0x08];
    int m_unk20;                // 0x020 dispatch key read by Execute
    char _pad024[0x3C - 0x24];
    PMNode *m_unk3C;            // 0x03C linked PMNode
    char _pad040[0xE9 - 0x40];
    unsigned char m_unkE9;      // 0x0E9
    unsigned char m_unkEA;      // 0x0EA set to 1 by Execute for state 1
    char _pad0EB[0x103 - 0xEB];
    unsigned char m_unk103;     // 0x103 initialised to 0xFF
    char _pad104[0x10C - 0x104];
    int m_unk10C;               // 0x10C flag word (bits 0x200 and 0x400 set by Execute)
    char _pad110[0x1B0 - 0x110];
    char m_unk1B0[4];           // 0x1B0 copied from SetEditableVars arg (0x24 bytes)
    int m_unk1B4;               // 0x1B4 state selector read by OnHitEvent
    int m_unk1B8;               // 0x1B8 index into AnimTable
    int m_unk1BC;               // 0x1BC linked animation node id
    int m_unk1C0;               // 0x1C0 cutscene id started by Execute
    int m_unk1C4;               // 0x1C4 camera cutscene id
    int m_unk1C8;               // 0x1C8 timer duration
    float m_unk1CC;             // 0x1CC end frame (must be >= 0)
    float m_unk1D0;             // 0x1D0 rise speed (must be > 0)
    PMNode *m_unk1D4;           // 0x1D4 linked PMNode
    float m_unk1D8;             // 0x1D8 initialised to 0.5f
    float m_unk1DC;             // 0x1DC initialised to 0.5f
    int m_unk1E0;               // 0x1E0
    unsigned char m_unk1E4;     // 0x1E4 enabled flag (initialised to 1)
    unsigned char m_unk1E5;     // 0x1E5 initialised to 1
    unsigned char m_unk1E6;     // 0x1E6
    unsigned char m_unk1E7;     // 0x1E7
    int m_unk1E8;               // 0x1E8
};

#endif
