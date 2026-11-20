// FLAGS: -str readonly
#include "types.h"
#include "PMotionBlur.h"

// TODO(header): foreign declarations
extern "C" void __destroy_new_array(void *pArray, void (*pDtor)(void *));
extern "C" void __dt__5PMat4Fv(void *pThis);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

// FUNCTION: 0x001C8CB0 Reset__11PMotionBlurFv
void PMotionBlur::Reset() {
    int nCount;
    int i;
    PMotionBlurEntry *pEntry;

    nCount = m_unk90.m_unk0;
    for (i = 0; i < nCount; i++) {
        pEntry = (i < m_unk90.m_unk0) ? (PMotionBlurEntry *)m_unk90.m_unk8[i] : 0;
        if (pEntry != 0) {
            if (pEntry->m_pMatrices != 0) {
                __destroy_new_array(pEntry->m_pMatrices, __dt__5PMat4Fv);
                pEntry->m_pMatrices = 0;
            }
            __dl__FPv(pEntry);
        }
    }
    if (m_unk90.m_unk8 != 0) {
        m_unk90.m_unk0 = 0;
        m_unk90.m_unk4 = 0;
    }
    memset(this, 0, 0x80);
    m_unk60 = 0;
    m_unk80 = 0;
    m_unk84 = 0;
    m_unkA0 = 0;
    m_unkA5 = 0;
}

// FUNCTION: 0x001C91C0 Update__11PMotionBlurFv
void PMotionBlur::Update() {
    char *pSrc;
    int nCount;
    int i;
    PMotionBlurEntry *pEntry;

    if (m_unkA4 != 0) {
        nCount = m_unk90.m_unk0;
        for (i = 0; i < nCount; i++) {
            pEntry = (i < m_unk90.m_unk0) ? (PMotionBlurEntry *)m_unk90.m_unk8[i] : 0;
            if (pEntry != 0) {
                pSrc = (char *)pEntry->m_pSource;
                char *pDst = (char *)pEntry->m_pMatrices + (m_unkA0 << 6);
                *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x40);
                *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x50);
                *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x60);
                *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x70);
            }
        }
        m_unkA0++;
        if (m_unkA0 < m_unk88) {
            return;
        }
        m_unkA0 = 0;
    }
}

// FUNCTION: 0x001C9280 Create__11PMotionBlurFP6PMNodeP6PMNodei
bool PMotionBlur::Create(PMNode *poSourceObj, PMNode *poBlurObj, int nCount) {
    if (poSourceObj == 0) {
        CdsAssert__FPciPc("PMotionBlur.cpp", 0x49, "poSourceObj");
    }
    if (poBlurObj == 0) {
        CdsAssert__FPciPc("PMotionBlur.cpp", 0x4A, "poBlurObj");
    }
    Reset();
    m_unk80 = poSourceObj;
    m_unk84 = poBlurObj;
    m_unk88 = nCount;
    m_unkA0 = 0;
    CreateBlurNodes(m_unk80, m_unk84);
    m_unkA4 = 0;
    return m_unk90.m_unk0 != 0;
}

// FUNCTION: 0x001C9480 __dt__11PMotionBlurFv
PMotionBlur::~PMotionBlur() {
    Reset();
}

// FUNCTION: 0x001C94E0 __ct__11PMotionBlurFv
PMotionBlur::PMotionBlur() {
    memset(this, 0, 0x80);
    m_unkA0 = 0;
    m_unk80 = 0;
    m_unk84 = 0;
    m_unk88 = 0;
    m_unkA4 = 0;
    m_unkA5 = 0;
    m_unk8C = 20.0f;
}
