// FLAGS: -str readonly
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
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int printf(const char *fmt, ...);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" int ReadApparitionData__15EntityBaseClassFiUi(void *pThis, int nArg, unsigned int nFlags);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, int bA, int bB);
extern "C" void DestroyFxTriggers__6PMNodeFbbb(void *pThis, int bA, int bB, int bC);
extern "C" void *FindAnimNode__6PMNodeFUi(void *pThis, unsigned int nID);
extern "C" void RecurseResetAnimByID__6PMNodeFUi(void *pThis, unsigned int nID);
extern "C" void RecurseSetAnimFlagsByID__6PMNodeFUiP8AnimData(void *pThis, unsigned int nID, void *pAnim);
extern "C" int BGAnimIsReset__13EntityManagerFi(void *pThis, int nID);
extern "C" void BGAnimAdd__13EntityManagerFi(void *pThis, int nID);
extern "C" int IsPlayerOnAnimNode__6PlayerFUi(void *pThis, unsigned int nID);
extern "C" void StartCutCamera__6CameraFUib(void *pThis, unsigned int nID, int bFlag);
extern unsigned char gEng[0x19B90];
extern unsigned char gInterface[2656];
extern unsigned int AnimSegmentTriggerInitSeqTable[];
extern unsigned int AnimSegmentTriggeredSeqTable[];
extern unsigned int AnimSegmentTriggerAnimSeqTable[];

// Assert form of PPakFile.cpp: the ternary keeps the runtime literal-address test.
#define CDS_ASSERT(line, cond, str) ((cond) ? (void)0 : CdsAssert__FPciPc("AnimSegmentTrigger.cpp", line, str))

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

