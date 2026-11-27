// FLAGS: -str readonly
#pragma opt_strength_reduction off
#include "PWorld.h"
#include "Debug.h"
#include "PArray.h"

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("PWorld.cpp", line, #cond))

// TODO(header): foreign declarations
class PLightManager;
class PMat4;
class PPakFile;
struct tagProceduralTextureData {
    int _pad[0x10];
};

class PSpacePartitionTree {
public:
    void CullToFrustrum(PFrustrum *pFrustrum, float *pOut);
    int Render(PLightManager *pLight, PMat4 *pMat, bool bFlag);
};

class PMeshNode {
public:
    void TestMeshNodeInFrustum(PFrustrum *pFrustrum);
};

class PCutScenePlayer {
public:
    void CullTest(PFrustrum *pFrustrum);
    void Render(PLightManager *pLight);
    void GetViewMatrix(PMat4 *pMat);
    int Animate(float fStep);
};

class PSpacePartitionNode {
public:
    void Animate(float fStep);
};

// Object reached through PWorld's offset 0 pointer; Render is at vtable offset 0xC.
class PRenderHook {
public:
    virtual void Slot0();
    virtual int Render(int nA, int nB, int nC);
};

// PMNode vtable view: Animate sits at vtable offset 0x18, which is virtual index 4.
class PMNodeVirtual {
public:
    virtual void Slot0(int nFlag);
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Animate(float fA, float fB, PMat4 *pMat, int nFlag, bool bFlag);
};

class PCDFile {
public:
    int Read(void *pBuf, unsigned int nSize);
    int Close();
};

struct tagParticleFxTrigger;

struct tagParticleFxTriggerData {
    unsigned int m_nId;     // 0x00
    char m_Trigger[0x28];   // 0x04, tagParticleFxTrigger
};

struct PNodeAnim {
    char _pad00[4];
    int m_04;
};

class PMNode {
public:
    char _pad00[0x0C];
    void *m_0C;             // 0x0C
    char _pad10[0x24 - 0x10];
    PNodeAnim *m_24;        // 0x24
    char _pad28[0x2C - 0x28];
    float m_2C;             // 0x2C
    char _pad30[0x3E - 0x30];
    unsigned char m_3E;     // 0x3E
    signed char m_3F;       // 0x3F
    int Find(PMNode *pNode);
    PMNode *Find(unsigned int nId);
    int AddFxTrigger(tagParticleFxTrigger *pTrigger, bool bFlag);
};

struct PNodeList {
    unsigned int m_nCount;
    unsigned int m_nIndex;
    PMNode **m_ppNodes;
};

struct PNodeTable {
    char _pad00[0x14];
    PNodeList m_list;
};

extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dla__FPv(void *pMem);

class PGfxEngine {
public:
    void RefreshDisplay();
    void SetScreenMatrix(PMat4 *pMat);
    int Init(short nWidth, short nHeight, short a2, short nTvMode, short a4, short a5, int a6, int a7);
    char _pad000[0x10];
};

class PShadowBuffer {
public:
    void SetZBufferRange(float fNear, float fFar);
};

class PMat4 {
public:
    void MakeScreenMatrix2(float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7);
    void MakeMayaProjectionMatrix(float f0, float f1, float f2, float f3, float f4, float f5);
};

extern "C" int printf(const char *fmt, ...);
void FastMath_Setup();
extern PGfxEngine gGfxEng;
extern float XY_ASPECT;
extern unsigned char MODE_PAL;
extern short SCREEN_WIDTH;
extern short SCREEN_HEIGHT;
extern short TV_MODE;
extern float Y_ASPECT;
extern float FOV_Y;
struct PClipVolume {
    float unk0;
    float unk4;
    char _pad08[0x10];
};
extern PClipVolume clip_volume;
void vu1SetScreenMatrix(PMat4 *pMat);
void vu1SetViewMatrix(PMat4 *pMat);
void vu1SetClipMatrix(PMat4 *pMat);
extern "C" void sceVu0UnitMatrix(void *pMat);
class Camera {
public:
    void SetPosAndRot(float (*pPos)[4], float (*pRot)[4]);
};
extern unsigned char gEng[0x1A000];
extern "C" void __dl__FPv(void *pMem);
extern "C" void scePcStart(int nMode, int nA, int nB);
extern "C" void __destroy_arr(void *pBlock, void *(*pDtor)(void *, short), int nSize, int nCount);
extern "C" void *__dt__11PFogTextureFv(void *pThis, short nFlag);
extern "C" void *__dt__12PFireTextureFv(void *pThis, short nFlag);
extern "C" void *__dt__11PGasTextureFv(void *pThis, short nFlag);
extern "C" void *__dt__13PWaterTextureFv(void *pThis, short nFlag);
extern "C" void *__dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void *__dt__11PZBufferFogFv(void *pThis, short nFlag);
extern "C" void *__dt__15PCutScenePlayerFv(void *pThis, short nFlag);
extern "C" void *__dt__13PLightManagerFv(void *pThis, short nFlag);
extern "C" void *__dt__9PFrustrumFv(void *pThis, short nFlag);
extern "C" void *__dt__19PSpacePartitionTreeFv(void *pThis, short nFlag);
extern "C" void *__dt__19PStaticInstanceMeshFv(void *pThis, short nFlag);
extern "C" void Unload__15PCutScenePlayerFb(void *pThis, bool bFlag);
extern "C" void DestroyFxTriggers__6PMNodeFbbb(void *pThis, bool bA, bool bB, bool bC);
extern "C" void DestroyAllStaticLights__13PLightManagerFv(void *pThis);
extern "C" void DestroyAllDynamicLights__13PLightManagerFv(void *pThis);
extern "C" void Reset__13PWaterTextureFv(void *pThis);
extern "C" void Reset__11PGasTextureFv(void *pThis);
extern "C" void Reset__12PFireTextureFv(void *pThis);
extern "C" void Reset__11PFogTextureFv(void *pThis);
extern "C" void Update__13PWaterTextureFv(void *pThis);
extern "C" void Update__11PGasTextureFv(void *pThis);
extern "C" void Update__12PFireTextureFv(void *pThis);
extern "C" void Update__11PFogTextureFv(void *pThis);
extern "C" void RemoveAllParticleSystems__16PParticleManagerF8ePSLayer(void *pThis, int nLayer);
extern unsigned char gInterface[0x300];
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__19PStaticInstanceMeshFv(void *pThis);
extern "C" void *__ct__9PFrustrumFv(void *pThis);
extern "C" void *__ct__13PLightManagerFv(void *pThis);
extern "C" void *__ct__15PCutScenePlayerFv(void *pThis);
extern "C" void *__ct__11PZBufferFogFv(void *pThis);
extern "C" void *__ct__6PArrayFv(void *pThis);
extern "C" char __vt__9PResource[];
extern "C" char __vt__6PMNode[];
extern "C" char __vt__9PMeshNode[];
extern "C" void InitMembers__6PMNodeFv(void *pThis);
extern "C" void InitMembers__9PMeshNodeFv(void *pThis);
extern "C" int Load__9PMeshNodeFP8PPakFileP6PArray16ePsx2FileVersion(void *pThis, PPakFile *pFile, PArray *pArr, ePsx2FileVersion nVersion);
extern "C" void *__ct__13PWaterTextureFv(void *pThis);
extern "C" void *__ct__11PGasTextureFv(void *pThis);
extern "C" void *__ct__12PFireTextureFv(void *pThis);
extern "C" void *__ct__11PFogTextureFv(void *pThis);
extern "C" void __construct_array(void *pBlock, void *(*pCtor)(void *), void *(*pDtor)(void *, short), int nSize, int nCount);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nCount);
extern "C" int Load__19PStaticInstanceMeshFP8PPakFileP6PArray16ePsx2FileVersion(void *pThis, PPakFile *pFile, PArray *pArray, ePsx2FileVersion nVersion);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
extern "C" void AddMasterParticleInstance__16PParticleManagerFP15PParticleSystem(void *pThis, void *pSystem);
extern char gPFile[0x10080];
extern int mstuLoadVersion__6PWorld;
extern "C" PPakFile *GetData__8PPakFileFPCc(void *pThis, const char *pFileName);
extern "C" int IsValidFileType__8PPakFileFi(void *pThis, int nType);
extern "C" int LoadStaticTextures__15PTextureManagerFP8PPakFile13eTextureGroupP6PArray(void *pThis, PPakFile *pFile, eTextureGroup eGroup, PArray *pArr);
extern "C" int LoadDynamicTextures__15PTextureManagerFP8PPakFile13eTextureGroupP6PArray(void *pThis, PPakFile *pFile, eTextureGroup eGroup, PArray *pArr);
extern "C" int Init__13PWaterTextureFP24tagProceduralTextureDataP6PArray(void *pThis, tagProceduralTextureData *pData, PArray *pArr);
extern "C" int Init__11PGasTextureFP24tagProceduralTextureDataP6PArray(void *pThis, tagProceduralTextureData *pData, PArray *pArr);
extern "C" int Init__12PFireTextureFP24tagProceduralTextureDataP6PArray(void *pThis, tagProceduralTextureData *pData, PArray *pArr);
extern "C" int Init__11PFogTextureFP24tagProceduralTextureDataP6PArray(void *pThis, tagProceduralTextureData *pData, PArray *pArr);
extern "C" int Load__13PLightManagerFP8PPakFile(void *pThis, PPakFile *pFile);
extern "C" void *__ct__19PSpacePartitionTreeFv(void *pThis);
extern "C" int Load__19PSpacePartitionTreeFP8PPakFileP6PArrayP6PArray16ePsx2FileVersion(void *pThis, PPakFile *pFile, PArray *pArr, PArray *pArr2, ePsx2FileVersion nVersion);
extern "C" int LoadFogObjects__16PParticleManagerFP8PPakFile16ePsx2FileVersion(void *pThis, PPakFile *pFile, ePsx2FileVersion nVersion);
extern "C" void RecurseSetSTAnimOptions__6PMNodeFb(void *pThis, bool bFlag);
extern "C" void RecurseSetSTAnimOptions__19PSpacePartitionNodeFb(void *pThis, bool bFlag);
extern "C" void ProcessFxTriggers__6PMNodeFfP5PMat4bb(void *pThis, float fStep, PMat4 *pMat, bool bA, bool bB);
extern "C" void Init__11PZBufferFogFv(void *pThis);
extern "C" char *strcpy(char *pDst, const char *pSrc);

