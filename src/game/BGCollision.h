#ifndef BGCOLLISION_H
#define BGCOLLISION_H

#include "types.h"

// TODO(header): foreign declarations
class PVec3;

class BGCollision {
public:
    BGCollision();
    void Destroy();
    int CheckCeiling(float (*pVec)[4]);
    int GetGroundPos(float (*pPos)[4]);
    int CheckIntersectAnim(float (*pA)[4], float (*pB)[4], float (*pC)[4], unsigned int nFlags);
    int FindIntersect(PVec3 &rFrom, PVec3 &rTo, unsigned int nFlags, float (*pOut)[4]);

    char _pad00[0x40];
    int m_unk40;            // 0x040 cleared by ctor and Destroy
    int m_unk44;            // 0x044 cleared by ctor
    char _pad48[0x4];
    void *m_unk4C;          // 0x04C block freed by Destroy
    char _pad50[0x20];
    int m_unk70;            // 0x070 PArray base (size not recovered), set up by ctor
    int m_unk74;            // 0x074 cleared by Destroy
    int m_unk78;            // 0x078 flag checked by Destroy
};

#endif
