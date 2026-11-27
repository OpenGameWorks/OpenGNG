// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "AnimTrigger.h"
#include "PArray.h"
#include "EntityBaseClass.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
class TriggerSystem {
public:
    char _pad0[0xA];
    signed char m_unkA;
};
extern unsigned char __vt__11AnimTrigger[];
extern char *mpEntMgr__15EntityBaseClass;
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void __dl__FPv(void *pMem);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" TriggerSystem *__ct__13TriggerSystemFiPA4_fUisbsfbUiUiUiUiUiUiUiUiUiUibb(TriggerSystem *pThis, int nAnim, float *pPos, unsigned int nFlags, short sA, bool bA, short sB, float fScale, bool bB, unsigned int u0, unsigned int u1, unsigned int u2, unsigned int u3, unsigned int u4, unsigned int u5, unsigned int u6, unsigned int u7, unsigned int u8, unsigned int u9, bool bC, bool bD);

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("AnimTrigger.cpp", line, #cond))

// FUNCTION: 0x001B0510 __dt__11AnimTriggerFv
extern "C" AnimTrigger *__dt__11AnimTriggerFv(AnimTrigger *pThis, short nFlag)
{
    if (pThis != 0) {
        pThis->m_unk0 = __vt__11AnimTrigger;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001B0570 GetClassName__11AnimTriggerFv
const char *AnimTrigger::GetClassName() {
    return "Anim Trigger";
}

// FUNCTION: 0x001B0580 NeedsToBeWoken__11AnimTriggerFv
int AnimTrigger::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x208);
}

// FUNCTION: 0x001B0590 GetWokenVarPos__11AnimTriggerFv
int AnimTrigger::GetWokenVarPos() {
    return 19;
}

// FUNCTION: 0x001B05A0 SetEditableVars__11AnimTriggerFPc
void AnimTrigger::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x5C);
}

// FUNCTION: 0x001B05B0 Execute__11AnimTriggerFv
void AnimTrigger::Execute()
{
    TriggerSystem *pTrg;

    switch (m_unk20) {
    case -1:
        pTrg = (TriggerSystem *)__nw__FUi(0x50);
        if (pTrg != 0) {
            pTrg = __ct__13TriggerSystemFiPA4_fUisbsfbUiUiUiUiUiUiUiUiUiUibb(
                pTrg, m_unk4, m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190,
                m_unk1B4, (short)m_unk1B8, (m_unk1B8 >= 0) ? false : true, (short)m_unk1BC, m_unk1B0,
                m_unk1D4 != 0, m_unk1F8, m_unk1FC, m_unk1D8, m_unk1DC, m_unk1E0,
                m_unk1E8, m_unk1EC, m_unk1F0, m_unk1E4, m_unk1F4, m_unk200 != 0,
                m_unk204 != 0);
        }
        CDS_ASSERT(0x2B, pTrg);
        if (m_unk1D0 != 0) {
            pTrg->m_unkA = (signed char)m_unk1D0;
        }
        ((PArray *)((char *)mpEntMgr__15EntityBaseClass + 0x5B60))->Add(pTrg);
        SetState__15EntityBaseClassFi(this, -2);
    }
}

// FUNCTION: 0x001B0710 __ct__11AnimTriggerFv
extern "C" AnimTrigger *__ct__11AnimTriggerFv(AnimTrigger *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 4, 0);
    pThis->m_unk0 = __vt__11AnimTrigger;
    return pThis;
}
