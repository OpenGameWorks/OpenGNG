// FLAGS: -str readonly
#include "types.h"
#include "SoundTriggerPlainBox.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001B0810 __dt__20SoundTriggerPlainBoxFv
SoundTriggerPlainBox::~SoundTriggerPlainBox() {
}

// FUNCTION: 0x001B0870 GetClassName__20SoundTriggerPlainBoxFv
const char *SoundTriggerPlainBox::GetClassName() {
    return "SoundTriggerPlainBox";
}

// FUNCTION: 0x001B0880 SetEditableVars__20SoundTriggerPlainBoxFPc
void SoundTriggerPlainBox::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x78);
}

// FUNCTION: 0x001B0890 Execute__20SoundTriggerPlainBoxFv
void SoundTriggerPlainBox::Execute() {
}

// FUNCTION: 0x001B08A0 __ct__20SoundTriggerPlainBoxFv
SoundTriggerPlainBox::SoundTriggerPlainBox() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
