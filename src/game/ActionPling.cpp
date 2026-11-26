// FLAGS: -str readonly
#include "types.h"
#include "ActionPling.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001B08F0 __dt__11ActionPlingFv
ActionPling::~ActionPling() {
}

// FUNCTION: 0x001B0950 GetClassName__11ActionPlingFv
const char *ActionPling::GetClassName() {
    return "ActionPling";
}

// FUNCTION: 0x001B0960 SetEditableVars__11ActionPlingFPc
void ActionPling::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x1);
}

// FUNCTION: 0x001B0A40 __ct__11ActionPlingFv
ActionPling::ActionPling() : EntityBaseClass((LoadClass)5, 0) {
    EnableSleep(false, false);
    m_unk1B1 = 0;
}
