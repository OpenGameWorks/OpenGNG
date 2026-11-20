// FLAGS: -str readonly
#include "PWorld.h"

// TODO(header): foreign declarations
class PLightManager;
class PMat4;

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
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Animate(float fA, float fB, PMat4 *pMat, int nFlag, bool bFlag);
};

class PCDFile {
public:
    int Read(void *pBuf, unsigned int nSize);
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

void CdsAssert(char *pFile, int nLine, char *pExpr);
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
extern "C" void *__ct__13PWaterTextureFv(void *pThis);
extern "C" void *__ct__11PGasTextureFv(void *pThis);
extern "C" void *__ct__12PFireTextureFv(void *pThis);
extern "C" void *__ct__11PFogTextureFv(void *pThis);
extern "C" void __construct_array(void *pBlock, void *(*pCtor)(void *), void *(*pDtor)(void *, short), int nSize, int nCount);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nCount);
extern "C" int Load__19PStaticInstanceMeshFP8PPakFileP6PArray16ePsx2FileVersion(void *pThis, PPakFile *pFile, PArray *pArray, ePsx2FileVersion nVersion);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, char *pExpr);
extern "C" void AddMasterParticleInstance__16PParticleManagerFP15PParticleSystem(void *pThis, void *pSystem);

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

// DRAFT: 0x19AA20 AttachFxTriggersToNodes__6PWorldFP9PMeshNodeP24tagParticleFxTriggerDataUi
// note: frame 0x70 and saves match; 33 lines remain, all in loop shape. Original has offset in s0 and counter in s1 with a pre-loop nCount guard; for-loop, while, do-while (40), body-add and inverted-branch variants all stay at 33 or worse.
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
    unsigned int nOffset = 0;
    for (unsigned int i = 0; i < nCount; i++) {
        tagParticleFxTriggerData *pEntry = (tagParticleFxTriggerData *)((char *)pData + nOffset);
        PMNode *pTarget = ((PMNode *)pNode)->Find(pEntry->m_nId);
        if (pTarget == 0) {
            ((PMNode *)pNode)->AddFxTrigger((tagParticleFxTrigger *)pEntry->m_Trigger, false);
        } else {
            pTarget->AddFxTrigger((tagParticleFxTrigger *)pEntry->m_Trigger, false);
        }
        nOffset += 0x2C;
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

// DRAFT: 0x19AC40 CleanupStaticInstanceMeshes__6PWorldFv
// note: 56 differing lines; loop guard shape (original sltu/beqz entry + bottom test) and second gGfxEng block gp-relative (original lui 0x46/addiu absolute). Tried: for-loop 58, do-while 59, pointer for first block 56
void PWorld::CleanupStaticInstanceMeshes() {
    unsigned int n;
    unsigned int i;
    PStaticInstanceMesh *p;
    char *pGfx;

    n = m_9FB0;
    for (i = 0; i < n; i++) {
        p = 0;
        if (i < m_9FB0) {
            p = m_9FB8[i];
        }
        if (p) {
            __dt__19PStaticInstanceMeshFv(p, 1);
        }
    }
    if (m_9FB8) {
        m_9FB0 = 0;
        m_9FB4 = 0;
    }
    pGfx = (char *)&gGfxEng + 0x154F00;
    if (*(int *)(pGfx + 0x2070)) {
        *(int *)(pGfx + 0x2068) = 0;
        *(int *)(pGfx + 0x206C) = 0;
    }
    if (*(int *)((char *)&gGfxEng + 0x154F00 + 0x2080)) {
        *(int *)((char *)&gGfxEng + 0x154F00 + 0x2078) = 0;
        *(int *)((char *)&gGfxEng + 0x154F00 + 0x207C) = 0;
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
            CdsAssert__FPciPc("PWorld.cpp", 0x2F7, (char *)"apMesh");
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

// DRAFT: 0x19B130 UpdateAnimate__6PWorldFP6PMNode
// note: size 0xbc vs 0xd0; pNode/cur in s2/s1 (orig s1/s2); no index reload before array access; 42 lines after variants (pList ptr, decl order).
void PWorld::UpdateAnimate(PMNode *pNode) {
    PNodeTable *pTable = (PNodeTable *)m_pMeshNode;
    if (pTable != 0) {
        PNodeList *pList;
        PMNode *pCur = 0;
        pTable->m_list.m_nIndex = 0;
        pList = &pTable->m_list;
        if (pList->m_nCount != 0) {
            pCur = pList->m_ppNodes[0];
        }
        while (pCur != 0) {
            if ((pCur->m_3F & 7) == 0 && pCur->Find(pNode) != 0) {
                pCur->m_3F = 2;
                return;
            }
            pList->m_nIndex++;
            if (pList->m_nIndex < pList->m_nCount) {
                pCur = pList->m_ppNodes[pList->m_nIndex];
            } else {
                pCur = 0;
            }
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

// DRAFT: 0x19BE70 UpdateTimer__6PWorldFv
// note: 51 lines differ: mfc0 sel bit (0x4010C800 vs 0x4011C801), fCounter in f2 vs f4, srl/andi order and or/mtc1 dest reg a0 vs v1 in the negative path, add.s dest, m_1E0/m_1E4 load order. Tried operand swap of or (53), fStep before fRate (54).
void PWorld::UpdateTimer() {
    int nCounter;
    asm {
        mfc0 nCounter, $25
    }
    scePcStart(0x8003403E, 0, 0);
    float fCounter;
    if (nCounter >= 0) {
        fCounter = (float)nCounter;
    } else {
        float fHalf = (float)(int)(((unsigned int)nCounter >> 1) | (nCounter & 1));
        fCounter = fHalf + fHalf;
    }
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
// note: 19 lines with FLAGS (XY_ASPECT gp access, float literal load order, m_8748 store order); 41 without FLAGS; -sdatathreshold 4 gives 41.
void PWorld::InitRenderFrame() {
    gGfxEng.RefreshDisplay();
    UpdateTimer();
    m_8748 = 0;
    ((PMat4 *)m_Screen)->MakeScreenMatrix2(m_13794, XY_ASPECT, 2048.0f, 2048.0f, 128.0f, m_9EA0, 0.1f, 1000.0f);
    gGfxEng.SetScreenMatrix((PMat4 *)m_Screen);
    ((PShadowBuffer *)((char *)&gGfxEng + 0x157000))->SetZBufferRange(128.0f, m_9EA0);
}

// DRAFT: 0x19C060 InitMatrices__6PWorldFv
// note: FOV_Y, XY_ASPECT and Y_ASPECT must be gp-relative in the original, but the file-wide -sdatathreshold 0 (needed by the string placement of LoadEditedInstanceData and LoadFxTriggerData) makes them lui; 50 lines with FLAGS, 41 without.
void PWorld::InitMatrices() {
    m_13794 = FOV_Y;
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
    __dt__9PFrustrumFv((char *)this + 0xF0, -1);
}

// DRAFT: 0x19C2E0 __ct__6PWorldFv
// note: DIFF 98; original spills this to 0x1C(sp) with frame 0x20 and reloads it before each call, ours keeps this in s0 with frame 0x30 and s1; the spill needs a member type with a destructor (PFrustrum's __dt__ exists but PFrustrum.h declares none); tried explicit (char *)this casts (99) and a local char *base (98).
PWorld::PWorld() {
    char *base = (char *)this;
    sceVu0UnitMatrix(base + 0x10);
    sceVu0UnitMatrix(base + 0x50);
    sceVu0UnitMatrix(base + 0x90);
    __ct__9PFrustrumFv(base + 0xF0);
    __ct__13PLightManagerFv(base + 0x1F0);
    __construct_array(base + 0x220, __ct__15PCutScenePlayerFv, __dt__15PCutScenePlayerFv, 0x2140, 4);
    __ct__11PZBufferFogFv(base + 0x8750);
    __ct__6PArrayFv(base + 0x9FB0);
    __ct__13PWaterTextureFv(base + 0x9FC0);
    __ct__11PGasTextureFv(base + 0x12690);
    __ct__12PFireTextureFv(base + 0x12C10);
    __ct__11PFogTextureFv(base + 0x13210);
    m_pMeshNode = 0;
    m_unk004 = 0;
    m_pSpacePartitionTree = 0;
    m_bCulled = 0;
    m_8724 = 0;
    m_1EC = 0;
    m_1ED = false;
    m_1E0 = 0.00333333341f;
    m_1E4 = 60.0f;
    m_Persp[0] = 60.0f;
    m_Persp[1] = 1.4f;
    m_Persp[2] = 1.0f;
    m_Persp[3] = 150.0f;
    Allocate__6PArrayFUi((char *)this + 0x9FB0, 0x40);
}
