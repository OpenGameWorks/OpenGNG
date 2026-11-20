// FLAGS: -str readonly
#include "PResourceManager.h"
#include "PCDFile.h"
#include "PShadowVolume.h"
#include "PStaticInstanceMesh.h"
#include "PArray.h"
#include "MemoryManager.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *__dt__13PShadowVolumeFv(void *pThis, short nFlag);
extern "C" void *__dt__19PStaticInstanceMeshFv(void *pThis, short nFlag);
extern "C" void UnloadDynamicTextures__15PTextureManagerF13eTextureGroup(void *pThis, int eGroup);
extern "C" void UnloadDynamicTexture__15PTextureManagerFi(void *pThis, int nHandle);
extern char gGfxEng[1504384];
extern MemoryManager MemMgr;
class PResourceElem {
public:
    virtual void Release(short nFlag);
    int m_unk4;
};
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__22PMeshNodeAnimDataTableFv(void *pThis);
extern "C" int Load__22PMeshNodeAnimDataTableFP8PPakFile16ePsx2FileVersion(void *pThis, PPakFile *pFile, ePsx2FileVersion eVersion);
extern "C" int printf(const char *pFmt, ...);
extern "C" void *__ct__9PMeshNodeFQ29PResource11eResObjType(void *pThis, int eType);
extern "C" int Load__9PMeshNodeFP8PPakFileP6PArray16ePsx2FileVersion(void *pThis, PPakFile *pFile, PArray *pArray, ePsx2FileVersion eVersion);
extern "C" void *__ct__9PSkeletonFQ29PResource11eResObjType(void *pThis, int eType);
extern "C" int Load__9PSkeletonFP8PPakFileP6PArray16ePsx2FileVersion(void *pThis, PPakFile *pFile, PArray *pArray, ePsx2FileVersion eVersion);
extern "C" void *__ct__9PMeshNodeFR9PMeshNode(void *pThis, void *pSrc);
extern "C" void *__ct__9PSkeletonFR9PSkeleton(void *pThis, void *pSrc);
extern "C" void *__ct__13PShadowVolumeFP13PShadowVolume(void *pThis, void *pSrc);
extern int guGlobalShaderIDOffset;
extern int guNumShadersInCurModel;
class PMeshNodeAnimDataTable {
public:
    virtual ~PMeshNodeAnimDataTable();
};

// DRAFT: 0x00152990 GetResourceFromIndex__16PResourceManagerFPQ216PResourceManager15tagResourceDatai14eResourceTypesUib
// note: DIFF 141 words; eType 1 out-of-range branch lands near (orig jumps to shared epilogue), bnez/printf/assert layout differs. Tried if-chain (161) and single-exit pResult (210).
PMNode *PResourceManager::GetResourceFromIndex(tagResourceData *pData, int nIndex, eResourceTypes eType, unsigned int uFlags, bool bFlag) {
    void *pEntry;
    void *pNew;

    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0x4E9, "pResData");
    }
    if (eType == 1) {
        pEntry = (nIndex < pData->m_unk0) ? pData->m_unk4[nIndex] : 0;
        if (pEntry == 0) {
            printf("\n **** Bogus mesh resource data! Resource ID = %d, Index = %d **** \n", uFlags, nIndex);
        }
        if (pEntry == 0) {
            CdsAssert("PResourceManager.cpp", 0x4F9, "apResource");
        }
        if (bFlag) {
            return (PMNode *)pEntry;
        }
        if (((int *)pEntry)[1] == 1) {
            pNew = __nw__FUi(0x140);
            if (pNew) {
                return (PMNode *)__ct__9PMeshNodeFR9PMeshNode(pNew, pEntry);
            }
            return 0;
        }
        if (((int *)pEntry)[1] == 2) {
            pNew = __nw__FUi(0x160);
            if (pNew) {
                return (PMNode *)__ct__9PSkeletonFR9PSkeleton(pNew, pEntry);
            }
            return 0;
        }
        CdsAssert("PResourceManager.cpp", 0x50B, "0");
        return (PMNode *)pEntry;
    }
    if (eType == 2) {
        pEntry = (nIndex < pData->m_unkC) ? pData->m_unk10[nIndex] : 0;
        if (pEntry == 0) {
            printf("\n **** Bogus animation resource data! Resource ID = %d, Index = %d **** \n", uFlags, nIndex);
        }
        if (pEntry == 0) {
            CdsAssert("PResourceManager.cpp", 0x51D, "apResource");
        }
        return (PMNode *)pEntry;
    }
    if (eType == 4) {
        pEntry = (nIndex < pData->m_unk24) ? pData->m_unk28[nIndex] : 0;
        if (pEntry == 0) {
            printf("\n **** Bogus texture resource data! Resource ID = %d, Index = %d **** \n", uFlags, nIndex);
        }
        if (pEntry == 0) {
            CdsAssert("PResourceManager.cpp", 0x52F, "apResource");
        }
        return (PMNode *)pEntry;
    }
    if (eType == 3) {
        pEntry = (nIndex < pData->m_unk18) ? (void *)&pData->m_unk1C[nIndex] : 0;
        if (pEntry == 0) {
            printf("\n **** Bogus FX resource data! Resource ID = %d, Index = %d **** \n", uFlags, nIndex);
        }
        if (pEntry == 0) {
            CdsAssert("PResourceManager.cpp", 0x541, "apResource");
        }
        return (PMNode *)pEntry;
    }
    if (eType == 7) {
        pEntry = (nIndex < pData->m_unk30) ? (void *)pData->m_unk34[nIndex] : 0;
        if (pEntry != 0) {
            if (bFlag) {
                return (PMNode *)pEntry;
            }
            pNew = __nw__FUi(0x1C);
            if (pNew) {
                return (PMNode *)__ct__13PShadowVolumeFP13PShadowVolume(pNew, pEntry);
            }
            return 0;
        }
        printf("\n **** Bogus Shadow Volume resource data! Resource ID = %d, Index = %d **** \n", uFlags, nIndex);
        return 0;
    }
    if (eType == 6) {
        pEntry = (nIndex < pData->m_unk3C) ? pData->m_unk40[nIndex] : 0;
        if (pEntry != 0) {
            return (PMNode *)pEntry;
        }
        printf("\n **** Bogus Instance Mesh resource data! Resource ID = %d, Index = %d **** \n", uFlags, nIndex);
        return 0;
    }
    return 0;
}

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

