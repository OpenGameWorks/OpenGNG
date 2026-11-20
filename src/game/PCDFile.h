#ifndef PCDFILE_H
#define PCDFILE_H

#include "types.h"

class PCDFile {
public:
    PCDFile();
    ~PCDFile();
    int GetSize();
    int Read(void *buf, unsigned int size);
    int Close();
    int ReadEx(void *buf, unsigned int size);

private:
    char _pad0[0x10004];
    int m_size;                      // 0x10004
    char _pad10008[0x1C];            // 0x10008
    PCDFile *m_unk10024;             // 0x10024
    void *m_unk10028;                // 0x10028
    unsigned char m_unk1002C;        // 0x1002C
    unsigned char m_unk1002D;        // 0x1002D
    unsigned char m_unk1002E;        // 0x1002E
    char _pad1002F[0x21];            // 0x1002F
    unsigned int m_unk10050;         // 0x10050
    int m_unk10054;                  // 0x10054
};

#endif
