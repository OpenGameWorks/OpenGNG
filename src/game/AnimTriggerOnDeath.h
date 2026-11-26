#ifndef ANIMTRIGGERONDEATH_H
#define ANIMTRIGGERONDEATH_H

#include "types.h"

// AnimTriggerOnDeath derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class AnimTriggerOnDeath {
public:
    void SetEditableVars(char *pVars);
    int CheckValidAnimID();
    void Execute();
    const char *GetClassName();

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                // 0x020 state selector (switch in Execute)
    char _pad024[0x1B0 - 0x24];
    int m_unk1B0;               // 0x1B0 anim ID; SetEditableVars copies 0x18 bytes from here
    void *m_unk1B4;             // 0x1B4 instance checked by InstanceIsValid
    void *m_unk1B8;             // 0x1B8 instance checked by InstanceIsValid
    void *m_unk1BC;             // 0x1BC instance checked by InstanceIsValid
    void *m_unk1C0;             // 0x1C0 instance checked by InstanceIsValid
    int m_unk1C4;               // 0x1C4 instance id looked up by GetPtrToInstance
};

#endif
