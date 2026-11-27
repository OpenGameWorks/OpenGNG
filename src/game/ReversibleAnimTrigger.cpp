// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
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
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void RemoveCollision__15EntityBaseClassFP15EntityBaseClass(void *pThis, void *arg0);
extern "C" int PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nVar, int nValue);
extern "C" void StartCutScene__10MaximoMainFi(void *pThis, int nScene);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void EnableAnim__6PMNodeFbb(void *pThis, bool bA, bool bB);
extern "C" float GetFrameTime__6PMNodeFv(void *pThis);
extern "C" void SetFrameRate__6PMNodeFfb(void *pThis, float fRate, bool bFlag);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" void StopSoundBySoundRef__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" int CreateTimer__8TimerAPIFUiUib(void *pTimer, unsigned int nA, unsigned int nB, bool bFlag);
extern char mTimerAPI__13EntityManager[40];

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

// FUNCTION: 0x001EB520 GetClassName__21ReversibleAnimTriggerFv
const char *ReversibleAnimTrigger::GetClassName() {
    return "ReversibleAnimTrigger";
}

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

// DRAFT: 0x001EB620 OnHitEvent__21ReversibleAnimTriggerFP15EntityBaseClassiUiUi
// note: 62 words differ; dispatch order and branch sense match, but the shared return-1 block sits 8 instructions earlier and return 5/return 0 exits lay out differently. Tried: early return, case reorder (66), if/else chain (66).
int ReversibleAnimTrigger::OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    if (*(int *)((char *)arg0 + 0x10C) & 1) {
        if (m_unk1E4) {
            switch (m_unk1B4) {
            case 4:
                if ((arg2 & 0x1F) != 0xF && (arg2 & 0x1F) != 8) {
                    return 5;
                }
                break;
            case 3:
                if ((arg2 & ~0x100) != 0x4F && (arg2 & ~0x100) != 0x44 && (arg2 & ~0x100) != 0x42 && (arg2 & ~0x100) != 0x41) {
                    return 5;
                }
                if (*(int *)((char *)arg0->m_unk38 + 0x108) & 1) {
                    PlaySound__15EntityBaseClassFUi(this, 0x84);
                } else {
                    RemoveCollision__15EntityBaseClassFP15EntityBaseClass(arg0, this);
                    return 0;
                }
                break;
            }
            if (m_unk1C4 > 0) {
                StartCutCamera__6CameraFUib(gEng + 0x19760, m_unk1C4, false);
            }
            SetState__15EntityBaseClassFi(this, 1);
        }
    }
    return 1;
}

