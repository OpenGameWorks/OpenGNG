#ifndef PAD_H
#define PAD_H

#include "types.h"

// Controller state record. Members are named by offset from the object start.
class Pad {
public:
    int ReadNew();
    int ReadPush();
    int IsConnected();

    char _pad000[0x108];
    unsigned short m_unk108;        // 0x108 gate: when set, the low button bits merge in
    unsigned short m_unk10A;        // 0x10A pushed-state button word
    unsigned short m_unk10C;        // 0x10C new-state button word
    char _pad10E[2];
    unsigned short m_unk110;        // 0x110 base word for the push read
    char _pad112[0x170 - 0x112];
    unsigned char m_unk170;         // 0x170 pad mode index, connected when below 8
    char _pad171[3];
    int m_unk174;                   // 0x174 fallback connection flag
};

void PadInit();
void PadEnd();

#endif
