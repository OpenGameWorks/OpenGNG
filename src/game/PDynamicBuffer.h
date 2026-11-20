#ifndef PDYNAMICBUFFER_H
#define PDYNAMICBUFFER_H

#include "types.h"

// Fixed-capacity command buffer of 16-byte entries (PDynamicBuffer.cpp,
// 0x1D5810-0x1D5ECC). Offsets count quadwords; the capacity check is 0x5000.
class PDynamicBuffer {
public:
    ~PDynamicBuffer();
    int Open();
    void Close();                                   // 0x1D5DE0, not in this job
    void *Allocate(unsigned int nQuadwords);
    int WriteDmaCntTag(unsigned int nQwCount, unsigned int nWord8, unsigned int nWordC);
    int WriteGhostData(unsigned int nQuadwords);

    u_long128 *m_pBuffer;       // 0x00 entry storage
    unsigned int m_uCurSize;    // 0x04 high-water mark, quadwords
    unsigned int m_uCurOffset;  // 0x08 next free entry, quadwords
};

#endif
