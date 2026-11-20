#ifndef PLIGHTMANAGER_H
#define PLIGHTMANAGER_H

#include "types.h"
#include "PArray.h"

// Light table owner, embedded in PWorld at offset 0x1F0. Size 0x30:
// PArray base at 0x00, PList block at 0x10 (list head at 0x14), 16-byte field at 0x20.
class PLightManager {
public:
    PLightManager();
    ~PLightManager();
    void *GetLightObject(unsigned int nId);
    void SetLightColor(unsigned int nId, float *pColor);
    void DestroyAllStaticLights();
    void DestroyAllDynamicLights();

    PArray m_unk0;          // 0x00 light array, storage allocated by the ctor
    char m_unk10[4];        // 0x10 PList (layout not recovered)
    void *m_unk14;          // 0x14 PList head, singly linked light nodes
    char m_unk18[8];        // 0x18 rest of PList block
    u_long128 m_unk20;      // 0x20 cleared by ctor
};

#endif
