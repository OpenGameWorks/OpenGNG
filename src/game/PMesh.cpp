// FLAGS: -str readonly
#include "types.h"
#include "PMesh.h"

// TODO(header): foreign declarations
extern "C" void __dt__13PMeshFragmentFv(void);
extern "C" void __destroy_new_array(void *pArray, void *pDtor);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

// DRAFT: 0x0018F590 SetSTAnimFlag__5PMeshFv
// note: original is 0x58 bytes with a bottom-tested loop and a join nop before jr; ours is 0x50. Tried while+return and for+break (9 words).
void PMesh::SetSTAnimFlag() {
    unsigned int nIndex;
    int nOffset;

    m_unkC = 0;
    nIndex = 0;
    nOffset = 0;
    while (nIndex < m_unk4) {
        if (*(unsigned int *)((char *)m_unk0 + nOffset + 0x10) & 1) {
            m_unkC = 1;
            return;
        }
        nOffset += 0x90;
        nIndex++;
    }
}

// FUNCTION: 0x0018F820 SetBoundBox__5PMeshFPA2_A4_f
void PMesh::SetBoundBox(float (*pBox)[2][4]) {
    if (pBox == 0) {
        CdsAssert__FPciPc("PMesh.cpp", 0x11F, "pBox");
    }
    *(u_long128 *)&m_unk10[0][0] = *(u_long128 *)&(*pBox)[0][0];
    *(u_long128 *)&m_unk10[1][0] = *(u_long128 *)&(*pBox)[1][0];
    m_unkD = 1;
}

// FUNCTION: 0x0018FDA0 Destroy__5PMeshFv
void PMesh::Destroy() {
    if (m_unk0 != 0) {
        __destroy_new_array(m_unk0, (void *)__dt__13PMeshFragmentFv);
        m_unk0 = 0;
        m_unk4 = 0;
    }
    m_unkC = 0;
    m_unk8 = 0;
    m_unkE = 0;
}

// FUNCTION: 0x0018FDF0 __dt__5PMeshFv
extern "C" PMesh *__dt__5PMeshFv(PMesh *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->Destroy();
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0018FE50 __ct__5PMeshFv
PMesh::PMesh() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkA = 0;
    m_unkE = 0;
    memset(m_unk10, 0, 0x20);
    m_unkD = 0;
    m_unkC = 0;
}
