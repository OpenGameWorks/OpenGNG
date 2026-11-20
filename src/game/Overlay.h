#ifndef OVERLAY_H
#define OVERLAY_H

#include "types.h"

class OverlayManager {
public:
    OverlayManager(unsigned int nGroup);
    int LoadOverlay(const char *pName);

    int m_unk0;                 // 0x00 group address from _overlay_group_addresses
    char m_unk4[0x20];          // 0x04 name of the loaded overlay
    unsigned char m_unk24;      // 0x24 selects the PSXDATA or PROGRAM directory
};

#endif
