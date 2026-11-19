#include "MathAPI.h"

// TODO(header): foreign declarations
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" float sqrtf(float x);
extern "C" float sinf(float x);
extern "C" float cosf(float x);
float FastMath_Fabs(float f);
struct tagVuMatrixBox;
struct tagFLOAT3D;
void FastMath_PointInMatrixBox(tagVuMatrixBox *arg0, int arg1, float *arg2, int *arg3);

struct tagSPHERE {
    char _pad00[0xC];
    float m_unkC;   // 0x0C
};

// FUNCTION: 0x157600 IsESphereWithinESphere__7MathAPIFP9tagSPHEREP9tagSPHERE
int MathAPI::IsESphereWithinESphere(tagSPHERE *arg0, tagSPHERE *arg1) {
    float sp30[4];
    float sp40[4];
    float sp50[4];
    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }
    memcpy(sp30, arg0, 0x10);
    memcpy(sp40, arg1, 0x10);
    sceVu0SubVector(sp50, sp30, sp40);
    sp50[3] = 0.0f;
    float d = sceVu0InnerProduct(sp50, sp50);
    float dist = sqrtf(d);
    int r = 1;
    if (!(dist + arg0->m_unkC <= arg1->m_unkC)) {
        r = 0;
    }
    return r;
}

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

// DRAFT: 0x157CA0 VectorRotateY__7MathAPIFPA4_ff
// note: 27 differing lines: literal 0x3C8EFA35 is inline lui/ori/mtc1 in orig, gp-pooled here; accumulator ops match but madd/msub results land in f0/f1 swapped. Tried temp outputs (27), operand swap (27), -sdatathreshold 0 in scratch (25, not a match).
void MathAPI::VectorRotateY(float (*arg0)[4], float arg1) {
    float rad = arg1 * 0.017453292f;
    float s = sinf(rad);
    float c = cosf(rad);
    float x = (*arg0)[0];
    float z = (*arg0)[2];
    (*arg0)[0] = z * s + x * c;
    (*arg0)[2] = z * c - x * s;
}

// FUNCTION: 0x157D10 FacingPoint__7MathAPIFP15EntityBaseClassPA4_ff
bool MathAPI::FacingPoint(EntityBaseClass *arg0, float (*arg1)[4], float arg2) {
    return FastMath_Fabs(GetRelAngleYToPoint(arg0, arg1)) < arg2;
}

// FUNCTION: 0x157D50 PointInMatrixBoxWSphereCheck__7MathAPIFPfP14tagVuMatrixBoxP10tagFLOAT3D
bool MathAPI::PointInMatrixBoxWSphereCheck(float *arg0, tagVuMatrixBox *arg1, tagFLOAT3D *arg2) {
    float sp30[4];
    float sp40[4];
    int sp5C;
    memcpy(sp40, arg1, 0x10);
    sceVu0SubVector(sp30, m_unk00, sp40);
    sp40[3] = 0.0f;
    if (sceVu0InnerProduct(sp30, sp30) > arg0[0x4C / 4] * arg0[0x4C / 4]) {
        return false;
    }
    FastMath_PointInMatrixBox((tagVuMatrixBox *)arg0, 1, m_unk00, &sp5C);
    return sp5C != 0;
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

// FUNCTION: 0x1586B0 RandomFloatRange__7MathAPIFff
float MathAPI::RandomFloatRange(float arg0, float arg1) {
    miRandom = miRandom * 0x343FD + 0x269EC3;
    float scaled = 0.000030517578f * (float)((miRandom >> 16) & 0x7FFF);
    scaled *= (arg1 - arg0);
    return arg0 + scaled;
}

// FUNCTION: 0x158710 RandomIntRange__7MathAPIFii
int MathAPI::RandomIntRange(int arg0, int arg1) {
    miRandom = miRandom * 0x343FD + 0x269EC3;
    float scaled = 0.000030517578f * (float)((miRandom >> 16) & 0x7FFF);
    scaled *= (float)(arg1 - arg0 + 1);
    return arg0 + (int)scaled;
}
