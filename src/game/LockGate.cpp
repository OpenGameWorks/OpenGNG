// FLAGS: -str readonly
#include "types.h"
#include "LockGate.h"
#include "PMNode.h"
#include "Player.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" float Round180__Ff(float f);
extern "C" int ReadApparitionData__15EntityBaseClassFiUi(void *pThis, int nArg, unsigned int nFlags);
extern unsigned char GateTable[0x50];
extern unsigned char gEng[0x19B90];
extern char *mpEntMgr__15EntityBaseClass;

// GateTable rows are 0x10 bytes; word 0 is a sequence pointer, word 4 and 8 likewise, word 0xC a PlingType.
#define GATE_WORD(off) (*(unsigned int *)(GateTable + m_unk1B0 * 0x10 + (off)))

// FUNCTION: 0x001DBD50 __dt__8LockGateFv
LockGate::~LockGate() {
}

// FUNCTION: 0x001DBDB0 GetClassName__8LockGateFv
const char *LockGate::GetClassName() {
    return "Lock Gate";
}

// FUNCTION: 0x001DBDC0 SetEditableVars__8LockGateFPc
void LockGate::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0x8);
}

// FUNCTION: 0x001DBDD0 OnHitEvent__8LockGateFP15EntityBaseClassiUiUi
int LockGate::OnHitEvent(EntityBaseClass *pArg, int nHit, unsigned int nFlagsA, unsigned int nFlagsB) {
    EnableSleep(false, false);
    SetState(1);
    return 0;
}

// DRAFT: 0x001DBE10 Execute__8LockGateFv
// note: 267 words differ, size 0x46c vs 0x448; this kept in s2 not s1 (dispatch order matches); case bodies lay out differently; tried ReadApparitionData int decl (kept), nested pM restructure (worse), !m_unk160 spelling (no change).
void LockGate::Execute() {
    float sp50[4];
    switch (m_unk20) {
    case -1:
        CheckVariable(m_unk1B0, 5);
        m_unk1BC = 0;
        if (ReadApparitionData__15EntityBaseClassFiUi(this, 1, 0)) {
            SetState(2);
            return;
        }
        PlaySequence((unsigned int *)GATE_WORD(0));
        SetState(0);
    case 0: {
        char *pPlayer = *(char **)(mpEntMgr__15EntityBaseClass + 0x505C);
        char *pPlayerM3C = *(char **)(pPlayer + 0x3C);
        char *pA = (m_unk3C != 0) ? (m_unk3C + 0x80) : ((char *)this + 0x190);
        char *pB = (pPlayerM3C != 0) ? (pPlayerM3C + 0x80) : (pPlayer + 0x190);
        sceVu0SubVector(sp50, (float *)pB, (float *)pA);
        if (FastMath_Fabs__Ff(sp50[1]) < 1.5f && sceVu0InnerProduct(sp50, sp50) < 16.0f &&
            FastMath_Fabs__Ff(sceVu0InnerProduct((float *)(m_unk3C + 0x40), sp50)) < 2.0f) {
            float *pV0 = (pPlayerM3C != 0) ? (float *)(pPlayerM3C + 0x90) : (float *)(pPlayer + 0x1A0);
            float *pV1 = (m_unk3C != 0) ? (float *)(m_unk3C + 0x90) : (float *)((char *)this + 0x1A0);
            float fAng = FastMath_Fabs__Ff(Round180__Ff(pV1[1] - pV0[1]));
            if (sceVu0InnerProduct((float *)(m_unk3C + 0x60), sp50) < 0.0f && !(fAng <= 90.0f) && fAng < 270.0f) {
                ((Player *)pPlayer)->SetPling((Player::PlingType)GATE_WORD(0xC), this, 0);
                return;
            }
        } else {
            return;
        }
        break;
    }
    case 1:
        if (*((unsigned char *)this + 0xE9) != 0) {
            PlaySequence((unsigned int *)GATE_WORD(4));
            WriteApparitionData(1, -3, 0);
        } else if (m_unk1B8 == 0) {
            int nFrame = (int)((PMNode *)m_unk3C)->GetFrameTime();
            if (m_unk1BC == 0) {
                switch (m_unk1B0) {
                case 1:
                    if (nFrame >= 0x50) {
                        m_unk1BC = PlaySound(0x78);
                        m_unk1B8 = 1;
                    }
                    break;
                case 2:
                case 3:
                    if (nFrame >= 0x74) {
                        m_unk1BC = PlaySound(0x26A);
                        m_unk1B8 = 1;
                    }
                    break;
                case 4:
                    if (nFrame >= 0x74) {
                        m_unk1BC = PlaySound(0x26E);
                        m_unk1B8 = 1;
                    }
                    break;
                }
            }
            if (m_unk1B4 != 0) {
                TriggerBGAnim(m_unk1B4, -1, false, 0, 0);
            }
        }
        if (m_unk160 == 0) {
            int nState = 3;
            if (m_unk1B4 == 0) {
                StopSoundBySoundRef(m_unk1BC);
                nState = 2;
            }
            SetState(nState);
            return;
        }
        break;
    case 2:
        if (*((unsigned char *)this + 0xE9) != 0) {
            unsigned int *pSeq = (unsigned int *)GATE_WORD(8);
            if (pSeq != 0) {
                PlaySequence(pSeq);
                return;
            }
            SetState(-2);
            return;
        }
        break;
    case 3: {
        PMNode *pNode = (*(PMNode **)gEng)->FindAnimNode(m_unk1B4);
        if (pNode == 0 || (((char *)pNode)[0x3F] & 7) == 0) {
            SetState(-2);
        }
        break;
    }
    }
}

// FUNCTION: 0x001DC260 __ct__8LockGateFv
LockGate::LockGate() : EntityBaseClass((LoadClass)5, 0) {
    m_unk1B8 = 0;
}
