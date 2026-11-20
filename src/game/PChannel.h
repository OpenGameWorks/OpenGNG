#ifndef PCHANNEL_H
#define PCHANNEL_H

#include "types.h"

class PChannel {
public:
    ~PChannel();
    void *AnimateBox(float fTime, unsigned char &ucMask);
    void EvaluateAnim(float fTime, float *pOut, int nCount, float fDefault);

private:
    int m_unk0;                      // 0x00
    unsigned short m_unk4;           // 0x04, animation kind (switch selector)
    unsigned short m_unk6;           // 0x06, record count
    unsigned short m_unk8;           // 0x08
    unsigned short m_unkA;           // 0x0A
    char _pad0C[4];                  // 0x0C
    // 0x10: records, 8 bytes each: float key time at 0x10 + 8 * i, mask byte at 0x14 + 8 * i
};

#endif