// FUNCTION: 0x19A680 CullMainWorld__6PWorldFv
void PWorld::CullMainWorld() {
    if (m_pSpacePartitionTree != 0) {
        m_pSpacePartitionTree->CullToFrustrum(&m_Frustrum, m_Vec);
    }
    if (m_8720 != 0) {
        ((PCutScenePlayer *)((char *)this + m_8724 * 0x2140 + 0x220))->CullTest(&m_Frustrum);
    } else if (m_pMeshNode != 0) {
        m_pMeshNode->TestMeshNodeInFrustum(&m_Frustrum);
    }
    m_bCulled = 1;
}

// FUNCTION: 0x19A730 InitFrustrum__6PWorldFP5PMat4PA4_f
void PWorld::InitFrustrum(PMat4 *pMat, float (*pVec)[4]) {
    *(u_long128 *)m_Vec = *(u_long128 *)pVec;
    sceVu0CopyMatrix(m_Mat, (float(*)[4])pMat);
    m_Frustrum.Init(m_Persp[0], m_Persp[1], m_Persp[2], m_Persp[3], pMat, pVec);
    m_bCulled = 0;
}

// DRAFT: 0x19A7B0 LoadMeshNodeHierarchy__6PWorldFP8PPakFileP6PArray16ePsx2FileVersion
// note: 7 words: PMNode vtable lui hoisted above the pMeshV/pNodeV spills in the original; ours places it after the __vt__9PResource store. Tried: store via apMeshNode, unsigned char locals, flat volatile decls, (char *)__vt__6PMNode cast (7), (char *)__vt__9PResource cast (7).
PMeshNode *PWorld::LoadMeshNodeHierarchy(PPakFile *pFile, PArray *pArr, ePsx2FileVersion nVersion) {
    int nTop;
    PMeshNode *apMeshNode;
    char *pRaw;
    char *pNode;
    char *pMesh;

    (void)((pFile != 0) ? (void)0 : CdsAssert("PWorld.cpp", 0x390, (char *)"poFile"));
    (void)((pArr != 0) ? (void)0 : CdsAssert("PWorld.cpp", 0x391, (char *)"poTextureHandles"));
    nTop = 1;
    if ((apMeshNode = (PMeshNode *)__nw__FUi(0x140)) != 0) {
        pRaw = (char *)apMeshNode;
        char *volatile pMeshV = pRaw;
        {
            char *volatile pNodeV = pRaw;
            *(char **)pRaw = __vt__9PResource;
            *(int *)(pNodeV + 4) = 0;
            *(char **)pNodeV = __vt__6PMNode;
            __ct__6PArrayFv(pNodeV + 0x14);
            sceVu0UnitMatrix((float (*)[4])(pNodeV + 0x40));
            __ct__6PArrayFv(pNodeV + 0xD8);
            InitMembers__6PMNodeFv(pNodeV);
        }
        *(char **)pMeshV = __vt__9PMeshNode;
        __ct__6PArrayFv(pMeshV + 0x130);
        InitMembers__9PMeshNodeFv((PMeshNode *)pMeshV);
        apMeshNode = (PMeshNode *)pMeshV;
    }
    if (apMeshNode == 0) {
        CdsAssert("PWorld.cpp", 0x397, "apMeshNode");
    }
    if (Load__9PMeshNodeFP8PPakFileP6PArray16ePsx2FileVersion(apMeshNode, pFile, pArr, nVersion) == 0) {
        if (apMeshNode != 0) {
            ((PMNodeVirtual *)apMeshNode)->Slot0(1);
        }
        return 0;
    }
    nTop = 0;
    if (((PCDFile *)pFile)->Read(&nTop, 4) != 4) {
        return 0;
    }
    if (nTop != 3) {
        (!"There's multiple top node in dbf\n") ? (void)0 : CdsAssert("PWorld.cpp", 0x3A8, (char *)"!\"There's multiple top node in dbf\\n\"");
    }
    ((PMNodeVirtual *)apMeshNode)->Animate(0.0f, 0.0f, 0, 0, false);
    return apMeshNode;
}

