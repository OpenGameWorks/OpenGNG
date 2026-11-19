#ifndef PMAT4_H
#define PMAT4_H

#include "types.h"

class PMat4 {
public:
    void Translate(float arg0, float arg1, float arg2);
    void RotateZ(float arg0);
    void RotateY(float arg0);
    void RotateX(float arg0);
    void LoadCol(int nCol, float arg1, float arg2, float arg3, float arg4);

    float m_unk00[4][4];
};

#endif
