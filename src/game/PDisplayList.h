#ifndef PDISPLAYLIST_H
#define PDISPLAYLIST_H

#include "types.h"

class PMat4;

class PDisplayList {
public:
    PDisplayList();
    ~PDisplayList();
    int AllocEntries(int nCount);
    void *AllocParticles(int nCount, int nSize);
    void DeAllocEntries(int nCount);
    void SetTexSyncPacket();
    void BeginFxLoop(unsigned int nTag);
    void SetVertexData(float (*pVerts)[4], int nCount, int nFlags);
    void DrawRawVertices(float (*p0)[4], float (*p1)[4], float (*p2)[4], float (*p3)[4], int nCount);
    void AddVifPacket(u_long128 *pTag, int nCount, unsigned int nCode0, unsigned int nCode1);
    void AddVifDmaPacket(u_long128 *pPacket, int nNumQW);
    void BeginMesh(unsigned int nTag);
    void SetVifCodes(unsigned int nCode0, unsigned int nCode1);
    void BeginMatrixList();
    void EndMatrixList();
    void AddMatrix(PMat4 *pMat, unsigned int nTag);
    void WriteToVu1Mem(unsigned int uVu1MemOffset, u_long128 *pData, int nQwords);
    void SendGsPacket(void *pvData, int iSize, bool bFlag);
    void SetGsRegisters(u_long128 *pRegData, int nNumRegs);
    void Reset();
    void RenderShadowVolume(void *pvData, int iSize);
    void BeginShadowVolume(PMat4 *pMat, float *pA, float *pB, float *pC, float *pD, float *pE);
    void DrawVertices(void *pvData, int iSize);
    void SetClipMatrix(PMat4 *pMat);
    void SetScreenMatrix(PMat4 *pMat);
    void SetViewMatrix(PMat4 *pMat);
    void SetWorldMatrix(PMat4 *pMat);
    void KickVifDmaChain(bool bWait);

    char _pad000[0xA3340];
    int m_unkA3340;         // 0xA3340 entry count, decremented by DeAllocEntries
    int m_unkA3344;         // 0xA3344
    int m_unkA3348;         // 0xA3348 checked against 2 in BeginFxLoop
    int m_unkA334C;         // 0xA334C result of AllocEntries(1) in BeginMatrixList
    int m_unkA3350;         // 0xA3350
    char _padA3354[0x2C];
    char m_unkA3380[1];     // 0xA3380 PTextureDmaChain, size not yet recovered
};

#endif
