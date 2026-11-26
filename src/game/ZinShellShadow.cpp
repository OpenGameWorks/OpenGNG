// FLAGS: -str readonly
#include "types.h"
#include "ZinShellShadow.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern unsigned int ZinShellShadow_InitShadowSeq[0x3];

// FUNCTION: 0x001B0040 __dt__14ZinShellShadowFv
ZinShellShadow::~ZinShellShadow() {
}

// FUNCTION: 0x001B00A0 GetClassName__14ZinShellShadowFv
const char *ZinShellShadow::GetClassName() {
    return "Zin Shell Shadow";
}

// FUNCTION: 0x001B00C0 SetEditableVars__14ZinShellShadowFPc
void ZinShellShadow::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x1);
}

// FUNCTION: 0x001B00D0 Execute__14ZinShellShadowFv
void ZinShellShadow::Execute() {
    switch (m_unk20) {
    case -1:
        m_unk1B4 = 0.1f;
        SetState(0);
        break;
    case 0:
        if (*((unsigned char *)this + 0xE9)) {
            PlaySequence(ZinShellShadow_InitShadowSeq);
        }
        m_unk1B4 += 0.02f;
        if (m_unk1B4 <= 2.0f) {
            if (m_unk3C != 0) {
                ((PMNode *)m_unk3C)->ScaleSet(m_unk1B4, 1.0f, m_unk1B4, 1.0f);
            }
        } else {
            SetState(-2);
        }
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x001B01B0 __ct__14ZinShellShadowFv
ZinShellShadow::ZinShellShadow() : EntityBaseClass((LoadClass)2, 0) { EnableSleep(false, false); }
