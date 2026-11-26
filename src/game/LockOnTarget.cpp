// FLAGS: -str readonly
#include "types.h"
#include "LockOnTarget.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001D3A30 __dt__12LockOnTargetFv
LockOnTarget::~LockOnTarget() {
}

// FUNCTION: 0x001D3A90 GetClassName__12LockOnTargetFv
const char *LockOnTarget::GetClassName() {
    return "LockOnTarget";
}
