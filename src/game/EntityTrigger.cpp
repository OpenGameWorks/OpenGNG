#include "types.h"
#include "EntityTrigger.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
extern unsigned char __vt__13EntityTrigger[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" void *GetPtrToInstance__13EntityManagerFUi(void *pThis, unsigned int nID);
extern "C" void Destroy__13EntityManagerFUiUi(void *pThis, unsigned int nID, unsigned int nArg);
extern "C" unsigned char PlayingCutCamera__6CameraFv(void *pThis);
extern "C" void StartCutCamera__6CameraFUib(void *pThis, unsigned int nID, int bFlag);
extern char gEng[105360];
extern unsigned char gInterface[0x1B28];
extern char *mPlayerAPI__13EntityManager;

// FUNCTION: 0x001FB630 __dt__13EntityTriggerFv
extern "C" EntityTrigger *__dt__13EntityTriggerFv(EntityTrigger *pThis, short nFlag)
{
    if (pThis != 0) {
        pThis->m_unk0 = __vt__13EntityTrigger;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001FB690 GetClassName__13EntityTriggerFv
const char *EntityTrigger::GetClassName() {
    return "EntityTrigger";
}

// FUNCTION: 0x001FB6A0 SetEditableVars__13EntityTriggerFPc
void EntityTrigger::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x28);
}

// DRAFT: 0x001FB6B0 Execute__13EntityTriggerFv
// note: frame 0x60 vs 0x70 (no separate s5 pointer, destroy handle folded into s4); this/gEng registers swapped (s0/s1); gEng lui hoist differs. 85 words. Tried pHandle before test (107), gEng pointer at top (95), signed offset (85).
void EntityTrigger::Execute()
{
    int i;
    unsigned int off;
    char *pSlot;
    int *pHandle;
    void *pInst;
    char *pPlayer;
    char *pTarget;
    char *pAlt;

    switch (m_unk20) {
    case -1:
        if (m_unk1D8[0] == 0) {
            m_unk1D8[0] = m_unk1B4;
            m_unk1D8[1] = m_unk1B8;
            m_unk1D8[2] = m_unk1BC;
            m_unk1D8[3] = m_unk1C0;
        }
        if (m_unk1E8[0] == 0) {
            m_unk1E8[0] = m_unk1C4;
            m_unk1E8[1] = m_unk1C8;
            m_unk1E8[2] = m_unk1CC;
            m_unk1E8[3] = m_unk1D0;
        }
        pTarget = (char *)m_unk190;
        if (m_unk3C != 0) {
            pTarget = m_unk3C + 0x80;
        }
        pPlayer = mPlayerAPI__13EntityManager;
        pAlt = pPlayer + 0x190;
        if (*(char **)(pPlayer + 0x3C) != 0) {
            pAlt = *(char **)(pPlayer + 0x3C) + 0x80;
        }
        if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pAlt, (float (*)[4])pTarget) <= m_unk1B0) {
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
        break;
    case 0:
        {
            char *pMgr = gEng + 0x137E0;
            i = 0;
            off = 0;
            do {
                pSlot = (char *)this + off;
                if (*(int *)(pSlot + 0x1D8) != 0) {
                    pInst = GetPtrToInstance__13EntityManagerFUi(pMgr, *(unsigned int *)(pSlot + 0x1D8));
                    if (pInst != 0) {
                        ((char *)pInst)[0x1A] = 1;
                    }
                }
                if (*(int *)(pSlot + 0x1E8) != 0) {
                    pHandle = (int *)(pSlot + 0x1E8);
                    pInst = GetPtrToInstance__13EntityManagerFUi(pMgr, *(unsigned int *)(pSlot + 0x1E8));
                    if (pInst != 0) {
                        Destroy__13EntityManagerFUiUi(pMgr, ((unsigned int *)pInst)[1], *pHandle);
                    }
                }
                i += 1;
                off += 4;
            } while (i < 4);
        }
        if (m_unk1D4 != 0) {
            if (PlayingCutCamera__6CameraFv(gEng + 0x19760) == 0) {
                StartCutCamera__6CameraFUib(gEng + 0x19760, m_unk1D4, 0);
                *(short *)(gInterface + 0x1B24) = 30;
                *(int *)(gInterface + 0x18D0) &= ~0xE;
            }
        }
        SetState__15EntityBaseClassFi(this, -2);
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x001FB8B0 __ct__13EntityTriggerFv
extern "C" EntityTrigger *__ct__13EntityTriggerFv(EntityTrigger *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 4, 0);
    pThis->m_unk0 = __vt__13EntityTrigger;
    pThis->m_unk1D8[0] = 0;
    pThis->m_unk1D8[1] = 0;
    pThis->m_unk1D8[2] = 0;
    pThis->m_unk1D8[3] = 0;
    pThis->m_unk1E8[0] = 0;
    pThis->m_unk1E8[1] = 0;
    pThis->m_unk1E8[2] = 0;
    pThis->m_unk1E8[3] = 0;
    return pThis;
}
