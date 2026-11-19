#ifndef PWORLD_H
#define PWORLD_H

#include "PFrustrum.h"

class PWorld {
public:
    void InitFrustrum(PMat4 *pMat, float (*pVec)[4]);

    char _pad000[0x90];
    float m_Mat[4][4];      // 0x090
    float m_Vec[4];         // 0x0D0
    float m_Persp[4];       // 0x0E0
    PFrustrum m_Frustrum;   // 0x0F0
    char _pad100[0x13790 - 0x100];
    char m_bCulled;         // 0x13790
};

#endif
