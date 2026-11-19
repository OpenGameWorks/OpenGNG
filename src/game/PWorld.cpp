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
};

// Object reached through PWorld's offset 0 pointer; Render is at vtable offset 0xC.
class PRenderHook {
public:
    virtual void Slot0();
    virtual int Render(int nA, int nB, int nC);
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

class PMNode {
public:
    char _pad00[0x3F];
    signed char m_3F;
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
};

class PShadowBuffer {
public:
    void SetZBufferRange(float fNear, float fFar);
};

class PMat4 {
public:
    void MakeScreenMatrix2(float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7);
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
extern "C" void __dl__FPv(void *pMem);
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

// DRAFT: 0x19C140 Init__6PWorldFv
// note: movz matches; 34 lines with FLAGS (gp loads of MODE_PAL/SCREEN_WIDTH/SCREEN_HEIGHT/TV_MODE become lui/at, load order); 25 with no flag or -sdatathreshold 4.
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
