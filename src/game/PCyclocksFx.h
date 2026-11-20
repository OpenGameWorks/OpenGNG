#ifndef PCYCLOCKSFX_H
#define PCYCLOCKSFX_H

#include "types.h"

class PParticleSplineTrail;

class PCyclocksFx {
public:
    PCyclocksFx();
    ~PCyclocksFx();

    void StopFx(unsigned int hFx);
    PParticleSplineTrail *CreateSplineTrail(float p0, float p1, float p2, float p3, float p4, float p5);
    void SetEyeBeamPos(float *pA, float *pB);
    void StopEyeBeam();
    void StartEyeBeam();
    void CreateEyeBeam();
    void CreateEyeBeamForAchille();
    void DestroyEyeBeam();

    int m_unk00[3];
    int m_unk0C;
};

#endif
