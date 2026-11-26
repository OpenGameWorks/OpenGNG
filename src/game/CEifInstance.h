#ifndef CEIFINSTANCE_H
#define CEIFINSTANCE_H

#include "types.h"

class PPakFile;
class tagEditableVariableData;

// CEifInstance members are named by their offset from the object start. The
// Read path fills 0x104 bytes at offset 0 and then 0x24 bytes at offset 0x104.
class CEifInstance {
public:
    tagEditableVariableData *GetEditVarData(int nIndex);
    void GetStartOrientation(float &fX, float &fY, float &fZ);
    void GetStartPosition(float &fX, float &fY, float &fZ);
    int Read(PPakFile *pFile, unsigned int nVersion);
    int GetInstanceID();
    int GetFlags();
    int GetNumEditVars();
    int GetEntityID();

    void SetStartPosition(float, float, float);
    char *GetInstanceName();
    char _pad000[0x104];                    // 0x000 header block read as one 0x104-byte record
    char _pad104[0x8];                      // 0x104
    float m_unk10C;                         // 0x10C start position X
    float m_unk110;                         // 0x110 start position Y
    float m_unk114;                         // 0x114 start position Z
    float m_unk118;                         // 0x118 start orientation X
    float m_unk11C;                         // 0x11C start orientation Y
    float m_unk120;                         // 0x120 start orientation Z
    int m_unk124;                           // 0x124 edit variable count
    tagEditableVariableData *m_unk128;      // 0x128 edit variable array (0x38-byte elements)
};

#endif
