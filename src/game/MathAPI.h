#ifndef MATHAPI_H
#define MATHAPI_H

#include "types.h"

class EntityBaseClass;
struct tagBOX;

class MathAPI {
public:
    float SetE_BOX_Radius(tagBOX *arg0);
    float GetRelAngleYToPoint(EntityBaseClass *arg0, float (*arg1)[4]);
    bool FacingPoint(EntityBaseClass *arg0, float (*arg1)[4], float arg2);
    float DistanceSquared(float (*arg0)[4], float (*arg1)[4]);
    float DistanceXZ(float (*arg0)[4], float (*arg1)[4]);
    float Distance(float (*arg0)[4], float (*arg1)[4]);

    float m_unk00[4];   // 0x00
    float m_unk10[4];   // 0x10
};

#endif
