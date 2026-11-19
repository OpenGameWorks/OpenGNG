// FLAGS: -sdatathreshold 0
#include "PWorld.h"

// TODO(header): foreign declarations
class PSpacePartitionTree {
public:
    void CullToFrustrum(PFrustrum *pFrustrum, float *pOut);
};

class PMeshNode {
public:
    void TestMeshNodeInFrustum(PFrustrum *pFrustrum);
};

class PCutScenePlayer {
public:
    void CullTest(PFrustrum *pFrustrum);
};

class PCDFile {
public:
    int Read(void *pBuf, unsigned int nSize);
};

class PMNode {
public:
    char _pad00[0x3F];
    signed char m_3F;
    int Find(PMNode *pNode);
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
