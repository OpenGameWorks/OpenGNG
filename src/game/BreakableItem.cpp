// FLAGS: -str readonly
#include "types.h"
#include "BreakableItem.h"

#include "EffectAPI.h"
#include "PMNode.h"
#include "pad.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" int printf(const char *pFmt, ...);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" void GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(EntityBaseClass *pOwner, float (*pOut)[4]);
extern "C" void sceVu0SubVector(float *pOut, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void ShakeScreen__9CameraAPIFfffUi(void *pCam, float fA, float fB, float fC, unsigned int nD);
extern char *mPlayerAPI__13EntityManager;
extern char *mpEntMgr__15EntityBaseClass;
extern int mCameraAPI__13EntityManager;
extern Pad gPad;

struct BreakableItemEntry {
    unsigned int *m_unk0;
    unsigned int *m_unk4;
    unsigned int *m_unk8;
    unsigned int *m_unkC;
    unsigned char m_unk10;
    float m_unk14;
    char _pad18[0x4];
    unsigned int m_unk1C;
    unsigned char m_unk20;
    char _pad21[0x3];
};

extern BreakableItemEntry BreakableItemTable[8];
extern unsigned int Crystalwall_SwordBreak1Seq[11];
extern EffectAPI mEffectAPI__13EntityManager;

// FUNCTION: 0x001D74D0 __dt__13BreakableItemFv
BreakableItem::~BreakableItem() {
}

// FUNCTION: 0x001D7530 GetClassName__13BreakableItemFv
const char *BreakableItem::GetClassName() {
    return "BreakableItem";
}

// FUNCTION: 0x001D7540 SetEditableVars__13BreakableItemFPc
void BreakableItem::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0xC);
    CheckVariable(m_unk1B0, 8);
}

// FUNCTION: 0x001D7580 OnHitEvent__13BreakableItemFP15EntityBaseClassiUiUi
int BreakableItem::OnHitEvent(EntityBaseClass *pArg, int nHit, unsigned int nFlagsA, unsigned int nFlagsB) {
    BreakableItemEntry *pEntry;

    if (*((unsigned char *)pArg + 0x10C) == 1) {
        if (nHit != 0) {
            switch (m_unk1B0) {
            case 0:
                mEffectAPI__13EntityManager.CreateOneshot(0x01000143, 0x02000296, 0, 0, this, 1.0f, false, 0, false);
                goto block_11;
            case 5:
                if (!(nFlagsA & 0x40)) {
                    PlaySequence(Crystalwall_SwordBreak1Seq);
                    PlaySound(0x18F);
                    return 1;
                }
                goto block_11;
            case 1:
                if (m_unk1C5 == 0) {
                    m_unk1C5 = 1;
                    ((PMNode *)m_unk3C)->EnableAnim(true, true);
                    PlaySound(0x15A);
                    return 1;
                }
                goto block_11;
            default:
            block_11:
                m_unk1C0 += 1;
                m_unk1BC -= nHit;
                pEntry = &BreakableItemTable[m_unk1B0];
                if (pEntry->m_unk1C != 0) {
                    PlaySound(pEntry->m_unk1C);
                }
                if ((m_unk1C0 >= 3U) || (m_unk1BC <= 0)) {
                    SetState(2);
                    return 1;
                } else {
                    switch (m_unk1C0) {
                    case 1:
                        PlaySequence(pEntry->m_unk4);
                        break;
                    case 2:
                        PlaySequence(pEntry->m_unk8);
                        break;
                    default:
                        SetState(2);
                        return 1;
                    }
                }
                break;
            }
        }
    }
    return 1;
}

