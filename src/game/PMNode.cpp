// FLAGS: -str readonly
#include "types.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern "C" void __dt__5PMeshFv(void *, short);
extern "C" void SetSTAnimOptions__5PMeshFb(void *, bool);
extern "C" void *__nw__FUi(unsigned int);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" PObjectDisplayList *__ct__18PObjectDisplayListFv(PObjectDisplayList *);
extern "C" void __dt__18PObjectDisplayListFv(PObjectDisplayList *, short);
extern "C" void *__dt__6PArrayFv(void *pThis, short nFlag);
// TODO(header): PArray::Find is not declared in PArray.h; same declaration as Peddler.cpp.
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" char __vt__9PResource[];
extern "C" int Create__18PObjectDisplayListFP6PMNodePb(PObjectDisplayList *, PMNode *, bool *);
// TODO(header): PAnimFrame is the 0x34-byte frame object held at PMNode+0x24; only its vtable slots 0x0C and 0x10 are named here.
class PAnimFrame {
public:
    virtual ~PAnimFrame();
    virtual void Slot01();
    virtual int LoadHeader(void *pFile, void *pHeader);
};
extern "C" PAnimFrame *__ct__10PAnimFrameFP5PAnim(PAnimFrame *, PAnim *);
extern "C" PAnimFrame *__ct__10PAnimFrameFs(PAnimFrame *, short);
extern "C" PAnim *__ct__5PAnimFv(PAnim *);
class PMat4;
class PDisplayList {
public:
    void AddMatrix(PMat4 *pMat, unsigned int uIdx);
};
// TODO(header): gGfxEng is a PDisplayList pointer. The original reaches it with lui/lw, which needs a placeholder larger than 8 bytes.
struct PGfxEngineRef {
    PDisplayList *pDisplayList;
    char _pad04[0x10];
};
extern PGfxEngineRef gGfxEng;
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    int IsAmbientSoundByID(unsigned int nID);
    int IsObjectPlayingAmbientByID(unsigned int p0, unsigned int p1, unsigned int p2);
    int PlaySoundPMNode(unsigned int p0, unsigned int p1, const PMNode *pNode);
    char _pad000[0x10];
};
extern PSound gSound;
// TODO(header): mst_NextPMNodeRef__6PMNode is a static PMNode counter; a 4-byte int keeps it gp-relative as the original does.
extern "C" int mst_NextPMNodeRef__6PMNode;
class PPakFile;
// TODO(header): PCDFile is a foreign class; only Read is needed here.
class PCDFile {
public:
    int Read(void *pBuf, unsigned int size);
};

class AnimData;
#include "PArray.h"

// TODO(header): PAnim, PChannel and eAnimType belong to the animation headers. Placeholder shapes; only the names, the FindChannel/AnimateBox signatures and the byte at PAnim+0xA matter here.
enum eAnimType { eAnimType_Placeholder = 0 };
class PChannel {
public:
    void *AnimateBox(float fTime, unsigned char &bOut);
};
class PAnim {
public:
    PChannel *FindChannel(eAnimType eType);
    char _pad000[0xA];
    unsigned char m_unkA;
};

// TODO(header): PMNode objects carry a vptr at offset 0; this view names the slots SetFrameTime calls on a child.
class PNodeVirtual {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02(float fTime);
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05(AnimData *pAnim);
};

// Object held at PMNode+0x24. Slot 18 (0x48) is the frame-rate query; slots 0..17 are unknown.
class PFrameSource {
public:
    virtual ~PFrameSource();   // two slots in CodeWarrior (complete and deleting)
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(AnimData *pAnim);
    virtual void Slot11(int nCount);
    virtual float Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual float GetFrameRate();
    int m_unk04;            // 0x04 state; 0x3E8 and 1 are excluded from CheckAnimated
    char _pad08[2];
    unsigned char m_unk0A;  // 0x0A nonzero keeps the object alive in RemoveNullAnimation
};

// FUNCTION: 0x00191830 PlaySound__6PMNodeFUi
int PMNode::PlaySound(unsigned int arg0) {
    int var_s0 = 0;
    int var_s1 = 1;
    if (gSound.IsAmbientSoundByID(arg0) != 0) {
        var_s0 = 1;
        m_unkF4 = 1;
        if (gSound.IsObjectPlayingAmbientByID(arg0, m_unkE8, 0x20) != 0) {
            var_s1 = 0;
        }
    }
    if (var_s1 != 0) {
        m_unkEC = gSound.PlaySoundPMNode(arg0, m_unkE8, this);
        if (var_s0 != 0) {
            m_unkF0 = m_unkEC;
        }
    } else {
        m_unkEC = 0;
    }
    return m_unkEC;
}

