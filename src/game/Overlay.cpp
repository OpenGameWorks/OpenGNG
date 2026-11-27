// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Overlay.h"

// TODO(header): foreign declarations
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
        CdsAssert("Overlay.cpp", 0x3A, "strlen( correctFileName ) < 64");
    }
    if (mwLoadOverlay(path, m_unk0) != 0) {
        strcpy(m_unk4, pName);
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0012BE20 __ct__14OverlayManagerFUi
OverlayManager::OverlayManager(unsigned int nGroup) {
    m_unk0 = _overlay_group_addresses[nGroup];
    if (m_unk0 == 0) {
        CdsAssert("Overlay.cpp", 0x11, "pOverlayGroupAddr");
    }
    m_unk4[0] = 0;
    m_unk24 = 1;
}