// FUNCTION: 0x19A9B0 LoadEditedInstanceData__6PWorldFP8PPakFile
int PWorld::LoadEditedInstanceData(PPakFile *pFile) {
    char buf[0x140];

    if (pFile == 0) {
        CdsAssert("PWorld.cpp", 0x35D, "poFile");
    }
    if (((PCDFile *)pFile)->Read(buf, 0x140) != 0x140) {
        return 0;
    }
    return 1;
}

// FUNCTION: 0x19AA20 AttachFxTriggersToNodes__6PWorldFP9PMeshNodeP24tagParticleFxTriggerDataUi
void PWorld::AttachFxTriggersToNodes(PMeshNode *pNode, tagParticleFxTriggerData *pData, unsigned int nCount) {
    if (pData == 0) {
        CdsAssert("PWorld.cpp", 0x341, "pTriggerTable");
    }
    if (nCount == 0) {
        CdsAssert("PWorld.cpp", 0x342, "uNumTriggers");
    }
    if (pNode == 0) {
        CdsAssert("PWorld.cpp", 0x343, "poRootNode");
    }
    unsigned int i = 0;
    if (i < nCount) {
        unsigned int nOffset = 0;
        do {
            tagParticleFxTriggerData *pEntry = (tagParticleFxTriggerData *)((char *)pData + nOffset);
            PMNode *pTarget = ((PMNode *)pNode)->Find(pEntry->m_nId);
            if (pTarget != 0) {
                pTarget->AddFxTrigger((tagParticleFxTrigger *)pEntry->m_Trigger, false);
            } else {
                ((PMNode *)pNode)->AddFxTrigger((tagParticleFxTrigger *)pEntry->m_Trigger, false);
            }
            nOffset += 0x2C;
        } while (++i < nCount);
    }
}

