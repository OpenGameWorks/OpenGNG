// FLAGS: -str readonly
#include "PResourceManager.h"
#include "PCDFile.h"
#include "PShadowVolume.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);

// FUNCTION: 0x00152D40 LookupResourceIndex__16PResourceManagerFPUiii
int PResourceManager::LookupResourceIndex(unsigned int *pIds, int nCount, int nId) {
    int i;
    for (i = 0; i < nCount; i++) {
        if (nId == pIds[i]) {
            return i;
        }
    }
    return -1;
}

// DRAFT: 0x00152D90 GetResource__16PResourceManagerFPQ216PResourceManager15tagResourceDataUi14eResourceTypesib
// note: DIFF 106; original is an if/else compare chain on eType sharing one epilogue, ours is a jump-table switch that repeats the epilogue per return. Tried if/else chain (DIFF 107), single-exit nested guards (DIFF 126), do/while break (DIFF 130).
PMNode *PResourceManager::GetResource(tagResourceData *pData, unsigned int uId, eResourceTypes eType, int nIndex, bool bFlag) {
    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0x467, "pResData");
    }
    PMNode *pResult = 0;
    if (nIndex < 0 || eType == 0) {
        return pResult;
    }
    switch (eType) {
    case 1:
        if (pData->m_unk8 != 0) {
            nIndex = LookupResourceIndex(pData->m_unk8, pData->m_unk0, nIndex);
            if (nIndex < 0) {
                return pResult;
            }
        }
        break;
    case 2:
        if (pData->m_unk14 != 0) {
            nIndex = LookupResourceIndex(pData->m_unk14, pData->m_unkC, nIndex);
            if (nIndex < 0) {
                return pResult;
            }
        }
        break;
    case 4:
        if (pData->m_unk2C != 0) {
            nIndex = LookupResourceIndex(pData->m_unk2C, pData->m_unk24, nIndex);
            if (nIndex < 0) {
                return pResult;
            }
        }
        break;
    case 3:
        if (pData->m_unk20 != 0) {
            nIndex = LookupResourceIndex(pData->m_unk20, pData->m_unk18, nIndex);
            if (nIndex < 0) {
                return pResult;
            }
        }
        break;
    case 7:
        if (pData->m_unk38 != 0) {
            nIndex = LookupResourceIndex(pData->m_unk38, pData->m_unk30, nIndex);
            if (nIndex < 0) {
                return pResult;
            }
        }
        break;
    case 6:
        if (pData->m_unk44 != 0) {
            nIndex = LookupResourceIndex(pData->m_unk44, pData->m_unk3C, nIndex);
            if (nIndex < 0) {
                return pResult;
            }
        }
        break;
    }
    return GetResourceFromIndex(pData, nIndex, eType, uId, bFlag);
}

// FUNCTION: 0x00153C50 LoadShadowVolumeTable__16PResourceManagerFP8PPakFilePQ216PResourceManager15tagResourceDataUi
int PResourceManager::LoadShadowVolumeTable(PPakFile *pFile, tagResourceData *pData, unsigned int uId) {
    unsigned int nCount;
    if (pFile == 0) {
        CdsAssert("PResourceManager.cpp", 0x234, "poFile");
    }
    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0x235, "pTheResData");
    }
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    pData->m_unk30 = nCount;
    if (nCount == 0) {
        pData->m_unk38 = 0;
        pData->m_unk34 = 0;
        return 1;
    }
    if (uId >= 0x20009) {
        pData->m_unk38 = (unsigned int *)__nwa__FUi(nCount * 4);
        if (pData->m_unk38 == 0) {
            return 0;
        }
        if (((PCDFile *)pFile)->Read(pData->m_unk38, nCount * 4) != (int)(nCount * 4)) {
            return 0;
        }
    }
    pData->m_unk34 = (unsigned int *)__nwa__FUi(nCount * 4);
    if (pData->m_unk34 == 0) {
        return 0;
    }
    for (unsigned int i = 0; i < nCount; i++) {
        PShadowVolume *p = new PShadowVolume();
        if (p == 0) {
            return 0;
        }
        if (p->Load(pFile) == 0) {
            delete p;
            return 0;
        }
        ((PShadowVolume **)pData->m_unk34)[i] = p;
    }
    return 1;
}

// FUNCTION: 0x00154820 GetNumResourcesOfType__16PResourceManagerF14eResourceTypesb
int PResourceManager::GetNumResourcesOfType(eResourceTypes eType, bool bLocal) {
    tagResourceData *pData;
    if (bLocal) {
        pData = (tagResourceData *)this;
    } else {
        pData = &m_unk68;
    }
    int nCount = 0;
    switch (eType) {
    case 1:
        nCount = pData->m_unk0;
        break;
    case 2:
        nCount = pData->m_unkC;
        break;
    case 4:
        nCount = pData->m_unk24;
        break;
    case 3:
        nCount = pData->m_unk18;
        break;
    case 7:
        nCount = pData->m_unk30;
        break;
    case 6:
        nCount = pData->m_unk3C;
        break;
    }
    return nCount;
}

// FUNCTION: 0x001548A0 GetResource__16PResourceManagerFi14eResourceTypesb
PMNode *PResourceManager::GetResource(int nId, eResourceTypes eType, bool bLocal) {
    tagResourceData *pData;
    if (bLocal) {
        pData = (tagResourceData *)this;
    } else {
        pData = &m_unk68;
    }
    return GetResourceFromIndex(pData, nId, eType, 0, false);
}

// FUNCTION: 0x001548D0 GetResource__16PResourceManagerFUib
PMNode *PResourceManager::GetResource(unsigned int uId, bool bFlag) {
    if (uId == 0) {
        CdsAssert("PResourceManager.cpp", 0x53, "uTheID");
    }
    if (uId == 0) {
        CdsAssert("PResourceManager.cpp", 0x2C6, "uTheID");
    }
    eResourceTypes eType = (eResourceTypes)((uId & 0x7F000000) >> 24);
    unsigned int nIndex = uId & 0xFFFFFF;
    if (((uId & 0x80000000) >> 31) == 1) {
        return GetResource((tagResourceData *)this, uId, eType, nIndex, bFlag);
    }
    return GetResource(&m_unk68, uId, eType, nIndex, bFlag);
}

// FUNCTION: 0x001549A0 GetResType__16PResourceManagerFUi
unsigned int PResourceManager::GetResType(unsigned int uTheID) {
    if (uTheID == 0) {
        CdsAssert("PResourceManager.cpp", 0x2C6, "uTheID");
    }
    return (uTheID & 0x7F000000) >> 24;
}

// FUNCTION: 0x00154A30 __dt__16PResourceManagerFv
PResourceManager::~PResourceManager() {
    Unload(&m_unk68);
    Unload(&m_unk0);
}

// FUNCTION: 0x00154A90 __ct__16PResourceManagerFv
PResourceManager::PResourceManager() {
    memset(&m_unk68, 0, 0x68);
    memset(&m_unk0, 0, 0x68);
}
