#include "types.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern "C" void __ct__16PTextureDmaChainFv(void *pThis);
extern "C" void __dt__16PTextureDmaChainFv(void *pThis, short nFlag);
extern "C" void Reset__16PTextureDmaChainFv(void *pThis);
void CdsAssert(char *pFile, int nLine, char *pExpr);

// FUNCTION: 0x180400 DeAllocEntries__12PDisplayListFi
void PDisplayList::DeAllocEntries(int nCount) {
    m_unkA3340 -= nCount;
}

// DRAFT: 0x180B20 BeginMatrixList__12PDisplayListFv
// note: original loads both string pointers with separate lui 0x26; mwcc CSEs the high half (ori), so the branch skip is 7 insns vs 8; tried (s32)/(int)/local-pointer casts
void PDisplayList::BeginMatrixList() {
    m_unkA334C = AllocEntries(1);
    if (m_unkA334C == 0) {
        CdsAssert((char *)0x266B90, 0x844, (char *)0x266BB8);
    }
    m_unkA3350 = 0;
}

// FUNCTION: 0x184120 Reset__12PDisplayListFv
void PDisplayList::Reset() {
    Reset__16PTextureDmaChainFv(m_unkA3380);
    m_unkA3340 = 0;
    m_unkA3344 = 0;
    m_unkA334C = 0;
    m_unkA3350 = 0;
}

// FUNCTION: 0x184570 __dt__12PDisplayListFv
PDisplayList::~PDisplayList() {
    __dt__16PTextureDmaChainFv(m_unkA3380, -1);
}

// FUNCTION: 0x1845D0 __ct__12PDisplayListFv
PDisplayList::PDisplayList() {
    __ct__16PTextureDmaChainFv(m_unkA3380);
    m_unkA3340 = 0;
    m_unkA3344 = 0;
    m_unkA334C = 0;
    m_unkA3350 = 0;
}