// FUNCTION: 0x19AB30 LoadFxTriggerData__6PWorldFP8PPakFilePP24tagParticleFxTriggerDataRUi
int PWorld::LoadFxTriggerData(PPakFile *pFile, tagParticleFxTriggerData **ppData, unsigned int &nCount) {
    unsigned int nNum;

    if (pFile == 0) {
        CdsAssert("PWorld.cpp", 0x321, "poFile");
    }
    nCount = 0;
    if (((PCDFile *)pFile)->Read(&nNum, 4) != 4) {
        return 0;
    }
    if (nNum != 0) {
        *ppData = (tagParticleFxTriggerData *)__nwa__FUi(nNum * 0x2C);
        if (ppData == 0) {
            CdsAssert("PWorld.cpp", 0x32E, "ppTriggerTable");
        }
        unsigned int nSize = nNum * 0x2C;
        if (((PCDFile *)pFile)->Read(*ppData, nSize) != (int)nSize) {
            __dla__FPv(*ppData);
            *ppData = 0;
            return 0;
        }
    }
    nCount = nNum;
    return 1;
}

// FUNCTION: 0x19AC40 CleanupStaticInstanceMeshes__6PWorldFv
void PWorld::CleanupStaticInstanceMeshes() {
    unsigned int n;
    unsigned int i;
    PStaticInstanceMesh *p;
    char *pGfx;

    n = m_9FB0;
    for (i = 0; i < n; i++) {
        p = (PStaticInstanceMesh *)((i < m_9FB0) ? m_9FB8[i] : 0);
        if (p) {
            __dt__19PStaticInstanceMeshFv(p, 1);
        }
    }
    if (m_9FB8) {
        m_9FB0 = 0;
        m_9FB4 = 0;
    }
    pGfx = (char *)((int)&gGfxEng + 0x154F00);
    if (*(int *)(pGfx + 0x2070)) {
        *(int *)(pGfx + 0x2068) = 0;
        *(int *)(pGfx + 0x206C) = 0;
    }
    pGfx = (char *)&gGfxEng + 0x154F00;
    if (*(int *)(pGfx + 0x2080)) {
        *(int *)(pGfx + 0x2078) = 0;
        *(int *)(pGfx + 0x207C) = 0;
    }
}

// FUNCTION: 0x19AD50 LoadStaticInstanceMeshes__6PWorldFP8PPakFileP6PArray16ePsx2FileVersion
int PWorld::LoadStaticInstanceMeshes(PPakFile *pFile, PArray *pArray, ePsx2FileVersion nVersion) {
    PStaticInstanceMesh *pMesh;
    char aHeader[0x18];
    unsigned int i;
    void *pSystem;

    if (((PCDFile *)pFile)->Read(aHeader, 0x18) != 0x18) {
        return 0;
    }
    for (i = 0; i < *(unsigned int *)aHeader; i++) {
        pMesh = (PStaticInstanceMesh *)__nw__FUi(0x14);
        if (pMesh) {
            pMesh = (PStaticInstanceMesh *)__ct__19PStaticInstanceMeshFv(pMesh);
        }
        if (!pMesh) {
            CdsAssert("PWorld.cpp", 0x2F7, (char *)"apMesh");
        }
        if (Load__19PStaticInstanceMeshFP8PPakFileP6PArray16ePsx2FileVersion(pMesh, pFile, pArray, nVersion) == 0) {
            return 0;
        }
        Add__6PArrayFPv(&m_9FB0, pMesh);
        pSystem = *(void **)((char *)pMesh + 0x10);
        if (pSystem) {
            AddMasterParticleInstance__16PParticleManagerFP15PParticleSystem((char *)&gGfxEng + 0x154F00, pSystem);
        }
    }
    return 1;
}

// FUNCTION: 0x19AE80 RenderWorld__6PWorldFv
void PWorld::RenderWorld() {
    if (m_pSpacePartitionTree != 0) {
        m_8748 += m_pSpacePartitionTree->Render((PLightManager *)((char *)this + 0x1F0), (PMat4 *)((char *)m_pMeshNode + 0x40), m_1ED);
    }
    if (m_8720 != 0) {
        ((PCutScenePlayer *)((char *)this + m_8724 * 0x2140 + 0x220))->Render((PLightManager *)((char *)this + 0x1F0));
        return;
    }
    if (m_pMeshNode != 0) {
        m_8748 += ((PRenderHook *)m_pMeshNode)->Render(0, 0x80, 0);
    }
}

// DRAFT: 0x19AF70 Render__6PWorldFv
// note: DIFF 39; float local array and offset variants tried, shared-local, pRot-first and clamp-rewrite variants gave DIFF 43 and were reverted.
void PWorld::Render() {
    float sp20[4][4];
    float sp60[4][4];
    float fFar;

    if (m_8720 != 0) {
        sceVu0UnitMatrix(sp20);
        ((PCutScenePlayer *)((char *)this + m_8724 * 0x2140 + 0x220))->GetViewMatrix((PMat4 *)sp20);
        InitFrustrum((PMat4 *)sp20, (float (*)[4])((char *)this + m_8724 * 0x2140 + 0x2E0));
        {
            float (*pPos)[4] = (float (*)[4])((char *)this + m_8724 * 0x2140 + 0x220 + 0xC0);
            float (*pRot)[4] = (float (*)[4])((char *)this + m_8724 * 0x2140 + 0x220 + 0xD0);
            ((Camera *)(gEng + 0x19760))->SetPosAndRot(pPos, pRot);
        }
        if (m_bCulled == 0) {
            CullMainWorld();
        }
        sceVu0UnitMatrix(sp60);
        fFar = 4194304.0f + m_9EA0;
        if (fFar >= 1.6777216e7f) {
            fFar = 1.6777216e7f;
        }
        ((PMat4 *)sp60)->MakeMayaProjectionMatrix(2048.0f, 2048.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 100.0f, fFar);
        vu1SetScreenMatrix((PMat4 *)sp60);
        vu1SetViewMatrix((PMat4 *)sp20);
    } else {
        if (m_bCulled == 0) {
            CullMainWorld();
        }
        vu1SetViewMatrix((PMat4 *)m_Mat);
    }
    vu1SetClipMatrix((PMat4 *)&m_50);
    RenderWorld();
}

