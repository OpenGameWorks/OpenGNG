// FLAGS: -str readonly
#include "types.h"
#include "FarPlaneTrigger.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern char *mPlayerAPI__13EntityManager;
extern float gEng[4][4];

// FUNCTION: 0x00202DE0 __dt__15FarPlaneTriggerFv
FarPlaneTrigger::~FarPlaneTrigger() {
}

// FUNCTION: 0x00202E40 GetClassName__15FarPlaneTriggerFv
const char *FarPlaneTrigger::GetClassName() {
    return "FarPlaneTrigger";
}

// FUNCTION: 0x00202E50 SetEditableVars__15FarPlaneTriggerFPc
void FarPlaneTrigger::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0x14);
}

// FUNCTION: 0x00202E60 Execute__15FarPlaneTriggerFv
void FarPlaneTrigger::Execute() {
    switch (m_unk20) {
    case -1:
        SetState(0);
        break;
    case 0:
        if (!m_unk1C4) {
            char *pPlayer = mPlayerAPI__13EntityManager;
            char *pAlt = *(char **)(pPlayer + 0x3C);
            char *pPlayerPos = (pAlt != 0) ? (pAlt + 0x80) : (pPlayer + 0x190);
            char *pSelf = m_unk3C;
            char *pSelfPos = (pSelf != 0) ? (pSelf + 0x80) : (char *)m_unk190;
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pSelfPos, (float (*)[4])pPlayerPos) <= m_unk1C0) {
                SetState(1);
            }
        }
        {
            char *pPlayer = mPlayerAPI__13EntityManager;
            char *pAlt = *(char **)(pPlayer + 0x3C);
            char *pPlayerPos = (pAlt != 0) ? (pAlt + 0x80) : (pPlayer + 0x190);
            char *pSelf = m_unk3C;
            char *pSelfPos = (pSelf != 0) ? (pSelf + 0x80) : (char *)m_unk190;
            if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pSelfPos, (float (*)[4])pPlayerPos) <= m_unk1C0)) {
                m_unk1C4 = 0;
            }
        }
        break;
    case 1:
        {
            float f = m_unk1B0;
            *(float *)((char *)gEng + 0xEC) = f;
            *(float *)((char *)gEng + 0x1CC) = f;
        }
        m_unk1C4 = 1;
        SetState(0);
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x00202F80 __ct__15FarPlaneTriggerFv
FarPlaneTrigger::FarPlaneTrigger() : EntityBaseClass((LoadClass)2, 0) {
    m_unk1C4 = 0;
}
