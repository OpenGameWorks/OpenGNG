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
extern "C" long long fptodp(float x);
extern "C" int _dpfgt(long long a, long long b);
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
extern "C" void sceVu0ApplyMatrix(tagBOX *dst, float *m, float *src);
extern "C" void FastMath_ComputeMatrixLite(float (*)[4], float (*)[4], float (*)[4], float (*)[4], int);
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
// note: 61 differing words; frame 0x180 vs 0x170, draft saves s0-s2 vs original s0-s1; s2/s1 register assignment differs across sceVu0UnitMatrix. Tried: pointer loop (63->62), local reorder (no change), uninitialized local as MakeVertexList arg2 (62->61), third memcpy from arg0+0x10 (no change, kept as correct source).
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
    float (*unset)[4];
    MakeVertexList((tagBOX *)sp60, unset);
    memcpy(sp40, (char *)arg0 + 0x20, 0x10);
    memcpy(sp50, arg0, 0x10);
    ((PMat4 *)mat1)->InverseByRT(sp40, sp50);
    sceVu0CopyMatrix(mat2, mat1);
    memcpy(sp160, (char *)arg0 + 0x10, 0x10);
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

// DRAFT: 0x1577A0 MakeVertexList__7MathAPIFP6tagBOXPA4_f
// note: 28 differing words; this/arg0 registers s1/s0 vs s0/s5, packed 1.0f build (lui/dsll32/or/pcpyld/sq) vs four sw. Tried: local order (42->32), unsigned counters (->31), reversed counter order (->28), separate dst pointer (47, reverted).
void MathAPI::MakeVertexList(tagBOX *arg0, float (*arg1)[4]) {
    float sp90[4][4];
    float spD0[4];
    float spE0[4];
    float spF0[4];
    float sp100[4];
    float sp110[4];
    unsigned int k;
    unsigned int j;
    unsigned int i;

    if (this == 0) {
        return;
    }
    if (arg0 == 0) {
        return;
    }
    memcpy(spF0, this, 0x10);
    memcpy(spE0, (char *)this + 0x20, 0x10);
    memcpy(sp100, (char *)this + 0x10, 0x10);
    spD0[0] = 1.0f;
    spD0[1] = 1.0f;
    spD0[2] = 1.0f;
    spD0[3] = 1.0f;
    FastMath_ComputeMatrixLite(sp90, (float (*)[4])spD0, (float (*)[4])spE0, (float (*)[4])spF0, 0);
    sp110[3] = 1.0f;
    sp110[0] = -sp100[0];
    for (i = 0; i < 2; i++) {
        sp110[1] = -sp100[1];
        for (j = 0; j < 2; j++) {
            sp110[2] = -sp100[2];
            for (k = 0; k < 2; k++) {
                sceVu0ApplyMatrix(arg0, &sp90[0][0], sp110);
                arg0 = (tagBOX *)((char *)arg0 + 0x10);
                sp110[2] = sp100[2];
            }
            sp110[1] = sp100[1];
        }
        sp110[0] = sp100[0];
    }
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

// DRAFT: 0x157950 QuatSlerp__7MathAPIFP9tag_EQuatP9tag_EQuatfP9tag_EQuat
// note: 8 differing words, all the 64-bit literal 0x3EB0C6F7A0B5ED8D build at 0xA0-0xC0 (orig: hi in a0, lo in v1, or a1,v1,a0; ours hi/lo in v1/v0). Tried split hi<<32|lo and swapped operands: both 8. Negation order now matches.
void MathAPI::QuatSlerp(tag_EQuat *arg0, tag_EQuat *arg1, float arg2, tag_EQuat *arg3) {
    float dot = arg0->m_unkC * arg1->m_unkC + (arg0->m_unk4 * arg1->m_unk4 + arg0->m_unk8 * arg1->m_unk8) + arg0->m_unk0 * arg1->m_unk0;
    float by = arg1->m_unk4;
    float bz = arg1->m_unk8;
    float bw = arg1->m_unkC;
    float bx = arg1->m_unk0;
    if (dot < 0.0f) {
        dot = -dot;
        by = -by;
        bz = -bz;
        bw = -bw;
        bx = -bx;
    }
    float w1;
    float w2;
    if (_dpfgt(fptodp(1.0f - dot), 0x3EB0C6F7A0B5ED8DLL) != 0) {
        float theta = acosf(dot);
        float sinTheta = sinf(theta);
        w1 = sinf((1.0f - arg2) * theta) / sinTheta;
        w2 = sinf(arg2 * theta) / sinTheta;
    } else {
        w1 = 1.0f - arg2;
        w2 = arg2;
    }
    arg3->m_unk4 = w1 * arg0->m_unk4 + w2 * by;
    arg3->m_unk8 = w1 * arg0->m_unk8 + w2 * bz;
    arg3->m_unkC = w1 * arg0->m_unkC + w2 * bw;
    arg3->m_unk0 = w1 * arg0->m_unk0 + w2 * bx;
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

// DRAFT: 0x158330 GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f
// note: 48 words with the non-static header FacingPoint 0x157D10 needs; the original is static-style (entity in a0, array in a1), so static gives 45 here but breaks FacingPoint (DIFF 17). Remaining: obj in v0 not v1, early-return branch offset, f4 vs f3 angle reg, atan2f reloc one insn off.
float MathAPI::GetRelAngleYToPoint(EntityBaseClass *arg0, float (*arg1)[4]) {
    char *self = (char *)arg0;
    char *obj = *(char **)(self + 0x3C);
    float (*a)[4] = obj ? (float (*)[4])(obj + 0x80) : (float (*)[4])(self + 0x190);
    float (*b)[4] = obj ? (float (*)[4])(obj + 0x90) : (float (*)[4])(self + 0x1A0);
    float dx = a[0][0] - arg1[0][0];
    float dz = a[0][2] - arg1[0][2];
    if (dx == 0.0f && dz == 0.0f) {
        return b[0][1];
    }
    float ang = 57.295776f * atan2f(dx, dz);
    float arg1f = b[0][1];
    float lo = ang;
    if (!(arg1f < ang)) {
        lo = arg1f;
    }
    float hi = arg1f;
    if (lo == arg1f) {
        hi = ang;
    }
    float d = lo - hi;
    float wrap = (360.0f - lo) + hi;
    if (!(d <= wrap)) {
        d = wrap;
    }
    float sum = arg1f + d;
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
