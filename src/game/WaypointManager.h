#ifndef WAYPOINTMANAGER_H
#define WAYPOINTMANAGER_H

#include "types.h"
#include "PPakFile.h"

struct tagWaypointGroup {
    unsigned int m_unk0;      // group id
    unsigned int iNWaypoints;
    char _pad8[0x10];
    unsigned int m_unk18[1];  // waypoint words: top nibble flag, low 28 bits offset
};

class WaypointManager {
public:
    WaypointManager();
    ~WaypointManager();
    int LoadWaypoints(PPakFile *pPak, unsigned int uSizeWpBlock);
    int GetWaypoint(tagWaypointGroup *pGroup, unsigned int iWpNumber, unsigned char &bRef);
    tagWaypointGroup *GetWaypointGroupInfo(unsigned int iGroupId);

    unsigned char m_unk0;
    char _pad1[3];
    int m_unk4;
    char *m_unk8;
    char *m_unkC;
    unsigned int m_unk10;
    char _pad14[0xC];
    unsigned char m_unk20;    // count byte of the loaded block
    char _pad21[3];
    int m_unk24;              // group data offset from the block start
    int m_unk28;              // group data size
    char m_unk2C[0x5000 - 0x2C];
};

#endif
