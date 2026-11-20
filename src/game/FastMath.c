// FLAGS: -lang c++ -str readonly
#include "types.h"
#include "FastMath.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

// VU0 microprogram placeholder (Vu0_Pt_In_MatrixBox, entry 0x828); no C form yet.
static int FastMath_Vu0PtInMatrixBox(float *pBox, float *pPoint) {
    return 0;
}

// DRAFT: 0x0012F320 FastMath_PointInMatrixBox__FP14tagVuMatrixBoxiPfPi
// note: VU0 lanes (lqc2 x5, vcallms 0x828, qmfc2) and the pre-loop lqc2 vf6 point load have no C form; entry arg-register order and string literal addressing also differ (37 words)
void FastMath_PointInMatrixBox(tagVuMatrixBox *pBoxTable, int nBoxes, float *pPoint, int *piResultTable) {
    int i;

    if (pBoxTable == 0) {
        CdsAssert__FPciPc("FastMath.c", 0x70E, "pBoxTable");
    }
    if (piResultTable == 0) {
        CdsAssert__FPciPc("FastMath.c", 0x70F, "piResultTable");
    }
    for (i = 0; i < nBoxes; i++) {
        piResultTable[i] = FastMath_Vu0PtInMatrixBox((float *)((char *)pBoxTable + i * 0x50), pPoint);
    }
}