// FUNCTION: 0x19B130 UpdateAnimate__6PWorldFP6PMNode
void PWorld::UpdateAnimate(PMNode *pNode) {
    PNodeTable *pTable = (PNodeTable *)m_pMeshNode;
    if (pTable != 0) {
        PNodeList *pList;
        pTable->m_list.m_nIndex = 0;
        pList = &pTable->m_list;
        PMNode *pCur = (pList->m_nCount != 0) ? pList->m_ppNodes[0] : 0;
        while (pCur != 0) {
            if ((signed char)(pCur->m_3F & 7) == 0 && pCur->Find(pNode) != 0) {
                pCur->m_3F = 2;
                return;
            }
            unsigned int nIdx = pList->m_nIndex + 1;
            pList->m_nIndex = nIdx;
            pCur = (nIdx < pList->m_nCount) ? pList->m_ppNodes[pList->m_nIndex] : 0;
        }
    }
}

// DRAFT: 0x19B200 Animate__6PWorldFv
// note: DIFF 72; original uses direct branches with one shared call block, ours is bool-free do-while (72) vs bCall (85), goto-label call block and swapped float compare gave no gain; m_0C==0 arm compares nType into v0 vs at and inverts the nType!=0x1F4 test.
void PWorld::Animate() {
    PNodeTable *pTable;
    PNodeList *pList;
    PMNode *pCur;
    int nType;
    bool bCall;

    if (m_8720 != 0) {
        m_8720 = ((PCutScenePlayer *)((char *)this + m_8724 * 0x2140 + 0x220))->Animate(m_1E8) & 7;
    } else {
        pTable = (PNodeTable *)m_pMeshNode;
        if (pTable != 0) {
            pList = &pTable->m_list;
            pList->m_nIndex = 0;
            pCur = 0;
            if (pList->m_nCount != 0) {
                pCur = pList->m_ppNodes[0];
            }
            while (pCur != 0) {
                do {
                    if ((signed char)(pCur->m_3F & 7) == 0 && (pCur->m_3E & 0x18) == 0) {
                        break;
                    }
                    nType = 0;
                    if (pCur->m_24 != 0) {
                        nType = pCur->m_24->m_04;
                    }
                    if (pCur->m_0C == 0) {
                        if (nType < 2) {
                            break;
                        }
                        if (nType == 0x1F4) {
                            break;
                        }
                    } else {
                        if (nType < 0 && pCur->m_2C == 0.0f) {
                            break;
                        }
                    }
                    ((PMNodeVirtual *)pCur)->Animate(0.0f, m_1E8, 0, 0, false);
                } while (0);
                pList->m_nIndex++;
                if (pList->m_nIndex < pList->m_nCount) {
                    pCur = pList->m_ppNodes[pList->m_nIndex];
                } else {
                    pCur = 0;
                }
            }
        }
    }

    if (m_pSpacePartitionTree != 0) {
        PSpacePartitionNode *pRoot = *(PSpacePartitionNode **)m_pSpacePartitionTree;
        pRoot->Animate(0.5f * m_1E8);
    }
    Update__13PWaterTextureFv((char *)this + 0x9FC0);
    Update__11PGasTextureFv((char *)this + 0x12690);
    Update__12PFireTextureFv((char *)this + 0x12C10);
    Update__11PFogTextureFv((char *)this + 0x13210);
}

// DRAFT: 0x19B400 Destroy__6PWorldFv
// note: 69 differing lines; this sits in s0 and the loop counter in s2 (original: s2 and s0); for-loop, comma-increment and declaration-order variants all stay at 69
void PWorld::Destroy() {
    int i;
    int off;

    off = 0;
    for (i = 0; i < 4; i++, off += 0x2140) {
        Unload__15PCutScenePlayerFb((char *)this + off + 0x220, false);
    }
    m_8720 = 0;
    if (m_pSpacePartitionTree) {
        __dt__19PSpacePartitionTreeFv(m_pSpacePartitionTree, 1);
        m_pSpacePartitionTree = 0;
    }
    if (m_pMeshNode) {
        (*(void (**)(void *, int))(*(char **)m_pMeshNode + 8))(m_pMeshNode, 1);
    }
    m_pMeshNode = 0;
    DestroyFxTriggers__6PMNodeFbbb(m_pMeshNode, false, true, true);
    if (*(void **)((char *)this + 4)) {
        if (*(void **)((char *)this + 4)) {
            (*(void (**)(void *, int))(*(char **)((char *)this + 4) + 8))(*(void **)((char *)this + 4), 1);
        }
        *(void **)((char *)this + 4) = 0;
    }
    DestroyAllStaticLights__13PLightManagerFv((char *)this + 0x1F0);
    DestroyAllDynamicLights__13PLightManagerFv((char *)this + 0x1F0);
    m_8728 = 0;
    CleanupStaticInstanceMeshes();
    Reset__13PWaterTextureFv((char *)this + 0x9FC0);
    Reset__11PGasTextureFv((char *)this + 0x12690);
    Reset__12PFireTextureFv((char *)this + 0x12C10);
    Reset__11PFogTextureFv((char *)this + 0x13210);
    (*(void (**)(void *))(*(char **)gInterface + 0xC))(gInterface);
    RemoveAllParticleSystems__16PParticleManagerF8ePSLayer((char *)&gGfxEng + 0x154F00, 2);
    RemoveAllParticleSystems__16PParticleManagerF8ePSLayer((char *)&gGfxEng + 0x154F00, 3);
}

