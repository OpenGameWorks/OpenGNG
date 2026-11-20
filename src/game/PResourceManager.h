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
    struct tagFxData {
        char _pad000[0x20];
        unsigned int m_unk20;   // index into the PArray, then the resolved entry
        unsigned int m_unk24;   // byte count read into m_unk38
        char _pad028[0x10];
        void *m_unk38;
    };

    struct tagResourceData {
        int m_unk0;
        void **m_unk4;
        unsigned int *m_unk8;
        int m_unkC;
        void **m_unk10;
        unsigned int *m_unk14;
        int m_unk18;
        tagFxData *m_unk1C;
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
        char _pad048[0x1F];
        unsigned char m_unk67;
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
    int LoadAnimResTable(PPakFile *pFile, ePsx2FileVersion eVersion, tagResourceData *pData, unsigned int uId);
    int LoadMeshResTable(PPakFile *pFile, PArray *pArray, ePsx2FileVersion eVersion, tagResourceData *pData, unsigned int uId);
    int LoadTextureResTable(PPakFile *pFile, PArray *pArray, tagResourceData *pData, unsigned int uId);
    int LoadFxResTable(PPakFile *pFile, PArray *pArray, tagResourceData *pData, unsigned int uId);
    int GetNumResourcesOfType(eResourceTypes eType, bool bLocal);

private:
    tagResourceData m_unk0;
    tagResourceData m_unk68;
};

#endif
