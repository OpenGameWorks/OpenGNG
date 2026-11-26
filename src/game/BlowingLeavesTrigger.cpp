// FLAGS: -str readonly
#include "types.h"
#include "BlowingLeavesTrigger.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x00208AC0 __dt__20BlowingLeavesTriggerFv
BlowingLeavesTrigger::~BlowingLeavesTrigger() {
}

// FUNCTION: 0x00208B20 GetClassName__20BlowingLeavesTriggerFv
const char *BlowingLeavesTrigger::GetClassName() {
    return "BlowingLeavesTrigger";
}

// FUNCTION: 0x00208B30 SetEditableVars__20BlowingLeavesTriggerFPc
void BlowingLeavesTrigger::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x18);
}
