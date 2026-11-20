#ifndef PRESOURCEMANAGER_H
#define PRESOURCEMANAGER_H

#include "types.h"

class PMNode;

// TODO(header): eResourceTypes belongs to the owner header of the resource type enum. Placeholder until that header defines it; only the name matters for mangling.
enum eResourceTypes { eResourceTypes_Placeholder = 0 };

class PResourceManager {
public:
    struct tagResourceData {
        char _pad000[0x68];
    };

    PResourceManager();
    ~PResourceManager();
    int LookupResourceIndex(unsigned int *pIds, int nCount, int nId);
    PMNode *GetResource(int nId, eResourceTypes eType, bool bLocal);
    PMNode *GetResourceFromIndex(tagResourceData *pData, int nIndex, eResourceTypes eType, unsigned int uFlags, bool bFlag);
    unsigned int GetResType(unsigned int uTheID);
    void Unload(tagResourceData *pData);

private:
    tagResourceData m_unk0;
    tagResourceData m_unk68;
};

#endif
