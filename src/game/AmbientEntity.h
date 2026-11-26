#ifndef AMBIENTENTITY_H
#define AMBIENTENTITY_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; AmbientEntity adds its fields from 0x190 on.
class AmbientEntity : public EntityBaseClass {
public:
    void OnTimerEvent(unsigned int nTimer);
    AmbientEntity();
    virtual ~AmbientEntity();
    const char *GetClassName();
    void SetEditableVars(char *pSrc);
    void Execute();

    char _pad190[0x20];
    float m_unk1B0;             // 0x1B0 editable var: delay before the shell launches (timer units)
    char _pad1B4[0xC];
    float m_unk1C0[4];          // 0x1C0 launch path, end minus start
    float m_unk1D0;             // 0x1D0 path parameter, 0..1
    float m_unk1D4;             // 0x1D4 arc height, half the path length
    float m_unk1D8;             // 0x1D8 path speed, grows 2% a frame up to 0.02
    char _pad1DC[0x4];
    float m_unk1E0[4];          // 0x1E0 launch start position
    unsigned int m_unk1F0;      // 0x1F0 timer id whose expiry sets state 1
};

#endif