// DRAFT: 0x00152F90 Unload__16PResourceManagerFPQ216PResourceManager15tagResourceData
// note: 23 differing words; remaining diffs are loop-entry b targets, inner null-test beqz shape, per-slot store order in the m_unk4/m_unk10/m_unk28/m_unk34/m_unk40 walks, and s1/s3 init order. Tried: offset form for m_unk1C, store-inside-if for m_unk44/m_unk8/m_unk14, pFx before nOff, while vs for.
void PResourceManager::Unload(tagResourceData *pData) {
    unsigned int i;
    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0x3A2, "pResData");
    }
    if (pData->m_unk67 != 0) {
        UnloadDynamicTextures__15PTextureManagerF13eTextureGroup(gGfxEng + 0x154C90, 0x68);
        MemMgr.DeletePoolContents(2);
        memset(pData, 0, 0x68);
        return;
    }
    if (pData->m_unk4 != 0) {
        for (i = 0; i < (unsigned int)pData->m_unk0; i++) {
            PResourceElem *pElem = (PResourceElem *)pData->m_unk4[i];
            if (pElem != 0) {
                if (pElem->m_unk4 == 1) {
                    if (pElem != 0) pElem->Release(1);
                } else if (pElem->m_unk4 == 2) {
                    if (pElem != 0) pElem->Release(1);
                } else {
                    if (pElem != 0) pElem->Release(1);
                }
            }
            pData->m_unk4[i] = 0;
        }
        __dla__FPv(pData->m_unk4);
        pData->m_unk4 = 0;
        pData->m_unk0 = 0;
    }
    if (pData->m_unk8 != 0) {
        __dla__FPv(pData->m_unk8);
        pData->m_unk8 = 0;
    }
    if (pData->m_unk10 != 0) {
        for (i = 0; i < (unsigned int)pData->m_unkC; i++) {
            PResourceElem *pElem = (PResourceElem *)pData->m_unk10[i];
            if (pElem != 0) {
                if (pElem->m_unk4 == 5) {
                    if (pElem != 0) pElem->Release(1);
                } else {
                    if (pElem != 0) pElem->Release(1);
                }
            }
            pData->m_unk10[i] = 0;
        }
        __dla__FPv(pData->m_unk10);
        pData->m_unk10 = 0;
        pData->m_unkC = 0;
    }
    if (pData->m_unk14 != 0) {
        __dla__FPv(pData->m_unk14);
        pData->m_unk14 = 0;
    }
    if (pData->m_unk28 != 0) {
        for (i = 0; i < (unsigned int)pData->m_unk24; i++) {
            unsigned int nHandle = (unsigned int)pData->m_unk28[i];
            if (nHandle != 0) {
                UnloadDynamicTexture__15PTextureManagerFi(gGfxEng + 0x154C90, (int)nHandle);
            }
            pData->m_unk28[i] = 0;
        }
        __dla__FPv(pData->m_unk28);
        pData->m_unk28 = 0;
        pData->m_unk24 = 0;
    }
    if (pData->m_unk2C != 0) {
        __dla__FPv(pData->m_unk2C);
    }
    pData->m_unk2C = 0;
    if (pData->m_unk1C != 0) {
        tagFxData *pFx;
        unsigned int nOff = 0;
        for (i = 0; i < (unsigned int)pData->m_unk18; i++) {
            pFx = (tagFxData *)((char *)pData->m_unk1C + nOff);
            if (pFx == 0) {
                CdsAssert("PResourceManager.cpp", 0x41B, "apFxData");
            }
            if (pFx->m_unk38 != 0) {
                __dl__FPv(pFx->m_unk38);
            }
            nOff += 0x3C;
        }
        __dla__FPv(pData->m_unk1C);
        pData->m_unk1C = 0;
        pData->m_unk18 = 0;
    }
    if (pData->m_unk20 != 0) {
        __dla__FPv(pData->m_unk20);
    }
    pData->m_unk20 = 0;
    if (pData->m_unk34 != 0) {
        for (i = 0; i < (unsigned int)pData->m_unk30; i++) {
            void *pElem = (void *)pData->m_unk34[i];
            if (pElem != 0) {
                __dt__13PShadowVolumeFv(pElem, 1);
            }
        }
        __dla__FPv(pData->m_unk34);
        pData->m_unk34 = 0;
        pData->m_unk30 = 0;
    }
    if (pData->m_unk38 != 0) {
        __dla__FPv(pData->m_unk38);
    }
    pData->m_unk38 = 0;
    if (pData->m_unk40 != 0) {
        for (i = 0; i < (unsigned int)pData->m_unk3C; i++) {
            void *pElem = (void *)pData->m_unk40[i];
            if (pElem != 0) {
                __dt__19PStaticInstanceMeshFv(pElem, 1);
            }
        }
        __dla__FPv(pData->m_unk40);
        pData->m_unk40 = 0;
        pData->m_unk3C = 0;
    }
    if (pData->m_unk44 != 0) {
        __dla__FPv(pData->m_unk44);
        pData->m_unk44 = 0;
    }
    memset(pData, 0, 0x68);
}

