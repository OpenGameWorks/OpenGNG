#ifndef PANIM_H
#define PANIM_H

#include "types.h"

class PPakFile;
class PChannel;

// Animation header read from the pak: 0x10 bytes. The channel count at 0x04 is unsigned (compared with unsigned ops in Load).
struct tagMeshNodeAnimationHeader {
    unsigned short m_unk0;           // 0x00
    char _pad02[2];
    unsigned int m_unk4;             // 0x04, channel count (at most 5)
    int m_unk8;                      // 0x08
    char _pad0C[4];
};

// Enumerator values are not recovered yet; the name is what the mangled signatures need.
enum eAnimType {
    eAnimType_Placeholder = 0
};

// Animation holder: vptr at 0x00, a 4-byte field at 0x04, a s16 at 0x08, two bytes at 0x0A and 0x0B,
// and five PChannel slots at 0x0C..0x1C. Size 0x20.
class PAnim {
public:
    PAnim();
    virtual ~PAnim();
    virtual int Load(PPakFile *pFile);
    virtual int Load(PPakFile *pFile, tagMeshNodeAnimationHeader *pHeader);
    PChannel *FindChannel(eAnimType eType);
    virtual float Animate(float fTime, float fUnused, float (*pMatrix)[4], float *pOut, bool bFlag);
    void Cleanup();

    int m_unk4;                      // 0x04
    short m_unk8;                    // 0x08
    unsigned char m_unkA;            // 0x0A
    unsigned char m_unkB;            // 0x0B
    PChannel *m_unkC[5];             // 0x0C
};

#endif
