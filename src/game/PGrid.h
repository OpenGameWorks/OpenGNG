#ifndef PGRID_H
#define PGRID_H

#include "types.h"

class PGrid {
public:
    PGrid();
    ~PGrid();
    void Enable(bool bEnable);
    void Render();
    void Destroy();

    void *m_pData;                  // 0x000, vertex block freed by Destroy and sent by Render
    int m_nSize;                    // 0x004, Render sends m_nSize * 16 bytes
    int m_08;                       // 0x008
    int m_0C;                       // 0x00C
    int m_10;                       // 0x010
    char _pad014[0x2018 - 0x14];
    int m_2018;                     // 0x2018, reset by Enable(true)
    float m_201C;                   // 0x201C, per-frame step set by Enable
    unsigned char m_bEnabled;       // 0x2020, Render draws only when set
    char _pad2021[3];
    float m_2024;                   // 0x2024, fade-in duration (step is 1 / m_2024)
    float m_2028;                   // 0x2028, fade-out duration (step is -1 / m_2028)
    int m_202C;                     // 0x202C
    float m_2030;                   // 0x2030, 60 + 240 * random fraction
};

#endif
