// FLAGS: -lang c++ -str readonly
#include "types.h"
#include "FastMath.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void Vu0_Pt_In_MatrixBox(void);

struct tagVuMatrixBox { float m[5][4]; };

// DRAFT: 0x0012F320 FastMath_PointInMatrixBox__FP14tagVuMatrixBoxiPfPi
// note: 20 differing lines: loop counter/result register order and i<<2 CSE across pBox/pRes differ (the VU0 lanes match); tried index forms, split asm blocks and nRes/i declaration order
void FastMath_PointInMatrixBox(tagVuMatrixBox *pBoxTable, int nBoxes, float *pPoint, int *piResultTable) {
    int nRes;
    int i;
    if (pBoxTable == 0) CdsAssert__FPciPc("FastMath.c", 0x70E, "pBoxTable");
    if (piResultTable == 0) CdsAssert__FPciPc("FastMath.c", 0x70F, "piResultTable");
    asm { lqc2 vf6, 0(pPoint) }
    for (i = 0; i < nBoxes; i++) {
        tagVuMatrixBox *pBox = &pBoxTable[i];
        asm {
            lqc2 vf1, 0x0(pBox)
            lqc2 vf2, 0x10(pBox)
            lqc2 vf3, 0x20(pBox)
            lqc2 vf4, 0x30(pBox)
            lqc2 vf5, 0x40(pBox)
            vcallms Vu0_Pt_In_MatrixBox
            qmfc2.i nRes, vf31
        }
        piResultTable[i] = nRes;
    }
}
