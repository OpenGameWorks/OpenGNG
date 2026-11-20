// FLAGS: -str readonly
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void sceVu0InversMatrix(float (*)[4], float (*)[4]);
extern "C" void sceVu0MulMatrix(float (*)[4], float (*)[4], float (*)[4]);
extern "C" void sceVu0TransMatrix(PMat4 *m0, PMat4 *m1, float *trans);
float Round180(float arg0);
void FastMath_MatRotateZ(float (*arg0)[4], float (*arg1)[4], float arg2);
void FastMath_MatRotateY(float (*arg0)[4], float (*arg1)[4], float arg2);
void FastMath_MatRotateX(float (*arg0)[4], float (*arg1)[4], float arg2);

// FUNCTION: 0x00130D30 __dt__5PMat4Fv
PMat4::~PMat4() {
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
