#ifndef PCYCLOCKSFX_H
#define PCYCLOCKSFX_H

#include "types.h"

class PCyclocksFx {
public:
    PCyclocksFx();
    ~PCyclocksFx();

    void StopFx(unsigned int hFx);
    void StopEyeBeam();
    void CreateEyeBeamForAchille();
    void DestroyEyeBeam();

    int m_unk00[3];
    int m_unk0C;
};

#endif
