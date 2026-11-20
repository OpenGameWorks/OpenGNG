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

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x3C - 0x04];
    BridgeSource *m_unk3C;      // 0x03C
    char _pad040[0x34C - 0x40];
    BridgeView *m_unk34C;       // 0x34C
};

#endif
