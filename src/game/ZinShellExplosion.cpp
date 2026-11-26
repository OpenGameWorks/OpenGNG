// FLAGS: -str readonly
#include "types.h"
#include "ZinShellExplosion.h"

// TODO(header): foreign declarations
extern unsigned int ZinShellExplosion_ShellExplose[0x12];
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001AFEE0 __dt__17ZinShellExplosionFv
ZinShellExplosion::~ZinShellExplosion() {
}

// FUNCTION: 0x001AFF40 GetClassName__17ZinShellExplosionFv
const char *ZinShellExplosion::GetClassName() {
    return "Zin Shell Explosion";
}

// FUNCTION: 0x001AFF50 SetEditableVars__17ZinShellExplosionFPc
void ZinShellExplosion::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x1);
}

// FUNCTION: 0x001AFF60 Execute__17ZinShellExplosionFv
void ZinShellExplosion::Execute() {
    switch (m_unk20) {
    case -1:
        m_unk10C = 0x2000100;
        SetState(0);
        break;
    case 0:
        if (*((unsigned char *)this + 0xE9)) {
            PlaySequence(ZinShellExplosion_ShellExplose);
        }
        // The original tests the flag as (flag != 0) ^ 1: sltu then xori.
        if ((m_unk160 != 0) ^ 1) {
            SetState(-2);
        }
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x001AFFF0 __ct__17ZinShellExplosionFv
ZinShellExplosion::ZinShellExplosion() : EntityBaseClass((LoadClass)2, 0) { EnableSleep(false, false); }
