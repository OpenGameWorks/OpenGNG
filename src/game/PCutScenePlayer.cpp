// FLAGS: -str readonly
#include "types.h"
#include "PCutScenePlayer.h"
#include "PMat4.h"

// TODO(header): foreign declarations
class PVec3 {
public:
    PVec3 operator-(PVec3 &rhs);
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
class PMeshNode {
public:
    void TestMeshNodeInFrustum(PFrustrum *pFrustrum);
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
};
class PMNode {
public:
    virtual ~PMNode();
    virtual void Render(PLightManager *pLightMgr, int nA, int nB);
    void ProcessFxTriggers(float fTime, PMat4 *pMat, bool bA, bool bB);
    PMNode *Find(unsigned int nId);
    void RecurseSetFade(float fFade);
    void SetAllFrustrumTest(eBoxIntersect eMode);
};
class PArray {
public:
    void Add(void *pItem);
    void Remove(void *pItem);
    void Allocate(unsigned int nSize);
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
};
class Player {
public:
    void FinishCutScene(PMeshNode *pNode, PMat4 *pMat, int nFlag);
    void RenderCutScene();
};
class FontManager {
public:
    void RemoveAll(bool bFlag);
    void InitSubTitle(int nArg);
};

extern unsigned char gInterface[];
extern char gGfxEng[1504384];
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void __dt__15PGrimReaperCapeFv(void *pThis, short nFlag);
class PMeshNodeAnimDataTable;
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
class PResourceManager {
public:
    int GetResource(unsigned int nId, bool bFlag);
};
class PCutSceneAnim {
public:
    virtual ~PCutSceneAnim();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
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

// DRAFT: 0x001BBBA0 KillActorFx__15PCutScenePlayerFv
// note: 33 differing lines; the diff starts at the prologue loop guard (original uses sltu $at,$zero,$s0 with a branch over the loop, ours tests the count directly) and the saved s1 register differs.
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

// DRAFT: 0x001BBD10 GetViewMatrix__15PCutScenePlayerFP5PMat4
// note: DIFF 138; original frame 0xC0 with s0..s5 saves and scratch at 0xB0, ours frame 0x90 with s0..s2; cop1 0x46010344 (sqrt) not reproduced; copying vDelta via sceVu0CopyVector gave 139
void PCutScenePlayer::GetViewMatrix(PMat4 *pMat) {
    PVec3 vDelta = *(PVec3 *)((char *)this + 0xE0) - *(PVec3 *)((char *)this + 0xC0);
    float *v = (float *)&vDelta;
    float fLen = sqrtf(v[0] * v[0] + v[2] * v[2]);
    float fPitch = atan2f(-v[1], fLen) * 57.29578f;
    *(float *)((char *)this + 0xD0) = fPitch;
    fPitch += 180.0f;
    *(float *)((char *)this + 0xD0) = fPitch;
    Round180__Ff(fPitch);
    *(float *)((char *)this + 0xD4) = atan2f(v[0], -v[2]) * 57.29578f;
    *(float *)((char *)this + 0xD8) = *(float *)((char *)this + 0xF0);
    sceVu0UnitMatrix(pMat);
    pMat->RotateY(*(float *)((char *)this + 0xD4));
    pMat->RotateX(*(float *)((char *)this + 0xD0));
    pMat->RotateZ(*(float *)((char *)this + 0xD8));
    float *m = (float *)pMat;
    float c0[4] = { m[0], m[4], m[8], 1.0f };
    float c1[4] = { m[1], m[5], m[9], 1.0f };
    float c2[4] = { m[2], m[6], m[10], 1.0f };
    m[12] = -sceVu0InnerProduct(c0, (float *)((char *)this + 0xC0));
    m[13] = -sceVu0InnerProduct(c1, (float *)((char *)this + 0xC0));
    m[14] = -sceVu0InnerProduct(c2, (float *)((char *)this + 0xC0));
    *(float *)((char *)this + 0xD4) = atan2f(-m[2], -m[10]) * 57.29578f;
}

// DRAFT: 0x001BBEE0 LoadBgAnims__15PCutScenePlayerFP8PPakFileUi
// note: 37 differing words; ours lacks the join nop after the __ct result move (original 0x1BBF8C), so every later word shifts by one. Vtable call uses $v0 where original uses $t9. Tried: function-scope pObj, temp for __ct result, ternary (49), else-form guard (37), typed fn-pointer for release call (37).
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
            if (pObj == 0) {
            } else {
                pObj = __ct__22PMeshNodeAnimDataTableFv(pObj);
            }
            if (pObj == 0) {
                CdsAssert("PCutScenePlayer.cpp", 0x3D9, "apoAnimData");
            }
            if (Load__22PMeshNodeAnimDataTableFP8PPakFile16ePsx2FileVersion(pObj, pFile, 0x20000) == 0) {
                if (pObj != 0) {
                    void (*pfnRelease)(PMeshNodeAnimDataTable *, int) = (void (*)(PMeshNodeAnimDataTable *, int))(*(void ***)pObj)[2];
                    pfnRelease(pObj, 1);
                }
                return false;
            }
            ((PArray *)m_unkA0)->Add(pObj);
            i++;
        } while (i < nFlag);
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

// DRAFT: 0x001BC770 SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf
// note: matches at -O4 only; at the file's -O4,p the index loop is strength-reduced (offset in s1) where the original recomputes sll i,2 and reloads the count each pass. Tried ternary tail and an inline PArray::Get accessor (for over m_unk0).
void PCutScenePlayer::SetBgNodesOpacity(PArray *pArray, float fOpacity) {
    if (pArray == 0) {
        CdsAssert("PCutScenePlayer.cpp", 0x2E1, "poNodeTable");
    }
    if (m_unk40 != 0) {
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
    ((FontManager *)(gInterface + 0x1790))->RemoveAll(true);
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
// note: 64 differing words; frame 0x80 vs 0x60 (ours saves s1..s5, original s0..s3), this in s4 vs s2, i/pItem registers permuted, constant copied via temp at sp+0x70 vs direct to sp+0x50. Tried: hoisting i (no change), direct pItem+0x30 reloads (88->64), non-static int[4] local (107).
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
        ((FontManager *)(gInterface + 0x1790))->InitSubTitle(m_unk2130);
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

// DRAFT: 0x001BCB60 Render__15PCutScenePlayerFP13PLightManager
// note: DIFF 55; frame 0x70 vs 0x60, this in s5 not s3, pItem in s2 not s4; tried pItem hoist/in-loop, i init placement, void** items
void PCutScenePlayer::Render(PLightManager *pLightMgr) {
    if (m_unk40 != 0) {
        m_unk40->Render(0, 0x80, 0);
    }
    gGfxEng[0x158E22] = 1;
    unsigned int n = m_unkB0;
    unsigned int i;
    if (n != 0) {
        i = 0;
        do {
            void **pItem = (i < m_unkB0) ? (void **)m_unkB8[i] : 0;
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
            i++;
        } while (i < n);
    }
    ((PDynamicSplinePatch *)m_unk100)->Render();
    gGfxEng[0x158E22] = 0;
}

// DRAFT: 0x001BCCF0 CullTest__15PCutScenePlayerFP9PFrustrum
// note: 49 differing words, register permutation: original this=$s4, frustum=$s3, element/node=$s2, nCount=$s0; ours this=$s3, frustum=$s2, element/node=$s4, nCount=$s0 with a different save order. Tried: char* element local (permutation remains), hoisted pNode (still 49), reverted.
void PCutScenePlayer::CullTest(PFrustrum *pFrustrum) {
    if (m_unk40 != 0) {
        ((PMeshNode *)m_unk40)->TestMeshNodeInFrustum(pFrustrum);
    }
    unsigned int nCount = m_unkB0;
    unsigned int i = 0;
    if (i < nCount) {
        do {
            char *pElem = 0;
            if (i < m_unkB0) {
                pElem = (char *)m_unkB8[i];
            }
            if (pElem == 0) {
                CdsAssert("PCutScenePlayer.cpp", 0x21F, "apData");
            }
            char *pNode = *(char **)(pElem + 0x34);
            if (pNode != 0) {
                *(int *)(pNode + 0x18) = 0;
                int nMode = 2;
                void *pBox = 0;
                if (*(void **)(pNode + 0x14) != 0) {
                    pBox = **(void ***)(pNode + 0x1C);
                }
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
    ((FontManager *)(gInterface + 0x1790))->RemoveAll(true);
}

// DRAFT: 0x001BD340 Unload__15PCutScenePlayerFb
// note: 153 lines differ; frame 0x70 with six saved regs vs 0x60 with five; this/bFlag/count/index in s1/s0/s3/s1 vs s3/s2/s0/s1; tried signed loop locals (153), swapped declaration order (154)
void PCutScenePlayer::Unload(bool bFlag) {
    unsigned int nIdx;
    unsigned int nCount;
    m_unk40 = 0;
    nCount = m_unkA0;
    for (nIdx = 0; nIdx < nCount; nIdx++) {
        PCutSceneAnim *pAnim = (nIdx < m_unkA0) ? (PCutSceneAnim *)m_unkA8[nIdx] : 0;
        if (pAnim != 0) {
            delete pAnim;
        }
    }
    if (m_unkA8 != 0) {
        m_unkA0 = 0;
        m_unkA4 = 0;
    }
    nCount = m_unkB0;
    for (nIdx = 0; nIdx < nCount; nIdx++) {
        char *pElem = (nIdx < m_unkB0) ? (char *)m_unkB8[nIdx] : 0;
        if (pElem != 0) {
            if (*(void **)(pElem + 0x30) != 0) {
                if (bFlag) {
                    if (*(void **)(pElem + 0x38) != 0) {
                        ((Player *)*(void **)(pElem + 0x38))->FinishCutScene((PMeshNode *)*(void **)(pElem + 0x30), (PMat4 *)this, m_unk213D & 2);
                        ((PArray *)(*(char **)(pElem + 0x30) + 0x14))->Remove(*(void **)(pElem + 0x34));
                    }
                }
                if (*(void **)(pElem + 0x30) != 0) {
                    delete (PMNode *)*(void **)(pElem + 0x30);
                }
            }
            __dt__22PMeshNodeAnimDataTableFv((PMeshNodeAnimDataTable *)pElem, -1);
            __dl__FPv(pElem);
        }
    }
    if (m_unkB8 != 0) {
        m_unkB0 = 0;
        m_unkB4 = 0;
    }
    if (m_unk48 != 0) {
        delete m_unk48;
    }
    m_unk48 = 0;
    if (m_unk4C != 0) {
        delete m_unk4C;
    }
    m_unk4C = 0;
    if (m_unk50 != 0) {
        delete m_unk50;
    }
    m_unk50 = 0;
    if (m_unk54 != 0) {
        delete m_unk54;
    }
    m_unk54 = 0;
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

// DRAFT: 0x001BDC80 __ct__15PCutScenePlayerFv
// note: 66 differing words; ours uses a 0x20 frame with a `this` spill at 0x1C($sp) and reloads, while the original uses a 0x80 frame, saves s0..s6, keeps this in $s0 (set in the sceVu0UnitMatrix delay slot) and caches the sub-object pointers in s1..s6. Tried: sp local, named pA locals, pThis assigned after the sceVu0UnitMatrix call, member-array addressing (pThis->m_unk60 etc.); none reduced the count.
PCutScenePlayer::PCutScenePlayer() {
    PCutScenePlayer *pThis;
    PArray *pA60;
    PArray *pA70;
    PArray *pA80;
    PArray *pA90;
    PArray *pAA0;
    PArray *pAB0;

    sceVu0UnitMatrix(this);
    pThis = this;
    pA60 = (PArray *)pThis->m_unk60;
    __ct__6PArrayFv(pA60);
    pA70 = (PArray *)pThis->m_unk70;
    __ct__6PArrayFv(pA70);
    pA80 = (PArray *)pThis->m_unk80;
    __ct__6PArrayFv(pA80);
    pA90 = (PArray *)pThis->m_unk90;
    __ct__6PArrayFv(pA90);
    pAA0 = (PArray *)pThis->m_unkA0;
    __ct__6PArrayFv(pAA0);
    pAB0 = (PArray *)&pThis->m_unkB0;
    __ct__6PArrayFv(pAB0);
    __ct__15PGrimReaperCapeFv((PGrimReaperCape *)pThis->m_unk100);
    pThis->m_unk44 = 0;
    pThis->m_unk40 = 0;
    pThis->m_unk48 = 0;
    pThis->m_unk4C = 0;
    pThis->m_unk50 = 0;
    pThis->m_unk54 = 0;
    pThis->m_unk213C = 0;
    pThis->m_unk213D = 1;
    pAB0->Allocate(0x10);
    pAA0->Allocate(4);
    pA60->Allocate(0xC);
    pA70->Allocate(0xC);
    pA80->Allocate(0xC);
    pA90->Allocate(0xC);
}
