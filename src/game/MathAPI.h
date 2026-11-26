#ifndef MATHAPI_H
#define MATHAPI_H

#include "types.h"

class EntityBaseClass;
struct tagBOX {
    float m_unk00[4];   // 0x00 centre
    float m_unk10[4];   // 0x10 extent
    float m_unk20[4];   // 0x20 angle
};
struct tagSPHERE;
struct tagVuMatrixBox;
struct tagFLOAT3D;

struct tag_EQuat {
    float m_unk0;   // 0x00
    float m_unk4;   // 0x04
    float m_unk8;   // 0x08
    float m_unkC;   // 0x0C
};

class MathAPI {
public:
    static int IsESphereWithinESphere(tagSPHERE *arg0, tagSPHERE *arg1);
    static int MakeMatrixBox(tagVuMatrixBox *pMatBox, tagBOX *pOut, tagBOX *pIn, float fGrow);
    int IsEBoxWithinEBox(tagBOX *arg0, tagBOX *arg1);
    void MakeVertexList(tagBOX *arg0, float (*arg1)[4]);
    static void VectorRotateY(float (*arg0)[4], float arg1);
    static int GetGroundPos(float (*pPos)[4]);
    static float SetE_BOX_Radius(tagBOX *pBox);
    float GetRelAngleYToPoint(EntityBaseClass *arg0, float (*arg1)[4]);
    bool FacingPoint(EntityBaseClass *arg0, float (*arg1)[4], float arg2);
    bool PointInMatrixBoxWSphereCheck(float *arg0, tagVuMatrixBox *arg1, tagFLOAT3D *arg2);
    float DistanceSquared(float (*arg0)[4], float (*arg1)[4]);
    float DistanceXZ(float (*arg0)[4], float (*arg1)[4]);
    float Distance(float (*arg0)[4], float (*arg1)[4]);
    static float GetAngleBetweenVectors(float *arg0, float *arg1);
    void GetForwardVector(EntityBaseClass *arg0, float (&arg1)[4]);
    static void QuatSlerp(tag_EQuat *arg0, tag_EQuat *arg1, float arg2, tag_EQuat *arg3);
    static float GetRelAngleYToPoint(float (*arg0)[4], float arg1, float (*arg2)[4]);
    static float RandomFloatRange(float arg0, float arg1);
    static int RandomIntRange(int arg0, int arg1);
    static int PointInBoundBox(float (*arg0)[4], tagBOX arg1);
    static float GetAngleYToPoint(EntityBaseClass *arg0, float (*arg1)[4]);

    static int miRandom;
    float m_unk00[4];   // 0x00
    float m_unk10[4];   // 0x10
    char _pad20[0x1C];
    int m_unk3C;        // 0x3C
    char _pad40[0x160];
    float m_unk1A0[4];  // 0x1A0
};

#endif
