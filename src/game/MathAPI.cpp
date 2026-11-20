#include "MathAPI.h"

// TODO(header): foreign declarations
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" float sqrtf(float x);
extern "C" float sinf(float x);
extern "C" float cosf(float x);
extern "C" float acosf(float x);
extern "C" float atan2f(float y, float x);
float FastMath_Fabs(float f);
struct tagVuMatrixBox;
struct tagFLOAT3D;
class PMat4 {
public:
    void RotateX(float angle);
    void RotateY(float angle);
    void RotateZ(float angle);
    void InverseByRT(float *arg0, float *arg1);
};
extern "C" void sceVu0UnitMatrix(PMat4 *m);
bool FastMath_PointInSingleMatrixBox(float *arg0, tagVuMatrixBox *arg1);
void FastMath_PointInMatrixBox(tagVuMatrixBox *arg0, int arg1, float *arg2, int *arg3);

struct tagSPHERE {
    char _pad00[0xC];
    float m_unkC;   // 0x0C
};

// DRAFT: 0x1574F0 MakeMatrixBox__7MathAPIFP14tagVuMatrixBoxP6tagBOXP6tagBOXf
// note: 4 differing words: argument setup order (addiu a0,sp,0x90 vs daddu a1,s0) before memcpy and SetE_BOX_Radius calls, plus one nop vs addiu in the SetE_BOX_Radius delay slot; frame and lq/sq match; tried volatile temp (25->4), split null test (4->many).
int MathAPI::MakeMatrixBox(tagVuMatrixBox *arg0, tagBOX *arg1, tagBOX *arg2, float arg3) {
    float mat[4][4];
    float box[12];
    float mat2[4][4];
    sceVu0UnitMatrix((PMat4 *)mat);
    if (this == 0 || arg1 == 0) {
        return -1;
    }
    memcpy(box, arg1, 0x30);
    if (arg3 != 0.0f) {
        box[4] += arg3;
        box[5] += arg3;
        box[6] += arg3;
    }
    ((MathAPI *)box)->SetE_BOX_Radius(arg1);
    ((PMat4 *)mat)->InverseByRT(&box[8], box);
    sceVu0CopyMatrix(mat2, mat);
    volatile u_long128 tmp = *(u_long128 *)&box[4];
    memcpy(this, mat2, 0x50);
    if (arg0 != 0) {
        memcpy(arg0, box, 0x30);
    }
    return 0;
}

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

// DRAFT: 0x1576B0 IsEBoxWithinEBox__7MathAPIFP6tagBOXP6tagBOX
// note: 62 differing words; size 0xFC vs 0xEC (frame 0x180 vs 0x170); s2/s1 register assignment differs across the sceVu0UnitMatrix call; tried pointer loop (63->62) and local reorder (no change).
int MathAPI::IsEBoxWithinEBox(tagBOX *arg0, tagBOX *arg1) {
    float sp30[4];
    float sp40[4];
    float sp50[4];
    float sp60[8][4];
    float mat1[4][4];
    float mat2[4][4];
    float sp160[4];
    int i;
    sceVu0UnitMatrix((PMat4 *)mat1);
    if (this == 0 || arg0 == 0) {
        return 0;
    }
    MakeVertexList((tagBOX *)sp60, (float (*)[4])arg1);
    memcpy(sp40, (char *)arg0 + 0x20, 0x10);
    memcpy(sp50, arg0, 0x10);
    ((PMat4 *)mat1)->InverseByRT(sp40, sp50);
    sceVu0CopyMatrix(mat2, mat1);
    memcpy(sp160, m_unk10, 0x10);
    float (*vp)[4] = sp60;
    for (i = 0; i < 8; i++) {
        *(u_long128 *)sp30 = *(u_long128 *)vp;
        *(int *)&sp30[3] = 0x3F800000;
        if (!FastMath_PointInSingleMatrixBox(sp30, (tagVuMatrixBox *)mat2)) {
            return 0;
        }
        vp++;
    }
    return 1;
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

// DRAFT: 0x157B00 GetAngleBetweenVectors__7MathAPIFPfPf
// note: 25 differing lines: -1.0f, 1.0f, 57.295776f are inline lui/mtc1 in orig, gp-pooled here (known pattern); clamp as two ifs or one || gave 35 and 25; register allocation of loads follows the literals.
float MathAPI::GetAngleBetweenVectors(float *arg0, float *arg1) {
    float dot = arg0[2] * arg1[2] + arg0[0] * arg1[0];
    float na = arg0[0] * arg0[0] + arg0[2] * arg0[2];
    float nb = arg1[0] * arg1[0] + arg1[2] * arg1[2];
    float c = dot / (sqrtf(na) * sqrtf(nb));
    if (c < -1.0f || c > 1.0f) {
        return 0.0f;
    }
    return FastMath_Fabs(57.295776f * acosf(c));
}

// FUNCTION: 0x157BC0 GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f
void MathAPI::GetForwardVector(EntityBaseClass *arg0, float (&arg1)[4]) {
    float sp30[4][4];
    float *angles;
    if (m_unk3C != 0) {
        angles = (float *)(m_unk3C + 0x90);
    } else {
        angles = m_unk1A0;
    }
    sceVu0UnitMatrix((PMat4 *)sp30);
    if (angles[0] != 0.0f) {
        ((PMat4 *)sp30)->RotateX(angles[0]);
    }
    if (angles[1] != 0.0f) {
        ((PMat4 *)sp30)->RotateY(angles[1]);
    }
    if (angles[2] != 0.0f) {
        ((PMat4 *)sp30)->RotateZ(angles[2]);
    }
    float *out = (float *)arg0;
    out[0] = -sp30[2][0];
    out[1] = -sp30[2][1];
    out[2] = -sp30[2][2];
    *(int *)&out[3] = 0x3F800000;
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

// DRAFT: 0x1581D0 GetRelAngleYToPoint__7MathAPIFPA4_ffPA4_f
// note: DIFF 64 (attempt 1). Original inlines 57.295776f/360.0f/180.0f as lui/ori/mtc1, ours loads gp-pooled lwc1; branch layout differs at 0x48. Integer-bit literal variant gave DIFF 69 (worse).
float MathAPI::GetRelAngleYToPoint(float (*arg0)[4], float arg1, float (*arg2)[4]) {
    float dx = arg0[0][0] - arg2[0][0];
    float dz = arg0[0][2] - arg2[0][2];
    if (dx == 0.0f && dz == 0.0f) {
        return arg1;
    }
    float ang = 57.295776f * atan2f(dx, dz);
    float a = ang;
    if (!(arg1 < ang)) {
        a = arg1;
    }
    float b = arg1;
    if (a == arg1) {
        b = ang;
    }
    float d = a - b;
    float wrap = (360.0f - a) + b;
    if (!(d <= wrap)) {
        d = wrap;
    }
    float sum = arg1 + d;
    if (!(sum <= 180.0f)) {
        if ((int)(sum - 360.0f) == (int)ang) {
            return d;
        }
        return -d;
    }
    if ((int)sum == (int)ang) {
        return d;
    }
    return -d;
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
