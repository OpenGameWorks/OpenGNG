// FLAGS: -str readonly
#include "types.h"
#include "BlowingLeavesTrigger.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" int IsValid__16PParticleManagerFP15PParticleSystem(void *pMgr, void *pSystem);
extern char gGfxEng[1504384];
extern char *mPlayerAPI__13EntityManager;

// FUNCTION: 0x00208AC0 __dt__20BlowingLeavesTriggerFv
BlowingLeavesTrigger::~BlowingLeavesTrigger() {
}

// FUNCTION: 0x00208B20 GetClassName__20BlowingLeavesTriggerFv
const char *BlowingLeavesTrigger::GetClassName() {
    return "BlowingLeavesTrigger";
}

// FUNCTION: 0x00208B30 SetEditableVars__20BlowingLeavesTriggerFPc
void BlowingLeavesTrigger::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0x18);
}

// DRAFT: 0x00208B40 Execute__20BlowingLeavesTriggerFv
// note: 114 words differ; frame 0x40 with this copied to s1 and a second saved register (original frame 0x30, this in s0 only, v at 0x20). Switch -1,0,1,-2 has the original test order with break exits (120 -> 114); the saved-register allocation is the remaining gap.
void BlowingLeavesTrigger::Execute() {
    float v[4];
    v[0] = m_unk1B8[0];
    v[1] = m_unk1B8[1];
    v[2] = m_unk1B8[2];
    v[3] = 1.0f;
    switch (m_unk20) {
    case -1:
        SetState(0);
        break;
    case 0: {
        char *pPlayer;
        char *pAlt;
        char *pPos;
        if (m_unk1C8 == 0) {
            pPlayer = mPlayerAPI__13EntityManager;
            pAlt = *(char **)(pPlayer + 0x3C);
            pPos = pAlt ? (pAlt + 0x80) : (pPlayer + 0x190);
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])v, (float (*)[4])pPos) <= m_unk1C4) {
                SetState(1);
            }
        }
        pPlayer = mPlayerAPI__13EntityManager;
        pAlt = *(char **)(pPlayer + 0x3C);
        pPos = pAlt ? (pAlt + 0x80) : (pPlayer + 0x190);
        if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])v, (float (*)[4])pPos) <= m_unk1C4) {
            return;
        }
        m_unk1C8 = 0;
        break;
    }
    case 1: {
        char *pSys = 0;
        if (IsValid__16PParticleManagerFP15PParticleSystem(gGfxEng + 0x154F00, *(char **)(gGfxEng + 0x156FFC))) {
            pSys = *(char **)(gGfxEng + 0x156FFC);
        }
        if (pSys != 0) {
            if (m_unk1B0 != 0) {
                if (*(float *)(pSys + 0xCC) < 1.0f) {
                    *(float *)(pSys + 0x9B0) = 1.0f / m_unk1B4;
                } else {
                    *(float *)(pSys + 0x9B0) = 0.0f;
                }
            } else {
                if (*(float *)(pSys + 0xCC) <= 0.0f) {
                    *(float *)(pSys + 0x9B0) = 0.0f;
                } else {
                    *(float *)(pSys + 0x9B0) = -1.0f / m_unk1B4;
                }
            }
            m_unk1C8 = 1;
            SetState(0);
        }
        break;
    }
    case -2:
        break;
    }
}

// FUNCTION: 0x00208D20 __ct__20BlowingLeavesTriggerFv
BlowingLeavesTrigger::BlowingLeavesTrigger() : EntityBaseClass((LoadClass)2, 0) {
    m_unk1C8 = 0;
}
