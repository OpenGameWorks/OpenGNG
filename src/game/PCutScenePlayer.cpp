// FLAGS: -str readonly
#pragma opt_strength_reduction off
#include "types.h"
#include "PCutScenePlayer.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
class PVec3 {
public:
    PVec3 operator-(PVec3 &rhs);
    PVec3 &operator=(const PVec3 &rhs) {
        sceVu0CopyVector(this, (float *)&rhs);
        return *this;
    }
    float m_fX, m_fY, m_fZ, m_fW;
};
extern "C" float sqrtf(float fVal);
extern "C" float atan2f(float fY, float fX);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" float Round180__Ff(float fAngle);
class PFrustrum {
public:
    int IntersectBox(float (*pBox)[2][4], PMat4 *pMat);
};
enum eBoxIntersect { eBoxIntersect_Unused };
class PLightManager;
struct tagComputedLightCache;
class PLightManager {
public:
    void ComputeLights(float *pPos, bool bA, bool bB, bool bC, tagComputedLightCache *pCache, float (*pMtx)[4], float fScale);
};
class PDynamicSplinePatch {
public:
    void Render();
    void Animate(float fTime);
};
class PArray;
class PResource {
public:
    PResource() { m_unk4 = 0; }
    virtual ~PResource();
    int m_unk4;
};
class PMNode;
class PArray {
public:
    void Add(void *pItem);
    void Remove(void *pItem);
    void RemoveCurrent();
    void Allocate(unsigned int nSize);
    PArray();

    unsigned int m_unk0;
    int m_unk4;
    void **m_unk8;
    unsigned int m_unkC;
};
extern "C" void sceVu0UnitMatrix(void *pMat);
// The identity matrix PMNode's inline ctor builds at 0x40.
struct PMNodeMatrix {
    PMNodeMatrix() { sceVu0UnitMatrix(m); }
    float m[4][4];
};
class PMNode : public PResource {
public:
    PMNode() { InitMembers(); }
    virtual ~PMNode();
    virtual void Render(PLightManager *pLightMgr, int nA, int nB);
    virtual void Vt2();
    virtual void Vt3();
    virtual void Animate(float fA, float fB, PMat4 *pMat, int nA, bool bB);
    virtual void Vt4();
    void ProcessFxTriggers(float fTime, PMat4 *pMat, bool bA, bool bB);
    PMNode *Find(unsigned int nId);
    void RecurseSetFade(float fFade);
    void SetAllFrustrumTest(eBoxIntersect eMode);
    void InitMembers();
    char _pad08[0x14 - 0x08];
    PArray m_unk14;
    char _pad24[0x40 - 0x24];
    PMNodeMatrix m_unk40;
    char _pad80[0xD8 - 0x80];
    PArray m_unkD8;
    char _padE8[0x130 - 0xE8];
};
class PMeshNode : public PMNode {
public:
    PMeshNode() { InitMembers(); }
    virtual ~PMeshNode();
    void TestMeshNodeInFrustum(PFrustrum *pFrustrum);
    void InitMembers();
    PArray m_unk130;
};
class PCDFile {
public:
    int Read(void *pBuf, unsigned int nSize);
};
void CdsAssert(char *pFile, int nLine, char *pExpr);
class PGrimReaperCape {
public:
    void Enable(bool bFlag, PMNode *pNode);
    void Init(float *pBuf);
    void AnimateControlNode(void *pAnim, float fTime);
};
class Player {
public:
    void FinishCutScene(PMeshNode *pNode, PMat4 *pMat, int nFlag);
    void RenderCutScene();
    void UpdatePlayerFx();
};
class FontManager {
public:
    void RemoveAll(bool bFlag);
    void InitSubTitle(int nArg);
    void RemoveText(int nId);
    void RemoveText(unsigned short nId);
    void DisplayString(int nStr, int nX, int nY, bool bFlag);
    int GetTextCount(int nStr);
    void ProcessSubtitle(int nArg);
};

