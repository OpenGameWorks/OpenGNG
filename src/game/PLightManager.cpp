// FLAGS: -str readonly
#include "PLightManager.h"

// TODO(header): foreign declarations
extern "C" void __dt__6PLightFv(void *pThis, short nFlag);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__6PLightFv(void *pThis);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0ApplyMatrix(float *dst, float *mat, float *src);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" void sceVu0Normalize(float *dst, float *src);
extern char gGfxEng[1504384];
extern "C" void SetDirLight__10PGfxEngineFiPfPf(void *pThis, int nIndex, float *pPos, float *pDir);
extern "C" void SetDirLightColor__10PGfxEngineFifff(void *pThis, int nIndex, float fR, float fG, float fB);
extern "C" void SetAmbientLight__10PGfxEngineFPf(void *pThis, float *pColor);
extern "C" void ModulateAllLights__10PGfxEngineFPf(void *pThis, float *pVec);
extern "C" void UpdateLights__10PGfxEngineFv(void *pThis);
extern "C" void GetLightingInfo__10PGfxEngineFP5PMat4P5PMat4PA4_f(void *pThis, void *pA, void *pB, float (*pC)[4]);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuf, unsigned int nSize);
extern "C" void memcpy(void *dst, const void *src, unsigned int n);
extern "C" int Load__6PLightFP8PPakFile(void *pThis, PPakFile *pFile);
extern "C" float GetBrightness__6PLightFPf(void *pThis, float *pOut);
extern "C" void ShellSort__FPFPvPv_bPPvi(bool (*pCompare)(void *, void *), void **ppItems, int nCount);

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PLightManager.cpp", line, #cond))

// Light node: id at 0x00, next node at 0x04.
struct PLightNode {
    unsigned int m_unk0;
    PLightNode *m_unk4;
};

// The light list's inline lookup; the callers' loops come from this body.
static inline PLightNode *FindLightNodeIn(PLightNode *pNode, unsigned int nKey) {
    for (; pNode != 0; pNode = pNode->m_unk4) {
        if (pNode->m_unk0 == nKey) {
            return pNode;
        }
    }
    return 0;
}

// FUNCTION: 0x0018E880 LightCompareBrightness__FPvPv
static bool LightCompareBrightness(void *pA, void *pB) {
    return *(float *)((char *)pA + 0x50) < *(float *)((char *)pB + 0x50);
}

// DRAFT: 0x0018E8B0 FindBrightestLightsOfType__13PLightManagerFPfbb10eLightTypeiPP6PLight
// note: 176 words differ, size 0x3B4 vs 0x3B8. Block A store folds sp+0xA0 (original: addiu v0,sp,0xA0 then addu) and its join has an extra nop, so block B branches sit 2 words early; block A loop tail nop differs. Tried: nIndex local and pDst store (182 before the PList member), split store with i++ and char-pointer store (176).
int PLightManager::FindBrightestLightsOfType(float *pOut, bool bA, bool bB, eLightType nType, int nCount, PLight **pBrightestLights) {
    PLight *aLights[32];
    int i = 0;
    int j;
    void *pNode;
    void *pLight;

    CDS_ASSERT(0x1C0, pBrightestLights);
    if (bA) {
        if (m_unk0.m_unk0 != 0) {
            m_unk0.m_unk4 = 0;
            pNode = (m_unk0.m_unk0 != 0) ? m_unk0.m_unk8[0] : 0;
            if (pNode != 0) {
                do {
                    if (*((unsigned char *)pNode + 0x48) != 0 && *(int *)((char *)pNode + 0x44) == nType) {
                        float fB = GetBrightness__6PLightFPf(pNode, pOut);
                        if (i >= 32) break;
                        if (fB != 0.0f) {
                            aLights[i++] = (PLight *)pNode;
                        }
                    }
                    int nIndex = m_unk0.m_unk4 + 1;
                    m_unk0.m_unk4 = nIndex;
                    pNode = ((unsigned int)nIndex < m_unk0.m_unk0) ? m_unk0.m_unk8[m_unk0.m_unk4] : 0;
                } while (pNode != 0);
            }
        }
    }
    if (bB) {
        if (m_unk10.m_unk0 != 0) {
            for (pLight = m_unk10.GetFirst(); pLight != 0; pLight = m_unk10.GetNext()) {
                if (*((unsigned char *)pLight + 0x48) != 0 && *(int *)((char *)pLight + 0x44) == nType) {
                    if (i >= 32) break;
                    aLights[i++] = (PLight *)pLight;
                    GetBrightness__6PLightFPf(pLight, pOut);
                }
            }
        }
    }
    if (nCount < i) {
        ShellSort__FPFPvPv_bPPvi(LightCompareBrightness, (void **)aLights, i);
    }
    if (nCount > 0) {
        for (j = 0; j < nCount; j++) {
            pBrightestLights[j] = aLights[j];
        }
        return nCount;
    }
    for (j = 0; j < i; j++) {
        pBrightestLights[j] = aLights[j];
    }
    nCount = i;
    return i;
}

