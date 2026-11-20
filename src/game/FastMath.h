#ifndef FASTMATH_H
#define FASTMATH_H

#include "types.h"

struct tagVuMatrixBox;

void FastMath_PointInMatrixBox(tagVuMatrixBox *pBoxTable, int nBoxes, float *pPoint, int *piResultTable);

#endif