// FUNCTION: 0x00153A40 LoadInstanceMeshTable__16PResourceManagerFP8PPakFilePQ216PResourceManager15tagResourceDataP6PArray16ePsx2FileVersionUi
int PResourceManager::LoadInstanceMeshTable(PPakFile *pFile, tagResourceData *pData, PArray *pArray, ePsx2FileVersion eVersion, unsigned int uId) {
    unsigned int nCount;
    if (pFile == 0) {
        CdsAssert("PResourceManager.cpp", 0x27B, "poFile");
    }
    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0x27C, "pTheResData");
    }
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    pData->m_unk3C = nCount;
    if (nCount == 0) {
        pData->m_unk44 = 0;
        pData->m_unk40 = 0;
        return 1;
    }
    if (uId >= 0x20009) {
        pData->m_unk44 = (unsigned int *)__nwa__FUi(nCount * 4);
        if (pData->m_unk44 == 0) {
            return 0;
        }
        if (((PCDFile *)pFile)->Read(pData->m_unk44, nCount * 4) != (int)(nCount * 4)) {
            return 0;
        }
    }
    pData->m_unk40 = (void **)__nwa__FUi(nCount * 4);
    if (pData->m_unk40 == 0) {
        return 0;
    }
    for (unsigned int i = 0; i < nCount; i++) {
        PStaticInstanceMesh *p = new PStaticInstanceMesh();
        if (p == 0) {
            return 0;
        }
        char buf[0x18];
        if (((PCDFile *)pFile)->Read(buf, 0x18) != 0x18) {
            return 0;
        }
        if (p->Load(pFile, pArray, eVersion) == 0) {
            delete p;
            return 0;
        }
        ((PStaticInstanceMesh **)pData->m_unk40)[i] = p;
    }
    return 1;
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