extern unsigned char gInterface[];
extern char gGfxEng[1504384];
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void __dt__15PGrimReaperCapeFv(void *pThis, short nFlag);
class PMeshNodeAnimDataTable {
public:
    virtual ~PMeshNodeAnimDataTable();
    char _pad[0x30];
};
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" PMeshNodeAnimDataTable *__ct__22PMeshNodeAnimDataTableFv(PMeshNodeAnimDataTable *pThis);
extern "C" int Load__22PMeshNodeAnimDataTableFP8PPakFile16ePsx2FileVersion(PMeshNodeAnimDataTable *pThis, PPakFile *pFile, int nVersion);
extern "C" void *__ct__6PArrayFv(PArray *pThis);
extern "C" void *__ct__15PGrimReaperCapeFv(PGrimReaperCape *pThis);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" int printf(const char *pFmt, ...);
extern "C" void __dt__22PMeshNodeAnimDataTableFv(PMeshNodeAnimDataTable *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__ct__5PAnimFv(void *pThis);
extern "C" void *__ct__10PAnimFrameFs(void *pThis, short nFrame);
void FastMath_ComputeMatrix(float (*pMat)[4][4], float (*pA)[4], float (*pB)[4], float (*pC)[4], float (*pD)[4], float (*pE)[4], float (*pF)[4][4]);
// PAnim virtual layout as seen through a PAnim pointer; PAnim.h stops at Animate.
// Slot 0x38 is EnableAnim (virtual 12).
class PAnimSlots {
public:
    virtual ~PAnimSlots();
    virtual int Load(PPakFile *pFile);
    virtual int Load(PPakFile *pFile, void *pHeader);
    virtual float Animate(float fTime, float fUnused, float (*pMatrix)[4], float *pOut, bool bFlag);
    virtual bool IsAnimate();
    virtual void SetFrameTime(float fTime);
    virtual float GetEndFrame();
    virtual void SetEndFrame(short nFrame);
    virtual int GetLoop();
    virtual void SetAllAnimFlags(void *pFlags);
    virtual void SetAnimLoopCount(int nCount);
    virtual float GetFrameTime();
    virtual void EnableAnim(bool bEnable);
};
class PResourceManager {
public:
    int GetResource(unsigned int nId, bool bFlag);
};
class PCutSceneAnim {
public:
    virtual ~PCutSceneAnim();
    virtual void V1();
    virtual void V2();
    virtual float V3(float fA, float fB, float *pVec, int *pInt, int nFlag);
    virtual signed char V4();
    virtual void V5();
    virtual int V6();
    virtual void V7();
    virtual void V8();
    virtual void V9(void *pArg);
};
class PCutSceneXform {
public:
    virtual ~PCutSceneXform();
    virtual void V1(PLightManager *pLightMgr, int nA, int nB);
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5(void *pArg);
};

extern "C" char __vt__9PResource[];
extern "C" char __vt__6PMNode[];
extern "C" char __vt__9PMeshNode[];
extern "C" void InitMembers__6PMNodeFv(void *pThis);
extern "C" void InitMembers__9PMeshNodeFv(void *pThis);
extern "C" void InitCutScene__6PlayerFv(void *pThis);
extern "C" void *GetResource__16PResourceManagerFUib(void *pThis, unsigned int nId, bool bFlag);
extern "C" void *GetFirstMesh__6PMNodeFv(void *pThis);
extern "C" void BuildDispList__9PSkeletonFv(void *pThis);
extern "C" void ScaleSet__6PMNodeFffff(void *pThis, float fA, float fB, float fC, float fD);
extern "C" void EnableAnim__6PMNodeFbb(void *pThis, bool bA, bool bB);
extern "C" void SetAllFrustrumTest__6PMNodeF13eBoxIntersect(void *pThis, eBoxIntersect eMode);
extern unsigned char gEng[0x19B90];
extern float gUnitMatrix[16];
struct PActorVec {
    float x, y, z, w;
};
class PActorSlots {
public:
    virtual ~PActorSlots();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(void *pData);
};

#define CDS_ASSERT(line, cond, msg) ((cond) ? (void)0 : CdsAssert("PCutScenePlayer.cpp", line, msg))

// FUNCTION: 0x001BBBA0 KillActorFx__15PCutScenePlayerFv
void PCutScenePlayer::KillActorFx() {
    unsigned int n = m_unkB0;
    for (unsigned int i = 0; i < n; i++) {
        void *pItem = (i < m_unkB0) ? m_unkB8[i] : 0;
        if (pItem != 0) {
            PMNode *pNode = *(PMNode **)((char *)pItem + 0x30);
            if (pNode != 0) {
                pNode->ProcessFxTriggers(-1.0f, 0, true, false);
            }
        }
    }
}

// FUNCTION: 0x001BBC40 LoadNodeNameTable__15PCutScenePlayerFP8PPakFileUiP6PArray
bool PCutScenePlayer::LoadNodeNameTable(PPakFile *pFile, unsigned int nCount, PArray *pArray) {
    if (pFile == 0) {
        CdsAssert("PCutScenePlayer.cpp", 0x42B, "poFile");
    }
    if (pArray == 0) {
        CdsAssert("PCutScenePlayer.cpp", 0x42C, "poNameTable");
    }
    unsigned int i = 0;
    if (i < nCount) {
        do {
            void *pItem;
            if (((PCDFile *)pFile)->Read(&pItem, 4) != 4) {
                return false;
            }
            pArray->Add(pItem);
            i++;
        } while (i < nCount);
    }
    return true;
}

// FUNCTION: 0x001BBD10 GetViewMatrix__15PCutScenePlayerFP5PMat4
void PCutScenePlayer::GetViewMatrix(PMat4 *pMat) {
    float *m = (float *)pMat;
    float c0[4];
    float c1[4];
    float c2[4];
    PVec3 vDelta;
    vDelta = *(PVec3 *)m_unkE0 - *(PVec3 *)m_unkC0;
    float fLen = sqrtf(vDelta.m_fX * vDelta.m_fX + vDelta.m_fZ * vDelta.m_fZ);
    float fPitch = atan2f(-vDelta.m_fY, fLen) * 57.295776f;
    *(float *)(m_unkD0 + 0) = fPitch;
    float fK = 180.0f;
    float fSum = fPitch + fK;
    *(float *)(m_unkD0 + 0) = fSum;
    Round180__Ff(fSum);
    *(float *)(m_unkD0 + 4) = atan2f(vDelta.m_fX, -vDelta.m_fZ) * 57.295776f;
    *(float *)(m_unkD0 + 8) = m_unkF0;
    sceVu0UnitMatrix(pMat);
    pMat->RotateY(*(float *)(m_unkD0 + 4));
    pMat->RotateX(*(float *)(m_unkD0 + 0));
    pMat->RotateZ(*(float *)(m_unkD0 + 8));
    c0[0] = m[0];
    c0[1] = m[4];
    c0[2] = m[8];
    c0[3] = 1.0f;
    c1[0] = m[1];
    c1[1] = m[5];
    c1[2] = m[9];
    c1[3] = 1.0f;
    c2[0] = m[2];
    c2[1] = m[6];
    c2[2] = m[10];
    c2[3] = 1.0f;
    m[12] = -sceVu0InnerProduct(c0, m_unkC0);
    m[13] = -sceVu0InnerProduct(c1, m_unkC0);
    m[14] = -sceVu0InnerProduct(c2, m_unkC0);
    *(float *)(m_unkD0 + 4) = atan2f(-m[2], -m[10]) * 57.295776f;
}

// FUNCTION: 0x001BBEE0 LoadBgAnims__15PCutScenePlayerFP8PPakFileUi
bool PCutScenePlayer::LoadBgAnims(PPakFile *pFile, unsigned int nFlag) {
    if (pFile == 0) {
        CdsAssert("PCutScenePlayer.cpp", 0x3C9, "poFile");
    }
    int nVersion = 0;
    if (((PCDFile *)pFile)->Read(&nVersion, 4) != 4) {
        return false;
    }
    if (nVersion != 0xA) {
        return false;
    }
    unsigned int i = 0;
    PMeshNodeAnimDataTable *pObj;
    if (i < nFlag) {
        do {
            pObj = (PMeshNodeAnimDataTable *)__nw__FUi(0x30);
            if (pObj != 0) {
                pObj = __ct__22PMeshNodeAnimDataTableFv(pObj);
            }
            if (pObj == 0) {
                CdsAssert("PCutScenePlayer.cpp", 0x3D9, "apoAnimData");
            }
            if (Load__22PMeshNodeAnimDataTableFP8PPakFile16ePsx2FileVersion(pObj, pFile, 0x20000) == 0) {
                delete pObj;
                return false;
            }
            ((PArray *)&m_unkA0)->Add(pObj);
            i++;
        } while (i < nFlag);
    }
    return true;
}

// FUNCTION: 0x001BC030 AttachActors__15PCutScenePlayerFv
bool PCutScenePlayer::AttachActors() {
    if (m_unk44 == 0) {
        CdsAssert("PCutScenePlayer.cpp", 0x343, "mpoResMgr");
    }
    m_unkB4 = 0;
    bool bNew;
    PMNode *pRoot;
    char *pA;
    char *pData = 0;
    if (m_unkB0 != 0) {
        pData = (char *)*m_unkB8;
    }
    if (pData != 0) {
        do {
            if (pData == 0) {
                CdsAssert("PCutScenePlayer.cpp", 0x346, "apData");
            }
            bNew = false;
            if (*(char **)(pData + 0x30) == 0) {
                *(PMeshNode **)(pData + 0x30) = new PMeshNode;
                if (*(char **)(pData + 0x30) == 0) {
                    CdsAssert("PCutScenePlayer.cpp", 0x34C, "apData->poTransform");
                }
                bNew = true;
            }
            unsigned int nId = *(unsigned int *)(pData + 0xD0);
            switch (nId) {
            case 0x81000018: {
                char *pPlayer = (char *)*(char **)(gEng + 0x1883C);
                *(char **)(pData + 0x38) = pPlayer;
                InitCutScene__6PlayerFv(pPlayer);
                char *pNode = *(char **)(pPlayer + 0x3C);
                *(char **)(pData + 0x34) = pNode;
                *(u_long128 *)(pNode + 0x80) = *(u_long128 *)&gUnitMatrix[12];
                *(unsigned char *)(pNode + 0x3E) |= 8;
                *(u_long128 *)(pNode + 0x90) = *(u_long128 *)&gUnitMatrix[12];
                *(unsigned char *)(pNode + 0x3E) |= 8;
                *(int *)(pNode + 0x18) = 0;
                char *pChild;
                PArray *pKids = (PArray *)(pNode + 0x14);
                if (pKids->m_unk0 != 0) {
                    pChild = (char *)pKids->m_unk8[0];
                } else {
                    pChild = 0;
                }
                *(signed char *)(pChild + 0x3D) = 3;
                bNew = true;
                break;
            }
            case 0x10003C5:
                if (*(char **)(pData + 0x34) == 0) {
                    pRoot = (PMNode *)GetResource__16PResourceManagerFUib((char *)m_unk44, nId, false);
                    if (pRoot == 0) {
                        CdsAssert("PCutScenePlayer.cpp", 0x360, "pRoot");
                    }
                    *(PMNode **)(pData + 0x34) = pRoot;
                    pA = (char *)pRoot->Find(0xB5714B5A);
                    if (pA != 0) {
                        char *pRes = (char *)GetResource__16PResourceManagerFUib((char *)m_unk44, 0x10003C8, true);
                        if (pRes != 0) {
                            char *pMesh = (char *)GetFirstMesh__6PMNodeFv(pRes);
                            *(char **)(pA + 0x10) = pMesh;
                            *(unsigned char *)(pA + 0x3E) &= 0xEF;
                            if (pMesh != 0 && *(unsigned char *)(pMesh + 0xC) != 0) {
                                *(unsigned char *)(pA + 0x3E) |= 0x10;
                            }
                        }
                    }
                    pA = (char *)pRoot->Find(0x6499DC24);
                    if (pA != 0) {
                        char *pRes = (char *)GetResource__16PResourceManagerFUib((char *)m_unk44, 0x10003C7, true);
                        if (pRes != 0) {
                            char *pMesh = (char *)GetFirstMesh__6PMNodeFv(pRes);
                            *(char **)(pA + 0x10) = pMesh;
                            *(unsigned char *)(pA + 0x3E) &= 0xEF;
                            if (pMesh != 0 && *(unsigned char *)(pMesh + 0xC) != 0) {
                                *(unsigned char *)(pA + 0x3E) |= 0x10;
                            }
                        }
                    }
                    BuildDispList__9PSkeletonFv(pRoot);
                }
                break;
            default:
                if (*(char **)(pData + 0x34) == 0) {
                    *(char **)(pData + 0x34) = (char *)GetResource__16PResourceManagerFUib((char *)m_unk44, nId, false);
                    if (*(char **)(pData + 0x34) == 0) {
                        printf("\nUnable to load actor resource, ID = %d\n", *(unsigned int *)(pData + 0xD0));
                        ((PArray *)&m_unkB0)->RemoveCurrent();
                        if (pData != 0) {
                            __dt__22PMeshNodeAnimDataTableFv((PMeshNodeAnimDataTable *)pData, -1);
                            __dl__FPv(pData);
                        }
                        CdsAssert("PCutScenePlayer.cpp", 0x380, "0");
                    }
                }
                break;
            }
            *(int *)(*(char **)(pData + 0x30) + 8) = *(int *)(pData + 0x3C);
            {
                float v[4];
                float *pS = (float *)(pData + 0x40);
                float f0, f1, f2, f3;
                f3 = pS[3]; f2 = pS[2]; f1 = pS[1]; f0 = pS[0];
                v[0] = f0; v[1] = f1; v[2] = f2; v[3] = f3;
                char *pT = *(char **)(pData + 0x30);
                *(u_long128 *)(pT + 0x80) = *(u_long128 *)v;
                *(unsigned char *)(pT + 0x3E) |= 8;
                float *pS2 = (float *)(pData + 0x50);
                float g0, g1, g2, g3;
                g3 = pS2[3]; g2 = pS2[2]; g1 = pS2[1]; g0 = pS2[0];
                v[0] = g0; v[1] = g1; v[2] = g2; v[3] = g3;
                pT = *(char **)(pData + 0x30);
                *(u_long128 *)(pT + 0x90) = *(u_long128 *)v;
                *(unsigned char *)(pT + 0x3E) |= 8;
            }
            ScaleSet__6PMNodeFffff(*(char **)(pData + 0x30), *(float *)(pData + 0x60), *(float *)(pData + 0x64), *(float *)(pData + 0x68), *(float *)(pData + 0x6C));
            ((PActorSlots *)*(char **)(pData + 0x30))->V6(pData);
            {
                PActorSlots *pSrc = (PActorSlots *)*(char **)(pData + 0x34);
                if (*(int *)((char *)pSrc + 4) == 2) {
                    pSrc->V6(pData);
                } else {
                    pSrc->V6(pData);
                }
            }
            EnableAnim__6PMNodeFbb(*(char **)(pData + 0x30), true, true);
            if (bNew) {
                ((PArray *)(*(char **)(pData + 0x30) + 0x14))->Add(*(void **)(pData + 0x34));
            }
            SetAllFrustrumTest__6PMNodeF13eBoxIntersect(*(char **)(pData + 0x30), (eBoxIntersect)2);
            if ((unsigned long long)*(unsigned int *)(pData + 0xD0) == 0x81000162ULL) {
                char *pFound = (char *)((PMNode *)*(char **)(pData + 0x34))->Find(0x9980D6C3);
                if (pFound != 0) {
                    ((PGrimReaperCape *)m_unk100)->Enable(true, (PMNode *)pFound);
                }
            }
            unsigned int nNext = m_unkB4 + 1;
            m_unkB4 = nNext;
            pData = (nNext < m_unkB0) ? (char *)m_unkB8[m_unkB4] : 0;
        } while (pData != 0);
    }
    return true;
}

// FUNCTION: 0x001BC590 LoadActors__15PCutScenePlayerFP8PPakFileUi
bool PCutScenePlayer::LoadActors(PPakFile *pFile, unsigned int nFlag) {
    if (pFile == 0) {
        CdsAssert("PCutScenePlayer.cpp", 0x30C, "poFile");
    }
    unsigned int i = 0;
    if (i < nFlag) {
        do {
            char abRec[0xA4];
            if (((PCDFile *)pFile)->Read(abRec, 0xA4) != 0xA4) {
                return false;
            }
            void *pRaw = __nw__FUi(0xE0);
            PMeshNodeAnimDataTable *pObj = (PMeshNodeAnimDataTable *)pRaw;
            if (pRaw != 0) {
                __ct__22PMeshNodeAnimDataTableFv(pObj);
            }
            if (pObj == 0) {
                CdsAssert("PCutScenePlayer.cpp", 0x317, "apData");
            }
            int nVersion = 0;
            if (((PCDFile *)pFile)->Read(&nVersion, 4) != 4) {
                return false;
            }
            if (nVersion != 0xA) {
                return false;
            }
            if (Load__22PMeshNodeAnimDataTableFP8PPakFile16ePsx2FileVersion(pObj, pFile, 0x20000) == 0) {
                if (pObj != 0) {
                    __dt__22PMeshNodeAnimDataTableFv(pObj, -1);
                    __dl__FPv(pObj);
                }
                return false;
            }
            *(int *)((char *)pObj + 0x30) = 0;
            *(int *)((char *)pObj + 0x34) = 0;
            *(int *)((char *)pObj + 0x38) = 0;
            memcpy((char *)pObj + 0x3C, abRec, 0xA4);
            ((PArray *)&m_unkB0)->Add(pObj);
            if ((unsigned long long)*(unsigned int *)((char *)pObj + 0xD0) == 0x81000162ULL) {
                float fBuf[4] = {128.0f, 128.0f, 128.0f, 128.0f};
                ((PGrimReaperCape *)m_unk100)->Init(fBuf);
                m_unk20E0 = ((PResourceManager *)m_unk44)->GetResource(0x84000010, false);
            }
            i++;
        } while (i < nFlag);
    }
    return true;
}

// FUNCTION: 0x001BC770 SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf
void PCutScenePlayer::SetBgNodesOpacity(PArray *pArray, float fOpacity) {
    if (pArray == 0) {
        CdsAssert("PCutScenePlayer.cpp", 0x2E1, "poNodeTable");
    }
    if (m_unk40 == 0) {
        return;
    }
    {
        unsigned int nCount = *(unsigned int *)pArray;
        unsigned int i = 0;
        if (i < nCount) {
            do {
                unsigned int nId = 0;
                if (i < *(unsigned int *)pArray) {
                    nId = (unsigned int)(*(void ***)((char *)pArray + 8))[i];
                }
                if (nId != 0) {
                    PMNode *pNode = m_unk40->Find(nId);
                    if (pNode != 0) {
                        pNode->RecurseSetFade(fOpacity);
                        float fZero = 0.0f;
                        if (fOpacity == fZero) {
                            pNode->ProcessFxTriggers(-1.0f, 0, true, false);
                        }
                    }
                }
                i++;
            } while (i < nCount);
        }
    }
}

// FUNCTION: 0x001BC890 Abort__15PCutScenePlayerFv
void PCutScenePlayer::Abort() {
    SetBgNodesOpacity((PArray *)m_unk80, 0.0f);
    SetBgNodesOpacity((PArray *)m_unk70, 1.0f);
    KillActorFx();
    ((FontManager *)(gInterface + 0x80))->RemoveAll(true);
    if ((m_unk213D & 1) != 0) {
        Unload(true);
    } else {
        UpdatePlayer();
    }
    m_unk213C = 0;
    ((PGrimReaperCape *)m_unk100)->Enable(false, 0);
    *(unsigned char *)(gGfxEng + 0x158E26) = 1;
}

// FUNCTION: 0x001BC940 ResetCutScene__15PCutScenePlayerFv
void PCutScenePlayer::ResetCutScene() {
    SetBgNodesOpacity((PArray *)m_unk60, 1.0f);
    SetBgNodesOpacity((PArray *)m_unk80, 1.0f);
    SetBgNodesOpacity((PArray *)m_unk90, 0.0f);
    SetBgNodesOpacity((PArray *)m_unk70, 0.0f);
    m_unk5C = m_unk2130;
    m_unk213C = 0;
    ((PGrimReaperCape *)m_unk100)->Enable(false, 0);
}

// DRAFT: 0x001BC9C0 ResetAnimations__15PCutScenePlayerFv
// note: 104 differing words under opt_strength_reduction off (64 before); frame 0x70 vs 0x60, original builds &sp50 in a1 before the lq/sq copy; tried split decl/assign, pointer dst, struct-typed constant (104-108). Earlier: frame 0x80 vs 0x60 (ours saves s1..s5, original s0..s3), this in s4 vs s2, i/pItem registers permuted, constant copied via temp at sp+0x70 vs direct to sp+0x50. Tried: hoisting i (no change), direct pItem+0x30 reloads (88->64), non-static int[4] local (107).
void PCutScenePlayer::ResetAnimations() {
    static const int kParams[4] = {0x0000ffff, 0x0000ffff, 0x00030001, 0x3f000000};
    u_long128 sp50 = *(u_long128 *)kParams;
    if (m_unk48 != 0) {
        m_unk48->V9(&sp50);
    }
    if (m_unk4C != 0) {
        m_unk4C->V9(&sp50);
    }
    if (m_unk50 != 0) {
        m_unk50->V9(&sp50);
    }
    if (m_unk54 != 0) {
        m_unk54->V9(&sp50);
    } else {
        ((FontManager *)(gInterface + 0x80))->InitSubTitle(m_unk2130);
    }
    printf("**** Cutscene load ****\n");
    AttachActors();
    printf("**** Cutscene load done ****\n");
    unsigned int n = m_unkB0;
    unsigned int i = 0;
    for (; i < n; i++) {
        void *pItem = (i < m_unkB0) ? m_unkB8[i] : 0;
        if (pItem == 0) {
            CdsAssert("PCutScenePlayer.cpp", 0x29F, "apData");
        }
        if (*(PCutSceneXform **)((char *)pItem + 0x30) == 0) {
            CdsAssert("PCutScenePlayer.cpp", 0x2A0, "apData->poTransform");
        }
        (*(PCutSceneXform **)((char *)pItem + 0x30))->V5(&sp50);
    }
    m_unk213C = 0;
    m_unk213D &= 0x7F;
}

// FUNCTION: 0x001BCB60 Render__15PCutScenePlayerFP13PLightManager
void PCutScenePlayer::Render(PLightManager *pLightMgr) {
    if (m_unk40 != 0) {
        m_unk40->Render(0, 0x80, 0);
    }
    gGfxEng[0x158E22] = 1;
    unsigned int n = m_unkB0;
    for (unsigned int i = 0; i < n; i++) {
        void **pItem = (void **)((i < m_unkB0) ? m_unkB8[i] : 0);
        if (pItem == 0) {
            CdsAssert("PCutScenePlayer.cpp", 0x24E, "apData");
        }
        if (pItem[12] == 0) {
            CdsAssert("PCutScenePlayer.cpp", 0x24F, "apData->poTransform");
        }
        char *pObj34 = (char *)pItem[13];
        if (pObj34 == 0 || *(int *)(pObj34 + 0xC) != 0) {
            if (pLightMgr != 0) {
                pLightMgr->ComputeLights((float *)(pObj34 + 0x70), 1, 1, 1, 0, 0, *(float *)((char *)this + 0xF4));
            }
            Player *p = (Player *)pItem[14];
            if (p != 0) {
                p->RenderCutScene();
            }
            ((PCutSceneXform *)pItem[12])->V1(0, 0x80, 0);
        }
    }
    ((PDynamicSplinePatch *)m_unk100)->Render();
    gGfxEng[0x158E22] = 0;
}

// DRAFT: 0x001BCCF0 CullTest__15PCutScenePlayerFP9PFrustrum
// note: 17 words differ, all register permutation: original this=s4, frustum=s3, element/node=s2; ours this=s3, frustum=s2, element/node=s4. The box read is the inline PArray read at node+0x14. Tried all 24 declaration orders of nCount/i/pElem/pNode (17), both reads as if-blocks (23).
void PCutScenePlayer::CullTest(PFrustrum *pFrustrum) {
    if (m_unk40 != 0) {
        ((PMeshNode *)m_unk40)->TestMeshNodeInFrustum(pFrustrum);
    }
    unsigned int nCount = m_unkB0;
    unsigned int i = 0;
    if (i < nCount) {
        do {
            char *pElem = (char *)((i < m_unkB0) ? m_unkB8[i] : 0);
            if (pElem == 0) {
                CdsAssert("PCutScenePlayer.cpp", 0x21F, "apData");
            }
            char *pNode = *(char **)(pElem + 0x34);
            if (pNode != 0) {
                *(int *)(pNode + 0x18) = 0;
                int nMode = 2;
                PArray *pArr = (PArray *)(pNode + 0x14);
                void *pBox = (0 < pArr->m_unk0) ? pArr->m_unk8[0] : 0;
                if (pBox != 0) {
                    nMode = pFrustrum->IntersectBox((float (*)[2][4])(pNode + 0x110), (PMat4 *)((char *)pBox + 0x40));
                }
                if (nMode != 0) {
                    nMode = 2;
                }
                ((PMNode *)pNode)->SetAllFrustrumTest((eBoxIntersect)nMode);
            }
            i++;
        } while (i < nCount);
    }
}

// DRAFT: 0x001BCE10 Animate__15PCutScenePlayerFf
// note: 106 differing lines (base 113); frame 0xC0 matches. First diff at 0x198: s1 vs s2 for the lw of 0xB0(s5) feeding the nCount/nIdx loop. Tried: aVec[12], aInt[2] aligned(16), if (m_unk2138) truth test, nCount > 0, nIdx declared before nCount (register moves, count unchanged).
bool PCutScenePlayer::Animate(float fTime) {
    float aVec[12];
    int aInt[2] __attribute__((aligned(16)));
    float fRes;
    char *pElem;
    PMNode *pFind;
    void *pAnim;
    unsigned int nCount;
    unsigned int nIdx;
    int nText;

    if (m_unk40 != 0) {
        m_unk40->Animate(0.0f, fTime, 0, 0, false);
    }
    if (m_unk48 != 0) {
        fRes = m_unk48->V3(0.0f, fTime, aVec, aInt, 1);
        m_unk213C = m_unk48->V4();
        *(int *)&aVec[3] = 0x3F800000;
        ((PMat4 *)this)->MulVector(m_unkC0, aVec);
        if (m_unk2138) {
            if (!(fRes <= (float)m_unk48->V6() - 30.0f * m_unk2138)) {
                m_unk213D |= ~0x7F;
            }
        }
    }
    if (m_unk4C != 0) {
        m_unk4C->V3(fRes, 0.0f, aVec, aInt, 1);
        *(int *)&aVec[3] = 0x3F800000;
        ((PMat4 *)this)->MulVector(m_unkE0, aVec);
    }
    if (m_unk50 != 0) {
        m_unk50->V3(fRes, 0.0f, aVec, aInt, 1);
        m_unkF0 = aVec[0];
    }

    nCount = m_unkB0;
    nIdx = 0;
    if (nCount != 0) {
        do {
            pElem = (nIdx < m_unkB0) ? (char *)m_unkB8[nIdx] : 0;
            CDS_ASSERT(0x1AF, pElem != 0, "apData");
            CDS_ASSERT(0x1B0, *(void **)(pElem + 0x30) != 0, "apData->poTransform");
            if (*(unsigned int *)(pElem + 0xD0) == 0x81000162ULL) {
                pAnim = 0;
                pFind = (*(PMNode **)(pElem + 0x34))->Find(0x9980D6C3U);
                if (pFind != 0) {
                    pAnim = *(void **)((char *)pFind + 0x24);
                    *(void **)((char *)pFind + 0x24) = 0;
                    ((PGrimReaperCape *)((char *)this + 0x100))->AnimateControlNode(pAnim, fTime);
                }
                (*(PMNode **)(pElem + 0x30))->Animate(0.0f, fTime, (PMat4 *)this, 0, false);
                ((PDynamicSplinePatch *)((char *)this + 0x100))->Animate(1.0f);
                if (pFind != 0 && pAnim != 0) {
                    *(void **)((char *)pFind + 0x24) = pAnim;
                }
            } else {
                (*(PMNode **)(pElem + 0x30))->Animate(0.0f, fTime, (PMat4 *)this, 0, false);
                if (*(char **)(pElem + 0x38) != 0) {
                    ((Player *)*(char **)(pElem + 0x38))->UpdatePlayerFx();
                }
            }
            nIdx += 1;
        } while (nIdx < nCount);
    }

    if (m_unk54 != 0) {
        m_unk54->V3(fRes, 0.0f, aVec, aInt, 1);
        nText = (int)*(float *)&aInt[1];
        if (nText != *(int *)&m_unk58) {
            *(int *)&m_unk58 = nText;
            ((FontManager *)(gInterface + 0x80))->RemoveText((unsigned short)0x28);
            if (nText != 0) {
                ((FontManager *)(gInterface + 0x80))->DisplayString(m_unk5C, 0, 0, false);
                m_unk5C += ((FontManager *)(gInterface + 0x80))->GetTextCount(m_unk5C);
            }
        }
    } else if (m_unk2130 != 0) {
        ((FontManager *)(gInterface + 0x80))->ProcessSubtitle((int)fRes);
    }

    if (m_unk213C == 0) {
        SetBgNodesOpacity((PArray *)m_unk80, 0.0f);
        SetBgNodesOpacity((PArray *)m_unk70, 1.0f);
        KillActorFx();
        ((FontManager *)(gInterface + 0x80))->RemoveAll(true);
        if (m_unk213D & 1) {
            Unload(true);
        } else {
            UpdatePlayer();
        }
        *(unsigned char *)(gGfxEng + 0x158E26) = 1;
    } else {
        *(unsigned char *)(gGfxEng + 0x158E26) = 0;
    }
    return m_unk213C != 0;
}

// FUNCTION: 0x001BD270 UpdatePlayer__15PCutScenePlayerFv
void PCutScenePlayer::UpdatePlayer() {
    char *pElem;
    m_unkB4 = 0;
    pElem = (m_unkB0 != 0) ? (char *)m_unkB8[0] : 0;
    if (pElem != 0) {
        do {
            if (*(Player **)(pElem + 0x38) != 0) {
                ((Player *)*(void **)(pElem + 0x38))->FinishCutScene(*(PMeshNode **)(pElem + 0x30), (PMat4 *)this, m_unk213D & 2);
                ((PArray *)(*(char **)(pElem + 0x30) + 0x14))->Remove(*(void **)(pElem + 0x34));
                break;
            }
            unsigned int nIdx = m_unkB4 + 1;
            m_unkB4 = nIdx;
            pElem = (nIdx < m_unkB0) ? (char *)m_unkB8[m_unkB4] : 0;
        } while (pElem != 0);
    }
    ((FontManager *)(gInterface + 0x80))->RemoveAll(true);
}

// FUNCTION: 0x001BD340 Unload__15PCutScenePlayerFb
void PCutScenePlayer::Unload(bool bFlag) {
    m_unk40 = 0;
    unsigned int nCount = m_unkA0;
    for (unsigned int nIdx = 0; nIdx < nCount; nIdx++) {
        PCutSceneAnim *pAnim = (PCutSceneAnim *)((nIdx < m_unkA0) ? m_unkA8[nIdx] : 0);
        if (pAnim != 0) {
            delete pAnim;
        }
    }
    if (m_unkA8 != 0) {
        m_unkA0 = 0;
        m_unkA4 = 0;
    }
    unsigned int nCount2 = m_unkB0;
    for (unsigned int nIdx2 = 0; nIdx2 < nCount2; nIdx2++) {
        char *pElem = (char *)((nIdx2 < m_unkB0) ? m_unkB8[nIdx2] : 0);
        if (pElem != 0) {
            if (*(void **)(pElem + 0x30) != 0) {
                if (bFlag) {
                    if (*(void **)(pElem + 0x38) != 0) {
                        ((Player *)*(void **)(pElem + 0x38))->FinishCutScene((PMeshNode *)*(void **)(pElem + 0x30), (PMat4 *)this, m_unk213D & 2);
                        ((PArray *)(*(char **)(pElem + 0x30) + 0x14))->Remove(*(void **)(pElem + 0x34));
                    }
                }
                delete (PMNode *)*(void **)(pElem + 0x30);
            }
            if (pElem != 0) {
                __dt__22PMeshNodeAnimDataTableFv((PMeshNodeAnimDataTable *)pElem, -1);
                __dl__FPv(pElem);
            }
        }
    }
    if (m_unkB8 != 0) {
        m_unkB0 = 0;
        m_unkB4 = 0;
    }
    if (m_unk48 != 0) {
        delete m_unk48;
        m_unk48 = 0;
    }
    if (m_unk4C != 0) {
        delete m_unk4C;
        m_unk4C = 0;
    }
    if (m_unk50 != 0) {
        delete m_unk50;
        m_unk50 = 0;
    }
    if (m_unk54 != 0) {
        delete m_unk54;
        m_unk54 = 0;
    }
    if (*(void **)(m_unk60 + 8) != 0) {
        *(unsigned int *)m_unk60 = 0;
        *(int *)(m_unk60 + 4) = 0;
    }
    if (*(void **)(m_unk70 + 8) != 0) {
        *(unsigned int *)m_unk70 = 0;
        *(int *)(m_unk70 + 4) = 0;
    }
    if (*(void **)(m_unk80 + 8) != 0) {
        *(unsigned int *)m_unk80 = 0;
        *(int *)(m_unk80 + 4) = 0;
    }
    if (*(void **)(m_unk90 + 8) != 0) {
        *(unsigned int *)m_unk90 = 0;
        *(int *)(m_unk90 + 4) = 0;
    }
    ((PGrimReaperCape *)m_unk100)->Enable(false, 0);
    sceVu0UnitMatrix(this);
    m_unk213C = 0;
}

// Cutscene file header read as one 0xBC-byte block; offsets follow the Load body.
struct CutSceneHeader {
    unsigned int magic;       // 0x00
    unsigned int unk04;       // 0x04
    unsigned int bgFlag;      // 0x08
    unsigned int actorFlag;   // 0x0C
    unsigned int nodeA;       // 0x10
    unsigned int nodeB;       // 0x14
    unsigned int chanCount;   // 0x18
    unsigned int subFlag;     // 0x1C
    short time0;              // 0x20
    short time1;              // 0x22
    char mtx0[0x10];          // 0x24
    char mtx1[0x10];          // 0x34
    char mtx2[0x10];          // 0x44
    char mtx3[0x10];          // 0x54
    char mtx4[0x10];          // 0x64
    char _pad74[0x40];        // 0x74
    unsigned int nodeC;       // 0xB4
    unsigned int nodeD;       // 0xB8
};

// DRAFT: 0x001BD5F0 Load__15PCutScenePlayerFP8PPakFileP16PResourceManagerP9PMeshNodeii
// note: DIFF 284. Float ternary store and prologue match; open: tail branches 6 words short (0x004C/0x00D8/0x00FC), c.eq.s operand order at 0x0128, memcpy row addresses held in s1/s2/s3/s6. Tried: local temp, volatile store, ternary (kept), `0.0f != fTime` (no change), `&aMtx[k]` (no change).
int PCutScenePlayer::Load(PPakFile *pFile, PResourceManager *pResMgr, PMeshNode *pRoot, int nA, int nB) {
    CutSceneHeader hdr;
    float aMtx[5][4];
    unsigned int aChan[4];
    int nTag;
    PAnimSlots *pAnim;
    void *pObj;
    unsigned int i;
    float fTime;

    Unload(true);
    if (pFile == 0) {
        return 0;
    }
    m_unk213D = (signed char)nB;
    m_unk44 = (int)pResMgr;
    m_unk5C = nA;
    m_unk2130 = nA;
    m_unkF4 = (nB & 0x40) ? 0.6f : 1.0f;
    CDS_ASSERT(0x57, pRoot != 0, "pRootNode");
    m_unk40 = (PMNode *)pRoot;
    if (((PCDFile *)pFile)->Read(&hdr, 0xBC) != 0xBC) {
        printf("\nError reading cutscene file %s", pFile);
        return 0;
    }
    if (hdr.magic != 0xFADE0000) {
        printf("\nInvalid cutscene file %s", pFile);
        return 0;
    }
    fTime = (float)hdr.time0 / 1000.0f;
    m_unk2134 = fTime;
    if (fTime != 0.0f) {
        m_unk213D |= 8;
    }
    m_unk2138 = (float)hdr.time1 / 1000.0f;
    memcpy(aMtx[0], hdr.mtx0, 0x10);
    memcpy(aMtx[1], hdr.mtx1, 0x10);
    memcpy(aMtx[2], hdr.mtx2, 0x10);
    memcpy(aMtx[3], hdr.mtx3, 0x10);
    memcpy(aMtx[4], hdr.mtx4, 0x10);
    FastMath_ComputeMatrix((float (*)[4][4])this, aMtx, aMtx + 1, aMtx + 2, aMtx + 3, aMtx + 4, 0);
    if (LoadNodeNameTable(pFile, hdr.nodeA, (PArray *)m_unk60) == 0) {
        return 0;
    }
    if (LoadNodeNameTable(pFile, hdr.nodeB, (PArray *)m_unk70) == 0) {
        return 0;
    }
    if (LoadNodeNameTable(pFile, hdr.nodeC, (PArray *)m_unk80) == 0) {
        return 0;
    }
    if (LoadNodeNameTable(pFile, hdr.nodeD, (PArray *)m_unk90) == 0) {
        return 0;
    }
    for (i = 0; i < hdr.chanCount; i++) {
        nTag = 0;
        if (((PCDFile *)pFile)->Read(&nTag, 4) != 4) {
            return 0;
        }
        if (nTag == 4) {
            if (((PCDFile *)pFile)->Read(aChan, 0x10) != 0x10) {
                return 0;
            }
            CDS_ASSERT(0xB7, aChan[1] < 6U, "aHeader.uNumChannels <= CHANNEL_MAX");
            switch (i) {
            case 0:
                pObj = __nw__FUi(0x34);
                if (pObj != 0) {
                    pObj = __ct__10PAnimFrameFs(pObj, 0);
                }
                m_unk48 = (PCutSceneAnim *)pObj;
                CDS_ASSERT(0xBC, m_unk48 != 0, "mpoCameraPosAnim");
                pAnim = (PAnimSlots *)m_unk48;
                break;
            case 1:
                pObj = __nw__FUi(0x20);
                if (pObj != 0) {
                    pObj = __ct__5PAnimFv(pObj);
                }
                m_unk4C = (PCutSceneAnim *)pObj;
                CDS_ASSERT(0xC2, m_unk4C != 0, "mpoCameraLookAtAnim");
                pAnim = (PAnimSlots *)m_unk4C;
                break;
            case 2:
                pObj = __nw__FUi(0x20);
                if (pObj != 0) {
                    pObj = __ct__5PAnimFv(pObj);
                }
                m_unk50 = (PCutSceneAnim *)pObj;
                CDS_ASSERT(0xC8, m_unk50 != 0, "mpoCameraUpTwistAnim");
                pAnim = (PAnimSlots *)m_unk50;
                break;
            }
            if (pAnim->Load(pFile, aChan) == 0) {
                return 0;
            }
            pAnim->EnableAnim(true);
        }
    }
    *(int *)&m_unk58 = 0;
    if (hdr.subFlag != 0) {
        nTag = 0;
        if (((PCDFile *)pFile)->Read(&nTag, 4) != 4) {
            return 0;
        }
        if (nTag == 4) {
            if (((PCDFile *)pFile)->Read(aChan, 0x10) != 0x10) {
                return 0;
            }
            pObj = __nw__FUi(0x20);
            if (pObj != 0) {
                pObj = __ct__5PAnimFv(pObj);
            }
            m_unk54 = (PCutSceneAnim *)pObj;
            CDS_ASSERT(0xEB, m_unk54 != 0, "mpoSubtitleAnim");
            pAnim = (PAnimSlots *)m_unk54;
            if (pAnim->Load(pFile, aChan) == 0) {
                return 0;
            }
            if (gInterface[0x93] == 0) {
                ((PAnimSlots *)m_unk54)->EnableAnim(true);
            } else {
                if (m_unk54 != 0) {
                    delete m_unk54;
                }
                m_unk54 = 0;
            }
        }
    }
    if (hdr.bgFlag != 0 && LoadBgAnims(pFile, hdr.bgFlag) == 0) {
        return 0;
    }
    if (hdr.actorFlag != 0) {
        if (LoadActors(pFile, hdr.actorFlag) == 0) {
            return 0;
        }
        return 1;
    }
    return 1;
}

// FUNCTION: 0x001BDBD0 __dt__15PCutScenePlayerFv
PCutScenePlayer::~PCutScenePlayer() {
    Unload(true);
    __dt__15PGrimReaperCapeFv((char *)this + 0x100, -1);
    __dt__6PArrayFv((char *)this + 0xB0, -1);
    __dt__6PArrayFv((char *)this + 0xA0, -1);
    __dt__6PArrayFv((char *)this + 0x90, -1);
    __dt__6PArrayFv((char *)this + 0x80, -1);
    __dt__6PArrayFv((char *)this + 0x70, -1);
    __dt__6PArrayFv((char *)this + 0x60, -1);
}

// FUNCTION: 0x001BDC80 __ct__15PCutScenePlayerFv
PCutScenePlayer::PCutScenePlayer() {
    sceVu0UnitMatrix(this);
    __ct__6PArrayFv((PArray *)m_unk60);
    __ct__6PArrayFv((PArray *)m_unk70);
    __ct__6PArrayFv((PArray *)m_unk80);
    __ct__6PArrayFv((PArray *)m_unk90);
    __ct__6PArrayFv((PArray *)&m_unkA0);
    __ct__6PArrayFv((PArray *)&m_unkB0);
    __ct__15PGrimReaperCapeFv((PGrimReaperCape *)m_unk100);
    m_unk44 = 0;
    m_unk40 = 0;
    m_unk48 = 0;
    m_unk4C = 0;
    m_unk50 = 0;
    m_unk54 = 0;
    m_unk213C = 0;
    m_unk213D = 1;
    ((PArray *)&m_unkB0)->Allocate(0x10);
    ((PArray *)&m_unkA0)->Allocate(4);
    ((PArray *)m_unk60)->Allocate(0xC);
    ((PArray *)m_unk70)->Allocate(0xC);
    ((PArray *)m_unk80)->Allocate(0xC);
    ((PArray *)m_unk90)->Allocate(0xC);
}
