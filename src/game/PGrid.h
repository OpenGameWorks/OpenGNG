#ifndef PGRID_H
#define PGRID_H

#include "types.h"

// One strip vertex, 0x30 bytes. InitStrip writes two per column, at 0x00 and 0x30 of each 0x60 step.
struct tagGridStripVertex {
    int m_00;                       // 0x00, first integer coordinate from FTOI4
    int m_04;                       // 0x04, second integer coordinate from FTOI4
    char _pad08[8];
    unsigned int m_10;              // 0x10
    unsigned int m_14;              // 0x14
    unsigned int m_18;              // 0x18
    unsigned int m_1C;              // 0x1C
    int m_20;                       // 0x20, row offset
    int m_24;                       // 0x24, column offset
    char _pad28[5];
    unsigned char m_2D;             // 0x2D, bit 0x80 set on the first column when bFlag is true
    char _pad2E[2];
};

class PGrid {
public:
    PGrid();
    ~PGrid();
    void Enable(bool bEnable);
    void Render();
    void Destroy();
    void Animate(float fStep);
    void AnimateAlphaGrid(float fAngle);
    void SetGridVertexAlpha();
    void InitStrip(tagGridStripVertex *pVerts, short sA, short sB, short sC, short sD,
                   unsigned int uA, unsigned int uB, unsigned int uC, unsigned int uD,
                   float fU, float fV, float fW, bool bFlag);

    void *m_pData;                  // 0x000, vertex block freed by Destroy and sent by Render
    int m_nSize;                    // 0x004, Render sends m_nSize * 16 bytes
    int m_08;                       // 0x008
    int m_0C;                       // 0x00C
    int m_10;                       // 0x010
    char _pad014[0x2014 - 0x14];
    unsigned int m_2014;            // 0x2014, unsigned scale read by SetGridVertexAlpha
    float m_2018;                  // 0x2018, reset by Enable(true)
    float m_201C;                   // 0x201C, per-frame step set by Enable
    unsigned char m_bEnabled;       // 0x2020, Render draws only when set
    char _pad2021[3];
    float m_2024;                   // 0x2024, fade-in duration (step is 1 / m_2024)
    float m_2028;                   // 0x2028, fade-out duration (step is -1 / m_2028)
    float m_202C;                   // 0x202C, fade-out countdown decremented by Animate
    float m_2030;                   // 0x2030, 60 + 240 * random fraction
};

#endif