// DRAFT: 0x0020F210 Execute__18AnimSegmentTriggerFv
// note: 345 words differ, size 0x5ac vs 0x570; delay slots filled with nop where the original puts lui a0 (0x44, 0x68, 0x90, 0x98), switch and case 2/3 layout shifted. Tried: case -2 entry (345), signed char flag byte (345, kept unsigned).
void AnimSegmentTrigger::Execute()
{
    static float vHitBoxHalfSize[4] = { 2.4f, 0.6f, 2.4f, 5.0f };
    void *pRoot;
    void *pNode;

    pRoot = *(void **)gEng;
    if (pRoot == 0) {
        CdsAssert__FPciPc("AnimSegmentTrigger.cpp", 0x35, "pRoot");
    }
    switch (m_unk20) {
    case -2:
        break;
    case -1:
        if (m_unk1F0 < 0) {
            printf("AnimSegmentTrigger shut down as anim ID not set up\n");
            SetState__15EntityBaseClassFi(this, -2);
            return;
        }
        if (m_unk1EC != 0) {
            CDS_ASSERT(0x45, m_unk1EC >= 0, "mEVars.m_iMeshType >= 0");
            CDS_ASSERT(0x46, m_unk1EC <= 1, "mEVars.m_iMeshType <= 1");
        }
        m_unk10C &= 0xFDFFFFFF;
        SetState__15EntityBaseClassFi(this, 0);
        return;
    case 0:
        if (m_unk1EC != 0) {
            if (ReadApparitionData__15EntityBaseClassFiUi(this, 2, 0) == 0) {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)AnimSegmentTriggerInitSeqTable[m_unk1EC - 1]);
            } else {
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)AnimSegmentTriggerInitSeqTable[m_unk1EC - 1]);
                PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)AnimSegmentTriggeredSeqTable[m_unk1EC - 1]);
                DestroyFxTriggers__6PMNodeFbbb(m_unk3C, 1, 1, 1);
            }
        }
        SetState__15EntityBaseClassFi(this, 1);
        return;
    case 1:
        if (m_unkE9 != 0) {
            if (ReadApparitionData__15EntityBaseClassFiUi(this, 2, 0) == 0) {
                if (m_unk1E8 != 0) {
                    if (m_unk1E8 == 1) {
                        m_unk10C |= 0x02000000;
                        *(u_long128 *)(m_unk3C + 0x120) = *(u_long128 *)vHitBoxHalfSize;
                    } else if (m_unk1E8 != 0) {
                        CdsAssert__FPciPc("AnimSegmentTrigger.cpp", 0x7A, "!mEVars.m_iTriggerType");
                    }
                }
                if (BGAnimIsReset__13EntityManagerFi(gEng + 0x137E0, m_unk1F0) == 0) {
                    RecurseResetAnimByID__6PMNodeFUi(pRoot, m_unk1F0);
                    BGAnimAdd__13EntityManagerFi(gEng + 0x137E0, m_unk1F0);
                }
                m_unk22A = 0;
            }
            m_unk228 = 0;
            m_unk229 = 0;
        }
        if (PlayerInsideTriggerVolume() != 0) {
            EnableSleep__15EntityBaseClassFbb(this, 0, 0);
            if (m_unk1E8 != 0) {
                switch (m_unk1E8) {
                case 0:
                    if (IsPlayerOnAnimNode__6PlayerFUi(*(void **)(gEng + 0x1883C), m_unk1F0) != 0) {
                        goto block_39;
                    }
                    goto block_40;
                case 1:
                    if (m_unk22A != 0) {
                        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)AnimSegmentTriggerAnimSeqTable[m_unk1EC - 1]);
                        m_unk22A = 0;
                        goto block_39;
                    }
                    goto block_40;
                default:
                    printf("AnimSegmentTrigger shut down as trigger type not set up\n");
                    SetState__15EntityBaseClassFi(this, -2);
                    return;
                }
            } else {
block_39:
                m_unk229 = 1;
block_40:
                if (m_unk229 != 0) {
                    if (m_unk208 != 0) {
                        StartCutCamera__6CameraFUib(gEng + 0x19760, m_unk208, m_unk20C != 0);
                        *(int *)(gInterface + 0x414) = 0x1E;
                        *(int *)(gInterface + 0x1C0) &= ~0xE;
                    }
                    if (m_unk214 != 0) {
                        *(int *)(gEng + 0x19A18) = 1;
                    }
                    SetState__15EntityBaseClassFi(this, 2);
                    return;
                }
            }
        } else {
default:
            return;
        }
        break;
    case 2:
        if (m_unkE9 != 0) {
            m_unk228 = 1;
            m_unk218 = m_unk1F4;
            m_unk21A = m_unk1F8;
            m_unk21C = m_unk1F4;
            m_unk21E = m_unk1F8;
            m_unk220 = 1;
            m_unk222 = 0;
            m_unk224 = m_unk204;
            RecurseSetAnimFlagsByID__6PMNodeFUiP8AnimData(pRoot, m_unk1F0, &m_unk218);
        }
        if (m_unk228 != 0) {
            pNode = FindAnimNode__6PMNodeFUi(pRoot, m_unk1F0);
            if (pNode != 0 && (((unsigned char *)pNode)[0x3F] & 7) == 0 && PlayerInsideTriggerVolume() == 0 && IsPlayerOnAnimNode__6PlayerFUi(*(void **)(gEng + 0x1883C), m_unk1F0) == 0) {
                m_unk228 = 0;
                SetState__15EntityBaseClassFi(this, 3);
                return;
            }
        }
        break;
    case 3:
        if (m_unkE9 != 0) {
            if (m_unk210 != 0) {
                WriteApparitionData__15EntityBaseClassFicUi(this, 2, 1, 0);
            }
            m_unk228 = 0;
            m_unk218 = m_unk1FC;
            m_unk21A = m_unk200;
            m_unk21C = m_unk1FC;
            m_unk21E = m_unk200;
            m_unk220 = 1;
            m_unk222 = 0;
            m_unk224 = m_unk204;
            if (m_unk218 == -1) {
                EnableSleep__15EntityBaseClassFbb(this, 1, 0);
                SetState__15EntityBaseClassFi(this, 1);
                return;
            }
            RecurseSetAnimFlagsByID__6PMNodeFUiP8AnimData(pRoot, m_unk1F0, &m_unk218);
            goto block_60;
        }
block_60:
        pNode = FindAnimNode__6PMNodeFUi(pRoot, m_unk1F0);
        if (pNode != 0 && (((unsigned char *)pNode)[0x3F] & 7) == 0) {
            if (m_unk214 != 0) {
                *(int *)(gEng + 0x19A18) = 0;
            }
            EnableSleep__15EntityBaseClassFbb(this, 1, 0);
            SetState__15EntityBaseClassFi(this, 1);
        }
        break;
    }
}

// FUNCTION: 0x0020F780 __ct__18AnimSegmentTriggerFv
extern "C" AnimSegmentTrigger *__ct__18AnimSegmentTriggerFv(AnimSegmentTrigger *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 2, 0);
    pThis->m_unk0 = __vt__18AnimSegmentTrigger;
    return pThis;
}
