#ifndef PLIGHTMANAGER_H
#define PLIGHTMANAGER_H

#include "types.h"
#include "PArray.h"
#include "PList.h"

// Light table owner, embedded in PWorld at offset 0x1F0. Size 0x30:
// PArray base at 0x00, PList block at 0x10 (list head at 0x14), 16-byte field at 0x20.
class PLight;
class PMesh;
class PMat4;
class PPakFile;
struct tagComputedLightCache;

// Light type tag of PLight at 0x44. Only the callers' values (2 and 3) are known.
enum eLightType { eLightType_Unknown = 0 };

class PLightManager {
public:
    void DestroyLight(unsigned int nID);
    PLightManager();
    ~PLightManager();
    bool Load(PPakFile *pFile);
    int FindBrightestLightsOfType(float *pOut, bool bA, bool bB, eLightType nType, int nCount, PLight **ppLights);
    void *GetLightObject(unsigned int nId);
    void SetLightColor(unsigned int nId, float *pColor);
    void DestroyAllStaticLights();
    void DestroyAllDynamicLights();
    void RemoveDynamicLight(PLight *pLight);
    PLight *CreateDirectionLight(float *pPos, float *pDir);
    void ComputeLights(float *pOut, bool bA, bool bB, bool bC, tagComputedLightCache *pCache, float (*pMatrix)[4], float fScale);
    void ComputeLights(PMesh *pMesh, PMat4 *pMat, bool bA, bool bB, bool bC, tagComputedLightCache *pCache, float fScale);

    PArray m_unk0;          // 0x00 light array, storage allocated by the ctor
    PList m_unk10;          // 0x10 dynamic light list (head at 0x14, cursor at 0x1C)
    u_long128 m_unk20;      // 0x20 cleared by ctor
};

#endif