// DRAFT: 0x001D7750 Execute__13BreakableItemFv
// note: DIFF 290 words; case -2 added for the 6-slot jump table, the PMNode local for pNode left the count unchanged; frame 0x50 vs 0x60 (original also saves s2), v0=4 hoisted into the m_unk0 test delay slot in the original, default branch 2 insns short
void BreakableItem::Execute() {
    BreakableItemEntry *pEntry;
    unsigned int *pSeq;
    float fVec[4];
    float fScale;
    char *pNode;
    char *pPos;
    char *pMgr;
    char *pEnt;
    char *pEntNode;
    char *pEntPos;
    int nType;
    int nState;
    static float BURN_DISTANCE;
    static signed char init;

    nType = m_unk1B0;
    pEntry = &BreakableItemTable[nType];

    switch (m_unk20) {
    case -1:
        if (pEntry->m_unk0 == 0) {
            printf("BreakableItem %d was removed\n", nType);
            SetState(-2);
            return;
        }
        if (nType != 4) {
            PlaySequence(pEntry->m_unk0);
        }
        if (m_unk1B0 == 4 && m_unk1C0 == 0) {
            m_unk1BC = 0x1E;
        }
        if (m_unk1B0 == 5 && m_unk1C0 == 0) {
            m_unk1C0 = 2;
        }
        m_unk10C &= 0xF8FFFFFF;
        m_unk10C |= 0x02000000;
        switch (m_unk1C0) {
        case 0:
            nState = 0;
            if (m_unk1B0 == 1) {
                nState = 3;
            }
            SetState(nState);
            return;
        case 1:
            pSeq = pEntry->m_unk4;
            break;
        case 2:
            pSeq = pEntry->m_unk8;
            break;
        default:
            SetState(2);
            return;
        }
        PlaySequence(pSeq);
        if (pEntry->m_unk20 != 0) {
            ((PMNode *)m_unk3C)->DisableAllHitBox();
        }
        pNode = m_unk3C;
        ((PMNode *)pNode)->SetFrameTime((float)*(int *)(pNode + 0x108));
        if (pNode != 0) {
            *(float *)(pNode + 0x12C) = pEntry->m_unk14;
        }
        SetState(1);
        return;
    case 0:
        if (pEntry->m_unk10 != 0) {
            if (ReadApparitionData(2, 0)) {
                PlaySequence(pEntry->m_unk0);
                ((PMNode *)m_unk3C)->SetFrameTime(1000.0f);
                SetState(1);
                return;
            }
            pMgr = mPlayerAPI__13EntityManager;
            pEntNode = *(char **)(pMgr + 0x3C);
            pPos = (pEntNode != 0) ? pEntNode + 0x80 : pMgr + 0x190;
            pEnt = m_unk3C;
            if (pEnt != 0) {
                pEnt = pEnt + 0x80;
            } else {
                pEnt = (char *)this + 0x190;
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pEnt, (float (*)[4])pPos) <= m_unk1B4) {
                PlaySequence(pEntry->m_unk0);
                WriteApparitionData(2, 1, 0);
                gPad.SetVibrate((Pad::VibType)1, 10);
                ShakeScreen__9CameraAPIFfffUi(&mCameraAPI__13EntityManager, 0.0f, 1.0f, 3.0f, 0);
                SetState(1);
                return;
            }
        } else {
            if (*((unsigned char *)this + 0xE9) != 0) {
                PlaySequence(pEntry->m_unk0);
                SetState(1);
                return;
            }
        }
        return;
    case 1:
        if (m_unk1B8 != 0) {
            UpdateShadowVolume();
            return;
        }
        break;
    case 2:
        if (*((unsigned char *)this + 0xE9) != 0) {
            m_unk163 = 6;
            EnableSleep(false, false);
            PlaySequence(pEntry->m_unkC);
            m_unk10C &= 0xF8FFFFFF;
            RemoveFromBGAnimList();
            WriteApparitionData(1, -3, 0);
            if (m_unk1B0 == 4) {
                GetForwardVector__7MathAPIFP15EntityBaseClassRA4_f(this, (float (*)[4])fVec);
                fScale = 0.1f;
                fVec[0] *= fScale;
                fVec[2] *= fScale;
                SpawnPickups(0, 1, (float (*)[4])fVec, false);
            } else if (m_unk1B0 == 5) {
                PlaySound(0x73);
            }
        }
        if (m_unk160 == 0) {
            SetState(-2);
            return;
        }
        break;
    case 3:
        UpdateShadowVolume();
        if (init == 0) {
            BURN_DISTANCE = 400.0f;
            init = 1;
        }
        if (m_unk1C0 == 0) {
            if (*((unsigned char *)this + 0xE9) != 0 && m_unk1C5 != 0) {
                ((PMNode *)m_unk3C)->SetFrameTime(100.0f);
            }
            if (m_unk1C5 == 0) {
                pNode = m_unk3C;
                if (pNode != 0) {
                    pPos = pNode + 0x80;
                } else {
                    pPos = (char *)this + 0x190;
                }
                pMgr = mpEntMgr__15EntityBaseClass;
                pEnt = *(char **)(pMgr + 0x505C);
                pEntNode = *(char **)(pEnt + 0x3C);
                if (pEntNode != 0) {
                    pEntPos = pEntNode + 0x80;
                } else {
                    pEntPos = pEnt + 0x190;
                }
                sceVu0SubVector(fVec, (float *)pEntPos, (float *)pPos);
                if (sceVu0InnerProduct(fVec, fVec) < BURN_DISTANCE) {
                    m_unk1C5 = 1;
                    ((PMNode *)m_unk3C)->EnableAnim(true, true);
                    PlaySound(0x15A);
                }
            }
        }
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x001D7C40 __ct__13BreakableItemFv
BreakableItem::BreakableItem() : EntityBaseClass((LoadClass)2, 2) {
    m_unk1BC = 0x78;
    m_unk1C0 = 0;
    m_unk1C4 = 0;
    m_unk1C5 = 0;
}