// FUNCTION: 0x00153E20 LoadAnimResTable__16PResourceManagerFP8PPakFile16ePsx2FileVersionPQ216PResourceManager15tagResourceDataUi
int PResourceManager::LoadAnimResTable(PPakFile *pFile, ePsx2FileVersion eVersion, tagResourceData *pData, unsigned int uId) {
    unsigned int nCount;
    if (pFile == 0) {
        CdsAssert("PResourceManager.cpp", 0x1BE, "poFile");
    }
    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0x1BF, "pTheResData");
    }
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    pData->m_unkC = nCount;
    if (nCount == 0) {
        pData->m_unk14 = 0;
        pData->m_unk10 = 0;
        return 1;
    }
    if (uId >= 0x20009) {
        pData->m_unk14 = (unsigned int *)__nwa__FUi(nCount * 4);
        if (pData->m_unk14 == 0) {
            return 0;
        }
        if (((PCDFile *)pFile)->Read(pData->m_unk14, nCount * 4) != (int)(nCount * 4)) {
            return 0;
        }
    }
    pData->m_unk10 = (void **)__nwa__FUi(nCount * 4);
    if (pData->m_unk10 == 0) {
        return 0;
    }
    for (unsigned int i = 0; i < nCount; i++) {
        unsigned int nRecord = 0;
        if (((PCDFile *)pFile)->Read(&nRecord, 4) != 4) {
            return 0;
        }
        if (nRecord == 0xA) {
            void *p = __nw__FUi(0x30);
            if (p != 0) {
                p = __ct__22PMeshNodeAnimDataTableFv(p);
            }
            if (p == 0) {
                return 0;
            }
            if (!Load__22PMeshNodeAnimDataTableFP8PPakFile16ePsx2FileVersion(p, pFile, eVersion)) {
                printf("\n**** Error loading MEA resource! Index = %d **** \n", i);
                delete (PMeshNodeAnimDataTable *)p;
                return 0;
            }
            pData->m_unk10[i] = p;
        } else {
            CdsAssert("PResourceManager.cpp", 0x225, "0");
            return 0;
        }
    }
    return 1;
}

// FUNCTION: 0x00154070 LoadMeshResTable__16PResourceManagerFP8PPakFileP6PArray16ePsx2FileVersionPQ216PResourceManager15tagResourceDataUi
int PResourceManager::LoadMeshResTable(PPakFile *pFile, PArray *pArray, ePsx2FileVersion eVersion, tagResourceData *pData, unsigned int uId) {
    unsigned int nCount;
    if (pFile == 0) {
        CdsAssert("PResourceManager.cpp", 0x143, "poFile");
    }
    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0x144, "pTheResData");
    }
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    pData->m_unk0 = nCount;
    if (nCount == 0) {
        pData->m_unk8 = 0;
        pData->m_unk4 = 0;
        return 1;
    }
    if (uId >= 0x20009) {
        pData->m_unk8 = (unsigned int *)__nwa__FUi(nCount * 4);
        if (pData->m_unk8 == 0) {
            return 0;
        }
        if (((PCDFile *)pFile)->Read(pData->m_unk8, nCount * 4) != (int)(nCount * 4)) {
            return 0;
        }
    }
    pData->m_unk4 = (void **)__nwa__FUi(nCount * 4);
    if (pData->m_unk4 == 0) {
        return 0;
    }
    for (unsigned int i = 0; i < nCount; i++) {
        int nType = 0;
        if (((PCDFile *)pFile)->Read(&nType, 4) != 4) {
            return 0;
        }
        if (nType == 1) {
            void *p = __nw__FUi(0x140);
            if (p != 0) {
                p = __ct__9PMeshNodeFQ29PResource11eResObjType(p, 1);
            }
            if (p == 0) {
                return 0;
            }
            if (!Load__9PMeshNodeFP8PPakFileP6PArray16ePsx2FileVersion(p, pFile, pArray, eVersion)) {
                printf("\n**** Error loading mesh resource! Index = %d **** \n", i);
                delete (PMeshNodeAnimDataTable *)p;
                return 0;
            }
            pData->m_unk4[i] = p;
        } else if (nType == 6) {
            void *p = __nw__FUi(0x160);
            if (p != 0) {
                p = __ct__9PSkeletonFQ29PResource11eResObjType(p, 2);
            }
            if (p == 0) {
                return 0;
            }
            if (!Load__9PSkeletonFP8PPakFileP6PArray16ePsx2FileVersion(p, pFile, pArray, eVersion)) {
                printf("\n**** Error loading mesh resource! Index = %d **** \n", i);
                delete (PMeshNodeAnimDataTable *)p;
                return 0;
            }
            pData->m_unk4[i] = p;
        } else {
            CdsAssert("PResourceManager.cpp", 0x1A7, "0");
            return 0;
        }
        guGlobalShaderIDOffset += guNumShadersInCurModel;
        guNumShadersInCurModel = 0;
    }
    return 1;
}

