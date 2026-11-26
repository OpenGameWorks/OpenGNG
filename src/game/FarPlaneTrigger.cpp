// FLAGS: -str readonly
#include "types.h"
#include "FarPlaneTrigger.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x00202DE0 __dt__15FarPlaneTriggerFv
FarPlaneTrigger::~FarPlaneTrigger() {
}

// FUNCTION: 0x00202E40 GetClassName__15FarPlaneTriggerFv
const char *FarPlaneTrigger::GetClassName() {
    return "FarPlaneTrigger";
}

// FUNCTION: 0x00202E50 SetEditableVars__15FarPlaneTriggerFPc
void FarPlaneTrigger::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x14);
}
