#ifndef PMAT4_H
#define PMAT4_H

#include "types.h"

class PMat4 {
public:
    ~PMat4();
    void Inverse(PMat4 *arg0);
    int Inverse();
    void Translate(float arg0, float arg1, float arg2);
    void RotateZ(float arg0);
    void RotateY(float arg0);
    void RotateX(float arg0);
    int Mul(PMat4 *arg0);
    int Mul(PMat4 arg0);
    void LoadCol(int nCol, float arg1, float arg2, float arg3, float arg4);
    void MakeMayaMatrix();
    void MakePerspectiveMatrix(float arg0, float arg1, float arg2, float arg3);
    void MakeProjectionMatrix(float (*arg0)[4], float arg1, float arg2, int arg3, int arg4, int arg5, int arg6);
    void MakeMayaProjectionMatrix(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5);
    void MakeOrthographicMatrix(float (*arg0)[4], float arg1, float arg2, float arg3, float arg4, float arg5, float arg6);
    void MakeParallelProjectionMatrix(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11);
    void MakeScreenMatrix2(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7);
    void MakeScreenMatrix(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8);
    void InverseByRT(float *arg0, float *arg1);
    void MulVector(float *arg0, float *arg1);

    float m_unk00[4][4];
};

#endif