// DRAFT: 0x001918F0 UpdateCameraFade__6PMNodeFb
// note: 23 words differ: lb vs lbu on m_unk3E, extra andi after ori, nop/epilogue order; int local gives 50, bool-local goto variant is best.
void PMNode::UpdateCameraFade(bool bFlag) {
    bool bNext = bFlag;
    unsigned char bVal;
    if (bNext) {
        bVal = m_unk3E | 0x20;
        goto store;
    }
    {
        void *pObj = m_unk24;
        int nVal = 0;
        if (pObj != 0) {
            nVal = ((int *)pObj)[1];
        }
        if ((unsigned int)(nVal - 500) < 10) {
            bNext = true;
            bVal = m_unk3E | 0x20;
store:
            m_unk3E = bVal;
        }
    }
    m_unk18 = 0;
    PMNode *pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->UpdateCameraFade(bNext);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x001919E0 CreateObjectDisplayList__6PMNodeFv
int PMNode::CreateObjectDisplayList() {
    PObjectDisplayList *p = m_pObjDisplayList;
    if (p != 0) {
        __dt__18PObjectDisplayListFv(p, 1);
        m_pObjDisplayList = 0;
    }
    p = (PObjectDisplayList *)__nw__FUi(0x1F0);
    if (p != 0) {
        p = __ct__18PObjectDisplayListFv(p);
    }
    m_pObjDisplayList = p;
    if (m_pObjDisplayList == 0) {
        CdsAssert__FPciPc("PMNode.cpp", 0x99E, "mpObjDisplayList");
    }
    if (Create__18PObjectDisplayListFP6PMNodePb(m_pObjDisplayList, this, &m_unkD4) == 0) {
        __dt__18PObjectDisplayListFv(m_pObjDisplayList, 1);
        m_pObjDisplayList = 0;
        return 0;
    }
    return 1;
}

// DRAFT: 0x00192CC0 CopyFxTriggers__6PMNodeFR6PMNode
// note: 32 lines differ in the current form (count>0 guard, do-while). Earlier 26 for for/while/do-while variants not reproduced; count!=0 guard also 32.
void PMNode::CopyFxTriggers(PMNode &src) {
    unsigned int count = src.m_unkD8;
    unsigned int idx = 0;
    if (count > 0) {
        do {
            tagParticleFxTrigger *pTrig = 0;
            if (idx < src.m_unkD8) {
                pTrig = src.m_unkE0[idx];
            }
            if (pTrig != 0 && !(*(int *)((char *)pTrig + 0x24) & 4)) {
                AddFxTrigger(pTrig, false);
            }
            idx++;
        } while (idx < count);
    }
}

// DRAFT: 0x00192D70 AddFxTriggers__6PMNodeFP6PArrayb
// note: 9 lines differ; original has one extra nop before the epilogue. Tried if(count!=0), if(count>0), if(0<count), for loop, bool guard temp, idx-zero guard with ++idx test.
void PMNode::AddFxTriggers(PArray *pArr, bool bFlag) {
    tagParticleFxTrigger *pTrig;
    unsigned int count;
    unsigned int idx;
    if (pArr == 0) {
        CdsAssert__FPciPc("PMNode.cpp", 0x753, "poTriggers");
    }
    count = *(unsigned int *)pArr;
    idx = 0;
    if (idx < count) {
        do {
            pTrig = 0;
            if (idx < *(unsigned int *)pArr) {
                pTrig = (*(tagParticleFxTrigger ***)((char *)pArr + 8))[idx];
            }
            AddFxTrigger(pTrig, bFlag);
        } while (++idx < count);
    }
}

// FUNCTION: 0x00192E30 AddFxTrigger__6PMNodeFP20tagParticleFxTriggerb
int PMNode::AddFxTrigger(tagParticleFxTrigger *pTrigger, bool bFlag) {
    char *pBlk = (char *)__nw__FUi(0x28);
    if (pBlk == 0) {
        CdsAssert__FPciPc("PMNode.cpp", 0x746, "apTrigger");
    }
    memcpy(pBlk, pTrigger, 0x28);
    *(int *)(pBlk + 0x20) = 0;
    *(int *)(pBlk + 0x24) = bFlag ? 4 : 0;
    ((PArray *)((char *)this + 0xD8))->Add(pBlk);
    return 1;
}

// FUNCTION: 0x00192ED0 LoadFxTriggers__6PMNodeFP8PPakFile
int PMNode::LoadFxTriggers(PPakFile *pFile) {
    unsigned int nCount = 0;
    unsigned int idx;
    char *pBlk;
    DestroyFxTriggers(false, false, false);
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    idx = 0;
    while (idx < nCount) {
        pBlk = (char *)__nw__FUi(0x28);
        if (pBlk == 0) {
            CdsAssert__FPciPc("PMNode.cpp", 0x732, "apTrigger");
        }
        if (((PCDFile *)pFile)->Read(pBlk, 0x28) != 0x28) {
            return 0;
        }
        *(int *)(pBlk + 0x20) = 0;
        *(int *)(pBlk + 0x24) = 0;
        ((PArray *)((char *)this + 0xD8))->Add(pBlk);
        idx++;
    }
    return 1;
}

// DRAFT: 0x00192FD0 SetAllFade__6PMNodeFf
// note: 5 words differ, the join nop at 0x84 before the epilogue and the f20 copy of fFade in the first beqz delay slot. Tried: local float copy (5), do-while on child count (30).
void PMNode::SetAllFade(float fFade) {
    PMNode *pChild;
    unsigned int idx;
    m_unk2C = fFade;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->SetAllFade(fFade);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193070 GetFrameRate__6PMNodeFv
float PMNode::GetFrameRate() {
    void *pObj = m_unk24;
    if (pObj != 0) {
        return ((PFrameSource *)pObj)->GetFrameRate();
    }
    return 0.0f;
}

// FUNCTION: 0x001930B0 SetFrameRate__6PMNodeFfb
void PMNode::SetFrameRate(float fRate, bool bFlag) {
    PMNode *pChild;
    void *pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot16();
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetFrameRate(fRate, bFlag);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193380 FindBone__6PMNodeFUi
PMNode *PMNode::FindBone(unsigned int uID) {
    PMNode *pChild;
    if (uID == 0xFFFFFFFFU) {
        return 0;
    }
    if (m_unkD0 == (int)uID) {
        return this;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            PMNode *pFound = pChild->FindBone(uID);
            unsigned int uNext;
            if (pFound != 0) {
                return pFound;
            }
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0;
}

// FUNCTION: 0x00193450 RecurseEnableBone__6PMNodeFP6PArrayb
void PMNode::RecurseEnableBone(PArray *pArr, bool bFlag) {
    if (m_unk10 != 0) {
        if (Find__6PArrayFPv(pArr, this) >= 0) {
            if (!bFlag) {
                pArr->Remove(this);
            }
        } else if (bFlag) {
            pArr->Add(this);
        }
    }
    m_unk18 = 0;
    PMNode *pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->RecurseEnableBone(pArr, bFlag);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193540 BuildDispList__6PMNodeFP6PArray
void PMNode::BuildDispList(PArray *pArr) {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk10 != 0 || m_unkD0 >= 0) {
        pArr->Add(this);
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    }
    if (pChild != 0) {
        do {
            pChild->BuildDispList(pArr);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193600 AddBoneMatrixToDisplayList__6PMNodeFb
void PMNode::AddBoneMatrixToDisplayList(bool bRecurse) {
    PMNode *pChild;
    unsigned int idx;
    if (m_unkD0 >= 0) {
        gGfxEng.pDisplayList->AddMatrix((PMat4 *)m_unk40, m_unkD0 * 4 + 0x296);
    }
    if (bRecurse) {
        m_unk18 = 0;
        pChild = 0;
        if (m_unk14 != 0) {
            pChild = *m_unk1C;
        }
        if (pChild != 0) {
            do {
                pChild->AddBoneMatrixToDisplayList(bRecurse);
                idx = m_unk18 + 1;
                m_unk18 = idx;
                pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x001936C0 SetFrameTime__6PMNodeFf
void PMNode::SetFrameTime(float fTime) {
    PMNode *pChild;
    void *pObj;
    m_unk38 = *(float *)&m_unk34;
    *(float *)&m_unk34 = fTime;
    m_unk3E |= 8;
    pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot06();
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            ((PNodeVirtual *)pChild)->Slot02(fTime);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// DRAFT: 0x00193790 CheckAnimated__6PMNodeFv
// note: DIFF 50 words; original keeps this in s0 with no frame locals and one shared epilogue (b end, li v0,1), ours uses a 0x30 frame and s1; tried nRet exit (50), early returns (53), nState local (53), reversed float compare (50/53).
int PMNode::CheckAnimated() {
    PMNode *pChild;
    PFrameSource *pObj;
    int nRet;
    nRet = 0;
    pObj = (PFrameSource *)m_unk24;
    if (pObj != 0 && pObj->m_unk04 != 0x3E8 && pObj->m_unk04 != 1 && 0.0f != pObj->Slot12()) {
        nRet = 1;
    } else {
        m_unk18 = 0;
        pChild = 0;
        if (m_unk14 != 0) {
            pChild = m_unk1C[0];
        }
        if (pChild != 0) {
            do {
                unsigned int uNext;
                if (pChild->CheckAnimated() != 0) {
                    nRet = 1;
                    break;
                }
                uNext = m_unk18 + 1;
                m_unk18 = uNext;
                pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
            } while (pChild != 0);
        }
    }
    return nRet;
}

// DRAFT: 0x00193890 GetFrameTime__6PMNodeFv
// note: 10 lines differ: compare operand order at 0x14 and 0x60 (x != 0.0f kept; 0.0f != x compiles identically), branch offsets and epilogue/mtc1 placement at 0xB4-0xC8; join nop after the loop (0x193944) missing as in FindBone.
float PMNode::GetFrameTime() {
    PMNode *pChild;
    float fTime = *(float *)&m_unk34;
    if (fTime != 0.0f) {
        return fTime;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            float fChild = pChild->GetFrameTime();
            unsigned int uNext;
            if (fChild != 0.0f) {
                return fChild;
            }
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0.0f;
}

// DRAFT: 0x00193960 SetAnimLoopCount__6PMNodeFib
// note: 8 lines differ; the bool guard beqz at 0x38 has offset 0x1C vs original 0x1D, and the original has the join nop (0xAC) before the epilogue. Loop body matches.
void PMNode::SetAnimLoopCount(int nCount, bool bFlag) {
    PMNode *pChild;
    void *pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot11(nCount);
    }
    if (bFlag) {
        m_unk18 = 0;
        pChild = 0;
        if (m_unk14 != 0) {
            pChild = m_unk1C[0];
        }
        if (pChild != 0) {
            do {
                unsigned int uNext;
                pChild->SetAnimLoopCount(nCount, bFlag);
                uNext = m_unk18 + 1;
                m_unk18 = uNext;
                pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x00193A30 SetAllAnimFlags__6PMNodeFP8AnimData
void PMNode::SetAllAnimFlags(AnimData *pAnim) {
    PMNode *pChild;
    void *pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot10(pAnim);
        float fTime = ((PFrameSource *)m_unk24)->Slot12();
        *(float *)&m_unk34 = fTime;
        m_unk38 = fTime;
    }
    m_unk3F = 3;
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            ((PNodeVirtual *)pChild)->Slot05(pAnim);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193B10 GetWorldMeshCenter__6PMNodeFPf
int PMNode::GetWorldMeshCenter(float *pOut) {
    u_long128 tmp;
    char *pMesh = (char *)GetFirstMesh();
    if (pMesh != 0) {
        sceVu0ApplyMatrix((float *)&tmp, m_unk40, (float *)(pMesh + 0x10));
        *(u_long128 *)pOut = tmp;
        return 0;
    }
    *(u_long128 *)pOut = *(u_long128 *)m_unk40[3];
    return 0;
}

// DRAFT: 0x00194340 DisableAllHitBox__6PMNodeFv
// note: 5 words differ, all the join nop at 0x84 before the epilogue; original has it, this does not. Tried: else-arm reorder (30), pChild=0 after m_unk18 (5, kept), trailing return (5), while form (25), nested if (27), ternary tail (12).
void PMNode::DisableAllHitBox() {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk10 != 0) {
        ((unsigned char *)m_unk10)[0xD] = 0;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    }
    if (pChild != 0) {
        do {
            pChild->DisableAllHitBox();
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}

// FUNCTION: 0x001943E0 AnimateBox__6PMNodeFf
void PMNode::AnimateBox(float fTime) {
    PAnim *pAnim;
    unsigned char *pMesh;
    pAnim = (PAnim *)m_unk24;
    if (pAnim != 0 && (pAnim->m_unkA & 0x10)) {
        m_unk28 = pAnim->FindChannel((eAnimType)5)->AnimateBox(fTime, m_unk3C);
        if (m_unk28 != 0) {
            return;
        }
        if (m_unk3C != 0) {
            if (m_unk10 != 0) {
                m_unk28 = (char *)m_unk10 + 0x10;
            }
        }
        return;
    } else {
        pMesh = (unsigned char *)m_unk10;
        if (pMesh != 0 && pMesh[0xD] != 0) {
            m_unk3C = pMesh[0xE];
            m_unk28 = (char *)m_unk10 + 0x10;
            return;
        }
        m_unk3C = 0;
        m_unk28 = 0;
    }
}

// FUNCTION: 0x001944B0 BuildAnimList__6PMNodeFP6PArrayUi
void PMNode::BuildAnimList(PArray *pArr, unsigned int uID) {
    PMNode *pChild;
    int nObjID;
    void *pObj = m_unk24;
    if (pObj != 0) {
        nObjID = *(int *)((char *)pObj + 4);
    } else {
        nObjID = 0;
    }
    if (uID == (unsigned int)nObjID) {
        pArr->Add(this);
        return;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->BuildAnimList(pArr, uID);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00194580 FindAnimNode__6PMNodeFUi
PMNode *PMNode::FindAnimNode(unsigned int uID) {
    PMNode *pChild;
    int nObjID;
    void *pObj = m_unk24;
    if (pObj != 0) {
        nObjID = *(int *)((char *)pObj + 4);
    } else {
        nObjID = 0;
    }
    if (uID == (unsigned int)nObjID) {
        return this;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            PMNode *pFound;
            unsigned int uNext;
            pFound = pChild->FindAnimNode(uID);
            if (pFound != 0) {
                return pFound;
            }
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0;
}


// DRAFT: 0x00194650 EnableOneRenderPassOnly__6PMNodeFi
// note: 42 words differ. Args D5..D7 read via bool lvalues to skip sltu normalization; still differs in load order and the D4 store address form (addiu+addu vs addu). Tried: pointer-index store form (same 42).
void PMNode::EnableOneRenderPassOnly(int nPass) {
    if (nPass >= 4) {
        CdsAssert__FPciPc("PMNode.cpp", 0x446, "iPassIndex < MAX_PASSES_PER_SHADER");
    }
    m_unkD4 = false;
    m_unkD5 = 0;
    m_unkD6 = 0;
    m_unkD7 = 0;
    (&m_unkD4)[nPass] = true;
    m_unk3E |= 0x80;
    m_unk18 = 0;
    PMNode *pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetRenderPassStatus(m_unkD4, *(bool *)&m_unkD5, *(bool *)&m_unkD6, *(bool *)&m_unkD7);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00194740 SetRenderPassStatus__6PMNodeFbbbb
void PMNode::SetRenderPassStatus(bool bA, bool bB, bool bC, bool bD) {
    PMNode *pChild;
    m_unkD4 = bA;
    m_unkD5 = bB;
    m_unkD6 = bC;
    m_unkD7 = bD;
    if (bA && bB && bC && bD) {
        m_unk3E &= 0x7F;
    } else {
        m_unk3E |= 0x80;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetRenderPassStatus(bA, bB, bC, bD);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00194850 Find__6PMNodeFUi
PMNode *PMNode::Find(unsigned int uID) {
    PMNode *pChild;
    if (uID == 0) {
        return 0;
    }
    if (m_unk08 == uID) {
        return this;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            PMNode *pFound = pChild->Find(uID);
            unsigned int uNext;
            if (pFound != 0) {
                return pFound;
            }
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0;
}

// DRAFT: 0x00194920 Find__6PMNodeFP6PMNode
// note: 2 words differ at the loop-exit beqz delay slot (original nop, ours daddu $v0,$zero,$zero); tried while, result var with break, idx indexing, early return guard.
int PMNode::Find(PMNode *pNode) {
    PMNode *pChild;
    if (this == pNode) {
        return 1;
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            if (pChild->Find(pNode) != 0) {
                return 1;
            }
            unsigned int idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
    return 0;
}

// DRAFT: 0x001949E0 RecurseSetSTAnimOptions__6PMNodeFb
// note: 8 words differ; the original returns the byte from s0 without andi 0xFF masks, and the loop-exit delay slot differs. Tried: int local and return (31 words, reverted), unsigned char kept.
unsigned char PMNode::RecurseSetSTAnimOptions(bool bFlag) {
    unsigned char bResult = 0;
    PMNode *pChild;
    if (m_unk10 != 0) {
        SetSTAnimOptions__5PMeshFb(m_unk10, bFlag);
        bResult = *((unsigned char *)m_unk10 + 0xC);
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            if (pChild->RecurseSetSTAnimOptions(bFlag) != 0) {
                bResult = 1;
            }
            unsigned int idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
    if (bResult != 0) {
        m_unk3E |= 0x10;
    }
    return bResult;
}

// DRAFT: 0x00194AD0 GetFirstMesh__6PMNodeFv
// note: 2 lines differ; zero-v0 move sits in the delay slot of the pChild guard beqz, original branches to a separate zero move with nop delay. Tried: pResult+break (larger), early return 0 with duplicated tail (26).
void *PMNode::GetFirstMesh() {
    PMNode *pChild;
    unsigned int idx;
    void *pMesh = m_unk10;
    if (pMesh != 0) {
        return pMesh;
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            void *pFound = pChild->GetFirstMesh();
            if (pFound != 0) {
                return pFound;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
    return 0;
}

// DRAFT: 0x00194B80 SetAllFrustrumTest__6PMNodeF13eBoxIntersect
// note: 7 lines differ; beq offset 0x1C vs 0x1B at 0x24 and missing join nop at 0x94 before epilogue (rest is shift). Tried: early return on m_unk04==2 (also 7, reverted).
void PMNode::SetAllFrustrumTest(eBoxIntersect eMode) {
    PMNode *pChild;
    unsigned int idx;
    m_unk0C = (int)eMode;
    if (m_unk04 != 2) {
        m_unk18 = 0;
        if (m_unk14 != 0) {
            pChild = *m_unk1C;
        } else {
            pChild = 0;
        }
        if (pChild != 0) {
            do {
                pChild->SetAllFrustrumTest(eMode);
                idx = m_unk18 + 1;
                m_unk18 = idx;
                if (idx < m_unk14) {
                    pChild = m_unk1C[m_unk18];
                } else {
                    pChild = 0;
                }
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x00194C30 ScaleSet__6PMNodeFffff
void PMNode::ScaleSet(float a, float b, float c, float d) {
    m_unkA0[0] = a;
    m_unkA0[1] = b;
    m_unkA0[2] = c;
    m_unkA0[3] = d;
    m_unk3E |= 8;
}

// DRAFT: 0x00195180 DestroyChildren__6PMNodeFv
// note: original keeps an inner pChild != 0 guard before the slot-8 call (CW drops it here) and calls through t9 with a nop after jalr; tried cast, local fn pointer, for-break loop; all leave the same diff.
void PMNode::DestroyChildren() {
    PMNode *pChild;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            if (pChild != 0) {
                void (*pfn)(PMNode *, int) = *(void (**)(PMNode *, int))(*(int *)pChild + 8);
                pfn(pChild, 1);
            }
            unsigned int idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
    if (m_unk1C != 0) {
        m_unk14 = 0;
        m_unk18 = 0;
    }
}

// FUNCTION: 0x00195480 SetAllLoopCountByID__6PMNodeFUii
void PMNode::SetAllLoopCountByID(unsigned int uID, int nCount) {
    PMNode *pChild;
    void *pObj = m_unk24;
    if (pObj != 0 && (uID == 0 || uID == *(unsigned int *)((char *)pObj + 4))) {
        uID = 0;
        ((PFrameSource *)pObj)->Slot11(nCount);
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetAllLoopCountByID(uID, nCount);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00195240 DestroyMesh__6PMNodeFv
void PMNode::DestroyMesh() {
    void *pMesh = m_unk10;
    if (pMesh != 0 && (m_unk3E & 1)) {
        __dt__5PMeshFv(pMesh, 1);
        StopAmbientSoundsByObject();
    }
    m_unk10 = 0;
    m_unk3E &= 0xEE;
    m_unk28 = 0;
    m_unk3C = 0;
}

// DRAFT: 0x001952B0 RecurseSetFade__6PMNodeFf
// note: 5 words differ, the join nop at 0x84 before the epilogue, same shape as SetAllFade. Tried: same structure as SetAllFade (not separately varied).
void PMNode::RecurseSetFade(float fFade) {
    PMNode *pChild;
    unsigned int idx;
    m_unk2C = fFade;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->RecurseSetFade(fFade);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}

// FUNCTION: 0x001956A0 RecurseSetAnimFlagsByID__6PMNodeFUiP8AnimData
int PMNode::RecurseSetAnimFlagsByID(unsigned int uID, AnimData *pAnim) {
    PMNode *pChild;
    unsigned int idx;
    void *pObj = m_unk24;
    if (pObj != 0 && uID == ((PFrameSource *)pObj)->m_unk04) {
        ((PFrameSource *)pObj)->Slot10(pAnim);
        m_unk3F |= 1;
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? *m_unk1C : 0;
    if (pChild != 0) {
        do {
            if (pChild->RecurseSetAnimFlagsByID(uID, pAnim) != 0) {
                m_unk3F |= 2;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return m_unk3F;
}

// DRAFT: 0x00195A40 EnableAnim__6PMNodeFbb
// note: DIFF 35 words; original stores m_unk3F in the delay slot of the first bB branch (store before the nop-delay second test), ours folds the store into the second branch. Tried split gating (54), bB-less inner test (53), unconditional store (52), if/else first-child load (35).
void PMNode::EnableAnim(bool bA, bool bB) {
    PMNode *pChild;
    unsigned int idx;
    void *pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot13();
    }
    if (bB) {
        m_unk3F = bA;
        if (bB && m_unk04 == 1) {
            m_unk18 = 0;
            pChild = (m_unk14 != 0) ? *m_unk1C : 0;
            if (pChild != 0) {
                do {
                    pChild->EnableAnim(bA, true);
                    if (m_unk3F == 0 && (pChild->m_unk3F & 7) != 0) {
                        m_unk3F = 2;
                    }
                    idx = m_unk18 + 1;
                    m_unk18 = idx;
                    pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
                } while (pChild != 0);
            }
        }
    }
}

// FUNCTION: 0x00195B50 AttachAnim__6PMNodeFP5PAnimb
void PMNode::AttachAnim(PAnim *pAnim, bool bFlag) {
    PAnimFrame *pFrame;
    if (pAnim == 0) {
        CdsAssert__FPciPc("PMNode.cpp", 0x10C, "pAnim");
    }
    DestroyAnim();
    if (bFlag) {
        pFrame = (PAnimFrame *)__nw__FUi(0x34);
        if (pFrame != 0) {
            pFrame = __ct__10PAnimFrameFP5PAnim(pFrame, pAnim);
        }
        m_unk24 = pFrame;
        if (m_unk24 == 0) {
            CdsAssert__FPciPc("PMNode.cpp", 0x113, "mpAnim");
        }
        m_unk3E |= 2;
    } else {
        m_unk24 = pAnim;
        m_unk3E &= 0xFD;
    }
}

struct PAnimHeader {
    unsigned int uA;
    unsigned int uNumChannels;
    unsigned int uC;
    unsigned short uFlags;
    unsigned short uG;
};

// FUNCTION: 0x00195C20 LoadAnim__6PMNodeFP8PPakFile
int PMNode::LoadAnim(PPakFile *pFile) {
    PAnimHeader hdr;
    PAnimFrame *pObj;
    DestroyAnim();
    if (((PCDFile *)pFile)->Read(&hdr, 0x10) != 0x10) {
        return 0;
    }
    if (hdr.uNumChannels > 5) {
        CdsAssert__FPciPc("PMNode.cpp", 0xFA, "aHeader.uNumChannels <= CHANNEL_MAX");
    }
    if (hdr.uFlags == 0 && hdr.uA > 1) {
        pObj = (PAnimFrame *)__nw__FUi(0x34);
        if (pObj != 0) {
            pObj = __ct__10PAnimFrameFs(pObj, 0);
        }
        m_unk24 = pObj;
    } else {
        pObj = (PAnimFrame *)__nw__FUi(0x20);
        if (pObj != 0) {
            pObj = (PAnimFrame *)__ct__5PAnimFv((PAnim *)pObj);
        }
        m_unk24 = pObj;
    }
    if (m_unk24 == 0) {
        CdsAssert__FPciPc("PMNode.cpp", 0x102, "mpAnim");
    }
    return ((PAnimFrame *)m_unk24)->LoadHeader(pFile, &hdr);
}

// FUNCTION: 0x00195D30 DestroyAnim__6PMNodeFv
void PMNode::DestroyAnim() {
    unsigned char flags = m_unk3E;
    if (flags & 2) {
        m_unk3E = flags & 0xFD;
        if (m_unk24 != 0) {
            delete (PFrameSource *)m_unk24;
        }
    }
    m_unk3E |= 8;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk3C = 0;
    StopAmbientSoundsByObject();
    m_unk3F = 0;
    *(unsigned int *)&m_unk2C = 0x3F800000;
    m_unk30 = 0;
    m_unk34 = 0;
    *(unsigned int *)&m_unk38 = 0xC61C4000;
}

// FUNCTION: 0x00195DD0 RecurseDetachAnim__6PMNodeFv
void PMNode::RecurseDetachAnim() {
    PMNode *pChild;
    unsigned int idx;
    DestroyAnim();
    DestroyFxTriggers(true, false, false);
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    }
    if (pChild != 0) {
        do {
            pChild->RecurseDetachAnim();
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00195E70 __dt__6PMNodeFv
PMNode::~PMNode() {
    DestroyMesh();
    DestroyAnim();
    DestroyChildren();
    DestroyFxTriggers(false, false, false);
    m_unk04 = 0;
    if (m_pObjDisplayList != 0) {
        __dt__18PObjectDisplayListFv(m_pObjDisplayList, 1);
        m_pObjDisplayList = 0;
    }
    StopAmbientSoundsByObject();
    m_unkEC = 0;
    m_unkF0 = 0;
    __dt__6PArrayFv(&m_unkD8, -1);
    __dt__6PArrayFv(&m_unk14, -1);
    if (this != 0) {
        *(void **)this = __vt__9PResource;
        m_unk04 = 0;
    }
}

// DRAFT: 0x00196220 InitMembers__6PMNodeFv
// note: sqc2 $vf0 zeroing stores are raw .word; base a1 is scheduled late, small constants take other registers, float constants use mtc1/cvt (25 words differ).
void PMNode::InitMembers() {
    m_unk08 = 0;
    m_unk10 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk3C = 0;
    m_unk3E = 8;
    m_unk3D = 3;
    m_unk3F = 0;
    asm {
        .word 0xF8A00000
        .word 0xF8A00010
        .word 0xF8A00030
        .word 0xF8A00040
    }
    m_unkA0[3] = 1.0f;
    m_unkA0[2] = 1.0f;
    m_unkA0[1] = 1.0f;
    m_unkA0[0] = 1.0f;
    m_unk2C = 1.0f;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk38 = -10000.0f;
    m_unk04 = 3;
    m_unk0C = 4;
    m_unkD4 = true;
    m_unkD5 = 1;
    m_unkD6 = 1;
    m_unkD7 = 1;
    m_unkD0 = -1;
    m_pObjDisplayList = 0;
    m_unkE8 = mst_NextPMNodeRef__6PMNode;
    mst_NextPMNodeRef__6PMNode = mst_NextPMNodeRef__6PMNode + 1;
    m_unkEC = 0;
    m_unkF0 = 0;
    m_unkF4 = 0;
}

// DRAFT: 0x001962E0 RemoveNullAnimation__6PMNodeFv
// note: 5 lines differ, all in the epilogue: original has the join nop at 0xB4 before the ld ra, ours does not. Guard, delete, child loop match. Tried: single delete without inner null check (kept, 5 lines from many).
void PMNode::RemoveNullAnimation() {
    PMNode *pChild;
    unsigned int idx;
    void *pObj = m_unk24;
    if (pObj != 0 && ((PFrameSource *)pObj)->m_unk0A == 0) {
        delete (PFrameSource *)pObj;
        m_unk24 = 0;
        StopAmbientSoundsByObject();
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->RemoveNullAnimation();
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}
