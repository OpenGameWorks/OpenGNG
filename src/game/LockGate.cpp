// FLAGS: -str readonly
#include "types.h"
#include "LockGate.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001DBD50 __dt__8LockGateFv
LockGate::~LockGate() {
}

// FUNCTION: 0x001DBDB0 GetClassName__8LockGateFv
const char *LockGate::GetClassName() {
    return "Lock Gate";
}

// FUNCTION: 0x001DBDC0 SetEditableVars__8LockGateFPc
void LockGate::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x8);
}

// FUNCTION: 0x001DC260 __ct__8LockGateFv
LockGate::LockGate() : EntityBaseClass((LoadClass)5, 0) {
    m_unk1B8 = 0;
}
