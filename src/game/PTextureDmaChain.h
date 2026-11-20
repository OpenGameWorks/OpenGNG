#ifndef PTEXTUREDMACHAIN_H
#define PTEXTUREDMACHAIN_H

#include "types.h"

// PTextureDmaChain is a 0x72A0-byte block embedded in PDisplayList at 0xA3380.
// Layout: entry buffer at 0x40 (0x700 entries of 16 bytes), used count at 0x7080,
// running count at 0x7084, index table at 0x7088 (128 ints), batch index at 0x7288,
// batch count at 0x728C, and a 128-bit field at 0x7290 set to 0x8000 by the ctor.
class PTextureDmaChain {
public:
    PTextureDmaChain();
    int NextBatch();
    void Kick(bool bFlag);
    void *AllocEntries(int nCount);
    void Reset();

    char _pad000[0x40];
    char m_unk40[0x7000];       // 0x040 entry buffer, indexed through the table at 0x7088
    char _pad7040[0x7080 - 0x7040];
    unsigned int m_unk7080;     // 0x7080 entries used
    int m_unk7084;              // 0x7084 running entry count
    int m_unk7088[0x80];        // 0x7088 index table of entry slots
    int m_unk7288;              // 0x7288 next batch index
    int m_unk728C;              // 0x728C batch count
    u_long128 m_unk7290;        // 0x7290 128-bit field, 0x8000 after construction
};

#endif
