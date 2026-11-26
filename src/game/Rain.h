#ifndef RAIN_H
#define RAIN_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; Rain adds its fields from 0x190 on.
class Rain : public EntityBaseClass {
public:
    Rain();
    virtual ~Rain();
    void Execute();
    void OutputDebug();
    const char *GetClassName();
    void SetEditableVars(char *);

    char _pad190[0x20];
    float m_unk1B0;             // 0x1B0 rain density passed to CreateRain
    float m_unk1B4;             // 0x1B4 lightning density passed to SetLightningDensity
};

#endif