// FUNCTION: 0x0018EC70 GetLightObject__13PLightManagerFUi
void *PLightManager::GetLightObject(unsigned int nId) {
    if (FindLightNodeIn((PLightNode *)m_unk10.m_unk4, nId) != 0) {
        return (void *)nId;
    }
    return 0;
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

// FUNCTION: 0x0018ED10 DestroyLight__13PLightManagerFUi
void PLightManager::DestroyLight(unsigned int nID) {
    RemoveDynamicLight((PLight *)nID);
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
    m_unk10.Add(pLight);
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
    m_unk10.m_unkC = m_unk10.m_unk4;
    void *pLight = (m_unk10.m_unk4 != 0) ? (void *)((PLightNode *)m_unk10.m_unk4)->m_unk0 : 0;
    while (pLight != 0) {
        __dt__6PLightFv(pLight, 1);
        if (m_unk10.m_unkC == 0) {
            m_unk10.m_unkC = m_unk10.m_unk4;
            pLight = (m_unk10.m_unk4 != 0) ? (void *)((PLightNode *)m_unk10.m_unk4)->m_unk0 : 0;
        } else {
            PLightNode *pNext = ((PLightNode *)m_unk10.m_unkC)->m_unk4;
            if (pNext != 0) {
                m_unk10.m_unkC = (PListNode *)pNext;
                pLight = (void *)((PLightNode *)m_unk10.m_unkC)->m_unk0;
            } else {
                pLight = 0;
            }
        }
    }
    m_unk10.RemoveAll();
}

// FUNCTION: 0x0018EF60 RemoveDynamicLight__13PLightManagerFP6PLight
void PLightManager::RemoveDynamicLight(PLight *pLight) {
    if (FindLightNodeIn((PLightNode *)m_unk10.m_unk4, (unsigned int)pLight) != 0) {
        __dt__6PLightFv(pLight, 1);
        m_unk10.Remove(pLight);
    }
}

// DRAFT: 0x0018EFE0 ComputeLights__13PLightManagerFPfbbbP21tagComputedLightCachePA4_ff
// note: 115 words differ; frame 0x100 matches (aLights[8]), but i/pLight swap s1/s2 in the first loop (orig i=s2, pLight=s1), and the branch offsets after it shift. Tried: aLights[4] (117), hoisted aDir/aMod (117), counter hoist (115), pLight hoist (115).
void PLightManager::ComputeLights(float *pOut, bool bA, bool bB, bool bC, tagComputedLightCache *pCache, float (*pMatrix)[4], float fScale) {
    PLight *aLights[8];
    float aDir[4];
    float aMod[4];
    int nCount = FindBrightestLightsOfType(pOut, bA, bB, (eLightType)3, 2, aLights);
    for (int i = 0; i < nCount; i++) {
        PLight *pLight = aLights[i];
        if (pLight == 0) {
            CdsAssert__FPciPc("PLightManager.cpp", 0x90, "apLight");
        }
        SetDirLight__10PGfxEngineFiPfPf(gGfxEng, i, (float *)((char *)pLight + 0x20), (float *)((char *)pLight + 0x30));
    }
    if (nCount < 4) {
        for (int i = nCount; i < 4; i++) {
            SetDirLightColor__10PGfxEngineFifff(gGfxEng, i, 0.0f, 0.0f, 0.0f);
        }
    }
    int nRest = 4 - nCount;
    if (nRest != 0) {
        int nFound = FindBrightestLightsOfType(pOut, bA, bB, (eLightType)2, nRest, aLights);
        if (nFound > 0) {
            for (int i = 0; i < nFound; i++) {
                PLight *pLight = aLights[i];
                if (pLight == 0) {
                    CdsAssert__FPciPc("PLightManager.cpp", 0xA7, "apLight");
                }
                sceVu0SubVector(aDir, pOut, (float *)pLight);
                sceVu0Normalize(aDir, aDir);
                SetDirLight__10PGfxEngineFiPfPf(gGfxEng, nCount + i, aDir, (float *)((char *)pLight + 0x60));
            }
        }
    }
    if (bC) {
        float *pAmb = (pMatrix != 0) ? (float *)pMatrix : (float *)((char *)this + 0x20);
        SetAmbientLight__10PGfxEngineFPf(gGfxEng, pAmb);
    }
    if (fScale < 1.0f) {
        aMod[0] = fScale;
        aMod[1] = fScale;
        aMod[2] = fScale;
        aMod[3] = 0.0f;
        ModulateAllLights__10PGfxEngineFPf(gGfxEng, aMod);
    }
    UpdateLights__10PGfxEngineFv(gGfxEng);
    if (pCache != 0) {
        GetLightingInfo__10PGfxEngineFP5PMat4P5PMat4PA4_f(gGfxEng, pCache, (char *)pCache + 0x40, (float (*)[4])((char *)pCache + 0x80));
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

struct PLightFileHeader {
    unsigned int uNumLights;      // 0x00
    unsigned int uLightDataSize;  // 0x04
    char aBlock[0x10];            // 0x08 copied to this+0x20
    char m_unk18[8];              // 0x18
};

// FUNCTION: 0x0018F350 Load__13PLightManagerFP8PPakFile
bool PLightManager::Load(PPakFile *pFile) {
    PLightFileHeader aHeader;
    if (pFile == 0) {
        CdsAssert__FPciPc("PLightManager.cpp", 0x39, "poFile");
    }
    if (Read__7PCDFileFPvUi(pFile, &aHeader, 0x20) != 0x20) {
        return false;
    }
    memcpy(&m_unk20, aHeader.aBlock, 0x10);
    if (aHeader.uNumLights == 0) {
        return true;
    }
    if (aHeader.uLightDataSize != aHeader.uNumLights * 0x40) {
        CdsAssert__FPciPc("PLightManager.cpp", 0x4A, "aHeader.uLightDataSize == sizeof(LIGHT_DATA) * aHeader.uNumLights");
    }
    if (aHeader.uNumLights >= 0x20) {
        CdsAssert__FPciPc("PLightManager.cpp", 0x4C, "aHeader.uNumLights < MAX_STATIC_LIGHTS");
    }
    for (unsigned int i = 0; i < aHeader.uNumLights; i++) {
        PLight *pLight = (PLight *)__nw__FUi(0x70);
        if (pLight != 0) {
            pLight = (PLight *)__ct__6PLightFv(pLight);
        }
        if (pLight == 0) {
            return false;
        }
        if (!Load__6PLightFP8PPakFile(pLight, pFile)) {
            __dt__6PLightFv(pLight, 1);
            return false;
        }
        m_unk0.Add(pLight);
    }
    return true;
}

// FUNCTION: 0x0018F4C0 __dt__13PLightManagerFv
PLightManager::~PLightManager() {
    DestroyAllStaticLights();
    DestroyAllDynamicLights();
}

// FUNCTION: 0x0018F540 __ct__13PLightManagerFv
PLightManager::PLightManager() {
    m_unk20 = 0;
    m_unk0.Allocate(0x20U);
}