// DRAFT: 0x19B580 Load__6PWorldFPCcb13eTextureGroup
// note: 236 words; prologue order differs (sq s0 before PArray ctor call at 0xA0, zero stores at 0xF0-0xF8). Tried local orders nHeader/spA0/spB0 (242, 236, 242).
PMNode *PWorld::Load(const char *pFileName, bool bFlag, eTextureGroup eGroup) {
    PMeshNode *var_s0;
    PSpacePartitionTree *var_v0;
    PSpacePartitionTree *temp_a0;
    PSpacePartitionTree *temp_a0_2;
    PMeshNode *temp_a0_3;
    PMeshNode *temp_a0_5;
    PSpacePartitionTree *temp_v0_2;
    void *temp_a0_4;
    void *temp_s5;
    tagParticleFxTriggerData *spF4;
    unsigned int spF8;
    int spF0;
    int spFC;
    int nHeader[4];
    PArray spA0;
    tagProceduralTextureData spB0;
    PPakFile *temp_v0;

    var_s0 = 0;
    spF4 = 0;
    spF8 = 0;
    if (pFileName == 0) {
        CdsAssert("PWorld.cpp", 0xEC, "pszWorldFile");
    }
    temp_v0 = GetData__8PPakFileFPCc(&gPFile, pFileName);
    if (temp_v0 == 0) {
        CdsAssert("PWorld.cpp", 0xF1, "aMemFile");
    }
    IsValidFileType__8PPakFileFi(temp_v0, 1);
    if (bFlag != 0) {
        Destroy();
        if (LoadStaticTextures__15PTextureManagerFP8PPakFile13eTextureGroupP6PArray((char *)&gGfxEng + 0x154C90, temp_v0, eGroup, &spA0) == 0) {
            CDS_ASSERT(0xF8, !"Error loading texture file!");
        } else {
            goto block_12;
        }
    } else if (LoadDynamicTextures__15PTextureManagerFP8PPakFile13eTextureGroupP6PArray((char *)&gGfxEng + 0x154C90, temp_v0, eGroup, &spA0) == 0) {
        CDS_ASSERT(0xFF, !"Error loading texture file!");
    } else {
block_12:
        IsValidFileType__8PPakFileFi(temp_v0, 2);
        if (((PCDFile *)temp_v0)->Read(nHeader, 0x10U) != 0x10) {
            CDS_ASSERT(0x10E, !"Error reading world file header!");
        } else if (nHeader[0] != 0x01020304) {
            CDS_ASSERT(0x115, !"World file corrupt. Magic number mismatch!");
        } else {
            mstuLoadVersion__6PWorld = nHeader[1];
            if (nHeader[2] & 0x100) {
                spFC = 0;
                if (((PCDFile *)temp_v0)->Read(&spFC, 4U) != 4) {
                    CDS_ASSERT(0x122, !"Error loading procedural texture data from world file!");
                } else if (spFC == 1) {
                    if (((PCDFile *)temp_v0)->Read(&spB0, 0x40U) != 0x40) {
                        CDS_ASSERT(0x12D, !"Error loading procedural texture data from world file!");
                    } else if (bFlag != 0) {
                        if (Init__13PWaterTextureFP24tagProceduralTextureDataP6PArray((char *)this + 0x9FC0, &spB0, &spA0) == 0) {
                            CDS_ASSERT(0x137, !"Error loading procedural texture data from world file!");
                        } else if (Init__11PGasTextureFP24tagProceduralTextureDataP6PArray((char *)this + 0x12690, &spB0, &spA0) == 0) {
                            CDS_ASSERT(0x13E, !"Error loading procedural texture data from world file!");
                        } else if (Init__12PFireTextureFP24tagProceduralTextureDataP6PArray((char *)this + 0x12C10, &spB0, &spA0) == 0) {
                            CDS_ASSERT(0x145, !"Error loading procedural texture data from world file!");
                        } else if (Init__11PFogTextureFP24tagProceduralTextureDataP6PArray((char *)this + 0x13210, &spB0, &spA0) == 0) {
                            CDS_ASSERT(0x14C, !"Error loading procedural texture data from world file!");
                        } else {
                            *(int *)((char *)&gGfxEng + 0x156F60) = *(int *)((char *)this + 0x13210);
                            goto block_40;
                        }
                    } else {
                        goto block_40;
                    }
                } else {
                    goto block_40;
                }
            } else {
block_40:
                if ((nHeader[2] & 0x20) && (LoadFxTriggerData(temp_v0, &spF4, spF8) == 0)) {
                    CDS_ASSERT(0x163, !"Error fx trigger data from world file!");
                } else if ((nHeader[2] & 0x80) && (LoadStaticInstanceMeshes(temp_v0, &spA0, (ePsx2FileVersion)nHeader[1]) == 0)) {
                    CDS_ASSERT(0x16C, !"Error loading static instance data from world file!");
                } else {
                    temp_s5 = (char *)&gGfxEng + 0x154F00;
                    if (nHeader[2] & 0x40) {
                        if (temp_s5 == 0) {
                            CdsAssert("PWorld.cpp", 0x174, "apParticleMgr");
                        }
                        if (LoadFogObjects__16PParticleManagerFP8PPakFile16ePsx2FileVersion(temp_s5, temp_v0, (ePsx2FileVersion)nHeader[1]) == 0) {
                            CDS_ASSERT(0x177, !"Error loading fog data from world file!");
                        } else {
                            goto block_54;
                        }
                    } else {
block_54:
                        if (nHeader[2] & 8) {
                            if (Load__13PLightManagerFP8PPakFile((char *)this + 0x1F0, temp_v0) == 0) {
                                CDS_ASSERT(0x180, !"Error loading light data from world file!");
                            } else {
                                goto block_59;
                            }
                        } else {
block_59:
                            if (LoadEditedInstanceData(temp_v0) == 0) {
                                CDS_ASSERT(0x187, !"Error loading appartion data from world file!");
                            } else if (nHeader[2] & 1) {
                                temp_a0 = m_pSpacePartitionTree;
                                if (temp_a0 != 0) {
                                    __dt__19PSpacePartitionTreeFv(temp_a0, 1);
                                }
                                var_v0 = (PSpacePartitionTree *)__nw__FUi(0x128A0U);
                                if (var_v0 != 0) {
                                    var_v0 = (PSpacePartitionTree *)__ct__19PSpacePartitionTreeFv(var_v0);
                                }
                                m_pSpacePartitionTree = var_v0;
                                temp_a0_2 = m_pSpacePartitionTree;
                                if (temp_a0_2 == 0) {
                                    CDS_ASSERT(0x195, !"Error allocating SP Tree object while loading world file!");
                                } else if (Load__19PSpacePartitionTreeFP8PPakFileP6PArrayP6PArray16ePsx2FileVersion(temp_a0_2, temp_v0, &spA0, (PArray *)&m_9FB0, (ePsx2FileVersion)nHeader[1]) == 0) {
                                    CDS_ASSERT(0x19B, !"Error loading SP Tree data from world file!");
                                    Destroy();
                                } else {
                                    goto block_75;
                                }
                            } else {
block_75:
                                spF0 = 0;
                                if (((PCDFile *)temp_v0)->Read(&spF0, 4U) != 4) {
                                    CDS_ASSERT(0x1A8, !"Error loading world file!");
                                } else if (spF0 != 3) {
                                    if (spF0 != 1) {
                                        CDS_ASSERT(0x1B4, !"Error loading dynamic objects from world file!");
                                        Destroy();
                                    } else {
                                        var_s0 = LoadMeshNodeHierarchy(temp_v0, &spA0, (ePsx2FileVersion)nHeader[1]);
                                        if (var_s0 == 0) {
                                            CDS_ASSERT(0x1C1, !"Error loading dynamic objects from world file!");
                                            Destroy();
                                        } else {
                                            if (bFlag != 0) {
                                                m_pMeshNode = (PMeshNode *)var_s0;
                                                strcpy((char *)&m_8728, pFileName);
                                            }
                                            temp_a0_3 = m_pMeshNode;
                                            if (temp_a0_3 != 0) {
                                                RecurseSetSTAnimOptions__6PMNodeFb(temp_a0_3, 0);
                                            }
                                            temp_v0_2 = m_pSpacePartitionTree;
                                            if (temp_v0_2 != 0) {
                                                temp_a0_4 = *(void **)temp_v0_2;
                                                if (temp_a0_4 != 0) {
                                                    RecurseSetSTAnimOptions__19PSpacePartitionNodeFb(temp_a0_4, 0);
                                                }
                                            }
                                            if (spF4 != 0) {
                                                AttachFxTriggersToNodes(m_pMeshNode, spF4, spF8);
                                            }
                                            temp_a0_5 = m_pMeshNode;
                                            if (temp_a0_5 != 0) {
                                                ProcessFxTriggers__6PMNodeFfP5PMat4bb(temp_a0_5, -2.0f, 0, 1, 0);
                                                Init__11PZBufferFogFv((char *)this + 0x8750);
                                            }
                                            if (spF4 != 0) {
                                                __dla__FPv(spF4);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ((PCDFile *)temp_v0)->Close();
    return (PMNode *)var_s0;
}

// DRAFT: 0x19BE70 UpdateTimer__6PWorldFv
// note: 40 words differ: fCounter in f3 vs f4 and the negative-path or/mtc1 dest v1 vs a0, the 1000.0f and 60.0f constant loads and m_1E0/m_1E4 loads in different order, tail of fResult reordered. Tried: mfc0 with sel operand (not accepted by asm), .word 0x4011C801 for the sel bit (42 to 41), fCounter by ternary (40, kept), decl/stmt order permutations (42 to 56), or operand swap (43), fStep before fRate (53).
void PWorld::UpdateTimer() {
    int nCounter;
    asm { mfpc nCounter, 0 }
    scePcStart(0x8003403E, 0, 0);
    float fCounter = (nCounter >= 0) ? (float)nCounter : (float)(int)(((unsigned int)nCounter >> 1) | (nCounter & 1)) + (float)(int)(((unsigned int)nCounter >> 1) | (nCounter & 1));
    float fRate = m_1E4;
    float fStep = (fCounter * m_1E0) / 1000.0f;
    float fResult;
    if (fRate != 60.0f) {
        fResult = (fStep * fRate) / 1000.0f;
    } else if (MODE_PAL != 0) {
        fResult = 1.2f * (float)(int)(0.5f + ((50.0f * fStep) / 1000.0f));
    } else {
        fResult = (float)(int)(0.5f + ((fStep * fRate) / 1000.0f));
    }
    m_1E8 = fResult;
}

// DRAFT: 0x19BFA0 InitRenderFrame__6PWorldFv
// note: DIFF 12 words; float constant load order differs (original loads 2048.0f into f14 first, then 0.1f, 1000.0f into f19, m_13794 into f12, 128.0f into f16). Tried named 0.1f/1000.0f locals (12), and all four float constants as locals declared in original load order (12).
void PWorld::InitRenderFrame() {
    gGfxEng.RefreshDisplay();
    UpdateTimer();
    m_8748 = 0;
    ((PMat4 *)m_Screen)->MakeScreenMatrix2(m_13794, XY_ASPECT, 2048.0f, 2048.0f, 128.0f, m_9EA0, 0.1f, 1000.0f);
    gGfxEng.SetScreenMatrix((PMat4 *)m_Screen);
    ((PShadowBuffer *)((char *)&gGfxEng + 0x157000))->SetZBufferRange(128.0f, m_9EA0);
}

// DRAFT: 0x19C060 InitMatrices__6PWorldFv
// note: DIFF 4 words; float constants 128.0f and 1000.0f are loaded in swapped order (original 128 into v1 first, 1000 into v0). Holding FOV_Y in a local fixed the early order; 128.0f or 1000.0f as locals gave 16 and 10; a 0.1f local gives 6 alone and with any second local (1000, 128, 16777216, 2048); both 128 and 1000 locals give 10-16.
void PWorld::InitMatrices() {
    float fFov = FOV_Y;
    m_13794 = fFov;
    ((PMat4 *)m_Screen)->MakeScreenMatrix2(m_13794, XY_ASPECT, 2048.0f, 2048.0f, 128.0f, 16777216.0f, 0.1f, 1000.0f);
    m_50 = 0xC5000000;
    m_54 = 0xC5000000;
    m_58 = 0xC3FA4000;
    m_60 = 1.0f / clip_volume.unk0;
    m_64 = 1.0f / (Y_ASPECT * clip_volume.unk4);
    m_68 = 0x3B033405;
    vu1SetScreenMatrix((PMat4 *)m_Screen);
}

// FUNCTION: 0x19C140 Init__6PWorldFv
void PWorld::Init() {
    FastMath_Setup();
    if (gGfxEng.Init(SCREEN_WIDTH, SCREEN_HEIGHT, 0, TV_MODE, 2, 0x31, MODE_PAL != 0 ? 0x177000 : 0x1B3000, 0xA9000) == 0) {
        printf("\n*** Engine Init failed!! ***\n\n");
        CdsAssert("PWorld.cpp", 0x5F, "0");
    }
    InitMatrices();
}

// FUNCTION: 0x19C1F0 __dt__6PWorldFv
PWorld::~PWorld() {
    Destroy();
    __dt__11PFogTextureFv((char *)this + 0x13210, -1);
    __dt__12PFireTextureFv((char *)this + 0x12C10, -1);
    __dt__11PGasTextureFv((char *)this + 0x12690, -1);
    __dt__13PWaterTextureFv((char *)this + 0x9FC0, -1);
    __dt__6PArrayFv((char *)this + 0x9FB0, -1);
    __dt__11PZBufferFogFv((char *)this + 0x8750, -1);
    __destroy_arr((char *)this + 0x220, __dt__15PCutScenePlayerFv, 0x2140, 4);
    __dt__13PLightManagerFv((char *)this + 0x1F0, -1);
}

// FUNCTION: 0x19C2E0 __ct__6PWorldFv
extern "C" PWorld *__ct__6PWorldFv(PWorld *volatile pThis)
{
    sceVu0UnitMatrix((char *)pThis + 0x10);
    sceVu0UnitMatrix((char *)pThis + 0x50);
    sceVu0UnitMatrix((char *)pThis + 0x90);
    __ct__9PFrustrumFv((char *)pThis + 0xF0);
    __ct__13PLightManagerFv((char *)pThis + 0x1F0);
    __construct_array((char *)pThis + 0x220, __ct__15PCutScenePlayerFv, __dt__15PCutScenePlayerFv, 0x2140, 4);
    __ct__11PZBufferFogFv((char *)pThis + 0x8750);
    __ct__6PArrayFv((char *)pThis + 0x9FB0);
    __ct__13PWaterTextureFv((char *)pThis + 0x9FC0);
    __ct__11PGasTextureFv((char *)pThis + 0x12690);
    __ct__12PFireTextureFv((char *)pThis + 0x12C10);
    __ct__11PFogTextureFv((char *)pThis + 0x13210);
    pThis->m_pMeshNode = 0;
    pThis->m_unk004 = 0;
    pThis->m_pSpacePartitionTree = 0;
    pThis->m_bCulled = 0;
    pThis->m_8724 = 0;
    pThis->m_1EC = 0;
    pThis->m_1ED = false;
    pThis->m_1E0 = 0.00333333341f;
    pThis->m_1E4 = 60.0f;
    pThis->m_Persp[0] = 60.0f;
    pThis->m_Persp[1] = 1.4f;
    pThis->m_Persp[2] = 1.0f;
    pThis->m_Persp[3] = 150.0f;
    Allocate__6PArrayFUi((char *)pThis + 0x9FB0, 0x40);
    return pThis;
}