static unsigned int ReversibleAnimTriggerStoneSeq[14] = {0x1, 0x100010a, 0x8, 0x2, 0x2000239, 0x3, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x1, 0x3, 0x80, 0xff};
static unsigned int *AnimTable[6] = {ReversibleAnimTriggerStoneSeq, ReversibleAnimTriggerStoneSeq, ReversibleAnimTriggerStoneSeq, ReversibleAnimTriggerStoneSeq, ReversibleAnimTriggerStoneSeq, ReversibleAnimTriggerStoneSeq};
// DRAFT: 0x001EB860 Execute__21ReversibleAnimTriggerFv
// note: 366 words differ, size 0x608 vs 0x5d8; switch 2 delay slot (addiu a1,1 at 0x2C) and case bodies differ
void ReversibleAnimTrigger::Execute() {
    static float vHitBoxHalfSize[4] = {2.4f, 0.6f, 2.4f, 5.0f};
    switch (m_unk20) {
    case -1: {
        CheckVariable__15EntityBaseClassFii(this, m_unk1B4, 5);
        CheckVariable__15EntityBaseClassFii(this, m_unk1B8, 6);
        CheckVariable__15EntityBaseClassFii(this, m_unk1B0, 5);
        if (m_unk1CC < 0.0f) {
            CdsAssert("ReversibleAnimTrigger.cpp", 0x84, "mEVars.fEndFrame >= 0");
        }
        if (m_unk1D0 <= 0.0f) {
            CdsAssert("ReversibleAnimTrigger.cpp", 0x85, "mEVars.fRiseSpeed > 0");
        }
        if (m_unk1D4 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
            return;
        }
        PlaySequence__15EntityBaseClassFPUi(this, AnimTable[m_unk1B8]);
        PMNode *pNode = m_unk3C;
        switch (m_unk1B4) {
        case 0:
            m_unk10C |= 0x04000000;
            break;
        case 1:
            m_unkEA = 1;
            /* fallthrough */
        case 3:
            m_unk10C |= 0x02000000;
            *(u_long128 *)((char *)pNode + 0x120) = *(u_long128 *)vHitBoxHalfSize;
            break;
        }
        EnableAnim__6PMNodeFbb(pNode, 0, 1);
        if (m_unk1E6 != 0) {
            ((PMNodeVirtuals *)pNode)->SetFrameTime((float)*(int *)((char *)pNode + 0x108));
        }
        if (m_unk1E7 != 0) {
            SetState__15EntityBaseClassFi(this, 4);
            return;
        }
        SetState__15EntityBaseClassFi(this, 0);
        return;
    }
    case 0:
        if (m_unkE9 != 0) {
            EnableSleep__15EntityBaseClassFbb(this, 1, 0);
        }
        if ((signed char)(m_unk1D4->m_unk3F & 7) == 0) {
            m_unk1E4 = 1;
            if (m_unk1E8 != 0) {
                StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk1E8);
                return;
            }
        }
        return;
    case 1: {
        PMNode *pNode = m_unk3C;
        if (m_unkE9 != 0) {
            EnableSleep__15EntityBaseClassFbb(this, 0, 0);
            m_unk1E4 = 0;
            float fTime = GetFrameTime__6PMNodeFv(pNode);
            ((PMNodeVirtuals *)pNode)->SetAllAnimFlags(0);
            SetFrameRate__6PMNodeFfb(pNode, m_unk1D8, 1);
            ((PMNodeVirtuals *)pNode)->SetFrameTime(fTime);
            return;
        }
        if ((signed char)(pNode->m_unk3F & 7) == 0) {
            float fTime = GetFrameTime__6PMNodeFv(m_unk1D4);
            ((PMNodeVirtuals *)m_unk1D4)->SetAllAnimFlags(0);
            SetFrameRate__6PMNodeFfb(m_unk1D4, m_unk1DC, 1);
            ((PMNodeVirtuals *)m_unk1D4)->SetFrameTime(fTime);
            CheckForSound(m_unk1D4);
            if (m_unk1B0 == 0) {
                m_unk1D8 = -m_unk1D8;
                m_unk1DC = -m_unk1DC;
                m_unk1E6 = m_unk1E6 == 0;
            }
            SetState__15EntityBaseClassFi(this, 2);
            return;
        }
        break;
    }
    case 2:
        if ((signed char)(m_unk1D4->m_unk3F & 7) == 0) {
            if (m_unk1E8 != 0) {
                StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk1E8);
            }
            if (m_unk1C0 >= 0) {
                StartCutScene__10MaximoMainFi(gEng - 0x590, m_unk1C0);
            }
            switch (m_unk1B0) {
            case 0:
                m_unk1E4 = 1;
                SetState__15EntityBaseClassFi(this, 0);
                return;
            case 1:
                m_unk1E4 = 1;
                SetState__15EntityBaseClassFi(this, 3);
                return;
            case 2:
                m_unk1E4 = 0;
                SetState__15EntityBaseClassFi(this, 3);
                return;
            case 4: {
                m_unk1E4 = 1;
                ((PMNodeVirtuals *)m_unk1D4)->SetFrameTime(0.0f);
                CheckForSound(m_unk1D4);
                PMNode *pNode = m_unk3C;
                ((PMNodeVirtuals *)pNode)->SetAllAnimFlags(0);
                SetFrameRate__6PMNodeFfb(pNode, -0.5f * m_unk1D0, 1);
                ((PMNodeVirtuals *)pNode)->SetFrameTime((float)*(int *)((char *)m_unk3C + 0x108));
                SetState__15EntityBaseClassFi(this, 0);
                return;
            }
            case 3:
                m_unk1E7 = 1;
                SetState__15EntityBaseClassFi(this, 4);
                return;
            }
        }
        break;
    case 3:
        if (m_unkE9 != 0) {
            if (m_unk1C8 > 0) {
                m_unk1E5 = 0;
                m_unk1E0 = CreateTimer__8TimerAPIFUiUib(&mTimerAPI__13EntityManager, m_unk4, (unsigned int)m_unk1C8, 0);
            } else {
                m_unk1E5 = 1;
            }
        }
        if (m_unk1E5 != 0) {
            ((PMNodeVirtuals *)m_unk1D4)->SetAllAnimFlags(0);
            SetFrameRate__6PMNodeFfb(m_unk1D4, -0.5f * m_unk1D0, 1);
            ((PMNodeVirtuals *)m_unk1D4)->SetFrameTime(m_unk1CC);
            CheckForSound(m_unk1D4);
            PMNode *pNode = m_unk3C;
            ((PMNodeVirtuals *)pNode)->SetAllAnimFlags(0);
            SetFrameRate__6PMNodeFfb(pNode, -0.5f * m_unk1D0, 1);
            ((PMNodeVirtuals *)pNode)->SetFrameTime((float)*(int *)((char *)m_unk3C + 0x108));
            if (m_unk1B4 == 3) {
                PlaySound__15EntityBaseClassFUi(this, 0x72);
            }
            SetState__15EntityBaseClassFi(this, 0);
        }
        break;
    }
}

// FUNCTION: 0x001EB760 OnTimerEvent__21ReversibleAnimTriggerFUi
void ReversibleAnimTrigger::OnTimerEvent(unsigned int arg0) {
    if (arg0 == m_unk1E0) {
        m_unk1E5 = 1;
    }
}

// FUNCTION: 0x001EB780 SetEditableVars__21ReversibleAnimTriggerFPc
void ReversibleAnimTrigger::SetEditableVars(char *pVars) {
    memcpy(&m_unk1B0, pVars, 0x24);
    if (*(PMNode **)gEng != 0) {
        m_unk1D4 = (*(PMNode **)gEng)->FindAnimNode(m_unk1BC);
        if (m_unk1D4 == 0) {
            CdsAssert("ReversibleAnimTrigger.cpp", 0x14C, "m_pLinkedNode");
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
