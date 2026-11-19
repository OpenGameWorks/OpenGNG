#include "PWorld.h"

// FUNCTION: 0x19A730 InitFrustrum__6PWorldFP5PMat4PA4_f
void PWorld::InitFrustrum(PMat4 *pMat, float (*pVec)[4]) {
    *(u_long128 *)m_Vec = *(u_long128 *)pVec;
    sceVu0CopyMatrix(m_Mat, (float(*)[4])pMat);
    m_Frustrum.Init(m_Persp[0], m_Persp[1], m_Persp[2], m_Persp[3], pMat, pVec);
    m_bCulled = 0;
}
