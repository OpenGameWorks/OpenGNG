// FLAGS: -str readonly
#include "types.h"
#include "SavePoint.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x0020E5F0 __dt__9SavePointFv
SavePoint::~SavePoint() {
}

// FUNCTION: 0x0020E670 GetClassName__9SavePointFv
const char *SavePoint::GetClassName() {
    return "SavePoint";
}

// FUNCTION: 0x0020E680 SetEditableVars__9SavePointFPc
void SavePoint::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B8, pSrc, 0x8);
}

// FUNCTION: 0x0020E690 OnTimerEvent__9SavePointFUi
void SavePoint::OnTimerEvent(unsigned int nTimer) {
    if (nTimer == m_unk1B0) {
        m_unk1B4 = 1;
    }
}

// FUNCTION: 0x0020E7C0 __ct__9SavePointFv
SavePoint::SavePoint() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
