#ifndef PDISPLAYLIST_H
#define PDISPLAYLIST_H

#include "types.h"

class PDisplayList {
public:
    PDisplayList();
    ~PDisplayList();
    int AllocEntries(int nCount);
    void *AllocParticles(int nCount, int nSize);
    void DeAllocEntries(int nCount);
    void SetTexSyncPacket();
    void BeginMesh(unsigned int nTag);
    void SetVifCodes(unsigned int nCode0, unsigned int nCode1);
    void BeginMatrixList();
    void Reset();

    char _pad000[0xA3340];
    int m_unkA3340;         // 0xA3340 entry count, decremented by DeAllocEntries
    int m_unkA3344;         // 0xA3344
    char _padA3348[0x4];
    int m_unkA334C;         // 0xA334C result of AllocEntries(1) in BeginMatrixList
    int m_unkA3350;         // 0xA3350
    char _padA3354[0x2C];
    char m_unkA3380[1];     // 0xA3380 PTextureDmaChain, size not yet recovered
};

#endif
