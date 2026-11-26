#include "types.h"
#include "CeilingDebris.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(void *pThis, unsigned int nId);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);
extern unsigned int ChurchCeilingDebris_FallSeq[16];
extern unsigned int DeadseaCeilingDebris_FallSeq[16];

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("CeilingDebris.cpp", line, #cond))

// FUNCTION: 0x0020F7C0 __dt__13CeilingDebrisFv
CeilingDebris::~CeilingDebris() {
}

// FUNCTION: 0x0020F820 GetClassName__13CeilingDebrisFv
const char *CeilingDebris::GetClassName() {
    return "CeilingDebris";
}

// FUNCTION: 0x0020F830 SetEditableVars__13CeilingDebrisFPc
void CeilingDebris::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x8);
}

// DRAFT: 0x0020F840 Execute__13CeilingDebrisFv
// note: 16 words differ; the default-arm assert (CDS_ASSERT, 0x41) tests the switch value with sltu/xori in the original but loads the message address in ours. Tried: switch with cases -1,0,-2 (54), <= -1 for slti/bnez (34), nested switch on m_unk1B0 (16, kept), direct CdsAssert with a variable cond (31).
void CeilingDebris::Execute() {
    switch (m_unk20) {
    case -1: {
        void *pInst = InstanceIsValid__15EntityBaseClassFUi(m_unk1B4, -2);
        if (m_unk1B4 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
            return;
        }
        if (pInst == 0) {
            return;
        }
        if (*(int *)((char *)pInst + 0x20) <= -1) {
            return;
        }
        SetState__15EntityBaseClassFi(this, 0);
        break;
    }
    case 0:
        if (m_unkE9 != 0) {
            switch (m_unk1B0) {
            case 0:
                PlaySequence__15EntityBaseClassFPUi(this, ChurchCeilingDebris_FallSeq);
                break;
            case 1:
                PlaySequence__15EntityBaseClassFPUi(this, DeadseaCeilingDebris_FallSeq);
                break;
            default:
                CDS_ASSERT(0x41, !"!mEVars.m_iDebrisType");
                break;
            }
        } else if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x0020F970 __ct__13CeilingDebrisFv
CeilingDebris::CeilingDebris() : EntityBaseClass((EntityBaseClass::LoadClass)2, 0) {
}
