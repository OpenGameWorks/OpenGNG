// FLAGS: -str readonly
#include "types.h"
#include "AnimTriggerOnDeath.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern unsigned char __vt__18AnimTriggerOnDeath[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char gEng[0x19B90];
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(void *pEntity);
extern "C" void *GetPtrToInstance__13EntityManagerFUi(void *pThis, unsigned int nID);
extern "C" void RecurseSetAnimFlagsByID__6PMNodeFUiP8AnimData(void *pThis, unsigned int nID, void *pAnim);

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

// FUNCTION: 0x00214890 __dt__18AnimTriggerOnDeathFv
extern "C" AnimTriggerOnDeath *__dt__18AnimTriggerOnDeathFv(AnimTriggerOnDeath *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->m_unk0 = __vt__18AnimTriggerOnDeath;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x002148F0 GetClassName__18AnimTriggerOnDeathFv
const char *AnimTriggerOnDeath::GetClassName() {
    return "AnimTriggerOnDeath";
}

// FUNCTION: 0x00214900 SetEditableVars__18AnimTriggerOnDeathFPc
void AnimTriggerOnDeath::SetEditableVars(char *pVars) {
    memcpy(&m_unk1B0, pVars, 0x18);
    if (CheckValidAnimID()) {
        if (*(PMNode **)gEng != 0) {
            PMNode *pNode = (*(PMNode **)gEng)->FindAnimNode(m_unk1B0);
            if (pNode != 0) {
                ((PMNodeVirtuals *)pNode)->SetFrameTime(0.0f);
                ((PMNodeVirtuals *)pNode)->Animate(0.0f, 0.0f, 0, 0, false);
                pNode->SetFrameRate(0.5f, true);
                ((PMNodeVirtuals *)pNode)->SetAllAnimFlags(0);
                pNode->EnableAnim(false, true);
            }
        }
    }
}

// FUNCTION: 0x002149D0 CheckValidAnimID__18AnimTriggerOnDeathFv
int AnimTriggerOnDeath::CheckValidAnimID() {
    switch (m_unk1B0) {
    case 1:
    case 1000:
    case -1:
        return 0;
    }
    return 1;
}

// FUNCTION: 0x00214A10 Execute__18AnimTriggerOnDeathFv
void AnimTriggerOnDeath::Execute() {
    static unsigned char mAnimData[16] = {0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x3F};

    switch (m_unk20) {
    case -1:
        EnableSleep__15EntityBaseClassFbb(this, false, false);
        SetState__15EntityBaseClassFi(this, 1);
        break;
    case 1: {
        bool bNoneValid = true;
        if (InstanceIsValid__15EntityBaseClassFUi(m_unk1B4) != 0) {
            bNoneValid = false;
        }
        if (InstanceIsValid__15EntityBaseClassFUi(m_unk1B8) != 0) {
            bNoneValid = false;
        }
        if (InstanceIsValid__15EntityBaseClassFUi(m_unk1BC) != 0) {
            bNoneValid = false;
        }
        if (InstanceIsValid__15EntityBaseClassFUi(m_unk1C0) != 0) {
            bNoneValid = false;
        }
        if (bNoneValid) {
            SetState__15EntityBaseClassFi(this, 3);
        }
        break;
    }
    case 3:
        if (m_unk1C4 != 0) {
            unsigned char *pInst = (unsigned char *)GetPtrToInstance__13EntityManagerFUi(gEng + 0x137E0, m_unk1C4);
            if (pInst != 0) {
                pInst[0x1A] = 1;
            }
        }
        if (CheckValidAnimID()) {
            RecurseSetAnimFlagsByID__6PMNodeFUiP8AnimData(*(void **)gEng, m_unk1B0, mAnimData);
        }
        SetState__15EntityBaseClassFi(this, -2);
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x00214B60 __ct__18AnimTriggerOnDeathFv
extern "C" AnimTriggerOnDeath *__ct__18AnimTriggerOnDeathFv(AnimTriggerOnDeath *pThis) {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 2, 1);
    pThis->m_unk0 = __vt__18AnimTriggerOnDeath;
    return pThis;
}
