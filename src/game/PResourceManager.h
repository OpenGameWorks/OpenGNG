#ifndef PRESOURCEMANAGER_H
#define PRESOURCEMANAGER_H

#include "types.h"
#include "PMesh.h"

class PMNode;
class PPakFile;
class PArray;

// TODO(header): eResourceTypes belongs to the owner header of the resource type enum. Placeholder until that header defines it; only the name matters for mangling.
enum eResourceTypes { eResourceTypes_Placeholder = 0 };

class PResourceManager {
public:
    struct tagResourceData {
        int m_unk0;
        char _pad004[0x4];
        unsigned int *m_unk8;
        int m_unkC;
        char _pad010[0x4];
        unsigned int *m_unk14;
        int m_unk18;
        char _pad01C[0x4];
        unsigned int *m_unk20;
        int m_unk24;
        void **m_unk28;
        unsigned int *m_unk2C;
        int m_unk30;
        unsigned int *m_unk34;
        unsigned int *m_unk38;
        int m_unk3C;
        void **m_unk40;
        unsigned int *m_unk44;
        char _pad048[0x20];
    };

    PResourceManager();
    ~PResourceManager();
    int LookupResourceIndex(unsigned int *pIds, int nCount, int nId);
    PMNode *GetResource(tagResourceData *pData, unsigned int uId, eResourceTypes eType, int nIndex, bool bFlag);
    PMNode *GetResource(int nId, eResourceTypes eType, bool bLocal);
    PMNode *GetResource(unsigned int uId, bool bFlag);
    PMNode *GetResourceFromIndex(tagResourceData *pData, int nIndex, eResourceTypes eType, unsigned int uFlags, bool bFlag);
    unsigned int GetResType(unsigned int uTheID);
    void Unload(tagResourceData *pData);
    int LoadShadowVolumeTable(PPakFile *pFile, tagResourceData *pData, unsigned int uId);
    int LoadInstanceMeshTable(PPakFile *pFile, tagResourceData *pData, PArray *pArray, ePsx2FileVersion eVersion, unsigned int uId);
    int LoadTextureResTable(PPakFile *pFile, PArray *pArray, tagResourceData *pData, unsigned int uId);
    int GetNumResourcesOfType(eResourceTypes eType, bool bLocal);

private:
    tagResourceData m_unk0;
    tagResourceData m_unk68;
};

#endif
