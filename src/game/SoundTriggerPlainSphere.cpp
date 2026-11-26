// FLAGS: -str readonly
#include "types.h"
#include "SoundTriggerPlainSphere.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x0020D930 __dt__23SoundTriggerPlainSphereFv
SoundTriggerPlainSphere::~SoundTriggerPlainSphere() {
}

// FUNCTION: 0x0020D990 GetClassName__23SoundTriggerPlainSphereFv
const char *SoundTriggerPlainSphere::GetClassName() {
    return "SoundTriggerPlainSphere";
}

// FUNCTION: 0x0020D9A0 SetEditableVars__23SoundTriggerPlainSphereFPc
void SoundTriggerPlainSphere::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x38);
}

// FUNCTION: 0x0020D9B0 Execute__23SoundTriggerPlainSphereFv
void SoundTriggerPlainSphere::Execute() {
}

// FUNCTION: 0x0020D9C0 __ct__23SoundTriggerPlainSphereFv
SoundTriggerPlainSphere::SoundTriggerPlainSphere() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
