#ifndef MATHAPI_H
#define MATHAPI_H

#include "types.h"

class EntityBaseClass;
struct tagBOX;
struct tagSPHERE;
struct tagVuMatrixBox;
struct tagFLOAT3D;

class MathAPI {
public:
    static int IsESphereWithinESphere(tagSPHERE *arg0, tagSPHERE *arg1);
    static void VectorRotateY(float (*arg0)[4], float arg1);
    float SetE_BOX_Radius(tagBOX *arg0);
    float GetRelAngleYToPoint(EntityBaseClass *arg0, float (*arg1)[4]);
    bool FacingPoint(EntityBaseClass *arg0, float (*arg1)[4], float arg2);
    bool PointInMatrixBoxWSphereCheck(float *arg0, tagVuMatrixBox *arg1, tagFLOAT3D *arg2);
    float DistanceSquared(float (*arg0)[4], float (*arg1)[4]);
    float DistanceXZ(float (*arg0)[4], float (*arg1)[4]);
    float Distance(float (*arg0)[4], float (*arg1)[4]);
    static float RandomFloatRange(float arg0, float arg1);
    static int RandomIntRange(int arg0, int arg1);

    static int miRandom;
    float m_unk00[4];   // 0x00
    float m_unk10[4];   // 0x10
};

#endif
