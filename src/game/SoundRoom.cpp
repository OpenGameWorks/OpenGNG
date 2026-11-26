// FLAGS: -str readonly
#include "types.h"
#include "SoundRoom.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x0020D850 __dt__9SoundRoomFv
SoundRoom::~SoundRoom() {
}

// FUNCTION: 0x0020D8B0 GetClassName__9SoundRoomFv
const char *SoundRoom::GetClassName() {
    return "SoundRoom";
}

// FUNCTION: 0x0020D8C0 SetEditableVars__9SoundRoomFPc
void SoundRoom::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x40);
}

// FUNCTION: 0x0020D8D0 Execute__9SoundRoomFv
void SoundRoom::Execute() {
}

// FUNCTION: 0x0020D8E0 __ct__9SoundRoomFv
SoundRoom::SoundRoom() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
