// FLAGS: -str readonly
#include "types.h"
#include "ReversibleAnimTrigger.h"
#include "EntityBaseClass.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__21ReversibleAnimTrigger[];
extern unsigned char gEng[0x19B90];
extern "C" void StartCutCamera__6CameraFUib(void *pThis, unsigned int arg0, bool bFlag);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int arg0);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void memcpy(void *, const void *, unsigned int);

// Leading virtuals of PMNode's vtable (__vt__6PMNode): a call through this view
// loads the slot into $t9 as the original's virtual calls do.
class PMNodeVirtuals {
public:
    virtual ~PMNodeVirtuals();
    virtual void Render(void *, int, int);
    virtual void SetFrameTime(float fTime);
    virtual void CreateObjectDisplayList();
    virtual void Animate(float, float, void *, int, bool);
    virtual void SetAllAnimFlags(void *pAnim);
};

// FUNCTION: 0x001EB530 CheckForSound__21ReversibleAnimTriggerFP6PMNode
void ReversibleAnimTrigger::CheckForSound(PMNode *pNode) {
    int nState = *(int *)(gEng + 0x19A78);
    if (nState != 6) {
        return;
    }
    void *pData = pNode->m_unk24;
    unsigned int nType;
    if (pData != 0) {
        nType = *(unsigned int *)((char *)pData + 4);
    } else {
        nType = 0;
    }
    switch (nType) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        m_unk1E8 = pNode->PlaySound(0x2F);
        break;
    }
}

// FUNCTION: 0x001EB5B0 OnTouchEvent__21ReversibleAnimTriggerFP15EntityBaseClass
void ReversibleAnimTrigger::OnTouchEvent(EntityBaseClass *arg0) {
    if (arg0->m_unk08 == 3 && m_unk1E4) {
        if (m_unk1C4 > 0) {
            StartCutCamera__6CameraFUib(gEng + 0x19760, m_unk1C4, false);
        }
        SetState__15EntityBaseClassFi(this, 1);
    }
}

// FUNCTION: 0x001EB780 SetEditableVars__21ReversibleAnimTriggerFPc
void ReversibleAnimTrigger::SetEditableVars(char *pVars) {
    memcpy(m_unk1B0, pVars, 0x24);
    if (*(PMNode **)gEng != 0) {
        m_unk1D4 = (*(PMNode **)gEng)->FindAnimNode(m_unk1BC);
        if (m_unk1D4 == 0) {
            CdsAssert__FPciPc("ReversibleAnimTrigger.cpp", 0x14C, "m_pLinkedNode");
        }
        ((PMNodeVirtuals *)m_unk1D4)->SetFrameTime(0.0f);
        ((PMNodeVirtuals *)m_unk1D4)->Animate(0.0f, 0.0f, 0, 0, false);
        m_unk1D4->SetFrameRate(0.5f, true);
        ((PMNodeVirtuals *)m_unk1D4)->SetAllAnimFlags(0);
        m_unk1D4->EnableAnim(false, true);
    }
}

// FUNCTION: 0x001EBE40 __dt__21ReversibleAnimTriggerFv
ReversibleAnimTrigger::~ReversibleAnimTrigger() {
    m_unk0 = __vt__21ReversibleAnimTrigger;
    __dt__15EntityBaseClassFv(this, 0);
}

// FUNCTION: 0x001EBEA0 __ct__21ReversibleAnimTriggerFv
ReversibleAnimTrigger::ReversibleAnimTrigger() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 2, 0);
    m_unk0 = __vt__21ReversibleAnimTrigger;
    m_unk1D4 = 0;
    m_unk1E0 = 0;
    m_unk1D8 = 0.5f;
    m_unk1DC = 0.5f;
    m_unk1E6 = 0;
    m_unk1E7 = 0;
    m_unk1E4 = 1;
    m_unk1E5 = 1;
    m_unk1E8 = 0;
    m_unk103 = 0xFF;
}
