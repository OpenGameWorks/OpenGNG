// FLAGS: -str readonly
#include "PLightManager.h"

// TODO(header): foreign declarations
extern "C" void __ct__5PListFv(void *pThis);
extern "C" void __dt__5PListFv(void *pThis, short nFlag);
extern "C" void __dt__6PLightFv(void *pThis, short nFlag);
extern "C" void RemoveAll__5PListFv(void *pThis);
extern "C" void Remove__5PListFPv(void *pThis, void *pItem);
extern "C" void Add__5PListFPv(void *pThis, void *pItem);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__6PLightFv(void *pThis);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0ApplyMatrix(float *dst, float *mat, float *src);

// Light node: id at 0x00, next node at 0x04.
struct PLightNode {
    unsigned int m_unk0;
    PLightNode *m_unk4;
};

// FUNCTION: 0x0018E880 LightCompareBrightness__FPvPv
bool LightCompareBrightness(void *pA, void *pB) {
    return *(float *)((char *)pA + 0x50) < *(float *)((char *)pB + 0x50);
}

// DRAFT: 0x0018EC70 GetLightObject__13PLightManagerFUi
// note: 8 words differ; the original keeps the node in v1 and tests a shared tail with beqz v1, we emit movz. Tried: return nId (12), ternary tail (8, best), if/pResult tail (14), else-arm loop (14), while loop (17).
void *PLightManager::GetLightObject(unsigned int nId) {
    PLightNode *pNode = (PLightNode *)m_unk14;
    if (pNode != 0) {
        do {
            if (pNode->m_unk0 == nId) {
                break;
            }
            pNode = pNode->m_unk4;
        } while (pNode != 0);
    }
    return (void *)(pNode != 0 ? nId : 0);
}

// FUNCTION: 0x0018ECC0 SetLightColor__13PLightManagerFUiPf
void PLightManager::SetLightColor(unsigned int nId, float *pColor) {
    char *pObj = (char *)GetLightObject(nId);
    if (pObj != 0) {
        *(float *)(pObj + 0x30) = pColor[0];
        *(float *)(pObj + 0x34) = pColor[1];
        *(float *)(pObj + 0x38) = pColor[2];
    }
}

// FUNCTION: 0x0018ED20 CreateDirectionLight__13PLightManagerFPfPf
PLight *PLightManager::CreateDirectionLight(float *pPos, float *pDir) {
    PLight *pLight = (PLight *)__nw__FUi(0x70U);
    if (pLight != 0) {
        pLight = (PLight *)__ct__6PLightFv(pLight);
    }
    if (pLight == 0) {
        return 0;
    }
    *(int *)((char *)pLight + 0x44) = 3;
    *(float *)((char *)pLight + 0x20) = pPos[0];
    *(float *)((char *)pLight + 0x24) = pPos[1];
    *(float *)((char *)pLight + 0x28) = pPos[2];
    *(float *)((char *)pLight + 0x30) = pDir[0];
    *(float *)((char *)pLight + 0x34) = pDir[1];
    *(float *)((char *)pLight + 0x38) = pDir[2];
    *(unsigned char *)((char *)pLight + 0x48) = 1;
    if (pLight == 0) {
        CdsAssert__FPciPc("PLightManager.h", 0x67, "pLight");
    }
    Add__5PListFPv(m_unk10, pLight);
    return pLight;
}

// FUNCTION: 0x0018EE00 DestroyAllStaticLights__13PLightManagerFv
void PLightManager::DestroyAllStaticLights() {
    m_unk0.m_unk4 = 0;
    void *pLight = (m_unk0.m_unk0 != 0) ? m_unk0.m_unk8[0] : 0;
    while (pLight != 0) {
        __dt__6PLightFv(pLight, 1);
        int nIndex = m_unk0.m_unk4 + 1;
        m_unk0.m_unk4 = nIndex;
        pLight = ((unsigned int)nIndex < m_unk0.m_unk0) ? m_unk0.m_unk8[m_unk0.m_unk4] : 0;
    }
    if (m_unk0.m_unk8 != 0) {
        m_unk0.m_unk0 = 0;
        m_unk0.m_unk4 = 0;
    }
}

// FUNCTION: 0x0018EEA0 DestroyAllDynamicLights__13PLightManagerFv
void PLightManager::DestroyAllDynamicLights() {
    m_unk1C = m_unk14;
    void *pLight = (m_unk14 != 0) ? (void *)((PLightNode *)m_unk14)->m_unk0 : 0;
    while (pLight != 0) {
        __dt__6PLightFv(pLight, 1);
        if (m_unk1C == 0) {
            m_unk1C = m_unk14;
            pLight = (m_unk14 != 0) ? (void *)((PLightNode *)m_unk14)->m_unk0 : 0;
        } else {
            PLightNode *pNext = ((PLightNode *)m_unk1C)->m_unk4;
            if (pNext != 0) {
                m_unk1C = pNext;
                pLight = (void *)((PLightNode *)m_unk1C)->m_unk0;
            } else {
                pLight = 0;
            }
        }
    }
    RemoveAll__5PListFv(m_unk10);
}

// DRAFT: 0x0018EF60 RemoveDynamicLight__13PLightManagerFP6PLight
// note: 5 words differ; the original branches with bne/beq into the tail and a b over the zeroing block, ours uses bnez at the loop back-edge and b for the break. Tried: do/while with else-null (5, best), while with inner break (25), for loop (20).
void PLightManager::RemoveDynamicLight(PLight *pLight) {
    void *pNode = m_unk14;
    if (pNode != 0) {
        do {
            if (((PLightNode *)pNode)->m_unk0 == (unsigned int)pLight) {
                break;
            }
            pNode = ((PLightNode *)pNode)->m_unk4;
        } while (pNode != 0);
    } else {
        pNode = 0;
    }
    if (pNode != 0) {
        __dt__6PLightFv(pLight, 1);
        Remove__5PListFPv(m_unk10, pLight);
    }
}

// FUNCTION: 0x0018F280 ComputeLights__13PLightManagerFP5PMeshP5PMat4bbbP21tagComputedLightCachef
void PLightManager::ComputeLights(PMesh *pMesh, PMat4 *pMat, bool bA, bool bB, bool bC, tagComputedLightCache *pCache, float fScale) {
    float aVec[4];
    if (pMesh == 0) {
        CdsAssert__FPciPc("PLightManager.cpp", 0x6D, "pMesh");
    }
    sceVu0ApplyMatrix(aVec, (float *)pMat, (float *)((char *)pMesh + 0x10));
    ComputeLights(aVec, bA, bB, bC, pCache, 0, fScale);
}

// FUNCTION: 0x0018F4C0 __dt__13PLightManagerFv
PLightManager::~PLightManager() {
    DestroyAllStaticLights();
    DestroyAllDynamicLights();
    __dt__5PListFv(m_unk10, -1);
}

// FUNCTION: 0x0018F540 __ct__13PLightManagerFv
PLightManager::PLightManager() {
    __ct__5PListFv(m_unk10);
    m_unk20 = 0;
    m_unk0.Allocate(0x20U);
}
