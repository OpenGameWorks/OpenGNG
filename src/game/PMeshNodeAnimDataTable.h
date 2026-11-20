#ifndef PMESHNODEANIMDATATABLE_H
#define PMESHNODEANIMDATATABLE_H

#include "types.h"
#include "PMeshNodeAnimData.h"

class PPakFile;

// Table of PMeshNodeAnimData records, deriving from PResource. The vtable pointer at 0x00 is stored by hand in the
// constructor and destructor (no virtual members are declared). PResource int at 0x04, record count at 0x08,
// record array at 0x0C, and a 0x20-byte block read from the pak at 0x10. Size at least 0x30.
class PMeshNodeAnimDataTable {
public:
    PMeshNodeAnimDataTable();
    ~PMeshNodeAnimDataTable();
    int Load(PPakFile *pFile, ePsx2FileVersion eVersion);

    char _pad00[4];                  // 0x00 vtable pointer
    int m_unk04;                     // 0x04 PResource field
    unsigned int m_unk08;            // 0x08 record count
    PMeshNodeAnimData *m_unk0C;      // 0x0C record array
    unsigned int m_unk10;            // 0x10 first word of the pak block
    char _pad14[0x1C];               // 0x14
};

#endif
