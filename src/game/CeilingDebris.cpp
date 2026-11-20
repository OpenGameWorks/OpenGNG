#include "types.h"
#include "CeilingDebris.h"

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

// DRAFT: 0x0020F840 Execute__13CeilingDebrisFv
// note: 43 words differ; branch layout (-2 and -1 tests, shared epilogue placement, inline -1 body) and 0-block order still differ. Tried: -1 block as primary if, early-return forms, else-return form (best), removing top -2 test (64).
void CeilingDebris::Execute() {
    if (m_unk20 == -2) {
        return;
    }
    if (m_unk20 != 0) {
        if (m_unk20 == -1) {
            void *pInst = InstanceIsValid__15EntityBaseClassFUi(m_unk1B4, -2);
            if (m_unk1B4 == 0) {
                SetState__15EntityBaseClassFi(this, -2);
                return;
            }
            if (pInst == 0) {
                return;
            }
            if (*(int *)((char *)pInst + 0x20) < 0) {
                return;
            }
            SetState__15EntityBaseClassFi(this, 0);
        } else {
            return;
        }
    } else {
        if (m_unkE9 != 0) {
            if (m_unk1B0 == 1) {
                PlaySequence__15EntityBaseClassFPUi(this, DeadseaCeilingDebris_FallSeq);
            } else if (m_unk1B0 == 0) {
                PlaySequence__15EntityBaseClassFPUi(this, ChurchCeilingDebris_FallSeq);
            } else {
                CDS_ASSERT(0x41, !"!mEVars.m_iDebrisType");
            }
        } else if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
        }
    }
}

// FUNCTION: 0x0020F970 __ct__13CeilingDebrisFv
CeilingDebris::CeilingDebris() : EntityBaseClass((EntityBaseClass::LoadClass)2, 0) {
}
