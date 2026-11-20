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
    void OnTimerEvent(unsigned int arg0);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x3C - 0x04];
    BridgeSource *m_unk3C;      // 0x03C
    char _pad040[0x190 - 0x40];
    float m_unk190[4];          // 0x190 vector copied into PMNode+0x80
    float m_unk1A0[4];          // 0x1A0 vector copied into PMNode+0x90
    int m_unk1B0;               // 0x1B0 rope reload flag
    char _pad1B4[0x1E4 - 0x1B4];
    void *m_unk1E4[9];          // 0x1E4 per-segment PMNode pointers, indexed by byte offset
    char _pad208[0x330 - 0x208];
    int m_unk330;               // 0x330 segment count
    char _pad334[0x344 - 0x334];
    int m_unk344;               // 0x344 timer-event id
    char _pad348[0x34C - 0x348];
    BridgeView *m_unk34C;       // 0x34C
    void *m_unk350[9];          // 0x350 per-segment PMNode pointers, +0x84 float
    float m_unk374[9];          // 0x374 per-segment float offsets
};

#endif
