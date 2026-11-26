// FLAGS: -str readonly
#include "types.h"
#include "AmbientEntity.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001BF1D0 __dt__13AmbientEntityFv
AmbientEntity::~AmbientEntity() {
}

// FUNCTION: 0x001BF230 GetClassName__13AmbientEntityFv
const char *AmbientEntity::GetClassName() {
    return "AmbientEntity";
}

// FUNCTION: 0x001BF240 SetEditableVars__13AmbientEntityFPc
void AmbientEntity::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x4);
}

// FUNCTION: 0x001BF750 __ct__13AmbientEntityFv
AmbientEntity::AmbientEntity() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
