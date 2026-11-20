#ifndef CBEFENTITYDATA_H
#define CBEFENTITYDATA_H

#include "types.h"

class PPakFile;
class tagBefEditableVariableData;

// CBefEntityData members are named by their offset from the object start. The
// Read path fills 0x04 bytes at offset 0, 0x04 bytes at offset 0x04, 0x80 bytes
// at offset 0x08 and 0x04 bytes at offset 0x88, then allocates the 0x58-byte
// tagBefEditableVariableData array at offset 0x8C.
class CBefEntityData {
public:
    int Read(PPakFile *pFile, unsigned int nVersion);

    int m_unk0;                                 // 0x00 header word read as the object start
    int m_unk4;                                 // 0x04
    char _pad008[0x80];                         // 0x08 record block read as one 0x80-byte record
    int m_unk88;                                // 0x88 edit variable count
    tagBefEditableVariableData *m_unk8C;        // 0x8C edit variable array (0x58-byte elements)
};

#endif
