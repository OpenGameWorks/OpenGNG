// FLAGS: -str readonly
#include "types.h"
#include "ArenaWaveSetup.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001C8840 __dt__14ArenaWaveSetupFv
ArenaWaveSetup::~ArenaWaveSetup() {
}

// FUNCTION: 0x001C88A0 GetClassName__14ArenaWaveSetupFv
const char *ArenaWaveSetup::GetClassName() {
    return "ArenaWaveSetup";
}

// FUNCTION: 0x001C88B0 SetEditableVars__14ArenaWaveSetupFPc
void ArenaWaveSetup::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x20);
}

// FUNCTION: 0x001C88C0 Execute__14ArenaWaveSetupFv
void ArenaWaveSetup::Execute() {
}

// FUNCTION: 0x001C88D0 __ct__14ArenaWaveSetupFv
ArenaWaveSetup::ArenaWaveSetup() : EntityBaseClass((LoadClass)5, 0) {}
