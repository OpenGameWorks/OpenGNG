// FLAGS: -str readonly
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void sceVu0InversMatrix(float (*)[4], float (*)[4]);
extern "C" void sceVu0MulMatrix(float (*)[4], float (*)[4], float (*)[4]);
extern "C" void sceVu0TransMatrix(PMat4 *m0, PMat4 *m1, float *trans);
extern "C" void sceVu0CopyMatrix(float (*)[4], float (*)[4]);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern "C" float tanf(float x);
float Round180(float arg0);
void FastMath_MatRotateZ(float (*arg0)[4], float (*arg1)[4], float arg2);
void FastMath_MatRotateY(float (*arg0)[4], float (*arg1)[4], float arg2);
void FastMath_MatRotateX(float (*arg0)[4], float (*arg1)[4], float arg2);

// DRAFT: 0x00130690 MakeProjectionMatrix__5PMat4FPA4_fffiiii
// note: 3 words differ: the three mul.s by -1.0f put the constant in the first operand (original has the variable first); swapping the source operands and a local neg variable did not change it.
void PMat4::MakeProjectionMatrix(float (*arg0)[4], float arg1, float arg2, int arg3, int arg4, int arg5, int arg6) {
    float f3 = (float)(-arg3 / 2) + arg1;
    float f4 = (((float)(arg3 / 2) + arg1) - f3) / 2.0f;
    float f5 = (float)(-arg4 / 2) + arg2;
    float f2 = (((float)(arg4 / 2) + arg2) - f5) / 2.0f;
    float f6 = (float)arg6;
    float f1 = ((float)arg5 - f6) / 2.0f;
    arg0[0][0] = f4;
    arg0[1][0] = 0.0f;
    arg0[2][0] = 0.0f;
    arg0[3][0] = f3 - f4 * -1.0f;
    arg0[0][1] = 0.0f;
    arg0[1][1] = f2;
    arg0[2][1] = 0.0f;
    arg0[3][1] = f5 - f2 * -1.0f;
    arg0[0][2] = 0.0f;
    arg0[1][2] = 0.0f;
    arg0[2][2] = f1;
    arg0[3][2] = f6 - f1 * -1.0f;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
}

// FUNCTION: 0x001307D0 MakePerspectiveMatrix__5PMat4Fffff
void PMat4::MakePerspectiveMatrix(float arg0, float arg1, float arg2, float arg3) {
    float cot = 1.0f / tanf(0.017453292f * (arg0 / 2.0f));
    m_unk00[0][0] = cot / arg1;
    m_unk00[0][1] = 0.0f;
    m_unk00[0][2] = 0.0f;
    m_unk00[0][3] = 0.0f;
    m_unk00[1][0] = 0.0f;
    m_unk00[1][1] = cot;
    m_unk00[1][2] = 0.0f;
    m_unk00[1][3] = 0.0f;
    m_unk00[2][0] = 0.0f;
    m_unk00[2][1] = 0.0f;
    m_unk00[2][2] = (arg3 + arg2) / (arg3 - arg2);
    m_unk00[2][3] = 1.0f;
    m_unk00[3][0] = 0.0f;
    m_unk00[3][1] = 0.0f;
    m_unk00[3][2] = -(2.0f * arg3 * arg2) / (arg3 - arg2);
    m_unk00[3][3] = 0.0f;
}

// DRAFT: 0x001308B0 MakeMayaMatrix__5PMat4Fv
// note: MW folds literal-only float ops (1.4994709f/1.4f, 0.07257143f*1.0f) the original keeps as runtime div.s/mul.s; size 0x264 vs 0x3B8; tried 3 variants (float-only, lazy float, double chains)
void PMat4::MakeMayaMatrix() {
    float f20 = 0.07257143f * 1.0f;
    float f21 = 1.4994709f / 1.4f;
    float f25 = 0.0f;
    if ((double)f21 > 1.0) {
        f25 = f25 * (0.945f - 0.945f * f21) / 2.0f;
    }
    double d1 = -0.5 * (double)1.417f;
    double d2 = d1 * 1.0;
    double d3 = 0.0 + d2;
    double d4 = 0.0 + d3;
    float f22 = (float)((double)f20 * d4);
    double d5 = 0.5 * (double)1.417f;
    double d6 = d5 * 1.0;
    double d7 = 0.0 + d6;
    double d8 = 0.0 + d7;
    float f23 = (float)((double)f20 * d8);
    double e1 = -0.5 * (double)0.945f;
    double e2 = e1 * (double)f21;
    double e3 = 0.0 + e2;
    double e4 = (double)f25 + e3;
    float f24 = (float)((double)f20 * e4);
    double g1 = 0.5 * (double)0.945f;
    double g2 = g1 * (double)f21;
    double g3 = 0.0 + g2;
    double g4 = (double)f25 + g3;
    float f0 = (float)((double)f20 * g4);
    float f4 = f23 - f22;
    float f3 = f23 + f22;
    float f5 = f0 - f24;
    m_unk00[0][0] = 0.2f / f4;
    m_unk00[1][0] = 0.0f;
    m_unk00[2][0] = f3 / f4;
    m_unk00[3][0] = 0.0f;
    m_unk00[0][1] = 0.0f;
    m_unk00[1][1] = 0.2f / f5;
    m_unk00[2][1] = (f0 + f24) / f5;
    m_unk00[3][1] = 0.0f;
    m_unk00[0][2] = 0.0f;
    m_unk00[1][2] = 0.0f;
    m_unk00[2][2] = 1.0001999f;
    m_unk00[3][2] = -200.0f / 999.9f;
    m_unk00[0][3] = 0.0f;
    m_unk00[1][3] = 0.0f;
    m_unk00[2][3] = 1.0f;
    m_unk00[3][3] = 0.0f;
}

