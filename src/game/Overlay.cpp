// FLAGS: -str readonly
#include "types.h"
#include "Overlay.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int mwLoadOverlay(char *pPath, int nGroup);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" int strcmp(const char *pA, const char *pB);
extern "C" char *strcpy(char *pDst, const char *pSrc);
extern "C" unsigned int strlen(const char *pStr);
extern int _overlay_group_addresses[32];

// FUNCTION: 0x0012BD50 LoadOverlay__14OverlayManagerFPCc
int OverlayManager::LoadOverlay(const char *pName) {
    char path[0x40];

    if (strcmp(pName, m_unk4) == 0) {
        return 1;
    }
    sprintf(path, "%s%sR.BIN", m_unk24 ? "PSXDATA\\OVERLAY\\" : "..\\PROGRAM\\", pName);
    if (strlen(path) >= 0x40U) {
        CdsAssert__FPciPc("Overlay.cpp", 0x3A, "strlen( correctFileName ) < 64");
    }
    if (mwLoadOverlay(path, m_unk0) != 0) {
        strcpy(m_unk4, pName);
        return 1;
    }
    return 0;
}

// DRAFT: 0x0012BE20 __ct__14OverlayManagerFUi
// note: table load uses R_MIPS reloc on _overlay_group_addresses; original has absolute lui/addiu 0x2C3F20 with no reloc (2 words differ). Tried byte-pointer, pointer+index, volatile base, and reordered stores; none reduced the count.
OverlayManager::OverlayManager(unsigned int nGroup) {
    m_unk0 = _overlay_group_addresses[nGroup];
    if (m_unk0 == 0) {
        CdsAssert__FPciPc("Overlay.cpp", 0x11, "pOverlayGroupAddr");
    }
    m_unk4[0] = 0;
    m_unk24 = 1;
}
