#ifndef PCDFILE_H
#define PCDFILE_H

#include "types.h"

enum OPEN_TYPE {
    OPEN_READ = 1,
};

class PCDFile {
public:
    PCDFile();
    ~PCDFile();
    int GetSize();
    int Read(void *buf, unsigned int size);
    int Close();
    int ReadEx(void *buf, unsigned int size);
    int OpenEx(const char *arg0);
    int Open(const char *arg0, OPEN_TYPE type);

private:
    int ErrorCheck();
    int ReadData(int arg0);
    char _pad0[0x10004];
    int m_size;                      // 0x10004
    char _pad10008[0x1C];            // 0x10008
    PCDFile *m_unk10024;             // 0x10024
    void *m_unk10028;                // 0x10028
    unsigned char m_unk1002C;        // 0x1002C
    unsigned char m_unk1002D;        // 0x1002D
    unsigned char m_unk1002E;        // 0x1002E
    char _pad1002F[0x1];             // 0x1002F
    int m_unk10030;                  // 0x10030
    int m_unk10034;                  // 0x10034
    int m_unk10038;                  // 0x10038
    int m_unk1003C;                  // 0x1003C
    char _pad10040[0x8];             // 0x10040
    int m_unk10048;                  // 0x10048
    int m_unk1004C;                  // 0x1004C
    unsigned int m_unk10050;         // 0x10050
    int m_unk10054;                  // 0x10054
};

#endif