// FUNCTION: 0x00130C70 MakeMayaProjectionMatrix__5PMat4Fffffff
void PMat4::MakeMayaProjectionMatrix(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    float proj[4][4];
    float tmp[4][4];

    sceVu0UnitMatrix(&tmp[0][0]);
    ((PMat4 *)&tmp[0][0])->MakeMayaMatrix();
    MakeProjectionMatrix(proj, arg0, arg1, (int)arg2, (int)arg3, (int)arg4, (int)arg5);
    sceVu0MulMatrix((float (*)[4])this, proj, tmp);
}

// FUNCTION: 0x00130D30 __dt__5PMat4Fv
PMat4::~PMat4() {
}

// DRAFT: 0x00130D80 MakeOrthographicMatrix__5PMat4FPA4_fffffff
// note: 9 words differ; store of [2][2] scheduled before the sw $zero,0x2C and the neg.s placement on the last division differ. Tried neg on [3][2] numerator (10 words), operand orders (11 to 9).
void PMat4::MakeOrthographicMatrix(float (*arg0)[4], float arg1, float arg2, float arg3, float arg4, float arg5, float arg6) {
    arg0[0][0] = 2.0f / (arg2 - arg1);
    arg0[0][1] = 0.0f;
    arg0[0][2] = 0.0f;
    arg0[0][3] = 0.0f;
    arg0[1][0] = 0.0f;
    arg0[1][1] = 2.0f / (arg3 - arg4);
    arg0[1][2] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][0] = 0.0f;
    arg0[2][1] = 0.0f;
    arg0[2][2] = 2.0f / (arg6 - arg5);
    arg0[2][3] = 0.0f;
    arg0[3][0] = -(arg2 + arg1) / (arg2 - arg1);
    arg0[3][1] = -(arg3 + arg4) / (arg3 - arg4);
    arg0[3][2] = -(arg6 + arg5) / (arg6 - arg5);
    arg0[3][3] = 1.0f;
}

// FUNCTION: 0x00130E10 MakeParallelProjectionMatrix__5PMat4Fffffffffffff
void PMat4::MakeParallelProjectionMatrix(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11) {
    float ortho[4][4];
    float proj[4][4];

    MakeOrthographicMatrix(ortho, arg6, arg7, arg8, arg9, arg10, arg11);
    MakeProjectionMatrix(proj, arg0, arg1, (int)arg2, (int)arg3, (int)arg4, (int)arg5);
    sceVu0MulMatrix((float (*)[4])this, proj, ortho);
}

// FUNCTION: 0x00130EE0 MakeScreenMatrix2__5PMat4Fffffffff
void PMat4::MakeScreenMatrix2(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7) {
    float proj[4][4];
    float persp[4][4];

    sceVu0UnitMatrix(&persp[0][0]);
    ((PMat4 *)&persp[0][0])->MakePerspectiveMatrix(arg0, arg1, arg6, arg7);
    MakeProjectionMatrix(proj, arg2, arg3, SCREEN_WIDTH, SCREEN_HEIGHT, (int)arg4, (int)arg5);
    sceVu0MulMatrix((float (*)[4])this, proj, persp);
}

// FUNCTION: 0x00130FC0 MakeScreenMatrix__5PMat4Ffffffffff
void PMat4::MakeScreenMatrix(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8) {
    float tmp[4][4];

    sceVu0UnitMatrix((float *)this);
    m_unk00[0][0] = arg0;
    m_unk00[1][1] = arg0;
    m_unk00[2][2] = 0.0f;
    m_unk00[3][3] = 0.0f;
    m_unk00[3][2] = 1.0f;
    m_unk00[2][3] = 1.0f;
    sceVu0UnitMatrix(&tmp[0][0]);
    tmp[0][0] = arg1;
    tmp[1][1] = arg2;
    tmp[3][0] = arg3;
    tmp[3][1] = arg4;
    tmp[2][2] = (arg8 * arg7 * (-arg5 + arg6)) / (-arg7 + arg8);
    tmp[3][2] = (-arg6 * arg7 + arg5 * arg8) / (-arg7 + arg8);
    sceVu0MulMatrix((float (*)[4])this, tmp, (float (*)[4])this);
}