// FUNCTION: 0x00154390 LoadTextureResTable__16PResourceManagerFP8PPakFileP6PArrayPQ216PResourceManager15tagResourceDataUi
int PResourceManager::LoadTextureResTable(PPakFile *pFile, PArray *pArray, tagResourceData *pData, unsigned int uId) {
    unsigned int nCount;
    int nIndex = -1;
    if (pFile == 0) {
        CdsAssert("PResourceManager.cpp", 0xF2, "poFile");
    }
    if (pArray == 0) {
        CdsAssert("PResourceManager.cpp", 0xF3, "poTextureHandles");
    }
    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0xF4, "pTheResData");
    }
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    pData->m_unk24 = nCount;
    if (pData->m_unk24 == 0) {
        pData->m_unk28 = 0;
        pData->m_unk2C = 0;
        return 1;
    }
    if (uId >= 0x20009) {
        pData->m_unk2C = (unsigned int *)__nwa__FUi(nCount * 4);
        if (pData->m_unk2C == 0) {
            return 0;
        }
        if (((PCDFile *)pFile)->Read(pData->m_unk2C, nCount * 4) != (int)(nCount * 4)) {
            return 0;
        }
    }
    pData->m_unk28 = (void **)__nwa__FUi(nCount * 4);
    if (pData->m_unk28 == 0) {
        return 0;
    }
    for (unsigned int i = 0; i < nCount; i++) {
        if (((PCDFile *)pFile)->Read(&nIndex, 4) != 4) {
            return 0;
        }
        if (nIndex < 0) {
            return 0;
        }
        pData->m_unk28[i] = (nIndex < pArray->m_unk0) ? pArray->m_unk8[nIndex] : 0;
        if (pData->m_unk28[i] == 0) {
            return 0;
        }
        nIndex = -1;
    }
    return 1;
}

// note: 39 words differ. The first is the return-0 branch at 0x0A8 (2 words longer in ours, from the shared epilogue layout); the loop tail is laid out differently. Tried: local nIdx, swapped compare, ternary temp, while loop, zero-then-if store (fx_v2..fx_v6 in scratch).
// DRAFT: 0x001545B0 LoadFxResTable__16PResourceManagerFP8PPakFileP6PArrayPQ216PResourceManager15tagResourceDataUi
int PResourceManager::LoadFxResTable(PPakFile *pFile, PArray *pArray, tagResourceData *pData, unsigned int uId) {
    unsigned int nCount;
    unsigned int i;
    unsigned int nIdx;
    unsigned int nRes;
    tagFxData *pFx;
    if (pFile == 0) {
        CdsAssert("PResourceManager.cpp", 0x9C, "poFile");
    }
    if (pArray == 0) {
        CdsAssert("PResourceManager.cpp", 0x9D, "poTextureHandles");
    }
    if (pData == 0) {
        CdsAssert("PResourceManager.cpp", 0x9E, "pTheResData");
    }
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    pData->m_unk18 = nCount;
    if (pData->m_unk18 == 0) {
        pData->m_unk1C = 0;
        pData->m_unk20 = 0;
        return 1;
    }
    if (uId >= 0x20009) {
        pData->m_unk20 = (unsigned int *)__nwa__FUi(nCount * 4);
        if (pData->m_unk20 == 0) {
            return 0;
        }
        if (((PCDFile *)pFile)->Read(pData->m_unk20, nCount * 4) != (int)(nCount * 4)) {
            return 0;
        }
    }
    pData->m_unk1C = (tagFxData *)__nwa__FUi(nCount * 0x3C);
    if (pData->m_unk1C == 0) {
        return 0;
    }
    i = 0;
    while (i < nCount) {
        pFx = &pData->m_unk1C[i];
        if (((PCDFile *)pFile)->Read(pFx, 0x38) != 0x38) {
            return 0;
        }
        if (pFx->m_unk24 == 0) {
            return 0;
        }
        pFx->m_unk38 = __nwa__FUi(pFx->m_unk24);
        if (pFx->m_unk38 == 0) {
            CdsAssert("PResourceManager.cpp", 0xD6, "apFxData->pvFxParams");
        }
        if (((PCDFile *)pFile)->Read(pFx->m_unk38, pFx->m_unk24) != (int)pFx->m_unk24) {
            return 0;
        }
        nIdx = pFx->m_unk20;
        nRes = 0;
        if (nIdx < pArray->m_unk0) {
            nRes = (unsigned int)pArray->m_unk8[nIdx];
        }
        pFx->m_unk20 = nRes;
        i++;
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
