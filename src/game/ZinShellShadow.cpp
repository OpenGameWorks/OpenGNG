// FLAGS: -str readonly
#include "types.h"
#include "ZinShellShadow.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001B0040 __dt__14ZinShellShadowFv
ZinShellShadow::~ZinShellShadow() {
}

// FUNCTION: 0x001B00A0 GetClassName__14ZinShellShadowFv
const char *ZinShellShadow::GetClassName() {
    return "Zin Shell Shadow";
}

// FUNCTION: 0x001B00C0 SetEditableVars__14ZinShellShadowFPc
void ZinShellShadow::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x1);
}

// FUNCTION: 0x001B01B0 __ct__14ZinShellShadowFv
ZinShellShadow::ZinShellShadow() : EntityBaseClass((LoadClass)2, 0) { EnableSleep(false, false); }