// DRAFT: 0x001310F0 InverseByRT__5PMat4FPfPf
// note: DIFF 46 words; first version without the sq/lq copy layout (sp+0x40/0x50/0x60) and with the wrong this+0x30 store; asm fold order not reproduced.
void PMat4::InverseByRT(float *arg0, float *arg1) {
    float vec[4];
    float out[4];

    sceVu0UnitMatrix((float *)this);
    vec[0] = -arg1[0];
    vec[1] = -arg1[1];
    vec[2] = -arg1[2];
    vec[3] = 1.0f;
    RotateZ(-arg0[2]);
    RotateY(-arg0[1]);
    RotateX(-arg0[0]);
    MulVector(out, vec);
    out[3] = 1.0f;
    *(u_long128 *)m_unk00[3] = *(u_long128 *)out;
}

// FUNCTION: 0x001311B0 Inverse__5PMat4FP5PMat4
void PMat4::Inverse(PMat4 *arg0) {
    if (arg0 == 0) {
        CdsAssert__FPciPc("PMat4.cpp", 0x118, "pMatResult");
    }
    sceVu0InversMatrix((float (*)[4])arg0, (float (*)[4])this);
}

// DRAFT: 0x00131210 Inverse__5PMat4Fv
// note: mangled name has no parameter, but the asm reads a1 as the inverse source; this uses this as the source.
int PMat4::Inverse() {
    float tmp[4][4];

    sceVu0UnitMatrix(&tmp[0][0]);
    sceVu0InversMatrix(tmp, (float (*)[4])this);
    sceVu0CopyMatrix((float (*)[4])this, tmp);
    return 0;
}

// FUNCTION: 0x00131260 Translate__5PMat4Ffff
void PMat4::Translate(float arg0, float arg1, float arg2) {
    float vec[4];

    vec[0] = arg0;
    vec[3] = 1.0f;
    vec[1] = arg1;
    vec[2] = arg2;
    sceVu0TransMatrix(this, this, vec);
}

// FUNCTION: 0x001312A0 RotateZ__5PMat4Ff
void PMat4::RotateZ(float arg0) {
    FastMath_MatRotateZ((float (*)[4])this, (float (*)[4])this, Round180(arg0));
}

// FUNCTION: 0x001312E0 RotateY__5PMat4Ff
void PMat4::RotateY(float arg0) {
    FastMath_MatRotateY((float (*)[4])this, (float (*)[4])this, Round180(arg0));
}

// FUNCTION: 0x00131320 RotateX__5PMat4Ff
void PMat4::RotateX(float arg0) {
    FastMath_MatRotateX((float (*)[4])this, (float (*)[4])this, Round180(arg0));
}

// DRAFT: 0x00131360 Mul__5PMat4FP5PMat4
// note: asm reads a1 and a2 as the two multiply operands and asserts on a2; the one-pointer mangled name can express only this and one operand.
int PMat4::Mul(PMat4 *arg0) {
    float tmp[4][4];

    sceVu0UnitMatrix(&tmp[0][0]);
    if (arg0 == 0) {
        CdsAssert__FPciPc("PMat4.cpp", 0x5F, "pMat");
    }
    sceVu0MulMatrix(tmp, (float (*)[4])this, (float (*)[4])arg0);
    sceVu0CopyMatrix((float (*)[4])this, tmp);
    return 0;
}

// DRAFT: 0x001313E0 Mul__5PMat4F5PMat4
// note: asm reads a1 and a2 as the two multiply operands; the by-value mangled name can express only this and one operand.
int PMat4::Mul(PMat4 arg0) {
    float tmp[4][4];

    sceVu0UnitMatrix(&tmp[0][0]);
    sceVu0MulMatrix(tmp, (float (*)[4])this, (float (*)[4])&arg0);
    sceVu0CopyMatrix((float (*)[4])this, tmp);
    return 0;
}

// DRAFT: 0x00131440 LoadCol__5PMat4Fiffff
// note: 13 words differ; original folds this+nCol*16 once and orders the four stores with per-element address chains. Tried m_unk00[nCol][k], char* base with constant offsets, and per-store offsets; all 13 words.
void PMat4::LoadCol(int nCol, float arg1, float arg2, float arg3, float arg4) {
    m_unk00[nCol][0] = arg1;
    m_unk00[nCol][1] = arg2;
    m_unk00[nCol][2] = arg3;
    m_unk00[nCol][3] = arg4;
}
