// FLAGS: -str readonly
#include "types.h"
#include "MovingFog.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001D68D0 GetClassName__9MovingFogFv
const char *MovingFog::GetClassName() {
    return "MovingFog";
}

// FUNCTION: 0x001D68E0 SetEditableVars__9MovingFogFPc
void MovingFog::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x44);
}

// FUNCTION: 0x001D6A90 __ct__9MovingFogFv
MovingFog::MovingFog() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
