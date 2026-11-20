#ifndef PFRUSTRUM_H
#define PFRUSTRUM_H

#include "types.h"

class PMat4;

// Only the first 0x10 bytes are declared. The object is larger: the planes at
// 0x80 and the box centre, radius and result at 0xD0..0xE0 are reached with
// char offsets in PFrustrum.cpp, so PWorld.h (which lays out m_1E0 relative to
// a 0x10-byte m_Frustrum) keeps its current offsets.
class PFrustrum {
public:
    enum eFrustumPlane {
        FRUSTUM_PLANE_0 = 0,
        FRUSTUM_PLANE_1 = 1,
        FRUSTUM_PLANE_2 = 2,
        FRUSTUM_PLANE_3 = 3,
        FRUSTUM_PLANE_4 = 4,
        FRUSTUM_MAX_PLANES = 5
    };

    PFrustrum();
    ~PFrustrum();
    void Init(float, float, float, float, PMat4 *, float (*)[4]);
    void GetPlaneEquation(eFrustumPlane ePlane, float &fA, float &fB, float &fC, float &fD);
    int IntersectBox(float (*pBox)[2][4], PMat4 *pMat);
    char _pad000[0x10];
};

#endif
