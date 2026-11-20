#include "types.h"
#include "AnimSegmentTrigger.h"

// TODO(header): foreign declarations
extern unsigned char __vt__18AnimSegmentTrigger[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nArg, char cArg, unsigned int nFlags);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" int PointInBoundBox__7MathAPIFPA4_f6tagBOX(float (*pM)[4], void *pBox);
extern char *mPlayerAPI__13EntityManager;

// FUNCTION: 0x0020F030 __dt__18AnimSegmentTriggerFv
extern "C" AnimSegmentTrigger *__dt__18AnimSegmentTriggerFv(AnimSegmentTrigger *pThis, short nFlag)
{
    if (pThis != 0) {
        pThis->m_unk0 = __vt__18AnimSegmentTrigger;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x0020F0B0 PlayerInsideTriggerVolume__18AnimSegmentTriggerFv
// note: 20 words differ. The global base register is reversed (orig lw v1,-0x7930(gp) then lw v0,0x3C(v1)), the true-path beqz is 2 words long, and the ?: returns emit movz where the original branches. Tried: if/return on second return (21), swapped local decl order (20), both ?: (20, kept).
int AnimSegmentTrigger::PlayerInsideTriggerVolume()
{
    char *pAlt;
    char *pPlayer;
    char *pTarget;
    char *pOrigin;

    if (m_unk1E4 != 0) {
        pTarget = (m_unk3C != 0) ? (m_unk3C + 0x80) : (char *)m_unk190;
        pPlayer = mPlayerAPI__13EntityManager;
        pAlt = *(char **)(pPlayer + 0x3C);
        pOrigin = (pAlt != 0) ? (pAlt + 0x80) : (pPlayer + 0x190);
        return (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pOrigin, (float (*)[4])pTarget) < m_unk1B0) ? 1 : 0;
    }
    pPlayer = mPlayerAPI__13EntityManager;
    pAlt = *(char **)(pPlayer + 0x3C);
    pOrigin = (pAlt != 0) ? (pAlt + 0x80) : (pPlayer + 0x190);
    return (PointInBoundBox__7MathAPIFPA4_f6tagBOX((float (*)[4])pOrigin, m_unk1B4) != 0) ? 1 : 0;
}

// DRAFT: 0x0020F160 OnHitEvent__18AnimSegmentTriggerFP15EntityBaseClassiUiUi
// note: 41 words differ, frame layout and pOther register; tried single-exit returns (43), no nResult local (43), nMasked local (41), inline mask (41, kept).
int AnimSegmentTrigger::OnHitEvent(EntityBaseClass *pOther, int nArg1, unsigned int nFlags, unsigned int nArg3)
{
    int nResult;

    nResult = 0;
    if (*(int *)((char *)pOther + 0x10C) & 1) {
        if (m_unk1E8 == 1) {
            if ((nFlags & ~0x100) == 0x42 || (nFlags & ~0x100) == 0x41) {
                PlaySound__15EntityBaseClassFUi(this, 0x84);
                m_unk22A = 1;
                nResult = 1;
                if (m_unk210 != 0) {
                    m_unk10C &= 0xFDFFFFFF;
                    WriteApparitionData__15EntityBaseClassFicUi(this, 2, 1, 0);
                }
            }
        }
    }
    return nResult;
}

// FUNCTION: 0x0020F780 __ct__18AnimSegmentTriggerFv
extern "C" AnimSegmentTrigger *__ct__18AnimSegmentTriggerFv(AnimSegmentTrigger *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 2, 0);
    pThis->m_unk0 = __vt__18AnimSegmentTrigger;
    return pThis;
}
