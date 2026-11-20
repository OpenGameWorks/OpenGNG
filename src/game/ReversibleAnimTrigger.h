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
    void OnTouchEvent(EntityBaseClass *arg0);
    int OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3);
    void OnTimerEvent(unsigned int arg0);
    void SetEditableVars(char *pVars);
    void CheckForSound(PMNode *pNode);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x103 - 0x04];
    unsigned char m_unk103;     // 0x103 initialised to 0xFF
    char _pad104[0x1B0 - 0x104];
    char m_unk1B0[4];           // 0x1B0 copied from SetEditableVars arg (0x24 bytes)
    int m_unk1B4;               // 0x1B4 state selector read by OnHitEvent
    char _pad1B8[4];
    int m_unk1BC;               // 0x1BC linked animation node id
    char _pad1C0[0x1C4 - 0x1C0];
    int m_unk1C4;               // 0x1C4 camera cutscene id
    char _pad1C8[0x1D4 - 0x1C8];
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
