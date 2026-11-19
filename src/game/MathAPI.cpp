#include "MathAPI.h"

// TODO(header): foreign declarations
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" float sqrtf(float x);
float FastMath_Fabs(float f);

// DRAFT: 0x157900 SetE_BOX_Radius__7MathAPIFP6tagBOX
// note: 17 differing lines: literal 0x358637BD pooled via $gp (orig inline lui/ori/mtc1 into f1); load order f0/f3/f4 vs f2/f1/f3; beqz target off by one. Tried eps local, reversed add, -sdatathreshold 0: all 17.
float MathAPI::SetE_BOX_Radius(tagBOX *arg0) {
    float r = 0.0f;
    if (this != 0) {
        float sum = m_unk10[0] * m_unk10[0] + m_unk10[1] * m_unk10[1] + m_unk10[2] * m_unk10[2];
        r = sqrtf(sum) + 0.000001f;
        m_unk10[3] = r;
    }
    return r;
}

// FUNCTION: 0x157D10 FacingPoint__7MathAPIFP15EntityBaseClassPA4_ff
bool MathAPI::FacingPoint(EntityBaseClass *arg0, float (*arg1)[4], float arg2) {
    return FastMath_Fabs(GetRelAngleYToPoint(arg0, arg1)) < arg2;
}

// FUNCTION: 0x1580F0 DistanceSquared__7MathAPIFPA4_fPA4_f
float MathAPI::DistanceSquared(float (*arg0)[4], float (*arg1)[4]) {
    float sp10[4];
    sceVu0SubVector(sp10, m_unk00, *arg0);
    return sceVu0InnerProduct(sp10, sp10);
}

// FUNCTION: 0x158130 DistanceXZ__7MathAPIFPA4_fPA4_f
float MathAPI::DistanceXZ(float (*arg0)[4], float (*arg1)[4]) {
    float sp10[4];
    sceVu0SubVector(sp10, m_unk00, *arg0);
    sp10[1] = 0.0f;
    return sqrtf(sceVu0InnerProduct(sp10, sp10));
}

// FUNCTION: 0x158180 Distance__7MathAPIFPA4_fPA4_f
float MathAPI::Distance(float (*arg0)[4], float (*arg1)[4]) {
    float sp10[4];
    sceVu0SubVector(sp10, m_unk00, *arg0);
    return sqrtf(sceVu0InnerProduct(sp10, sp10));
}
