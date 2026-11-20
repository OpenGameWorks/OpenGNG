#ifndef PANIMFRAME_H
#define PANIMFRAME_H

#include "PAnim.h"

// Frame-based animation: the PAnim base (size 0x20) followed by frame range and enable fields. Size 0x34.
// Only the virtuals defined in PAnimFrame.cpp are declared; the rest of the vtable is not recovered yet.
class PAnimFrame : public PAnim {
public:
    PAnimFrame(short nFrame);
    virtual int Load(PPakFile *pFile);
    virtual int Load(PPakFile *pFile, tagMeshNodeAnimationHeader *pHeader);
    void EnableAnim(bool bEnable);
    void RestoreAnim(PAnimFrame *pSrc);

    short m_unk20;                   // 0x20
    short m_unk22;                   // 0x22
    short m_unk24;                   // 0x24
    short m_unk26;                   // 0x26
    short m_unk28;                   // 0x28
    signed char m_unk2A;             // 0x2A
    char _pad2B[1];                  // 0x2B
    float m_unk2C;                   // 0x2C
    float m_unk30;                   // 0x30
};

#endif
