// FLAGS: -str readonly
#include "PResourceManager.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);

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
