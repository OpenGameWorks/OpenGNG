// FLAGS: -str readonly
#include "types.h"
#include "SavePoint.h"
#include "TimerAPI.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern void *mpEntMgr__15EntityBaseClass;
extern TimerAPI mTimerAPI__13EntityManager;
extern "C" void SetHolyGround__13EntityManagerFPA4_ffb(void *pThis, float (*pPos)[4], float fRadius, bool bFlag);

// FUNCTION: 0x0020E5F0 __dt__9SavePointFv
SavePoint::~SavePoint() {
}

// FUNCTION: 0x0020E650 NeedsToBeWoken__9SavePointFv
int SavePoint::NeedsToBeWoken() {
    return m_unk1BC;
}

// FUNCTION: 0x0020E660 GetWokenVarPos__9SavePointFv
int SavePoint::GetWokenVarPos() {
    return 1;
}

// FUNCTION: 0x0020E670 GetClassName__9SavePointFv
const char *SavePoint::GetClassName() {
    return "SavePoint";
}

// FUNCTION: 0x0020E680 SetEditableVars__9SavePointFPc
void SavePoint::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B8, pSrc, 0x8);
}

// FUNCTION: 0x0020E690 OnTimerEvent__9SavePointFUi
void SavePoint::OnTimerEvent(unsigned int nTimer) {
    if (nTimer == m_unk1B0) {
        m_unk1B4 = 1;
    }
}

// FUNCTION: 0x0020E6B0 Execute__9SavePointFv
void SavePoint::Execute() {
    switch (m_unk20) {
    case -1:
        if (ReadApparitionData(3, 0)) {
            SetState(-2);
            return;
        }
        m_unk1B4 = 0;
        if (m_unk1B8 > 0) {
            m_unk1B0 = mTimerAPI__13EntityManager.CreateTimer(m_unk04, m_unk1B8, true);
            SetState(0);
            return;
        }
        SetState(1);
        return;
    case 0:
        if (m_unk1B4 != 0) {
            SetState(1);
            return;
        }
        break;
    case 1:
        SetHolyGround__13EntityManagerFPA4_ffb(mpEntMgr__15EntityBaseClass, &m_unk190, m_unk1A4, false);
        WriteApparitionData(3, 1, 0);
        SetState(-2);
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x0020E7C0 __ct__9SavePointFv
SavePoint::SavePoint() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
