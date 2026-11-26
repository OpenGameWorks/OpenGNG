#ifndef CEIFFILE_H
#define CEIFFILE_H

#include "types.h"
#include "PCDFile.h"
#include "WaypointManager.h"

class CEifInstanceGroup;

// CEifFile members are named by their offset from the object start. The
// instance group pointer array is at 0x000, the 0x104-byte header block at
// 0x008, and the 0x218-byte block at 0x114.
class CEifFile {
public:
    CEifFile();
    ~CEifFile();
    void Cleanup();
    int Close(bool bFlag);
    CEifInstanceGroup *GetInstanceGroup(int nIndex);
    int Load(const char *pszFilename);
    int GetNumInstanceGroups();

    CEifInstanceGroup **m_unk0;             // 0x000 instance group pointer array
    int m_unk4;                             // 0x004 instance group count
    char _pad008[0x104];                    // 0x008 header block
    int m_unk10C;                           // 0x10C state
    PCDFile *m_unk110;                      // 0x110 open file
    char _pad114[0x218];                    // 0x114 block read after the header
    WaypointManager *m_unk32C;              // 0x32C waypoint manager
};

#endif
