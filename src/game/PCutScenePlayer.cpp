// FLAGS: -str readonly
#include "types.h"
#include "PCutScenePlayer.h"

// TODO(header): foreign declarations
class PMat4;
class PFrustrum {
public:
    int IntersectBox(float (*pBox)[2][4], PMat4 *pMat);
};
class PMeshNode {
public:
    void TestMeshNodeInFrustum(PFrustrum *pFrustrum);
};
enum eBoxIntersect { eBoxIntersect_Unused };
class PMNode {
public:
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
};
class Player {
public:
    void FinishCutScene(PMeshNode *pNode, PMat4 *pMat, int nFlag);
};
class FontManager {
public:
    void RemoveAll(bool bFlag);
};

extern unsigned char gInterface[];
extern unsigned char gGfxEng[];
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void __dt__15PGrimReaperCapeFv(void *pThis, short nFlag);
class PMeshNodeAnimDataTable;
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" PMeshNodeAnimDataTable *__ct__22PMeshNodeAnimDataTableFv(PMeshNodeAnimDataTable *pThis);
extern "C" int Load__22PMeshNodeAnimDataTableFP8PPakFile16ePsx2FileVersion(PMeshNodeAnimDataTable *pThis, PPakFile *pFile, int nVersion);
extern "C" void *__ct__6PArrayFv(PArray *pThis);
extern "C" void *__ct__15PGrimReaperCapeFv(PGrimReaperCape *pThis);
extern "C" void sceVu0UnitMatrix(void *pMat);

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

// DRAFT: 0x001BBC40 LoadNodeNameTable__15PCutScenePlayerFP8PPakFileUiP6PArray
// note: 9 differing lines, all in the return tail: the original has a nop before the `return true` load and its false branch targets the epilogue one slot later. Tried: bOk flag (worse, extra s4 and 0x70 frame), while loop (15+ lines), ++i loop test (9, same), for loop (31), nCount != 0 guard (beqz instead of sltu).
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

// FUNCTION: 0x001BC770 SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf
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

// DRAFT: 0x001BD270 UpdatePlayer__15PCutScenePlayerFv
// note: 9 differing lines; the loop matches, but the original has one extra nop before the RemoveAll call, which shifts the tail by one instruction. Tried: void* and char* element pointer, node local, for(;;) top test, guarded do-while (kept), index local, direct m_unkB4 increment (16 lines, reverted).
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
