#ifndef BGCOLLISION_H
#define BGCOLLISION_H

#include "types.h"
#include "PArray.h"

// TODO(header): foreign declarations
class PVec3;
class PMat4;
class PMeshNode;
class SurfaceInfo;
struct STCollisionPoly;
struct STCollisionNode;

class BGCollision {
public:
    BGCollision();
    void Destroy();
    int CheckCeiling(float (*pVec)[4]);
    int GetGroundPos(float (*pPos)[4]);
    int CheckIntersect(float (&pA)[4], float (&pB)[4], float (*pC)[4], unsigned int nFlags);
    int GetGround(float (*pArr)[4], unsigned int nFlags);
    STCollisionPoly *FindIntersectST(int nX, int nZ, float (*pA)[4], float (*pB)[4], float &rT, unsigned int nFlags);
    int CheckIntersectST(int nX, int nZ, float (*pA)[4], float (*pB)[4], float (*pC)[4], unsigned int nFlags);
    int CheckIntersectAnim(float (*pA)[4], float (*pB)[4], float (*pC)[4], unsigned int nFlags);
    STCollisionPoly *FindIntersectAnim(float (*pA)[4], float (*pB)[4], float &rT, unsigned int nFlags, float (*pOut)[4]);
    void FindNextGrid(int &rX, int &rZ, int nDX, int nDZ, float (*pA)[4], float (*pB)[4], bool bFlag);
    int FindIntersect(PVec3 &rFrom, PVec3 &rTo, unsigned int nFlags, float (*pOut)[4]);
    int FindGrid(float (*pArr)[4], int &rX, int &rZ);
    void BGDetection(float (*pArr)[2][4], PMat4 *pMat, float fLen, SurfaceInfo &rSurf, int nFlag, PMeshNode *pMesh);
    void BGDetectionST(float (*pArr)[2][4], PMat4 *pMat, SurfaceInfo *pSurf, int nFlag);
    void BGDetectionAnim(float (*pArr)[2][4], PMat4 *pMat, SurfaceInfo *pSurf, int nFlag, PMeshNode *pMesh);
    int AreaCheckSub(float (*pA)[2][4], float (*pB)[4][4], float (*pC)[2][4], float (*pD)[4][4], int nFlag, int nBit);
    int ReadCollisionData(char *pName, PMeshNode *pMesh);
    int GridCheck(float (*pArr)[2][4], PMat4 *pMat, STCollisionNode **ppOut, float *pOut);

    float m_unk0;           // 0x000 grid origin X
    char _pad04[0x4];
    float m_unk8;           // 0x008 grid origin Z
    char _pad0C[0x4];
    float m_unk10[4];       // 0x010 half extent vector
    float m_unk20[4];       // 0x020 half extent from origin; [0] and [2] feed the cell counts
    float m_unk30;          // 0x030 cell size X
    float m_unk34;          // 0x034 cell size Z
    unsigned int m_unk38;   // 0x038 cell count X
    unsigned int m_unk3C;   // 0x03C cell count Z
    int m_unk40;            // 0x040 cleared by ctor and Destroy
    int m_unk44;            // 0x044 cleared by ctor
    float m_unk48;          // 0x048 holds pArr[1][2] from GridCheck
    void *m_unk4C;          // 0x04C block freed by Destroy
    float m_unk50;          // 0x050
    char _pad54[0x4];
    float m_unk58;          // 0x058
    char _pad5C[0x4];
    float m_unk60;          // 0x060 half of m_unk30
    char _pad64[0x4];
    float m_unk68;          // 0x068 half of m_unk34
    char _pad6C[0x4];
    PArray m_unk70;         // 0x070 allocated with 0x80 slots by the ctor
};

#endif
