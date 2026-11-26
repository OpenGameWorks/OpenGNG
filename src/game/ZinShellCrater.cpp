// FLAGS: -str readonly
#include "types.h"
#include "ZinShellCrater.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001C8910 __dt__14ZinShellCraterFv
ZinShellCrater::~ZinShellCrater() {
}

// FUNCTION: 0x001C8970 GetClassName__14ZinShellCraterFv
const char *ZinShellCrater::GetClassName() {
    return "ZinShellCrater";
}

// FUNCTION: 0x001C8980 SetEditableVars__14ZinShellCraterFPc
void ZinShellCrater::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x1);
}

// FUNCTION: 0x001C8AA0 __ct__14ZinShellCraterFv
ZinShellCrater::ZinShellCrater() : EntityBaseClass((LoadClass)5, 0) {}
